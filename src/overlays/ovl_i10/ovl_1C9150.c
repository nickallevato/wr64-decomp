#include "global.h"

extern s32 D_801CB308[][3];
extern s32 D_800DA988[][3];
extern s32 D_802C6B38;
extern s32 D_i10_802C6AF8[][2];
extern s32 D_i10_802C6B10;

void func_i10_802C6A00(s32);

void func_i10_802C5800(void) {
    s32 i;

    if (D_801CE63C != 0) {
        if (gGameState == 0x44) {
            for (i = 0; i < 3 + 3; i++) {
                D_802C6B40[i] = 0;
            }

            D_802C6B40[3] = D_802C6B40[4] = 1;

            if (D_801CB280 & 1) {
                D_802C6B40[0] = 1;
            }
            if (D_801CB280 & 2) {
                D_802C6B40[1] = 1;
            }
            if (D_801CB280 & 4) {
                D_802C6B40[2] = 1;
            }

            for (i = 0; i < 3 + 2; i++) {
                if (D_802C6B40[i] != 0) {
                    break;
                }
            }

            if (i == 3) {
                D_802C6B30 = 1;
                D_802C6B34 = 1;
            } else {
                D_802C6B30 = i % 3;
                D_802C6B34 = i / 3;
            }

            D_i10_802C6B14 = 0;
            for (i = 0; i < 3; i++) {
                if (D_802C6B40[i] != 0) {
                    D_i10_802C6B14++;
                }
            }

            if (D_i10_802C6B14 == 0) {
                D_802C6B40[3] = 0;
            }
        }
    }
}

Gfx* func_i10_802C5968(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return func_80093C44(gfxP);
        }
    }

    D_800DAB2C = 0;

    gfxP = func_i10_802C6200(gfxP);

    if (gGameState == 68) {
        func_i10_802C5A10();
    } else if (D_80228A16 == 1) {
        func_8007C50C();
        GameState_EnterOptionsMenu();
    }

    return gfxP;
}

