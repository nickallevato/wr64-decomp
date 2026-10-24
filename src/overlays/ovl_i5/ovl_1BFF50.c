#include "common.h"

extern s16 D_i5_802C7A00;
extern s32 D_802C7B00;
extern s32 D_802C7B08;
extern s32 D_802C7B0C;

void func_800C3E4C(void);
void func_801EC944(void);
void func_i5_802C6F84(s32 arg0);

void func_i5_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 52)) {
        func_80094ACC();
        func_i5_802C5A98();
    }
    func_i5_802C5850();
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5850.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5A98.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5C1C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5DC0.s")

void func_i5_802C6CC4(void) {
    s32 playSound = false;

    switch (D_801CE640) {
        case 0:
            if (D_80228A16 == 1) {
                D_801CE640 = 1;
                playSound = true;
            }
            break;

        case 1:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < 0x14) {
                D_801CE640 = 2;
                D_i5_802C7A00 = 0x14;
                D_801CE644 = 0;
            }
            break;

        case 2:
            if (D_801CE644 < 0x3C) {
                D_801CE644++;
            }
            if (D_801CE644 >= 0x1F) {
                if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                    D_801CE640 = 3;
                    playSound = true;
                }
            }
            break;

        case 3:
            D_i5_802C7A00 -= 0x14;
            if (D_i5_802C7A00 < -0x109) {
                D_801CE640 = 4;
                D_i5_802C7A00 = -0x109;
                playSound = true;
            }
            break;

        case 4:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 > 0x14) {
                D_801CE640 = 5;
                D_i5_802C7A00 = 0x14;
                D_802C7B0C = 0;
            }
            break;

        case 5:
            if (D_802C7B0C < 0x10) {
                D_802C7B0C++;
            }
            if ((D_802C7B0C == 6) && (D_802C7B00 == 1)) {
                func_800C3E4C();
            }
            if (D_802C7B0C >= 6) {
                if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                    D_801CE640 = 6;
                    D_801CE644 = 0;
                    AudioGeneral_PlaySound(0x11, 0);
                }
            }
            break;

        case 6:
            D_801CE644++;
            if (D_801CE644 >= 0x1E) {
                if (D_802C7B08 != 0x5A) {
                    func_i5_802C6F84(D_802C7B08);
                } else {
                    D_801CE640 = 7;
                    playSound = true;
                    func_800C1F60(5);
                }
            }
            break;

        case 7:
            D_i5_802C7A00 += 0x14;
            if (D_i5_802C7A00 > 0x140) {
                D_i5_802C7A00 = 0x140;
                func_801EC944();
            }
            break;
    }

    if (playSound) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}

void func_i5_802C6F84(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x35;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    if (D_801CE630 == 0x66) {
        FadeTransition_SetProps(1, 4, 0);
    } else if (D_801CE630 == 0x1E) {
        FadeTransition_SetProps(5, 2, 0);
    } else {
        FadeTransition_SetProps(5, 1, 0);
    }

    if (D_801CE630 == 0x66) {
        func_800C1F60(0xB);
    } else if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
    }
}
