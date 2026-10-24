#include "global.h"
#include "camera.h"

// Degrees to a gSinTable index.
#define DEG_TO_BINANG(x) ((s32) (((x) * 4096.0f) / 360.0f))

#define LERP(startPosition, targetPosition, factor) ((targetPosition - startPosition) * factor) + startPosition

typedef struct UnkStruct_80052C6C_1_s {
    /* 0x0 */ s16 unk0; /* inferred */
    /* 0x2 */ s16 unk2; /* inferred */
    /* 0x4 */ s16 unk4; /* inferred */
    /* 0x6 */ s8 unk6;  /* inferred */
    /* 0x7 */ s8 unk7;  /* inferred */
    /* 0x8 */ s8 unk8;  /* inferred */
    /* 0x9 */ s8 unk9;  /* inferred */
    /* 0xA */ s8 unkA;  /* inferred */
    /* 0xB */ s8 unkB;  /* inferred */
} UnkStruct_80052C6C_1; /* size = 0xC */

typedef struct UnkStruct_80052C6C_2_s {
    /* 0x0 */ Vec3f unk0;
    /* 0xC */ Vec3f unkC;
    /* 0x14 */ Vec3f unk14;
} UnkStruct_80052C6C_2; /* size = 0x24 */

struct UnkStruct_80052480 {
    /* 0x00 */ s8 unk0;       /* inferred */
    /* 0x01 */ s8 unk1;       /* inferred */
    /* 0x02 */ s8 unk2;       /* inferred */
    /* 0x03 */ s8 unk3;       /* inferred */
    /* 0x04 */ s8 unk4;       /* inferred */
    /* 0x05 */ char pad5[9];  /* maybe part of unk4[0xA]? */
    /* 0x0E */ s8 unkE;       /* inferred */
    /* 0x0F */ s8 unkF;       /* inferred */
    /* 0x10 */ s8 unk10;      /* inferred */
    /* 0x11 */ s8 unk11;      /* inferred */
    /* 0x12 */ s8 unk12;      /* inferred */
    /* 0x13 */ s8 unk13;      /* inferred */
    /* 0x14 */ s8 unk14;      /* inferred */
    /* 0x15 */ s8 unk15;      /* inferred */
    /* 0x16 */ char pad16[2]; /* maybe part of unk15[3]? */
    /* 0x18 */ s8 unk18;      /* inferred */
    /* 0x19 */ s8 unk19;      /* inferred */
    /* 0x1A */ char pad1A[1];
    /* 0x1B */ s8 unk1B; /* inferred */
    s8 unk1C;
}; /* size = 0x1C */

struct UnkStruct_801C2938 {
    char pad0[4];
    s32 unk4;
    char pad8[0x124];
    s32 unk12C;
    char pad130[0x198];
    s32 unk2C8;
    char pad2CC[0x4C];
    s32 unk318;
    char pad31C[0x1C];
    s32 unk338;
    char pad33C[0x3C];
};
struct UnkStruct_801D0798 {
    char pad0[0x1C5C];
    s32 unk1C5C;
    s32 unk1C60;
    char pad1C64[0x10];
};

typedef struct UnkStruct_802238DC_s {
    /* 0x00 */ s16 unk0; /* inferred */
    /* 0x02 */ char pad2[2];
    /* 0x04 */ UnkStruct_80052C6C_1* unk4; /* inferred */
    /* 0x08 */ s16* unk8;                  /* inferred */
    /* 0x0C */ s16* unkC;                  /* inferred */
    /* 0x10 */ s16* unk10;                 /* inferred */
    /* 0x14 */ s16* unk14;                 /* inferred */
    /* 0x18 */ s16* unk18;                 /* inferred */
    /* 0x1C */ s16* unk1C;                 /* inferred */
    /* 0x20 */ s16* unk20;                 /* inferred */
    /* 0x24 */ s16* unk24;                 /* inferred */
    /* 0x28 */ s16* unk28;                 /* inferred */
    /* 0x2C */ s16* unk2C;                 /* inferred */
    /* 0x30 */ s16* unk30;                 /* inferred */
    /* 0x34 */ s16* unk34;                 /* inferred */
    /* 0x38 */ s16* unk38;                 /* inferred */
    /* 0x3C */ s16* unk3C;                 /* inferred */
    /* 0x40 */ s16* unk40;                 /* inferred */
    /* 0x44 */ s16* unk44;                 /* inferred */
    /* 0x48 */ s16* unk48;                 /* inferred */
    /* 0x4C */ s16* unk4C;                 /* inferred */
} UnkStruct_802238DC;                      /* size = 0x50 */

typedef struct UnkStruct_80052E90_arg1_s {
    /* 0x000 */ UnkStruct_80052C6C_2 unk0;   /* inferred */
    /* 0x024 */ UnkStruct_80052C6C_2 unk24;  /* inferred */
    /* 0x048 */ UnkStruct_80052C6C_2 unk48;  /* inferred */
    /* 0x06C */ UnkStruct_80052C6C_2 unk6C;  /* inferred */
    /* 0x090 */ UnkStruct_80052C6C_2 unk90;  /* inferred */
    /* 0x0B4 */ UnkStruct_80052C6C_2 unkB4;  /* inferred */
    /* 0x0D8 */ UnkStruct_80052C6C_2 unkD8;  /* inferred */
    /* 0x0FC */ UnkStruct_80052C6C_2 unkFC;  /* inferred */
    /* 0x120 */ UnkStruct_80052C6C_2 unk120; /* inferred */
    /* 0x144 */ UnkStruct_80052C6C_2 unk144; /* inferred */
    /* 0x168 */ UnkStruct_80052C6C_2 unk168; /* inferred */
    /* 0x18C */ UnkStruct_80052C6C_2 unk18C; /* inferred */
    /* 0x1B0 */ UnkStruct_80052C6C_2 unk1B0; /* inferred */
    /* 0x1D4 */ UnkStruct_80052C6C_2 unk1D4; /* inferred */
    /* 0x1F8 */ UnkStruct_80052C6C_2 unk1F8; /* inferred */
    /* 0x21C */ UnkStruct_80052C6C_2 unk21C; /* inferred */
    /* 0x240 */ UnkStruct_80052C6C_2 unk240; /* inferred */
    /* 0x264 */ UnkStruct_80052C6C_2 unk264;
} UnkStruct_80052E90_arg1_s; /* size = 0x284 */

typedef struct UnkStruct_8005CEF8_s {
    /* 0x000 */ char pad0[4];
    /* 0x004 */ f32 unk4; /* inferred */
    /* 0x008 */ f32 unk8; /* inferred */
    /* 0x00C */ f32 unkC; /* inferred */
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ char pad1C[0x10]; /* maybe part of unk18[5]? */
    /* 0x02C */ f32 unk2C;        /* inferred */
    /* 0x030 */ f32 unk30;        /* inferred */
    /* 0x034 */ f32 unk34;        /* inferred */
    /* 0x038 */ f32 unk38;
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ char pad44[0x10]; /* maybe part of unk40[5]? */
    /* 0x054 */ f32 unk54;        /* inferred */
    /* 0x058 */ f32 unk58;        /* inferred */
    /* 0x05C */ f32 unk5C;        /* inferred */
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06C */ char pad6C[0x10]; /* maybe part of unk68[5]? */
    /* 0x07C */ f32 unk7C;        /* inferred */
    /* 0x080 */ f32 unk80;        /* inferred */
    /* 0x084 */ f32 unk84;        /* inferred */
    /* 0x088 */ f32 unk88;
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ char pad94[0x10]; /* maybe part of unk90[5]? */
    /* 0x0A4 */ f32 unkA4;        /* inferred */
    /* 0x0A8 */ f32 unkA8;        /* inferred */
    /* 0x0AC */ f32 unkAC;        /* inferred */
    /* 0x0B0 */ f32 unkB0;
    /* 0x0B4 */ f32 unkB4;
    /* 0x0B8 */ f32 unkB8;
    /* 0x0BC */ char padBC[0x10]; /* maybe part of unkB8[5]? */
    /* 0x0CC */ f32 unkCC;        /* inferred */
    /* 0x0D0 */ f32 unkD0;        /* inferred */
    /* 0x0D4 */ f32 unkD4;        /* inferred */
    /* 0x0D8 */ f32 unkD8;
    /* 0x0DC */ f32 unkDC;
    /* 0x0E0 */ f32 unkE0;
    /* 0x0E4 */ char padE4[0x10]; /* maybe part of unkE0[5]? */
    /* 0x0F4 */ f32 unkF4;        /* inferred */
    /* 0x0F8 */ f32 unkF8;        /* inferred */
    /* 0x0FC */ f32 unkFC;        /* inferred */
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10C */ char pad10C[0x10]; /* maybe part of unk108[5]? */
    /* 0x11C */ f32 unk11C;        /* inferred */
    /* 0x120 */ f32 unk120;        /* inferred */
    /* 0x124 */ f32 unk124;        /* inferred */
    /* 0x128 */ f32 unk128;
    /* 0x12C */ f32 unk12C;
    /* 0x130 */ f32 unk130;
    /* 0x134 */ char pad134[0x10]; /* maybe part of unk130[5]? */
    /* 0x144 */ f32 unk144;        /* inferred */
    /* 0x148 */ f32 unk148;        /* inferred */
    /* 0x14C */ f32 unk14C;        /* inferred */
    /* 0x150 */ f32 unk150;
    /* 0x154 */ f32 unk154;
    /* 0x158 */ f32 unk158;
    /* 0x15C */ char pad15C[0x10]; /* maybe part of unk158[5]? */
    /* 0x16C */ f32 unk16C;        /* inferred */
    /* 0x170 */ f32 unk170;        /* inferred */
    /* 0x174 */ f32 unk174;        /* inferred */
    /* 0x178 */ f32 unk178;
    /* 0x17C */ f32 unk17C;
    /* 0x180 */ f32 unk180;
    /* 0x184 */ char pad184[0x10]; /* maybe part of unk180[5]? */
    /* 0x194 */ f32 unk194;        /* inferred */
    /* 0x198 */ f32 unk198;        /* inferred */
    /* 0x19C */ f32 unk19C;        /* inferred */
    /* 0x1A0 */ f32 unk1A0;
    /* 0x1A4 */ f32 unk1A4;
    /* 0x1A8 */ f32 unk1A8;
    /* 0x1AC */ char pad1AC[0x10]; /* maybe part of unk1A8[5]? */
    /* 0x1BC */ f32 unk1BC;        /* inferred */
    /* 0x1C0 */ f32 unk1C0;        /* inferred */
    /* 0x1C4 */ f32 unk1C4;        /* inferred */
    /* 0x1C8 */ f32 unk1C8;
    /* 0x1CC */ f32 unk1CC;
    /* 0x1D0 */ f32 unk1D0;
    /* 0x1D4 */ char pad1D4[0x10]; /* maybe part of unk1D0[5]? */
    /* 0x1E4 */ f32 unk1E4;        /* inferred */
    /* 0x1E8 */ f32 unk1E8;        /* inferred */
    /* 0x1EC */ f32 unk1EC;        /* inferred */
    /* 0x1F0 */ f32 unk1F0;
    /* 0x1F4 */ f32 unk1F4;
    /* 0x1F8 */ f32 unk1F8;
    /* 0x1FC */ char pad1FC[0x10]; /* maybe part of unk1F8[5]? */
    /* 0x20C */ f32 unk20C;        /* inferred */
    /* 0x210 */ f32 unk210;        /* inferred */
    /* 0x214 */ f32 unk214;        /* inferred */
    /* 0x218 */ f32 unk218;
    /* 0x21C */ f32 unk21C;
    /* 0x220 */ f32 unk220;
    /* 0x224 */ char pad224[0x10]; /* maybe part of unk220[5]? */
    /* 0x234 */ f32 unk234;        /* inferred */
    /* 0x238 */ f32 unk238;        /* inferred */
    /* 0x23C */ f32 unk23C;        /* inferred */
    /* 0x240 */ f32 unk240;
    /* 0x244 */ f32 unk244;
    /* 0x248 */ f32 unk248;
    /* 0x24C */ char pad24C[0x10]; /* maybe part of unk248[5]? */
    /* 0x25C */ f32 unk25C;        /* inferred */
    /* 0x260 */ f32 unk260;        /* inferred */
    /* 0x264 */ f32 unk264;        /* inferred */
    /* 0x268 */ f32 unk268;
    /* 0x26C */ f32 unk26C;
    /* 0x270 */ f32 unk270;
    /* 0x274 */ char pad274[0x10]; /* maybe part of unk270[5]? */
    /* 0x284 */ f32 unk284;        /* inferred */
    /* 0x288 */ f32 unk288;        /* inferred */
    /* 0x28C */ f32 unk28C;        /* inferred */
    /* 0x290 */ f32 unk290;
    /* 0x294 */ f32 unk294;
    /* 0x298 */ f32 unk298;
    /* 0x29C */ char pad29C[0x10]; /* maybe part of unk298[5]? */
    /* 0x2AC */ f32 unk2AC;        /* inferred */
    /* 0x2B0 */ f32 unk2B0;        /* inferred */
    /* 0x2B4 */ f32 unk2B4;        /* inferred */
    /* 0x2B8 */ f32 unk2B8;
    /* 0x2BC */ f32 unk2BC;
    /* 0x2C0 */ f32 unk2C0;
    /* 0x2C4 */ char pad2C4[0x10]; /* maybe part of unk2C0[5]? */
    /* 0x2D4 */ f32 unk2D4;        /* inferred */
    /* 0x2D8 */ f32 unk2D8;        /* inferred */
    /* 0x2DC */ f32 unk2DC;        /* inferred */
    /* 0x2E0 */ f32 unk2E0;
    /* 0x2E4 */ f32 unk2E4;
    /* 0x2E8 */ f32 unk2E8;
    /* 0x2EC */ char pad2EC[0x10]; /* maybe part of unk2E8[5]? */
    /* 0x2FC */ f32 unk2FC;        /* inferred */
    /* 0x300 */ f32 unk300;        /* inferred */
    /* 0x304 */ f32 unk304;        /* inferred */
    /* 0x308 */ f32 unk308;
    /* 0x30C */ f32 unk30C;
    /* 0x310 */ f32 unk310;
    /* 0x314 */ char pad314[0x10]; /* maybe part of unk310[5]? */
    /* 0x324 */ f32 unk324;        /* inferred */
    /* 0x328 */ f32 unk328;        /* inferred */
    /* 0x32C */ f32 unk32C;        /* inferred */
    /* 0x330 */ f32 unk330;
    /* 0x334 */ f32 unk334;
    /* 0x338 */ f32 unk338;
    /* 0x33C */ char pad33C[0x10]; /* maybe part of unk338[5]? */
    /* 0x34C */ f32 unk34C;        /* inferred */
    /* 0x350 */ f32 unk350;        /* inferred */
    /* 0x354 */ f32 unk354;        /* inferred */
    /* 0x358 */ f32 unk358;
    /* 0x35C */ f32 unk35C;
    /* 0x360 */ f32 unk360;
    /* 0x364 */ char pad364[0x10]; /* maybe part of unk360[5]? */
    /* 0x374 */ f32 unk374;        /* inferred */
    /* 0x378 */ f32 unk378;        /* inferred */
    /* 0x37C */ f32 unk37C;        /* inferred */
    /* 0x380 */ f32 unk380;
    /* 0x384 */ f32 unk384;
    /* 0x388 */ f32 unk388;
    /* 0x38C */ char pad38C[0x10]; /* maybe part of unk388[5]? */
    /* 0x39C */ f32 unk39C;        /* inferred */
    /* 0x3A0 */ f32 unk3A0;        /* inferred */
    /* 0x3A4 */ f32 unk3A4;        /* inferred */
    /* 0x3A8 */ f32 unk3A8;
    /* 0x3AC */ f32 unk3AC;
    /* 0x3B0 */ f32 unk3B0;
    /* 0x3B4 */ char pad3B4[0x10]; /* maybe part of unk3B0[5]? */
    /* 0x3C4 */ f32 unk3C4;        /* inferred */
    /* 0x3C8 */ f32 unk3C8;        /* inferred */
    /* 0x3CC */ f32 unk3CC;        /* inferred */
    /* 0x3D0 */ f32 unk3D0;
    /* 0x3D4 */ f32 unk3D4;
    /* 0x3D8 */ f32 unk3D8;
} UnkStruct_8005CEF8; /* size = 0x3DC */

// Entries for func_800AC098 (the same layout as A95D0.c's UnkStruct_801DB0E4_arg0).
typedef struct UnkStruct_80192540 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ f32 unk30;
} UnkStruct_80192540; /* size = 0x34 */

typedef struct UnkStruct_80227A60 {
    /* 0x00 */ Gfx* unk0[12];
    /* 0x30 */ Gfx* unk30[5];
} UnkStruct_80227A60; /* size = 0x44 */

// The rider's 19 entries of 0x28 bytes at 0x660 (unk660 .. 0x958).
typedef struct RiderPart {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Vec3f unk4;
    /* 0x10 */ Vec3f unk10;
    /* 0x1C */ char pad1C[0xC];
} RiderPart; /* size = 0x28 */

// The rider's 3 x 18 entries of 0x24 bytes at 0xC88 (unkC88 .. 0x1420).
typedef struct UnkStruct_80192690_C88 {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ char padC[0x18];
} UnkStruct_80192690_C88; /* size = 0x24 */

#define RIDER_C88(rider) ((UnkStruct_80192690_C88(*)[18]) &(rider)->unkC88)

#define RIDER_PARTS(rider) ((RiderPart*) (rider)->unk660)

// A view of the rider's button state at 0xB56 (unkB56 .. unkB5F).
typedef struct RiderButtons {
    /* 0x0 */ u16 held;
    /* 0x2 */ u16 pressed;
    /* 0x4 */ u16 released;
    /* 0x6 */ u16 prevHeld;
    /* 0x8 */ s8 stickX;
    /* 0x9 */ s8 stickY;
} RiderButtons; /* size = 0xA */

typedef struct UnkStruct_80069798_1 {
    /* 0x00 */ s32 unk0[6];
} UnkStruct_80069798_1; /* size = 0x18 */

typedef struct UnkStruct_80069798 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ Vec3f unk8;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ char pad24[4];
    /* 0x28 */ UnkStruct_80069798_1 unk28;
} UnkStruct_80069798; /* size = 0x40 */

// The rider's four collision spheres at 0x160C (unk160C .. 0x169C).
typedef struct RiderSphere {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f vel;
    /* 0x18 */ UnkStruct_8004B0F8_1* unk18;
    /* 0x1C */ UnkStruct_8004B0F8_1* unk1C;
    /* 0x20 */ UnkStruct_8004B0F8_1* unk20;
} RiderSphere; /* size = 0x24 */

#define RIDER_SPHERES(rider) ((RiderSphere*) &(rider)->unk160C)

typedef struct UnkStruct_8005A280_s {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} UnkStruct_8005A280;

extern UnkStruct_80192690 D_80192690[];
extern struct UnkStruct_801C2938 D_801C2938[];
extern struct UnkStruct_801D0798 D_801D0798[];
extern UnkStruct_802238DC* D_802238DC[];
extern s32 D_800DA930[];
extern UnkStruct_80052C6C_1 D_801CE9C4;
extern UnkStruct_80052C6C_1 D_801CE9D0;
extern UnkStruct_80052C6C_1 D_801CE9DC;
extern UnkStruct_80052C6C_1 D_801CE9E8;
extern UnkStruct_80052C6C_1 D_801CE9F4;
extern UnkStruct_80052C6C_1 D_801CEA00;
extern UnkStruct_80052C6C_1 D_801CEA0C;
extern UnkStruct_80052C6C_1 D_801CEA18;
extern UnkStruct_80052C6C_1 D_801CEA24;
extern UnkStruct_80052C6C_1 D_801CEA30;
extern UnkStruct_80052C6C_1 D_801CEA3C;
extern UnkStruct_80052C6C_1 D_801CEA48;
extern UnkStruct_80052C6C_1 D_801CEA54;
extern UnkStruct_80052C6C_1 D_801CEA60;
extern UnkStruct_80052C6C_1 D_801CEA6C;
extern f32 D_800D4958;
extern f32 D_800D495C;
extern f32 D_800D49E8;
extern f32 D_800D4A04;
extern f32 D_800D4A68[7];
extern f32 D_800D49F4;
extern f32 D_800D4A00;
extern UnkStruct_80192690 D_80193D5C[];
extern u8 D_3000000[];
extern UnkStruct_80192540 D_80192540[];
extern s32 D_800D4948;
extern s32 D_80154344;
extern Gfx D_10068B0[];
extern s32 D_800D49DC;
extern s32 gFrameCounter;
extern s32 D_800D4934;
extern s16 D_800D492C;
extern s32 D_800D4930;
extern u16* D_800D48D0[];
extern f32 D_800D93D0[];
extern f32 D_800D93E0[];
extern f32 D_800D93F0[];
extern f32 D_800D9420[];
extern f32 D_800D9430[];
extern f32 D_800D9440[];
extern f32 D_800D9450[];
extern f32 D_800D9460[];
extern f32 D_800D9470[];
extern f32 D_800D9490[];
extern f32 D_800D94A0[];
extern f32 D_800D94B0[];
extern f32 D_800D94C0[];
extern f32 D_800D94D0[];
extern f32 D_800D94E0[];
extern f32 D_800D94F0[];
extern f32 D_800D9500[];
extern f32 D_800D9510[];
extern f32 D_800D9520[];
extern f32 D_800D9530[];
extern f32 D_800D9540[];
extern f32 D_800D9550[];
extern f32 D_800D9560[];
extern f32 D_800D9570[];
extern f32 D_800D9580[];
extern f32 D_800D9590[];
extern f32 D_800D95A0[];
extern f32 D_800D95B0[];
extern f32 D_800D95C0[];
extern f32 D_800D95D0[];
extern f32 D_800D95E0[];
extern f32 D_800D95F0[];
extern f32 D_800D9600[];
extern f32 D_800D9610[];
extern f32 D_800D9620[];
extern s16 D_800DAB60;
extern s16 D_800D4928;
extern u16 D_800D4964;
extern s16 D_800D496C;
extern s16 D_800D4974;
extern s16 D_800D4978;
extern s32 D_80223934;
extern f32 D_800D4AF0;
extern f32 D_800D4AF4;
extern Gfx D_1007968[];
extern UnkStruct_80227A60 D_80227A60[];

