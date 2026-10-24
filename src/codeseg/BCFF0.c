#include "common.h"

typedef struct UnkStruct_80228C30_sub {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} UnkStruct_80228C30_sub; /* size = 0x1C */

typedef struct UnkStruct_80228C30 {
    /* 0x00 */ UnkStruct_80228C30_sub unk0[3];
} UnkStruct_80228C30; /* size = 0x54 */

typedef struct PortraitPos {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ char pad8[8];
    /* 0x10 */ s32 bobPhase; /* index into gPortraitBob (& 7) */
} PortraitPos; /* size = 0x14 */

void func_801F25E0(Gfx** gdlp, s32 x, s32 y, s32 time, s32 style, s32 arg5, s32 color);

extern Gfx D_1014708[];
extern Gfx D_1014760[];
extern Gfx D_1014790[];
extern u8 D_102DF50[];
extern u8 D_102E3D8[];
extern u8 D_102E620[];
extern u8 D_102E868[];
extern u32 D_102EE70[];
extern u8 D_1032078[];
extern u8 D_1032500[];
extern u8 D_1032B08[];
extern u8 D_10331D0[];
extern u8 D_10337D8[];
extern u8 D_1033C60[];
extern u8 D_10387C0[];
extern u8 D_1039248[];
extern u8 D_103B4D0[];
extern u8 D_103D5D0[];
extern u8 D_103D8D8[];
extern u8 D_1040FE0[];
extern u8 D_10416A8[];
extern u8 D_1041BB0[];
extern u8 D_10420B8[];
extern u8 D_1042780[];
extern u8 D_8024008[];
extern u8 D_8024BC8[];
extern u8 D_80273D8[];
extern u8 D_802A5E0[];
extern u8 D_802C3E8[];
extern s32 D_800D4B00;
extern s32 D_801C1FDC;
extern s32 D_801C1FE4;
extern s32 D_801C1FE8;
extern RiderStruct D_801C2938[];
extern u8* gPortraitFaces[];
extern f32 gPortraitBob[];
extern char D_802279E0[];
extern char D_802279EC[];
extern f32 D_80227A24;
extern s32 D_80228A9C;
extern s32 D_80228AAC;
extern s32 D_80228AB0;
extern s32 D_80228AB4;
extern s32 D_80228AB8;
extern s32 D_80228ABC;
extern s32 D_80228AC0;
extern s32 D_80228B50;
extern s32 D_80228B54;
extern UnkStruct_80228C30 D_80228C30[];
extern s8 D_80228CF8[5];
extern u16 D_80228D24;
extern PortraitPos gPortraitPos[2][4];
extern s32 D_80228DC8[];
extern s32 D_80228DF8;

// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;

// Draw a 16x20 (1P) or 12x16 (2P) RGBA32 digit image at (x, y).
#define HUD_DIGIT(gdl, img, w, h, x, y)                                                                         \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP,         \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);         \
    gSPTextureRectangle(gdl++, (x) << 2, (y) << 2, ((x) + (w)) << 2, ((y) + (h)) << 2, G_TX_RENDERTILE, 0, 0, \
                        1 << 10, 1 << 10)

#define HUD_LOAD32(gdl, img, w, h)                                                                      \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP, \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD)

#define HUD_RECT(gdl, x, y, w, h) \
    gSPTextureRectangle(gdl++, (x) << 2, (y) << 2, ((x) + (w)) << 2, ((y) + (h)) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10)

#define HUD_SCISRECT(gdl, x, y, w, h)                                                                            \
    gSPScisTextureRectangle(gdl++, ((x) << 2), ((y) << 2), (((x) + (w)) << 2), (((y) + (h)) << 2), G_TX_RENDERTILE, 0, \
                            0, 1 << 10, 1 << 10)

#ifdef NON_MATCHING
// Score 435: idx (the second half's index) is copied from D_80228D1C early into its own register; the original reuses the first index product's.
extern s32 D_801C1FD8;
extern s32 D_80227888[][3];
extern s32 D_802278C4[][3];
extern s32 D_80227900[][3];
extern s32 D_8022793C[][3];
extern s32 D_80228AC4;
extern s32 D_80228AC8;
extern s32 D_80228ACC;
extern s32 D_80228AD0;
extern s32 D_80228AD4;
extern s32 D_80228AD8;
extern s32 D_80228D1C;
extern s32 D_80228D20;

