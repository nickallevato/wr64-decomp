#include "global.h"
#include "macros.h"
#include "camera.h"

typedef struct UnkStruct_800E60DC_s {
    void* (*unk0)(void*);
    s16 unk4;
} UnkStruct_800E60DC;

typedef struct UnkStruct_801CED60_s {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
    /* 0x2 */ s8 unk2; /* inferred */
    /* 0x3 */ s8 unk3;
    /* 0x4 */ s16 unk4; /* inferred */
    /* 0x6 */ s16 unk6; /* inferred */
    /* 0x8 */ s16 unk8; /* inferred */
} UnkStruct_801CED60;   /* size = 0xA */

typedef struct UnkStruct_800998B0 {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ s8 unk2;
    /* 0x4 */ s16 unk4[3];
} UnkStruct_800998B0; /* size = 0xA */

typedef struct UnkStruct_801CEBE0 {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ s32 pad18;
    /* 0x1C */ u8 unk1C;
    s32 pad;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ Vec3f unk30;
    /* 0x3C */ Vec3f unk3C;
} UnkStruct_801CEBE0; /* size = 0x48 */

typedef struct UnkStruct_80099858 {
    char unk0;
    char unk1;
    char unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
} UnkStruct_80099858;

typedef struct UnkStruct_80099858_1 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} UnkStruct_80099858_1;

typedef struct UnkStruct_801CF008 {
    f32 unk0;
    char pad[0x14];
} UnkStruct_801CF008;

typedef struct UnkStruct_801CF058 {
    char pad[0x1C];
    s16 unk20;
    f32 unk22;
    char pad1[0x64];
    f32 unk88;
} UnkStruct_801CF058;

typedef struct UnkStruct_8009BB98 {
    s32 unk0;
    f32 y;
    s32 unk8;
    s32 unkC;
    f32 unk10;
} UnkStruct_8009BB98;

typedef struct UnkStruct_80099D94 {
    /* 0x00 */ char pad0[0x4C];
    /* 0x4C */ f32 unk4C; /* inferred */
    /* 0x50 */ f32 unk50; /* inferred */
    /* 0x54 */ f32 unk54; /* inferred */
    /* 0x58 */ f32 unk58;
    /* 0x5C */ char pad5C[8]; /* maybe part of unk58[3]? */
    /* 0x64 */ f32 unk64;     /* inferred */
    /* 0x68 */ s32 unk68;
    /* 0x6C */ char pad6C[4];
    /* 0x70 */ f32 unk70; /* inferred */
    /* 0x74 */ f32 unk74; /* inferred */
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
} UnkStruct_80099D94;

typedef struct UnkStruct_801CF0D8_s {
    /* 0x00 */ s32 unk0;        /* inferred */
    /* 0x04 */ char pad4[0xB8]; /* maybe part of unk0[0x2F]? */
} UnkStruct_801CF0D8;           /* size = 0xBC */

extern u8 D_801CEAA6[];
extern struct UnkStruct_801CEBE0 D_801CEBE0[];
extern f32 D_801CEFE0[];
extern s16 D_801CEFE8[];
extern s16 D_801CEFEC[];
extern u8 D_801CEFF0[];
extern s32 gPlayer1Rider;
extern s16 D_800DAA00;
extern s32 D_800E5138;
extern u8 D_800E514C;
extern u8 D_801CEAA8;
extern s32 D_800E56AC;
extern s32 D_800E56E0;
extern struct UnkStruct_801CF008 D_801CF008[];
extern struct UnkStruct_801CF058* D_801CF058[];
extern s32 D_801D06B8;
extern UnkStruct_801CED60 D_801CED60[32];
extern UnkStruct_801CED60 D_801CEEA0[32];
extern f32 D_801D075C;
extern f32 D_801D0760;
extern f32 D_801D0768;
extern f32 D_801D06D4;
extern s32 D_800E62C4;
extern f32 D_801D0764;
extern s32 gPlayer2Rider;
extern s32 D_801CEAA0;
extern UnkStruct_801CEFF8 D_801CEC70[10];
extern UnkStruct_801CEFF8 D_801CEC7C[10];
extern RiderStruct D_801C2C70[];
extern UnkStruct_8009A04C D_801CEB48;
extern s16 D_801CE776;
extern s16 D_801CE778;
extern Mtx D_801D0678;
extern UnkStruct_801CE780 D_801CE780[];
extern UnkStruct_801CF0D8 D_801CF0D8[];
extern Gfx D_800E6CA0[];
extern Gfx D_800E6CF8[];
extern s16 D_801CE774;
extern s16 D_801CE768[];
extern s16 D_801CE76A;
extern s16 D_801CE76C;
extern s16 D_801CE76E;
extern s16 D_801CE770;
extern s32 D_801D0738;

//.data
extern s32 gPlayer2Rider;
extern s32 D_801CEAA0;
extern UNK_TYPE D_800E581C;
extern UNK_TYPE D_800E58B4;
extern s32 D_800E62C8;
extern s32 D_800E62CC;
extern u8 D_800E5150[MAX_DIFFICULTY][MAX_CHAMPIONSHIP_LAPS + 1];
extern s16 D_801CEA9C[];