void func_80098048(s32, s32);
f32 func_8004D30C(f32, f32);
void func_80052C6C(UnkStruct_80192690* arg0, UnkStruct_80052C6C_1* arg1, UnkStruct_80052C6C_2* arg2);
s32 func_80052E90(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3);
s32 func_80053268(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3);
Gfx* func_800687A4(Gfx* arg0);
Gfx* func_800916B4(Gfx* arg0);
void func_8005374C(UnkStruct_80052C6C_2* arg0, f32 t, UnkStruct_80052C6C_2* arg2, UnkStruct_80052C6C_2* arg3);
void func_80053A5C(UnkStruct_80052E90_arg1_s* arg0, f32 arg1, UnkStruct_80052E90_arg1_s* arg2,
                   UnkStruct_80052E90_arg1_s* arg3);
void func_80053FBC(UnkStruct_80192690* arg0, UnkStruct_80052C6C_1* arg1, UnkStruct_80052C6C_2* arg2);
s32 func_80054130(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
s32 func_80054E14(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3);
s32 func_80055270(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3);
s32 func_80055C6C(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3);
void func_800534AC(UnkStruct_80052C6C_2*, f32*, f32*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_80052BB8(UnkStruct_80052E90_arg1_s* arg0);
void func_80057B24(s32 arg0, UnkStruct_80052E90_arg1_s* arg1);
void func_8005A1B4(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3);
void func_8005CEF8(UnkStruct_80052E90_arg1_s* arg0, UnkStruct_8005CEF8* arg1);
f32 func_8007FAE4(f32, f32, f32, f32*, f32*, f32*);
f32 func_8007F448(f32, f32, f32, f32*, f32*, f32*);
void func_80061184(UnkStruct_80192690*);
void func_80080400(void);
Gfx* func_800694B8(Gfx*, s32);
Gfx* func_80067810(Gfx*, s32, s32);
void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8006AC84(s32, void*);
void func_8006390C(s32, void*);
void func_80067C6C(void);
void func_8006243C(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_801EE91C(MtxF_t arg0, f32 x, f32 y, f32 z);
void func_800AC098(UnkStruct_80192540*, s32);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80051EC0.s")

void func_80052480(s32 arg0, struct UnkStruct_80052480* arg1) {
    char pad[0x4];
    f32 ft2;
    f32 ft5;
    f32 sp28;
    s32 var_v0;

    arg1->unk0 = (s8) (s32) (D_80192690[arg0].unkB90 * 1.4399999f);
    arg1->unk1 = (s8) (s32) ((f32) D_801C2938[arg0].unk2C8 * 0.44444445f);
    var_v0 = (s32) (D_80192690[arg0].unkBFC * 5.0f);
    if (var_v0 < -0xF) {
        var_v0 = -0xF;
    } else if (var_v0 >= 0x10) {
        var_v0 = 0xF;
    }
    arg1->unk2 = (s8) var_v0;
    if (D_80192690[arg0].unkC7E != 0) {
        var_v0 = (D_80192690[arg0].unkC78 * 0xA) + (s32) (D_80192690[arg0].unkB7C * -3.0f);
        if (var_v0 < 0) {
            var_v0 = 1;
        } else if (var_v0 >= 0x80) {
            var_v0 = 0x7F;
        }
    } else {
        var_v0 = D_80192690[arg0].unkC7C;
    }
    arg1->unk3 = var_v0;
    if (D_80192690[arg0].unkB56 & 0xA000) {
        arg1->unk4 = 1;
    } else {
        arg1->unk4 = 0;
    }
    if ((D_80192690[arg0].unkC54 == 7) && (D_80192690[arg0].unkC58 == 0x3A)) {
        arg1->unk1C = 1;
    }

    ft2 = (D_80192690[arg0].unk90[2].unk0 + D_80192690[arg0].unk90[0].unk0) * 0.5f;
    sp28 = ((D_80192690[arg0].unk90[2].unk4 + D_80192690[arg0].unk90[0].unk4) * 0.5f);
    var_v0 =
        (func_8004D30C(ft2, (D_80192690[arg0].unk90[2].unk8 + D_80192690[arg0].unk90[0].unk8) * 0.5f) - sp28 - 7.0f) *
        20;

    if (var_v0 < 0) {
        var_v0 = 0;
    } else if (var_v0 >= 0x80) {
        var_v0 = 0x7F;
    }
    arg1->unkF = var_v0;
    if ((D_80192690[arg0].unkC84 == 0) && (D_80192690[arg0].unkC86 == 1)) {
        arg1->unk18 = 1;
    } else {
        arg1->unk18 = 0;
    }
    arg1->unkE = (s8) D_801C2938[arg0].unk12C;
    if (D_80192690[arg0].unkC40 != 0.0f) {
        arg1->unk12 = 0x14;
        var_v0 = (s32) (D_80192690[arg0].unkC40 * 19050.0f);
    } else if (D_80192690[arg0].unkC38 != 0.0f) {
        arg1->unk12 = 0x18;
        var_v0 = (s32) (D_80192690[arg0].unkC38 * 6350.0f);
    } else if (D_80192690[arg0].unkC50 != 0.0f) {
        if (D_80192690[arg0].unk16D8 == 1) {
            arg1->unk12 = 0x3C;
        } else if (D_80192690[arg0].unk16D8 == 2) {
            arg1->unk12 = 2;
        } else {
            arg1->unk12 = 0x1C;
        }
        var_v0 = (s32) (D_80192690[arg0].unkC50 * 6350.0f);
    } else if (D_80192690[arg0].unkC44 != 0.0f) {
        arg1->unk12 = 0x1C;
        var_v0 = (s32) (D_80192690[arg0].unkC44 * 234.0f);
    } else if (D_80192690[arg0].unkC4C != 0.0f) {
        arg1->unk12 = 0x41;
        var_v0 = (s32) (D_80192690[arg0].unkC4C * 234.0f);
    } else if (D_80192690[arg0].unkC48 != 0.0f) {
        if (D_80192690[arg0].unk15DE != 0) {
            arg1->unk12 = 0x40;
            var_v0 = (s32) (D_80192690[arg0].unkC48 * 468.0f);
        } else {
            arg1->unk12 = 0x10;
            var_v0 = (s32) (D_80192690[arg0].unkC48 * 234.0f);
        }
    } else if (D_80192690[arg0].unkC3C != 0.0f) {
        arg1->unk12 = 0x10;
        var_v0 = (s32) (D_80192690[arg0].unkC3C * 6350.0f);
    } else {
        if (D_801C2938[arg0].unk318 != 0) {
            arg1->unk12 = 0x28;
            var_v0 = (s32) ((D_80192690[arg0].unkB90 * 127.0f) / 55.555557f);
        } else {
            var_v0 = 0;
        }
    }
    if (var_v0 >= 0x80) {
        var_v0 = 0x7F;
    }
    arg1->unk13 = (s8) var_v0;
    arg1->unk14 = 1;

    if (D_801D0798[arg0].unk1C60 < D_801D0798[arg0].unk1C5C) {
        arg1->unk11 = (s8) D_801D0798[arg0].unk1C5C;
    } else {
        arg1->unk11 = (s8) D_801D0798[arg0].unk1C60;
    }
    arg1->unk10 = 1;
    arg1->unk19 = (s8) D_801C2938[arg0].unk4;
    arg1->unk1B = (s8) D_80192690[arg0].unkB68;
    if ((D_80192690[arg0].unk1608 != 0) || ((D_80192690[arg0].unkC54 == 0x17)) ||
        ((D_80192690[arg0].unkC54 == 7) && (D_80192690[arg0].unkC58 < 0x38))) {
        arg1->unk15 = 2;
        return;
    }
    if (D_80192690[arg0].unkC54 == 0x18) {
        arg1->unk15 = 1;
        return;
    }
    arg1->unk15 = 0;
}

void func_80052A20(UnkStruct_80052C6C_2* arg0) {
    f32 temp_fa0;
    f32 temp_ft0;
    f32 temp_ft2;

    temp_fa0 = SQ(arg0->unkC.x) + SQ(arg0->unkC.y) + SQ(arg0->unkC.z);
    if (temp_fa0 != 0.0f) {
        temp_fa0 = 1.0f / sqrtf(temp_fa0);

        arg0->unkC.x *= temp_fa0;
        arg0->unkC.y *= temp_fa0;
        arg0->unkC.z *= temp_fa0;

        temp_fa0 = (arg0->unk14.y * arg0->unkC.z) - (arg0->unk14.z * arg0->unkC.y);
        temp_ft0 = (arg0->unk14.z * arg0->unkC.x) - (arg0->unk14.x * arg0->unkC.z);
        temp_ft2 = (arg0->unk14.x * arg0->unkC.y) - (arg0->unk14.y * arg0->unkC.x);

        arg0->unk14.x = (arg0->unkC.y * temp_ft2) - (arg0->unkC.z * temp_ft0);
        arg0->unk14.y = (arg0->unkC.z * temp_fa0) - (arg0->unkC.x * temp_ft2);
        arg0->unk14.z = (arg0->unkC.x * temp_ft0) - (arg0->unkC.y * temp_fa0);

        temp_fa0 = SQ(arg0->unk14.x) + SQ(arg0->unk14.y) + SQ(arg0->unk14.z);
        if (temp_fa0 != 0.0f) {
            temp_fa0 = 1.0f / sqrtf(temp_fa0);
            arg0->unk14.x *= temp_fa0;
            arg0->unk14.y *= temp_fa0;
            arg0->unk14.z *= temp_fa0;
        }
    }
}

void func_80052BB8(UnkStruct_80052E90_arg1_s* arg0) {
    func_80052A20(&arg0->unk264);
    func_80052A20(&arg0->unk240);
    func_80052A20(&arg0->unk21C);
    func_80052A20(&arg0->unkFC);
    func_80052A20(&arg0->unk1F8);
    func_80052A20(&arg0->unkD8);
    func_80052A20(&arg0->unk168);
    func_80052A20(&arg0->unk1D4);
    func_80052A20(&arg0->unk144);
    func_80052A20(&arg0->unk1B0);
    func_80052A20(&arg0->unk120);
    func_80052A20(&arg0->unk18C);
    func_80052A20(&arg0->unk48);
    func_80052A20(&arg0->unkB4);
    func_80052A20(&arg0->unk24);
    func_80052A20(&arg0->unk90);
    func_80052A20(&arg0->unk0);
    func_80052A20(&arg0->unk6C);
}

void func_80052C6C(UnkStruct_80192690* arg0, UnkStruct_80052C6C_1* arg1, UnkStruct_80052C6C_2* arg2) {
    f32 temp_fv0;
    f32 temp_fa0;
    f32 temp_fv1;

    temp_fv0 = arg1->unk0 * 0.1f;
    temp_fv1 = arg1->unk2 * 0.1f;
    temp_fa0 = arg1->unk4 * 0.1f;

    arg2->unk0.x = (arg0->unk84 * temp_fv0) + (arg0->unk78 * temp_fv1) + (arg0->unk6C * temp_fa0) + arg0->unk44.x;
    arg2->unk0.y = (arg0->unk88 * temp_fv0) + (arg0->unk7C * temp_fv1) + (arg0->unk70 * temp_fa0) + arg0->unk44.y;
    arg2->unk0.z = (arg0->unk8C * temp_fv0) + (arg0->unk80 * temp_fv1) + (arg0->unk74 * temp_fa0) + arg0->unk44.z;

    temp_fv0 = arg1->unk6 * 0.00787402f;
    temp_fv1 = arg1->unk7 * 0.00787402f;
    temp_fa0 = arg1->unk8 * 0.00787402f;

    arg2->unkC.x = (arg0->unk84 * temp_fv0) + (arg0->unk78 * temp_fv1) + (arg0->unk6C * temp_fa0);
    arg2->unkC.y = (arg0->unk88 * temp_fv0) + (arg0->unk7C * temp_fv1) + (arg0->unk70 * temp_fa0);
    arg2->unkC.z = (arg0->unk8C * temp_fv0) + (arg0->unk80 * temp_fv1) + (arg0->unk74 * temp_fa0);

    temp_fv0 = arg1->unk9 * 0.00787402f;
    temp_fv1 = arg1->unkA * 0.00787402f;
    temp_fa0 = arg1->unkB * 0.00787402f;

    arg2->unk14.x = (arg0->unk84 * temp_fv0) + (arg0->unk78 * temp_fv1) + (arg0->unk6C * temp_fa0);
    arg2->unk14.y = (arg0->unk88 * temp_fv0) + (arg0->unk7C * temp_fv1) + (arg0->unk70 * temp_fa0);
    arg2->unk14.z = (arg0->unk8C * temp_fv0) + (arg0->unk80 * temp_fv1) + (arg0->unk74 * temp_fa0);
}

s32 func_80052E90(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    UnkStruct_80192690* temp_s1;
    UnkStruct_802238DC* temp_s0;
    s16 temp_v0;

    temp_s0 = D_802238DC[arg2];
    if (arg3 >= temp_s0->unk0) {
        arg3 = temp_s0->unk0 - 1;
    }
    temp_s1 = &D_80192690[arg0];
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk4C[arg3]], &arg1->unk264);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk48[arg3]], &arg1->unk240);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk44[arg3]], &arg1->unk21C);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk24[arg3]], &arg1->unkFC);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk40[arg3]], &arg1->unk1F8);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk20[arg3]], &arg1->unkD8);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk30[arg3]], &arg1->unk168);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk3C[arg3]], &arg1->unk1D4);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk2C[arg3]], &arg1->unk144);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk38[arg3]], &arg1->unk1B0);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk28[arg3]], &arg1->unk120);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk34[arg3]], &arg1->unk18C);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk10[arg3]], &arg1->unk48);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk1C[arg3]], &arg1->unkB4);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unkC[arg3]], &arg1->unk24);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk18[arg3]], &arg1->unk90);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk8[arg3]], &arg1->unk0);
    func_80052C6C(temp_s1, (s32) &temp_s0->unk4[temp_s0->unk14[arg3]], &arg1->unk6C);
    arg3++;
    if (arg3 >= temp_s0->unk0) {
        arg3 = -1;
    }
    return arg3;
}

s32 func_80053268(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    s32* sp28;
    UnkStruct_80192690* temp_s0_2;
    s32 temp_s0;

    temp_s0 = arg2 - 0x12;
    if (arg3 >= D_800DA930[arg2 - 18]) {
        arg3 = D_800DA930[temp_s0] - 1;
    }
    func_80098048(temp_s0, arg3);
    func_80052C6C(&D_80192690[arg0], &D_801CE9C4, &arg1->unk264);
    func_80052C6C(&D_80192690[arg0], (UnkStruct_80052C6C_1*) D_801CE9B8, &arg1->unk240);
    func_80052C6C(&D_80192690[arg0], &D_801CEA6C, &arg1->unk21C);
    func_80052C6C(&D_80192690[arg0], &D_801CEA0C, &arg1->unkFC);
    func_80052C6C(&D_80192690[arg0], &D_801CEA60, &arg1->unk1F8);
    func_80052C6C(&D_80192690[arg0], &D_801CEA00, &arg1->unkD8);
    func_80052C6C(&D_80192690[arg0], &D_801CEA30, &arg1->unk168);
    func_80052C6C(&D_80192690[arg0], &D_801CEA54, &arg1->unk1D4);
    func_80052C6C(&D_80192690[arg0], &D_801CEA24, &arg1->unk144);
    func_80052C6C(&D_80192690[arg0], &D_801CEA48, &arg1->unk1B0);
    func_80052C6C(&D_80192690[arg0], &D_801CEA18, &arg1->unk120);
    func_80052C6C(&D_80192690[arg0], &D_801CEA3C, &arg1->unk18C);
    func_80052C6C(&D_80192690[arg0], &D_801CE9D0, &arg1->unk48);
    func_80052C6C(&D_80192690[arg0], &D_801CE9F4, &arg1->unkB4);
    func_80052C6C(&D_80192690[arg0], &D_801CE9C4, &arg1->unk24);
    func_80052C6C(&D_80192690[arg0], &D_801CE9E8, &arg1->unk90);
    func_80052C6C(&D_80192690[arg0], (UnkStruct_80052C6C_1*) D_801CE9B8, &arg1->unk0);
    func_80052C6C(&D_80192690[arg0], &D_801CE9DC, &arg1->unk6C);
    arg3 = arg3 + 1;
    if (arg3 >= D_800DA930[temp_s0]) {
        arg3 = -1;
    }
    return arg3;
}

