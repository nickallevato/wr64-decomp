#include "common.h"

extern s32 D_801CB288[];
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern const s16 D_800EABBC[][8];
extern RiderStruct gRiderRaceState[];
extern s32 D_i5_802C7A2C[];
extern s16 D_i5_802C7A00;
extern Vp D_i5_802C7A08;
extern s32 D_i5_802C7B00;
extern s16 D_i5_802C7B04;
extern u16 D_i5_802C7B06;
extern s32 D_i5_802C7B08;
extern s32 D_i5_802C7B0C;
extern s32 D_i5_802C7A18[];
extern s32 D_801C2650;
extern s32 D_801CB350[][4];
extern s32 D_801CE704; // D_801CE6FC + 8 in the asm; its symbol is in linker_scripts/us/rev1/resolve.txt
extern s32 D_800DA9DC[];
extern s32 D_801CE718[];
extern u8 gPrinterWidthsFont0[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];

s32 Save_EepromWriteHeader(void);
void func_800C3E4C(void);
void func_801EC944(void);
Gfx* func_i5_802C5DC0(Gfx*);
void RaceResults_Update(void);
void func_i5_802C6F84(s32 arg0);
void GameState_EnterCeremony(void);
void GameState_EnterCourseOverview(void);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);

void func_i5_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_RACE_RESULTS)) {
        func_80094ACC();
        func_i5_802C5A98();
    }
    func_i5_802C5850();
}

void func_i5_802C5850(void) {
    s32 i;
    f32 temp_fv1; // FAKE: temp needed for match
    f32 temp_fa0; // FAKE: temp needed for match
    MtxF sp174;
    MtxF sp134;
    MtxF spF4;
    Mtx spB0;
    Mtx sp70;

    D_i5_802C7B04 = 0x28 - D_i5_802C7A00;
    func_800481E0(D_801CE5F8->unkA40, &D_i5_802C7B06, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f);
    temp_fv1 = COS(0) * 500.0f;
    temp_fa0 = SIN(0) * 500.0f;
    // FAKE: arg3 is an int 0 literal to match (li a3, 0)
    func_800484C8(&sp70, &sp134, temp_fv1, 0, temp_fa0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB0, &sp174);
    SysUtils_MatrixAffineMultiply(&sp134, &sp174, &spF4);

    for (i = 0; i < 4; i++) {
        SysUtils_MtxFToMtx(&spF4, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_i5_802C7A08;
        if (i & 1) {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (D_i5_802C7B04 + 0x42) << 2;
        } else {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (D_i5_802C7A00 + 0x42) << 2;
        }
        D_801CE5F8->unk1280[i].vp.vtrans[1] = ((i * 0x20) + 0x58) << 2;
    }
}

void func_i5_802C5A98(void) {
    s32 last = D_i5_802C7A2C[gDifficulty];
    s32 need = D_800EABBC[gDifficulty][D_801CB334];

    if (D_801CB340[gPlayer1Rider] >= need) {
        if (D_801CB334 >= last) {
            if (gDifficulty == DIFFICULTY_NORMAL) {
                D_801CB280 |= 1;
            } else if (gDifficulty == DIFFICULTY_HARD) {
                D_801CB280 |= 2;
            } else if (gDifficulty == DIFFICULTY_EXPERT) {
                D_801CB280 |= 4;
                if (gRiderRaceState[gPlayer1Rider].unk338 == 0) {
                    D_801CB280 |= 8;
                }
            }
            D_i5_802C7B08 = 0x66;
            D_i5_802C7B00 = 2;
        } else {
            D_i5_802C7B08 = 0x1E;
            D_i5_802C7B00 = 1;
        }
    } else {
        D_i5_802C7B08 = 0x5A;
        D_i5_802C7B00 = 0;
    }
    func_800C21F4(3, (D_i5_802C7B00 != 0) ? 0 : 1);
}

Gfx* func_i5_802C5C1C(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_RACE_RESULTS) {
            osViBlack(false);
            return func_80093C44(gdl);
        }
    }

    gdl = func_80093F78(gdl);
    D_800DAB2C = 0;
    gdl = func_800949B8(gdl, gCourseID);
    gdl = func_8008FB74(gdl);
    gdl = Draw_WaterEffects(gdl);
    gdl = func_i5_802C5DC0(gdl);

    if (gGameState == GAME_STATE_RACE_RESULTS) {
        RaceResults_Update();
    } else if (D_80228A16 == 1) {
        if (D_801CE630 == 0x66) {
            GameState_EnterCeremony();
        } else if (D_801CE630 == 0x1E) {
            D_801CB334++;
            if (D_800DAB68 != 0) {
                if (D_801CB288[3] < D_801CB334) {
                    D_801CB288[3] = D_801CB334;
                }
            } else {
                if (D_801CB288[gDifficulty] < D_801CB334) {
                    D_801CB288[gDifficulty] = D_801CB334;
                }
            }
            GameState_EnterCourseOverview();
        } else {
            GameState_EnterTitleScreen();
        }
    }

    if (D_801CE638 != 9) {
        Save_EepromWriteHeader();
    }
    return gdl;
}

