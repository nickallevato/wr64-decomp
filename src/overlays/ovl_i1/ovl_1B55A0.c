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
extern s32 D_i1_802C96A0;
extern s32 D_i1_802C96A4;
extern s32 D_800D817C;
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 gStuntRecords[][3];
extern s32 D_801C2930;
extern Gfx D_106F1B8[];
extern s16 D_801CE628;
extern RiderStruct gRiderRaceState[];
// The asm names this array D_801CE6FC + 0xC; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE708[4];
// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;
// The asm names these D_801CB350 + 0x80 and + 0xA0; their symbols are in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CB3D0[];
extern s32 D_801CB3F0[2];
extern s32 D_801CB340[];
extern const s16 D_800EABB0[];
extern const s16 D_800EABBC[][8];
extern s32 D_80228AA8;
extern s32 D_i1_802C96D4;
extern u16 D_i1_802C96D8;
extern u8 D_i1_802C952B;
extern Vp D_i1_802C9560;
extern s32 D_i1_802C9544[];
extern s32 D_800DA9DC[];
extern s32 D_801CE718[];
extern u8 gPrinterWidthsFont0[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];
extern s32 D_i1_802C9444[][3];
extern TexEntry D_80226890[];

void Race_RankUnfinishedRiders(void);
s32 Save_EepromWriteCourse(s32);
s32 Save_EepromWriteRecord5(s32);
s32 Save_EepromWriteHeader(void);
Gfx* func_80093AFC(Gfx*);
void func_801EC830(void);
void func_800C37D4(s32);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);
void func_800BFE70(u8* arg0);
void Race_EnterState29(void);
void Race_EnterState2A(void);
void Race_EnterState2C(void);
s32 Save_EepromWriteStunt(s32);
void GameState_EnterTimeTrialsResults(void);
void GameState_EnterStuntModeResults(void);
void Camera_HandleCButtons(void);
Gfx* func_i1_802C6B38(Gfx* dList);
Gfx* func_i1_802C6BD8(Gfx* dList);
void Race_UpdateInRace(void);
void Race_UpdateState2A(void);
void Race_UpdateState29(void);
void Race_UpdateState2C(void);
void Race_EnterStandings(s32 arg0);
Gfx* RaceStandings_DrawTable(Gfx*);
void RaceStandings_Step(void);
void GameState_EnterCeremony(void);
void GameState_EnterCourseOverview(void);
void GameState_EnterRaceResults(void);

void Race_OverlayUpdate(void) {
    if ((D_801CE63C != 0) && (gGameState == 0x28)) {
        Race_FirstFrame();
    }
    if ((gCourseID == 0) && (D_801CE608.gameMode == 4) && (D_800DAB64 == 0)) {
        Race_UpdateScroller();
    }
}

void Race_FirstFrame(void) {
    D_i1_802C9440 = 0;
    if (D_801CE608.gameMode == 4) {
        if (gCourseID == 0) {
            D_i1_802C96A8 = D_i1_802C94C8;
        }
        D_i1_802C96CC = D_i1_802C9514[gDifficulty];
    }
}

