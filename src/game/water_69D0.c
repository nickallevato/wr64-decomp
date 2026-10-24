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

extern f32 D_800D4738;
extern f32 D_800D473C;
extern f32 D_800D4740;
extern f32 D_800D4744;
extern s32 D_800D4748;
extern s32 D_800D474C;
extern f32 D_800D4750;
extern s32 D_800D4754;
extern s32 D_800D4758;
extern s32 D_800D475C;
extern s32 D_800D4760;
extern f32 D_800D4764;
extern f32 D_801924B4;
extern f32 D_801924C0;
extern f32 D_801924C4;
extern f32 D_801924C8;
extern s32 D_80223934;

/*
 * Seven vertices at height D_800D4740 around a point ahead of the camera, found as in
 * func_80050B78 from the view's corner rays: alpha from the distance to the camera, and texture
 * coordinates projected towards the camera height and scrolled by D_800D475C/D_800D4760.
 */

#ifdef NON_MATCHING
// 21445/49800: float register allocation and stack layout (frame 0x108 here, 0xF0 in the original), as in func_80050B78
void func_8004C1D0(s32 view, Vtx* vtx) {
    camera_unk_1* cam;
    s32 angle;
    s32 i;
    f32 d;
    f32 h;
    f32 hv;
    f32 w;
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
    f32 e;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 dist;
    f32 r;
    f32 upx;
    f32 upy;
    f32 upz;
    f32 lox;
    f32 loy;
    f32 loz;
    f32 hix;
    f32 hiy;
    f32 hiz;
    f32 px;
    f32 pz;
    f32 k;
    f32 a;
    Vtx* vp;

    if (view != 0) {
        cam = &gCameraPerspective[D_80223934];
    } else {
        cam = &gCameraPerspective[D_80223930];
    }
    angle = SysUtils_Round((cam->unk88 / 720.0f) * 4096.0f);
    d = cam->unk9C;
    h = (d * SIN(angle)) / COS(angle);
    hv = h;
    w = (h * 320.0f) / 240.0f;
    if (gPlayers == TWO_PLAYERS) {
        hv = h;
        if (D_801CE638 == 1) {
            hv = h * 0.5f;
        }
    }
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
    hix = (e + w) * cx;
    hiy = (e + w) * cy;
    hiz = (e + w) * cz;
    lox = (e - w) * cx;
    loy = (e - w) * cy;
    loz = (e - w) * cz;
    upx = d * bx;
    upy = d * by;
    upz = d * bz;
    r = D_800D4744;
    s = D_800D4740 - cam->unk50;
    dist = (d * r * 1.732f) / 320.0f;

    e = cam->unk98 - hv;
    rx = (ax * e) + upx;
    ry = (ay * e) + upy;
    rz = (az * e) + upz;
    if ((ry + hiy) > 5.0f) {
        a = (s / (ry + hiy)) * (((rx + hix) * cam->unkF0) + ((rz + hiz) * cam->unkF4));
        if (a < dist) {
            dist = a;
        }
    }
    if ((ry + loy) > 5.0f) {
        a = (s / (ry + loy)) * (((rx + lox) * cam->unkF0) + ((rz + loz) * cam->unkF4));
        if (a < dist) {
            dist = a;
        }
    }
    e = cam->unk98 + hv;
    rx = (ax * e) + upx;
    ry = (ay * e) + upy;
    rz = (az * e) + upz;
    if ((ry + hiy) > 5.0f) {
        a = (s / (ry + hiy)) * (((rx + hix) * cam->unkF0) + ((rz + hiz) * cam->unkF4));
        if (a < dist) {
            dist = a;
        }
    }
    if ((ry + loy) > 5.0f) {
        a = (s / (ry + loy)) * (((rx + lox) * cam->unkF0) + ((rz + loz) * cam->unkF4));
        if (a < dist) {
            dist = a;
        }
    }
    dist = (r * 0.866f) + dist;
    px = cam->unk4C + (dist * cam->unkF0);
    pz = cam->unk54 + (dist * cam->unkF4);
    k = r * D_800D4764;

    vtx[6].v.ob[0] = SysUtils_Round(px - r);
    vtx[1].v.ob[0] = vtx[5].v.ob[0] = SysUtils_Round(px - (D_800D4744 * 0.5f));
    vtx[0].v.ob[0] = SysUtils_Round(px - (cam->unkF0 * k));
    vtx[2].v.ob[0] = vtx[4].v.ob[0] = SysUtils_Round((D_800D4744 * 0.5f) + px);
    vtx[3].v.ob[0] = SysUtils_Round(px + D_800D4744);
    vtx[0].v.ob[1] = vtx[1].v.ob[1] = vtx[2].v.ob[1] = vtx[3].v.ob[1] = vtx[4].v.ob[1] = vtx[5].v.ob[1] =
        vtx[6].v.ob[1] = SysUtils_Round(D_800D4740);
    vtx[2].v.ob[2] = vtx[1].v.ob[2] = SysUtils_Round(pz - (D_800D4744 * 0.866f));
    vtx[0].v.ob[2] = SysUtils_Round(pz - (cam->unkF4 * k));
    vtx[3].v.ob[2] = vtx[6].v.ob[2] = SysUtils_Round(pz);
    vtx[4].v.ob[2] = vtx[5].v.ob[2] = SysUtils_Round((D_800D4744 * 0.866f) + pz);

    if (gCourseID == DOLPHIN_PARK) {
        D_800D475C = D_800D4760 = 0;
    } else if (D_801CE638 == 21) {
        D_800D475C = 0x708;
        D_800D4760 = 0x76C;
    } else {
        D_800D475C = (D_800D475C + D_800D4748) & 0xFFF;
        D_800D4760 = (D_800D4760 + D_800D474C) & 0x7FF;
    }
    D_801924C4 = D_801924B4 / (f32) (D_800D4754 << 12);
    D_801924C8 = D_801924C0 / (f32) (D_800D4758 << 11);
    s = D_800D4740 - cam->unk50;
    if (s == 0.0f) {
        k = 1.0f;
    } else {
        k = (D_800D4750 - cam->unk50) / s;
    }
    for (i = 6; i >= 0; i--) {
        vp = &vtx[i];
        px = vp->v.ob[0] - cam->unk4C;
        pz = vp->v.ob[2] - cam->unk54;
        a = (sqrtf((px * px) + (pz * pz)) * D_800D4738) + D_800D473C;
        if (a < 0.5f) {
            vp->v.cn[3] = 0;
        } else if (a > 254.5f) {
            vp->v.cn[3] = 255;
        } else {
            vp->v.cn[3] = a + 0.5f;
        }
        vp->v.tc[0] = SysUtils_Round((cam->unk4C + (k * px)) / D_801924C4) + D_800D475C;
        vp->v.tc[1] = SysUtils_Round((cam->unk54 + (k * pz)) / D_801924C8) + D_800D4760;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C1D0.s")
#endif

extern f32 D_800D4768;
extern s32 D_800D476C;
extern s32 D_800D4770;
extern s32 D_800D4774;
extern s32 D_800D4778;
extern f32 D_800D477C;
extern s32 D_80192460[];
extern f32 D_801924CC;
extern f32 D_801924D0;

/*
 * The seven skirt vertices: copies of the arena vertices D_80192460[0..6] at the water level, with
 * vertex 0 moved back along the camera direction by D_80192498 * D_800D477C, and texture
 * coordinates projected towards height D_800D4768 and offset by D_800D4774/D_800D4778.
 */
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
        // FAKE: the masks are no-ops on the 16-bit stores (maybe a real wrap); without them two
        // temp registers differ
        vp->v.tc[1] = (SysUtils_Round(((((f32) vp->v.ob[0] - cam->unk4C) * t) + cam->unk4C) / D_801924CC) + D_800D4774) & 0xFFFF;
        vp->v.tc[0] = (SysUtils_Round(((((f32) vp->v.ob[2] - cam->unk54) * t) + cam->unk54) / D_801924D0) + D_800D4778) & 0xFFFF;
    }
}

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