void func_i10_802C5A10(void) {
    s32* limits;
    s32* value;
    s32 sound = 0;
    s32 sel;
    s32 i;
    s32 j;
    s32 idx;

    if (D_801CE658[2].unk_00.unk_2 & (A_BUTTON | START_BUTTON | Z_TRIG)) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                sel = D_802C6B34 * 3 + D_802C6B30;
                if (sel == 4) {
                    func_i10_802C6A00(60);
                } else if (sel == 3) {
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            D_801CB308[i][j] = D_800DA988[i][j];
                        }
                    }
                } else {
                    D_801CE640 = 1;
                    D_802C6B38 = 0;
                }
                break;

            case 1:
                D_801CE640 = 2;
                sound = 1;
                D_802C6B38 = 1;
                break;

            case 2:
                D_801CE640 = 3;
                sound = 1;
                D_802C6B38 = 2;
                break;

            case 3:
                sound = 1;
                D_801CE640 = 0;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE658[2].unk_00.unk_2 & B_BUTTON) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                func_i10_802C6A00(60);
                break;

            case 1:
                D_801CE640 = 0;
                sound = 1;
                D_802C6B38 = 0;
                break;

            case 2:
                D_801CE640 = 1;
                sound = 1;
                D_802C6B38 = 0;
                break;

            case 3:
                D_801CE640 = 2;
                sound = 1;
                D_802C6B38 = 1;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & U_JPAD) {
        if (D_801CE640 == 0) {
            sound = 1;
            if ((D_802C6B34 == 1) && (D_i10_802C6B10 != -1)) {
                D_802C6B30 = D_i10_802C6B10;
            }
            if ((D_i10_802C6B14 == 1) && (D_802C6B34 == 1)) {
                D_802C6B30 = 0;
            } else if ((D_i10_802C6B14 == 3) && (D_802C6B34 == 0) && (D_802C6B30 == 2)) {
                D_802C6B30 = 1;
            }
            if (--D_802C6B34 < 0) {
                D_802C6B34 = 1;
            }
            for (;;) {
                idx = D_802C6B34 * 3 + D_802C6B30;
                if (D_802C6B40[idx] != 0) {
                    break;
                }
                if (--D_802C6B34 < 0) {
                    D_802C6B34 = 1;
                }
            }
            if (D_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_802C6B30;
                }
                if ((D_i10_802C6B14 == 3) && (D_802C6B30 == 2)) {
                    D_802C6B30 = 1;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & D_JPAD) {
        if (D_801CE640 == 0) {
            sound = 1;
            if ((D_802C6B34 == 1) && (D_i10_802C6B10 != -1)) {
                D_802C6B30 = D_i10_802C6B10;
                D_i10_802C6B10 = -1;
            }
            if ((D_i10_802C6B14 == 1) && (D_802C6B34 == 1)) {
                D_802C6B30 = 0;
            } else if ((D_i10_802C6B14 == 3) && (D_802C6B34 == 0) && (D_802C6B30 == 2)) {
                D_802C6B30 = 1;
            }
            if (++D_802C6B34 >= 2) {
                D_802C6B34 = 0;
            }
            for (;;) {
                idx = D_802C6B34 * 3 + D_802C6B30;
                if (D_802C6B40[idx] != 0) {
                    break;
                }
                if (++D_802C6B34 >= 2) {
                    D_802C6B34 = 0;
                }
            }
            if (D_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_802C6B30;
                }
                if ((D_i10_802C6B14 == 3) && (D_802C6B30 == 2)) {
                    D_802C6B30 = 1;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & L_JPAD) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                if (--D_802C6B30 < 0) {
                    if (D_802C6B34 == 0) {
                        D_802C6B30 = 2;
                    } else {
                        D_802C6B30 = 1;
                    }
                }
                for (;;) {
                    idx = D_802C6B34 * 3 + D_802C6B30;
                    if (D_802C6B40[idx] != 0) {
                        break;
                    }
                    if (--D_802C6B30 < 0) {
                        if (D_802C6B34 == 0) {
                            D_802C6B30 = 2;
                        } else {
                            D_802C6B30 = 1;
                        }
                    }
                }
                D_i10_802C6B10 = -1;
                break;

            case 1:
            case 2:
            case 3:
                idx = D_802C6B34 * 3 + D_802C6B30;
                limits = D_i10_802C6AF8[D_802C6B38];
                value = &D_801CB308[idx][D_802C6B38];
                sound = 1;
                if (--*value < limits[0]) {
                    *value = limits[1];
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & R_JPAD) {
        switch (D_801CE640) {
            case 0:
                sound = 1;
                D_802C6B30++;
                if (D_802C6B34 == 0) {
                    if (D_802C6B30 >= 3) {
                        D_802C6B30 = 0;
                    }
                } else if (D_802C6B30 >= 2) {
                    D_802C6B30 = 0;
                }
                for (;;) {
                    idx = D_802C6B34 * 3 + D_802C6B30;
                    if (D_802C6B40[idx] != 0) {
                        break;
                    }
                    D_802C6B30++;
                    if (D_802C6B34 == 0) {
                        if (D_802C6B30 >= 3) {
                            D_802C6B30 = 0;
                        }
                    } else if (D_802C6B30 >= 2) {
                        D_802C6B30 = 0;
                    }
                }
                D_i10_802C6B10 = -1;
                break;

            case 1:
            case 2:
            case 3:
                idx = D_802C6B34 * 3 + D_802C6B30;
                limits = D_i10_802C6AF8[D_802C6B38];
                value = &D_801CB308[idx][D_802C6B38];
                sound = 1;
                if (++*value > limits[1]) {
                    *value = limits[0];
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C6200.s")

void func_i10_802C6A00(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x45;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
    Popup_Spawn(0, 0);
}