f32 func_801ED154(f32, f32);
f32 func_801ED090(f32);
f32 func_8009D3AC(f32, f32);
f32 func_8009D564(f32);
void func_8009D5C0(void);
Gfx* func_800916B4(Gfx*);
Gfx* func_8009DB90(Gfx*, s32);
Gfx* func_8009DC10(Gfx*, s32);
Gfx* func_8009E794(Gfx*, s32);
Gfx* func_8009E814(Gfx*, s32);
Gfx* func_8009F398(Gfx*, s32);
Gfx* func_8009FCB0(Gfx*, s32);
Gfx* func_800A063C(Gfx*, s32);
Gfx* func_800A10E4(Gfx*, s32);
Gfx* func_800A16F0(Gfx*, s32);
Gfx* func_800A1CFC(Gfx*, s32);
Gfx* func_800A2308(Gfx*, s32);
Gfx* func_800A28F4(Gfx*, s32);
s32 func_800ADC8C(s32);
void func_800ADD14(void);
void func_800A2B24(s32);
// File declarations
f32 Water_GetHeight(f32, f32);
void func_8009A97C(UnkStruct_801CF060* arg0);
void func_8009A4DC(UnkStruct_801CF060* arg0);
void func_8009A9FC(UnkStruct_801CF060* arg0);
void func_8009B130(UnkStruct_801CF060* arg0);
void func_80099B20(f32*, f32);
s32 func_80099514(s32 arg0, s32 arg1, UnkStruct_801CED60* arg2, s16* arg3, f32* arg4);
void func_800998B0(UnkStruct_801CED60* arg0, UnkStruct_800998B0* arg1, s32 arg2);
void func_8009B650(UnkStruct_801CF060* arg0, f32 arg1, f32 arg2);
void func_8009AD74(UnkStruct_801CF060*);
void func_8009C814(UnkStruct_8009A04C*, s32);
void func_8009A1CC(UnkStruct_8009A04C*, f32);
void func_8009934C(f32 t, Vec3f* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6);
u8 func_8009CD50(UnkStruct_func_8009CCE8*);
u8 func_8009CB70(UnkStruct_801CF060* arg0, UnkStruct_func_8009CCE8* arg1);
void func_801E4C60(Mtx*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

// Declarations for the functions and data of code_52CD0.c, the first object of the old file.
extern s32 gWaterLevel;
extern UNK_TYPE D_800E515C;
extern UNK_TYPE D_800E51A4;
extern UNK_TYPE D_800E51EC;
extern UNK_TYPE D_800E5228;
extern UNK_TYPE D_800E5264;
extern UNK_TYPE D_800E528C;
extern UNK_TYPE D_800E52B4;
extern UNK_TYPE D_800E52E8;
extern RiderStruct D_801C293C[];
extern UNK_TYPE D_800E5714;
extern UNK_TYPE D_800E573C;
extern UNK_TYPE D_800E5764;
extern UNK_TYPE D_800E5798;
extern UNK_TYPE D_800E57CC;
extern UNK_TYPE D_800E57F4;
extern UnkStruct_801CF008 D_801CEFFC[];
extern f32 D_800E5130;
extern s32 D_801CE638;
extern UnkStruct_800E60DC D_800E60DC[10];
extern UnkStruct_800E60DC D_800E60E4[];
extern UnkStruct_800E60DC D_800E60EC[];
extern UnkStruct_800E60DC D_800E60F4[];
extern UnkStruct_800E60DC D_800E60FC[];
extern UnkStruct_800E60DC D_800E6104[];
extern UnkStruct_800E60DC D_800E6114[];
extern UnkStruct_800E60DC D_800E6124[];
extern UnkStruct_800E60DC D_800E618C[];
extern UnkStruct_800E60DC D_800E61A4[];
extern UnkStruct_800E60DC D_800E61CC[];
extern UnkStruct_800E60DC D_800E61E4[];
extern UnkStruct_800E60DC D_800E61FC[];
extern UnkStruct_800E60DC D_800E6214[];
extern UnkStruct_800E60DC D_800E622C[];

f32 Math_Fabs(f32 x);
void Math_Vec3f_Set(Vec3f* vec, f32 x, f32 y, f32 z);
void Math_Vec3f_Initialize(Vec3f* vec);
void Math_Vec3f_Copy(Vec3f* dest, Vec3f* src);
UNUSED void Math_Vec3s_Copy(Vec3s* dest, Vec3s* src);
UNUSED void func_80098564(void);
UNUSED void stub(void);
void func_80098574(Vec3f* dest, Vec3f* src, s32 arg2);
void func_80098644(Vec3f* dest, Vec3f* src, s32 arg2);
s32 func_80098714(f32* arg0, f32 arg1, f32 arg2);
s32 func_80098774(s16* arg0, s16 arg1, s16 arg2);
s32 func_80098820(f32* arg0, f32 arg1, f32 arg2);
void func_800988D8(s32 arg0);
f32 func_80098918(s32 arg0);
f32 func_8009898C(s32 arg0);
void func_800989E0(Vec3f* arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_80098A5C(void);
void func_80098A64(void);
void func_80098AC4(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_80098BFC(void);
void func_80098C04(Vec3f* arg0, s32 arg1, s8 arg2);
void func_80098DE0(Vec3f* vec);
void Math_Vec3f_Substract(Vec3f* dest, Vec3f* vec1, Vec3f* vec2);
void func_80098E70(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, s32 arg3);
void func_80098FF8(Vec3f* arg0, Vec3f* arg1, f32* arg2, f32* arg3, f32* arg4);
void func_800990A8(Vec3f* src, Vec3f* dest, f32 radius, f32 pitch, f32 yaw);
void func_8009917C(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
void func_8009934C(f32 t, Vec3f* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6);
s32 func_80099514(s32 arg0, s32 arg1, UnkStruct_801CED60* arg2, s16* arg3, f32* arg4);
void func_80099858(struct UnkStruct_80099858* arg0, s8 arg1, u8 arg2, s16 arg3, s16* arg4, s32 arg5);
void func_800998B0(UnkStruct_801CED60* arg0, UnkStruct_800998B0* arg1, s32 arg2);
s32 func_80099A00(UnkStruct_801CF060* arg0, void* arg1, void* arg2, s32 arg3);
void func_80099AD8(s32 arg0, void* arg1, f32 arg2, f32 arg3, f32 arg4);
void func_80099B20(f32* arg0, f32 arg1);
void func_80099BBC(s32 arg0, UnkStruct_801CF060* arg1, UnkStruct_801CF060* arg2);
void func_80099D94(UnkStruct_80099D94* arg0, UnkStruct_80099D94* arg1);
void func_8009A04C(s32 arg0, s16 arg1);
void func_8009A1CC(UnkStruct_8009A04C* arg0, f32 arg1);
void func_8009A2E4(UnkStruct_8009A04C* arg0);
void func_8009A404(char arg0, s16 arg1);
s32 func_8009A460(void (*arg0)(UnkStruct_801CF060*), UnkStruct_801CF060* arg1, s16 arg2, s16 arg3);
void func_8009A4DC(UnkStruct_801CF060* arg0);
void func_8009A520(UnkStruct_801CF060* arg0);
void func_8009A554(UnkStruct_801CF060* arg0);
void func_8009A6AC(UnkStruct_801CF060* arg0);
void func_8009A764(UnkStruct_801CF060* arg0);
void func_8009A7A8(UnkStruct_801CF060* arg0);
void func_8009A818(UnkStruct_801CF060* arg0);
void func_8009A844(UnkStruct_801CF060* arg0);
void func_8009A8C8(UnkStruct_801CF060* arg0);
void func_8009A8F4(UnkStruct_801CF060* arg0);
void func_8009A97C(UnkStruct_801CF060* arg0);
void func_8009A9FC(UnkStruct_801CF060* arg0);
void func_8009AA24(UnkStruct_801CF060* arg0);
void func_8009AB20(UnkStruct_801CF060* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8009AC50(UnkStruct_801CF060* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4);
void func_8009AD14(UnkStruct_801CF060* arg0);
void func_8009AD3C(UnkStruct_801CF060* arg0);
void func_8009AD74(UnkStruct_801CF060* arg0);
void func_8009ADA8(UnkStruct_801CF060* arg0);
void func_8009AE6C(UnkStruct_801CF060* arg0);
void func_8009AE94(UnkStruct_801CF060* arg0);
void func_8009AF14(UnkStruct_801CF060* arg0);
void func_8009AF64(UnkStruct_801CF060* arg0);
void func_8009AFA0(UnkStruct_801CF060* arg0);
void func_8009B030(UnkStruct_801CF060* arg0);
void func_8009B0C8(UnkStruct_801CF060* arg0);
void func_8009B100(void);
void func_8009B108(UnkStruct_801CF060* arg0);
void func_8009B130(UnkStruct_801CF060* arg0);
void func_8009B178(s32 arg0);
void func_8009B19C(s32 arg0);
void func_8009B250(UnkStruct_801CF060* arg0);
void func_8009B2B8(UnkStruct_801CF060* arg0);
void func_8009B33C(UnkStruct_801CF060* arg0);
void func_8009B3F4(UnkStruct_801CF060* arg0);
void func_8009B4AC(UnkStruct_801CF060* arg0);
void func_8009B530(UnkStruct_801CF060* arg0);
void func_8009B57C(UnkStruct_801CF060* arg0);
void func_8009B650(UnkStruct_801CF060* arg0, f32 arg1, f32 arg2);
void func_8009B824(UnkStruct_801CF060* arg0);
void func_8009B89C(UnkStruct_801CF060* arg0);
void func_8009B910(UnkStruct_801CF060* arg0);
void func_8009BA14(UnkStruct_801CF060* arg0);
void func_8009BAE0(UnkStruct_801CF060* arg0);
void func_8009BB98(struct UnkStruct_801CF060* arg0);
void func_8009BCA4(UnkStruct_801CF060* arg0);
void func_8009BDE4(UNUSED UnkStruct_801CF060* arg0);
void func_8009BE40(UnkStruct_801CF060* arg0, void* arg1, void* arg2, f32 arg3);
void stub_8009BEB8();
void func_8009BEBC(UnkStruct_801CF060* arg0);
void func_8009BEEC(UnkStruct_801CF060* arg0);
void func_8009BF1C(UnkStruct_801CF060* arg0);
void func_8009BF4C(UnkStruct_801CF060* arg0);
void func_8009BF7C(UnkStruct_801CF060* arg0);
void func_8009BFAC(UnkStruct_801CF060* arg0);
void func_8009BFDC(UnkStruct_801CF060* arg0);
void func_8009C00C(UnkStruct_801CF060* arg0);
void func_8009C00C_padding(void);
void func_8009C044(UnkStruct_801CF060* arg0);
void func_8009C074(UnkStruct_801CF060* arg0);
void func_8009C0A4(UnkStruct_801CF060* arg0);
void func_8009C0D4(UnkStruct_801CF060* arg0);
void func_8009C104(UnkStruct_801CF060* arg0);
void func_8009C134(UnkStruct_801CF060* arg0);
void func_8009C164(UnkStruct_801CF060* arg0);
void func_8009C194(UnkStruct_801CF060* arg0);
void func_8009C1C4(UnkStruct_801CF060* arg0);
void func_8009C240(UnkStruct_801CEBE0* arg0);
void func_8009C2CC(UnkStruct_801CEBE0* arg0);
void func_8009C814(UnkStruct_8009A04C* arg0, s32 arg1);
void func_8009C968(void);
s32 func_8009CB68(void);
u8 func_8009CB70(UnkStruct_801CF060* arg0, UnkStruct_func_8009CCE8* arg1);
u8 func_8009CCE8(UnkStruct_func_8009CCE8* arg0);
u8 func_8009CD50(UnkStruct_func_8009CCE8* arg0);
void func_8009D320(void);
void func_8009D340(void);
f32 func_8009D3AC(f32 arg0, f32 arg1);
f32 func_8009D4A8(f32 arg0, f32 arg1);
f32 func_8009D4DC(f32 arg0, f32 arg1);
f32 Math_Normalize_Angle(f32 x);
f32 func_8009D564(f32 arg0);
void func_8009D5C0(void);

s32 func_8009D6B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 pad; // stack pad: puts idx at sp+8, as the original
    s16 index;
    UnkStruct_801CE780_unk4** pp;
    UnkStruct_801CE780_unk4* p;
    s16 k;
    s32 idx;

    switch (arg0) {
        case 6:
            idx = 0;
            break;
        case 5:
            idx = 1;
            break;
        case 7:
        case 8:
        case 9:
            idx = 2;
            break;
        case 3:
        case 4:
            idx = 3;
            break;
        case 10:
            idx = 4;
            break;
        case 1:
        case 2:
            idx = 6;
            break;
        case 12:
            idx = 7;
            break;
    }
    index = D_801CE768[idx];
    switch (arg0) {
        case 6:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unk8[arg2];
            return (s32) &p->unk4[k];
        case 5:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unk10[arg2];
            return (s32) &p->unk4[k];
        case 7:
        case 8:
        case 9:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unkC[arg2];
            return (s32) &p->unk4[k];
        case 3:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unk8[arg2];
            return (s32) &p->unk4[k];
        case 10:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unkC[arg2];
            return (s32) &p->unk4[k];
        case 1:
            pp = D_801CE780[index].unk4;
            p = pp[arg1];
            k = p->unk8[arg2];
            return (s32) &p->unk4[k];
    }
    // FAKE: no return here; the original falls off the end with arg0 (the switch value) still in v0
}

Gfx* func_8009D96C(Gfx* gdl, s32 arg1, f32 arg2) {
    f32 sp4C;

    if (D_801CF060[arg1].unkB8 == 0) {
        sp4C = D_801CF060[arg1].unk18;
        switch (D_801CF060[arg1].unk0) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 12:
            case 13:
                sp4C = -(sp4C - 90.0f);
                break;
            case 7:
            case 8:
            case 9:
            case 10:
                sp4C = 90.0f - sp4C;
                break;
        }
        func_80049C9C(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], func_8009D564(D_801CF060[arg1].unk20),
                      func_8009D564(sp4C), func_8009D564(D_801CF060[arg1].unk1C), D_801CF060[arg1].unkC,
                      D_801CF060[arg1].unk10, D_801CF060[arg1].unk14, arg2);
    } else {
        func_80048A88(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], D_801CF060[arg1].unk30, D_801CF060[arg1].unk34,
                      D_801CF060[arg1].unk38, D_801CF060[arg1].unk3C, D_801CF060[arg1].unk40, D_801CF060[arg1].unk44,
                      D_801CF060[arg1].unkC, D_801CF060[arg1].unk10, D_801CF060[arg1].unk14, D_801CF060[arg1].unk48);
    }
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    D_801D06B8++;
    return gdl;
}

Gfx* func_8009D96C(Gfx*, s32, f32);

typedef struct UnkStruct_801CE798 {
    s32 unk0;
    char pad[0x28];
} UnkStruct_801CE798;
extern UnkStruct_801CE798 D_801CE798[];

Gfx* func_8009DB90(Gfx* dl, s32 arg1) {
    UNUSED s32 pad; // stack pad
    s32 sp18;

    sp18 = D_801CE774;
    gSPDisplayList(dl++, D_800E6CA0);
    dl = func_8009D96C(dl++, arg1, 0.1f);
    gSPDisplayList(dl++, D_801CE798[sp18].unk0);
    return dl;
}

Gfx* func_8009DC10(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    s32 sp68;
    s32 var_s3;

    index = D_801CE774;

    v1 = D_801CE780[index].unk4;

    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }

    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);

    gdl = func_8009D96C(gdl, arg1, 0.1f);

    var_s3 = temp_s4->unk14[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk20[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk1C[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk18[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_8009E794(Gfx* dl, s32 arg1) {
    UNUSED s32 pad; // stack pad
    s32 sp18;

    sp18 = D_801CE76E;
    gSPDisplayList(dl++, D_800E6CA0);
    dl = func_8009D96C(dl++, arg1, 0.2f);
    gSPDisplayList(dl++, D_801CE798[sp18].unk0);
    return dl;
}

Gfx* func_8009E814(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    s32 sp68;
    s32 var_s3;

    index = D_801CE76E;

    v1 = D_801CE780[index].unk4;

    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }

    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);

    gdl = func_8009D96C(gdl, arg1, 0.2f);

    var_s3 = temp_s4->unk14[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk20[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk1C[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk18[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_8009F398(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 sp58;
    s32 k;
    s32 var_s3;

    index = D_801CE76A;
    k = D_801CF060[arg1].unk74 % 3;

    v1 = D_801CE780[index].unk4;

    temp_s2 = v1[k];
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s2->unk0;
        if (D_801CF060[arg1].unk78 == 0) {
            D_801CF060[arg1].unk74 = 0;
        }
    }
    sp58 = D_801CF060[arg1].unk78 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);
    if (D_801CF060[arg1].unk7C == 0xFF) {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.05f);
    }
    var_s3 = temp_s2->unk10[sp58];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk18[sp58];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk14[sp58];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unkC[sp58];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk8[sp58];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_8009FCB0(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 spC0;
    UNUSED s32 pad[7]; // stack pad
    s32 k;
    s32 var_s3;
    s32 t;
    s32 prev;

    index = D_801CE768[0];
    k = D_801CF060[arg1].unk74;

    v1 = D_801CE780[index].unk4;

    temp_s2 = v1[k % 8];
    if ((D_801CF060[arg1].unkB8 == 0) && (gCurrentPauseMenuOption == -1)) {
        prev = D_801CF060[arg1].unk78++;
        if (prev >= temp_s2->unk0 - 1) {
            D_801CF060[arg1].unk74 = 0;
            D_801CF060[arg1].unk78 = 0;
        }
    }
    spC0 = D_801CF060[arg1].unk78 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);
    if (gCourseID == DOLPHIN_PARK) {
        if (D_801CF060[arg1].unk7C == 0xFF) {
            t = D_800DAA00 % 100;
            if (t < 20) {
                gdl = func_8009D96C(gdl, arg1, 0.15f);
            }
            if (t >= 20) {
                gdl = func_8009D96C(gdl, arg1, 0.25f);
            }
        } else {
            gdl = func_8009D96C(gdl, arg1, 0.07f);
        }
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.15f);
    }
    var_s3 = temp_s2->unk8[spC0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk18);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk18[spC0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk1C);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk14[spC0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unkC[spC0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[spC0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A063C(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    StructVarS0* e;
    s32 index;
    s32 spE0;
    UnkStruct_801CE780_unk4* temp_s2;
    UNUSED s32 pad[2]; // stack pad
    s32 k;
    s32 var_s3;

    e = &D_801CF060[arg1];
    index = D_801CE778;
    k = e->unk74;

    v1 = D_801CE780[index].unk4;

    temp_s2 = v1[k % 2];
    if ((gCurrentPauseMenuOption == -1) && ((spE0 = e->unk78) >= temp_s2->unk0)) { // FAKE: spE0
        e->unk78 = 0;
    }
    spE0 = e->unk78 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);
    if (e->unk8 == 2) {
        gdl = func_8009D96C(gdl, arg1, 0.15f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.6f);
    }
    var_s3 = temp_s2->unk8[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unkC[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk14[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk18[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk1C[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[spE0];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_FOG | G_LIGHTING | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gSPMatrix(gdl++, &D_801D0678, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A10E4(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 sp90;
    UNUSED s32 pad[4]; // stack pad (frame 0xA0)
    s32 var_s3;

    index = D_801CE76C;

    v1 = D_801CE780[index].unk4;

    temp_s2 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s2->unk0;
    }
    sp90 = D_801CF0D8[arg1].unk0 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s2->unkC[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk8[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A16F0(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 sp90;
    UNUSED s32 pad[4]; // stack pad (frame 0xA0)
    s32 var_s3;

    index = D_801CE76C;

    v1 = D_801CE780[index].unk4;

    temp_s2 = v1[1];
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s2->unk0;
    }
    sp90 = D_801CF0D8[arg1].unk0 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s2->unkC[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk8[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk1C);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk18);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A1CFC(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 sp90;
    UNUSED s32 pad[4]; // stack pad (frame 0xA0)
    s32 var_s3;

    index = D_801CE76C;

    v1 = D_801CE780[index].unk4;

    temp_s2 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s2->unk0;
    }
    sp90 = D_801CF0D8[arg1].unk0 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s2->unkC[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk20);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk8[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk28);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk24);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A2308(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    UnkStruct_801CE780_unk4* temp_s2;
    s32 sp90;
    UNUSED s32 pad[4]; // stack pad (frame 0xA0)
    s32 var_s3;

    index = D_801CE770;

    v1 = D_801CE780[index].unk4;

    temp_s2 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s2->unk0;
    }
    sp90 = D_801CF0D8[arg1].unk0 % temp_s2->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    gdl = func_8009D96C(gdl, arg1, 0.1f);
    var_s3 = temp_s2->unkC[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk8[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s2->unk10[sp90];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s2->unk4[var_s3].unk6, temp_s2->unk4[var_s3].unk7,
                  temp_s2->unk4[var_s3].unk8, temp_s2->unk4[var_s3].unk9, temp_s2->unk4[var_s3].unkA,
                  temp_s2->unk4[var_s3].unkB, temp_s2->unk4[var_s3].unk0, temp_s2->unk4[var_s3].unk2,
                  temp_s2->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A28F4(Gfx* gdl, s32 arg1) {
    StructVarS0* temp_t0;
    s32 sp68;
    StructVarS0* temp_t0_2;
    UnkStruct_801CE780* temp_a2;
    s32 pad; // stack pad

    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (s32) (D_801CF060[arg1].unk78 + 1) % 2;
    }
    sp68 = D_801CE776;
    gSPDisplayList(gdl++, D_800E6CA0);
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gdl = func_8009D96C(gdl, arg1, 0.4f);
    gSPDisplayList(gdl++, D_801CE780[sp68].unk8);
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_PASS2);
    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    if (D_801CF060[arg1].unk78 == 0) {
        gSPDisplayList(gdl++, D_801CE780[sp68].unkC);
    } else {
        gSPDisplayList(gdl++, D_801CE780[sp68].unk10);
    }
    return gdl;
}

void func_800A2B24(s32 arg0) {
    camera_unk_1* cam;

    cam = &gCameraPerspective[D_80223930];
    switch (D_801CF060[arg0].unk50) {
        case 0:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(D_801CF060[arg0].unk1C) * 0.6;
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk20) * 0.9;
            if ((f64) Math_Normalize_Angle(D_801CF060[arg0].unk20) > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if ((f64) Math_Normalize_Angle(D_801CF060[arg0].unk20) < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk20 = func_8009D564(D_801CF060[arg0].unk20);
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
        case 1:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 == 1) {
                D_801CF060[arg0].unk5C += -10.0f;
            }
            if (D_801CF060[arg0].unk54 == 7) {
                D_801CF060[arg0].unk5C += 120.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 2:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 == 1) {
                D_801CF060[arg0].unk5C += 120.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            if (D_801CF060[arg0].unk54 == 1) {
                D_801CF060[arg0].unk74 = 3;
                D_801CF060[arg0].unk78 = 0;
            }
            break;
        case 3:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 3.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 8.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 15)) {
                D_801CF060[arg0].unk5C += 25.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.0);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 11) && (D_801CF060[arg0].unk54 < 40)) {
                D_801CF060[arg0].unk20 = Math_Normalize_Angle((f32) (D_801CF060[arg0].unk54 - 10) * -12.0f);
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 4:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 10.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 14)) {
                D_801CF060[arg0].unk5C += 25.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.0);
            D_801CF060[arg0].unk1C = 0.0f;
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 16) && (D_801CF060[arg0].unk54 < 45)) {
                D_801CF060[arg0].unk1C = Math_Normalize_Angle(2.0f * ((f32) (D_801CF060[arg0].unk54 - 15) * -12.0f));
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            if (D_801CF060[arg0].unk54 == 15) {
                D_801CF060[arg0].unk74 = 3;
                D_801CF060[arg0].unk78 = 0;
            }
            break;
        case 5:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 10.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 16)) {
                D_801CF060[arg0].unk5C += 30.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.0);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 6:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.5;
                } else {
                    D_801CF060[arg0].unk5C += 1.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 7.5;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 8.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 14)) {
                D_801CF060[arg0].unk74 = 3;
                D_801CF060[arg0].unk78 = 0;
                D_801CF060[arg0].unk5C += 27.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 7:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk1C = func_8009D564(Math_Normalize_Angle(D_801CF060[arg0].unk1C) * 0.9);
            D_801CF060[arg0].unk74 = 5;
            D_801CF060[arg0].unk78 = D_801CF060[arg0].unk54;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 80;
            break;
        case 8:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.5f;
                } else {
                    D_801CF060[arg0].unk5C += 1.5f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 0.5f;
            } else {
                D_801CF060[arg0].unk5C += 0.5f;
            }
            if (D_801CF060[arg0].unk54 == 1) {
                D_801CF060[arg0].unk5C += -5.0f;
            }
            if (D_801CF060[arg0].unk54 == 7) {
                D_801CF060[arg0].unk5C += 50.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 30;
            break;
        case 9:
            if (D_801CF060[arg0].unk10 >= 1000.0f) {
                D_801D0758 = D_801CF060[arg0].unk10 - 1000.0f;
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - 1000.0f);
            }
            if (D_801D0758 > 30.0f) {
                if (D_801CF060[arg0].unk10 > 1000) {
                    D_801CF060[arg0].unk5C -= 5.0f;
                } else {
                    D_801CF060[arg0].unk5C += 5.0f;
                }
            } else if (D_801CF060[arg0].unk10 > 1000.0f) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
        case 10:
            if (D_801CF060[arg0].unk10 >= 600.0f) {
                D_801D0758 = D_801CF060[arg0].unk10 - 600.0f;
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - 600.0f);
            }
            if (D_801D0758 > 30.0f) {
                if (D_801CF060[arg0].unk10 > 600.0f) {
                    D_801CF060[arg0].unk5C -= 5.0f;
                } else {
                    D_801CF060[arg0].unk5C += 5.0f;
                }
            } else if (D_801CF060[arg0].unk10 > 600.0f) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
        case 12:
            D_801CF060[arg0].unk74 = 0;
            D_801CF060[arg0].unk20 = 0.0f;
            D_801CF060[arg0].unk1C = 0.0f;
            D_801CF060[arg0].unk5C = 0.0f;
            D_801CF060[arg0].unk10 = 75.0f;
            break;
        case 13:
            if (D_801CF060[arg0].unk10 >= -200.0) {
                D_801D0758 = D_801CF060[arg0].unk10 - -200.0;
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - -200.0);
            }
            if (D_801D0758 > 40.0f) {
                if (D_801CF060[arg0].unk10 > -200.0f) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.5f;
                }
            } else if (D_801CF060[arg0].unk10 > -200.0f) {
                D_801CF060[arg0].unk5C -= 0.5f;
            } else {
                D_801CF060[arg0].unk5C += 0.5f;
            }
            if (D_801CF060[arg0].unk54 == 1) {
                D_801CF060[arg0].unk74 = 1;
                D_801CF060[arg0].unk78 = 0;
                D_801CF060[arg0].unk5C = 5.0f;
            }
            if (D_801CF060[arg0].unk20 < 90.0) {
                D_801CF060[arg0].unk20 = D_801CF060[arg0].unk20 + ((90.0f - D_801CF060[arg0].unk20) * 0.1);
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
        case 14:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 7.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 1.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 10.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 14)) {
                D_801CF060[arg0].unk5C += 30.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C * 1.5);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 15:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 8.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 0.3f;
            } else {
                D_801CF060[arg0].unk5C += 0.1f;
            }
            if (D_801CF060[arg0].unk54 < 7) {
                D_801CF060[arg0].unk5C -= 5.5f;
            }
            if ((D_801CF060[arg0].unk54 >= 20) && (D_801CF060[arg0].unk54 < 24)) {
                D_801CF060[arg0].unk5C += 14.0f;
            }
            if (D_801CF060[arg0].unk54 == 32) {
                func_800BF784(func_8009D4A8(cam->eyeX - D_801CF060[arg0].unkC, cam->eyeZ - D_801CF060[arg0].unk14) /
                                  100.0f,
                              64);
            }
            D_801CF060[arg0].unk5C *= 0.9;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.5);
            D_801CF060[arg0].unk1C = 0.0f;
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 21) && (D_801CF060[arg0].unk54 < 80)) {
                D_801CF060[arg0].unk1C = Math_Normalize_Angle((f32) (D_801CF060[arg0].unk54 - 20) * -6.0f);
                D_801CF060[arg0].unk20 = Math_Normalize_Angle(FABS(D_801CF060[arg0].unk5C) * -1.2);
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 16:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 8.0f;
                } else {
                    D_801CF060[arg0].unk5C += 3.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 20.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 0.3f;
            } else {
                D_801CF060[arg0].unk5C += 0.1f;
            }
            if (D_801CF060[arg0].unk54 < 7) {
                D_801CF060[arg0].unk5C -= 5.5f;
            }
            if ((D_801CF060[arg0].unk54 >= 20) && (D_801CF060[arg0].unk54 < 24)) {
                D_801CF060[arg0].unk5C += 14.0f;
            }
            if (D_801CF060[arg0].unk54 == 32) {
                func_800BF784(func_8009D4A8(cam->eyeX - D_801CF060[arg0].unkC, cam->eyeZ - D_801CF060[arg0].unk14) /
                                  100.0f,
                              64);
            }
            D_801CF060[arg0].unk5C *= 0.9;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.5);
            D_801CF060[arg0].unk1C = 0.0f;
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 21) && (D_801CF060[arg0].unk54 < 80)) {
                D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.2);
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            if (D_801CF060[arg0].unk54 == 20) {
                D_801CF060[arg0].unk74 = 1;
                D_801CF060[arg0].unk78 = 0;
            }
            break;
        case 17:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 40.0f) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.0f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) - 40.0f) <
                       D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 3.0f;
            } else {
                D_801CF060[arg0].unk5C += 1.0f;
            }
            if (D_801CF060[arg0].unk54 < 3) {
                D_801CF060[arg0].unk5C -= 5.0f;
            }
            if ((D_801CF060[arg0].unk54 >= 10) && (D_801CF060[arg0].unk54 < 16)) {
                D_801CF060[arg0].unk5C += 15.0f;
            }
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(-D_801CF060[arg0].unk5C);
            if (D_801CF060[arg0].unk20 > 90.0) {
                D_801CF060[arg0].unk20 = 90.0f;
            }
            if (D_801CF060[arg0].unk20 < -90.0) {
                D_801CF060[arg0].unk20 = -90.0f;
            }
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            D_801CF060[arg0].unk54 = (D_801CF060[arg0].unk54 + 1) % 65535;
            break;
        case 18:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) -
                     ((gSinTable[(D_800E62C4 * 200) & 0xFFF] * 20.0f) + 70.0f)) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.5f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) -
                        ((gSinTable[(D_800E62C4 * 200) & 0xFFF] * 20.0f) + 70.0f)) < D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 0.5f;
            } else {
                D_801CF060[arg0].unk5C += 0.5f;
            }
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.2);
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(D_801CF060[arg0].unk1C) * 0.6;
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
        case 19:
            if (Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) <= D_801CF060[arg0].unk10) {
                D_801D0758 = D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14);
            } else {
                D_801D0758 = -(D_801CF060[arg0].unk10 - Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14));
            }
            if (D_801D0758 > 40.0f) {
                if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) -
                     ((gSinTable[(D_800E62C4 * 200) & 0xFFF] * 20.0f) + 200.0f)) < D_801CF060[arg0].unk10) {
                    D_801CF060[arg0].unk5C -= 3.0f;
                } else {
                    D_801CF060[arg0].unk5C += 1.5f;
                }
            } else if ((Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) -
                        ((gSinTable[(D_800E62C4 * 200) & 0xFFF] * 20.0f) + 200.0f)) < D_801CF060[arg0].unk10) {
                D_801CF060[arg0].unk5C -= 0.5f;
            } else {
                D_801CF060[arg0].unk5C += 0.5f;
            }
            D_801CF060[arg0].unk20 = Math_Normalize_Angle(D_801CF060[arg0].unk5C * -1.2);
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(D_801CF060[arg0].unk1C) * 0.6;
            D_801CF060[arg0].unk5C *= 0.8;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk5C;
            break;
    }
}

