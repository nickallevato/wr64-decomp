#include "common.h"

#ifdef NON_MATCHING
// Score 210 of 22600: as in guLookAtF, the second cross product is written back into ux, uy, uz. The third
// value of each block (c before) is a repeated cast, not a local; without c the spill slots match. Left: the FAKE copy m2
// takes c's stack slot back, so the spills are 4 bytes lower again; the integer temporaries of the third and last
// blocks are swapped (a2, a3, t0 here for the third, v0, v1, a1 for the last; the other way round in the original).
void func_801E4C60(Mtx* mtx, f32 fx, f32 fy, f32 fz, f32 ux, f32 uy, f32 uz, f32 arg7, f32 arg8, f32 arg9,
                   f32 arg10) {
    f32 scale;
    f32 xx;
    f32 xy;
    f32 xz;
    f32 len;
    s32 a;
    s32 b;
    Mtx* m2;

    fx /= 127.0;
    fy /= 127.0;
    fz /= 127.0;
    ux /= 127.0;
    uy /= 127.0;
    uz /= 127.0;
    scale = arg10 * 65536.0f;
    a = fx * scale;
    b = fy * scale;
    mtx->m[1][0] = (a & 0xFFFF0000) | ((u32) b >> 16);
    mtx->m[3][0] = (a << 16) | (b & 0xFFFF);
    mtx->m[1][1] = ((s32) (fz * scale)) & 0xFFFF0000;
    mtx->m[3][1] = ((s32) (fz * scale)) << 16;

    xx = uy * fz - uz * fy;
    xy = uz * fx - ux * fz;
    xz = ux * fy - uy * fx;
    len = xx * xx + xy * xy + xz * xz;
    if (len != 0.0) {
        len = scale / sqrtf(len);
        a = xx * len;
        b = xy * len;
        mtx->m[0][0] = (a & 0xFFFF0000) | ((u32) b >> 16);
        mtx->m[0][1] = ((s32) (xz * len)) & 0xFFFF0000;
        mtx->m[2][1] = ((s32) (xz * len)) << 16;
        mtx->m[2][0] = (a << 16) | (b & 0xFFFF);

        ux = fy * xz - fz * xy;
        uy = fz * xx - fx * xz;
        uz = fx * xy - fy * xx;
        len = 1.0 / sqrtf(ux * ux + uy * uy + uz * uz);
        ux *= len;
        uy *= len;
        uz *= len;
        a = ux * scale;
        b = uy * scale;
        mtx->m[0][2] = (a & 0xFFFF0000) | ((u32) b >> 16);
        mtx->m[0][3] = ((s32) (uz * scale)) & 0xFFFF0000;
        m2 = mtx; // FAKE: a copy of mtx for the last two blocks' registers
        m2->m[2][2] = (a << 16) | (b & 0xFFFF);
        m2->m[2][3] = ((s32) (uz * scale)) << 16;

        a = 65536.0f * arg7;
        b = 65536.0f * arg8;
        m2->m[1][2] = (a & 0xFFFF0000) | ((u32) b >> 16);
        m2->m[1][3] = (((s32) (65536.0f * arg9)) & 0xFFFF0000) | 1;
        m2->m[3][2] = (a << 16) | (b & 0xFFFF);
        m2->m[3][3] = ((s32) (65536.0f * arg9)) << 16;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4C60.s")
#endif

typedef struct AnimKey {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s8 fx;
    /* 0x7 */ s8 fy;
    /* 0x8 */ s8 fz;
    /* 0x9 */ s8 ux;
    /* 0xA */ s8 uy;
    /* 0xB */ s8 uz;
} AnimKey; /* size = 0xC */

typedef struct Anim {
    /* 0x00 */ s16 numFrames;
    /* 0x02 */ char pad2[2];
    /* 0x04 */ AnimKey* keys;
    /* 0x08 */ s16* parts[18]; /* per part, the key index for each frame */
} Anim; /* size = 0x50 */

extern Gfx* D_801CE9A0[];
extern Anim* D_802238DC[];
extern s32 D_80226C30;
extern UnkStruct_80227A60 D_80227A60[];
extern s32 D_80228920;

void func_801E4C60(Mtx* mtx, f32 fx, f32 fy, f32 fz, f32 ux, f32 uy, f32 uz, f32 x, f32 y, f32 z, f32 scale);

Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx) {
    Anim* anim;
    s32 id;

    // id holds the animation number here and each part's key index below: with the copy, the store to D_80228920
    // and the key loads get the original's registers
    id = arg2;
    if (id != D_80228920) {
        D_80226C30 = 0;
    }
    D_80228920 = id;
    anim = D_802238DC[arg2];

    id = anim->parts[15][D_80226C30];
    func_801E4C60(mtx, anim->keys[id].fx, anim->keys[id].fy, anim->keys[id].fz, anim->keys[id].ux, anim->keys[id].uy,
                  anim->keys[id].uz, anim->keys[id].x, anim->keys[id].y, anim->keys[id].z, 1.0f);
    gSPMatrix(gdl++, (u32) mtx & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    if (D_801CE638 == 0x15) {
        gSPDisplayList(gdl++, D_801CE9A0[arg1]);
    } else {
        gSPDisplayList(gdl++, D_80227A60[arg1].unk0[2]);
    }
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);

    id = anim->parts[16][D_80226C30];
    func_801E4C60(mtx + 1, anim->keys[id].fx, anim->keys[id].fy, anim->keys[id].fz, anim->keys[id].ux,
                  anim->keys[id].uy, anim->keys[id].uz, anim->keys[id].x, anim->keys[id].y, anim->keys[id].z, 1.0f);
    gSPMatrix(gdl++, (u32) (mtx + 1) & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[1]);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);

    id = anim->parts[17][D_80226C30];
    func_801E4C60(mtx + 2, anim->keys[id].fx, anim->keys[id].fy, anim->keys[id].fz, anim->keys[id].ux,
                  anim->keys[id].uy, anim->keys[id].uz, anim->keys[id].x, anim->keys[id].y, anim->keys[id].z, 1.0f);
    gSPMatrix(gdl++, (u32) (mtx + 2) & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[0]);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}
