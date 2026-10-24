#include "global.h"

typedef struct UnkStruct_801D0798_unk1AA0_s {
    /* 0x00 */ f32 unk0;  /* inferred */
    /* 0x04 */ f32 unk4;  /* inferred */
    /* 0x08 */ f32 unk8;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ f32 unk14; /* inferred */
    /* 0x18 */ f32 unk18; /* inferred */
    /* 0x1C */ f32 unk1C; /* inferred */
    /* 0x20 */ f32 unk20; /* inferred */
    /* 0x24 */ s32 unk24; /* inferred */
    /* 0x28 */ s32 unk28; /* inferred */
    /* 0x2C */ char pad2C[4];
} UnkStruct_801D0798_unk1AA0; /* size = 0x30 */

typedef struct UnkStruct_801D0798_unk0_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char pad18[0x18];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ char pad34[0x4];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
} UnkStruct_801D0798_unk0; /* size = 0x40 */

typedef struct UnkStruct_801D0798_unk1000_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ char padC[0xC];
    /* 0x18 */ f32 unk18;
    /* 0x1C */ char pad1C[0x4];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
} UnkStruct_801D0798_unk1000; /* size = 0x28 */

typedef struct UnkStruct_801D0798_s {
    /* 0x0000 */ UnkStruct_801D0798_unk0 unk0[64];
    /* 0x1000 */ UnkStruct_801D0798_unk1000 unk1000[64];
    /* 0x1A00 */ UnkStruct_801D0798_unk1000 unk1A00[4];
    /* 0x1AA0 */ UnkStruct_801D0798_unk1AA0 unk1AA0[8];
    /* 0x1C20 */ s32 unk1C20;
    /* 0x1C24 */ s32 unk1C24;
    /* 0x1C28 */ char pad1C28[0x4];
    /* 0x1C30 */ s32 unk1C2C;
    /* 0x1C34 */ s32 unk1C30;
    char pad1C34[0x4];
    /* 0x1C3C */ s32 unk1C38;
    /* 0x1C40 */ s32 unk1C3C;
    s32 unk1C40;
    /* 0x1C48 */ s32 unk1C44;
    /* 0x1C4C */ s32 unk1C48;
    char pad1C4C[0x4];
    /* 0x1C54 */ s32 unk1C50;
    /* 0x1C58 */ s32 unk1C54;
    /* 0x1C5C */ s32 unk1C58;
    /* 0x1C60 */ s32 unk1C5C;
    /* 0x1C64 */ s32 unk1C60;
    char pad1C64[0x4];
    /* 0x1C6C */ f32 unk1C68;
    /* 0x1C70 */ f32 unk1C6C;
    /* 0x1C74 */ char pad1C74[4];
} UnkStruct_801D0798; /* size = 0x1C78 */

typedef struct UnkStruct_800E6D90_s {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} UnkStruct_800E6D90;

// The file's .bss, 0x801D0790..0x801D7B6F, in address order.
s32 D_801D0790;
UnkStruct_801D0798 D_801D0798[4];
struct camera_unk_1* D_801D7968;
struct camera_unk_1* D_801D796C;
struct camera_unk_1* D_801D7970;
f32 D_801D7974;
f32 D_801D7978;
f32 D_801D797C;
f32 D_801D7980;
f32 D_801D7984;
f32 D_801D7988;
f32 D_801D798C;
f32 D_801D7990;
f32 D_801D7994;
f32 D_801D7998;
f32 D_801D799C;
f32 D_801D79A0;
f32 D_801D79A4;
f32 D_801D79A8;
f32 D_801D79AC;
f32 D_801D79B0;
f32 D_801D79B4;
f32 D_801D79B8;
f32 D_801D79BC;
f32 D_801D79C0;
f32 D_801D79C4;
f32 D_801D79C8;
f32 D_801D79CC;
f32 D_801D79D0;
f32 D_801D79D4;
f32 D_801D79D8;
f32 D_801D79DC;
f32 D_801D79E0;
f32 D_801D79E4;
f32 D_801D79E8;
f32 D_801D79EC;
f32 D_801D79F0;
f32 D_801D79F4;
f32 D_801D79F8;
f32 D_801D79FC;
f32 D_801D7A00;
s32 D_801D7A04;
s32 D_801D7A08;
s32 D_801D7A0C;
s32 D_801D7A10;
s32 D_801D7A14;
UnkStruct_801D7A18 D_801D7A18[8];
s32 D_801D7AD8;
s32 D_801D7ADC;
f32 D_801D7AE0;
f32 D_801D7AE4;
f32 D_801D7AE8;
UnkStruct_801D7AF0 D_801D7AF0[2];
s32 D_801D7B10;
u64 D_801D7B18;
u64 D_801D7B20;
u64 D_801D7B28;
u64 D_801D7B30;
s64 D_801D7B38;
s64 D_801D7B40;
s64 D_801D7B48;
s64 D_801D7B50;
s64 D_801D7B58;
s32 D_801D7B60;
s32 D_801D7B64;
s32 D_801D7B68;

