#include "global.h"

extern s32 gVIsPerFrame;
extern s32 D_800DAB1C;
extern s32 D_801CE630;
extern s32 gPrevGameState;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;
extern s32 D_801CB334;
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern const s16 D_800EAC14[][8];
extern Mtx D_8011F820;
extern Gfx D_106F6C0[];
extern s32 gLetterWheelFirst;
extern s32 gLetterWheelLast;
extern s32 gLetterWheelSlots[];
// Defined here, not extern: IDO then addresses the four zero stores in func_801E1BA8 from one
// `lui at`, as the original does. Its address still comes from symbol_addrs.txt (the linker
// script's assignment wins over this .bss slot), because codeseg's .bss is not split yet.
s8 gInitialsEntered[4];
extern u16 D_802288EC;
extern s16 D_800DAB6C;
extern s32 D_801C2650;
extern s32 D_801C2654;
extern s8 D_801CE700[];
// 2 * pi. This copy sits just past the end of this file's split rodata (splat gives
// 0x80226330 to B17D0's data), so the code names it rather than writing the literal.
extern f32 D_80226330;
extern f32 D_80228828[];
extern f32 D_80228868[];
extern f32 D_802288A8[];
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 gStuntRecords[][3];

s32 Save_EepromWriteCourse(s32);
s32 Save_EepromWriteRecord5(s32);
void func_8006DE24(Gfx**);
Gfx* func_80094A44(Gfx*, s32);
void GameState_EnterViewRecords(void);
Gfx* Initials_DrawLetterWheel(Gfx*);
Gfx* Initials_DrawPanel(Gfx*);
void Initials_UpdateInput(void);
void func_801E2B8C(s32);
void Initials_SaveToRecords(void);
void GameState_EnterTimeTrialsResults(void);
f32 func_801E31A0(void);
void func_801E1BA8(void);
void func_80049A94(Mtx*, MtxF*, f32, f32, f32, f32, f32, f32);
void Water_StampPoint(f32, f32, s32);
void Water_StampPointTimed(f32, f32, s32, s32);

// Display lists for the 31 letter-wheel slots: A-Z, '-', '.', ' ', delete and end.
Gfx* gLetterWheelDLs[] = {
    (Gfx*) 0x0808EB68, (Gfx*) 0x08090BA0, (Gfx*) 0x080912B0, (Gfx*) 0x08091818,
    (Gfx*) 0x08091C40, (Gfx*) 0x080920D8, (Gfx*) 0x080924E0, (Gfx*) 0x0808EE78,
    (Gfx*) 0x0808F1B0, (Gfx*) 0x08092A90, (Gfx*) 0x0808F3B0, (Gfx*) 0x0808F6E8,
    (Gfx*) 0x0808F878, (Gfx*) 0x0808FBB0, (Gfx*) 0x08092D80, (Gfx*) 0x08093428,
    (Gfx*) 0x08093928, (Gfx*) 0x080940A0, (Gfx*) 0x08094608, (Gfx*) 0x08090030,
    (Gfx*) 0x08094CD0, (Gfx*) 0x0808FE58, (Gfx*) 0x08090248, (Gfx*) 0x080905C0,
    (Gfx*) 0x080951A8, (Gfx*) 0x080908F8, (Gfx*) 0x0808F2B0, (Gfx*) 0x08095640,
    (Gfx*) 0x08096248, (Gfx*) 0x08095858, (Gfx*) 0x080969E0,
};

s8* gInitialsLetters[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z", "-", ".", " ",
};

s8 gInitialsAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-. ";

s32 gInitialsLetterOffsets[] = {
    2, 5, 5, 4, 6, 5, 4, 3, 7, 6, 4, 6, 0, 3, 3,
    5, 3, 4, 5, 4, 3, 3, 0, 3, 3, 4, 5, 8, 0,
};

s32 gLetterWheelCursor = 0;
s32 gInitialsState = 0;
f32 D_802261CC = 0.0f;
f32 D_802261D0 = 0.0f;
f32 D_802261D4 = 0.0f;
f32 D_802261D8 = 1.0f;
s16 D_802261DC = 0;
s32 D_802261E0 = 0;
s32 gInitialsCount = 0;
s32 gInitialsPanelShown = 0;
Gfx* D_802261EC[] = { (Gfx*) 0x080973D0, (Gfx*) 0x08097428, (Gfx*) 0x08097448 };
s32 D_802261F8 = 0;

