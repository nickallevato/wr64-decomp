#!/usr/bin/env python3
"""Draw docs/progress-map{,-dark}.svg: every function as a rectangle sized by its bytes, grouped by area and
then by source file, green when matched and amber when still assembly. Reads the built ELF, the linker map
and asm/us/rev1/nonmatchings, as tools/progress.py does; run it after a full `make`."""

import glob
import os
import re
import subprocess
import sys

ROOT = os.path.join(os.path.dirname(os.path.realpath(__file__)), "..", "..")
ELF = os.path.join(ROOT, "build", "waverace64.us.rev1.elf")
MAP = os.path.join(ROOT, "build", "waverace64.us.rev1.map")
ASM = os.path.join(ROOT, "asm", "us", "rev1", "nonmatchings")
AREAS = ["src/game", "src/codeseg", "src/audio", "src/libultra", "src/overlays", "src/sys", "other"]

THEMES = {
    "light": {"bg": "#fbfbf9", "fg": "#1c2421", "muted": "#5d6762", "ok": "#0b6e63", "no": "#d9893a"},
    "dark": {"bg": "#18201c", "fg": "#e4e9e5", "muted": "#9aa5a0", "ok": "#4fc9b8", "no": "#e0a24f"},
}
W, H = 1000, 620
LABEL = 18


def functions():
    out = subprocess.run(["objdump", "-x", ELF], stdout=subprocess.PIPE, check=True).stdout.decode()
    syms = []
    for line in out.splitlines():
        if " F " in line:
            p = line.split()
            if int(p[4], 16) and p[3] != "*ABS*":
                syms.append((p[3].lstrip("."), int(p[0], 16), int(p[4], 16), p[5]))
    # Overlays share addresses, so each function is placed by (output section, address).
    objs, cur = {}, None
    for line in open(MAP):
        m = re.match(r"^(\.?[A-Za-z_][\w.]*)\s", line)
        if m:
            cur = m.group(1).lstrip(".")
        m = re.match(r"^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(\S+)", line)
        if m and cur and int(m.group(2), 16):
            objs.setdefault(cur, []).append((int(m.group(1), 16), int(m.group(2), 16), m.group(3)))
    nonmatching = {os.path.basename(f)[:-2] for f in glob.glob(ASM + "/**/*.s", recursive=True)}
    funcs = []
    for sec, addr, size, name in syms:
        obj = next((o for s, n, o in objs.get(sec, []) if s <= addr < s + n), sec)
        obj = re.sub(r"^build/|\.o$", "", obj)
        m = re.match(r"src/(game|codeseg|audio|libultra|overlays|sys)/", obj)
        funcs.append((m and "src/" + m.group(1) or "other", obj, size, name not in nonmatching))
    return funcs


def worst(row, w):
    s = sum(row)
    return max(max(w * w * r / (s * s), s * s / (w * w * r)) for r in row)


def squarify(values, x, y, w, h):
    """Bruls et al.'s squarified layout; values sorted largest first, summing to w * h."""
    rects, i = [], 0
    while i < len(values):
        side = min(w, h)
        row = [values[i]]
        i += 1
        while i < len(values) and worst(row + [values[i]], side) <= worst(row, side):
            row.append(values[i])
            i += 1
        s = sum(row)
        if w >= h:
            rw = s / h if h else 0
            yy = y
            for r in row:
                rh = r / rw if rw else 0
                rects.append((x, yy, rw, rh))
                yy += rh
            x, w = x + rw, w - rw
        else:
            rh = s / w if w else 0
            xx = x
            for r in row:
                rw = r / rh if rh else 0
                rects.append((xx, y, rw, rh))
                xx += rw
            y, h = y + rh, h - rh
    return rects


def layout(items, x, y, w, h):
    """items: [(weight, payload)]; returns [(rect, payload)] scaled to the box."""
    items = sorted((i for i in items if i[0] > 0), key=lambda i: -i[0])
    total = sum(i[0] for i in items)
    if not items or w <= 0 or h <= 0:
        return []
    scale = w * h / total
    return list(zip(squarify([i[0] * scale for i in items], x, y, w, h), [i[1] for i in items]))


def svg(funcs, t):
    areas = {a: {} for a in AREAS}
    for area, obj, size, ok in funcs:
        areas[area].setdefault(obj, []).append((size, ok))
    matched = sum(1 for f in funcs if f[3])
    out = [
        f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {W} {H}" width="{W}" height="{H}" '
        f'font-family="ui-monospace,SFMono-Regular,Menlo,Consolas,monospace">',
        f"<title>{matched} of {len(funcs)} functions matched</title>",
        f'<rect width="{W}" height="{H}" rx="6" fill="{t["bg"]}"/>',
    ]
    pad = 4
    files_out, labels = [], []
    area_items = [(sum(s for fs in files.values() for s, _ in fs), (a, files)) for a, files in areas.items()]
    for (ax, ay, aw, ah), (area, files) in layout(area_items, pad, pad, W - 2 * pad, H - 2 * pad):
        ax, ay, aw, ah = ax + 2, ay + 2, aw - 4, ah - 4
        fs = [f for fl in files.values() for f in fl]
        text = f"{area} {sum(1 for _, ok in fs if ok)}/{len(fs)}"
        if len(text) * 7.8 + 6 > aw:
            text = area if len(area) * 7.8 + 6 <= aw else ""
        labels.append(f'<text x="{ax + 3:.1f}" y="{ay + 13:.1f}" font-size="12" font-weight="600" '
                      f'fill="{t["fg"]}">{text}</text>')
        file_items = [(sum(s for s, _ in fl), fl) for fl in files.values()]
        for (fx, fy, fw, fh), fl in layout(file_items, ax, ay + LABEL, aw, ah - LABEL):
            for (x, y, w, h), ok in layout(fl, fx, fy, fw, fh):
                out.append(f'<rect x="{x:.1f}" y="{y:.1f}" width="{w:.1f}" height="{h:.1f}" '
                           f'fill="{t["ok"] if ok else t["no"]}" stroke="{t["bg"]}" stroke-width="0.6"/>')
            files_out.append(f'<rect x="{fx:.1f}" y="{fy:.1f}" width="{fw:.1f}" height="{fh:.1f}" '
                             f'fill="none" stroke="{t["bg"]}" stroke-width="2"/>')
    return "\n".join(out + files_out + labels + ["</svg>", ""])


def main():
    funcs = functions()
    outdir = os.path.join(ROOT, "docs")
    os.makedirs(outdir, exist_ok=True)
    for name, t in THEMES.items():
        path = os.path.join(outdir, "progress-map.svg" if name == "light" else "progress-map-dark.svg")
        with open(path, "w") as f:
            f.write(svg(funcs, t))
    print(f"{sum(1 for f in funcs if f[3])} / {len(funcs)} functions drawn", file=sys.stderr)


if __name__ == "__main__":
    main()
