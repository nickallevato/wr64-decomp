#include "common.h"

extern f32 gPrinterScale;   /* glyph scale, set by func_801E93B4 */
extern s16 gPrinterScaled;  /* 1 while the scaled printer is in use; func_801E93B4 leaves it set */

typedef struct {
    /* 0x00 */ s16 unk0;  /* nonzero: func_801EAFB4 steps unk2 */
    /* 0x02 */ s16 unk2;  /* 0..3, advanced every unk8 frames */
    /* 0x04 */ s32 unk4;  /* frame counter */
    /* 0x08 */ s32 unk8;  /* frames per step */
    /* 0x0C */ s16 r; /* prim colour, set by func_801E946C */
    /* 0x0E */ s16 g;
    /* 0x10 */ s16 b;
    /* 0x12 */ s16 unk12;
} UnkStruct_80228A78; /* size = 0x14 */

extern u8 D_80226D70[]; /* glyph widths, font 0 */
extern u8 D_80226D98[]; /* glyph widths, the other fonts */
extern u8 D_80226DC4[]; /* glyph widths, font 2 */

extern s32 D_80228A40; /* next free vertex in D_801CE5F8->unk40 */
extern u8 D_7000000[];

extern UnkStruct_80228A78 D_80228A78;
extern UnkStruct_80228A78 D_80226E30; /* initial value, copied by func_801EAF78 */

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E80B0.s")

/* Draws a w x h quad at (x, y), scaled, with corner colours r0..b3 (Gouraud), from the D_801CE5F8->unk40 vertex pool. */
Gfx* func_801E8800(Gfx* gdl, u32 w, u32 h, s32 x, s32 y, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1, u8 r2, u8 g2,
                   u8 b2, u8 r3, u8 g3, u8 b3, f32 scale) {
    Vtx* vtx;
    s32 i;

    for (i = 0; i < 4; i++) {
        vtx = &D_801CE5F8->unk40[D_80228A40 + i];
        if (i == 1 || i == 3) {
            vtx->v.ob[0] = (s32) (w * scale) + x - 1;
            vtx->v.tc[0] = (w * 2 + 1) << 5;
        } else {
            vtx->v.ob[0] = x;
            vtx->v.tc[0] = -0x20;
        }
        if (i == 2 || i == 3) {
            vtx->v.ob[1] = (s32) (h * scale) + y - 1;
            vtx->v.tc[1] = (h * 2) << 5;
        } else {
            vtx->v.ob[1] = y;
            vtx->v.tc[1] = -0x20;
        }
        vtx->v.ob[2] = 0;
        vtx->v.flag = 0;
        if (i == 0) {
            vtx->v.cn[0] = r0;
            vtx->v.cn[1] = g0;
            vtx->v.cn[2] = b0;
        } else if (i == 1) {
            vtx->v.cn[0] = r1;
            vtx->v.cn[1] = g1;
            vtx->v.cn[2] = b1;
        } else if (i == 2) {
            vtx->v.cn[0] = r2;
            vtx->v.cn[1] = g2;
            vtx->v.cn[2] = b2;
        } else {
            vtx->v.cn[0] = r3;
            vtx->v.cn[1] = g3;
            vtx->v.cn[2] = b3;
        }
        vtx->v.cn[3] = 0xFF;
    }
    gSPVertex(gdl++, D_7000000 + (D_80228A40 * 0x10) + 0x40, 4, 0);
    gSP1Triangle(gdl++, 0, 3, 1, 0);
    gSP1Triangle(gdl++, 0, 2, 3, 0);
    D_80228A40 += 4;
    if (D_80228A40 >= 0x78) {
        D_80228A40 = 0x74;
    }
    return gdl;
}

