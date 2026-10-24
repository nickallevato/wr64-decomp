#include "global.h"

typedef struct UnkStruct_801603E0_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ s32 unk1C;
} UnkStruct_801603E0; /* size = 0x20 */

extern UnkStruct_801603E0 D_80160400[];
extern UnkStruct_801603E0 D_801603E0[];
extern UnkStruct_801603E0 D_80158520[];
extern Vec3f D_80158450[];

extern s32 D_1000140;
extern s32 D_10001E0;
extern s32 D_800D4650;
extern s32 D_800D4658[];
extern Mtx D_8011F860;
extern Mtx D_8011F8A0;
extern s16 D_8011F8AA;

void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8004AE88(struct UnkStruct_8004B0F8* arg0);

void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 sp6C[15];
    f32 temp_f0_3;
    f32 var_f20;
    s32 i;

    var_f20 = 0.0f;

    for (i = arg0->unk28; i >= 0; i--) {
        f32 temp_f0 = arg0->unk30[i].unk0 - arg1;
        f32 temp_f2 = arg0->unk30[i].unk4 - arg2;
        f32 temp_f14 = arg0->unk30[i].unk8 - arg3;
        temp_f0 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        sp6C[i] = temp_f0;
        if (var_f20 < temp_f0) {
            var_f20 = sp6C[i];
        }
    }

    temp_f0_3 = ((arg0->unk8 - arg0->unk4) / var_f20);
    for (i = arg0->unk28; i >= 0; i--) {
        arg0->unk30[i].unk18 = (sp6C[i] * temp_f0_3) + arg0->unk4;
    }
}

void func_8004ADEC(struct UnkStruct_8004B0F8* arg0) {
    f32* var_a2;
    UnkStruct_8004B0F8_unk34* var_v0;
    f32 var_f0;

    var_f0 = (0.5f / ((arg0->unk20 * (arg0->unk28 - 1)) + 1.0f));

    var_v0 = &arg0->unk34[arg0->unk2C];
    var_a2 = &arg0->unk38[arg0->unk2C];

    while (var_v0 >= arg0->unk34) {
        var_v0->unk8 = *var_a2 * var_f0;
        var_v0--, var_a2--;
    }
}

void func_8004AE88(struct UnkStruct_8004B0F8* arg0) {
    UnkStruct_8004B0F8_1* temp_v0_2;
    UnkStruct_8004B0F8_1* temp_v1_2;
    UnkStruct_8004B0F8_unk34* var_s0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f14;
    f32 temp_fs0;
    f32 temp_f2;
    f32* var_s1;
    s32 temp_v1;

    temp_fs0 = 0.5f / (arg0->unk20 * (arg0->unk28 - 1) + 1.0f);
    var_s0 = &arg0->unk34[arg0->unk2C];
    arg0->unk3C = 99999.9f;
    arg0->unk40 = 0.0f;
    var_s1 = &arg0->unk38[arg0->unk2C];

    while (var_s0 >= arg0->unk34) {
        temp_v0_2 = var_s0->unk0;
        temp_v1_2 = var_s0->unk4;
        temp_f0 = temp_v1_2->unk0 - temp_v0_2->unk0;
        temp_f2 = temp_v1_2->unk4 - temp_v0_2->unk4;
        temp_f14 = temp_v1_2->unk8 - temp_v0_2->unk8;
        temp_f0_2 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        *var_s1 = temp_f0_2;
        if (temp_f0_2 < arg0->unk3C) {
            arg0->unk3C = *var_s1;
        }
        if (arg0->unk40 < *var_s1) {
            arg0->unk40 = *var_s1;
        }
        var_s0->unk8 = (f32) (*var_s1 * temp_fs0);
        var_s0--;
        var_s1--;
    }
}

void func_8004AFE8(struct UnkStruct_8004B0F8* arg0, s32 arg1, s32 arg2) {
    s32 var_a1;
    s32 var_v1;
    UnkStruct_8004B0F8_unk34* var_v0;

    var_v0 = arg0->unk34;
    var_v1 = arg1;

    while (arg2 - 1 >= var_v1) {
        for (var_a1 = var_v1 + 1; var_a1 <= arg2; var_a1++, var_v0++) {
            var_v0->unk0 = &arg0->unk30[var_v1];
            var_v0->unk4 = &arg0->unk30[var_a1];
        }
        var_v1++;
    }
}

void func_8004B0F8(struct UnkStruct_8004B0F8* arg0) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    f32 var_f2;
    struct UnkStruct_8004B0F8_1* var_v0;

    var_f0 = 0.0f;
    var_f2 = 0.0f;
    var_f12 = 0.0f;
    arg0->unk64 = 0.0f;
    arg0->unk60 = 0.0f;
    arg0->unk5C = 0.0f;
    arg0->unk58 = 0.0f;
    arg0->unk54 = 0.0f;
    arg0->unk50 = 0.0f;
    arg0->unk68 = 0.0f;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        var_v0->unk14 = 0.0f;
        var_v0->unk10 = 0.0f;
        var_v0->unkC = 0.0f;
        var_v0->unk1C = 0.0f;

        var_f12 += var_v0->unk0;
        var_f2 += var_v0->unk4;
        var_f0 += var_v0->unk8;
    }

    var_f14 = arg0->unk28 + 1;

    arg0->unk44 = (f32) (var_f12 / var_f14);
    arg0->unk48 = (f32) (var_f2 / var_f14);
    arg0->unk4C = (f32) (var_f0 / var_f14);
}

