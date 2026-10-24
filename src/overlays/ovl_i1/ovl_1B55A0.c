#include "global.h"

extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801CB330;
extern s32 D_801CB334;
extern s32 D_801CB350[][4];
extern s32 D_i1_802C9500;
extern s32 D_i1_802C9504;
extern s32 D_i1_802C9508;
extern s32 D_i1_802C950C;
extern s32 D_i1_802C9510;
extern s32 D_802C96A0;
extern s32 D_802C96A4;
extern s32 D_800D817C;
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 gStuntRecords[][3];
extern s32 D_801C2930;
extern s16 D_800DAB60;
extern Gfx D_106F1B8[];
extern s16 D_801CE628;
extern RiderStruct gRiderRaceState[];
// The asm names this array D_801CE6FC + 0xC; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE708[4];
// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;
extern s32 D_i1_802C9444[][3];
extern TexEntry D_80226890[];

void Race_RankUnfinishedRiders(void);
s32 Save_EepromWriteCourse(s32);
s32 Save_EepromWriteRecord5(s32);
s32 Save_EepromWriteHeader(void);
Gfx* func_80093AFC(Gfx*);
void func_801EC830(void);
void func_800C37D4(s32);
s32 Save_EepromWriteStunt(s32);
void GameState_EnterTimeTrialsResults(void);
void GameState_EnterStuntModeResults(void);
void Camera_HandleCButtons(void);
Gfx* func_i1_802C6B38(Gfx* dList);
Gfx* func_i1_802C6BD8(Gfx* dList);
void func_i1_802C5DF4(void);
void func_i1_802C6550(void);
void func_i1_802C63B4(void);
void func_i1_802C6B00(void);
void func_i1_802C7570(s32 arg0);
Gfx* func_i1_802C7E48(Gfx*);
void func_i1_802C8E70(void);
void GameState_EnterCeremony(void);
void GameState_EnterCourseOverview(void);
void GameState_EnterRaceResults(void);

void func_i1_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 0x28)) {
        func_i1_802C587C();
    }
    if ((gCourseID == 0) && (D_801CE608.gameMode == 4) && (D_800DAB64 == 0)) {
        func_i1_802C5900();
    }
}

void func_i1_802C587C(void) {
    D_i1_802C9440 = 0;
    if (D_801CE608.gameMode == 4) {
        if (gCourseID == 0) {
            D_802C96A8 = D_i1_802C94C8;
        }
        D_802C96CC = D_i1_802C9514[gDifficulty];
    }
}

void func_i1_802C5900(void) {
    switch (D_i1_802C94EC) {
        case 0:
            if (--D_i1_802C94F0 <= 0) {
                D_i1_802C94EC = 1;
                D_i1_802C94F0 = 0;
            }
            break;

        case 1:
            D_i1_802C94EC = 2;
            func_i1_802C59E8(D_i1_802C94F4);
            if (++D_i1_802C94F4 >= 0xB) {
                D_i1_802C94F4 = 0;
            }
            break;

        case 2:
            if (D_802C96A8.unk_0 == 0) {
                D_i1_802C94EC = 0;
                if (D_i1_802C94F4 != 1) {
                    D_i1_802C94F0 = 0x64;
                } else {
                    D_i1_802C94F0 = 0;
                }
            }
            break;
    }
}

void func_i1_802C59E8(s32 arg0) {
    UnkStruct_802C96A8* scroll;
    s32 i;
    s32 tex;
    s32 width;
    s32 x;

    scroll = &D_802C96A8;
    *scroll = D_i1_802C94C8;
    scroll->unk_0 = 1;
    x = 290;
    for (i = 0; i < 3; i++) {
        tex = D_i1_802C9444[arg0][i];
        D_802C96A8.unk_C[i] = x;
        D_802C96A8.unk_18[i] = tex;
        if (tex != -1) {
            scroll->unk_4++;
            width = D_80226890[tex].width + 1;
            scroll->unk_8 += width;
            x += width;
        }
    }
    func_800C37D4(arg0);
}