// The per-course node tables func_800A52D8 and func_800AAAC8 walk (0x1C bytes per node).
typedef struct UnkStruct_800E6C78 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
} UnkStruct_800E6C78; /* size = 0x1C */

extern UnkStruct_800E6C78* D_800E6C78[];

void func_800A52D8(s32 arg0, f32 arg1) {
    f32 temp;
    f32 temp2;
    UnkStruct_800E6C78* node;
    UnkStruct_800E6C78* node2;

    if (D_801CF060[arg0].unk9C >= 0) {
        D_801D0754 = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk8;
        D_801D075C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unkC;
    } else {
        D_801D0758 = Math_Normalize_Angle(func_8009D3AC(D_801CF060[arg0].unkC - D_801CF060[arg0].unk80,
                                                        -(D_801CF060[arg0].unk14 - D_801CF060[arg0].unk88)));
        D_801D0754 = (D_801CF060[arg0].unk70 * COS((s32) ((D_801D0758 / 360.0f) * 4096.0f))) + D_801D06BC;
        D_801D075C = (D_801CF060[arg0].unk70 * SIN((s32) ((D_801D0758 / 360.0f) * 4096.0f))) + D_801D06C4;
        D_801CF060[arg0].unk4C =
            func_8009D4A8(D_801D0754 - D_801CF060[arg0].unkC, D_801D075C - D_801CF060[arg0].unk14) / 10.0f;
        if (D_801CF060[arg0].unk4C > 70) {
            D_801CF060[arg0].unk4C = 70.0f;
        }
    }
    D_801D0760 =
        Math_Normalize_Angle(func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                             D_801CF060[arg0].unk18);
    if (D_801CF060[arg0].unk0 != 12) {
        if (D_801D0760 >= 2) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
            if (D_801D0760 > 45.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 5.0f);
            }
        }
        if (D_801D0760 <= -2) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
            if (D_801D0760 < -45.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 5.0f);
            }
        }
        temp = FABS(D_801D0760);
        if (temp < 2.0f) {
            D_801CF060[arg0].unk18 = func_8009D564(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
        }
    } else {
        if (D_801D0760 >= 0.5) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 0.5f);
            if (D_801D0760 > 45.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
            }
        }
        if (D_801D0760 <= -0.5) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 0.5f);
            if (D_801D0760 < -45.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
            }
        }
        temp = FABS(D_801D0760);
        if (temp < 0.5) {
            D_801CF060[arg0].unk18 = func_8009D564(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
        }
    }
    D_801CF060[arg0].unk1C = Math_Normalize_Angle(
        D_801CF060[arg0].unk1C + (Math_Normalize_Angle((D_801D0760 / 3.0f) - D_801CF060[arg0].unk1C) * 0.1));
    if (D_801CF060[arg0].unk1C > 45.0f) {
        D_801CF060[arg0].unk1C = 45.0f;
    }
    if (D_801CF060[arg0].unk1C < -45.0f) {
        D_801CF060[arg0].unk1C = -45.0f;
    }
    D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
    D_801D0768 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
    if (D_801CF060[arg0].unk0 == 12) {
        D_801CF060[arg0].unk20 = D_801D0768 / 7.0f;
    }
    temp = FABS(D_801D0760);
    D_801D0764 = ((D_801CF060[arg0].unk4C * ((180 - temp) / 180.0f)) - D_801D0768) * 0.15 + D_801D0768;
    if ((func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < SQ(arg1)) &&
        (D_801CF060[arg0].unk9C >= 0)) {
        if (func_8009D4A8(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) <
            (node2 = D_801CF060[arg0].unk9C + D_800E6C78[gCourseID])->unk18) { // int + pointer: the addu operand order

            D_801CF060[arg0].unkC +=
                (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            D_801CF060[arg0].unk14 +=
                (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            node = node2; // FAKE: the same pointer; node here and node2 in the unk10 tests give the original's registers
            temp2 = node->unk14;
            if (temp2 > -1.0f) {
                D_801CF060[arg0].unk54 = 0;
                D_801CF060[arg0].unk50 = temp2;
            }
            if (node2->unk10 != -1.0f) {
                D_801CF060[arg0].unk4C = node->unk10;
            }
            if (node2->unk10 == -2.0f) {
                D_801CF060[arg0].unk4C = D_801D06D4;
                if (D_801D06D4 < 30.0f) {
                    D_801CF060[arg0].unk4C = 30.0f;
                }
            }
            if (D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk10 == -3.0f) {
                D_801CF060[arg0].unk4C = D_801D06D4 + 10.0;
                if (D_801CF060[arg0].unk4C < 40.0f) {
                    D_801CF060[arg0].unk4C = 40.0f;
                }
            }
            if (D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk10 == -4.0f) {
                D_801CF060[arg0].unk4C = D_801D06D4 + 20.0;
                if (D_801CF060[arg0].unk4C < 50.0f) {
                    D_801CF060[arg0].unk4C = 50.0f;
                }
            }
            if (D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk14 == -2.0f) {
                D_801CF060[arg0].unkC = D_800E6C78[gCourseID][D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk0].unk8;
                D_801CF060[arg0].unk14 = D_800E6C78[gCourseID][D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk0].unkC;
            }
            if ((D_800DAB68 == 1) && (D_801CF060[arg0].unk0 == 5)) {
                D_801CF060[arg0].unk9C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk4;
            } else {
                D_801CF060[arg0].unk9C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk0;
            }
        }
    } else {
        D_801CF060[arg0].unkC +=
            (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
        D_801CF060[arg0].unk14 +=
            (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
    }
    func_800A2B24(arg0);
}

void func_800C1E0C(f32);

void func_800A5C74(void) {
    camera_unk_1* temp_s1;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f20;
    s32 i;

    var_f20 = 1600000.0f;
    temp_s1 = &gCameraPerspective[D_80223930];
    for (i = 0; i < 30; i++) {
        if (D_801CF060[i].unk0 == 1) {
            temp_f0 = func_8009D4A8(temp_s1->eyeX - D_801CF060[i].unkC, temp_s1->eyeZ - D_801CF060[i].unk14);
            if (temp_f0 < var_f20) {
                var_f20 = temp_f0;
            }
        }
    }
    var_f20 = var_f20 / 40.0f;
    if (var_f20 > 50.0f) {
        func_800C1DEC();
    }
    func_800C1E0C(var_f20);
}

extern s32 D_800D4720;
extern f32 gWaterWindow[];

// TODO: Migrate rodata

void func_800A5D70(s32 arg0) {
    camera_unk_1* cam;
    s32 idx; // Index for D_801CF060
    s32 angle;
    u32 rand_num;

    cam = &gCameraPerspective[D_80223930];
    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 11) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk8C + 90.0f);
            angle = (s32) ((D_801CF060[arg0].unk8C / 360.0f) * 4096.0f);
            D_801CF060[arg0].unkC = D_801CF060[arg0].unk80 + (D_801CF060[arg0].unk70 * COS(angle));
            D_801CF060[arg0].unk14 = D_801CF060[arg0].unk88 + (D_801CF060[arg0].unk70 * SIN(angle));
            D_801CF060[arg0].unk8C += 0.5f;
        } else if ((D_801CF060[arg0].unk8 == 5) || (D_801CF060[arg0].unk8 == 10)) {
            D_801CF060[arg0].unk74 = 0;
            D_801D0760 = func_8009D564(-func_8009D3AC(cam->unkF0, cam->unkF4));
            idx = D_801CF060[arg0].unk7C;
            if (idx == 0xFF) {
                if ((D_801CF060[arg0].unk8 == 5) || (D_801CF060[arg0].unk8 == 10)) {
                    D_801D0754 =
                        (COS(ANGLE_TO_CUSTOM_UNITS(D_801D0760)) * ((300.0f + (D_801D06D4 * 10.0f)))) + D_801D06BC;
                    D_801D075C =
                        (SIN(ANGLE_TO_CUSTOM_UNITS(D_801D0760)) * ((300.0f + (D_801D06D4 * 10.0f)))) + D_801D06C4;
                }
            } else {
                D_801D0754 = D_801CF060[idx].unkC;
                D_801D075C = D_801CF060[idx].unk14;
            }
            if (D_801CF060[arg0].unk8 == 5) {
                D_801D0760 = Math_Normalize_Angle(
                    func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                    D_801CF060[arg0].unk18);
            }
            if (D_801CF060[arg0].unk8 == 10) {
                D_801D0760 = Math_Normalize_Angle(
                    (func_8009D3AC(D_801D06BC - D_801CF060[arg0].unkC, -(D_801D06C4 - D_801CF060[arg0].unk14)) -
                     D_801CF060[arg0].unk18) +
                    180.0f);
            }
            if (D_801CF060[arg0].unk0 == 7) {
                D_801D0764 = 0.5f;
            }
            if (D_801CF060[arg0].unk0 == 8) {
                D_801D0764 = 0.7f;
            }
            if (D_801CF060[arg0].unk0 == 9) {
                D_801D0764 = 1.0f;
            }
            if (D_801CF060[arg0].unk0 == 10) {
                D_801D0764 = 0.7f;
            }
            if (D_801CF060[arg0].unk8 == 5) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + D_801D0764);
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 2));
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - D_801D0764);
                    if (D_801D0760 < -45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 2));
                    }
                }

                D_801D0764 = ((180.0f - FABS(D_801D0760)) / 180.0f) * 10.0f;
            }
            if (D_801CF060[arg0].unk8 == 10) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 3.0f));
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 6.0f));
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 3.0f));
                    if (D_801D0760 < -45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 6.0f));
                    }
                }

                D_801D0764 = ((180.0f - FABS(D_801D0760)) / 180.0f) * 25.0f;
            }

            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = (D_801D0760 + ((D_801D0764 - D_801D0760) * 0.1));
            ;
            angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
            D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D0764);
            D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D0764);
            if (D_801CF060[arg0].unk8 == 5) {
                if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) <
                    SQ((D_801D06D4 * 500.0f))) {
                    D_801CF060[arg0].unk8 = 10;
                }
            }
            if ((D_801CF060[arg0].unk8 == 10) &&
                (1000000.0f < func_8009D4DC(D_801D06BC - D_801CF060[arg0].unkC, D_801D06C4 - D_801CF060[arg0].unk14))) {
                D_801CF060[arg0].unk8 = 5;
            }
            D_801D0754 = gWaterWindow[2] - D_801CF060[arg0].unkC;
            D_801D0758 = gWaterWindow[3] - D_801CF060[arg0].unk14;
            if (((f64) gWaterWindow[4] * 0.9 * 0.9) < func_8009D4DC(D_801D0754, D_801D0758)) {
                rand_num = SysUtils_Rand() % 4095U;
                D_801CF060[arg0].unkC = (gWaterWindow[2] + (SIN(rand_num) * (D_800D4720 * 0.8)));
                D_801CF060[arg0].unk14 = (gWaterWindow[3] + (COS(rand_num) * (D_800D4720 * 0.8)));
                D_801CF060[arg0].unk18 = (s32) (SysUtils_Rand() & 255);
            }
        }
    }
}

f32 func_800A6628(s32 arg0, f32 arg1, f32 arg2) {
    return func_8009D4A8(D_801CF060[arg0].unkC - arg1, D_801CF060[arg0].unk14 - arg2);
}

s32 func_800A6684(s32 arg0) {
    s32 var_v0;

    if (func_800A6628(arg0, 112.0f, 5108.0f) < 1100.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 3252.0f, 3922.0f) < 1200.0f) {
        return 1;
    }
    if (func_800A6628(arg0, -3520.0f, -85.0f) < 1770.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 179.0f, -2485.0f) < 1400.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 3063.0f, -1319.0f) < 2200.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 1425.0f, 3603.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 1159.0f, 4182.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 2441.0f, -5018.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 32.0f, -4958.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, -2511.0f, -4971.0f) < 1000.0f) {
        return 1;
    }
    return 0;
}

extern UnkStruct_801AEE20 D_801B2F20[];
extern s32 D_801BB124;
extern f32 D_801D076C;
extern s32 D_800E62D0;
extern s32 D_800E62D4;
extern f32 D_801D06D0;
extern f32 D_801D06C8;
extern f32 D_801D0724;
extern f32 D_801D0770;
extern f32 D_801D0774;
f32 func_8007FAE4(f32, f32, f32, f32*, f32*, f32*);
f32 func_8007F448(f32, f32, f32, f32*, f32*, f32*);
f32 func_80051CB4(f32, f32, f32*, f32*);
void func_800C1EB8(s32);

