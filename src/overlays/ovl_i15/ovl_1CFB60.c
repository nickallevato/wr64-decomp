#include "global.h"

extern s32 D_800DAA08;
extern const s16 D_800EABB0[];
extern RiderStruct D_801C2C70[];
extern s32 D_801CB350[][4];
extern s32 D_i15_802C6D54[];
extern s32 D_i15_802C6D68;
extern s32 D_i15_802C6D6C;
extern s32 D_i15_802C6D70[];
extern UnkStruct_D_802C6E80 D_i15_802C6D8C;
extern s32 D_802C6E7C;
extern s32 D_802C6F20[];
extern s32 D_802C6F44;
extern const s16 D_800EAC14[][8];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern s32 D_801CB334;
extern u16 D_802C6F40;
extern s32 D_i15_802C6DD4;
extern s32 D_i15_802C6DD8;
extern s32 D_i15_802C6DDC;
extern Vp D_i15_802C6DE0;
extern s32 D_i15_802C6DF0;

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
        D_802C6E74 = D_802C6E78 = 0;
        for (i = 0; i < D_801CB334 + 1; i++) {
            course = D_800EAC14[gDifficulty][i];
            if (D_801C2660[course] != 0) {
                D_802C6E74 = 1;
            }
            if (D_801C2690[course] != 0) {
                D_802C6E78 = 1;
            }
        }
    }

    i = 0;
    if ((--D_i15_802C6D6C < 0) && (D_i15_802C6D68 != -1)) {
        func_i15_802C5EE4(D_i15_802C6D68);
        D_i15_802C6D6C = 40;
        if (D_i15_802C6D68 == D_802C6E7C) {
            D_i15_802C6D68 = 10;
            D_i15_802C6D6C = 110;
        } else if (D_i15_802C6D68 == 10) {
            D_i15_802C6D68 = -1;
        } else {
            D_i15_802C6D68++;
        }
    }

    func_800481E0(D_801CE5F8->unkA40, &D_802C6F40, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB8, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.04f);
    temp_fv1 = COS(0) * 500.0f;
    temp_fa0 = SIN(0) * 500.0f;
    // FAKE: arg3 is an int 0 literal to match (li a3, 0), as in func_i5_802C5850
    func_800484C8(&sp78, &sp13C, temp_fv1, 0, temp_fa0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB8, &sp17C);
    SysUtils_MatrixAffineMultiply(&sp13C, &sp17C, &spFC);

    thing = D_802C6E80;
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
        D_802C6E80[i] = D_i15_802C6D8C;
    }
    D_802C6E7C = D_i15_802C6D54[gDifficulty];
    if (D_801C2C70[gPlayer1Rider].lapCount == 3) {
        D_802C6F44 = 6;
    } else if (gDifficulty == DIFFICULTY_EXPERT) {
        if (D_801C2C70[gPlayer1Rider].lapCount == 0) {
            D_802C6F44 = 3;
        } else if (D_801C2C70[gPlayer1Rider].lapCount == 1) {
            D_802C6F44 = 4;
        } else {
            D_802C6F44 = 5;
        }
    } else {
        if (D_801C2C70[gPlayer1Rider].lapCount == 0) {
            D_802C6F44 = 0;
        } else if (D_801C2C70[gPlayer1Rider].lapCount == 1) {
            D_802C6F44 = 1;
        } else {
            D_802C6F44 = 2;
        }
    }
    D_i15_802C6D6C = D_i15_802C6D70[D_802C6F44];
    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_i15_802C6D68 = 1;
    } else {
        D_i15_802C6D68 = 0;
    }
    for (i = 0; i < D_802C6E7C + 1; i++) {
        for (j = 0; j < 4; j++) {
            if (D_800EABB0[j] == D_801CB350[i][0]) {
                break;
            }
        }
        D_802C6F20[i] = j;
    }
    D_800DAA08 = 1;
}

void func_i15_802C5EE4(s32 arg0) {
    UnkStruct_D_802C6E80* thing;
    s32 i;

    for (i = 0, thing = &D_802C6E80[0]; i < 10; i++, thing++) {
        if (thing->unk0 == 0) {
            break;
        }
    }

    thing = &D_802C6E80[i];

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i15/ovl_1CFB60/func_i15_802C602C.s")

void func_i15_802C6C1C(void) {
    if (D_i15_802C6DF4) {
        D_i15_802C6DF8++;
        if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) || (D_i15_802C6DF8 > 600)) {
            if ((D_802C6E74 != 0) || (D_802C6E78 != 0)) {
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
