#include "global.h"

typedef struct UnkStruct_801C3B90 {
    /* 0x0 */ f32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ s32 unk8;
} UnkStruct_801C3B90; // size = 0xC

extern s16 D_800D9640[16][2];
extern UnkStruct_801C3B90 D_801C3B90[16];

// Places D_801C3B90 at D_800D9640's sixteen positions with random angles, and sets the texture coordinates of the
// vertices at GfxPool + 0x185E8 in both pools (eight per entry).
#ifdef NON_MATCHING
// D_800D9640[i] is strength-reduced (a pointer += 4) where the original indexes it; the temp registers in the vertex
// loop are numbered two higher. Score 530.
void func_8007FD80(void) {
    s32 i;
    s32 j;
    Vtx* v;

    for (i = 0; i < 16; i++) {
        D_801C3B90[i].unk0 = D_800D9640[i][0];
        D_801C3B90[i].unk4 = D_800D9640[i][1];
        D_801C3B90[i].unk8 = SysUtils_Rand() & 0xFFF;
    }
    for (j = 1; j >= 0; j--) {
        if (i) {} // FAKE: keeps i live after the first loop, as the original
        // GfxPool + 0x185E8 (16 * 8 vertices; func_8007FFA8 also addresses them there)
        v = D_8011F8E8[j].unk170D8 + 0x151;
        for (i = 0; i < 16; i++, v += 8) {
            v[0].v.tc[0] = v[3].v.tc[0] = v[5].v.tc[0] = v[0].v.tc[1] = v[1].v.tc[1] = v[2].v.tc[1] = 0;
            v[1].v.tc[0] = v[6].v.tc[0] = 0x7E0;
            v[2].v.tc[0] = v[4].v.tc[0] = v[7].v.tc[0] = 0xFC0;
            v[3].v.tc[1] = v[4].v.tc[1] = 0x3E0;
            v[5].v.tc[1] = v[6].v.tc[1] = v[7].v.tc[1] = 0x7C0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_3A580/func_8007FD80.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_3A580/func_8007FFA8.s")