extern s32 D_800D47C0;

/*
 * Stamps sin(phase * 4096 / period) * amplitude along the diagonal from (x - r, z - r) to
 * (x + r, z + r) in steps of 64, with r = D_80192498 / 4. The phase, D_800D47C0, advances by step
 * on each call and wraps at period.
 */
void func_8004D018(f32 x, f32 z, s32 amplitude, s32 period, s32 step) {
    s32* pp = &D_800D47C0; // FAKE: through a pointer, the global gets its own lui at each access
    s32 t;                 // FAKE
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;
    s32 phase;
    s32 h;
    f32 end;

    phase = *pp;
    phase += step;
    if (phase >= period) {
        phase -= period;
    }
    amplitude = (s32) (SIN((phase << 12) / period) * amplitude) << 8; // FAKE: h computed in amplitude
    *pp = phase;
    h = amplitude;
    // the radius is not a local: as one, it takes the original's register for end
    end = (D_80192498 >> 2) + x;
    x -= D_80192498 >> 2;
    z -= D_80192498 >> 2;
    while (x <= end) {
        u = (s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576;
        v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
        t = v >> 6; // FAKE: the copy through t gives the original register choice, as in func_8004F520
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
        x += 64.0f;
        z += 64.0f;
    }
}

#ifdef NON_MATCHING
// 24/19900: only the spill slots of du and dv differ (0x2C/0x18 here, 0x24/0x1C in the original).
// CU and CV are macros so that IDO keeps them as common subexpressions: as named locals they add
// stack slots
#define CU (((s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576) >> 6)
#define CV (((s32) (TWO_OVER_SQRT_3 * z) % 24576) >> 6)
f32 func_8004D30C(f32 x, f32 z) {
    s32 du;
    s32 h00;
    s32 dv;
    s32 d0;
    s32 d1;

    du = (CU << 6) - ((s32) ((DIRLIGHT_DIRECTION * z) + x) % 24576);
    h00 = WATER_CELL(CU, CV)->unk0 >> 8;
    dv = (CV << 6) - ((s32) (TWO_OVER_SQRT_3 * z) % 24576);
    if (dv < du) {
        d0 = WATER_CELL(CU, CV + 1)->unk0 >> 8;
        d1 = h00 - d0;
        d0 -= WATER_CELL(CU + 1, CV + 1)->unk0 >> 8;
    } else {
        d1 = WATER_CELL(CU + 1, CV)->unk0 >> 8;
        d0 = h00 - d1;
        d1 -= WATER_CELL(CU + 1, CV + 1)->unk0 >> 8;
    }
    return (f32) ((d0 * du) + ((gWaterLevel + h00) << 12) + (d1 * dv)) /
           sqrtf((f32) (((d0 * d0) + (d1 * d1) + 0x1000) << 12));
}
#undef CU
#undef CV
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D30C.s")
#endif

#ifdef NON_MATCHING
// 9125/30600: register allocation (saved-register numbering from the first block on; the original also orders some float multiplies the other way). Same operations as func_8004E0A4
void func_8004D628(struct UnkStruct_8004B0F8* arg0) {
    f32 max;
    f32 inv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 depth;
    struct UnkStruct_8004B0F8_1* var_v0;
    s32 v;
    s32 cv;
    s32 u;
    s32 cu;
    s32 h00;
    s32 h;
    s32 fu;
    s32 fv;
    s32 d0;
    s32 d1;

    max = arg0->unk1C * arg0->unk40 * arg0->unk18;
    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        u = (s32) ((DIRLIGHT_DIRECTION * var_v0->unk8) + var_v0->unk0) % 24576;
        cu = u >> 6;
        v = (s32) (TWO_OVER_SQRT_3 * var_v0->unk8) % 24576;
        cv = v >> 6;
        h00 = WATER_CELL(cu, cv)->unk0 >> 8;
        fu = (cu << 6) - u;
        fv = (cv << 6) - v;
        if (fv < fu) {
            h = WATER_CELL(cu, cv + 1)->unk0 >> 8;
            d1 = h00 - h;
            d0 = h - (WATER_CELL(cu + 1, cv + 1)->unk0 >> 8);
        } else {
            h = WATER_CELL(cu + 1, cv)->unk0 >> 8;
            d0 = h00 - h;
            d1 = h - (WATER_CELL(cu + 1, cv + 1)->unk0 >> 8);
        }
        inv = 1.0f / sqrtf((f32) (((d0 * d0) + (d1 * d1) + 0x1000) << 12));
        nx = d0 * inv;
        ny = 4096.0f * inv;
        nz = d1 * inv;
        depth = (fu * nx) + (ny * ((f32) (gWaterLevel + h00) - var_v0->unk4)) + (nz * fv);
        if (depth >= 0.0f) {
            var_v0->unk1C |= 1;
            var_v0->unkC *= arg0->unk14;
            var_v0->unk10 *= arg0->unk10;
            var_v0->unk14 *= arg0->unk14;
            depth *= arg0->unk18;
            if (max < depth) {
                depth = max;
            }
            var_v0->unkC += depth * (nx - (0.5f * nz));
            var_v0->unk10 += depth * ny;
            var_v0->unk14 += depth * (0.8660254f * nz);
        } else {
            var_v0->unk1C &= 0xFFFE;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D628.s")
#endif

/*
 * For each of a body's points touching the water (unk1C bit 0), keeps the part of its (unkC, unk14)
 * velocity along the unit (unk6C, unk74) direction and scales the rest by unk14, and scales unk10
 * by unk10. Points 0/2, 3/5, 6/7 and 9/10 are tested in pairs.
 */
#define WATER_DAMP_POINT(pt)                                                  \
    vx = (pt)->unkC;                                                          \
    vz = (pt)->unk14;                                                         \
    d = (vx * dx) + (vz * dz);                                                \
    (pt)->unkC = (d * dx * k) + (body->unk14 * vx);                           \
    (pt)->unk10 *= body->unk10;                                               \
    (pt)->unk14 = (d * dz * k) + (body->unk14 * vz);

#ifdef NON_MATCHING
// 3191/36500: the original keeps 1.0f in $fs0 across sqrtf (frame 0x40 with $fs0/$fs1 saved; 0x20 here), so the float registers differ throughout; the per-point blocks match in shape
void func_8004DAF0(void* arg0) {
    UnkStruct_80192690* body = arg0;
    UnkStruct_8004B0F8_1* pt2;
    f32 dz;
    UnkStruct_8004B0F8_1* pt;
    f32 vz;
    f32 len;
    f32 inv;
    f32 d;
    f32 k;
    f32 dx;
    f32 vx;

    dx = body->unk6C;
    dz = body->unk74;
    k = 1.0f - body->unk14;
    len = (dx * dx) + (dz * dz);
    if (len == 0.0f) {
        dx = 0.0f;
        dz = 0.0f;
    } else {
        inv = 1.0f / sqrtf(len);
        dx = body->unk6C * inv;
        dz = body->unk74 * inv;
    }
    pt = &body->unk30[1];
    if (pt->unk1C & 1) {
        WATER_DAMP_POINT(pt);
    }
    pt = &body->unk30[4];
    if (pt->unk1C & 1) {
        WATER_DAMP_POINT(pt);
    }
    pt = &body->unk30[8];
    if (pt->unk1C & 1) {
        WATER_DAMP_POINT(pt);
    }
    pt = &body->unk30[11];
    if (pt->unk1C & 1) {
        WATER_DAMP_POINT(pt);
    }
    pt = &body->unk30[3];
    pt2 = &body->unk30[5];
    if ((pt->unk1C | pt2->unk1C) & 1) {
        WATER_DAMP_POINT(pt);
        WATER_DAMP_POINT(pt2);
    }
    pt = &body->unk30[6];
    pt2 = &body->unk30[7];
    if ((pt->unk1C | pt2->unk1C) & 1) {
        WATER_DAMP_POINT(pt);
        WATER_DAMP_POINT(pt2);
    }
    pt = &body->unk30[9];
    pt2 = &body->unk30[10];
    if ((pt->unk1C | pt2->unk1C) & 1) {
        WATER_DAMP_POINT(pt);
        WATER_DAMP_POINT(pt2);
    }
    pt2 = &body->unk30[2];
    if ((body->unk30[0].unk1C | pt2->unk1C) & 1) {
        body->unk30[0].unk10 *= body->unk10;
        pt2->unk10 *= body->unk10;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004DAF0.s")
#endif

#ifdef NON_MATCHING
// 9025/29700: register allocation; the original keeps arg0 in $t3 and reloads it from the stack after sqrtf, keeps the four integer corner values in saved registers and 1.0f/4096.0f in $fs4/$fs5
void func_8004E0A4(struct UnkStruct_8004B0F8* arg0, f32 arg1) {
    f32 max;
    f32 inv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 depth;
    struct UnkStruct_8004B0F8_1* var_v0;
    s32 v;
    s32 cv;
    s32 u;
    s32 cu;
    s32 h00;
    s32 h;
    s32 fu;
    s32 fv;
    s32 d0;
    s32 d1;

    max = arg0->unk1C * arg0->unk40 * arg0->unk18;
    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        u = (s32) ((DIRLIGHT_DIRECTION * var_v0->unk8) + var_v0->unk0) % 24576;
        cu = u >> 6;
        v = (s32) (TWO_OVER_SQRT_3 * var_v0->unk8) % 24576;
        cv = v >> 6;
        h00 = WATER_CELL(cu, cv)->unk0 >> 8;
        fu = (cu << 6) - u;
        fv = (cv << 6) - v;
        if (fv < fu) {
            h = WATER_CELL(cu, cv + 1)->unk0 >> 8;
            d1 = h00 - h;
            d0 = h - (WATER_CELL(cu + 1, cv + 1)->unk0 >> 8);
        } else {
            h = WATER_CELL(cu + 1, cv)->unk0 >> 8;
            d0 = h00 - h;
            d1 = h - (WATER_CELL(cu + 1, cv + 1)->unk0 >> 8);
        }
        inv = 1.0f / sqrtf((f32) (((d0 * d0) + (d1 * d1) + 0x1000) << 12));
        nx = d0 * inv;
        ny = 4096.0f * inv;
        nz = d1 * inv;
        depth = (fu * nx) + (ny * ((arg1 + h00) - var_v0->unk4)) + (nz * fv);
        if (depth >= 0.0f) {
            var_v0->unk1C |= 1;
            depth *= arg0->unk18;
            if (max < depth) {
                depth = max;
            }
            var_v0->unkC += depth * (nx - (0.5f * nz));
            var_v0->unk10 += depth * ny;
            var_v0->unk14 += depth * (0.8660254f * nz);
        } else {
            var_v0->unk1C &= 0xFFFE;
        }
    }
    func_8004DAF0(arg0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E0A4.s")
#endif

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

void func_8004E614(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 len;

    n = 0;
    for (i = -D_80192494; i < 0; i++) {
        len = D_80192494 * 2;
        for (j = 0; j <= len + i; j++) {
            D_80160430[n].unk0 = -D_80192494 + j;
            D_80160430[n].unk1 = i;
            n++;
        }
    }
    for (i = 0; i <= D_80192494; i++) {
        len = D_80192494 * 2;
        for (j = 0; j <= len - i; j++) {
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

/*
 * Fills the field with noise: each cell's height is the sum of six random values (the first redrawn
 * for each cell), scaled to +-amplitude: first column by column (velocity 0), then added again row
 * by row.
 */
void func_8004F790(s32 amplitude) {
    s32 i;
    s32 j;
    s32 bit;
    s32 sum;
    s32 k;
    u8* row;
    UnkStruct_80162420* q;
    s32 rnd[6];
    s32 h;

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
            // i and the row are byte offsets into the field (i steps by 4); the row is written as
            // (j << 7) << 2 (128 cells of 4 bytes): j << 9 compiles differently
            q = (UnkStruct_80162420*) ((u8*) D_80162420 + ((j << 7) << 2) + i);
            q->unk0 = h;
            q->unk2 = 0;
        }
    }
    for (k = 5; k >= 0; k--) {
        rnd[k] = SysUtils_Rand() & 0x7FFF;
    }
    for (j = 0; j != 384; j++) {
        row = (u8*) D_80162420 + ((j << 7) << 2);
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

extern s32 D_800D4684[];
extern UnkStruct_80192420 D_80192420[];
extern s32 D_8019249C;
extern s32 D_801924A0;
extern s32 D_801924A8;
extern s32 D_801924A4;
extern f32 D_801924AC;
extern f32 D_801924B0;
extern f32 D_801924B8;
extern f32 D_801924BC;

void func_8004E614(void);
void func_8004F790(s32 amplitude);

/*
 * Sets up the water for a scene: the simulation shifts and the window size N (16, 10 or 12), the
 * 13-word parameter set from D_800D4684, gWaterLevel, the cell lists (func_8004E614) and a random
 * field (func_8004F790); the field's wrap bounds; and, in both GfxPools, the vertex colours of the
 * window's vertices and the texture coordinate 0x400 on its boundary ring and skirt.
 */

#ifdef NON_MATCHING
// 12834/52100: registers from the start (saved registers numbered differently) and the frame (0x40 here, 0x50 in the original, which spills the two wrap counts to 0x40/0x44 across sqrtf)
void func_8004F9E0(s32 waterLevel, s32 amplitude) {
    s32 set;
    s32* src;
    s32* dst;
    s32 nu;
    s32 nv;
    GfxPool* pool;
    s32 i;
    s32 j;
    s32 k;
    s32 top;
    s32 bot;
    s32 b;
    s32 c;
    s32 d;
    s32 step;

    if (D_801CE64C == 1) {
        D_800D4724 = 10;
        D_800D472C = 4;
        D_800D4730 = 5;
        D_80192494 = 16;
        set = 0;
    } else {
        D_800D4724 = 9;
        D_800D472C = 5;
        D_800D4730 = 6;
        if ((D_801CE64C == 2) || (gPlayers == TWO_PLAYERS)) {
            D_80192494 = 10;
            set = 26;
        } else {
            D_80192494 = 12;
            set = 13;
        }
    }
    D_80192420[0].unk0 = D_80192420[0].unk4 = D_80192420[1].unk0 = D_80192420[1].unk4 = 0;
    D_80192420[1].unk18 = 0.0f;
    D_80192420[0].unk8 = D_80192420[0].unkC = D_80192420[0].unk10 = D_80192420[0].unk14 = D_80192420[0].unk18 =
        D_80192420[1].unk8 = D_80192420[1].unkC = D_80192420[1].unk10 = D_80192420[1].unk14 = D_80192420[1].unk18;
    for (src = &D_800D4684[set], dst = D_80192460; dst < &D_80192494;) {
        *dst++ = *src++;
    }
    D_801924A0 = 0x8000;
    D_801924A4 = 0x8000;
    D_801924A8 = 0x800;
    D_80192498 = D_80192494 << 6;
    D_8019249C = (D_80192494 * 3 * (D_80192494 + 1)) + 1;
    gWaterLevel = waterLevel;
    func_8004E614();
    func_8004F790(amplitude);
    nu = ((f32) ((D_801924A8 * 2) + D_801924A0) / 49152.0f) + 0.9;
    nv = ((f32) (D_801924A4 + (D_801924A8 * 2)) / (sqrtf(3.0f) * 2.0f * 8192.0f)) + 0.9;
    D_801924AC = (nu * 0x6000) - 1.0;
    D_801924B0 = -nu * 0x6000;
    D_801924B8 = (sqrtf(3.0f) * nv * 8192.0f) - 1.0;
    D_801924BC = sqrtf(3.0f) * -nv * 8192.0f;
    D_801924B4 = (D_801924AC - D_801924B0) + 1.0;
    D_801924C0 = (D_801924B8 - D_801924BC) + 1.0;
    for (pool = &D_8011F8E8[1]; pool >= D_8011F8E8; pool--) {
        for (i = D_8019249C + 5; i >= 0; i--) {
            pool->unk13D68[i].v.cn[0] = 0xFF;
            pool->unk13D68[i].v.cn[1] = 0xFF;
            pool->unk13D68[i].v.cn[2] = 0xFF;
            pool->unk13D68[i].v.cn[3] = 0xB0;
        }
        if (gPlayers == TWO_PLAYERS) {
            for (i = D_8019249C + 5; i >= 0; i--) {
                pool->unk170D8[i].v.cn[0] = 0xFF;
                pool->unk170D8[i].v.cn[1] = 0xFF;
                pool->unk170D8[i].v.cn[2] = 0xFF;
                pool->unk170D8[i].v.cn[3] = 0xB0;
            }
        }
        top = D_80192494;
        bot = D_8019249C - D_80192494;
        c = bot - 1;
        d = bot - 2;
        b = top + 1;
        step = top + 2;
        for (j = D_80192494 - 1, k = D_8019249C - 1; j >= 0; j--, k--) {
            pool->unk13D68[j].v.tc[1] = pool->unk13D68[j].v.tc[0] = pool->unk13D68[b].v.tc[1] = pool->unk13D68[b].v.tc[0] =
                pool->unk13D68[top].v.tc[1] = pool->unk13D68[top].v.tc[0] = pool->unk13D68[c].v.tc[0] =
                    pool->unk13D68[c].v.tc[1] = pool->unk13D68[d].v.tc[1] = pool->unk13D68[d].v.tc[0] =
                        pool->unk13D68[k].v.tc[0] = pool->unk13D68[k].v.tc[1] = 0x400;
            b += step;
            top += step;
            c -= step;
            d -= step;
            step++;
        }
        pool->unk13D68[D_80192460[1]].v.tc[0] = pool->unk13D68[D_80192460[1]].v.tc[1] =
            pool->unk13D68[D_80192460[2]].v.tc[0] = pool->unk13D68[D_80192460[2]].v.tc[1] =
                pool->unk13D68[D_80192460[3]].v.tc[0] = pool->unk13D68[D_80192460[3]].v.tc[1] =
                    pool->unk13D68[D_80192460[4]].v.tc[0] = pool->unk13D68[D_80192460[4]].v.tc[1] =
                        pool->unk13D68[D_80192460[5]].v.tc[0] = pool->unk13D68[D_80192460[5]].v.tc[1] =
                            pool->unk13D68[D_80192460[6]].v.tc[0] = pool->unk13D68[D_80192460[6]].v.tc[1] = 0x400;
        if (gPlayers == TWO_PLAYERS) {
            top = D_80192494;
            bot = D_8019249C - D_80192494;
            c = bot - 1;
            d = bot - 2;
            b = top + 1;
            step = top + 2;
            for (j = D_80192494 - 1, k = D_8019249C - 1; j >= 0; j--, k--) {
                pool->unk170D8[j].v.tc[1] = pool->unk170D8[j].v.tc[0] = pool->unk170D8[b].v.tc[1] = pool->unk170D8[b].v.tc[0] =
                    pool->unk170D8[top].v.tc[1] = pool->unk170D8[top].v.tc[0] = pool->unk170D8[c].v.tc[0] =
                        pool->unk170D8[c].v.tc[1] = pool->unk170D8[d].v.tc[1] = pool->unk170D8[d].v.tc[0] =
                            pool->unk170D8[k].v.tc[0] = pool->unk170D8[k].v.tc[1] = 0x400;
                b += step;
                top += step;
                c -= step;
                d -= step;
                step++;
            }
            pool->unk170D8[D_80192460[1]].v.tc[0] = pool->unk170D8[D_80192460[1]].v.tc[1] =
                pool->unk170D8[D_80192460[2]].v.tc[0] = pool->unk170D8[D_80192460[2]].v.tc[1] =
                    pool->unk170D8[D_80192460[3]].v.tc[0] = pool->unk170D8[D_80192460[3]].v.tc[1] =
                        pool->unk170D8[D_80192460[4]].v.tc[0] = pool->unk170D8[D_80192460[4]].v.tc[1] =
                            pool->unk170D8[D_80192460[5]].v.tc[0] = pool->unk170D8[D_80192460[5]].v.tc[1] =
                                pool->unk170D8[D_80192460[6]].v.tc[0] = pool->unk170D8[D_80192460[6]].v.tc[1] = 0x400;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F9E0.s")
#endif

extern s32 D_800D4720;

/*
 * Fills a view's vertex arena from the window's cells, row by row: x and z from the window centre
 * plus each cell's offsets; on the boundary y is gWaterLevel, inside it is the field height (>> 8)
 * plus gWaterLevel and the texture coordinates come from the slopes to the neighbouring rows.
 * Then places the six skirt vertices out at D_800D4720 and stores the window's centre and
 * D_800D4720 squared in D_80192420[view].
 */

#ifdef NON_MATCHING
// 26108/60500: registers and stack (frame 0x90 here, 0x78 in the original) throughout; the row loops follow the original control flow
void func_80050204(s32 view, Vtx* arena) {
    UnkStruct_80192420* w;
    UnkStruct_80160A98* e;
    UnkStruct_80160A98* end;
    Vtx* vtx;
    Vtx* c;
    Vtx* v;
    s32* idx;
    s32 i;
    s32 hA;
    s32 hB;
    s32 sx;
    s32 sz;
    s32 ox;
    s32 oz;
    f32 k;
    f32 dx;
    f32 dz;

    e = D_80160A98;
    vtx = arena;
    w = &D_80192420[view];
    for (end = &D_80160A98[D_80192494]; end >= e;) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
    }
    for (i = 1 - D_80192494; i < 0; i++) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
        for (end = e + ((D_80192494 * 2) + i - 2); end >= e;) {
            hA = WATER_CELL_AT((e + (-((D_80192494 * 2) + i + 1)))->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT((e + ((D_80192494 * 2) + i + 1))->unk0)->unk0 >> 7;
            sx = (((hA + hB) >> 1) - (WATER_CELL_AT(e[1].unk0)->unk0 >> 7)) << 6;
            sz = (hA - hB) * 55;
            k = 992.0f / sqrtf((sx * sx) + (sz * sz) + 0xC00000);
            e++;
            vtx++;
            vtx[-1].v.tc[0] = (s32) (sx * k) + 0x400;
            vtx[-1].v.tc[1] = (s32) (sz * k) + 0x400;
            vtx[-1].v.ob[1] = (WATER_CELL_AT(e[-1].unk0)->unk0 >> 8) + gWaterLevel;
            vtx[-1].v.ob[0] = w->unk0 + e[-1].unk4;
            vtx[-1].v.ob[2] = e[-1].unk6 + w->unk4;
        }
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
    }
    vtx->v.ob[0] = w->unk0 + e->unk4;
    vtx->v.ob[1] = gWaterLevel;
    vtx->v.ob[2] = e->unk6 + w->unk4;
    e++;
    vtx++;
    for (end = e + ((D_80192494 * 2) - 2); end >= e;) {
            hA = WATER_CELL_AT((e + (-((D_80192494 * 2) + 1)))->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT((e + (D_80192494 * 2))->unk0)->unk0 >> 7;
            sx = (((hA + hB) >> 1) - (WATER_CELL_AT(e[1].unk0)->unk0 >> 7)) << 6;
            sz = (hA - hB) * 55;
            k = 992.0f / sqrtf((sx * sx) + (sz * sz) + 0xC00000);
            e++;
            vtx++;
            vtx[-1].v.tc[0] = (s32) (sx * k) + 0x400;
            vtx[-1].v.tc[1] = (s32) (sz * k) + 0x400;
            vtx[-1].v.ob[1] = (WATER_CELL_AT(e[-1].unk0)->unk0 >> 8) + gWaterLevel;
            vtx[-1].v.ob[0] = w->unk0 + e[-1].unk4;
            vtx[-1].v.ob[2] = e[-1].unk6 + w->unk4;
    }
    vtx->v.ob[0] = w->unk0 + e->unk4;
    vtx->v.ob[1] = gWaterLevel;
    vtx->v.ob[2] = e->unk6 + w->unk4;
    e++;
    vtx++;
    for (i = 1; i < D_80192494; i++) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
        for (end = e + ((D_80192494 * 2) - i - 2); end >= e;) {
            hA = WATER_CELL_AT((e + (-((D_80192494 * 2) - i + 2)))->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT((e + ((D_80192494 * 2) - i))->unk0)->unk0 >> 7;
            sx = (((hA + hB) >> 1) - (WATER_CELL_AT(e[1].unk0)->unk0 >> 7)) << 6;
            sz = (hA - hB) * 55;
            k = 992.0f / sqrtf((sx * sx) + (sz * sz) + 0xC00000);
            e++;
            vtx++;
            vtx[-1].v.tc[0] = (s32) (sx * k) + 0x400;
            vtx[-1].v.tc[1] = (s32) (sz * k) + 0x400;
            vtx[-1].v.ob[1] = (WATER_CELL_AT(e[-1].unk0)->unk0 >> 8) + gWaterLevel;
            vtx[-1].v.ob[0] = w->unk0 + e[-1].unk4;
            vtx[-1].v.ob[2] = e[-1].unk6 + w->unk4;
        }
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
    }
    for (end = &D_80160A98[D_8019249C - 1]; end >= e;) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
    }
    k = (f32) D_800D4720 / (f32) D_80192498;
    for (idx = &D_80192460[1]; idx < &D_80192460[7]; idx++) {
        c = &arena[D_80192460[0]];
        v = &arena[idx[6]];
        arena[*idx].v.ob[0] = c->v.ob[0] + (s32) (k * (v->v.ob[0] - c->v.ob[0]));
        arena[*idx].v.ob[2] = arena[D_80192460[0]].v.ob[2] + (s32) (k * (v->v.ob[2] - c->v.ob[2]));
        arena[*idx].v.ob[1] = gWaterLevel;
    }
    if (w != D_80192420) {
        dx = gCameraPerspective[1].unkF0;
        dz = gCameraPerspective[1].unkF4;
    } else {
        dx = gCameraPerspective[0].unkF0;
        dz = gCameraPerspective[0].unkF4;
    }
    k = (f32) (D_800D4720 - D_80192498) * 0.866f;
    ox = SysUtils_Round(k * dx);
    oz = SysUtils_Round(k * dz);
    for (idx = &D_80192460[1]; idx < &D_80192460[7]; idx++) {
        arena[*idx].v.ob[0] += ox;
        arena[*idx].v.ob[2] += oz;
    }
    w->unk8 = ((f32) (arena[D_80192460[4]].v.ob[0] + arena[D_80192460[1]].v.ob[0]) * 0.5f) - w->unk14;
    w->unkC = ((f32) (arena[D_80192460[4]].v.ob[2] + arena[D_80192460[1]].v.ob[2]) * 0.5f) - w->unk18;
    w->unk10 = D_800D4720 * D_800D4720;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050204.s")
#endif

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

extern s32 D_800D47C4;
extern s32 D_800D47C8;
extern f32 D_800D47CC;
extern f32 D_800D47D0;
extern s32 D_801C1FCC;

void func_80050B78(camera_unk_1* cam, f32* x, f32* z);

#ifdef NON_MATCHING
// 5472/18800: the frame is 0x30 here, 0x28 in the original, and the addresses of D_800D47C4 and D_800D47CC/D0 are held in registers here; the original loads each with its own lui
void func_80051238(void) {
    s32 angle;
    f32 x;
    f32 z;

    if ((gCourseID == GLACIER_COAST) && (gRiderGameModes != PAUSE_MODE) && (D_801CE638 == 1)) {
        if (D_801C1FCC == 1) {
            if (gWaterLevel >= -99) {
                gWaterLevel--;
            }
        } else if ((D_801C1FCC == 2) && (gWaterLevel >= -149)) {
            gWaterLevel--;
        }
    }
    if (D_801CE64C == 1) {
        if (D_801CE638 != 6) {
            angle = (D_800D47C4 + D_800D47C8 + 0x1000) & 0xFFF;
            D_800D47CC += 51.2 * COS(angle);
            D_800D47C4 = angle;
            D_800D47D0 += 51.2 * SIN(angle);
            if ((f32) (D_80192498 * D_80192498) < ((D_800D47CC * D_800D47CC) + (D_800D47D0 * D_800D47D0))) {
                angle = SysUtils_Rand() & 0xFFF;
                D_800D47C4 = angle;
                D_800D47CC = COS(angle) * D_80192498;
                D_800D47D0 = SIN(angle) * D_80192498;
                D_800D47C4 = SysUtils_Rand() & 0xFFF;
                D_800D47C8 = (s32) (((f32) (SysUtils_Rand() & 0x3FFF) * 14.0f) / 16383.0) - 7;
            }
            func_8004EFB4(D_800D47CC, D_800D47D0, -50);
        }
        func_80050F8C(0, 0.0f, 0.0f);
        return;
    }
    if (gPlayers == TWO_PLAYERS) {
        func_80050B78(&gCameraPerspective[1], &x, &z);
        func_80050F8C(1, x, z);
    }
    func_80050B78(gCameraPerspective, &x, &z);
    func_80050F8C(0, x, z);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80051238.s")
#endif
