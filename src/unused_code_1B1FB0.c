#include "global.h"

extern s32 D_800D45DC[]; // array pointing to some mio0 adresses

Gfx* func_1B1FB0_802C71B8(Gfx*, char, s32, s32);
extern s32 D_802C7718;
extern u8 D_8000008[];
extern u8 D_804A460[];

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5800.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5BA4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5DF4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C62E4.s")

Gfx* func_1B1FB0_802C67BC(Gfx* gdl, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < 5; i++) {
        gDPLoadTextureBlock(gdl++, &D_804A460[i * 0x1000], G_IM_FMT_RGBA, G_IM_SIZ_16b, 512, 4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, x << 2, (y + i * 4) << 2, (x + 511) << 2, (y + i * 4 + 3) << 2, G_TX_RENDERTILE,
                            0, 0, 4 << 10, 1 << 10);
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6970.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6C1C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6E40.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6FF8.s")

#ifdef NON_MATCHING
// Score 410 of 8300: the first packet goes through a copy of gdl (move v1,a0 in the delay slot); the
// original writes it at a0 and puts gdl + 8 in t0 there. The rest matches.
Gfx* func_1B1FB0_802C71B8(Gfx* gdl, char c, s32 x, s32 y) {
    if (c < 16) {
        return gdl;
    }
    if (c >= 0x42) {
        c = 0x3B;
    }
    c -= 16;
    if (1) {} // FAKE: without it c is copied into v1 and the score is 2285
    gDPLoadTextureBlock(gdl++, &D_8000008[c << 8], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                        1 << 10);
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C71B8.s")
#endif

s32 func_1B1FB0_802C7304(s32 arg0, s8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s1 = arg3;

    D_802C7718 = 0;

    while (arg2) {
        if (*arg1 != 0) {
            D_802C7718++;
        }
        arg0 = (s32) func_1B1FB0_802C71B8((Gfx*) arg0, *(arg1++), s1, arg4);
        arg2--;
        s1 += 0x10;
    }
    return arg0;
}

Gfx* func_1B1FB0_802C73B0(Gfx* gdl) {
    size_t i;

    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);

    gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE | 0x300000);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gdl++);
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 640, VIRTUAL_TO_PHYSICAL2(D_800D45DC[i]));

        gDPSetFillColor(gdl++, 0x10001);
        gDPFillRectangle(gdl++, 0, 0, 639, 479);
    }

    return gdl;
}

void func_1B1FB0_802C7510(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 6;
    D_801CE638 = 0x13;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 3;
    gVIsPerFrame = 2;
}

void* func_1B1FB0_802C7578(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {

    gSPTexture(arg0++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(arg0++);
    gDPSetCycleType(arg0++, G_CYC_1CYCLE);
    gDPSetPrimColor(arg0++, 0, 0, 0, 0, 0, arg5);
    gDPSetCombineMode(arg0++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(arg0++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(arg0++, G_AC_NONE);
    gDPFillRectangle(arg0++, arg1, arg2, arg3, arg4);

    return arg0;
}