Gfx* func_i1_802C5AE4(Gfx* dList) {
    s32 i;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x28) {
            return func_80093C44(dList);
        }
    }

    dList = func_8009328C(dList);
    if (GAME_NOT_PAUSED) {
        dList = func_801E5554(dList);
    }
    if (gPlayers == TWO_PLAYERS) {
        dList = func_i1_802C6B38(dList);
    }
    if ((gCourseID == DOLPHIN_PARK) && (D_801CE608.gameMode == 4) && (D_800DAB64 == 0)) {
        dList = func_i1_802C6BD8(dList);
    }
    if (gPlayers == ONE_PLAYER) {
        gSPDisplayList(dList++, D_106F168);
    } else {
        gSPDisplayList(dList++, D_106F1B8);
    }

    if (gGameState == 0x28) {
        Camera_HandleCButtons();
        func_i1_802C5DF4();
    } else if (gGameState == 0x29) {
        func_i1_802C63B4();
    } else if (gGameState == 0x2A) {
        func_i1_802C6550();
    } else if (gGameState == 0x2C) {
        func_i1_802C6B00();
    } else if ((gGameState == 0x2B) && (D_80228A16 == 1)) {
        gCurrentPauseMenuOption = -1;
        D_801CE628 = 0;
        switch (D_801CE630) {
            case 2:
                GameState_EnterTitleScreen();
                func_800AD3C4();
                break;

            case 40:
                func_8009345C();
                func_800AD3C4();
                break;

            case 10:
                GameState_EnterRiderSelect();
                func_800AD3C4();
                break;

            case 20:
                GameState_EnterCourseSelect();
                func_800AD3C4();
                break;

            case 30:
                if (D_801CB330 == 0) {
                    D_801CE608.rider = 4;
                    for (i = 0; i < D_801CE608.rider; i++) {
                        D_801CB350[D_801CB334][i] = 0;
                    }
                    D_801CB334++;
                } else {
                    D_801CE6F8 = 1;
                    D_801CB334 = 0;
                    if (gDifficulty == DIFFICULTY_NORMAL) {
                        D_801CB334 = 1;
                    }
                }
                GameState_EnterCourseOverview();
                func_800AD3C4();
                break;
        }
    }
    return dList;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C5DF4.s")

void func_i1_802C63B4(void) {
    s32 i;

    if (gPlayers == ONE_PLAYER) {
        if (D_i1_802C9510 != 0) {
            if (D_i1_802C950C > 0) {
                D_i1_802C950C--;
            }
            if (D_i1_802C950C == 0) {
                func_i1_802C7570(0x66);
            }
        }
    } else if (D_802C96A0 == 1) {
        D_802C96A0 = 2;
        FadeTransition_SetProps(1, 4, 0);
    }

    if (D_80228A16 == 1) {
        if (gPlayers == ONE_PLAYER) {
            switch (D_801CE608.gameMode) {
                case GMODE_CHAMPIONSHIP:
                    if (D_801CB330 == 0) {
                        D_801CE608.rider = 4;
                        for (i = 0; i < D_801CE608.rider; i++) {
                            D_801CB350[D_801CB334][i] = 0;
                        }
                        D_801CB334++;
                        GameState_EnterCourseOverview();
                    } else {
                        Race_RankUnfinishedRiders();
                        GameState_EnterRaceResults();
                    }
                    break;

                case GMODE_TIME_TRIALS:
                case GMODE_STUNT:
                    func_801EC830();
                    break;

                default:
                    GameState_EnterTitleScreen();
                    break;
            }
        } else {
            func_801ECE50();
        }
        func_800AD3C4();
    }
}