void Race_UpdateScroller(void) {
    switch (D_i1_802C94EC) {
        case 0:
            if (--D_i1_802C94F0 <= 0) {
                D_i1_802C94EC = 1;
                D_i1_802C94F0 = 0;
            }
            break;

        case 1:
            D_i1_802C94EC = 2;
            Race_StartScroller(D_i1_802C94F4);
            if (++D_i1_802C94F4 >= 0xB) {
                D_i1_802C94F4 = 0;
            }
            break;

        case 2:
            if (D_i1_802C96A8.unk_0 == 0) {
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

void Race_StartScroller(s32 arg0) {
    UnkStruct_802C96A8* scroll;
    s32 i;
    s32 tex;
    s32 width;
    s32 x;

    scroll = &D_i1_802C96A8;
    *scroll = D_i1_802C94C8;
    scroll->unk_0 = 1;
    x = 290;
    for (i = 0; i < 3; i++) {
        tex = D_i1_802C9444[arg0][i];
        D_i1_802C96A8.unk_C[i] = x;
        D_i1_802C96A8.unk_18[i] = tex;
        if (tex != -1) {
            scroll->unk_4++;
            width = D_80226890[tex].width + 1;
            scroll->unk_8 += width;
            x += width;
        }
    }
    func_800C37D4(arg0);
}

Gfx* Race_Draw(Gfx* dList) {
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
        Race_UpdateInRace();
    } else if (gGameState == 0x29) {
        Race_UpdateState29();
    } else if (gGameState == 0x2A) {
        Race_UpdateState2A();
    } else if (gGameState == 0x2C) {
        Race_UpdateState2C();
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

void Race_UpdateInRace(void) {
    s32 flag;
    s32 points;
    s32 need;

    if ((D_80228A16 == 1) && (gGameState == 0x28)) {
        if ((D_800DAB64 != 0) && (gGameModes == GMODE_CHAMPIONSHIP) && (gCourseID == DOLPHIN_PARK)) {
            func_800BFE70((u8*) &D_80192610);
        } else {
            func_800BFDD0(&D_80192610);
        }
        func_800BFEF8((u8*) &D_80192630);
    }

    if (gCourseID == DOLPHIN_PARK) {
        if (D_801CE6FC != 0) {
            if (D_i1_802C9440 == 0) {
                gGameModeState = 1;
                D_i1_802C9440 = -1;
            }
            if ((gGameModeState == 2) && GAME_NOT_PAUSED) {
                gRiderGameModes = RACE_MODE;
            }
        }
    } else {
        flag = 0;
        if (D_i1_802C9440 >= 0) {
            D_i1_802C9440++;
            if (gPlayers == ONE_PLAYER) {
                if ((gGameModes == GMODE_STUNT) || (gGameModes == GMODE_TIME_TRIALS)) {
                    if (D_i1_802C9440 >= 10) {
                        flag = 1;
                    }
                } else if (D_i1_802C9440 >= 50) {
                    flag = 1;
                }
            } else if (D_i1_802C9440 >= 46) {
                flag = 1;
            }
            if (flag != 0) {
                gGameModeState = 1;
                D_i1_802C9440 = -1;
            }
        }
        if ((gGameModeState == 2) && GAME_NOT_PAUSED) {
            gRiderGameModes = RACE_MODE;
        }
    }

    if (gPlayers == ONE_PLAYER) {
        if (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) {
            if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
                D_801CB3D0[D_801CB334] = gRiderRaceState[gPlayer1Rider].raceTime;
                if (D_i1_802C96CC == D_801CB334) {
                    points = D_801CB340[0] + D_800EABB0[gRiderRaceState[gPlayer1Rider].racePosition];
                    need = D_800EABBC[gDifficulty][D_801CB334];
                    if (points >= need) {
                        D_i1_802C9510 = 1;
                    }
                }
            }
            Race_EnterState2A();
        } else if ((D_801CE72E != 0) && (gRiderRaceState[gPlayer1Rider].finishState != 0)) {
            if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
                D_801CB3D0[D_801CB334] = gRiderRaceState[gPlayer1Rider].raceTime;
                if (D_i1_802C96CC == D_801CB334) {
                    points = D_801CB340[0];
                    need = D_800EABBC[gDifficulty][D_801CB334];
                    if (points >= need) {
                        D_i1_802C9510 = 1;
                    }
                }
            }
            D_801CE6F0 = 1;
            Race_EnterState29();
        }
    } else if ((gRiderRaceState[gPlayer1Rider].unk2F4 != 0) && (gRiderRaceState[gPlayer2Rider].unk2F4 != 0)) {
        if (gRiderRaceState[gPlayer1Rider].raceTime == gRiderRaceState[gPlayer2Rider].raceTime) {
            D_801CE6F0 = 3;
            Race_EnterState2C();
            D_80228AA8 = 3;
        } else if (gRiderRaceState[gPlayer1Rider].raceTime < gRiderRaceState[gPlayer2Rider].raceTime) {
            D_801CE6F0 = 2;
            if (D_801CB3F0[0] < 99) {
                D_801CB3F0[0]++;
            }
            Race_EnterState2A();
            D_80228AA8 = 1;
        } else {
            D_801CE6F0 = 1;
            if (D_801CB3F0[1] < 99) {
                D_801CB3F0[1]++;
            }
            Race_EnterState2A();
            D_80228AA8 = 2;
        }
    } else if (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) {
        D_801CE6F0 = 2;
        if (D_801CB3F0[0] < 99) {
            D_801CB3F0[0]++;
        }
        Race_EnterState2A();
        D_80228AA8 = 1;
    } else if (gRiderRaceState[gPlayer2Rider].unk2F4 != 0) {
        D_801CE6F0 = 1;
        if (D_801CB3F0[1] < 99) {
            D_801CB3F0[1]++;
        }
        Race_EnterState2A();
        D_80228AA8 = 2;
    } else if (D_801CE72E != 0) {
        if ((gRiderRaceState[gPlayer1Rider].finishState != 0) && (gRiderRaceState[gPlayer2Rider].finishState != 0)) {
            D_801CE6F0 = 3;
            Race_EnterState2C();
            D_80228AA8 = 3;
        } else if (gRiderRaceState[gPlayer1Rider].finishState != 0) {
            D_801CE6F0 = 1;
            if (D_801CB3F0[1] < 99) {
                D_801CB3F0[1]++;
            }
            D_80228AA8 = 2;
        } else if (gRiderRaceState[gPlayer2Rider].finishState != 0) {
            D_801CE6F0 = 2;
            if (D_801CB3F0[0] < 99) {
                D_801CB3F0[0]++;
            }
            D_80228AA8 = 1;
        }
        if ((D_801CE6F0 == 1) || (D_801CE6F0 == 2)) {
            Race_EnterState29();
        }
    }
}

void Race_UpdateState29(void) {
    s32 i;

    if (gPlayers == ONE_PLAYER) {
        if (D_i1_802C9510 != 0) {
            if (D_i1_802C950C > 0) {
                D_i1_802C950C--;
            }
            if (D_i1_802C950C == 0) {
                Race_EnterStandings(0x66);
            }
        }
    } else if (D_i1_802C96A0 == 1) {
        D_i1_802C96A0 = 2;
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

void Race_UpdateState2A(void) {
    s32 i;

    if (((D_801CE608.gameMode == GMODE_TIME_TRIALS) || (D_801CE608.gameMode == GMODE_CHAMPIONSHIP)) &&
        (D_i1_802C9500 == 0)) {
        D_i1_802C9504--;
        if (D_i1_802C9504 < 0) {
            D_i1_802C9504 = 0;
        }
        if (D_i1_802C9504 == 0) {
            if (D_i1_802C9510 != 0) {
                Race_EnterStandings(0x66);
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

void Race_UpdateState2C(void) {
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
        if (D_i1_802C96A4 < 30) {
            D_800D817C = 1;
            if (D_801CE6F0 == 1) {}
        } else if (D_801CE6F0 == 1) {}
        if (++D_i1_802C96A4 > 60) {
            if (D_i1_802C96A0 == 0) {
                D_i1_802C96A0 = 1;
            }
        }
    }
    return dList;
}

Gfx* func_i1_802C6BD8(Gfx* dList) {
    UnkStruct_802C96A8* scroll;
    s32 i;

    gSPDisplayList(dList++, D_106F628);
    dList = func_80094338(dList, 0, 22, 197, 276, 20);
    if (D_i1_802C96A8.unk_0 != 0) {
        dList = Printer_SetMode(dList, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPPipeSync(dList++);
        gDPSetScissor(dList++, G_SC_NON_INTERLACE, 30, 20, 290, 218);
        scroll = &D_i1_802C96A8;
        for (i = 0; i < scroll->unk_4; i++) {
            if (D_i1_802C96A8.unk_18[i] != -1) {
                if (GAME_NOT_PAUSED) {
                    D_i1_802C96A8.unk_C[i] -= 2;
                }
                dList = func_801E3EE0(dList, 3, D_i1_802C96A8.unk_18[i], D_i1_802C96A8.unk_C[i], 200, 0);
            }
        }
        if (scroll->unk_C[0] < -scroll->unk_8) {
            scroll->unk_0 = 0;
        }
    }

    gDPPipeSync(dList++);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 0, 0, 319, 239);

    return dList;
}

void Race_EnterState29(void) {
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
    D_i1_802C96A4 = 0;
    D_i1_802C96A0 = 0;

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

void Race_EnterState2A(void) {
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

void Race_EnterState2C(void) {
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

void Race_Leave(s32 arg0) {
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

void Race_EnterStandings(s32 arg0) {
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

void RaceStandings_Update(void) {
    s32 i;
    s32 showPoints;
    s32 x;
    f32 temp_fv1; // FAKE: temp needed for match, as in RaceResults_SetModelMatrices
    f32 temp_fa0; // FAKE: temp needed for match
    MtxF sp154;
    MtxF sp114;
    MtxF spD4;
    Mtx sp90;
    Mtx sp50;

    if (D_801CE63C != 0) {
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
        func_80094ACC();
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
    }

    switch (D_i1_802C9520) {
        case 0:
            showPoints = 0;
            break;

        case 1:
            showPoints = 0;
            D_i1_802C9524 -= 40;
            if (D_i1_802C9524 < 20) {
                D_i1_802C9524 = 20;
            }
            break;

        case 2:
            showPoints = 0;
            break;

        case 3:
            showPoints = 0;
            D_i1_802C9524 -= 40;
            if (D_i1_802C9524 < -265) {
                D_i1_802C9524 = -265;
            }
            break;

        case 4:
            showPoints = 1;
            D_i1_802C96D0++;
            if (D_i1_802C96D0 > 10) {
                D_i1_802C96D0 = 10;
            }
            D_i1_802C952C = (D_i1_802C96D0 * 170) / 10;
            D_i1_802C9528 = (D_i1_802C96D0 * 255) / 10;
            break;

        case 5:
            showPoints = 1;
            D_i1_802C96D0++;
            if (D_i1_802C96D0 >= 16) {
                D_i1_802C96D0 = 0;
                if (D_i1_802C9530 > 0) {
                    D_i1_802C9530--;
                    AudioGeneral_PlaySound(0x31, 0);
                }
            }
            for (i = 0; i < 4; i++) {
                if (D_i1_802C9530 <= i) {
                    D_i1_802C9534[i] -= 60;
                    if (D_i1_802C9534[i] < 20) {
                        D_i1_802C9534[i] = 20;
                    }
                }
            }
            break;

        case 6:
        case 7:
            showPoints = 1;
            break;
    }

    D_i1_802C96D4 = 40 - D_i1_802C9524;
    func_800481E0(D_801CE5F8->unkA40, &D_i1_802C96D8, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&sp90, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f);
    temp_fv1 = COS(0) * 500.0f;
    temp_fa0 = SIN(0) * 500.0f;
    // FAKE: arg3 is an int 0 literal to match (li a3, 0), as in RaceResults_SetModelMatrices
    func_800484C8(&sp50, &sp114, temp_fv1, 0, temp_fa0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&sp90, &sp154);
    SysUtils_MatrixAffineMultiply(&sp114, &sp154, &spD4);

    for (i = 0; i < 4; i++) {
        if (showPoints == 0) {
            if (i & 1) {
                x = D_i1_802C96D4;
            } else {
                x = D_i1_802C9524;
            }
        } else {
            x = D_i1_802C9534[i];
        }
        SysUtils_MtxFToMtx(&spD4, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_i1_802C9560;
        // Both arms are the same in the original.
        if (i & 1) {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (x + 0x42) << 2;
        } else {
            D_801CE5F8->unk1280[i].vp.vtrans[0] = (x + 0x42) << 2;
        }
        D_801CE5F8->unk1280[i].vp.vtrans[1] = ((i * 0x20) + 0x58) << 2;
    }
}

Gfx* RaceStandings_Draw(Gfx* dList) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }

    dList = func_8009328C(dList);
    dList = func_80093AFC(dList);

    gDPPipeSync(dList++);
    gDPSetColorImage(dList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    dList = RaceStandings_DrawTable(dList);

    if (gPlayers == 1) {
        gSPDisplayList(dList++, D_106F168);
    }

    RaceStandings_Step();

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

Gfx* RaceStandings_DrawTable(Gfx* dList) {
    s32 i;
    s32 mode;
    s32 showPoints;
    s32 x;
    s32 titleX;
    s32 titleW;
    s32 headerX;
    s32 pad1; // stack pad: two unused words keep the original's slots
    s32 value;
    s32 pad2; // stack pad
    s32 timeMode;
    s32 valueMode;
    s32 placeX;
    s32 rank;
    s32 tieRank;
    s32 count;
    s32 j;
    s32 start;
    s32 rider;
    s32 valueX;
    PlayerName* name;
    char placeBuf[12];
    char valueBuf[12];

    switch (D_i1_802C9520) {
        case 0:
        case 1:
        case 2:
        case 3:
            titleX = 36;
            showPoints = 0;
            titleW = 191;
            break;

        case 4:
        case 5:
        case 6:
        case 7:
            showPoints = 1;
            titleX = 13;
            titleW = 244;
            break;
    }

    if (showPoints == 0) {
        mode = 0;
    } else {
        mode = 2;
    }

    gSPDisplayList(dList++, D_106F628);
    if (showPoints == 0) {
        dList = func_80094338(dList, mode, D_i1_802C9524 + titleX + 8, 25, titleW, 24);
        dList = func_80094338(dList, mode, D_i1_802C96D4 + 8, 52, 265, 16);
        dList = func_80094338(dList, mode, D_i1_802C9524 + 8, 199, 265, 16);
        for (i = 0; i < 4; i++) {
            if (i & 1) {
                x = D_i1_802C96D4;
            } else {
                x = D_i1_802C9524;
            }
            dList = func_80094338(dList, mode, x + 8, 71 + i * 32, 265, 28);
        }
    } else {
        gDPSetPrimColor(dList++, 0, 0, 255, 255, 255, D_i1_802C952C);
        dList = func_80094338(dList, mode, titleX + 28, 25, titleW, 24);
        dList = func_80094338(dList, mode, 28, 52, 265, 16);
        dList = func_80094338(dList, mode, 28, 199, 265, 16);
        for (i = 0; i < 4; i++) {
            dList = func_80094338(dList, mode, D_i1_802C9534[i] + 8, 71 + i * 32, 265, 28);
        }
    }

    placeX = 0;
    if (showPoints == 0) {
        dList = Printer_SetMode(dList, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 2, 20, D_i1_802C9524 + 53, 28, 0);
        dList = func_801E3EE0(dList, 1, 79, D_i1_802C9524 + 24, 202, 0);
    } else {
        dList = Printer_SetMode(dList, 10, D_i1_802C952B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 2, 21, 61, 28, 0);
        dList = func_801E3EE0(dList, 1, 6, 44, 202, 0);
    }

    if (showPoints == 0) {
        headerX = D_i1_802C96D4;
    } else {
        headerX = 20;
    }
    dList = func_801E3EE0(dList, 1, 31, headerX + 13, 55, 0);
    dList = func_801E3EE0(dList, 1, 32, headerX + 109, 55, 0);
    dList = func_801E3EE0(dList, 1, 58, headerX + 215, 55, 0);

    dList = func_801E7E74(dList, 0, 0, 0, 255);
    for (i = 0; i < 4; i++) {
        if (showPoints == 0) {
            if (i & 1) {
                x = D_i1_802C96D4;
            } else {
                x = D_i1_802C9524;
            }
        } else {
            x = D_i1_802C9534[i];
        }
        dList = func_801E7FD8(dList, x + 42, 74 + i * 32, x + 86, 95 + i * 32);
    }

    gDPPipeSync(dList++);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    rank = count = tieRank = 1;
    for (i = 0; i < 4; i++) {
        if (showPoints == 0) {
            if (i & 1) {
                x = D_i1_802C96D4;
            } else {
                x = D_i1_802C9524;
            }
        } else {
            x = D_i1_802C9534[i];
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
            if (gPlayer1Rider != D_800DA9DC[i]) {
                valueMode = 0;
            } else {
                valueMode = 6;
            }
        }

        sprintf(valueBuf, "%d", value);
        if ((value / 10) % 10 != 0) {
            valueX = 228 - gPrinterWidthsFont0[(value / 10) % 10];
        } else {
            valueX = 228;
        }
        dList = Printer_Print(dList, 0, placeBuf, x + placeX + 13, 75 + i * 32, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = Printer_Print(dList, 2, name->unk_0, x + 92, 75 + i * 32, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF);
        dList = Printer_Print(dList, 0, valueBuf, x + valueX + 8, 75 + i * 32, valueMode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

        if (showPoints == 0) {
            if (gRiderRaceState[D_801CE718[i]].finishState != 0) {
                dList = Printer_SetMode(dList, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                        0xFF);
                dList = func_801E3EE0(dList, 0, 27, x + 92, 88 + i * 32, 0);
            } else {
                dList = Printer_PrintTime(dList, 1, gRiderRaceState[D_801CE718[i]].raceTime, x + 92, 88 + i * 32, timeMode, 0xFF,
                                          0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        } else {
            dList = Printer_SetMode(dList, valueMode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            dList = func_801E3EE0(dList, 0, 24, x + 92, 88 + i * 32, 0);
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
                dList = Printer_Print(dList, 1, valueBuf, 132 + x + (j - start) * 12, 88 + i * 32, valueMode, 0xFF, 0xFF, 0xFF,
                                      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            }
        }
    }

    if (showPoints == 0) {
        dList = Printer_SetMode(dList, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = func_801E3EE0(dList, 1, D_i1_802C9544[D_801CE704], D_i1_802C9524 + 160, 202, 0);
    } else {
        if (D_i1_802C9558 == 0) {
            mode = 10;
        } else {
            mode = 6;
        }
        dList = Printer_SetMode(dList, mode, D_i1_802C952B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        dList = Printer_DrawNumber(dList, 2, D_800EABBC[gDifficulty][D_801CB334], 262, 201);
    }

    gSPPerspNormalize(dList++, D_i1_802C96D8);
    gSPMatrix(dList++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(dList++, D_106F488);
    for (i = 0; i < 4; i++) {
        gSPViewport(dList++, &D_7001280[i]);
        gSPMatrix(dList++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (showPoints == 1) {
            rider = D_800DA9DC[i];
        } else {
            rider = D_801CE718[i];
        }
        if (rider == 2) {
            rider = 3;
        } else if (rider == 3) {
            rider = 5;
        }
        dList = func_801E4FE8(dList, rider, 0, 0, D_801CE5F8->unkC80[i]);
    }
    return dList;
}

void RaceStandings_Step(void) {
    s32 i;
    s32 count; // also case 6's done flag: one variable in the original
    s32 flag = 0;

    switch (D_i1_802C9520) {
        case 0:
            if ((++D_i1_802C96D0) >= 60) {
                D_i1_802C9520 = 1;
                D_i1_802C96D0 = 0;
                flag = 1;
            }
            break;

        case 1:
            if (D_i1_802C9524 == 20) {
                D_i1_802C9520 = 2;
                D_i1_802C96D0 = 0;
            }
            break;

        case 2:
            if (D_i1_802C96D0 < 0x258) {
                D_i1_802C96D0++;
            }
            if (D_i1_802C96D0 >= 0x15) {
                if (D_801CE65A[0].unk0 & 0xB000) {
                    D_i1_802C9520 = 3;
                    D_i1_802C96D0 = 0;
                    AudioGeneral_PlaySound(0x11, 0);
                } else {
                    if (D_i1_802C96D0 >= 0x258) {
                        D_i1_802C9520 = 3;
                        D_i1_802C96D0 = 0;
                    }
                }
            }
            break;

        case 3:
            if (D_i1_802C9524 == (-0x109)) {
                D_i1_802C9520 = 4;
                D_i1_802C952C = 0;
                D_i1_802C96D0 = 0;
            }
            break;

        case 4:
            if (D_i1_802C96D0 == 0xA) {
                D_i1_802C9520 = 5;
                D_i1_802C96D0 = 0;
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
                D_i1_802C96D0 = 0;
            }
            break;

        case 6:
            count = 0;
            D_i1_802C96D0++;
            if (D_i1_802C96D0 >= 0x190) {
                count = 1;
            }
            if ((D_i1_802C96D0 >= 0x28) && (D_801CE65A[0].unk0 & 0xB000)) {
                AudioGeneral_PlaySound(0x11, 0);
                count = 1;
            }
            if (count != 0) {
                D_i1_802C9520 = 7;
                D_i1_802C96D0 = 0;
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

Gfx* Demo_Draw(Gfx* dList) {
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
            Demo_Leave(2);
        }
    } else if (D_80228A16 == 1) {
        GameState_EnterTitleScreen();
    }

    return dList;
}

void Demo_Leave(s32 arg0) {
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
