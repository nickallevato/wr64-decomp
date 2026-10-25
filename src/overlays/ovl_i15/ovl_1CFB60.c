#include "global.h"

extern s32 D_800DAA08;
extern const s16 D_800EABB0[];
extern RiderStruct gRiderRaceState[];
extern s32 D_801CB350[][4];
extern s32 D_i15_802C6D54[];
extern s32 D_i15_802C6D68;
extern s32 D_i15_802C6D6C;
extern s32 D_i15_802C6D70[];
extern UnkStruct_D_802C6E80 D_i15_802C6D8C;
extern s32 D_i15_802C6E7C;
extern s32 D_i15_802C6F20[];
extern s32 D_i15_802C6F44;
extern const s16 D_800EAC14[][8];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern s32 D_801CB334;
extern u16 D_i15_802C6F40;
extern s32 D_i15_802C6DD4;
extern s32 D_i15_802C6DD8;
extern s32 D_i15_802C6DDC;
extern Vp D_i15_802C6DE0;
extern s32 D_i15_802C6DF0;
extern s32 D_801CB340[];
extern s32 D_801CB3D0[];
extern s32 D_800DA9DC[];
extern s32 D_800DAA10[];
extern s32 D_i15_802C6D9C[];
extern s32 D_i15_802C6DC0[];
extern s32 D_i15_802C6DD0;
extern s32 D_i15_802C6DFC[];
extern u8 gPrinterWidthsFont0[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];

Gfx* func_80093AFC(Gfx*);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);

Gfx* func_80091DBC(Gfx*);
Gfx* func_80093DBC(Gfx*, u16, u16, u16);
Gfx* func_i15_802C602C(Gfx*);
void func_i15_802C6C1C(void);
void func_i15_802C5CE8(void);
void func_i15_802C5EE4(s32);
void func_800C489C(s32);

