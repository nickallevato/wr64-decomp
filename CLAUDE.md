# Working in this fork

`FORK.md` is the reference: the loop, the commit rule, the NON_MATCHING rule, and what each milestone
taught. Read it before matching anything. This file holds the standing rules for agents.

## Worker models

- **Matching workers: Opus.** Every byte-matching batch goes to an Opus worker.
- **One worker at a time,** unless the owner asks for more. Two in parallel need disjoint files and must not
  both run the permuter on na-workhorse.
- The coordinator reviews every batch itself: reads the diff, re-scores two set-asides with
  `tools/fork/score.sh`, trial-merges, and proves the merge plus two mid-batch commits with
  `tools/fork/remote-check.sh` before main moves.

## Standing rules

- **CPU-heavy work runs on na-workhorse.** The permuter runs there at `-j10`, started with `setsid`; stop a
  run only with `kill -- -<pgid>`, never a pattern kill. Prove every commit with
  `tools/fork/remote-check.sh <name> <commit>...`. Locally only single-object compiles, `diff.py` and m2c;
  never run `tools/fork/check.sh` locally (it rebuilds every NON_MATCHING file).
- `ssh` can be a shell function locally: use `command ssh`. na-workhorse can't reach Gitea;
  `remote-check.sh` pushes to it directly.
- `tools/fork/check.sh` (via `remote-check.sh`) is the only proof of a match. Gate each commit on its own exit
  status, never through a pipe; never pipe `make` through `head` (SIGPIPE can leave a stale ELF that scores 0).
- Score set-asides with `tools/fork/score.sh <func>`, or `diff.py <func> --no-pager --max-size <size/4>`.
  Never pass `-s` (it is `--stop-at-ret`).
- Mark every hack: `// FAKE` with its reason, stack pads, odd literals, gotos, `// fallthrough`.
- Names only from evidence: a call into a named function, a `GAME_STATE_*` or course value, a libultra call,
  a string. Commit messages make no claims the code doesn't show.
- Never commit or push the ROM or anything extracted from it. Never run the game here.
- Push `main` to `origin` and `github`; batch branches to `origin`. Never push to, or open PRs against,
  upstream (LLONSIT/Wave-Race-64): it refuses AI-generated code.
