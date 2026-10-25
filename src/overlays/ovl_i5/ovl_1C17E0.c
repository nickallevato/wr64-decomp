#include "common.h"

extern Gfx D_106F6C0[];
extern Mtx D_7001380[];
extern Gfx* D_i5_802C7AA8[];
extern s32 D_i5_802C7AA0;
extern s32 D_i5_802C7AC8;
extern s32 D_i5_802C7ACC;
extern s32 D_i5_802C7AD0;
extern s32 D_802C7B30;
extern s32 D_802C7B34;
extern s16* D_802C7B38;
extern s16* D_802C7B3C;
extern s32 D_802C7B88;
extern s32 D_802C7B8C;
extern s32 D_802C7B90;
extern Mtx D_8011F820;

Gfx* func_80094A44(Gfx*, s32);
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);
void func_801EC830(void);
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

Gfx* func_i5_802C7698(Gfx* gdl) {
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, D_i5_802C7ACC, 145, 208, 15);
    gdl = func_80094338(gdl, 0, D_i5_802C7AD0, 166, 208, 15);
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 1, 6, D_i5_802C7ACC + 10, 147, 0);
    gdl = func_801E3EE0(gdl, 1, 7, D_i5_802C7AD0 + 10, 168, 0);
    gdl = Printer_DrawNumber(gdl, 2, D_802C7B34, D_i5_802C7ACC + 186, 147);
    gdl = Printer_DrawNumber(gdl, 2, D_802C7B30, D_i5_802C7AD0 + 186, 168);
    return gdl;
}

void func_i5_802C781C(void) {
    s32 done;

    switch (D_i5_802C7AC8) {
        case 0:
            D_i5_802C7ACC -= 30;
            if (D_i5_802C7ACC < 56) {
                D_i5_802C7AC8 = 1;
                D_i5_802C7ACC = 56;
            }
            break;

        case 1:
            D_i5_802C7AC8 = 2;
            break;

        case 2:
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == *D_802C7B38) {
                D_i5_802C7AA0--;
                D_i5_802C7AC8 = 3;
            }
            break;

        case 3:
            if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                D_i5_802C7AC8 = 4;
                D_i5_802C7AA0 = 0;
                D_802C7B88 = 0;
            }
            break;

        case 4:
            done = 0;
            D_i5_802C7ACC -= 30;
            if (D_i5_802C7ACC < -208) {
                done = 1;
                D_i5_802C7ACC = -208;
            }
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == *D_802C7B3C) {
                done++;
                D_i5_802C7AA0--;
            }
            if (done == 2) {
                D_802C7B88++;
            }
            if (D_802C7B88 >= 4) {
                if ((D_802C7B8C != 0) || (D_802C7B90 != 0)) {
                    func_801EC9C8();
                } else {
                    func_801EC830();
                }
            }
            break;
    }
    D_i5_802C7AD0 = 112 - D_i5_802C7ACC;
}

void func_i5_802C79F4(void) {
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
