#include "global.h"

/* Two panels, drawn at unk0 + D_i9_802C80CC, unk4 + D_i9_802C80D0 */
typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ s32 unkC;
} UnkStruct_i9_802C80E4; // size = 0x10

extern s32 D_800DAA10[];
extern s32 D_800DAA08;
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 gStuntRecords[][3];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
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
extern s32 D_i9_802C8198[];
extern s32 D_i9_802C81A4;
extern s32 D_i9_802C81B4;
extern u16 D_i9_802C8280;

void ViewRecords_Input(void);
Gfx* ViewRecords_DrawPanels(Gfx* gdl);
Gfx* ViewRecords_DrawCourseList(Gfx* gdl, s32 x);
Gfx* ViewRecords_DrawRecordsPanel(Gfx* gdl, s32 panel, s32 course, s32 kind, s32 x, s32 y);
void ViewRecords_SetPanel(UnkStruct_i9_802C80E4* panel, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void ViewRecords_Leave(s32 arg0);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);

void ViewRecords_OverlayUpdate(void) {
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

    func_800481E0(D_801CE5F8->unkA40, &D_i9_802C8280, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
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

Gfx* ViewRecords_Draw(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x42) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gdl = ViewRecords_DrawPanels(gdl);

    if (gGameState == 0x42) {
        if (D_i9_802C80DC == 0) {
            ViewRecords_Input();
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

void ViewRecords_Input(void) {
    s32 sound = false;
    s32 course;
    s32 first;

    if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
        if (D_i9_802C80E4[0].unk8 == 10) {
            switch (D_i9_802C80C0) {
                case 0:
                    sound = true;
                    if (D_i9_802C80C4 == 0) {
                        D_i9_802C80C8 = 1;
                        D_i9_802C80C0 = 1;
                    } else if (D_i9_802C80C4 == 1) {
                        D_i9_802C80C8 = 0;
                        D_i9_802C80C0 = 1;
                    } else {
                        ViewRecords_Leave(60);
                    }
                    break;
                case 1:
                    sound = true;
                    D_i9_802C80DC = 2;
                    course = D_800DAAD8[D_i9_802C80C8];
                    ViewRecords_SetPanel(&D_i9_802C80E4[1], 320, 0, course, (D_i9_802C80C4 == 0) ? 1 : 2);
                    D_i9_802C80E0 = 2;
                    ViewRecords_SetPanel(&D_i9_802C8104[1], 320, 0, course, 0);
                    AudioGeneral_PlaySound(0x2A, 0);
                    break;
            }
        } else if (D_i9_802C81A4 != 0) {
            sound = true;
            if (D_800DAA08 != 0) {
                ViewRecords_Leave(2);
            } else {
                ViewRecords_Leave(80);
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if ((D_801CE65A->unk0 & CONT_B) && D_i9_802C81A4 == 0) {
        if (D_i9_802C80E4[0].unk8 == 10) {
            switch (D_i9_802C80C0) {
                case 0:
                    ViewRecords_Leave(60);
                    break;
                case 1:
                    D_i9_802C80C0 = 0;
                    break;
            }
        } else {
            if (D_i9_802C80E4[0].unkC == 1 || D_i9_802C80E4[0].unkC == 3) {
                D_i9_802C80C4 = 0;
            } else {
                D_i9_802C80C4 = 1;
            }
            D_i9_802C80DC = 1;
            ViewRecords_SetPanel(&D_i9_802C80E4[1], -320, 0, 10, 0);
            D_i9_802C80E0 = 1;
            ViewRecords_SetPanel(&D_i9_802C8104[1], -320, 0, 10, 0);
            AudioGeneral_PlaySound(0x2A, 0);
        }
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE65A->unk0 & CONT_UP) {
        if (D_i9_802C80E4[0].unk8 == 10) {
            if (D_i9_802C80C0 == 1) {
                sound = true;
                D_i9_802C80C8--;
                if (D_i9_802C80C8 < ((D_i9_802C80C4 == 0) ? 1 : 0)) {
                    D_i9_802C80C8 = 8;
                }
            }
        } else {
            first = (D_i9_802C80C4 == 0) ? 1 : 0; // FAKE: unused; found by the permuter, it fixes the t1/t2 allocation
            D_i9_802C80C8--;
            if (D_i9_802C80E4[0].unkC == 2) {
                if (D_i9_802C80C8 < 0) {
                    D_i9_802C80C8 = 8;
                }
            } else if (D_i9_802C80C8 <= 0) {
                D_i9_802C80C8 = 8;
            }
            course = D_800DAAD8[D_i9_802C80C8];
            D_i9_802C80DC = 4;
            ViewRecords_SetPanel(&D_i9_802C80E4[1], 0, -240, course, D_i9_802C80E4[0].unkC);
            D_i9_802C80E0 = 4;
            ViewRecords_SetPanel(&D_i9_802C8104[1], 0, -240, course, 0);
            AudioGeneral_PlaySound(0x2A, 0);
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_DOWN) {
        if (D_i9_802C80E4[0].unk8 == 10) {
            if (D_i9_802C80C0 == 1) {
                sound = true;
                D_i9_802C80C8++;
                first = (D_i9_802C80C4 == 0) ? 1 : 0;
                if (D_i9_802C80C8 >= 9) {
                    D_i9_802C80C8 = first;
                }
            }
        } else {
            D_i9_802C80C8++;
            if (D_i9_802C80C8 >= 9) {
                if (D_i9_802C80E4[0].unkC == 2) {
                    D_i9_802C80C8 = 0;
                } else {
                    D_i9_802C80C8 = 1;
                }
            }
            course = D_800DAAD8[D_i9_802C80C8];
            D_i9_802C80DC = 3;
            ViewRecords_SetPanel(&D_i9_802C80E4[1], 0, 240, course, D_i9_802C80E4[0].unkC);
            D_i9_802C80E0 = 3;
            ViewRecords_SetPanel(&D_i9_802C8104[1], 0, 240, course, 0);
            AudioGeneral_PlaySound(0x2A, 0);
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if ((D_801CE65A->unk0 & CONT_LEFT) && D_i9_802C81A4 == 0) {
        if (D_i9_802C80E4[0].unk8 != 0) {
            if (D_i9_802C80E4[0].unk8 == 10) {
                sound = true;
                switch (D_i9_802C80C0) {
                    case 0:
                        D_i9_802C80C4--;
                        if (D_i9_802C80C4 < 0) {
                            D_i9_802C80C4 = 2;
                        }
                        break;
                    case 1:
                        if (D_i9_802C80C4 != 0 || D_i9_802C80C8 != 5) {
                            if (D_i9_802C80C8 != 4) {
                                D_i9_802C80C8 -= 5;
                                if (D_i9_802C80C8 < 0) {
                                    D_i9_802C80C8 += 10;
                                }
                            }
                        }
                        break;
                }
            } else if (D_i9_802C80E4[0].unkC == 2) {
                D_i9_802C80DC = 1;
                ViewRecords_SetPanel(&D_i9_802C80E4[1], -320, 0, D_800DAAD8[D_i9_802C80C8],
                                     (D_i9_802C80E4[0].unkC == 1) ? 2 : 1);
                AudioGeneral_PlaySound(0x2A, 0);
            } else if (D_i9_802C80E4[0].unkC == 1 && D_i9_802C81B4 != 0) {
                D_i9_802C80DC = 1;
                ViewRecords_SetPanel(&D_i9_802C80E4[1], -320, 0, D_800DAAD8[D_i9_802C80C8], 3);
                AudioGeneral_PlaySound(0x2A, 0);
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if ((D_801CE65A->unk0 & CONT_RIGHT) && D_i9_802C81A4 == 0) {
        if (D_i9_802C80E4[0].unk8 != 0) {
            if (D_i9_802C80E4[0].unk8 == 10) {
                sound = true;
                switch (D_i9_802C80C0) {
                    case 0:
                        D_i9_802C80C4++;
                        if (D_i9_802C80C4 == 3) {
                            D_i9_802C80C4 = 0;
                        }
                        break;
                    case 1:
                        if (D_i9_802C80C4 != 0 || D_i9_802C80C8 != 5) {
                            if (D_i9_802C80C8 != 4) {
                                D_i9_802C80C8 += 5;
                                if (D_i9_802C80C8 >= 9) {
                                    D_i9_802C80C8 -= 10;
                                }
                            }
                        }
                        break;
                }
            } else if (D_i9_802C80E4[0].unkC == 1) {
                D_i9_802C80DC = 2;
                ViewRecords_SetPanel(&D_i9_802C80E4[1], 320, 0, D_800DAAD8[D_i9_802C80C8],
                                     (D_i9_802C80E4[0].unkC == 1) ? 2 : 1);
                AudioGeneral_PlaySound(0x2A, 0);
            } else if (D_i9_802C80E4[0].unkC == 3) {
                D_i9_802C80DC = 2;
                ViewRecords_SetPanel(&D_i9_802C80E4[1], 320, 0, D_800DAAD8[D_i9_802C80C8], 1);
                AudioGeneral_PlaySound(0x2A, 0);
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}

// The first arrow's dtdy 0xFC00 makes gSPScisTextureRectangle expand yl*dtdy to (y + 21) << 2*0xFC00, a shift
// IDO folds to none (the original's code); gcc's check pass warns about it.
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshift-count-overflow"
#endif
Gfx* ViewRecords_DrawPanels(Gfx* gdl) {
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
                gdl = ViewRecords_DrawCourseList(gdl, x);
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
                gdl = ViewRecords_DrawRecordsPanel(gdl, j, D_i9_802C80E4[j].unk8, D_i9_802C80E4[j].unkC, x, y);
                break;
        }
    }
    return gdl;
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

Gfx* ViewRecords_DrawCourseList(Gfx* gdl, s32 x) {
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
        gdl = Printer_SetMode(gdl, (i == D_i9_802C80C4) ? 6 : 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                              255);
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

void ViewRecords_SetPanel(UnkStruct_i9_802C80E4* panel, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    panel->unk0 = arg1;
    panel->unk4 = arg2;
    panel->unk8 = arg3;
    panel->unkC = arg4;
}

Gfx* ViewRecords_DrawRecordsPanel(Gfx* gdl, s32 panel, s32 course, s32 kind, s32 x, s32 y) {
    UnkStruct_AF8C0_14* rec;
    UnkStruct_AF8C0_10* stunt;
    s32 i;
    s32 flag;
    s32 base;
    s32 count;
    s32 rider;
    s32 mode;
    s32 tex;
    s32 off;
    s8* name;
    char buf[8];

    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, x + 38, y + 70, 244, 24);
    gdl = func_80094338(gdl, 0, x + 28, y + 104, 264, 16);
    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, x + 28, y + 126 + i * 18, 264, 16);
    }
    if (kind == 1 || kind == 3) {
        gdl = func_80094338(gdl, 0, x + 28, y + 183, 264, 10);
        gdl = func_80094338(gdl, 0, x + 28, y + 194, 264, 16);
    }
    gdl = func_801E7E74(gdl, 0, 0, 0, 255);
    for (i = 0; i < 3; i++) {
        gdl = func_801E7FD8(gdl, x + 60, y + 128 + i * 18, x + 86, y + 140 + i * 18);
    }
    if (kind == 1 || kind == 3) {
        gdl = func_801E7FD8(gdl, x + 60, y + 196, x + 86, y + 208);
    }
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gSPPerspNormalize(gdl++, D_i9_802C8280);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);

    if (panel == 0) {
        base = 0;
    } else {
        base = 4;
    }
    if (kind == 3) {
        count = 1;
    } else {
        count = 3;
    }
    // Viewport and matrix by their segment 7 address (the pool D_801CE5F8 is segment 7).
    for (i = 0; i < count; i++) {
        if (kind == 1) {
            rider = gBestTimes[course][i].unk4;
        } else if (kind == 3) {
            rider = D_801C23B0[course].unk4;
        } else {
            rider = gStuntRecords[course][i].unk4;
        }
        gSPViewport(gdl++, &((UnkStruct_801CE5F8*) D_7000000)->unk1280[base + i]);
        gSPMatrix(gdl++, &((UnkStruct_801CE5F8*) D_7000000)->unkA80[base + i],
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, rider, 0, 0, D_801CE5F8->unkC80[base + i]);
    }
    if (kind == 1) {
        gSPViewport(gdl++, &((UnkStruct_801CE5F8*) D_7000000)->unk1280[base + i]);
        gSPMatrix(gdl++, &((UnkStruct_801CE5F8*) D_7000000)->unkA80[base + i],
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, gBestLaps[course].unk4, 0, 0, D_801CE5F8->unkC80[base + i]);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    if (kind == 1) {
        gdl = func_801E3EE0(gdl, 3, 5, x + 61, y + 74, 2);
    } else if (kind == 3) {
        gdl = func_801E3EE0(gdl, 3, 32, x + 51, y + 74, 2);
    } else {
        gdl = func_801E3EE0(gdl, 3, 4, x + 51, y + 74, 2);
    }
    gdl = func_801E3EE0(gdl, 1, 31, x + 43, y + 107, 0);
    if (kind == 1 || kind == 3) {
        tex = 3;
        gdl = func_801E3EE0(gdl, 1, 17, x + 95, y + 107, 0);
        gdl = func_801E3EE0(gdl, 1, 32, x + 160, y + 107, 0);
        gdl = func_801E3EE0(gdl, 0, 13, x + 38, y + 184, 0);
    } else {
        tex = 62;
        gdl = func_801E3EE0(gdl, 1, 32, x + 139, y + 107, 0);
    }
    gdl = func_801E3EE0(gdl, 1, tex, x + 238, y + 107, 0);

    for (i = 0; i < 3; i++) {
        if (D_i9_802C81A4 != 0) {
            if (i == D_801C2660[course] - 1) {
                mode = 6;
            } else if (kind == 3) {
                if (i == 0) {
                    mode = 0;
                } else {
                    mode = 7;
                }
            } else {
                mode = 0;
            }
        } else if (kind == 3) {
            if (i == 0) {
                mode = 0;
            } else {
                mode = 7;
            }
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        if (kind == 1) {
            rec = &gBestTimes[course][i];
            name = rec->unk10;
            flag = rec->unk8;
            gdl = Printer_DrawTime(gdl, 2, rec->unk0, x + 215, y + 128 + i * 18);
            gdl = Printer_DrawString(gdl, 2, name, x + 160, y + 128 + i * 18);
            gdl = func_801E3EE0(gdl, 0, D_i9_802C8198[rec->unkC], x + 95, y + 129 + i * 18, 0);
        } else if (kind == 3) {
            rec = &D_801C23B0[course];
            flag = rec->unk8;
            if (i == 0) {
                gdl = Printer_DrawTime(gdl, 2, rec->unk0, x + 215, y + 128 + i * 18);
                gdl = Printer_DrawString(gdl, 2, rec->unk10, x + 160, y + 128 + i * 18);
            } else {
                gdl = Printer_DrawString(gdl, 2, "-'--@---", x + 215, y + 128 + i * 18);
                gdl = Printer_DrawString(gdl, 2, "---", x + 160, y + 128 + i * 18);
            }
            gdl = func_801E3EE0(gdl, 0, 36, x + 95, y + 129 + i * 18, 0);
        } else {
            stunt = &gStuntRecords[course][i];
            flag = stunt->unk8;
            gdl = func_80094200(gdl, 2, stunt->unk0, x + 228, y + 128 + i * 18);
            gdl = Printer_DrawString(gdl, 2, stunt->unkC, x + 139, y + 128 + i * 18);
        }
        if (kind == 3) {
            if (i == 0) {
                sprintf(buf, "%1d", i + 1);
            } else {
                sprintf(buf, "-", i + 1); // the original passes the unused argument too
            }
        } else {
            sprintf(buf, "%1d", i + 1);
        }
        if (kind != 3) {
            if (i == 2) {
                off = -1;
            } else {
                off = 0;
            }
        } else {
            off = 2;
        }
        gdl = Printer_DrawString(gdl, 2, buf, x + off + 37, y + 128 + i * 18);
        if (flag == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        if (kind != 3 || i == 0) {
            gdl = Printer_DrawString(gdl, 1, buf, x + 79, y + 128 + i * 18);
        }
    }

    if (kind == 1) {
        if (D_i9_802C81A4 != 0) {
            if (D_801C2690[course] != 0) {
                mode = 6;
            } else {
                mode = 0;
            }
            gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        }
        rec = &gBestLaps[course];
        if (rec->unk8 == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        gdl = Printer_DrawString(gdl, 1, buf, x + 79, y + 196);
        gdl = Printer_DrawString(gdl, 2, rec->unk10, x + 160, y + 196);
        gdl = Printer_DrawTime(gdl, 2, rec->unk0, x + 215, y + 196);
        gdl = func_801E3EE0(gdl, 0, D_i9_802C8198[rec->unkC], x + 95, y + 197, 0);
    } else if (kind == 3) {
        gdl = Printer_SetMode(gdl, 7, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = Printer_DrawString(gdl, 2, "---", x + 155, y + 302); // y + 302 as in the asm (off screen)
        gdl = Printer_DrawString(gdl, 2, "-'--@---", x + 215, y + 196);
        gdl = func_801E3EE0(gdl, 0, 36, x + 95, y + 197, 0);
    }

    gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    if (course != 0 && D_i9_802C81A4 == 0) {
        if (kind == 1) {
            gdl = Printer_DrawString(gdl, 2, ">", x + 290, y + 78);
            if (D_i9_802C81B4 != 0) {
                gdl = Printer_DrawString(gdl, 2, "<", x + 22, y + 78);
            }
        } else if (kind == 3) {
            gdl = Printer_DrawString(gdl, 2, ">", x + 290, y + 78);
        } else {
            gdl = Printer_DrawString(gdl, 2, "<", x + 22, y + 78);
        }
    }
    return gdl;
}

void ViewRecords_Leave(s32 arg0) {
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
