# Fork notes

Public fork of [LLONSIT/Wave-Race-64](https://github.com/LLONSIT/Wave-Race-64), at
<https://github.com/nickallevato/wr64-decomp>. It turns the remaining included assembly into C
that still rebuilds the ROM byte for byte, and records how: the loop, the tools and what each
milestone taught. Upstream does not accept AI-generated contributions, so nothing from this fork
is offered upstream; the work is shipped on `main` here.

## Branch model

- `master`: a mirror of upstream (`upstream/master`, currently e00a55f). Never edited here.
- `main`: ours. Everything proven lands here.
- `match/<func>`: one branch per function, in its own worktree (see `tools/fork/start.sh`).
  Merged into `main` only after `tools/fork/check.sh <func>` passes.

Remotes: `github` is the public fork (`https://github.com/nickallevato/wr64-decomp`) and
`origin` is the owner's Gitea; `main` is pushed to both, batch branches to `origin`.
`upstream` is LLONSIT's repository and is fetch-only.

`port/pr92-davkdavk` is the PR branch: it contains davkdavk's five commits from
LLONSIT/Wave-Race-64#92 (closed upstream unmerged) and everything after them, and points at `5764666`;
see Milestone 3.

## Setup (one time)

These are the commands that produced the baseline below. Needs the system packages
`mips-linux-gnu` binutils, `gcc`, `make`, `python3` with `venv`, and your own dump of the
US Rev 1 ROM (`waverace64.us.rev1.sha1` holds its checksum). The ROM is never committed.

```bash
git clone https://github.com/nickallevato/wr64-decomp.git && cd wr64-decomp
git submodule update --init --recursive

python3 -m venv .venv && . .venv/bin/activate
pip install -r tools/splat/requirements.txt GitPython colour capstone
pip install git+https://github.com/matt-kempster/m2c
pip install pynacl toml Levenshtein        # the permuter's own requirements
pip install colorama watchdog               # asm-differ (./diff)

make toolchain                              # tools/n64crc + tools/ido-static-recomp/build/5.3/out/cc
git clone https://github.com/simonlindholm/decomp-permuter tools/decomp-permuter

cp /path/to/your/Wave\ Race\ 64.z64 baserom.us.rev1.z64    # your own dump; *.z64 is ignored by git
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
  recompiles the C files that define the named functions and every file with an
  `#ifdef NON_MATCHING` block, runs the full `make`, and exits 0 only if it prints
  `waverace64.us.rev1.z64: OK`, the gcc check pass reported no warning or error beyond
  `tools/fork/warnings-baseline.txt` (upstream's existing ones), and each defining file is
  linked (in `build/waverace64.us.rev1.map`). Then prints the progress line.
  A mismatch: `python3 first_diff.py` locates the first differing address; `./diff <func>` shows the asm diff.
- Call `check.sh` from the worktree you are checking (`tools/fork/check.sh`, the copy in that
  worktree): it `cd`s into the repository it lives in, so running the main checkout's copy
  checks the main checkout, whatever the current directory is.
- A function counts as done only when `check.sh` passes on the commit that adds it.
- `tools/fork/remote-check.sh <name> <commit>...`: runs `check.sh` on each commit on
  na-workhorse (or `$WR64_REMOTE`), which has its own extracted checkout at the same path.
  It pushes the local branches there first, so unpushed commits work, and resolves commit
  names (`HEAD`, branch names) locally. Use it for the
  one-by-one recheck of a batch's commits and for merge reviews, to keep full rebuilds off
  the local machine.

## The loop

One function per worktree; every step runs from the worktree root with `. .venv/bin/activate`.

1. **Start.** `tools/fork/start.sh <func> <file.c>`, then `cd ../wr64-decomp-wt/<func>`.
2. **Draft.** Start from `m2c/<func>.c`. Prefer an existing prototype (`include/`, the same `.c`,
   other callers in `src/`) and the style of a matched sibling. Replace the `#pragma GLOBAL_ASM`
   line with the C. Then `make extract`, so splat drops the function's `.s` (without it the
   progress count does not move).
3. **Diff.** `./diff <func>` (watch mode: rebuilds on save). One-shot:
   `python3 tools/asm-differ/diff.py <func> --no-pager --max-size <size in bytes / 4>` (`--format json` gives
   `current_score`; 0 = clean). Don't pass `-s`: it is `--stop-at-ret` and scores only up to the first `jr ra`.
   Milestone 4 re-scored every set-aside without it (see "Milestone 4"); the notes in the source and the
   scores quoted in this file are those.
   Check the function's rodata (floats, strings, jump tables) moved with it.
4. **Permute,** only if stuck and within the cap (about 2 h per function, about 1 h of it permuter):
   `tools/decomp-permuter/import.py <c file> <asm file>`, then
   `tools/decomp-permuter/permuter.py nonmatchings/<func> -j4`.
5. **Prove.** `tools/fork/check.sh <func>`: must print `check: OK` and the count must rise by one.
6. **Commit** on `match/<func>` (`<func>: <what it is> in C`). Push the branch to `origin` if wanted.
7. **Merge.** The coordinator merges `--no-ff` into `main`, runs `make extract` and
   `tools/fork/check.sh <func>` again there, and pushes `main`.

**Commit rule.** `FORK.md` and `tools/fork/` changes always get their own commits; a game-code
commit (`src/`, `include/`, `linker_scripts/`, ...) never includes fork files. A rename or names
commit stays within one area: separate commits for, for
example, the text printer, the popups and the portraits.

A struct or type change that also changes the text of functions already in C (a field split into
an array, a global turned into an array) goes in its own commit, before the function that needs
it: `<file>: <struct> layout` (or `<symbol> type`), listing the matched functions it touches. A
function commit holds that function plus only the declarations it needs (its prototypes and
externs arrive in the same commit as their first caller). Mark every hack: `// FAKE` on each
fake construct, a short comment on stack pads, odd literal forms (`seg + 5U`) and gotos, and
`// fallthrough` where a case falls through.

**A 0 from `./diff` can be stale.** When the gcc check pass fails, make stops before the object is
rebuilt, and `./diff` (or any script reading `build/`) compares the old object and can score 0.
Only `tools/fork/check.sh` counts as proof.

**`make NON_MATCHING=1` leaves its objects behind.** That build writes non-matching objects into
`build/`, and a later plain `make` reuses them, so the ROM stops matching for no visible reason.
Run `make clean` (or `rm -rf build`) before going back to normal builds.

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
| `func_801E5554` | `src/codeseg/B3AA0.c` | 40 / 71200 | the popup cards. One register swap in case 4 (loop counter and IDO's strength-reduced texture-offset temp take `$t0`/`$t1` the wrong way round; it spans six instructions); frame and everything else match | about 1 h by hand and 50 min of permuter, then a 15 min retry and 10 min more permuter, nothing helped |
| `func_801F4120` | `src/codeseg/BCFF0.c` | 58563 / 490800 | LAP, RANK and SPEED (0x4CB0 bytes, about 4,900 instructions). Same control flow and frame; register allocation and scheduling differ throughout. The `1.8f` is `D_80227A4C` in the original | about 40 min by hand and 10 min of permuter |

`func_801E5554` is one register swap (six instructions) from done; `func_801F4120` is a long way off.

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

## Milestone 2

Goal: the HUD and menu code in `src/codeseg`, file by file in six batches, smallest functions
first, each within a size-based cap. The batches ran on 2026-10-24, roughly 03:30 to 08:30, two
workers at a time, plus reviewers (merges `509ed40`, `650b0ca`, `5898c63`, `bfab8dd`, `2d92e88`, `8c602c9`).

**Count (`tools/progress.py`): 1080 -> 1197 of 1472 (73.37% -> 81.32%); 384132 of 838772
bytes (45.80%).** 117 functions matched, 25 set aside. `src/codeseg` is now 192 of 219.

### Matched, by file

| File | Matched | What it is | Batch time |
|---|---|---|---|
| `A95D0.c` | 65 of 70 (all but the five below; the file is now 73 of 78) | the per-player camera scripts: script runners and steps (`UnkA95D0_Runner`, `UnkA95D0_Step`), keyed camera objects of types 1, 2/3 and 5, spline samplers and a clamped cubic B-spline basis (`func_801DE690`), the C-button view switching (`func_801DE3CC`), and the camera matrices (`func_801E11B4`) | 17 min (35) and 1 h 50 (30) |
| `AF8C0.c` | 6 of 7: `func_801E1290`, `Initials_DrawLetterWheel`, `Initials_DrawPanel`, `Initials_UpdateInput`, `Initials_SaveToRecords`, `func_801E1E8C`; and the file's `.data` (29 one-letter strings) | the initials entry after a record: letter wheel, panel, input, the record writes, the EEPROM save | 55 min |
| `B66E0.c` | all 16 | the text printer (`Printer_*`): glyphs, quads, strings, numbers, times, the mode setup and the colour cycles | 42 min |
| `B97B0.c` | 19 of 23: ten `GameState_Enter*` switches (demo, course overview, rider select, course select, race, time-trials and stunt results, options, change names, ceremony), `func_801EB180` (title screen), `func_801ECE50`, `func_801ED004`, and six matrix helpers (`func_801EE228`, `EE46C`, `EE698`, `EE8C0`, `EE91C`, `EE97C`) | the switches to a new screen (each saves `gGameState` in `gPrevGameState` and sets one `GAME_STATE_*`), and the scale/rotate/translate matrix helpers | 55 min |
| `BCFF0.c` | 8: `Hud_BlendColorSets`, `Hud_SetupMatrices`, `Hud_DrawGuideArrow`, `Hud_UpdateStartCountdown`, `Hud_DrawStartLights`, `Hud_DrawMarkers`, `Hud_UpdateOffCourseCountdown`, `func_801F23A0` | the race HUD's colour blend, matrices, guide arrow, start countdown and lights, markers, off-course countdown, and a 0-180 eased per-rider value | 2 h 40 for the whole "rest of codeseg" batch |
| `B3AA0.c` | 2: `Popup_UpdateCard1`, `Popup_UpdateCard2` | popup card types 1 and 2 | (same batch) |
| `wr64_fade.c` | 1: `func_801E7908` | the fade overlay draw (a screen rectangle, or the wipe display lists) | (same batch) |

### Set aside (C under `#ifdef NON_MATCHING`; asm-differ score / the function's maximum, re-measured in milestone 4)

| Function | File | Best | What differs |
|---|---|---|---|
| `func_801DB8F0` | A95D0 | 220 / 41400 | register allocation drifts by one temp in the second loop; the first sqrt result is in `fa1`, not `fa0` |
| `func_801DC274` | A95D0 | 739 / 10000 | each `D_80228190` store gets its own `lui` where the original shares one; the step index is in `v0`, not `a1` |
| `func_801DCD34` | A95D0 | 4833 / 35900 | IDO keeps `&D_802287DC` in a saved register; the original reloads it with `lui` |
| `func_801DF744` | A95D0 | 5965 / 32100 | `obj` stays on the stack, not in `s0`; the frame is 8 bytes short |
| `func_801DC60C` | A95D0 | 13057 / 45800 | register allocation; the original keeps `center` on the stack and `gSinTable`/`D_80228190` in `s7`/`fp` |
| `func_801E1BA8` | AF8C0 | 1460 | the four `D_802288E8[0..3] = 0` stores use the hoisted base in `v1`; the original uses one `lui at` and four `sb` |
| `func_801EE4D0` | B97B0 | 239 | two products sit 4 bytes lower on the stack, and `arg4` loads one store later |
| `func_801EE6F4` | B97B0 | 275 | only the `arg4` load, one store later (swaps two float registers) |
| `func_801EE274` | B97B0 | 4879 | `ys`/`zxt` stay in registers (frame 0x60, not 0x68) |
| `func_801EE040` | B97B0 | 6045 | `c` and the 1.0f get no callee-saved register (frame 0x68, not 0x70) |
| `func_801F2060` | BCFF0 | 300 | every temp register is one higher in the original from the first index product on |
| `func_801F8DD0` | BCFF0 | 1360 | one extra early temp, loop constants in other registers, end-block store order |
| `func_801FA3C0` | BCFF0 | 6660 | the original counts `j` in 0x14-byte steps against `gRiders * 20` (linear-function test replacement) |
| `func_801F25E0` | BCFF0 | 12816 | same instructions; the frame is 0x18 smaller and `y` is not in `s0` |
| `func_801EF504` | BCFF0 | 10863 | the literal at `0x80227A34` is an extern (see the lessons), so its address is hoisted into `s7` |
| `func_801EED70` | BCFF0 | 10726 | global addresses kept in registers; frame 0x40 vs 0x28 |
| `func_801F9EA0` | BCFF0 | 10788 | float registers; the original keeps the camera position and direction on the stack |
| `func_801F0E7C` | BCFF0 | 10992 | the hoisted constants (300.0f, 8.0f) take the saved registers and `i` is spilled |
| `func_801E3EE0` | B2510 | 588 | `isBlock`/`segs` swap `v0`/`v1` and are spilled after the loop guard |
| `func_801E3698` | B17D0 | 3453 | `gdl` in `s2`, not `s3`; frame 0xC0 vs 0xB8 |
| `func_801E4FE8` | B3290 | 3450 | `&D_80228920` kept in a register for the load and the store |
| `func_801E4C60` | B3290 | 12434 | float registers: `ux`/`uy`/`uz` stay in saved registers across `sqrtf` in the original |
| `func_801FAEB8` | C94E0 | 1287 | the float constants take other saved FP registers; the literal is a stand-in local (see the lessons) |
| `func_801FBFB4` | C94E0 | 9598 | loop register allocation and constant hoisting; frame 0xD8 vs 0xE0 |
| `func_801FB514` | C94E0 | 12094 | the original keeps two dead computations that IDO deletes here |

Milestone 1's two set-asides were revisited and stay as they were: `func_801E5554` (40, one
`t0`/`t1` swap in case 4) and `func_801F4120` (its note carries the score, 58563 / 490800).

### Names

Renamed at the end of the milestone (branch `batch/m2-names`), one commit per area, only where the
code shows it: calls into known functions, `GAME_STATE_*` and `GMODE_*` values, the file's own data
(strings, display-list tables), and fields already named.

- **Printer** (`B66E0.c`): `Printer_DrawGlyph`, `_DrawQuad`, `_PrintTime`, `_DrawTime`, `_Print`,
  `_PrintScaled`, `_SetMode`, `_GetGlyph`, `_CycleColorMode3`..`9`, `_ResetColorCycle`, `_DrawNumber`;
  `gPrinterWidthsFont0`..`6`, `gPrinterLastFont`, `gPrinterMode`, `gPrinterCornerR/G/B`,
  `gPrinterColorCycle` (`PrinterColorCycle`: `enable`, `phase`, `timer`, `period`) and its initial value.
- **Popups** (`B3AA0.c`): `Popup_UpdateCard1`, `_UpdateCard2`, `_UpdatePauseCursor`, `_UpdateCard4`,
  `_FindFreeSlot`, `gPopupSlotInit`.
- **HUD** (`BCFF0.c`): the seven `Hud_*` above, `gHudColorStep/Frame`, `gHudMarkers`,
  `gHudMarkerColorStep/Frame`, `gStartLightsState`, `gStartLightsOffset(Max)`, `gHudPerspNorm`.
- **Game states** (`B97B0.c`): `GameState_Enter*` for the fifteen switches to a named state.
- **Initials entry** (`AF8C0.c`): `Initials_*`, `gLetterWheel*`, `gInitials*`.

Kept on purpose, because the parallel `batch/C6C0` names them in `src/game` (rename after it
merges): `func_801E9858` (the string printer), `func_801EAFB4`, `D_80228A40`, `func_801E5470`,
`func_801E6A4C`, `func_801E7908`, `func_801E71A8`, `func_801EB180`, `func_801ECAF4`,
`func_801E1290`, `func_801E1E8C`, `D_80228A90`. Set-asides keep their names (the `GLOBAL_ASM` path
uses them). A95D0's camera code keeps `func_`/`UnkA95D0_*` names: what it does is clear, but no
known call or constant names it yet.
(The twelve kept names were all renamed in milestone 3; the A95D0 script runners and steps still
keep their `func_`/`UnkA95D0_*` names.)

### What we learned

- **Data can move to C with one token.** AF8C0's 36 `GLOBAL_ASM` entries were 7 functions and 29
  one-letter strings. Writing the file's data in C and changing its yaml line from `data` to `.data`
  removed all 29 and let `func_801E1290` match. The per-file `GLOBAL_ASM` count overstates the work;
  `progress.py` counts functions.
- **Pointer loop variables change the program.** `for (i = 0, e = D_80228190; i < n; i++, e++)` is
  not `e = &D_80228190[i]` to IDO: aliasing, induction variables and the stack all move. That took
  `func_801DD2D0` from 1140 to 0 and `func_801DB8F0` from 4383 to 220. The other way round also
  happens: indexing a global array directly (`D_80227888[step][k]`) instead of through a row pointer
  matched `func_801EE9C0` and halved `func_801FAEB8` and `func_801F8DD0`; a pointer initialised to a
  global is copy-propagated into plain `lui`/`%lo` accesses.
- **Float literals stranded in another file's data.** `D_80227A24`..`D_80227A58` are BCFF0/C94E0
  rodata, but splat put them in F6010's data blob. As externs, IDO hoists their addresses or values
  into saved registers, where the original loads them with `lui at` each time. That blocks
  `func_801EF504` and `func_801FAEB8`, and probably part of `func_801F9EA0`, `func_801F0E7C` and
  `func_801FB514`. The fix is a rodata migration of that range, not more source changes. The same
  kind of split error puts AF8C0's last 2*pi 4 bytes into B17D0 (`D_80226330`).
- **Source shape that mattered:** locals declared in the original's order (stack slots follow it);
  one variable per value (reuse forces a saved FP register); `/ 4` (int) stays a `div.s`, `/ 4.0f`
  becomes `* 0.25f`; a float constant as a function-scope `static` (`func_801E1290`); chained
  assignments (`a = b = 0`) for store order; reading a just-stored global back; a separate symbol
  where the original has one (`D_800DB58C`, not `D_800DB568 + 0x24`); IDO orders stores by source
  line, so three statements on one line can match where three lines do not (`func_801E946C`).
- **Matrix builders are their own problem.** All four B97B0 set-asides fail on which named float
  locals IDO keeps on the stack. A fresh look at the four together may pay off, starting with the
  239 and 275.
- **The permuter rarely helped.** It found the four `if (1) {}` in `func_801E2058`, a temp in
  `func_801E229C`, a chained `= 0` in `func_801EBD28`, and hinted at the line joining in
  `func_801E946C`. Most runs (several hours in total, on a second machine) found nothing. A small local
  variant tester (apply N source variants, score each with asm-differ in seconds) found more.
- **A 0 from `./diff` can be stale** (see "The loop"): when the gcc check pass failed, the object was
  never rebuilt and asm-differ scored the old one. Only `check.sh` counts.
- **Batches of near-identical functions are fast.** A95D0 part 1 (35 script steps and samplers)
  took 17 minutes; the printer's 16 took 42. Above about 0x400 bytes most functions hit the cap.
- **Checking an older commit needs its own `make extract`:** extract writes only the remaining
  `GLOBAL_ASM` files, so a tree extracted at a later commit lacks the `.s` of functions matched since.

### Open follow-ups

- Move `D_80227A24`..`D_80227A58` into BCFF0/C94E0's rodata (unblocks `func_801EF504` and
  `func_801FAEB8`); re-split AF8C0/B17D0 at the right boundary (`D_80226330`).