void Initials_Update(void) {
    static f32 D_802261FC = 50.0f;
    static f32 D_80226200 = -50.0f; // UNUSED: only its .data slot after D_802261FC is needed
    s32 i;
    s32 splash;
    s32 side;
    s32 active;
    s32 letter;
    f32 step;
    f32 dist;
    f32 angle;
    f32 frame;
    Mtx mtx;
    Mtx mtx2;
    MtxF wheelMtx;
    MtxF letterMtx;
    MtxF posMtx;
    MtxF mtx2F;
    MtxF finalMtx;

    active = 0;
    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_64)) {
        func_801E1BA8();
    }
    switch (gInitialsState) {
        case 0:
            D_802261CC = (D_802261E0 * 750.0f) / 30.0f;
            D_802261E0++;
            if (D_802261E0 >= 31) {
                D_802261E0 = 0;
                gInitialsState = 1;
                D_802261CC = 750.0f;
                gInitialsPanelShown = 1;
            }
            break;
        case 1:
            active = 1;
            break;
        case 2:
        case 8:
            active = 1;
            if (gInitialsState == 8) {
                step = 0.3f;
            } else {
                if (D_802261DC != 0) {
                    D_802261D8 = func_801E31A0();
                }
                step = 0.05f * D_802261D8;
            }
            D_802261D0 -= step;
            if (D_802261D0 < 0.0f) {
                if (D_802261D4 != 0.0f) {
                    D_802261D0 += 6.2831855f;
                }
            }
            if (D_802261D0 <= D_802261D4) {
                D_802261D0 = D_802261D4;
                if ((gInitialsState == 8) && (D_802288EC & 1)) {
                    gInitialsState = 10;
                } else {
                    gInitialsState = 1;
                }
            }
            break;
        case 3:
        case 9:
            active = 1;
            if (gInitialsState == 9) {
                step = 0.3f;
            } else {
                if (D_802261DC != 0) {
                    D_802261D8 = func_801E31A0();
                }
                step = 0.05f * D_802261D8;
            }
            D_802261D0 += step;
            if (D_802261D0 >= D_802261D4) {
                D_802261D0 = D_802261D4;
                if ((gInitialsState == 9) && (D_802288EC & 2)) {
                    gInitialsState = 10;
                } else {
                    gInitialsState = 1;
                }
            }
            if (D_802261D0 >= 6.2831855f) {
                D_802261D0 -= 6.2831855f;
            }
            break;
        case 4:
            active = 1;
            D_802261E0++;
            frame = D_802261E0;
            angle = (frame * (2.0 * 3.1415927f)) / 16;
            if (D_802261E0 >= 16) {
                letter = gLetterWheelSlots[gLetterWheelCursor];
                dist = 750.0f;
                if (letter == 30) {
                    if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
                        gInitialsState = 5;
                    } else {
                        gInitialsState = 7;
                        gInitialsPanelShown = 0;
                        D_802261E0 = 0;
                    }
                } else if (letter == 29) {
                    gInitialsState = 1;
                    if (gInitialsCount > 0) {
                        gInitialsCount--;
                    }
                    gInitialsEntered[gInitialsCount] = 0;
                } else {
                    gInitialsEntered[gInitialsCount] = *gInitialsLetters[letter];
                    gInitialsCount++;
                    if (gInitialsCount == 3) {
                        gInitialsState = 10;
                        if (gLetterWheelSlots[gLetterWheelCursor] >= 16) {
                            D_802288EC = 2;
                        } else {
                            D_802288EC = 1;
                        }
                    } else {
                        gInitialsState = 1;
                    }
                }
            } else if (D_802261E0 >= 8) {
                dist = (((D_802261E0 - 8) * 400.0f) / 8) + 350.0f;
            } else {
                dist = 750.0f - ((frame * 400.0f) / 8);
            }
            break;
        case 6:
            D_802261E0++;
            if (D_802261E0 >= 11) {
                gInitialsState = 7;
                gInitialsPanelShown = 0;
                D_802261E0 = 0;
            }
            break;
        case 7:
            D_802261CC = ((30 - D_802261E0) * 750.0f) / 30.0f;
            D_802261E0++;
            if (D_802261E0 >= 31) {
                D_802261E0 = 0;
                gInitialsState = 5;
                D_802261CC = 0;
            }
            break;
    }
    gLetterWheelFirst = gLetterWheelCursor - 3;
    if (gLetterWheelFirst < 0) {
        gLetterWheelFirst += 16;
    }
    gLetterWheelLast = gLetterWheelCursor + 3;
    if (gLetterWheelLast >= 16) {
        gLetterWheelLast -= 16;
    }
    for (i = 0; i < 16; i++) {
        func_80049A94(&mtx, &wheelMtx, 0.0f, -0.2f, D_802261D0 - ((i * 6.2831855f) / 16), 0.0f, -540.0f, 0.0f);
        splash = 0;
        if ((gInitialsState == 4) && (i == gLetterWheelCursor)) {
            func_80049A94(&mtx, &letterMtx, angle, 1.7707964f, -1.5707964f, 0.0f, dist, 0.0f);
        } else {
            func_80049A94(&mtx, &letterMtx, 0.0f, 1.7707964f, -1.5707964f, 0.0f, D_802261CC, 0.0f);
        }
        SysUtils_MatrixAffineMultiply(&wheelMtx, &letterMtx, &posMtx);
        func_80048A88(&mtx2, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.1f);
        SysUtils_MtxToMtxF(&mtx2, &mtx2F);
        SysUtils_MatrixAffineMultiply(&posMtx, &mtx2F, &finalMtx);
        SysUtils_MtxFToMtx(&finalMtx, &D_801CE5F8->unk1380[i]);
        if (D_801CE63C == 0) {
            if ((D_80228868[i] < 0.0f) && (posMtx.mf[3][1] >= 0.0f)) {
                splash = 1;
            } else if ((D_80228868[i] >= 0.0f) && (posMtx.mf[3][1] < 0.0f)) {
                splash = 2;
            }
            if (active == 0) {
                if (splash == 1) {
                    Water_StampPoint(posMtx.mf[3][0], posMtx.mf[3][2], D_802261FC);
                } else if (splash == 2) {
                    Water_StampPoint(posMtx.mf[3][0], posMtx.mf[3][2], 0.0f - D_802261FC);
                }
            } else if (i == gLetterWheelCursor) {
                if (posMtx.mf[3][1] < 0.0f) {
                    Water_StampPoint(posMtx.mf[3][0], posMtx.mf[3][2], -50);
                }
            } else {
                side = (posMtx.mf[3][0] >= 0.0f) ? 1 : 0;
                if (splash == 1) {
                    Water_StampPointTimed(D_80228828[i], D_802288A8[i], D_802261FC, side);
                } else if (splash == 2) {
                    Water_StampPointTimed(D_80228828[i], D_802288A8[i], 0.0f - D_802261FC, side);
                }
            }
        }
        D_80228828[i] = posMtx.mf[3][0];
        D_80228868[i] = posMtx.mf[3][1];
        D_802288A8[i] = posMtx.mf[3][2];
    }
}

