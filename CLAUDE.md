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

## Long-tail practice (milestone 5, after "The long tail of LLM-assisted decompilation", Chris Lewis)

- **Start from a sibling.** Before working a set-aside, run `tools/fork/similar.py <func>` and read the C of
  the closest matched functions (opcode similarity, as ethteck/coddog measures it). Twins have matched in
  minutes once one of the pair matched. `similar.py --unmatched` lists every function still in assembly with
  its nearest matched ones: use it to order a batch.
- **Permuter last.** Its finds are often FAKEs (`do {} while (0)`, `if (t && t && t) {}`, dead reads, odd
  variable reuse) that match without explaining the code, and later workers copy them as if they were real.
  Try semantic shapes first (sibling C, declaration and statement order, literals, chained stores); use the
  permuter only for the last few registers, and list every permuter-found FAKE in the report.
- **Reorder only independent statements.** A greedy statement-move search must not swap two statements that
  share a variable, a call, a display-list command or a store through a pointer; check each kept move.
- **Matched code is reference material.** Prefer idiomatic C (array indexing over pointer arithmetic, real
  names over temporaries) when it still matches: the next worker learns from it.
- **Guardrails.** In the coordinator's session a PreToolUse hook denies pattern kills (`pkill -f`,
  `killall`), `pgrep -f` wait loops (they match themselves), a local `check.sh`, pushes to upstream, and
  edits to `*.sha1` or to `asm/`, `build/`, `bin/`, `mio0/`, `expected/`. The rules hold without it too.
