#include "common.h"

extern f32 gPrinterScale;  /* glyph scale, set by Printer_PrintScaled */
extern s16 gPrinterScaled; /* 1 while the scaled printer is in use; Printer_PrintScaled leaves it set */

typedef struct {
    /* 0x00 */ s16 enable; /* nonzero: func_801EAFB4 steps phase */
    /* 0x02 */ s16 phase;  /* 0..3, advanced every period frames */
    /* 0x04 */ s32 timer;  /* frame counter */
    /* 0x08 */ s32 period; /* frames per step */
    /* 0x0C */ s16 r;      /* prim colour for modes 3-9: set by the colour cycles, read by Printer_SetMode */
    /* 0x0E */ s16 g;
    /* 0x10 */ s16 b;
    /* 0x12 */ s16 unk12;
} PrinterColorCycle; /* size = 0x14 */

extern u8 gPrinterWidthsFont0[]; /* glyph widths, font 0 */
extern u8
    gPrinterWidthsFont1[]; /* glyph widths, font 1 (Printer_DrawNumber also uses it for fonts other than 0 and 2) */
extern u8 gPrinterWidthsFont2[]; /* glyph widths, font 2 */
extern u8 gPrinterWidthsFont3[]; /* glyph widths, font 3 */
extern u8 gPrinterWidthsFont4[]; /* glyph widths, font 4 */
extern u8 gPrinterWidthsFont5[]; /* glyph widths, font 5 */
extern u8 gPrinterWidthsFont6[]; /* glyph widths, font 6 */

extern s32 D_80228A40;         /* next free vertex in D_801CE5F8->unk40 */
extern s32 gPrinterMode;       /* printer mode, set by Printer_SetMode */
extern s32 gPrinterCornerR[4]; /* corner colours, set by Printer_SetMode: red */
extern s32 gPrinterCornerG[4]; /* green */
extern s32 gPrinterCornerB[4]; /* blue */
extern u8 D_7000000[];
extern u8 D_2000A40[];
extern Gfx D_106F030[];
extern Gfx D_106F0A8[];
extern s32 gPrinterLastFont; /* font of the last glyph drawn */
extern u8 D_1033CB8[];       /* glyph textures, font 0 (IA8, 24x20) */
extern u8 D_10387C0[];       /* font 1 (IA8, 8x8) */
extern u8 D_1039248[];       /* font 2 (IA8, 16x12) */
extern u32 D_103B4D0[];      /* fonts 3 and 4 (RGBA32, 12x16) */
extern u32 D_103D8D8[];      /* font 5 (RGBA32, 16x20) */

extern PrinterColorCycle gPrinterColorCycle;
extern PrinterColorCycle gPrinterColorCycleInit; /* initial value, copied by Printer_ResetColorCycle */

/* Draws glyph of font at (x, y): culls it off screen, loads its texture (IA8 fonts 0-2, RGBA32 fonts 3-5), then a
 * texture rectangle, or in mode 2 a scaled Gouraud quad (Printer_DrawQuad). */
