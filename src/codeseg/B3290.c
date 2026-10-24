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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4FE8.s")
