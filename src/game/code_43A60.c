#include "global.h"
#include "rider.h"

struct unk_D_801C3C60 {
    struct unk_D_801C3C58* unk0;
    char pad[0x4C];
    int unk5C;
    char pad1[0x94];
};

struct UnkStruct_801C2C70 {
    s32 unk0;
    char pad[0x374];
};

struct UnkStruct_801CB058 {
    char pad[0xC0];
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    char padCC[0x3C];
    f32 unk108;
};

void func_800890B4(void);

extern s32 gPlayer1Rider;
extern s32 D_801C26C0[];
extern struct unk_D_801C3C60 D_801C3C60[];
extern s32 D_801C4100[];
extern s32 D_800D476C;
extern s32 D_800D4770;
extern s8 D_800D9888;
extern s32 D_800D98CC;
extern s32 D_800D98D0;
extern s32 D_800D98D4;
extern u8 D_800E5150[2][4];
extern struct UnkStruct_801C2C70 D_801C2C70[];
extern struct UnkStruct_801CB058 D_801CB058;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern Vtx D_801C4698[][0x363];
extern Vtx D_801C46C8[][0x363];

extern s32 D_801C4110;
extern s32 D_801C4118[];

void func_80088EA0(void) {
}

#ifdef NON_MATCHING
// Score 225 / 13100 (330 in an earlier measurement). Same blocks and calls. The original takes the rand index
// (srl a0) through three copies (a1, v0, a0) before the lookup; this C uses two (a1, v1, a0) and is one
// instruction shorter, so the rand/loop registers differ (the address immediates in the diff only move with the size).
void func_80088EA8(void) {
    s32 var_s4;
    s32 var_s6;
    s32 rand_seed;

    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C4100[D_801C26C0[var_s4]] = var_s4;
    }
    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C3C58->unk60 = 1.0f;
    }
    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[var_s4];
        D_801C3C58->unk5C = -1;
    }
    for (var_s6 = var_s4 = 0; var_s4 < (gRiders - 1); var_s6++, var_s4++) {
        rand_seed = (SysUtils_Rand(), SysUtils_Rand() / 256) % 4; // What?

        while (D_801C3C58 = (struct_801C3C58*) &D_801C3C60[rand_seed],
               D_801C3C58->unk5C != -1 || rand_seed == gPlayer1Rider) {
            rand_seed = (rand_seed % gRiders) + 1;
        }
        D_801C3C58->unk5C = var_s6;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43A60/func_80088EA8.s")
#endif

// Sets up the four D_801C3C60 entries from the riders (D_80192690) and func_80088EA8, picks up to three random
// entries for unk80[i], colours the vertices at D_801C4698/D_801C46C8 in both frame-buffer blocks, and lists the
// D_801BC940 entries whose unk4C is 1 in D_801C4118 (count D_801C4110).
#ifdef NON_MATCHING
// The two vertex loops are strength-reduced (a pointer += 0x10) where the original indexes with i << 4, and the
// D_801C3C58 = &D_801C3C60[3] store goes through s1 instead of lui at; v0/v1 swap in the first loop. Score 1285.
void func_800890B4(void) {
    s32 i;
    s32 j;
    Vtx* va;
    Vtx* vb;

    for (i = 0; i < 4; i++) {
        D_801C3C50 = (struct UnkStruct_801C3C50*) &D_80192690[i];
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[i];
        D_801C3C58->unk0 = i;
        D_801C3C58->currentRider = D_801C3C50->unkB68;
        D_801C3C58->unk74 = 1;
        D_801C3C58->unk8C = 0;
        D_801C3C58->unkAC = 0;
        D_801C3C58->unkB0 = 0;
        D_801C3C58->unkB4 = 1;
        D_801C3C58->pad58 = 0;
        D_801C3C58->unkA0 = 0;
        D_801C3C58->unkD8 = 0;
        D_801C3C58->unkDC[0] = 0;
        switch (D_801C3C50->unkB64) {
            case 0:
            case 1:
            case 2:
                D_801C3C58->unk64 = 32.0f;
                break;
            case 3:
                D_801C3C58->unk64 = 24.0f;
                break;
        }
    }
    func_80088EA8();
    for (i = 0; i < 4; i++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[i];
        for (j = 0; j < 3; j++) {
            D_801C3C58->unk80[j] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((SysUtils_Rand(), SysUtils_Rand() / 256) % 4 == 0) {
            D_801C3C58 = (struct_801C3C58*) &D_801C3C60[(SysUtils_Rand(), SysUtils_Rand() / 256) % 4];
            D_801C3C58->unk80[i] = 1;
        }
    }
    D_801C3C58 = (struct_801C3C58*) &D_801C3C60[3];
    for (i = 0; i < 3; i++) { // empty: the original counts to 3 here too
    }
    for (j = 0; j < 2; j++) {
        va = D_801C4698[j];
        vb = D_801C46C8[j];
        for (i = 0; i < 3; i++) {
            va[i].v.cn[0] = 0xFF;
            va[i].v.cn[1] = 0;
            va[i].v.cn[2] = 0;
            va[i].v.cn[3] = 0xFF;
        }
        for (i = 0; i < 4; i++) {
            vb[i].v.ob[1] = 0;
            vb[i].v.cn[0] = 0xFF;
            vb[i].v.cn[1] = 0xFF;
            vb[i].v.cn[2] = 0xFF;
        }
        D_801C4110 = 0;
        for (i = 0; i < D_801BFA40; i++) {
            if (D_801BC940[i].unk4C == 1) {
                D_801C4118[D_801C4110++] = i;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43A60/func_800890B4.s")
#endif

void func_800893A8(void) {
    func_800890B4();
    D_800D476C = D_801CB058.unkC4;
    D_800D4770 = D_801CB058.unkC8;
    if (gCourseID == DRAKE_LAKE) {
        D_800D9888 = 1;
        D_801CB058.unk108 = 0.0f;
    } else {
        D_800D9888 = 0;
    }
    switch (D_800E5150[gDifficulty][D_801C2C70[gPlayer1Rider].unk0]) {
        case 0x8F:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x90:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x91:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x92:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x93:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x94:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x95:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
        default:
            break;
    }
}