Gfx* Printer_DrawGlyph(Gfx* gdl, s32 font, u32 glyph, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                       u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3, f32 scale) {
    u8* tex;
    s32 visible;
    u32 w;
    s32 rect;
    u32 h;
    s32 rgba32;

    rect = 1;
    if (mode == 2) {
        rect = 0;
    }
    switch (font) {
        case 0:
            if (glyph >= 40) {
                glyph = 0;
            }
            w = 24;
            h = 20;
            tex = D_1033CB8 + glyph * 0x1E0;
            rgba32 = 0;
            break;
        case 1:
            if (glyph >= 42) {
                glyph = 0;
            }
            w = 8;
            h = 8;
            tex = D_10387C0 + glyph * 0x40;
            rgba32 = 0;
            break;
        case 2:
            if (glyph >= 46) {
                glyph = 0;
            }
            w = 16;
            h = 12;
            tex = D_1039248 + glyph * 0xC0;
            rgba32 = 0;
            break;
        case 3:
            if (glyph >= 12) {
                glyph = 0;
            }
            w = 12;
            h = 16;
            // The RGBA32 textures are declared u32[] (one texel per element), so glyph * 0xC0 texels is
            // glyph * 0x300 bytes; IDO's register use matches only with this u32 arithmetic.
            tex = (u8*) (D_103B4D0 + glyph * 0xC0);
            rgba32 = 1;
            break;
        case 4:
            if (glyph >= 10) {
                glyph = 0;
            }
            w = 12;
            h = 16;
            tex = (u8*) (D_103B4D0 + glyph * 0xC0);
            rgba32 = 1;
            break;
        case 5:
            if (glyph >= 11) {
                glyph = 0;
            }
            w = 16;
            h = 20;
            tex = (u8*) (D_103D8D8 + glyph * 0x140);
            rgba32 = 1;
            break;
    }
    visible = 1;
    if (x >= 320) {
        visible = 0;
    } else if ((s32) (w * scale) + x < 0) {
        visible = 0;
    } else if (y >= 240) {
        visible = 0;
    } else if ((s32) (h * scale) + y < 0) {
        visible = 0;
    }
    if (visible == 0) {
        return gdl;
    }
    if (font != gPrinterLastFont) {
        gPrinterLastFont = font;
    }
    if (rgba32 == 0) {
        gDPLoadTextureBlock(gdl++, tex, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK,
                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    } else if (rgba32 == 1) {
        gDPLoadTextureBlock(gdl++, tex, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK,
                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }
    if (rect == 1) {
        gSPScisTextureRectangle(gdl++, x << 2, y << 2, (x + (s32) w) << 2, (y + (s32) h) << 2, G_TX_RENDERTILE, 0, 0,
                                1 << 10, 1 << 10);
    } else {
        gdl = Printer_DrawQuad(gdl, w, h, x, y, (u8) r0, (u8) g0, (u8) b0, (u8) r1, (u8) g1, (u8) b1, (u8) r2, (u8) g2,
                               (u8) b2, (u8) r3, (u8) g3, (u8) b3, scale);
    }
    return gdl;
}

/* Draws a w x h quad at (x, y), scaled, with corner colours r0..b3 (Gouraud), from the D_801CE5F8->unk40
 * vertex pool. */
Gfx* Printer_DrawQuad(Gfx* gdl, u32 w, u32 h, s32 x, s32 y, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1, u8 r2, u8 g2,
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

/* Sets the printer's mode and corner colours, then prints time (ms, as M'SS"mmm) at (x, y); the time-trial best
 * times use it. */
Gfx* Printer_PrintTime(Gfx* gdl, s32 font, s32 time, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                       u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3) {
    gdl = Printer_SetMode(gdl, mode, r0, g0, b0, r1, g1, b1, r2, g2, b2, r3, g3, b3);
    return Printer_DrawTime(gdl, font, time, x, y);
}

/* Prints time (in ms) as M'SS"mmm in font from (x, y); the separators are the fonts' ' and @ glyphs. */
Gfx* Printer_DrawTime(Gfx* gdl, s32 font, s32 time, s32 x, s32 y) {
    s32 cx;
    s32 digitW;
    s32 sep1;
    s32 sep2;
    s32 sep1W;
    s32 sep2W;
    s32 min;
    s32 sec10;
    s32 sec1;
    s32 ms100;
    s32 ms10;
    s32 ms1;

    switch (font) {
        case 0:
            digitW = 24;
            sep1 = 0x25;
            sep2 = 0x26;
            sep1W = gPrinterWidthsFont0[0x25];
            sep2W = gPrinterWidthsFont0[0x26];
            break;
        case 1:
            digitW = 8;
            sep1 = 0x25;
            sep2 = 0x26;
            sep1W = gPrinterWidthsFont1[0x25];
            sep2W = gPrinterWidthsFont1[0x26];
            break;
        case 2:
            digitW = 10;
            sep1 = 0x26;
            sep2 = 0x27;
            sep1W = gPrinterWidthsFont2[0x26];
            sep2W = gPrinterWidthsFont2[0x27];
            break;
        case 3:
            digitW = 12;
            sep1 = 0xA;
            sep2 = 0xB;
            sep1W = gPrinterWidthsFont3[0xA];
            sep2W = gPrinterWidthsFont3[0xB];
            break;
        case 4:
            digitW = 12;
            sep1 = 0;
            sep2 = 0;
            sep1W = gPrinterWidthsFont4[0];
            sep2W = gPrinterWidthsFont4[0];
            break;
        case 5:
            digitW = 16;
            sep1 = 0;
            sep2 = 0;
            sep1W = gPrinterWidthsFont5[0];
            sep2W = gPrinterWidthsFont5[0];
            break;
    }
    cx = x; // FAKE: this copy gives IDO's prologue order
    min = (time / 1000 / 60) % 10;
    gdl = Printer_DrawGlyph(gdl, font, min, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += digitW;
    gdl = Printer_DrawGlyph(gdl, font, sep1, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += sep1W;
    sec10 = ((time / 1000 % 60) / 10) % 10;
    gdl = Printer_DrawGlyph(gdl, font, sec10, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += digitW;
    sec1 = (time / 1000 % 60) % 10;
    gdl = Printer_DrawGlyph(gdl, font, sec1, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += digitW;
    gdl = Printer_DrawGlyph(gdl, font, sep2, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += sep2W;
    ms100 = ((time % 1000) / 100) % 10;
    gdl = Printer_DrawGlyph(gdl, font, ms100, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += digitW;
    ms10 = ((time % 1000) / 10) % 10;
    gdl = Printer_DrawGlyph(gdl, font, ms10, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    cx += digitW;
    ms1 = (time % 1000) % 10;
    gdl = Printer_DrawGlyph(gdl, font, ms1, cx, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                            gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                            gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                            gPrinterCornerG[3], gPrinterCornerB[3], 1.0f);
    return gdl;
}

/* r0..b3: RGB of the four glyph-quad corners (the recomp passes top, top, bottom, bottom). */
Gfx* Printer_Print(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3) {
    gPrinterScale = 1.0f;
    gdl = Printer_SetMode(gdl, mode, r0, g0, b0, r1, g1, b1, r2, g2, b2, r3, g3, b3);
    gPrinterScaled = 0;
    return func_801E9858(gdl, font, str, x, y);
}

/* Prints str in font at (x, y) at the given scale: sets the printer's mode and corner colours, then prints. */
Gfx* Printer_PrintScaled(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1,
                         u8 b1, u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3, f32 scale) {
    gPrinterScale = scale;
    gdl = Printer_SetMode(gdl, mode, r0, g0, b0, r1, g1, b1, r2, g2, b2, r3, g3, b3);
    gPrinterScaled = 1;
    return func_801E9858(gdl, font, str, x, y);
}

/* Sets the printer mode and the four corner colours, and emits the mode's render setup (display list, combiner,
 * prim colour). */
Gfx* Printer_SetMode(Gfx* gdl, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 r3, u8 g3,
                     u8 b3) {
    gPrinterLastFont = 100;
    gPrinterMode = mode;
    gPrinterScaled = 0;
    // FAKE: one line per corner (as a macro would expand); IDO orders the stores by source line
    // clang-format off
    gPrinterCornerR[0] = r0; gPrinterCornerG[0] = g0; gPrinterCornerB[0] = b0;
    gPrinterCornerR[1] = r1; gPrinterCornerG[1] = g1; gPrinterCornerB[1] = b1;
    gPrinterCornerR[2] = r2; gPrinterCornerG[2] = g2; gPrinterCornerB[2] = b2;
    gPrinterCornerR[3] = r3; gPrinterCornerG[3] = g3; gPrinterCornerB[3] = b3;
    // clang-format on
    switch (mode) {
        case 1:
            gSPDisplayList(gdl++, D_106F030);
            gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
            gDPSetPrimColor(gdl++, 0, 0, r0, g0, b0, 255);
            break;
        case 2:
            gSPDisplayList(gdl++, D_106F0A8);
            gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPMatrix(gdl++, D_2000A40, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 8:
        case 9:
            gSPDisplayList(gdl++, D_106F030);
            gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gPrinterColorCycle.enable = 1;
            switch (mode) {
                case 3:
                    Printer_CycleColorMode3();
                    break;
                case 4:
                    Printer_CycleColorMode4();
                    break;
                case 5:
                    Printer_CycleColorMode5();
                    break;
                case 6:
                    Printer_CycleColorMode6();
                    break;
                case 8:
                    Printer_CycleColorMode8();
                    break;
                case 9:
                    Printer_CycleColorMode9();
                    break;
            }
            gDPSetPrimColor(gdl++, 0, 0, gPrinterColorCycle.r, gPrinterColorCycle.g, gPrinterColorCycle.b, 255);
            break;
        case 7:
            gSPDisplayList(gdl++, D_106F030);
            gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPSetPrimColor(gdl++, 0, 0, r0, g0, b0, 255);
            break;
        case 10:
            gSPDisplayList(gdl++, D_106F030);
            gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, r0);
            break;
        default:
            gSPDisplayList(gdl++, D_106F030);
            break;
    }
    return gdl;
}

/* Prints str in font from (x, y) with the mode and colours Printer_SetMode set; a space (glyph 0xFF) only advances x.
 */
Gfx* func_801E9858(Gfx* gdl, s32 font, char* str, s32 x, s32 y) {
    s32 glyph;
    s8* s;
    s32 penX;
    s32 pad; // stack pad
    s32 space;
    s32 width;

    s = (s8*) str; // FAKE: these two copies give IDO's prologue order
    penX = x;
    while (1) {
        if (*s == 0) {
            break;
        }
        glyph = Printer_GetGlyph(font, *s);
        switch (font) {
            case 0:
                width = gPrinterWidthsFont0[glyph];
                space = 0x18;
                break;
            case 1:
                width = gPrinterWidthsFont1[glyph];
                space = 8;
                break;
            case 2:
                width = gPrinterWidthsFont2[glyph];
                space = 0xC;
                break;
            case 3:
                width = gPrinterWidthsFont3[glyph];
                space = 0xC;
                break;
            case 4:
                width = gPrinterWidthsFont4[glyph];
                space = 0xC;
                break;
            case 5:
                width = gPrinterWidthsFont5[glyph];
                space = 0x10;
                break;
            case 6:
                width = gPrinterWidthsFont6[glyph];
                space = 0x28;
                break;
        }
        if (glyph == 0xFF) {
            if (gPrinterScaled) {
                penX = penX + space * gPrinterScale;
            } else {
                penX += space;
            }
        } else {
            gdl = Printer_DrawGlyph(gdl, font, glyph, penX, y, gPrinterMode, gPrinterCornerR[0], gPrinterCornerG[0],
                                    gPrinterCornerB[0], gPrinterCornerR[1], gPrinterCornerG[1], gPrinterCornerB[1],
                                    gPrinterCornerR[2], gPrinterCornerG[2], gPrinterCornerB[2], gPrinterCornerR[3],
                                    gPrinterCornerG[3], gPrinterCornerB[3], gPrinterScaled ? gPrinterScale : 1.0f);
            if (gPrinterScaled) {
                penX += (s32) (width * gPrinterScale);
            } else {
                penX += width;
            }
        }
        s++;
    }
    return gdl;
}

/* Glyph index of character c in font, or 0xFF for a space; 0 for a character the font lacks. */
s32 Printer_GetGlyph(s32 font, s8 c) {
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

/* Colour cycle for gPrinterColorCycle by phase: red -> yellow -> white -> yellow -> red. */
void Printer_CycleColorMode3(void) {
    switch (gPrinterColorCycle.phase) {
        case 0:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
        case 1:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            break;
        case 2:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            break;
        case 3:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
    }
}

/* Colour cycle for gPrinterColorCycle by phase: black -> red -> yellow -> red -> black. */
void Printer_CycleColorMode4(void) {
    switch (gPrinterColorCycle.phase) {
        case 0:
            gPrinterColorCycle.r = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 0;
            gPrinterColorCycle.b = 0;
            break;
        case 1:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
        case 2:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
        case 3:
            gPrinterColorCycle.r =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 0;
            gPrinterColorCycle.b = 0;
            break;
    }
}

/* Colour cycle for gPrinterColorCycle by phase: green -> yellow -> white -> yellow -> green. */
void Printer_CycleColorMode5(void) {
    switch (gPrinterColorCycle.phase) {
        case 0:
            gPrinterColorCycle.r = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = 0;
            break;
        case 1:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            break;
        case 2:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            break;
        case 3:
            gPrinterColorCycle.r =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = 0;
            break;
    }
}

/* Colour cycle for gPrinterColorCycle by phase: black -> green -> yellow -> green -> black. */
void Printer_CycleColorMode6(void) {
    switch (gPrinterColorCycle.phase) {
        case 0:
            gPrinterColorCycle.r = 0;
            gPrinterColorCycle.g = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
        case 1:
            gPrinterColorCycle.r = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = 0;
            break;
        case 2:
            gPrinterColorCycle.r =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = 0;
            break;
        case 3:
            gPrinterColorCycle.r = 0;
            gPrinterColorCycle.g =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 0;
            break;
    }
}

/* Colour cycle for gPrinterColorCycle by phase: pink (255, 128, 255) -> magenta -> red -> magenta -> pink. */
void Printer_CycleColorMode8(void) {
    switch (gPrinterColorCycle.phase) {
        case 0:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 128.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 255;
            break;
        case 1:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 0;
            gPrinterColorCycle.b =
                (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 255.0f) / gPrinterColorCycle.period);
            break;
        case 2:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = 0;
            gPrinterColorCycle.b = (u32) ((gPrinterColorCycle.timer * 255.0f) / gPrinterColorCycle.period);
            break;
        case 3:
            gPrinterColorCycle.r = 255;
            gPrinterColorCycle.g = (u32) ((gPrinterColorCycle.timer * 128.0f) / gPrinterColorCycle.period);
            gPrinterColorCycle.b = 255;
            break;
    }
}

/* Colour cycle for gPrinterColorCycle by phase: red and blue ramp 128 -> 255 in phases 0 and 2, back in 1 and 3 (green
 * stays 255). */
void Printer_CycleColorMode9(void) {
    s32 c;
    s32 c2;

    switch (gPrinterColorCycle.phase) {
        case 0:
        case 2:
            c = (u32) ((gPrinterColorCycle.timer * 127.0f) / gPrinterColorCycle.period) + 128;
            gPrinterColorCycle.r = c;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = c;
            break;
        case 1:
        case 3:
            c2 = (u32) (((gPrinterColorCycle.period - gPrinterColorCycle.timer) * 127.0f) / gPrinterColorCycle.period) +
                 128;
            gPrinterColorCycle.r = c2;
            gPrinterColorCycle.g = 255;
            gPrinterColorCycle.b = c2;
            break;
    }
}

void Printer_ResetColorCycle(void) {
    gPrinterColorCycle = gPrinterColorCycleInit;
}

void func_801EAFB4(void) {
    if (gPrinterColorCycle.enable != 0) {
        gPrinterColorCycle.timer++;
        if (gPrinterColorCycle.timer >= gPrinterColorCycle.period) {
            gPrinterColorCycle.timer = 0;
            gPrinterColorCycle.phase++;
            if (gPrinterColorCycle.phase == 4) {
                gPrinterColorCycle.phase = 0;
            }
        }
    }
}

/* Prints value (0..999) in font, right-aligned so its last digit starts at x. */
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y) {
    s32 i;
    s32 j;
    s32 digits[3];
    s32 v;
    s32 offset;
    s32 found;
    u8* widths;
    char buf[12];

    if (font == 0) {
        widths = gPrinterWidthsFont0;
    } else if (font == 2) {
        widths = gPrinterWidthsFont2;
    } else {
        widths = gPrinterWidthsFont1;
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
