#include "common.h"

extern Gfx D_106F6C0[];
extern Mtx D_7001380[];
extern Gfx* D_i5_802C7AA8[];

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7090.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7484.s")

Gfx* func_i5_802C7594(Gfx* gdl) {
    s32 i;

    gSPDisplayList(gdl++, D_106F6C0);
    for (i = 0; i < 8; i++) {
        gSPMatrix(gdl++, &D_7001380[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gdl++, D_i5_802C7AA8[i]);
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7698.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C781C.s")

void func_i5_802C79F4(void) {
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
