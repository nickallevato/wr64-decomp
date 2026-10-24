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

extern UnkStruct_80228A78 D_80228A78;
extern UnkStruct_80228A78 D_80226E30; /* initial value, copied by func_801EAF78 */

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E80B0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8800.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9D6C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA0B0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA3EC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA730.s")

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
