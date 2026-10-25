#include "global.h"

void GameState_EnterChangeNames(void);
void GameState_EnterViewRecords(void);
void GameState_EnterChangeConditions(void);
void GameState_EnterAudio(void);
void GameState_EnterEraseCourseRecords(void);
void GameState_EnterSaveAndLoad(void);
Gfx* func_i7_802C5A18(Gfx*);
void func_i7_802C5C94(s32);
extern s32 gCurrentOptionsMenuItem;
extern s32 D_i7_802C5D20[];

Gfx* func_i7_802C5800(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x3C) {
            if (gPrevGameState == 4) {
                gCurrentOptionsMenuItem = 0;
            }
            return func_80093C44(arg0);
        }
    }
    D_800DAB2C = 0;
    arg0 = func_i7_802C5A18(arg0);
    if (gGameState == 0x3C) {
        if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
            func_i7_802C5C94(D_i7_802C5D20[gCurrentOptionsMenuItem]);
            AudioGeneral_PlaySound(0x11, 0);
        } else if (D_801CE65A->unk0 & CONT_B) {
            func_i7_802C5C94(2);
            AudioGeneral_PlaySound(0x16, 0);
        } else if (D_801CE65A->unk0 & CONT_UP) {
            if ((--gCurrentOptionsMenuItem) < 0) {
                gCurrentOptionsMenuItem = 6;
            }
            AudioGeneral_PlaySound(0x10, 0);
        } else if (D_801CE65A->unk0 & CONT_DOWN) {
            if ((++gCurrentOptionsMenuItem) == 7) {
                gCurrentOptionsMenuItem = 0;
            }
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x3E:
                GameState_EnterChangeNames();
                break;
            case 0x42:
                GameState_EnterViewRecords();
                break;
            case 0x44:
                GameState_EnterChangeConditions();
                break;
            case 0x46:
                GameState_EnterEraseCourseRecords();
                break;
            case 0x40:
                GameState_EnterSaveAndLoad();
                break;
            case 0x48:
                GameState_EnterAudio();
                break;
            default:
                GameState_EnterTitleScreen();
                break;
        }
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i7/ovl_1C43F0/func_i7_802C5A18.s")

void func_i7_802C5C94(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x3D;
    D_801CE638 = 7;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(1, 4, 0);
}