extern UnkStruct_801D0798* D_800E6D60;
extern UnkStruct_801D0798_unk1AA0* D_800E6D7C;
extern s32 D_800E6D84;
extern s32 D_800E6D88;
extern s32 D_800E6D8C;
extern s32 D_800E6DB4;
extern s32 D_1049C80;
extern s32 D_104A488;
extern s32 D_104AC90;
extern s32 D_104B498;
extern s32 D_104BCA0;
extern s32 D_104C4A8;
extern s32 D_104CCB0;
extern s32 D_10514D0;
extern s32 D_1051580;
extern s32 D_800E6D84;
extern s32 D_800E6D88;
extern s32 D_800E6D8C;
extern s32 D_801AE950;
extern s32 D_80223934;

extern UnkStruct_800E6D90 D_800E6D90[];
extern UnkStruct_80198368 D_80198368[];

// External functions
f32 Math_FloatRand(f32);
void func_801EE97C(Mtx*, f32, f32, f32);
f32 func_8004D30C(f32 arg0, f32 arg1);

// File functions
void func_800B43BC(Gfx** gdl, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u32 arg5);

void func_800AE210(s32 rider) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f14;
    f32 temp_f2;
    StructVarS0* temp_v0; // Real
    UnkStruct_80192690* temp_v0_2;
    UnkStruct_801D0798* var_v1;

    if ((D_801D7A08 != 0) && (gRiders == rider)) {
        temp_v0 = &D_801CF060[D_801D7A04]; // Struct wise..
        D_801D79C8 = temp_v0->unk24;
        D_801D79CC = temp_v0->unk28;
        D_801D79D0 = temp_v0->unk2C;
        D_801D79E0 = temp_v0->unk30;
        D_801D79E4 = temp_v0->unk34;
        D_801D79E8 = temp_v0->unk38;
        D_801D79EC = -temp_v0->unk38;
        D_801D79F0 = temp_v0->unk34;
        D_801D79F4 = temp_v0->unk30;

        var_v1 = &D_801D0798[rider];
        D_801D79BC = temp_v0->unk64 + (96.0f * D_801D79E0);
        D_801D79C0 = temp_v0->unk68 - 5.0f;
        D_801D79C4 = temp_v0->unk6C + (96.0f * D_801D79E8);
        D_801D79DC = 0.0f;
        D_801D7A0C = 0;
        D_801D79FC = 0.0f;
        D_801D79F8 = D_801D79FC;
        var_v1->unk1C54 = 0;
        D_801D7A10 = 0;
    } else {
        temp_v0_2 = &D_80192690[rider];
        D_801D79BC = temp_v0_2->unk44.x;
        D_801D79C0 = temp_v0_2->unk44.y - 8.0f;
        D_801D79C4 = temp_v0_2->unk44.z;
        D_801D79C8 = temp_v0_2->unkB78;
        D_801D79CC = temp_v0_2->unkB7C;
        D_801D79D0 = temp_v0_2->unkB80;
        D_801D79E0 = temp_v0_2->unk6C;
        D_801D79E4 = temp_v0_2->unk70;
        D_801D79E8 = temp_v0_2->unk74;
        D_801D79EC = -temp_v0_2->unk84;
        D_801D79F0 = -temp_v0_2->unk88;
        D_801D79F4 = -temp_v0_2->unk8C;
        temp_f0 = temp_v0_2->unk1618 - temp_v0_2->unk50;
        temp_f2 = temp_v0_2->unk161C - temp_v0_2->unk54;
        temp_f14 = temp_v0_2->unk1620 - temp_v0_2->unk58;
        D_801D79DC = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        D_801D7A0C = (s32) temp_v0_2->unk16E0;
        D_801D79F8 = temp_v0_2->unkBF0;
        D_801D79FC = temp_v0_2->unkBF4;
        if ((D_801D7A14 != 0) && (temp_v0_2->unkC4C > 0.0f) &&
            (((func_8004D30C(D_801D79BC, D_801D79C4) + 4.0f) < D_801D79C0))) {
            D_801D0798[rider].unk1C54 = 1;
        } else {
            D_801D0798[rider].unk1C54 = 0;
        }
        D_801D7A10 = temp_v0_2->unk16CC;
        if (D_801D7A10 != 0) {
            D_801D79C0 += 2.0f;
        }
    }

    D_801D79D4 = sqrtf(SQ(D_801D79C8) + SQ(D_801D79CC) + SQ(D_801D79D0));
    if (D_801D0798[rider].unk1C54 == 0) {
        D_801D7A00 = func_8004D30C(D_801D79BC, D_801D79C4);
        if (D_801D79C0 <= D_801D7A00) {
            D_801D0798[rider].unk1C58 = 0;
        }
    } else {
        D_801D79C0 -= 2.0f;
        D_801D0798[rider].unk1C58 = 1;
        D_801D7A00 = D_801D79C0 + 12.0f;
    }

    temp_f0_2 = sqrtf(SQ(D_801D79EC) + SQ(D_801D79F4));
    if (temp_f0_2 > 0.0f) {
        float expr1 = (D_801D79EC / temp_f0_2);
        float expr2 = (D_801D79F4 / temp_f0_2);
        D_801D79D8 = (D_801D79C8 * expr1) + (D_801D79D0 * expr2);

        D_801D79D8 = FABS(D_801D79D8);

    } else {
        D_801D79D8 = sqrtf(SQ(D_801D79C8) + SQ(D_801D79D0));
    }
}


