#ifndef STRUCTS_H
#define STRUCTS_H

// TODO: Some lazy names here

struct Mtx {
    s16 intarr[4][4];
    u16 fracarr[4][4];
};

typedef union {
    struct Mtx m;
    struct {
        s32 xx, yx, zx, wx, xy, yy, zy, wy, xz, yz, zz, wz, xw, yw, zw, ww;
    };
} MF;

typedef struct {
    f32 unk_x;
    f32 unk_y;
    f32 unk_z;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} f_struct; // Float Struct

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} struct_80098548;

typedef struct {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    char pad[0x3];
    s8 unk13;
} chr_struct;

// Size: 0x10 bytes
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} struct_801C1F84;

typedef struct UnkStruct_801AEE20_s {
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ f32 unk48;
    /* 0x04C */ f32 unk4C;
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07C */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09C */ s32 unk9C; /* inferred */
    /* 0x0A0 */ s32 unkA0; /* maybe part of unk9C[0xB]? */
    /* 0x0A4 */ s32 unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ s32 unkB0;
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ s32 unkB8;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ s32 unkC4;
    /* 0x0C8 */ s32 unkC8;        /* inferred */
    /* 0x0CC */ s32 unkCC[4];
    /* 0x0DC */ char padDC[0x8];
    /* 0x0E4 */ f32 unkE4;
    /* 0x0E8 */ f32 unkE8;
    /* 0x0EC */ f32 unkEC;
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ s32 unkF4[4];
} UnkStruct_801AEE20;             /* size = 0x104 */

typedef struct {
    u8 pad00[0x19B];
    s32 raceTime;
    u8 pad1AC[0x124];
    s32 timeLeft;
    u8 pad2C8[0x24];
    s32 finishState;
    u8 pad2F0[0x3C];
    f32 progress;
} struct_800762D0;

struct unk_80097E68 {
    s16 unk0;
    struct unk_80097E68* unk4;
};

typedef struct UnkStruct_801D7B70 {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    s32 unk20;
} UnkStruct_801D7B70;

typedef struct Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3f; // size = 0xC

typedef struct Vec3s {
    /* 0x0 */ s16 x;
    /* 0x4 */ s16 y;
    /* 0x8 */ s16 z;
} Vec3s; // size = 0x8

struct UnkStruct_800E6DD0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

typedef struct Unkstruct_8007B1AC_arg0 {
    s32 unk0;
    char pad[0x3];
    u8 unk7;
    char pad8[0x3];
    u8 unkB;
    u8 unkC;
} Unkstruct_8007B1AC_arg0;

typedef struct Unkstruct_8007B1AC_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
} Unkstruct_8007B1AC_arg1;

struct UnkStruct_801C3C54 {
    f32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[4];
    f32 unk14;
    f32 unk18;
    char pad1C[4];
    f32 unk20;
    char pad24[0x4C];
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    char pad88[0x10];
    s32 unk98;
    char pad9C[0x20];
    s32 unkBC;
    s32 unkC0[3];
    s32 unkCC[0xA];
    s32 unkF4[0x4];
};
typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 currentRider;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ s32 pad50;
    /* 0x54 */ s32 pad54;
    /* 0x58 */ s32 pad58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ s32 unk78;
    /* 0x7C */ char pad7C[0x4];
    /* 0x80 */ s32 unk80[3];
    /* 0x8C */ s32 unk8C;
    /* 0x90 */ s32 unk90;
    /* 0x94 */ s32 unk94;
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
    /* 0xAC */ s32 unkAC;
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ s32 unkB4; /* inferred */
    /* 0xB8 */ f32 unkB8; /* inferred */
    /* 0xBC */ f32 unkBC; /* inferred */
    /* 0xC0 */ f32 unkC0; /* inferred */
    /* 0xC4 */ f32 unkC4; /* inferred */
    /* 0xC8 */ f32 unkC8; /* inferred */
    /* 0xCC */ f32 unkCC; /* inferred */
    /* 0xD0 */ f32 unkD0; /* inferred */
    /* 0xD4 */ f32 unkD4; /* inferred */
    /* 0xD8 */ s32 unkD8;
    /* 0xDC */ s32 unkDC[1];
} struct_801C3C58; /* size = 0xE0 */

struct UnkStruct_801C3C60 {
    /* 0x00 */ struct_801C3C58 unk0; /* inferred */
    /* 0xE0 */ char padE0[8];
};

struct UnkStruct_80088B00 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

struct UnkStruct_801C3C50 {
    /* 0x0000 */ char pad0[0x44];
    /* 0x0044 */ f32 unk44;
    /* 0x0048 */ f32 unk48;
    /* 0x004C */ f32 unk4C;
    /* 0x0050 */ char pad50[0xC]; /* maybe part of unk4C[4]? */
    /* 0x005C */ f32 unk5C;
    /* 0x0060 */ f32 unk60;
    /* 0x0064 */ f32 unk64;
    /* 0x0068 */ char pad68[4];
    /* 0x006C */ f32 unk6C;
    /* 0x0070 */ f32 unk70;
    /* 0x0074 */ f32 unk74;
    /* 0x0078 */ char pad78[4];
    /* 0x007C */ f32 unk7C;
    /* 0x0080 */ char pad80[4];
    /* 0x0084 */ f32 unk84;
    /* 0x0088 */ char pad88[4];
    /* 0x008C */ f32 unk8C;
    /* 0x0090 */ char pad90[0xAC0]; /* maybe part of unk8C[0x2B1]? */
    /* 0x0B50 */ u16 unkB50;
    /* 0x0B52 */ s8 unkB52;
    /* 0x0B53 */ u8 unkB53;
    /* 0x0B54 */ char padB54[0x10];
    /* 0x0B64 */ s32 unkB64;
    /* 0x0B68 */ s32 unkB68;
    /* 0x0B6C */ char padB6C[0x24];
    /* 0x0B90 */ f32 unkB90;
    /* 0x0B94 */ char padB94[0xB0]; /* maybe part of unkB90[0x2D]? */
    /* 0x0C44 */ f32 unkC44;
    /* 0x0C48 */ char padC48[4];
    /* 0x0C4C */ f32 unkC4C;
    /* 0x0C50 */ char padC50[4];
    /* 0x0C54 */ s32 unkC54;
    /* 0x0C58 */ s32 unkC58;
    /* 0x0C5C */ s32 unkC5C;
    /* 0x0C60 */ char padC60[0x1C]; /* maybe part of unkC5C[8]? */
    /* 0x0C7C */ u16 unkC7C[1];
    /* 0x0C7E */ char padC7E[0x8FA]; /* maybe part of unkC7C[0x47E]? */
    /* 0x1578 */ f32 riderSpeedMultiplier;
    /* 0x157C */ char pad157C[0x38]; /* maybe part of riderSpeedMultiplier[0xF]? */
    /* 0x15B4 */ f32 unk15B4;
    /* 0x15B8 */ f32 unk15B8;
    /* 0x15BC */ f32 unk15BC;
    /* 0x15C0 */ char pad15C0[0x1C]; /* maybe part of unk15BC[8]? */
    /* 0x15DC */ s16 unk15DC;
    /* 0x15DE */ s16 unk15DE;
    /* 0x15E0 */ char pad15E0[0xE4]; /* maybe part of unk15DE[0x73]? */
    /* 0x16C4 */ s32 unk16C4;        /* inferred */
    /* 0x16C8 */ char pad16C8[0xC];  /* maybe part of unk16C4[4]? */
    /* 0x16D4 */ s32 unk16D4;
    /* 0x16D8 */ char pad16D8[0x1C]; /* maybe part of unk16D4[8]? */
    /* 0x16F4 */ s16 unk16F4;
    /* 0x16F6 */ char pad16F6[2];
}; /* size = 0x16F8 */