void func_i1_802C6550(void) {
    s32 i;

    if (((D_801CE608.gameMode == GMODE_TIME_TRIALS) || (D_801CE608.gameMode == GMODE_CHAMPIONSHIP)) &&
        (D_i1_802C9500 == 0)) {
        D_i1_802C9504--;
        if (D_i1_802C9504 < 0) {
            D_i1_802C9504 = 0;
        }
        if (D_i1_802C9504 == 0) {
            if (D_i1_802C9510 != 0) {
                func_i1_802C7570(0x66);
            } else {
                if (D_i1_802C9508 < 1200) {
                    D_i1_802C9508++;
                }
                if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (D_i1_802C9508 == 1200)) {
                    D_i1_802C9500 = 1;
                    FadeTransition_SetProps(1, 4, 0);
                }
            }
        }
    }

    if (D_80228A16 == 1) {
        func_800AD3C4();
        switch (D_801CE608.gameMode) {
            case GMODE_CHAMPIONSHIP:
                if (D_801CB330 == 0) {
                    D_801CE608.rider = 4;
                    GameState_EnterCourseOverview();
                    return;
                }
                if (D_801C2650 != 0) {
                    if (D_800DAB68 != 0) {
                        for (i = 0; i < 3; i++) {
                            D_801C23B0[gCourseID].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                        }
                        D_801C23B0[gCourseID].unk10[i] = 0;
                    } else {
                        for (i = 0; i < 3; i++) {
                            gBestTimes[gCourseID][D_801C2650 - 1].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                        }
                        gBestTimes[gCourseID][D_801C2650 - 1].unk10[i] = 0;
                    }
                }
                if (D_801C2654 != 0) {
                    for (i = 0; i < 3; i++) {
                        gBestLaps[gCourseID].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                    }
                    gBestLaps[gCourseID].unk10[i] = 0;
                }
                Race_RankUnfinishedRiders();
                if ((D_801C2650 != 0) || (D_801C2654 != 0)) {
                    if (D_800DAB68 != 0) {
                        Save_EepromWriteRecord5(gCourseID);
                    } else {
                        Save_EepromWriteCourse(gCourseID);
                    }
                }
                GameState_EnterRaceResults();
                return;

            case GMODE_TIME_TRIALS:
                if (D_801C2650 != 0) {
                    if (D_800DAB68 != 0) {
                        for (i = 0; i < 3; i++) {
                            D_801C23B0[gCourseID].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                        }
                        D_801C23B0[gCourseID].unk10[i] = 0;
                    } else {
                        for (i = 0; i < 3; i++) {
                            gBestTimes[gCourseID][D_801C2650 - 1].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                        }
                        gBestTimes[gCourseID][D_801C2650 - 1].unk10[i] = 0;
                    }
                }
                if (D_801C2654 != 0) {
                    for (i = 0; i < 3; i++) {
                        gBestLaps[gCourseID].unk10[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                    }
                    gBestLaps[gCourseID].unk10[i] = 0;
                }
                if ((D_801C2650 != 0) || (D_801C2654 != 0)) {
                    if (D_800DAB68 != 0) {
                        Save_EepromWriteRecord5(gCourseID);
                    } else {
                        Save_EepromWriteCourse(gCourseID);
                    }
                    func_801EC9C8();
                    return;
                }
                GameState_EnterTimeTrialsResults();
                return;

            case GMODE_STUNT:
                if (D_801C2928 != 0) {
                    for (i = 0; i < 3; i++) {
                        gStuntRecords[gCourseID][D_801C2928 - 1].unkC[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
                    }
                    gStuntRecords[gCourseID][D_801C2928 - 1].unkC[i] = 0;
                    Save_EepromWriteStunt(gCourseID);
                }
                if ((D_801C2930 != 0) && (D_800DAB60 == 0)) {
                    D_801CB280 |= 0x10;
                    D_800DAB60 = 1;
                    Save_EepromWriteHeader();
                }
                GameState_EnterStuntModeResults();
                return;

            default:
                func_801ECE50();
                break;
        }
    }
}

void func_i1_802C6B00(void) {
    if (D_80228A16 == 1) {
        func_800AD3C4();
        func_801ECE50();
    }
}

// The empty ifs keep the original's branches on D_801CE6F0 (their bodies were probably
// debug code compiled out).
Gfx* func_i1_802C6B38(Gfx* dList) {
    if (gGameState == 0x2A) {
        if (D_801CE6F0 == 1) {}
    } else if (gGameState == 0x29) {
        if (D_802C96A4 < 30) {
            D_800D817C = 1;
            if (D_801CE6F0 == 1) {}
        } else if (D_801CE6F0 == 1) {}
        if (++D_802C96A4 > 60) {
            if (D_802C96A0 == 0) {
                D_802C96A0 = 1;
            }
        }
    }
    return dList;
}

#ifdef NON_MATCHING
// Score 265 of 12500: scroll stays in s5, and the loop guard reads unk_4 by absolute address; the
// original keeps scroll in s0 for the guard, then moves it to s4 for the loop.
Gfx* func_i1_802C6BD8(Gfx* dList) {
    UnkStruct_802C96A8* scroll;
    s32 i;

    gSPDisplayList(dList++, D_106F628);
    dList = func_80094338(dList, 0, 22, 197, 276, 20);
    scroll = &D_802C96A8;
    if (scroll->unk_0 != 0) {
        dList = Printer_SetMode(dList, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPPipeSync(dList++);
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 30, 20, 290, 218);
        for (i = 0; i < scroll->unk_4; i++) {
            if (D_802C96A8.unk_18[i] != -1) {
                if (GAME_NOT_PAUSED) {
                    D_802C96A8.unk_C[i] -= 2;
                }
                dList = func_801E3EE0(dList, 3, D_802C96A8.unk_18[i], D_802C96A8.unk_C[i], 200, 0);
            }
        }
        if (scroll->unk_C[0] < -scroll->unk_8) {
            D_802C96A8.unk_0 = 0;
        }
    }

    gDPPipeSync(dList++);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 0, 0, 319, 239);

    return dList;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C6BD8.s")
#endif

void func_i1_802C6DCC(void) {
    s32 i;
    u16 param;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x29;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    D_802C96A4 = 0;
    D_802C96A0 = 0;

    if (D_801CE608.gameMode == 4) {
        for (i = 0; i < 4; i++) {
            if (D_801CE708[i] >= gRiderRaceState[i].racePosition) {
                D_801CB3F8[i] = 1;
            } else {
                D_801CB3F8[i] = 0;
            }
        }
    }

    if (gPlayers == ONE_PLAYER) {
        if (D_i1_802C9510 != 0) {
            D_i1_802C950C = 120;
        } else {
            FadeTransition_SetProps(1, 4, 120);
        }
    }
    Popup_Spawn(0, 0);

    if (gPlayers == ONE_PLAYER) {
        param = 0;
        if (gRiderRaceState[gPlayer1Rider].finishState == 1) {
            param = 0;
        } else if (gRiderRaceState[gPlayer1Rider].finishState == 2) {
            param = 1;
        }
        Popup_Spawn(4, param);
    }

    D_801CE62A = 0;
    func_800BFD34();
    func_800BFD68();
    func_800C1F60(4);
    func_800C21F4(4, 0);
}

void func_i1_802C6FE0(void) {
    s32 pad; // stack pad: the original frame is 0x28
    s32 i;
    s32 mode;
    s32 param;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x2A;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    D_i1_802C9500 = 0;

    if (D_801CE608.gameMode == 4) {
        for (i = 0; i < 4; i++) {
            if (D_801CE708[i] >= gRiderRaceState[i].racePosition) {
                D_801CB3F8[i] = 1;
            } else {
                D_801CB3F8[i] = 0;
            }
        }
    }

    if (gPlayers == ONE_PLAYER) {
        mode = D_80192690[gPlayer1Rider].unk16C8;
        if (mode == 1) {
            D_i1_802C9504 = 130;
        } else if (mode == 2) {
            D_i1_802C9504 = 140;
        } else if (mode == 3) {
            D_i1_802C9504 = 100;
        } else if (mode == 4) {
            D_i1_802C9504 = 120;
        } else if (mode == 5) {
            D_i1_802C9504 = 110;
        } else {
            D_i1_802C9504 = 100;
        }
        if (gGameModes == GMODE_STUNT) {
            FadeTransition_SetProps(1, 4, D_i1_802C9504);
        }
        D_i1_802C9508 = 0;
    } else {
        FadeTransition_SetProps(1, 4, 100);
    }

    Popup_Spawn(0, 0);
    if (gPlayers == ONE_PLAYER) {
        Popup_Spawn(1, 1);
    }

    D_801CE62A = 0;

    switch (D_801CE608.gameMode) {
        case 11:
            break;

        case 0:
            if (D_801C2650 == 1) {
                param = 0;
            } else {
                param = 1;
            }
            func_800C1F60(6);
            func_800C21F4(6, param);
            break;

        default:
            func_800C1F60(6);
            if (D_801CE704 >= gRiderRaceState[gPlayer1Rider].racePosition) {
                func_800C21F4(6, gRiderRaceState[gPlayer1Rider].racePosition + 1);
            } else {
                func_800C21F4(6, 5);
            }
            break;

        case 1:
            func_800C1F60(6);
            if (D_801CE6F0 == 3) {
                param = 0;
            } else if (D_801CE6F0 == 1) {
                param = 2;
            } else {
                param = 1;
            }
            func_800C21F4(6, param);
            break;
    }

    func_800BFD34();
    func_800BFD68();
}

void func_i1_802C7394(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 44;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    FadeTransition_SetProps(1, 4, 100);
    Popup_Spawn(0, 0);

    D_801CE62A = 0;

    func_800C1F60(4);
    func_800C21F4(4, 0);
    func_800BFD34();
    func_800BFD68();
}

void func_i1_802C744C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 43;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    FadeTransition_SetProps(1, 4, 0);

    D_801CE62A = 0;

    func_800BFD34();
    func_800BFD68();

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }

    if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
        return;
    }

    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
        return;
    }

    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }

    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
    }
}

