#include "global.h"

extern s32 D_80223938;
extern s32 D_802C7028;
extern s32 D_802C702C;
extern s32 D_i3_802C6F84;
extern s32 D_i3_802C6F88;
extern s32 D_801CB330;
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern s32 D_801CB350[][4];
extern s32 D_801CB3D0[];
extern RiderStruct D_801C2C70[];
extern const s16 D_800EABB0[];
extern const s16 D_800EABBC[][8];
extern s32 D_800E9AB0;
// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;
// The asm names this array D_801CE6FC + 0xC; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE708[4];
extern s32 D_802C7020;
extern s32 D_i3_802C6F8C;
extern s32 D_i3_802C6FE4[];
extern s32 D_i3_802C6F64;
extern s32 D_i3_802C6F68;
extern s32 D_i3_802C6F6C;
extern s32 D_i3_802C6F70;
extern s32 D_i3_802C6F74;
extern s32 D_i3_802C6F78;
extern s32 D_i3_802C6F7C;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x4 */ s32 texture;
} UnkStruct_i3_802C6FB4; // size = 0x8

extern UnkStruct_i3_802C6FB4 D_i3_802C6FB4[];
extern UnkStruct_i3_802C6FB4 D_i3_802C6FCC;

void func_i3_802C5AE8(void);
void func_i3_802C5AF0(void);
Gfx* func_i3_802C5D54(Gfx*);
Gfx* func_i3_802C6344(Gfx*);
void GameState_EnterCourseOverview(void);
void func_i3_802C6E9C(void);

void func_i3_802C5800(void) {
    s32 i;
    s32 j;

    if ((D_801CE63C != 0) && (gGameState == 30)) {
        if (D_801CB334 == D_i3_802C6FE4[gDifficulty]) {
            for (i = 0; i < 8; i++) {
                // A do-while: a for loop over j unrolls into another store order.
                j = 0;
                do {
                    D_801CB350[i][j] = 0;
                } while (++j < 4);
                D_801CB3D0[i] = 0;
            }
            for (i = 0; i < 4; i++) {
                D_801CB340[i] = 0;
            }
            for (i = 0; i < 4; i++) {
                D_801C2C70[i].lapCount = 0;
            }
        }

        D_802C7028 = 1;
        D_i3_802C6F84 = 0;
        if (gDifficulty == DIFFICULTY_NORMAL) {
            if (D_801CB334 == 1) {
                D_802C7028 = 0;
                D_802C702C = 240;
            } else {
                D_802C702C = 180;
            }
        } else if (D_801CB334 == 0) {
            D_802C7028 = 0;
            D_802C702C = 240;
        } else {
            D_802C702C = 180;
        }

        if (D_801CB330 == 0) {
            D_802C7020 = 0;
            for (i = 0; i < 4; i++) {
                D_801CE708[i] = 4;
            }
            D_801CE704 = D_801CE708[gPlayer1Rider];
        } else {
            for (i = 0; i < 4; i++) {
                D_802C7020 = D_800EABBC[gDifficulty][D_801CB334] - D_801CB340[i];
                for (j = 1; j < 5; j++) {
                    if (D_800EABB0[j] < D_802C7020) {
                        break;
                    }
                }
                D_801CE708[i] = j - 1;
            }
            D_801CE704 = D_801CE708[gPlayer1Rider];
        }

        func_80069740((UnkStruct_80069740*) &D_80198310, D_800DAAB4[gCourseID]);
        func_8006977C(&D_80198350, (s32) &D_800E9AB0);
        if (D_800DAB68 != 0) {
            D_i3_802C6F8C = 2;
        } else {
            D_i3_802C6F8C = 0;
        }
    }

    switch (D_802C7028) {
        case 0:
            func_i3_802C5AE8();
            break;
        case 1:
            func_i3_802C5AF0();
            break;
    }
}

void func_i3_802C5AE8(void) {
}

void func_i3_802C5AF0(void) {
    Camera_SetOrbitMatrices(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C7024, &D_80198310, &D_80198350);
}