#ifdef NON_MATCHING
// Score 9475 of 259500: registers and scheduling. The 11.0f compare is single precision (c.lt.s) as in the
// original; best = -1 is set just before the 3000.0f test and the checkpoint search loop starts p before i. cam declared after five locals and sp4C/sp48 last put them at
// 0x58/0x4C/0x48 as in the original; D_801D0774's offset is stored before it is scaled; statement order from a move
// search. D_801B2EB4 reads are written as D_801B2F20[unk9C - 1].unk98 (same address).
void func_800A68A4(s32 arg0) {
    UnkStruct_801CE780_unk4_unk4* node;
    s32 angle;
    s32 i;
    s32 best;
    UnkStruct_801AEE20* p;
    camera_unk_1* cam;
    StructVarS0* lead;
    s32 t;
    f32 sp4C;
    f32 sp48;

    cam = &gCameraPerspective[D_80223930];
    node = (UnkStruct_801CE780_unk4_unk4*) func_8009D6B0(D_801CF060[arg0].unk0, D_801CF060[arg0].unk74,
                                                         D_801CF060[arg0].unk78);
    D_801CF060[arg0].unk28 = (D_801CF060[arg0].unk10 + (node->unk2 * 0.1)) - D_801CF060[arg0].unk68;
    D_801CF060[arg0].unk6C = D_801CF060[arg0].unk14;
    D_801CF060[arg0].unk68 = D_801CF060[arg0].unk10 + (node->unk2 * 0.1);
    D_801CF060[arg0].unk64 = D_801CF060[arg0].unkC;
    if (Water_GetHeight(D_801CF060[arg0].unk64, D_801CF060[arg0].unk6C) < D_801CF060[arg0].unk68) {
        D_801D0668.unk_5 = 0;
    } else {
        D_801D0668.unk_5 = 1;
    }
    D_801D0668.unk_0 = func_8009D4A8(D_801CF060[arg0].unk64 - D_801D06BC, D_801CF060[arg0].unk6C - D_801D06C4) / 100.0f;
    D_801D0668.unk_6 = (s32) ((func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C) / 90.0f) * 120.0f);
    angle = (s32) ((D_801CF060[arg0].unk18 / 360.0f) * 4096.0f);
    D_801CF060[arg0].unk34 = 0.0f;
    D_801CF060[arg0].unk30 = COS(angle);
    D_801CF060[arg0].unk38 = SIN(angle);
    if ((gGameModeState == GMODE_STATE_STARTED) && (gCurrentPauseMenuOption == -1)) {
        if ((D_801CF060[arg0].unk74 == 0) &&
            (func_8009D4DC(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C) > 2500.0f)) {
            D_801CF060[arg0].unk78 += 1;
        }
        if (D_801CF060[arg0].unk7C != 0xFF) {
            lead = &D_801CF060[D_801CF060[arg0].unk7C];
            D_801D0758 = lead->unk18 - 180.0f;
            switch (arg0) { /* irregular */
                case 1:
                    angle = (s32) (((D_801D0758 - 30.0f) / 360.0f) * 4096.0f);
                    D_801D0754 = (COS(angle) * 150.0f) + lead->unkC;
                    D_801D075C = (SIN(angle) * 150.0f) + lead->unk14;
                    break;
                case 2:
                    angle = (s32) (((D_801D0758 + 30.0f) / 360.0f) * 4096.0f);
                    D_801D0754 = (COS(angle) * 200.0f) + lead->unkC;
                    D_801D075C = (SIN(angle) * 200.0f) + lead->unk14;
                    break;
                case 3:
                    angle = (s32) ((D_801D0758 / 360.0f) * 4096.0f);
                    D_801D0754 = (COS(angle) * 220.0f) + lead->unkC;
                    D_801D075C = (SIN(angle) * 220.0f) + lead->unk14;
                    break;
            }
            D_801CF060[arg0].unk4C =
                func_8009D4A8(D_801D0754 - D_801CF060[arg0].unkC, D_801D075C - D_801CF060[arg0].unk14) / 10.0f;
            if (D_801CF060[arg0].unk4C > 80.0f) {
                D_801CF060[arg0].unk4C = 80.0f;
            }
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801D0760 >= 2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
                if (D_801D0760 > 45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 5.0f);
                }
            }
            if (D_801D0760 <= -2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
                if (D_801D0760 < -45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 5.0f);
                }
            }
            if (FABS(D_801D0760) < 2.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(
                    func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
            }
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                (f32) (((f64) Math_Normalize_Angle((D_801D0760 / 3.0f) - D_801CF060[arg0].unk1C) * 0.1) +
                       (f64) D_801CF060[arg0].unk1C));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D0768 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 =
                (f32) (((f64) ((D_801CF060[arg0].unk4C * ((180.0f - FABS(D_801D0760)) / 180.0f)) - D_801D0768) * 0.15) +
                       (f64) D_801D0768);
            angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
            D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D0764);
            D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D0764);
            func_800A2B24(arg0);
            return;
        }
        if (D_801CF060[arg0].unk8 == 1) {
            D_801D0754 = D_801B2F20[D_801CF060[arg0].unk9C].unk0;
            D_801D0758 = Water_GetHeight(D_801CF060[arg0].unk64, D_801CF060[arg0].unk6C) +
                         (D_801B2F20[D_801CF060[arg0].unk9C].unk4 - 20.0f);
            D_801D075C = D_801B2F20[D_801CF060[arg0].unk9C].unk8;
            if ((D_801D06BC > 0.0f) && (D_801D06C4 < -4000.0f)) {
                D_801D0754 = 7000.0f;
                D_801D075C = -2650.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            if ((D_801D06BC <= 0.0f) && (D_801D06C4 < -4000.0f)) {
                D_801D0754 = -7000.0f;
                D_801D075C = -2650.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            if ((D_801D06BC > 0.0f) && (D_801D06C4 > -4000.0f) && (D_801D06C4 < -1300.0f)) {
                D_801D0754 = 5600.0f;
                D_801D075C = 0.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            if ((D_801D06BC <= 0.0f) && (D_801D06C4 > -4000.0f) && (D_801D06C4 < -1300.0f)) {
                D_801D0754 = -5600.0f;
                D_801D075C = 2000.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            if ((D_801D06BC > 3300.0f) && (D_801D06C4 > -1300.0f) && (D_801D06C4 < 1000.0f)) {
                D_801D0754 = 5000.0f;
                D_801D075C = 1000.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            if ((D_801D06BC <= -3700.0f) && (D_801D06C4 > -1300.0f) && (D_801D06C4 < 2000.0f)) {
                D_801D0754 = -5000.0f;
                D_801D075C = 2500.0f;
                D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            }
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801D0760 >= 2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
                if (D_801D0760 > 45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 5.0f);
                }
            }
            if (D_801D0760 <= -2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
                if (D_801D0760 < -45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 5.0f);
                }
            }
            if (FABS(D_801D0760) < 2.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(
                    func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
            }
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                (f32) (((f64) Math_Normalize_Angle((D_801D0760 / 3.0f) - D_801CF060[arg0].unk1C) * 0.1) +
                       (f64) D_801CF060[arg0].unk1C));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D076C = 0.2f;
            D_801CF060[arg0].unk10 += 0.03 * (D_801D0758 - D_801CF060[arg0].unk10);
            D_801D0770 = func_8009D4A8(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4);
            if (D_801D0770 < 1000.0f) {
                D_801D076C =
                    (f32) (((f64) (((SIN(D_800E62C4 * 2) * 200.0f) + (1000.0f - D_801D0770)) / 1000.0f) * 1.5) + 0.2);
            }
            if (D_801B2F20[D_801CF060[arg0].unk9C - 1].unk98 == 9) {
                D_801D076C = 1.0f;
            }
            if ((f64) D_801D076C > 1.2) {
                D_801D076C = 1.2f;
            }
            D_801D0768 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 =
                (f32) (((f64) ((((180.0f - FABS(D_801D0760)) / 180.0f) * D_801D0724 * D_801D076C) - D_801D0768) *
                        0.15) +
                       (f64) D_801D0768);
            if (D_801CF060[arg0].unk68 < Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14)) {
                angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
                D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D0764);
                D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D0764);
            } else {
                D_801CF060[arg0].unkC += D_801CF060[arg0].unk24;
                D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C;
            }
            if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < 160000.0f) {
                D_801CF060[arg0].unk9C = D_801B2F20[D_801CF060[arg0].unk9C].unkA0;
                if (D_801CF060[arg0].unk54 >= 0x65) {
                    D_801CF060[arg0].unk50 = 0;
                    D_801CF060[arg0].unk54 = 0;
                }
                if (D_801CF060[arg0].unk9C == 3) {
                    if (D_801CF060[arg0].unkA4 == 1) {
                        D_801CF060[arg0].unk50 = 3;
                        D_801CF060[arg0].unk54 = 0;
                        func_800C1EB8(2);
                        D_800E62D0++;
                        if (D_800E62D0 == 3) {
                            D_801CF060[1].unk0 = 6;
                            if (D_800E62D4 <= 0) {
                                D_800E62D4 = 1;
                            }
                        }
                        if (D_800E62D0 == 5) {
                            D_801CF060[2].unk0 = 6;
                            if (D_800E62D4 < 2) {
                                D_800E62D4 = 2;
                            }
                        }
                        if (D_800E62D0 == 7) {
                            D_801CF060[3].unk0 = 6;
                            if (D_800E62D4 < 3) {
                                D_800E62D4 = 3;
                            }
                        }
                    }
                    D_801CF060[arg0].unkA4 = 1;
                }
                if (D_801B2F20[D_801CF060[arg0].unk9C - 1].unk98 == 9) {
                    D_801CF060[arg0].unk74 = 0;
                    D_801CF060[arg0].unk78 = 0;
                    t = (s16) D_800DAA00 % 9;
                    if ((t >= 0) && (t < 3)) {
                        D_801CF060[arg0].unk50 = 0x11;
                    }
                    if ((t >= 3) && (t < 6)) {
                        D_801CF060[arg0].unk50 = 3;
                    }
                    if ((t >= 6) && (t < 9)) {
                        D_801CF060[arg0].unk50 = 4;
                    }
                    D_801CF060[arg0].unk54 = 0;
                }
            }
            func_800A2B24(arg0);
            sp48 = func_8009D3AC(D_801D06C8, D_801D06D0);
            D_801D075C = Math_Normalize_Angle(
                -sp48 - func_8009D3AC(D_801CF060[arg0].unkC - D_801D06BC, -(D_801CF060[arg0].unk14 - D_801D06C4)));
            if ((FABS(D_801D075C) > 120.0f) || (D_801D06D4 < 10.0f) ||
                (func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) > 4000000.0f)) {
                D_801CF060[arg0].unk8 = 5;
                D_801CF060[arg0].unk50 = 0;
                best = -1;
                D_801D0754 = 2e9f;
                for (i = 0, p = D_801AEE20; i < D_801BB124; i++, p++) {
                    D_801D0758 = func_8009D4DC(D_801D06BC - p->unk0, D_801D06C4 - p->unk8);
                    if ((D_801D0758 < D_801D0754) && (p->unkC0 < 2)) {
                        best = i;
                        D_801D0754 = D_801D0758;
                    }
                }
                D_801CF060[arg0].unk9C = best;
            }
            D_801D0754 = cam->eyeX - D_801CF060[arg0].unkC;
            D_801D0758 = cam->eyeZ - D_801CF060[arg0].unk14;
            D_801D075C = func_8009D564(-func_8009D3AC(cam->unkF0, cam->unkF4));
            D_801D0760 = func_8009D564(
                func_8009D3AC(D_801CF060[arg0].unkC - cam->eyeX, -(D_801CF060[arg0].unk14 - cam->eyeZ)));
            if ((func_8009D4DC(D_801D0754, D_801D0758) > 1.6e7f) ||
                ((FABS(Math_Normalize_Angle(D_801D0760 - D_801D075C)) > 100.0f) &&
                 (func_8009D4DC(D_801D0754, D_801D0758) > 250000.0f))) {
                D_801D0754 = D_801CF060[arg0].unkC;
                D_801D0758 = D_801CF060[arg0].unk14;
                D_801D0764 = func_8009D564(180.0f - func_8009D3AC(cam->unkF0, cam->unkF4));
                angle = (s32) ((D_801D0764 / 360.0f) * 4096.0f);
                D_801CF060[arg0].unkC = (COS(angle) * 200.0f) + cam->eyeX;
                D_801CF060[arg0].unk14 = (SIN(angle) * 200.0f) + cam->eyeZ;
                if (func_800A6684(arg0) != 0) {
                    D_801CF060[arg0].unkC = D_801D0754;
                    D_801CF060[arg0].unk14 = D_801D0758;
                }
            }
            if (D_801CF060[arg0].unk74 == 5) {
                D_801CF060[arg0].unk78 += 1;
            }
        } else if (D_801CF060[arg0].unk8 == 5) {
            D_801CF060[arg0].unkA4 = 0;
            D_800E62D0 = 0;
            D_801D0764 = func_8009D564(-func_8009D3AC(cam->unkF0, cam->unkF4));
            angle = (s32) ((D_801D0764 / 360.0f) * 4096.0f);
            D_801D0754 = (COS(angle) * 600.0f) + D_801D06BC;
            D_801D0758 = (SIN(angle) * 600.0f) + D_801D06C4;
            D_801D075C = D_801B2F20[D_801CF060[arg0].unk9C].unk0;
            D_801D0760 = D_801B2F20[D_801CF060[arg0].unk9C].unk8;
            if ((D_801D06BC > 0.0f) && (D_801D06C4 < -4000.0f)) {
                D_801D075C = 7000.0f;
                D_801D0760 = -2650.0f;
            }
            if ((D_801D06BC <= 0.0f) && (D_801D06C4 < -4000.0f)) {
                D_801D075C = -7000.0f;
                D_801D0760 = -2650.0f;
            }
            if ((D_801D06BC > 0.0f) && (D_801D06C4 > -4000.0f) && (D_801D06C4 < -1300.0f)) {
                D_801D075C = 5600.0f;
                D_801D0760 = 0.0f;
            }
            if ((D_801D06BC <= 0.0f) && (D_801D06C4 > -4000.0f) && (D_801D06C4 < -1300.0f)) {
                D_801D075C = -5600.0f;
                D_801D0760 = 2000.0f;
            }
            if ((D_801D06BC > 3300.0f) && (D_801D06C4 > -1300.0f) && (D_801D06C4 < 1000.0f)) {
                D_801D075C = 5000.0f;
                D_801D0760 = 1000.0f;
            }
            if ((D_801D06BC <= -3700.0f) && (D_801D06C4 > -1300.0f) && (D_801D06C4 < 2000.0f)) {
                D_801D075C = -5000.0f;
                D_801D0760 = 2500.0f;
            }
            D_801D0768 = func_8009D4A8(D_801D0754 - D_801D075C, D_801D0758 - D_801D0760);
            if (D_801D0768 > 500.0f) {
                D_801D0768 = 500.0f;
            }
            D_801D0760 = func_8009D564(func_8009D3AC(D_801D075C - D_801D0754, -(D_801D0760 - D_801D0758)));
            if (Math_Normalize_Angle(D_801D0760 - D_801D0764) > 90.0f) {
                D_801D0760 = func_8009D564(D_801D0764 + 90.0f);
            }
            if (Math_Normalize_Angle(D_801D0760 - D_801D0764) < -90.0f) {
                D_801D0760 = func_8009D564(D_801D0764 - 90.0f);
            }
            angle = (s32) ((D_801D0760 / 360.0f) * 4096.0f);
            D_801D0754 += COS(angle) * D_801D0768;
            D_801D075C = (SIN(angle) * D_801D0768) + D_801D0758;
            D_801D0758 = Water_GetHeight(D_801D0754, D_801D075C) - 20.0f;
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801CF060[arg0].unk74 != 5) {
                if (D_801D0760 >= 2) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 5.0f);
                    }
                }
                if (D_801D0760 <= -2) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
                    if (D_801D0760 < -45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 5.0f);
                    }
                }
                if (FABS(D_801D0760) < 2.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(
                        func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
                }
            }
            D_801CF060[arg0].unk10 += 0.03 * (D_801D0758 - D_801CF060[arg0].unk10);
            D_801D076C = D_801D06D4 / D_801D0724;
            D_801D0770 = func_8009D4A8(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C);
            if (D_801D0770 < 2000.0f) {
                D_801D076C = (f32) (((f64) (D_801D0770 / 2000.0f) * 1.2) + (f64) D_801D076C);
            }
            if ((D_801CF060[arg0].unk74 == 5) && ((D_801CF060[arg0].unk78 == 35) || (D_801CF060[arg0].unk78 == 45)) &&
                (gGameModes == GMODE_CHAMPIONSHIP)) {
                D_801D0668.unk_8 = 0xA;
            }
            if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < 2500.0f) {
                D_801D076C = 0.0f;
                if ((func_800A6684(arg0) == 0) && (D_801CF060[arg0].unk74 != 5)) {
                    D_801CF060[arg0].unk74 = 5;
                    D_801CF060[arg0].unk78 = 0;
                }
                D_801CF060[arg0].unk18 = func_8009D564(
                    (f32) (((f64) Math_Normalize_Angle(func_8009D3AC(D_801CF060[arg0].unkC - D_801D06BC,
                                                                     -(D_801CF060[arg0].unk14 - D_801D06C4)) -
                                                       D_801CF060[arg0].unk18) *
                            0.1) +
                           (f64) D_801CF060[arg0].unk18));
            } else {
                D_801CF060[arg0].unk50 = 0;
            }
            if (D_801CF060[arg0].unk74 != 5) {
                D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                    (f32) (((f64) Math_Normalize_Angle((D_801D0760 / 3.0f) - D_801CF060[arg0].unk1C) * 0.1) +
                           (f64) D_801CF060[arg0].unk1C));
                if (D_801CF060[arg0].unk1C > 45.0f) {
                    D_801CF060[arg0].unk1C = 45.0f;
                }
                if (D_801CF060[arg0].unk1C < -45.0f) {
                    D_801CF060[arg0].unk1C = -45.0f;
                }
                D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            } else {
                D_801CF060[arg0].unk1C = 0.0f;
                D_801CF060[arg0].unk20 = 0.0f;
            }
            if ((f64) D_801D076C > 1.5) {
                D_801D076C = 1.5f;
            }
            D_801D0768 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 =
                (f32) (((f64) ((((180.0f - FABS(D_801D0760)) / 180.0f) * D_801D0724 * D_801D076C) - D_801D0768) *
                        0.15) +
                       (f64) D_801D0768);
            D_801D0754 = D_801CF060[arg0].unkC;
            D_801D0758 = D_801CF060[arg0].unk10;
            D_801D075C = D_801CF060[arg0].unk14;
            if (D_801CF060[arg0].unk68 < Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14)) {
                angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
                D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D0764);
                D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D0764);
            } else {
                D_801CF060[arg0].unkC += D_801CF060[arg0].unk24;
                D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C;
            }
            for (i = 0; i < 8; i++) {
                D_801D076C =
                    ((((D_801CF060[arg0].unk30 * 500.0f) + D_801CF060[arg0].unkC) - D_801D0754) * 0.125f * (f32) i) +
                    D_801D0754;
                D_801D0770 = D_801CF060[arg0].unk10 - 10.0f;
                D_801D0774 = ((D_801CF060[arg0].unk38 * 500.0f) + D_801CF060[arg0].unk14) - D_801D075C;
                D_801D0774 = (D_801D0774 * 0.125f * (f32) i) + D_801D075C;
                sp48 = func_8007FAE4(D_801D076C, D_801D0770, D_801D0774, &D_801D0760, &D_801D0764, &D_801D0768);
                sp4C = func_8007F448(D_801D076C, D_801D0770, D_801D0774, &D_801D0760, &D_801D0764, &D_801D0768);
                if ((f64) (func_80051CB4(D_801D076C, D_801D0774, &D_801D0760, &D_801D0768) + (sp4C + sp48)) > 0.0) {
                    D_801CF060[arg0].unk14 = D_801D075C;
                    D_801CF060[arg0].unkC = D_801D0754;
                    D_801CF060[arg0].unk24 = 0.0f;
                    D_801CF060[arg0].unk10 = D_801D0758;
                    D_801CF060[arg0].unk28 = 0.0f;
                    D_801CF060[arg0].unk2C = 0.0f;
                }
            }
            func_800A2B24(arg0);
            D_801D0754 = func_8009D4A8(D_801CF060[arg0].unkC - D_801B2F20[D_801CF060[arg0].unk9C].unk0,
                                       D_801CF060[arg0].unk14 - D_801B2F20[D_801CF060[arg0].unk9C].unk8);
            if ((D_801D0754 < 1000.0f) && (D_801D06D4 > 11.0f)) {
                D_801CF060[arg0].unk8 = 1;
                D_801CF060[arg0].unk9C = D_801B2F20[D_801CF060[arg0].unk9C].unkA0;
                D_801CF060[arg0].unk50 = 0;
            }
            best = -1;
            if (D_801D0754 > 3000.0f) {
                D_801D0754 = 2e9f;
                for (p = D_801B2F20, i = 0; i < D_801BB124; i++, p++) {
                    D_801D0758 = func_8009D4DC(D_801D06BC - p->unk0, D_801D06C4 - p->unk8);
                    if ((D_801D0758 < D_801D0754) && (p->unkC0 < 2)) {
                        best = i;
                        D_801D0754 = D_801D0758;
                    }
                }
                D_801CF060[arg0].unk9C = best;
            }
            D_801D0754 = cam->eyeX - D_801CF060[arg0].unkC;
            D_801D0758 = cam->eyeZ - D_801CF060[arg0].unk14;
            D_801D075C = func_8009D564(-func_8009D3AC(cam->unkF0, cam->unkF4));
            D_801D0760 = func_8009D564(
                func_8009D3AC(D_801CF060[arg0].unkC - cam->eyeX, -(D_801CF060[arg0].unk14 - cam->eyeZ)));
            if ((func_8009D4DC(D_801D0754, D_801D0758) > 1.6e7f) ||
                ((FABS(Math_Normalize_Angle(D_801D0760 - D_801D075C)) > 100.0f) &&
                 (func_8009D4DC(D_801D0754, D_801D0758) > 250000.0f))) {
                D_801D0754 = D_801CF060[arg0].unkC;
                D_801D0758 = D_801CF060[arg0].unk14;
                D_801D0764 = func_8009D564(180.0f - func_8009D3AC(cam->unkF0, cam->unkF4));
                angle = (s32) ((D_801D0764 / 360.0f) * 4096.0f);
                D_801CF060[arg0].unkC = (COS(angle) * 200.0f) + cam->eyeX;
                D_801CF060[arg0].unk14 = (SIN(angle) * 200.0f) + cam->eyeZ;
                if (func_800A6684(arg0) != 0) {
                    D_801CF060[arg0].unkC = D_801D0754;
                    D_801CF060[arg0].unk14 = D_801D0758;
                }
            }
        } else if (D_801CF060[arg0].unk8 == 13) {
            D_801D0754 = Math_Normalize_Angle(D_801CF060[arg0].unk8C - D_801CF060[arg0].unk18);
            if (D_801D0754 >= 10.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 10.0f);
            }
            if (D_801D0754 <= -10.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 10.0f);
            }
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                (f32) (((f64) Math_Normalize_Angle((D_801D0760 / 3.0f) - D_801CF060[arg0].unk1C) * 0.1) +
                       (f64) D_801CF060[arg0].unk1C));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D076C = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            if ((f64) D_801D076C > 100.0) {
                D_801D076C = 100.0f;
            }
            func_800A2B24(arg0);
            if (FABS(D_801D0754) < 10.0f) {
                D_801CF060[arg0].unk8 = 5;
            }
            D_801D0754 = D_801CF060[arg0].unkC;
            D_801D0758 = D_801CF060[arg0].unk10;
            D_801D075C = D_801CF060[arg0].unk14;
            angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
            D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D076C);
            D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D076C);
            for (i = 0; i < 4; i++) {
                D_801D0770 = D_801CF060[arg0].unk10 - 20.0f;
                D_801D076C = ((D_801CF060[arg0].unk14 - D_801D075C) * 0.25f * (f32) i) + D_801D075C;
                sp48 = func_8007FAE4(D_801D076C, D_801D0770, D_801D0774, &D_801D0760, &D_801D0764, &D_801D0768);
                sp4C = func_8007F448(D_801D076C, D_801D0770, D_801D0774, &D_801D0760, &D_801D0764, &D_801D0768);
                if ((f64) (func_80051CB4(D_801D076C, D_801D0774, &D_801D0760, &D_801D0768) + (sp4C + sp48)) > 0.0) {
                    D_801CF060[arg0].unkC = D_801D0754;
                    D_801CF060[arg0].unk10 = D_801D0758;
                    D_801CF060[arg0].unk14 = D_801D075C;
                    D_801CF060[arg0].unk24 *= 0.5f;
                    D_801CF060[arg0].unk28 *= 0.5f;
                    D_801CF060[arg0].unk2C *= 0.5f;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A68A4.s")
#endif

// TODO: Migrate rodata

void func_800A9130(s32 arg0) {
    char pad[0x8]; // stack pad

    if ((gGameModeState == 3) && (gCurrentPauseMenuOption == -1)) {
        if (D_801CF060[arg0].unk8 == 1) {
            func_800A52D8(arg0, 200.0f);
            if ((D_801D0738 + 1) == D_801CE728[0]) {
                if (arg0 == 0) {
                    D_801CF060->unkC = 6000.0f;
                    D_801CF060->unk18 = 90.0f;
                    D_801CF060->unk4C = 25.0f;
                    D_801CF060->unk9C = 0;
                    D_801CF060->unk8 = 0xB;
                    D_801CF060->unk0 = 6;
                    D_801CF060->unk14 = 4000.0f;
                }
                if (arg0 == 1) {
                    D_801CF060[1].unk8 = 0xC;
                    D_801CF060[1].unk0 = 6;
                    D_801CF060[1].unk7C = 0;
                }
                if (arg0 == 2) {
                    D_801CF060[2].unk7C = 0;
                    D_801CF060[2].unk14 = 4000.0f;
                    D_801CF060[2].unkC = 4800.0f;
                    D_801CF060[2].unk18 = 180.0f;
                    D_801CF060[2].unk0 = 6, D_801CF060[2].unk8 = 2;
                }
            }
        } else {
            if (D_801CF060[arg0].unk8 == 0xB) {
                func_800A52D8(arg0, 100.0f);
            } else if (D_801CF060[arg0].unk8 == 0xC) {
                D_801CF060[arg0].unkC = D_801CF060[D_801CF060[arg0].unk7C].unkC + 50.0f;
                D_801CF060[arg0].unk10 = D_801CF060[D_801CF060[arg0].unk7C].unk10;
                D_801CF060[arg0].unk14 = 4000.0f - (D_801CF060[D_801CF060[arg0].unk7C].unk14 - 4000.0f);
                D_801CF060[arg0].unk18 = -D_801CF060[D_801CF060[arg0].unk7C].unk18;
                D_801CF060[arg0].unk1C = D_801CF060[D_801CF060[arg0].unk7C].unk1C;
                D_801CF060[arg0].unk20 = D_801CF060[D_801CF060[arg0].unk7C].unk20;
            } else if (D_801CF060[arg0].unk8 == 2) {
                if (((D_801CF060[D_801CF060[arg0].unk7C].unk9C == 0) ||
                     (D_801CF060[D_801CF060[arg0].unk7C].unk9C == 5)) &&
                    (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 1)) {
                    D_801CF060[arg0].unk50 = 0xE;
                    D_801CF060[arg0].unk54 = 0;
                    D_801CF060[arg0].unk74 = D_801CF060[arg0].unk78 = 0;
                }
                if ((D_801CF060[D_801CF060[arg0].unk7C].unk9C == 1) ||
                    (D_801CF060[D_801CF060[arg0].unk7C].unk9C == 6)) {
                    D_801CF060[arg0].unk50 = 0;
                    D_801CF060[arg0].unk54 = 0;
                    D_801CF060[arg0].unk74 = 6;
                    D_801CF060[arg0].unk78 = 0xA;
                }
                func_800A2B24(arg0);
            } else if (D_801CF060[arg0].unk8 == 5) {
                func_800A52D8(arg0, 200.0f);
            }
        }
    }
}

void func_800A93C8(s32 arg0) {
    D_801D0754 = func_8009D4A8(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) / 40.0f;
    D_801D0758 = 0.0f;

    func_800C1BD8(D_801D0754, D_801D0758);

    if ((gCurrentPauseMenuOption == -1) && (D_801CF060[arg0].unk8 == 1)) {
        func_800A52D8(arg0, 400.0f);
    }
}

void func_800A9494(s32 arg0) {
    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 1) {
            D_801CF060[arg0].unk74 = 0;
            switch (gCourseID) {
                case SUNNY_BEACH:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 3000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 1100.0f;
                    } else {
                        D_801D0754 = -3500.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = -1100.0f;
                    }
                    break;

                case GLACIER_COAST:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 4000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = -2600.0f;
                    } else {
                        D_801D0754 = -290.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 4800.0f;
                    }
                    break;
                default:
                    break;
            }

            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (FABS(D_801D0760) > 170) {
                if (arg0 % 2 == 0) {
                    D_801D0760 = 170.0f;
                } else {
                    D_801D0760 = -170.0f;
                }
            }
            if (arg0 % 2 == 0) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 += 2.0f;
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 += 3.0f;
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 -= 2.0f;
                    if (D_801D0760 < (-45.0f)) {
                        D_801CF060[arg0].unk18 -= 3.0f;
                    }
                }
            } else {
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 -= 2.0f;
                    if (D_801D0760 < (-45.0f)) {
                        D_801CF060[arg0].unk18 -= 3.0f;
                    }
                }
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 += 2.0f;
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 += 3.0f;
                    }
                }
            }
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18);
            D_801CF060[arg0].unk10 += 0.05 * (D_801D0758 - D_801CF060[arg0].unk10);
            D_801D0764 = (((180 - FABS(D_801D0760))) / 180.0f) * 30.0f;
            D_801CF060[arg0].unk1C =
                Math_Normalize_Angle(((f64) D_801CF060[arg0].unk1C) +
                                     (Math_Normalize_Angle(D_801D0760 - D_801CF060[arg0].unk1C) * 0.1));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = D_801D0760 + ((D_801D0764 - D_801D0760) * 0.1);
            D_801CF060[arg0].unkC +=
                (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            D_801CF060[arg0].unk14 +=
                (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            if (func_8009D4A8(D_801D0754 - D_801CF060[arg0].unkC, D_801D075C - D_801CF060[arg0].unk14) <
                D_801CF060[arg0].unk70) {
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unkA8 = (SysUtils_Rand() & 15) + 10;
                D_801CF060[arg0].unk70 = ((SysUtils_Rand() & 15) * 10.0f) + 200.0f;
            }
            if (func_8009D4A8(D_801D06BC - D_801D0754, D_801D06C4 - D_801D075C) < 1000.0f) {
                D_801CF060[arg0].unk9C = (D_801CF060[arg0].unk9C + 1) % 2;
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unkA8 = (SysUtils_Rand() & 15) + 10;
            }
            if (D_801CF060[arg0].unk78 == 15) {
                D_801CF060[arg0].unk78 = 0;
            }
        } else if (D_801CF060[arg0].unk8 == 7) {
            switch (gCourseID) {
                case SUNNY_BEACH:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 3000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 1100.0f;
                    } else {
                        D_801D0754 = -3500.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = -1100.0f;
                    }
                    break;

                case GLACIER_COAST:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 4000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = -2600.0f;
                    } else {
                        D_801D0754 = -290.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 4800.0f;
                    }
                    break;
                default:
                    break;
            }

            if (func_8009D4DC(D_801CF060[arg0].unk2C, D_801CF060[arg0].unk2C) < 1600.0f) {
                D_801CF060[arg0].unk24 =
                    D_801CF060[arg0].unk24 + (COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 2);
                D_801CF060[arg0].unk2C =
                    D_801CF060[arg0].unk2C + (SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 2);
            }
            D_801CF060[arg0].unkC += D_801CF060[arg0].unk24;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk28;
            D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C;
            D_801CF060[arg0].unkA4++;
            if (D_801CF060[arg0].unkA4 >= D_801CF060[arg0].unkA8) {
                D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unkA8 = 0;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unk8 = 1;
            }
            if (func_8009D4DC(D_801D06BC - D_801D0754, D_801D06C4 - D_801D075C) < 1000000.0f) {
                D_801CF060[arg0].unk9C = (D_801CF060[arg0].unk9C + 1) % 2;
            }
        }
    }
}