typedef struct RiderStruct {
    /* 0x000 */ s32 lapCount;
    /* 0x004 */ s32 racePosition;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ char pad14[0x8];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;                          /* inferred */
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C[64]; /* one per table B record */
    /* 0x12C */ s32 power;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ s32 unk13C;
    /* 0x140 */ s32 lapBuoyMisses[9];
    /* 0x164 */ s32 unk164;
    /* 0x168 */ s32 lapTime;
    /* 0x16C */ s32 unk16C;
    /* 0x170 */ s32 bestLapTime;
    /* 0x174 */ s32 unk174;
    /* 0x178 */ s32 lapTimes[9]; /* lap split times */
    /* 0x19C */ s32 raceTime;
    /* 0x1A0 */ char pad1A0[0x4];
    /* 0x1A4 */ s32 checkpointTimes[9][8]; /* checkpoint times, per lap */
    /* 0x2C4 */ s32 timeLeft;
    /* 0x2C8 */ s32 unk2C8;
    /* 0x2CC */ s32 unk2CC;
    /* 0x2D0 */ s32 unk2D0;
    /* 0x2D4 */ s32 unk2D4;
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ s32 unk2DC;
    /* 0x2E0 */ s32 unk2E0;
    /* 0x2E4 */ s32 unk2E4;
    /* 0x2E8 */ s32 unk2E8;
    /* 0x2EC */ s32 finishState;
    /* 0x2F0 */ s32 unk2F0;
    /* 0x2F4 */ s32 unk2F4;
    /* 0x2F8 */ s32 checkpointGap;
    /* 0x2FC */ s32 gapRequest;
    /* 0x300 */ s32 gapTimer;
    /* 0x304 */ s32 unk304;
    /* 0x308 */ s32 unk308;
    /* 0x30C */ s32 unk30C;
    /* 0x310 */ s32 nearestRecord;
    /* 0x314 */ s32 unk314;
    /* 0x318 */ s32 unk318;
    /* 0x31C */ s32 inBox;
    /* 0x320 */ s32 unk320;                         /* inferred */
    /* 0x324 */ s32 unk324;
    /* 0x328 */ s32 unk328;
    /* 0x32C */ f32 progress;
    /* 0x330 */ f32 unk330;        /* inferred */
    /* 0x334 */ s32 unk334;
    s32 unk338;
    /* 0x33C */ s32 unk33C;
    char pad340[0x10];
    /* 0x350 */ struct UnkStruct_801C3C54* unk350;
    /* 0x354 */ char pad354[0x24]; /* maybe part of unk350[0xA]? */
} RiderStruct;              /* size = 0x378 */

typedef struct Controller {
    /* 0x00*/ u16 unk0;
    /* 0x02 */ u8 pad[0x1A];
} Controller;

typedef struct UnkStruct_D_802C6E80 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_D_802C6E80; // size = 0x10

typedef struct UnkStruct_8009A04C {
    /* 0x00 */ f32 unk_0;
    /* 0x04 */ f32 unk4;                            /* inferred */
    /* 0x08 */ f32 unk8;                            /* inferred */
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ char pad1D[3];                       /* maybe part of unk1C[4]? */
    /* 0x20 */ Vec3f unk20;
    /* 0x2C */ Vec3f unk2C;
    /* 0x38 */ Vec3f unk38;
    /* 0x44 */ Vec3f unk44;
    /* 0x50 */ Vec3f unk50;
    /* 0x5C */ Vec3f unk5C;
    /* 0x68 */ Vec3f unk68;
    /* 0x74 */ char pad74[0x1C];                    /* maybe part of unk68[3]? */
    /* 0x90 */ f32 unk90;
    /* 0x94 */ s8 unk94;
    /* 0x95 */ char pad95[3];                       /* maybe part of unk94[4]? */
} UnkStruct_8009A04C;                               /* size = 0x98 */

typedef struct {
    char pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    char pad58[0x18];
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    char pad88[0x60];
    s32 unkE8;
} UnkStruct_func_8009CCE8;

typedef struct UnkStruct_802C96A8 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ char pad_4[0x20];
} UnkStruct_802C96A8; // size = 0x24;

typedef struct GfxPool_s {
    /* 0x00000 */ Gfx dList[0xC00];
    /* 0x06000 */ char pad6000[0x8008];
    /* 0x0E008 */ Mtx unkE008[2];
    /* 0x0E088 */ Mtx unkE088[1]; // part of unkE008?
    /* 0x0E0C8 */ char padE0C8[0x40];
    /* 0x0E108 */ Mtx unkE108[4];
    /* 0x0E208 */ Mtx unkE208[4];         
    /* 0x0E308 */ Mtx unkE308[4];         
    /* 0x0E408 */ Mtx unkE408[4];         
    /* 0x0E508 */ Mtx unkE508[4];         
    /* 0x0E608 */ Mtx unkE608[4];         
    /* 0x0E708 */ Mtx unkE708[4];         
    /* 0x0E808 */ Mtx unkE808[4];         
    /* 0x0E908 */ Mtx unkE908[4];         
    /* 0x0EA08 */ Mtx unkEA08[4];         
    /* 0x0EB08 */ Mtx unkEB08[4];         
    /* 0x0EC08 */ Mtx unkEC08[4];         
    /* 0x0ED08 */ Mtx unkED08[4];         
    /* 0x0EE08 */ Mtx unkEE08[4];         
    /* 0x0EF08 */ Mtx unkEF08[4];         
    /* 0x0F008 */ Mtx unkF008[4];         
    /* 0x0F108 */ Mtx unkF108[4];         
    /* 0x0F208 */ Mtx unkF208[4];         
    /* 0x0F308 */ Mtx unkF308[4];
    /* 0x0F408 */ Mtx unkF408[4];
    /* 0x0F508 */ Mtx unkF508[4];
    /* 0x0F608 */ Mtx unkF608[4];
    /* 0x0F708 */ Mtx unkF708[4];
    /* 0x0F808 */ Mtx unkF808[4];
    /* 0x0F908 */ char padF908[0x500];
    /* 0x0FE08 */ Vtx unkFE08[0x3F6];
    /* 0x13D68 */ Vtx unk13D68[0x337]; /* water vertices, view 0 (filled by func_80050204) */
    /* 0x170D8 */ Vtx unk170D8[0x1F1]; /* water vertices, view 1 */
} GfxPool; /* size = 0x18FE8 */