void func_800AE7C4(void) {
    s32 j;
    s32 k;
    s32 i;
    s32 view;
    Vtx* vtx;

    if (D_800E6DB4 != 0) {
        D_800E6DB4 = 0;
    }
    D_801D0790 = gRiders;
    Math_srand();
    D_801D7B20 = D_801D7B30 = D_801D7B28 = 0;
    D_801D7B40 = D_801D7B50 = D_801D7B48 = 0;
    D_801D7B58 = 0;
    D_801D7B60 = 0;
    D_801D7B68 = 0;
    D_801D7A08 = D_801D7A04 = 0;
    if (gCourseID == DOLPHIN_PARK) {
        D_801D7A08 = 1;
        for (j = 0; j < 0x1E; j++) {
            if (D_801CF060[j].unk0 == 6) {
                D_801D7A04 = j;
                break;
            }
        }
        if (D_801D0790 < 4) {
            D_801D0790++;
        }
    }
    D_800E6D84 = D_800E6D90[gCourseID].unk0;
    D_800E6D88 = D_800E6D90[gCourseID].unk1;
    D_800E6D8C = D_800E6D90[gCourseID].unk2;
    switch (gCourseID) {
        case DOLPHIN_PARK:
        case SUNNY_BEACH:
        case SUNSET_BAY:
        case TWILIGHT_CITY:
        case GLACIER_COAST:
            D_801D7A14 = 1;
            break;
        default:
            D_801D7A14 = 0;
            break;
    }

    for (i = 0; i < D_801D0790; i++) {
        D_800E6D60 = &D_801D0798[i];
        for (j = 63; j >= 0; j--) {
            D_800E6D60->unk0[j].unk38 = 0;
        }
        for (j = 63; j >= 0; j--) {
            D_800E6D60->unk1000[j].unk20 = 0;
        }
        for (j = 3; j >= 0; j--) {
            D_800E6D60->unk1A00[j].unk20 = 0;
        }
    }

    for (i = 0; i < D_801D0790; i++) {
        func_800AE210(i);
        D_800E6D60 = &D_801D0798[i];
        D_800E6D60->unk1C68 = 0.0f;
        D_800E6D60->unk1C6C = 0.0f;
        D_800E6D60->unk1C3C = 0;

        D_800E6D60->unk1C2C = D_800E6D60->unk1C30 = (D_801D79C0 <= D_801D7A00);

        D_800E6D60->unk1C40 = D_800E6D60->unk1C44 = D_800E6D60->unk1C48 = 0;
        D_800E6D60->unk1C38 = 0;
        D_800E6D60->unk1C50 = 0;
        D_800E6D60->unk1C58 = 0;
        D_800E6D60->unk1C54 = D_800E6D60->unk1C58;
        D_800E6D60->unk1C60 = 0;
        D_800E6D60->unk1C5C = D_800E6D60->unk1C60;
        D_800E6D7C = D_800E6D60->unk1AA0;

        for (j = 0; j < 8; j++, D_800E6D7C++) {
            D_800E6D7C->unk24 = 1;
            D_800E6D7C->unk28 = 0;
            D_800E6D7C->unk0 = D_800E6D7C->unkC = D_801D79BC;
            D_800E6D7C->unk4 = D_800E6D7C->unk10 = D_801D79C0;
            D_800E6D7C->unk8 = D_800E6D7C->unk14 = D_801D79C4;
            D_800E6D7C->unk18 = D_800E6D7C->unk1C = D_800E6D7C->unk20 = 0;
        }
    }
    for (view = 0; view < 2; view++) {

        for (i = 0; i < 4; i++) {
            vtx = D_80198368[view].unk51C0[i];
            for (j = 0; j < 0xC0; j++) {
                k = j % 3;
                if (k == 0) {
                    vtx->v.tc[0] = 0x3C0;
                    vtx->v.tc[1] = 0x954;
                } else {
                    if (k == 1) {
                        vtx->v.tc[0] = -0x13C;
                        vtx->v.tc[1] = 0;
                    } else {
                        vtx->v.tc[0] = 0x8BC;
                        vtx->v.tc[1] = 0;
                    }
                }

                vtx->v.flag = 0;
                vtx->v.cn[0] = 0xFF;
                vtx->v.cn[1] = 0xFF;
                vtx->v.cn[2] = 0xFF;
                vtx++;
            }

            if (i == 0) {
                vtx = D_80198368[view].unk81C0;
                for (j = 0; j < 0xC0; j++) {
                    k = j % 3;
                    if (k == 0) {
                        vtx->n.tc[0] = 0;
                        vtx->n.tc[1] = 0x7C0;
                    } else if (k == 1) {
                        vtx->n.tc[0] = 0xFC0;
                        vtx->n.tc[1] = 0x7C0;
                    } else {
                        vtx->n.tc[0] = 0;
                        vtx->n.tc[1] = -0x800;
                    }
                    vtx->v.flag = 0;
                    vtx->v.cn[0] = 0xFF;
                    vtx->v.cn[1] = 0xFF;
                    vtx->v.cn[2] = 0xFF;
                    vtx++;
                }
            }
            vtx = D_80198368[view].unk8DC0[i];
            for (j = 0; j < 16; j++) {
                k = j % 4;
                if (k == 0) {
                    vtx->v.tc[0] = 0;
                    vtx->v.tc[1] = 0x7C0;
                } else if (k == 1) {
                    vtx->v.tc[0] = 0x7C0;
                    vtx->v.tc[1] = 0x7C0;
                } else {
                    if (k == 2) {
                        vtx->v.tc[0] = 0x7C0;
                        vtx->v.tc[1] = 0;
                    } else {
                        vtx->v.tc[0] = 0;
                        vtx->v.tc[1] = 0;
                    }
                }
                vtx->v.flag = 0;
                vtx->v.cn[0] = 0xFF;
                vtx->v.cn[1] = 0xFF;
                vtx->v.cn[2] = 0xFF;
                vtx->v.cn[3] = 0xFF;
                vtx++;
            }

            vtx = D_80198368[view].unk91C0[i];
            for (j = 0; j < 16; j++) {
                if (j & 1) {
                    vtx->v.tc[0] = 0;
                } else {
                    vtx->v.tc[0] = 0x7C0;
                }

                vtx->v.tc[1] = ((((j / 2) * 0x3F) / 7) << 6);

                vtx->v.flag = 0;
                vtx->v.cn[0] = 0xFF;
                vtx->v.cn[1] = 0xFF;
                vtx->v.cn[2] = 0xFF;
                vtx->v.cn[3] = 0xFF;
                vtx++;
            }
        }
    }
    for (j = 0; j < 8; j++) {
        D_801D7A18[j].unk0 = 0;
    }
    D_801D7AD8 = D_801D7ADC = 0;
    D_801D7AE0 = D_801D7AE4 = D_801D7AE8 = 0.0f;
    for (j = 0; j < 2; j++) {
        D_801D7AF0[j].unk0 = 0;
        D_801D7AF0[j].unk4 = D_801D7AF0[j].unk8 = D_801D7AF0[j].unkC = 0.0f;
    }
    D_801D7B10 = 0;
}

