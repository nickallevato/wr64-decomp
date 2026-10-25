#include "global.h"

extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801CB334;

extern TexLabel D_i14_802C60F4[];
extern TexLabel D_i14_802C6114[];

void func_i14_802C5840(void);
Gfx* func_i14_802C5B70(Gfx*);
void func_i14_802C5F60(void);
s32 Save_EepromWriteCourse(s32);
s32 Save_EepromWriteRecord5(s32);
s32 Save_EepromWriteStunt(s32);
void GameState_EnterCourseOverview(void);

void func_i14_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 0x50)) {
        func_i14_802C5840();
    }
}

void func_i14_802C5840(void) {
    s32 flag = 0;

    D_802C61EC = 4;

    if (D_801CE608.gameMode == 4) {
        if (gPrevGameState == 0x43) {
            flag = 1;
        }
    } else if ((gPrevGameState != 100) && (gPrevGameState != 0x32) && (gPrevGameState != 0x39)) {
        flag = 1;
    }

    if (D_801CE608.gameMode == 4) {
        D_802C61EC = 2;
    }

    if (flag != 0) {
        D_802C61E0 = 1;
        D_802C61E4 = D_802C61E8 = 0x4C;
        return;
    }

    D_802C61E0 = 0;
    D_802C61E4 = 0x140;
    D_802C61E8 = -0xA9;

    AudioGeneral_PlaySound(0x31, 0);
}

Gfx* func_i14_802C5924(Gfx* dList) {
    s32 flag;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        // FAKE (maybe): flag first holds gPrevGameState (the original's register choice)
        if ((gGameState == 0x50) && ((flag = gPrevGameState) != 0x32) && (flag != 0x39) && (flag != 100)) {
            flag = 0;
            if (D_801CE608.gameMode == 4) {
                if (gPrevGameState == 0x43) {
                    flag = 1;
                }
            } else {
                flag = 1;
            }
            if (flag != 0) {
                osViBlack(0);
                return func_80093C44(dList);
            }
        }
    }

    D_800DAB2C = 0;
    dList = func_i14_802C5B70(Draw_WaterEffects(func_800949B8(func_8008FB74(dList), gCourseID)));

    if (gGameState == 0x50) {
        func_i14_802C5F60();
    } else if (D_80228A16 == 1) {
        if (D_801CE608.gameMode == 0) {
            if ((D_801C2650 != 0) || (D_801C2654 != 0)) {
                if (D_800DAB68 != 0) {
                    Save_EepromWriteRecord5(gCourseID);
                } else {
                    Save_EepromWriteCourse(gCourseID);
                }
            }
        } else if ((D_801CE608.gameMode == 11) && (D_801C2928 != 0)) {
            Save_EepromWriteStunt(gCourseID);
        }
        switch (D_801CE630) {
            case 30:
                D_801CE6F8 = 1;
                D_801CB334 = 0;
                if (gDifficulty == DIFFICULTY_NORMAL) {
                    D_801CB334 = 1;
                }
                GameState_EnterCourseOverview();
                break;

            case 40:
                func_8009345C();
                break;

            case 10:
                GameState_EnterRiderSelect();
                break;

            case 20:
                GameState_EnterCourseSelect();
                break;

            case 2:
                GameState_EnterTitleScreen();
                break;
        }
    }
    return dList;
}

Gfx* func_i14_802C5B70(Gfx* gdl) {
    s32 i;
    s32 x;
    TexLabel* item;

    gSPDisplayList(gdl++, D_106F628);

    for (i = 0; i < D_802C61EC; i++) {
        if (i & 1) {
            x = D_802C61E4;
        } else {
            x = D_802C61E8;
        }
        gdl = func_80094338(gdl, 0, x + 8, i * 18 + 97, 169, 16);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);

    if (D_801CE608.gameMode == 4) {
        item = D_i14_802C6114;
    } else {
        item = D_i14_802C60F4;
    }
    for (i = 0; i < D_802C61EC; i++, item++) {
        if (i != D_i14_802C60F0) {
            if (i & 1) {
                x = D_802C61E4;
                if (1) {} // FAKE: the original's s3/s4/s5 order for the three globals
            } else {
                x = D_802C61E8;
            }
            gdl = func_801E3EE0(gdl, 1, item->texture, x + 60 + item->x, i * 18 + 100, 0);
        }
    }

    i = D_i14_802C60F0;
    if (i & 1) {
        x = D_802C61E4;
    } else {
        x = D_802C61E8;
    }
    if (D_801CE608.gameMode == 4) {
        item = &D_i14_802C6114[i];
    } else {
        item = &D_i14_802C60F4[i];
    }
    gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    return func_801E3EE0(gdl, 1, item->texture, x + 60 + item->x, i * 18 + 100, 0);
}

void func_i14_802C5E5C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x51;
    D_801CE638 = 0xD;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(5, 1, 0);
    Popup_Spawn(0, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }
    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
        return;
    }
    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }
    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
    }
}

void func_i14_802C5F60(void) {
    if (D_802C61E0 == 0) {
        D_802C61E4 -= 0x14;
        if (D_802C61E4 < 0x4C) {
            D_802C61E0 = 1;
            D_802C61E4 = 0x4C;
        }
        D_802C61E8 = 0x98 - D_802C61E4;
        return;
    }

    if (D_i14_802C613C == 0) {
        D_i14_802C613C = 1;
        func_800C30F8();
    }

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_801CE608.gameMode == 4) {
            func_i14_802C5E5C(D_i14_802C6134[D_i14_802C60F0]);
        } else {
            func_i14_802C5E5C(D_i14_802C6124[D_i14_802C60F0]);
        }
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE65A[0].unk0 & U_JPAD) {
        if (--D_i14_802C60F0 < 0) {
            D_i14_802C60F0 = D_802C61EC - 1;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[0].unk0 & D_JPAD) {
        if (++D_i14_802C60F0 >= D_802C61EC) {
            D_i14_802C60F0 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }
}
