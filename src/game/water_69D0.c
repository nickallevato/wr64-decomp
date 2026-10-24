#include "global.h"

#define TWO_OVER_SQRT_3 1.1547005f
#define DIRLIGHT_DIRECTION (0.57735026f)

typedef struct UnkStruct_80162420_s {
    s16 unk0;
    s16 unk2;
} UnkStruct_80162420;

extern UnkStruct_80162420 D_80162420[];

/*
 * The field entry for lattice cell (cu, cv): 384 rows of 128, the row taking the high bits of cu.
 * The byte offset is added to the address as an integer; indexing the array instead makes IDO
 * scale the row and the column separately, which the original does not do.
 */
#define WATER_CELL(cu, cv) \
    ((UnkStruct_80162420*) ((s32) D_80162420 + (((((cv) + ((cu) & ~0x7F) + 0x600) % 384) * 128) + ((cu) & 0x7F)) * 4))

/* 0x1C bytes per view; func_80050F8C writes the window centre here */
typedef struct UnkStruct_80192420_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
} UnkStruct_80192420; /* size = 0x1C */

/* the window's cell offsets, 2 bytes a cell */
typedef struct UnkStruct_80160430_s {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
} UnkStruct_80160430;

/* 8 bytes a cell: the cell's field offset, and its x and z offsets from the window centre */
typedef struct UnkStruct_80160A98_s {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
} UnkStruct_80160A98;

extern UnkStruct_80160430 D_80160430[];
extern UnkStruct_80160A98 D_80160A98[];
extern s32 D_80192498; /* the window radius, N << 6 */

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C1D0.s")

extern f32 D_800D4768;
extern s32 D_800D476C;
extern s32 D_800D4770;
extern s32 D_800D4774;
extern s32 D_800D4778;
extern f32 D_800D477C;
extern s32 D_80192460[];
extern f32 D_801924B4;
extern f32 D_801924C0;
extern f32 D_801924CC;
extern f32 D_801924D0;
extern s32 D_80223934;