void func_801E1BA8(void) {
    s32 i;
    s32 j;
    s32 first;
    s32 course;

    gLetterWheelCursor = 0;
    gInitialsState = 0;
    D_802261CC = 0.0f;
    D_802261D0 = 0.0f;
    D_802261D4 = 0.0f;
    D_802261E0 = 0;
    gInitialsCount = 0;
    gInitialsPanelShown = 0;
    D_802288EC = 0;
    for (i = 0; i < 16; i++) {
        if (i < 8) {
            gLetterWheelSlots[i] = i;
        } else {
            gLetterWheelSlots[i] = i + 15;
        }
    }
    if (D_800DAB6C != 0) {
        D_800DAB6C = 0;
        i = 0;
        do {
            gInitialsEntered[i] = 0;
            i++;
        } while (i < 4);
    } else {
        for (i = 0; i < 4; i++) {
            gInitialsEntered[i] = D_801CE700[i];
        }
        for (i = 0; i < 3; i++) {
            if (gInitialsEntered[i] == 0) {
                break;
            }
        }
        gInitialsCount = i;
        j = (gLetterWheelCursor + 8) % 16;
        gLetterWheelSlots[j] = gLetterWheelSlots[(j + 1) % 16] - 1;
        if (gLetterWheelSlots[j] < 0) {
            gLetterWheelSlots[j] += 31;
        }
        gLetterWheelCursor--;
        if (gLetterWheelCursor < 0) {
            gLetterWheelCursor = 15;
        }
        D_802261D4 = (gLetterWheelCursor * 6.2831855f) / 16;
        D_802261D0 = D_802261D4;
    }
    D_802261F8 = 0;
    switch (D_801CE608.gameMode) {
        case GMODE_CHAMPIONSHIP:
            if (gDifficulty == DIFFICULTY_NORMAL) {
                first = 1;
            } else {
                first = 0;
            }
            for (i = first; i < D_801CB334 + 1; i++) {
                course = D_800EAC14[gDifficulty][i];
                if ((D_801C2660[course] == 1) || (D_801C2690[course] != 0)) {
                    D_802261F8 = 1;
                }
            }
            break;
        case GMODE_TIME_TRIALS:
            if ((D_801C2650 == 1) || (D_801C2654 != 0)) {
                D_802261F8 = 1;
            }
            break;
        case GMODE_STUNT:
            if (D_801C2928 == 1) {
                D_802261F8 = 1;
            }
            break;
    }
}