Gfx* func_i5_802C5DC0(Gfx* gdl) {
    s32 i;
    s32 mode;
    s32 showPoints;
    s32 x;
    s32 titleX;
    s32 titleW;
    s32 count;
    s32 tieRank;
    s32 rank;
    s32 timeMode;
    s32 valueMode;
    s32 value;
    s32 valueX;
    s32 placeX;
    s32 j;
    s32 start;
    s32 rider;
    s32 panelMode;
    s32 pad; // stack pad
    PlayerName* name;
    char placeBuf[12];
    char valueBuf[12];

    switch (D_801CE640) {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            showPoints = 1;
            titleX = 13;
            titleW = 244;
            break;

        default:
            showPoints = 0;
            titleX = 36;
            titleW = 191;
            break;
    }

    if (showPoints == 0) {
        panelMode = 0;
    } else {
        panelMode = 2;
    }

    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, panelMode, D_i5_802C7A00 + titleX + 8, 25, titleW, 24);
    gdl = func_80094338(gdl, panelMode, D_i5_802C7B04 + 8, 52, 265, 16);
    gdl = func_80094338(gdl, panelMode, D_i5_802C7A00 + 8, 199, 265, 16);
    for (i = 0; i < 4; i++) {
        if (i & 1) {
            x = D_i5_802C7B04;
        } else {
            x = D_i5_802C7A00;
        }
        gdl = func_80094338(gdl, panelMode, x + 8, 71 + i * 32, 265, 28);
    }

    placeX = 0;
    gdl = Printer_SetMode(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    if (showPoints == 0) {
        gdl = func_801E3EE0(gdl, 2, 20, D_i5_802C7A00 + 53, 28, 0);
        gdl = func_801E3EE0(gdl, 1, 79, D_i5_802C7A00 + 24, 202, 0);
    } else {
        gdl = func_801E3EE0(gdl, 2, 21, D_i5_802C7A00 + 41, 28, 0);
        gdl = func_801E3EE0(gdl, 1, 6, D_i5_802C7A00 + 24, 202, 0);
    }
    gdl = func_801E3EE0(gdl, 1, 31, D_i5_802C7B04 + 13, 55, 0);
    gdl = func_801E3EE0(gdl, 1, 32, D_i5_802C7B04 + 109, 55, 0);
    gdl = func_801E3EE0(gdl, 1, 58, D_i5_802C7B04 + 215, 55, 0);

    gdl = func_801E7E74(gdl, 0, 0, 0, 255);
    for (i = 0; i < 4; i++) {
        if (i & 1) {
            x = D_i5_802C7B04;
        } else {
            x = D_i5_802C7A00;
        }
        gdl = func_801E7FD8(gdl, x + 42, 74 + i * 32, x + 86, 95 + i * 32);
    }

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 310, 218);

    rank = count = tieRank = 1;
    for (i = 0; i < 4; i++) {
        if (i & 1) {
            x = D_i5_802C7B04;
        } else {
            x = D_i5_802C7A00;
        }

        if (showPoints == 0) {
            if (i != 0) {
                count++;
                if (D_801CB350[D_801CB334][D_801CE718[i]] != D_801CB350[D_801CB334][D_801CE718[i - 1]]) {
                    tieRank = count;
                    rank = count;
                } else {
                    rank = tieRank;
                }
            }
            if (gRiderRaceState[D_801CE718[i]].finishState != 0) {
                placeX = 6;
                sprintf(placeBuf, "%s", "R");
            } else {
                sprintf(placeBuf, "%d", count);
            }
            name = &gPlayerNames[D_800DA9B0[D_801CE718[i]]];
            value = D_801CB350[D_801CB334][D_801CE718[i]];
            if (gPlayer1Rider != D_801CE718[i]) {
                mode = 0;
                timeMode = 0;
                valueMode = 0;
            } else {
                mode = 6;
                valueMode = 6;
                if (D_801C2650 != 1) {
                    timeMode = 6;
                } else {
                    timeMode = 4;
                }
            }
        } else {
            if (i != 0) {
                count++;
                if (D_801CB340[D_800DA9DC[i]] != D_801CB340[D_800DA9DC[i - 1]]) {
                    tieRank = count;
                    rank = count;
                } else {
                    rank = tieRank;
                }
            }
            sprintf(placeBuf, "%d", rank);
            name = &gPlayerNames[D_800DA9B0[D_800DA9DC[i]]];
            value = D_801CB340[D_800DA9DC[i]];
            if (gPlayer1Rider != D_800DA9DC[i]) {
                mode = 0;
                timeMode = 0;
            } else {
                mode = 6;
                if (D_801C2650 != 1) {
                    timeMode = 6;
                } else {
                    timeMode = 7;
                }
            }
            if (D_801CE640 < 6) {
                valueMode = 0;
            } else if (gPlayer1Rider != D_800DA9DC[i]) {
                valueMode = 0;
            } else if (D_i5_802C7B00 != 0) {
                valueMode = 6;
            } else {
                do { // FAKE: an empty block; it keeps the final loop's index in memory, as in the original
                } while (0);
                valueMode = 4;
            }
        }

        sprintf(valueBuf, "%d", value);
        if ((value / 10) % 10 != 0) {
            valueX = 228 - gPrinterWidthsFont0[(value / 10) % 10];
        } else {
            valueX = 228;
        }
        gdl = Printer_Print(gdl, 0, placeBuf, x + placeX + 13, 75 + i * 32, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gdl = Printer_Print(gdl, 2, name->unk_0, x + 92, 75 + i * 32, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                            0xFF, 0xFF, 0xFF, 0xFF);
        gdl = Printer_Print(gdl, 0, valueBuf, x + valueX + 8, 75 + i * 32, valueMode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

        if (showPoints == 0) {
            if (gRiderRaceState[D_801CE718[i]].finishState != 0) {
                gdl =
                    Printer_SetMode(gdl, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                gdl = func_801E3EE0(gdl, 0, 27, x + 92, 88 + i * 32, 0);
            } else {
                gdl = Printer_PrintTime(gdl, 1, gRiderRaceState[D_801CE718[i]].raceTime, x + 92, 88 + i * 32, timeMode,
                                        0xFF, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        } else {
            gdl =
                Printer_SetMode(gdl, valueMode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            gdl = func_801E3EE0(gdl, 0, 24, x + 92, 88 + i * 32, 0);
            if (gDifficulty == DIFFICULTY_NORMAL) {
                start = 1;
            } else {
                start = 0;
            }
            for (j = start; j <= D_801CB334; j++) {
                value = D_801CB350[j][D_800DA9DC[i]];
                if (j != D_801CB334) {
                    sprintf(valueBuf, "%d-", value);
                } else {
                    sprintf(valueBuf, "%d", value);
                }
                gdl = Printer_Print(gdl, 1, valueBuf, 132 + x + (j - start) * 12, 88 + i * 32, valueMode, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    if (showPoints == 0) {
        if (D_i5_802C7B00 != 0) {
            mode = 0;
        } else {
            mode = 4;
        }
        gdl = Printer_SetMode(gdl, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gdl = func_801E3EE0(gdl, 1, D_i5_802C7A18[D_801CE704], D_i5_802C7A00 + 160, 202, 0);
    } else {
        if (D_801CE640 < 6) {
            mode = 0;
        } else if (D_i5_802C7B00 != 0) {
            mode = 6;
        } else {
            mode = 4;
        }
        gdl = Printer_SetMode(gdl, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gdl = Printer_DrawNumber(gdl, 2, D_800EABBC[gDifficulty][D_801CB334], D_i5_802C7A00 + 242, 201);
    }

    gSPPerspNormalize(gdl++, D_i5_802C7B06);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    for (i = 0; i < 4; i++) {
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (showPoints == 1) {
            rider = D_800DA9B0[D_800DA9DC[i]];
        } else {
            rider = D_800DA9B0[D_801CE718[i]];
        }
        gdl = func_801E4FE8(gdl, rider, 0, 0, D_801CE5F8->unkC80[i]);
    }
    return gdl;
}

void RaceResults_Update(void) {
    s32 playSound = false;

    switch (D_801CE640) {
        case 0:
            if (D_80228A16 == 1) {
                D_801CE640 = 1;
                playSound = true;
            }
            break;

        case 1:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < 0x14) {
                D_801CE640 = 2;
                D_i5_802C7A00 = 0x14;
                D_801CE644 = 0;
            }
            break;

        case 2:
            if (D_801CE644 < 0x3C) {
                D_801CE644++;
            }
            if (D_801CE644 >= 0x1F) {
                if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                    D_801CE640 = 3;
                    playSound = true;
                }
            }
            break;

        case 3:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < -0x109) {
                D_801CE640 = 4;
                D_i5_802C7A00 = -0x109;
                playSound = true;
            }
            break;

        case 4:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 > 0x14) {
                D_801CE640 = 5;
                D_i5_802C7A00 = 0x14;
                D_i5_802C7B0C = 0;
            }
            break;

        case 5:
            if (D_i5_802C7B0C < 0x10) {
                D_i5_802C7B0C++;
            }
            if ((D_i5_802C7B0C == 6) && (D_i5_802C7B00 == 1)) {
                func_800C3E4C();
            }
            if (D_i5_802C7B0C >= 6) {
                if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                    D_801CE640 = 6;
                    D_801CE644 = 0;
                    AudioGeneral_PlaySound(0x11, 0);
                }
            }
            break;

        case 6:
            D_801CE644++;
            if (D_801CE644 >= 0x1E) {
                if (D_i5_802C7B08 != 0x5A) {
                    func_i5_802C6F84(D_i5_802C7B08);
                } else {
                    D_801CE640 = 7;
                    playSound = true;
                    func_800C1F60(5);
                }
            }
            break;

        case 7:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 > 0x140) {
                D_i5_802C7A00 = 0x140;
                func_801EC944();
            }
            break;
    }

    if (playSound) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}

void func_i5_802C6F84(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x35;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    if (D_801CE630 == 0x66) {
        FadeTransition_SetProps(1, 4, 0);
    } else if (D_801CE630 == 0x1E) {
        FadeTransition_SetProps(5, 2, 0);
    } else {
        FadeTransition_SetProps(5, 1, 0);
    }

    if (D_801CE630 == 0x66) {
        func_800C1F60(0xB);
    } else if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
    }
}