typedef struct UnkStruct_801CEFF8 {
    /* 0x00 */ Vec3f vec1;
    /* 0x0C */ Vec3f vec2;
} UnkStruct_801CEFF8;

typedef struct RGB {
    /* 0x0 */ u16 r;
    /* 0x2 */ u16 g;
    /* 0x4 */ u16 b;
} RGB; // size = 0x6
typedef struct UnkStruct_8007B2BC {
    char unk0;
    char unk1;
    char unk2;
} UnkStruct_8007B2BC;
typedef struct UnkStruct_func_8007AF78_1 {
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
    u8 unk10;
} UnkStruct_func_8007AF78_1;

typedef struct UnkStruct_func_8007AF78_2 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    s32 unkC;
} UnkStruct_func_8007AF78_2;

typedef struct StructVarS0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    s32 unk50;
    s32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    char padB0[8];
    s32 unkB8;
} StructVarS0;

typedef struct UnkStruct_801CF060 {
    /* 0x000 */ Vec3f unk0;
    /* 0x00C */ Vec3f unkC;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ Vec3f unk20;
    /* 0x02C */ Vec3f unk2C;
    /* 0x038 */ Vec3f unk38;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    char padding[0x4];
    /* 0x064 */ f32 unk64; /* inferred */
    /* 0x068 */ f32 unk68; /* inferred */
    /* 0x06C */ f32 unk6C; /* inferred */
    /* 0x070 */ f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    /* 0x090 */ s32 pad90;
    /* 0x094 */ u8 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09C */ f32 unk9C;
    /* 0x0A0 */ f32 unkA0;
    char padding1[0x18];

} UnkStruct_801CF060;

typedef struct Struct801926D8 {
    s32 unk0;
    char pad[0x1714];
} Struct801926D8;
typedef struct StructAB90 {
    s32 unk0;              // +0x00
    s32 unk4;              // +0x04
    s32 unk8;              // +0x08
    u8 pad0C[0x68 - 0x0C]; // Padding up to offset 0x68
    s32 unk68;             // +0x68 (optional, in case needed)
    u8 pad6C[0x74 - 0x6C]; // Padding to 0x74
    s32 unk74;             // +0x74
    s32 unk78;             // +0x78
} StructAB90;

typedef struct UnkStruct_func_8007AE8C {
    s8 unk0;
    s8 unk1;
    s8 unk2;
} UnkStruct_func_8007AE8C;
typedef struct StructADA8 {
    u8 pad0[4]; // padding to offset 0x4
    f32 unk4;   // accessed at arg0->unk4
} StructADA8;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} StructCEFF8; // size = 0x18

typedef struct StructCEC70 {
    f32 unk0;
    f32 unk4[20];
} StructCEC70;

typedef struct ControllerBase {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ u16 unk_4;
    /* 0x6 */ u16 unk_6;
    /* 0x8 */ s8 unk_8;
    /* 0x9 */ s8 unk_9;
} ControllerBase; // size 0xA

typedef struct UnkStruct_func_i8_802C6E00 {
    /* 0x0 */ s8 unk_0[0xB];
    /* 0xB */ s8 unk_B[0x3];
} UnkStruct_func_i8_802C6E00;

typedef struct UnkStruct_8004B0F8_1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    s32 unk1C;
} UnkStruct_8004B0F8_1;
typedef struct UnkStruct_8004B0F8_unk34 {
    /* 0x0 */ struct UnkStruct_8004B0F8_1* unk0; // guess
    /* 0x4 */ struct UnkStruct_8004B0F8_1* unk4; // guess
    /* 0x8 */ f32 unk8;
} UnkStruct_8004B0F8_unk34;
struct UnkStruct_8004B0F8 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ f32 unk4;       /* inferred */
    /* 0x08 */ f32 unk8;       /* inferred */
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ UnkStruct_8004B0F8_1* unk30;
    /* 0x34 */ UnkStruct_8004B0F8_unk34* unk34;
    /* 0x38 */ f32* unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
};


typedef struct UnkStruct_801BC940_unk60_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
} UnkStruct_801BC940_unk60; /* size = 0x40 */

typedef struct UnkStruct_801BC940 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;                           /* inferred */
    /* 0x60 */ UnkStruct_801BC940_unk60* unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ MtxF unk74;
    /* 0xB4 */ Gfx* unkB4;
    /* 0xB8 */ Gfx* unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ s32 unkC0;
} UnkStruct_801BC940;                               /* size = 0xC4 */

// Used in code_68A10
typedef struct UnkStruct_801D7AF0 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} UnkStruct_801D7AF0;

typedef struct UnkStruct_801D7A18 {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ f32 unk8;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ f32 unk14; /* inferred */
} UnkStruct_801D7A18;

typedef struct unkStruct_func_800C1268 {
    /* 0x0 */ f32 unk_0;
    /* 0x4 */ s8 unk_4;
    /* 0x5 */ s8 unk_5;
    /* 0x6 */ u8 unk_6;
    /* 0x7 */ u8 pan;
    /* 0x8 */ s8 unk_8;
} unkStruct_func_800C1268;

typedef struct SEGA {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 pad4;
    u8 unk5;
} func_8007AFF4_arg0;

typedef struct SEGA2 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    u8 pad11;
    u8 pad12;
    s8 unk13;
} func_8007AFF4_arg1;

