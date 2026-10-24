#!/usr/bin/env bash
# Set up a worktree to match one function, with an m2c draft.
#
#   tools/fork/start.sh <func> <file.c>      e.g. func_801E93B4 src/codeseg/B66E0.c
#
# Creates ../wr64-decomp-wt/<func> on branch match/<func> from main, links the
# ROM, venv and built toolchain into it, extracts the asm, builds once, and
# writes the m2c draft to <worktree>/m2c/<func>.c.
set -eu

if [ $# -ne 2 ]; then
    echo "usage: $0 <func> <file.c>" >&2
    exit 2
fi
func=$1
cfile=$2

# The main checkout, even when run from inside another worktree.
main=$(git -C "$(dirname "${BASH_SOURCE[0]}")" worktree list --porcelain | sed -n '1s/^worktree //p')
wt="$main/../wr64-decomp-wt/$func"

cd "$main"
for need in baserom.us.rev1.z64 .venv/bin/python3 tools/ido-static-recomp/build/5.3/out/cc tools/n64crc; do
    [ -e "$need" ] || { echo "start: $main/$need is missing; do the setup in FORK.md first" >&2; exit 1; }
done
[ -f "$cfile" ] || { echo "start: $cfile not found in $main" >&2; exit 1; }
[ ! -e "$wt" ] || { echo "start: $wt already exists" >&2; exit 1; }

mkdir -p "$(dirname "$wt")"
git worktree add -b "match/$func" "$wt" main

cd "$wt"
ln -s "$main/baserom.us.rev1.z64" baserom.us.rev1.z64
ln -s "$main/.venv" .venv
ln -s "$main/tools/n64crc" tools/n64crc
mkdir -p tools/ido-static-recomp            # empty directory of the uninitialised submodule
ln -s "$main/tools/ido-static-recomp/build" tools/ido-static-recomp/build
for t in decomp-permuter m2c; do
    [ -e "$main/tools/$t" ] && ln -s "$main/tools/$t" "tools/$t"
done

# asm/ and bin/ are generated from the ROM and are not in git.
out=$(make extract -j"$(nproc)" 2>&1) || { echo "$out" >&2; exit 1; }
make -j"$(nproc)" 2>&1 | sed 's/\x1b\[[0-9;]*m//g' | tail -4

# m2c draft, using the C file's preprocessed context.
s=$(find asm/us/rev1/nonmatchings -name "$func.s" | head -1)
[ -n "$s" ] || { echo "start: no asm/.../$func.s found (already C?)" >&2; exit 1; }
python3 tools/m2ctx "$cfile" >/dev/null
mkdir -p m2c
.venv/bin/m2c --context ctx.c -f "$func" "$s" > "m2c/$func.c"
echo "start: worktree $wt"
echo "start: draft   $wt/m2c/$func.c"
