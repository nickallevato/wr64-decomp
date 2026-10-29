#include "global.h"

extern s32 D_i12_802C6460;
extern s32 D_i12_802C6464;
extern s32 D_i12_802C6468;
extern s32 D_i12_802C646C[];
extern s32 D_i12_802C6478[];
extern s32 D_i12_802C6480[];
extern s32 D_i12_802C648C[];
extern s32 D_800DAA10[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

s32 Save_EepromResetCourse(s32);
s32 Save_EepromResetStunt(s32);
void func_800C3E6C(s32);

Gfx* EraseCourseRecords_Draw(Gfx* dList) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x46) {
            return func_80093C44(dList);
        }
    }

    D_800DAB2C = 0;

    dList = EraseCourseRecords_DrawScreen(dList);

    if (gGameState == 0x46) {
        EraseCourseRecords_Input();
    } else if (D_80228A16 == 1) {
        GameState_EnterOptionsMenu();
    }

    return dList;
}

Gfx* EraseCourseRecords_DrawScreen(Gfx* gdl) {
    s32 i;
    s32 mode;

    gSPMatrix(gdl++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_106F550);
    gSPDisplayList(gdl++, D_106F628);

    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, i * 89 + 28, 58, 86, 16);
    }
    for (i = 0; i < 9; i++) {
        gdl = func_80094338(gdl, 0, (i / 5) * 133 + 28, (i % 5) * 18 + 85, 131, 16);
    }
    gdl = func_80094338(gdl, 0, 66, 181, 90, 16);
    gdl = func_80094338(gdl, 0, 164, 181, 90, 16);

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 2, 17, 32, 29, 0);
    gdl = TexLabel_Draw(gdl, 4, 12, 87, 206, 0);
    gdl = TexLabel_Draw(gdl, 4, 13, 169, 206, 0);

    for (i = 0; i < 3; i++) {
        if (i == D_i12_802C6460) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, D_i12_802C646C[i], D_i12_802C6480[i] + i * 89 + 52, 61, 0);
    }

    for (i = 0; i < 9; i++) {
        if (D_801CE640 == 0) {
            if (D_i12_802C6460 == 0) {
                if (i == 0) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else {
                mode = 0;
            }
        } else if (D_i12_802C6460 == 0) {
            if (i == 0) {
                mode = 7;
            } else if (i == D_i12_802C6464) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else if (i == D_i12_802C6464) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, D_800DAA10[D_800DAAD8[i]], D_i12_802C648C[D_800DAAD8[i]] + (i / 5) * 133 + 55,
                            (i % 5) * 18 + 88, 0);
    }

    for (i = 0; i < 2; i++) {
        if (D_801CE640 == 2) {
            if (i == D_i12_802C6468) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else {
            mode = 7;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, D_i12_802C6478[i], i * 97 + 82, 184, 0);
    }
    return gdl;
}

void EraseCourseRecords_Leave(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x47;
    D_801CE638 = 0x10;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(1, 4, 0);
}

void EraseCourseRecords_Input(void) {
    s32 sound = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (D_i12_802C6460 == 2) {
                    EraseCourseRecords_Leave(60);
                } else if (D_i12_802C6460 == 0) {
                    D_i12_802C6464 = 1;
                    D_801CE640 = 1;
                } else {
                    D_i12_802C6464 = 0;
                    D_801CE640 = 1;
                }
                break;

            case 1:
                D_801CE640 = 2;
                D_i12_802C6468 = 1;
                func_800C3E6C(3);
                break;

            case 2:
                sound = 1;
                D_801CE640 = 1;
                if (D_i12_802C6468 == 0) {
                    sound = 2;
                    if (D_i12_802C6460 == 0) {
                        Save_EepromResetCourse(D_800DAAD8[D_i12_802C6464]);
                    } else {
                        Save_EepromResetStunt(D_800DAAD8[D_i12_802C6464]);
                    }
                }
                break;
        }
        if (sound == 1) {
            AudioGeneral_PlaySound(0x11, 0);
        } else if (sound == 2) {
            AudioGeneral_PlaySound(0x37, 0);
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                EraseCourseRecords_Leave(60);
                break;

            case 1:
                sound = 1;
                D_801CE640 = 0;
                break;

            case 2:
                sound = 1;
                D_801CE640 = 1;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE65A[0].unk0 & U_JPAD) {
        if (D_801CE640 == 1) {
            sound = 1;
            D_i12_802C6464--;
            if (D_i12_802C6460 == 0) {
                if (D_i12_802C6464 <= 0) {
                    D_i12_802C6464 = 8;
                }
            } else if (D_i12_802C6464 < 0) {
                D_i12_802C6464 = 8;
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & D_JPAD) {
        if (D_801CE640 == 1) {
            sound = 1;
            D_i12_802C6464++;
            if (D_i12_802C6460 == 0) {
                if (D_i12_802C6464 >= 9) {
                    D_i12_802C6464 = 1;
                }
            } else if (D_i12_802C6464 >= 9) {
                D_i12_802C6464 = 0;
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (--D_i12_802C6460 < 0) {
                    D_i12_802C6460 = 2;
                }
                break;

            case 1:
                sound = 1;
                if ((D_i12_802C6460 != 0) || (D_i12_802C6464 != 5)) {
                    if (D_i12_802C6464 != 4) {
                        D_i12_802C6464 -= 5;
                        if (D_i12_802C6464 < 0) {
                            D_i12_802C6464 += 10;
                        }
                    }
                }
                break;

            case 2:
                sound = 1;
                if (--D_i12_802C6468 < 0) {
                    D_i12_802C6468 = 1;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (++D_i12_802C6460 == 3) {
                    D_i12_802C6460 = 0;
                }
                break;

            case 1:
                sound = 1;
                if ((D_i12_802C6460 != 0) || (D_i12_802C6464 != 5)) {
                    if (D_i12_802C6464 != 4) {
                        D_i12_802C6464 += 5;
                        if (D_i12_802C6464 >= 9) {
                            D_i12_802C6464 -= 10;
                        }
                    }
                }
                break;

            case 2:
                sound = 1;
                if (++D_i12_802C6468 >= 2) {
                    D_i12_802C6468 = 0;
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}