/* Sets the printer's mode and corner colours, then has func_801E8B24 print arg2 (the time-trial best times) at (x, y). */
Gfx* func_801E8A84(Gfx* gdl, s32 font, s32 arg2, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3) {
    gdl = func_801E946C(gdl, mode, (s32) r0, (s32) g0, (s32) b0, (s32) r1, (s32) g1, (s32) b1,
                        (s32) r2, (s32) g2, (s32) b2, (s32) r3, (s32) g3, (s32) b3);
    return func_801E8B24(gdl, font, arg2, x, y);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8B24.s")

/* r0..b3: RGB of the four glyph-quad corners (the recomp passes top, top, bottom, bottom). */
Gfx* func_801E92FC(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3) {
    gPrinterScale = 1.0f;
    gdl = func_801E946C(gdl, mode, (s32) r0, (s32) g0, (s32) b0, (s32) r1, (s32) g1, (s32) b1,
                        (s32) r2, (s32) g2, (s32) b2, (s32) r3, (s32) g3, (s32) b3);
    gPrinterScaled = 0;
    return func_801E9858(gdl, font, str, x, y);
}

/* Prints str in font at (x, y) at the given scale: sets the printer's mode and corner colours, then prints. */
Gfx* func_801E93B4(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3, f32 scale) {
    gPrinterScale = scale;
    gdl = func_801E946C(gdl, mode, (s32) r0, (s32) g0, (s32) b0, (s32) r1, (s32) g1, (s32) b1,
                        (s32) r2, (s32) g2, (s32) b2, (s32) r3, (s32) g3, (s32) b3);
    gPrinterScaled = 1;
    return func_801E9858(gdl, font, str, x, y);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E946C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9858.s")

/* Glyph index of character c in font, or 0xFF for a space; 0 for a character the font lacks. */
s32 func_801E9B04(s32 font, s8 c) {
    s32 glyph = 0;

    if (c >= '0' && c <= '9') {
        glyph = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        switch (font) {
            case 0:
            case 1:
            case 2:
                glyph = c - 'A' + 10;
                break;
        }
    } else if (c == '/') {
        switch (font) {
            case 5:
                glyph = 0xA;
                break;
            case 2:
                glyph = 0x28;
                break;
        }
    } else if (c == '-') {
        switch (font) {
            case 0:
            case 1:
                glyph = 0x24;
                break;
            case 2:
                glyph = 0x25;
                break;
        }
    } else if (c == '\'') {
        switch (font) {
            case 0:
            case 1:
                glyph = 0x25;
                break;
            case 2:
                glyph = 0x26;
                break;
            case 3:
                glyph = 0xA;
                break;
        }
    } else if (c == '@') {
        switch (font) {
            case 0:
            case 1:
                glyph = 0x26;
                break;
            case 2:
                glyph = 0x27;
                break;
            case 3:
                glyph = 0xB;
                break;
        }
    } else if (c == '&') {
        if (font == 2) {
            glyph = 0x24;
        }
    } else if (c == '.') {
        switch (font) {
            case 0:
                glyph = 0x27;
                break;
            case 2:
                glyph = 0x29;
                break;
            case 1:
                glyph = 0x29;
                break;
        }
    } else if (c == '|') {
        if (font == 2) {
            glyph = 0x2A;
        }
    } else if (c == '<') {
        if (font == 2) {
            glyph = 0x2B;
        }
    } else if (c == '>') {
        if (font == 2) {
            glyph = 0x2C;
        }
    } else if (c == '\n') {
        if (font == 1) {
            glyph = 0x28;
        }
    } else if (c == '+') {
        if (font == 2) {
            glyph = 0x2D;
        }
    } else if (c == ' ') {
        glyph = 0xFF;
    }
    return glyph;
}

/* Colour cycle for D_80228A78 by phase: red -> yellow -> white -> yellow -> red. */
void func_801E9D6C(void) {
    switch (D_80228A78.unk2) {
        case 0:
            D_80228A78.r = 255;
            D_80228A78.g = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
        case 1:
            D_80228A78.r = 255;
            D_80228A78.g = 255;
            D_80228A78.b = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            break;
        case 2:
            D_80228A78.r = 255;
            D_80228A78.g = 255;
            D_80228A78.b = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            break;
        case 3:
            D_80228A78.r = 255;
            D_80228A78.g = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
    }
}

/* Colour cycle for D_80228A78 by phase: black -> red -> yellow -> red -> black. */
void func_801EA0B0(void) {
    switch (D_80228A78.unk2) {
        case 0:
            D_80228A78.r = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 0;
            D_80228A78.b = 0;
            break;
        case 1:
            D_80228A78.r = 255;
            D_80228A78.g = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
        case 2:
            D_80228A78.r = 255;
            D_80228A78.g = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
        case 3:
            D_80228A78.r = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 0;
            D_80228A78.b = 0;
            break;
    }
}

/* Colour cycle for D_80228A78 by phase: green -> yellow -> white -> yellow -> green. */
void func_801EA3EC(void) {
    switch (D_80228A78.unk2) {
        case 0:
            D_80228A78.r = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 255;
            D_80228A78.b = 0;
            break;
        case 1:
            D_80228A78.r = 255;
            D_80228A78.g = 255;
            D_80228A78.b = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            break;
        case 2:
            D_80228A78.r = 255;
            D_80228A78.g = 255;
            D_80228A78.b = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            break;
        case 3:
            D_80228A78.r = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 255;
            D_80228A78.b = 0;
            break;
    }
}

/* Colour cycle for D_80228A78 by phase: black -> green -> yellow -> green -> black. */
void func_801EA730(void) {
    switch (D_80228A78.unk2) {
        case 0:
            D_80228A78.r = 0;
            D_80228A78.g = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
        case 1:
            D_80228A78.r = (u32) ((D_80228A78.unk4 * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 255;
            D_80228A78.b = 0;
            break;
        case 2:
            D_80228A78.r = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.g = 255;
            D_80228A78.b = 0;
            break;
        case 3:
            D_80228A78.r = 0;
            D_80228A78.g = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 255.0f) / D_80228A78.unk8);
            D_80228A78.b = 0;
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EAA6C.s")

/* Sets D_80228A78's colour from its phase and timer: red and blue ramp 128 -> 255 in phases 0 and 2, back in 1 and 3. */
void func_801EADB0(void) {
    s32 c;
    s32 c2;

    switch (D_80228A78.unk2) {
        case 0:
        case 2:
            c = (u32) ((D_80228A78.unk4 * 127.0f) / D_80228A78.unk8) + 128;
            D_80228A78.r = c;
            D_80228A78.g = 255;
            D_80228A78.b = c;
            break;
        case 1:
        case 3:
            c2 = (u32) (((D_80228A78.unk8 - D_80228A78.unk4) * 127.0f) / D_80228A78.unk8) + 128;
            D_80228A78.r = c2;
            D_80228A78.g = 255;
            D_80228A78.b = c2;
            break;
    }
}

void func_801EAF78(void) {
    D_80228A78 = D_80226E30;
}

void func_801EAFB4(void) {
    if (D_80228A78.unk0 != 0) {
        D_80228A78.unk4++;
        if (D_80228A78.unk4 >= D_80228A78.unk8) {
            D_80228A78.unk4 = 0;
            D_80228A78.unk2++;
            if (D_80228A78.unk2 == 4) {
                D_80228A78.unk2 = 0;
            }
        }
    }
}

/* Prints value (0..999) in font, right-aligned so its last digit starts at x. */
Gfx* func_801EB00C(Gfx* gdl, s32 font, s32 value, s32 x, s32 y) {
    s32 i;
    s32 j;
    s32 digits[3];
    s32 v;
    s32 offset;
    s32 found;
    u8* widths;
    char buf[12];

    if (font == 0) {
        widths = D_80226D70;
    } else if (font == 2) {
        widths = D_80226DC4;
    } else {
        widths = D_80226D98;
    }
    sprintf(buf, "%d", value);
    v = value;
    for (i = 0; i < 3; i++) {
        digits[i] = v % 10;
        v /= 10;
    }
    offset = 0;
    for (i = 1; i < 3; i++) {
        if (digits[i] != 0) {
            offset -= widths[digits[i]];
            continue;
        }
        found = 0;
        for (j = i + 1; j < 3; j++) {
            if (digits[j] != 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            break;
        }
        offset -= widths[digits[i]];
    }
    return func_801E9858(gdl, font, buf, x + offset, y);
}
