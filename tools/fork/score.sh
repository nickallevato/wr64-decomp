#!/usr/bin/env bash
# Score one set-aside function alone.
#
#   tools/fork/score.sh <func>          prints "<func> <current_score> <max_score>"
#
# Run the copy inside the worktree you are scoring: it cds into the repository it
# lives in. The worktree must be extracted (asm/ holds <func>.s) and built once.
#
# Finds the "#ifdef NON_MATCHING" block whose "#else" includes <func>.s, switches
# that one line to "#if 1", rebuilds the ROM image (that one object and the link;
# no sha1 check), and runs
#   diff.py <func> --no-pager --max-size <instructions in <func>.s> --format json
# (never -s: that is --stop-at-ret). The source file is restored on every exit,
# including failure and interrupt, and the object built from the scratch edit is
# deleted, so the next make rebuilds it from the restored file instead of linking
# the set-aside's C into a "matching" build (the stale-object trap).
#
# Exits non-zero, printing no score, when the block is not found, make fails (a
# failed build would leave the old object and a stale score), or diff.py fails.
set -u

if [ $# -ne 1 ]; then
    echo "usage: $0 <func>" >&2
    exit 2
fi
func=$1

cd "$(dirname "${BASH_SOURCE[0]}")/../.." || exit 1
[ -x .venv/bin/python3 ] && py=.venv/bin/python3 || py=python3

# The source file and the pragma line that includes <func>.s.
hits=$(grep -rn --include='*.c' -E "^#pragma GLOBAL_ASM\(\"[^\"]*/$func\.s\"\)" src)
if [ -z "$hits" ] || [ "$(printf '%s\n' "$hits" | wc -l)" -ne 1 ]; then
    echo "score: no single '#pragma GLOBAL_ASM(\".../$func.s\")' line in src/" >&2
    exit 1
fi
cfile=${hits%%:*}
rest=${hits#*:}
pline=${rest%%:*}
asmfile=$(printf '%s\n' "$rest" | sed -E 's/^[0-9]+:#pragma GLOBAL_ASM\("([^"]*)"\)$/\1/')

# Walking up from the pragma: the "#else" must come first, then "#ifdef NON_MATCHING",
# with no other preprocessor conditional in between.
iline=$(awk -v p="$pline" '
    NR < p { l[NR] = $0 }
    END {
        seen_else = 0
        for (i = p - 1; i >= 1; i--) {
            if (l[i] ~ /^#[ \t]*else/) { if (seen_else) exit; seen_else = 1; continue }
            if (l[i] ~ /^#[ \t]*ifdef[ \t]+NON_MATCHING[ \t]*$/) { if (seen_else) print i; exit }
            if (l[i] ~ /^#[ \t]*(if|ifdef|ifndef|elif|endif)/) exit
        }
    }' "$cfile")
if [ -z "$iline" ]; then
    echo "score: $cfile:$pline: $func.s is not the #else of an '#ifdef NON_MATCHING' block" >&2
    exit 1
fi

[ -f "$asmfile" ] || { echo "score: $asmfile missing (run make extract)" >&2; exit 1; }
ninsn=$(awk -v f="$func" '
    $0 ~ "^glabel "f"$" { on = 1 }
    on && /\/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]{8} \*\// { n++ }
    $0 ~ "^endlabel "f"$" { on = 0 }
    END { print n + 0 }' "$asmfile")
[ "$ninsn" -gt 0 ] || { echo "score: no instructions for $func in $asmfile" >&2; exit 1; }

obj=build/${cfile%.c}.o
backup=$(mktemp "${TMPDIR:-/tmp}/score.XXXXXX") || exit 1
cp -p "$cfile" "$backup" || exit 1
restore() {
    # Copy back without -p: the file is newer than any object built from the edit.
    cat "$backup" > "$cfile" && rm -f "$backup"
    rm -f "$obj"
}
trap restore EXIT
trap 'exit 130' INT
trap 'exit 143' TERM HUP

sed -i "${iline}s/.*/#if 1/" "$cfile" || exit 1

log=$(make build/waverace64.us.rev1.z64 2>&1)
if [ $? -ne 0 ]; then
    printf '%s\n' "$log" | sed 's/\x1b\[[0-9;]*[mK]//g' | tail -20 >&2
    echo "score: make failed; no score" >&2
    exit 1
fi

json=$("$py" -W ignore::SyntaxWarning tools/asm-differ/diff.py "$func" --no-pager --max-size "$ninsn" --format json)
[ $? -eq 0 ] || { echo "score: diff.py failed" >&2; exit 1; }
scores=$(printf '%s' "$json" | "$py" -c 'import json, sys; d = json.load(sys.stdin); print(d["current_score"], d["max_score"])') \
    || { echo "score: could not read diff.py's json" >&2; exit 1; }
echo "$func $scores"
