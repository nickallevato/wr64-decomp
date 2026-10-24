#include "common.h"

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EE9C0.s")

// HUD_Init
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EED70.s")

// Set up the HUD projection matrices in the current Gfx pool.
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EF3C4.s")

// Per-frame update of the guide arrow
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EF504.s")

// Draw the guide arrow (next-buoy compass) for each player.
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EFFD8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F03E0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F06A0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F0E7C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F14B4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F1CFC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F2060.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F23A0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F25E0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F4120.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F8DD0.s")

typedef struct UnkStruct_80228D28 {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ char pad8[8];
    /* 0x10 */ s32 unk10;
} UnkStruct_80228D28; /* size = 0x14 */

extern Gfx D_1014760[];
extern Gfx D_1014790[];
extern u8 D_10387C0[];
extern u8 D_1040FE0[];
extern u8 D_10416A8[];
extern u8 D_1041BB0[];
extern u8 D_10420B8[];
extern RiderStruct D_801C2938[];
extern u8* D_80227978[];
extern f32 D_802279A4[];
extern s32 D_80228AB8;
extern s32 D_80228ABC;
extern s32 D_80228AC0;
extern s32 D_80228B50;
extern UnkStruct_80228D28 D_80228D28[2][4];
extern s32 D_80228DC8[];

// Draw the column of rider portraits, with their race positions.
void func_801F9520(Gfx** gdlp) {
    Gfx* gdl = *gdlp;
    s32 i;
    s32 idx;
    s32 player;
    s32 x;
    s32 y;
    s32 xOff;
    s32 yOff;
    s32 highlight;
    s32 face;
    s32 numX;
    s32 numY;
    u8* img;
    UnkStruct_80228D28* pos;
    f32 bob;

    if (gPlayers == ONE_PLAYER) {
        gSPDisplayList(gdl++, D_1014760);
    } else {
        gSPDisplayList(gdl++, D_1014790);
    }

    for (player = 0; player < gPlayers; player++) {
        if (gPlayers == ONE_PLAYER) {
            xOff = D_80228B50 + 0x106;
            yOff = 0x3C;
        } else {
            xOff = 0x108;
            if (player == 0) {
                yOff = 0x2B;
            } else {
                yOff = 0x99;
            }
        }
        for (i = 0; i < gRiders; i++) {
            if (player == 0) {
                idx = gRiders - i - 1;
            } else {
                idx = i;
            }
            pos = &D_80228D28[player][idx];
            x = pos->x + xOff;
            y = pos->y + yOff;
            bob = D_802279A4[pos->unk10 & 7] * 4.0f;
            y = y - bob;

            if (((player == 0) && (idx == D_800D48DC)) || ((player == 1) && (idx == D_800D48E0))) {
                highlight = 1;
            } else {
                highlight = 0;
            }

            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetRenderMode(gdl++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);

            if (highlight) {
                if (D_801C2938[idx].unk2F4 == 0) {
                    img = D_1040FE0;
                } else {
                    img = D_10420B8;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, (x - 7) << 2, y << 2, (x + 0x1D) << 2, (y + 0x18) << 2, G_TX_RENDERTILE, 0,
                                    0, 1 << 10, 1 << 10);
            } else {
                if (D_801C2938[idx].unk2F4 == 0) {
                    img = D_10416A8;
                } else {
                    img = D_1041BB0;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
            }

            if (((idx == D_800D48DC) && (D_801CE6F4[0] != 0)) ||
                ((gPlayers == TWO_PLAYERS) && (idx == D_800D48E0) && (D_801CE6F4[1] != 0))) {
                face = 4;
            } else {
                face = 0;
            }
            gDPLoadTextureBlock(gdl++, D_80227978[D_80192690[idx].unkB68 + face], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20,
                                0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            if (highlight) {
                gSPTextureRectangle(gdl++, (x + 5) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x16) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 1 << 10, 1 << 10);
            } else {
                gSPTextureRectangle(gdl++, (x + 9) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x12) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 0x500, 0x500);
            }

            gDPPipeSync(gdl++);
            gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0,
                              TEXEL0);
            if (highlight) {
                gDPSetEnvColor(gdl++, D_80228AB8, D_80228ABC, D_80228AC0, 255);
                numX = x - 4;
                numY = y + 4;
            } else {
                gDPSetEnvColor(gdl++, 255, 255, 255, 255);
                numX = x + 2;
                numY = y + 2;
            }
            gDPLoadTextureBlock(gdl++, &D_10387C0[(D_801C2938[idx].racePosition + 1) * 64], G_IM_FMT_IA, G_IM_SIZ_8b, 8,
                                8, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gdl++, numX << 2, numY << 2, (numX + 8) << 2, (numY + 8) << 2, G_TX_RENDERTILE, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    *gdlp = gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F9EA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FA3C0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FAD68.s")

void func_801FAEA8(void) {
}
