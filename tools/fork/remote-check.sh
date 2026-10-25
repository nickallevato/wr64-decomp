#!/bin/bash
# tools/fork/remote-check.sh <name> <commit>...: build each commit on $WR64_REMOTE
# (default na-workhorse), in a worktree <repo>-wt/rcheck-<name> there, and print one line
# per commit with check.sh's verdict and exit status. Exits non-zero if any commit fails.
# Commits come from the local repo: its branches and origin refs are pushed to the
# remote's repo under refs/remotes/local*/ first. Removes the worktree when done.
# The remote needs its own extracted checkout of this repo at the same path, with
# the ROM, .venv, n64crc and IDO built (as for the permuter).
[ $# -ge 2 ] || { echo "usage: $0 <name> <commit>..." >&2; exit 2; }
host=${WR64_REMOTE:-na-workhorse}
repo=$(git -C "$(dirname "$0")" rev-parse --path-format=absolute --git-common-dir)/..
repo=$(cd "$repo" && pwd)
name=$1; shift
git -C "$repo" push -q -f "ssh://$host$repo" \
    'refs/heads/*:refs/remotes/local/*' 'refs/remotes/origin/*:refs/remotes/local-origin/*' || exit 1
command ssh "$host" bash -s -- "$repo" "$name" "$@" <<'REMOTE'
set -u
main=$1; name=$2; shift 2
wt=$main-wt/rcheck-$name
cd $main || exit 1
rm -rf "$wt"; git worktree prune
git worktree add -q --detach "$wt" "$1" || exit 1
cd "$wt"
ln -s "$main/baserom.us.rev1.z64" baserom.us.rev1.z64; ln -s "$main/.venv" .venv; ln -s "$main/tools/n64crc" tools/n64crc
mkdir -p tools/ido-static-recomp; ln -s "$main/tools/ido-static-recomp/build" tools/ido-static-recomp/build
for t in decomp-permuter m2c; do [ -e "$main/tools/$t" ] && ln -s "$main/tools/$t" "tools/$t"; done
rc=0
for c in "$@"; do
    git checkout -q --detach "$c" || { echo "$c: checkout failed"; rc=1; continue; }
    make extract -j"$(nproc)" >/dev/null 2>&1 || { echo "$c: extract failed"; rc=1; continue; }
    out=$(tools/fork/check.sh 2>&1); s=$?
    echo "$(git log --oneline -1 | cut -c1-60): $(echo "$out" | grep -E '^check: |matched functions' | grep -v 'forcing rebuild' | tr '\n' ' ') [exit $s]"
    [ $s -eq 0 ] || rc=1
done
cd $main && git worktree remove --force "$wt" && git worktree prune
exit $rc
REMOTE