extern UnkStruct_801BC940 D_801BC940[];
extern f32 D_801D06F0;
extern f32 D_801D06F8;

void func_800A9D48(s32 arg0) {
    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 2) {
            switch (gCourseID) {
                case SUNNY_BEACH:
                    switch (gGameModes) {
                        case GMODE_TIME_TRIALS:
                        case GMODE_CHAMPIONSHIP:
                            D_801CF060[arg0].unkC = D_801AEE20[D_801CF060[arg0].unk98].unk0;
                            D_801CF060[arg0].unk14 = D_801AEE20[D_801CF060[arg0].unk98].unk8;
                            D_801CF060[arg0].unk10 = D_801AEE20[D_801CF060[arg0].unk98].unk4 + 50.0f;
                            break;
                        case GMODE_STUNT:
                            D_801CF060[arg0].unkC = D_801BC940[D_801CF060[arg0].unk98].unk0;
                            D_801CF060[arg0].unk14 = D_801BC940[D_801CF060[arg0].unk98].unk8;
                            D_801CF060[arg0].unk10 = D_801BC940[D_801CF060[arg0].unk98].unk4 + 135.0f;
                            break;
                    }
                    break;
                case MARINE_FORTRESS:
                    D_801CF060[arg0].unkC = D_801CF060[arg0].unk80;
                    D_801CF060[arg0].unk10 = D_801CF060[arg0].unk84;
                    D_801CF060[arg0].unk14 = D_801CF060[arg0].unk88;
                    break;
                case DRAKE_LAKE:
                    switch (gGameModes) {
                        case GMODE_TIME_TRIALS:
                        case GMODE_CHAMPIONSHIP:
                            D_801CF060[arg0].unkC = D_801AEE20[D_801CF060[arg0].unk98].unk0;
                            D_801CF060[arg0].unk14 = D_801AEE20[D_801CF060[arg0].unk98].unk8;
                            D_801CF060[arg0].unk10 = D_801AEE20[D_801CF060[arg0].unk98].unk4;
                            break;
                        case GMODE_STUNT:
                            D_801CF060[arg0].unkC = D_801BC940[D_801CF060[arg0].unk98].unk0;
                            D_801CF060[arg0].unk14 = D_801BC940[D_801CF060[arg0].unk98].unk8;
                            D_801CF060[arg0].unk10 = D_801BC940[D_801CF060[arg0].unk98].unk4 + 135.0f;
                            break;
                    }
                    break;
            }
            D_801CF060[arg0].unk1C = 0.0f;
            D_801D0754 = func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4);
            D_801D0758 = func_8009D4DC(D_801CF060[arg0].unkC - D_801D06F0, D_801CF060[arg0].unk14 - D_801D06F8);
            if (D_801D0754 < SQ(D_801CF060[arg0].unk70)) {
                if (gCourseID != MARINE_FORTRESS) {
                    D_801CF060[arg0].unk18 = func_8009D564(
                        func_8009D3AC(D_801CF060[arg0].unkC - D_801D06BC, -(D_801CF060[arg0].unk14 - D_801D06C4)));
                } else {
                    D_801CF060[arg0].unk18 = Math_Normalize_Angle(
                        func_8009D3AC(D_801CF060[arg0].unkC - D_801D06BC, -(D_801CF060[arg0].unk14 - D_801D06C4)) +
                        (s32) ((SysUtils_Rand() & 0xFF) - 0x80));
                }
            }
            if (D_801D0758 < SQ(D_801CF060[arg0].unk70)) {
                if (gCourseID != MARINE_FORTRESS) {
                    D_801CF060[arg0].unk18 = func_8009D564(
                        func_8009D3AC(D_801CF060[arg0].unkC - D_801D06F0, -(D_801CF060[arg0].unk14 - D_801D06F8)));
                } else {
                    D_801CF060[arg0].unk18 = Math_Normalize_Angle(
                        func_8009D3AC(D_801CF060[arg0].unkC - D_801D06F0, -(D_801CF060[arg0].unk14 - D_801D06F8)) +
                        (s32) ((SysUtils_Rand() & 0xFF) - 0x80));
                }
            }
            if ((D_801D0754 < SQ(D_801CF060[arg0].unk70)) || (D_801D0758 < SQ(D_801CF060[arg0].unk70))) {
                D_801CF060[arg0].unk8 = 9;
                D_801CF060[arg0].unk78 = D_801CF060[arg0].unk74 = 0;
                D_801CF060[arg0].unk24 = D_801CF060[arg0].unk2C = 0.0f;
                D_801CF060[arg0].unk28 = 10.0f;
                if (D_801CF060[arg0].unk0 == 2) {
                    D_801CF060[arg0].unk0 = 1;
                }
                if (D_801CF060[arg0].unk0 == 4) {
                    D_801CF060[arg0].unk0 = 3;
                }
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
            }
        } else if (D_801CF060[arg0].unk8 == 9) {
            D_801CF060[arg0].unk74 = 1;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk28;
            D_801CF060[arg0].unkA4++;
            D_801CF060[arg0].unk78 += 3;
            if (D_801CF060[arg0].unk78 >= 21) {
                D_801CF060[arg0].unk78 = 1;
            }
            if (D_801CF060[arg0].unkA4 >= 11) {
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
            }
        } else if (D_801CF060[arg0].unk8 == 7) {
            if (func_8009D4DC(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C) < 400.0f) {
                D_801CF060[arg0].unk24 =
                    D_801CF060[arg0].unk24 + COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 1;
                D_801CF060[arg0].unk2C =
                    D_801CF060[arg0].unk2C + SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 1;
            } else {
                D_801CF060[arg0].unk24 =
                    (D_801CF060[arg0].unk24 / func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C)) * 20.0f;
                D_801CF060[arg0].unk2C =
                    (D_801CF060[arg0].unk2C / func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C)) * 20.0f;
            }
            D_801CF060[arg0].unkC += D_801CF060[arg0].unk24;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk28;
            D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C;
            D_801CF060[arg0].unkA4++;
            if (D_801CF060[arg0].unkA4 >= 4) {
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unk8 = 8;
            }
        } else if (D_801CF060[arg0].unk8 == 8) {
            D_801CF060[arg0].unk74 = 0;
            switch (gCourseID) {
                case SUNNY_BEACH:
                    switch (gGameModes) {
                        case GMODE_TIME_TRIALS:
                        case GMODE_CHAMPIONSHIP:
                            D_801D0754 = D_801AEE20[D_801CF060[arg0].unk98].unk0;
                            D_801D0758 = D_801AEE20[D_801CF060[arg0].unk98].unk4 + 50.0f;
                            D_801D075C = D_801AEE20[D_801CF060[arg0].unk98].unk8;
                            break;
                        case GMODE_STUNT:
                            D_801D0754 = D_801BC940[D_801CF060[arg0].unk98].unk0;
                            D_801D0758 = D_801BC940[D_801CF060[arg0].unk98].unk4 + 135.0f;
                            D_801D075C = D_801BC940[D_801CF060[arg0].unk98].unk8;
                            break;
                    }
                    break;
                case MARINE_FORTRESS:
                    D_801D0754 = D_801CF060[arg0].unk80;
                    D_801D0758 = D_801CF060[arg0].unk84;
                    D_801D075C = D_801CF060[arg0].unk88;
                    break;
                case DRAKE_LAKE:
                    switch (gGameModes) {
                        case GMODE_TIME_TRIALS:
                        case GMODE_CHAMPIONSHIP:
                            D_801D0754 = D_801AEE20[D_801CF060[arg0].unk98].unk0;
                            D_801D0758 = D_801AEE20[D_801CF060[arg0].unk98].unk4;
                            D_801D075C = D_801AEE20[D_801CF060[arg0].unk98].unk8;
                            break;
                        case GMODE_STUNT:
                            D_801D0754 = D_801BC940[D_801CF060[arg0].unk98].unk0;
                            D_801D0758 = D_801BC940[D_801CF060[arg0].unk98].unk4 + 135.0f;
                            D_801D075C = D_801BC940[D_801CF060[arg0].unk98].unk8;
                            break;
                    }
                    break;
            }
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801D0760 > 0.0f) {
                D_801CF060[arg0].unk18 += 2.0f;
                if (D_801D0760 > 45.0f) {
                    D_801CF060[arg0].unk18 += 3.0f;
                }
            }
            if (D_801D0760 < 0.0f) {
                D_801CF060[arg0].unk18 -= 2.0f;
                if (D_801D0760 < -45.0f) {
                    D_801CF060[arg0].unk18 -= 3.0f;
                }
            }
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18);
            D_801CF060[arg0].unk10 += 0.05 * (D_801D0758 - D_801CF060[arg0].unk10);
            D_801D0764 = ((180 - FABS(D_801D0760)) / 180.0f) * 20.0f;
            if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < 80000.0f) {
                D_801D0764 = func_8009D4A8(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) *
                             0.005 * D_801D0764;
                D_801CF060[arg0].unkC += 0.05 * (D_801D0754 - D_801CF060[arg0].unkC);
                D_801CF060[arg0].unk14 += 0.05 * (D_801D075C - D_801CF060[arg0].unk14);
            }
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                D_801CF060[arg0].unk1C + (Math_Normalize_Angle(D_801D0760 - D_801CF060[arg0].unk1C) * 0.1));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = D_801D0760 + ((D_801D0764 - D_801D0760) * 0.1);
            if (func_8009D4DC(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C) < 900.0f) {
                D_801CF060[arg0].unkC +=
                    (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
                D_801CF060[arg0].unk14 +=
                    (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            } else {
                D_801CF060[arg0].unkC +=
                    (D_801CF060[arg0].unk24 =
                         (D_801CF060[arg0].unk24 / func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C)) *
                         30.0f);
                D_801CF060[arg0].unk14 +=
                    (D_801CF060[arg0].unk2C =
                         (D_801CF060[arg0].unk2C / func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C)) *
                         30.0f);
            }
            if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < 200.0f) {
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unk8 = 2;
                if (D_801CF060[arg0].unk0 == 1) {
                    D_801CF060[arg0].unk0 = 2;
                }
                if (D_801CF060[arg0].unk0 == 3) {
                    D_801CF060[arg0].unk0 = 4;
                }
            }
            if ((func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) < 4000000.0f) ||
                (func_8009D4DC(D_801CF060[arg0].unkC - D_801D06F0, D_801CF060[arg0].unk14 - D_801D06F8) < 4000000.0f)) {
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unk28 = 5.0f;
            }
        }
    }
}