void func_i1_802C7570(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x2D;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    Popup_Spawn(0, 0);
    D_80228AA4 = 1;
    func_800C21F4(3, 0);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C7608.s")

Gfx* func_i1_802C7D00(Gfx* dList) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }

    dList = func_8009328C(dList);
    dList = func_80093AFC(dList);

    gDPPipeSync(dList++);
    gDPSetColorImage(dList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    dList = func_i1_802C7E48(dList);

    if (gPlayers == 1) {
        gSPDisplayList(dList++, D_106F168);
    }

    func_i1_802C8E70();

    if (D_80228A16 == 1) {
        Save_EepromWriteHeader();
        if ((D_801C2650 != 0) || (D_801C2654 != 0)) {
            if (D_800DAB68 != 0) {
                Save_EepromWriteRecord5(gCourseID);
            } else {
                Save_EepromWriteCourse(gCourseID);
            }
        }
        GameState_EnterCeremony();
    }

    return dList;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i1/ovl_1B55A0/func_i1_802C7E48.s")

void func_i1_802C8E70(void) {
    s32 i;
    s32 count; // also case 6's done flag: one variable in the original
    s32 flag = 0;

    switch (D_i1_802C9520) {
        case 0:
            if ((++D_802C96D0) >= 60) {
                D_i1_802C9520 = 1;
                D_802C96D0 = 0;
                flag = 1;
            }
            break;

        case 1:
            if (D_i1_802C9524 == 20) {
                D_i1_802C9520 = 2;
                D_802C96D0 = 0;
            }
            break;

        case 2:
            if (D_802C96D0 < 0x258) {
                D_802C96D0++;
            }
            if (D_802C96D0 >= 0x15) {
                if (D_801CE65A[0].unk0 & 0xB000) {
                    D_i1_802C9520 = 3;
                    D_802C96D0 = 0;
                    AudioGeneral_PlaySound(0x11, 0);
                } else {
                    if (D_802C96D0 >= 0x258) {
                        D_i1_802C9520 = 3;
                        D_802C96D0 = 0;
                    }
                }
            }
            break;

        case 3:
            if (D_i1_802C9524 == (-0x109)) {
                D_i1_802C9520 = 4;
                D_i1_802C952C = 0;
                D_802C96D0 = 0;
            }
            break;

        case 4:
            if (D_802C96D0 == 0xA) {
                D_i1_802C9520 = 5;
                D_802C96D0 = 0;
                D_i1_802C952C = 0xAA;
                D_i1_802C9528 = 0xFF;
                D_i1_802C9530 = 3;
                AudioGeneral_PlaySound(0x31, 0);
            }
            break;

        case 5:
            count = 0;
            for (i = 0; i < 4; i++) {
                if (D_i1_802C9534[i] == 0x14) {
                    count++;
                }
            }
            if (i == count) {
                D_i1_802C9520 = 6;
                D_802C96D0 = 0;
            }
            break;

        case 6:
            count = 0;
            D_802C96D0++;
            if (D_802C96D0 >= 0x190) {
                count = 1;
            }
            if ((D_802C96D0 >= 0x28) && (D_801CE65A[0].unk0 & 0xB000)) {
                AudioGeneral_PlaySound(0x11, 0);
                count = 1;
            }
            if (count != 0) {
                D_i1_802C9520 = 7;
                D_802C96D0 = 0;
                D_i1_802C9558 = 1;
                FadeTransition_SetProps(3, 0x14, 0x14);
                func_800C1F60(0xB);
            }
            break;

        case 7:
            break;
    }

    if (flag != 0) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}

Gfx* func_i1_802C913C(Gfx* dList) {
    s32 var_v0;
    s32 flag;
    Gfx* gfxPtr = dList;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;

        if (gGameState == 7) {
            D_i1_802C9440 = 0;
            return func_80093C44(gfxPtr);
        }
    }

    if ((D_80228A16 == 1) && (gGameState == 7)) {
        func_800BFDD0(&D_80192610);
        func_800BFEF8((u8*) &D_80192630);
    }

    if (D_i1_802C9440 >= 0) {
        D_i1_802C9440++;
        flag = 0;

        if (gPlayers == 1) {
            if ((gGameModes == GMODE_STUNT) || (gGameModes == GMODE_TIME_TRIALS)) {
                if (D_i1_802C9440 >= 0xA) {
                    flag = 1;
                }
            } else if (D_i1_802C9440 >= 0x32) {
                flag = 1;
            }
        } else if (D_i1_802C9440 >= 0x2E) {
            flag = 1;
        }
        if (flag != 0) {
            gGameModeState = 1;
            D_i1_802C9440 = -1;
        }
    }

    D_800DAB2C = 0;

    dList = func_8009328C(dList);

    gDPPipeSync(dList++);

    if (gPlayers == 1) {
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    } else {
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 12, 311, 229);
    }

    if (gGameState == 7) {
        D_i1_802C9570++;
        if (gGameModes == GMODE_STUNT) {
            var_v0 = 600;
        } else {
            var_v0 = 800;
        }
        if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (var_v0 < D_i1_802C9570)) {
            func_i1_802C9380(2);
        }
    } else if (D_80228A16 == 1) {
        GameState_EnterTitleScreen();
    }

    return dList;
}

void func_i1_802C9380(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 8;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    FadeTransition_SetProps(1, 4, 0);
    Popup_Spawn(0, 0);
    func_800BFD34();
    func_800BFD68();

    if (D_801CE630 == 2) {
        func_800C1F60(0);
    }
}
