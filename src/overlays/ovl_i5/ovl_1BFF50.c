#include "common.h"

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C6CC4.s")

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
