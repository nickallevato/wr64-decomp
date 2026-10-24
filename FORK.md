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

**Commit rule.** `FORK.md` and `tools/fork/` changes always get their own commits; a game-code
commit (`src/`, `include/`, `linker_scripts/`, ...) never includes fork files. A rename or names
commit stays within one area, the size of one future upstream batch: separate commits for, for
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
| `func_801F4120` | `src/codeseg/BCFF0.c` | 58028 / 490800 | LAP, RANK and SPEED (0x4CB0 bytes, about 4,900 instructions). Same control flow and frame; register allocation and scheduling differ throughout. The `1.8f` is `D_80227A4C` in the original | about 40 min by hand and 10 min of permuter |

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
first, each within a size-based cap. The batches ran on 2026-10-24, roughly 03:30 to 08:30, up to
three at a time (merges `509ed40`, `650b0ca`, `5898c63`, `bfab8dd`, `2d92e88`, `8c602c9`).

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

### Set aside (C under `#ifdef NON_MATCHING`; best asm-differ score / the function's maximum)

| Function | File | Best | What differs |
|---|---|---|---|
| `func_801DB8F0` | A95D0 | 220 / 41400 | register allocation drifts by one temp in the second loop; the first sqrt result is in `fa1`, not `fa0` |
| `func_801DC274` | A95D0 | 539 / 10000 | each `D_80228190` store gets its own `lui` where the original shares one; the step index is in `v0`, not `a1` |
| `func_801DCD34` | A95D0 | 4582 / 35900 | IDO keeps `&D_802287DC` in a saved register; the original reloads it with `lui` |
| `func_801DF744` | A95D0 | 6006 / 32100 | `obj` stays on the stack, not in `s0`; the frame is 8 bytes short |
| `func_801DC60C` | A95D0 | 12429 / 45800 | register allocation; the original keeps `center` on the stack and `gSinTable`/`D_80228190` in `s7`/`fp` |
| `func_801E1BA8` | AF8C0 | 610 | the four `D_802288E8[0..3] = 0` stores use the hoisted base in `v1`; the original uses one `lui at` and four `sb` |
| `func_801EE4D0` | B97B0 | 239 | two products sit 4 bytes lower on the stack, and `arg4` loads one store later |
| `func_801EE6F4` | B97B0 | 275 | only the `arg4` load, one store later (swaps two float registers) |
| `func_801EE274` | B97B0 | 4439 | `ys`/`zxt` stay in registers (frame 0x60, not 0x68) |
| `func_801EE040` | B97B0 | 5846 | `c` and the 1.0f get no callee-saved register (frame 0x68, not 0x70) |
| `func_801F2060` | BCFF0 | 300 | every temp register is one higher in the original from the first index product on |
| `func_801F8DD0` | BCFF0 | 1255 | one extra early temp, loop constants in other registers, end-block store order |
| `func_801FA3C0` | BCFF0 | 5600 | the original counts `j` in 0x14-byte steps against `gRiders * 20` (linear-function test replacement) |
| `func_801F25E0` | BCFF0 | 9103 | same instructions; the frame is 0x18 smaller and `y` is not in `s0` |
| `func_801EF504` | BCFF0 | 9735 | the literal at `0x80227A34` is an extern (see the lessons), so its address is hoisted into `s7` |
| `func_801EED70` | BCFF0 | 9945 | global addresses kept in registers; frame 0x40 vs 0x28 |
| `func_801F9EA0` | BCFF0 | 10188 | float registers; the original keeps the camera position and direction on the stack |
| `func_801F0E7C` | BCFF0 | 10592 | the hoisted constants (300.0f, 8.0f) take the saved registers and `i` is spilled |
| `func_801E3EE0` | B2510 | 588 | `isBlock`/`segs` swap `v0`/`v1` and are spilled after the loop guard |
| `func_801E3698` | B17D0 | 2848 | `gdl` in `s2`, not `s3`; frame 0xC0 vs 0xB8 |
| `func_801E4FE8` | B3290 | 2885 | `&D_80228920` kept in a register for the load and the store |
| `func_801E4C60` | B3290 | 11089 | float registers: `ux`/`uy`/`uz` stay in saved registers across `sqrtf` in the original |
| `func_801FAEB8` | C94E0 | 1287 | the float constants take other saved FP registers; the literal is a stand-in local (see the lessons) |
| `func_801FBFB4` | C94E0 | 9598 | loop register allocation and constant hoisting; frame 0xD8 vs 0xE0 |
| `func_801FB514` | C94E0 | 10384 | the original keeps two dead computations that IDO deletes here |

Milestone 1's two set-asides were revisited and stay as they were: `func_801E5554` (40, one
`t0`/`t1` swap in case 4) and `func_801F4120` (its note still has no score).

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
  `func_801E946C`. Most runs (several hours in total, on na-workhorse) found nothing. A small local
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
  `func_801EE6F4` (275), `func_801F2060` (300), `func_801DC274` (539), `func_801E3EE0` (588),
  `func_801E1BA8` (610). Re-score `func_801F4120`, whose note has no score.
- Types that disagree between files, to settle in a shared header: `D_800DAB60` (`s16` in B97B0,
  `s32[]` in code_4C750), `D_800EAC44`/`D_800EAC14` (2-D vs 1-D), `D_103B4D0` (`u32[]` vs `u8[]`),
  `D_7000000` (`u8[]` vs `Mtx*`), `func_801E9858`'s argument (`s8*` vs `u32`); `D_80228120` is used
  both as `f32[][2]` and `f32[24]`; `camera_unk_1.unk8` is declared `s32` but holds a float.
- Local types and externs to hoist when a second file needs them: the `UnkA95D0_*` types,
  `PrinterColorCycle` (B17D0's `func_801E3698` and `func_i6_802C5C2C` also use
  `gPrinterColorCycle`), the record-entry structs in AF8C0, the `D_10xxxxx` segment externs; the
  letter-wheel display lists are still numeric segment addresses.
- The names kept for `batch/C6C0` (list above), once it merges.