void func_800AF40C(f32 arg0, f32 arg1, f32 arg2) {
    D_801D7ADC = 4;
    D_801D7AE0 = arg0;
    D_801D7AE4 = arg1;
    D_801D7AE8 = arg2;
}

void func_800AF43C(f32 arg0, f32 arg1, f32 arg2) {
    UnkStruct_801D7AF0* temp_v0;

    temp_v0 = &D_801D7AF0[D_801D7B10];
    temp_v0->unk0 = 4;
    temp_v0->unk4 = arg0;
    temp_v0->unk8 = arg1;
    temp_v0->unkC = arg2;
    D_801D7B10++;
    D_801D7B10 %= 2;
}

void func_800AF4A0(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    struct UnkStruct_801D7A18* temp_v0;

    temp_v0 = &D_801D7A18[D_801D7AD8];
    temp_v0->unk0 = 1;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = arg0;
    temp_v0->unkC = arg1;
    temp_v0->unk10 = arg2;
    temp_v0->unk14 = arg3;
    D_801D7AD8++;
    D_801D7AD8 %= 8;
}

void func_800AF51C(void) {
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s32 i;

    if (D_801D7ADC > 0) {
        D_801D7ADC -= 1;
        temp_f24 = Math_FloatRand(32.0f);
        temp_f20 = Math_FloatRand(4.0f);

        func_800AF4A0((0, temp_f24) + (D_801D7AE0 - 16.0f), (0, temp_f20) + (D_801D7AE4 - 2.0f),
                      Math_FloatRand(32.0f) + (D_801D7AE8 - 16.0f), ((f32) D_801D7ADC * 0.2f) + 1.2f);
    }

    for (i = 0; i < 2; i++) {
        if (D_801D7AF0[i].unk0 > 0) {
            D_801D7AF0[i].unk0--;
            temp_f22 = Math_FloatRand(32.0f);
            temp_f24 = Math_FloatRand(4.0f);
            temp_f20 = Math_FloatRand(32.0f);
            func_800AF4A0((D_801D7AF0[i].unk4 - 16.0f) + (0, temp_f22), // FAKE
                          (D_801D7AF0[i].unk8 - 2.0f) + (0, temp_f24), (D_801D7AF0[i].unkC - 16.0f) + (0, temp_f20),
                          Math_FloatRand(2.0f) + 2);
        }
    }

    for (i = 0; i < 8; i++) {
        UnkStruct_801D7A18* ptr = &D_801D7A18[i];
        if (ptr->unk0) {
            ptr->unk4++;

            if (ptr->unk4 >= 8) {
                ptr->unk0 = 0;
            }
        }
    }
}

