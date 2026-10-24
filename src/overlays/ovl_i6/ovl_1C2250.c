#include "common.h"

void func_i6_802C6B34(void);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5800.s")

Gfx* func_i6_802C5B74(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if ((gGameState == 0x32) && (gPrevGameState != 0x64)) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;
    gdl = func_i6_802C5C2C(Draw_WaterEffects(func_800949B8(func_8008FB74(gdl), gCourseID)));

    if (gGameState == 0x32) {
        func_i6_802C6B34();
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5C2C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C6B34.s")