// Fun float functions
#ifdef NON_MATCHING
// Float register allocation differs: the original keeps arg9/arg13 (later px/py/pz) in fs0-fs2 and has a
// 0x70 frame; this version spills more (frame 0x88). Control flow and arithmetic order match.
void func_800534AC(UnkStruct_80052C6C_2* arg0, f32* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                   f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 mx;
    f32 my;
    f32 mz;
    f32 ex;
    f32 ey;
    f32 ez;
    f32 px;
    f32 py;
    f32 pz;
    f32 len;
    f32 t;

    dx = arg6 - arg3;
    dy = arg7 - arg4;
    dz = arg8 - arg5;
    len = SQ(dx) + SQ(dy) + SQ(dz);
    if (!(len < 1e-06)) {
        t = (0.5 / len) * ((arg9 - arg10) + len);
        mx = (t * dx) + arg3;
        ex = mx - arg3;
        my = (t * dy) + arg4;
        ey = my - arg4;
        mz = (t * dz) + arg5;
        ez = mz - arg5;
        t = ((arg9 - SQ(ex)) - SQ(ey)) - SQ(ez);
        if (!(t <= 0.0f)) {
            cx = (arg12 * dz) - (arg13 * dy);
            cy = (arg13 * dx) - (arg11 * dz);
            cz = (arg11 * dy) - (arg12 * dx);
            px = (dy * cz) - (dz * cy);
            py = (dz * cx) - (dx * cz);
            pz = (dx * cy) - (dy * cx);
            len = SQ(px) + SQ(py) + SQ(pz);
            if (len != 0.0f) {
                t = sqrtf(t / len);
                arg0->unk0.x = (t * px) + mx;
                *arg1 = (t * py) + my;
                *arg2 = (t * pz) + mz;
                return;
            }
        }
    }
    arg9 = sqrtf(arg9);
    t = arg9 / (arg9 + sqrtf(arg10));
    arg0->unk0.x = (t * dx) + arg3;
    *arg1 = (t * dy) + arg4;
    *arg2 = (t * dz) + arg5;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800534AC.s")
#endif

void func_8005374C(UnkStruct_80052C6C_2* arg0, f32 t, UnkStruct_80052C6C_2* arg2, UnkStruct_80052C6C_2* arg3) {
    f32 lenSq;
    f32 vx;
    f32 vy;
    f32 vz;

    /* position lerp */
    arg0->unk0.x = LERP(arg2->unk0.x, arg3->unk0.x, t);
    arg0->unk0.y = LERP(arg2->unk0.y, arg3->unk0.y, t);
    arg0->unk0.z = LERP(arg2->unk0.z, arg3->unk0.z, t);

    /* forward vector lerp + normalize */
    vx = LERP(arg2->unkC.x, arg3->unkC.x, t);
    vy = LERP(arg2->unkC.y, arg3->unkC.y, t);
    vz = LERP(arg2->unkC.z, arg3->unkC.z, t);

    lenSq = SQ(vx) + SQ(vy) + SQ(vz);
    if (!(lenSq != 0.0f)) {
        return;
    }

    lenSq = 1.0f / sqrtf(lenSq);
    arg0->unkC.x = lenSq * vx;
    arg0->unkC.y = lenSq * vy;
    arg0->unkC.z = lenSq * vz;

    /* up vector lerp + normalize */
    vx = LERP(arg2->unk14.x, arg3->unk14.x, t);
    vy = LERP(arg2->unk14.y, arg3->unk14.y, t);
    vz = LERP(arg2->unk14.z, arg3->unk14.z, t);

    lenSq = SQ(vx) + SQ(vy) + SQ(vz);
    if (!(lenSq != 0.0f)) {
        return;
    }

    lenSq = 1.0f / sqrtf(lenSq);
    arg0->unk14.x = lenSq * vx;
    arg0->unk14.y = lenSq * vy;
    arg0->unk14.z = lenSq * vz;

    /* right = cross(up, forward) */
    vx = (arg0->unk14.y * arg0->unkC.z) - (arg0->unk14.z * arg0->unkC.y);
    vy = (arg0->unk14.z * arg0->unkC.x) - (arg0->unk14.x * arg0->unkC.z);
    vz = (arg0->unk14.x * arg0->unkC.y) - (arg0->unk14.y * arg0->unkC.x);

    lenSq = SQ(vx) + SQ(vy) + SQ(vz);
    if (!(lenSq != 0.0f)) {
        return;
    }

    lenSq = 1.0f / sqrtf(lenSq);
    vx *= lenSq;
    vy *= lenSq;
    vz *= lenSq;

    /* rebuild orthonormal up */
    arg0->unk14.x = (arg0->unkC.y * vz) - (arg0->unkC.z * vy);
    arg0->unk14.y = (arg0->unkC.z * vx) - (arg0->unkC.x * vz);
    arg0->unk14.z = (arg0->unkC.x * vy) - (arg0->unkC.y * vx);
}

void func_80053A5C(UnkStruct_80052E90_arg1_s* arg0, f32 arg1, UnkStruct_80052E90_arg1_s* arg2,
                   UnkStruct_80052E90_arg1_s* arg3) {
    func_8005374C(&arg0->unk264, arg1, &arg2->unk264, &arg3->unk264);
    func_8005374C(&arg0->unk240, arg1, &arg2->unk240, &arg3->unk240);
    func_8005374C(&arg0->unk21C, arg1, &arg2->unk21C, &arg3->unk21C);
    func_8005374C(&arg0->unkFC, arg1, &arg2->unkFC, &arg3->unkFC);
    func_8005374C(&arg0->unk1F8, arg1, &arg2->unk1F8, &arg3->unk1F8);
    func_8005374C(&arg0->unkD8, arg1, &arg2->unkD8, &arg3->unkD8);
    func_8005374C(&arg0->unk168, arg1, &arg2->unk168, &arg3->unk168);
    func_8005374C(&arg0->unk1D4, arg1, &arg2->unk1D4, &arg3->unk1D4);
    func_8005374C(&arg0->unk144, arg1, &arg2->unk144, &arg3->unk144);
    func_8005374C(&arg0->unk1B0, arg1, &arg2->unk1B0, &arg3->unk1B0);
    func_8005374C(&arg0->unk120, arg1, &arg2->unk120, &arg3->unk120);
    func_8005374C(&arg0->unk18C, arg1, &arg2->unk18C, &arg3->unk18C);
    func_8005374C(&arg0->unk48, arg1, &arg2->unk48, &arg3->unk48);
    func_8005374C(&arg0->unkB4, arg1, &arg2->unkB4, &arg3->unkB4);
    func_8005374C(&arg0->unk24, arg1, &arg2->unk24, &arg3->unk24);
    func_8005374C(&arg0->unk90, arg1, &arg2->unk90, &arg3->unk90);
    func_8005374C(&arg0->unk0, arg1, &arg2->unk0, &arg3->unk0);
    func_8005374C(&arg0->unk6C, arg1, &arg2->unk6C, &arg3->unk6C);
}

void func_80053C08(s32, s32);

void func_80053C08(s32 arg0, s32 arg1) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    RiderPart* p;

    if ((arg1 >= 18) && (arg1 < 22)) {
        rider->unkC68 = 0;
    } else {
        rider->unkC68 = 1;
    }
    if ((arg1 == 23) || (arg1 == 24) || (arg1 == 17) || ((arg1 >= 18) && (arg1 < 22))) {
        for (p = &RIDER_PARTS(rider)[18]; p >= &RIDER_PARTS(rider)[0]; p--) {
            p->unk0 = 0;
        }
        if (arg1 == 24) {
            rider->unk1574 = 0;
        }
    } else {
        for (p = &RIDER_PARTS(rider)[18]; p >= &RIDER_PARTS(rider)[0]; p--) {
            p->unk0 = 1;
        }
    }
    switch (arg1) {
        case 22:
        case 25:
            if (rider->unk16CC == 0) {
                RIDER_PARTS(rider)[17].unk0 = 4;
                RIDER_PARTS(rider)[9].unk0 = 4;
                RIDER_PARTS(rider)[18].unk0 = 4;
                RIDER_PARTS(rider)[10].unk0 = 4;
                RIDER_PARTS(rider)[6].unk0 = 2;
                RIDER_PARTS(rider)[14].unk0 = 3;
                return;
            }
            RIDER_PARTS(rider)[15].unk0 = 0;
            RIDER_PARTS(rider)[7].unk0 = 0;
            RIDER_PARTS(rider)[2].unk0 = 0;
            RIDER_PARTS(rider)[14].unk0 = 0;
            RIDER_PARTS(rider)[6].unk0 = 0;
            return;
        case 24:
            RIDER_PARTS(rider)[2].unk0 = 5;
            RIDER_PARTS(rider)[15].unk0 = 5;
            RIDER_PARTS(rider)[7].unk0 = 5;
            RIDER_PARTS(rider)[11].unk0 = 5;
            RIDER_PARTS(rider)[3].unk0 = 5;
            RIDER_PARTS(rider)[6].unk0 = 2;
            RIDER_PARTS(rider)[14].unk0 = 3;
            return;
        case 10:
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            RIDER_PARTS(rider)[6].unk0 = 2;
            RIDER_PARTS(rider)[14].unk0 = 3;
            return;
        case 15:
            RIDER_PARTS(rider)[16].unk0 = 0;
            RIDER_PARTS(rider)[8].unk0 = 0;
            RIDER_PARTS(rider)[15].unk0 = 0;
            RIDER_PARTS(rider)[7].unk0 = 0;
            RIDER_PARTS(rider)[2].unk0 = 0;
            RIDER_PARTS(rider)[6].unk0 = 2;
            RIDER_PARTS(rider)[14].unk0 = 3;
            return;
        case 8:
            RIDER_PARTS(rider)[14].unk0 = 0;
            RIDER_PARTS(rider)[6].unk0 = 0;
            RIDER_PARTS(rider)[15].unk0 = 0;
            RIDER_PARTS(rider)[7].unk0 = 0;
            RIDER_PARTS(rider)[2].unk0 = 0;
            rider->unkC68 = 0;
            return;
        case 17:
            rider->unkC68 = 0;
            return;
        case 7:
            RIDER_PARTS(rider)[14].unk0 = 0;
            RIDER_PARTS(rider)[6].unk0 = 0;
            RIDER_PARTS(rider)[16].unk0 = 0;
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[15].unk0 = 0;
            RIDER_PARTS(rider)[8].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            RIDER_PARTS(rider)[7].unk0 = 0;
            RIDER_PARTS(rider)[2].unk0 = 0;
            RIDER_PARTS(rider)[1].unk0 = 0;
            RIDER_PARTS(rider)[0].unk0 = 0;
            return;
        case 2:
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            RIDER_PARTS(rider)[14].unk0 = 3;
            return;
        case 9:
            RIDER_PARTS(rider)[15].unk0 = 0;
            RIDER_PARTS(rider)[7].unk0 = 0;
            RIDER_PARTS(rider)[2].unk0 = 0;
            RIDER_PARTS(rider)[16].unk0 = 0;
            RIDER_PARTS(rider)[8].unk0 = 0;
            return;
        case 1:
        case 6:
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            return;
        case 3:
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            RIDER_PARTS(rider)[14].unk0 = 3;
            return;
        case 4:
            RIDER_PARTS(rider)[16].unk0 = 0;
            RIDER_PARTS(rider)[18].unk0 = 0;
            RIDER_PARTS(rider)[17].unk0 = 0;
            RIDER_PARTS(rider)[8].unk0 = 0;
            RIDER_PARTS(rider)[10].unk0 = 0;
            RIDER_PARTS(rider)[9].unk0 = 0;
            return;
    }
}

s32 func_80053EAC(s32 arg0, s32 arg1, s32 arg2, f32 arg3, u16 arg4) {
    UnkStruct_80192690* temp_v0;

    temp_v0 = &D_80192690[arg0];

    if (arg3 == 1.0f) {
        if (arg1 == temp_v0->unkC54) {
            return -1;
        }
        temp_v0->unkC54 = arg1;
        temp_v0->unkC5C = -1;
        temp_v0->unkC58 = arg2;
        temp_v0->unkC6C = 0;
        temp_v0->unk142C = 0.0f;
        func_80053C08(arg0, arg1);
        return 0;
    }

    if (arg1 == temp_v0->unkC5C) {
        return -1;
    }
    temp_v0->unkC5C = arg1;
    temp_v0->unkC60 = arg2;
    temp_v0->unkC6C = 0;
    temp_v0->unk1430 = arg3;
    temp_v0->unk142C = arg3;
    temp_v0->unkC64 = arg4;
    func_80053C08(arg0, -1);
    return 0;
}

void func_80053FBC(UnkStruct_80192690* arg0, UnkStruct_80052C6C_1* arg1, UnkStruct_80052C6C_2* arg2) {
    f32 temp_f0;
    f32 temp_f12;
    f32 y;

    temp_f0 = arg1->unk0 * 0.1f;
    y = (arg1->unk2 * 0.1f);
    temp_f12 = arg1->unk4 * 0.1f;

    arg2->unk0.x = (arg0->unk143C * temp_f0) + (arg0->unk1434 * temp_f12) + arg0->unk44.x;
    arg2->unk0.y = arg0->unk44.y + y;
    arg2->unk0.z = (arg0->unk1440 * temp_f0) + (arg0->unk1438 * temp_f12) + arg0->unk44.z;

    temp_f0 = arg1->unk6 * 0.00787402f;
    y = arg1->unk7 * 0.00787402f;
    temp_f12 = arg1->unk8 * 0.00787402f;

    arg2->unkC.x = (arg0->unk143C * temp_f0) + (arg0->unk1434 * temp_f12);
    arg2->unkC.y = y;
    arg2->unkC.z = (arg0->unk1440 * temp_f0) + (arg0->unk1438 * temp_f12);

    temp_f0 = arg1->unk9 * 0.00787402f;
    y = arg1->unkA * 0.00787402f;
    temp_f12 = arg1->unkB * 0.00787402f;

    arg2->unk14.x = (arg0->unk143C * temp_f0) + (arg0->unk1434 * temp_f12);
    arg2->unk14.y = y;
    arg2->unk14.z = (arg0->unk1440 * temp_f0) + (arg0->unk1438 * temp_f12);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80054130.s")

s32 func_80054E14(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    UnkStruct_80192690* temp_s1;
    UnkStruct_802238DC* temp_s0;
    s32 var_s5;

    temp_s0 = D_802238DC[arg2];
    if (arg3 >= temp_s0->unk0) {
        arg3 = temp_s0->unk0 - 1;
    }
    temp_s1 = &D_80192690[arg0];
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk4C[arg3]], &arg1->unk264);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk48[arg3]], &arg1->unk240);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk44[arg3]], &arg1->unk21C);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk24[arg3]], &arg1->unkFC);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk40[arg3]], &arg1->unk1F8);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk20[arg3]], &arg1->unkD8);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk30[arg3]], &arg1->unk168);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk3C[arg3]], &arg1->unk1D4);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk2C[arg3]], &arg1->unk144);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk38[arg3]], &arg1->unk1B0);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk28[arg3]], &arg1->unk120);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk34[arg3]], &arg1->unk18C);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk10[arg3]], &arg1->unk48);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk1C[arg3]], &arg1->unkB4);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unkC[arg3]], &arg1->unk24);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk18[arg3]], &arg1->unk90);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk8[arg3]], &arg1->unk0);
    func_80053FBC(temp_s1, &temp_s0->unk4[temp_s0->unk14[arg3]], &arg1->unk6C);
    arg3++;
    if (arg3 >= temp_s0->unk0) {
        arg3 = -1;
    }
    return arg3;
}

s32 func_800551EC(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_v1;

    var_v1 = func_80054130(arg0, arg1, arg2, arg3, arg4, arg5);
    if (var_v1 == 0x19) {
        if ((D_801C3C50->unk16C4 == 2) || (D_801C3C50->unk16C4 == 1)) {
            var_v1 = -1;
        }
    } else if ((var_v1 < 0) && (D_801C3C50->unk16C4 == 1)) {
        var_v1 = 1;
    }
    return var_v1;
}

extern f32 D_800D4960;

s32 func_80055270(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    UnkStruct_80192690* temp_s2;
    UnkStruct_802238DC* temp_s1;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f0;
    f32 spB4;
    f32 spB0;
    f32 spAC;

    temp_s1 = D_802238DC[arg2];
    if (arg3 >= temp_s1->unk0) {
        arg3 = temp_s1->unk0 - 1;
    }
    temp_s2 = &D_80192690[arg0];
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk4C[arg3]], &arg1->unk264);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk48[arg3]], &arg1->unk240);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk44[arg3]], &arg1->unk21C);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk20[arg3]], &arg1->unkD8);
    temp_f2 = arg1->unkD8.unk0.x - temp_s2->unk44.x;
    temp_f12 = arg1->unkD8.unk0.y - temp_s2->unk44.y;
    temp_f14 = arg1->unkD8.unk0.z - temp_s2->unk44.z;
    temp_f0 = temp_s2->unk16B8 * D_800D4960;
    spB4 = temp_s2->unk84 * temp_f0;
    spB0 = temp_s2->unk88 * temp_f0;
    spAC = temp_s2->unk8C * temp_f0;
    temp_f0 = ((temp_s2->unk16BC * 0.9f) - 0.9f) *
              ((temp_f2 * temp_s2->unk78) + (temp_f12 * temp_s2->unk7C) + (temp_f14 * temp_s2->unk80));

    temp_f2 += temp_s2->unk44.x + (temp_f0 * temp_s2->unk78) + spB4;
    spB4 = temp_f2 - arg1->unkD8.unk0.x;
    temp_f12 += temp_s2->unk44.y + (temp_f0 * temp_s2->unk7C) + spB0;
    spB0 = temp_f12 - arg1->unkD8.unk0.y;
    temp_f14 += temp_s2->unk44.z + (temp_f0 * temp_s2->unk80) + spAC;
    spAC = temp_f14 - arg1->unkD8.unk0.z;

    arg1->unkD8.unk0.x = temp_f2;
    arg1->unkD8.unk0.y = temp_f12;
    arg1->unkD8.unk0.z = temp_f14;

    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk10[arg3]], &arg1->unk48);
    arg1->unk48.unk0.x += spB4;
    arg1->unk48.unk0.y += spB0;
    arg1->unk48.unk0.z += spAC;
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk1C[arg3]], &arg1->unkB4);
    arg1->unkB4.unk0.x += spB4;
    arg1->unkB4.unk0.y += spB0;
    arg1->unkB4.unk0.z += spAC;
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk8[arg3]], &arg1->unk0);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk14[arg3]], &arg1->unk6C);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unkC[arg3]], &arg1->unk24);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk18[arg3]], &arg1->unk90);
    func_800534AC(&arg1->unk24, &arg1->unk24.unk0.y, &arg1->unk24.unk0.z, arg1->unk48.unk0.x, arg1->unk48.unk0.y,
                  arg1->unk48.unk0.z, arg1->unk0.unk0.x, arg1->unk0.unk0.y, arg1->unk0.unk0.z, 298.01123f, 355.76913f,
                  arg1->unk48.unk14.x, arg1->unk48.unk14.y, arg1->unk48.unk14.z);
    func_800534AC(&arg1->unk90, &arg1->unk90.unk0.y, &arg1->unk90.unk0.z, arg1->unkB4.unk0.x, arg1->unkB4.unk0.y,
                  arg1->unkB4.unk0.z, arg1->unk6C.unk0.x, arg1->unk6C.unk0.y, arg1->unk6C.unk0.z, 298.01123f,
                  355.76913f, arg1->unkB4.unk14.x, arg1->unkB4.unk14.y, arg1->unkB4.unk14.z);
    arg1->unk48.unkC.x = arg1->unk24.unk0.x - arg1->unk48.unk0.x;
    arg1->unk48.unkC.y = arg1->unk24.unk0.y - arg1->unk48.unk0.y;
    arg1->unk48.unkC.z = arg1->unk24.unk0.z - arg1->unk48.unk0.z;
    arg1->unkB4.unkC.x = arg1->unk90.unk0.x - arg1->unkB4.unk0.x;
    arg1->unkB4.unkC.y = arg1->unk90.unk0.y - arg1->unkB4.unk0.y;
    arg1->unkB4.unkC.z = arg1->unk90.unk0.z - arg1->unkB4.unk0.z;
    arg1->unk24.unkC.x = arg1->unk0.unk0.x - arg1->unk24.unk0.x;
    arg1->unk24.unkC.y = arg1->unk0.unk0.y - arg1->unk24.unk0.y;
    arg1->unk24.unkC.z = arg1->unk0.unk0.z - arg1->unk24.unk0.z;
    arg1->unk90.unkC.x = arg1->unk6C.unk0.x - arg1->unk90.unk0.x;
    arg1->unk90.unkC.y = arg1->unk6C.unk0.y - arg1->unk90.unk0.y;
    arg1->unk90.unkC.z = arg1->unk6C.unk0.z - arg1->unk90.unk0.z;
    func_80052A20(&arg1->unk48);
    func_80052A20(&arg1->unkB4);
    func_80052A20(&arg1->unk24);
    func_80052A20(&arg1->unk90);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk28[arg3]], &arg1->unk120);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk34[arg3]], &arg1->unk18C);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk2C[arg3]], &arg1->unk144);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk38[arg3]], &arg1->unk1B0);
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk40[arg3]], &arg1->unk1F8);
    arg1->unk1F8.unk0.x += (spB4 = arg1->unkD8.unk0.x - arg1->unk1F8.unk0.x);
    arg1->unk1F8.unk0.y += (spB0 = arg1->unkD8.unk0.y - arg1->unk1F8.unk0.y);
    arg1->unk1F8.unk0.z += (spAC = arg1->unkD8.unk0.z - arg1->unk1F8.unk0.z);
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk24[arg3]], &arg1->unkFC);
    arg1->unkFC.unk0.x += spB4;
    arg1->unkFC.unk0.y += spB0;
    arg1->unkFC.unk0.z += spAC;
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk30[arg3]], &arg1->unk168);
    arg1->unk168.unk0.x += spB4;
    arg1->unk168.unk0.y += spB0;
    arg1->unk168.unk0.z += spAC;
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk3C[arg3]], &arg1->unk1D4);
    arg1->unk1D4.unk0.x += spB4;
    arg1->unk1D4.unk0.y += spB0;
    arg1->unk1D4.unk0.z += spAC;
    func_800534AC(&arg1->unk144, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y,
                  arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk168.unk14.x, -arg1->unk168.unk14.y, -arg1->unk168.unk14.z);
    func_800534AC(&arg1->unk1B0, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y,
                  arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk1D4.unk14.x, -arg1->unk1D4.unk14.y, -arg1->unk1D4.unk14.z);
    arg1->unk168.unkC.x = arg1->unk144.unk0.x - arg1->unk168.unk0.x;
    arg1->unk168.unkC.y = arg1->unk144.unk0.y - arg1->unk168.unk0.y;
    arg1->unk168.unkC.z = arg1->unk144.unk0.z - arg1->unk168.unk0.z;
    arg1->unk144.unkC.x = arg1->unk120.unk0.x - arg1->unk144.unk0.x;
    arg1->unk144.unkC.y = arg1->unk120.unk0.y - arg1->unk144.unk0.y;
    arg1->unk144.unkC.z = arg1->unk120.unk0.z - arg1->unk144.unk0.z;
    arg1->unk1D4.unkC.x = arg1->unk1B0.unk0.x - arg1->unk1D4.unk0.x;
    arg1->unk1D4.unkC.y = arg1->unk1B0.unk0.y - arg1->unk1D4.unk0.y;
    arg1->unk1D4.unkC.z = arg1->unk1B0.unk0.z - arg1->unk1D4.unk0.z;
    arg1->unk1B0.unkC.x = arg1->unk18C.unk0.x - arg1->unk1B0.unk0.x;
    arg1->unk1B0.unkC.y = arg1->unk18C.unk0.y - arg1->unk1B0.unk0.y;
    arg1->unk1B0.unkC.z = arg1->unk18C.unk0.z - arg1->unk1B0.unk0.z;
    func_80052A20(&arg1->unk168);
    func_80052A20(&arg1->unk144);
    func_80052A20(&arg1->unk1D4);
    func_80052A20(&arg1->unk1B0);
    arg3++;
    if ((arg3 >= temp_s1->unk0) || (((arg3) == 0x26))) {
        arg3 = -1;
    }

    return arg3;
}

