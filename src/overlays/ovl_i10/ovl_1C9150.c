#include "global.h"

extern s32 D_801CB308[][3];
extern s32 D_800DA988[][3];
extern s32 D_i10_802C6B38;
extern s32 D_i10_802C6AF8[][2];
extern s32 D_i10_802C6B10;

extern TexLabel D_i10_802C6AA0[];
extern s32 D_i10_802C6AC8[];
extern s32 D_i10_802C6AD4[];
extern s32 D_i10_802C6AE4[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

void ChangeConditions_Leave(s32);

void ChangeConditions_OverlayUpdate(void) {
    s32 i;

    if (D_801CE63C != 0) {
        if (gGameState == 0x44) {
            for (i = 0; i < 3 + 3; i++) {
                D_i10_802C6B40[i] = 0;
            }

            D_i10_802C6B40[3] = D_i10_802C6B40[4] = 1;

            if (D_801CB280 & 1) {
                D_i10_802C6B40[0] = 1;
            }
            if (D_801CB280 & 2) {
                D_i10_802C6B40[1] = 1;
            }
            if (D_801CB280 & 4) {
                D_i10_802C6B40[2] = 1;
            }

            for (i = 0; i < 3 + 2; i++) {
                if (D_i10_802C6B40[i] != 0) {
                    break;
                }
            }

            if (i == 3) {
                D_i10_802C6B30 = 1;
                D_i10_802C6B34 = 1;
            } else {
                D_i10_802C6B30 = i % 3;
                D_i10_802C6B34 = i / 3;
            }

            D_i10_802C6B14 = 0;
            for (i = 0; i < 3; i++) {
                if (D_i10_802C6B40[i] != 0) {
                    D_i10_802C6B14++;
                }
            }

            if (D_i10_802C6B14 == 0) {
                D_i10_802C6B40[3] = 0;
            }
        }
    }
}

Gfx* ChangeConditions_Draw(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return func_80093C44(gfxP);
        }
    }

    D_800DAB2C = 0;

    gfxP = func_i10_802C6200(gfxP);

    if (gGameState == 68) {
        ChangeConditions_Input();
    } else if (D_80228A16 == 1) {
        func_8007C50C();
        GameState_EnterOptionsMenu();
    }

    return gfxP;
}

