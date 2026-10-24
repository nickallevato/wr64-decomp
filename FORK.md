# Fork notes

Private working fork of [LLONSIT/Wave-Race-64](https://github.com/LLONSIT/Wave-Race-64),
used to turn the remaining included assembly into C that still rebuilds the ROM
byte for byte. Nothing here is sent upstream without the owner's say-so.

## Branch model

- `master`: a mirror of upstream (`upstream/master`, currently e00a55f). Never edited here.
- `main`: ours. Everything proven lands here.
- `match/<func>`: one branch per function, in its own worktree (see `tools/fork/start.sh`).
  Merged into `main` only after `tools/fork/check.sh <func>` passes.

`origin` is the private Gitea (`ssh://na@gitea.allevato.io:2222/na/wr64-decomp.git`).
`upstream` is GitHub and is fetch-only.

## Setup (one time)

These are the commands that produced the baseline below. Needs the system packages
`mips-linux-gnu` binutils, `gcc`, `make`, `python3` with `venv`.

```bash
git checkout -b main master
git submodule update --init --recursive

python3 -m venv .venv && . .venv/bin/activate
pip install -r tools/splat/requirements.txt GitPython colour capstone
pip install git+https://github.com/matt-kempster/m2c
pip install pynacl toml Levenshtein        # the permuter's own requirements
pip install colorama watchdog               # asm-differ (./diff)

make toolchain                              # tools/n64crc + tools/ido-static-recomp/build/5.3/out/cc
git clone https://github.com/simonlindholm/decomp-permuter tools/decomp-permuter

cp /home/na/projects/wr_64_exe/reference/wr64-decomp/baserom.us.rev1.z64 .   # never committed (*.z64 is ignored)
make init                                   # clean + extract + build; ends with "waverace64.us.rev1.z64: OK"
```

Notes:

- `tools/Torch` (asset extraction) is fetched by the submodule step but not built; `make init` does not need it.
- The Makefile uses `.venv/bin/python3` automatically when it exists.
- `make context` in the Makefile points at `tools/m2ctx.py`, which does not exist; the script is `tools/m2ctx` (`python3 tools/m2ctx <file.c>` writes `ctx.c`).

## Baseline (at e00a55f, clean build)

```
waverace64.us.rev1.z64: OK
1076 matched functions / 1472 total (73.10%)       <- tools/progress.py
327612 matching bytes / 838784 total (39.06%)
431                                                 <- grep -r GLOBAL_ASM src | wc -l
```

The spec's 889/1,365 and 438 came from upstream a51b38a by a different count
(`grep -E 'INCLUDE_ASM|GLOBAL_ASM'`). `tools/progress.py` is the authoritative number
and also counts library/other functions, so its totals are larger. The goal of the
first milestone is to raise the 1076 by at least four.

## Matching one function

```bash
tools/fork/start.sh func_801E93B4 src/codeseg/B66E0.c
cd ../wr64-decomp-wt/func_801E93B4
# m2c/func_801E93B4.c holds the m2c draft; write the C into the source file,
# replacing the GLOBAL_ASM line, then:
tools/fork/check.sh func_801E93B4
```

- `tools/fork/start.sh <func> <file.c>`: creates the worktree `../wr64-decomp-wt/<func>` on
  `match/<func>` from `main`, links in the ROM, `.venv` and the built tools, extracts the asm,
  runs `make` once, and writes the draft to `m2c/<func>.c`.
- `tools/fork/check.sh [func ...]`: fails if a named function still has a `GLOBAL_ASM` line,
  recompiles the C files that define the named functions, runs the full `make`, and exits 0
  only if it prints `waverace64.us.rev1.z64: OK`. Then prints the progress line.
  A mismatch: `python3 first_diff.py` locates the first differing address; `./diff <func>` shows the asm diff.
- A function counts as done only when `check.sh` passes on the commit that adds it.

## The loop

One function per worktree; every step runs from the worktree root with `. .venv/bin/activate`.

1. **Start.** `tools/fork/start.sh <func> <file.c>`, then `cd ../wr64-decomp-wt/<func>`.
2. **Draft.** Start from `m2c/<func>.c`. Prefer an existing prototype (`include/`, the same `.c`,
   other callers in `src/`) and the style of a matched sibling. Replace the `#pragma GLOBAL_ASM`
   line with the C. Then `make extract`, so splat drops the function's `.s` (without it the
   progress count does not move).
3. **Diff.** `./diff <func>` (watch mode: rebuilds on save). One-shot:
   `python3 tools/asm-differ/diff.py -s <func> --no-pager` (`--format json` gives `current_score`; 0 = clean).
   Check the function's rodata (floats, strings, jump tables) moved with it.
4. **Permute,** only if stuck and within the cap (about 2 h per function, about 1 h of it permuter):
   `tools/decomp-permuter/import.py <c file> <asm file>`, then
   `tools/decomp-permuter/permuter.py nonmatchings/<func> -j4`.
