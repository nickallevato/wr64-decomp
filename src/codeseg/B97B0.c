#include <ultra64.h>
#include "variables.h"
#include "rider.h"
#include "camera.h"
#include "libc/math.h"

extern RiderStruct D_801C2C70[];
extern s32 D_800DA9C8[];
extern s32 D_80226EF0[];
extern s32 D_800DA9F8;
extern s32 D_800DA9FC;
extern s32 D_800DAA08;
extern s32 D_801CB334;
extern s16 D_800EAC44[][4];
extern s32 D_801CB330;
extern s32 D_801CE704;
extern s16 D_800DAA00;
extern s16 D_800EABEC[];
extern s16 D_800EAC14[][8];
extern UnkStruct_800DB568 D_800DB58C[];

void func_8004A208(void);
void func_8009684C(s32 arg0, s32 arg1, s32 arg2);
void func_800C4998(s32 arg0, s32 arg1);
void func_801EE040(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_801EE274(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_801EE4D0(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_801EE6F4(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_801EE91C(MtxF_t arg0, f32 x, f32 y, f32 z);

void GameState_EnterTitleScreen(void) {
    s32 pad[2]; // stack pad for the original's 0x30 frame
    s32 rider;
    s32 i;
    s32 course;
    s16 unk;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_TITLE_SCREEN;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gGameModes = GMODE_TIME_TRIALS;
    gPlayers = ONE_PLAYER;
    gRiders = 2;
    D_800D49B0 = 0x14;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    D_800D8178 = 1;
    D_801CE600 = 0;
    D_801CE6F8 = 0;
    D_801CB334 = 0;
    if (D_800D8240 == 0) {
        gCourseID = DOLPHIN_PARK;
    }
    D_801CE6F0 = 0;
    D_800DAB68 = 0;
    D_800DAB0C = 0;
    if (D_801CB280 & 0x10) {
        D_800DAB60 = 1;
    } else {
        D_800DAB60 = 0;
    }
    D_800DAB64 = 0;
    D_800DAA08 = 0;
    D_800DA9F8++;
    if (D_800DA9F8 >= 3) {
        D_800DA9F8 = 0;
    }
    D_800DA9FC++;
    if (D_800DA9FC >= 4) {
        D_800DA9FC = 0;
    }
    rider = D_800EAC44[D_800DA9FC][0];
    unk = D_800EAC44[D_800DA9FC][1];
    for (i = 0; i < gRiders; i++) {
        D_80192690[i].unkB68 = unk;
        D_80192690[i].unkB6C = D_800D96A4[gCourseID][unk].unk0;
        D_80192690[i].unkB70 = D_800D96A4[gCourseID][unk].unk4;
        D_80192690[i].unkB74 = D_800D96A4[gCourseID][unk].unk8;
    }
    D_80192690[gPlayer1Rider].unkB68 = rider;
    D_80192690[gPlayer1Rider].unkB6C = D_800D96A4[gCourseID][rider].unk0;
    D_80192690[gPlayer1Rider].unkB70 = D_800D96A4[gCourseID][rider].unk4;
    D_80192690[gPlayer1Rider].unkB74 = D_800D96A4[gCourseID][rider].unk8;
    D_801CE6F4[1] = 0;
    D_801CE6F4[0] = D_801CE6F4[1];
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_STARTED;
    func_80096960(1, rider, unk, 0, 0);
    course = gCourseID;
    if (course < DOLPHIN_PARK) {
        course = DOLPHIN_PARK;
    }
    if (course >= RIDER_SELECTION) {
        course = SOUTHERN_ISLAND;
    }
    func_8009684C(0x08060000, D_800DB568[course].unk0, D_800DB568[course].unk2);
    func_8004A208();
    FadeTransition_SetProps(0, 0, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 5;
    D_800DA9AC = 1;
    func_800C21F4(0, 0);
}

void GameState_EnterDemo(void) {
    s32 i;
    s32 course;
    s32 riders[4];

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_DEMO;
    D_801CE638 = 1;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gDifficulty = DIFFICULTY_EXPERT;
    switch (D_800DA9F8) {
        case 0:
            gGameModes = GMODE_CHAMPIONSHIP;
            gPlayers = ONE_PLAYER;
            gRiders = 4;
            D_801CB330 = 2;
            gCourseID = D_801CB330;
            riders[0] = D_800EAC44[D_800DA9FC][0];
            riders[1] = D_800EAC44[D_800DA9FC][1];
            riders[2] = D_800EAC44[D_800DA9FC][2];
            riders[3] = D_800EAC44[D_800DA9FC][3];
            func_80096960(0, riders[0], riders[1], riders[2], riders[3]);
            D_801CE728[0] = 3;
            D_801CE6F8 = 1;
            D_801CE704 = 4;
            func_800C4998(0, gCourseID);
            break;
        case 1:
            gGameModes = GMODE_STUNT;
            gPlayers = ONE_PLAYER;
            gRiders = 1;
            D_801CB330 = 1;
            gCourseID = D_801CB330;
            riders[0] = D_800EAC44[D_800DA9FC][0];
            riders[2] = riders[1] = riders[3] = 0;
            func_80096960(0, riders[0], riders[1], riders[2], riders[3]);
            D_801CE728[0] = 1;
            D_801CE6F8 = 0;
            func_800C4998(3, gCourseID);
            break;
        default:
            gGameModes = GMODE_2P_VS;
            gPlayers = TWO_PLAYERS;
            gRiders = 2;
            D_801CB330 = 1;
            gCourseID = D_801CB330;
            riders[0] = D_800EAC44[D_800DA9FC][0];
            riders[1] = D_800EAC44[D_800DA9FC][1];
            riders[2] = 0;
            riders[3] = 0;
            func_80096960(4, riders[0], riders[1], riders[0], riders[1]);
            D_801CE728[0] = 3;
            D_800D4970 = 0;
            D_801CE6F8 = 0;
            func_800C4998(1, gCourseID);
            break;
    }
    D_800D49B0 = 0x14;
    gBuoyMisses = 5;
    D_801CE608.gameMode = gGameModes;
    D_801CE608.player = gPlayers;
    D_801CE608.rider = gRiders;
    D_801CE608.waveLevel = D_800D49B0;
    D_801CE608.powerMisses = gBuoyMisses;
    D_801CE608.lapCount = D_801CE728[0];
    D_801CE608.unk_14 = 0;
    D_800D8178 = 0;
    D_801CE600 = 1;
    D_801CB334 = 0;
    D_801CE6F0 = 0;
    D_800DAB68 = 0;
    for (i = 0; i < gRiders; i++) {
        D_80192690[i].unkB68 = riders[i];
        D_80192690[i].unkB6C = D_800D96A4[gCourseID][riders[i]].unk0;
        D_80192690[i].unkB70 = D_800D96A4[gCourseID][riders[i]].unk4;
        D_80192690[i].unkB74 = D_800D96A4[gCourseID][riders[i]].unk8;
    }
    D_801CE6F4[1] = 0;
    D_801CE6F4[0] = D_801CE6F4[1];
    gRiderGameModes = AI_MODE;
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_0;
    course = gCourseID;
    if (course < DOLPHIN_PARK) {
        course = DOLPHIN_PARK;
    }
    if (course >= RIDER_SELECTION) {
        course = SOUTHERN_ISLAND;
    }
    func_8009684C(0x08060000, D_800DB568[course].unk0, D_800DB568[course].unk2);
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 3;
    if (gPlayers == TWO_PLAYERS) {
        gCameraPerspective[1].viewMode = gCameraPerspective->viewMode;
    }
}

void GameState_EnterCourseOverview(void) {
    s32 rand;
    s32 rider;
    s32 course;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_SATE_COURSE_OVERVIEW;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gPlayers = ONE_PLAYER;
    if (D_800D8240 != 0) {
        D_801CB330 = D_801C3A10;
    }
    D_801CB330 = D_800EAC14[gDifficulty][D_801CB334];
    gCourseID = D_801CB330;
    if ((gCourseID == DOLPHIN_PARK) && (D_800DAA00 < 9999)) {
        D_800DAA00++;
    }
    gGameModes = 0xA;
    D_800D49B0 = D_800EABEC[D_801CB330];
    gBuoyMisses = 5;
    if (gCourseID == SUNNY_BEACH) {
        gRiders = 4;
    } else if (gCourseID == SUNSET_BAY) {
        gRiders = 2;
    } else {
        gRiders = 1;
    }
    gCameraPerspective->viewMode = 5;
    if ((gCourseID == SUNNY_BEACH) || (gCourseID == 4)) {
        gRiderGameModes = UNACTIVE_MODE;
    } else {
        gRiderGameModes = AI_MODE;
    }
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_STARTED;
    D_800D8178 = 1;
    FadeTransition_SetProps(4, 0, 0);
    Popup_Spawn(0, 0);
    D_800DAA08 = 0;
    rider = D_800DA9B0[gPlayer1Rider];
    rand = SysUtils_Rand() & 3;
    if (rider == rand) {
        rand = (rand + 1) % 4;
    }
    if (D_801CE6F4[0] != 0) {
        rider += 4;
    }
    if (gCourseID == SUNNY_BEACH) {
        func_80096960(0, rider, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);
    } else {
        func_80096960(1, rider, rand, 0, 0);
    }
    D_80192690[gPlayer1Rider].unkB68 = D_800DA9B0[gPlayer1Rider];
    D_80192690[gPlayer1Rider].unkB6C = gPlayerNames[D_80192690[gPlayer1Rider].unkB68].unk_B[0];
    D_80192690[gPlayer1Rider].unkB70 = gPlayerNames[D_80192690[gPlayer1Rider].unkB68].unk_B[1];
    D_80192690[gPlayer1Rider].unkB74 = gPlayerNames[D_80192690[gPlayer1Rider].unkB68].unk_B[2];
    if (gCourseID == SUNSET_BAY) {
        D_80192690[gPlayer2Rider].unkB68 = D_800DA9B0[gPlayer1Rider];
    } else {
        D_80192690[gPlayer2Rider].unkB68 = D_800DA9B0[gPlayer2Rider];
    }
    D_80192690[gPlayer2Rider].unkB6C = gPlayerNames[D_80192690[gPlayer2Rider].unkB68].unk_B[0];
    D_80192690[gPlayer2Rider].unkB70 = gPlayerNames[D_80192690[gPlayer2Rider].unkB68].unk_B[1];
    D_80192690[gPlayer2Rider].unkB74 = gPlayerNames[D_80192690[gPlayer2Rider].unkB68].unk_B[2];
    D_80192690[2].unkB68 = D_800DA9B0[2];
    D_80192690[2].unkB6C = gPlayerNames[D_80192690[2].unkB68].unk_B[0];
    D_80192690[2].unkB70 = gPlayerNames[D_80192690[2].unkB68].unk_B[1];
    D_80192690[2].unkB74 = gPlayerNames[D_80192690[2].unkB68].unk_B[2];
    D_80192690[3].unkB68 = D_800DA9B0[3];
    D_80192690[3].unkB6C = gPlayerNames[D_80192690[3].unkB68].unk_B[0];
    D_80192690[3].unkB70 = gPlayerNames[D_80192690[3].unkB68].unk_B[1];
    D_80192690[3].unkB74 = gPlayerNames[D_80192690[3].unkB68].unk_B[2];
    course = gCourseID;
    if (course < DOLPHIN_PARK) {
        course = DOLPHIN_PARK;
    }
    if (course >= RIDER_SELECTION) {
        course = SOUTHERN_ISLAND;
    }
    func_8009684C(0x08060000, D_800DB58C[course].unk0, D_800DB58C[course].unk2);
    func_800C21F4(2, gCourseID);
}

void GameState_EnterRiderSelect(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_RIDER_SELECT;
    D_801CE638 = 4;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gGameModes = GMODE_TIME_TRIALS;
    if (D_801CE608.player == 1) {
        gPlayers = ONE_PLAYER;
        gRiders = 1;
    } else {
        gPlayers = TWO_PLAYERS;
        gRiders = 2;
    }
    D_800D49B0 = 0xA;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    gCourseID = RIDER_SELECTION;
    if (D_800DA9AC != 0) {
        D_800DA9C0[0] = 0;
        D_800DA9C0[1] = 3;
        D_800DA9C8[0] = D_800DA9C8[1] = 0;
    }
    D_80192690[gPlayer1Rider].unkB68 = D_80226EF0[D_800DA9C0[0]];
    D_80192690[gPlayer1Rider].unkB6C = D_800DA950[D_80192690[gPlayer1Rider].unkB68].unk_B[0];
    D_80192690[gPlayer1Rider].unkB70 = D_800DA950[D_80192690[gPlayer1Rider].unkB68].unk_B[1];
    D_80192690[gPlayer1Rider].unkB74 = D_800DA950[D_80192690[gPlayer1Rider].unkB68].unk_B[2];
    if (gPlayers == TWO_PLAYERS) {
        D_80192690[gPlayer2Rider].unkB68 = D_80226EF0[D_800DA9C0[1]];
        D_80192690[gPlayer2Rider].unkB6C = D_800DA950[D_80192690[gPlayer2Rider].unkB68].unk_B[0];
        D_80192690[gPlayer2Rider].unkB70 = D_800DA950[D_80192690[gPlayer2Rider].unkB68].unk_B[1];
        D_80192690[gPlayer2Rider].unkB74 = D_800DA950[D_80192690[gPlayer2Rider].unkB68].unk_B[2];
    }
    gRiderGameModes = AI_MODE;
    D_801CE64C = 2;
    gGameModeState = GMODE_STATE_STARTED;
    D_800DAB64 = 0;
    func_80096960(3, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 2;
    gCameraPerspective[1].viewMode = 2;
    switch (D_801CE608.gameMode) {
        case GMODE_CHAMPIONSHIP:
            func_800C21F4(1, 0);
            break;
        case GMODE_TIME_TRIALS:
            func_800C21F4(1, 2);
            break;
        case GMODE_STUNT:
            func_800C21F4(1, 3);
            break;
        case GMODE_2P_VS:
            func_800C21F4(1, 1);
            break;
    }
}

void GameState_EnterCourseSelect(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_COURSE_SELECT;
    D_801CE638 = 5;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gCourseID = SUNNY_BEACH;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 1;
    if (D_800DA9AC != 0) {
        D_800DA9D0 = 0;
    }
    func_800C21F4(0xA, 0);
    osViBlack(1);
}

void GameState_EnterRaceResults(void) {
    s32 i;
    s32 args[4];

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_RACE_RESULTS;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    for (i = 0; i < 4; i++) {
        args[i] = i;
    }
    if (D_801CE6F4[0] != 0) {
        args[D_800DA9B0[gPlayer1Rider]] += 4;
    }
    func_80096960(2, args[0], args[1], args[2], args[3]);
    FadeTransition_SetProps(4, 1, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 1;
    osViBlack(true);
}

void GameState_EnterTimeTrialsResults(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_TIME_TRIALS_RESULTS;
    D_801CE638 = 3;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    if (gPrevGameState != GAME_STATE_64) {
        func_80096960(2, 0, 1, 2, 3);
        FadeTransition_SetProps(4, 1, 0);
        Popup_Spawn(0, 0);
    }
    gCameraPerspective->viewMode = 1;
    func_800C21F4(3, 0);
}

void GameState_EnterOptionsMenu(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_OPTIONS_MENU;
    D_801CE638 = 7;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
    D_800E5134 = 0;
    func_800C21F4(9, 0);
}

void GameState_EnterChangeNames(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_OPTIONS_CHANGE_NAMES;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gPlayers = ONE_PLAYER;
    gRiders = 1;
    gCourseID = RIDER_SELECTION;
    gRiderGameModes = AI_MODE;
    D_801CE64C = 2;
    gGameModeState = GMODE_STATE_STARTED;
    D_80192690[gPlayer1Rider].unkB68 = 0;
    D_80192690[gPlayer1Rider].unkB6C = D_800DA950->unk_B[0];
    D_80192690[gPlayer1Rider].unkB70 = D_800DA950->unk_B[1];
    D_80192690[gPlayer1Rider].unkB74 = D_800DA950->unk_B[2];
    D_801CE6F4[1] = 0;
    D_801CE6F4[0] = D_801CE6F4[1];
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 2;
}

void GameState_EnterViewRecords(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x42;
    D_801CE638 = 0xC;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
}

void GameState_EnterChangeConditions(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x44;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
}

void GameState_EnterAudio(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x48;
    D_801CE638 = 0x14;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
}

void GameState_EnterEraseCourseRecords(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x46;
    D_801CE638 = 0x10;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
}

void GameState_EnterSaveAndLoad(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x40;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(2, 4, 0);
    Popup_Spawn(0, 0);
}

void func_801EC830(void) {
    s32 var_v1;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x50;
    D_801CE638 = 0xD;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;

    var_v1 = false;

    if (D_801CE608.gameMode == 4) {
        if (gPrevGameState == 0x43) {
            var_v1 = true;
        }
    } else if ((gPrevGameState != 0x32) && (gPrevGameState != 0x39)) {
        var_v1 = true;
    }
    if (var_v1) {
        FadeTransition_SetProps(4, 1, 0);
        osViBlack(true);
    }
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 1;
}

void func_801EC944(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x5A;
    D_801CE638 = 0xF;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    func_800C21F4(5, 0);
}

void func_801EC9C8(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x64;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = 1;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = 0;
    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 0xB)) {
        func_80096960(2, 0, 1, 2, 3);
    }
    if (gPrevGameState == 0x67) {
        FadeTransition_SetProps(7, 0x14, 0);
    } else if (gPrevGameState == 0x2A) {
        FadeTransition_SetProps(4, 1, 0);
    }
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 1;
    func_800C21F4(0xC, 0);
}

void GameState_EnterBootUp(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_BOOT_UP;
    D_801CE638 = 0x13;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 3;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(0, 0, 0);
    Popup_Spawn(0, 0);
    func_800C21F4(8, 0);
}

void GameState_EnterCeremony(void) {
    s32 i;
    s32 var_a1;

    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_CEREMONY;
    D_801CE638 = 0x15;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    gGameModes = GMODE_TIME_TRIALS;
    gPlayers = ONE_PLAYER;
    gRiders = 4;
    D_800D49B0 = 0xA;
    gBuoyMisses = 5;
    D_801CE728[0] = 3;
    gCourseID = GLACIER_COAST;
    D_800D8178 = 1;
    gRiderGameModes = AI_MODE;
    D_801CE64C = 0;
    gGameModeState = GMODE_STATE_STARTED;
    for (i = 0; i < 4; i++) {
        D_80192690[i].unkB68 = D_800DA9B0[i];
        D_80192690[i].unkB6C = D_800D96A4[gCourseID][D_800DA9B0[i]].unk0;
        D_80192690[i].unkB70 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk4;
        D_80192690[i].unkB74 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk8;
    }
    var_a1 = D_800DA9B0[gPlayer1Rider];
    if (D_801CE6F4[0] != 0) {
        var_a1 += 4;
    }
    func_80096960(2, var_a1, D_800DA9B0[1], D_800DA9B0[2], D_800DA9B0[3]);
    func_8009684C(0x08060000, 3, -1);
    FadeTransition_SetProps(7, 10, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 8;
    func_800C21F4(0xB, D_801C2C70[gPlayer1Rider].lapCount + 1);
}

void func_801ECE50(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_36;
    D_801CE638 = 0x12;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    FadeTransition_SetProps(4, 1, 0);
    Popup_Spawn(0, 0);
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    gCameraPerspective->viewMode = 1;
    osViBlack(1);
}

void GameState_EnterStuntModeResults(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = GAME_STATE_STUNT_MODE_RESULTS;
    D_801CE638 = 0x16;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = UNACTIVE_MODE;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    func_80096960(2, 0, 1, 2, 3);
    FadeTransition_SetProps(4, 1, 0);
    Popup_Spawn(0, 0);
    gCameraPerspective->viewMode = 1;
    func_800C21F4(3, 0);
    osViBlack(1);
}

void func_801ED004(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x39;
    D_801CE638 = 0x17;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    gPlayers = ONE_PLAYER;
    gRiderGameModes = 1;
    D_801CE64C = 1;
    gGameModeState = GMODE_STATE_0;
    gCameraPerspective->viewMode = 1;
}

f32 func_801ED090(f32 arg0) {
    if ((arg0 < -1.0f) || (arg0 > 1.0f)) {
        return 0.0f;
    }
    if (arg0 >= 0.0f) {
        return D_80226F08[(s32) (arg0 * 511.0f)];
    }
    return 180.0f - D_80226F08[(s32) (-arg0 * 511.0f)];
}

f32 func_801ED154(f32 arg0, f32 arg1) {
    s32 sp24 = 0;
    s32 sp20 = 0;
    f32 temp_f0;
    f32 var_f2;

    if ((arg1 == 0.0f) && (arg0 == 0.0f)) {
        return 0.0f;
    }

    if (arg1 < 0.0f) {
        arg1 = -arg1;
        sp24 = 1;
    }
    if (arg0 < 0.0f) {
        arg0 = -arg0;
        sp20 = 1;
    }

    var_f2 = sqrtf(SQ(arg1) + SQ(arg0));

    if (arg0 >= arg1) {
        temp_f0 = D_80226F08[(s32) (arg1 / var_f2 * 511)];
    } else {
        temp_f0 = 90.0f - D_80226F08[(s32) (arg0 / var_f2 * 511)];
    }

    if ((sp24 != 0) && (sp20 == 0)) {
        temp_f0 = 180.0 - temp_f0;
    } else if (sp24 && sp20) {
        temp_f0 += 180.0;
    } else if (!sp24 && sp20) {
        temp_f0 = 360.0 - temp_f0;
    }

    return temp_f0;
}

void Math_srand(void) {
    sRandSeed = osGetTime();
}

s32 Math_Rand(s32 arg0) {
    sRandSeed = (sRandSeed << 2) + sRandSeed + 1;

    return (sRandSeed * arg0) >> 16;
}

f32 Math_FloatRand(f32 arg0) {
    sRandSeed = (sRandSeed << 2) + sRandSeed + 1;

    return (arg0 * sRandSeed / 65536.0f);
}

s32 func_801ED388(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);
    arg0 = arg0 - arg1;
    arg0 = ABS(arg0);

    return (arg0 <= 180 ? arg0 : 360 - arg0);
}

s32 func_801ED43C(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);
    arg0 = arg0 - arg1;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

s32 func_801ED4E0(s32 arg0, s32 arg1) {
    arg0 = ABS_DEG(arg0);
    arg1 = ABS_DEG(arg1);

    if (arg0 == arg1) {
        return 0;
    }

    arg0 -= arg1;
    arg0 = (arg0 >= 0) ? arg0 : arg0 + 360;

    return (arg0 < 180 ? 1 : -1);
}

s32 func_801ED5A8(s32 arg0) {
    arg0 = ABS_DEG(arg0);

    if (arg0 > 270) {
        arg0 -= 360;
    } else if (arg0 > 90) {
        arg0 = 180 - arg0;
    }
    return arg0;
}

s32 func_801ED5F8(s32 arg0, s32 arg1) {
    arg0 = func_801ED5A8(arg0);
    arg1 = func_801ED5A8(arg1);
    arg0 = arg0 - arg1;

    return ABS(arg0);
}

s32 func_801ED63C(s32 arg0, s32 arg1) {
    arg0 = func_801ED5A8(arg0);
    arg1 = func_801ED5A8(arg1);
    arg0 = arg0 - arg1;

    return SIGNUM(arg0);
}

f32 func_801ED694(f32 arg0) {
    s32 temp_f12 = arg0 / 360;
    arg0 -= temp_f12 * 360;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

f32 func_801ED704(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);
    arg0 -= arg1;
    arg0 = ABS(arg0);

    return (arg0 <= 180 ? arg0 : 360 - arg0);
}

f32 func_801ED780(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);
    arg0 -= arg1;

    return (arg0 >= 0 ? arg0 : arg0 + 360);
}

s32 func_801ED7E4(f32 arg0, f32 arg1) {
    arg0 = func_801ED694(arg0);
    arg1 = func_801ED694(arg1);

    if (arg0 == arg1) {
        return 0;
    }

    arg0 -= arg1;
    arg0 = arg0 >= 0 ? arg0 : arg0 + 360;

    return (arg0 < 180 ? 1 : -1);
}

f32 func_801ED87C(f32 arg0) {
    arg0 = func_801ED694(arg0);
    if (arg0 > 270) {
        arg0 -= 360;
    } else if (arg0 > 90) {
        arg0 = 180 - arg0;
    }
    return arg0;
}

f32 func_801ED8EC(f32 arg0, f32 arg1) {
    arg0 = func_801ED87C(arg0);
    arg1 = func_801ED87C(arg1);
    arg0 = arg0 - arg1;

    return ABS(arg0);
}

s32 func_801ED944(f32 arg0, f32 arg1) {
    arg0 = func_801ED87C(arg0);
    arg1 = func_801ED87C(arg1);
    arg0 = arg0 - arg1;

    return SIGNUM(arg0);
}

f32 func_801ED9B4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp1C = sqrtf(SQ(arg0) + SQ(arg1) + SQ(arg2));
    f32 temp_f0 = sqrtf(SQ(arg3) + SQ(arg4) + SQ(arg5));

    if ((sp1C > 0.0f) && (temp_f0 > 0.0f)) {
        return (((arg0 * arg3) + (arg1 * arg4) + (arg2 * arg5)) / sp1C) / temp_f0;
    } else {
        return 0.0f;
    }
}

void func_801EDA80(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = (arg0 * arg4) - (arg1 * arg3);
}

void func_801EDAE0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6, f32* arg7, f32* arg8) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f2;

    *arg6 = (arg1 * arg5) - (arg2 * arg4);
    *arg7 = (arg2 * arg3) - (arg0 * arg5);
    *arg8 = temp_f0 = (arg0 * arg4) - (arg1 * arg3);
    temp_f2 = *arg6;
    temp_f16 = *arg7;
    temp_f0_2 = sqrtf(SQ(temp_f0) + (SQ(temp_f2) + SQ(temp_f16)));

    if (temp_f0_2 > 0.0f) {
        *arg6 /= temp_f0_2;
        *arg7 /= temp_f0_2;
        *arg8 /= temp_f0_2;
    }
}

void func_801EDBD4(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 temp_f0 = sqrtf((arg0 * arg0) + (arg1 * arg1) + (arg2 * arg2));

    if (temp_f0 > 0.0f) {
        *arg3 = arg0 / temp_f0;
        *arg4 = arg1 / temp_f0;
        *arg5 = arg2 / temp_f0;
    }
}

void func_801EDC60(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0[0][0] * arg1) + arg0[1][0] * arg2 + (arg0[2][0] * arg3) + arg0[3][0];
    *arg5 = (arg0[0][1] * arg1) + arg0[1][1] * arg2 + (arg0[2][1] * arg3) + arg0[3][1];
    *arg6 = (arg0[0][2] * arg1) + arg0[1][2] * arg2 + (arg0[2][2] * arg3) + arg0[3][2];
}

