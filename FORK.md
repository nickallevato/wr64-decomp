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
