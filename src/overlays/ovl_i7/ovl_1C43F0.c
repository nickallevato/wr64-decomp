#include "global.h"

void GameState_EnterChangeNames(void);
void GameState_EnterViewRecords(void);
void GameState_EnterChangeConditions(void);
void GameState_EnterAudio(void);
void GameState_EnterEraseCourseRecords(void);
void GameState_EnterSaveAndLoad(void);
Gfx* OptionsMenu_DrawItems(Gfx*);
void OptionsMenu_Leave(s32);
extern s32 gCurrentOptionsMenuItem;
extern s32 D_i7_802C5D20[];

extern TexLabel D_i7_802C5D3C[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

Gfx* OptionsMenu_Draw(Gfx* arg0) {
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
    arg0 = OptionsMenu_DrawItems(arg0);
    if (gGameState == 0x3C) {
        if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
            OptionsMenu_Leave(D_i7_802C5D20[gCurrentOptionsMenuItem]);
            AudioGeneral_PlaySound(0x11, 0);
        } else if (D_801CE65A->unk0 & CONT_B) {
            OptionsMenu_Leave(2);
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

Gfx* OptionsMenu_DrawItems(Gfx* gdl) {
    s32 i;
    TexLabel* item;

    gSPMatrix(gdl++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_106F550);
    gSPDisplayList(gdl++, D_106F628);

    for (i = 0; i < 7; i++) {
        gdl = func_80094338(gdl, 0, 58, i * 19 + 73, 204, 16);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 2, 5, 107, 34, 0);

    for (i = 0, item = D_i7_802C5D3C; i < 7; i++, item++) {
        if (i != gCurrentOptionsMenuItem) {
            if (1) {} // FAKE: gives the original's i * 19 (shifts, not a multu by a hoisted 19)
            gdl = TexLabel_Draw(gdl, 1, item->texture, item->x + 109, i * 19 + 76, 0);
        }
    }

    gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    item = &D_i7_802C5D3C[gCurrentOptionsMenuItem];
    return TexLabel_Draw(gdl, 1, item->texture, item->x + 109, gCurrentOptionsMenuItem * 19 + 76, 0);
}

void OptionsMenu_Leave(s32 arg0) {
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