void func_801EDD04(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0[0][0] * arg1) + (arg0[1][0] * arg2) + (arg0[2][0] * arg3);
    *arg5 = (arg0[0][1] * arg1) + (arg0[1][1] * arg2) + (arg0[2][1] * arg3);
    *arg6 = (arg0[0][2] * arg1) + (arg0[1][2] * arg2) + (arg0[2][2] * arg3);
}

#define INTPART(x, y) dest->mu.intPart[x][y] = ((u32) fixedPoint >> 0x10)
#define FRACPART(x, y) dest->mu.fracPart[x][y] = fixedPoint & 0xFFFF

void _MtxF_to_Mtx(MtxF* src, Mtx* dest) {
    s32 fixedPoint;

    fixedPoint = src->mf[3][3] * 0x10000;
    INTPART(3, 3);
    FRACPART(3, 3);

    fixedPoint = src->mf[3][2] * 0x10000;
    INTPART(3, 2);
    FRACPART(3, 2);

    fixedPoint = src->mf[3][1] * 0x10000;
    INTPART(3, 1);
    FRACPART(3, 1);

    fixedPoint = src->mf[3][0] * 0x10000;
    INTPART(3, 0);
    FRACPART(3, 0);

    fixedPoint = src->mf[2][3] * 0x10000;
    INTPART(2, 3);
    FRACPART(2, 3);

    fixedPoint = src->mf[2][2] * 0x10000;
    INTPART(2, 2);
    FRACPART(2, 2);

    fixedPoint = src->mf[2][1] * 0x10000;
    INTPART(2, 1);
    FRACPART(2, 1);

    fixedPoint = src->mf[2][0] * 0x10000;
    INTPART(2, 0);
    FRACPART(2, 0);

    fixedPoint = src->mf[1][3] * 0x10000;
    INTPART(1, 3);
    FRACPART(1, 3);

    fixedPoint = src->mf[1][2] * 0x10000;
    INTPART(1, 2);
    FRACPART(1, 2);

    fixedPoint = src->mf[1][1] * 0x10000;
    INTPART(1, 1);
    FRACPART(1, 1);

    fixedPoint = src->mf[1][0] * 0x10000;
    INTPART(1, 0);
    FRACPART(1, 0);

    fixedPoint = src->mf[0][3] * 0x10000;
    INTPART(0, 3);
    FRACPART(0, 3);

    fixedPoint = src->mf[0][2] * 0x10000;
    INTPART(0, 2);
    FRACPART(0, 2);

    fixedPoint = src->mf[0][1] * 0x10000;
    INTPART(0, 1);
    FRACPART(0, 1);

    fixedPoint = src->mf[0][0] * 0x10000;
    INTPART(0, 0);
    FRACPART(0, 0);
}