s32 func_80055C6C(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    UnkStruct_80192690* temp_s2;
    UnkStruct_802238DC* temp_s1;
    f32 var_fv0;
    f32 temp_fv1;
    f32 temp_fa0;
    f32 temp_fa1;

    temp_s1 = D_802238DC[arg2];
    if (arg3 >= temp_s1->unk0) {
        arg3 = temp_s1->unk0 - 1;
    }
    temp_s2 = &D_80192690[arg0];
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk4C[arg3]], &arg1->unk264);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk48[arg3]], &arg1->unk240);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk44[arg3]], &arg1->unk21C);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk20[arg3]], &arg1->unkD8);
    if (arg3 < 0x2D) {
        if (arg3 < 0x24) {
            var_fv0 = 0.0f;
        } else {
            var_fv0 = 1.0f - ((f32) (0x2D - arg3) / 10.0f);
        }
    } else if (arg3 >= 0x37) {
        var_fv0 = 0.0f;
    } else {
        var_fv0 = 1.0f - ((f32) (arg3 - 0x2D) / 10.0f);
    }
    var_fv0 *= (D_800D495C * temp_s2->unk16B8);
    temp_fv1 = temp_s2->unk84 * var_fv0;
    temp_fa0 = temp_s2->unk88 * var_fv0;
    temp_fa1 = temp_s2->unk8C * var_fv0;
    arg1->unkD8.unk0.x += temp_fv1;
    arg1->unkD8.unk0.y += temp_fa0;
    arg1->unkD8.unk0.z += temp_fa1;
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk10[arg3]], &arg1->unk48);
    arg1->unk48.unk0.x += temp_fv1;
    arg1->unk48.unk0.y += temp_fa0;
    arg1->unk48.unk0.z += temp_fa1;
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk1C[arg3]], &arg1->unkB4);
    arg1->unkB4.unk0.x += temp_fv1;
    arg1->unkB4.unk0.y += temp_fa0;
    arg1->unkB4.unk0.z += temp_fa1;
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk8[arg3]], &arg1->unk0);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk14[arg3]], &arg1->unk6C);
    if (var_fv0 < 0.0f) {
        arg1->unk6C.unk0.x -= var_fv0 * temp_s2->unk78;
        arg1->unk6C.unk0.y -= var_fv0 * temp_s2->unk7C;
        arg1->unk6C.unk0.z -= var_fv0 * temp_s2->unk80;
    } else {
        arg1->unk0.unk0.x += var_fv0 * temp_s2->unk78;
        arg1->unk0.unk0.y += var_fv0 * temp_s2->unk7C;
        arg1->unk0.unk0.z += var_fv0 * temp_s2->unk80;
    }
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unkC[arg3]], &arg1->unk24);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk18[arg3]], &arg1->unk90);
    func_800534AC(&arg1->unk24, &arg1->unk24.unk0.y, &arg1->unk24.unk0.z, arg1->unk48.unk0.x, arg1->unk48.unk0.y,
                  arg1->unk48.unk0.z, arg1->unk0.unk0.x, arg1->unk0.unk0.y, arg1->unk0.unk0.z, 298.01123f, 355.76913f,
                  arg1->unk48.unk14.x, arg1->unk48.unk14.y, arg1->unk48.unk14.z);
    func_800534AC(&arg1->unk90, &arg1->unk90.unk0.y, &arg1->unk90.unk0.z, arg1->unkB4.unk0.x, arg1->unkB4.unk0.y,
                  arg1->unkB4.unk0.z, arg1->unk6C.unk0.x, arg1->unk6C.unk0.y, arg1->unk6C.unk0.z, 298.01123f,
                  355.76913f, arg1->unkB4.unk14.x, arg1->unkB4.unk14.y, arg1->unkB4.unk14.z);
    arg1->unk48.unkC.x = arg1->unk24.unk0.x - arg1->unk48.unk0.x;
    arg1->unk48.unkC.y = arg1->unk24.unk0.y - arg1->unk48.unk0.y;
    arg1->unk48.unkC.z = arg1->unk24.unk0.z - arg1->unk48.unk0.z;
    arg1->unkB4.unkC.x = arg1->unk90.unk0.x - arg1->unkB4.unk0.x;
    arg1->unkB4.unkC.y = arg1->unk90.unk0.y - arg1->unkB4.unk0.y;
    arg1->unkB4.unkC.z = arg1->unk90.unk0.z - arg1->unkB4.unk0.z;
    arg1->unk24.unkC.x = arg1->unk0.unk0.x - arg1->unk24.unk0.x;
    arg1->unk24.unkC.y = arg1->unk0.unk0.y - arg1->unk24.unk0.y;
    arg1->unk24.unkC.z = arg1->unk0.unk0.z - arg1->unk24.unk0.z;
    arg1->unk90.unkC.x = arg1->unk6C.unk0.x - arg1->unk90.unk0.x;
    arg1->unk90.unkC.y = arg1->unk6C.unk0.y - arg1->unk90.unk0.y;
    arg1->unk90.unkC.z = arg1->unk6C.unk0.z - arg1->unk90.unk0.z;
    func_80052A20(&arg1->unk48);
    func_80052A20(&arg1->unkB4);
    func_80052A20(&arg1->unk24);
    func_80052A20(&arg1->unk90);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk28[arg3]], &arg1->unk120);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk34[arg3]], &arg1->unk18C);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk2C[arg3]], &arg1->unk144);
    func_80052C6C(temp_s2, &temp_s1->unk4[temp_s1->unk38[arg3]], &arg1->unk1B0);
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk40[arg3]], &arg1->unk1F8);

    arg1->unk1F8.unk0.x += (temp_fv1 = arg1->unkD8.unk0.x - arg1->unk1F8.unk0.x);
    arg1->unk1F8.unk0.y += (temp_fa0 = arg1->unkD8.unk0.y - arg1->unk1F8.unk0.y);
    arg1->unk1F8.unk0.z += (temp_fa1 = arg1->unkD8.unk0.z - arg1->unk1F8.unk0.z);
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk24[arg3]], &arg1->unkFC);
    arg1->unkFC.unk0.x += temp_fv1;
    arg1->unkFC.unk0.y += temp_fa0;
    arg1->unkFC.unk0.z += temp_fa1;
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk30[arg3]], &arg1->unk168);
    arg1->unk168.unk0.x += temp_fv1;
    arg1->unk168.unk0.y += temp_fa0;
    arg1->unk168.unk0.z += temp_fa1;
    func_80053FBC(temp_s2, &temp_s1->unk4[temp_s1->unk3C[arg3]], &arg1->unk1D4);
    arg1->unk1D4.unk0.x += temp_fv1;
    arg1->unk1D4.unk0.y += temp_fa0;
    arg1->unk1D4.unk0.z += temp_fa1;
    func_800534AC(&arg1->unk144, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y,
                  arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk168.unk14.x, -arg1->unk168.unk14.y, -arg1->unk168.unk14.z);
    func_800534AC(&arg1->unk1B0, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y,
                  arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk1D4.unk14.x, -arg1->unk1D4.unk14.y, -arg1->unk1D4.unk14.z);
    arg1->unk168.unkC.x = arg1->unk144.unk0.x - arg1->unk168.unk0.x;
    arg1->unk168.unkC.y = arg1->unk144.unk0.y - arg1->unk168.unk0.y;
    arg1->unk168.unkC.z = arg1->unk144.unk0.z - arg1->unk168.unk0.z;
    arg1->unk144.unkC.x = arg1->unk120.unk0.x - arg1->unk144.unk0.x;
    arg1->unk144.unkC.y = arg1->unk120.unk0.y - arg1->unk144.unk0.y;
    arg1->unk144.unkC.z = arg1->unk120.unk0.z - arg1->unk144.unk0.z;
    arg1->unk1D4.unkC.x = arg1->unk1B0.unk0.x - arg1->unk1D4.unk0.x;
    arg1->unk1D4.unkC.y = arg1->unk1B0.unk0.y - arg1->unk1D4.unk0.y;
    arg1->unk1D4.unkC.z = arg1->unk1B0.unk0.z - arg1->unk1D4.unk0.z;
    arg1->unk1B0.unkC.x = arg1->unk18C.unk0.x - arg1->unk1B0.unk0.x;
    arg1->unk1B0.unkC.y = arg1->unk18C.unk0.y - arg1->unk1B0.unk0.y;
    arg1->unk1B0.unkC.z = arg1->unk18C.unk0.z - arg1->unk1B0.unk0.z;
    func_80052A20(&arg1->unk168);
    func_80052A20(&arg1->unk144);
    func_80052A20(&arg1->unk1D4);
    func_80052A20(&arg1->unk1B0);
    arg3++;
    if (arg3 >= temp_s1->unk0) {
        arg3 = -1;
    }
    return arg3;
}

s32 func_80056670(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    UnkStruct_80192690* temp_s1;
    UnkStruct_802238DC* temp_s2;
    f32 temp_fv1;
    f32 diffX;
    f32 diffY;
    f32 diffZ;
    f32 sp31C;
    f32 sp318;
    f32 sp314;
    UnkStruct_80052E90_arg1_s sp8C;

    if ((arg3 < 0xE) || (arg3 >= 0x2F)) {
        return func_80052E90(arg0, arg1, arg2, arg3);
    }
    temp_s2 = D_802238DC[arg2];
    if (arg3 >= temp_s2->unk0) {
        arg3 = temp_s2->unk0 - 1;
    }
    temp_s1 = &D_80192690[arg0];
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk4C[arg3]], &arg1->unk264);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk48[arg3]], &arg1->unk240);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk44[arg3]], &arg1->unk21C);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk28[arg3]], &arg1->unk120);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk34[arg3]], &arg1->unk18C);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk30[arg3]], &arg1->unk168);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk3C[arg3]], &arg1->unk1D4);
    temp_fv1 = temp_s1->unk16B8 * D_800D4958;
    sp31C = temp_s1->unk84 * temp_fv1;
    sp318 = temp_s1->unk88 * temp_fv1;
    sp314 = temp_s1->unk8C * temp_fv1;
    diffX = arg1->unk168.unk0.x - temp_s1->unk44.x;
    diffY = arg1->unk168.unk0.y - temp_s1->unk44.y;
    diffZ = arg1->unk168.unk0.z - temp_s1->unk44.z;

    temp_fv1 =
        (temp_s1->unk16BC - 1.0f) * ((diffX * temp_s1->unk78) + (diffY * temp_s1->unk7C) + (diffZ * temp_s1->unk80));

    diffX =
        (arg1->unk144.unk0.x = temp_s1->unk44.x + diffX + (temp_fv1 * temp_s1->unk78) + sp31C) - arg1->unk120.unk0.x;
    diffY =
        (arg1->unk144.unk0.y = temp_s1->unk44.y + diffY + (temp_fv1 * temp_s1->unk7C) + sp318) - arg1->unk120.unk0.y;
    diffZ =
        (arg1->unk144.unk0.z = temp_s1->unk44.z + diffZ + (temp_fv1 * temp_s1->unk80) + sp314) - arg1->unk120.unk0.z;

    temp_fv1 = SQ(diffX) + SQ(diffY) + SQ(diffZ);
    if (temp_fv1 > 361.00007600000407) {
        temp_fv1 = 19.000002000000002 / sqrtf(temp_fv1);
        arg1->unk144.unk0.x = arg1->unk120.unk0.x + (temp_fv1 * diffX);
        arg1->unk144.unk0.y = arg1->unk120.unk0.y + (temp_fv1 * diffY);
        arg1->unk144.unk0.z = arg1->unk120.unk0.z + (temp_fv1 * diffZ);
    }
    diffX = arg1->unk1D4.unk0.x - temp_s1->unk44.x;
    diffY = arg1->unk1D4.unk0.y - temp_s1->unk44.y;
    diffZ = arg1->unk1D4.unk0.z - temp_s1->unk44.z;
    temp_fv1 =
        (temp_s1->unk16BC - 1.0f) * ((diffX * temp_s1->unk78) + (diffY * temp_s1->unk7C) + (diffZ * temp_s1->unk80));
    diffX =
        (arg1->unk1B0.unk0.x = temp_s1->unk44.x + diffX + (temp_fv1 * temp_s1->unk78) + sp31C) - arg1->unk18C.unk0.x;
    diffY =
        (arg1->unk1B0.unk0.y = temp_s1->unk44.y + diffY + (temp_fv1 * temp_s1->unk7C) + sp318) - arg1->unk18C.unk0.y;
    diffZ =
        (arg1->unk1B0.unk0.z = temp_s1->unk44.z + diffZ + (temp_fv1 * temp_s1->unk80) + sp314) - arg1->unk18C.unk0.z;

    temp_fv1 = SQ(diffX) + SQ(diffY) + SQ(diffZ);
    if ((f64) temp_fv1 > 361.00007600000407) {
        temp_fv1 = (f32) (19.000002000000002 / (f64) sqrtf(temp_fv1));
        arg1->unk1B0.unk0.x = arg1->unk18C.unk0.x + (temp_fv1 * diffX);
        arg1->unk1B0.unk0.y = arg1->unk18C.unk0.y + (temp_fv1 * diffY);
        arg1->unk1B0.unk0.z = arg1->unk18C.unk0.z + (temp_fv1 * diffZ);
    }
    sp31C = (((arg1->unk144.unk0.x - arg1->unk168.unk0.x) + arg1->unk1B0.unk0.x) - arg1->unk1D4.unk0.x) * 0.5f;
    sp318 = (((arg1->unk144.unk0.y - arg1->unk168.unk0.y) + arg1->unk1B0.unk0.y) - arg1->unk1D4.unk0.y) * 0.5f;
    sp314 = (((arg1->unk144.unk0.z - arg1->unk168.unk0.z) + arg1->unk1B0.unk0.z) - arg1->unk1D4.unk0.z) * 0.5f;
    arg1->unk168.unk0.x = arg1->unk168.unk0.x + sp31C;
    arg1->unk168.unk0.y = arg1->unk168.unk0.y + sp318;
    arg1->unk168.unk0.z = arg1->unk168.unk0.z + sp314;
    arg1->unk1D4.unk0.x = arg1->unk1D4.unk0.x + sp31C;
    arg1->unk1D4.unk0.y = arg1->unk1D4.unk0.y + sp318;
    arg1->unk1D4.unk0.z = arg1->unk1D4.unk0.z + sp314;
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk2C[arg3]], &arg1->unk144);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk38[arg3]], &arg1->unk1B0);
    func_800534AC(&arg1->unk144, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y,
                  arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk168.unk14.x, -arg1->unk168.unk14.y, -arg1->unk168.unk14.z);
    func_800534AC(&arg1->unk1B0, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y,
                  arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f,
                  109.34885f, -arg1->unk1D4.unk14.x, -arg1->unk1D4.unk14.y, -arg1->unk1D4.unk14.z);
    arg1->unk168.unkC.x = arg1->unk144.unk0.x - arg1->unk168.unk0.x;
    arg1->unk168.unkC.y = arg1->unk144.unk0.y - arg1->unk168.unk0.y;
    arg1->unk168.unkC.z = arg1->unk144.unk0.z - arg1->unk168.unk0.z;
    arg1->unk144.unkC.x = arg1->unk120.unk0.x - arg1->unk144.unk0.x;
    arg1->unk144.unkC.y = arg1->unk120.unk0.y - arg1->unk144.unk0.y;
    arg1->unk144.unkC.z = arg1->unk120.unk0.z - arg1->unk144.unk0.z;
    arg1->unk1D4.unkC.x = arg1->unk1B0.unk0.x - arg1->unk1D4.unk0.x;
    arg1->unk1D4.unkC.y = arg1->unk1B0.unk0.y - arg1->unk1D4.unk0.y;
    arg1->unk1D4.unkC.z = arg1->unk1B0.unk0.z - arg1->unk1D4.unk0.z;
    arg1->unk1B0.unkC.x = arg1->unk18C.unk0.x - arg1->unk1B0.unk0.x;
    arg1->unk1B0.unkC.y = arg1->unk18C.unk0.y - arg1->unk1B0.unk0.y;
    arg1->unk1B0.unkC.z = arg1->unk18C.unk0.z - arg1->unk1B0.unk0.z;
    func_80052A20(&arg1->unk168);
    func_80052A20(&arg1->unk144);
    func_80052A20(&arg1->unk1D4);
    func_80052A20(&arg1->unk1B0);
    func_80052C6C(temp_s1, &temp_s2->unk4[temp_s2->unk40[arg3]], &arg1->unk1F8);
    arg1->unk1F8.unk0.x += sp31C;
    arg1->unk1F8.unk0.y += sp318;
    arg1->unk1F8.unk0.z += sp314;
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk24[arg3]], &arg1->unkFC);
    arg1->unkFC.unk0.x = (f32) ((f64) arg1->unk1F8.unk0.x + (14.483002 * (f64) arg1->unk1F8.unkC.x));
    arg1->unkFC.unk0.y = (f32) ((f64) arg1->unk1F8.unk0.y + (14.483002 * (f64) arg1->unk1F8.unkC.y));
    arg1->unkFC.unk0.z = (f32) ((f64) arg1->unk1F8.unk0.z + (14.483002 * (f64) arg1->unk1F8.unkC.z));
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk20[arg3]], &arg1->unkD8);
    sp31C = arg1->unk1F8.unk0.x - arg1->unkD8.unk0.x;
    sp318 = arg1->unk1F8.unk0.y - arg1->unkD8.unk0.y;
    sp314 = arg1->unk1F8.unk0.z - arg1->unkD8.unk0.z;
    arg1->unkD8.unk0.x = arg1->unk1F8.unk0.x;
    arg1->unkD8.unk0.y = arg1->unk1F8.unk0.y;
    arg1->unkD8.unk0.z = arg1->unk1F8.unk0.z;
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk10[arg3]], &arg1->unk48);
    arg1->unk48.unk0.x += sp31C;
    arg1->unk48.unk0.y += sp318;
    arg1->unk48.unk0.z += sp314;
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk1C[arg3]], &arg1->unkB4);
    arg1->unkB4.unk0.x += sp31C;
    arg1->unkB4.unk0.y += sp318;
    arg1->unkB4.unk0.z += sp314;
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk8[arg3]], &arg1->unk0);
    diffX = (arg1->unk0.unk0.x + sp31C) - temp_s1->unk44.x;
    diffY = (arg1->unk0.unk0.y + sp318) - temp_s1->unk44.y;
    diffZ = (arg1->unk0.unk0.z + sp314) - temp_s1->unk44.z;
    temp_fv1 = ((temp_s1->unk16BC * 0.9f) - 0.9f) *
               ((diffX * temp_s1->unk78) + (diffY * temp_s1->unk7C) + (diffZ * temp_s1->unk80));
    arg1->unk0.unk0.x = temp_s1->unk44.x + diffX + (temp_fv1 * temp_s1->unk78);
    arg1->unk0.unk0.y = temp_s1->unk44.y + diffY + (temp_fv1 * temp_s1->unk7C);
    arg1->unk0.unk0.z = temp_s1->unk44.z + diffZ + (temp_fv1 * temp_s1->unk80);
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk14[arg3]], &arg1->unk6C);
    diffX = (arg1->unk6C.unk0.x + sp31C) - temp_s1->unk44.x;
    diffY = (arg1->unk6C.unk0.y + sp318) - temp_s1->unk44.y;
    diffZ = (arg1->unk6C.unk0.z + sp314) - temp_s1->unk44.z;
    temp_fv1 = ((temp_s1->unk16BC * 0.9f) - 0.9f) *
               ((diffX * temp_s1->unk78) + (diffY * temp_s1->unk7C) + (diffZ * temp_s1->unk80));
    arg1->unk6C.unk0.x = temp_s1->unk44.x + diffX + (temp_fv1 * temp_s1->unk78);
    arg1->unk6C.unk0.y = temp_s1->unk44.y + diffY + (temp_fv1 * temp_s1->unk7C);
    arg1->unk6C.unk0.z = temp_s1->unk44.z + diffZ + (temp_fv1 * temp_s1->unk80);
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unkC[arg3]], &arg1->unk24);
    func_80053FBC(temp_s1, &temp_s2->unk4[temp_s2->unk18[arg3]], &arg1->unk90);
    func_800534AC(&arg1->unk24, &arg1->unk24.unk0.y, &arg1->unk24.unk0.z, arg1->unk48.unk0.x, arg1->unk48.unk0.y,
                  arg1->unk48.unk0.z, arg1->unk0.unk0.x, arg1->unk0.unk0.y, arg1->unk0.unk0.z, 298.01123f, 355.76913f,
                  arg1->unk48.unk14.x, arg1->unk48.unk14.y, arg1->unk48.unk14.z);
    func_800534AC(&arg1->unk90, &arg1->unk90.unk0.y, &arg1->unk90.unk0.z, arg1->unkB4.unk0.x, arg1->unkB4.unk0.y,
                  arg1->unkB4.unk0.z, arg1->unk6C.unk0.x, arg1->unk6C.unk0.y, arg1->unk6C.unk0.z, 298.01123f,
                  355.76913f, arg1->unkB4.unk14.x, arg1->unkB4.unk14.y, arg1->unkB4.unk14.z);
    arg1->unk48.unkC.x = arg1->unk24.unk0.x - arg1->unk48.unk0.x;
    arg1->unk48.unkC.y = arg1->unk24.unk0.y - arg1->unk48.unk0.y;
    arg1->unk48.unkC.z = arg1->unk24.unk0.z - arg1->unk48.unk0.z;
    arg1->unkB4.unkC.x = arg1->unk90.unk0.x - arg1->unkB4.unk0.x;
    arg1->unkB4.unkC.y = arg1->unk90.unk0.y - arg1->unkB4.unk0.y;
    arg1->unkB4.unkC.z = arg1->unk90.unk0.z - arg1->unkB4.unk0.z;
    arg1->unk24.unkC.x = arg1->unk0.unk0.x - arg1->unk24.unk0.x;
    arg1->unk24.unkC.y = arg1->unk0.unk0.y - arg1->unk24.unk0.y;
    arg1->unk24.unkC.z = arg1->unk0.unk0.z - arg1->unk24.unk0.z;
    arg1->unk90.unkC.x = arg1->unk6C.unk0.x - arg1->unk90.unk0.x;
    arg1->unk90.unkC.y = arg1->unk6C.unk0.y - arg1->unk90.unk0.y;
    arg1->unk90.unkC.z = arg1->unk6C.unk0.z - arg1->unk90.unk0.z;
    func_80052A20(&arg1->unk48);
    func_80052A20(&arg1->unkB4);
    func_80052A20(&arg1->unk24);
    func_80052A20(&arg1->unk90);
    if (arg3 < 0x17) {
        arg3 = func_80052E90(arg0, &sp8C, arg2, arg3);
        func_80053A5C(arg1, (f32) (arg3 - 0xD) / 10.0f, &sp8C, arg1);
    } else if (arg3 >= 0x26) {
        arg3 = func_80052E90(arg0, &sp8C, arg2, arg3);
        func_80053A5C(arg1, (f32) (arg3 - 0x25) / 10.0f, arg1, &sp8C);
    } else {
        arg3++;
        if (arg3 >= temp_s2->unk0) {
            arg3 = -1;
        }
    }
    return arg3;
}