extern f32 D_801D06D8;
extern f32 D_801D06E0;

void func_800AAAC8(s32 arg0) {
    s32 i;

    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 2) {
            D_801CF060[arg0].unkC = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk8 + D_801CF060[arg0].unk80;
            D_801CF060[arg0].unk14 = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unkC + D_801CF060[arg0].unk88;
            D_801CF060[arg0].unk10 = Water_GetHeight(D_801CF060[arg0].unkC, D_801CF060[arg0].unk14) + 20.0f;
            D_801CF060[arg0].unk1C = 0.0f;
            D_801D0754 = func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4);
            if (D_801D0754 < SQ(D_801CF060[arg0].unk70)) {
                for (i = 0; i < 30; i++) {
                    if (D_801CF060[i].unk0 == 2) {
                        D_801CF060[i].unk18 = Math_Normalize_Angle(func_8009D3AC(
                            D_800E6C78[gCourseID][D_800E6C78[gCourseID][D_801CF060[i].unk9C].unk0].unk8 -
                                D_801CF060[i].unkC,
                            -(D_800E6C78[gCourseID][D_800E6C78[gCourseID][D_801CF060[i].unk9C].unk0].unkC -
                              D_801CF060[i].unk14)));
                        // The [arg0] stores in this loop are in the original.
                        D_801CF060[i].unk24 = D_801CF060[arg0].unk2C = 0.0f;
                        D_801CF060[i].unk28 = (s32) ((SysUtils_Rand() & 3) + 1);
                        D_801CF060[i].unk8 = 9;
                        D_801CF060[i].unk78 = D_801CF060[arg0].unk74 = 0;
                        D_801CF060[i].unk0 = 1;
                        D_801CF060[i].unkA4 = D_801CF060[arg0].unkA8 = 0;
                        D_801CF060[i].unkAC = (SysUtils_Rand() & 0xF) + 3;
                    }
                }
                func_800C1DA8();
            }
        } else if (D_801CF060[arg0].unk8 == 9) {
            if (D_801CF060[arg0].unkAC != 0) {
                D_801CF060[arg0].unkAC--;
                return;
            }
            D_801CF060[arg0].unk74 = 1;
            D_801CF060[arg0].unkA4++;
            D_801CF060[arg0].unk78 += 3;
            if (D_801CF060[arg0].unk78 >= 21) {
                D_801CF060[arg0].unk78 = 1;
            }
            if (D_801CF060[arg0].unkA4 >= 3) {
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
            }
        } else if (D_801CF060[arg0].unk8 == 7) {
            if (func_8009D4DC(D_801CF060[arg0].unk2C, D_801CF060[arg0].unk2C) < 4900.0f) {
                D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 4.0f;
                D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 4.0f;
            }
            D_801CF060[arg0].unk20 -= 1.0f;
            D_801CF060[arg0].unkC += D_801CF060[arg0].unk24 + D_801D06D8;
            D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C + D_801D06E0;
            D_801CF060[arg0].unkA4++;
            if (D_801CF060[arg0].unkA4 >= 10) {
                D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unk8 = 8;
                D_801CF060[arg0].unk9C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk0;
            }
        } else if (D_801CF060[arg0].unk8 == 8) {
            D_801CF060[arg0].unk74 = 0;
            D_801D0754 = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk8 + D_801CF060[arg0].unk80;
            D_801D075C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unkC + D_801CF060[arg0].unk88;
            D_801D0758 = D_801CF060[arg0].unk10 + D_801CF060[arg0].unk28;
            D_801CF060[arg0].unk20 *= 0.8;
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801D0760 > 0.0f) {
                D_801CF060[arg0].unk18 += 2.0f;
                if (D_801D0760 > 45.0f) {
                    D_801CF060[arg0].unk18 += 3.0f;
                }
            }
            if (D_801D0760 < 0.0f) {
                D_801CF060[arg0].unk18 -= 2.0f;
                if (D_801D0760 < -45.0f) {
                    D_801CF060[arg0].unk18 -= 3.0f;
                }
            }
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18);
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk28;
            D_801D0764 = ((180 - FABS(D_801D0760)) / 180.0f) * 50.0f;
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                D_801CF060[arg0].unk1C + (Math_Normalize_Angle(D_801D0760 - D_801CF060[arg0].unk1C) * 0.2));
            if (D_801CF060[arg0].unk1C > 60.0f) {
                D_801CF060[arg0].unk1C = 60.0f;
            }
            if (D_801CF060[arg0].unk1C < -60.0f) {
                D_801CF060[arg0].unk1C = -60.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = D_801D0760 + ((D_801D0764 - D_801D0760) * 0.15);
            D_801CF060[arg0].unkC +=
                (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            D_801CF060[arg0].unk14 +=
                (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D0754, D_801CF060[arg0].unk14 - D_801D075C) < 360000.0f) {
                if (!(D_801CF060[arg0].unk9C & 3)) {
                    D_801CF060[arg0].unkA4 = D_801CF060[arg0].unkA8 = D_801CF060[arg0].unkAC = 0;
                    D_801CF060[arg0].unk8 = 2;
                    func_800C1DEC();
                    D_801CF060[arg0].unk0 = 2;
                    return;
                }
                D_801CF060[arg0].unk9C = D_800E6C78[gCourseID][D_801CF060[arg0].unk9C].unk0;
            }
        }
    }
}

void func_800AB25C(s32 arg0) {
    s32 angle;
    f32 dist;

    if ((gGameModeState == GMODE_STATE_STARTED) && (gCurrentPauseMenuOption == -1)) {
        if (D_801CF060[arg0].unk7C != 0xFF) {
            D_801D0758 = D_801CF060[D_801CF060[arg0].unk7C].unk18 - 180.0f;
            switch (arg0) {
                case 1:
                    angle = ((D_801D0758 - 20.0f) / 360.0f) * 4096.0f;
                    dist = 400.0f;
                    dist += 200.0f * SIN(D_800E62C4 * 2);
                    D_801D0754 = D_801CF060[D_801CF060[arg0].unk7C].unkC + (COS(angle) * dist);
                    D_801D075C = D_801CF060[D_801CF060[arg0].unk7C].unk14 + (SIN(angle) * dist);
                    if ((D_801CF060[D_801CF060[arg0].unk7C].unk50 == 15) &&
                        (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 50)) {
                        D_801CF060[arg0].unk50 = 15;
                        D_801CF060[arg0].unk54 = 0;
                    }
                    if ((D_801CF060[D_801CF060[arg0].unk7C].unk50 == 16) &&
                        (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 50)) {
                        D_801CF060[arg0].unk50 = 16;
                        D_801CF060[arg0].unk54 = 0;
                    }
                    break;
                case 2:
                    angle = ((D_801D0758 + 20.0f) / 360.0f) * 4096.0f;
                    dist = 400.0f;
                    dist += 200.0f * SIN(D_800E62C4 * 2);
                    D_801D0754 = D_801CF060[D_801CF060[arg0].unk7C].unkC + (COS(angle) * dist);
                    D_801D075C = D_801CF060[D_801CF060[arg0].unk7C].unk14 + (SIN(angle) * dist);
                    if ((D_801CF060[D_801CF060[arg0].unk7C].unk50 == 15) &&
                        (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 55)) {
                        D_801CF060[arg0].unk50 = 15;
                        D_801CF060[arg0].unk54 = 0;
                    }
                    if ((D_801CF060[D_801CF060[arg0].unk7C].unk50 == 16) &&
                        (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 55)) {
                        D_801CF060[arg0].unk50 = 16;
                        D_801CF060[arg0].unk54 = 0;
                    }
                    break;
            }
            D_801CF060[arg0].unk4C =
                func_8009D4A8(D_801D0754 - D_801CF060[arg0].unkC, D_801D075C - D_801CF060[arg0].unk14) / 10.0f;
            if (D_801CF060[arg0].unk4C > 80) {
                D_801CF060[arg0].unk4C = 80.0f;
            }
            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (D_801D0760 >= 2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 2.0f);
                if (D_801D0760 > 45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + 5.0f);
                }
            }
            if (D_801D0760 <= -2) {
                D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 2.0f);
                if (D_801D0760 < -45.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - 5.0f);
                }
            }
            if (FABS(D_801D0760) < 2.0f) {
                D_801CF060[arg0].unk18 = func_8009D564(
                    func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)));
            }
            D_801CF060[arg0].unk1C = 0.0f;
            D_801D0768 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 =
                ((((180 - FABS(D_801D0760)) / 180.0f) * D_801CF060[arg0].unk4C) - D_801D0768) * 0.15 + D_801D0768;
            D_801CF060[arg0].unkC +=
                (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            D_801CF060[arg0].unk14 +=
                (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            func_800A2B24(arg0);
            return;
        }
        if (D_801CF060[arg0].unk8 == 1) {
            func_800A52D8(arg0, 200.0f);
        }
    }
}

void func_800AB890(s32 arg0) {
    s32 temp_v1;
    StructAB90* temp_v0;

    if ((gGameModeState == 3) && (gCurrentPauseMenuOption == -1)) {
        temp_v0 = (StructAB90*) ((arg0 * 0xBC) + (u32) &D_801CF060);

        if (temp_v0->unk8 == 2) {
            temp_v0->unk78 = (s32) (temp_v0->unk78 + 1);
        } else if (temp_v0->unk8 == 1) {
            temp_v0->unk74 = 1;
            temp_v0->unk78 = (s32) (temp_v0->unk78 + 1);
            func_800A52D8(arg0, 200.0f);
        }
    }
}

void func_800AB92C(void) {
    D_800E62C8 = D_800E62CC = 0;
    func_8009D5C0();
}

// The entries func_800AB95C adds to D_801CF060: a type and a count.
typedef struct UnkStruct_800AB95C {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} UnkStruct_800AB95C; /* size = 0x8 */

extern struct UnkStruct_801C2938 gRiderRaceState[];
extern s32 D_80192460[];
extern f32 D_801D06C0;
extern f32 D_801D06C8;
extern f32 D_801D06CC;
extern f32 D_801D06D0;
extern f32 D_801D06DC;
extern f32 D_801D06E4;
extern f32 D_801D06E8;
extern f32 D_801D06EC;
extern f32 D_801D06F0;
extern f32 D_801D06F4;
extern f32 D_801D06F8;
extern f32 D_801D06FC;
extern f32 D_801D0700;
extern f32 D_801D0704;
extern f32 D_801D0708;
extern f32 D_801D070C;
extern f32 D_801D0710;
extern f32 D_801D0714;
extern f32 D_801D0718;
extern f32 D_801D071C;
extern f32 D_801D0720;
extern f32 D_801D0724;
extern f32 D_801D0728;
extern f32 D_801D0778;
extern f32 D_801D0780;
extern f32 D_801D0784;
extern f32 D_801D078C;
extern s32 D_801D0730;
extern s32 D_801D0734;
extern s32 D_801D073C;
extern s32 D_801D0744;
extern s32 D_801D0748;
extern s32 D_801D074C;
extern s32 D_801D0750;
void func_800A68A4(s32);
void func_800A9D48(s32);
void func_800AB25C(s32);

