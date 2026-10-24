#include "common.h"

extern f32 gPrinterScale;   /* glyph scale, set by func_801E93B4 */
extern s16 gPrinterScaled;  /* 1 while the scaled printer is in use; func_801E93B4 leaves it set */

typedef struct {
    /* 0x00 */ s16 unk0;  /* nonzero: func_801EAFB4 steps unk2 */
    /* 0x02 */ s16 unk2;  /* 0..3, advanced every unk8 frames */
    /* 0x04 */ s32 unk4;  /* frame counter */
    /* 0x08 */ s32 unk8;  /* frames per step */
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
} UnkStruct_80228A78; /* size = 0x14 */

extern UnkStruct_80228A78 D_80228A78;
extern UnkStruct_80228A78 D_80226E30; /* initial value, copied by func_801EAF78 */

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E80B0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8800.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8A84.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E8B24.s")

/* r0..b3: RGB of the four glyph-quad corners (the recomp passes top, top, bottom, bottom). */
Gfx* func_801E92FC(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3) {
    gPrinterScale = 1.0f;
    gdl = func_801E946C(gdl, mode, (s32) r0, (s32) g0, (s32) b0, (s32) r1, (s32) g1, (s32) b1,
                        (s32) r2, (s32) g2, (s32) b2, (s32) r3, (s32) g3, (s32) b3);
    gPrinterScaled = 0;
    return func_801E9858(gdl, font, str, x, y);
}

/* Prints str in font at (x, y) at the given scale: sets the printer's mode and corner colours, then prints. */
Gfx* func_801E93B4(Gfx* gdl, s32 font, char* str, s32 x, s32 y, s32 mode, u8 r0, u8 g0, u8 b0, u8 r1, u8 g1, u8 b1,
                   u8 r2, u8 g2, u8 b2, u8 r3, u8 g3, u8 b3, f32 scale) {
    gPrinterScale = scale;
    gdl = func_801E946C(gdl, mode, (s32) r0, (s32) g0, (s32) b0, (s32) r1, (s32) g1, (s32) b1,
                        (s32) r2, (s32) g2, (s32) b2, (s32) r3, (s32) g3, (s32) b3);
    gPrinterScaled = 1;
    return func_801E9858(gdl, font, str, x, y);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E946C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9858.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9B04.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801E9D6C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA0B0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA3EC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EA730.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EAA6C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EADB0.s")

void func_801EAF78(void) {
    D_80228A78 = D_80226E30;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EAFB4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B66E0/func_801EB00C.s")