#ifdef NON_MATCHING
// 20/18500: the D_800D4774 load and the last tc add use other temp registers ($t0/$t4 for $t8/$t3); everything else matches
void func_8004C998(s32 view, Vtx* skirt) {
    camera_unk_1* cam;
    Vtx* arena;
    s32* idx;
    s32 i;
    f32 t;
    f32 h;
    f32 r;
    Vtx* vp;

    if (view != 0) {
        arena = gGfxPool->unk170D8;
        cam = &gCameraPerspective[D_80223934];
    } else {
        arena = gGfxPool->unk13D68;
        cam = &gCameraPerspective[D_80223930];
    }
    D_801924CC = D_801924B4 / (f32) (D_800D476C << 10);
    D_801924D0 = D_801924C0 / (f32) (D_800D4770 << 13);
    h = (f32) gWaterLevel - cam->unk50;
    if (h == 0.0f) {
        t = 1.0f;
    } else {
        t = (D_800D4768 - cam->unk50) / h;
    }
    for (i = 6, idx = &D_80192460[6]; i >= 0; i--, idx--) {
        vp = &skirt[i];
        vp->v.ob[0] = arena[*idx].v.ob[0];
        vp->v.ob[1] = gWaterLevel;
        vp->v.ob[2] = arena[*idx].v.ob[2];
        if (i == 0) {
            r = D_80192498 * D_800D477C;
            vp->v.ob[0] -= (s32) (r * cam->unkF0);
            vp->v.ob[2] -= (s32) (r * cam->unkF4);
        }
        // FAKE: the (u16) cast brings the score from 50 to 20
        vp->v.tc[1] = (u16) SysUtils_Round(((((f32) vp->v.ob[0] - cam->unk4C) * t) + cam->unk4C) / D_801924CC) + D_800D4774;
        vp->v.tc[0] = SysUtils_Round(((((f32) vp->v.ob[2] - cam->unk54) * t) + cam->unk54) / D_801924D0) + D_800D4778;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C998.s")
#endif

/* a wave generator stamped as rows of lines (the arg of func_8004CC7C) */
typedef struct UnkStruct_8004CC7C_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
} UnkStruct_8004CC7C; /* size = 0x3C */

void func_8004CC7C(UnkStruct_8004CC7C* arg0) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;
    s32 h;
    s32 i;
    s32 j;
    s32 phase;
    s32 period;
    s32 start;
    s32 end;
    s32 step;
    f32 x;
    f32 z;
    f32 px;
    f32 pz;

    if (D_801CE72C != 1) {
        period = arg0->unk30 << 11;
        start = arg0->unk34 << 11;
        end = arg0->unk38 << 11;
        arg0->unk28 -= arg0->unk2C * 4;
        if (arg0->unk28 < 0) {
            arg0->unk28 += period;
        }
        phase = arg0->unk28;
        step = arg0->unk24 * 4;
        x = arg0->unk0;
        z = arg0->unk4;
        for (i = 0; i < arg0->unk20; i++) {
            phase += step;
            if (phase >= period) {
                phase -= period;
            }
            if ((phase >= start) && (end >= phase)) {
                px = x;
                pz = z;
                h = (s32) (SIN(phase) * arg0->unk18) << 8;
                for (j = 0; j < arg0->unk1C; j++) {
                    u = (s32) ((DIRLIGHT_DIRECTION * pz) + px) % 24576;
                    v = (s32) (TWO_OVER_SQRT_3 * pz) % 24576;
                    cv = v >> 6;
                    cu = u >> 6;
                    if ((u - (cu * 64)) < (v - (cv * 64))) {
                        p0 = WATER_CELL(cu, cv + 1);
                    } else {
                        p0 = WATER_CELL(cu + 1, cv);
                    }
                    p2 = WATER_CELL(cu, cv);
                    p1 = WATER_CELL(cu + 1, cv + 1);
                    p0->unk0 = p2->unk0 = p1->unk0 = h;
                    p0->unk2 = p2->unk2 = p1->unk2 = 0;
                    px += arg0->unk8;
                    pz += arg0->unkC;
                }
            }
            x += arg0->unk10;
            z += arg0->unk14;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D018.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D30C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D628.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004DAF0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E0A4.s")

void func_8004E548(struct UnkStruct_8004B0F8* arg0, f32 arg1) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;
    struct UnkStruct_8004B0F8_1* var_v0;

    temp_f2 = arg0->unk1C * arg0->unk40 * arg0->unk18;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        var_f0 = (arg1 - var_v0->unk4);
        if (var_f0 >= 0.0f) {
            var_v0->unk1C |= 1;
            var_f0 *= arg0->unk18;
            if (temp_f2 < var_f0) {
                var_f0 = temp_f2;
            }
            var_v0->unk10 += var_f0;
        } else {
            var_v0->unk1C &= 0xFFFE;
        }
    }
    func_8004DAF0(arg0);
}

extern s32 D_80192494;

#ifdef NON_MATCHING
// 1405/29200: the first two loops; the original recomputes 2N +- i every row, IDO here strength-reduces it (registers then shift by one). The rest matches
void func_8004E614(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 len;

    n = 0;
    for (i = -D_80192494; i < 0; i++) {
        for (j = 0; j <= (D_80192494 * 2) + i; j++) {
            D_80160430[n].unk0 = -D_80192494 + j;
            D_80160430[n].unk1 = i;
            n++;
        }
    }
    for (i = 0; i <= D_80192494; i++) {
        for (j = 0; j <= (D_80192494 * 2) - i; j++) {
            D_80160430[n].unk0 = -D_80192494 + i + j;
            D_80160430[n].unk1 = i;
            n++;
        }
    }
    n = 0;
    for (i = -D_80192494; i <= D_80192494; i++) {
        len = (D_80192494 * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            if ((i % 2) == 0) {
                D_80160A98[n++].unk4 = (j - (len / 2)) * 64;
            } else {
                D_80160A98[n++].unk4 = ((j - (len / 2)) * 64) - 32;
            }
        }
    }
    n = 0;
    for (i = -D_80192494; i < 0; i++) {
        len = (D_80192494 * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            D_80160A98[n].unk6 = (((sqrtf(3.0f) * 64.0f) / 2) * i) - 0.5;
            n++;
        }
    }
    for (i = 0; i <= D_80192494; i++) {
        len = (D_80192494 * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            D_80160A98[n].unk6 = (((sqrtf(3.0f) * 64.0f) / 2) * i) + 0.5;
            n++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E614.s")
#endif

extern s32 D_800D4724;
extern s32 D_800D472C;
extern s32 D_800D4730;

/* the field entry at a byte offset (UnkStruct_80160A98.unk0) */
#define WATER_CELL_AT(off) ((UnkStruct_80162420*) ((s32) D_80162420 + (off)))

/*
 * One step of the wave simulation over the window's cells (see the recomp's GAME-INTERNALS.md,
 * "Entry + 2 is a velocity"). Each neighbour pair a, b is coupled once:
 *     mean = (a.h + b.h) >> D_800D4724, diff = (b.h - a.h) >> D_800D472C,
 *     a.v += diff - mean, b.v -= diff + mean;
 * and each cell, once all its pairs are done, steps: h += v, v -= v >> D_800D4730.
 */

#ifdef NON_MATCHING
// 8175/32400: registers, and the original reloads a cell velocity after storing the cell height (here it reuses the register), so the stepping blocks are a few instructions shorter here
void func_8004EAA4(void) {
    UnkStruct_80160A98* p;
    UnkStruct_80160A98* q;
    UnkStruct_80160A98* end;
    UnkStruct_80162420* a;
    UnkStruct_80162420* b;
    s32 i;
    s32 mean;
    s32 diff;

    p = D_80160A98;
    for (i = -D_80192494; i < 0; i++) {
        q = p + ((D_80192494 * 2) + i + 2);
        a = WATER_CELL_AT(p->unk0);
        b = WATER_CELL_AT(q[-1].unk0);
        mean = (a->unk0 + b->unk0) >> D_800D4724;
        diff = (b->unk0 - a->unk0) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        b->unk2 = (b->unk2 - diff) - mean;
        for (end = p + ((D_80192494 * 2) + i); p < end;) {
            p++;
            b = WATER_CELL_AT(q->unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            q++;
            b->unk2 = (b->unk2 - diff) - mean;
            a = WATER_CELL_AT(p->unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b = WATER_CELL_AT(p[-1].unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b->unk0 += b->unk2;
            b->unk2 -= b->unk2 >> D_800D4730;
        }
        b = WATER_CELL_AT(q->unk0);
        p++;
        mean = (a->unk0 + b->unk0) >> D_800D4724;
        diff = (b->unk0 - a->unk0) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        a->unk0 += a->unk2;
        b->unk2 = (b->unk2 - diff) - mean;
        a->unk2 -= a->unk2 >> D_800D4730;
    }
    for (i = 0; i < D_80192494; i++) {
        a = WATER_CELL_AT(p->unk0);
        end = p + ((D_80192494 * 2) - i);
        for (q = p + (((D_80192494 * 2) - i) + 1); p < end;) {
            p++;
            b = WATER_CELL_AT(q->unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            q++;
            b->unk2 = (b->unk2 - diff) - mean;
            a = WATER_CELL_AT(p->unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b = WATER_CELL_AT(p[-1].unk0);
            mean = (a->unk0 + b->unk0) >> D_800D4724;
            diff = (b->unk0 - a->unk0) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b->unk0 += b->unk2;
            b->unk2 -= b->unk2 >> D_800D4730;
        }
        p++;
        a->unk0 += a->unk2;
        a->unk2 -= a->unk2 >> D_800D4730;
    }
    end = p + D_80192494;
    a = WATER_CELL_AT(p->unk0);
    while (p < end) {
        b = WATER_CELL_AT(p[1].unk0);
        p += 2;
        mean = (a->unk0 + b->unk0) >> D_800D4724;
        diff = (b->unk0 - a->unk0) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        a->unk0 += a->unk2;
        b->unk2 = (b->unk2 - diff) - mean;
        a->unk2 -= a->unk2 >> D_800D4730;
        a = WATER_CELL_AT(p->unk0);
        mean = (a->unk0 + b->unk0) >> D_800D4724;
        diff = (b->unk0 - a->unk0) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        b->unk2 = (b->unk2 - diff) - mean;
        b->unk0 += b->unk2;
        b->unk2 -= b->unk2 >> D_800D4730;
    }
    a->unk0 += a->unk2;
    a->unk2 -= a->unk2 >> D_800D4730;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004EAA4.s")
#endif

void func_8004EFB4(f32 x, f32 z, s32 height) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;

    u = (s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576;
    v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
    cv = v >> 6;
    cu = u >> 6;

    if ((u - (cu * 64)) < (v - (cv * 64))) {
        p0 = WATER_CELL(cu, cv + 1);
    } else {
        p0 = WATER_CELL(cu + 1, cv);
    }
    p2 = WATER_CELL(cu, cv);
    p1 = WATER_CELL(cu + 1, cv + 1);
    p0->unk0 = p2->unk0 = p1->unk0 = height << 8;
    p0->unk2 = p2->unk2 = p1->unk2 = 0;
}

extern s32 gFrameCounter;
extern u32 D_800D4680;
extern s32 D_801924E0[];

void func_8004F1EC(f32 x, f32 z, s32 height, s32 arg3) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;

    u = (s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576;
    v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
    cv = v >> 6;
    cu = u >> 6;

    if ((u - (cu * 64)) < (v - (cv * 64))) {
        p0 = WATER_CELL(cu, cv + 1);
    } else {
        p0 = WATER_CELL(cu + 1, cv);
    }
    if ((u32) (gFrameCounter - D_801924E0[arg3]) >= D_800D4680) {
        D_801924E0[arg3] = gFrameCounter;
        p1 = WATER_CELL(cu + 1, cv + 1);
        p2 = WATER_CELL(cu, cv);
        p0->unk0 = p2->unk0 = p1->unk0 = height << 8;
        p0->unk2 = p2->unk2 = p1->unk2 = 0;
    }
}

void func_8004F3D4(f32 arg0, f32 arg1, s32 arg2) {
    UnkStruct_80162420* var_v0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_hi;
    s32 temp_hi_2;

    temp_hi = (s32) ((DIRLIGHT_DIRECTION * arg1) + arg0) % 24576;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a0 = temp_hi_2 >> 6;
    temp_a1 = temp_hi >> 6;

    if ((temp_hi - (temp_a1 * 64)) < (temp_hi_2 - (temp_a0 * 64))) {
        var_v0 = D_80162420 + ((((((temp_a0 + 1) + (temp_a1 & ~0x7F) + 0x600) % 384)) * 128) + (temp_a1 & 0x7F));
    } else {
        var_v0 = D_80162420 + (((((temp_a0 + ((temp_a1 + 1) & ~0x7F) + 0x600) % 384)) * 128) + ((temp_a1 + 1) & 0x7F));
    }
    if ((arg2 * 256) < var_v0->unk0) {
        var_v0->unk0 += arg2 * 256;
        var_v0->unk2 = 0;
    }
}

void func_8004F520(f32 height, f32 x, f32 z, f32 dx, f32 dz, s32 count) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;
    s32 t; // FAKE
    s32 h;
    f32 px = x;
    f32 pz = z;

    if (count != 0) {
        h = (s32) height << 8;
        do {
            count--;
            u = (s32) ((DIRLIGHT_DIRECTION * pz) + px) % 24576;
            v = (s32) (TWO_OVER_SQRT_3 * pz) % 24576;
            t = v >> 6; // FAKE: the copy through t gives the original register choice
            cv = t;
            cu = u >> 6;
            if ((u - (cu * 64)) < (v - (cv * 64))) {
                p0 = WATER_CELL(cu, cv + 1);
            } else {
                p0 = WATER_CELL(cu + 1, cv);
            }
            p2 = WATER_CELL(cu, cv);
            p1 = WATER_CELL(cu + 1, cv + 1);
            p0->unk0 = p2->unk0 = p1->unk0 = h;
            p0->unk2 = p2->unk2 = p1->unk2 = 0;
            px += dx;
            pz += dz;
        } while (count != 0);
    }
}

#ifdef NON_MATCHING
// 285/14800: one move (the row index copied before its shift in the first loop) is missing, so the temps after it are numbered one lower; frame and stack match
void func_8004F790(s32 amplitude) {
    s32 i;
    s32 j;
    s32 bit;
    s32 sum;
    s32 k;
    u8* row;
    UnkStruct_80162420* q;
    s32 h;
    s32 rnd[6];

    for (k = 5; k >= 0; k--) {
        rnd[k] = SysUtils_Rand() & 0x7FFF;
    }
    for (i = 0; i < 0x200; i += 4) {
        for (j = 0; j < 384; j++) {
            bit = 1;
            sum = 0;
            for (k = 5; k >= 0; k--) {
                if (bit & 1) {
                    rnd[k] = SysUtils_Rand() & 0x7FFF;
                }
                bit *= 2;
                sum += rnd[k];
            }
            h = SysUtils_Round(amplitude * (((sum / 6.0f) / 16383.5f) - 1.0f)) << 8;
            // i and the row are byte offsets into the field (i steps by 4)
            q = (UnkStruct_80162420*) ((u8*) D_80162420 + (j << 9) + i);
            q->unk0 = h;
            q->unk2 = 0;
        }
    }
    for (k = 5; k >= 0; k--) {
        rnd[k] = SysUtils_Rand() & 0x7FFF;
    }
    for (j = 0; j != 384; j++) {
        row = (u8*) D_80162420 + (j << 9);
        for (i = 0; i != 0x200; i += 4) {
            bit = 1;
            sum = 0;
            for (k = 5; k >= 0; k--) {
                if (bit & 1) {
                    rnd[k] = SysUtils_Rand() & 0x7FFF;
                }
                bit *= 2;
                sum += rnd[k];
            }
            ((UnkStruct_80162420*) (row + i))->unk0 += SysUtils_Round(amplitude * (((sum / 6.0f) / 16383.5f) - 1.0f)) << 8;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F790.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F9E0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050204.s")

extern s32 D_801924A8;

/*
 * Casts the four corner rays of the camera's view onto the plane at gWaterLevel + D_800D49B0, keeps
 * the shortest forward distance (capped), and returns the point that far ahead of the camera along
 * (unkF0, unkF4), less 32 and plus 0.866 of the window radius, in *x and *z.
 */

#ifdef NON_MATCHING
// 17535/26100: float register allocation; the original keeps more of the corner products in stack slots (frame 0xC0, here 0xD0) and uses five saved FP registers, here six
void func_80050B78(camera_unk_1* cam, f32* x, f32* z) {
    s32 angle;
    f32 d;
    f32 s;
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 h;
    f32 w;
    f32 e;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 dist;
    f32 t;
    f32 upx;
    f32 upy;
    f32 upz;
    f32 lox;
    f32 loy;
    f32 loz;
    f32 hix;
    f32 hiy;
    f32 hiz;

    angle = SysUtils_Round((cam->unk88 / 720.0f) * 4096.0f);
    d = cam->unk9C;
    h = (d * SIN(angle)) / COS(angle);
    ax = cam->unk70;
    ay = cam->unk74;
    az = cam->unk78;
    bx = cam->unk64;
    by = cam->unk68;
    bz = cam->unk6C;
    cx = (ay * bz) - (az * by);
    cy = (az * bx) - (ax * bz);
    cz = (ax * by) - (ay * bx);
    e = cam->unk94;
    w = (h * 320.0f) / 240.0f;
    hix = (e + w) * cx;
    hiy = (e + w) * cy;
    hiz = (e + w) * cz;
    lox = (e - w) * cx;
    loy = (e - w) * cy;
    loz = (e - w) * cz;
    upx = d * bx;
    upy = d * by;
    upz = d * bz;
    s = (f32) (gWaterLevel + D_800D49B0) - cam->unk50;
    dist = (d * (f32) D_801924A8 * 1.732f) / 320.0f;

    e = cam->unk98 - h;
    rx = (ax * e) + upx;
    ry = (ay * e) + upy;
    rz = (az * e) + upz;
    if ((ry + hiy) < -5.0f) {
        t = (s / (ry + hiy)) * (((rx + hix) * cam->unkF0) + ((rz + hiz) * cam->unkF4));
        if (t < dist) {
            dist = t;
        }
    }
    if ((ry + loy) < -5.0f) {
        t = (s / (ry + loy)) * (((rx + lox) * cam->unkF0) + ((rz + loz) * cam->unkF4));
        if (t < dist) {
            dist = t;
        }
    }
    e = cam->unk98 + h;
    rx = (ax * e) + upx;
    ry = (ay * e) + upy;
    rz = (az * e) + upz;
    if ((ry + hiy) < -5.0f) {
        t = (s / (ry + hiy)) * (((rx + hix) * cam->unkF0) + ((rz + hiz) * cam->unkF4));
        if (t < dist) {
            dist = t;
        }
    }
    if ((ry + loy) < -5.0f) {
        t = (s / (ry + loy)) * (((rx + lox) * cam->unkF0) + ((rz + loz) * cam->unkF4));
        if (t < dist) {
            dist = t;
        }
    }
    dist = (((f32) D_80192498 * 0.866f) + dist) - 32.0f;
    *x = cam->unk4C + (dist * cam->unkF0);
    *z = cam->unk54 + (dist * cam->unkF4);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050B78.s")
#endif

extern UnkStruct_80160430 D_80160430[];
extern UnkStruct_80160A98 D_80160A98[];
extern UnkStruct_80192420 D_80192420[];
extern s32 D_8019249C;

void func_8004EAA4(void);
void func_80050204(s32 view, Vtx* vtx);

void func_80050F8C(s32 view, f32 x, f32 z) {
    UnkStruct_80192420* w;
    s32 u;
    s32 cu;
    s32 v;
    s32 cv;
    f32 fcv;
    f32 fv;
    UnkStruct_80160430* off;
    UnkStruct_80160A98* cell;
    s32 col;
    s32 row;
    s32 pad; // stack pad: puts the spill of w at sp+0x1C

    w = &D_80192420[view];
    u = (s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576;
    cu = (u + 0x20) >> 6;
    v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
    cv = (v + 0x20) >> 6;
    fcv = cv << 6;
    fv = v;
    w->unk14 = ((f32) (cu << 6) - (0.5f * fcv)) - ((f32) u - (0.5f * fv));
    w->unk0 = w->unk14 + x;
    w->unk18 = (0.8660254f * fcv) - (0.8660254f * fv);
    w->unk4 = w->unk18 + z;
    for (off = &D_80160430[D_8019249C - 1], cell = &D_80160A98[D_8019249C - 1]; off >= D_80160430; off--, cell--) {
        col = off->unk0 + (cu & 0x7F);
        // (cu >> 7) << 7 is cu & ~0x7F; the original's sra/sll needs the shifts
        row = off->unk1 + ((cv + ((cu >> 7) << 7) + 0x600) % 384);
        cell->unk0 = ((((((col & ~0x7F) + row) + 0x600) % 384) << 7) + (col & 0x7F)) * 4;
    }
    if (gRiderGameModes != PAUSE_MODE) {
        func_8004EAA4();
    }
    if (w == D_80192420) {
        func_80050204(0, gGfxPool->unk13D68);
    } else {
        func_80050204(1, gGfxPool->unk170D8);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80051238.s")