void func_801EE9C0(void) {
    f32 f;
    f32 g;
    s32 idx;
    s32(*a)[3];
    s32(*b)[3];

    f = (2 - D_80228D20) / (f32) 2;
    g = 1.0f - f;
    a = &D_80227888[D_80228D1C];
    D_80228AAC = a[0][0] * f + a[1][0] * g;
    D_80228AB0 = a[0][1] * f + a[1][1] * g;
    D_80228AB4 = a[0][2] * f + a[1][2] * g;
    b = &D_802278C4[D_80228D1C];
    idx = D_80228D1C;
    D_80228AB8 = b[0][0] * f + b[1][0] * g;
    D_80228ABC = b[0][1] * f + b[1][1] * g;
    D_80228AC0 = b[0][2] * f + b[1][2] * g;
    if (D_801C1FD8 != 0) {
        g = 0.0f;
        idx = 0;
        f = 1.0f;
    }
    a = &D_80227900[idx];
    D_80228AC4 = a[0][0] * f + a[1][0] * g;
    D_80228AC8 = a[0][1] * f + a[1][1] * g;
    D_80228ACC = a[0][2] * f + a[1][2] * g;
    b = &D_8022793C[idx];
    D_80228AD0 = b[0][0] * f + b[1][0] * g;
    D_80228AD4 = b[0][1] * f + b[1][1] * g;
    D_80228AD8 = b[0][2] * f + b[1][2] * g;
    if (gCurrentPauseMenuOption == -1) {
        D_80228D20++;
        if (D_80228D20 >= 2) {
            D_80228D1C++;
            D_80228D20 = 0;
            D_80228D1C &= 3;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EE9C0.s")
#endif

// HUD_Init
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EED70.s")

// Set up the HUD projection matrices in the current Gfx pool.

void func_801EF3C4(void) {
    MtxF sp40;

    func_800481E0(&D_801AE948->unk4080, &D_80228D24, 24.0f, 1.3333334f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_800484C8(&D_801AE948->unk40C0, &sp40, 0.0f, 512.0f, D_80227A24, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    guOrtho(&D_801AE948->unk4000, -160.0f, 160.0f, -120.0f, 120.0f, -1024.0f, 1024.0f, 1.0f);
    guOrtho(&D_801AE948->unk4040, 0.0f, 320.0f, 240.0f, 0.0f, -1024.0f, 1024.0f, 1.0f);
}

// Per-frame update of the guide arrow
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EF504.s")

// Draw the guide arrow (next-buoy compass) for each player.
extern Gfx D_1010528[];
extern Vp D_1014450;
extern Vp D_1014460;
extern Vp D_1014470;
extern Vp D_1014480;
extern Gfx D_1014618[];
extern Mtx D_300E008;
extern Mtx D_300E088;
extern s32 D_801AE950;

void func_801EE228(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

void func_801EFFD8(Gfx** gdlp) {
    Gfx* gdl;
    RiderStruct* rider;
    s32 i;
    s32 alpha;

    gdl = *gdlp;
    gSPDisplayList(gdl++, D_1014618);
    gSPPerspNormalize(gdl++, D_80228D24);
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &D_801C2938[D_800D48DC];
        } else {
            rider = &D_801C2938[D_800D48E0];
        }
        alpha = rider->unk2DC * 255 / 4;
        if ((alpha > 0) && (rider->unk2F4 == 0) && (rider->unk2EC == 0)) {
            if (gPlayers == ONE_PLAYER) {
                gSPViewport(gdl++, &D_1014460);
            } else if (i == 0) {
                gSPViewport(gdl++, &D_1014470);
            } else {
                gSPViewport(gdl++, &D_1014480);
            }
            gDPPipeSync(gdl++);
            if ((rider->unk328 >= 40) && ((rider->unk328 % 20) == 0)) {
                gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            } else {
                gDPSetCombineLERP(gdl++, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE);
            }
            func_801EE228(&D_801AE948->unk4140[D_801AE950], rider->unk2D0, 0.0f, 1.0f, 0.0f);
            gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPPipeSync(gdl++);
            gDPSetPrimColor(gdl++, 0, 0, 255, 150, 150, alpha);
            if (alpha < 255) {
                gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
            } else {
                gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            }
            gSPDisplayList(gdl++, D_1010528);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
    }
    gSPViewport(gdl++, &D_1014450);
    gSPMatrix(gdl++, &D_300E008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_300E088, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].unkE4);
    *gdlp = gdl;
}

extern s32 D_800D817C;
extern s8 D_80228B58[];
extern s32 D_80228D08;
extern s32 D_80228D0C;
extern s32 D_80228D10;

void func_801F03E0(void) {
    s32 d;
    s32 i;

    if ((gGameModeState == GMODE_STATE_1) || (gGameModeState == GMODE_STATE_2)) {
        if (D_80228D08 == 0) {
            D_80228D0C -= 3;
            if (D_80228D0C <= 0) {
                D_80228D0C = 0;
                D_80228D08 = 1;
            }
        } else {
            if ((D_80228A90 % 15) == 0) {
                if (gGameModeState != GMODE_STATE_2) {
                    AudioGeneral_PlaySound(0x22, (D_80228A90 / 15) - 1);
                } else {
                    AudioGeneral_PlaySound(0x23, 0);
                }
            }
            d = D_80228A90 - 15;
            if (d < 0) {
                d = -d;
            }
            if (d < 15) {
                for (i = 0; i < gRiders; i++) {
                    if ((D_80192690[i].unkB58 & 0xA000) && (D_80228B58[i] == 0)) {
                        if (d <= 0) {
                            D_801C2938[i].unk12C = 5;
                        } else if (d < 2) {
                            D_801C2938[i].unk12C = 4;
                        } else if (d < 3) {
                            D_801C2938[i].unk12C = 3;
                        } else if (d < 4) {
                            D_801C2938[i].unk12C = 2;
                        } else if (d < 5) {
                            D_801C2938[i].unk12C = 1;
                        }
                        if (d < 5) {
                            D_801C2938[i].unk314 = 1;
                            D_801C2938[i].unk28 = 1;
                        }
                        D_80228B58[i] = 1;
                    }
                }
            }
            D_80228A90--;
            if (D_80228A90 == 15) {
                gGameModeState = GMODE_STATE_2;
                D_800D817C = 0;
            } else if (D_80228A90 <= 0) {
                gGameModeState = GMODE_STATE_STARTED;
                D_80228D08 = 2;
            }
        }
    } else if ((D_80228D08 == 2) && (gCurrentPauseMenuOption == -1)) {
        D_80228D0C += 6;
        if (D_80228D0C >= D_80228D10) {
            D_80228D08 = 0;
        }
    }
}

extern Gfx D_10106C0[];
extern Gfx D_1010730[];
extern Gfx D_1010998[];
extern Gfx D_10109F8[];
extern u8 D_10123A8[];
extern u8 D_1012BA8[];
extern u8 D_10133A8[];
extern u8 D_1013BA8[];
extern Vp D_1014490;
extern Vp D_10144A0;
extern Vp D_10144B0;
extern Gfx D_1014658[];

void func_801EDFFC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3);

#define LIGHT_TEX(gdl, img)                                                                                    \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,       \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD)

// Draw the start lights: three red lamps lit one by one as the countdown runs, then the green one.
void func_801F06A0(Gfx** gdlp) {
    s32 i;
    f32 angle;
    s32 n;
    u8* lamp1;
    u8* lamp2;
    u8* lamp3;
    u8* go;
    Gfx* gdl;
    MtxF mf;

    n = (D_80228A90 - 1) / 15;
    gdl = *gdlp;
    if (n < 0) {
        n = 0;
    }
    if (D_80228D08 == 0) {
        n = 4;
    }
    if ((n > 0) && (n < 4)) {
        lamp1 = D_1013BA8;
    } else {
        lamp1 = D_10133A8;
    }
    if ((n > 0) && (n < 3)) {
        lamp2 = D_1013BA8;
    } else {
        lamp2 = D_10133A8;
    }
    if (n == 1) {
        lamp3 = D_1013BA8;
    } else {
        lamp3 = D_10133A8;
    }
    if (n == 0) {
        go = D_1012BA8;
    } else {
        go = D_10123A8;
    }
    gSPDisplayList(gdl++, D_1014658);
    func_800481E0(&D_801AE948->unk4140[D_801AE950], &D_80228D24, 120.0f, 1.3333334f, 16.0f, 1024.0f, 0.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    func_800484C8(&D_801AE948->unk4140[D_801AE950], &mf, 0.0f, 0.0f, (gPlayers == TWO_PLAYERS) * 20.0f + 60.0f,
                  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPPerspNormalize(gdl++, D_80228D24);
    func_801EDFFC(&D_801AE948->unk4140[D_801AE950], 0.0f, D_80228D0C, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    angle = (D_80228D0C / 100.0f) * 120.0f;
    if (D_80228D08 == 2) {
        angle = -angle;
    }
    func_801EE228(&D_801AE948->unk4140[D_801AE950], angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    for (i = 0; i < gPlayers; i++) {
        if (gPlayers == ONE_PLAYER) {
            gSPViewport(gdl++, &D_1014490);
        } else if (i == 0) {
            gSPViewport(gdl++, &D_10144A0);
        } else {
            gDPPipeSync(gdl++);
            gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 122, 311, 229);
            gSPViewport(gdl++, &D_10144B0);
        }
        LIGHT_TEX(gdl, lamp1);
        gSPDisplayList(gdl++, D_10106C0);
        LIGHT_TEX(gdl, lamp2);
        gSPDisplayList(gdl++, D_1010730);
        LIGHT_TEX(gdl, lamp3);
        gSPDisplayList(gdl++, D_1010998);
        LIGHT_TEX(gdl, go);
        gSPDisplayList(gdl++, D_10109F8);
    }
    gSPViewport(gdl++, &D_1014450);
    if (gPlayers == TWO_PLAYERS) {
        gDPPipeSync(gdl++);
        gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 12, 311, 229);
    }
    gSPMatrix(gdl++, &D_300E008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_300E088, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].unkE4);
    *gdlp = gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F0E7C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F14B4.s")

extern u16 D_801CE72E;
extern s32 D_80228B5C;

void func_801F1CFC(void) {
    f32 x;
    f32 z;
    s32 blocked;
    RiderStruct* rider;
    UnkStruct_80192690* p;
    s32 i;
    s32 inZone;
    s32 show;
    s32 add;

    if ((gGameModes == GMODE_2P_VS) &&
        ((D_801C2938[D_800D48DC].unk2F4 != 0) || (D_801C2938[D_800D48DC].unk2EC != 0) ||
         (D_801C2938[D_800D48E0].unk2F4 != 0) || (D_801C2938[D_800D48E0].unk2EC != 0))) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            p = &D_80192690[D_800D48DC];
            rider = &D_801C2938[D_800D48DC];
        } else {
            p = &D_80192690[D_800D48E0];
            rider = &D_801C2938[D_800D48E0];
        }
        if ((rider->unk2EC != 0) || (rider->unk2F4 != 0)) {
            continue;
        }
        x = p->unk44.x;
        z = p->unk44.z;
        inZone = (gCourseID != SOUTHERN_ISLAND) && (p->unk16D0 > 80);
        show = (func_80074264(x, z) || inZone) && (blocked == 0) && (D_801CE72E != 0);
        if (rider->unk2E4 != 0) {
            if (!show) {
                rider->unk2E4 = 0;
            } else if ((p->unkC54 != 23) && (p->unkC54 != 7)) {
                if (rider->unk2E8 > 0) {
                    if (D_80228B5C >= rider->unk2E8) {
                        add = inZone ? 0x80 : 0;
                        if (rider->unk2E8 == D_80228B5C) {
                            AudioGeneral_PlaySound(10, rider->unk2E8 / 20 + add);
                        } else if ((rider->unk2E8 % 20) == 0) {
                            AudioGeneral_PlaySound(10, rider->unk2E8 / 20 + add - 1);
                        }
                    }
                    rider->unk2E8--;
                } else if (rider->unk2E8 == 0) {
                    func_800762D0((struct_800762D0*) rider);
                }
            }
        } else if (show) {
            rider->unk2E4 = 1;
            rider->unk2E8 = D_80228B5C + 20;
        }
    }
}

#ifdef NON_MATCHING
// Score 300: temp registers are off by one from the first index product on (the original has one more temp early).
extern char D_802279D0[];
extern char D_802279D8[];
extern char D_802279DC[];

void func_801F2060(Gfx** gdlp) {
    RiderStruct* rider;
    UnkStruct_80192690* p;
    s32 i;
    s32 y;
    s32 mode;
    s32 r0;
    s32 g0;
    s32 r1;
    s32 g1;
    s32 n;
    s32 x;
    s32 t; // unused; with x it fills the 0x30 bytes of locals above gdl
    Gfx* gdl;

    gdl = *gdlp;
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            p = &D_80192690[D_800D48DC];
            rider = &D_801C2938[D_800D48DC];
        } else {
            p = &D_80192690[D_800D48E0];
            rider = &D_801C2938[D_800D48E0];
        }
        if ((rider->unk2E4 != 0) && (rider->unk2E8 <= D_80228B5C) && (rider->unk2EC == 0) && (rider->unk2F4 == 0)) {
            if (gPlayers == ONE_PLAYER) {
                y = 90;
            } else if (i == 0) {
                y = 50;
            } else {
                y = 160;
            }
            if (((rider->unk2E8 % 20) != 0) || (p->unkC54 == 23) || (p->unkC54 == 7)) {
                mode = 2;
                r0 = 255;
                g0 = 0;
                r1 = 0;
                g1 = 0;
            } else {
                mode = 1;
                r0 = 128;
                g0 = 128;
                r1 = 255;
                g1 = 255;
            }
            gdl = func_801E92FC(gdl, 0, D_802279D0, 68, y, mode, r0, 255, g0, r0, 255, g0, 255, r1, g1, 255, r1, g1);
            gdl = func_801E92FC(gdl, 0, D_802279D8, 164, y, mode, r0, 255, g0, r0, 255, g0, 255, r1, g1, 255, r1, g1);
            n = rider->unk2E8 / 20;
            sprintf((char*) D_80228CF8, D_802279DC, n);
            x = 223 - (n >= 10) * 5;
            gdl = func_801E92FC(gdl, 0, (char*) D_80228CF8, x, y, mode, r0, 255, g0, r0, 255, g0,
                                255, r1, g1, 255, r1, g1);
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F2060.s")
#endif

void func_801F23A0(void) {
    s32 i;
    UnkStruct_80192690* p;
    RiderStruct* rider;
    f32 lo;
    f32 range;
    f32 f;
    s32 diff;
    s32 dist;
    s32 step;

    for (i = 0; i < gRiders; i++) {
        p = &D_80192690[i];
        rider = &D_801C2938[i];
        f = p->unkBBC - p->unkBC0;
        lo = p->unkBC0 - f / 5.0f;
        range = (f * 6.0f) / 5.0f;
        f = p->unkB98;
        if (lo <= p->unkB98) {
            if (range > 0.0f) {
                f = (p->unkB98 - lo) / range;
            }
            if (f < 0.0f) {
                f = 0.0f;
            }
            if (f > 1.0f) {
                f = 1.0f;
            }
            rider->unk2CC = f * 180.0f;
            rider->unk2CC += Math_Rand(3) * 2 - 2;
            if (rider->unk2CC > 180) {
                rider->unk2CC = 180;
            }
        } else {
            rider->unk2CC = (p->unkB98 / lo) * 36.0f;
        }
        step = rider->unk2CC; // FAKE: step holds the target first, for the register allocation
        diff = step - rider->unk2C8;
        dist = (diff >= 0) ? diff : -diff;
        step = dist / 4;
        if (step < 2) {
            step = 2;
        }
        if (rider->unk2C8 < rider->unk2CC && step > 4) {
            step = 4;
        }
        if (dist <= step) {
            rider->unk2C8 = rider->unk2CC;
        } else {
            rider->unk2C8 += ((diff == 0) ? 0 : (diff > 0) ? 1 : -1) * step;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F25E0.s")

#ifdef NON_MATCHING
// Same control flow and stack frame; register allocation and scheduling differ throughout
// (asm-differ score 58028 of 490800), and the 1.8f below is D_80227A4C in the original.
// Draw the race HUD: lap splits and total time, the TIME, LAP, RANK and SPEED readouts, the missed-buoy
// marks, the boost meter, the stunt score and the best times.
void func_801F4120(Gfx** gdlp) {
    s32 i;
    s32 k;
    s32 j;
    s32 x;
    s32 y;
    s32 n;
    s32 value;
    s32 color;
    RiderStruct* rider;
    PortraitPos* pos;
    UnkStruct_80228C30* boost;
    s8* digit;
    s32 x2;
    s32 y2;
    Gfx* gdl = *gdlp;

    gSPDisplayList(gdl++, D_1014708);

    // Lap splits and the total race time.
    if (((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) && (gCourseID != DOLPHIN_PARK)) {
        rider = &D_801C2938[D_800D48DC];
        if ((rider->lapCount >= 2) || (D_800D8178 != 0)) {
            n = rider->lapCount - 1;
            y = 0x34;
            if (n >= 10) {
                k = n - 9;
                n = 9;
            } else {
                k = 0;
            }
            if ((rider->unk2F4 != 0) || (D_800D8178 != 0)) {
                n++;
            }
            for (j = 0; j < n; j++) {
                func_801F25E0(&gdl, D_80228B54 + 0x18, y, rider->unk178[j], 0, (k + j + 1) % 10, 0);
                y += 10;
            }
        }
        if ((rider->unk2F4 != 0) || (rider->unk2EC == 2)) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, D_80228B50 + 0x18, 0x22, rider->unk19C, 1, i, rider->unk16C);
    } else if (gGameModes == GMODE_2P_VS) {
        rider = &D_801C2938[D_800D48DC];
        if (rider->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, 0x18, 0xE, rider->unk19C, 1, i, rider->unk16C);
        rider = &D_801C2938[D_800D48E0];
        if (rider->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, 0x18, 0x7C, rider->unk19C, 1, i, rider->unk16C);
    }

    // Championship: the leader's time and the others' gaps to it, beside the portrait column.
    // k: the leader, value: the leader's time.
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (gCourseID != DOLPHIN_PARK) && (D_801C1FDC >= 0x28)) {
        for (k = 0; k < gRiders; k++) {
            if ((D_801C2938[k].unk2F4 != 0) && (D_801C2938[k].racePosition == 0)) {
                break;
            }
        }
        if (k >= gRiders) {
            k = 0;
        }
        value = D_801C2938[k].unk19C;
        for (i = 0; i < gRiders; i++) {
            rider = &D_801C2938[i];
            if (D_801C1FDC >= (rider->racePosition * 10) + 0x28) {
                color = 1;
                pos = &gPortraitPos[0][i];
                x = pos->x + 0xB0;
                y = pos->y + 0x3F;
                if (i == D_800D48DC) {
                    color = 2;
                }
                if (i == k) {
                    func_801F25E0(&gdl, x + D_80228B50, y, rider->unk19C, 3, 3, color);
                } else if (rider->unk2F4 != 0) {
                    func_801F25E0(&gdl, x + D_80228B50, y, rider->unk19C - value, 3, 1, color);
                }
            }
        }
    }

    // 2P VS: the lap split popups.
    if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gPlayers; i++) {
            y = 0xB2;
            if (i == 0) {
                y = 0x44;
                rider = &D_801C2938[D_800D48DC];
            } else {
                rider = &D_801C2938[D_800D48E0];
            }
            if (rider->unk300 != 0) {
                value = rider->unk2F8;
                color = 2;
                if (value < 10000) {
                    x = -0xF;
                } else if (value < 60000) {
                    x = -0xA;
                } else {
                    x = 0;
                }
                if (rider->unk2FC == 1) {
                    color = 1;
                }
                func_801F25E0(&gdl, x + 0x80, y, value, 3, rider->unk2FC, color);
            }
        }
    }

    // Championship: the other riders' lap split popups.
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (gCourseID != DOLPHIN_PARK)) {
        for (i = 0; i < gRiders; i++) {
            if (i != D_800D48DC) {
                rider = &D_801C2938[i];
                pos = &gPortraitPos[0][i];
                x = pos->x + 0xBA;
                y = pos->y + 0x3F;
                if (rider->unk300 != 0) {
                    func_801F25E0(&gdl, x, y, rider->unk2F8, 3, rider->unk2FC, 1);
                }
            }
        }
    }

    // Championship and time trials: the player's lap split popup, with a portrait (or a record icon).
    // j: how many leading digits the time drops (2 under 10 s, 1 under 60 s).
    if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) {
        rider = &D_801C2938[D_800D48DC];
        if (rider->unk300 != 0) {
            value = rider->unk2F8;
            color = 2;
            if (value < 10000) {
                j = 2;
            } else if (value < 60000) {
                j = 1;
            } else {
                j = 0;
            }
            x = 0x8C;
            if (j == 1) {
                x = 0x85;
            } else if (j == 2) {
                x = 0x7F;
            }
            if ((gGameModes == GMODE_TIME_TRIALS) && (rider->unk2FC == 1)) {
                color = 1;
            }
            func_801F25E0(&gdl, x, 0x7E, value, 3, rider->unk2FC, color);
            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            // n, y: the icon's position.
            n = x - 0x28;
            y = 0x7A;
            if (j == 1) {
                n += 0xF;
            } else if (j == 2) {
                n += 0x1A;
            }
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                gDPLoadTextureBlock(gdl++, D_10416A8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
                n += 9;
                y += 2;
                gDPLoadTextureBlock(gdl++, gPortraitFaces[D_80192690[rider->unk33C].unkB68], G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x10) << 2, (y + 0x10) << 2, G_TX_RENDERTILE, 0, 0,
                                    0x500, 0x500);
            } else {
                n -= 6;
                gDPLoadTextureBlock(gdl++, D_1042780, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
            }
        }
    }

    gDPPipeSync(gdl++);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    // TIME label.
    if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) {
        if (gCourseID != DOLPHIN_PARK) {
            HUD_LOAD32(gdl, D_1032500, 32, 12);
            HUD_RECT(gdl, D_80228B50 + 0x38, 0x15, 32, 12);
        }
    }

    // LAP label and the lap number (n).
    if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
        if (gPlayers == ONE_PLAYER) {
            y = 0x15;
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                x = D_80228B50 + 0xBC;
            } else {
                x = 0x84;
            }
        } else {
            x = 0xCA;
            y = 0xD;
            x2 = 0xCA;
            y2 = 0x7B;
        }
        HUD_LOAD32(gdl, D_1032078, 24, 12);
        HUD_RECT(gdl, x, y, 24, 12);
        if (gPlayers == TWO_PLAYERS) {
            HUD_RECT(gdl, x2, y2, 24, 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0x22;
                if (gGameModes == GMODE_CHAMPIONSHIP) {
                    x = D_80228B50 + 0xC0;
                } else {
                    x = 0x88;
                }
                n = D_801C2938[D_800D48DC].lapCount;
            } else {
                x = 0xD0;
                if (i == 0) {
                    y = 0x19;
                    n = D_801C2938[D_800D48DC].lapCount;
                } else {
                    y = 0x87;
                    n = D_801C2938[D_800D48E0].lapCount;
                }
            }
            if (D_801CE728[0] < n) {
                n = D_801CE728[0];
            }
            if (gPlayers == ONE_PLAYER) {
                HUD_DIGIT(gdl, &D_103D8D8[(n % 10) * 0x500], 16, 20, x, y);
            } else {
                HUD_DIGIT(gdl, &D_103B4D0[(n % 10) * 0x300], 12, 16, x, y);
            }
        }
    }

    // RANK: label, position digit (zooming when it changes), "/" and the number of riders.
    if (gGameModes == GMODE_CHAMPIONSHIP) {
        if (gCourseID != DOLPHIN_PARK) {
            HUD_LOAD32(gdl, D_1032B08, 36, 12);
            HUD_RECT(gdl, D_80228B50 + 0x84, 0x15, 36, 12);
            HUD_LOAD32(gdl, &D_103D8D8[(D_801C2938[D_800D48DC].racePosition + 1) * 0x500], 16, 20);
            x = D_80228B50 + 0x88;
            if (D_80228A9C == 0) {
                HUD_RECT(gdl, x, 0x22, 16, 20);
            } else {
                color = D_80228DF8 * 6;
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_BILERP);
                gSPTextureRectangle(gdl++, (x - color) << 2, 0x22 << 2, (x + 0x10) << 2, (color + 0x36) << 2,
                                    G_TX_RENDERTILE, 0, 0, 0x4000 / (color + 0x10), 0x5000 / (color + 0x14));
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_POINT);
            }
            gDPPipeSync(gdl++);
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
                              TEXEL0, 0, ENVIRONMENT, 0);
            if (D_801CE704 < D_801C2938[D_800D48DC].racePosition) {
                gDPSetEnvColor(gdl++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
            } else {
                gDPSetEnvColor(gdl++, 255, 255, 255, 255);
            }
            gDPLoadTextureBlock(gdl++, D_1033C60, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            HUD_RECT(gdl, D_80228B50 + 0x9B, 0x20, 8, 10);
            if (D_801CE704 < 4) {
                n = D_801CE704 + 1;
            } else {
                n = 0x25;
            }
            gDPLoadTextureBlock(gdl++, &D_1039248[n * 0xC0], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 12, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            HUD_RECT(gdl, D_80228B50 + 0x9A, 0x2A, 16, 12);
            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        }
    }

    // SPEED label.
    HUD_LOAD32(gdl, D_10331D0, 32, 12);
    if (gGameModes == GMODE_STUNT) {
        HUD_RECT(gdl, 0xEC, 0x16, 32, 12);
    } else if (gPlayers == ONE_PLAYER) {
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x97;
        } else {
            x = 0xD9;
        }
        HUD_RECT(gdl, x + D_80228B50 + 0x18, 0x15, 32, 12);
    } else {
        HUD_RECT(gdl, 0xF2, 0xD, 32, 12);
        HUD_RECT(gdl, 0xF2, 0x7B, 32, 12);
    }

    // The speed (value, km/h), three digits.
    for (i = 0; i < gPlayers; i++) {
        if (gPlayers == ONE_PLAYER) {
            y = 0x22;
            x = D_80228B50 + 0xE1;
            value = D_80192690[D_800D48DC].unkB90;
        } else if (i == 0) {
            x = 0xEC;
            y = 0x19;
            value = D_80192690[D_800D48DC].unkB90;
        } else {
            x = 0xEC;
            y = 0x87;
            value = D_80192690[D_800D48E0].unkB90;
        }
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xE1;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x9F;
        }
        value = value * 1.8f;
        if (value >= 1000) {
            value = 999;
        }
        if (gGameModes == GMODE_STUNT) {
            x = 0xE4;
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_802C3E8[(value / 100) * 0x300], 12, 16, x, 0x26);
            }
            x += 0xE;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_802C3E8[((value % 100) / 10) * 0x300], 12, 16, x, 0x26);
            }
            x += 0xE;
            HUD_DIGIT(gdl, &D_802C3E8[(value % 10) * 0x300], 12, 16, x, 0x26);
        } else if (gPlayers == ONE_PLAYER) {
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_103D8D8[(value / 100) * 0x500], 16, 20, x, y);
            }
            x += 0x10;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_103D8D8[((value % 100) / 10) * 0x500], 16, 20, x, y);
            }
            x += 0x10;
            HUD_DIGIT(gdl, &D_103D8D8[(value % 10) * 0x500], 16, 20, x, y);
        } else {
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_103B4D0[(value / 100) * 0x300], 12, 16, x, y);
            }
            x += 0xD;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_103B4D0[((value % 100) / 10) * 0x300], 12, 16, x, y);
            }
            x += 0xD;
            HUD_DIGIT(gdl, &D_103B4D0[(value % 10) * 0x300], 12, 16, x, y);
        }
    }

    // km/h label.
    HUD_LOAD32(gdl, D_10337D8, 24, 12);
    if (gGameModes == GMODE_STUNT) {
        HUD_RECT(gdl, 0x10E, 0x2B, 24, 12);
    } else if (gPlayers == ONE_PLAYER) {
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x97;
        } else {
            x = 0xD9;
        }
        HUD_RECT(gdl, x + D_80228B50 + 0x39, 0x2A, 24, 12);
    } else {
        HUD_RECT(gdl, 0x114, 0x1E, 24, 12);
        HUD_RECT(gdl, 0x114, 0x8C, 24, 12);
    }

    // Buoy marks: the label, k = gBuoyMisses (at most 28) marks D_102E3D8, then the rider's unk134 (n)
    // marks D_102E620 over the right end of the row (one fewer while D_80228C30[player].unk0[0].unk18 == 1).
    if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
        if (gPlayers == ONE_PLAYER) {
            HUD_LOAD32(gdl, D_102DF50, 24, 12);
            x = D_80228B54 + 0x18;
            y = 0xCD;
            HUD_SCISRECT(gdl, x, y, 24, 12);
        }
        HUD_LOAD32(gdl, D_102E3D8, 12, 12);
        k = gBuoyMisses;
        if (k > 28) {
            k = 28;
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCD;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                y = 0xD6;
                if (i == 0) {
                    y = 0x68;
                }
            }
            for (j = 0; j < k; j++) {
                HUD_SCISRECT(gdl, x, y, 12, 12);
                x += 0xE;
            }
        }
        boost = D_80228C30;
        HUD_LOAD32(gdl, D_102E620, 12, 12);
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCD;
                n = D_801C2938[D_800D48DC].unk134;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                if (i == 0) {
                    y = 0x68;
                    n = D_801C2938[D_800D48DC].unk134;
                } else {
                    y = 0xD6;
                    n = D_801C2938[D_800D48E0].unk134;
                }
            }
            if (boost->unk0[0].unk18 == 1) {
                n--;
            }
            j = k - n;
            if (j < 0) {
                j = 0;
            }
            for (x += j * 0xE; j < k; j++) {
                HUD_SCISRECT(gdl, x, y, 12, 12);
                x += 0xE;
            }
            boost++;
        }
    }

    // Power meter: the label and five chevrons, n = the rider's unk138 of them lit, the n-th one
    // animating (color: the chevron's image, 0-3).
    if ((gCourseID != DOLPHIN_PARK) && (gGameModes != GMODE_STUNT)) {
        if (gPlayers == ONE_PLAYER) {
            HUD_LOAD32(gdl, D_102E868, 32, 12);
            x = D_80228B54 + 0x94;
            y = 0xCD;
            HUD_SCISRECT(gdl, x, y, 32, 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCF;
                n = D_801C2938[D_800D48DC].unk138;
                x = D_80228B54 + 0xBC;
            } else {
                y = 0x6A;
                x = 0xBC;
                if (i == 0) {
                    x = 0xBC;
                    n = D_801C2938[D_800D48DC].unk138;
                } else {
                    y = 0xD8;
                    n = D_801C2938[D_800D48E0].unk138;
                }
            }
            for (j = 0; j < 5; j++) {
                if (j + 1 == n) {
                    color = D_800D4B00 % 6;
                    if (color >= 4) {
                        color = 6 - color;
                    }
                } else {
                    color = 0;
                    if (j < n) {
                        color = 3;
                    }
                }
                HUD_LOAD32(gdl, &D_102EE70[(color + j * 4) * (20 * 8)], 20, 8);
                HUD_SCISRECT(gdl, x, y, 20, 8);
                x += 0x16;
            }
        }
    }

    // Stunt mode: the score (value), five digits.
    if (gGameModes == GMODE_STUNT) {
        HUD_LOAD32(gdl, D_8024008, 36, 12);
        HUD_RECT(gdl, 0x2D, 0x16, 36, 12);
        value = D_801C26D0;
        x = 0x1C;
        if (value >= 100000) {
            value = 99999;
        }
        for (digit = &D_80228CF8[4]; digit > &D_80228CF8[-1]; digit--) {
            *digit = value % 10;
            value /= 10;
        }
        for (digit = D_80228CF8; digit != &D_80228CF8[5]; digit++) {
            HUD_DIGIT(gdl, &D_8024BC8[*digit * 0x300], 12, 16, x, 0x26);
            x += 0xE;
        }
    }

    // Stunt mode: the time left (value): n seconds and k thousandths; under six seconds the seconds
    // digit zooms out over each second (color: the shrink, x/y: the drawn size).
    if (gGameModes == GMODE_STUNT) {
        HUD_LOAD32(gdl, D_1032500, 32, 12);
        HUD_RECT(gdl, 0x8D, 0x16, 32, 12);
        value = D_801C2938[D_800D48DC].unk2C4;
        k = value % 1000;
        n = value / 1000;
        HUD_DIGIT(gdl, &D_103B4D0[(k / 100) * 0x300], 12, 16, 0xAA, 0x26);
        HUD_DIGIT(gdl, D_103D5D0, 12, 16, 0xA2, 0x23);
        if ((n >= 6) || (D_801C2938[D_800D48DC].unk2F4 != 0) || (D_801C2938[D_800D48DC].unk2EC != 0)) {
            x = 0x84;
            if (n >= 10) {
                HUD_DIGIT(gdl, &D_80273D8[(n / 10) * 0x500], 16, 20, x, 0x26);
            }
            x += 0x10;
            HUD_DIGIT(gdl, &D_80273D8[(n % 10) * 0x500], 16, 20, x, 0x26);
        } else {
            k -= 700;
            if (k < 0) {
                k = 0;
            }
            color = (k * 16) / 300;
            x = 0x20 - color * 2;
            y = 0x28 - color * 2;
            if ((x > 0) && (y > 0)) {
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_BILERP);
                gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT,
                                  0, TEXEL0, 0, ENVIRONMENT, 0);
                gDPSetEnvColor(gdl++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
                gDPLoadTextureBlock(gdl++, &D_802A5E0[n * 0x500], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 40, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, (color + 0x84) << 2, (color + 0x26) << 2, (0xA4 - color) << 2,
                                    (0x4E - color) << 2, G_TX_RENDERTILE, 0, 0, 0x8000 / x, 0xA000 / y);
            }
        }
    }

    // Time trials: the best times.
    if ((gGameModes == GMODE_TIME_TRIALS) && (gCourseID != DOLPHIN_PARK)) {
        y = 0x16;
        gdl = func_801E92FC(gdl, 1, D_802279E0, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        y += 9;
        gdl = func_801E8A84(gdl, 1, D_801C1FE4, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (D_800DAB68 == 0) {
            y += 0xB;
            gdl = func_801E92FC(gdl, 1, D_802279EC, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            y += 9;
            gdl = func_801E8A84(gdl, 1, D_801C1FE8, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F4120.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F8DD0.s")

// Draw the column of rider portraits, with their race positions.
void func_801F9520(Gfx** gdlp) {
    Gfx* gdl = *gdlp;
    s32 i;
    s32 idx;
    s32 player;
    s32 x;
    s32 y;
    s32 xOff;
    s32 yOff;
    s32 highlight;
    s32 face;
    s32 numX;
    s32 numY;
    u8* img;
    PortraitPos* pos;
    f32 bob;

    if (gPlayers == ONE_PLAYER) {
        gSPDisplayList(gdl++, D_1014760);
    } else {
        gSPDisplayList(gdl++, D_1014790);
    }

    for (player = 0; player < gPlayers; player++) {
        if (gPlayers == ONE_PLAYER) {
            xOff = D_80228B50 + 0x106;
            yOff = 0x3C;
        } else {
            xOff = 0x108;
            if (player == 0) {
                yOff = 0x2B;
            } else {
                yOff = 0x99;
            }
        }
        for (i = 0; i < gRiders; i++) {
            if (player == 0) {
                idx = gRiders - i - 1;
            } else {
                idx = i;
            }
            pos = &gPortraitPos[player][idx];
            x = pos->x + xOff;
            y = pos->y + yOff;
            bob = gPortraitBob[pos->bobPhase & 7] * 4.0f;
            y = y - bob;

            if (((player == 0) && (idx == D_800D48DC)) || ((player == 1) && (idx == D_800D48E0))) {
                highlight = 1;
            } else {
                highlight = 0;
            }

            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetRenderMode(gdl++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);

            if (highlight) {
                if (D_801C2938[idx].unk2F4 == 0) {
                    img = D_1040FE0;
                } else {
                    img = D_10420B8;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, (x - 7) << 2, y << 2, (x + 0x1D) << 2, (y + 0x18) << 2, G_TX_RENDERTILE, 0,
                                    0, 1 << 10, 1 << 10);
            } else {
                if (D_801C2938[idx].unk2F4 == 0) {
                    img = D_10416A8;
                } else {
                    img = D_1041BB0;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
            }

            if (((idx == D_800D48DC) && (D_801CE6F4[0] != 0)) ||
                ((gPlayers == TWO_PLAYERS) && (idx == D_800D48E0) && (D_801CE6F4[1] != 0))) {
                face = 4;
            } else {
                face = 0;
            }
            gDPLoadTextureBlock(gdl++, gPortraitFaces[D_80192690[idx].unkB68 + face], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20,
                                0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            if (highlight) {
                gSPTextureRectangle(gdl++, (x + 5) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x16) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 1 << 10, 1 << 10);
            } else {
                gSPTextureRectangle(gdl++, (x + 9) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x12) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 0x500, 0x500);
            }

            gDPPipeSync(gdl++);
            gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0,
                              TEXEL0);
            if (highlight) {
                gDPSetEnvColor(gdl++, D_80228AB8, D_80228ABC, D_80228AC0, 255);
                numX = x - 4;
                numY = y + 4;
            } else {
                gDPSetEnvColor(gdl++, 255, 255, 255, 255);
                numX = x + 2;
                numY = y + 2;
            }
            gDPLoadTextureBlock(gdl++, &D_10387C0[(D_801C2938[idx].racePosition + 1) * 64], G_IM_FMT_IA, G_IM_SIZ_8b, 8,
                                8, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gdl++, numX << 2, numY << 2, (numX + 8) << 2, (numY + 8) << 2, G_TX_RENDERTILE, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    *gdlp = gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F9EA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FA3C0.s")

// Rasterise a line from (x0, y0) to (x1, y1) (Bresenham): writes the points into xs/ys and their count.
void func_801FAD68(s32 x0, s32 y0, s32 x1, s32 y1, s32* count, s32* xs, s32* ys) {
    s32 dx;
    s32 dy;
    s32 adx;
    s32 ady;
    s32 sx;
    s32 sy;
    s32 err;
    s32 x;
    s32 y;
    s32 n;

    dx = adx = x1 - x0;
    dy = ady = y1 - y0;
    sx = SIGNUM(dx);
    sy = SIGNUM(dy);
    err = 0;
    if (dx < 0) {
        adx = -dx;
    }
    if (dy < 0) {
        ady = -dy;
    }
    x = x0;
    y = y0;
    xs[0] = x;
    ys[0] = y;
    n = 1;
    if (adx >= ady) {
        while (x != x1) {
            err += ady;
            x += sx;
            if (err * 2 >= adx) {
                err -= adx;
                y += sy;
            }
            xs[n] = x;
            ys[n] = y;
            n++;
        }
    } else {
        while (y != y1) {
            err += adx;
            y += sy;
            if (err * 2 >= ady) {
                err -= ady;
                x += sx;
            }
            xs[n] = x;
            ys[n] = y;
            n++;
        }
    }
    *count = n;
}

void func_801FAEA8(void) {
}
