#include "global.h"

/* Two panels, drawn at unk0 + D_i9_802C80CC, unk4 + D_i9_802C80D0 */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} UnkStruct_i9_802C80E4; // size = 0x10

extern s32 D_800DAA10[];
extern u8 D_7000000[];
extern u8 D_2000A40[];
extern Gfx D_106F550[];
extern u8 D_8060008[];
extern s32 D_i9_802C80C0;
extern s32 D_i9_802C80C4;
extern s32 D_i9_802C80C8;
extern s32 D_i9_802C80CC;
extern s32 D_i9_802C80D0;
extern s32 D_i9_802C80D4;
extern s32 D_i9_802C80D8;
extern s32 D_i9_802C80E0;
extern UnkStruct_i9_802C80E4 D_i9_802C80E4[2];
extern UnkStruct_i9_802C80E4 D_i9_802C8104[2];
extern Vp D_i9_802C8128;
extern s32 D_i9_802C8138[];
extern s32 D_i9_802C8144[];
extern s32 D_i9_802C8150[];
extern s32 D_i9_802C8174[];
extern s32 D_i9_802C81A4;
extern s32 D_i9_802C81B4;
extern u16 D_802C8280;

Gfx* func_i9_802C6750(Gfx* gdl);
Gfx* func_i9_802C6CC8(Gfx* gdl, s32 x);
Gfx* func_i9_802C71AC(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_i9_802C5800(void) {
    s32 k;
    s32 j;
    s32 n;
    s32 x;
    s32 y;
    s32 count;
    s32 vertical;
    s32 done;
    MtxF sp178;
    MtxF sp138;
    MtxF spF8;
    Mtx spB8;
    Mtx sp78;

    if (D_801CE63C != 0 && gGameState == GAME_STATE_OPTIONS_VIEW_RECORDS) {
        if (D_801CB280 & 8) {
            D_i9_802C81B4 = 1;
        }
        if (gPrevGameState == GAME_STATE_65) {
            D_i9_802C81A4 = 1;
            D_i9_802C80C0 = 1;
            D_i9_802C80C4 = 0;
            D_i9_802C80C8 = 1;
            D_i9_802C80E4[0].unk0 = 0;
            D_i9_802C80E4[0].unk4 = 0;
            D_i9_802C80E4[0].unk8 = 1;
            D_i9_802C80E4[0].unkC = 1;
            D_i9_802C80E4[1].unk0 = 320;
            D_i9_802C80E4[1].unk4 = 0;
            D_i9_802C80E4[1].unk8 = 1;
            D_i9_802C80E4[1].unkC = 1;
            if (D_800DAB68 != 0) {
                D_i9_802C80E4[0].unkC = 3;
                D_i9_802C80E4[1].unkC = 3;
            }
            D_i9_802C8104[0].unk0 = 0;
            D_i9_802C8104[0].unk4 = 0;
            D_i9_802C8104[0].unk8 = 1;
            D_i9_802C8104[0].unkC = 1;
            D_i9_802C8104[1].unk0 = 320;
            D_i9_802C8104[1].unk4 = 0;
            D_i9_802C8104[1].unk8 = 1;
            D_i9_802C8104[1].unkC = 0;
        }
    }

    count = 1;
    if (D_i9_802C80DC != 0) {
        count = 2;
        if (D_i9_802C80DC == 1) {
            vertical = 0;
            D_i9_802C80CC += 30;
        } else if (D_i9_802C80DC == 2) {
            vertical = 0;
            D_i9_802C80CC -= 30;
        } else if (D_i9_802C80DC == 3) {
            vertical = 1;
            D_i9_802C80D0 -= 30;
        } else {
            vertical = 1;
            D_i9_802C80D0 += 30;
        }
        done = 0;
        if (vertical == 0) {
            if (D_i9_802C80CC < -319 || D_i9_802C80CC >= 320) {
                done = 1;
            }
        } else if (D_i9_802C80D0 < -239 || D_i9_802C80D0 >= 240) {
            done = 1;
        }
        if (done) {
            D_i9_802C80D0 = 0;
            D_i9_802C80CC = 0;
            D_i9_802C80DC = 0;
            D_i9_802C80E4[0].unk8 = D_i9_802C80E4[1].unk8;
            D_i9_802C80E4[0].unkC = D_i9_802C80E4[1].unkC;
        }
        if (D_i9_802C80E0 != 0) {
            D_i9_802C80D4 = D_i9_802C80CC;
            D_i9_802C80D8 = D_i9_802C80D0;
            D_i9_802C80E0 = D_i9_802C80DC;
            D_i9_802C8104[0].unk8 = D_i9_802C80E4[0].unk8;
            D_i9_802C8104[1].unk8 = D_i9_802C80E4[1].unk8;
        }
    }

    func_800481E0(D_801CE5F8->unkA40, &D_802C8280, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB8, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.025f);
    func_800484C8(&sp78, &sp138, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB8, &sp178);
    SysUtils_MatrixAffineMultiply(&sp138, &sp178, &spF8);

    for (j = 0; j < count; j++) {
        n = j * 4;
        x = D_i9_802C80E4[j].unk0 + D_i9_802C80CC;
        y = D_i9_802C80E4[j].unk0 + D_i9_802C80D0; // unk0, not unk4: the asm loads one word for both
        for (k = 0; k < 3; k++) {
            SysUtils_MtxFToMtx(&spF8, &D_801CE5F8->unkA80[n + k]);
            D_801CE5F8->unk1280[n + k] = D_i9_802C8128;
            D_801CE5F8->unk1280[n + k].vp.vtrans[0] = (x + 76) << 2;
            D_801CE5F8->unk1280[n + k].vp.vtrans[1] = (y + 138 + k * 18) << 2;
        }
        SysUtils_MtxFToMtx(&spF8, &D_801CE5F8->unkA80[n + k]);
        D_801CE5F8->unk1280[n + k] = D_i9_802C8128;
        D_801CE5F8->unk1280[n + k].vp.vtrans[0] = (x + 76) << 2;
        D_801CE5F8->unk1280[n + k].vp.vtrans[1] = (y + 206) << 2;
    }
}

Gfx* func_i9_802C5D24(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x42) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gdl = func_i9_802C6750(gdl);

    if (gGameState == 0x42) {
        if (D_i9_802C80DC == 0) {
            func_i9_802C5E5C();
        }
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x3C:
                GameState_EnterOptionsMenu();
                break;
            case 0x02:
                GameState_EnterTitleScreen();
                break;
            case 0x50:
                func_801EC830();
        }
    }

    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5E5C.s")