#ifdef NON_MATCHING
// Score 505 of 31400, register allocation only: the saved registers of &spFC, &D_i15_802C6DE0 and the loop bound
// 0x80 are permuted (s7/s5/s6 for the original's s5/s6/s7), and the original passes func_800C489C its 10 in the a0
// it already holds for the `unk4 == 10` tests.
void func_i15_802C5800(void) {
    s32 i;
    s32 j;
    s32 course;
    s32 draw;
    f32 temp_fv1; // FAKE (as in func_i5_802C5850): temp needed for match
    f32 temp_fa0; // FAKE (as in func_i5_802C5850): temp needed for match
    UnkStruct_D_802C6E80* thing;
    MtxF sp17C;
    MtxF sp13C;
    MtxF spFC;
    Mtx spB8;
    Mtx sp78;

    if ((D_801CE63C != 0) && (gGameState == 0x66)) {
        func_i15_802C5CE8();
        D_i15_802C6E74 = D_i15_802C6E78 = 0;
        for (i = 0; i < D_801CB334 + 1; i++) {
            course = D_800EAC14[gDifficulty][i];
            if (D_801C2660[course] != 0) {
                D_i15_802C6E74 = 1;
            }
            if (D_801C2690[course] != 0) {
                D_i15_802C6E78 = 1;
            }
        }
    }

    i = 0;
    if ((--D_i15_802C6D6C < 0) && (D_i15_802C6D68 != -1)) {
        func_i15_802C5EE4(D_i15_802C6D68);
        D_i15_802C6D6C = 40;
        if (D_i15_802C6D68 == D_i15_802C6E7C) {
            D_i15_802C6D68 = 10;
            D_i15_802C6D6C = 110;
        } else if (D_i15_802C6D68 == 10) {
            D_i15_802C6D68 = -1;
        } else {
            D_i15_802C6D68++;
        }
    }

    func_800481E0(D_801CE5F8->unkA40, &D_i15_802C6F40, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB8, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f);
    temp_fv1 = COS(0) * 500.0f;
    temp_fa0 = SIN(0) * 500.0f;
    // FAKE: arg3 is an int 0 literal to match (li a3, 0), as in func_i5_802C5850
    func_800484C8(&sp78, &sp13C, temp_fv1, 0, temp_fa0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB8, &sp17C);
    SysUtils_MatrixAffineMultiply(&sp13C, &sp17C, &spFC);

    thing = D_i15_802C6E80;
    do {
        if (thing->unk0 != 0) {
            draw = 0;
            switch (thing->unk0) {
                case 1:
                    thing->unkC = thing->unkC - 2; // not -=: the permuter's form, a better score
                    if (thing->unk4 == 10) {
                        if (thing->unkC < 26) {
                            thing->unk0 = 2;
                            thing->unkC = 25;
                        }
                    } else if (thing->unkC < -12) {
                        thing->unk0 = 0;
                    }
                    if (thing->unk4 == 10) {
                        draw = 1;
                    }
                    break;

                case 2:
                    draw = 1;
                    if (D_i15_802C6DF0 < 20) {
                        D_i15_802C6DF0++;
                    }
                    if (D_i15_802C6DF0 >= 11) {
                        // FAKE: 20U keeps IDO from loading 20 into a register for the compare and both divisions
                        if (++D_i15_802C6DDC == 20U) {
                            thing->unk0 = 3;
                            D_i15_802C6DD4 = 255;
                            D_i15_802C6DD8 = 170;
                            D_i15_802C6DF4 = 1;
                            func_800C489C(10);
                        } else {
                            D_i15_802C6DD8 = D_i15_802C6DDC * 170 / 20;
                            D_i15_802C6DD4 = D_i15_802C6DDC * 255 / 20;
                        }
                    }
                    break;

                case 3:
                    draw = 1;
                    break;
            }
            if (draw) {
                for (j = 0; j < 4; j++) {
                    SysUtils_MtxFToMtx(&spFC, &D_801CE5F8->unkA80[j]);
                    D_801CE5F8->unk1280[j] = D_i15_802C6DE0;
                    D_801CE5F8->unk1280[j].vp.vtrans[0] = (thing->unk8 + 58) << 2;
                    D_801CE5F8->unk1280[j].vp.vtrans[1] = (thing->unkC + j * 32 + 65) << 2;
                }
                if (1) {} // FAKE (permuter)
            }
        }
        thing++;
    } while (++i != 10);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C5800.s")
#endif

void func_i15_802C5CE8(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        D_i15_802C6E80[i] = D_i15_802C6D8C;
    }
    D_i15_802C6E7C = D_i15_802C6D54[gDifficulty];
    if (gRiderRaceState[gPlayer1Rider].unk338 == 3) {
        D_i15_802C6F44 = 6;
    } else if (gDifficulty == DIFFICULTY_EXPERT) {
        if (gRiderRaceState[gPlayer1Rider].unk338 == 0) {
            D_i15_802C6F44 = 3;
        } else if (gRiderRaceState[gPlayer1Rider].unk338 == 1) {
            D_i15_802C6F44 = 4;
        } else {
            D_i15_802C6F44 = 5;
        }
    } else {
        if (gRiderRaceState[gPlayer1Rider].unk338 == 0) {
            D_i15_802C6F44 = 0;
        } else if (gRiderRaceState[gPlayer1Rider].unk338 == 1) {
            D_i15_802C6F44 = 1;
        } else {
            D_i15_802C6F44 = 2;
        }
    }
    D_i15_802C6D6C = D_i15_802C6D70[D_i15_802C6F44];
    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_i15_802C6D68 = 1;
    } else {
        D_i15_802C6D68 = 0;
    }
    for (i = 0; i < D_i15_802C6E7C + 1; i++) {
        for (j = 0; j < 4; j++) {
            if (D_800EABB0[j] == D_801CB350[i][0]) {
                break;
            }
        }
        D_i15_802C6F20[i] = j;
    }
    D_800DAA08 = 1;
}

void func_i15_802C5EE4(s32 arg0) {
    UnkStruct_D_802C6E80* thing;
    s32 i;

    for (i = 0, thing = &D_i15_802C6E80[0]; i < 10; i++, thing++) {
        if (thing->unk0 == 0) {
            break;
        }
    }

    thing = &D_i15_802C6E80[i];

    if (i != 10) {
        thing->unk0 = 1;
        thing->unk4 = arg0;
        thing->unkC = 235;
        if (arg0 != 10) {
            thing->unk8 = 32;
        } else {
            thing->unk8 = 28;
        }
    }
}

