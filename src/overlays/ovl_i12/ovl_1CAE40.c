#include "global.h"

extern s32 D_i12_802C6460;
extern s32 D_i12_802C6464;
extern s32 D_i12_802C6468;

s32 Save_EepromResetCourse(s32);
s32 Save_EepromResetStunt(s32);
void func_800C3E6C(s32);

Gfx* func_i12_802C5800(Gfx* dList) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x46) {
            return func_80093C44(dList);
        }
    }

    D_800DAB2C = 0;

    dList = func_i12_802C58A0(dList);

    if (gGameState == 0x46) {
        func_i12_802C5F6C();
    } else if (D_80228A16 == 1) {
        GameState_EnterOptionsMenu();
    }

    return dList;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i12/ovl_1CAE40/func_i12_802C58A0.s")

void func_i12_802C5EE4(s32 arg0) {
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

void func_i12_802C5F6C(void) {
    s32 sound = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (D_i12_802C6460 == 2) {
                    func_i12_802C5EE4(60);
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
                func_i12_802C5EE4(60);
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