void ChangeConditions_Input(void) {
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
                sel = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                if (sel == 4) {
                    ChangeConditions_Leave(60);
                } else if (sel == 3) {
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            D_801CB308[i][j] = D_800DA988[i][j];
                        }
                    }
                } else {
                    D_801CE640 = 1;
                    D_i10_802C6B38 = 0;
                }
                break;

            case 1:
                D_801CE640 = 2;
                sound = 1;
                D_i10_802C6B38 = 1;
                break;

            case 2:
                D_801CE640 = 3;
                sound = 1;
                D_i10_802C6B38 = 2;
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
                ChangeConditions_Leave(60);
                break;

            case 1:
                D_801CE640 = 0;
                sound = 1;
                D_i10_802C6B38 = 0;
                break;

            case 2:
                D_801CE640 = 1;
                sound = 1;
                D_i10_802C6B38 = 0;
                break;

            case 3:
                D_801CE640 = 2;
                sound = 1;
                D_i10_802C6B38 = 1;
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & U_JPAD) {
        if (D_801CE640 == 0) {
            sound = 1;
            if ((D_i10_802C6B34 == 1) && (D_i10_802C6B10 != -1)) {
                D_i10_802C6B30 = D_i10_802C6B10;
            }
            if ((D_i10_802C6B14 == 1) && (D_i10_802C6B34 == 1)) {
                D_i10_802C6B30 = 0;
            } else if ((D_i10_802C6B14 == 3) && (D_i10_802C6B34 == 0) && (D_i10_802C6B30 == 2)) {
                D_i10_802C6B30 = 1;
            }
            if (--D_i10_802C6B34 < 0) {
                D_i10_802C6B34 = 1;
            }
            for (;;) {
                idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                if (D_i10_802C6B40[idx] != 0) {
                    break;
                }
                if (--D_i10_802C6B34 < 0) {
                    D_i10_802C6B34 = 1;
                }
            }
            if (D_i10_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_i10_802C6B30;
                }
                if ((D_i10_802C6B14 == 3) && (D_i10_802C6B30 == 2)) {
                    D_i10_802C6B30 = 1;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE658[0].unk_00.unk_2 & D_JPAD) {
        if (D_801CE640 == 0) {
            sound = 1;
            if ((D_i10_802C6B34 == 1) && (D_i10_802C6B10 != -1)) {
                D_i10_802C6B30 = D_i10_802C6B10;
                D_i10_802C6B10 = -1;
            }
            if ((D_i10_802C6B14 == 1) && (D_i10_802C6B34 == 1)) {
                D_i10_802C6B30 = 0;
            } else if ((D_i10_802C6B14 == 3) && (D_i10_802C6B34 == 0) && (D_i10_802C6B30 == 2)) {
                D_i10_802C6B30 = 1;
            }
            if (++D_i10_802C6B34 >= 2) {
                D_i10_802C6B34 = 0;
            }
            for (;;) {
                idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                if (D_i10_802C6B40[idx] != 0) {
                    break;
                }
                if (++D_i10_802C6B34 >= 2) {
                    D_i10_802C6B34 = 0;
                }
            }
            if (D_i10_802C6B34 == 1) {
                if (D_i10_802C6B14 == 3) {
                    D_i10_802C6B10 = D_i10_802C6B30;
                }
                if ((D_i10_802C6B14 == 3) && (D_i10_802C6B30 == 2)) {
                    D_i10_802C6B30 = 1;
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
                if (--D_i10_802C6B30 < 0) {
                    if (D_i10_802C6B34 == 0) {
                        D_i10_802C6B30 = 2;
                    } else {
                        D_i10_802C6B30 = 1;
                    }
                }
                for (;;) {
                    idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                    if (D_i10_802C6B40[idx] != 0) {
                        break;
                    }
                    if (--D_i10_802C6B30 < 0) {
                        if (D_i10_802C6B34 == 0) {
                            D_i10_802C6B30 = 2;
                        } else {
                            D_i10_802C6B30 = 1;
                        }
                    }
                }
                D_i10_802C6B10 = -1;
                break;

            case 1:
            case 2:
            case 3:
                idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                limits = D_i10_802C6AF8[D_i10_802C6B38];
                value = &D_801CB308[idx][D_i10_802C6B38];
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
                D_i10_802C6B30++;
                if (D_i10_802C6B34 == 0) {
                    if (D_i10_802C6B30 >= 3) {
                        D_i10_802C6B30 = 0;
                    }
                } else if (D_i10_802C6B30 >= 2) {
                    D_i10_802C6B30 = 0;
                }
                for (;;) {
                    idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                    if (D_i10_802C6B40[idx] != 0) {
                        break;
                    }
                    D_i10_802C6B30++;
                    if (D_i10_802C6B34 == 0) {
                        if (D_i10_802C6B30 >= 3) {
                            D_i10_802C6B30 = 0;
                        }
                    } else if (D_i10_802C6B30 >= 2) {
                        D_i10_802C6B30 = 0;
                    }
                }
                D_i10_802C6B10 = -1;
                break;

            case 1:
            case 2:
            case 3:
                idx = D_i10_802C6B34 * 3 + D_i10_802C6B30;
                limits = D_i10_802C6AF8[D_i10_802C6B38];
                value = &D_801CB308[idx][D_i10_802C6B38];
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

// The `conds != &gDifficulty` test is the asm's (gDifficulty follows D_801CB308[4][3]); its source is unknown.
Gfx* func_i10_802C6200(Gfx* gdl) {
    s32 i;
    s32 mode;
    s32 useString;
    s32 changed;
    TexLabel* item;
    s32 texture;
    s32 pad; // stack pad
    s32 sel;
    s32* conds;
    s32 value;
    s32* cond;
    char buf[16];

    gSPMatrix(gdl++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_106F550);
    gSPDisplayList(gdl++, D_106F628);

    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, i * 89 + 28, 69, 86, 16);
    }
    gdl = func_80094338(gdl, 0, 164, 90, 86, 16);
    gdl = func_80094338(gdl, 0, 70, 90, 86, 16);
    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, 28, i * 20 + 125, 156, 16);
        gdl = func_80094338(gdl, 0, 187, i * 20 + 124, 105, 16);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 2, 16, 38, 39, 0);

    sel = D_i10_802C6B34 * 3 + D_i10_802C6B30;
    for (i = 0, item = D_i10_802C6AA0; i < 5; i++, item++) {
        if (i == sel) {
            mode = 6;
        } else if (D_i10_802C6B40[i] == 0) {
            mode = 7;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        if (i == 4) {
            gdl = TexLabel_Draw(gdl, 1, item->texture, 193, 93, 0);
        } else if (i == 3) {
            gdl = TexLabel_Draw(gdl, 1, item->texture, 80, 93, 0);
        } else {
            gdl = TexLabel_Draw(gdl, 1, item->texture, i * 97 + item->x + 44, 72, 0);
        }
    }

    if ((sel != 4) && (sel != 3)) {
        conds = D_801CB308[sel];
        cond = conds;
        for (i = 0; i < 3; i++, cond++) {
            if (D_801CE640 != 0) {
                if (i == D_i10_802C6B38) {
                    mode = 6;
                } else if (*cond == -1) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else if (*cond == -1) {
                mode = 7;
            } else {
                mode = 0;
            }
            gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
            gdl = TexLabel_Draw(gdl, 1, D_i10_802C6AC8[i], 41, i * 20 + 128, 0);
            gdl = Printer_DrawString(gdl, 2, ">", 167, i * 20 + 127);

            if (D_801CE640 != 0) {
                if (i == D_i10_802C6B38) {
                    if (*cond == D_800DA988[sel][i]) {
                        mode = 6;
                    } else {
                        mode = 4;
                    }
                } else if (*cond == -1) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else if (*cond == -1) {
                mode = 7;
            } else {
                mode = 0;
            }

            if (i == 0) {
                useString = false;
                if (*cond == -1) {
                    value = 0;
                } else {
                    value = *cond;
                }
                texture = D_i10_802C6AD4[value];
            } else if (i == 1) {
                useString = true;
                if (*cond == -1) {
                    value = 1;
                } else {
                    value = *cond;
                }
                sprintf(buf, "%d", value);
            } else if (i == 2) {
                useString = true;
                if (*cond == -1) {
                    value = 1;
                } else {
                    value = *cond;
                }
                sprintf(buf, "%d", value);
            } else {
                useString = false;
                if (*cond == -1) {
                    value = 0;
                } else {
                    value = *cond;
                }
                texture = D_i10_802C6AE4[value];
            }

            gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
            if (!useString) {
                gdl = TexLabel_Draw(gdl, 1, texture, 198, i * 20 + 127, 0);
            } else {
                gdl = Printer_DrawString(gdl, 2, buf, 198, i * 20 + 127);
            }
        }

        changed = false;
        if ((conds != (s32*) &gDifficulty) && (conds[0] != D_800DA988[sel][0])) {
            changed = true;
        }
        if (changed) {
            gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
            gdl = TexLabel_Draw(gdl, 1, 65, 28, 202, 0);
            gdl = TexLabel_Draw(gdl, 1, 68, 98, 202, 0);
        }
    }
    return gdl;
}

void ChangeConditions_Leave(s32 arg0) {
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