// The first arrow's dtdy 0xFC00 makes gSPScisTextureRectangle expand yl*dtdy to (y + 21) << 2*0xFC00, a shift
// IDO folds to none (the original's code); gcc's check pass warns about it.
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
#endif
Gfx* func_i9_802C6750(Gfx* gdl) {
    s32 j;
    s32 count;
    s32 x;
    s32 y;

    if (D_i9_802C80DC == 0) {
        count = 1;
    } else {
        count = 2;
    }

    gSPMatrix(gdl++, D_7000000, (G_MTX_PROJECTION | G_MTX_LOAD) | G_MTX_NOPUSH);
    gSPMatrix(gdl++, D_2000A40, (G_MTX_MODELVIEW | G_MTX_LOAD) | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_106F550);

    for (j = 0; j < count; j++) {
        x = D_i9_802C8104[j].unk0 + D_i9_802C80D4;
        y = D_i9_802C8104[j].unk4 + D_i9_802C80D8;
        switch (D_i9_802C8104[j].unk8) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                gSPDisplayList(gdl++, D_106F628);
                gdl = func_80094338(gdl, 0, x + 28, y + 30, 264, 24);
                gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                gdl = func_801E3EE0(gdl, 2, D_800DAA34[D_i9_802C8104[j].unk8],
                                    D_i9_802C8174[D_i9_802C8104[j].unk8] + x + 76, y + 33, 0);
                gDPLoadTextureBlock(gdl++, D_8060008, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                gSPScisTextureRectangle(gdl++, (x + 152) << 2, (y + 21) << 2, (x + 160) << 2, (y + 29) << 2, 0, 0,
                                        7 << 5, 1 << 10, 0xFC00);
                gSPScisTextureRectangle(gdl++, (x + 152) << 2, (y + 211) << 2, (x + 160) << 2, (y + 219) << 2, 0, 0, 0,
                                        1 << 10, 1 << 10);
                break;
            case 10:
                break;
        }
        x = D_i9_802C80E4[j].unk0 + D_i9_802C80CC;
        y = D_i9_802C80E4[j].unk4 + D_i9_802C80D0;
        switch (D_i9_802C80E4[j].unk8) {
            case 10:
                gdl = func_i9_802C6CC8(gdl, x);
                break;
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                gdl = func_i9_802C71AC(gdl, j, D_i9_802C80E4[j].unk8, D_i9_802C80E4[j].unkC, x, y);
                break;
        }
    }
    return gdl;
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

Gfx* func_i9_802C6CC8(Gfx* gdl, s32 x) {
    s32 i;
    s32 mode;

    gSPDisplayList(gdl++, D_106F628);
    for (i = 0; i < 9; i++) {
        gdl = func_80094338(gdl, 0, x + 28 + (i / 5) * 133, (i % 5) * 18 + 95, 131, 16);
    }
    gdl = func_80094338(gdl, 0, x + 28, 68, 87, 16);
    gdl = func_80094338(gdl, 0, x + 117, 68, 87, 16);
    gdl = func_80094338(gdl, 0, x + 206, 68, 87, 16);
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 7, x + 72, 29, 0);

    for (i = 0; i < 3; i++) {
        gdl = Printer_SetMode(gdl, (i == D_i9_802C80C4) ? 6 : 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                              255, 255);
        gdl = func_801E3EE0(gdl, 1, D_i9_802C8138[i], D_i9_802C8144[i] + x + i * 89 + 52, 71, 0);
    }

    for (i = 0; i < 9; i++) {
        if (D_i9_802C80C0 == 0) {
            if (D_i9_802C80C4 == 0) {
                if (i == 0) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else {
                mode = 0;
            }
        } else if (D_i9_802C80C4 == 0) {
            if (i == 0) {
                mode = 7;
            } else if (i == D_i9_802C80C8) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else if (i == D_i9_802C80C8) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = func_801E3EE0(gdl, 1, D_800DAA10[D_800DAAD8[i]], D_i9_802C8150[D_800DAAD8[i]] + x + (i / 5) * 133 + 55,
                            (i % 5) * 18 + 98, 0);
    }
    return gdl;
}

void func_i9_802C7194(UnkStruct_i9_802C80E4* panel, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    panel->unk0 = arg1;
    panel->unk4 = arg2;
    panel->unk8 = arg3;
    panel->unkC = arg4;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C71AC.s")

void func_i9_802C802C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x43;
    D_801CE638 = 0xC;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
}
