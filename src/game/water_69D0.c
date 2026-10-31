#include "global.h"

#define TWO_OVER_SQRT_3 1.1547005f
/* 1 / sqrt(3): the water lattice is triangular, a cell at (x, z) is at u = x + z / sqrt(3) along its skewed axis */
#define INV_SQRT3 (0.57735026f)

typedef struct UnkStruct_80162420_s {
    s16 unk0;
    s16 unk2;
} UnkStruct_80162420;

extern UnkStruct_80162420 gWaterField[];

/*
 * The field entry for lattice cell (cu, cv): 384 rows of 128, the row taking the high bits of cu.
 * The byte offset is added to the address as an integer; indexing the array instead makes IDO
 * scale the row and the column separately, which the original does not do.
 */
#define WATER_CELL(cu, cv) \
    ((UnkStruct_80162420*) ((s32) gWaterField + (((((cv) + ((cu) & ~0x7F) + 0x600) % 384) * 128) + ((cu) & 0x7F)) * 4))

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

extern UnkStruct_80160430 gWaterCellLattice[];
extern UnkStruct_80160A98 gWaterCellOffsets[];
extern s32 D_80192498; /* the window radius, N << 6 */

/* the file's .data (0x800D4680..0x800D47DF) */
u32 D_800D4680 = 9;
s32 D_800D4684[] = {
    0x00000196, 0x00000331, 0x00000332, 0x00000333, 0x00000334, 0x00000335, 0x00000336, 0x00000000,
    0x00000010, 0x000001A8, 0x00000330, 0x00000320, 0x00000188, 0x000000EA, 0x000001D5, 0x000001D6,
    0x000001D7, 0x000001D8, 0x000001D9, 0x000001DA, 0x00000000, 0x0000000C, 0x000000F6, 0x000001D4,
    0x000001C8, 0x000000DE, 0x000000A5, 0x0000014B, 0x0000014C, 0x0000014D, 0x0000014E, 0x0000014F,
    0x00000150, 0x00000000, 0x0000000A, 0x000000AF, 0x0000014A, 0x00000140, 0x0000009B,
};
s32 D_800D4720 = 1500;
s32 D_800D4724 = 9;
s32 D_800D4728 = 32;
s32 D_800D472C = 5;
s32 D_800D4730 = 6;
s32 D_800D4734 = 255;
f32 D_800D4738 = -0.055f;
f32 D_800D473C = 450.0f;
f32 D_800D4740 = 400.0f;
f32 D_800D4744 = 3000.0f;
s32 D_800D4748 = 1;
s32 D_800D474C = 1;
f32 D_800D4750 = 5000.0f;
s32 D_800D4754 = 1;
s32 D_800D4758 = 2;
s32 D_800D475C = 0;
s32 D_800D4760 = 0;
f32 D_800D4764 = 0.7f;
f32 D_800D4768 = -70.0f;
s32 D_800D476C = 32;
s32 D_800D4770 = 5;
s32 D_800D4774 = 0;
s32 D_800D4778 = 0;
f32 D_800D477C = 0.75f;
f32 D_800D4780[] = { 0.0f, 0.0f, -51.2f, 38.4f, 38.4f, 51.2f, 50.0f };
s32 D_800D479C[] = { 30, 30, 100, 0, 30, 0, 0, 0, 0 };

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
// Score 485 of 49800: calls, branches, the frame (0xF0) and every stack slot agree. As in its twin func_80050B78,
// cam->unk9C is read through (no d local; pd keeps its stack word), which gives the d multiplies the original's
// operand order. The alpha is a signed conversion ((s32) (e + 0.5f)). One f32 (e) serves the corner-ray temps,
// the alpha and the far vertex's offset; declared third it gets the original's home (sp+0xE4). vp declared after
// hiz and padB (a stack pad) give the up-vector products' slots (declaration search). The dist offset spells 0.866
// as .866f, a separate constant to IDO from the vertices' 0.866f; the ob[1] chain runs from vtx[6]; the ob[0] and
// ob[2] chains store vtx[1] first. The (s16) on the second texture coordinate's SysUtils_Round takes an extra
// integer temporary (hack). The do {} while (0) in the first corner ray and the empty test of cam->unkF4 after
// the last one are FAKEs (marked; without them the float temporaries rotate from the first instruction on, 4800).
// The cross product's y through k (FAKE, from a search that routes each assignment through a free local): 485.
// Left: the cam->upY CSE takes $f14 (the original's $f24) and the float registers after it rotate (unk6C, unk68,
// unk64, the 5.0f and dist), 0.866f is loaded later into $f20 (early into $f24 there), and the texture
// coordinates' sums take t7/t0 (t8/t9 there).
void func_8004C1D0(s32 view, Vtx* vtx) {
    s32 i;
    f32 pd; // stack pad (cam->unk9C is read through, as in func_80050B78)
    f32 e;
    f32 k;
    s32 angle;
    f32 w;
    f32 h;
    f32 s;
    f32 dist;
    f32 lox;
    f32 loy;
    f32 loz;
    f32 hix;
    f32 hiy;
    f32 hiz;
    Vtx* vp;
    f32 padB; // stack pad
    camera_unk_1* cam;
    f32 x;
    f32 y;
    f32 z;
    f32 upx;
    f32 upy;
    f32 upz;

    if (view != 0) {
        cam = &gCameraPerspective[D_80223934];
    } else {
        cam = &gCameraPerspective[D_80223930];
    }
    angle = SysUtils_Round((cam->unk88 / 720.0f) * 4096.0f);
    h = (cam->unk9C * SIN(angle)) / COS(angle);
    w = (h * 320.0f) / 240.0f;
    if (gPlayers == TWO_PLAYERS) {
        if (D_801CE638 == 1) {
            h = h * 0.5f;
        }
    }
    x = (cam->upY * cam->unk6C) - (cam->upZ * cam->unk68);
    k = (cam->upZ * cam->unk64) - (cam->upX * cam->unk6C); // FAKE: the cross product's y through k (a search)
    y = k;
    z = (cam->upX * cam->unk68) - (cam->upY * cam->unk64);
    e = cam->unk94 + w;
    hix = e * x;
    hiy = e * y;
    hiz = e * z;
    e = cam->unk94 - w;
    lox = e * x;
    loy = e * y;
    loz = e * z;
    upx = cam->unk9C * cam->unk64;
    upy = cam->unk9C * cam->unk68;
    upz = cam->unk9C * cam->unk6C;
    s = D_800D4740 - cam->eyeY;
    dist = (cam->unk9C * D_800D4744 * 1.732f) / 320.0f;

    e = cam->unk98 - h;
    x = (cam->upX * e) + upx;
    y = (cam->upY * e) + upy;
    z = (cam->upZ * e) + upz;
    if ((y + hiy) > 5.0f) {
        do {} while (0); // FAKE: a block boundary with no code; moves the register allocation towards the original
        e = (s / (y + hiy)) * (((x + hix) * cam->unkF0) + ((z + hiz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    if ((y + loy) > 5.0f) {
        e = (s / (y + loy)) * (((x + lox) * cam->unkF0) + ((z + loz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    e = cam->unk98 + h;
    x = (cam->upX * e) + upx;
    y = (cam->upY * e) + upy;
    z = (cam->upZ * e) + upz;
    if ((y + hiy) > 5.0f) {
        e = (s / (y + hiy)) * (((x + hix) * cam->unkF0) + ((z + hiz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    if ((y + loy) > 5.0f) {
        e = (s / (y + loy)) * (((x + lox) * cam->unkF0) + ((z + loz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
        if (!cam->unkF4) {} // FAKE (permuter): an empty test, for the float registers
    }
    dist = (D_800D4744 * .866f) + dist; // .866f: a separate constant from the 0.866f below (IDO keeps them apart)
    x = cam->eyeX + (dist * cam->unkF0);
    z = cam->eyeZ + (dist * cam->unkF4);
    e = D_800D4744 * D_800D4764;

    vtx[6].v.ob[0] = SysUtils_Round(x - D_800D4744);
    vtx[1].v.ob[0] = vtx[5].v.ob[0] = SysUtils_Round(x - (D_800D4744 * 0.5f));
    vtx[0].v.ob[0] = SysUtils_Round(x - (cam->unkF0 * e));
    vtx[2].v.ob[0] = vtx[4].v.ob[0] = SysUtils_Round((D_800D4744 * 0.5f) + x);
    vtx[3].v.ob[0] = SysUtils_Round(x + D_800D4744);
    vtx[6].v.ob[1] = vtx[5].v.ob[1] = vtx[4].v.ob[1] = vtx[3].v.ob[1] = vtx[2].v.ob[1] = vtx[1].v.ob[1] =
        vtx[0].v.ob[1] = SysUtils_Round(D_800D4740);
    vtx[1].v.ob[2] = vtx[2].v.ob[2] = SysUtils_Round(z - (D_800D4744 * 0.866f));
    vtx[0].v.ob[2] = SysUtils_Round(z - (cam->unkF4 * e));
    vtx[3].v.ob[2] = vtx[6].v.ob[2] = SysUtils_Round(z);
    vtx[4].v.ob[2] = vtx[5].v.ob[2] = SysUtils_Round((D_800D4744 * 0.866f) + z);

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
    s = D_800D4740 - cam->eyeY;
    if (s == 0.0f) {
        k = 1.0f;
    } else {
        k = (D_800D4750 - cam->eyeY) / s;
    }
    for (i = 6; i >= 0; i--) {
        vp = &vtx[i];
        x = vp->v.ob[0] - cam->eyeX;
        z = vp->v.ob[2] - cam->eyeZ;
        e = (sqrtf((x * x) + (z * z)) * D_800D4738) + D_800D473C;
        if (e < 0.5f) {
            vp->v.cn[3] = 0;
        } else if (e > 254.5f) {
            vp->v.cn[3] = 255;
        } else {
            vp->v.cn[3] = (s32) (e + 0.5f);
        }
        vp->v.tc[0] = SysUtils_Round((cam->eyeX + (k * x)) / D_801924C4) + D_800D475C;
        vp->v.tc[1] = (s16) SysUtils_Round((cam->eyeZ + (k * z)) / D_801924C8) + D_800D4760; // (s16): see above
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C1D0.s")
#endif

extern s32 D_80192460[];
extern s32 D_80192464[];
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
    h = (f32) gWaterLevel - cam->eyeY;
    if (h == 0.0f) {
        t = 1.0f;
    } else {
        t = (D_800D4768 - cam->eyeY) / h;
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
        vp->v.tc[1] = (SysUtils_Round(((((f32) vp->v.ob[0] - cam->eyeX) * t) + cam->eyeX) / D_801924CC) + D_800D4774) & 0xFFFF;
        vp->v.tc[0] = (SysUtils_Round(((((f32) vp->v.ob[2] - cam->eyeZ) * t) + cam->eyeZ) / D_801924D0) + D_800D4778) & 0xFFFF;
    }
}

/* a wave generator stamped as rows of lines (the arg of Water_StampPhasedSine) */
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

void Water_StampPhasedSine(UnkStruct_8004CC7C* arg0) {
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
                    u = (s32) ((INV_SQRT3 * pz) + px) % 24576;
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


/*
 * Stamps sin(phase * 4096 / period) * amplitude along the diagonal from (x - r, z - r) to
 * (x + r, z + r) in steps of 64, with r = D_80192498 / 4. The phase, D_800D47C0, advances by step
 * on each call and wraps at period.
 */
void Water_StampDiagonalSine(f32 x, f32 z, s32 amplitude, s32 period, s32 step) {
    static s32 D_800D47C0 = 0;
    s32 t; // FAKE
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

    D_800D47C0 += step;
    if (D_800D47C0 >= period) {
        D_800D47C0 -= period;
    }
    phase = D_800D47C0;
    amplitude = (s32) (SIN((phase << 12) / period) * amplitude) << 8; // FAKE: h computed in amplitude
    h = amplitude;
    // the radius is not a local: as one, it takes the original's register for end
    end = (D_80192498 >> 2) + x;
    x -= D_80192498 >> 2;
    z -= D_80192498 >> 2;
    while (x <= end) {
        u = (s32) ((INV_SQRT3 * z) + x) % 24576;
        v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
        t = v >> 6; // FAKE: the copy through t gives the original register choice, as in Water_StampLine
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

// CU and CV are macros so that IDO keeps them as common subexpressions: as named locals they add
// stack slots
#define CU (((s32) ((INV_SQRT3 * z) + x) % 24576) >> 6)
#define CV (((s32) (TWO_OVER_SQRT_3 * z) % 24576) >> 6)
f32 Water_GetHeight(f32 x, f32 z) {
    s32 du;
    s32 h00;
    s32 dv;
    s32 d0;
    s32 d1;
    s32 pad1; // stack pad: the spill slots of du and dv sit just below the declared locals
    s32 pad2; // stack pad

    du = (CU << 6) - ((s32) ((INV_SQRT3 * z) + x) % 24576);
    dv = (CV << 6) - ((s32) (TWO_OVER_SQRT_3 * z) % 24576);
    h00 = WATER_CELL(CU, CV)->unk0 >> 8;
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

void Water_PushPoints(struct UnkStruct_8004B0F8* arg0) {
    f32 max;
    f32 inv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 depth;
    struct UnkStruct_8004B0F8_1* pt;
    s32 v;
    s32 cv;
    s32 u;
    s32 cu;
    s32 h00;
    s32 fu;
    s32 fv;
    s32 d0;
    s32 d1;
    f32 x;

    max = arg0->unk1C * arg0->unk40 * arg0->unk18;
    for (pt = &arg0->unk30[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--) {
        x = pt->unk0;
        nx = pt->unk8; // nx holds the point's z until the normal is computed, as in Water_PushPointsAtLevel
        u = (s32) ((INV_SQRT3 * nx) + x) % 24576;
        cu = u >> 6;
        fu = (cu << 6) - u;
        v = (s32) (TWO_OVER_SQRT_3 * nx) % 24576;
        cv = v >> 6;
        fv = (cv << 6) - v;
        h00 = WATER_CELL(cu, cv)->unk0 >> 8;
        if (fv < fu) {
            d0 = WATER_CELL(cu, cv + 1)->unk0 >> 8;
            d1 = h00 - d0;
            d0 -= WATER_CELL(cu + 1, cv + 1)->unk0 >> 8;
        } else {
            d1 = WATER_CELL(cu + 1, cv)->unk0 >> 8;
            d0 = h00 - d1;
            d1 -= WATER_CELL(cu + 1, cv + 1)->unk0 >> 8;
        }
        inv = 1.0f / sqrtf((f32) (((d0 * d0) + (d1 * d1) + 0x1000) << 12));
        nx = d0 * inv;
        ny = 4096.0f * inv;
        nz = d1 * inv;
        depth = (fu * nx) + (ny * ((f32) (gWaterLevel + h00) - pt->unk4)) + (nz * fv);
        if (depth >= 0.0f) {
            pt->unk1C |= 1;
            pt->unkC *= arg0->unk14;
            pt->unk10 *= arg0->unk10;
            pt->unk14 *= arg0->unk14;
            depth *= arg0->unk18;
            if (max < depth) {
                depth = max;
            }
            pt->unkC += depth * (nx - (0.5f * nz));
            pt->unk10 += depth * ny;
            pt->unk14 += depth * (0.8660254f * nz);
        } else {
            pt->unk1C &= 0xFFFE;
        }
    }
}

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

void Water_DampPoints(void* arg0) {
    UnkStruct_80192690* body = arg0;
    f32 vx;
    UnkStruct_8004B0F8_1* pt2;
    UnkStruct_8004B0F8_1* pt;
    f32 vz;
    f32 k;
    f32 dx;
    f32 inv;
    f32 d;
    f32 dz;
    f32 len;

    vx = body->unk6C;
    vz = body->unk74;
    k = 1.0f - body->unk14;
    len = (vx * vx) + (vz * vz);
    if (.0f == len) { // .0f, not 0.0f: keeps the two zero constants apart, as in the original
        dz = 0.0f;
        dx = 0.0f;
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
        d = (pt->unkC * dx) + (pt->unk14 * dz);
        pt->unkC = (d * dx * k) + (body->unk14 * pt->unkC);
        pt->unk10 *= body->unk10;
        pt->unk14 = (d * dz * k) + (body->unk14 * pt->unk14);
        d = (pt2->unkC * dx) + (pt2->unk14 * dz);
        pt2->unkC = (d * dx * k) + (body->unk14 * pt2->unkC);
        pt2->unk10 *= body->unk10;
        pt2->unk14 = (d * dz * k) + (body->unk14 * pt2->unk14);
    }
    pt = &body->unk30[6];
    pt2 = &body->unk30[7];
    if ((pt->unk1C | pt2->unk1C) & 1) {
        d = (pt->unkC * dx) + (pt->unk14 * dz);
        pt->unkC = (d * dx * k) + (body->unk14 * pt->unkC);
        pt->unk10 *= body->unk10;
        pt->unk14 = (d * dz * k) + (body->unk14 * pt->unk14);
        d = (pt2->unkC * dx) + (pt2->unk14 * dz);
        if (1) {} if (1) {} // FAKE: two empty ifs put the second point's d in $f12, as the original
        pt2->unkC = (d * dx * k) + (body->unk14 * pt2->unkC);
        pt2->unk10 *= body->unk10;
        pt2->unk14 = (d * dz * k) + (body->unk14 * pt2->unk14);
    }
    pt = &body->unk30[9];
    pt2 = &body->unk30[10];
    if ((pt->unk1C | pt2->unk1C) & 1) {
        d = (pt->unkC * dx) + (pt->unk14 * dz);
        pt->unkC = (d * dx * k) + (body->unk14 * pt->unkC);
        pt->unk10 *= body->unk10;
        pt->unk14 = (d * dz * k) + (body->unk14 * pt->unk14);
        d = (pt2->unkC * dx) + (pt2->unk14 * dz);
        pt2->unkC = (d * dx * k) + (body->unk14 * pt2->unkC);
        pt2->unk10 *= body->unk10;
        pt2->unk14 = (d * dz * k) + (body->unk14 * pt2->unk14);
    }
    pt2 = &body->unk30[2];
    if ((body->unk30[0].unk1C | pt2->unk1C) & 1) {
        body->unk30[0].unk10 *= body->unk10;
        pt2->unk10 *= body->unk10;
    }
}

void Water_PushPointsAtLevel(struct UnkStruct_8004B0F8* arg0, f32 arg1) {
    f32 max;
    f32 inv;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 depth;
    struct UnkStruct_8004B0F8_1* pt;
    s32 v;
    s32 cv;
    s32 u;
    s32 cu;
    s32 h00;
    s32 fu;
    s32 fv;
    s32 d0;
    s32 d1;
    f32 x;

    max = arg0->unk1C * arg0->unk40 * arg0->unk18;
    for (pt = &arg0->unk30[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--) {
        x = pt->unk0;
        nx = pt->unk8; // nx holds the point's z until the normal is computed: the original's registers
        u = (s32) ((INV_SQRT3 * nx) + x) % 24576;
        cu = u >> 6;
        fu = (cu << 6) - u;
        v = (s32) (TWO_OVER_SQRT_3 * nx) % 24576;
        cv = v >> 6;
        fv = (cv << 6) - v;
        h00 = WATER_CELL(cu, cv)->unk0 >> 8;
        if (fv < fu) {
            d0 = WATER_CELL(cu, cv + 1)->unk0 >> 8;
            d1 = h00 - d0;
            d0 -= WATER_CELL(cu + 1, cv + 1)->unk0 >> 8;
        } else {
            d1 = WATER_CELL(cu + 1, cv)->unk0 >> 8;
            d0 = h00 - d1;
            d1 -= WATER_CELL(cu + 1, cv + 1)->unk0 >> 8;
        }
        inv = 1.0f / sqrtf((f32) (((d0 * d0) + (d1 * d1) + 0x1000) << 12));
        nx = d0 * inv;
        ny = 4096.0f * inv;
        nz = d1 * inv;
        depth = (fu * nx) + (ny * ((arg1 + h00) - pt->unk4)) + (nz * fv);
        if (depth >= 0.0f) {
            pt->unk1C |= 1;
            depth *= arg0->unk18;
            if (max < depth) {
                depth = max;
            }
            pt->unkC += depth * (nx - (0.5f * nz));
            pt->unk10 += depth * ny;
            pt->unk14 += depth * (0.8660254f * nz);
        } else {
            pt->unk1C &= 0xFFFE;
        }
    }
    Water_DampPoints(arg0);
}

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
    Water_DampPoints(arg0);
}

extern s32 gWaterWindowN;

void Water_BuildCellLists(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 len;

    n = 0;
    for (i = -gWaterWindowN; i < 0; i++) {
        len = gWaterWindowN * 2;
        for (j = 0; j <= len + i; j++) {
            gWaterCellLattice[n].unk0 = -gWaterWindowN + j;
            gWaterCellLattice[n].unk1 = i;
            n++;
        }
    }
    for (i = 0; i <= gWaterWindowN; i++) {
        len = gWaterWindowN * 2;
        for (j = 0; j <= len - i; j++) {
            gWaterCellLattice[n].unk0 = -gWaterWindowN + i + j;
            gWaterCellLattice[n].unk1 = i;
            n++;
        }
    }
    n = 0;
    for (i = -gWaterWindowN; i <= gWaterWindowN; i++) {
        len = (gWaterWindowN * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            if ((i % 2) == 0) {
                gWaterCellOffsets[n++].unk4 = (j - (len / 2)) * 64;
            } else {
                gWaterCellOffsets[n++].unk4 = ((j - (len / 2)) * 64) - 32;
            }
        }
    }
    n = 0;
    for (i = -gWaterWindowN; i < 0; i++) {
        len = (gWaterWindowN * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            gWaterCellOffsets[n].unk6 = (((sqrtf(3.0f) * 64.0f) / 2) * i) - 0.5;
            n++;
        }
    }
    for (i = 0; i <= gWaterWindowN; i++) {
        len = (gWaterWindowN * 2) - (s32) sqrtf(i * i);
        for (j = 0; j <= len; j++) {
            gWaterCellOffsets[n].unk6 = (((sqrtf(3.0f) * 64.0f) / 2) * i) + 0.5;
            n++;
        }
    }
}


/* the field entry at a byte offset (UnkStruct_80160A98.unk0) */
#define WATER_CELL_AT(off) ((UnkStruct_80162420*) ((s32) gWaterField + (off)))

/*
 * One step of the wave simulation over the window's cells (see the recomp's GAME-INTERNALS.md,
 * "Entry + 2 is a velocity"). Each neighbour pair a, b is coupled once:
 *     mean = (a.h + b.h) >> D_800D4724, diff = (b.h - a.h) >> D_800D472C,
 *     a.v += diff - mean, b.v -= diff + mean;
 * and each cell, once all its pairs are done, steps: h += v, v -= v >> D_800D4730.
 */

#ifdef NON_MATCHING
// Score 3490 of 32400: heights held in ha/hb as the original keeps them in registers. Adding the new velocity to
// the height in one statement (h += v = ...) gives the original's reload of v after the height store; q set before
// end in the second pass and end as p + 2N + i in the first follow the original's address arithmetic. The velocity
// damping reads the velocity into hb first (v -= v >> D_800D4730 as hb = v; v = hb - (hb >> ...)) in the first
// pass's last cell, the third pass's b and the final cell (from a search over which ones): that removes the extra
// saved s0 IDO kept here. Left: the first pair's cells load in the other order, the q index is computed in a1 in the
// original, the damping's reload goes to a1 there (a t register here), and the t registers rotate differently.
void func_8004EAA4(void) {
    UnkStruct_80160A98* p;
    UnkStruct_80160A98* q;
    UnkStruct_80160A98* end;
    UnkStruct_80162420* a;
    UnkStruct_80162420* b;
    s32 i;
    s32 mean;
    s32 diff;
    s32 ha;
    s32 hb;

    p = gWaterCellOffsets;
    for (i = -gWaterWindowN; i < 0; i++) {
        q = p + ((gWaterWindowN * 2) + i + 2);
        a = WATER_CELL_AT(p->unk0);
        ha = a->unk0;
        b = WATER_CELL_AT(q[-1].unk0);
        hb = b->unk0;
        mean = (ha + hb) >> D_800D4724;
        diff = (hb - ha) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        b->unk2 = (b->unk2 - diff) - mean;
        for (end = p + (gWaterWindowN * 2) + i; p < end;) {
            p++;
            b = WATER_CELL_AT(q->unk0);
            hb = b->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            q++;
            b->unk2 = (b->unk2 - diff) - mean;
            a = WATER_CELL_AT(p->unk0);
            ha = a->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b = WATER_CELL_AT(p[-1].unk0);
            hb = b->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk0 += b->unk2 = (b->unk2 - diff) - mean;
            b->unk2 -= b->unk2 >> D_800D4730;
        }
        b = WATER_CELL_AT(q->unk0);
        hb = b->unk0;
        p++;
        mean = (ha + hb) >> D_800D4724;
        diff = (hb - ha) >> D_800D472C;
        a->unk0 += a->unk2 = (a->unk2 + diff) - mean;
        b->unk2 = (b->unk2 - diff) - mean;
        hb = a->unk2;
        a->unk2 = hb - (hb >> D_800D4730);
    }
    for (i = 0; i < gWaterWindowN; i++) {
        a = WATER_CELL_AT(p->unk0);
        ha = a->unk0;
        q = p + (((gWaterWindowN * 2) - i) + 1);
        for (end = p + ((gWaterWindowN * 2) - i); p < end;) {
            p++;
            b = WATER_CELL_AT(q->unk0);
            hb = b->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            q++;
            b->unk2 = (b->unk2 - diff) - mean;
            a = WATER_CELL_AT(p->unk0);
            ha = a->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk2 = (b->unk2 - diff) - mean;
            b = WATER_CELL_AT(p[-1].unk0);
            hb = b->unk0;
            mean = (ha + hb) >> D_800D4724;
            diff = (hb - ha) >> D_800D472C;
            a->unk2 = (a->unk2 + diff) - mean;
            b->unk0 += b->unk2 = (b->unk2 - diff) - mean;
            b->unk2 -= b->unk2 >> D_800D4730;
        }
        p++;
        a->unk0 += a->unk2;
        a->unk2 -= a->unk2 >> D_800D4730;
    }
    a = WATER_CELL_AT(p->unk0);
    ha = a->unk0;
    for (end = p + gWaterWindowN; p < end;) {
        b = WATER_CELL_AT(p[1].unk0);
        hb = b->unk0;
        p += 2;
        mean = (ha + hb) >> D_800D4724;
        diff = (hb - ha) >> D_800D472C;
        a->unk0 += a->unk2 = (a->unk2 + diff) - mean;
        b->unk2 = (b->unk2 - diff) - mean;
        a->unk2 -= a->unk2 >> D_800D4730;
        a = WATER_CELL_AT(p->unk0);
        ha = a->unk0;
        mean = (ha + hb) >> D_800D4724;
        diff = (hb - ha) >> D_800D472C;
        a->unk2 = (a->unk2 + diff) - mean;
        b->unk0 += b->unk2 = (b->unk2 - diff) - mean;
        hb = b->unk2;
        b->unk2 = hb - (hb >> D_800D4730);
    }
    hb = a->unk2;
    a->unk0 += hb;
    a->unk2 = hb - (hb >> D_800D4730);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004EAA4.s")
#endif

void Water_StampPoint(f32 x, f32 z, s32 height) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;

    u = (s32) ((INV_SQRT3 * z) + x) % 24576;
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
extern s32 D_801924E0[];

void Water_StampPointTimed(f32 x, f32 z, s32 height, s32 arg3) {
    UnkStruct_80162420* p0;
    UnkStruct_80162420* p1;
    UnkStruct_80162420* p2;
    s32 u;
    s32 v;
    s32 cu;
    s32 cv;

    u = (s32) ((INV_SQRT3 * z) + x) % 24576;
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

    temp_hi = (s32) ((INV_SQRT3 * arg1) + arg0) % 24576;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a0 = temp_hi_2 >> 6;
    temp_a1 = temp_hi >> 6;

    if ((temp_hi - (temp_a1 * 64)) < (temp_hi_2 - (temp_a0 * 64))) {
        var_v0 = gWaterField + ((((((temp_a0 + 1) + (temp_a1 & ~0x7F) + 0x600) % 384)) * 128) + (temp_a1 & 0x7F));
    } else {
        var_v0 = gWaterField + (((((temp_a0 + ((temp_a1 + 1) & ~0x7F) + 0x600) % 384)) * 128) + ((temp_a1 + 1) & 0x7F));
    }
    if ((arg2 * 256) < var_v0->unk0) {
        var_v0->unk0 += arg2 * 256;
        var_v0->unk2 = 0;
    }
}

void Water_StampLine(f32 height, f32 x, f32 z, f32 dx, f32 dz, s32 count) {
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
            u = (s32) ((INV_SQRT3 * pz) + px) % 24576;
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
void Water_FillNoise(s32 amplitude) {
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
            q = (UnkStruct_80162420*) ((u8*) gWaterField + ((j << 7) << 2) + i);
            q->unk0 = h;
            q->unk2 = 0;
        }
    }
    for (k = 5; k >= 0; k--) {
        rnd[k] = SysUtils_Rand() & 0x7FFF;
    }
    for (j = 0; j != 384; j++) {
        row = (u8*) gWaterField + ((j << 7) << 2);
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

extern UnkStruct_80192420 gWaterWindow[];
extern s32 D_8019249C;
extern s32 D_801924A0;
extern s32 D_801924A8;
extern s32 D_801924A4;
extern f32 D_801924AC;
extern f32 D_801924B0;
extern f32 D_801924B8;
extern f32 D_801924BC;

void Water_BuildCellLists(void);
void Water_FillNoise(s32 amplitude);

/*
 * Sets up the water for a scene: the simulation shifts and the window size N (16, 10 or 12), the
 * 13-word parameter set from D_800D4684, gWaterLevel, the cell lists (Water_BuildCellLists) and a random
 * field (Water_FillNoise); the field's wrap bounds; and, in both GfxPools, the vertex colours of the
 * window's vertices and the texture coordinate 0x400 on its boundary ring and skirt.
 */

#ifdef NON_MATCHING
// Score 480 of 52100: the frame (0x50) and every stack slot agree with the copy pointers declared in a block of
// their own and the ring loop's counters in the pool loop's body; the ring step reuses i (the colour loops' counter,
// dead by then; from a search over variable merges). bot and b also hold the two wrap counts (nu, nv) and
// set also walks the lower edge, which lowers their priority as in the original, where the wrap counts sit in
// caller-saved registers and are spilled across sqrtf. The sqrt(3) scale is "* 2" and D_801924B8 is set before
// D_801924B0; the ring chains are written tc[0] = tc[1] for j, b and top (from a search over each pair's order), and
// the first ring sets set before d, as the second does.
// The original builds D_80192460's address twice: for the copy loop (v0) and again before the pool loop (s2), for the
// six skirt indices D_80192460[1..6]. With the copy loop written through D_80192460 too, IDO keeps one address in s4
// from the copy loop on. Here the copy runs from D_80192464 - 1 to &D_80192464[12] (FAKE: the same 13 words; a
// different symbol, so IDO builds the pool loop's base on its own, and the bytes are the same). Through D_80192464[0..5]
// in the pool loop instead, the base is 0x80192464 (940); an index copy loop gives its pointers among the
// gWaterWindow stores (1750).
// Left: the waterLevel copy in a2 (a3 there) and the wrap count in a1 (a2 there); the copy loop's index shift is
// scheduled one slot early; the ring loops' temporaries.
void func_8004F9E0(s32 waterLevel, s32 amplitude) {
    s32 set;
    GfxPool* pool;
    s32 bot;
    s32 b;

    if (D_801CE64C == 1) {
        D_800D4724 = 10;
        D_800D472C = 4;
        D_800D4730 = 5;
        gWaterWindowN = 16;
        set = 0;
    } else {
        D_800D4724 = 9;
        D_800D472C = 5;
        D_800D4730 = 6;
        if ((D_801CE64C == 2) || (gPlayers == TWO_PLAYERS)) {
            gWaterWindowN = 10;
            set = 26;
        } else {
            gWaterWindowN = 12;
            set = 13;
        }
    }
    gWaterWindow[0].unk0 = gWaterWindow[0].unk4 = gWaterWindow[1].unk0 = gWaterWindow[1].unk4 = 0;
    gWaterWindow[1].unk18 = 0.0f;
    gWaterWindow[0].unk8 = gWaterWindow[0].unkC = gWaterWindow[0].unk10 = gWaterWindow[0].unk14 = gWaterWindow[0].unk18 =
        gWaterWindow[1].unk8 = gWaterWindow[1].unkC = gWaterWindow[1].unk10 = gWaterWindow[1].unk14 = gWaterWindow[1].unk18;
    {
        s32* src;
        s32* dst;

        for (src = &D_800D4684[set], dst = D_80192464 - 1; dst < &D_80192464[12];) {
            *dst++ = *src++;
        }
    }
    D_801924A0 = 0x8000;
    D_801924A4 = 0x8000;
    D_801924A8 = 0x800;
    D_80192498 = gWaterWindowN << 6;
    D_8019249C = (gWaterWindowN * 3 * (gWaterWindowN + 1)) + 1;
    gWaterLevel = waterLevel;
    Water_BuildCellLists();
    Water_FillNoise(amplitude);
    bot = ((f32) ((D_801924A8 * 2) + D_801924A0) / 49152.0f) + 0.9;
    b = ((f32) (D_801924A4 + (D_801924A8 * 2)) / (sqrtf(3.0f) * 2 * 8192.0f)) + 0.9;
    D_801924AC = (bot * 0x6000) - 1.0;
    D_801924B8 = (sqrtf(3.0f) * b * 8192.0f) - 1.0;
    D_801924B0 = -bot * 0x6000;
    D_801924BC = sqrtf(3.0f) * -b * 8192.0f;
    D_801924B4 = (D_801924AC - D_801924B0) + 1.0;
    D_801924C0 = (D_801924B8 - D_801924BC) + 1.0;
    for (pool = &D_8011F8E8[1]; pool >= D_8011F8E8; pool--) {
        s32 i;
        s32 j;
        s32 k;
        s32 top;
        s32 d;

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
        top = gWaterWindowN;
        bot = D_8019249C - gWaterWindowN;
        set = bot - 1;
        d = bot - 2;
        b = top + 1;
        i = top + 2;
        for (j = gWaterWindowN - 1, k = D_8019249C - 1; j >= 0; j--, k--) {
            pool->unk13D68[j].v.tc[0] = pool->unk13D68[j].v.tc[1] = pool->unk13D68[b].v.tc[0] = pool->unk13D68[b].v.tc[1] =
                pool->unk13D68[top].v.tc[0] = pool->unk13D68[top].v.tc[1] = pool->unk13D68[set].v.tc[0] =
                    pool->unk13D68[set].v.tc[1] = pool->unk13D68[d].v.tc[1] = pool->unk13D68[d].v.tc[0] =
                        pool->unk13D68[k].v.tc[0] = pool->unk13D68[k].v.tc[1] = 0x400;
            b += i;
            top += i;
            set -= i;
            d -= i;
            i++;
        }
        pool->unk13D68[D_80192460[1]].v.tc[0] = pool->unk13D68[D_80192460[1]].v.tc[1] =
            pool->unk13D68[D_80192460[2]].v.tc[0] = pool->unk13D68[D_80192460[2]].v.tc[1] =
                pool->unk13D68[D_80192460[3]].v.tc[0] = pool->unk13D68[D_80192460[3]].v.tc[1] =
                    pool->unk13D68[D_80192460[4]].v.tc[0] = pool->unk13D68[D_80192460[4]].v.tc[1] =
                        pool->unk13D68[D_80192460[5]].v.tc[0] = pool->unk13D68[D_80192460[5]].v.tc[1] =
                            pool->unk13D68[D_80192460[6]].v.tc[0] = pool->unk13D68[D_80192460[6]].v.tc[1] = 0x400;
        if (gPlayers == TWO_PLAYERS) {
            top = gWaterWindowN;
            bot = D_8019249C - gWaterWindowN;
            set = bot - 1;
            d = bot - 2;
            b = top + 1;
            i = top + 2;
            for (j = gWaterWindowN - 1, k = D_8019249C - 1; j >= 0; j--, k--) {
                pool->unk170D8[j].v.tc[0] = pool->unk170D8[j].v.tc[1] = pool->unk170D8[b].v.tc[0] = pool->unk170D8[b].v.tc[1] =
                    pool->unk170D8[top].v.tc[0] = pool->unk170D8[top].v.tc[1] = pool->unk170D8[set].v.tc[0] =
                        pool->unk170D8[set].v.tc[1] = pool->unk170D8[d].v.tc[1] = pool->unk170D8[d].v.tc[0] =
                            pool->unk170D8[k].v.tc[0] = pool->unk170D8[k].v.tc[1] = 0x400;
                b += i;
                top += i;
                set -= i;
                d -= i;
                i++;
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


/*
 * Fills a view's vertex arena from the window's cells, row by row: x and z from the window centre
 * plus each cell's offsets; on the boundary y is gWaterLevel, inside it is the field height (>> 8)
 * plus gWaterLevel and the texture coordinates come from the slopes to the neighbouring rows.
 * Then places the six skirt vertices out at D_800D4720 and stores the window's centre and
 * D_800D4720 squared in gWaterWindow[view].
 */

#ifdef NON_MATCHING
// Score 10353 of 60500: frame, the row loops and the first skirt loop match in shape. Left: callee-saved register
// choice (vtx, lo, sx and sz land in other s registers), and the second skirt loop ends on idx != &D_80192460[7]
// (with < IDO unrolls it by two; the original compares with sltu and does not unroll)
void func_80050204(s32 view, Vtx* arena) {
    UnkStruct_80160A98* last;
    f32 dx;
    f32 k;
    s32 oz;
    s32 ox;
    s32 sz;
    s32 sx;
    s32 hB;
    s32 hA;
    s32 i;
    f32 dz;
    UnkStruct_80160A98* hi;
    UnkStruct_80160A98* lo;
    s32* idx;
    Vtx* v;
    Vtx* c;
    Vtx* vtx;
    UnkStruct_80160A98* end;
    UnkStruct_80160A98* e;
    UnkStruct_80192420* w;

    e = gWaterCellOffsets;
    vtx = arena;
    w = &gWaterWindow[view];
    for (last = &gWaterCellOffsets[gWaterWindowN]; last >= e;) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
    }
    for (i = 1 - gWaterWindowN; i < 0; i++) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
        end = e + ((gWaterWindowN * 2) + i - 2);
        lo = e - ((gWaterWindowN * 2) + i + 1);
        hi = e + ((gWaterWindowN * 2) + i + 1);
        for (; end >= e; lo++, hi++) {
            hA = WATER_CELL_AT(lo->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT(hi->unk0)->unk0 >> 7;
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
    for (end = e + ((gWaterWindowN * 2) - 2); end >= e;) {
            hA = WATER_CELL_AT((e + (-((gWaterWindowN * 2) + 1)))->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT((e + (gWaterWindowN * 2))->unk0)->unk0 >> 7;
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
    for (i = 1; i < gWaterWindowN; i++) {
        vtx->v.ob[0] = w->unk0 + e->unk4;
        vtx->v.ob[1] = gWaterLevel;
        vtx->v.ob[2] = e->unk6 + w->unk4;
        e++;
        vtx++;
        end = e + ((gWaterWindowN * 2) - i - 2);
        lo = (e - ((gWaterWindowN * 2) - i)) - 2;
        hi = e + ((gWaterWindowN * 2) - i);
        for (; end >= e; lo++, hi++) {
            hA = WATER_CELL_AT(lo->unk0)->unk0 >> 7;
            hB = WATER_CELL_AT(hi->unk0)->unk0 >> 7;
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
    for (end = &gWaterCellOffsets[D_8019249C - 1]; end >= e;) {
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
        ox = v->v.ob[0] - c->v.ob[0];
        oz = v->v.ob[2] - c->v.ob[2];
        v = &arena[*idx];
        v->v.ob[0] = c->v.ob[0] + (s32) (k * ox);
        v->v.ob[2] = arena[D_80192460[0]].v.ob[2] + (s32) (k * oz);
        v->v.ob[1] = gWaterLevel;
    }
    if (w != gWaterWindow) {
        dx = gCameraPerspective[1].unkF0;
        dz = gCameraPerspective[1].unkF4;
    } else {
        dx = gCameraPerspective[0].unkF0;
        dz = gCameraPerspective[0].unkF4;
    }
    k = (f32) (D_800D4720 - D_80192498) * 0.866f;
    ox = SysUtils_Round(k * dx);
    oz = SysUtils_Round(k * dz);
    for (idx = &D_80192460[1]; idx != &D_80192460[7]; idx++) {
        v = &arena[*idx];
        v->v.ob[0] += ox;
        v->v.ob[2] += oz;
    }
    v = &arena[D_80192460[1]];
    c = &arena[D_80192460[4]];
    w->unk8 = ((f32) (c->v.ob[0] + v->v.ob[0]) * 0.5f) - w->unk14;
    w->unkC = ((f32) (c->v.ob[2] + v->v.ob[2]) * 0.5f) - w->unk18;
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

// Where the camera's view meets the water plane: the four corner rays (up vector +/- h, side +/- w) that point
// down past -5 give a distance along (unkF0, unkF4), the nearest one (from a D_801924A8-based limit) kept; the point
// is stored to *x / *z. cam->unk9C and cam->unk98 are read through (IDO spills its copies), e serves the ray
// offsets and each ray's distance.
void func_80050B78(camera_unk_1* cam, f32* x, f32* z) {
    s32 pad[3]; // stack pad
    f32 h;
    s32 angle;
    f32 e;
    f32 lox;
    f32 loy;
    f32 loz;
    f32 hix;
    f32 hiy;
    f32 hiz;
    f32 s;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 w;
    f32 dist;
    f32 upx;
    f32 upy;
    f32 upz;

    angle = SysUtils_Round((cam->unk88 / 720.0f) * 4096.0f);
    h = (cam->unk9C * SIN(angle)) / COS(angle);
    w = (h * 320.0f) / 240.0f;
    cx = (cam->upY * cam->unk6C) - (cam->upZ * cam->unk68);
    cy = (cam->upZ * cam->unk64) - (cam->upX * cam->unk6C);
    cz = (cam->upX * cam->unk68) - (cam->upY * cam->unk64);
    e = cam->unk94 + w;
    hix = e * cx;
    hiy = e * cy;
    hiz = e * cz;
    e = cam->unk94 - w;
    lox = e * cx;
    loy = e * cy;
    loz = e * cz;

    upx = cam->unk9C * cam->unk64;
    upy = cam->unk9C * cam->unk68;
    upz = cam->unk9C * cam->unk6C;
    s = (f32) (gWaterLevel + D_800D49B0) - cam->eyeY;
    dist = (cam->unk9C * (f32) D_801924A8 * 1.732f) / 320.0f;
    e = cam->unk98 - h;

    cx = (cam->upX * e) + upx;
    cy = (cam->upY * e) + upy;
    cz = (cam->upZ * e) + upz;
    if ((cy + hiy) < -5.0f) {
        e = (s / (cy + hiy)) * (((cx + hix) * cam->unkF0) + ((cz + hiz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    if ((cy + loy) < -5.0f) {
        e = (s / (cy + loy)) * (((cx + lox) * cam->unkF0) + ((cz + loz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    e = cam->unk98 + h;
    cx = (cam->upX * e) + upx;
    cy = (cam->upY * e) + upy;
    cz = (cam->upZ * e) + upz;
    if ((cy + hiy) < -5.0f) {
        e = (s / (cy + hiy)) * (((cx + hix) * cam->unkF0) + ((cz + hiz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    if ((cy + loy) < -5.0f) {
        e = (s / (cy + loy)) * (((cx + lox) * cam->unkF0) + ((cz + loz) * cam->unkF4));
        if (e < dist) {
            dist = e;
        }
    }
    e = (((f32) D_80192498 * 0.866f) + dist) - 32.0f;
    *x = cam->eyeX + (e * cam->unkF0);
    *z = cam->eyeZ + (e * cam->unkF4);
}

void func_8004EAA4(void);
void func_80050204(s32 view, Vtx* vtx);

void Water_UpdateWindow(s32 view, f32 x, f32 z) {
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

    w = &gWaterWindow[view];
    u = (s32) ((INV_SQRT3 * z) + x) % 24576;
    cu = (u + 0x20) >> 6;
    v = (s32) (TWO_OVER_SQRT_3 * z) % 24576;
    cv = (v + 0x20) >> 6;
    fcv = cv << 6;
    fv = v;
    w->unk14 = ((f32) (cu << 6) - (0.5f * fcv)) - ((f32) u - (0.5f * fv));
    w->unk0 = w->unk14 + x;
    w->unk18 = (0.8660254f * fcv) - (0.8660254f * fv);
    w->unk4 = w->unk18 + z;
    for (off = &gWaterCellLattice[D_8019249C - 1], cell = &gWaterCellOffsets[D_8019249C - 1]; off >= gWaterCellLattice; off--, cell--) {
        col = off->unk0 + (cu & 0x7F);
        // (cu >> 7) << 7 is cu & ~0x7F; the original's sra/sll needs the shifts
        row = off->unk1 + ((cv + ((cu >> 7) << 7) + 0x600) % 384);
        cell->unk0 = ((((((col & ~0x7F) + row) + 0x600) % 384) << 7) + (col & 0x7F)) * 4;
    }
    if (gRiderGameModes != PAUSE_MODE) {
        func_8004EAA4();
    }
    if (w == gWaterWindow) {
        func_80050204(0, gGfxPool->unk13D68);
    } else {
        func_80050204(1, gGfxPool->unk170D8);
    }
}

extern s32 D_801C1FCC;

void func_80050B78(camera_unk_1* cam, f32* x, f32* z);

/*
 * The per-frame water update. On Glacier Coast (not paused, D_801CE638 == 1) it lowers the water
 * level while D_801C1FCC is 1 or 2. In the N = 16 scene (D_801CE64C == 1) it moves a wandering
 * stamp (angle D_800D47C4 turning by D_800D47C8, position D_800D47CC/D0, respawned on the rim when
 * it leaves the window) and keeps the window at (0, 0); otherwise it centres each view's window
 * from func_80050B78.
 */
void Water_Update(void) {
    static s32 D_800D47C4 = 0;
    static s32 D_800D47C8 = 1;
    static f32 D_800D47CC = 1024.0f;
    static f32 D_800D47D0 = 1024.0f;
    s32 turn;
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
            D_800D47C4 = (D_800D47C4 + D_800D47C8 + 0x1000) & 0xFFF;
            D_800D47CC += 51.2 * COS(D_800D47C4);
            D_800D47D0 += 51.2 * SIN(D_800D47C4);
            if ((f32) (D_80192498 * D_80192498) < ((D_800D47CC * D_800D47CC) + (D_800D47D0 * D_800D47D0))) {
                D_800D47C4 = SysUtils_Rand() & 0xFFF;
                D_800D47CC = COS(D_800D47C4) * D_80192498;
                D_800D47D0 = SIN(D_800D47C4) * D_80192498;
                D_800D47C4 = SysUtils_Rand() & 0xFFF;
                turn = (s32) (((f32) (SysUtils_Rand() & 0x3FFF) * 14.0f) / 16383.0) - 7;
                D_800D47C8 = turn;
            }
            Water_StampPoint(D_800D47CC, D_800D47D0, -50);
        }
        Water_UpdateWindow(0, 0.0f, 0.0f);
        return;
    }
    if (gPlayers == TWO_PLAYERS) {
        func_80050B78(&gCameraPerspective[1], &x, &z);
        Water_UpdateWindow(1, x, z);
    }
    func_80050B78(gCameraPerspective, &x, &z);
    Water_UpdateWindow(0, x, z);
}