Gfx* Initials_Draw(Gfx* gdl) {
    s32 i;
    s16 course;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    gdl = Initials_DrawLetterWheel(func_8008FB74(func_80093F78(gdl)));
    gSPMatrix(gdl++, &D_8011F820, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gdl = Initials_DrawPanel(Draw_WaterEffects(func_80094A44(gdl, gCourseID)));
    if (gGameState == GAME_STATE_64) {
        Initials_UpdateInput();
    } else if (D_80228A16 == 1) {
        if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
            for (i = 0; i < D_801CB334 + 1; i++) {
                course = D_800EAC14[gDifficulty][i];
                if ((D_801C2660[course] != 0) || (D_801C2690[course] != 0)) {
                    if (D_800DAB68 != 0) {
                        Save_EepromWriteRecord5(course);
                    } else {
                        Save_EepromWriteCourse(course);
                    }
                }
            }
        }
        GameState_EnterViewRecords();
    }
    return gdl;
}

Gfx* Initials_DrawLetterWheel(Gfx* gdl) {
    s32 i;
    s32 wrap;
    s32 draw;

    gdl = func_800949B8(gdl, gCourseID);
    gSPDisplayList(gdl++, D_106F6C0);
    if (D_802261F8 != 0) {
        func_8006DE24(&gdl);
    }
    if (gLetterWheelFirst < gLetterWheelLast) {
        wrap = 0;
    } else {
        wrap = 1;
    }
    for (i = 0; i < 16; i += 2) {
        draw = 0;
        if (wrap == 0) {
            if ((i >= gLetterWheelFirst) && (i <= gLetterWheelLast)) {
                draw = 1;
            }
        } else if ((i >= gLetterWheelFirst) || (i <= gLetterWheelLast)) {
            draw = 1;
            if (1) {} // FAKE
            if (1) {} // FAKE
            if (1) {} // FAKE
            if (1) {} // FAKE
        }
        if (draw != 0) {
            gSPMatrix(gdl++, &D_801CE5F8->unk1380[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(gdl++, gLetterWheelDLs[gLetterWheelSlots[i]]);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
        draw = 0;
        if (wrap == 0) {
            if ((i >= gLetterWheelFirst - 1) && (i < gLetterWheelLast)) {
                draw = 1;
            }
        } else if ((i >= gLetterWheelFirst - 1) || (i < gLetterWheelLast)) {
            draw = 1;
        }
        if (draw) {
            gSPMatrix(gdl++, &D_801CE5F8->unk1380[i + 1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(gdl++, gLetterWheelDLs[gLetterWheelSlots[i + 1]]);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
    }
    return gdl;
}

Gfx* Initials_DrawPanel(Gfx* gdl) {
    s32 mode;
    s32 i;
    s32 j;
    s32 offset;
    s8 str[2];

    if (gInitialsPanelShown == 0) {
        return gdl;
    }
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 0x36, 0x20, 0xD3, 0x18);
    gdl = func_80094338(gdl, 0, 0x65, 0xB1, 0x75, 0x1C);
    for (i = 0; i < 3; i++) {
        mode = (i == gInitialsCount) ? 6 : 0;
        gdl = Printer_SetMode(gdl, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPDisplayList(gdl++, D_802261EC[i]);
    }
    gdl = Printer_SetMode(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gdl = func_801E3EE0(gdl, 2, 0x1D, 0x48, 0x23, 0);
    for (i = 0; i < 3; i++) {
        str[1] = 0;
        str[0] = gInitialsEntered[i];
        for (j = 0; j < 29; j++) {
            if (str[0] == gInitialsAlphabet[j]) {
                break;
            }
        }
        if (j == 29) {
            offset = 0;
        } else {
            offset = gInitialsLetterOffsets[j];
        }
        gdl = Printer_DrawString(gdl, 0, (char*) str, i * 26 + offset + 0x7A, 0xB4);
    }
    return gdl;
}

void Initials_UpdateInput(void) {
    s32 j;
    s32 k;
    s32 action;
    s32 letter;
    ControllerBase* cont;
    s32 buttons;
    s8 stickX;

    switch (gInitialsState) {
        case 5:
            Initials_SaveToRecords();
            sprintf(D_801CE700, "%s", gInitialsEntered);
            if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
                func_801E2B8C(0x42);
            } else if (D_801CE608.gameMode == GMODE_TIME_TRIALS) {
                GameState_EnterTimeTrialsResults();
            } else if (D_801CE608.gameMode == GMODE_STUNT) {
                func_801ED004();
            }
            break;
        case 0:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 10:
            if (D_802288EC & 1) {
                gInitialsState = 8;
                j = (gLetterWheelCursor + 8) % 16;
                gLetterWheelSlots[j] = gLetterWheelSlots[(j + 1) % 16] - 1;
                if (gLetterWheelSlots[j] < 0) {
                    gLetterWheelSlots[j] += 31;
                }
                gLetterWheelCursor--;
                if (gLetterWheelCursor < 0) {
                    gLetterWheelCursor = 15;
                }
                if (gLetterWheelSlots[gLetterWheelCursor] == 30) {
                    D_802288EC = 0;
                }
                D_802261D4 = (gLetterWheelCursor * 6.2831855f) / 16;
                AudioGeneral_PlaySound(0x2E, 0);
            } else if (D_802288EC & 2) {
                gInitialsState = 9;
                j = (gLetterWheelCursor + 8) % 16;
                k = j - 1;
                if (k < 0) {
                    k += 16;
                }
                gLetterWheelSlots[j] = gLetterWheelSlots[k] + 1;
                if (gLetterWheelSlots[j] >= 31) {
                    gLetterWheelSlots[j] -= 31;
                }
                gLetterWheelCursor++;
                D_802261D4 = (gLetterWheelCursor * 6.2831855f) / 16;
                if (gLetterWheelCursor >= 16) {
                    gLetterWheelCursor = 0;
                }
                if (gLetterWheelSlots[gLetterWheelCursor] == 30) {
                    D_802288EC = 0;
                }
                AudioGeneral_PlaySound(0x2F, 0);
            }
            break;
        default:
            if (D_801CE65A[0].unk0 & (CONT_A | CONT_G | CONT_START)) {
                if (gInitialsState == 1) {
                    action = 0;
                    letter = gLetterWheelSlots[gLetterWheelCursor];
                    if (gInitialsCount < 3) {
                        action = 1;
                        if (letter == 30) {
                            action = 2;
                        }
                    } else if (letter == 30) {
                        action = 2;
                    } else if (letter == 29) {
                        action = 1;
                    }
                    if (action != 0) {
                        gInitialsState = 4;
                        D_802261E0 = 0;
                        if (action == 1) {
                            AudioGeneral_PlaySound(0x1A, 0);
                        } else if (action == 2) {
                            AudioGeneral_PlaySound(0x30, 0);
                        } else if (action == 3) {
                            AudioGeneral_PlaySound(0x12, 0);
                        }
                    }
                }
            } else if (D_801CE65A[0].unk0 & CONT_B) {
                if (gInitialsState == 1) {
                    if (gInitialsCount > 0) {
                        gInitialsCount--;
                    }
                    gInitialsEntered[gInitialsCount] = 0;
                    AudioGeneral_PlaySound(0x12, 0);
                }
            } else {
                cont = &gControllerOne[D_80154330[0]];
                buttons = cont->unk_0;
                if ((buttons & CONT_LEFT) || ((stickX = cont->unk_8) < -12)) {
                    if (gInitialsState == 1) {
                        if (buttons & CONT_LEFT) {
                            D_802261D8 = 1.0f;
                            D_802261DC = 0;
                        } else {
                            D_802261D8 = func_801E31A0();
                            D_802261DC = 1;
                        }
                        gInitialsState = 2;
                        j = (gLetterWheelCursor + 8) % 16;
                        gLetterWheelSlots[j] = gLetterWheelSlots[(j + 1) % 16] - 1;
                        if (gLetterWheelSlots[j] < 0) {
                            gLetterWheelSlots[j] += 31;
                        }
                        gLetterWheelCursor--;
                        if (gLetterWheelCursor < 0) {
                            gLetterWheelCursor = 15;
                        }
                        D_802261D4 = (gLetterWheelCursor * 6.2831855f) / 16;
                        AudioGeneral_PlaySound(0x2E, 0);
                    }
                } else if ((buttons & CONT_RIGHT) || (stickX >= 13)) {
                    if (gInitialsState == 1) {
                        if (buttons & CONT_RIGHT) {
                            D_802261D8 = 1.0f;
                            D_802261DC = 0;
                        } else {
                            D_802261D8 = func_801E31A0();
                            D_802261DC = 1;
                        }
                        gInitialsState = 3;
                        j = (gLetterWheelCursor + 8) % 16;
                        k = j - 1;
                        if (k < 0) {
                            k += 16;
                        }
                        gLetterWheelSlots[j] = gLetterWheelSlots[k] + 1;
                        if (gLetterWheelSlots[j] >= 31) {
                            gLetterWheelSlots[j] -= 31;
                        }
                        gLetterWheelCursor++;
                        D_802261D4 = (gLetterWheelCursor * D_80226330) / 16;
                        if (gLetterWheelCursor >= 16) {
                            gLetterWheelCursor = 0;
                        }
                        AudioGeneral_PlaySound(0x2F, 0);
                    }
                }
            }
            break;
    }
}

void func_801E2B8C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = GAME_STATE_65;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(1, 0xE, 0x14);
}

void Initials_SaveToRecords(void) {
    s32 i;
    s32 j;
    s32 course;

    if (gInitialsEntered[0] == 0) {
        for (i = 0; i < 3; i++) {
            gInitialsEntered[i] = gPlayerNames[D_800DA9B0[0]].unk_0[i];
        }
        gInitialsEntered[i] = 0;
        D_800DAB6C = 1;
    }
    if (D_801CE608.gameMode == GMODE_CHAMPIONSHIP) {
        for (j = 0; j < D_801CB334 + 1; j++) {
            course = D_800EAC14[gDifficulty][j];
            if (D_801C2660[course] != 0) {
                for (i = 0; i < 4; i++) {
                    if (D_800DAB68 != 0) {
                        D_801C23B0[course].unk10[i] = gInitialsEntered[i];
                    } else {
                        gBestTimes[course][D_801C2660[course] - 1].unk10[i] = gInitialsEntered[i];
                    }
                }
                if (D_800DAB68 != 0) {
                    D_801C23B0[course].unk10[i] = 0;
                } else {
                    gBestTimes[course][D_801C2660[course] - 1].unk10[i] = 0;
                }
            }
            if (D_801C2690[course] != 0) {
                for (i = 0; i < 4; i++) {
                    gBestLaps[course].unk10[i] = gInitialsEntered[i];
                }
                gBestLaps[course].unk10[i] = 0;
            }
        }
    } else if (D_801CE608.gameMode == GMODE_STUNT) {
        if (D_801C2928 != 0) {
            for (i = 0; i < 4; i++) {
                gStuntRecords[gCourseID][D_801C2928 - 1].unkC[i] = gInitialsEntered[i];
            }
            gStuntRecords[gCourseID][D_801C2928 - 1].unkC[i] = 0;
        }
    } else {
        if (D_801C2660[gCourseID] != 0) {
            for (i = 0; i < 4; i++) {
                if (D_800DAB68 != 0) {
                    D_801C23B0[gCourseID].unk10[i] = gInitialsEntered[i];
                } else {
                    gBestTimes[gCourseID][D_801C2660[gCourseID] - 1].unk10[i] = gInitialsEntered[i];
                }
            }
            if (D_800DAB68 != 0) {
                D_801C23B0[gCourseID].unk10[i] = 0;
            } else {
                gBestTimes[gCourseID][D_801C2660[gCourseID] - 1].unk10[i] = 0;
            }
        }
        if (D_801C2690[gCourseID] != 0) {
            for (i = 0; i < 4; i++) {
                gBestLaps[gCourseID].unk10[i] = gInitialsEntered[i];
            }
            gBestLaps[gCourseID].unk10[i] = 0;
        }
    }
}