void func_801EDF9C(MtxF_t arg0, f32 x, f32 y, f32 z) {
    arg0[3][3] = 1.0f;
    arg0[2][2] = 1.0f;
    arg0[1][1] = 1.0f;
    arg0[0][0] = 1.0f;

    arg0[2][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][2] = 0.0f;
    arg0[0][2] = 0.0f;
    arg0[2][1] = 0.0f;
    arg0[0][1] = 0.0f;
    arg0[2][0] = 0.0f;
    arg0[1][0] = 0.0f;

    arg0[3][0] = x;
    arg0[3][1] = y;
    arg0[3][2] = z;
}

void func_801EDFFC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    MtxF mtx;

    func_801EDF9C((float (*)[4]) & mtx, arg1, arg2, arg3);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
// Score 6045 of 12200: c and the 1.0f constant get no callee-saved register (frame 0x68, not 0x70), so the products
// spill.
void func_801EE040(MtxF_t arg0, f32 arg1, f32 x, f32 y, f32 z) {
    f32 len;
    f32 xx;
    f32 yy;
    f32 zz;
    s32 angle;
    f32 s;
    f32 c;
    f32 t;

    len = sqrtf(SQ(x) + SQ(y) + SQ(z));
    if (len > 0.0f) {
        x /= len;
        y /= len;
        z /= len;
    }
    xx = SQ(x);
    yy = SQ(y);
    zz = SQ(z);
    angle = ANGLE_TO_CUSTOM_UNITS(arg1);
    c = COS(angle);
    s = SIN(angle);
    arg0[3][0] = 0.0f;
    t = 1.0f - c;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
    arg0[0][0] = ((1.0f - xx) * c) + xx;
    arg0[2][1] = (y * z * t) - (x * s);
    arg0[1][2] = (x * s) + (y * z * t);
    arg0[1][1] = ((1.0f - yy) * c) + yy;
    arg0[2][0] = (y * s) + (z * x * t);
    arg0[0][2] = (z * x * t) - (y * s);
    arg0[2][2] = ((1.0f - zz) * c) + zz;
    arg0[1][0] = (x * y * t) - (z * s);
    arg0[0][1] = (z * s) + (x * y * t);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE040.s")
#endif

void func_801EE228(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    MtxF mtx;

    func_801EE040((float (*)[4]) & mtx, arg1, arg2, arg3, arg4);

    _MtxF_to_Mtx(&mtx, arg0);
}

#ifdef NON_MATCHING
// Score 4879 of 12600: ys and zxt stay in registers (the original keeps them on the stack), frame 0x60, not 0x68.
void func_801EE274(MtxF_t arg0, f32 arg1, f32 x, f32 y, f32 z, f32 arg5, f32 arg6, f32 arg7) {
    f32 len;
    f32 xx;
    f32 yy;
    f32 zz;
    s32 angle;
    f32 s;
    f32 c;
    f32 t;
    f32 ys;
    f32 zxt;

    len = sqrtf(SQ(x) + SQ(y) + SQ(z));
    if (len > 0.0f) {
        x /= len;
        y /= len;
        z /= len;
    }
    xx = SQ(x);
    yy = SQ(y);
    zz = SQ(z);
    angle = ANGLE_TO_CUSTOM_UNITS(arg1);
    s = SIN(angle);
    c = COS(angle);
    arg0[3][0] = arg5;
    arg0[3][1] = arg6;
    arg0[3][3] = 1.0f;
    arg0[3][2] = arg7;
    t = 1.0f - c;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[0][0] = ((1.0f - xx) * c) + xx;
    arg0[2][1] = (y * z * t) - (x * s);
    arg0[1][2] = (x * s) + (y * z * t);
    arg0[1][1] = ((1.0f - yy) * c) + yy;
    ys = y * s;
    zxt = z * x * t;
    arg0[2][0] = ys + zxt;
    arg0[0][2] = zxt - ys;
    arg0[2][2] = ((1.0f - zz) * c) + zz;
    arg0[1][0] = (x * y * t) - (z * s);
    arg0[0][1] = (z * s) + (x * y * t);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B97B0/func_801EE274.s")
#endif

void func_801EE46C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    MtxF mtx;

    func_801EE274((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE4D0(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 sxsy;

    sx = SIN(ANGLE_TO_CUSTOM_UNITS(arg1));
    sy = SIN(ANGLE_TO_CUSTOM_UNITS(arg2));
    sz = SIN(ANGLE_TO_CUSTOM_UNITS(arg3));
    cx = COS(ANGLE_TO_CUSTOM_UNITS(arg1));
    cy = COS(ANGLE_TO_CUSTOM_UNITS(arg2));
    cz = COS(ANGLE_TO_CUSTOM_UNITS(arg3));

    arg0[0][0] = cy * cz;
    sxsy = sx * sy;
    arg0[1][0] = (-cx * sz) + (sxsy * cz);
    arg0[2][0] = (sx * sz) + ((cx * sy) * cz);
    arg0[3][0] = arg4;
    arg0[0][1] = cy * sz;
    arg0[1][1] = (cx * cz) + (sxsy * sz);
    arg0[2][1] = (-sx * cz) + ((cx * sy) * sz);
    arg0[3][1] = arg5;
    arg0[0][2] = -sy;
    arg0[1][2] = sx * cy;
    arg0[2][2] = cx * cy;
    arg0[3][2] = arg6;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void func_801EE698(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE4D0((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);

    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE6F4(MtxF_t arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 sx = SIN(ANGLE_TO_CUSTOM_UNITS(arg1));
    f32 sy = SIN(ANGLE_TO_CUSTOM_UNITS(arg2));
    f32 sz = SIN(ANGLE_TO_CUSTOM_UNITS(arg3));
    f32 cx = COS(ANGLE_TO_CUSTOM_UNITS(arg1));
    f32 cy = COS(ANGLE_TO_CUSTOM_UNITS(arg2));
    f32 cz = COS(ANGLE_TO_CUSTOM_UNITS(arg3));
    f32 temp;

    temp = sx * sy;
    arg0[0][0] = (temp * sz) + (cy * cz);
    arg0[1][0] = (temp * cz) - (cy * sz);
    temp = sx * cy;
    arg0[2][0] = cx * sy;
    arg0[3][0] = arg4;
    arg0[0][1] = cx * sz;
    arg0[1][1] = cx * cz;
    arg0[2][1] = -sx;
    arg0[3][1] = arg5;
    arg0[0][2] = (temp * sz) - (sy * cz);
    arg0[1][2] = (temp * cz) + (sy * sz);
    arg0[2][2] = cx * cy;
    arg0[3][2] = arg6;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}

void func_801EE8C0(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    MtxF mtx;

    func_801EE6F4((float (*)[4]) & mtx, arg1, arg2, arg3, arg4, arg5, arg6);

    _MtxF_to_Mtx(&mtx, arg0);
}

void func_801EE91C(MtxF_t arg0, f32 x, f32 y, f32 z) {
    arg0[0][0] = x;
    arg0[1][1] = y;
    arg0[2][2] = z;

    arg0[1][0] = 0.0f;
    arg0[2][0] = 0.0f;
    arg0[0][1] = 0.0f;
    arg0[2][1] = 0.0f;
    arg0[0][2] = 0.0f;
    arg0[1][2] = 0.0f;
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][0] = 0.0f;
    arg0[3][1] = 0.0f;
    arg0[3][2] = 0.0f;
    arg0[3][3] = 1.0f;
}

void func_801EE97C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    MtxF mtx;

    func_801EE91C((float (*)[4]) & mtx, arg1, arg2, arg3);

    _MtxF_to_Mtx(&mtx, arg0);
}
