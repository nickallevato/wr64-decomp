#include "global.h"

typedef struct UnkStruct_801C3B90 {
    /* 0x0 */ f32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ s32 unk8;
} UnkStruct_801C3B90; // size = 0xC

extern s16 D_800D9640[32];
extern UnkStruct_801C3B90 D_801C3B90[16];
extern UnkStruct_80192420 gWaterWindow[];
extern Gfx D_E010F28[];
extern Mtx D_2000A40[];
extern u8 D_3000000[];

f32 func_8004D30C(f32, f32);

// Places D_801C3B90 at D_800D9640's sixteen positions with random angles, and sets the texture coordinates of the
// vertices at GfxPool + 0x185E8 in both pools (eight per entry).
void func_8007FD80(void) {
    s32 i;
    s32 j;
    Vtx* v;

    for (i = 0; i < 16; i++) {
        D_801C3B90[i].unk0 = D_800D9640[i << 1];
        D_801C3B90[i].unk4 = D_800D9640[(i << 1) + 1];
        D_801C3B90[i].unk8 = SysUtils_Rand() & 0xFFF;
    }
    for (j = 1; j >= 0; j--) {
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

// In Port Blue, draws each D_801C3B90 entry inside the water window (gWaterWindow[0]) as eight vertices at its angle,
// on the water height (func_8004D30C), and six triangles.
Gfx* func_8007FFA8(Gfx* gdl) {
    UnkStruct_801C3B90* p;
    Vtx* v;
    s32 i;
    s32 pad[4]; // stack pad: the frame is 0x98 as in the original
    f32 ax;
    f32 az;
    f32 bx;
    f32 bz;
    f32 x;
    f32 z;
    f32 dx;
    f32 dz;

    if (gCourseID != PORT_BLUE) {
        return gdl;
    }
    gSPDisplayList(gdl++, D_E010F28);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    do { // FAKE (permuter): moves i to the original's saved register
        i = 0;
    } while (0);
    // FAKE (line join, found by the permuter): IDO schedules by source line; with p's set-up on the loop's first
    // line, p's address (s2) is set up after the other loop-invariant addresses, as in the original
    p = D_801C3B90; do {
        dx = p->unk0 - gWaterWindow[0].unk8;
        dz = p->unk4 - gWaterWindow[0].unkC;
        if (!(gWaterWindow[0].unk10 <= dx * dx + dz * dz)) {
            dx = gSinTable[(p->unk8 + 0x400) & 0xFFF];
            ax = 26.24f * dx;
            dz = gSinTable[p->unk8 & 0xFFF];
            az = 26.24f * dz;
            bx = -17.28f * dz;
            bz = 17.28f * dx;
            v = &gGfxPool->unk170D8[0x151 + i];
            v[3].v.ob[0] = x = p->unk0 - ax;
            v[3].v.ob[2] = z = p->unk4 - az;
            v[3].v.ob[1] = func_8004D30C(x, z);
            v[0].v.ob[0] = dx = x - bx;
            v[0].v.ob[2] = dz = z - bz;
            v[0].v.ob[1] = func_8004D30C(dx, dz);
            v[5].v.ob[0] = dx = x + bx;
            v[5].v.ob[2] = dz = z + bz;
            v[5].v.ob[1] = func_8004D30C(dx, dz);
            v[1].v.ob[0] = dx = p->unk0 - bx;
            v[1].v.ob[2] = dz = p->unk4 - bz;
            v[1].v.ob[1] = func_8004D30C(dx, dz);
            v[6].v.ob[0] = dx = p->unk0 + bx;
            v[6].v.ob[2] = dz = p->unk4 + bz;
            v[6].v.ob[1] = func_8004D30C(dx, dz);
            v[4].v.ob[0] = x = p->unk0 + ax;
            v[4].v.ob[2] = z = p->unk4 + az;
            v[4].v.ob[1] = func_8004D30C(x, z);
            v[2].v.ob[0] = dx = x - bx;
            v[2].v.ob[2] = dz = z - bz;
            v[2].v.ob[1] = func_8004D30C(dx, dz);
            v[7].v.ob[0] = dx = x + bx;
            v[7].v.ob[2] = dz = z + bz;
            v[7].v.ob[1] = func_8004D30C(dx, dz);
            gSPVertex(gdl++, &((GfxPool*) D_3000000)->unk170D8[0x151 + i], 8, 0);
            gSP1Triangle(gdl++, 0, 3, 1, 0);
            gSP1Triangle(gdl++, 1, 3, 6, 0);
            gSP1Triangle(gdl++, 6, 3, 5, 0);
            gSP1Triangle(gdl++, 6, 7, 4, 0);
            gSP1Triangle(gdl++, 6, 4, 1, 0);
            gSP1Triangle(gdl++, 1, 4, 2, 0);
        }
        i += 8;
        p++;
    } while ((u32) p < (u32) &D_801C3B90[16]);
    return gdl;
}
