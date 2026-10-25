#include "common.h"

extern Gfx D_106F6C0[];
extern Mtx D_7001380[];
extern Gfx* D_i5_802C7AA8[];
extern s32 D_i5_802C7AC8;
extern Mtx D_8011F820;

Gfx* func_80094A44(Gfx*, s32);
Gfx* func_i5_802C7594(Gfx* gdl);
Gfx* func_i5_802C7698(Gfx* gdl);
void func_i5_802C781C(void);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7090.s")

Gfx* func_i5_802C7484(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    gdl = func_80093F78(gdl);
    D_800DAB2C = 0;
    gdl = func_800949B8(gdl, gCourseID);
    gdl = func_8008FB74(gdl);
    if ((D_i5_802C7AC8 == 2) || (D_i5_802C7AC8 == 3) || (D_i5_802C7AC8 == 4)) {
        gdl = func_i5_802C7594(gdl);
    }
    gSPMatrix(gdl++, &D_8011F820, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_80094A44(gdl, gCourseID);
    gdl = Draw_WaterEffects(gdl);
    gdl = func_i5_802C7698(gdl);
    if (gGameState == GAME_STATE_5A) {
        func_i5_802C781C();
    } else if (D_80228A16 == 1) {
        GameState_EnterTitleScreen();
    }
    return gdl;
}

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
