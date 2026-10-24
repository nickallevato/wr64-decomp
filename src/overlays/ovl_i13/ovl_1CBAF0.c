#include "global.h"

extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_802C8E90;
extern s32 D_802C8E94;
extern s32 D_802C8E9C;

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5800.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5F6C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6068.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C61E0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C62EC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C64AC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C65D4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6700.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C69CC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6ABC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6BC4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6CE4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6E48.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6F0C.s")

void func_i13_802C7060(void) {
    switch (D_i13_802C8D78) {
        case 1:
            if (D_802C8E98 >= 5) {
                D_i13_802C8D78 = 2;
                D_802C8E98 = 0;
            }
            break;

        case 2:
            if (++D_802C8E98 >= 0xA) {
                D_i13_802C8D78 = 3;
                D_802C8E98 = 0;
            }
            break;

        case 3:
            if (++D_i13_802C8DC0 >= 0x5B) {
                D_i13_802C8D78 = 0;
                D_802C8E98 = 0;
                D_i13_802C8DC0 = 0;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C81AC.s")

void func_i13_802C82A4(s32 arg0) {
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    switch (arg0) {
        case 2:
            D_802C8E9C = 5;
            break;
        case 3:
            D_802C8E9C = 7;
            break;
        case 4:
            D_802C8E9C = 8;
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C832C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C8484.s")

void func_i13_802C8CBC(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x41;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
}