typedef struct UnkStruct_8007CB68_2_s {
    u16 unk0;
    u16 unk2;
    u8 unk4[8];
    u8 unkC;
    u8 unkD[3];
    u8 unk10[4][10];
    s8 unk38[2][4][3];
    u8 unk50[3][3];
    u8 unk59[7];
    u8 unk60[8][4][6];
    u8 unk120[9][3][5];
    u8 unk1A7;
    u8 unk1A8[8][2][3];
    u8 unk1D8[8][5];
} UnkStruct_8007CB68_2;

typedef struct UnkStruct_80052C6C_2_s {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk14;
} UnkStruct_80052C6C_2; /* size = 0x24 */

// Pointers into the rider's parts at 0x660 (RiderPart, defined in code_C6C0.c).
typedef struct UnkStruct_80192690_A48 {
    /* 0x00 */ struct RiderPart* unk0;
    /* 0x04 */ struct RiderPart* unk4;
    /* 0x08 */ char pad8[4];
    /* 0x0C */ struct RiderPart* unkC;
    /* 0x10 */ struct RiderPart* unk10;
    /* 0x14 */ char pad14[4];
} UnkStruct_80192690_A48; /* size = 0x18 */

union float_halfword {
    f32 f;
    u16 h;
};

// This is probably a part of UnkStruct_801C3C50
typedef struct UnkStruct_80192690 {
    /* 0x0000 */ union float_halfword unk0;
    /* 0x0004 */ f32 unk4;
    /* 0x0008 */ f32 unk8;
    /* 0x000C */ f32 unkC;
    /* 0x0010 */ f32 unk10;
    /* 0x0014 */ f32 unk14;
    /* 0x0018 */ f32 unk18;
    /* 0x001C */ f32 unk1C;
    /* 0x0020 */ f32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ s32 unk2C;
    /* 0x0030 */ UnkStruct_8004B0F8_1* unk30;
    /* 0x0034 */ UnkStruct_8004B0F8_unk34* unk34;
    /* 0x0038 */ f32* unk38;
    /* 0x003C */ char pad3C[8];
    /* 0x0044 */ Vec3f unk44;
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ f32 unk54;
    /* 0x0058 */ f32 unk58;
    /* 0x005C */ f32 unk5C;
    /* 0x0060 */ f32 unk60;
    /* 0x0064 */ f32 unk64;
    /* 0x0068 */ f32 unk68;
    /* 0x006C */ f32 unk6C;
    /* 0x0070 */ f32 unk70;
    /* 0x0074 */ f32 unk74;
    /* 0x0078 */ f32 unk78;
    /* 0x007C */ f32 unk7C;
    /* 0x0080 */ f32 unk80;
    /* 0x0084 */ f32 unk84;
    /* 0x0088 */ f32 unk88;
    /* 0x008C */ f32 unk8C;
    /* 0x0090 */ UnkStruct_8004B0F8_1 unk90[0xD];
    /* 0x0230 */ char pad230[0x2F8];                /* maybe part of unk90[3]? */
    /* 0x0528 */ f32 unk528[0x42];
    /* 0x0630 */ f32 unk630[12];
    /* 0x0660 */ char unk660[0x10];
    /* 0x0670 */ Vec3f unk670;                      /* inferred */
    /* 0x067C */ char pad67C[0x1C];                 /* maybe part of unk670[3]? */
    /* 0x0698 */ f32 unk698[3];                        /* inferred */
    /* 0x06A4 */ char pad6A4[0x1C];                 /* maybe part of unk6A0[8]? */
    /* 0x06C0 */ f32 unk6C0[3];                        /* inferred */
    /* 0x06CC */ char pad6CC[0x1C];                 /* maybe part of unk6C8[8]? */
    /* 0x06E8 */ f32 unk6E8;                        /* inferred */
    /* 0x06EC */ f32 unk6EC;                        /* inferred */
    /* 0x06F0 */ f32 unk6F0;                        /* inferred */
    /* 0x06F4 */ char pad6F4[0x1C];                 /* maybe part of unk6F0[8]? */
    /* 0x0710 */ f32 unk710;                        /* inferred */
    /* 0x0714 */ f32 unk714;                        /* inferred */
    /* 0x0718 */ f32 unk718;                        /* inferred */
    /* 0x071C */ char pad71C[0x1C];                 /* maybe part of unk718[8]? */
    /* 0x0738 */ f32 unk738;                        /* inferred */
    /* 0x073C */ f32 unk73C;                        /* inferred */
    /* 0x0740 */ f32 unk740;                        /* inferred */
    /* 0x0744 */ char pad744[0x1C];                 /* maybe part of unk740[8]? */
    /* 0x0760 */ f32 unk760;                        /* inferred */
    /* 0x0764 */ f32 unk764;                        /* inferred */
    /* 0x0768 */ f32 unk768;                        /* inferred */
    /* 0x076C */ char pad76C[0x1C];                 /* maybe part of unk768[8]? */
    /* 0x0788 */ f32 unk788;                        /* inferred */
    /* 0x078C */ f32 unk78C;                        /* inferred */
    /* 0x0790 */ f32 unk790;                        /* inferred */
    /* 0x0794 */ char pad794[0x1C];                 /* maybe part of unk790[8]? */
    /* 0x07B0 */ f32 unk7B0;                        /* inferred */
    /* 0x07B4 */ f32 unk7B4;                        /* inferred */
    /* 0x07B8 */ f32 unk7B8;                        /* inferred */
    /* 0x07BC */ char pad7BC[0x1C];                 /* maybe part of unk7B8[8]? */
    /* 0x07D8 */ f32 unk7D8;                        /* inferred */
    /* 0x07DC */ f32 unk7DC;                        /* inferred */
    /* 0x07E0 */ f32 unk7E0;                        /* inferred */
    /* 0x07E4 */ char pad7E4[0x1C];                 /* maybe part of unk7E0[8]? */
    /* 0x0800 */ f32 unk800;                        /* inferred */
    /* 0x0804 */ f32 unk804;                        /* inferred */
    /* 0x0808 */ f32 unk808;                        /* inferred */
    /* 0x080C */ char pad80C[0x1C];                 /* maybe part of unk808[8]? */
    /* 0x0828 */ f32 unk828;                        /* inferred */
    /* 0x082C */ f32 unk82C;                        /* inferred */
    /* 0x0830 */ f32 unk830;                        /* inferred */
    /* 0x0834 */ char pad834[0x1C];                 /* maybe part of unk830[8]? */
    /* 0x0850 */ f32 unk850;                        /* inferred */
    /* 0x0854 */ f32 unk854;                        /* inferred */
    /* 0x0858 */ f32 unk858;                        /* inferred */
    /* 0x085C */ char pad85C[0x1C];                 /* maybe part of unk858[8]? */
    /* 0x0878 */ f32 unk878;                        /* inferred */
    /* 0x087C */ f32 unk87C;                        /* inferred */
    /* 0x0880 */ f32 unk880;                        /* inferred */
    /* 0x0884 */ char pad884[0x1C];                 /* maybe part of unk880[8]? */
    /* 0x08A0 */ f32 unk8A0;                        /* inferred */
    /* 0x08A4 */ f32 unk8A4;                        /* inferred */
    /* 0x08A8 */ f32 unk8A8;                        /* inferred */
    /* 0x08AC */ char pad8AC[0x1C];                 /* maybe part of unk8A8[8]? */
    /* 0x08C8 */ f32 unk8C8;                        /* inferred */
    /* 0x08CC */ f32 unk8CC;                        /* inferred */
    /* 0x08D0 */ f32 unk8D0;                        /* inferred */
    /* 0x08D4 */ char pad8D4[0x1C];                 /* maybe part of unk8D0[8]? */
    /* 0x08F0 */ f32 unk8F0;                        /* inferred */
    /* 0x08F4 */ f32 unk8F4;                        /* inferred */
    /* 0x08F8 */ f32 unk8F8;                        /* inferred */
    /* 0x08FC */ char pad8FC[0x1C];                 /* maybe part of unk8F8[8]? */
    /* 0x0918 */ f32 unk918;                        /* inferred */
    /* 0x091C */ f32 unk91C;                        /* inferred */
    /* 0x0920 */ f32 unk920;                        /* inferred */
    /* 0x0924 */ char pad924[0xC];                  /* maybe part of unk920[4]? */
    /* 0x0930 */ u8 unk930[0x10];
    /* 0x0940 */ f32 unk940;                        /* inferred */
    /* 0x0944 */ f32 unk944;                        /* inferred */
    /* 0x0948 */ f32 unk948;                        /* inferred */
    /* 0x094C */ char pad94C[0xFC];                 /* maybe part of unk948[0x83]? */
    /* 0x0A48 */ UnkStruct_80192690_A48 unkA48[11];
    /* 0x0B50 */ OSContPad unkB50;
    /* 0x0B56 */ u16 unkB56;
    /* 0x0B58 */ u16 unkB58;
    /* 0x0B5A */ u16 unkB5A;
    /* 0x0B5C */ u16 unkB5C;
    /* 0x0B5E */ s8 unkB5E;
    /* 0x0B5F */ s8 unkB5F;
    /* 0x0B60 */ s32 unkB60;
    /* 0x0B64 */ s32 unkB64;
    /* 0x0B68 */ s32 unkB68;
    /* 0x0B6C */ s32 unkB6C;
    /* 0x0B70 */ s32 unkB70;
    /* 0x0B74 */ s32 unkB74;
    /* 0x0B78 */ f32 unkB78;
    /* 0x0B7C */ f32 unkB7C;
    /* 0x0B80 */ f32 unkB80;
    /* 0x0B84 */ f32 unkB84;
    /* 0x0B88 */ f32 unkB88;
    /* 0x0B8C */ f32 unkB8C;
    /* 0x0B90 */ f32 unkB90;
    /* 0x0B94 */ f32 unkB94;
    /* 0x0B98 */ f32 unkB98;
    /* 0x0B9C */ f32 unkB9C;
    /* 0x0BA0 */ f32 unkBA0;
    /* 0x0BA4 */ f32 unkBA4;
    /* 0x0BA8 */ f32 unkBA8;
    /* 0x0BAC */ f32 unkBAC;
    /* 0x0BB0 */ f32 unkBB0;
    /* 0x0BB4 */ f32 unkBB4;
    /* 0x0BB8 */ f32 unkBB8;
    /* 0x0BBC */ f32 unkBBC;
    /* 0x0BC0 */ f32 unkBC0;
    /* 0x0BC4 */ f32 unkBC4;
    /* 0x0BC8 */ f32 unkBC8;
    /* 0x0BCC */ f32 unkBCC;
    /* 0x0BD0 */ f32 unkBD0;
    /* 0x0BD4 */ f32 unkBD4;
    /* 0x0BD8 */ f32 unkBD8;
    /* 0x0BDC */ f32 unkBDC;
    /* 0x0BE0 */ f32 unkBE0;
    /* 0x0BE4 */ f32 unkBE4;
    /* 0x0BE8 */ f32 unkBE8;
    /* 0x0BEC */ f32 unkBEC;
    /* 0x0BF0 */ f32 unkBF0;
    /* 0x0BF4 */ f32 unkBF4;
    /* 0x0BF8 */ f32 unkBF8;
    /* 0x0BFC */ f32 unkBFC;
    /* 0x0C00 */ f32 unkC00;
    /* 0x0C04 */ f32 unkC04;
    /* 0x0C08 */ f32 unkC08;
    /* 0x0C0C */ f32 unkC0C;
    /* 0x0C10 */ f32 unkC10;
    /* 0x0C14 */ f32 unkC14;
    /* 0x0C18 */ f32 unkC18;
    /* 0x0C1C */ f32 unkC1C;
    /* 0x0C20 */ f32 unkC20;
    /* 0x0C24 */ f32 unkC24;
    /* 0x0C28 */ f32 unkC28;
    /* 0x0C2C */ f32 unkC2C;
    /* 0x0C30 */ f32 unkC30;
    /* 0x0C34 */ f32 unkC34;
    /* 0x0C38 */ f32 unkC38;
    /* 0x0C3C */ f32 unkC3C;
    /* 0x0C40 */ f32 unkC40;
    /* 0x0C44 */ f32 unkC44;
    /* 0x0C48 */ f32 unkC48;
    /* 0x0C4C */ f32 unkC4C;
    /* 0x0C50 */ f32 unkC50;
    /* 0x0C54 */ s32 unkC54;
    /* 0x0C58 */ s32 unkC58;
    /* 0x0C5C */ s32 unkC5C;
    /* 0x0C60 */ s32 unkC60;
    /* 0x0C64 */ u16 unkC64;
    /* 0x0C66 */ u16 unkC66;
    /* 0x0C68 */ s32 unkC68;
    /* 0x0C6C */ s32 unkC6C;
    /* 0x0C70 */ s32 unkC70;
    /* 0x0C74 */ s32 unkC74;
    /* 0x0C78 */ s32 unkC78;
    /* 0x0C7C */ u16 unkC7C;
    /* 0x0C7E */ u16 unkC7E;
    /* 0x0C80 */ u16 unkC80;
    /* 0x0C82 */ u16 unkC82;
    /* 0x0C84 */ u16 unkC84;
    /* 0x0C86 */ u16 unkC86;
    /* 0x0C88 */ Vec3f unkC88;
    /* 0x0C94 */ char padC94[0xC];
    /* 0x0CA0 */ f32 unkCA0;                        /* inferred */
    /* 0x0CA4 */ f32 unkCA4;                        /* inferred */
    /* 0x0CA8 */ f32 unkCA8;                        /* inferred */
    /* 0x0CAC */ char padCAC[0x18];                 /* maybe part of unkCA8[7]? */
    /* 0x0CC4 */ f32 unkCC4;                        /* inferred */
    /* 0x0CC8 */ f32 unkCC8;                        /* inferred */
    /* 0x0CCC */ f32 unkCCC;                        /* inferred */
    /* 0x0CD0 */ char padCD0[0x18];                 /* maybe part of unkCCC[7]? */
    /* 0x0CE8 */ f32 unkCE8;                        /* inferred */
    /* 0x0CEC */ f32 unkCEC;                        /* inferred */
    /* 0x0CF0 */ f32 unkCF0;                        /* inferred */
    /* 0x0CF4 */ char padCF4[0x18];                 /* maybe part of unkCF0[7]? */
    /* 0x0D0C */ f32 unkD0C;                        /* inferred */
    /* 0x0D10 */ f32 unkD10;                        /* inferred */
    /* 0x0D14 */ f32 unkD14;                        /* inferred */
    /* 0x0D18 */ char padD18[0x18];                 /* maybe part of unkD14[7]? */
    /* 0x0D30 */ f32 unkD30;                        /* inferred */
    /* 0x0D34 */ f32 unkD34;                        /* inferred */
    /* 0x0D38 */ f32 unkD38;                        /* inferred */
    /* 0x0D3C */ char padD3C[0x18];                 /* maybe part of unkD38[7]? */
    /* 0x0D54 */ f32 unkD54;                        /* inferred */
    /* 0x0D58 */ f32 unkD58;                        /* inferred */
    /* 0x0D5C */ f32 unkD5C;                        /* inferred */
    /* 0x0D60 */ char padD60[0x18];                 /* maybe part of unkD5C[7]? */
    /* 0x0D78 */ f32 unkD78;                        /* inferred */
    /* 0x0D7C */ f32 unkD7C;                        /* inferred */
    /* 0x0D80 */ f32 unkD80;                        /* inferred */
    /* 0x0D84 */ char padD84[0x18];                 /* maybe part of unkD80[7]? */
    /* 0x0D9C */ f32 unkD9C;                        /* inferred */
    /* 0x0DA0 */ f32 unkDA0;                        /* inferred */
    /* 0x0DA4 */ f32 unkDA4;                        /* inferred */
    /* 0x0DA8 */ char padDA8[0x18];                 /* maybe part of unkDA4[7]? */
    /* 0x0DC0 */ f32 unkDC0;                        /* inferred */
    /* 0x0DC4 */ f32 unkDC4;                        /* inferred */
    /* 0x0DC8 */ f32 unkDC8;                        /* inferred */
    /* 0x0DCC */ char padDCC[0x18];                 /* maybe part of unkDC8[7]? */
    /* 0x0DE4 */ f32 unkDE4;                        /* inferred */
    /* 0x0DE8 */ f32 unkDE8;                        /* inferred */
    /* 0x0DEC */ f32 unkDEC;                        /* inferred */
    /* 0x0DF0 */ char padDF0[0x18];                 /* maybe part of unkDEC[7]? */
    /* 0x0E08 */ f32 unkE08;                        /* inferred */
    /* 0x0E0C */ f32 unkE0C;                        /* inferred */
    /* 0x0E10 */ f32 unkE10;                        /* inferred */
    /* 0x0E14 */ char padE14[0x18];                 /* maybe part of unkE10[7]? */
    /* 0x0E2C */ f32 unkE2C;                        /* inferred */
    /* 0x0E30 */ f32 unkE30;                        /* inferred */
    /* 0x0E34 */ f32 unkE34;                        /* inferred */
    /* 0x0E38 */ char padE38[0x18];                 /* maybe part of unkE34[7]? */
    /* 0x0E50 */ f32 unkE50;                        /* inferred */
    /* 0x0E54 */ f32 unkE54;                        /* inferred */
    /* 0x0E58 */ f32 unkE58;                        /* inferred */
    /* 0x0E5C */ char padE5C[0x18];                 /* maybe part of unkE58[7]? */
    /* 0x0E74 */ f32 unkE74;                        /* inferred */
    /* 0x0E78 */ f32 unkE78;                        /* inferred */
    /* 0x0E7C */ f32 unkE7C;                        /* inferred */
    /* 0x0E80 */ char padE80[0x18];                 /* maybe part of unkE7C[7]? */
    /* 0x0E98 */ f32 unkE98;                        /* inferred */
    /* 0x0E9C */ f32 unkE9C;                        /* inferred */
    /* 0x0EA0 */ f32 unkEA0;                        /* inferred */
    /* 0x0EA4 */ char padEA4[0x57C];                /* maybe part of unkEA0[0x163]? */
    /* 0x1420 */ s32 unk1420;
    /* 0x1424 */ s32 unk1424;
    /* 0x1428 */ s32 unk1428;
    /* 0x142C */ f32 unk142C;
    /* 0x1430 */ f32 unk1430;
    /* 0x1434 */ f32 unk1434;
    /* 0x1438 */ f32 unk1438;
    /* 0x143C */ f32 unk143C;
    /* 0x1440 */ f32 unk1440;
    /* 0x1444 */ s16 unk1444;
    /* 0x1446 */ s16 unk1446;
    /* 0x1448 */ UnkStruct_80052C6C_2 unk1448[6];
    /* 0x1520 */ Vec3f unk1520[6];
    /* 0x1568 */ f32 unk1568;
    /* 0x156C */ f32 unk156C;
    /* 0x1570 */ f32 unk1570;
    /* 0x1574 */ s32 unk1574;
    /* 0x1578 */ f32 unk1578;
    /* 0x157C */ s32 unk157C;
    /* 0x1580 */ f32 unk1580;
    /* 0x1584 */ f32 unk1584;
    /* 0x1588 */ f32 unk1588;
    /* 0x158C */ f32 unk158C;
    /* 0x1590 */ f32 unk1590;
    /* 0x1594 */ f32 unk1594;
    /* 0x1598 */ s32 unk1598;
    /* 0x159C */ s32 unk159C;
    /* 0x15A0 */ s32 unk15A0;
    /* 0x15A4 */ s32 unk15A4;
    /* 0x15A8 */ s32 unk15A8;
    /* 0x15AC */ f32 unk15AC;
    /* 0x15B0 */ s32 unk15B0;
    /* 0x15B4 */ f32 unk15B4;
    /* 0x15B8 */ f32 unk15B8;
    /* 0x15BC */ f32 unk15BC;
    /* 0x15C0 */ s32 unk15C0;
    /* 0x15C4 */ f32 unk15C4;
    /* 0x15C8 */ s32 unk15C8;
    /* 0x15CC */ f32 unk15CC;
    /* 0x15D0 */ f32 unk15D0;
    /* 0x15D4 */ f32 unk15D4;
    /* 0x15D8 */ f32 unk15D8;
    /* 0x15DC */ s16 unk15DC;
    /* 0x15DE */ s16 unk15DE;
    /* 0x15E0 */ f32 unk15E0;
    /* 0x15E4 */ f32 unk15E4;
    /* 0x15E8 */ f32 unk15E8;
    /* 0x15EC */ f32 unk15EC;
    /* 0x15F0 */ s32 unk15F0;
    /* 0x15F4 */ u16 unk15F4;
    /* 0x15F6 */ u16 unk15F6;
    /* 0x15F8 */ u16 unk15F8;
    /* 0x15FA */ u16 unk15FA;
    /* 0x15FC */ u16 unk15FC;
    /* 0x15FE */ u16 unk15FE;
    /* 0x1600 */ s16 unk1600;
    /* 0x1602 */ s16 unk1602;
    /* 0x1604 */ s16 unk1604;
    /* 0x1606 */ s16 unk1606;
    /* 0x1608 */ u16 unk1608;
    /* 0x160A */ s16 unk160A;
    /* 0x160C */ f32 unk160C;
    /* 0x1610 */ f32 unk1610;
    /* 0x1614 */ f32 unk1614;
    /* 0x1618 */ f32 unk1618;
    /* 0x161C */ f32 unk161C;
    /* 0x1620 */ f32 unk1620;
    /* 0x1624 */ char pad1624[0x30];                /* maybe part of unk1620[0xD]? */
    /* 0x1654 */ f32 unk1654;
    /* 0x1658 */ f32 unk1658;
    /* 0x165C */ f32 unk165C;
    /* 0x1660 */ char pad1660[0x3C];                /* maybe part of unk165C[0x11]? */
    /* 0x169C */ f32 unk169C;
    /* 0x16A0 */ f32 unk16A0;
    /* 0x16A4 */ f32 unk16A4;
    /* 0x16A8 */ f32 unk16A8;
    /* 0x16AC */ f32 unk16AC;
    /* 0x16B0 */ f32 unk16B0;
    /* 0x16B4 */ s32 unk16B4;
    /* 0x16B8 */ f32 unk16B8;
    /* 0x16BC */ f32 unk16BC;
    /* 0x16C0 */ f32 unk16C0;
    /* 0x16C4 */ s32 unk16C4;
    /* 0x16C8 */ s32 unk16C8;
    /* 0x16CC */ u16 unk16CC;
    /* 0x16CE */ u16 unk16CE;
    /* 0x16D0 */ s32 unk16D0;
    /* 0x16D4 */ s32 unk16D4;
    /* 0x16D8 */ s32 unk16D8;
    /* 0x16DC */ s32 unk16DC;
    /* 0x16E0 */ u16 unk16E0;
    /* 0x16E2 */ s16 unk16E2;
    /* 0x16E4 */ s32 unk16E4;
    /* 0x16E8 */ s32 unk16E8;
    /* 0x16EC */ s32 unk16EC;
    /* 0x16F0 */ s16 unk16F0;
    /* 0x16F2 */ s16 unk16F2;
    /* 0x16F4 */ s16 unk16F4;
    /* 0x16F6 */ char pad16F6[0x22];
} UnkStruct_80192690;                               /* size = 0x1718 */