void func_800574E4(UnkStruct_80052E90_arg1_s* arg0, UnkStruct_80052C6C_2* arg1, UnkStruct_80052C6C_1* arg2,
                   UnkStruct_80052C6C_1* arg3, f32 arg4) {
    UnkStruct_80052C6C_2 sp4C;
    UnkStruct_80052C6C_2 sp28;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f2;

    temp_f0 = arg2->unk0 * 0.1f;
    temp_f2 = arg2->unk2 * 0.1f;
    temp_f12 = arg2->unk4 * 0.1f;
    sp4C.unk0.x = arg0->unk24.unk14.z + (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) +
                  (arg0->unk6C.unk0.x * temp_f12);
    sp4C.unk0.y = arg0->unk48.unk0.x + (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) +
                  (arg0->unk6C.unk0.y * temp_f12);
    sp4C.unk0.z = arg0->unk48.unk0.y + (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) +
                  (arg0->unk6C.unk0.z * temp_f12);
    temp_f0 = (f32) arg2->unk6 * 0.00787402f;
    temp_f2 = (f32) arg2->unk7 * 0.00787402f;
    temp_f12 = (f32) arg2->unk8 * 0.00787402f;
    sp4C.unkC.x = (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) + (arg0->unk6C.unk0.x * temp_f12);
    sp4C.unkC.y = (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) + (arg0->unk6C.unk0.y * temp_f12);
    sp4C.unkC.z = (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) + (arg0->unk6C.unk0.z * temp_f12);
    temp_f0 = (f32) arg2->unk9 * 0.00787402f;
    temp_f2 = (f32) arg2->unkA * 0.00787402f;
    temp_f12 = (f32) arg2->unkB * 0.00787402f;
    sp4C.unk14.x = (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) + (arg0->unk6C.unk0.x * temp_f12);
    sp4C.unk14.y = (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) + (arg0->unk6C.unk0.y * temp_f12);
    sp4C.unk14.z = (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) + (arg0->unk6C.unk0.z * temp_f12);
    temp_f0 = (f32) arg3->unk0 * 0.1f;
    temp_f2 = (f32) arg3->unk2 * 0.1f;
    temp_f12 = (f32) arg3->unk4 * 0.1f;
    sp28.unk0.x = arg0->unk24.unk14.z + (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) +
                  (arg0->unk6C.unk0.x * temp_f12);
    sp28.unk0.y = arg0->unk48.unk0.x + (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) +
                  (arg0->unk6C.unk0.y * temp_f12);
    sp28.unk0.z = arg0->unk48.unk0.y + (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) +
                  (arg0->unk6C.unk0.z * temp_f12);
    temp_f0 = (f32) arg3->unk6 * 0.00787402f;
    temp_f2 = (f32) arg3->unk7 * 0.00787402f;
    temp_f12 = (f32) arg3->unk8 * 0.00787402f;
    sp28.unkC.x = (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) + (arg0->unk6C.unk0.x * temp_f12);
    sp28.unkC.y = (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) + (arg0->unk6C.unk0.y * temp_f12);
    sp28.unkC.z = (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) + (arg0->unk6C.unk0.z * temp_f12);
    temp_f0 = (f32) arg3->unk9 * 0.00787402f;
    temp_f2 = (f32) arg3->unkA * 0.00787402f;
    temp_f12 = (f32) arg3->unkB * 0.00787402f;
    sp28.unk14.x = (arg0->unk6C.unk14.x * temp_f0) + (arg0->unk6C.unkC.x * temp_f2) + (arg0->unk6C.unk0.x * temp_f12);
    sp28.unk14.y = (arg0->unk6C.unk14.y * temp_f0) + (arg0->unk6C.unkC.y * temp_f2) + (arg0->unk6C.unk0.y * temp_f12);
    sp28.unk14.z = (arg0->unk6C.unk14.z * temp_f0) + (arg0->unk6C.unkC.z * temp_f2) + (arg0->unk6C.unk0.z * temp_f12);
    func_8005374C(arg1, arg4, (UnkStruct_80052C6C_2*) &sp4C, (UnkStruct_80052C6C_2*) &sp28);
}

void func_8005790C(s32 arg0, UnkStruct_80052E90_arg1_s* arg1) {
    UnkStruct_80192690* temp_s0;
    f32 temp_f14;
    f32 temp_f20;
    s32 sp2C0;
    s32 sp2BC;
    f32 temp_f2;
    UnkStruct_80052E90_arg1_s sp30;

    temp_s0 = &D_80192690[arg0];
    if (temp_s0->unk16B8 < 0) {
        sp2C0 = 7;
        temp_f20 = temp_s0->unk16B8 * -1.5f;
    } else {
        sp2C0 = 6;
        temp_f20 = temp_s0->unk16B8 * 1.5f;
    }
    if (temp_f20 > 1.0f) {
        temp_f20 = 1.0f;
    }
    func_80052E90(arg0, arg1, 0, 5);
    func_80052E90(arg0, &sp30, 0, sp2C0);
    func_80053A5C(arg1, temp_f20, arg1, &sp30);
    sp2BC = SysUtils_Round((f32) temp_s0->unkB60 * D_800D49E8) + 0x400;
    temp_f14 = SQ(temp_s0->unk6C) + SQ(temp_s0->unk74);
    temp_f20 = SQ(temp_s0->unk84) + SQ(temp_s0->unk8C);
    if ((temp_f14 != 0.0f) && (temp_f20 != 0.0f)) {
        temp_f14 = (SIN(sp2BC) / sqrtf(temp_f14));
        temp_f20 = COS(sp2BC) / sqrtf(temp_f20);
        arg1->unkFC.unkC.x = (temp_s0->unk6C * temp_f14) + (temp_f20 * temp_s0->unk84);
        arg1->unkFC.unkC.y = 0;
        arg1->unkFC.unkC.z = (temp_s0->unk74 * temp_f14) + (temp_f20 * temp_s0->unk8C);
        arg1->unkFC.unk14.x = 0;
        arg1->unkFC.unk14.y = 1.0f;
        arg1->unkFC.unk14.z = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80057B24.s")

void func_8005A1B4(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3) {
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f18;

    temp_f14 = arg1->x - arg0->x;
    temp_f16 = arg1->y - arg0->y;
    temp_f18 = arg1->z - arg0->z;
    temp_f12 = SQ(temp_f14) + SQ(temp_f16) + SQ(temp_f18);
    if (temp_f12 != 0.0f) {
        temp_f12 = arg2 / sqrtf(temp_f12);
        arg3->x = arg0->x + (temp_f12 * temp_f14);
        arg3->y = arg0->y + (temp_f12 * temp_f16);
        arg3->z = arg0->z + (temp_f12 * temp_f18);
    }
}

void func_8005A280(s32 arg0, UnkStruct_80052E90_arg1_s* arg1) {
    UnkStruct_80192690* temp_s0;
    UnkStruct_8005A280* var_v0;
    f32 temp_fv1_6;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;

    temp_s0 = &D_80192690[arg0];
    arg1->unk264.unk0.x = temp_s0->unk44.x;
    arg1->unk264.unk0.y = temp_s0->unk44.y;
    arg1->unk264.unk0.z = temp_s0->unk44.z;
    arg1->unk264.unkC.x = temp_s0->unk6C;
    arg1->unk264.unkC.y = temp_s0->unk70;
    arg1->unk264.unkC.z = temp_s0->unk74;

    // useless assignment of temp_fv1_6 to force f registers
    temp_fv1_6 = arg1->unk21C.unk14.x = arg1->unk264.unk14.x = temp_s0->unk78;
    arg1->unk240.unk14.x = arg1->unk21C.unk14.x + temp_s0->unk6C;

    // useless assignment of temp_fv1_6 to force f registers
    temp_fv1_6 = arg1->unk21C.unk14.y = arg1->unk264.unk14.y = temp_s0->unk7C;
    arg1->unk240.unk14.y = arg1->unk21C.unk14.y + temp_s0->unk70;

    arg1->unk21C.unk14.z = arg1->unk264.unk14.z = temp_s0->unk80;
    arg1->unk240.unk14.z = arg1->unk21C.unk14.z + temp_s0->unk74;

    arg1->unk21C.unkC.x = temp_s0->unk84;
    arg1->unk21C.unkC.y = temp_s0->unk88;
    arg1->unk21C.unkC.z = temp_s0->unk8C;

    temp_fv1_6 = (temp_s0->unk44.x + (13.0 * temp_s0->unk78) + (37.0 * temp_s0->unk6C));
    arg1->unk240.unk0.x = temp_fv1_6;
    arg1->unk21C.unk0.x = ((arg1->unk240.unkC.x = -temp_s0->unk6C) * 41.070999) + temp_fv1_6;
    temp_fv1_6 = (temp_s0->unk44.y + (13.0 * temp_s0->unk7C) + (37.0 * temp_s0->unk70));
    arg1->unk240.unk0.y = temp_fv1_6;
    arg1->unk21C.unk0.y = ((arg1->unk240.unkC.y = -temp_s0->unk70) * 41.070999) + temp_fv1_6;
    temp_fv1_6 = (temp_s0->unk44.z + (13.0 * temp_s0->unk80) + (37.0 * temp_s0->unk74));
    arg1->unk240.unk0.z = temp_fv1_6;
    arg1->unk21C.unk0.z = ((arg1->unk240.unkC.z = -temp_s0->unk74) * 41.070999) + temp_fv1_6;
    var_v0 = temp_s0->unk930;
    while ((u32) var_v0 >= (u32) temp_s0->unk660) {
        var_v0->unk10 = (var_v0->unk4 + (var_v0->unk1C * D_800D49F4));
        var_v0->unk14 = (var_v0->unk8 + (var_v0->unk20 * D_800D49F4) + D_800D4A00);
        if (var_v0->unk14 < -16000.0f) {
            var_v0->unk14 = -16000.0f;
        }
        var_v0->unk18 = var_v0->unkC + var_v0->unk24 * D_800D49F4;
        var_v0--;
    }
    temp_fs0 = temp_s0->unk698[0] - temp_s0->unk6C0[0];
    temp_fs1 = temp_s0->unk698[1] - temp_s0->unk6C0[1];
    temp_fs2 = temp_s0->unk698[2] - temp_s0->unk6C0[2];
    temp_fv1_6 = 14.483002 / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));

    temp_s0->unk698[0] = temp_s0->unk6C0[0] + (temp_fs0 *= temp_fv1_6);
    temp_s0->unk698[1] = temp_s0->unk6C0[1] + (temp_fs1 *= temp_fv1_6);
    temp_s0->unk698[2] = temp_s0->unk6C0[2] + (temp_fs2 *= temp_fv1_6);

    temp_fa1 = temp_s0->unk6C0[0] + (0.8662848f * temp_fs0);
    temp_ft4 = temp_s0->unk6C0[1] + (0.8662848f * temp_fs1);
    temp_ft5 = temp_s0->unk6C0[2] + (0.8662848f * temp_fs2);
    temp_fs0 = temp_s0->unk6E8 - temp_s0->unk828;
    temp_fs1 = temp_s0->unk6EC - temp_s0->unk82C;
    temp_fs2 = temp_s0->unk6F0 - temp_s0->unk830;

    temp_fv1_6 = 7.0 / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_fs0 *= temp_fv1_6;
    temp_fs1 *= temp_fv1_6;
    temp_fs2 *= temp_fv1_6;

    temp_s0->unk6E8 = temp_fs0 + temp_fa1;
    temp_s0->unk6EC = temp_fs1 + temp_ft4;
    temp_s0->unk6F0 = temp_fs2 + temp_ft5;
    temp_s0->unk828 = temp_fa1 - temp_fs0;
    temp_s0->unk82C = temp_ft4 - temp_fs1;
    temp_s0->unk830 = temp_ft5 - temp_fs2;
    temp_fs0 = ((0.5 * (temp_s0->unk788 + temp_s0->unk8C8)) - temp_s0->unk698[0]);
    temp_fs1 = ((0.5 * (temp_s0->unk78C + temp_s0->unk8CC)) - temp_s0->unk698[1]);
    temp_fs2 = ((0.5 * (temp_s0->unk790 + temp_s0->unk8D0)) - temp_s0->unk698[2]);
    temp_fv1_6 = (2.729486 / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2)));
    temp_fa1 = temp_s0->unk6C0[0] + (temp_fv1_6 * temp_fs0);
    temp_ft4 = temp_s0->unk6C0[1] + (temp_fv1_6 * temp_fs1);
    temp_ft5 = temp_s0->unk6C0[2] + (temp_fv1_6 * temp_fs2);
    temp_fs0 = temp_s0->unk788 - temp_s0->unk8C8;
    temp_fs1 = temp_s0->unk78C - temp_s0->unk8CC;
    temp_fs2 = temp_s0->unk790 - temp_s0->unk8D0;
    temp_fv1_6 = (3.133 / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2)));
    temp_fs0 *= temp_fv1_6;
    temp_fs1 *= temp_fv1_6;
    temp_fs2 *= temp_fv1_6;
    temp_s0->unk788 = temp_fs0 + temp_fa1;
    temp_s0->unk78C = temp_fs1 + temp_ft4;
    temp_s0->unk790 = temp_fs2 + temp_ft5;
    temp_s0->unk8C8 = temp_fa1 - temp_fs0;
    temp_s0->unk8CC = temp_ft4 - temp_fs1;
    temp_s0->unk8D0 = temp_ft5 - temp_fs2;
    temp_fs0 = temp_s0->unk710 - temp_s0->unk8C8;
    temp_fs1 = temp_s0->unk714 - temp_s0->unk8CC;
    temp_fs2 = temp_s0->unk718 - temp_s0->unk8D0;
    temp_fv1_6 = 2.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk710 += temp_fv1_6 * temp_fs0;
    temp_s0->unk714 += temp_fv1_6 * temp_fs1;
    temp_s0->unk718 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk738 - temp_s0->unk8C8;
    temp_fs1 = temp_s0->unk73C - temp_s0->unk8CC;
    temp_fs2 = temp_s0->unk740 - temp_s0->unk8D0;
    temp_fv1_6 = 4.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk738 += temp_fv1_6 * temp_fs0;
    temp_s0->unk73C += temp_fv1_6 * temp_fs1;
    temp_s0->unk740 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk760 - temp_s0->unk8C8;
    temp_fs1 = temp_s0->unk764 - temp_s0->unk8CC;
    temp_fs2 = temp_s0->unk768 - temp_s0->unk8D0;
    temp_fv1_6 = 6.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk760 += temp_fv1_6 * temp_fs0;
    temp_s0->unk764 += temp_fv1_6 * temp_fs1;
    temp_s0->unk768 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk850 - temp_s0->unk788;
    temp_fs1 = temp_s0->unk854 - temp_s0->unk78C;
    temp_fs2 = temp_s0->unk858 - temp_s0->unk790;
    temp_fv1_6 = 2.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk850 += temp_fv1_6 * temp_fs0;
    temp_s0->unk854 += temp_fv1_6 * temp_fs1;
    temp_s0->unk858 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk878 - temp_s0->unk788;
    temp_fs1 = temp_s0->unk87C - temp_s0->unk78C;
    temp_fs2 = temp_s0->unk880 - temp_s0->unk790;
    temp_fv1_6 = 4.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk878 += temp_fv1_6 * temp_fs0;
    temp_s0->unk87C += temp_fv1_6 * temp_fs1;
    temp_s0->unk880 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk8A0 - temp_s0->unk788;
    temp_fs1 = temp_s0->unk8A4 - temp_s0->unk78C;
    temp_fs2 = temp_s0->unk8A8 - temp_s0->unk790;
    temp_fv1_6 = 6.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk8A0 += temp_fv1_6 * temp_fs0;
    temp_s0->unk8A4 += temp_fv1_6 * temp_fs1;
    temp_s0->unk8A8 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk7B0 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk7B4 - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk7B8 - temp_s0->unk698[2];
    temp_fv1_6 = 2.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk7B0 += temp_fv1_6 * temp_fs0;
    temp_s0->unk7B4 += temp_fv1_6 * temp_fs1;
    temp_s0->unk7B8 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk7D8 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk7DC - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk7E0 - temp_s0->unk698[2];
    temp_fv1_6 = 4.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk7D8 += temp_fv1_6 * temp_fs0;
    temp_s0->unk7DC += temp_fv1_6 * temp_fs1;
    temp_s0->unk7E0 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk800 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk804 - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk808 - temp_s0->unk698[2];
    temp_fv1_6 = 6.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk800 += temp_fv1_6 * temp_fs0;
    temp_s0->unk804 += temp_fv1_6 * temp_fs1;
    temp_s0->unk808 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk8F0 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk8F4 - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk8F8 - temp_s0->unk698[2];
    temp_fv1_6 = 2.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk8F0 += temp_fv1_6 * temp_fs0;
    temp_s0->unk8F4 += temp_fv1_6 * temp_fs1;
    temp_s0->unk8F8 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk918 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk91C - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk920 - temp_s0->unk698[2];
    temp_fv1_6 = 4.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk918 += temp_fv1_6 * temp_fs0;
    temp_s0->unk91C += temp_fv1_6 * temp_fs1;
    temp_s0->unk920 += temp_fv1_6 * temp_fs2;
    temp_fs0 = temp_s0->unk940 - temp_s0->unk698[0];
    temp_fs1 = temp_s0->unk944 - temp_s0->unk698[1];
    temp_fs2 = temp_s0->unk948 - temp_s0->unk698[2];
    temp_fv1_6 = 6.0f / sqrtf(SQ(temp_fs0) + SQ(temp_fs1) + SQ(temp_fs2));
    temp_s0->unk940 += temp_fv1_6 * temp_fs0;
    temp_s0->unk944 += temp_fv1_6 * temp_fs1;
    temp_s0->unk948 += temp_fv1_6 * temp_fs2;
    func_8005A1B4((Vec3f*) &temp_s0->unk698[0], &temp_s0->unk670, 25.0f, &temp_s0->unk670);
    func_8005A1B4((Vec3f*) &temp_s0->unk6E8, (Vec3f*) &temp_s0->unk710, 8.543002f, (Vec3f*) &temp_s0->unk710);
    func_8005A1B4((Vec3f*) &temp_s0->unk828, (Vec3f*) &temp_s0->unk850, 8.543002f, (Vec3f*) &temp_s0->unk850);
    func_8005A1B4((Vec3f*) &temp_s0->unk710, (Vec3f*) &temp_s0->unk738, 10.457f, (Vec3f*) &temp_s0->unk738);
    func_8005A1B4((Vec3f*) &temp_s0->unk850, (Vec3f*) &temp_s0->unk878, 10.457f, (Vec3f*) &temp_s0->unk878);
    func_8005A1B4((Vec3f*) &temp_s0->unk738, (Vec3f*) &temp_s0->unk760, 3.5f, (Vec3f*) &temp_s0->unk760);
    func_8005A1B4((Vec3f*) &temp_s0->unk878, (Vec3f*) &temp_s0->unk8A0, 3.5f, (Vec3f*) &temp_s0->unk8A0);
    func_8005A1B4((Vec3f*) &temp_s0->unk788, (Vec3f*) &temp_s0->unk7B0, 17.263002f, (Vec3f*) &temp_s0->unk7B0);
    func_8005A1B4((Vec3f*) &temp_s0->unk8C8, (Vec3f*) &temp_s0->unk8F0, 17.263002f, (Vec3f*) &temp_s0->unk8F0);
    func_8005A1B4((Vec3f*) &temp_s0->unk7B0, (Vec3f*) &temp_s0->unk7D8, 18.861843f, (Vec3f*) &temp_s0->unk7D8);
    func_8005A1B4((Vec3f*) &temp_s0->unk8F0, (Vec3f*) &temp_s0->unk918, 18.861843f, (Vec3f*) &temp_s0->unk918);
    func_8005A1B4((Vec3f*) &temp_s0->unk7D8, (Vec3f*) &temp_s0->unk800, 10.0f, (Vec3f*) &temp_s0->unk800);
    func_8005A1B4((Vec3f*) &temp_s0->unk918, (Vec3f*) &temp_s0->unk940, 10.0f, (Vec3f*) &temp_s0->unk940);
    arg1->unkFC.unk0.x = temp_s0->unk698[0];
    arg1->unkFC.unk0.y = temp_s0->unk698[1];
    arg1->unkFC.unk0.z = temp_s0->unk698[2];
    arg1->unkD8.unk0.x = arg1->unk1F8.unk0.x = temp_s0->unk6C0[0];
    arg1->unkD8.unk0.y = arg1->unk1F8.unk0.y = temp_s0->unk6C0[1];
    arg1->unkD8.unk0.z = arg1->unk1F8.unk0.z = temp_s0->unk6C0[2];
    arg1->unk168.unk0.x = temp_s0->unk6E8;
    arg1->unk168.unk0.y = temp_s0->unk6EC;
    arg1->unk168.unk0.z = temp_s0->unk6F0;
    arg1->unk144.unk0.x = temp_s0->unk710;
    arg1->unk144.unk0.y = temp_s0->unk714;
    arg1->unk144.unk0.z = temp_s0->unk718;
    arg1->unk120.unk0.x = temp_s0->unk738;
    arg1->unk120.unk0.y = temp_s0->unk73C;
    arg1->unk120.unk0.z = temp_s0->unk740;
    arg1->unk48.unk0.x = temp_s0->unk788;
    arg1->unk48.unk0.y = temp_s0->unk78C;
    arg1->unk48.unk0.z = temp_s0->unk790;
    arg1->unk24.unk0.x = temp_s0->unk7B0;
    arg1->unk24.unk0.y = temp_s0->unk7B4;
    arg1->unk24.unk0.z = temp_s0->unk7B8;
    arg1->unk0.unk0.x = temp_s0->unk7D8;
    arg1->unk0.unk0.y = temp_s0->unk7DC;
    arg1->unk0.unk0.z = temp_s0->unk7E0;
    arg1->unk1D4.unk0.x = temp_s0->unk828;
    arg1->unk1D4.unk0.y = temp_s0->unk82C;
    arg1->unk1D4.unk0.z = temp_s0->unk830;
    arg1->unk1B0.unk0.x = temp_s0->unk850;
    arg1->unk1B0.unk0.y = temp_s0->unk854;
    arg1->unk1B0.unk0.z = temp_s0->unk858;
    arg1->unk18C.unk0.x = temp_s0->unk878;
    arg1->unk18C.unk0.y = temp_s0->unk87C;
    arg1->unk18C.unk0.z = temp_s0->unk880;
    arg1->unkB4.unk0.x = temp_s0->unk8C8;
    arg1->unkB4.unk0.y = temp_s0->unk8CC;
    arg1->unkB4.unk0.z = temp_s0->unk8D0;
    arg1->unk90.unk0.x = temp_s0->unk8F0;
    arg1->unk90.unk0.y = temp_s0->unk8F4;
    arg1->unk90.unk0.z = temp_s0->unk8F8;
    arg1->unk6C.unk0.x = temp_s0->unk918;
    arg1->unk6C.unk0.y = temp_s0->unk91C;
    arg1->unk6C.unk0.z = temp_s0->unk920;
    arg1->unkFC.unkC.x = temp_s0->unk670.x - temp_s0->unk698[0];
    arg1->unkFC.unkC.y = temp_s0->unk670.y - temp_s0->unk698[1];
    arg1->unkFC.unkC.z = temp_s0->unk670.z - temp_s0->unk698[2];
    arg1->unk1F8.unkC.x = temp_s0->unk698[0] - temp_s0->unk6C0[0];
    arg1->unk1F8.unkC.y = temp_s0->unk698[1] - temp_s0->unk6C0[1];
    arg1->unk1F8.unkC.z = temp_s0->unk698[2] - temp_s0->unk6C0[2];
    arg1->unkD8.unkC.x = (f32) ((0.5 * (f64) (temp_s0->unk788 + temp_s0->unk8C8)) - (f64) temp_s0->unk6C0[0]);
    arg1->unkD8.unkC.y = (f32) ((0.5 * (f64) (temp_s0->unk78C + temp_s0->unk8CC)) - (f64) temp_s0->unk6C0[1]);
    arg1->unkD8.unkC.z = (f32) ((0.5 * (f64) (temp_s0->unk790 + temp_s0->unk8D0)) - (f64) temp_s0->unk6C0[2]);
    arg1->unk168.unkC.x = temp_s0->unk710 - temp_s0->unk6E8;
    arg1->unk168.unkC.y = temp_s0->unk714 - temp_s0->unk6EC;
    arg1->unk168.unkC.z = temp_s0->unk718 - temp_s0->unk6F0;
    arg1->unk144.unkC.x = temp_s0->unk738 - temp_s0->unk710;
    arg1->unk144.unkC.y = temp_s0->unk73C - temp_s0->unk714;
    arg1->unk144.unkC.z = temp_s0->unk740 - temp_s0->unk718;
    arg1->unk120.unkC.x = temp_s0->unk760 - temp_s0->unk738;
    arg1->unk120.unkC.y = temp_s0->unk764 - temp_s0->unk73C;
    arg1->unk120.unkC.z = temp_s0->unk768 - temp_s0->unk740;
    arg1->unk48.unkC.x = temp_s0->unk7B0 - temp_s0->unk788;
    arg1->unk48.unkC.y = temp_s0->unk7B4 - temp_s0->unk78C;
    arg1->unk48.unkC.z = temp_s0->unk7B8 - temp_s0->unk790;
    arg1->unk24.unkC.x = temp_s0->unk7D8 - temp_s0->unk7B0;
    arg1->unk24.unkC.y = temp_s0->unk7DC - temp_s0->unk7B4;
    arg1->unk24.unkC.z = temp_s0->unk7E0 - temp_s0->unk7B8;
    arg1->unk0.unkC.x = temp_s0->unk800 - temp_s0->unk7D8;
    arg1->unk0.unkC.y = temp_s0->unk804 - temp_s0->unk7DC;
    arg1->unk0.unkC.z = temp_s0->unk808 - temp_s0->unk7E0;
    arg1->unk1D4.unkC.x = temp_s0->unk850 - temp_s0->unk828;
    arg1->unk1D4.unkC.y = temp_s0->unk854 - temp_s0->unk82C;
    arg1->unk1D4.unkC.z = temp_s0->unk858 - temp_s0->unk830;
    arg1->unk1B0.unkC.x = temp_s0->unk878 - temp_s0->unk850;
    arg1->unk1B0.unkC.y = temp_s0->unk87C - temp_s0->unk854;
    arg1->unk1B0.unkC.z = temp_s0->unk880 - temp_s0->unk858;
    arg1->unk18C.unkC.x = temp_s0->unk8A0 - temp_s0->unk878;
    arg1->unk18C.unkC.y = temp_s0->unk8A4 - temp_s0->unk87C;
    arg1->unk18C.unkC.z = temp_s0->unk8A8 - temp_s0->unk880;
    arg1->unkB4.unkC.x = temp_s0->unk8F0 - temp_s0->unk8C8;
    arg1->unkB4.unkC.y = temp_s0->unk8F4 - temp_s0->unk8CC;
    arg1->unkB4.unkC.z = temp_s0->unk8F8 - temp_s0->unk8D0;
    arg1->unk90.unkC.x = temp_s0->unk918 - temp_s0->unk8F0;
    arg1->unk90.unkC.y = temp_s0->unk91C - temp_s0->unk8F4;
    arg1->unk90.unkC.z = temp_s0->unk920 - temp_s0->unk8F8;
    arg1->unk6C.unkC.x = temp_s0->unk940 - temp_s0->unk918;
    arg1->unk6C.unkC.y = temp_s0->unk944 - temp_s0->unk91C;
    arg1->unk6C.unkC.z = temp_s0->unk948 - temp_s0->unk920;
    arg1->unkFC.unk14.x = temp_s0->unkD9C;
    arg1->unkFC.unk14.y = temp_s0->unkDA0;
    arg1->unkFC.unk14.z = temp_s0->unkDA4;
    arg1->unk1F8.unk14.x = temp_s0->unkE98;
    arg1->unk1F8.unk14.y = temp_s0->unkE9C;
    arg1->unk1F8.unk14.z = temp_s0->unkEA0;
    arg1->unkD8.unk14.x = temp_s0->unkD78;
    arg1->unkD8.unk14.y = temp_s0->unkD7C;
    arg1->unkD8.unk14.z = temp_s0->unkD80;
    arg1->unk168.unk14.x = temp_s0->unkE08;
    arg1->unk168.unk14.y = temp_s0->unkE0C;
    arg1->unk168.unk14.z = temp_s0->unkE10;
    arg1->unk1D4.unk14.x = temp_s0->unkE74;
    arg1->unk1D4.unk14.y = temp_s0->unkE78;
    arg1->unk1D4.unk14.z = temp_s0->unkE7C;
    arg1->unk144.unk14.x = temp_s0->unkDE4;
    arg1->unk144.unk14.y = temp_s0->unkDE8;
    arg1->unk144.unk14.z = temp_s0->unkDEC;
    arg1->unk1B0.unk14.x = temp_s0->unkE50;
    arg1->unk1B0.unk14.y = temp_s0->unkE54;
    arg1->unk1B0.unk14.z = temp_s0->unkE58;
    arg1->unk120.unk14.x = temp_s0->unkDC0;
    arg1->unk120.unk14.y = temp_s0->unkDC4;
    arg1->unk120.unk14.z = temp_s0->unkDC8;
    arg1->unk18C.unk14.x = temp_s0->unkE2C;
    arg1->unk18C.unk14.y = temp_s0->unkE30;
    arg1->unk18C.unk14.z = temp_s0->unkE34;
    arg1->unk48.unk14.x = temp_s0->unkCE8;
    arg1->unk48.unk14.y = temp_s0->unkCEC;
    arg1->unk48.unk14.z = temp_s0->unkCF0;
    arg1->unkB4.unk14.x = temp_s0->unkD54;
    arg1->unkB4.unk14.y = temp_s0->unkD58;
    arg1->unkB4.unk14.z = temp_s0->unkD5C;
    arg1->unk24.unk14.x = temp_s0->unkCC4;
    arg1->unk24.unk14.y = temp_s0->unkCC8;
    arg1->unk24.unk14.z = temp_s0->unkCCC;
    arg1->unk90.unk14.x = temp_s0->unkD30;
    arg1->unk90.unk14.y = temp_s0->unkD34;
    arg1->unk90.unk14.z = temp_s0->unkD38;
    arg1->unk0.unk14.x = temp_s0->unkCA0;
    arg1->unk0.unk14.y = temp_s0->unkCA4;
    arg1->unk0.unk14.z = temp_s0->unkCA8;
    arg1->unk6C.unk14.x = temp_s0->unkD0C;
    arg1->unk6C.unk14.y = temp_s0->unkD10;
    arg1->unk6C.unk14.z = temp_s0->unkD14;
    func_80052BB8(arg1);
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8005B510.s")