5. **Prove.** `tools/fork/check.sh <func>`: must print `check: OK` and the count must rise by one.
6. **Commit** on `match/<func>` (`<func>: <what it is> in C`). Push the branch to `origin` if wanted.
7. **Merge.** The coordinator merges `--no-ff` into `main`, runs `make extract` and
   `tools/fork/check.sh <func>` again there, and pushes `main`.

**NON_MATCHING rule.** Past the cap the function stays `#pragma GLOBAL_ASM` and does not count.
The best attempt is kept beside it, never built by default:

```c
#ifdef NON_MATCHING
// <one line: the remaining difference>
<the C>
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/.../<func>.s")
#endif
```

## Milestone 1

Goal: raise the count of matched functions by at least four, and learn what the loop costs.
Both workers ran on 2026-10-24 (roughly 01:55 to 03:25).

**Count (`tools/progress.py`): 1076 -> 1080 of 1472 (73.10% -> 73.37%).** The goal is met, but
two of the four are stand-ins: the two functions the recomp hooks call (`func_801F4120`,
`func_801E5554`) are in the second table.

### Matched (plain C, byte-exact, `tools/fork/check.sh <func>` prints OK)

| Function | File | What it is | Time |
|---|---|---|---|
| `func_801E93B4` | `src/codeseg/B66E0.c` | the scaled text printer: sets `gPrinterScale`, calls `func_801E946C` (mode and corner colours), sets `gPrinterScaled`, calls `func_801E9858` | about 5 min, no permuter |
| `func_801F9520` | `src/codeseg/BCFF0.c` | the portrait column of the race HUD (frame, face and place digit per rider, bobbing); local struct `PortraitPos` (0x14) | about 7 min, no permuter |
| `func_801FAD68` | `src/codeseg/BCFF0.c` | a Bresenham line rasteriser; stand-in for `func_801F4120` | about 10 min, no permuter |
| `func_801E66F4` | `src/codeseg/B3AA0.c` | the spinning pause-menu cursor's update (popup type 3); stand-in for `func_801E5554` | about 8 min, no permuter |

### Set aside (do not count; C under `#ifdef NON_MATCHING`, `#pragma GLOBAL_ASM` in the `#else`)

| Function | File | Best score | Remaining difference | Time |
|---|---|---|---|---|
| `func_801E5554` | `src/codeseg/B3AA0.c` | 40 / 71200 | the popup cards. One register swap in case 4 (loop counter and IDO's strength-reduced texture-offset temp take `$t0`/`$t1` the wrong way round); frame and everything else match | about 1 h by hand and 50 min of permuter, then a 15 min retry and 10 min more permuter, nothing helped |
| `func_801F4120` | `src/codeseg/BCFF0.c` | 58028 / 490800 | LAP, RANK and SPEED (0x4CB0 bytes, about 4,900 instructions). Same control flow and frame; register allocation and scheduling differ throughout. The `1.8f` is `D_80227A4C` in the original | about 40 min by hand and 10 min of permuter |

`func_801E5554` is two instructions of regalloc from done; `func_801F4120` is a long way off.

### Names

Names come from the code, `docs/GAME-INTERNALS.md` and the recomp's `patches/br_draw.cpp`.
`func_` names are kept (none of the four meanings is certain enough to rename a function that other
code calls). Renamed: the printer's parameters (`gdl, font, str, x, y, mode, r0..b3, scale`) and
its two globals `gPrinterScale` / `gPrinterScaled` (`0x80226E24`/`28`, via `symbol_addrs.txt`);
the portrait column's `gPortraitPos` / `gPortraitBob` / `gPortraitFaces` and `PortraitPos.bobPhase`;
and the popup slot fields (`UnkStruct_menu_buffer_1`: `type`, `state`, `index`, `active`, `x`, `y`,
`frame`, `menuY`, `variant`) with the parameters of `func_801E66F4`, `func_801E68EC`, `func_801E6A4C`.
Shared symbols (`D_80228B50`, the HUD's x offset; `D_800D48DC`, the human's slot) were left, because
other files use them.

### What we learned

- **Stand-ins work.** Two of the four functions the milestone counts are stand-ins, small neighbours
  of a function that would not match. A function of 0xB8 to 0x1F8 bytes took 5 to 10 minutes; the two
  large ones (0xB20 and 0x4CB0) took an hour or more and did not match.
- **Size decides.** Up to about 0x200 bytes, m2c plus a few source-shape changes (declaration order,
  one temp, a literal's type) matched without the permuter. Above that, register allocation drifts
  and a hand fix moves something else.
- **The permuter rarely helped.** About 2 h of it in total found one useful change (a temp `h` in
  `func_801E5554`) and nothing else. On a 4,900-instruction function it only found "better" scores
  by deleting display-list commands. Macros expanded for it made the base score worse.
- **Tricks that mattered:** an outer `for` loop plus per-case initialisations to get IDO's loop
  strength reduction; `0.0` (double) rather than `0.0f` for a second zero argument; a `MtxF unused[2]`
  pad for the frame size; exactly as many locals as the original has, declared in its order.
- **Setup costs:** `check.sh` does not run `make extract`, so the progress count lags until it is run
  after removing a pragma. Do it in `main` after every merge. Workers sharing one scratchpad directory
  overwrote each other's files once; give each worker its own.