typedef struct UnkStruct_801AE948_s {
    char pad[0x35D0];
    Lights0 unk35D8[1];
    char pad35E8[0xA18];
    /* 0x4000 */ Mtx unk4000;
    /* 0x4040 */ Mtx unk4040;
    /* 0x4080 */ Mtx unk4080;
    /* 0x40C0 */ Mtx unk40C0;
    Mtx unk4100[1];
    Mtx unk4140[1];
    /* 0x4180 */ char pad4180[0x1040];
    /* 0x51C0 */ Vtx unk51C0[4][0xC0];
    /* 0x81C0 */ Vtx unk81C0[0xC0];
    /* 0x8DC0 */ Vtx unk8DC0[4][16];
    /* 0x91C0 */ Vtx unk91C0[4][16];
    /* 0x95C0 */ Mtx unk95C0[2][12]; /* table B buoys, per view */
    /* 0x9BC0 */ Mtx unk9BC0[2][12]; /* their arrows */
    /* 0xA1C0 */ Mtx unkA1C0[2][32]; /* table A buoys, per view */
    /* 0xB1C0 */ Vtx unkB1C0[4];
    /* 0xB200 */ Vtx unkB200[4];
    /* 0xB240 */ Vtx unkB240[4];
    /* 0xB280 */ Vtx unkB280[4];
    LookAt unkB2C0[1];
    Hilite unkB2E0[1];
} UnkStruct_801AE948;