s32 func_8005CD24(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3) {
    switch (arg2) {
        case 22:
            if ((u16) D_80193D5C[arg0].unk0.h == 0) {
                func_80057B24(arg0, arg1);
                return 0;
            }
            func_8005790C(arg0, arg1);
            return 0;
        case 24:
            func_8005B510();
            return 0;
        case 23:
            func_8005A280(arg0, arg1);
            return 0;
        case 7:
            return func_80054E14(arg0, arg1, arg2, arg3);
        case 10:
            return func_800551EC(arg0, arg1, arg2, arg3, 1, 1);
        case 15:
            return func_80054130(arg0, arg1, 7, arg3, 1, 1);
        case 8:
            return func_80056670(arg0, arg1, arg2, arg3);
        case 2:
        case 3:
            return func_80054130(arg0, arg1, arg2, arg3, 0, 1);
        case 1:
        case 4:
        case 6:
            return func_80054130(arg0, arg1, arg2, arg3, 0, 0);
        case 25:
            if (D_80193D5C[arg0].unk0.h == 0) {
                func_80052E90(arg0, arg1, 0, 4);
                return 0;
            }
            func_80052E90(arg0, arg1, 0, 8);
            return 0;
        case 9:
            return func_80055C6C(arg0, arg1, arg2, arg3);
        case 17:
            return func_80055270(arg0, arg1, arg2, arg3);
        case 18:
        case 19:
        case 20:
        case 21:
            return func_80053268(arg0, arg1, arg2, arg3);
        default:
            return func_80052E90(arg0, arg1, arg2, arg3);
    }
}

void func_8005CEF8(UnkStruct_80052E90_arg1_s* arg0, UnkStruct_8005CEF8* arg1) {
    arg1->unk10 = arg0->unkFC.unk0.x + (25.0f * arg0->unkFC.unkC.x);
    arg1->unk14 = arg0->unkFC.unk0.y + (25.0f * arg0->unkFC.unkC.y);
    arg1->unk18 = arg0->unkFC.unk0.z + (25.0f * arg0->unkFC.unkC.z);
    arg1->unk38 = arg0->unkFC.unk0.x;
    arg1->unk3C = arg0->unkFC.unk0.y;
    arg1->unk40 = arg0->unkFC.unk0.z;
    arg1->unk60 = arg0->unkD8.unk0.x;
    arg1->unk64 = arg0->unkD8.unk0.y;
    arg1->unk68 = arg0->unkD8.unk0.z;
    arg1->unk88 = arg0->unk168.unk0.x;
    arg1->unk8C = arg0->unk168.unk0.y;
    arg1->unk90 = arg0->unk168.unk0.z;
    arg1->unkB0 = arg0->unk144.unk0.x;
    arg1->unkB4 = arg0->unk144.unk0.y;
    arg1->unkB8 = arg0->unk144.unk0.z;
    arg1->unkD8 = arg0->unk120.unk0.x;
    arg1->unkDC = arg0->unk120.unk0.y;
    arg1->unkE0 = arg0->unk120.unk0.z;
    arg1->unk100 = (f32) ((f64) arg0->unk120.unk0.x + (3.5 * (f64) arg0->unk120.unkC.x));
    arg1->unk104 = (f32) ((f64) arg0->unk120.unk0.y + (3.5 * (f64) arg0->unk120.unkC.y));
    arg1->unk108 = (f32) ((f64) arg0->unk120.unk0.z + (3.5 * (f64) arg0->unk120.unkC.z));
    arg1->unk128 = arg0->unk48.unk0.x;
    arg1->unk12C = arg0->unk48.unk0.y;
    arg1->unk130 = arg0->unk48.unk0.z;
    arg1->unk150 = arg0->unk24.unk0.x;
    arg1->unk154 = arg0->unk24.unk0.y;
    arg1->unk158 = arg0->unk24.unk0.z;
    arg1->unk178 = arg0->unk0.unk0.x;
    arg1->unk17C = arg0->unk0.unk0.y;
    arg1->unk180 = arg0->unk0.unk0.z;
    arg1->unk1A0 = arg0->unk0.unk0.x + (10.0f * arg0->unk0.unkC.x);
    arg1->unk1A4 = arg0->unk0.unk0.y + (10.0f * arg0->unk0.unkC.y);
    arg1->unk1A8 = arg0->unk0.unk0.z + (10.0f * arg0->unk0.unkC.z);
    arg1->unk1C8 = arg0->unk1D4.unk0.x;
    arg1->unk1CC = arg0->unk1D4.unk0.y;
    arg1->unk1D0 = arg0->unk1D4.unk0.z;
    arg1->unk1F0 = arg0->unk1B0.unk0.x;
    arg1->unk1F4 = arg0->unk1B0.unk0.y;
    arg1->unk1F8 = arg0->unk1B0.unk0.z;
    arg1->unk218 = arg0->unk18C.unk0.x;
    arg1->unk21C = arg0->unk18C.unk0.y;
    arg1->unk220 = arg0->unk18C.unk0.z;
    arg1->unk240 = (f32) ((f64) arg0->unk18C.unk0.x + (3.5 * (f64) arg0->unk18C.unkC.x));
    arg1->unk244 = (f32) ((f64) arg0->unk18C.unk0.y + (3.5 * (f64) arg0->unk18C.unkC.y));
    arg1->unk248 = (f32) ((f64) arg0->unk18C.unk0.z + (3.5 * (f64) arg0->unk18C.unkC.z));
    arg1->unk268 = arg0->unkB4.unk0.x;
    arg1->unk26C = arg0->unkB4.unk0.y;
    arg1->unk270 = arg0->unkB4.unk0.z;
    arg1->unk290 = arg0->unk90.unk0.x;
    arg1->unk294 = arg0->unk90.unk0.y;
    arg1->unk298 = arg0->unk90.unk0.z;
    arg1->unk2B8 = arg0->unk6C.unk0.x;
    arg1->unk2BC = arg0->unk6C.unk0.y;
    arg1->unk2C0 = arg0->unk6C.unk0.z;
    arg1->unk2E0 = arg0->unk6C.unk0.x + (10.0f * arg0->unk6C.unkC.x);
    arg1->unk2E4 = arg0->unk6C.unk0.y + (10.0f * arg0->unk6C.unkC.y);
    arg1->unk2E8 = arg0->unk6C.unk0.z + (10.0f * arg0->unk6C.unkC.z);
    arg1->unk308 = arg0->unk264.unk0.x;
    arg1->unk30C = arg0->unk264.unk0.y;
    arg1->unk310 = arg0->unk264.unk0.z;
    arg1->unk3D0 = (f32) (arg0->unk264.unk0.x + (10.0f * arg0->unk264.unkC.x));
    arg1->unk3D4 = (f32) (arg0->unk264.unk0.y + (10.0f * arg0->unk264.unkC.y));
    arg1->unk3D8 = (f32) (arg0->unk264.unk0.z + (10.0f * arg0->unk264.unkC.z));
    arg1->unk330 = arg0->unk240.unk0.x;
    arg1->unk334 = arg0->unk240.unk0.y;
    arg1->unk338 = arg0->unk240.unk0.z;
    arg1->unk358 = arg0->unk21C.unk0.x;
    arg1->unk35C = arg0->unk21C.unk0.y;
    arg1->unk360 = arg0->unk21C.unk0.z;
    arg1->unk380 = (f32) ((f64) arg0->unk21C.unk0.x + (1.867542 * (f64) arg0->unk240.unkC.x) +
                          (10.135 * (f64) arg0->unk21C.unkC.x));
    arg1->unk384 = (f32) ((f64) arg0->unk21C.unk0.y + (1.867542 * (f64) arg0->unk240.unkC.y) +
                          (10.135 * (f64) arg0->unk21C.unkC.y));
    arg1->unk388 = (f32) ((f64) arg0->unk21C.unk0.z + (1.867542 * (f64) arg0->unk240.unkC.z) +
                          (10.135 * (f64) arg0->unk21C.unkC.z));
    arg1->unk3A8 = (f32) (((f64) arg0->unk21C.unk0.x + (1.867542 * (f64) arg0->unk240.unkC.x)) -
                          (10.135 * (f64) arg0->unk21C.unkC.x));
    arg1->unk3AC = (f32) (((f64) arg0->unk21C.unk0.y + (1.867542 * (f64) arg0->unk240.unkC.y)) -
                          (10.135 * (f64) arg0->unk21C.unkC.y));
    arg1->unk3B0 = (f32) (((f64) arg0->unk21C.unk0.z + (1.867542 * (f64) arg0->unk240.unkC.z)) -
                          (10.135 * (f64) arg0->unk21C.unkC.z));
}

void func_8005D390(UnkStruct_80052E90_arg1_s* arg0, UnkStruct_8005CEF8* arg1) {
    arg1->unk4 = arg0->unkFC.unk0.x + (25.0f * arg0->unkFC.unkC.x);
    arg1->unk8 = arg0->unkFC.unk0.y + (25.0f * arg0->unkFC.unkC.y);
    arg1->unkC = arg0->unkFC.unk0.z + (25.0f * arg0->unkFC.unkC.z);
    arg1->unk2C = arg0->unkFC.unk0.x;
    arg1->unk30 = arg0->unkFC.unk0.y;
    arg1->unk34 = arg0->unkFC.unk0.z;
    arg1->unk54 = arg0->unkD8.unk0.x;
    arg1->unk58 = arg0->unkD8.unk0.y;
    arg1->unk5C = arg0->unkD8.unk0.z;
    arg1->unk7C = arg0->unk168.unk0.x;
    arg1->unk80 = arg0->unk168.unk0.y;
    arg1->unk84 = arg0->unk168.unk0.z;
    arg1->unkA4 = arg0->unk144.unk0.x;
    arg1->unkA8 = arg0->unk144.unk0.y;
    arg1->unkAC = arg0->unk144.unk0.z;
    arg1->unkCC = arg0->unk120.unk0.x;
    arg1->unkD0 = arg0->unk120.unk0.y;
    arg1->unkD4 = arg0->unk120.unk0.z;
    arg1->unkF4 = (f32) ((f64) arg0->unk120.unk0.x + (3.5 * (f64) arg0->unk120.unkC.x));
    arg1->unkF8 = (f32) ((f64) arg0->unk120.unk0.y + (3.5 * (f64) arg0->unk120.unkC.y));
    arg1->unkFC = (f32) ((f64) arg0->unk120.unk0.z + (3.5 * (f64) arg0->unk120.unkC.z));
    arg1->unk11C = arg0->unk48.unk0.x;
    arg1->unk120 = arg0->unk48.unk0.y;
    arg1->unk124 = arg0->unk48.unk0.z;
    arg1->unk144 = arg0->unk24.unk0.x;
    arg1->unk148 = arg0->unk24.unk0.y;
    arg1->unk14C = arg0->unk24.unk0.z;
    arg1->unk16C = arg0->unk0.unk0.x;
    arg1->unk170 = arg0->unk0.unk0.y;
    arg1->unk174 = arg0->unk0.unk0.z;
    arg1->unk194 = arg0->unk0.unk0.x + (10.0f * arg0->unk0.unkC.x);
    arg1->unk198 = arg0->unk0.unk0.y + (10.0f * arg0->unk0.unkC.y);
    arg1->unk19C = arg0->unk0.unk0.z + (10.0f * arg0->unk0.unkC.z);
    arg1->unk1BC = arg0->unk1D4.unk0.x;
    arg1->unk1C0 = arg0->unk1D4.unk0.y;
    arg1->unk1C4 = arg0->unk1D4.unk0.z;
    arg1->unk1E4 = arg0->unk1B0.unk0.x;
    arg1->unk1E8 = arg0->unk1B0.unk0.y;
    arg1->unk1EC = arg0->unk1B0.unk0.z;
    arg1->unk20C = arg0->unk18C.unk0.x;
    arg1->unk210 = arg0->unk18C.unk0.y;
    arg1->unk214 = arg0->unk18C.unk0.z;
    arg1->unk234 = (f32) ((f64) arg0->unk18C.unk0.x + (3.5 * (f64) arg0->unk18C.unkC.x));
    arg1->unk238 = (f32) ((f64) arg0->unk18C.unk0.y + (3.5 * (f64) arg0->unk18C.unkC.y));
    arg1->unk23C = (f32) ((f64) arg0->unk18C.unk0.z + (3.5 * (f64) arg0->unk18C.unkC.z));
    arg1->unk25C = arg0->unkB4.unk0.x;
    arg1->unk260 = arg0->unkB4.unk0.y;
    arg1->unk264 = arg0->unkB4.unk0.z;
    arg1->unk284 = arg0->unk90.unk0.x;
    arg1->unk288 = arg0->unk90.unk0.y;
    arg1->unk28C = arg0->unk90.unk0.z;
    arg1->unk2AC = arg0->unk6C.unk0.x;
    arg1->unk2B0 = arg0->unk6C.unk0.y;
    arg1->unk2B4 = arg0->unk6C.unk0.z;
    arg1->unk2D4 = arg0->unk6C.unk0.x + (10.0f * arg0->unk6C.unkC.x);
    arg1->unk2D8 = arg0->unk6C.unk0.y + (10.0f * arg0->unk6C.unkC.y);
    arg1->unk2DC = arg0->unk6C.unk0.z + (10.0f * arg0->unk6C.unkC.z);
    arg1->unk2FC = arg0->unk264.unk0.x;
    arg1->unk300 = arg0->unk264.unk0.y;
    arg1->unk304 = arg0->unk264.unk0.z;
    arg1->unk3C4 = arg0->unk264.unk0.x + (10.0f * arg0->unk264.unkC.x);
    arg1->unk3C8 = arg0->unk264.unk0.y + (10.0f * arg0->unk264.unkC.y);
    arg1->unk3CC = arg0->unk264.unk0.z + (10.0f * arg0->unk264.unkC.z);
    arg1->unk324 = arg0->unk240.unk0.x;
    arg1->unk328 = arg0->unk240.unk0.y;
    arg1->unk32C = arg0->unk240.unk0.z;
    arg1->unk34C = arg0->unk21C.unk0.x;
    arg1->unk350 = arg0->unk21C.unk0.y;
    arg1->unk354 = arg0->unk21C.unk0.z;
    arg1->unk374 = (f32) ((f64) arg0->unk21C.unk0.x + (1.867542 * (f64) arg0->unk240.unkC.x) +
                          (10.135 * (f64) arg0->unk21C.unkC.x));
    arg1->unk378 = (f32) ((f64) arg0->unk21C.unk0.y + (1.867542 * (f64) arg0->unk240.unkC.y) +
                          (10.135 * (f64) arg0->unk21C.unkC.y));
    arg1->unk37C = (f32) ((f64) arg0->unk21C.unk0.z + (1.867542 * (f64) arg0->unk240.unkC.z) +
                          (10.135 * (f64) arg0->unk21C.unkC.z));
    arg1->unk39C = (f32) (((f64) arg0->unk21C.unk0.x + (1.867542 * (f64) arg0->unk240.unkC.x)) -
                          (10.135 * (f64) arg0->unk21C.unkC.x));
    arg1->unk3A0 = (f32) (((f64) arg0->unk21C.unk0.y + (1.867542 * (f64) arg0->unk240.unkC.y)) -
                          (10.135 * (f64) arg0->unk21C.unkC.y));
    arg1->unk3A4 = (f32) (((f64) arg0->unk21C.unk0.z + (1.867542 * (f64) arg0->unk240.unkC.z)) -
                          (10.135 * (f64) arg0->unk21C.unkC.z));
}