// One step of the point-and-link body: moves each point by its velocity times unkC (saving the old position in
// D_80158450), runs unk24 rounds of link corrections, then sets the velocities from the moves, the centre
// (unk44..unk4C), its change (unk50..unk58) and that change's length and direction (unk68, unk5C..unk64).
#ifdef NON_MATCHING
// Same loops and calls; register allocation differs (the original keeps the point pointer in s1 throughout, 12 in s5
// from the start, and other float registers), and its frame is 0x10 smaller. Score 8621.
void func_8004B1B4(struct UnkStruct_8004B0F8* arg0) {
    UnkStruct_8004B0F8_1* pt;
    UnkStruct_8004B0F8_unk34* link;
    UnkStruct_8004B0F8_1* b;
    Vec3f* prev;
    s32 n;
    f32 dt;
    f32 k;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 s;
    f32 fx;
    f32 fy;
    f32 fz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 d;
    f32 count;
    f32 old;
    f32 len2;
    f32 len;

    dt = arg0->unkC;
    for (pt = &arg0->unk30[arg0->unk28], prev = &D_80158450[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--, prev--) {
        pt->unk0 = (prev->x = pt->unk0) + (dt * pt->unkC);
        pt->unk4 = (prev->y = pt->unk4) + (dt * pt->unk10);
        pt->unk8 = (prev->z = pt->unk8) + (dt * pt->unk14);
    }
    k = 0.5f / ((arg0->unk20 * (arg0->unk28 - 1)) + 1.0f);
    for (n = arg0->unk24; n != 0; n--) {
        for (pt = &arg0->unk30[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--) {
            pt->unk14 = 0.0f;
            pt->unk10 = 0.0f;
            pt->unkC = 0.0f;
        }
        for (link = &arg0->unk34[arg0->unk2C]; (u32) link >= (u32) arg0->unk34; link--) {
            pt = link->unk0;
            b = link->unk4;
            dx = b->unk0 - pt->unk0;
            dy = b->unk4 - pt->unk4;
            dz = b->unk8 - pt->unk8;
            s = (link->unk8 / sqrtf(SQ(dx) + SQ(dy) + SQ(dz))) - k;
            fx = dx * s;
            fy = dy * s;
            fz = dz * s;
            b->unkC += fx;
            b->unk10 += fy;
            b->unk14 += fz;
            pt->unkC -= fx;
            pt->unk10 -= fy;
            pt->unk14 -= fz;
        }
        for (pt = &arg0->unk30[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--) {
            pt->unk0 += pt->unkC;
            pt->unk4 += pt->unk10;
            pt->unk8 += pt->unk14;
        }
    }
    sx = 0.0f;
    sz = 0.0f;
    sy = 0.0f;
    prev = &D_80158450[arg0->unk28];
    for (pt = &arg0->unk30[arg0->unk28]; (u32) pt >= (u32) arg0->unk30; pt--, prev--) {
        sx += pt->unk0;
        sy += pt->unk4;
        sz += pt->unk8;
        dx = pt->unk0 - prev->x;
        dy = pt->unk4 - prev->y;
        dz = pt->unk8 - prev->z;
        d = (1.0f - pt->unk18) * ((dx * arg0->unk5C) + (dy * arg0->unk60) + (dz * arg0->unk64));
        pt->unkC = (arg0->unk5C * d) + (pt->unk18 * dx);
        pt->unk10 = (arg0->unk60 * d) + (pt->unk18 * dy);
        pt->unk14 = (arg0->unk64 * d) + (pt->unk18 * dz);
    }
    count = arg0->unk28 + 1;
    old = arg0->unk44;
    arg0->unk44 = sx / count;
    dx = arg0->unk44 - old;
    arg0->unk50 = dx;
    old = arg0->unk48;
    arg0->unk48 = sy / count;
    dy = arg0->unk48 - old;
    arg0->unk54 = dy;
    old = arg0->unk4C;
    arg0->unk4C = sz / count;
    dz = arg0->unk4C - old;
    arg0->unk58 = dz;
    len2 = SQ(dx) + SQ(dy) + SQ(dz);
    if (len2 != 0.0f) {
        len = sqrtf(len2);
        arg0->unk68 = len;
        arg0->unk5C = dx / len;
        arg0->unk60 = dy / len;
        arg0->unk64 = dz / len;
    } else {
        arg0->unk64 = 0.0f;
        arg0->unk60 = 0.0f;
        arg0->unk5C = 0.0f;
        arg0->unk68 = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_5480/func_8004B1B4.s")
#endif

void func_8004B680(void) {
}

void func_8004B684(void) {
}

UNUSED void stub_5480(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_5484(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_5488(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_548C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8004B6E0(void) {
    s32 temp_s1;
    s32 temp_s2;
    s32 var_v0;

    if (D_800DAB1C == 1) {
        D_801603E0->unk0 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x260) >> 0x10) - 0x90;
        D_80160400->unk0 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x260) >> 0x10) - 0x90;
        D_801603E0->unk4 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x190) >> 0x10) - 0x50;
        D_80160400->unk4 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x190) >> 0x10) - 0x50;
    } else {
        D_801603E0->unk0 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0x130) >> 0xE) + 8;
        D_801603E0->unk4 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0xC8) >> 0xE) + 0x14;
        do {
            D_80160400->unk0 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0x130) >> 0xD) - 0x90;
            D_80160400->unk4 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0xC8) >> 0xD) - 0x50;
        } while ((D_80160400->unk0 >= 8) && (D_80160400->unk0 < 0x138) && (D_80160400->unk4 >= 0x14) &&
                 (D_80160400->unk4 < 0xDC));
    }

    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        D_80158520[var_v0].unk0 = (s32) (((var_v0 % 39) * 8) + 8);
        D_80158520[var_v0].unk4 = (s32) (((var_v0 / 39) * 8) + 0x14);
    }
    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        D_80158520[var_v0].unk10 = 0;
        D_80158520[var_v0].unk14 = 0;
        D_80158520[var_v0].unk8 = D_80158520[var_v0].unk0;
        D_80158520[var_v0].unkC = D_80158520[var_v0].unk4;
    }
    D_801603E0->unk8 = D_801603E0->unk0;
    D_801603E0->unkC = D_801603E0->unk4;
    D_801603E0->unk10 = D_801603E0->unk14 = 0;
    D_80160400->unk8 = D_80160400->unk0;
    D_80160400->unkC = D_80160400->unk4;
    D_80160400->unk10 = D_80160400->unk14 = 0;

    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        temp_s1 = D_80158520[var_v0].unk8 - D_801603E0->unk8;
        temp_s2 = D_80158520[var_v0].unkC - D_801603E0->unkC;
        D_80158520[var_v0].unk18 = (sqrtf((SQ(temp_s1) + SQ(temp_s2))) + 0.5);
        temp_s1 = D_80158520[var_v0].unk8 - D_80160400->unk8;
        temp_s2 = D_80158520[var_v0].unkC - D_80160400->unkC;
        D_80158520[var_v0].unk1C = (sqrtf((SQ(temp_s1) + SQ(temp_s2))) + 0.5);
    }
}