typedef struct UnkStruct_80069740_s {
    s32 pad[0x10];
} UnkStruct_80069740;
typedef struct Game_801CE608 {
    /* 0x0 */ s32 gameMode;
    /* 0x4 */ s16 player;
    /* 0x6 */ s16 rider;
    /* 0x8 */ s32 waveLevel;
    /* 0xC */ s32 powerMisses;
    /* 0x10 */ s32 lapCount; // Race lap count
    /* 0x14 */ s32 unk_14;
} Game_801CE608;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkStruct_800D96A4;

typedef struct {
    s16 unk0;
    s16 unk2;
} UnkStruct_800DB568;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_800DA9B0;


typedef struct {
    /* 0x00 */ ControllerBase unk_00;
    /* 0x0A */ ControllerBase unk_0A;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkStruct_801CE658; // size = 0x1C


typedef struct UnkStruct_menu_buffer_1_s {
    /* 0x00 */ u16 type;                            /* 0 free, 1 and 2 cards, 3 spinning cursor, 4 eight-strip card */
    /* 0x02 */ u16 state;                           /* 0 sliding in, 1 settled (2 for type 4) */
    /* 0x04 */ s16 index;                           /* own slot number; picks the card's matrix */
    /* 0x06 */ u16 active;                          /* set by Popup_UpdateAll each frame; func_801E5554 draws only these */
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ char pad10[4];
    /* 0x14 */ f32 unk14;                           /* inferred */
    /* 0x18 */ s32 frame;                           /* animation counter (the cursor's wraps at 40) */
    /* 0x1C */ s32 unk1C;                           /* inferred */
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 menuY;                           /* the pause cursor's y for option 0 (+15 per option) */
    /* 0x28 */ s32 variant;                         /* type 2: 0 place card, else wide card; type 4: 176 wide */
} UnkStruct_menu_buffer_1;                          /* size = 0x2C */

typedef struct UnkStruct_80198368_s {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ char pad4[0x513C];
    /* 0x5140 */ Vtx unk5140[2][4];
    /* 0x51C0 */ Vtx unk51C0[4][0xC0];
    /* 0x81C0 */ Vtx unk81C0[0xC0];
    /* 0x8DC0 */ Vtx unk8DC0[4][16];                         /* inferred */
    /* 0x91C0 */ Vtx unk91C0[4][16];                         /* inferred */
    /* 0x95C0 */ char pad95C0[0x1C00];
    /* 0xB1C0 */ Vtx unkB1C0[4];
    /* 0xB200 */ Vtx unkB200[4];
    /* 0xB240 */ Vtx unkB240[4];
    /* 0xB280 */ Vtx unkB280[4];
    /* 0xB2C0 */ char padB2C0[0x30];
} UnkStruct_80198368;                               /* size = 0xB2F0 */

typedef struct UnkStruct_801C43F8_s {
    Vtx unk0[7];
    Vtx unk70[7];
    Vtx unkE0[7];
    Vtx unk150[7];
    Vtx unk1C0[7];
    char pad230[0xE0];
    Vtx unk310[4];
    Vtx unk350[10][4];
    Mtx unk5D0[1];
    char pad610[0x2fc0];
    Lights0 unk35D8[2]; /* the field is at 0x35D0 (Lights0 is 0x18) */
    Lights0 unk3608[2]; /* the field is at 0x3600; named, like unk35D8, by the offset of its l[0] (field + 8) */
} UnkStruct_801C43F8;

typedef struct UnkStruct_801CE5F8_s {
    char pad[0x40];
    Vtx unk40[120]; /* the text printer's quad vertices (Printer_DrawQuad), from gPrinterNextQuadVtx (clamped to 0x74 + 4) */
    char pad7C0[0x280];
    Mtx unkA40[1];
    Mtx unkA80[1];
    char padAC0[0x1C0];
    Mtx unkC80[9]; /* three per rider model on the records screen */
    char padEC0[0x380];
    char pad2[0x40];
    Vp unk1280[3];
    char pad12B0[0x50];
    Mtx unk1300[1];
    Mtx unk1340[1];
    Mtx unk1380[16];
    Mtx unk1780[1];
} UnkStruct_801CE5F8;

typedef struct UnkStruct_801CE780_unk4_unk4_s {
    /* 0x0 */ s16 unk0;         /* inferred */
    /* 0x2 */ s16 unk2;         /* inferred */
    /* 0x4 */ s16 unk4;         /* inferred */
    /* 0x6 */ s8 unk6;          /* inferred */
    /* 0x7 */ s8 unk7;          /* inferred */
    /* 0x8 */ s8 unk8;          /* inferred */
    /* 0x9 */ s8 unk9;          /* inferred */
    /* 0xA */ s8 unkA;          /* inferred */
    /* 0xB */ s8 unkB;          /* inferred */
} UnkStruct_801CE780_unk4_unk4; /* size = 0xC */
typedef struct UnkStruct_801CE780_unk4_s {
    /* 0x00 */ s16 unk0; /* inferred */
    /* 0x02 */ char pad2[2];
    /* 0x04 */ UnkStruct_801CE780_unk4_unk4* unk4; /* inferred */
    /* 0x08 */ s16* unk8;                          /* inferred */
    /* 0x0C */ s16* unkC;                          /* inferred */
    /* 0x10 */ s16* unk10;                         /* inferred */
    /* 0x14 */ s16* unk14;                         /* inferred */
    /* 0x18 */ s16* unk18;                         /* inferred */
    /* 0x1C */ s16* unk1C;                         /* inferred */
    /* 0x20 */ s16* unk20;                         /* inferred */
} UnkStruct_801CE780_unk4;                         /* size = 0x24 */

typedef struct UnkStruct_801CE780_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ UnkStruct_801CE780_unk4** unk4; /* inferred */
    /* 0x08 */ u32 unk8;                       /* inferred */
    /* 0x0C */ u32 unkC;                       /* inferred */
    /* 0x10 */ u32 unk10;                      /* inferred */
    /* 0x14 */ u32 unk14;                      /* inferred */
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
} UnkStruct_801CE780;                          /* size = 0x2C */