Gfx* func_i15_802C5F50(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x66) {
            return func_80093DBC(gdl, 255, 255, 255);
        }
    }

    D_800DAB2C = 0;
    gdl = func_80091DBC(gdl);
    gdl = func_8009328C(gdl);
    gdl = func_i15_802C602C(gdl);

    if (gGameState == 0x66) {
        func_i15_802C6C1C();
    } else if (D_80228A16 == 1) {
        if (D_801CE630 == 2) {
            GameState_EnterTitleScreen();
        } else {
            func_801EC9C8();
        }
    }
    return gdl;
}

#ifdef NON_MATCHING
// Score 1717 of 76400: the instructions match except the scheduling of the standings' first assignments (rank,
// tieRank, count and the loop index before the first panel); the two address constants it keeps on the stack
// (D_7000A40, D_106F488) sit at sp+0x7C/0x80 instead of sp+0x80/0x84.
Gfx* func_i15_802C602C(Gfx* gdl) {
    s32 i;
    s32 race;
    s32 course;
    s32 show;
    s32 rank;
    s32 count;
    s32 tieRank;
    s32 value;
    s32 mode;
    s32 valueMode;
    s32 valueX;
    s32* place;
    PlayerName* name;
    UnkStruct_D_802C6E80* thing;
    char placeBuf[20];
    char valueBuf[12];
    s32 idx;
    s32 pad; // stack pad

    for (i = 0, thing = D_i15_802C6E80; i < 10; i++, thing++) {
        if (thing->unk0 == 0) {
            continue;
        }
        switch (thing->unk4) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                gSPDisplayList(gdl++, D_106F628);
                gdl = func_80094338(gdl, 0, thing->unk8, thing->unkC, 256, 32);
                gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                race = thing->unk4;
                if (gDifficulty == DIFFICULTY_NORMAL) {
                    race--;
                }
                if (D_i15_802C6E7C == thing->unk4) {
                    race = 8;
                }
                gdl = func_801E3EE0(gdl, 1, D_i15_802C6D9C[race], thing->unk8 + 24, thing->unkC + 4, 1);
                idx = D_i15_802C6F20[thing->unk4];
                place = &D_i15_802C6DC0[idx];
                gdl = func_801E3EE0(gdl, 1, *place, thing->unk8 + 39, thing->unkC + 16, 0);
                // The last place texture (index 4) is a separate symbol in the asm.
                if (place != &D_i15_802C6DD0) {
                    gdl = Printer_DrawTime(gdl, 2, D_801CB3D0[thing->unk4], thing->unk8 + 147, thing->unkC + 16);
                } else {
                    gdl = Printer_DrawString(gdl, 2, "-'--@---", thing->unk8 + 147, thing->unkC + 16);
                }
                course = D_800EAC14[gDifficulty][thing->unk4];
                gdl = func_801E3EE0(gdl, 1, D_800DAA10[course], D_i15_802C6DFC[course] + thing->unk8 + 137,
                                    thing->unkC + 4, 0);
                if (D_801C2660[course] == 1) {
                    gdl = Printer_SetMode(gdl, 4, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                    gdl = func_801E3EE0(gdl, 1, 98, thing->unk8 + 109, thing->unkC + 16, 2);
                }
                break;

            case 10:
                gSPDisplayList(gdl++, D_106F628);
                rank = 1;
                tieRank = 1;
                count = 1;
                gdl = func_80094338(gdl, 0, thing->unk8, thing->unkC, 265, 23);
                gdl = func_80094338(gdl, 0, thing->unk8, thing->unkC + 27, 265, 16);
                for (i = 0; i < 4; i++) {
                    gdl = func_80094338(gdl, 0, thing->unk8, thing->unkC + i * 32 + 46, 265, 28);
                }
                if (D_800DAB68 == 0) {
                    if (gDifficulty == DIFFICULTY_EXPERT) {
                        if (gRiderRaceState[gPlayer1Rider].unk338 == 0) {
                            show = true;
                        } else {
                            show = false;
                        }
                    } else {
                        show = true;
                    }
                    if (show) {
                        gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i15_802C6DD8);
                        gdl = func_80094338(gdl, 0, thing->unk8 + 30, thing->unkC + 174, 204, 16);
                    }
                }
                gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                gdl = func_801E3EE0(gdl, 2, 38, thing->unk8 + 12, thing->unkC + 3, 0);
                gdl = func_801E3EE0(gdl, 1, 31, thing->unk8 + 5, thing->unkC + 30, 0);
                gdl = func_801E3EE0(gdl, 1, 32, thing->unk8 + 101, thing->unkC + 30, 0);
                gdl = func_801E3EE0(gdl, 1, 58, thing->unk8 + 207, thing->unkC + 30, 0);
                if (D_800DAB68 == 0) {
                    if (gDifficulty == DIFFICULTY_EXPERT) {
                        if (gRiderRaceState[gPlayer1Rider].unk338 == 0) {
                            show = true;
                        } else {
                            show = false;
                        }
                    } else {
                        show = true;
                    }
                    if (show) {
                        gdl = Printer_SetMode(gdl, 10, D_i15_802C6DD4, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                                              255);
                        gdl = func_801E3EE0(gdl, 1, 99, thing->unk8 + 36, thing->unkC + 177, 0);
                    }
                }
                gdl = func_801E7E74(gdl, 0, 0, 0, 255);
                for (i = 0; i < 4; i++) {
                    gdl = func_801E7FD8(gdl, thing->unk8 + 34, thing->unkC + i * 32 + 49, thing->unk8 + 78,
                                        thing->unkC + i * 32 + 70);
                }
                gDPPipeSync(gdl++);
                gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
                for (i = 0; i < 4; i++) {
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
                    } else {
                        mode = 6;
                    }
                    if (gPlayer1Rider != D_800DA9DC[i]) {
                        valueMode = 0;
                    } else {
                        valueMode = 6;
                    }
                    sprintf(valueBuf, "%d", value);
                    if ((value / 10) % 10 != 0) {
                        valueX = 228 - gPrinterWidthsFont0[(value / 10) % 10];
                    } else {
                        valueX = 228;
                    }
                    gdl = Printer_Print(gdl, 0, placeBuf, thing->unk8 + 5, thing->unkC + i * 32 + 50, mode, 0xFF, 0xFF,
                                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                    gdl = Printer_Print(gdl, 2, name->unk_0, thing->unk8 + 84, thing->unkC + i * 32 + 54, 0, 0xFF, 0xFF,
                                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                    gdl = Printer_Print(gdl, 0, valueBuf, thing->unk8 + valueX, thing->unkC + i * 32 + 50, valueMode,
                                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                }
                gdl = func_80093AFC(gdl);
                gDPPipeSync(gdl++);
                gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320,
                                 OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
                gSPPerspNormalize(gdl++, D_i15_802C6F40);
                gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                gSPDisplayList(gdl++, D_106F488);
                gDPPipeSync(gdl++);
                gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
                for (i = 0; i < 4; i++) {
                    gSPViewport(gdl++, &D_7001280[i]);
                    gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gdl = func_801E4FE8(gdl, D_800DA9DC[i], 0, 0, D_801CE5F8->unkC80[i]);
                }
                break;
        }
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C602C.s")
#endif

void func_i15_802C6C1C(void) {
    if (D_i15_802C6DF4) {
        D_i15_802C6DF8++;
        if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (D_i15_802C6DF8 > 600)) {
            if ((D_i15_802C6E74 != 0) || (D_i15_802C6E78 != 0)) {
                func_i15_802C6CAC(100);
            } else {
                func_i15_802C6CAC(2);
            }
        }
    }
}

void func_i15_802C6CAC(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x67;
    D_801CE638 = 0x15;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    FadeTransition_SetProps(3, 0x14, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
    }
}