void func_800AB95C(UnkStruct_800AB95C* arg0, s32 arg1) {
    s32 sp94;
    UnkStruct_80192690* rider;
    UnkStruct_80192690* rider2;
    s32 i;
    s32 j;
    GfxPool* pool;
    UNUSED s32 pad[8]; // stack pad: cam is spilled to 0x5C, as in the original
    camera_unk_1* cam;

    cam = &gCameraPerspective[D_80223930];
    rider = &D_80192690[gPlayer1Rider];
    if (gPlayers == TWO_PLAYERS) {
        rider2 = &D_80192690[gPlayer2Rider];
    } else {
        rider2 = &D_80192690[gPlayer1Rider];
    }
    pool = gGfxPool;
    D_800E62C4++;
    D_801D0778 = pool->unk13D68[D_80192460[0]].v.ob[0];
    D_801D0780 = pool->unk13D68[D_80192460[0]].v.ob[2];
    D_801D06BC = rider->unk44.x;
    D_801D06C0 = rider->unk44.y;
    D_801D06C4 = rider->unk44.z;
    D_801D06C8 = rider->unk5C;
    D_801D06CC = rider->unk60;
    D_801D06D0 = rider->unk64;
    D_801D06D8 = D_801D06BC - D_801D06E4;
    D_801D06DC = D_801D06C0 - D_801D06E8;
    D_801D06E0 = D_801D06C4 - D_801D06EC;
    D_801D06E4 = D_801D06BC;
    D_801D06E8 = D_801D06C0;
    D_801D06EC = D_801D06C4;
    D_801D06D4 = sqrtf(SQ(D_801D06D8) + SQ(D_801D06E0));
    if (D_801D0724 < D_801D06D4) {
        D_801D0724 = D_801D06D4;
    }
    D_801D0730 = gRiderRaceState[gPlayer1Rider].unkC;
    D_801D0738 = gRiderRaceState[gPlayer1Rider].unk0;
    D_801D0734 = gRiderRaceState[gPlayer1Rider].unk4;
    D_801D073C = gRiderRaceState[gPlayer1Rider].unk2F4;
    if (gPlayers == TWO_PLAYERS) {
        D_801D0784 = pool->unk13D68[D_80192460[1]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[1]].v.ob[2];
    } else {
        D_801D0784 = pool->unk13D68[D_80192460[0]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[0]].v.ob[2];
    }
    D_801D06F0 = rider2->unk44.x;
    D_801D06F4 = rider2->unk44.y;
    D_801D06F8 = rider2->unk44.z;
    D_801D06FC = rider2->unk5C;
    D_801D0700 = rider2->unk60;
    D_801D0704 = rider2->unk64;
    D_801D070C = D_801D06F0 - D_801D0718;
    D_801D0710 = D_801D06F4 - D_801D071C;
    D_801D0714 = D_801D06F8 - D_801D0720;
    D_801D0718 = D_801D06F0;
    D_801D071C = D_801D06F4;
    D_801D0720 = D_801D06F8;
    D_801D0708 = sqrtf(SQ(D_801D06D8) + SQ(D_801D06E0));
    if (D_801D0728 < D_801D0708) {
        D_801D0728 = D_801D0708;
    }
    if (gPlayers == TWO_PLAYERS) {
        D_801D0744 = gRiderRaceState[gPlayer2Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer2Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer2Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer2Rider].unk2F4;
    } else {
        D_801D0744 = gRiderRaceState[gPlayer1Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer1Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer1Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer1Rider].unk2F4;
    }
    if (D_800E62CC < 30) {
        if (arg0 == (UnkStruct_800AB95C*) 1) {
            D_801CF060[0].unkC = 6000.0f;
            D_801CF060[0].unk9C = 2;
            D_801CF060[0].unk8 = 11;
            D_801CF060[0].unk0 = 6;
            D_801CF060[1].unk8 = 12;
            D_801CF060[1].unk0 = 6;
            D_801CF060[1].unk7C = 0;
            D_801CF060[2].unk7C = 0;
            D_801CF060[2].unk8 = 2;
            D_801CF060[2].unk0 = 6;
            D_800E62C8 = D_800E62CC = 3;
            D_801CF060[0].unk14 = 4000.0f;
            D_801CF060[2].unk14 = 4000.0f;
            D_801CF060[0].unk18 = 90.0f;
            D_801CF060[0].unk4C = 25.0f;
            D_801CF060[2].unkC = 4800.0f;
            D_801CF060[2].unk18 = 180.0f;
            return;
        }
        for (i = 0; i < arg1; i++) {
            for (j = 0; j < arg0[i].unk4; j++) {
                D_801CF060[D_800E62C8].unk0 = arg0[sp94].unk0; // sp94 is never set
                if ((D_801CF060[D_800E62C8].unk0 == 7) || (D_801CF060[D_800E62C8].unk0 == 8) ||
                    (D_801CF060[D_800E62C8].unk0 == 9) || (D_801CF060[D_800E62C8].unk0 == 10)) {
                    // The random angles go through u16, as the original's temporary registers show.
                    D_801CF060[D_800E62C8].unkC = (COS((u16) SysUtils_Rand()) * 500.0f) + cam->eyeX;
                    D_801CF060[D_800E62C8].unk14 = (SIN((u16) SysUtils_Rand()) * 500.0f) + cam->eyeX;
                    D_801CF060[D_800E62C8].unk7C = 0xFF;
                    D_801CF060[D_800E62C8].unk10 = -80.0f - (s32) (SysUtils_Rand() & 0x3F);
                    D_801CF060[D_800E62C8].unk8 = 5;
                    D_801CF060[D_800E62C8].unk80 = 100000.0f;
                    D_801CF060[D_800E62C8].unk84 = 100000.0f;
                    D_801CF060[D_800E62C8].unk88 = 100000.0f;
                }
                D_800E62C8++;
                D_800E62CC++;
                if (D_800E62CC >= 30) {
                    return;
                }
            }
        }
    }
}

// The entries func_800AC098 copies into D_801CF060 (the same layout as code_C6C0.c's UnkStruct_80192540).
typedef struct UnkStruct_800AC098 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ f32 unk30;
} UnkStruct_800AC098; /* size = 0x34 */

void func_800AC098(UnkStruct_800AC098* arg0, s32 arg1) {
    s32 j;
    s32 k;

    if (D_800E62CC < 30) {
        for (k = 0, j = D_800E62CC; j < D_800E62CC + arg1; j++) {
            D_801CF060[j].unk0 = arg0[k].unk0;
            D_801CF060[j].unkB8 = 1;
            D_801CF060[j].unk74 = arg0[k].unk4;
            D_801CF060[j].unk78 = arg0[k].unk8;
            D_801CF060[j].unkC = arg0[k].unkC.x;
            D_801CF060[j].unk10 = arg0[k].unkC.y;
            D_801CF060[j].unk14 = arg0[k].unkC.z;
            D_801CF060[j].unk30 = arg0[k].unk18.x;
            D_801CF060[j].unk34 = arg0[k].unk18.y;
            D_801CF060[j].unk38 = arg0[k].unk18.z;
            D_801CF060[j].unk3C = arg0[k].unk24.x;
            D_801CF060[j].unk40 = arg0[k].unk24.y;
            D_801CF060[j].unk44 = arg0[k].unk24.z;
            D_801CF060[j].unk48 = arg0[k].unk30;
            k++;
            if (D_800E62CC + k >= 30) {
                return;
            }
        }
        D_800E62CC += arg1;
    }
}

extern MtxF D_800E6280;
extern s32 D_800E62D0;
extern s32 D_800E62D4;
extern s32 D_801CB340;

void func_800AC184(void) {
    s32 pad[5]; // stack pad
    UnkStruct_80192690* rider;
    UnkStruct_80192690* rider2;
    GfxPool* pool;
    s32 i;
    s32 t;
    s32 j;

    rider = &D_80192690[gPlayer1Rider];
    if (gPlayers == TWO_PLAYERS) {
        rider2 = &D_80192690[gPlayer2Rider];
    } else {
        rider2 = &D_80192690[gPlayer1Rider];
    }
    pool = gGfxPool;
    D_800E62C4++;
    D_801D0778 = pool->unk13D68[D_80192460[0]].v.ob[0];
    D_801D0780 = pool->unk13D68[D_80192460[0]].v.ob[2];
    D_801D06BC = rider->unk44.x;
    D_801D06C0 = rider->unk44.y;
    D_801D06C4 = rider->unk44.z;
    D_801D06C8 = rider->unk5C;
    D_801D06CC = rider->unk60;
    D_801D06D0 = rider->unk64;
    D_801D06D8 = 0.0f;
    D_801D06DC = 0.0f;
    D_801D06E0 = 0.0f;
    D_801D06E4 = D_801D06BC;
    D_801D06E8 = D_801D06C0;
    D_801D06EC = D_801D06C4;
    D_801D06D4 = sqrtf(SQ(D_801D06D8) + SQ(D_801D06E0));
    if (D_801D0724 < D_801D06D4) {
        D_801D0724 = D_801D06D4;
    }
    D_801D0730 = gRiderRaceState[gPlayer1Rider].unkC;
    D_801D0738 = gRiderRaceState[gPlayer1Rider].unk0;
    D_801D0734 = gRiderRaceState[gPlayer1Rider].unk4;
    D_801D073C = gRiderRaceState[gPlayer1Rider].unk2F4;
    if (gPlayers == TWO_PLAYERS) {
        D_801D0784 = pool->unk13D68[D_80192460[1]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[1]].v.ob[2];
    } else {
        D_801D0784 = pool->unk13D68[D_80192460[0]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[0]].v.ob[2];
    }
    D_801D06F0 = rider2->unk44.x;
    D_801D06F4 = rider2->unk44.y;
    D_801D06F8 = rider2->unk44.z;
    D_801D06FC = rider2->unk5C;
    D_801D0700 = rider2->unk60;
    D_801D0704 = rider2->unk64;
    D_801D070C = 0.0f;
    D_801D0710 = 0.0f;
    D_801D0714 = 0.0f;
    D_801D0718 = D_801D06F0;
    D_801D071C = D_801D06F4;
    D_801D0720 = D_801D06F8;
    D_801D0708 = sqrtf(SQ(D_801D06D8) + SQ(D_801D06E0));
    if (D_801D0728 < D_801D0708) {
        D_801D0728 = D_801D0708;
    }
    if (gPlayers == TWO_PLAYERS) {
        D_801D0744 = gRiderRaceState[gPlayer2Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer2Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer2Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer2Rider].unk2F4;
    } else {
        D_801D0744 = gRiderRaceState[gPlayer1Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer1Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer1Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer1Rider].unk2F4;
    }
    func_8009D5C0();
    SysUtils_MtxFToMtx(&D_800E6280, &D_801D0678);
    if ((D_801CE638 == 8) || (D_801CE638 == 21)) {
        return;
    }
    if (gPlayers == TWO_PLAYERS) {
        D_800E62C8 = D_800E62CC = 0;
        return;
    }
    D_801D0724 = D_801D0728 = 30.0f;
    switch (gCourseID) {
        case DOLPHIN_PARK:
            func_800C123C((u8*) &D_801D0668);
            D_800E62D0 = 0;
            if (gPlayers == ONE_PLAYER) {
                D_801CF060[0].unk2C = 0.0f;
                D_801CF060[0].unk10 = -20.0f;
                D_801CF060[0].unk68 = D_801CF060[0].unk10;
                D_801CF060[0].unk6C = D_801CF060[0].unk14 = D_801AEE20[0].unk8 + 100.0f;
                D_801CF060[0].unk0 = 6;
                D_801CF060[0].unk7C = 0xFF;
                D_801CF060[0].unk8 = 5;
                D_801CF060[0].unk9C = 1;
                D_801CF060[0].unk64 = D_801CF060[0].unkC = D_801AEE20[0].unk0 - 200.0f;
                D_801CF060[0].unk50 = 0;
                D_801CF060[0].unk54 = 0;
                D_801CF060[0].unk74 = 5;
                D_801CF060[0].unk78 = 10;
                D_801CF060[0].unk18 = 0.0f;
                D_801CF060[0].unk1C = D_801CF060[0].unk24 = D_801CF060[0].unk28 = D_801CF060[0].unk2C;
                if (D_800E62D4 > 0) {
                    D_801CF060[1].unk0 = 6;
                }
                if (D_800E62D4 >= 2) {
                    D_801CF060[2].unk0 = 6;
                }
                if (D_800E62D4 >= 3) {
                    D_801CF060[3].unk0 = 6;
                }
                for (i = 1; i < 4; i++) {
                    D_801CF060[i].unk7C = 0;
                    D_801CF060[i].unk8 = 5;
                    D_801CF060[i].unk2C = 0.0f;
                    D_801CF060[i].unk28 = 0.0f;
                    D_801CF060[i].unk24 = 0.0f;
                    D_801CF060[i].unk1C = 0.0f;
                    D_801CF060[i].unk9C = 1;
                    D_801CF060[i].unk68 = D_801CF060[i].unk10 = -20.0f;
                    D_801CF060[i].unk6C = D_801CF060[i].unk14 = 5000.0f;
                    D_801CF060[i].unk64 = D_801CF060[i].unkC = 47.0f;
                    D_801CF060[i].unk50 = 5;
                    D_801CF060[i].unk54 = 20;
                    D_801CF060[i].unk18 = 180.0f;
                }
                if (D_801CE638 != 0) {
                    for (i = 4; i < 12; i++) {
                        D_801CF060[i].unk7C = 0xFF;
                        D_801CF060[i].unkC = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06BC;
                        D_801CF060[i].unk14 = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06C4;
                        t = SysUtils_Rand() & 0x3F;
                        D_801CF060[i].unk8 = 5;
                        D_801CF060[i].unk80 = 100000.0f;
                        D_801CF060[i].unk84 = 100000.0f;
                        D_801CF060[i].unk88 = 100000.0f;
                        D_801CF060[i].unk10 = -80.0f - t;
                        if ((i % 3) == 0) {
                            D_801CF060[i].unk0 = 7;
                        }
                        if ((i % 3) == 1) {
                            D_801CF060[i].unk0 = 8;
                        }
                        if ((i % 3) == 2) {
                            D_801CF060[i].unk0 = 9;
                        }
                        D_801CF060[i].unk78 = D_801CF060[i].unk74 = 0;
                    }
                }
            }
            D_800E62C8 = D_800E62CC = 12;
            break;
        case SUNNY_BEACH:
            if (gPlayers == ONE_PLAYER) {
                for (i = 0; i < 6; i++) {
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unkC = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06BC;
                    D_801CF060[i].unk14 = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06C4;
                    t = SysUtils_Rand() & 0x3F;
                    D_801CF060[i].unk8 = 5;
                    D_801CF060[i].unk80 = 100000.0f;
                    D_801CF060[i].unk84 = 100000.0f;
                    D_801CF060[i].unk88 = 100000.0f;
                    D_801CF060[i].unk10 = -80.0f - t;
                    if ((i % 3) == 0) {
                        D_801CF060[i].unk0 = 7;
                    }
                    if ((i % 3) == 1) {
                        D_801CF060[i].unk0 = 8;
                    }
                    if ((i % 3) == 2) {
                        D_801CF060[i].unk0 = 9;
                    }
                    D_801CF060[i].unk78 = D_801CF060[i].unk74 = 0;
                }
                for (i = 6; i < 11; i++) {
                    D_801CF060[i].unk0 = 3;
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unk8 = 1;
                    D_801CF060[i].unkC = (COS(i * 200) * 200.0f) + 3000.0f;
                    D_801CF060[i].unk14 = (SIN(i * 300) * 300.0f) + 1100.0f;
                    D_801CF060[i].unk10 = (i - 4) * 50;
                    D_801CF060[i].unk18 = 90.0f;
                    D_801CF060[i].unk74 = 0;
                    D_801CF060[i].unk78 = SysUtils_Rand() & 0x3F;
                    D_801CF060[i].unk70 = ((SysUtils_Rand() & 0xF) * 10.0f) + 200.0f;
                }
            }
            D_800E62C8 = D_800E62CC = 12;
            break;
        case SUNSET_BAY:
            if (gPlayers == ONE_PLAYER) {
                if (D_800DAB68 == 0) {
                    for (i = 0; i < 3; i++) {
                        D_801CF060[i].unkC = -4300.0f;
                        D_801CF060[i].unk14 = -800.0f;
                        D_801CF060[i].unk8 = 1;
                        D_801CF060[i].unk0 = 6;
                        D_801CF060[i].unk4C = 40.0f;
                        // int 200 and 5000 below: a constant apart from the 200.0f / 5000.0f used elsewhere
                        D_801CF060[i].unk80 = COS(((i * 120) / 360) * 4096) * 200;
                        D_801CF060[i].unk84 = 100000.0f;
                        D_801CF060[i].unk88 = SIN(((i * 120) / 360) * 4096) * 200;
                    }
                    D_801CF060[0].unk9C = 10;
                    D_801CF060[1].unk9C = 11;
                    D_801CF060[2].unk9C = 12;
                } else {
                    D_801CF060[0].unkC = 6000.0f;
                    D_801CF060[0].unk9C = 0;
                    D_801CF060[0].unk8 = 11;
                    D_801CF060[0].unk0 = 6;
                    D_801CF060[1].unk8 = 12;
                    D_801CF060[1].unk0 = 6;
                    D_801CF060[1].unk7C = 0;
                    D_801CF060[2].unk7C = 0;
                    D_801CF060[2].unk8 = 2;
                    D_801CF060[2].unk0 = 6;
                    D_801CF060[0].unk14 = 4000.0f;
                    D_801CF060[2].unk14 = 4000.0f;
                    D_801CF060[2].unk18 = 180.0f;
                    D_801CF060[0].unk18 = 90.0f;
                    D_801CF060[0].unk4C = 25.0f;
                    D_801CF060[2].unkC = 4800.0f;
                }
            }
            D_800E62C8 = D_800E62CC = 3;
            break;
        case MARINE_FORTRESS:
            if (gPlayers == ONE_PLAYER) {
                for (i = 0, j = -4000; j != -3500; i++, j += 100) {
                    D_801CF060[i].unk0 = 4;
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unk8 = 2;
                    D_801CF060[i].unk10 = D_801CF060[i].unk84 = 80.0f;
                    D_801CF060[i].unkC = D_801CF060[i].unk80 = j;
                    D_801CF060[i].unk18 = 270.0f;
                    D_801CF060[i].unk74 = 0;
                    D_801CF060[i].unk78 = 0;
                    D_801CF060[i].unk14 = D_801CF060[i].unk88 = -2400.0f;
                    D_801CF060[i].unk70 = (s32) (2000 - (SysUtils_Rand() & 0x3FF));
                }
            }
            D_800E62C8 = D_800E62CC = 6;
            break;
        case DRAKE_LAKE:
            if (gPlayers == ONE_PLAYER) {
                for (i = 0; i < 6; i++) {
                    D_801CF060[i].unk0 = 2;
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unk8 = 2;
                    D_801CF060[i].unk80 = (s32) ((SysUtils_Rand() & 0x1FF) - 0x100);
                    D_801CF060[i].unk88 = (s32) ((SysUtils_Rand() & 0xFF) - 0x80);
                    D_801CF060[i].unk18 = 0.0f;
                    D_801CF060[i].unk74 = 0;
                    D_801CF060[i].unk78 = 0;
                    D_801CF060[i].unk70 = (s32) ((SysUtils_Rand() & 0x3FF) + 1000);
                    D_801CF060[i].unk9C = 0;
                }
                for (i = 6, j = 540; j != 900; i++, j += 90) {
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unkC = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06BC;
                    D_801CF060[i].unk14 = (s32) ((SysUtils_Rand() & 0x3FF) - 0x200) + D_801D06C4;
                    t = SysUtils_Rand() & 0x3F;
                    D_801CF060[i].unk8 = 5;
                    D_801CF060[i].unk80 = 100000.0f;
                    D_801CF060[i].unk84 = 100000.0f;
                    D_801CF060[i].unk88 = 100000.0f;
                    D_801CF060[i].unk10 = -50.0f - t;
                    D_801CF060[i].unk8C = j;
                    D_801CF060[i].unk0 = 10;
                    D_801CF060[i].unk78 = D_801CF060[i].unk74 = 0;
                }
            }
            D_800E62C8 = D_800E62CC = 11;
            break;
        case PORT_BLUE:
            if (gPlayers == ONE_PLAYER) {
                func_800C1B64();
                D_801CF060[0].unk0 = 12;
                D_801CF060[0].unk7C = 0xFF;
                D_801CF060[0].unk8 = 1;
                D_801CF060[0].unk10 = 50.0f;
                D_801CF060[0].unkC = -2000.0f;
                D_801CF060[0].unk14 = -5000.0f;
                D_801CF060[0].unk18 = 135.0f;
                D_801CF060[0].unk24 = D_801CF060[0].unk28 = D_801CF060[0].unk2C = 0.0f;
                D_801CF060[0].unk9C = 0;
                D_801CF060[0].unk74 = 0;
                D_801CF060[0].unk78 = 0;
                D_801CF060[0].unk50 = 10;
                D_801CF060[0].unk54 = 0;
                D_801CF060[0].unk4C = 10.0f;
            }
            D_800E62C8 = D_800E62CC = 2;
            break;
        case TWILIGHT_CITY:
            D_800E62C8 = D_800E62CC = 0;
            break;
        case GLACIER_COAST:
            if (gPlayers == ONE_PLAYER) {
                if (gGameModes == GMODE_CHAMPIONSHIP) {
                    D_801CF060[0].unk0 = 5;
                    D_801CF060[0].unk7C = 0xFF;
                    D_801CF060[0].unk8 = 1;
                    D_801CF060[0].unk9C = 6;
                    D_801CF060[0].unkC = -3200.0f;
                    D_801CF060[0].unk10 = -500.0f;
                    D_801CF060[0].unk14 = 4600.0f;
                    D_801CF060[0].unk18 = 180.0f;
                    D_801CF060[0].unk4C = 50.0f;
                    if (D_801CB340 >= 35) {
                        D_801CF060[1].unk0 = 5;
                        D_801CF060[1].unk7C = 0;
                        D_801CF060[1].unk8 = 1;
                        D_801CF060[1].unkC = -3200.0f;
                        D_801CF060[1].unk10 = -500.0f;
                        D_801CF060[1].unk14 = 4600.0f;
                        D_801CF060[1].unk18 = 180.0f;
                        D_801CF060[1].unk4C = 50.0f;
                    }
                    if (D_801CB340 >= 45) {
                        D_801CF060[2].unk0 = 5;
                        D_801CF060[2].unk7C = 0;
                        D_801CF060[2].unk8 = 1;
                        D_801CF060[2].unkC = -3200.0f;
                        D_801CF060[2].unk10 = -500.0f;
                        D_801CF060[2].unk14 = 4600.0f;
                        D_801CF060[2].unk18 = 180.0f;
                        D_801CF060[2].unk4C = 50.0f;
                    }
                }
                for (i = 3; i < 8; i++) {
                    D_801CF060[i].unk0 = 3;
                    D_801CF060[i].unk7C = 0xFF;
                    D_801CF060[i].unk8 = 1;
                    D_801CF060[i].unkC = (COS(i * 200) * 200.0f) + 5000;
                    D_801CF060[i].unk14 = (SIN(i * 300) * 300.0f) + -2600.0f;
                    D_801CF060[i].unk10 = (i * 10) + 240;
                    D_801CF060[i].unk18 = 90.0f;
                    D_801CF060[i].unk74 = 0;
                    D_801CF060[i].unk78 = SysUtils_Rand() & 0x3F;
                    D_801CF060[i].unk70 = ((SysUtils_Rand() & 0xF) * 10.0f) + 200.0f;
                }
            }
            D_800E62C8 = D_800E62CC = 9;
            break;
        case SOUTHERN_ISLAND:
            if (gPlayers == ONE_PLAYER) {
                D_801CF060[0].unk0 = D_801CF060[1].unk0 = D_801CF060[2].unk0 = D_801CF060[3].unk0 = D_801CF060[4].unk0 =
                    13;
                D_801CF060[0].unk7C = D_801CF060[1].unk7C = D_801CF060[2].unk7C = D_801CF060[3].unk7C =
                    D_801CF060[4].unk7C = 0xFF;
                D_801CF060[0].unk8 = D_801CF060[1].unk8 = D_801CF060[2].unk8 = D_801CF060[3].unk8 = D_801CF060[4].unk8 =
                    2;
                D_801CF060[0].unk18 = D_801CF060[1].unk18 = D_801CF060[2].unk18 = D_801CF060[3].unk18 =
                    D_801CF060[4].unk18 = 45.0f;
                D_801CF060[0].unkC = 2260.0f;
                D_801CF060[0].unk10 = D_801CF060[0].unk84 = 94.0f;
                D_801CF060[0].unk14 = -2630.0f;
                D_801CF060[1].unkC = 2140.0f;
                D_801CF060[1].unk10 = D_801CF060[1].unk84 = 94.0f;
                D_801CF060[1].unk14 = -2500.0f;
                D_801CF060[2].unkC = 1900.0f;
                D_801CF060[2].unk10 = D_801CF060[2].unk84 = 100.0f;
                D_801CF060[2].unk14 = -2330.0f;
                D_801CF060[3].unkC = 1670.0f;
                D_801CF060[3].unk10 = D_801CF060[3].unk84 = 80.0f;
                D_801CF060[3].unk14 = -2100.0f;
                D_801CF060[4].unkC = 1550.0f;
                D_801CF060[4].unk10 = D_801CF060[4].unk84 = 70.0f;
                D_801CF060[4].unk14 = -1900.0f;
                if ((gGameModes == GMODE_CHAMPIONSHIP) && (D_800DAB68 == 0) && (D_801CB340 >= 40)) {
                    D_801CF060[5].unk0 = 13;
                    D_801CF060[5].unk7C = 0xFF;
                    D_801CF060[5].unk8 = 1;
                    D_801CF060[5].unk74 = 1;
                    D_801CF060[5].unk18 = 180.0f;
                    D_801CF060[5].unkC = -2571.0f;
                    D_801CF060[5].unk10 = D_801CF060[5].unk84 = D_801D06C0 - 500.0f;
                    D_801CF060[5].unk4C = 30.0f;
                    D_801CF060[5].unk50 = 18;
                    D_801CF060[5].unk14 = 5120.0f;
                    D_801CF060[5].unk20 = 90.0f;
                }
            }
            D_800E62C8 = D_800E62CC = 6;
            break;
    }
}

