#!/usr/bin/env python3
# tools/fork/similar.py: find matched functions whose code looks like a given one, as reference C.
#
#   similar.py <func> [-n N]       the N matched functions closest to <func> (default 8)
#   similar.py --unmatched [-n N]  every function still in assembly with its N closest matched ones,
#                                  most similar first (a scheduling list: start where a sibling exists)
#
# Similarity is 1 - normalised Levenshtein distance over the two functions' opcode sequences (mnemonics only,
# registers and immediates ignored), the measure ethteck/coddog uses. Pairs whose lengths differ by more than
# the cutoff allows are skipped. Opcodes come from build/waverace64.us.rev1.elf, so run `make` first; a function
# counts as unmatched when a src file still has its GLOBAL_ASM pragma.
import argparse
import os
import re
import subprocess
import sys

from rapidfuzz.distance import Levenshtein

ELF = "build/waverace64.us.rev1.elf"
OBJDUMP = "mips-linux-gnu-objdump"


def opcodes():
    out = subprocess.run([OBJDUMP, "-d", "--no-show-raw-insn", ELF], capture_output=True, text=True,
                         check=True).stdout
    funcs, name, ops = {}, None, []
    for line in out.splitlines():
        m = re.match(r"^[0-9a-f]+ <([^>]+)>:$", line)
        if m:
            if name:
                funcs[name] = ops
            name, ops = m.group(1), []
            continue
        if name and "\t" in line:
            parts = line.split("\t")
            if len(parts) >= 2 and parts[1].strip():
                ops.append(parts[1].split()[0])
    if name:
        funcs[name] = ops
    # objdump also opens a block at jump-table labels and .NON_MATCHING aliases; keep functions only
    sizes = {}
    syms = subprocess.run(["mips-linux-gnu-readelf", "-sW", ELF], capture_output=True, text=True,
                          check=True).stdout
    for line in syms.splitlines():
        f = line.split()
        if len(f) >= 8 and f[3] == "FUNC" and int(f[2], 0 if f[2].startswith("0x") else 10) > 0:
            sizes[f[7]] = int(f[2], 0 if f[2].startswith("0x") else 10)
    return {n: o[: sizes[n] // 4] for n, o in funcs.items() if n in sizes and not n.endswith(".NON_MATCHING")}


def unmatched():
    names = set()
    for root, _, files in os.walk("src"):
        for fn in files:
            if fn.endswith(".c"):
                with open(os.path.join(root, fn), errors="replace") as f:
                    names.update(re.findall(r'GLOBAL_ASM\("asm/[^"]*/([^/"]+)\.s"\)', f.read()))
    return names


def closest(target, ops, candidates, n, cutoff):
    t = ops[target]
    found = []
    for c in candidates:
        o = ops[c]
        if c == target or min(len(o), len(t)) < cutoff * max(len(o), len(t)):
            continue
        s = Levenshtein.normalized_similarity(t, o, score_cutoff=cutoff)
        if s:
            found.append((s, c))
    return sorted(found, reverse=True)[:n]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("func", nargs="?")
    ap.add_argument("--unmatched", action="store_true")
    ap.add_argument("-n", type=int, default=8)
    ap.add_argument("--cutoff", type=float, default=0.5, help="minimum similarity shown (default 0.5)")
    a = ap.parse_args()
    if not a.func and not a.unmatched:
        ap.error("give a function name or --unmatched")
    ops = opcodes()
    left = unmatched() & ops.keys()
    matched = ops.keys() - left
    if a.unmatched:
        rows = []
        for u in left:
            best = closest(u, ops, matched, a.n, a.cutoff)
            rows.append((best[0][0] if best else 0.0, u, best))
        for s, u, best in sorted(rows, reverse=True):
            sib = ", ".join(f"{c} {x:.2f}" for x, c in best) or "-"
            print(f"{u}  ({len(ops[u])} insns)  {sib}")
        return
    if a.func not in ops:
        sys.exit(f"similar: {a.func} is not a function in {ELF}")
    for s, c in closest(a.func, ops, matched, a.n, a.cutoff):
        print(f"{s:.3f}  {c}  ({len(ops[c])} insns)")


if __name__ == "__main__":
    main()