void func_8004BA18(void) {
    GfxPool* poolIter;
    s32 i;
    s32 j;
    s32 temp_lo;
    s32 temp_hi;
    s32 temp_v1;
    s32 temp_a0;
    Vtx* vtx;

    for (i = 0; i < 2; i++) {
        poolIter = &D_8011F8E8[i];

        for (j = 0; j < 0x3F6; j++) {
            temp_hi = j % 39;
            temp_lo = j / 39;

            temp_v1 = temp_hi * 8;
            temp_a0 = temp_lo * 8;

            vtx = &poolIter->unkFE08[j];

            vtx->v.ob[0] = temp_v1 + 8;
            vtx->v.ob[1] = temp_a0 + 0x14;
            vtx->v.ob[2] = 0;
            vtx->v.tc[0] = (temp_v1 * 0x59) + 0x2F4;
            vtx->v.tc[1] = (temp_a0 * 0x59) + 0x720;

            if (temp_hi == 38) {
                vtx->v.tc[0] -= 0xDE;
            }
            if (temp_lo == 25) {
                vtx->v.tc[1] -= 0xDE;
            }

            if (i == 0) {
                vtx->v.cn[0] = SysUtils_Rand() & 0xFF;
                vtx->v.cn[1] = SysUtils_Rand() & 0xFF;
                vtx->v.cn[2] = SysUtils_Rand() & 0xFF;
            } else {
                vtx->v.cn[0] = D_8011F8E8[0].unkFE08[j].v.cn[0];
                vtx->v.cn[1] = D_8011F8E8[0].unkFE08[j].v.cn[1];
                vtx->v.cn[2] = D_8011F8E8[0].unkFE08[j].v.cn[2];
            }
            vtx->v.cn[3] = 0xFF;
        }
    }

    guOrtho(&D_8011F860, -160.0f, 160.0f, -120.0f, 120.0f, 0.0f, 2.0f, 1.0f);
    guTranslate(&D_8011F8A0, -160.0f, 120.0f, -1.0f);

    D_8011F8AA = -1;
    func_8004B6E0();
}

Gfx* func_8004BC40(Gfx* gdl) {
    gSPDisplayList(gdl++, &D_1000140);
    gDPSetFillColor(gdl++, D_800D4658[D_800D4650]);
    gSPDisplayList(gdl++, &D_10001E0);
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_5480/func_8004BC98.s")