- Near misses worth a short retry: `func_801E5554` (40), `func_801DB8F0` (220), `func_801EE4D0` (239),
  `func_801EE6F4` (275), `func_801F2060` (300), `func_801DC274` (739), `func_801E3EE0` (588),
  `func_801E1BA8` (1460). `func_801F4120` stays at 58563 / 490800.
- Types that disagree between files, to settle in a shared header: `D_800DAB60` (`s16` in B97B0,
  `s32[]` in code_4C750; settled in milestone 4), `D_800EAC44`/`D_800EAC14` (2-D vs 1-D), `D_103B4D0` (`u32[]` vs `u8[]`),
  `D_7000000` (`u8[]` vs `Mtx*`), `func_801E9858`'s argument (`s8*` vs `u32`); `D_80228120` is used
  both as `f32[][2]` and `f32[24]`; `camera_unk_1.unk8` is declared `s32` but holds a float.
- Local types and externs to hoist when a second file needs them: the `UnkA95D0_*` types,
  `PrinterColorCycle` (B17D0's `func_801E3698` and `func_i6_802C5C2C` also use
  `gPrinterColorCycle`), the record-entry structs in AF8C0, the `D_10xxxxx` segment externs; the
  letter-wheel display lists are still numeric segment addresses.
- The names kept for `batch/C6C0` (list above), once it merges. Done in milestone 3.

