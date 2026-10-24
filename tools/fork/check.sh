#!/usr/bin/env bash
# The one proof command for the fork.
#
#   tools/fork/check.sh [func ...]
#
# Run the copy inside the worktree you are checking: it cds into the repository
# it lives in, whatever the current directory is.
#
# With names: refuses if a named function is still included as assembly, forces
# the C files that define them to be recompiled, then runs the full build.
# With no names: runs the full build only.
#
# Every run also forces a recompile of each src/ .c file that contains
# "#ifdef NON_MATCHING". The IDO build skips those set-aside bodies, but the gcc
# check pass (CC_CHECK, which defines NON_MATCHING) compiles them, so a body that
# stops compiling cleanly is caught here.
#
# Fails (exit 1) when:
#   - the build log has a gcc "file:line:col: warning:" or "...: error:" line that
#     is not in tools/fork/warnings-baseline.txt (the lines are shown). Only files
#     rebuilt in this run produce such lines; that always includes the
#     NON_MATCHING files and the files defining the named functions;
#   - make fails;
#   - a file defining a named function is not linked (its .o has no .text entry
#     in build/waverace64.us.rev1.map), so an unlinked .c cannot give a false OK;
#   - the build does not print "waverace64.us.rev1.z64: OK" (the sha1 check of
#     the whole ROM).
# Then prints tools/progress.py's function count.
#
# The baseline holds the warnings upstream's code already had when it was made
# (the same set as main 7c56acf, full rebuild): one per line as
# "file: warning: text", line and column removed, sorted with LC_ALL=C; a warning
# that occurs twice in a file is listed twice (the comparison counts them). make runs under LC_ALL=C so gcc's
# messages are plain ASCII whatever the locale. In "passing argument N of 'f'" warnings the function name is
# not compared (both sides are normalised), so renaming f needs no baseline edit. Add to the baseline only warnings
# you did not cause. To regenerate it from a full rebuild:
#   rm -rf build/src && LC_ALL=C COLOR=0 make 2>&1 | sed 's/\x1b\[[0-9;]*[mK]//g' \
#     | grep -E '^[^ :]+:[0-9]+:[0-9]+: (warning|error):' \
#     | sed -E 's/^([^ :]+):[0-9]+:[0-9]+: /\1: /' | LC_ALL=C sort > tools/fork/warnings-baseline.txt
set -u

cd "$(dirname "${BASH_SOURCE[0]}")/../.." || exit 2

if [ -x .venv/bin/python3 ]; then PY=.venv/bin/python3; else PY=python3; fi

MAP=build/waverace64.us.rev1.map
BASELINE=tools/fork/warnings-baseline.txt
export LC_ALL=C   # also for make: ASCII quotes in gcc messages, stable sort order

objs=()
deffiles=()
for f in "$@"; do
    # 1. Still assembly?  (GLOBAL_ASM pragma or INCLUDE_ASM macro naming it)
    asm=$(grep -rnE '(GLOBAL_ASM|INCLUDE_ASM)' src --include='*.c' --include='*.h' | grep -E "(/|[(, \"])${f}([.\")]|,|\$)" || true)
    if [ -n "$asm" ]; then
        echo "check: $f is still included as assembly:" >&2
        echo "$asm" | sed 's/^/  /' >&2
        exit 1
    fi
    # 2. Which C file defines it?  (a line starting a definition, not a prototype)
    defs=$(grep -rnE "^[A-Za-z_].*[ *]${f}[[:space:]]*\(" src --include='*.c' | grep -vE ';[[:space:]]*(//.*|/\*.*)?$' | cut -d: -f1 | sort -u || true)
    if [ -z "$defs" ]; then
        echo "check: no C definition of $f found under src/" >&2
        exit 1
    fi
    for c in $defs; do
        objs+=("build/${c%.c}.o")
        deffiles+=("$c")
    done
done

# 3. Files with set-aside (NON_MATCHING) bodies are always recompiled.
for c in $(grep -rl '#ifdef NON_MATCHING' src --include='*.c' | sort); do
    objs+=("build/${c%.c}.o")
done

if [ "${#objs[@]}" -gt 0 ]; then
    mapfile -t objs < <(printf '%s\n' "${objs[@]}" | sort -u)
    rm -f -- "${objs[@]}"
    echo "check: forcing rebuild of: ${objs[*]}"
fi

tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
COLOR=0 make -j"$(nproc)" 2>&1 | tee "$tmp/log"
make_status=${PIPESTATUS[0]}

# 4. gcc diagnostics not in the baseline. Checked before make's status, so an
#    error in a NON_MATCHING body is reported with its file and line.
sed 's/\x1b\[[0-9;]*[mK]//g' "$tmp/log" | grep -E '^[^ :]+:[0-9]+:[0-9]+: (warning|error):' > "$tmp/diag" || true
# The function named in a "passing argument N of 'f'" warning is not compared: a rename
# must not need a baseline edit. The file, the argument number and the rest of the text are.
norm() { sed -E "s/^([^ :]+):[0-9]+:[0-9]+: /\\1: /; s/(passing argument [0-9]+ of )'[A-Za-z_0-9]+'/\\1'FUNC'/"; }
norm < "$tmp/diag" | sort > "$tmp/now"
if [ -f "$BASELINE" ]; then sed -E "s/(passing argument [0-9]+ of )'[A-Za-z_0-9]+'/\\1'FUNC'/" "$BASELINE" | sort > "$tmp/base"; else : > "$tmp/base"; fi
comm -23 "$tmp/now" "$tmp/base" | sort -u > "$tmp/new"
if [ -s "$tmp/new" ]; then
    echo "check: FAILED - the gcc check pass reported warnings/errors not in $BASELINE:" >&2
    while IFS= read -r d; do
        # the full line, with line numbers, for each new diagnostic
        if grep -qxF -- "$(printf '%s\n' "$d" | norm)" "$tmp/new"; then echo "  $d" >&2; fi
    done < "$tmp/diag"
    exit 1
fi

if [ "$make_status" -ne 0 ]; then
    echo "check: make failed (exit $make_status)" >&2
    exit 1
fi

# 5. Every file defining a named function must be linked into the ROM.
for c in "${deffiles[@]+"${deffiles[@]}"}"; do
    if ! grep -qF " build/${c%.c}.o(.text)" "$MAP"; then
        echo "check: FAILED - $c defines a named function, but build/${c%.c}.o is not linked (no .text entry in $MAP)" >&2
        exit 1
    fi
done

if ! sed 's/\x1b\[[0-9;]*m//g' "$tmp/log" | grep -q 'waverace64\.us\.rev1\.z64: OK'; then
    echo "check: FAILED - the rebuilt ROM does not match (no 'waverace64.us.rev1.z64: OK')" >&2
    echo "check: locate the first difference with: $PY first_diff.py" >&2
    exit 1
fi

echo "check: OK - ROM matches"
"$PY" tools/progress.py | head -1
exit 0