void func_800AF798(Gfx** gdl) {
    s32* var_a2;
    camera_unk_1* var_s3;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fs0;
    f32 var_fv0;
    f32 var_fv1;
    Gfx* gdlh;
    MtxF spD8;
    s32 i;
    f32 ft1;
    f32 temp_fs2;

    gdlh = *gdl;
    gSPDisplayList(gdlh++, &D_10514D0);
    gDPSetCombineLERP(gdlh++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                      SHADE, 0);
    gDPSetRenderMode(gdlh++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetEnvColor(gdlh++, D_800E6D84, D_800E6D88, D_800E6D8C, 0xFF);
    if (D_800DAB2C == 0) {
        var_s3 = &gCameraPerspective[D_80223930];
    } else {
        var_s3 = &gCameraPerspective[D_80223934];
    }
    for (i = 0; i < 8; i++) {
        if (D_801D7A18[i].unk0 == 0) {
            continue;
        }

        temp_fa0 = var_s3->unk4C - D_801D7A18[i].unk8;
        temp_fs2 = var_s3->unk50 - D_801D7A18[i].unkC;
        temp_fa1 = var_s3->unk54 - D_801D7A18[i].unk10;

        // fake match
        if (temp_fa0 == temp_fa1) {}
        if (temp_fa0 == temp_fa1) {}

        if ((temp_fa0 != 0.0f) || (temp_fa1 != 0.0f)) {
            var_fv0 = 1.0f;
            var_fv1 = 0.0f;
        } else {
            var_fv0 = 0.0f;
            var_fv1 = 1.0f;
        }
        SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spD8, temp_fa0, temp_fs2, temp_fa1, 0.0f, var_fv0,
                              var_fv1, D_801D7A18[i].unk8, D_801D7A18[i].unkC, D_801D7A18[i].unk10);

        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_801EE97C(&D_801AE948->unk4140[D_801AE950], D_801D7A18[i].unk14, D_801D7A18[i].unk14, D_801D7A18[i].unk14);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        switch (D_801D7A18[i].unk4) {
            default:
            case 1:
                var_a2 = &D_1049C80;
                break;
            case 2:
                var_a2 = &D_104A488;
                break;
            case 3:
                var_a2 = &D_104AC90;
                break;
            case 4:
                var_a2 = &D_104B498;
                break;
            case 5:
                var_a2 = &D_104BCA0;
                break;
            case 6:
                var_a2 = &D_104C4A8;
                break;
            case 7:
                var_a2 = &D_104CCB0;
                break;
        }
        gDPLoadTextureBlock(gdlh++, var_a2, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPDisplayList(gdlh++, &D_1051580);
    }
    *gdl = gdlh;
}

extern UnkStruct_801D0798_unk0* D_800E6D64;
extern UnkStruct_801D0798_unk0* D_800E6D68;
extern UnkStruct_801D0798_unk1000* D_800E6D6C;
extern UnkStruct_801D0798_unk1000* D_800E6D70;
extern UnkStruct_801D0798_unk1000* D_800E6D74;
extern UnkStruct_801D0798_unk1000* D_800E6D78;
extern UnkStruct_801D0798_unk1AA0* D_800E6D80;
extern struct camera_unk_1* D_801D796C;
extern struct camera_unk_1* D_801D7970;

void func_801EDAE0(f32, f32, f32, f32, f32, f32, f32*, f32*, f32*);

#ifdef NON_MATCHING
// 11460: same loops, calls and stores. Register allocation and scheduling differ from the
// first loop on (the original keeps 0xFF, 24 and the side-vector addresses in saved registers
// and spills more); the frame is 0xD0, not 0xE8.
void func_800AFBD0(s32 arg0) {
    f32 sideX;
    f32 sideY;
    f32 sideZ;
    s32 i;
    s32 alpha;
    f32 size;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    f32 h;
    f32 x;
    f32 y;
    f32 z;
    Vtx* vtx;

    // Records of unk0, oldest first: a three-vertex streak along the record's velocity.
    D_800E6D60->unk1C20 = 0;
    vtx = D_801AE948->unk51C0[arg0];
    for (i = 63, D_800E6D64 = &D_800E6D68[63]; i >= 0; i--, D_800E6D64--) {
        if (D_800E6D64->unk38 != 0) {
            alpha = 0xFF - (D_800E6D64->unk3C * 24);
            if (alpha < 0) {
                alpha = 0;
            }
            size = D_800E6D64->unk30;
            if ((D_801D7A08 != 0) && (arg0 == gRiders)) {
                size *= 2.0f;
            }
            dx = D_800E6D64->unkC;
            dy = D_800E6D64->unk10;
            dz = D_800E6D64->unk14;
            len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
            if (len > 0.0f) {
                dx /= len;
                dy /= len;
                dz /= len;
            }
            h = size * 1.2f;
            vtx->v.ob[0] = D_800E6D64->unk0 + (h * dx);
            vtx->v.ob[1] = D_800E6D64->unk4 + (h * dy);
            vtx->v.cn[3] = alpha;
            vtx->v.ob[2] = D_800E6D64->unk8 + (h * dz);
            vtx++;
            func_801EDAE0(D_800E6D64->unk0 - D_801D796C->unk4C, D_800E6D64->unk4 - D_801D796C->unk50,
                          D_800E6D64->unk8 - D_801D796C->unk54, dx, dy, dz, &sideX, &sideY, &sideZ);
            h = size * 0.5f;
            x = h * sideX;
            vtx->v.ob[0] = x + D_800E6D64->unk0;
            y = h * sideY;
            vtx->v.ob[1] = y + D_800E6D64->unk4;
            z = h * sideZ;
            vtx->v.cn[3] = alpha;
            vtx->v.ob[2] = z + D_800E6D64->unk8;
            vtx++;
            vtx->v.ob[0] = D_800E6D64->unk0 - x;
            vtx->v.ob[1] = D_800E6D64->unk4 - y;
            vtx->v.cn[3] = alpha;
            vtx->v.ob[2] = D_800E6D64->unk8 - z;
            vtx++;
            D_800E6D60->unk1C20++;
        }
    }
    // The same streaks for the second view's camera.
    if (gPlayers == TWO_PLAYERS) {
        vtx = D_801AE948->unk51C0[arg0 + 2];
        for (i = 63, D_800E6D64 = &D_800E6D68[63]; i >= 0; i--, D_800E6D64--) {
            if (D_800E6D64->unk38 != 0) {
                alpha = 0xFF - (D_800E6D64->unk3C * 24);
                if (alpha < 0) {
                    alpha = 0;
                }
                size = D_800E6D64->unk30;
                vtx->v.cn[3] = alpha;
                dx = D_800E6D64->unkC;
                dy = D_800E6D64->unk10;
                dz = D_800E6D64->unk14;
                len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                if (len > 0.0f) {
                    dx /= len;
                    dy /= len;
                    dz /= len;
                }
                h = size * 1.2f;
                vtx->v.ob[0] = D_800E6D64->unk0 + (h * dx);
                vtx->v.ob[1] = D_800E6D64->unk4 + (h * dy);
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = D_800E6D64->unk8 + (h * dz);
                vtx++;
                func_801EDAE0(D_800E6D64->unk0 - D_801D7970->unk4C, D_800E6D64->unk4 - D_801D7970->unk50,
                              D_800E6D64->unk8 - D_801D7970->unk54, dx, dy, dz, &sideX, &sideY, &sideZ);
                h = size * 0.5f;
                vtx->v.ob[0] = D_800E6D64->unk0 + (h * sideX);
                vtx->v.ob[1] = D_800E6D64->unk4 + (h * sideY);
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = D_800E6D64->unk8 + (h * sideZ);
                vtx++;
                vtx->v.ob[0] = D_800E6D64->unk0 - (h * sideX);
                vtx->v.ob[1] = D_800E6D64->unk4 - (h * sideY);
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = D_800E6D64->unk8 - (h * sideZ);
                vtx++;
            }
        }
    }
    // Records of unk1000, only for the human's slot: a triangle facing the camera (D_801D7980/8C).
    D_800E6D60->unk1C24 = 0;
    if (arg0 == D_800D48DC) {
        vtx = D_801AE948->unk81C0;
        for (i = 63, D_800E6D6C = &D_800E6D70[63]; i >= 0; i--, D_800E6D6C--) {
            if (D_800E6D6C->unk20 != 0) {
                size = D_800E6D6C->unk18;
                alpha = 0xFF - (D_800E6D6C->unk24 << 5);
                if (alpha < 0) {
                    alpha = 0;
                }
                x = D_800E6D6C->unk0;
                y = D_800E6D6C->unk4;
                z = D_800E6D6C->unk8;
                vtx->v.ob[0] = x;
                vtx->v.ob[1] = y;
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = z;
                vtx++;
                vtx->v.ob[0] = (D_801D7980 * size) + x;
                vtx->v.ob[1] = (D_801D7984 * size) + y;
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = (D_801D7988 * size) + z;
                vtx++;
                vtx->v.ob[0] = (D_801D798C * size) + x;
                vtx->v.ob[1] = (D_801D7990 * size) + y;
                vtx->v.cn[3] = alpha;
                vtx->v.ob[2] = (D_801D7994 * size) + z;
                vtx++;
                D_800E6D60->unk1C24++;
            }
        }
    }
    // Records of unk1A00: a camera-facing square each.
    vtx = D_801AE948->unk8DC0[arg0];
    for (i = 0, D_800E6D74 = D_800E6D78; i < 4; i++, D_800E6D74++) {
        if (D_800E6D74->unk20 != 0) {
            size = D_800E6D74->unk18;
            if ((D_801D7A08 != 0) && (arg0 == gRiders)) {
                size *= 2.0f;
            }
            h = size / 2.0f;
            x = D_800E6D74->unk0 - (h * (D_801D7980 + D_801D798C));
            y = D_800E6D74->unk4 - (h * (D_801D7984 + D_801D7990));
            z = D_800E6D74->unk8 - (h * (D_801D7988 + D_801D7994));
            vtx->v.ob[0] = x;
            vtx->v.ob[1] = y;
            vtx->v.ob[2] = z;
            vtx++;
            vtx->v.ob[0] = (size * D_801D7980) + x;
            vtx->v.ob[1] = (size * D_801D7984) + y;
            vtx->v.ob[2] = (size * D_801D7988) + z;
            vtx++;
            vtx->v.ob[0] = ((D_801D7980 + D_801D798C) * size) + x;
            vtx->v.ob[1] = ((D_801D7984 + D_801D7990) * size) + y;
            vtx->v.ob[2] = ((D_801D7988 + D_801D7994) * size) + z;
            vtx++;
            vtx->v.ob[0] = (size * D_801D798C) + x;
            vtx->v.ob[1] = (size * D_801D7990) + y;
            vtx->v.ob[2] = (size * D_801D7994) + z;
            vtx++;
        }
    }
    if (gPlayers == TWO_PLAYERS) {
        vtx = D_801AE948->unk8DC0[arg0 + 2];
        for (i = 0, D_800E6D74 = D_800E6D78; i != 4; i++, D_800E6D74++) {
            if (D_800E6D74->unk20 != 0) {
                size = D_800E6D74->unk18;
                h = size / 2.0f;
                x = D_800E6D74->unk0 - (h * (D_801D79A4 + D_801D79B0));
                y = D_800E6D74->unk4 - (h * (D_801D79A8 + D_801D79B4));
                z = D_800E6D74->unk8 - (h * (D_801D79AC + D_801D79B8));
                vtx->v.ob[0] = x;
                vtx->v.ob[1] = y;
                vtx->v.ob[2] = z;
                vtx++;
                vtx->v.ob[0] = (size * D_801D79A4) + x;
                vtx->v.ob[1] = (size * D_801D79A8) + y;
                vtx->v.ob[2] = (size * D_801D79AC) + z;
                vtx++;
                vtx->v.ob[0] = ((D_801D79A4 + D_801D79B0) * size) + x;
                vtx->v.ob[1] = ((D_801D79A8 + D_801D79B4) * size) + y;
                vtx->v.ob[2] = ((D_801D79AC + D_801D79B8) * size) + z;
                vtx++;
                vtx->v.ob[0] = (size * D_801D79B0) + x;
                vtx->v.ob[1] = (size * D_801D79B4) + y;
                vtx->v.ob[2] = (size * D_801D79B8) + z;
                vtx++;
            }
        }
    }
    // The eight unk1AA0 records, newest first from unk1C38: two vertices each.
    vtx = D_801AE948->unk91C0[arg0];
    for (i = 7; i >= 0; i--) {
        D_800E6D7C = &D_800E6D80[(D_800E6D60->unk1C38 + i) % 8];
        vtx->v.ob[0] = D_800E6D7C->unk0;
        vtx->v.ob[1] = D_800E6D7C->unk4;
        vtx->v.cn[3] = 0xFF;
        vtx->v.ob[2] = D_800E6D7C->unk8;
        vtx++;
        vtx->v.ob[0] = D_800E6D7C->unkC;
        vtx->v.ob[1] = D_800E6D7C->unk10;
        vtx->v.cn[3] = 0xFF;
        vtx->v.ob[2] = D_800E6D7C->unk14;
        vtx++;
        D_800E6D7C->unk28++;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_68A10/func_800AFBD0.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_68A10/func_800B08F8.s")

void func_801EDBD4(f32, f32, f32, f32*, f32*, f32*);
void func_800AFBD0(s32);
void func_800B08F8(s32);

#ifdef NON_MATCHING
// 8560: same blocks and calls. Here &gCameraPerspective and 0x10C stay in saved registers
// (multu), where the original rebuilds each camera address with shifts and keeps the
// D_800E6D60..D_800E6D80 addresses in s2-s7 instead; the frame is 0x80, not 0x78.
void func_800B2ABC(void) {
    s32 i;
    UnkStruct_801D0798* e;
    struct camera_unk_1* other;
    struct camera_unk_1* cam;

    D_801D7B18 = osGetTime();

    D_801D7968 = &gCameraPerspective[D_80223930];
    func_801EDBD4(D_801D7968->unk64, D_801D7968->unk68, D_801D7968->unk6C, &D_801D7974, &D_801D7978, &D_801D797C);
    if ((D_801D7968->unk64 != 0.0f) || (D_801D7968->unk6C != 0.0f)) {
        func_801EDAE0(D_801D7968->unk64, D_801D7968->unk68, D_801D7968->unk6C, 0.0f, 1.0f, 0.0f, &D_801D7980,
                      &D_801D7984, &D_801D7988);
        func_801EDAE0(D_801D7980, D_801D7984, D_801D7988, D_801D7968->unk64, D_801D7968->unk68, D_801D7968->unk6C,
                      &D_801D798C, &D_801D7990, &D_801D7994);
    } else {
        D_801D7984 = 0.0f;
        D_801D7988 = 0.0f;
        D_801D7980 = 1.0f;
        D_801D798C = 0.0f;
        D_801D7990 = 0.0f;
        D_801D7994 = 1.0f;
    }
    if (gPlayers == TWO_PLAYERS) {
        D_801D7968 = &gCameraPerspective[D_80223934];
        func_801EDBD4(D_801D7968->unk64, D_801D7968->unk68, D_801D7968->unk6C, &D_801D7998, &D_801D799C,
                      &D_801D79A0);
        if ((D_801D7968->unk64 != 0.0f) || (D_801D7968->unk6C != 0.0f)) {
            func_801EDAE0(D_801D7968->unk64, D_801D7968->unk68, D_801D7968->unk6C, 0.0f, 1.0f, 0.0f, &D_801D79A4,
                          &D_801D79A8, &D_801D79AC);
            func_801EDAE0(D_801D79A4, D_801D79A8, D_801D79AC, D_801D7968->unk64, D_801D7968->unk68,
                          D_801D7968->unk6C, &D_801D79B0, &D_801D79B4, &D_801D79B8);
        } else {
            D_801D79A8 = 0.0f;
            D_801D79AC = 0.0f;
            D_801D79A4 = 1.0f;
            D_801D79B0 = 0.0f;
            D_801D79B4 = 0.0f;
            D_801D79B8 = 1.0f;
        }
    }
    for (i = 0, e = D_801D0798; i < D_801D0790; i++, e++) {
        D_800E6D60 = e;
        D_800E6D68 = e->unk0;
        D_800E6D70 = e->unk1000;
        D_800E6D78 = e->unk1A00;
        D_800E6D80 = e->unk1AA0;
        func_800AE210(i);
        if ((gPlayers == ONE_PLAYER) || ((gPlayers == TWO_PLAYERS) && (i != D_800D48E0))) {
            D_801D7968 = cam = &gCameraPerspective[D_80223930];
            other = &gCameraPerspective[D_80223934];
        } else {
            D_801D7968 = other = &gCameraPerspective[D_80223934];
            cam = &gCameraPerspective[D_80223930];
        }
        D_801D796C = cam;
        D_801D7970 = other;
        if (gCurrentPauseMenuOption == -1) {
            func_800B08F8(i);
        }
        func_800AFBD0(i);
    }
    D_801D7B18 = osGetTime() - D_801D7B18;
    D_801D7B28 += D_801D7B18;
    D_801D7B30++;
    if (D_801D7B18 > D_801D7B20) {
        D_801D7B20 = D_801D7B18;
    }
    func_800AF51C();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_68A10/func_800B2ABC.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_68A10/func_800B305C.s")

void func_800B43BC(Gfx** gdl, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u32 arg5) {
    camera_unk_1* temp_t0;
    f32 temp_f14;
    f32 temp_f16;
    f32 var_f0;
    f32 var_f2;
    s32* var_a3;
    f32 other;
    Gfx* gdlh;
    char pad[0x4];
    MtxF sp74;

    gdlh = *gdl;
    gSPDisplayList(gdlh++, &D_10514D0);
    gDPSetCombineLERP(gdlh++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                      SHADE, 0);
    gDPSetRenderMode(gdlh++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    gDPSetEnvColor(gdlh++, D_800E6D84, D_800E6D88, D_800E6D8C, 0xFF);
    temp_t0 = &gCameraPerspective[D_80223930];
    temp_f14 = temp_t0->unk4C - arg1;
    other = temp_t0->unk50 - arg2;
    temp_f16 = temp_t0->unk54 - arg3;
    if ((temp_f14 != 0.0f) || (temp_f16 != 0.0f)) {
        var_f0 = 1.0f;
        var_f2 = 0.0f;
    } else {
        var_f2 = 1.0f;
        var_f0 = 0.0f;
    }
    SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &sp74, temp_f14, other, temp_f16, 0.0f, var_f0, var_f2,
                          arg1, arg2, arg3);
    gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_801EE97C(&D_801AE948->unk4140[D_801AE950], arg4, arg4, arg4);
    gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    D_801AE950 += 1;
    switch (arg5) {
        default:
        case 0:
            var_a3 = &D_1049C80;
            break;
        case 1:
            var_a3 = &D_104A488;
            break;
        case 2:
            var_a3 = &D_104AC90;
            break;
        case 3:
            var_a3 = &D_104B498;
            break;
        case 4:
            var_a3 = &D_104BCA0;
            break;
        case 5:
            var_a3 = &D_104C4A8;
            break;
        case 6:
            var_a3 = &D_104CCB0;
            break;
    }
    gDPLoadTextureBlock(gdlh++, var_a3, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPDisplayList(gdlh++, &D_1051580);
    *gdl = gdlh;
}