void func_8005D828(UnkStruct_80052C6C_2* arg0, Mtx* arg1, s32 arg2) {
    s32 temp_ft3;   // sp4C
    f32 temp_f6_2;  // sp48
    f32 temp_f10_2; // sp44
    f32 temp_f0_2;
    s32 temp_ft0;
    f32 var_fv1;
    s32 temp_ft1;

    temp_ft0 = (s32) (arg0->unkC.x * 6553.6f);
    temp_ft3 = (s32) (arg0->unkC.y * 6553.6f);
    temp_ft1 = (s32) (arg0->unkC.z * 6553.6f);

    arg1->m[1][0] = (temp_ft0 & 0xFFFF0000) | ((u32) temp_ft3 >> 0x10);
    arg1->m[1][1] = temp_ft1 & 0xFFFF0000;
    arg1->m[3][0] = (temp_ft0 << 0x10) | (temp_ft3 & 0xFFFF);
    arg1->m[3][1] = temp_ft1 << 0x10;

    temp_f6_2 = (arg0->unk14.y * arg0->unkC.z) - (arg0->unk14.z * arg0->unkC.y);
    temp_f10_2 = (arg0->unk14.z * arg0->unkC.x) - (arg0->unk14.x * arg0->unkC.z);
    temp_f0_2 = (arg0->unk14.x * arg0->unkC.y) - (arg0->unk14.y * arg0->unkC.x);
    var_fv1 = SQ(temp_f6_2) + SQ(temp_f10_2) + SQ(temp_f0_2);
    if (var_fv1 == 0.0f) {
        return;
    }

    if (arg2 != 0) {
        var_fv1 = -6553.6f / sqrtf(var_fv1);
    } else {
        var_fv1 = 6553.6f / sqrtf(var_fv1);
    }
    temp_ft3 = temp_f10_2 * var_fv1;
    temp_ft0 = temp_f6_2 * var_fv1;
    temp_ft1 = temp_f0_2 * var_fv1;

    arg1->m[0][0] = (temp_ft0 & 0xFFFF0000) | ((u32) temp_ft3 >> 0x10);
    arg1->m[0][1] = temp_ft1 & 0xFFFF0000;
    arg1->m[2][0] = (temp_ft0 << 0x10) | (temp_ft3 & 0xFFFF);
    arg1->m[2][1] = temp_ft1 << 0x10;

    temp_ft0 = (s32) (arg0->unk14.x * 6553.6f);
    temp_ft3 = (s32) (arg0->unk14.y * 6553.6f);
    temp_ft1 = (s32) (arg0->unk14.z * 6553.6f);

    arg1->m[0][2] = (temp_ft0 & 0xFFFF0000) | ((u32) temp_ft3 >> 0x10);
    arg1->m[0][3] = temp_ft1 & 0xFFFF0000;
    arg1->m[2][2] = (temp_ft0 << 0x10) | (temp_ft3 & 0xFFFF);
    arg1->m[2][3] = temp_ft1 << 0x10;

    temp_ft0 = (s32) (arg0->unk0.x * 65536.0f);
    temp_ft3 = (s32) (arg0->unk0.y * 65536.0f);
    temp_ft1 = (s32) (arg0->unk0.z * 65536.0f);
    arg1->m[1][2] = (temp_ft0 & 0xFFFF0000) | ((u32) temp_ft3 >> 0x10);
    arg1->m[1][3] = (temp_ft1 & 0xFFFF0000) | 1;
    arg1->m[3][2] = (temp_ft0 << 0x10) | (temp_ft3 & 0xFFFF);
    arg1->m[3][3] = temp_ft1 << 0x10;
}

void func_8005DACC(s32 arg0, UnkStruct_80052E90_arg1_s* arg1) {
    func_8005D828(&arg1->unk264, &gGfxPool->unkE108[arg0], 0);
    func_8005D828(&arg1->unk240, &gGfxPool->unkE208[arg0], 0);
    func_8005D828(&arg1->unk21C, &gGfxPool->unkE308[arg0], 0);
    func_8005D828(&arg1->unkFC, &gGfxPool->unkE408[arg0], 0);
    func_8005D828(&arg1->unk1F8, &gGfxPool->unkE508[arg0], 0);
    func_8005D828(&arg1->unkD8, &gGfxPool->unkE608[arg0], 0);
    func_8005D828(&arg1->unk168, &gGfxPool->unkE708[arg0], 0);
    func_8005D828(&arg1->unk1D4, &gGfxPool->unkE808[arg0], 1);
    func_8005D828(&arg1->unk144, &gGfxPool->unkE908[arg0], 0);
    func_8005D828(&arg1->unk1B0, &gGfxPool->unkEA08[arg0], 1);
    func_8005D828(&arg1->unk120, &gGfxPool->unkEB08[arg0], 0);
    func_8005D828(&arg1->unk18C, &gGfxPool->unkEC08[arg0], 1);
    func_8005D828(&arg1->unk48, &gGfxPool->unkED08[arg0], 0);
    func_8005D828(&arg1->unkB4, &gGfxPool->unkEE08[arg0], 1);
    func_8005D828(&arg1->unk24, &gGfxPool->unkEF08[arg0], 0);
    func_8005D828(&arg1->unk90, &gGfxPool->unkF008[arg0], 1);
    func_8005D828(&arg1->unk0, &gGfxPool->unkF108[arg0], 0);
    func_8005D828(&arg1->unk6C, &gGfxPool->unkF208[arg0], 1);
}

