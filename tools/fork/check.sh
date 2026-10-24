#!/usr/bin/env bash
# The one proof command for the fork.
#
#   tools/fork/check.sh [func ...]
#
# With names: refuses if a named function is still included as assembly, forces
# the C files that define them to be recompiled, then runs the full build.
# With no names: runs the full build only.
# Exits 0 only when the build prints "waverace64.us.rev1.z64: OK" (the sha1
# check of the whole ROM). Then prints tools/progress.py's function count.
set -u

cd "$(dirname "${BASH_SOURCE[0]}")/../.." || exit 2

if [ -x .venv/bin/python3 ]; then PY=.venv/bin/python3; else PY=python3; fi

objs=()
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
    done
done

if [ "${#objs[@]}" -gt 0 ]; then
    rm -f -- "${objs[@]}"
    echo "check: forcing rebuild of: ${objs[*]}"
fi

log=$(mktemp)
trap 'rm -f "$log"' EXIT
COLOR=0 make -j"$(nproc)" 2>&1 | tee "$log"
make_status=${PIPESTATUS[0]}

if [ "$make_status" -ne 0 ]; then
    echo "check: make failed (exit $make_status)" >&2
    exit 1
fi
if ! sed 's/\x1b\[[0-9;]*m//g' "$log" | grep -q 'waverace64\.us\.rev1\.z64: OK'; then
    echo "check: FAILED - the rebuilt ROM does not match (no 'waverace64.us.rev1.z64: OK')" >&2
    echo "check: locate the first difference with: $PY first_diff.py" >&2
    exit 1
fi

echo "check: OK - ROM matches"
"$PY" tools/progress.py | head -1
exit 0