void func_800AD3C4(void) {
    switch (gCourseID) {
        case DRAKE_LAKE:
            func_800C1DEC();
            break;
        case PORT_BLUE:
            func_800C1B98();
            break;
        default:
            break;
    }
}

void func_800AD418(void) {
    UnkStruct_80192690* rider;
    UnkStruct_80192690* rider2;
    s32 i;
    GfxPool* pool;

    rider = &D_80192690[gPlayer1Rider];
    // An empty loop, as in the original.
    for (i = 0; i < 30; i += 2) {}
    if (gPlayers == TWO_PLAYERS) {
        rider2 = &D_80192690[gPlayer2Rider];
    } else {
        rider2 = &D_80192690[gPlayer1Rider];
    }
    pool = gGfxPool;
    D_800E62C4++;
    D_801D0778 = pool->unk13D68[D_80192460[0]].v.ob[0];
    D_801D0780 = pool->unk13D68[D_80192460[0]].v.ob[2];
    D_801D06BC = rider->unk44.x;
    D_801D06C0 = rider->unk44.y;
    D_801D06C4 = rider->unk44.z;
    D_801D0754 = func_8009D4A8(rider->unk5C, D_801D06C4 - D_801D06EC);
    if (D_801D0754 < 0.01) {
        D_801D0754 = 0.01f;
    }
    D_801D06C8 = rider->unk5C / D_801D0754;
    D_801D06CC = rider->unk60;
    D_801D06D0 = rider->unk64 / D_801D0754;
    D_801D06D8 = D_801D06BC - D_801D06E4;
    D_801D06DC = D_801D06C0 - D_801D06E8;
    D_801D06E0 = D_801D06C4 - D_801D06EC;
    D_801D06E4 = D_801D06BC;
    D_801D06E8 = D_801D06C0;
    D_801D06EC = D_801D06C4;
    D_801D06D4 = func_8009D4A8(D_801D06D8, D_801D06E0);
    if (D_801D0724 < D_801D06D4) {
        D_801D0724 = D_801D06D4;
    }
    if (D_801D0724 > 70.0f) {
        D_801D0724 = 70.0f;
    }
    D_801D0730 = gRiderRaceState[gPlayer1Rider].unkC;
    D_801D0738 = gRiderRaceState[gPlayer1Rider].unk0;
    D_801D0734 = gRiderRaceState[gPlayer1Rider].unk4;
    D_801D073C = gRiderRaceState[gPlayer1Rider].unk2F4;
    if (gPlayers == TWO_PLAYERS) {
        D_801D0784 = pool->unk13D68[D_80192460[1]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[1]].v.ob[2];
    } else {
        D_801D0784 = pool->unk13D68[D_80192460[0]].v.ob[0];
        D_801D078C = pool->unk13D68[D_80192460[0]].v.ob[2];
    }
    D_801D06F0 = rider2->unk44.x;
    D_801D06F4 = rider2->unk44.y;
    D_801D06F8 = rider2->unk44.z;
    D_801D06FC = rider2->unk5C;
    D_801D0700 = rider2->unk60;
    D_801D0704 = rider2->unk64;
    D_801D070C = D_801D06F0 - D_801D0718;
    D_801D0710 = D_801D06F4 - D_801D071C;
    D_801D0714 = D_801D06F8 - D_801D0720;
    D_801D0718 = D_801D06F0;
    D_801D071C = D_801D06F4;
    D_801D0720 = D_801D06F8;
    D_801D0708 = func_8009D4A8(D_801D06D8, D_801D06E0);
    if (D_801D0728 < D_801D0708) {
        D_801D0728 = D_801D0708;
    }
    if (D_801D0728 > 70.0f) {
        D_801D0728 = 70.0f;
    }
    if (gPlayers == TWO_PLAYERS) {
        D_801D0744 = gRiderRaceState[gPlayer2Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer2Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer2Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer2Rider].unk2F4;
    } else {
        D_801D0744 = gRiderRaceState[gPlayer1Rider].unkC;
        D_801D074C = gRiderRaceState[gPlayer1Rider].unk0;
        D_801D0748 = gRiderRaceState[gPlayer1Rider].unk4;
        D_801D0750 = gRiderRaceState[gPlayer1Rider].unk2F4;
    }
    switch (gCourseID) {
        case DOLPHIN_PARK:
            func_800C1268(&D_801D0668);
            for (i = 0; i < 30; i++) {
                switch (D_801CF060[i].unk0) {
                    case 6:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800A68A4(i);
                        }
                        break;
                    case 7:
                    case 8:
                    case 9:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800A5D70(i);
                        }
                        break;
                }
            }
            break;
        case SUNNY_BEACH:
            func_800BF8C8();
            for (i = 0; i < 30; i++) {
                switch (D_801CF060[i].unk0) {
                    case 3:
                    case 4:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800A9494(i);
                        }
                        break;
                    case 7:
                    case 8:
                    case 9:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800A5D70(i);
                        }
                        break;
                }
            }
            break;
        case GLACIER_COAST:
            for (i = 0; i < 30; i++) {
                switch (D_801CF060[i].unk0) {
                    case 3:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800A9494(i);
                        }
                        break;
                    case 5:
                        if (D_801CF060[i].unkB8 == 0) {
                            func_800AB25C(i);
                        }
                        break;
                }
            }
            break;
        case SUNSET_BAY:
            for (i = 0; i < 30; i++) {
                if ((D_801CF060[i].unk0 == 6) && (D_801CF060[i].unkB8 == 0)) {
                    func_800A9130(i);
                }
            }
            break;
        case MARINE_FORTRESS:
            func_800BF8C8();
            for (i = 0; i < 30; i++) {
                if (((D_801CF060[i].unk0 == 3) || (D_801CF060[i].unk0 == 4)) && (D_801CF060[i].unkB8 == 0)) {
                    func_800A9D48(i);
                }
            }
            break;
        case DRAKE_LAKE:
            if (gCurrentPauseMenuOption == -1) {
                func_800A5C74();
                for (i = 0; i < 30; i++) {
                    if (D_801CF060[i].unk0 == 10) {
                        func_800A5D70(i);
                    }
                    if (((D_801CF060[i].unk0 == 1) || (D_801CF060[i].unk0 == 2)) && (D_801CF060[i].unkB8 == 0)) {
                        func_800AAAC8(i);
                    }
                }
            }
            break;
        case PORT_BLUE:
            for (i = 0; i < 30; i++) {
                if ((D_801CF060[i].unk0 == 12) && (D_801CF060[i].unkB8 == 0)) {
                    func_800A93C8(i);
                }
            }
            break;
        case SOUTHERN_ISLAND:
            for (i = 0; i < 30; i++) {
                if ((D_801CF060[i].unk0 == 13) && (D_801CF060[i].unkB8 == 0)) {
                    func_800AB890(i);
                }
            }
            break;
    }
}

s32 func_800ADC8C(s32 arg0) {
    s32 ret;

    ret = D_801D06B8;
    switch (arg0) {
        case 1:
            ret += 8;
            break;
        case 2:
            ret++;
            break;
        case 3:
            ret += 8;
            break;
        case 4:
            ret++;
            break;
        case 5:
            ret += 6;
            break;
        case 6:
            ret += 6;
            break;
        case 7:
            ret += 4;
            break;
        case 8:
            ret += 4;
            break;
        case 9:
            ret += 4;
            break;
        case 10:
            ret += 4;
            break;
        case 12:
            ret += 1;
    }
    return ret;
}

// TO CHECK
void func_800ADD14(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if ((D_801CF060[i].unkB8 == 0) && (D_801CF060[i].unk0 != 0)) {
            if (D_801CF060[i].unkC > 8000) {
                D_801CF060[i].unkC = 8000.0f;
            }
            if (D_801CF060[i].unkC < -8000.0f) {
                D_801CF060[i].unkC = -8000.0f;
            }
            if (D_801CF060[i].unk14 > 8000) {
                D_801CF060[i].unk14 = 8000.0f;
            }
            if (D_801CF060[i].unk14 < -8000.0f) {
                D_801CF060[i].unk14 = -8000.0f;
            }
            if (D_801CF060[i].unk10 > 4000) {
                D_801CF060[i].unk14 = 4000.0f;
            }
            if (D_801CF060[i].unk10 < -4000.0f) {
                D_801CF060[i].unk14 = -4000.0f;
            }
        }
    }
}

s32 func_800ADE14(s32 arg0) {
    camera_unk_1* temp_v0;
    f32 angle;

    if (D_801CF060[arg0].unkB8 != 0) {
        return 1;
    }
    if (D_801CF060[arg0].unk0 != 0) {
        temp_v0 = &gCameraPerspective[D_80223930];
        D_801D0754 = func_8009D564(-func_8009D3AC(temp_v0->unkF0, temp_v0->unkF4));

        D_801D0758 = func_8009D564(
            func_8009D3AC(D_801CF060[arg0].unkC - temp_v0->eyeX, -(D_801CF060[arg0].unk14 - temp_v0->eyeZ)));

        if (D_801CF060[arg0].unk0 == 6) {
            return 1;
        }

        angle = FABS(Math_Normalize_Angle(D_801D0758 - D_801D0754));

        if (angle < 100.0f) {
            return 1;
        }
    }
    return 0;
}

extern s32 D_800E62C0;
extern s32 D_801D06B8;

Gfx* func_800ADF90(Gfx* arg0) {
    Gfx* var_v0;
    s32 var_s1;

    if (D_800E62C0 == 1) {
        D_800E62C0 = 0;
    } else {
        D_800E62C0 = 1;
    }
    arg0 = func_800916B4(arg0);
    func_800ADD14();
    D_801D06B8 = 0;

    for (var_s1 = 0; var_s1 < 30; var_s1++) {
        if ((func_800ADC8C(D_801CF060[var_s1].unk0 + D_801CF060[var_s1].unk4)) > 0xBF) {
            break;
        }

        if (func_800ADE14(var_s1) == 1) {
            switch (D_801CF060[var_s1].unk0 + D_801CF060[var_s1].unk4) {
                case 1:
                    var_v0 = func_8009DC10(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 2:
                    var_v0 = func_8009DB90(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 3:
                    var_v0 = func_8009E814(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 4:
                    var_v0 = func_8009E794(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 5:
                    var_v0 = func_8009F398(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 6:
                    var_v0 = func_8009FCB0(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 7:
                    var_v0 = func_800A10E4(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 8:
                    var_v0 = func_800A16F0(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 9:
                    var_v0 = func_800A1CFC(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 10:
                    var_v0 = func_800A2308(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 12:
                    var_v0 = func_800A28F4(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 13:
                    var_v0 = func_800A063C(arg0, var_s1);
                    arg0 = var_v0;
                    break;
            }
        }
    }
    D_800E62CC = D_800E62C8;

    for (var_s1 = D_800E62C8; var_s1 < 30; var_s1++) {
        D_801CF060[var_s1].unk0 = 0;
    }

    return arg0;
}