s32 func_8005DD04(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_fs5;
    f32 sp68;
    f32 sp64;
    f32 sp60;

    temp_fs5 = gWaterLevel - 0x32;
    for (arg1 -= 10.0f; arg1 > temp_fs5; arg1 -= 16.0F) {
        if (func_8007F448(arg0, arg1, arg2, &sp68, &sp64, &sp60) != 0.0f) {
            return true;
        }
        if (func_8007FAE4(arg0, arg1, arg2, &sp68, &sp64, &sp60) != 0.0f) {
            return true;
        }
    }
    return false;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8005DE24.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800609EC.s")

#ifdef NON_MATCHING
// Register allocation differs: the original reads unkB56/unkB5E/unkB5F through a pointer kept in $a1
// (saved across SysUtils_Round); IDO folds this version's pointer into arg0. Control flow matches.
void func_80061184(UnkStruct_80192690* arg0) {
    RiderButtons* btn;
    OSContPad* pad;
    s32 d;
    u16 dirs;

    arg0->unkB58 = (arg0->unkB56 ^ arg0->unkB50.button) & arg0->unkB50.button;
    arg0->unkB5A = (arg0->unkB56 ^ arg0->unkB50.button) & arg0->unkB56;
    arg0->unkB5C = arg0->unkB56;
    arg0->unkB56 = arg0->unkB50.button;
    arg0->unkB5E = arg0->unkB50.stick_x;
    arg0->unkB5F = arg0->unkB50.stick_y;
    d = arg0->unkB50.stick_x - arg0->unkB60;
    if (d < -D_800D49DC) {
        d = -D_800D49DC;
    } else if (D_800D49DC < d) {
        d = D_800D49DC;
    }
    arg0->unkB60 += d;
    btn = (RiderButtons*) &arg0->unkB56;
    arg0->unkC66 = btn->held & 0xA000;
    if ((arg0->unkC54 == 23) || (arg0->unk1608 != 0) || ((arg0->unkC54 == 7) && (arg0->unkC58 < 56)) ||
        ((arg0->unkC54 > 0) && (arg0->unkC54 < 7)) || (gRiderGameModes == PAUSE_MODE) ||
        (gRiderGameModes == UNACTIVE_MODE)) {
        btn->stickX = btn->stickY = 0;
        arg0->unkC66 = 0;
        arg0->unk15DC = 0;
        if ((arg0->unkC54 == 7) || ((arg0->unkC54 == 23) && (RIDER_PARTS(arg0)[0].unk4.y < 0.0f))) {
            arg0->unk1444 = 1;
        } else {
            arg0->unk1444 = 0;
        }
    } else {
        arg0->unk15DC = 1;
        arg0->unk1444 = 0;
        if (arg0->unkC54 == 24) {
            arg0->unk1578 *= 0.3f;
        } else if ((arg0->unkC54 == 9) || (arg0->unkC54 == 17)) {
            arg0->unk1578 *= 0.9f;
        } else if (arg0->unkC54 == 8) {
            btn->stickX = SysUtils_Round(btn->stickX * 0.8f);
            arg0->unk1578 *= 0.85f;
        }
    }
    if (btn->stickX < -14) {
        arg0->unk159C = gFrameCounter;
    } else if (btn->stickX >= 15) {
        arg0->unk15A0 = gFrameCounter;
    }
    if (btn->stickY < -14) {
        arg0->unk15A8 = gFrameCounter;
        if (!(btn->held & 0xA000)) {
            arg0->unk1600 = 0;
            arg0->unk15F0 = gFrameCounter;
        }
    } else if (btn->stickY >= 15) {
        arg0->unk15A4 = gFrameCounter;
    }
    pad = &arg0->unkB50;
    dirs = 0;
    if (pad->stick_x < -64) {
        arg0->unk1600 = 1;
        dirs = 0x200;
    }
    if (pad->stick_x > 64) {
        dirs |= 0x100;
        arg0->unk1600 = 1;
    }
    if (pad->stick_y > 64) {
        dirs |= 0x800;
    }
    if (pad->stick_y < -64) {
        dirs |= 0x400;
    }
    arg0->unk15F4 = (arg0->unk15F6 ^ dirs) & dirs;
    arg0->unk15F6 = dirs;
    if ((arg0->unkC54 == 22) || (arg0->unkC54 == 15)) {
        if ((arg0->unkC66 == 0) && (arg0->unk15F4 != 0)) {
            if (arg0->unk15F8 == 0) {
                arg0->unk15F8++;
            } else {
                switch (arg0->unk15FC) {
                    case 0x100:
                        if (arg0->unk15F4 & 0x800) {
                            arg0->unk15F8++;
                        } else {
                            arg0->unk15F8 = 0;
                        }
                        break;
                    case 0x200:
                        if (arg0->unk15F4 & 0x400) {
                            arg0->unk15F8++;
                        } else {
                            arg0->unk15F8 = 0;
                        }
                        break;
                    case 0x400:
                        if (arg0->unk15F4 & 0x100) {
                            arg0->unk15F8++;
                        } else {
                            arg0->unk15F8 = 0;
                        }
                        break;
                    case 0x800:
                        if (arg0->unk15F4 & 0x200) {
                            arg0->unk15F8++;
                        } else {
                            arg0->unk15F8 = 0;
                        }
                        break;
                }
            }
            if (arg0->unk15FA == 0) {
                arg0->unk15FA++;
            } else {
                switch (arg0->unk15FC) {
                    case 0x100:
                        if (arg0->unk15F4 & 0x400) {
                            arg0->unk15FA++;
                        } else {
                            arg0->unk15FA = 0;
                        }
                        break;
                    case 0x200:
                        if (arg0->unk15F4 & 0x800) {
                            arg0->unk15FA++;
                        } else {
                            arg0->unk15FA = 0;
                        }
                        break;
                    case 0x400:
                        if (arg0->unk15F4 & 0x200) {
                            arg0->unk15FA++;
                        } else {
                            arg0->unk15FA = 0;
                        }
                        break;
                    case 0x800:
                        if (arg0->unk15F4 & 0x100) {
                            arg0->unk15FA++;
                        } else {
                            arg0->unk15FA = 0;
                        }
                        break;
                }
            }
            arg0->unk15FC = arg0->unk15F4;
            arg0->unk15FE = 0;
        } else {
            arg0->unk15FE++;
            if (arg0->unk15FE >= 5) {
                arg0->unk15FA = 0;
                arg0->unk15F8 = 0;
            }
        }
    } else {
        arg0->unk15FA = 0;
        arg0->unk15F8 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80061184.s")
#endif

s32 func_80061644(f32 arg0) {
    s32 var_v1;

    arg0 /= 70.0f;
    var_v1 = ((SQ(arg0) * 70.0f) + 0.5);
    if (var_v1 >= 0x47) {
        var_v1 = 0x46;
    }
    if (arg0 < 0.0f) {
        return -var_v1;
    }
    return var_v1;
}

void func_800616B0(s32 arg0) {
    func_80080400();
    func_80061184(&D_80192690[arg0]);
}

void func_80061708(s32 arg0, s32 arg1) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    f32 scale;
    f32 x;
    f32 y;
    f32 sq;
    f32 len;

    if (rider->unk1446 < 0) {
        func_800616B0(arg0);
        return;
    }
    if (arg1 < D_80154344) {
        rider->unkB50 = gControllers[D_80154330[arg1]];
    } else {
        rider->unkB50.button = 0;
        rider->unkB50.stick_x = rider->unkB50.stick_y = rider->unkB50.button;
    }
    rider->unk1578 = 1.0f;
    func_80061184(rider);
    x = (rider->unkB5E < 0) ? -rider->unkB5E : rider->unkB5E;
    y = (rider->unkB5F < 0) ? -rider->unkB5F : rider->unkB5F;
    sq = SQ(x) + SQ(y);
    if (sq != 0.0f) {
        len = sqrtf(sq);
        if (y < x) {
            scale = 70.0f / ((70.0f / len) * x);
        } else {
            scale = 70.0f / ((70.0f / len) * y);
        }
        rider->unkB5E = func_80061644(rider->unkB5E * scale);
        rider->unkB5F = func_80061644(rider->unkB5F * scale);
    }
}

void func_800618F4(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3) {
    RiderPart* part;
    UnkStruct_8004B0F8_1* point;
    UnkStruct_80192690_C88(*row)[18];

    for (part = &RIDER_PARTS(arg0)[24]; part >= RIDER_PARTS(arg0); part--) {
        part->unk4.x += arg1;
        part->unk10.x += arg1;
        part->unk4.y += arg2;
        part->unk10.y += arg2;
        part->unk4.z += arg3;
        part->unk10.z += arg3;
    }
    for (point = &arg0->unk90[arg0->unk28]; point >= arg0->unk90; point--) {
        point->unk0 += arg1;
        point->unk4 += arg2;
        point->unk8 += arg3;
    }
    arg0->unkC14 += arg1;
    arg0->unkC18 += arg2;
    arg0->unkC1C += arg3;
    arg0->unk44.x += arg1;
    arg0->unk44.y += arg2;
    arg0->unk44.z += arg3;
    arg0->unkBE4 += arg1;
    arg0->unkBE8 += arg2;
    arg0->unkBEC += arg3;
    // The entries are moved in this order in the original.
    for (row = RIDER_C88(arg0); row <= &RIDER_C88(arg0)[2]; row++) {
        (*row)[17].unk0.x += arg1;
        (*row)[17].unk0.y += arg2;
        (*row)[17].unk0.z += arg3;
        (*row)[16].unk0.x += arg1;
        (*row)[16].unk0.y += arg2;
        (*row)[16].unk0.z += arg3;
        (*row)[15].unk0.x += arg1;
        (*row)[15].unk0.y += arg2;
        (*row)[15].unk0.z += arg3;
        (*row)[7].unk0.x += arg1;
        (*row)[7].unk0.y += arg2;
        (*row)[7].unk0.z += arg3;
        (*row)[14].unk0.x += arg1;
        (*row)[14].unk0.y += arg2;
        (*row)[14].unk0.z += arg3;
        (*row)[6].unk0.x += arg1;
        (*row)[6].unk0.y += arg2;
        (*row)[6].unk0.z += arg3;
        (*row)[10].unk0.x += arg1;
        (*row)[10].unk0.y += arg2;
        (*row)[10].unk0.z += arg3;
        (*row)[13].unk0.x += arg1;
        (*row)[13].unk0.y += arg2;
        (*row)[13].unk0.z += arg3;
        (*row)[9].unk0.x += arg1;
        (*row)[9].unk0.y += arg2;
        (*row)[9].unk0.z += arg3;
        (*row)[12].unk0.x += arg1;
        (*row)[12].unk0.y += arg2;
        (*row)[12].unk0.z += arg3;
        (*row)[8].unk0.x += arg1;
        (*row)[8].unk0.y += arg2;
        (*row)[8].unk0.z += arg3;
        (*row)[11].unk0.x += arg1;
        (*row)[11].unk0.y += arg2;
        (*row)[11].unk0.z += arg3;
        (*row)[2].unk0.x += arg1;
        (*row)[2].unk0.y += arg2;
        (*row)[2].unk0.z += arg3;
        (*row)[5].unk0.x += arg1;
        (*row)[5].unk0.y += arg2;
        (*row)[5].unk0.z += arg3;
        (*row)[1].unk0.x += arg1;
        (*row)[1].unk0.y += arg2;
        (*row)[1].unk0.z += arg3;
        (*row)[4].unk0.x += arg1;
        (*row)[4].unk0.y += arg2;
        (*row)[4].unk0.z += arg3;
        (*row)[0].unk0.x += arg1;
        (*row)[0].unk0.y += arg2;
        (*row)[0].unk0.z += arg3;
        (*row)[3].unk0.x += arg1;
        (*row)[3].unk0.y += arg2;
        (*row)[3].unk0.z += arg3;
    }
}

void func_80061FEC(void) {
    UnkStruct_80192690* a;
    UnkStruct_80192690* b;
    RiderSphere* sa;
    RiderSphere* sb;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distSq;
    f32 dist;
    f32 inv;
    f32 closing;
    f32 push;

    for (a = D_80192690; a <= &D_80192690[gRiders - 2]; a++) {
        for (b = a + 1; b <= &D_80192690[gRiders - 1]; b++) {
            dx = a->unk44.x - b->unk44.x;
            dz = a->unk44.z - b->unk44.z;
            if (SQ(dx) + SQ(dz) > 6084.0f) {
                continue;
            }
            for (sa = RIDER_SPHERES(a); sa <= &RIDER_SPHERES(a)[3]; sa++) {
                for (sb = RIDER_SPHERES(b); sb <= &RIDER_SPHERES(b)[3]; sb++) {
                    dx = sa->pos.x - sb->pos.x;
                    dz = sa->pos.z - sb->pos.z;
                    distSq = SQ(dx) + SQ(dz);
                    if (distSq >= 576.0f) {
                        continue;
                    }
                    dy = sa->pos.y - sb->pos.y;
                    distSq += SQ(dy);
                    if (distSq >= 576.0f) {
                        continue;
                    }
                    dist = sqrtf(distSq);
                    inv = 1.0f / dist;
                    dx *= inv;
                    dy *= inv;
                    dz *= inv;
                    closing = ((sb->vel.x - sa->vel.x) * dx) + (dy * (sb->vel.y - sa->vel.y)) + (dz * (sb->vel.z - sa->vel.z));
                    if (a->unkC40 < closing) {
                        a->unkC40 = closing;
                        a->unk15B4 = dx;
                        a->unk15B8 = dy;
                        a->unk15BC = dz;
                    }
                    if (b->unkC40 < closing) {
                        b->unkC40 = closing;
                        b->unk15B4 = -dx;
                        b->unk15B8 = -dy;
                        b->unk15BC = -dz;
                    }
                    push = (24.0f - dist) * 0.5f;
                    dx *= push;
                    dy *= push;
                    dz *= push;
                    sa->unk18->unkC += dx;
                    sa->unk18->unk10 += dy;
                    sa->unk18->unk14 += dz;
                    sa->unk1C->unkC += dx;
                    sa->unk1C->unk10 += dy;
                    sa->unk1C->unk14 += dz;
                    sa->unk20->unkC += dx;
                    sa->unk20->unk10 += dy;
                    sa->unk20->unk14 += dz;
                    sb->unk18->unkC -= dx;
                    sb->unk18->unk10 -= dy;
                    sb->unk18->unk14 -= dz;
                    sb->unk1C->unkC -= dx;
                    sb->unk1C->unk10 -= dy;
                    sb->unk1C->unk14 -= dz;
                    sb->unk20->unkC -= dx;
                    sb->unk20->unk10 -= dy;
                    sb->unk20->unk14 -= dz;
                    func_8006243C(a, dx, dy, dz);
                    func_8006243C(b, -dx, -dy, -dz);
                }
            }
        }
    }
}

void func_8006243C(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3) {
    UnkStruct_8004B0F8_1* var_v0;

    for (var_v0 = &arg0->unk90[0]; var_v0 < &arg0->unk90[0xC]; var_v0++) {
        var_v0->unk0 += arg1;
        var_v0->unk4 += arg2;
        var_v0->unk8 += arg3;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800624CC.s")

void func_80062918(Vec3f* arg0) {
    f32 temp_f20;
    s32 i;

    temp_f20 = 0.5f / ((D_800D4A04 * 17.0f) + 1.0f);
    for (i = 0; i < 22; i++) {
        arg0[i + 220].x = sqrtf(D_800D4A68[i]) * temp_f20;
    }
}

#ifdef NON_MATCHING
// One difference: the original loads 11.0f again for t = unkB70 / 11.0f (into $f4) instead of
// reusing the copy in $f18, so this version is 0x10 bytes shorter. The rest matches.
void func_800629A8(UnkStruct_80192690* arg0) {
    f32 t;
    f32 v;
    s32 i;

    if (arg0->unk16CE != 0) {
        arg0->unk4 = D_800D9440[arg0->unkB64];
        arg0->unk8 = D_800D9450[arg0->unkB64];
        arg0->unk15E8 = D_800D9570[arg0->unkB64];
    } else {
        arg0->unk4 = D_800D9420[arg0->unkB64];
        arg0->unk8 = D_800D9430[arg0->unkB64];
        arg0->unk15E8 = LERP(D_800D9550[arg0->unkB64], D_800D9560[arg0->unkB64], arg0->unkB74  / 11.0f);
    }
    arg0->unk14 = arg0->unk15E8;
    arg0->unk15D0 = D_800D9490[arg0->unkB68];
    arg0->unk1568 = D_800D93D0[arg0->unkB64];
    arg0->unk156C = D_800D93E0[arg0->unkB64];
    arg0->unk1570 = D_800D93F0[arg0->unkB64];
    arg0->unk1580 = D_800D9460[arg0->unkB64];
    arg0->unk1584 = D_800D9470[arg0->unkB64];
    if (arg0->unk16CE != 0) {
        arg0->unkBB8 = D_800D94C0[arg0->unkB64];
        arg0->unk1590 = arg0->unk1594 = D_800D95F0[arg0->unkB64];
        arg0->unk158C = D_800D9620[arg0->unkB64];
    } else {
        arg0->unkBB8 = LERP(D_800D94A0[arg0->unkB64], D_800D94B0[arg0->unkB64], arg0->unkB6C  / 11.0f);
        arg0->unk1590 = arg0->unk1594 = LERP(D_800D95D0[arg0->unkB64], D_800D95E0[arg0->unkB64], arg0->unkB74  / 11.0f);
        arg0->unk158C = LERP(D_800D9600[arg0->unkB64], D_800D9610[arg0->unkB64], arg0->unkB74  / 11.0f);
    }
    t = arg0->unkB70 / 11.0f;
    if (arg0->unk16CE != 0) {
        arg0->unkBC8 = D_800D94F0[arg0->unkB64];
        arg0->unkBCC = D_800D9520[arg0->unkB64];
        v = D_800D9540[arg0->unkB64];
        arg0->unkBD0 = ((v / 1.8f) / 5.0f) + ((((100.0f - v) / 1.8f) / 5.0f) * t);
        arg0->unkBC4 = D_800D95A0[arg0->unkB64];
        arg0->unkBBC = D_800D95C0[arg0->unkB64] + arg0->unkBC4;
    } else {
        arg0->unkBC8 = LERP(D_800D94D0[arg0->unkB64], D_800D94E0[arg0->unkB64], t);
        arg0->unkBCC = LERP(D_800D9500[arg0->unkB64], D_800D9510[arg0->unkB64], t);
        v = D_800D9530[arg0->unkB64];
        arg0->unkBD0 = ((v / 1.8f) / 5.0f) + ((((100.0f - v) / 1.8f) / 5.0f) * t);
        arg0->unkBC4 = LERP(D_800D9580[arg0->unkB64], D_800D9590[arg0->unkB64], arg0->unkB74  / 11.0f);
        arg0->unkBBC = D_800D95B0[arg0->unkB64] + arg0->unkBC4;
    }
    arg0->unkBC0 = arg0->unkBC4 * arg0->unkBC8;
    if (arg0->unkBD0 != 0.0f) {
        arg0->unkBD4 = 2048.0f / arg0->unkBD0;
        arg0->unkBD8 = (1.0f - arg0->unkBC8) * 0.5f;
    }
    v = 11.111112f - arg0->unkBD0;
    if (v != 0.0f) {
        arg0->unkBE0 = 1.0f - arg0->unkBCC;
        arg0->unkBDC = 1024.0f / v;
    }
    func_8004AC80((struct UnkStruct_8004B0F8*) arg0, arg0->unk44.x, arg0->unk44.y, arg0->unk44.z);
    for (i = 11; i >= 0; i--) {
        arg0->unk630[i] = arg0->unk90[i].unk18;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800629A8.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80062E50.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8006390C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80063C88.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80064C0C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80065C18.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800665B0.s")

Gfx* func_8006719C(Gfx* gdl, s32 arg1) {
    gSPClearGeometryMode(gdl++, G_CULL_FRONT);
    gSPSetGeometryMode(gdl++, G_CULL_BACK);
    if ((D_801C2938[arg1].unk338 == 0) && (gDifficulty == DIFFICULTY_EXPERT)) {
        guLookAtReflect(&gGfxPool->unkE108[arg1], (LookAt*) &gGfxPool->unkE208[arg1], gCameraPerspective[D_80223930].unk4C,
                        gCameraPerspective[D_80223930].unk50, gCameraPerspective[D_80223930].unk54,
                        gCameraPerspective[D_80223930].unk7C, gCameraPerspective[D_80223930].unk80,
                        gCameraPerspective[D_80223930].unk84, gCameraPerspective[D_80223930].unk70,
                        gCameraPerspective[D_80223930].unk74, gCameraPerspective[D_80223930].unk78);
        gSPSetGeometryMode(gdl++, G_TEXTURE_GEN);
        gSPLookAt(gdl++, &((GfxPool*) D_3000000)->unkE208[arg1]);
        gSPTexture(gdl++, D_800D4934, D_800D4934, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gdl++);
        gDPSetTextureLUT(gdl++, G_TT_NONE);
        gDPSetEnvColor(gdl++, 255, 255, 255, D_800D492C);
        gDPLoadMultiBlock(gdl++, D_800D48D0[D_800D4930], 0, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP, G_TX_WRAP, 5,
                          5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetCombineLERP(gdl++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, SHADE);
        gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE308[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPDisplayList(gdl++, D_80227A60[arg1].unk0[2]);
        gSPClearGeometryMode(gdl++, G_TEXTURE_GEN);
        gDPPipeSync(gdl++);
        gDPSetCombineMode(gdl++, G_CC_MODULATERGBDECALA, G_CC_PASS2);
        gDPSetTextureLUT(gdl++, G_TT_RGBA16);
    }
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE408[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[3]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE508[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[4]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE608[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[5]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEB08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[8]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE708[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[6]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE908[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[7]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkED08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[9]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEF08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[10]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF108[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[11]);
    gSPClearGeometryMode(gdl++, G_CULL_BACK);
    gSPSetGeometryMode(gdl++, G_CULL_FRONT);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEC08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[8]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE808[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[6]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEA08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[7]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEE08[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[9]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF008[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[10]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF208[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[11]);
    return gdl;
}

Gfx* func_80067810(Gfx* gdl, s32 arg1, s32 arg2) {
    gSPClearGeometryMode(gdl++, G_CULL_FRONT);
    gSPSetGeometryMode(gdl++, G_CULL_BACK);
    if (D_80193D5C[arg2].unk0.h == 0) {
        gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE108[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPDisplayList(gdl++, D_80227A60[arg1].unk0[0]);
        gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE208[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPDisplayList(gdl++, D_80227A60[arg1].unk0[1]);
        gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE308[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
        gSPDisplayList(gdl++, D_80227A60[arg1].unk0[2]);
    }
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE408[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[3]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE508[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[4]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE608[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[5]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE708[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[6]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE908[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[7]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEB08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[8]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkED08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[9]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEF08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[10]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF108[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[11]);
    gSPClearGeometryMode(gdl++, G_CULL_BACK);
    gSPSetGeometryMode(gdl++, G_CULL_FRONT);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE808[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[6]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEA08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[7]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEC08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[8]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkEE08[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[9]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF008[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[10]);
    gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF208[arg2], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].unk0[11]);
    return gdl;
}

Gfx* func_80067BFC(Gfx* gdl, s32 arg1, s32 arg2) {
    gdl = func_80067810(gdl, arg1, arg2);
    gSPEndDisplayList(gdl++);
    if (D_80193D5C[arg2].unk0.h != 0) {
        gdl += 6;
    }
    return gdl;
}

void func_80067C6C(void) {
    Gfx* gdl = (Gfx*) &D_8011EDE0;
    s32 i;
    s32 j;

    if ((D_801CE638 == 0) || ((D_801CE638 == 8) && (gCourseID != SUNNY_BEACH))) {
        gdl = func_80067BFC(gdl, 0, D_800D48DC);
        gdl = func_80067BFC(gdl, 1, D_800D48E0);
        return;
    }
    if (D_801CE64C != 2) {
        if ((gPlayers == ONE_PLAYER) || ((D_801CE638 == 8) && (gCourseID == SUNNY_BEACH))) {
            j = 1;
            for (i = 0; i < gRiders; i++) {
                if (i == D_800D48DC) {
                    gdl = func_80067BFC(gdl, 0, i);
                    gdl = func_80067BFC(gdl, 0, i);
                } else {
                    gdl = func_80067BFC(gdl, j, i);
                    gdl = func_80067BFC(gdl, j + 1, i);
                    j += 2;
                }
            }
        } else {
            gdl = func_80067BFC(gdl, 0, D_800D48DC);
            gdl = func_80067BFC(gdl, 1, D_800D48E0);
            gdl = func_80067BFC(gdl, 2, D_800D48DC);
            gdl = func_80067BFC(gdl, 3, D_800D48E0);
            gdl = func_80067BFC(gdl, 4, D_800D48DC);
            gdl = func_80067BFC(gdl, 5, D_800D48E0);
        }
    }
}

#ifdef NON_MATCHING
// After the rider loop the original keeps the constant 1 in $s2 and stores D_800D496C through
// an address in $v1; this version uses $v1 = 1 and a %lo store. The rest matches.
void func_80067E40(void) {
    u8 sp50[0x48];
    camera_unk_1* cam;
    s32 i;

    if ((D_801CE638 == 0) && (D_800DAB60 != 0)) {
        D_800D4928 ^= 1;
    }
    for (i = gRiders - 1; i >= 0; i--) {
        if ((D_801CE638 == 0) || (D_801CE638 == 8)) {
            D_80192690[i].unk16CE = 1;
        } else if (i == D_800D48DC) {
            if (((D_800D4964 != 0) || (gRiderGameModes == AI_MODE)) && (D_801CE638 != 4)) {
                D_80192690[i].unk16CE = 1;
            } else {
                D_80192690[i].unk16CE = 0;
            }
        } else if (i == D_800D48E0) {
            if ((gRiderGameModes == AI_MODE) || (gPlayers == ONE_PLAYER)) {
                D_80192690[i].unk16CE = 1;
            } else {
                D_80192690[i].unk16CE = 0;
            }
        } else {
            D_80192690[i].unk16CE = 1;
        }
        func_8006AC84(i, sp50);
        func_8006390C(i, sp50);
    }
    if ((gCourseID < 9) && (D_801CE638 != 21)) {
        D_800D496C = 1;
        D_800D4974 = 1;
    } else {
        D_800D496C = 0;
        D_800D4974 = 0;
    }
    if (D_801CE638 == 4) {
        D_800D4978 = 0;
    } else {
        D_800D4978 = 1;
    }
    func_80067C6C();
    cam = &gCameraPerspective[D_80223930];
    cam->unk4 = D_80192690[D_800D48DC].unk44.x;
    *(f32*) &cam->unk8 = D_80192690[D_800D48DC].unk44.y;
    cam->unkC = D_80192690[D_800D48DC].unk44.z;
    cam->unk10 = D_80192690[D_800D48DC].unk50;
    cam->unk14 = D_80192690[D_800D48DC].unk54;
    cam->unk18 = D_80192690[D_800D48DC].unk58;
    cam->unk1C = D_80192690[D_800D48DC].unk6C;
    cam->unk20 = D_80192690[D_800D48DC].unk70;
    cam->unk24 = D_80192690[D_800D48DC].unk74;
    cam->unk28 = D_80192690[D_800D48DC].unk78;
    cam->unk2C = D_80192690[D_800D48DC].unk7C;
    cam->unk30 = D_80192690[D_800D48DC].unk80;
    cam->unk34 = D_80192690[D_800D48DC].unk84;
    cam->unk38 = D_80192690[D_800D48DC].unk88;
    cam->unk3C = D_80192690[D_800D48DC].unk8C;
    cam = &gCameraPerspective[D_80223934];
    cam->unk4 = D_80192690[D_800D48E0].unk44.x;
    *(f32*) &cam->unk8 = D_80192690[D_800D48E0].unk44.y;
    cam->unkC = D_80192690[D_800D48E0].unk44.z;
    cam->unk10 = D_80192690[D_800D48E0].unk50;
    cam->unk14 = D_80192690[D_800D48E0].unk54;
    cam->unk18 = D_80192690[D_800D48E0].unk58;
    cam->unk1C = D_80192690[D_800D48E0].unk6C;
    cam->unk20 = D_80192690[D_800D48E0].unk70;
    cam->unk24 = D_80192690[D_800D48E0].unk74;
    cam->unk28 = D_80192690[D_800D48E0].unk78;
    cam->unk2C = D_80192690[D_800D48E0].unk7C;
    cam->unk30 = D_80192690[D_800D48E0].unk80;
    cam->unk34 = D_80192690[D_800D48E0].unk84;
    cam->unk38 = D_80192690[D_800D48E0].unk88;
    cam->unk3C = D_80192690[D_800D48E0].unk8C;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80067E40.s")
#endif

void func_800683A0(s32 arg0) {
    UnkStruct_80192690* rider = &D_80192690[arg0];

    D_80192540[arg0].unk0 = 6;
    D_80192540[arg0].unk4 = rider->unk16E8;
    D_80192540[arg0].unk8 = rider->unk16EC;
    D_80192540[arg0].unkC.x = rider->unk44.x + (D_800D4948 * rider->unk6C);
    D_80192540[arg0].unkC.y = rider->unk44.y + (D_800D4948 * rider->unk70);
    D_80192540[arg0].unkC.z = rider->unk44.z + (D_800D4948 * rider->unk74);
    D_80192540[arg0].unk18.x = rider->unk6C;
    D_80192540[arg0].unk18.y = rider->unk70;
    D_80192540[arg0].unk18.z = rider->unk74;
    D_80192540[arg0].unk24.x = rider->unk78;
    D_80192540[arg0].unk24.y = rider->unk7C;
    D_80192540[arg0].unk24.z = rider->unk80;
    D_80192540[arg0].unk30 = 0.1f;
    func_800AC098(&D_80192540[arg0], 1);
    if (gRiderGameModes != PAUSE_MODE) {
        if (rider->unk16E8 == 0) {
            if (rider->unkC7C != 0) {
                if (rider->unkC66 != 0) {
                    rider->unk16EC += 2;
                } else {
                    rider->unk16EC += 1;
                }
            }
        } else {
            rider->unk16EC += 1;
        }
        if (rider->unk16EC >= 16) {
            rider->unk16EC = 0;
            if (rider->unk16E8 == 3) {
                rider->unk16E8 = 0;
            }
        }
    }
}

Gfx* func_80068538(Gfx* gdl) {
    s32 i;
    s32 flag;

    gSPDisplayList(gdl++, D_1007968);
    for (i = 0; i < gRiders; i++) {
        if (D_80192690[i].unkB68 == 2) {
            if (i == D_800D48DC) {
                if (D_801CE6F4[0] != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            } else if ((i == D_800D48E0) && (gPlayers == TWO_PLAYERS)) {
                if (D_801CE6F4[1] != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
            gSPClearGeometryMode(gdl++, G_CULL_BOTH);
            if (flag == 0) {
                gSPSetGeometryMode(gdl++, G_CULL_BACK);
            }
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF308[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_80227A60[flag].unk30[0]);
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF408[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_80227A60[flag].unk30[1]);
            if (1) {} // FAKE
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF508[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_80227A60[flag].unk30[2]);
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF608[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_80227A60[flag].unk30[3]);
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF708[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_80227A60[flag].unk30[4]);
        }
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800687A4.s")

s32 func_8006931C(UnkStruct_80192690* arg0, Mtx* arg1) {
    MtxF sp30;

    sp30.mf[2][0] = arg0->unk6C;
    sp30.mf[2][2] = arg0->unk74;
    if ((sp30.mf[3][3] = (SQ(arg0->unk6C) + SQ(arg0->unk74))) == 0.0f) {
        return -1;
    }
    sp30.mf[3][3] = 1 / sqrtf(sp30.mf[3][3]);
    sp30.mf[0][0] = sp30.mf[3][3] * arg0->unk74;
    sp30.mf[0][2] = sp30.mf[3][3] * -arg0->unk6C;
    sp30.mf[3][0] = sp30.mf[0][2] * arg0->unk70;
    sp30.mf[3][1] = (arg0->unk74 * sp30.mf[0][0]) - (sp30.mf[0][2] * arg0->unk6C);
    sp30.mf[3][2] = sp30.mf[0][0] * -arg0->unk70;
    if ((sp30.mf[3][3] = (SQ(sp30.mf[3][0]) + SQ(sp30.mf[3][1])) + SQ(sp30.mf[3][2])) == 0.0f) {
        return -1;
    }
    sp30.mf[3][3] = 1 / sqrtf(sp30.mf[3][3]);
    sp30.mf[1][0] = sp30.mf[3][3] * sp30.mf[3][0];
    sp30.mf[1][2] = sp30.mf[3][3] * sp30.mf[3][2];
    sp30.mf[3][0] = arg0->unk44.x;
    sp30.mf[3][1] = func_8004D30C(arg0->unk44.x, arg0->unk44.z);
    sp30.mf[3][2] = arg0->unk44.z;
    sp30.mf[0][1] = sp30.mf[1][1] = sp30.mf[2][1] = sp30.mf[0][3] = sp30.mf[1][3] = sp30.mf[2][3] = 0;
    sp30.mf[3][3] = 1.0f;

    SysUtils_MtxFToMtx(&sp30, arg1);
    return 0;
}

Gfx* func_800694B8(Gfx* gdl, s32 arg1) {
    if (D_80192690[arg1].unkC78 < 4) {
        if (func_8006931C(&D_80192690[arg1], &gGfxPool->unkF808[arg1]) == 0) {
            // Segment 3 is gGfxPool.
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkF808[arg1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPDisplayList(gdl++, D_10068B0);
        }
    }
    return gdl;
}


Gfx* func_80069594(Gfx* arg0) {
    UnkStruct_80192690* temp_v1;
    camera_unk_1* temp_v0;
    f32 temp_f0;
    Gfx* s1;
    s32 var_s0;

    if (!(gPlayers != TWO_PLAYERS) || (gCourseID == DRAKE_LAKE) || (D_801CE638 == 0x15)) {
        return arg0;
    }
    arg0 = func_800694B8(arg0, D_800D48DC);
    for (var_s0 = 0; var_s0 < gRiders; var_s0++) {
        if (var_s0 != D_800D48DC) {
            temp_v0 = &gCameraPerspective[D_80223930];
            temp_v1 = &D_80192690[var_s0];
            temp_f0 = (temp_v0->unk6C * (temp_v1->unk44.z - temp_v0->unk54)) +
                      (((temp_v1->unk44.x - temp_v0->unk4C) * temp_v0->unk64) +
                       ((temp_v1->unk44.y - temp_v0->unk50) * temp_v0->unk68));
            if ((temp_f0 > 0.0f) && (temp_f0 < 1000.0f)) {
                arg0 = func_800694B8(arg0, var_s0);
            }
        }
        if (1) {
            ; // FAKE
        }
    }
    return arg0;
}

void func_80069740(UnkStruct_80069740* arg0, UnkStruct_80069740* arg1) {
    *arg0 = *arg1;
}

void func_8006977C(void* arg0, s32 arg1) {
    *(Vec3f*) arg0 = *(Vec3f*) arg1;
}

// arg4 and arg5 are void* in functions.h; typed views of them:
#define CAM ((UnkStruct_80069798*) arg4)
#define SCALE ((Vec3f*) arg5)

void func_80069798(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    f32 eye[3];
    f32 r;
    MtxF lookAt;
    MtxF scaleMtx;
    MtxF result;

    r = CAM->unk14 * SCALE->y;
    eye[0] = ((r * COS(DEG_TO_BINANG(CAM->unk20))) * COS(DEG_TO_BINANG(CAM->unk18))) + CAM->unk8.x;
    eye[1] = (SIN(DEG_TO_BINANG(CAM->unk20)) * r) + CAM->unk8.y;
    eye[2] = ((r * COS(DEG_TO_BINANG(CAM->unk20))) * SIN(DEG_TO_BINANG(CAM->unk18))) + CAM->unk8.z;
    r = CAM->unk18 + (CAM->unk1C * SCALE->z);
    CAM->unk18 = (r + ((r > 360.0f) ? -360.0f : 0.0f)) + ((r < 0.0f) ? 360.0f : 0.0f);
    func_800484C8(arg0, &lookAt, eye[0], eye[1], eye[2], CAM->unk8.x, CAM->unk8.y, CAM->unk8.z, 0.0f, 1.0f, 0.0f);
    r = CAM->unk0 * SCALE->x;
    func_801EE91C(scaleMtx.mf, r, r, r);
    SysUtils_MatrixAffineMultiply(&lookAt, &scaleMtx, &result);
    SysUtils_MtxFToMtx(&result, arg0);
    *(UnkStruct_80069798_1*) arg1 = CAM->unk28;
    func_800481E0(arg2, arg3, CAM->unk4, 1.0f, D_800D4AF0, D_800D4AF4, 0.0f, 0.0f);
}

#undef CAM
#undef SCALE
