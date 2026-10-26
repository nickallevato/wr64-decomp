#include "common.h"

#ifdef NON_MATCHING
// Score 36 of 34300: isBlock and segs are stored to the stack in the other order (isBlock at sp+0x3c in the original), and in case 1 tex
// and height take $t1/$a3 where the original has $a3/$t4. The (s32) cast makes the rectangle's right edge signed (blez), as the original.
extern TexEntry D_802263C0[];
extern TexEntry D_802264F8[];
extern TexEntry D_80226568[];
extern TexEntry D_80226890[];
extern TexEntry D_80226A48[];

Gfx* func_801E3EE0(Gfx* gdl, s32 kind, s32 index, s32 x, s32 y, s32 arg5) {
    s32 i;
    s32 height;
    s32 segs;
    s32 isBlock;
    TexEntry* tex;

    isBlock = 1;
    segs = 1;
    switch (kind) {
        case 0:
            height = 8;
            tex = &D_802263C0[index];
            break;
        case 4:
            height = 10;
            tex = &D_802264F8[index];
            break;
        case 1:
            tex = &D_80226568[index];
            height = arg5 + 10;
            isBlock = 0;
            if (height) {} // FAKE: empty test, reassigns this case's registers (found with a scan)
            break;
        case 2:
            tex = &D_80226A48[index];
            height = 18;
            isBlock = 0;
            if ((s32) tex->width >= 228) {
                segs = 2;
                height = 9;
            }
            break;
        case 3:
            tex = &D_80226890[index];
            isBlock = 0;
            height = arg5 + 14;
            if (arg5 == 6) {
                segs = 5;
                height = 4;
            } else if ((s32) tex->width >= 291) {
                segs = 2;
                height = 7;
            }
            break;
    }
    for (i = 0; i < segs; i++) {
        if (isBlock) {
            // the block load sees height as unsigned, the tile load as signed
            gDPLoadTextureBlock(gdl++, tex->img, G_IM_FMT_IA, G_IM_SIZ_8b, tex->width, (u32) height, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureTile(gdl++, tex->img + tex->width * height * i, G_IM_FMT_IA, G_IM_SIZ_8b, tex->width,
                               height, 0, 0, tex->width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPScisTextureRectangle(gdl++, x << 2, (y + height * i) << 2, (x + (s32) tex->width) << 2,
                                (y + height * i + height) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B2510/func_801E3EE0.s")
#endif
