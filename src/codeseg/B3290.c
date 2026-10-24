#include "common.h"

#ifdef NON_MATCHING
// Score 11089: float register allocation; the original keeps ux, uy, uz in saved registers across the sqrtf calls and spills the cross product through the stack.
void func_801E4C60(Mtx* mtx, f32 fx, f32 fy, f32 fz, f32 ux, f32 uy, f32 uz, f32 arg7, f32 arg8, f32 arg9,
                   f32 arg10) {
    f32 scale;
    f32 xx;
    f32 xy;
    f32 xz;
    f32 yx;
    f32 yy;
    f32 yz;
    f32 len;
    s32 a;
    s32 b;
    s32 c;

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
    c = fz * scale;
    mtx->m[1][1] = c & 0xFFFF0000;
    mtx->m[3][1] = c << 16;

    xx = uy * fz - uz * fy;
    xy = uz * fx - ux * fz;
    xz = ux * fy - uy * fx;
    len = xx * xx + xy * xy + xz * xz;
    if (len != 0.0) {
        len = scale / sqrtf(len);
        a = xx * len;
        b = xy * len;
        mtx->m[0][0] = (a & 0xFFFF0000) | ((u32) b >> 16);
        mtx->m[2][0] = (a << 16) | (b & 0xFFFF);
        c = xz * len;
        mtx->m[0][1] = c & 0xFFFF0000;
        mtx->m[2][1] = c << 16;

        yx = fy * xz - fz * xy;
        yy = fz * xx - fx * xz;
        yz = fx * xy - fy * xx;
        len = 1.0 / sqrtf(yx * yx + yy * yy + yz * yz);
        a = yx * len * scale;
        b = yy * len * scale;
        c = yz * len * scale;
        mtx->m[0][2] = (a & 0xFFFF0000) | ((u32) b >> 16);
        mtx->m[0][3] = c & 0xFFFF0000;
        mtx->m[2][2] = (a << 16) | (b & 0xFFFF);
        mtx->m[2][3] = c << 16;

        a = 65536.0f * arg7;
        b = 65536.0f * arg8;
        mtx->m[1][2] = (a & 0xFFFF0000) | ((u32) b >> 16);
        mtx->m[3][2] = (a << 16) | (b & 0xFFFF);
        c = 65536.0f * arg9;
        mtx->m[1][3] = (c & 0xFFFF0000) | 1;
        mtx->m[3][3] = c << 16;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4C60.s")
#endif

#ifdef NON_MATCHING
// Score 2885: &D_80228920 is kept in a register for the load and the store (the original reloads arg2 and uses at), which shifts the temps.
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
    AnimKey* key;
    UnkStruct_80227A60* dl;
    Mtx* m1;
    Mtx* m2;

    if (arg2 != D_80228920) {
        D_80226C30 = 0;
    }
    anim = D_802238DC[arg2];
    D_80228920 = arg2;

    key = &anim->keys[anim->parts[15][D_80226C30]];
    func_801E4C60(mtx, key->fx, key->fy, key->fz, key->ux, key->uy, key->uz, key->x, key->y, key->z, 1.0f);
    gSPMatrix(gdl++, (u32) mtx & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    if (D_801CE638 == 0x15) {
        dl = &D_80227A60[arg1];
        gSPDisplayList(gdl++, D_801CE9A0[arg1]);
    } else {
        dl = &D_80227A60[arg1];
        gSPDisplayList(gdl++, dl->unk0[2]);
    }
    // FAKE: gSPPopMatrix written out; each macro's block variable takes a stack slot (frame 0x88, not 0x80)
    gdl->words.w0 = 0xBD000000;
    gdl->words.w1 = 0;
    gdl++;

    key = &anim->keys[anim->parts[16][D_80226C30]];
    m1 = mtx + 1;
    func_801E4C60(m1, key->fx, key->fy, key->fz, key->ux, key->uy, key->uz, key->x, key->y, key->z, 1.0f);
    gSPMatrix(gdl++, (u32) m1 & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, dl->unk0[1]);
    // FAKE: gSPPopMatrix written out; each macro's block variable takes a stack slot (frame 0x88, not 0x80)
    gdl->words.w0 = 0xBD000000;
    gdl->words.w1 = 0;
    gdl++;

    key = &anim->keys[anim->parts[17][D_80226C30]];
    m2 = mtx + 2;
    func_801E4C60(m2, key->fx, key->fy, key->fz, key->ux, key->uy, key->uz, key->x, key->y, key->z, 1.0f);
    gSPMatrix(gdl++, (u32) m2 & 0x1FFFFFFF, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, dl->unk0[0]);
    // FAKE: gSPPopMatrix written out; each macro's block variable takes a stack slot (frame 0x88, not 0x80)
    gdl->words.w0 = 0xBD000000;
    gdl->words.w1 = 0;
    gdl++;
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4FE8.s")
#endif