Gfx* func_i3_802C5B40(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 30) {
            return func_80093C44(arg0);
        }
    }
    D_800DAB2C = 0;
    arg0 = func_8009328C(arg0);

    if (D_80223938 != 0) {
        switch (D_802C7028) {
            case 0:
                arg0 = func_i3_802C5D54(arg0);
                break;
            case 1:
                arg0 = func_i3_802C6344(arg0);
                break;
        }
    }
    gSPDisplayList(arg0++, D_106F168);

    if (gGameState == 30) {
        if (D_i3_802C6F88 != 0) {
            D_i3_802C6F88 = 0;
            GameState_EnterCourseOverview();
        } else {
            if (D_801CE692[0].unk0 & 0xB000) {
                if (D_i3_802C6F84 != 0) {
                    func_i3_802C6E9C();
                }
            } else if (D_80223938 != 0) {
                if (D_801CE644 >= D_802C702C) {
                    func_i3_802C6E9C();
                }
            }
            SysUtils_Rand();
        }
    } else {
        if (D_801CE644 >= 0) {
            D_801CE644--;
        }
        if (D_801CE644 == 0) {
            func_800C1F60(7);
        }
        if (D_80228A16 == 1) {
            gCourseID = D_801CB330;
            func_8009345C();
        }
    }
    if (D_801CE638 != 8) {
        func_800AD3C4();
    }
    if (gGameState == 30) {
        D_801CE644++;
    }
    return arg0;
}

#ifdef NON_MATCHING
// Score 4465 of 38000. The control flow and arithmetic match, but the original keeps the addresses of
// D_i3_802C6F78 and D_i3_802C6F7C in registers (base-register stores in every case) where IDO here stores
// through `lui at`, so the C is 0x20 bytes shorter and the overlay's data after it moves.
Gfx* func_i3_802C5D54(Gfx* gdl) {
    UnkStruct_i3_802C6FB4* label;

    switch (D_i3_802C6F64) {
        case 0:
            if (++D_i3_802C6F68 >= 5) {
                D_i3_802C6F64 = 1;
                D_i3_802C6F74 = 0;
                D_i3_802C6F68 = 0;
            }
            D_i3_802C6F7C = D_i3_802C6F70 = D_i3_802C6F6C = D_i3_802C6F78 = 0;
            break;

        case 1:
            if (++D_i3_802C6F68 >= 20) {
                D_i3_802C6F74++;
            }
            if (D_i3_802C6F68 >= 10) {
                D_i3_802C6F6C = 255;
                D_i3_802C6F70 = 170;
            } else {
                D_i3_802C6F6C = D_i3_802C6F68 * 255 / 10;
                D_i3_802C6F70 = D_i3_802C6F68 * 170 / 10;
            }
            if (D_i3_802C6F74 >= 10) {
                D_i3_802C6F78 = 255;
                D_i3_802C6F7C = 170;
            } else {
                D_i3_802C6F78 = D_i3_802C6F74 * 255 / 10;
                D_i3_802C6F7C = D_i3_802C6F74 * 170 / 10;
            }
            if ((D_i3_802C6F68 >= 10) && (D_i3_802C6F74 >= 10)) {
                D_i3_802C6F64 = 2;
                D_i3_802C6F6C = D_i3_802C6F78 = 255;
                D_i3_802C6F7C = D_i3_802C6F70 = 170;
                D_i3_802C6F68 = 0;
                D_i3_802C6F74 = 0;
            }
            break;

        case 2:
            if (++D_i3_802C6F68 >= 25) {
                D_i3_802C6F64 = 3;
                D_i3_802C6F74 = 0;
                D_i3_802C6F68 = 0;
            }
            D_i3_802C6F6C = D_i3_802C6F78 = 255;
            D_i3_802C6F7C = D_i3_802C6F70 = 170;
            break;

        case 3:
            if (++D_i3_802C6F68 >= 10) {
                D_i3_802C6F64 = 0;
                D_i3_802C6F68 = 0;
                D_i3_802C6F6C = 0;
                D_i3_802C6F70 = 0;
                D_802C7028 = 1;
            } else {
                D_i3_802C6F6C = (10 - D_i3_802C6F68) * 255 / 10;
                D_i3_802C6F70 = (10 - D_i3_802C6F68) * 170 / 10;
            }
            D_i3_802C6F78 = D_i3_802C6F6C;
            D_i3_802C6F7C = D_i3_802C6F70;
            break;
    }

    gSPDisplayList(gdl++, D_106F628);
    gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i3_802C6F70);
    gdl = func_80094338(gdl, 2, 32, 75, 256, 32);
    gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i3_802C6F7C);
    gdl = func_80094338(gdl, 0, 32, 133, 256, 32);
    gdl = Printer_SetMode(gdl, 10, D_i3_802C6F6C, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 34, 72, 81, 0);
    gdl = Printer_SetMode(gdl, 10, D_i3_802C6F78, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    if (D_800DAB68 != 0) {
        label = &D_i3_802C6FCC;
    } else {
        label = &D_i3_802C6FB4[gDifficulty];
    }
    return func_801E3EE0(gdl, 2, label->texture, label->x + 50, 139, 0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5D54.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C6344.s")

void func_i3_802C6E9C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    Popup_Spawn(0, 0);
    AudioGeneral_PlaySound(58, 0);
}
