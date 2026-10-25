#include "global.h"

extern s32 D_800DAA10[];
extern s32 D_i9_802C80C0;
extern s32 D_i9_802C80C4;
extern s32 D_i9_802C80C8;
extern s32 D_i9_802C8138[];
extern s32 D_i9_802C8144[];
extern s32 D_i9_802C8150[];

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5800.s")

Gfx* func_i9_802C5D24(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x42) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gdl = func_i9_802C6750(gdl);

    if (gGameState == 0x42) {
        if (D_i9_802C80DC == 0) {
            func_i9_802C5E5C();
        }
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x3C:
                GameState_EnterOptionsMenu();
                break;
            case 0x02:
                GameState_EnterTitleScreen();
                break;
            case 0x50:
                func_801EC830();
        }
    }

    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5E5C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C6750.s")

Gfx* func_i9_802C6CC8(Gfx* gdl, s32 x) {
    s32 i;
    s32 mode;

    gSPDisplayList(gdl++, D_106F628);
    for (i = 0; i < 9; i++) {
        gdl = func_80094338(gdl, 0, x + 28 + (i / 5) * 133, (i % 5) * 18 + 95, 131, 16);
    }
    gdl = func_80094338(gdl, 0, x + 28, 68, 87, 16);
    gdl = func_80094338(gdl, 0, x + 117, 68, 87, 16);
    gdl = func_80094338(gdl, 0, x + 206, 68, 87, 16);
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 7, x + 72, 29, 0);

    for (i = 0; i < 3; i++) {
        gdl = Printer_SetMode(gdl, (i == D_i9_802C80C4) ? 6 : 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                              255, 255);
        gdl = func_801E3EE0(gdl, 1, D_i9_802C8138[i], D_i9_802C8144[i] + x + i * 89 + 52, 71, 0);
    }

    for (i = 0; i < 9; i++) {
        if (D_i9_802C80C0 == 0) {
            if (D_i9_802C80C4 == 0) {
                if (i == 0) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else {
                mode = 0;
            }
        } else if (D_i9_802C80C4 == 0) {
            if (i == 0) {
                mode = 7;
            } else if (i == D_i9_802C80C8) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else if (i == D_i9_802C80C8) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = func_801E3EE0(gdl, 1, D_800DAA10[D_800DAAD8[i]], D_i9_802C8150[D_800DAAD8[i]] + x + (i / 5) * 133 + 55,
                            (i % 5) * 18 + 98, 0);
    }
    return gdl;
}

void func_i9_802C7194(s32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
    arg0[3] = arg4;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C71AC.s")

void func_i9_802C802C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x43;
    D_801CE638 = 0xC;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
}