struct UnkStruct_801C2938 {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ char pad8[4];
    /* 0x00C */ s32 unkC;
    /* 0x010 */ char pad10[0x11C];
    /* 0x12C */ s32 power;
    /* 0x130 */ char pad130[0x6C];
    /* 0x19C */ s32 raceTime;
    /* 0x1A0 */ char pad1A0[0x124];
    /* 0x2C4 */ s32 timeLeft;
    /* 0x2C8 */ s32 unk2C8;
    /* 0x2CC */ char pad2CC[0x20];
    /* 0x2EC */ s32 finishState;
    /* 0x2F0 */ char pad2F0[4];
    /* 0x2F4 */ s32 unk2F4;
    /* 0x2F8 */ char pad2F8[0x20];
    /* 0x318 */ s32 unk318;
    /* 0x31C */ char pad31C[0x1C];
    /* 0x338 */ s32 unk338;
    /* 0x33C */ char pad33C[0x3C];
}; /* size = 0x378 */

// Seventeen display lists per entry of D_80227A60.
typedef struct UnkStruct_80227A60 {
    /* 0x00 */ Gfx* unk0[12];
    /* 0x30 */ Gfx* unk30[5];
} UnkStruct_80227A60; /* size = 0x44 */

// One view's water window (gWaterWindow[], 0x1C bytes per view): the snapped centre as integer world x and z, the
// window centre, its radius squared and the snap offsets (Water_UpdateWindow writes them).
typedef struct UnkStruct_80192420_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
} UnkStruct_80192420; /* size = 0x1C */

// A record of gCoursePoints (table A): buoys by type and difficulty, course-edge points and points with a height.
typedef struct UnkStruct_801BB138_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} UnkStruct_801BB138; /* size = 0x18 */

#endif /* STRUCTS_H */