## Milestone 3

Goal: `src/game`, the race, rider, water and save code, in batches of one or two files, plus the
overlays' functions that davkdavk's open pull request had already done. The batches ran on
2026-10-24 (roughly 06:30 to 16:30): two workers at a time up to the code_43DA0/code_4F850 batch
(`batch/C6C0` beside milestone 2's last batch, water beside 52CD0), then one worker at a time at
the owner's request ("burn things down a little more slowly"), with the coordinator reviewing
inline while a worker ran. Merges: `1fd16e6`, `3e29f75`, `6862b57`, `7b17b76`, `f2c4405`, `2340fd3`, `5764666`,
`3789333`.

### Count, and the recount

**`tools/progress.py`: 1072 -> 1170 of 1347 (79.6% -> 86.9%): +98 matched**, measured with the tool as
it is now (it skips symbols of size 0; see the note after the table). Milestone 2 closed at 1197 of
1472 on the old scale; the same commit (`8c602c9`, before the code_C6C0.c merge) counts 1072 of 1347
today. The table below keeps the numbers the batches printed at the time, which still count the 25
size-0 symbols and so sit 25 above the current tool (1195 of 1372 at the `3789333` merge is 1170 of
1347 now). 1133 is where it stood after the third merge, the first one
that carried the recount.

The recount: `code_52CD0.c`'s rodata was a separate blob, and moving it into the C file (a2704f4)
turned its 100 jump-table labels (`.L8009C304`, ...) from `F` symbols into plain labels.
`tools/progress.py` counts every `F` symbol in the ELF, so those 100 labels had been counted as
matched functions on both sides of the fraction. Nothing real changed state. Every count before
the 52CD0 merge is 100 too high in both numbers; from there on the total is 1372.

| After merge | Matched / total | Batch |
|---|--:|---|
| `3872f73` (milestone 2 names) | 1110 / 1372 (1210 / 1472 on the old scale, with C6C0) | code_C6C0.c, +13 |
| `3e29f75` | 1116 | water_69D0.c, +6 |
| `6862b57` | 1133 | code_52CD0.c, +17 (the first count after the recount) |
| `7b17b76` | 1137 | water second pass, +4 |
| `f2c4405` | 1145 | code_43DA0.c and code_4F850.c, +8 |
| `2340fd3` | 1149 | the save file and small files, +4 |
| `5764666` | 1191 | the PR #92 port, +42 |
| `3789333` | 1195 | the large functions, +4 |

Note on the count: until `ef24ff5`, `tools/progress.py` counted every `F` symbol in the ELF,
including 25 of size 0 that have no `.s` file: 22 `*ABS*` overlay entry addresses (`func_802C5B78`,
`func_802C5F6C`, ..., the raw addresses `code_4C750.c` calls, and `func_801ED338`) and the three
microcode `*TextEnd` markers. They counted as matched. The tool now skips every size-0 symbol, so the
true figure is 1170 of 1347 and the table above, which was taken before that, is 25 high in both
numbers. The five overlay draw functions that `code_4C750.c` calls by raw address still have their
`func_i*` names, but not because of the count: renaming them no longer changes it. Nothing in the code
names them yet.

### Matched and set aside, by batch

Scores are asm-differ's current / maximum with only that function's C enabled
(`--max-size` = the function's size; lower is closer), as re-measured without `-s` in milestone 4; the lists
keep the batches' order. Function names are the addresses used when
the batch ran; the names commits below renamed many matched ones, and set-asides keep theirs (the
`GLOBAL_ASM` path uses them).

**code_C6C0.c** (31 entries): matched 13: `func_8006977C`, `80067BFC`, `800694B8`, `800683A0`,
`80067C6C`, `80061708`, `80068538`, `80053C08`, `80069798`, `80067810`, `80061FEC`, `8006719C`,
`800618F4` (rider part matrices and display lists, the stick rescale, the sphere push-apart, the
orbit camera). Set aside 18 (scores re-measured alone, also in each note in the source): `80067E40` 1680 / 34400, `800629A8` 2090 / 29800, `80064C0C` 1805 /
102700, `80061184` 4338, `80063C88` 6362, `8006390C` 11133, `800609EC` 6603, `80065C18` 7624,
`800624CC` 7979, `800665B0` 9308, `80054130` 9938, `800534AC` 14660, `800687A4` 14356,
`80051EC0` 22584, `80062E50` 41018, `8005B510` 54770, `80057B24` 83692, `8005DE24` 101742 (the last
two are the m2c structure kept for reading).

**water_69D0.c** (19 entries): first pass matched 6 (`8004F1EC`, `8004EFB4`, `8004F520`,
`80050F8C`, `8004CC7C`, `8004E614`), set aside 13. Second pass (`batch/water-2`) matched 4 more
(`8004F790`, `8004C998`, `8004D018`, `80051238`; the file's `.data` moved to C for the function-scope
statics) and brought four closer. Left, nine: `8004D30C` 24 / 19900, `8004DAF0` 532, `8004E0A4`
2500, `8004D628` 2600, `8004EAA4` 8325, `8004F9E0` 13359, `80050B78` 18761, `8004C1D0` 22795,
`80050204` 33384.

**code_52CD0.c** (26 entries; four already had C under `NEEDS_RODATA`): rodata moved to C first
(the recount above), then matched 17: `80099AD8`, `800ADC8C`, `8009934C`, `8009D96C`, `800ADF90`,
`8009C2CC`, `800A10E4`, `800A16F0`, `800A1CFC`, `800A2308`, `8009F398`, `8009FCB0`, `8009DC10`,
`800AAAC8`, `800AD418`, `800A2B24`, `800A063C`. Set aside 9: `800AB25C` 60 / 39700, `8009D6B0` 315
(also needs the unreferenced `D_800EB54C`, now owned by it in `symbol_addrs.txt`), `800A52D8` 320,
`800998B0` 904 (matched later by the PR port), `800AC098` 1710, `800A9D48` 1810, `800AB95C` 4743,
`800AC184` 10230, `800A68A4` 16348.

**code_43DA0.c and code_4F850.c** (17 entries): matched 8: `80091CD8`, `800963CC`, `800961B8`,
`80096694`, `8008E4B0`, `800916B4`, `8008D94C`, `8008FB74`. Set aside 9: `80091DBC` 30 / 9800
(needs this file's `.data` for a function-scope static; the boundary near `D_800DA920` is
unclear), `80096048` 60, `unk_game_load` 913, `8008D454` 2180, `8008BD2C` 2741, `8008DFD0` 3190,
`80096960` 13917, `8008E794` 20256, `8008A0E0` 75435.

**The save file and small files** (16 entries across wr64_save.c, code_3A580.c, code_383C0.c,
code_43A60.c, code_3AC00.c and code_5480.c): matched 4: `8007C494`, `8007BEA4`, `8007C604`,
`8004BC98` (after moving code_5480's `.data` and `.bss` to C). Set aside 10: `8007F030` 245 /
26200, `8007FD80` 530, `8007D2D4` 931, `800890B4` 1285, `8007D614` 4441, `8007B630` 4527,
`8007B930` 4557, `8007FFA8` 7464, `8004B1B4` 8621, `8007DF4C` 23088. Two older set-asides were
looked at and left: `80088EA8` (330 in the old note, 225 measured then, 330 again without `-s`, with a note; one register
copy fewer than the original) and `80085510` 4370 / 27700 (upstream's decomp.me score of 105 is on another scale).

**The PR #92 port**: 42 functions, all matched, none set aside (below).

**The large functions** (16 entries across code_2FB10.c, code_2C670.c, code_24B00.c and
code_68A10.c): matched 4: `800AE7C4`, `80077F5C`, `80073E6C`, `800744EC`. Set aside 12:
`800AFBD0` 876 / 84200, `800735EC` 1105, `80076378` 3003, `80079528` 3995, `800B2ABC` 10560,
`80075310` 13908, `800B305C` 19964, `800783AC` 24854, `8007687C` 43461, `80071E70` 52762,
`800B08F8` 51543, `8006E674` 135881.

In all, 66 set-aside bodies come from the milestone (68 in `src/game` with the two older ones); each
compiles under gcc and under IDO (`make NON_MATCHING=1` builds every object; only the final link
fails, on `__osThreadTail_fix` from upstream's `libultra_internal.h`) and has a note with its score.

### The PR #92 port

davkdavk's pull request LLONSIT/Wave-Race-64#92 was closed upstream unmerged ("We won't be
accepting AI generated contributions"). It was based on master `e00a55f`, and 84 of its 132
functions overlapped ones already done here, so a git merge would have conflicted across the
headers. Instead its 48 functions that were not yet in C were taken one by one. Six were in files
the `src/game` batches were already working on (code_43DA0 2, code_4F850 3, wr64_save 1) and had
been matched there before the drafts arrived, so no commit credits them. The other 42 were ported
in `batch/pr92-port`: 38 overlay functions, two audio, `func_800741A4` and `func_800998B0` (which
replaced our 904 set-aside); the logic needed no change. Commit bodies read "Ported from LLONSIT/Wave-Race-64#92 (davkdavk)". To
keep his history in ours, his five commits were pushed as `port/pr92-davkdavk` (GitHub PR #1) and
`5764666` is a merge commit whose parents are `2340fd3`, the port batch's tip and his `949d50c`,
with exactly the batch tip's tree. So `main`'s tree is what was reviewed, and his commits are in
its history. Where both versions matched, ours won. Hacks he documented stay marked (the
intentionally uninitialised `var_v0` in `func_i11_802C5D48`, FAKE temps in `func_i5_802C5850`, a
stack pad in `func_i13_802C6068`).

### Names, hack marks and header tidies (`batch/m3-names`)

Names, one commit per area, each only where the code or a report shows the meaning (a call into a
named function, a `GAME_STATE_*` or course value, a libultra call, a string, or a fact the reports
state with its evidence; the commit body gives each one's evidence):

- the twelve milestone 2 names left for `code_4C750.c` (`Printer_DrawString`, `Popup_Spawn`,
  `FadeTransition_Draw`, `GameState_EnterTitleScreen`, `Initials_Update`, `gStartCountdown`, ...);
- `wr64_save.c`: `Save_PackRecord`/`UnpackRecord`, `Save_EepromWrite*`, `Save_MergePakImage`,
  `gSaveImage`, `gBestTimes`, `gStuntRecords`, ...;
- water: `Water_Stamp*`, `Water_Update`, `gWaterField`, `gWaterWindow`, ...;
- riders and race: `Rider_*`, `Riders_PushApart`, `Race_RankUnfinishedRiders`, `Course_*`,
  `gPlayer1Rider`, `gRiderRaceState`, and RiderStruct fields (`raceTime`, `lapTime`, `power`,
  `progress`, ...);
- camera: `camera_unk_1`'s `eyeX..upZ` (they are `guLookAt*`'s arguments), `Camera_*`,
  `Spline_EvalClampedBSpline`;
- overlays: `SaveLoad_*`, `ChangeNames_*`, `CourseSelect_*`, `RaceResults_Update`.

A rename of a data symbol or of a function that asm still calls needs a line in
`linker_scripts/us/rev1/symbol_addrs.txt` (name = address), because the extracted `.s` files take
their names from it; `ovl_symbols.txt` holds the code segment's function names. `tools/fork/check.sh`
no longer compares the function name inside gcc's "passing argument N of 'f'" warnings, so
renaming such a function needs no baseline edit.

Hack marks (comments only): the unmarked gotos and m2c labels in the `func_8005DE24` and
`func_80057B24` set-asides, the `loop_1` goto in `func_800967EC`, two stack pads, an unused static,
and a note for `func_80088EA8`.

Header tidies (each byte-neutral, its own commit, listing the matched functions it touches):
`UnkStruct_801C43F8.unk3600` renamed `unk3608` (named by the offset of its first light, like
`unk35D8`); one definition each for `UnkStruct_80192420`, `UnkStruct_801BB138` and
`UnkStruct_80228AE0` in `structs.h`; `UnkStruct_801AE948` and `UnkStruct_80198368` merged (they were
the same 0xB2F0-byte buffer); `DIRLIGHT_DIRECTION` renamed `INV_SQRT3`. Not done: the types listed
under "Open follow-ups" below.

### What we learned

**Process**

- **Count with the same ruler.** A rodata move can change which symbols `progress.py` sees (the 100
  jump-table labels, the 22 absolute symbols). Diff the `F` symbols of the ELF before and after a
  change that moves data into C, and report a recount as a recount.
- **Struct work and merges.** Batches that carve the same shared struct conflict textually in
  `structs.h` (RiderStruct's carves from two batches, GfxPool, `UnkStruct_801C43F8`). Resolving by
  hand is safe when the carves sum to the same sizes; check offsets with a compile-time assert, and
  note that the check pass is `gcc -m32` while IDO's layout can differ (measure with IDO itself:
  `typedef char c[(sizeof(T) == N) ? 1 : -1];` warns 654 when false).
- **Score each function alone**, with `--max-size` set to the function's own size. The default 1024
  lines cuts large functions short, and a score taken while a neighbour also differs includes the
  shift. To score a set-aside without linking `NON_MATCHING=1`, switch its `#ifdef` to `#if 1` in a
  scratch copy of the worktree. A score of 0 can be a failed build that scored the stale object.
- **Permuter hygiene.** `pkill -f permuter.py` kills other workers' runs, and stopping a run by its
  `timeout`/`permuter.py` PIDs leaves its forkserver workers running. Start each run under `setsid`
  and stop it with `kill -- -<pgid>`. The permuter's scorer ignores stack offsets, and its printer
  puts each macro statement on its own line, so display-list-heavy functions did not benefit.
- **A worker that reports "waiting on background work" may be waiting on nothing.** Check the
  machine and stop it.

**IDO 5.3**

- **Function-scope statics** compile differently from file-scope globals: each access gets its own
  `lui` and the address is not kept in a register. Statics land in `.data`/`.bss` after the file's
  globals, so matching them needs the file's data in C first (water_69D0, code_5480, code_68A10);
  that was a yaml split plus defining the data in address order.
- **Index shapes.** Direct `D_801C2938[i].x = ...` stores let IDO keep globals in temporaries
  across the block; `rider = &D_801C2938[i]; rider->x = ...` reloads them (3995 vs 11395 in
  `func_80079528`), but not always: it is something to try both ways. A pointer to a global (`s32*
  p = &G`) reproduces separate `lui`s but costs alias reloads (a FAKE).
- **Literals.** `180 - x` and `180.0f - x` do not share one constant load; where the original loads
  a constant twice, one use is an integer literal. `x * 1.0f` is folded away, `x * 1` is not; `/ 2`
  stays a `div.s`, `/ 2.0f` becomes `* 0.5f`; `.0f` and `0.0f` differ to the optimizer.
- **Statement order and shape.** `a = b = c = 0` stores `c` first (reverse the chain to change the
  store order); IDO orders stores by source line, so three statements on one line can match where
  three lines do not; `(j << 7) << 2` is not `j << 9`; declaration order sets stack slots (count
  the slots above and below a known spill and add or reorder locals); an unused declared local can
  renumber registers.
- **Jump tables show the cases.** A table that starts at 1 with its first entry pointing at the
  join means `case 1: break;` (a semantic fix in `Course_SetupObjects`). splat's `lui at,%hi(A)`
  followed by `sw x,%lo(B)(at)` stores to B, not A.
- **A 2-byte-aligned struct copy** compiles to `lwl`/`lwr`; the original goes through a
  word-aligned type.
- **Big functions** (`func_800A2B24`, 0x27b4 bytes) matched from m2c's structure after three
  systematic fixes; functions that need no callee-saved registers at all (`func_800783AC`) did not.
  A local variant tester (apply N text replacements to one function, rebuild, score) found most
  fixes in seconds per variant.

### Open follow-ups

- The five overlay draw functions called by raw address from `code_4C750.c` (named in milestone 4);
  the `UnkA95D0_*` script runners; the near set-asides: `func_8004D30C` (24), `func_80091DBC` (30,
  needs the file's `.data`), `func_800AB25C` (60), `func_80096048` (60), `func_8007F030` (245),
  `func_8004DAF0` (532), `func_800AFBD0` (876), `func_80067E40` (1680).
- Types still describing the same object two ways: `RiderStruct` and `struct UnkStruct_801C2938`
  (and `struct_800762D0`); `UnkStruct_8004B0F8` and `UnkStruct_80192690`; `D_800DACD0` and
  `D_80227A60` (17 words, `s32` vs `Gfx*`); `D_801C26E8` (several local types, `CourseRecord.time` is
  the stunt score); `camera_unk_1.unk8` (`s32` that holds a float); `GfxPool + 0x185E8` (written as
  `unk170D8 + 0x151`, a separate 16 x 8-vertex block); `D_80228A78`/`D_103B4D0` locals; `UnkStruct_801BFA48` and `UnkStruct_801BFB70`, each defined in both
  code_2C670.c and code_24B00.c (`UnkStruct_801BFB70.unk0` is `f32` in one and `s32` in the other).
- The yaml splits for `.data`/`.bss` (water_69D0 at `0x8EE80`, code_5480, code_68A10's bss) will
  conflict with any future change in those ranges.
- Local macros kept on purpose: `RIDER_CP_TIME` (code_2FB10.c), `gSP1QuadrangleLP` (code_68A10.c),
  `BUOY_FADE` (code_24B00.c).
- The `(0, x)` comma casts left by upstream in code_24B00.c, code_383C0.c and code_3AC00.c are
  unmarked fakes.

## Milestone 4

Goal: `src/overlays`, the per-course and per-screen code that loads on demand: 62 functions still in
assembly across 17 overlay files at `e75eb6d`. Five batches ran on 2026-10-24 and 25 (roughly 17:20 to
00:45), one worker at a time at the owner's request, each reviewed and merged by the coordinator:
`cd77e28` (ovl_i1), `b7131d4` (ovl_i2, ovl_i0), `2d33d43` (ovl_i9, ovl_i8), `50004e2` (ovl_i5,
ovl_i13), `f40b21d` (ovl_i3, i4, i6, i7, i10, i11, i12, i14, i15). Then `batch/m4-names` (this section's
names, tidies and re-score).

### Count, and the ruler change

**`tools/progress.py`: 1170 / 1347 -> 1224 / 1348 (86.9% -> 90.8%); matched bytes 56.2% -> 64.5%.**
`src/overlays` (the `ovl_i0`..`ovl_i15` `.text` sections in the linker map) went from 88 / 150 to 142 / 151.
(The plan and the old README gave the base as 92 / 158 overlays and 40 / 47 other, from a split that
can't be reproduced; by `.text` section the base is 88 / 150 overlays and 44 / 55 other.)

| After merge | Matched / total | Batch |
|---|--:|---|
| `cd77e28` | 1180 / 1347 | ovl_i1, the race overlay: +10, 1 set aside |
| `b7131d4` | 1190 / 1347 | ovl_i2 rider select and ovl_i0 title/main menu: +10, 2 set aside |
| `2d33d43` | 1200 / 1347 | ovl_i9 view records and ovl_i8 change names: +10, all matched |
| `50004e2` | 1211 / 1347 | ovl_i5 race results and ovl_i13 save/load: +11, 1 set aside |
| `f40b21d` | 1224 / 1348 | the nine small overlays: +12 and one new function, 5 set aside |

The ruler change: splat had folded an unnamed empty function (`jr ra; nop` at 0x802C6E94 in ovl_i3) into
`func_i3_802C6344`'s size. The last batch made it its own C function, `func_i3_802C6E94`, so the ELF
has one more sized `F` symbol and the total is 1348. It counts as matched, so by the old ruler the
milestone ends at 1223 / 1347: 53 functions matched, 9 set aside. Check the end of a large function's
asm for a second `jr ra; nop` before trusting splat's size.

### Matched and set aside, by batch

Names are the ones `batch/m4-names` gave (the old `func_i<N>_<vram>` is the address). Set-asides keep
their `func_` names (the `GLOBAL_ASM` path uses them); scores as in "Re-score" below.

- **ovl_i1** (race states 0x28 to 0x2D and the demo): matched `func_i1_802C6B38` (2P timers),
  `Race_StartScroller`, `Race_EnterState29`, `RaceStandings_Step`, `Race_Draw`, `Race_EnterState2A`,
  `Race_UpdateState2A`, `Race_UpdateInRace`, `RaceStandings_Update`, `RaceStandings_DrawTable` (PR #92's
  C for `RaceStandings_Step`, fixed). Set aside `func_i1_802C6BD8` (the Dolphin Park scroller's draw)
  265 / 12500, register allocation only.
- **ovl_i2, ovl_i0**: matched `RiderSelect_Init`, `TitleScreen_DrawScroller`, `RiderSelect_DrawPicture`,
  `RiderSelect_DrawBackground`, `RiderSelect_OverlayUpdate`, `MainMenu_DrawRows`, `MainMenu_Draw`,
  `RiderSelect_Draw1P`, `RiderSelect_Draw2P`, `RiderSelect_DrawPlayer`; ovl_i0's `.data` moved into C
  (yaml `.data`) and ovl_i2's `.bss` defined in C. Set aside `func_i0_802C63AC` (main menu input)
  1035 / 30700 and `func_i2_802C5E28` (rider select input) 590 / 59300 (one `beqz` + delay slot that
  IDO makes `beqzl`).
- **ovl_i9, ovl_i8**: all ten: `ChangeNames_ClearName`, `ChangeNames_PressKey`,
  `ViewRecords_DrawCourseList`, `ViewRecords_OverlayUpdate`, `ChangeNames_Input`,
  `ChangeNames_OverlayUpdate`, `ViewRecords_DrawPanels`, `ChangeNames_DrawScreen`, `ViewRecords_Input`,
  `ViewRecords_DrawRecordsPanel`. `structs.h` carves `UnkStruct_801CE5F8.unkA80[8]` and `unk1280[8]`.
- **ovl_i5, ovl_i13**: matched `NotQualified_DrawObjects`, `NotQualified_Draw`, `SaveLoad_DrawMessageBox`,
  `RaceResults_CheckQualified`, `NotQualified_DrawPanels`, `NotQualified_Update`, `SaveLoad_Step8Popup`,
  `NotQualified_UpdateAnimation`, `SaveLoad_OverlayUpdate`, `SaveLoad_DrawMessage`,
  `RaceResults_DrawTable` (the last is ovl_i1's `RaceStandings_DrawTable` with small changes). Set aside
  `func_i13_802C711C` (the save/load screen draw) 695 / 106000: the original keeps a row's y (186) in a
  variable it does not fold.
- **the small overlays**: matched `PostRaceMenu_Draw`, `func_i3_802C5800`, `OptionsMenu_DrawItems`,
  `TimeTrialsResults_OverlayUpdate`, `PostRaceMenu_DrawMenu`, `EraseCourseRecords_Input`,
  `AudioOptions_Draw`, `EraseCourseRecords_DrawScreen`, `ChangeConditions_Input`,
  `TimeTrialsResults_DrawPanel`, `CourseSelect_DrawScreen`, `func_i3_802C6344` (+ the new empty
  `func_i3_802C6E94`). Set aside `func_i10_802C6200` 359 / 51200 (stack layout only),
  `func_i15_802C5800` 505 / 31400 (register allocation only), `func_i15_802C602C` 1717 / 76400,
  `func_i4_802C6778` 1845 / 14700, `func_i3_802C5D54` 4465 / 38000.

The nine overlay set-asides compile under gcc (the check pass) and are scored alone; each has a note.

### Names, tidies and notes (`batch/m4-names`)

Byte-neutral tidies, one commit each: `TexLabel` in `structs.h` for the `{ s16 x; s32 texture; }` label
type seven overlays each defined; `UnkStruct_801CE5F8.unkC80` as `Mtx[8][3]` (three matrices per rider
model, one per `unkA80`/`unk1280` slot; it absorbed the padding after it, offsets unchanged);
`D_800DAB60` (`s16`) and `D_801CE72E` (`u16`, read with `lhu` everywhere) declared once in `variables.h`;
ovl_i15 and ovl_i3 (93060d6) use `gRiderRaceState[].unk338`, not a misplaced `RiderStruct` view
`D_801C2C70[].lapCount` (main code's `code_24B00.c` still writes it through that view);
`UnkStruct_func_i8_802C6E00` renamed `PlayerName` (the `gPlayerNames` element, which four other overlays
used under an ovl_i8 name).

Overlay `.bss`: the 95 symbols the overlays' C uses past each overlay's `BSS_START` were `D_802C....`;
they are `D_i<N>_<vram>` now, each with a `symbol_addrs.txt` entry `//segment:ovl_i<N>` (the addresses
overlap between overlays). ovl_i0's cursor row `D_i0_802C6EE4` is also read by main code
(`Popup_UpdatePauseCursor` places its slot on the main menu's rows), which now uses the overlay's name.

Function names, one commit per overlay, from `GAME_STATE_*` transitions, the draw and update switches
in `code_4C750.c`, calls into named functions and the batches' facts (each commit body gives the
evidence). The pattern per screen: `<Screen>_OverlayUpdate` (the function at 0x802C5800, which
`code_4C750.c`'s update switch calls by address), `<Screen>_Draw` (the draw switch's entry, which also
runs the input and, after the fade, enters the next screen), `<Screen>_Input`, `<Screen>_Leave` (sets
the screen's "leaving" state and `D_801CE630` with a fade), and helpers. Screens: `TitleScreen_`,
`MainMenu_` (ovl_i0), `Race_`, `RaceStandings_`, `Demo_` (ovl_i1), `RiderSelect_`, `CourseOverview_`,
`CourseSelect_`, `RaceResults_`, `NotQualified_` (GAME_STATE_5A, entered when the championship points
miss the race's threshold), `TimeTrialsResults_`, `OptionsMenu_`, `ChangeNames_`, `ViewRecords_`,
`ChangeConditions_`, `AudioOptions_`, `EraseCourseRecords_`, `SaveLoad_`, `PostRaceMenu_`
(GAME_STATE_50, entered after the results screens), `Ceremony_`. Not renamed: the set-asides,
`func_i3_802C5800` (see below), and helpers with no evidence yet.

`symbol_addrs.txt` gets every new name with its segment, except the addresses that main code calls as
raw `func_802Cxxxx` symbols (`func_802C5A7C`, `func_802C5AE4`, ...: the draw switch's entries,
`Race_Leave`, `RaceStandings_Update`, `NotQualified_UpdateAnimation`). With an entry, splat names those
main-code references after the overlay's function, drops the raw symbol from `undefined_funcs_auto.ld`,
and the link fails. Collisions count: `RiderSelect_Init` (ovl_i2) and `EraseCourseRecords_Input`
(ovl_i12) sit at addresses main code calls for ovl_i1 and ovl_i13. Each skipped name is listed in a
comment. `code_4C750.c` calls every overlay's 0x802C5800 entry under ovl_i3's name
(`func_i3_802C5800`) and some draws under seg_1C3D00's (`func_1C3D00_802C5800`); comments say so now, and
`func_i3_802C5800` keeps its name until that call is given a neutral symbol.

Hack marks: the batches had marked every hack in the overlay files; one m2c comment was dropped.

### Re-score

Until milestone 4 the briefs and this file said `diff.py -s`, which is `--stop-at-ret`: it scores only up
to the first `jr ra`. Every `#ifdef NON_MATCHING` set-aside under `src/` (104) was re-scored alone on
na-workhorse: in a scratch worktree only that `#ifdef` becomes `#if 1`, a full `make`, then
`diff.py <func> --no-pager --max-size <symbol size / 4> --format json`, and the file is restored.
Measured at `f40b21d` and at this branch's tip: the same except `func_8007687C` (43646 -> 43461, from the
`D_801CE72E` type). Against the notes: 50 scores were too low (the largest gaps:
`func_8006390C` 6123 -> 11133, `func_80050204` 26108 -> 33384, `func_800AFBD0` 666 -> 876), one too high
(`func_8007FFA8` 7764 -> 7464), three maxima differed, eight notes had no score. Every note now gives
"Score N of M" (85 edited), and the numbers this file quotes in milestones 1 to 3 are corrected in place.

### What we learned

**Process**

- **Gate a commit on check.sh's own status.** `check.sh ... | tail -2 && git commit` commits on `tail`'s
  status; it happened once. Run it unpiped or test `${PIPESTATUS[0]}`.
- **`tools/fork/remote-check.sh <name> <sha>...`** runs check.sh per commit on na-workhorse and keeps
  full rebuilds off the local machine; batches 4 and 5 and this branch used it. At first it resolved
  a ref like `HEAD` in the remote checkout, so it once checked the remote's own `HEAD` here and said OK;
  it now resolves every commit name locally and refuses one that isn't a commit.
- **A `symbol_addrs.txt` entry changes what splat calls every reference to that address,** including
  main code's raw `func_802Cxxxx` and other overlays' data at the same vram. Rename, re-extract and
  link before believing a rename is free; `check.sh` does not run `make extract`.
- **Scoring needs only the one object rebuilt.** The 104 re-scores took a few minutes on na-workhorse
  with `-j12`: switch one `#ifdef`, `make`, `diff.py`, restore. The remote's venv lacks `watchdog`, which
  diff.py imports only for watch mode; an empty stub module on `PYTHONPATH` is enough.

**IDO 5.3**

- **Data defined in the file shares `lui at`.** With the symbol defined in the same C file (initialised
  `.data`, or an uninitialised definition, which goes to the file's `.bss` in declaration order), IDO
  emits consecutive stores as one `lui at` and `sw x, %lo(sym+off)(at)`; with an `extern` it reloads the
  `lui` per store or keeps the base in a register. Two functions matched only after their overlay's
  `.data`/`.bss` moved into C.
- **Stack slot order follows declaration order.** Every declared local owns a slot from the top of the
  locals area, used only if it spills, so a spilled variable's offset tells how many locals come before
  it; unused frame space at the top needs a marked pad.
- **Loop and index shapes**: IDO fully unrolls 4-iteration loops (four if-blocks over consecutive words
  are often a loop), and some unrolled loops rotate their store order, which a do-while fixes; an index
  local keeps a product together (`idx = row * 7 + col`); `i == x - 1` and `i + 1 == x` differ to
  partial redundancy elimination; `((Mtx(*)[3]) p)[i]` (now `unkC80[i]`) where the original multiplies by
  0xC0 once.
- **Types steer moves**: `u32` globals are loaded into temporaries and moved into argument registers
  where `s32` ones are not; an int `0` compare is not a `0.0f` one; `/ 4` stays `div.s`, `/ 4.0f`
  becomes `* 0.25f`.

### Open follow-ups

- Give `code_4C750.c`'s calls to 0x802C5800 neutral symbols (one `void(void)` for the update switch,
  one `Gfx*(Gfx*)` for the draw switch) instead of ovl_i3's and seg_1C3D00's names; then
  `func_i3_802C5800` can be named.
- The near overlay set-asides: `func_i1_802C6BD8` (265), `func_i10_802C6200` (359, stack only),
  `func_i15_802C5800` (505), `func_i2_802C5E28` (590, one delay slot), `func_i13_802C711C` (695).
- Still `.s`: ovl_i2's `.data` (its `D_i2_802C8BD8` runs into `.rodata`), ovl_i8's and ovl_i9's
  `.data`, ovl_1C17E0's five `D_i5_802C7Axx`.
- Record entry views that disagree: `UnkStruct_AF8C0_14` vs wr64_save.c's `UnkStruct_func_8007AF78_1`,
  and `UnkStruct_AF8C0_10` vs B17D0.c's `CourseRecord` and wr64_save.c's `UnkStruct_800D8578`.
- `Popup_UpdatePauseCursor` places its slot on ovl_i0's main menu rows, so its name may be wrong.
- Data and helper names in the overlays (`D_i<N>_...`, `UnkStruct_i<N>_...` field names, the
  unnamed helpers listed in each names commit).
- Possible original bugs kept as the asm has them: `ViewRecords_OverlayUpdate` places both panel
  coordinates from `unk0`; `ViewRecords_DrawRecordsPanel` draws kind 3's lap dashes at y + 302 and
  passes an unused argument to `sprintf(buf, "-", ...)`.

## Milestone 5 (in progress)

Goal: the 124 functions still in assembly at `a0a7efa`: the closest set-asides first, then `src/sys`,
`src/audio`, the unused segment and `seg_1C3D00` (never attempted), then the remaining set-asides by
score band, largest last; names and a final review at the end. Plan:
`docs/superpowers/plans/2026-10-25-decomp-milestone-5.md` in the wr_64_exe repo. Batches ran 2026-10-25
to 29, each reviewed and merged by the coordinator; from 2026-10-28 the workers ran at medium effort. Done
so far: Tasks 1-13 (every set-aside band has had at least one pass), codeseg's `.bss` split per file, and an
audit of the greedy statement moves. Next: Task 14 (names, a sweep of the FAKEs, the final review) and
further passes on the largest set-asides.

### Count

**`tools/progress.py`: 1224 / 1348 -> 1286 / 1348 (90.8% -> 95.4%); matched bytes 64.5% -> 74.2%.**

| After merge | Matched / total | Batch |
|---|--:|---|
| `86576d4` | 1226 / 1348 | `func_8004D30C`, `func_80096048`; `tools/fork/score.sh` |
| `9c2fdcd` | 1228 / 1348 | `func_801E5554`, `func_80091DBC` (after code_43DA0's `.data` tail moved into C) |
| `9165e6f` | 1233 / 1348 | five set-asides scored 220-330 |
| `d6dc10f` | 1235 / 1348 | `func_800A52D8`, `func_i15_802C5800`; `code_52CD0.c` split |
| `4bd66b9` | 1239 / 1348 | four near-misses (Opus head-to-head) |
| `34d769a` | 1242 / 1348 | `func_80088EA8`, `func_i10_802C6200`, `func_i2_802C5E28` |
| `b6ec626` | 1243 / 1348 | `SysMain_Thread`; eight sys/audio functions as C, set aside |
| `4602b20` | 1252 / 1348 | nine of eleven in `segment_1B1FB0` and `seg_1C3D00` |
| `afe8f66` | 1253 / 1348 | `AudioGeneral_PlaySound`; `C94E0.c` merged into `BCFF0.c` |
| `6698635` | 1255 / 1348 | `func_8004DAF0`, `func_8007D2D4` |
| `9a8ca79` | 1259 / 1348 | `func_i15_802C602C`, `func_800AC098`, `func_800A9D48`, `func_i4_802C6778` |
| `c49e3d0` | 1262 / 1348 | `func_801E1BA8`, `func_80067E40`, `func_80064C0C` |
| `3ccb48c` | 1266 / 1348 | `func_8004E0A4`, `func_8004D628`, `func_801E4FE8`, `func_801E3698` |
| `11f3e63` | 1268 / 1348 | `func_801DC274`, `func_800629A8` |
| `399a76b` | 1274 / 1348 | `func_80079528` (`code_2FB10`'s `.bss` split), `func_8007D614`, `func_8007B630`, `func_8007B930`, `func_800AB95C`, `func_801EE274` |
| `db1da95` | 1277 / 1348 | `func_801DCD34`, `func_800609EC`, `func_800624CC` |
| `eaa7c97` | 1279 / 1348 | `func_801F0E7C`, `func_8006390C` |
| `0d71cd8` | 1280 / 1348 | `func_801EE040` |
| `76a9347` | 1281 / 1348 | `func_8008BD2C` (`code_43DA0`'s `.bss` split) |
| `c3972fa` | 1283 / 1348 | `func_800735EC`, `func_1B1FB0_802C71B8` |
| `6c6864c` | 1283 / 1348 | codeseg's `.bss` split per file (with `3e014f5`) |
| `5f6f0c2` | 1285 / 1348 | `func_1B1FB0_802C6C1C`, `func_800B2ABC` |
| `e55e6c2` | 1286 / 1348 | `func_8007FFA8` |

No batch changed the set of sized `F` symbols (each data move was checked with a sized-`F`-symbol diff of
the ELF before and after); `SysMain_Thread`'s size went 1744 -> 1732 when its trailing `nop` padding left
the symbol; `func_80079528`'s went 4136 -> 4132 the same way.

### Matched and moved, by batch

- **Closest set-asides** (24 to 60 points off): `func_8004D30C` (water), `func_80096048`, `func_801E5554`
  (the popup cards, one register swap away since milestone 1), `func_80091DBC`. `func_800AB25C` matched
  later, in the head-to-head.
- **Near (220-330)**: `func_801EE4D0`, `func_801EE6F4`, `func_i1_802C6BD8` (the Dolphin Park scroller's
  draw), `func_8007F030`, `func_801DB8F0`.
- **Mid (315-739)**: `func_800A52D8`, `func_i15_802C5800`. `code_52CD0.c` was two objects: a second one
  starts at `func_8009D6B0` (its first word, `D_800EB54C`, was rodata padding), now `code_57EB0.c`, with
  its later functions and set-asides.
- **Head-to-head** (Opus 5.5 against Sonnet 5.5 on the same five near-misses, same brief): Opus matched
  `func_8007FD80`, `func_801E3EE0`, `func_800AB25C`, `func_8009D6B0` in 44 minutes and took
  `func_801F2060` from 25 to 10; Sonnet matched one in 66 minutes for about as many tokens. From then on
  every matching worker is Opus (see `CLAUDE.md`).
- **Opus batch of five**: `func_80088EA8` (random numbering of the `D_801C3C60` entries),
  `func_i10_802C6200` (the panel `ChangeConditions_Draw` draws), `func_i2_802C5E28` (rider select input).
- **sys and audio**: `SysMain_Thread` (segment addresses, start-up, the frame loop). It needed a second
  linker name for one address (`D_1008290_2`, marked FAKE), because the original materialises it twice.
  `sys_utils.c`'s `.data` (`Seed`, `D_800D4644`) moved into C. Eight others are readable C, set aside.
- **The unused segment and `seg_1C3D00`**: `segment_1B1FB0` is the boot-time Controller Pak note manager
  (list, delete, page counts). Matched: its draw function, input, note list, five image-strip draws, a
  scroller and `seg_1C3D00`'s "1P - 2P" menu. Set aside `func_1B1FB0_802C6C1C` and
  `func_1B1FB0_802C71B8`.
- **Band 1, Step 1**: the HUD's float constants in the `F6010` data blob showed that `C94E0.c` was the
  second half of `BCFF0.c`: one rodata block holds both files' strings, then both files' floats. The two
  are one file now, and the blob is its `.rodata`. `AudioGeneral_PlaySound` matched; eight set-asides got
  closer.
- **Nearest leftovers**: `func_8004DAF0` (water damping of a body's points; two old FAKEs gone) and
  `func_8007D2D4` (the Controller Pak save read).

- **2026-10-28/29** (Opus at medium effort, about 90k tokens per match): 31 functions matched (1255 -> 1286)
  and most of the rest came closer; the unused segment is complete. Two game objects (`code_2FB10` at
  0x801C3A00, `code_43DA0` at 0x801C4170) and then all of codeseg (0x80227A60-0x80228E0F) got their `.bss`
  split per file, replacing FAKE definitions and pads; `resolve.txt` names the in-object addresses the code
  uses. A greedy statement-move search was the biggest single gain on large functions; an audit found and
  undid the one move that swapped dependent statements (`func_800B305C`).

### What we learned

**Process**

- **`tools/fork/score.sh <func>`** scores one set-aside alone (its `#ifdef` switched on in a scratch copy,
  one object rebuilt, `diff.py` with the right `--max-size`). Every note's "Score N of M" comes from it.
- **Prove each commit remotely.** Workers commit, run `remote-check.sh <name> HEAD` unpiped, and amend on
  failure; only single-object compiles and `diff.py` run locally. A new worktree gets its build from
  na-workhorse (build `main` there, tar `asm bin build mio0` and the generated linker scripts, untar,
  then touch the outputs newer than the sources) instead of a local full build.
- **Opus for matching.** On near-misses it was faster and cheaper per match than Sonnet (about 82k tokens
  per match); free OpenRouter models made no progress. Caps of about 30 min / 1 h / 2 h by size held up:
  most matches came early, and a function that resisted an hour of Opus rarely moved later in the cap.
- **A worker that waits on its own background loop can outlive its work.** Two shell loops polling for a
  permuter output that never came were found still running two days later. A worker stops every loop it
  starts before it reports.

**IDO 5.3**

- **Differently spelled float zeros are separate constants:** `0.f`, `0.00f` and `0e0f` are not `0.0f`
  (`0.0F` is), and that decides where a zero is loaded and which saved registers hold what
  (`func_801F9EA0`, 1800 -> 120). Likewise `0` vs `0.0f` and `100000.0` vs `100000.0f`.
- **`--n` in a loop condition** puts the counter's first decrement in the delay slot; **stores in
  struct-field order** fixed a float-register swap no single statement move could.
- **Pass a value through a local or a global:** the right edge as `x = 560 - i * 18`, or a loop reading back
  through the global it just set, matched two functions with no FAKE.
- **Matched siblings are the best start** (`tools/fork/similar.py`); twins matched in minutes once one did.
- **Source lines steer scheduling.** Two statements on one line let a constant load move ahead of a stack
  reload. The permuter's import reformats the source and loses such joins, so its base score can be worse
  than the local one.
- **A field read twice with no store between becomes a CSE temporary,** coloured differently from locals:
  reading `pt->unkC` directly, not through a local, put `func_8004DAF0`'s second point in callee-saved
  registers with no FAKE.
- **A local for a repeated subexpression** (`step`, `k`, `entry`) fixed a whole function's register
  numbering three times; **reusing a variable** (a loop counter, a narrow local for an unrelated value)
  can set the colouring of the whole function.
- **`v = &arr[i]` per iteration stops strength reduction;** `v = base; v += i` puts the base first in the
  address add.
- **Falling off the end keeps v0 live,** including a switch whose cases the original returns straight
  from; an empty `if (x) {}` at the end keeps `x` live; `do {} while (0)` is a register-allocation block
  boundary with no code.
- **Conditions written as `switch`** give the original's compare operand order.
- **gbi display-list macros don't survive the permuter's import** (token pasting such as
  `G_IM_SIZ_8b_SHIFTL` breaks; with `--preserve-macros=` the base score is far worse), so on
  display-list-heavy functions it rarely helps.

### Open follow-ups

- Nearest set-asides: `func_801F2060` 10, `func_80054130` 15, `func_801F8DD0` 30, `func_80063C88` 40,
  `func_800890B4` 55, `func_8008D454` 70, `func_801F9EA0` 120, `func_801E4C60` 130. Most have had three or
  more tries.
- Many recent closer attempts rely on permuter FAKEs (`do {} while (0)`, `while ((u64) 0)`, empty `if (1)`,
  line joins); a sweep should replace them with real shapes where it can.
- Give 0x80045650 a symbol (now written `&gAudioGlobalsEndMarker + 3`, splat's naming of an unnamed
  address).
- Names (Task 14) and the final review.
