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

// The rider's entries of 0x28 bytes at 0x660: most loops cover the first 19 (unk660 .. 0x958);
// func_8005DE24 also uses entries 19 to 24 (up to 0xA48).
typedef struct RiderPart {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Vec3f unk4;
    /* 0x10 */ Vec3f unk10;
    /* 0x1C */ Vec3f unk1C;
} RiderPart; /* size = 0x28 */

// The rider's 3 x 18 entries of 0x24 bytes at 0xC88 (unkC88 .. 0x1420).
typedef struct UnkStruct_80192690_C88 {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ Vec3f unk18;
} UnkStruct_80192690_C88; /* size = 0x24 */

#define RIDER_C88(rider) ((UnkStruct_80192690_C88(*)[18]) &(rider)->unkC88)

#define RIDER_PARTS(rider) ((RiderPart*) (rider)->unk660)

// A view of unkA48 as 22 links of 0xC bytes between two entries, with a length.
typedef struct RiderLink {
    /* 0x0 */ RiderPart* unk0;
    /* 0x4 */ RiderPart* unk4;
    /* 0x8 */ f32 unk8;
} RiderLink; /* size = 0xC */

#define RIDER_LINKS(rider) ((RiderLink*) (rider)->unkA48)

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
    /* 0x00 */ f32 scale;
    /* 0x04 */ f32 fov;
    /* 0x08 */ Vec3f target;
    /* 0x14 */ f32 distance;
    /* 0x18 */ f32 yaw;
    /* 0x1C */ f32 yawSpeed;
    /* 0x20 */ f32 pitch;
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

typedef struct UnkStruct_801C3D14 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ char pad4[0xE4];
} UnkStruct_801C3D14; /* size = 0xE8 */

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
extern struct UnkStruct_801C2938 gRiderRaceState[];
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
extern f32 D_800D4A10;
extern f32 D_800D4A14;
extern f32 D_800D4A18;
extern f32 D_800D4A1C;
extern f32 D_800D9630;
extern f32 D_800D49C4;
extern f32 D_800D49C8;
extern s32 D_800D4990;
extern f32 D_800D4950;
extern f32 D_800D498C;
extern f32 D_800D49D8;
extern f32 D_800D4988;
extern f32 D_800D49D0;
extern f32 D_800D49D4;
extern f32 D_800D4ACC;
extern f32 D_800D4AD4;
extern UnkStruct_801C3D14 D_801C3D14[];
extern f32 D_800D4AC8;
extern f32 D_800D4938;
extern f32 D_800D92F0[];
extern f32 D_800D9300[];
extern f32 D_800D9310[];
extern f32 D_800D9320[];
extern f32 D_800D9330[];
extern f32 D_800D9340[];
extern f32 D_800D9400[];
extern f32 D_800D9410[];
extern f32 D_800D9480[];

extern f32 D_800D49C0;
extern f32 D_800D494C;
extern f32 D_800D4954;
extern u32 D_800D4944;
extern Gfx D_10079F0[];
extern Gfx D_2000000[];
extern f32 D_800D49A4;
extern f32 D_800D49A8;
extern s32 D_800D4924;
extern u16 D_800D4968;
extern Vec3f D_80192650;
extern Vec3f D_80192660;
extern Vec3f D_80192670;
extern Vec3f D_80192680;
extern UnkStruct_80192420 gWaterWindow[];
extern s32 D_80192498;
extern f32 D_801C1FB4;
extern s32 D_800D49AC;
extern f32 D_801924AC;
extern f32 D_801924B0;
extern f32 D_801924B4;
extern f32 D_801924B8;
extern f32 D_801924BC;
extern f32 D_801924C0;
extern Vec3f D_800D4840[12];
extern f32 D_800D490C;
extern f32 D_800D4910;
extern f32 D_800D4914;
extern f32 D_800D4918;
extern f32 D_800D491C;
extern f32 D_800D4920;
extern f32 D_800D48E4[5];
extern f32 D_800D48F8[5];
extern f32 D_800D4AC0;
extern f32 D_800D4AC4;
extern f32 D_800D4AD0;
extern f32 D_800D4AD8;
extern f32 D_800D4ADC;
extern f32 D_800D4AE0;
extern s32 D_800D4AE4;
extern s8 D_800D4A3C[11][4];
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
extern f32 D_800D49E4;
extern s32 D_801C2658;
extern UnkStruct_802238DC* D_8022391C; // the same address as D_802238DC[16]
extern f32 D_800D499C;
extern s32 D_800D4820[];
extern f32 D_800D49A0;
extern f32 D_800D49EC;
extern s16 gColorRed;
extern s32 D_800D4800[];
extern s32 D_800D4818[];
extern s32 D_801C2650;
extern s32 D_8022393C;
extern f32 D_800D4940;
extern s32 D_800D497C;
extern s32 D_800D4980;
extern f32 D_800D4984;
extern s32 D_800D4994;
extern s32 D_800D4998;
extern f32 D_800D49E0;
extern f32 D_800D49F0;
extern f32 D_800D49F8;
extern f32 D_800D49FC;
extern s32 D_800D4A08;
extern s32 D_800D4A0C;
extern f32 D_800D4A24;
extern f32 D_800D4A28;
extern f32 D_800D4A30;
extern f32 D_800D4A34;
extern f32 D_800D4A38;
extern f32 D_800D9350[];
extern f32 D_800D9360[];
extern f32 D_800D9370[];
extern f32 D_800D9380[];
extern f32 D_800D9390[];
extern f32 D_800D93A0[];
extern f32 D_800D93B0[];
extern f32 D_800D93C0[];

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
void func_8005B510(s32 arg0, UnkStruct_80052E90_arg1_s* arg1);
void func_8005A1B4(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3);
void func_8005CEF8(UnkStruct_80052E90_arg1_s* arg0, UnkStruct_8005CEF8* arg1);
f32 func_8007FAE4(f32, f32, f32, f32*, f32*, f32*);
f32 func_8007F448(f32, f32, f32, f32*, f32*, f32*);
void func_80061184(UnkStruct_80192690*);
void func_80080400(void);
Gfx* func_800694B8(Gfx*, s32);
Gfx* Rider_DrawParts(Gfx*, s32, s32);
void func_8004E0A4(UnkStruct_80192690*, f32);
void func_8004E548(struct UnkStruct_8004B0F8*, f32);
void func_80051740(struct UnkStruct_801C3C50*, struct UnkStruct_8004B0F8*);
void func_8007F030(UnkStruct_80192690*, UnkStruct_80192690*);
void func_8007F700(UnkStruct_80192690*);
void func_8007E8C8(UnkStruct_80192690*);
void func_8007EF80(UnkStruct_80192690*);
void func_8007ECBC(UnkStruct_80192690*);
void func_8004B1B4(struct UnkStruct_8004B0F8*);
void func_8004F3D4(f32, f32, s32);
Gfx* func_80091CD8(Gfx*);
Gfx* Rider_DrawPartsReflect(Gfx*, s32);
void func_800683A0(s32);
void func_80063C88(s32);
void func_80064C0C(s32);
void func_80065C18(s32);
void func_800C118C(void*);
void func_800C11CC(void*);
void func_800BFB84(Vec3f*, Vec3f*, Vec3f*, Vec3f*, u8);
void Water_StampDiagonalSine(f32, f32, s32, s32, s32);
void func_8004B0F8(struct UnkStruct_8004B0F8* arg0);
void func_800624CC(UnkStruct_80192690* arg0);
void Rider_MovePoints(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8005DE24(s32);
void func_800609EC(s32);
void func_800C35B4(void);
void func_80051EC0(s32);
void func_80062E50(s32, Mtx*, s32);
void func_800629A8(UnkStruct_80192690*);
void func_8004AFE8(struct UnkStruct_8004B0F8* arg0, s32 arg1, s32 arg2);
void func_8004AE88(struct UnkStruct_8004B0F8* arg0);
void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8006AC84(s32, void*);
void func_8006390C(s32, void*);
void Riders_BuildPartsLists(void);
void func_8006243C(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_801EE91C(MtxF_t arg0, f32 x, f32 y, f32 z);
void func_800AC098(UnkStruct_80192540*, s32);

#ifdef NON_MATCHING
// Score 19419 of 36800: far off: the original keeps the 18 differences in stack homes (frame 0x88) with a different
// register assignment. Control flow matches: the plane tests short-circuit in the same order, then the 12 points are
// reset from D_800D4840 in the rider's basis.
void func_80051EC0(s32 arg0) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    UnkStruct_8004B0F8_1* p = rider->unk90;
    Vec3f* t;
    f32 x;
    f32 y;
    f32 z;
    f32 dz2;
    f32 dx2;
    f32 dy2;
    f32 dz1;
    f32 dx1;
    f32 dy1;
    f32 dz0;
    f32 dx0;
    f32 dy0;
    f32 dz5;
    f32 dx5;
    f32 dy5;
    f32 dz4;
    f32 dx4;
    f32 dy4;
    f32 dz3;
    f32 dx3;
    f32 dy3;

    z = rider->unk44.z;
    x = rider->unk44.x;
    y = rider->unk44.y;
    if (((dz2 = p[2].unk8 - z, dx2 = p[2].unk0 - x, dy2 = p[2].unk4 - y), ((rider->unk84 * dx2) + (rider->unk88 * dy2) + (dz2 * rider->unk8C)) < 0.0f) ||
        ((dz5 = p[5].unk8 - z, dx5 = p[5].unk0 - x, dy5 = p[5].unk4 - y), ((rider->unk84 * dx5) + (rider->unk88 * dy5) + (dz5 * rider->unk8C)) < 0.0f) ||
        ((dz0 = p[0].unk8 - z, dx0 = p[0].unk0 - x, dy0 = p[0].unk4 - y), ((rider->unk84 * dx0) + (rider->unk88 * dy0) + (dz0 * rider->unk8C)) > 0.0f) ||
        ((dz3 = p[3].unk8 - z, dx3 = p[3].unk0 - x, dy3 = p[3].unk4 - y), ((rider->unk84 * dx3) + (rider->unk88 * dy3) + (dz3 * rider->unk8C)) > 0.0f) ||
        ((dz1 = p[1].unk8 - z, dx1 = p[1].unk0 - x, dy1 = p[1].unk4 - y), ((rider->unk78 * dx1) + (rider->unk7C * dy1) + (dz1 * rider->unk80)) < 0.0f) ||
        ((dz4 = p[4].unk8 - z, dx4 = p[4].unk0 - x, dy4 = p[4].unk4 - y), ((rider->unk78 * dx4) + (rider->unk7C * dy4) + (dz4 * rider->unk80)) < 0.0f) ||
        (((rider->unk78 * dx0) + (rider->unk7C * dy0) + (dz0 * rider->unk80)) > 0.0f) ||
        (((rider->unk78 * dx2) + (rider->unk7C * dy2) + (dz2 * rider->unk80)) > 0.0f) ||
        (((rider->unk78 * dx3) + (rider->unk7C * dy3) + (dz3 * rider->unk80)) > 0.0f) ||
        (((rider->unk78 * dx5) + (rider->unk7C * dy5) + (dz5 * rider->unk80)) > 0.0f) ||
        (((rider->unk6C * dx3) + (rider->unk70 * dy3) + (dz3 * rider->unk74)) < 0.0f) ||
        (((rider->unk6C * dx4) + (rider->unk70 * dy4) + (dz4 * rider->unk74)) < 0.0f) ||
        (((rider->unk6C * dx5) + (rider->unk70 * dy5) + (dz5 * rider->unk74)) < 0.0f) ||
        (((rider->unk6C * dx0) + (rider->unk70 * dy0) + (dz0 * rider->unk74)) > 0.0f) ||
        (((rider->unk6C * dx1) + (rider->unk70 * dy1) + (dz1 * rider->unk74)) > 0.0f) ||
        (((rider->unk6C * dx2) + (rider->unk70 * dy2) + (dz2 * rider->unk74)) > 0.0f)) {
        for (t = D_800D4840; t != &D_800D4840[12]; t++, p++) {
            p->unk0 = (rider->unk84 * t->x) + (rider->unk78 * t->y) + (rider->unk6C * t->z) + x;
            p->unk4 = (rider->unk88 * t->x) + (rider->unk7C * t->y) + (rider->unk70 * t->z) + y;
            p->unk8 = (rider->unk8C * t->x) + (rider->unk80 * t->y) + (rider->unk74 * t->z) + z;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80051EC0.s")
#endif

void func_80052480(s32 arg0, struct UnkStruct_80052480* arg1) {
    char pad[0x4];
    f32 ft2;
    f32 ft5;
    f32 sp28;
    s32 var_v0;

    arg1->unk0 = (s8) (s32) (D_80192690[arg0].unkB90 * 1.4399999f);
    arg1->unk1 = (s8) (s32) ((f32) gRiderRaceState[arg0].unk2C8 * 0.44444445f);
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
    arg1->unkE = (s8) gRiderRaceState[arg0].power;
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
        if (gRiderRaceState[arg0].unk318 != 0) {
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
    arg1->unk19 = (s8) gRiderRaceState[arg0].unk4;
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
// Score 11744 of 16800: float register allocation differs: the original keeps arg9/arg13 (later px/py/pz) in fs0-fs2
// and has a 0x70 frame; this version spills more (frame 0x88). Control flow and arithmetic order match.
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

void Rider_SetPartsState(s32, s32);

void Rider_SetPartsState(s32 arg0, s32 arg1) {
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
        Rider_SetPartsState(arg0, arg1);
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
    Rider_SetPartsState(arg0, -1);
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

#ifdef NON_MATCHING
// Score 9443 of 82500: close in structure: float register allocation differs (the original also keeps the double
// 19.000002 in $f30 across the loop) and the frame is 8 bytes larger. Control flow matches.
s32 func_80054130(s32 arg0, UnkStruct_80052E90_arg1_s* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    UnkStruct_80192690* rider;
    UnkStruct_802238DC* anim;
    s32 i;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    f32 s;
    f32 mx;
    f32 my;
    f32 mz;
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;

    anim = D_802238DC[arg2];
    if (arg3 >= anim->unk0) {
        arg3 = anim->unk0 - 1;
    }
    rider = &D_80192690[arg0];
    func_80053FBC(rider, &anim->unk4[anim->unk20[arg3]], &arg1->unkD8);
    func_80053FBC(rider, &anim->unk4[anim->unk10[arg3]], &arg1->unk48);
    func_80053FBC(rider, &anim->unk4[anim->unk1C[arg3]], &arg1->unkB4);
    func_80052C6C(rider, &anim->unk4[anim->unk8[arg3]], &arg1->unk0);
    func_80052C6C(rider, &anim->unk4[anim->unk14[arg3]], &arg1->unk6C);
    func_80052C6C(rider, &anim->unk4[anim->unkC[arg3]], &arg1->unk24);
    func_80052C6C(rider, &anim->unk4[anim->unk18[arg3]], &arg1->unk90);
    func_80052C6C(rider, &anim->unk4[anim->unk4C[arg3]], &arg1->unk264);
    func_80052C6C(rider, &anim->unk4[anim->unk48[arg3]], &arg1->unk240);
    func_80052C6C(rider, &anim->unk4[anim->unk44[arg3]], &arg1->unk21C);
    if (arg4 != 0) {
        func_80052C6C(rider, &anim->unk4[anim->unk28[arg3]], &arg1->unk120);
    } else {
        func_80053FBC(rider, &anim->unk4[anim->unk28[arg3]], &arg1->unk120);
    }
    if (arg5 != 0) {
        func_80052C6C(rider, &anim->unk4[anim->unk34[arg3]], &arg1->unk18C);
    } else {
        func_80053FBC(rider, &anim->unk4[anim->unk34[arg3]], &arg1->unk18C);
    }
    func_80053FBC(rider, &anim->unk4[anim->unk40[arg3]], &arg1->unk1F8);
    func_80053FBC(rider, &anim->unk4[anim->unk30[arg3]], &arg1->unk168);
    func_80053FBC(rider, &anim->unk4[anim->unk3C[arg3]], &arg1->unk1D4);
    for (i = 3; i != 0; i--) {
        if (arg4 != 0) {
            dx = arg1->unk168.unk0.x - arg1->unk120.unk0.x;
            dy = arg1->unk168.unk0.y - arg1->unk120.unk0.y;
            dz = arg1->unk168.unk0.z - arg1->unk120.unk0.z;
            len = SQ(dx) + SQ(dy) + SQ(dz);
            if (len > (19.000002 * 19.000002)) {
                s = 19.000002 / sqrtf(len);
                arg1->unk168.unk0.x = arg1->unk120.unk0.x + (s * dx);
                arg1->unk168.unk0.y = arg1->unk120.unk0.y + (s * dy);
                arg1->unk168.unk0.z = arg1->unk120.unk0.z + (s * dz);
            }
            dx = arg1->unk168.unk0.x - arg1->unk1F8.unk0.x;
            dy = arg1->unk168.unk0.y - arg1->unk1F8.unk0.y;
            dz = arg1->unk168.unk0.z - arg1->unk1F8.unk0.z;
            s = 14.367054f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
            arg1->unk168.unk0.x = arg1->unk1F8.unk0.x + (s * dx);
            arg1->unk168.unk0.y = arg1->unk1F8.unk0.y + (s * dy);
            arg1->unk168.unk0.z = arg1->unk1F8.unk0.z + (s * dz);
        }
        if (arg5 != 0) {
            dx = arg1->unk1D4.unk0.x - arg1->unk18C.unk0.x;
            dy = arg1->unk1D4.unk0.y - arg1->unk18C.unk0.y;
            dz = arg1->unk1D4.unk0.z - arg1->unk18C.unk0.z;
            len = SQ(dx) + SQ(dy) + SQ(dz);
            if (len > (19.000002 * 19.000002)) {
                s = 19.000002 / sqrtf(len);
                arg1->unk1D4.unk0.x = arg1->unk18C.unk0.x + (s * dx);
                arg1->unk1D4.unk0.y = arg1->unk18C.unk0.y + (s * dy);
                arg1->unk1D4.unk0.z = arg1->unk18C.unk0.z + (s * dz);
            }
            dx = arg1->unk1D4.unk0.x - arg1->unk1F8.unk0.x;
            dy = arg1->unk1D4.unk0.y - arg1->unk1F8.unk0.y;
            dz = arg1->unk1D4.unk0.z - arg1->unk1F8.unk0.z;
            s = 14.367054f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
            arg1->unk1D4.unk0.x = arg1->unk1F8.unk0.x + (s * dx);
            arg1->unk1D4.unk0.y = arg1->unk1F8.unk0.y + (s * dy);
            arg1->unk1D4.unk0.z = arg1->unk1F8.unk0.z + (s * dz);
        }
        dx = arg1->unk168.unk0.x - arg1->unk1D4.unk0.x;
        dy = arg1->unk168.unk0.y - arg1->unk1D4.unk0.y;
        dz = arg1->unk168.unk0.z - arg1->unk1D4.unk0.z;
        mx = (arg1->unk168.unk0.x + arg1->unk1D4.unk0.x) * 0.5;
        s = 7.0 / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
        dx *= s;
        arg1->unk168.unk0.x = dx + mx;
        dy *= s;
        my = (arg1->unk168.unk0.y + arg1->unk1D4.unk0.y) * 0.5;
        arg1->unk168.unk0.y = dy + my;
        arg1->unk1D4.unk0.x = mx - dx;
        dz *= s;
        arg1->unk1D4.unk0.y = my - dy;
        mz = (arg1->unk168.unk0.z + arg1->unk1D4.unk0.z) * 0.5;
        arg1->unk168.unk0.z = dz + mz;
        arg1->unk1D4.unk0.z = mz - dz;
    }
    dx = ((arg1->unk168.unk0.x + arg1->unk1D4.unk0.x) * 0.5) - arg1->unk1F8.unk0.x;
    dy = ((arg1->unk168.unk0.y + arg1->unk1D4.unk0.y) * 0.5) - arg1->unk1F8.unk0.y;
    dz = ((arg1->unk168.unk0.z + arg1->unk1D4.unk0.z) * 0.5) - arg1->unk1F8.unk0.z;
    s = 1.0f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    arg1->unk1F8.unkC.x = s * dx;
    arg1->unk1F8.unkC.y = s * dy;
    arg1->unk1F8.unkC.z = s * dz;
    ax = arg1->unk168.unk0.x - arg1->unk1F8.unk0.x;
    ay = arg1->unk168.unk0.y - arg1->unk1F8.unk0.y;
    az = arg1->unk168.unk0.z - arg1->unk1F8.unk0.z;
    bx = arg1->unk1D4.unk0.x - arg1->unk1F8.unk0.x;
    by = arg1->unk1D4.unk0.y - arg1->unk1F8.unk0.y;
    bz = arg1->unk1D4.unk0.z - arg1->unk1F8.unk0.z;
    dx = (bz * ay) - (by * az);
    dy = (bx * az) - (bz * ax);
    dz = (by * ax) - (bx * ay);
    s = 1.0f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    arg1->unk1F8.unk14.x = s * dx;
    arg1->unk1F8.unk14.y = s * dy;
    arg1->unk1F8.unk14.z = s * dz;
    if (arg4 != 0) {
        func_80052C6C(rider, &anim->unk4[anim->unk2C[arg3]], &arg1->unk144);
        func_800534AC(&arg1->unk144, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y,
                      arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f,
                      109.34885f, arg1->unk144.unk0.x - (0.5 * (arg1->unk120.unk0.x + arg1->unk168.unk0.x)),
                      arg1->unk144.unk0.y - (0.5 * (arg1->unk120.unk0.y + arg1->unk168.unk0.y)),
                      arg1->unk144.unk0.z - (0.5 * (arg1->unk120.unk0.z + arg1->unk168.unk0.z)));
        arg1->unk168.unkC.x = arg1->unk144.unk0.x - arg1->unk168.unk0.x;
        arg1->unk168.unkC.y = arg1->unk144.unk0.y - arg1->unk168.unk0.y;
        arg1->unk168.unkC.z = arg1->unk144.unk0.z - arg1->unk168.unk0.z;
        arg1->unk168.unk14.x = rider->unk6C;
        arg1->unk168.unk14.y = rider->unk70;
        arg1->unk168.unk14.z = rider->unk74;
        func_80052A20(&arg1->unk168);
        arg1->unk144.unkC.x = arg1->unk120.unk0.x - arg1->unk144.unk0.x;
        arg1->unk144.unkC.y = arg1->unk120.unk0.y - arg1->unk144.unk0.y;
        arg1->unk144.unkC.z = arg1->unk120.unk0.z - arg1->unk144.unk0.z;
        arg1->unk144.unk14.x = rider->unk78;
        arg1->unk144.unk14.y = rider->unk7C;
        arg1->unk144.unk14.z = rider->unk80;
        func_80052A20(&arg1->unk144);
    } else {
        func_80053FBC(rider, &anim->unk4[anim->unk2C[arg3]], &arg1->unk144);
    }
    if (arg5 != 0) {
        func_80052C6C(rider, &anim->unk4[anim->unk38[arg3]], &arg1->unk1B0);
        func_800534AC(&arg1->unk1B0, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y,
                      arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f,
                      109.34885f, arg1->unk1B0.unk0.x - (0.5 * (arg1->unk18C.unk0.x + arg1->unk1D4.unk0.x)),
                      arg1->unk1B0.unk0.y - (0.5 * (arg1->unk18C.unk0.y + arg1->unk1D4.unk0.y)),
                      arg1->unk1B0.unk0.z - (0.5 * (arg1->unk18C.unk0.z + arg1->unk1D4.unk0.z)));
        arg1->unk1D4.unkC.x = arg1->unk1B0.unk0.x - arg1->unk1D4.unk0.x;
        arg1->unk1D4.unkC.y = arg1->unk1B0.unk0.y - arg1->unk1D4.unk0.y;
        arg1->unk1D4.unkC.z = arg1->unk1B0.unk0.z - arg1->unk1D4.unk0.z;
        arg1->unk1D4.unk14.x = rider->unk6C;
        arg1->unk1D4.unk14.y = rider->unk70;
        arg1->unk1D4.unk14.z = rider->unk74;
        func_80052A20(&arg1->unk1D4);
        arg1->unk1B0.unkC.x = arg1->unk18C.unk0.x - arg1->unk1B0.unk0.x;
        arg1->unk1B0.unkC.y = arg1->unk18C.unk0.y - arg1->unk1B0.unk0.y;
        arg1->unk1B0.unkC.z = arg1->unk18C.unk0.z - arg1->unk1B0.unk0.z;
        arg1->unk1B0.unk14.x = rider->unk78;
        arg1->unk1B0.unk14.y = rider->unk7C;
        arg1->unk1B0.unk14.z = rider->unk80;
        func_80052A20(&arg1->unk1B0);
    } else {
        func_80053FBC(rider, &anim->unk4[anim->unk38[arg3]], &arg1->unk1B0);
    }
    func_80053FBC(rider, &anim->unk4[anim->unk24[arg3]], &arg1->unkFC);
    arg1->unkFC.unk0.x = arg1->unk1F8.unk0.x + (14.483002 * arg1->unk1F8.unkC.x);
    arg1->unkFC.unk0.y = arg1->unk1F8.unk0.y + (14.483002 * arg1->unk1F8.unkC.y);
    arg1->unkFC.unk0.z = arg1->unk1F8.unk0.z + (14.483002 * arg1->unk1F8.unkC.z);
    arg3++;
    if (arg3 >= anim->unk0) {
        arg3 = -1;
    }
    return arg3;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80054130.s")
#endif

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

#ifdef NON_MATCHING
// Score 82354 of 246800: far off (frame, registers, 0x68 bytes longer); this is the m2c structure with named
// skeleton entries and rider parts, kept for reading. Control flow follows the original: the lean side (unk16B8),
// the per-entry func_800574E4 placement, the two-bone limb solves (func_800534AC), the unk15B0/unkC70 frame counters
// and the water-level checks that pick the D_802238DC entry.
void func_80057B24(s32 arg0, UnkStruct_80052E90_arg1_s* arg1) {
    f32 sp360;
    f32 sp364;
    f32 sp80;
    f32 sp84;
    f32 sp8C;
    f32 spA0;
    f32 spA8;
    f32 spAC;
    f32 spB0;
    s32 spB4;
    f32 spB4f;
    UnkStruct_80052C6C_2* limb48;
    UnkStruct_80052C6C_2* limb24;
    UnkStruct_80052C6C_2* limbB4;
    UnkStruct_80052E90_arg1_s spC4;
    UnkStruct_80052C6C_2* temp_a1;
    UnkStruct_80052C6C_2* temp_a1_2;
    UnkStruct_80052C6C_2* temp_a1_3;
    f32 temp_fa0;
    f32 temp_fa0_10;
    f32 temp_fa0_11;
    f32 temp_fa0_12;
    f32 temp_fa0_13;
    f32 temp_fa0_14;
    f32 temp_fa0_15;
    f32 temp_fa0_16;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa0_7;
    f32 temp_fa0_8;
    f32 temp_fa0_9;
    f32 temp_fa1;
    f32 temp_fa1_10;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fa1_5;
    f32 temp_fa1_6;
    f32 temp_fa1_7;
    f32 temp_fa1_8;
    f32 temp_fa1_9;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_11;
    f32 temp_fs0_12;
    f32 temp_fs0_13;
    f32 temp_fs0_14;
    f32 temp_fs0_15;
    f32 temp_fs0_16;
    f32 temp_fs0_17;
    f32 temp_fs0_18;
    f32 temp_fs0_19;
    f32 temp_fs0_2;
    f32 temp_fs0_20;
    f32 temp_fs0_21;
    f32 temp_fs0_22;
    f32 temp_fs0_23;
    f32 temp_fs0_24;
    f32 temp_fs0_25;
    f32 temp_fs0_26;
    f32 temp_fs0_27;
    f32 temp_fs0_28;
    f32 temp_fs0_29;
    f32 temp_fs0_3;
    f32 temp_fs0_30;
    f32 temp_fs0_31;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fs0_7;
    f32 temp_fs0_8;
    f32 temp_fs0_9;
    f32 temp_fs1;
    f32 temp_fs1_10;
    f32 temp_fs1_11;
    f32 temp_fs1_12;
    f32 temp_fs1_13;
    f32 temp_fs1_14;
    f32 temp_fs1_15;
    f32 temp_fs1_16;
    f32 temp_fs1_17;
    f32 temp_fs1_18;
    f32 temp_fs1_19;
    f32 temp_fs1_2;
    f32 temp_fs1_20;
    f32 temp_fs1_21;
    f32 temp_fs1_22;
    f32 temp_fs1_23;
    f32 temp_fs1_24;
    f32 temp_fs1_25;
    f32 temp_fs1_26;
    f32 temp_fs1_27;
    f32 temp_fs1_28;
    f32 temp_fs1_29;
    f32 temp_fs1_3;
    f32 temp_fs1_30;
    f32 temp_fs1_31;
    f32 temp_fs1_4;
    f32 temp_fs1_5;
    f32 temp_fs1_6;
    f32 temp_fs1_7;
    f32 temp_fs1_8;
    f32 temp_fs1_9;
    f32 temp_fs2;
    f32 temp_fs2_10;
    f32 temp_fs2_11;
    f32 temp_fs2_12;
    f32 temp_fs2_13;
    f32 temp_fs2_14;
    f32 temp_fs2_15;
    f32 temp_fs2_16;
    f32 temp_fs2_17;
    f32 temp_fs2_18;
    f32 temp_fs2_19;
    f32 temp_fs2_2;
    f32 temp_fs2_20;
    f32 temp_fs2_21;
    f32 temp_fs2_22;
    f32 temp_fs2_23;
    f32 temp_fs2_24;
    f32 temp_fs2_25;
    f32 temp_fs2_26;
    f32 temp_fs2_27;
    f32 temp_fs2_28;
    f32 temp_fs2_29;
    f32 temp_fs2_3;
    f32 temp_fs2_30;
    f32 temp_fs2_31;
    f32 temp_fs2_32;
    f32 temp_fs2_4;
    f32 temp_fs2_5;
    f32 temp_fs2_6;
    f32 temp_fs2_7;
    f32 temp_fs2_8;
    f32 temp_fs2_9;
    f32 temp_fs3;
    f32 temp_fs3_2;
    f32 temp_fs3_3;
    f32 temp_fs3_4;
    f32 temp_fs3_5;
    f32 temp_fs3_6;
    f32 temp_fs3_7;
    f32 temp_fs3_8;
    f32 temp_fs3_9;
    f32 temp_fs4;
    f32 temp_fs4_2;
    f32 temp_fs4_3;
    f32 temp_fs4_4;
    f32 temp_fs4_5;
    f32 temp_fs4_6;
    f32 temp_fs4_7;
    f32 temp_fs4_8;
    f32 temp_fs5;
    f32 temp_fs5_2;
    f32 temp_ft3;
    f32 temp_ft4;
    f32 temp_ft4_10;
    f32 temp_ft4_11;
    f32 temp_ft4_12;
    f32 temp_ft4_2;
    f32 temp_ft4_3;
    f32 temp_ft4_4;
    f32 temp_ft4_5;
    f32 temp_ft4_6;
    f32 temp_ft4_7;
    f32 temp_ft4_8;
    f32 temp_ft4_9;
    f32 temp_ft5;
    f32 temp_ft5_10;
    f32 temp_ft5_11;
    f32 temp_ft5_12;
    f32 temp_ft5_2;
    f32 temp_ft5_3;
    f32 temp_ft5_4;
    f32 temp_ft5_5;
    f32 temp_ft5_6;
    f32 temp_ft5_7;
    f32 temp_ft5_8;
    f32 temp_ft5_9;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_10;
    f32 temp_fv1_11;
    f32 temp_fv1_12;
    f32 temp_fv1_13;
    f32 temp_fv1_14;
    f32 temp_fv1_15;
    f32 temp_fv1_16;
    f32 temp_fv1_17;
    f32 temp_fv1_18;
    f32 temp_fv1_19;
    f32 temp_fv1_2;
    f32 temp_fv1_20;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_8;
    f32 temp_fv1_9;
    UnkStruct_80192690* rider;
    UnkStruct_80052C6C_2* temp_s2;
    UnkStruct_80052C6C_2* temp_s2_2;
    UnkStruct_80052C6C_2* temp_s2_3;
    UnkStruct_80052C6C_2* temp_s2_4;
    s32 temp_s2_5;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_t9;
    UnkStruct_80052C6C_1* temp_v0;
    UnkStruct_80052C6C_1* temp_v0_10;
    UnkStruct_80052C6C_1* temp_v0_11;
    UnkStruct_80052C6C_1* temp_v0_12;
    UnkStruct_80052C6C_1* temp_v0_13;
    UnkStruct_80052C6C_1* temp_v0_14;
    UnkStruct_80052C6C_1* temp_v0_15;
    UnkStruct_80052C6C_1* temp_v0_16;
    UnkStruct_80052C6C_1* temp_v0_2;
    UnkStruct_80052C6C_1* temp_v0_3;
    UnkStruct_80052C6C_1* temp_v0_4;
    UnkStruct_80052C6C_1* temp_v0_5;
    UnkStruct_80052C6C_1* temp_v0_6;
    UnkStruct_80052C6C_1* temp_v0_7;
    UnkStruct_80052C6C_1* temp_v0_8;
    UnkStruct_80052C6C_1* temp_v0_9;
    s16* temp_v1;
    s16* temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s16* temp_v1_2;
    s16* temp_v1_3;
    s16* temp_v1_4;
    s16* temp_v1_5;
    s16* temp_v1_6;
    s16* temp_v1_7;
    s16* temp_v1_8;
    s16* temp_v1_9;
    f32 var_fv0;
    s32 var_s2;
    UnkStruct_802238DC* var_s3;
    s32 var_t0;
    s32 var_t6;
    s32 var_v1;


    rider = &D_80192690[arg0];
    temp_fv0 = rider->unk16B8;
    var_s3 = *D_802238DC;
    if (temp_fv0 < 0.0f) {
        sp360 = -temp_fv0;
        var_t0 = 3;
        if (sp360 > 0.2f) {
            RIDER_PARTS(rider)[9].unk0 = 1;
            RIDER_PARTS(rider)[10].unk0 = 1;
        } else {
            RIDER_PARTS(rider)[9].unk0 = 4;
            RIDER_PARTS(rider)[10].unk0 = 4;
        }
    } else {
        var_t0 = 2;
        sp360 = temp_fv0;
        RIDER_PARTS(rider)[9].unk0 = 4;
        RIDER_PARTS(rider)[10].unk0 = 4;
    }
    temp_v1 = var_s3->unk20;
    temp_v0 = var_s3->unk4;
    spB4 = var_t0 * 2;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, &arg1->unkD8, &temp_v0[*temp_v1], &temp_v0[temp_v1[var_t0]], sp360);
    temp_fa1 = rider->unk44.x;
    temp_fs0 = arg1->unkD8.unk0.x - temp_fa1;
    temp_fa0 = rider->unk84;
    temp_fs1 = arg1->unkD8.unk0.y - rider->unk44.y;
    temp_fs2 = arg1->unkD8.unk0.z - rider->unk44.z;
    var_fv0 = rider->unk16C0;
    spB0 = rider->unk78;
    temp_fs4 = (temp_fa0 * temp_fs0) + (temp_fs1 * rider->unk88) + (temp_fs2 * rider->unk8C);
    temp_fs3 = rider->unk16BC * ((temp_fs0 * spB0) + (temp_fs1 * rider->unk7C) + (temp_fs2 * rider->unk80));
    if (var_fv0 > 1.0f) {
        var_fv0 = 1.0f;
    }
    temp_fv1 = rider->unk6C;
    temp_a1 = &arg1->unk48;
    temp_fv0_2 = var_fv0 * ((temp_fs0 * temp_fv1) + (temp_fs1 * rider->unk70) + (temp_fs2 * rider->unk74));
    arg1->unkD8.unk0.x = temp_fa1 + (temp_fs4 * temp_fa0) + (temp_fs3 * spB0) + (temp_fv0_2 * temp_fv1);
    arg1->unkD8.unk0.y = rider->unk44.y + (temp_fs4 * rider->unk88) + (temp_fs3 * rider->unk7C) + (temp_fv0_2 * rider->unk70);
    arg1->unkD8.unk0.z = rider->unk44.z + (temp_fs4 * rider->unk8C) + (temp_fs3 * rider->unk80) + (temp_fv0_2 * rider->unk74);
    temp_v1_2 = var_s3->unk10;
    temp_v0_2 = var_s3->unk4;
    limb48 = temp_a1;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, temp_a1, &temp_v0_2[*temp_v1_2], &temp_v0_2[*(temp_v1_2 + spB4)], sp360);
    temp_v1_3 = var_s3->unkC;
    temp_v0_3 = var_s3->unk4;
    temp_a1_2 = &arg1->unk24;
    limb24 = temp_a1_2;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, temp_a1_2, &temp_v0_3[*temp_v1_3], &temp_v0_3[*(temp_v1_3 + spB4)], sp360);
    temp_v1_4 = var_s3->unk8;
    temp_v0_4 = var_s3->unk4;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, &arg1->unk0, &temp_v0_4[*temp_v1_4], &temp_v0_4[*(temp_v1_4 + spB4)], sp360);
    temp_v1_5 = var_s3->unk1C;
    temp_v0_5 = var_s3->unk4;
    temp_a1_3 = &arg1->unkB4;
    limbB4 = temp_a1_3;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, temp_a1_3, &temp_v0_5[*temp_v1_5], &temp_v0_5[*(temp_v1_5 + spB4)], sp360);
    temp_v1_6 = var_s3->unk18;
    temp_v0_6 = var_s3->unk4;
    temp_s2 = &arg1->unk90;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, temp_s2, &temp_v0_6[*temp_v1_6], &temp_v0_6[*(temp_v1_6 + spB4)], sp360);
    temp_v1_7 = var_s3->unk14;
    temp_v0_7 = var_s3->unk4;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, &arg1->unk6C, &temp_v0_7[*temp_v1_7], &temp_v0_7[*(temp_v1_7 + spB4)], sp360);
    temp_fv0_3 = arg1->unkD8.unkC.x;
    temp_fv1_2 = arg1->unkD8.unkC.y;
    temp_fa0_2 = arg1->unkD8.unkC.z;
    temp_fs4_2 = arg1->unkD8.unk14.y;
    temp_fs5 = arg1->unkD8.unk14.z;
    temp_fs0_2 = (f32) ((f64) arg1->unkD8.unk0.x + (2.729486 * (f64) temp_fv0_3));
    temp_fs1_2 = (f32) ((f64) arg1->unkD8.unk0.y + (2.729486 * (f64) temp_fv1_2));
    temp_fs2_2 = (f32) ((f64) arg1->unkD8.unk0.z + (2.729486 * (f64) temp_fa0_2));
    sp8C = arg1->unkD8.unk14.x;
    temp_ft4 = (f32) ((f64) ((temp_fs4_2 * temp_fa0_2) - (temp_fs5 * temp_fv1_2)) * 3.133);
    temp_ft5 = (f32) ((f64) ((temp_fs5 * temp_fv0_3) - (sp8C * temp_fa0_2)) * 3.133);
    temp_fv0_4 = temp_fs1_2 + temp_ft5;
    sp364 = (f32) ((f64) ((sp8C * temp_fv1_2) - (temp_fs4_2 * temp_fv0_3)) * 3.133);
    arg1->unk48.unk0.x = temp_fs0_2 + temp_ft4;
    arg1->unk48.unk0.y = temp_fv0_4;
    arg1->unkB4.unk0.x = temp_fs0_2 - temp_ft4;
    temp_fa0_3 = arg1->unk48.unk0.x;
    temp_fv1_3 = temp_fs2_2 + sp364;
    arg1->unkB4.unk0.y = temp_fs1_2 - temp_ft5;
    arg1->unk48.unk0.z = temp_fv1_3;
    arg1->unkB4.unk0.z = temp_fs2_2 - sp364;
    temp_fa1_2 = arg1->unk0.unk0.x;
    temp_fs3_2 = arg1->unk0.unk0.y;
    temp_fs4_3 = arg1->unk0.unk0.z;
    func_800534AC(limb24, &arg1->unk24.unk0.y, &arg1->unk24.unk0.z, temp_fa0_3, temp_fv0_4, temp_fv1_3, temp_fa1_2, temp_fs3_2, temp_fs4_3, 298.01123f, 355.76913f, (f32) ((f64) arg1->unk24.unk0.x - (0.5 * (f64) (temp_fa0_3 + temp_fa1_2))), (f32) ((f64) arg1->unk24.unk0.y - (0.5 * (f64) (temp_fv0_4 + temp_fs3_2))), (f32) ((f64) arg1->unk24.unk0.z - (0.5 * (f64) (temp_fv1_3 + temp_fs4_3))));
    func_800534AC(temp_s2, &arg1->unk90.unk0.y, &arg1->unk90.unk0.z, arg1->unkB4.unk0.x, arg1->unkB4.unk0.y, arg1->unkB4.unk0.z, arg1->unk6C.unk0.x, arg1->unk6C.unk0.y, arg1->unk6C.unk0.z, 298.01123f, 355.76913f, arg1->unk6C.unkC.x, arg1->unk6C.unkC.y, arg1->unk6C.unkC.z);
    arg1->unk48.unkC.x = arg1->unk24.unk0.x - arg1->unk48.unk0.x;
    arg1->unk48.unkC.y = arg1->unk24.unk0.y - arg1->unk48.unk0.y;
    arg1->unk48.unkC.z = arg1->unk24.unk0.z - arg1->unk48.unk0.z;
    func_80052A20(limb48);
    arg1->unk24.unkC.x = arg1->unk0.unk0.x - arg1->unk24.unk0.x;
    arg1->unk24.unkC.y = arg1->unk0.unk0.y - arg1->unk24.unk0.y;
    arg1->unk24.unkC.z = arg1->unk0.unk0.z - arg1->unk24.unk0.z;
    func_80052A20(limb24);
    arg1->unkB4.unkC.x = arg1->unk90.unk0.x - arg1->unkB4.unk0.x;
    arg1->unkB4.unkC.y = arg1->unk90.unk0.y - arg1->unkB4.unk0.y;
    arg1->unkB4.unkC.z = arg1->unk90.unk0.z - arg1->unkB4.unk0.z;
    func_80052A20(limbB4);
    arg1->unk90.unkC.x = arg1->unk6C.unk0.x - arg1->unk90.unk0.x;
    arg1->unk90.unkC.y = arg1->unk6C.unk0.y - arg1->unk90.unk0.y;
    arg1->unk90.unkC.z = arg1->unk6C.unk0.z - arg1->unk90.unk0.z;
    func_80052A20(temp_s2);
    temp_v1_8 = var_s3->unk4C;
    temp_v0_8 = var_s3->unk4;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, &arg1->unk264, &temp_v0_8[*temp_v1_8], &temp_v0_8[*(temp_v1_8 + spB4)], sp360);
    temp_v1_9 = var_s3->unk48;
    temp_v0_9 = var_s3->unk4;
    temp_s2_2 = &arg1->unk240;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, temp_s2_2, &temp_v0_9[*temp_v1_9], &temp_v0_9[*(temp_v1_9 + spB4)], sp360);
    temp_fv1_4 = arg1->unk240.unkC.x;
    temp_fa0_4 = arg1->unk240.unkC.y;
    temp_fa1_3 = arg1->unk240.unkC.z;
    temp_fs3_3 = rider->unk16BC * ((temp_fv1_4 * arg1->unk264.unk14.x) + (temp_fa0_4 * arg1->unk264.unk14.y) + (temp_fa1_3 * arg1->unk264.unk14.z));
    temp_fv0_5 = (temp_fv1_4 * arg1->unk264.unkC.x) + (temp_fa0_4 * arg1->unk264.unkC.y) + (temp_fa1_3 * arg1->unk264.unkC.z);
    arg1->unk240.unkC.x = (rider->unk78 * temp_fs3_3) + (temp_fv0_5 * rider->unk6C);
    arg1->unk240.unkC.y = (rider->unk7C * temp_fs3_3) + (temp_fv0_5 * rider->unk70);
    arg1->unk240.unkC.z = (rider->unk80 * temp_fs3_3) + (temp_fv0_5 * rider->unk74);
    arg1->unk240.unk14.x = rider->unk78;
    arg1->unk240.unk14.y = rider->unk7C;
    arg1->unk240.unk14.z = rider->unk80;
    arg1->unk240.unk0.x = (f32) ((f64) rider->unk44.x + (37.0 * (f64) rider->unk6C) + (13.0 * (f64) rider->unk78));
    arg1->unk240.unk0.y = (f32) ((f64) rider->unk44.y + (37.0 * (f64) rider->unk70) + (13.0 * (f64) rider->unk7C));
    arg1->unk240.unk0.z = (f32) ((f64) rider->unk44.z + (37.0 * (f64) rider->unk74) + (13.0 * (f64) rider->unk80));
    func_80052A20(temp_s2_2);
    arg1->unk264.unk0.x = rider->unk44.x;
    arg1->unk264.unk0.y = rider->unk44.y;
    arg1->unk264.unk0.z = rider->unk44.z;
    arg1->unk264.unkC.x = rider->unk6C;
    arg1->unk264.unkC.y = rider->unk70;
    arg1->unk264.unkC.z = rider->unk74;
    arg1->unk264.unk14.x = rider->unk78;
    arg1->unk264.unk14.y = rider->unk7C;
    arg1->unk264.unk14.z = rider->unk80;
    arg1->unk21C.unk0.x = (f32) ((f64) arg1->unk240.unk0.x + (41.070999 * (f64) arg1->unk240.unkC.x));
    arg1->unk21C.unk0.y = (f32) ((f64) arg1->unk240.unk0.y + (41.070999 * (f64) arg1->unk240.unkC.y));
    arg1->unk21C.unk0.z = (f32) ((f64) arg1->unk240.unk0.z + (41.070999 * (f64) arg1->unk240.unkC.z));
    temp_fv1_5 = rider->unk80;
    temp_fs3_4 = rider->unk7C;
    temp_fs2_3 = rider->unk78;
    spB0 = temp_fs2_3;
    temp_ft4_2 = (rider->unkBAC * D_800D49E4) - rider->unkBA0;
    temp_ft5_2 = (rider->unkBB0 * D_800D49E4) - rider->unkBA4;
    temp_fa0_5 = (rider->unkBB4 * D_800D49E4) - rider->unkBA8;
    temp_fs0_3 = (temp_fv1_5 * temp_ft5_2) - (temp_fs3_4 * temp_fa0_5);
    temp_fs1_3 = (temp_fs2_3 * temp_fa0_5) - (temp_fv1_5 * temp_ft4_2);
    temp_fs2_4 = (temp_fs3_4 * temp_ft4_2) - (spB0 * temp_ft5_2);
    temp_fa0_6 = 1.0f / sqrtf((temp_fs0_3 * temp_fs0_3) + (temp_fs1_3 * temp_fs1_3) + (temp_fs2_4 * temp_fs2_4));
    temp_ft4_3 = temp_fa0_6 * temp_fs1_3;
    temp_ft5_3 = temp_fa0_6 * temp_fs2_4;
    arg1->unk21C.unkC.x = temp_fa0_6 * temp_fs0_3;
    arg1->unk21C.unkC.y = temp_ft4_3;
    arg1->unk21C.unkC.z = temp_ft5_3;
    arg1->unk21C.unk14.x = rider->unk78;
    arg1->unk21C.unk14.y = rider->unk7C;
    temp_fs3_5 = arg1->unk21C.unk14.y;
    arg1->unk21C.unk14.z = rider->unk80;
    temp_fs4_4 = arg1->unk21C.unk14.z;
    temp_fv1_6 = (temp_fs4_4 * temp_ft4_3) - (temp_fs3_5 * temp_ft5_3);
    arg1->unk18C.unkC.x = temp_fv1_6;
    spAC = temp_fs3_5;
    temp_fv0_6 = arg1->unk21C.unk14.x;
    temp_ft4_4 = arg1->unk21C.unkC.z;
    temp_fa0_7 = arg1->unk21C.unkC.x;
    arg1->unk120.unkC.x = temp_fv1_6;
    temp_ft5_4 = arg1->unk21C.unkC.y;
    temp_fs0_4 = (f32) ((f64) arg1->unk21C.unk0.x - ((f64) temp_fv1_6 * 5.367542));
    temp_fa1_4 = (temp_fv0_6 * temp_ft4_4) - (temp_fs4_4 * temp_fa0_7);
    arg1->unk18C.unkC.y = temp_fa1_4;
    arg1->unk120.unkC.y = temp_fa1_4;
    temp_fs1_4 = (f32) ((f64) arg1->unk21C.unk0.y - ((f64) temp_fa1_4 * 5.367542));
    temp_fa1_5 = (spAC * temp_fa0_7) - (temp_fv0_6 * temp_ft5_4);
    arg1->unk18C.unkC.z = temp_fa1_5;
    spA8 = temp_ft4_4;
    spA0 = temp_ft5_4;
    arg1->unk120.unkC.z = temp_fa1_5;
    temp_fs2_5 = (f32) ((f64) arg1->unk21C.unk0.z - ((f64) temp_fa1_5 * 5.367542));
    temp_ft4_5 = (f32) ((f64) temp_fa0_7 * 10.135);
    temp_ft5_5 = (f32) ((f64) spA0 * 10.135);
    temp_fv1_7 = (f32) ((f64) spA8 * 10.135);
    arg1->unk120.unk0.x = temp_fs0_4 + temp_ft4_5;
    arg1->unk120.unk0.y = temp_fs1_4 + temp_ft5_5;
    arg1->unk120.unk0.z = temp_fs2_5 + temp_fv1_7;
    arg1->unk18C.unk0.x = temp_fs0_4 - temp_ft4_5;
    arg1->unk18C.unk0.y = temp_fs1_4 - temp_ft5_5;
    sp364 = temp_fv1_7;
    temp_fv1_8 = arg1->unk21C.unk14.x;
    arg1->unk120.unk14.x = temp_fv1_8;
    arg1->unk18C.unk14.x = temp_fv1_8;
    temp_fv1_9 = arg1->unk21C.unk14.y;
    arg1->unk18C.unk14.y = temp_fv1_9;
    arg1->unk120.unk14.y = temp_fv1_9;
    temp_fv1_10 = arg1->unk21C.unk14.z;
    arg1->unk18C.unk0.z = temp_fs2_5 - sp364;
    arg1->unk18C.unk14.z = temp_fv1_10;
    arg1->unk120.unk14.z = temp_fv1_10;
    temp_v1_10 = var_s3->unk40;
    temp_v0_10 = var_s3->unk4;
    func_800574E4((UnkStruct_80052E90_arg1_s *) rider, &arg1->unk1F8, &temp_v0_10[*temp_v1_10], &temp_v0_10[*(temp_v1_10 + spB4)], sp360);
    temp_fa0_8 = arg1->unkD8.unk0.x;
    temp_fa1_6 = arg1->unkD8.unk0.y;
    temp_fs3_6 = arg1->unkD8.unk0.z;
    arg1->unk1F8.unk0.x = temp_fa0_8;
    arg1->unk1F8.unk0.y = temp_fa1_6;
    arg1->unk1F8.unk0.z = temp_fs3_6;
    spB4f = arg1->unk1F8.unkC.x;
    var_s2 = 3;
    temp_fs0_5 = (f32) ((f64) temp_fa0_8 + (12.546404 * (f64) spB4f));
    spB0 = arg1->unk1F8.unkC.y;
    temp_fv0_7 = arg1->unk1F8.unkC.z;
    temp_fs1_5 = (f32) ((f64) temp_fa1_6 + (12.546404 * (f64) spB0));
    temp_fs2_6 = (f32) ((f64) temp_fs3_6 + (12.546404 * (f64) temp_fv0_7));
    spAC = arg1->unk1F8.unk14.y;
    temp_fs4_5 = arg1->unk1F8.unk14.z;
    sp80 = spB4f;
    sp84 = spB0;
    spA8 = arg1->unk1F8.unk14.x;
    temp_ft4_6 = (f32) ((f64) ((spAC * temp_fv0_7) - (temp_fs4_5 * spB0)) * 7.0);
    sp80 = spAC;
    temp_ft5_6 = (f32) ((f64) ((temp_fs4_5 * spB4f) - (spA8 * temp_fv0_7)) * 7.0);
    arg1->unk168.unk0.x = temp_fs0_5 - temp_ft4_6;
    arg1->unk168.unk0.y = temp_fs1_5 - temp_ft5_6;
    temp_fv0_8 = (f32) ((f64) ((spA8 * sp84) - (spAC * spB4f)) * 7.0);
    arg1->unk1D4.unk0.y = temp_fs1_5 + temp_ft5_6;
    arg1->unk1D4.unk0.x = temp_fs0_5 + temp_ft4_6;
    arg1->unk168.unk0.z = temp_fs2_6 - temp_fv0_8;
    arg1->unk1D4.unk0.z = temp_fs2_6 + temp_fv0_8;
    do {
        temp_fs0_6 = arg1->unk168.unk0.x - arg1->unk120.unk0.x;
        temp_fs1_6 = arg1->unk168.unk0.y - arg1->unk120.unk0.y;
        temp_fs2_7 = arg1->unk168.unk0.z - arg1->unk120.unk0.z;
        temp_fa0_9 = (temp_fs0_6 * temp_fs0_6) + (temp_fs1_6 * temp_fs1_6) + (temp_fs2_7 * temp_fs2_7);
        if ((f64) temp_fa0_9 > 361.00007600000407) {
            temp_fv1_11 = (f32) (19.000002000000002 / (f64) sqrtf(temp_fa0_9));
            arg1->unk168.unk0.x = arg1->unk120.unk0.x + (temp_fv1_11 * temp_fs0_6);
            arg1->unk168.unk0.y = arg1->unk120.unk0.y + (temp_fv1_11 * temp_fs1_6);
            arg1->unk168.unk0.z = arg1->unk120.unk0.z + (temp_fv1_11 * temp_fs2_7);
        }
        temp_fs0_7 = arg1->unk1D4.unk0.x - arg1->unk18C.unk0.x;
        temp_fs1_7 = arg1->unk1D4.unk0.y - arg1->unk18C.unk0.y;
        temp_fs2_8 = arg1->unk1D4.unk0.z - arg1->unk18C.unk0.z;
        temp_fa0_10 = (temp_fs0_7 * temp_fs0_7) + (temp_fs1_7 * temp_fs1_7) + (temp_fs2_8 * temp_fs2_8);
        if ((f64) temp_fa0_10 > 361.00007600000407) {
            temp_fv1_12 = (f32) (19.000002000000002 / (f64) sqrtf(temp_fa0_10));
            arg1->unk1D4.unk0.x = arg1->unk18C.unk0.x + (temp_fv1_12 * temp_fs0_7);
            arg1->unk1D4.unk0.y = arg1->unk18C.unk0.y + (temp_fv1_12 * temp_fs1_7);
            arg1->unk1D4.unk0.z = arg1->unk18C.unk0.z + (temp_fv1_12 * temp_fs2_8);
        }
        temp_fs0_8 = arg1->unk168.unk0.x - arg1->unk1F8.unk0.x;
        temp_fs1_8 = arg1->unk168.unk0.y - arg1->unk1F8.unk0.y;
        temp_fs2_9 = arg1->unk168.unk0.z - arg1->unk1F8.unk0.z;
        temp_fa1_7 = arg1->unk1F8.unk0.x;
        temp_ft4_7 = arg1->unk1F8.unk0.y;
        temp_fv1_13 = 14.367054f / sqrtf((temp_fs0_8 * temp_fs0_8) + (temp_fs1_8 * temp_fs1_8) + (temp_fs2_9 * temp_fs2_9));
        temp_ft5_7 = arg1->unk1F8.unk0.z;
        arg1->unk168.unk0.x = temp_fa1_7 + (temp_fv1_13 * temp_fs0_8);
        arg1->unk168.unk0.y = temp_ft4_7 + (temp_fv1_13 * temp_fs1_8);
        temp_fs0_9 = arg1->unk1D4.unk0.x - temp_fa1_7;
        arg1->unk168.unk0.z = temp_ft5_7 + (temp_fv1_13 * temp_fs2_9);
        temp_fs1_9 = arg1->unk1D4.unk0.y - temp_ft4_7;
        temp_fs2_10 = arg1->unk1D4.unk0.z - temp_ft5_7;
        temp_fv1_14 = 14.367054f / sqrtf((temp_fs0_9 * temp_fs0_9) + (temp_fs1_9 * temp_fs1_9) + (temp_fs2_10 * temp_fs2_10));
        temp_fa1_8 = arg1->unk1F8.unk0.x + (temp_fv1_14 * temp_fs0_9);
        arg1->unk1D4.unk0.x = temp_fa1_8;
        temp_ft4_8 = arg1->unk1F8.unk0.y + (temp_fv1_14 * temp_fs1_9);
        temp_ft5_8 = arg1->unk1F8.unk0.z + (temp_fv1_14 * temp_fs2_10);
        arg1->unk1D4.unk0.y = temp_ft4_8;
        temp_fs0_10 = arg1->unk168.unk0.x - temp_fa1_8;
        arg1->unk1D4.unk0.z = temp_ft5_8;
        temp_fs1_10 = arg1->unk168.unk0.y - temp_ft4_8;
        temp_fs2_11 = arg1->unk168.unk0.z - temp_ft5_8;
        var_s2 -= 1;
        temp_ft4_9 = (f32) ((f64) (arg1->unk168.unk0.x + arg1->unk1D4.unk0.x) * 0.5);
        temp_fa0_11 = (f32) (7.0 / (f64) sqrtf((temp_fs0_10 * temp_fs0_10) + (temp_fs1_10 * temp_fs1_10) + (temp_fs2_11 * temp_fs2_11)));
        temp_fs0_11 = temp_fs0_10 * temp_fa0_11;
        arg1->unk168.unk0.x = temp_fs0_11 + temp_ft4_9;
        temp_fs1_11 = temp_fs1_10 * temp_fa0_11;
        temp_ft5_9 = (f32) ((f64) (arg1->unk168.unk0.y + arg1->unk1D4.unk0.y) * 0.5);
        arg1->unk168.unk0.y = temp_fs1_11 + temp_ft5_9;
        arg1->unk1D4.unk0.x = temp_ft4_9 - temp_fs0_11;
        temp_fs2_12 = temp_fs2_11 * temp_fa0_11;
        arg1->unk1D4.unk0.y = temp_ft5_9 - temp_fs1_11;
        temp_fv1_15 = (f32) ((f64) (arg1->unk168.unk0.z + arg1->unk1D4.unk0.z) * 0.5);
        arg1->unk168.unk0.z = temp_fs2_12 + temp_fv1_15;
        arg1->unk1D4.unk0.z = temp_fv1_15 - temp_fs2_12;
    } while (var_s2 != 0);
    temp_fs0_12 = (f32) (((f64) (arg1->unk168.unk0.x + arg1->unk1D4.unk0.x) * 0.5) - (f64) arg1->unk1F8.unk0.x);
    temp_fs1_12 = (f32) (((f64) (arg1->unk168.unk0.y + arg1->unk1D4.unk0.y) * 0.5) - (f64) arg1->unk1F8.unk0.y);
    temp_fs2_13 = (f32) (((f64) (arg1->unk168.unk0.z + arg1->unk1D4.unk0.z) * 0.5) - (f64) arg1->unk1F8.unk0.z);
    temp_ft4_10 = arg1->unk1F8.unk0.y;
    temp_ft5_10 = arg1->unk1F8.unk0.z;
    temp_fa0_12 = 1.0f / sqrtf((temp_fs0_12 * temp_fs0_12) + (temp_fs1_12 * temp_fs1_12) + (temp_fs2_13 * temp_fs2_13));
    temp_fs3_7 = arg1->unk1D4.unk0.z - temp_ft5_10;
    arg1->unk1F8.unkC.x = temp_fa0_12 * temp_fs0_12;
    arg1->unk1F8.unkC.y = temp_fa0_12 * temp_fs1_12;
    temp_fs5_2 = arg1->unk168.unk0.y - temp_ft4_10;
    arg1->unk1F8.unkC.z = temp_fa0_12 * temp_fs2_13;
    spA8 = arg1->unk1D4.unk0.y - temp_ft4_10;
    temp_fa1_9 = arg1->unk1F8.unk0.x;
    temp_fv1_16 = arg1->unk168.unk0.z - temp_ft5_10;
    temp_fs0_13 = (temp_fs3_7 * temp_fs5_2) - (spA8 * temp_fv1_16);
    spAC = arg1->unk1D4.unk0.x - temp_fa1_9;
    temp_fs4_6 = arg1->unk168.unk0.x - temp_fa1_9;
    temp_fs1_13 = (spAC * temp_fv1_16) - (temp_fs3_7 * temp_fs4_6);
    temp_fs2_14 = (spA8 * temp_fs4_6) - (spAC * temp_fs5_2);
    temp_fa0_13 = 1.0f / sqrtf((temp_fs0_13 * temp_fs0_13) + (temp_fs1_13 * temp_fs1_13) + (temp_fs2_14 * temp_fs2_14));
    arg1->unk1F8.unk14.x = temp_fa0_13 * temp_fs0_13;
    arg1->unk1F8.unk14.y = temp_fa0_13 * temp_fs1_13;
    arg1->unk1F8.unk14.z = temp_fa0_13 * temp_fs2_14;
    if (gGameModes == GMODE_TIME_TRIALS) {
        temp_v1_11 = rider->unk15B0;
        if (temp_v1_11 < 0) {
            if ((D_801C2658 != 0) && (rider->unkC70 < 0)) {
                rider->unk15B0 = 0;
                var_s3 = D_8022391C;
            }
        } else {
            var_s3 = D_8022391C;
            temp_t9 = temp_v1_11 + 1;
            rider->unk15B0 = temp_t9;
            if (temp_t9 >= var_s3->unk0) {
                rider->unk15B0 = -1;
            }
        }
    }
    var_v1 = rider->unkC70;
    if (var_v1 < 0) {
        if (((D_800D499C + (f32) gWaterLevel) < rider->unk44.y) && (rider->unkB7C > 0.0f) && (rider->unk15B0 < 0) && (rider->unkC4C == 0.0f) && (rider->unkC48 == 0.0f)) {
            rider->unkC70 = 0;
            var_s3 = D_802238DC[D_800D4820[rider->unkB68]];
            if (arg0 == gPlayer1Rider) {
                func_800C1EB8(temp_fa0_13, 0);
            }
        }
        var_v1 = rider->unkC70;
    } else {
        var_s3 = D_802238DC[D_800D4820[rider->unkB68]];
        if ((rider->unk44.y < (D_800D49A0 + (f32) gWaterLevel)) && (rider->unkB7C < 0.0f)) {
            temp_t7 = var_v1 + 1;
            if (var_v1 == 5) {
                var_v1 = 6;
                rider->unkC70 = 6;
            } else {
                rider->unkC70 = temp_t7;
                var_v1 = temp_t7;
                if (temp_t7 >= var_s3->unk0) {
                    rider->unkC70 = -1;
                    var_v1 = -1;
                }
            }
        } else {
            temp_t6 = var_v1 + 1;
            if (var_v1 != 5) {
                rider->unkC70 = temp_t6;
                var_v1 = temp_t6;
                if (temp_t6 >= var_s3->unk0) {
                    rider->unkC70 = -1;
                    var_v1 = -1;
                }
            }
        }
    }
    if (var_v1 >= 0) {
        temp_fa0_14 = rider->unk84;
        temp_fv0_9 = rider->unk78;
        temp_fv1_17 = rider->unk6C;
        temp_v0_11 = &var_s3->unk4[var_s3->unk30[var_v1]];
        temp_fs0_14 = (f32) temp_v0_11->unk0 * 0.1f;
        temp_fs1_14 = (f32) temp_v0_11->unk2 * 0.1f;
        temp_fs2_15 = (f32) temp_v0_11->unk4 * 0.1f;
        temp_ft4_11 = arg1->unk168.unk0.x - ((temp_fa0_14 * temp_fs0_14) + (temp_fv0_9 * temp_fs1_14) + (temp_fv1_17 * temp_fs2_15));
        spB0 = temp_fv0_9;
        temp_ft5_11 = arg1->unk168.unk0.y - ((rider->unk88 * temp_fs0_14) + (rider->unk7C * temp_fs1_14) + (rider->unk70 * temp_fs2_15));
        sp364 = arg1->unk168.unk0.z - ((rider->unk8C * temp_fs0_14) + (rider->unk80 * temp_fs1_14) + (rider->unk74 * temp_fs2_15));
        temp_fs0_15 = (f32) temp_v0_11->unk6 * 0.00787402f;
        temp_fs1_15 = (f32) temp_v0_11->unk7 * 0.00787402f;
        temp_fs2_16 = (f32) temp_v0_11->unk8 * 0.00787402f;
        arg1->unk168.unkC.x = (temp_fa0_14 * temp_fs0_15) + (spB0 * temp_fs1_15) + (temp_fv1_17 * temp_fs2_16);
        arg1->unk168.unkC.y = (rider->unk88 * temp_fs0_15) + (rider->unk7C * temp_fs1_15) + (rider->unk70 * temp_fs2_16);
        arg1->unk168.unkC.z = (rider->unk8C * temp_fs0_15) + (rider->unk80 * temp_fs1_15) + (rider->unk74 * temp_fs2_16);
        temp_fs0_16 = (f32) temp_v0_11->unk9 * 0.00787402f;
        temp_fs1_16 = (f32) temp_v0_11->unkA * 0.00787402f;
        temp_fs2_17 = (f32) temp_v0_11->unkB * 0.00787402f;
        arg1->unk168.unk14.x = (rider->unk84 * temp_fs0_16) + (rider->unk78 * temp_fs1_16) + (rider->unk6C * temp_fs2_17);
        arg1->unk168.unk14.y = (rider->unk88 * temp_fs0_16) + (rider->unk7C * temp_fs1_16) + (rider->unk70 * temp_fs2_17);
        arg1->unk168.unk14.z = (rider->unk8C * temp_fs0_16) + (rider->unk80 * temp_fs1_16) + (rider->unk74 * temp_fs2_17);
        temp_v0_12 = &var_s3->unk4[var_s3->unk2C[rider->unkC70]];
        temp_fs0_17 = (f32) temp_v0_12->unk0 * 0.1f;
        temp_fs1_17 = (f32) temp_v0_12->unk2 * 0.1f;
        temp_fs2_18 = (f32) temp_v0_12->unk4 * 0.1f;
        arg1->unk144.unk0.x = (rider->unk84 * temp_fs0_17) + temp_ft4_11 + (rider->unk78 * temp_fs1_17) + (rider->unk6C * temp_fs2_18);
        arg1->unk144.unk0.y = (rider->unk88 * temp_fs0_17) + temp_ft5_11 + (rider->unk7C * temp_fs1_17) + (rider->unk70 * temp_fs2_18);
        arg1->unk144.unk0.z = (rider->unk8C * temp_fs0_17) + sp364 + (rider->unk80 * temp_fs1_17) + (rider->unk74 * temp_fs2_18);
        temp_fs0_18 = (f32) temp_v0_12->unk6 * 0.00787402f;
        temp_fs1_18 = (f32) temp_v0_12->unk7 * 0.00787402f;
        temp_fs2_19 = (f32) temp_v0_12->unk8 * 0.00787402f;
        arg1->unk144.unkC.x = (rider->unk84 * temp_fs0_18) + (rider->unk78 * temp_fs1_18) + (rider->unk6C * temp_fs2_19);
        arg1->unk144.unkC.y = (rider->unk88 * temp_fs0_18) + (rider->unk7C * temp_fs1_18) + (rider->unk70 * temp_fs2_19);
        arg1->unk144.unkC.z = (rider->unk8C * temp_fs0_18) + (rider->unk80 * temp_fs1_18) + (rider->unk74 * temp_fs2_19);
        temp_fs0_19 = (f32) temp_v0_12->unk9 * 0.00787402f;
        temp_fs1_19 = (f32) temp_v0_12->unkA * 0.00787402f;
        temp_fs2_20 = (f32) temp_v0_12->unkB * 0.00787402f;
        arg1->unk144.unk14.x = (rider->unk84 * temp_fs0_19) + (rider->unk78 * temp_fs1_19) + (rider->unk6C * temp_fs2_20);
        arg1->unk144.unk14.y = (rider->unk88 * temp_fs0_19) + (rider->unk7C * temp_fs1_19) + (rider->unk70 * temp_fs2_20);
        arg1->unk144.unk14.z = (rider->unk8C * temp_fs0_19) + (rider->unk80 * temp_fs1_19) + (rider->unk74 * temp_fs2_20);
        temp_v0_13 = &var_s3->unk4[var_s3->unk28[rider->unkC70]];
        temp_fs0_20 = (f32) temp_v0_13->unk0 * 0.1f;
        var_t6 = 1;
        temp_fs1_20 = (f32) temp_v0_13->unk2 * 0.1f;
        temp_fs2_21 = (f32) temp_v0_13->unk4 * 0.1f;
        arg1->unk120.unk0.x = (rider->unk84 * temp_fs0_20) + temp_ft4_11 + (rider->unk78 * temp_fs1_20) + (rider->unk6C * temp_fs2_21);
        arg1->unk120.unk0.y = (rider->unk88 * temp_fs0_20) + temp_ft5_11 + (rider->unk7C * temp_fs1_20) + (rider->unk70 * temp_fs2_21);
        arg1->unk120.unk0.z = (rider->unk8C * temp_fs0_20) + sp364 + (rider->unk80 * temp_fs1_20) + (rider->unk74 * temp_fs2_21);
        temp_fs0_21 = (f32) temp_v0_13->unk6 * 0.00787402f;
        temp_fs1_21 = (f32) temp_v0_13->unk7 * 0.00787402f;
        temp_fs2_22 = (f32) temp_v0_13->unk8 * 0.00787402f;
        arg1->unk120.unkC.x = (rider->unk84 * temp_fs0_21) + (rider->unk78 * temp_fs1_21) + (rider->unk6C * temp_fs2_22);
        arg1->unk120.unkC.y = (rider->unk88 * temp_fs0_21) + (rider->unk7C * temp_fs1_21) + (rider->unk70 * temp_fs2_22);
        arg1->unk120.unkC.z = (rider->unk8C * temp_fs0_21) + (rider->unk80 * temp_fs1_21) + (rider->unk74 * temp_fs2_22);
        temp_fs0_22 = (f32) temp_v0_13->unk9 * 0.00787402f;
        temp_fs1_22 = (f32) temp_v0_13->unkA * 0.00787402f;
        temp_fs2_23 = (f32) temp_v0_13->unkB * 0.00787402f;
        arg1->unk120.unk14.x = (rider->unk84 * temp_fs0_22) + (rider->unk78 * temp_fs1_22) + (rider->unk6C * temp_fs2_23);
        arg1->unk120.unk14.y = (rider->unk88 * temp_fs0_22) + (rider->unk7C * temp_fs1_22) + (rider->unk70 * temp_fs2_23);
        arg1->unk120.unk14.z = (rider->unk8C * temp_fs0_22) + (rider->unk80 * temp_fs1_22) + (rider->unk74 * temp_fs2_23);
        goto block_45; // m2c goto: the two branches share the store to part 6
    }
    temp_v1_12 = rider->unk15B0;
    if (temp_v1_12 >= 0) {
        temp_v0_14 = &var_s3->unk4[var_s3->unk30[temp_v1_12]];
        temp_fa0_15 = rider->unk84;
        temp_fv0_10 = rider->unk78;
        temp_fv1_18 = rider->unk6C;
        temp_fs0_23 = (f32) temp_v0_14->unk0 * 0.1f;
        temp_fs1_23 = (f32) temp_v0_14->unk2 * 0.1f;
        temp_fs2_24 = (f32) temp_v0_14->unk4 * 0.1f;
        temp_ft4_12 = arg1->unk168.unk0.x - ((temp_fa0_15 * temp_fs0_23) + (temp_fv0_10 * temp_fs1_23) + (temp_fv1_18 * temp_fs2_24));
        spB0 = temp_fv0_10;
        temp_ft5_12 = arg1->unk168.unk0.y - ((rider->unk88 * temp_fs0_23) + (rider->unk7C * temp_fs1_23) + (rider->unk70 * temp_fs2_24));
        sp364 = arg1->unk168.unk0.z - ((rider->unk8C * temp_fs0_23) + (rider->unk80 * temp_fs1_23) + (rider->unk74 * temp_fs2_24));
        temp_fs0_24 = (f32) temp_v0_14->unk6 * 0.00787402f;
        temp_fs1_24 = (f32) temp_v0_14->unk7 * 0.00787402f;
        temp_fs2_25 = (f32) temp_v0_14->unk8 * 0.00787402f;
        arg1->unk168.unkC.x = (temp_fa0_15 * temp_fs0_24) + (spB0 * temp_fs1_24) + (temp_fv1_18 * temp_fs2_25);
        arg1->unk168.unkC.y = (rider->unk88 * temp_fs0_24) + (rider->unk7C * temp_fs1_24) + (rider->unk70 * temp_fs2_25);
        arg1->unk168.unkC.z = (rider->unk8C * temp_fs0_24) + (rider->unk80 * temp_fs1_24) + (rider->unk74 * temp_fs2_25);
        temp_fs0_25 = (f32) temp_v0_14->unk9 * 0.00787402f;
        temp_fs1_25 = (f32) temp_v0_14->unkA * 0.00787402f;
        temp_fs2_26 = (f32) temp_v0_14->unkB * 0.00787402f;
        arg1->unk168.unk14.x = (rider->unk84 * temp_fs0_25) + (rider->unk78 * temp_fs1_25) + (rider->unk6C * temp_fs2_26);
        arg1->unk168.unk14.y = (rider->unk88 * temp_fs0_25) + (rider->unk7C * temp_fs1_25) + (rider->unk70 * temp_fs2_26);
        arg1->unk168.unk14.z = (rider->unk8C * temp_fs0_25) + (rider->unk80 * temp_fs1_25) + (rider->unk74 * temp_fs2_26);
        temp_v0_15 = &var_s3->unk4[var_s3->unk2C[rider->unk15B0]];
        temp_fs0_26 = (f32) temp_v0_15->unk0 * 0.1f;
        temp_fs1_26 = (f32) temp_v0_15->unk2 * 0.1f;
        temp_fs2_27 = (f32) temp_v0_15->unk4 * 0.1f;
        arg1->unk144.unk0.x = (rider->unk84 * temp_fs0_26) + temp_ft4_12 + (rider->unk78 * temp_fs1_26) + (rider->unk6C * temp_fs2_27);
        arg1->unk144.unk0.y = (rider->unk88 * temp_fs0_26) + temp_ft5_12 + (rider->unk7C * temp_fs1_26) + (rider->unk70 * temp_fs2_27);
        arg1->unk144.unk0.z = (rider->unk8C * temp_fs0_26) + sp364 + (rider->unk80 * temp_fs1_26) + (rider->unk74 * temp_fs2_27);
        temp_fs0_27 = (f32) temp_v0_15->unk6 * 0.00787402f;
        temp_fs1_27 = (f32) temp_v0_15->unk7 * 0.00787402f;
        temp_fs2_28 = (f32) temp_v0_15->unk8 * 0.00787402f;
        arg1->unk144.unkC.x = (rider->unk84 * temp_fs0_27) + (rider->unk78 * temp_fs1_27) + (rider->unk6C * temp_fs2_28);
        arg1->unk144.unkC.y = (rider->unk88 * temp_fs0_27) + (rider->unk7C * temp_fs1_27) + (rider->unk70 * temp_fs2_28);
        arg1->unk144.unkC.z = (rider->unk8C * temp_fs0_27) + (rider->unk80 * temp_fs1_27) + (rider->unk74 * temp_fs2_28);
        temp_fs0_28 = (f32) temp_v0_15->unk9 * 0.00787402f;
        temp_fs1_28 = (f32) temp_v0_15->unkA * 0.00787402f;
        temp_fs2_29 = (f32) temp_v0_15->unkB * 0.00787402f;
        arg1->unk144.unk14.x = (rider->unk84 * temp_fs0_28) + (rider->unk78 * temp_fs1_28) + (rider->unk6C * temp_fs2_29);
        arg1->unk144.unk14.y = (rider->unk88 * temp_fs0_28) + (rider->unk7C * temp_fs1_28) + (rider->unk70 * temp_fs2_29);
        arg1->unk144.unk14.z = (rider->unk8C * temp_fs0_28) + (rider->unk80 * temp_fs1_28) + (rider->unk74 * temp_fs2_29);
        temp_v0_16 = &var_s3->unk4[var_s3->unk28[rider->unk15B0]];
        temp_fs0_29 = (f32) temp_v0_16->unk0 * 0.1f;
        temp_fs1_29 = (f32) temp_v0_16->unk2 * 0.1f;
        temp_fs2_30 = (f32) temp_v0_16->unk4 * 0.1f;
        arg1->unk120.unk0.x = (rider->unk84 * temp_fs0_29) + temp_ft4_12 + (rider->unk78 * temp_fs1_29) + (rider->unk6C * temp_fs2_30);
        arg1->unk120.unk0.y = (rider->unk88 * temp_fs0_29) + temp_ft5_12 + (rider->unk7C * temp_fs1_29) + (rider->unk70 * temp_fs2_30);
        arg1->unk120.unk0.z = (rider->unk8C * temp_fs0_29) + sp364 + (rider->unk80 * temp_fs1_29) + (rider->unk74 * temp_fs2_30);
        temp_fs0_30 = (f32) temp_v0_16->unk6 * 0.00787402f;
        temp_fs1_30 = (f32) temp_v0_16->unk7 * 0.00787402f;
        temp_fs2_31 = (f32) temp_v0_16->unk8 * 0.00787402f;
        arg1->unk120.unkC.x = (rider->unk84 * temp_fs0_30) + (rider->unk78 * temp_fs1_30) + (rider->unk6C * temp_fs2_31);
        arg1->unk120.unkC.y = (rider->unk88 * temp_fs0_30) + (rider->unk7C * temp_fs1_30) + (rider->unk70 * temp_fs2_31);
        arg1->unk120.unkC.z = (rider->unk8C * temp_fs0_30) + (rider->unk80 * temp_fs1_30) + (rider->unk74 * temp_fs2_31);
        temp_fs0_31 = (f32) temp_v0_16->unk9 * 0.00787402f;
        temp_fs1_31 = (f32) temp_v0_16->unkA * 0.00787402f;
        temp_fs2_32 = (f32) temp_v0_16->unkB * 0.00787402f;
        arg1->unk120.unk14.x = (rider->unk84 * temp_fs0_31) + (rider->unk78 * temp_fs1_31) + (rider->unk6C * temp_fs2_32);
        arg1->unk120.unk14.y = (rider->unk88 * temp_fs0_31) + (rider->unk7C * temp_fs1_31) + (rider->unk70 * temp_fs2_32);
        arg1->unk120.unk14.z = (rider->unk8C * temp_fs0_31) + (rider->unk80 * temp_fs1_31) + (rider->unk74 * temp_fs2_32);
        RIDER_PARTS(rider)[6].unk0 = 1;
    } else {
        temp_s2_3 = &arg1->unk144;
        func_800534AC(temp_s2_3, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y, arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f, 109.34885f, (-rider->unk6C - rider->unk78) + (D_800D49EC * rider->unk84), (-rider->unk70 - rider->unk7C) + (D_800D49EC * rider->unk88), (-rider->unk74 - rider->unk80) + (D_800D49EC * rider->unk8C));
        arg1->unk168.unkC.x = arg1->unk144.unk0.x - arg1->unk168.unk0.x;
        arg1->unk168.unkC.y = arg1->unk144.unk0.y - arg1->unk168.unk0.y;
        arg1->unk168.unkC.z = arg1->unk144.unk0.z - arg1->unk168.unk0.z;
        arg1->unk168.unk14.x = rider->unk6C;
        arg1->unk168.unk14.y = rider->unk70;
        arg1->unk168.unk14.z = rider->unk74;
        func_80052A20(&arg1->unk168);
        arg1->unk144.unkC.x = arg1->unk120.unk0.x - arg1->unk144.unk0.x;
        arg1->unk144.unkC.y = arg1->unk120.unk0.y - arg1->unk144.unk0.y;
        arg1->unk144.unkC.z = arg1->unk120.unk0.z - arg1->unk144.unk0.z;
        arg1->unk144.unk14.x = rider->unk78;
        arg1->unk144.unk14.y = rider->unk7C;
        arg1->unk144.unk14.z = rider->unk80;
        func_80052A20(temp_s2_3);
        var_t6 = 2;
block_45: // m2c label name
        RIDER_PARTS(rider)[6].unk0 = var_t6;
    }
    temp_s2_4 = &arg1->unk1B0;
    func_800534AC(temp_s2_4, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y, arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f, 109.34885f, (-rider->unk6C - rider->unk78) - (D_800D49EC * rider->unk84), (-rider->unk70 - rider->unk7C) - (D_800D49EC * rider->unk88), (-rider->unk74 - rider->unk80) - (D_800D49EC * rider->unk8C));
    arg1->unk1D4.unkC.x = arg1->unk1B0.unk0.x - arg1->unk1D4.unk0.x;
    arg1->unk1D4.unkC.y = arg1->unk1B0.unk0.y - arg1->unk1D4.unk0.y;
    arg1->unk1D4.unkC.z = arg1->unk1B0.unk0.z - arg1->unk1D4.unk0.z;
    arg1->unk1D4.unk14.x = rider->unk6C;
    arg1->unk1D4.unk14.y = rider->unk70;
    arg1->unk1D4.unk14.z = rider->unk74;
    func_80052A20(&arg1->unk1D4);
    arg1->unk1B0.unkC.x = arg1->unk18C.unk0.x - arg1->unk1B0.unk0.x;
    arg1->unk1B0.unkC.y = arg1->unk18C.unk0.y - arg1->unk1B0.unk0.y;
    arg1->unk1B0.unkC.z = arg1->unk18C.unk0.z - arg1->unk1B0.unk0.z;
    arg1->unk1B0.unk14.x = rider->unk78;
    arg1->unk1B0.unk14.y = rider->unk7C;
    arg1->unk1B0.unk14.z = rider->unk80;
    func_80052A20(temp_s2_4);
    arg1->unkFC.unk0.x = (f32) ((f64) arg1->unk1F8.unk0.x + (14.483002 * (f64) arg1->unk1F8.unkC.x));
    arg1->unkFC.unk0.y = (f32) ((f64) arg1->unk1F8.unk0.y + (14.483002 * (f64) arg1->unk1F8.unkC.y));
    arg1->unkFC.unk0.z = (f32) ((f64) arg1->unk1F8.unk0.z + (14.483002 * (f64) arg1->unk1F8.unkC.z));
    temp_fv1_19 = rider->unk6C;
    temp_fv0_11 = rider->unk74;
    temp_fa0_16 = rider->unk84;
    temp_fa1_10 = rider->unk8C;
    temp_s2_5 = SysUtils_Round((f32) rider->unkB60 * D_800D49E8) + 0x400;
    temp_fs4_7 = (temp_fv1_19 * temp_fv1_19) + (temp_fv0_11 * temp_fv0_11);
    temp_fs3_8 = (temp_fa0_16 * temp_fa0_16) + (temp_fa1_10 * temp_fa1_10);
    if ((temp_fs4_7 != 0.0f) && (temp_fs3_8 != 0.0f)) {
        temp_fs4_8 = gSinTable[temp_s2_5 & 0xFFF] / sqrtf(temp_fs4_7);
        temp_fs3_9 = gSinTable[(temp_s2_5 + 0x400) & 0xFFF] / sqrtf(temp_fs3_8);
        temp_ft3 = temp_fs3_9 * rider->unk84;
        arg1->unkFC.unkC.y = 0.0f;
        arg1->unkFC.unkC.x = (rider->unk6C * temp_fs4_8) + temp_ft3;
        arg1->unkFC.unk14.x = 0.0f;
        arg1->unkFC.unkC.z = (rider->unk74 * temp_fs4_8) + (temp_fs3_9 * rider->unk8C);
        arg1->unkFC.unk14.y = 1.0f;
        arg1->unkFC.unk14.z = 0.0f;
    }
    temp_fv0_12 = rider->unkB78;
    temp_fv1_20 = rider->unkB80;
    temp_fv0_13 = sqrtf((temp_fv0_12 * temp_fv0_12) + (temp_fv1_20 * temp_fv1_20));
    if (!(temp_fv0_13 >= 16.666668f)) {
        func_80054130(arg0, &spC4, 0, 0, 1, 1);
        func_80053A5C(arg1, temp_fv0_13 / 16.666668f, &spC4, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80057B24.s")
#endif

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

#ifdef NON_MATCHING
// Score 53675 of 154100: far off (frame and registers); this is the m2c structure with named skeleton entries and
// rider parts, kept for reading. Control flow follows the original: the two arm cases, the 3-pass loop, the reach
// clamps.
void func_8005B510(s32 arg0, UnkStruct_80052E90_arg1_s* arg1) {
    f32 sp84;
    f64 sp88;
    f64 sp90;
    f32 spA8;
    UnkStruct_80052C6C_2* spB4;
    UnkStruct_80052C6C_2* spB8;
    f32 spD0;
    f32 spD4;
    f32 spDC;
    f32 spE0;
    f32 spE4;
    UnkStruct_80052C6C_2* temp_a0;
    UnkStruct_80052C6C_2* temp_a2;
    UnkStruct_80052C6C_2* temp_a2_2;
    f32 temp_fa0;
    f32 temp_fa0_10;
    f32 temp_fa0_11;
    f32 temp_fa0_12;
    f32 temp_fa0_13;
    f32 temp_fa0_14;
    f32 temp_fa0_15;
    f32 temp_fa0_16;
    f32 temp_fa0_17;
    f32 temp_fa0_18;
    f32 temp_fa0_19;
    f32 temp_fa0_2;
    f32 temp_fa0_20;
    f32 temp_fa0_21;
    f32 temp_fa0_22;
    f32 temp_fa0_23;
    f32 temp_fa0_24;
    f32 temp_fa0_25;
    f32 temp_fa0_26;
    f32 temp_fa0_27;
    f32 temp_fa0_28;
    f32 temp_fa0_29;
    f32 temp_fa0_3;
    f32 temp_fa0_30;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa0_7;
    f32 temp_fa0_8;
    f32 temp_fa0_9;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fa1_5;
    f32 temp_fa1_6;
    f32 temp_fa1_7;
    f32 temp_fa1_8;
    f32 temp_fa1_9;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_11;
    f32 temp_fs0_12;
    f32 temp_fs0_13;
    f32 temp_fs0_14;
    f32 temp_fs0_15;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fs0_7;
    f32 temp_fs0_8;
    f32 temp_fs0_9;
    f32 temp_fs1;
    f32 temp_fs1_10;
    f32 temp_fs1_11;
    f32 temp_fs1_12;
    f32 temp_fs1_13;
    f32 temp_fs1_14;
    f32 temp_fs1_15;
    f32 temp_fs1_16;
    f32 temp_fs1_17;
    f32 temp_fs1_2;
    f32 temp_fs1_3;
    f32 temp_fs1_4;
    f32 temp_fs1_5;
    f32 temp_fs1_6;
    f32 temp_fs1_7;
    f32 temp_fs1_8;
    f64 temp_fs1_9;
    f32 temp_fs2;
    f32 temp_fs2_10;
    f32 temp_fs2_11;
    f32 temp_fs2_12;
    f32 temp_fs2_13;
    f32 temp_fs2_14;
    f32 temp_fs2_15;
    f32 temp_fs2_2;
    f32 temp_fs2_3;
    f32 temp_fs2_4;
    f32 temp_fs2_5;
    f32 temp_fs2_6;
    f32 temp_fs2_7;
    f64 temp_fs2_8;
    f32 temp_fs2_9;
    f32 temp_fs3;
    f32 temp_fs3_10;
    f32 temp_fs3_11;
    f32 temp_fs3_12;
    f32 temp_fs3_13;
    f32 temp_fs3_2;
    f32 temp_fs3_3;
    f32 temp_fs3_4;
    f32 temp_fs3_5;
    f32 temp_fs3_6;
    f32 temp_fs3_7;
    f32 temp_fs3_8;
    f32 temp_fs3_9;
    f32 temp_fs4;
    f64 temp_fs4_2;
    f32 temp_fs4_3;
    f32 temp_fs4_4;
    f32 temp_fs4_5;
    f32 temp_fs5;
    f64 temp_fs5_2;
    f32 temp_fs5_3;
    f32 temp_fs5_4;
    f32 temp_ft4;
    f32 temp_ft4_2;
    f32 temp_ft4_3;
    f32 temp_ft4_4;
    f32 temp_ft4_5;
    f32 temp_ft4_6;
    f32 temp_ft4_7;
    f32 temp_ft4_8;
    f32 temp_ft4_9;
    f32 temp_ft5;
    f32 temp_ft5_10;
    f32 temp_ft5_2;
    f32 temp_ft5_3;
    f32 temp_ft5_4;
    f32 temp_ft5_5;
    f32 temp_ft5_6;
    f32 temp_ft5_7;
    f32 temp_ft5_8;
    f32 temp_ft5_9;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_16;
    f32 temp_fv0_17;
    f32 temp_fv0_18;
    f32 temp_fv0_19;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f64 temp_fv0_5;
    f64 temp_fv0_6;
    f32 temp_fv0_7;
    f64 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f64 temp_fv1_10;
    f32 temp_fv1_11;
    f32 temp_fv1_12;
    f32 temp_fv1_13;
    f32 temp_fv1_14;
    f32 temp_fv1_15;
    f32 temp_fv1_16;
    f32 temp_fv1_17;
    f32 temp_fv1_18;
    f32 temp_fv1_19;
    f32 temp_fv1_2;
    f32 temp_fv1_20;
    f32 temp_fv1_21;
    f32 temp_fv1_22;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_8;
    f32 temp_fv1_9;
    UnkStruct_80192690* temp_s1;
    UnkStruct_80052C6C_2* temp_s1_2;
    UnkStruct_80052C6C_2* temp_s2;
    UnkStruct_80052C6C_2* temp_s2_2;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs2;
    f32 var_fs2_2;
    f32 var_fs3;
    f32 var_fs3_2;
    f32 var_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv0_2;
    s32 var_s2;


    temp_s1 = &D_80192690[arg0];
    arg1->unk264.unk0.x = (f32) temp_s1->unk44.x;
    arg1->unk264.unk0.y = (f32) temp_s1->unk44.y;
    arg1->unk264.unk0.z = (f32) temp_s1->unk44.z;
    arg1->unk264.unkC.x = (f32) temp_s1->unk6C;
    arg1->unk264.unkC.y = (f32) temp_s1->unk70;
    arg1->unk264.unkC.z = (f32) temp_s1->unk74;
    temp_fv0 = temp_s1->unk78;
    arg1->unk264.unk14.x = temp_fv0;
    arg1->unk21C.unk14.x = temp_fv0;
    arg1->unk240.unk14.x = (f32) (temp_fv0 + temp_s1->unk6C);
    temp_fv0_2 = temp_s1->unk7C;
    arg1->unk264.unk14.y = temp_fv0_2;
    arg1->unk21C.unk14.y = temp_fv0_2;
    arg1->unk240.unk14.y = (f32) (temp_fv0_2 + temp_s1->unk70);
    temp_fv0_3 = temp_s1->unk80;
    arg1->unk264.unk14.z = temp_fv0_3;
    arg1->unk21C.unk14.z = temp_fv0_3;
    arg1->unk240.unk14.z = (f32) (temp_fv0_3 + temp_s1->unk74);
    arg1->unk21C.unkC.x = (f32) temp_s1->unk84;
    arg1->unk21C.unkC.y = (f32) temp_s1->unk88;
    arg1->unk21C.unkC.z = (f32) temp_s1->unk8C;
    temp_fa0 = (f32) ((f64) temp_s1->unk44.x + (13.0 * (f64) temp_s1->unk78) + (37.0 * (f64) temp_s1->unk6C));
    arg1->unk240.unk0.x = temp_fa0;
    spE4 = (RIDER_PARTS(temp_s1)[21].unk4.x + (D_800D4A14 * RIDER_PARTS(temp_s1)[21].unk1C.x) + (D_800D4A10 * temp_s1->unk78)) - temp_fa0;
    temp_fa0_2 = (f32) ((f64) temp_s1->unk44.y + (13.0 * (f64) temp_s1->unk7C) + (37.0 * (f64) temp_s1->unk70));
    arg1->unk240.unk0.y = temp_fa0_2;
    temp_fs4 = (RIDER_PARTS(temp_s1)[21].unk4.y + (D_800D4A14 * RIDER_PARTS(temp_s1)[21].unk1C.y) + (D_800D4A10 * temp_s1->unk7C)) - temp_fa0_2;
    temp_fa0_3 = (f32) ((f64) temp_s1->unk44.z + (13.0 * (f64) temp_s1->unk80) + (37.0 * (f64) temp_s1->unk74));
    arg1->unk240.unk0.z = temp_fa0_3;
    temp_fs1 = temp_s1->unk80;
    temp_ft4 = temp_s1->unk6C;
    temp_ft5 = temp_s1->unk70;
    temp_fs0 = temp_s1->unk74;
    spA8 = temp_fs1;
    temp_fs5 = (RIDER_PARTS(temp_s1)[21].unk4.z + (D_800D4A14 * RIDER_PARTS(temp_s1)[21].unk1C.z) + (D_800D4A10 * temp_fs1)) - temp_fa0_3;
    var_fv0 = (temp_ft4 * spE4) + (temp_fs4 * temp_ft5) + (temp_fs5 * temp_fs0);
    if ((f64) var_fv0 > -0.1) {
        var_fv0 = -0.1f;
    }
    temp_fv1 = temp_s1->unk78;
    temp_fa1 = temp_s1->unk7C;
    var_fv0_2 = (temp_fv1 * spE4) + (temp_fs4 * temp_fa1) + (temp_fs5 * spA8);
    if (var_fv0_2 < 0.0f) {
        var_fv0_2 = 0.0f;
    }
    temp_fs3 = (temp_ft4 * var_fv0) + (var_fv0_2 * temp_fv1);
    temp_fs1_2 = (temp_ft5 * var_fv0) + (var_fv0_2 * temp_fa1);
    temp_fs2 = (temp_fs0 * var_fv0) + (var_fv0_2 * spA8);
    temp_fv1_2 = 1.0f / sqrtf((temp_fs3 * temp_fs3) + (temp_fs1_2 * temp_fs1_2) + (temp_fs2 * temp_fs2));
    temp_fa1_2 = temp_fv1_2 * temp_fs3;
    arg1->unk240.unkC.x = temp_fa1_2;
    temp_ft4_2 = temp_fv1_2 * temp_fs1_2;
    arg1->unk240.unkC.y = temp_ft4_2;
    arg1->unk21C.unk0.x = (f32) (((f64) temp_fa1_2 * 41.070999) + (f64) arg1->unk240.unk0.x);
    temp_ft5_2 = temp_fv1_2 * temp_fs2;
    arg1->unk240.unkC.z = temp_ft5_2;
    arg1->unk21C.unk0.y = (f32) (((f64) temp_ft4_2 * 41.070999) + (f64) arg1->unk240.unk0.y);
    arg1->unk21C.unk0.z = (f32) (((f64) temp_ft5_2 * 41.070999) + (f64) arg1->unk240.unk0.z);
    func_80052A20(&arg1->unk240);
    if (temp_s1->unk16CC == 0) {
        temp_fs0_2 = (f32) ((f64) arg1->unk21C.unk0.x - (1.867542 * (f64) arg1->unk264.unkC.x));
        temp_fs3_2 = (f32) ((f64) arg1->unk21C.unkC.x * 10.135);
        RIDER_PARTS(temp_s1)[6].unk10.x = temp_fs3_2 + temp_fs0_2;
        temp_ft4_3 = (f32) ((f64) arg1->unk21C.unk0.y - (1.867542 * (f64) arg1->unk264.unkC.y));
        temp_fs1_3 = (f32) ((f64) arg1->unk21C.unkC.y * 10.135);
        RIDER_PARTS(temp_s1)[6].unk10.y = temp_fs1_3 + temp_ft4_3;
        spB4 = &arg1->unk18C;
        spB8 = &arg1->unk120;
        temp_fa0_4 = (f32) ((f64) arg1->unk21C.unk0.z - (1.867542 * (f64) arg1->unk264.unkC.z));
        RIDER_PARTS(temp_s1)[14].unk10.x = temp_fs0_2 - temp_fs3_2;
        temp_fs2_2 = (f32) ((f64) arg1->unk21C.unkC.z * 10.135);
        RIDER_PARTS(temp_s1)[14].unk10.y = temp_ft4_3 - temp_fs1_3;
        RIDER_PARTS(temp_s1)[6].unk10.z = temp_fs2_2 + temp_fa0_4;
        RIDER_PARTS(temp_s1)[14].unk10.z = temp_fa0_4 - temp_fs2_2;
    } else {
        temp_a2 = &arg1->unk120;
        spB8 = temp_a2;
        func_80052C6C(temp_s1, &D_802238DC[0]->unk4[D_802238DC[0]->unk28[5]], temp_a2);
        temp_a2_2 = &arg1->unk18C;
        spB4 = temp_a2_2;
        func_80052C6C(temp_s1, &D_802238DC[0]->unk4[D_802238DC[0]->unk34[5]], temp_a2_2);
        RIDER_PARTS(temp_s1)[6].unk10.x = arg1->unk120.unk0.x;
        RIDER_PARTS(temp_s1)[6].unk10.y = arg1->unk120.unk0.y;
        RIDER_PARTS(temp_s1)[6].unk10.z = arg1->unk120.unk0.z;
        RIDER_PARTS(temp_s1)[14].unk10.x = arg1->unk18C.unk0.x;
        RIDER_PARTS(temp_s1)[14].unk10.y = arg1->unk18C.unk0.y;
        RIDER_PARTS(temp_s1)[14].unk10.z = arg1->unk18C.unk0.z;
    }
    var_s2 = 3;
    RIDER_PARTS(temp_s1)[3].unk10.x = (RIDER_PARTS(temp_s1)[3].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[3].unk4.x;
    temp_fv0_4 = RIDER_PARTS(temp_s1)[3].unk10.x;
    RIDER_PARTS(temp_s1)[3].unk10.y = (RIDER_PARTS(temp_s1)[3].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[3].unk4.y + D_800D4A18;
    temp_fv1_3 = RIDER_PARTS(temp_s1)[3].unk10.y;
    RIDER_PARTS(temp_s1)[3].unk10.z = (RIDER_PARTS(temp_s1)[3].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[3].unk4.z;
    temp_fa0_5 = RIDER_PARTS(temp_s1)[3].unk10.z;
    RIDER_PARTS(temp_s1)[11].unk10.x = (RIDER_PARTS(temp_s1)[11].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[11].unk4.x;
    temp_fa1_3 = RIDER_PARTS(temp_s1)[11].unk10.x;
    RIDER_PARTS(temp_s1)[11].unk10.y = (RIDER_PARTS(temp_s1)[11].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[11].unk4.y + D_800D4A18;
    temp_ft4_4 = RIDER_PARTS(temp_s1)[11].unk10.y;
    RIDER_PARTS(temp_s1)[11].unk10.z = (RIDER_PARTS(temp_s1)[11].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[11].unk4.z;
    temp_ft5_3 = RIDER_PARTS(temp_s1)[11].unk10.z;
    if (((temp_s1->unk84 * (temp_fv0_4 - temp_fa1_3)) + ((temp_fv1_3 - temp_ft4_4) * temp_s1->unk88) + ((temp_fa0_5 - temp_ft5_3) * temp_s1->unk8C)) < 0.0f) {
        RIDER_PARTS(temp_s1)[3].unk10.x = temp_fa1_3;
        RIDER_PARTS(temp_s1)[3].unk10.y = temp_ft4_4;
        RIDER_PARTS(temp_s1)[3].unk10.z = temp_ft5_3;
        RIDER_PARTS(temp_s1)[11].unk10.x = temp_fv0_4;
        RIDER_PARTS(temp_s1)[11].unk10.y = temp_fv1_3;
        RIDER_PARTS(temp_s1)[11].unk10.z = temp_fa0_5;
    }
    temp_fs3_3 = arg1->unk21C.unkC.x * 5.0f;
    temp_fs1_4 = arg1->unk21C.unkC.y * 5.0f;
    arg1->unk168.unk0.x = (f32) (temp_fs3_3 + RIDER_PARTS(temp_s1)[3].unk10.x);
    temp_fs2_3 = arg1->unk21C.unkC.z * 5.0f;
    arg1->unk168.unk0.y = (f32) (temp_fs1_4 + RIDER_PARTS(temp_s1)[3].unk10.y);
    arg1->unk168.unk0.z = (f32) (temp_fs2_3 + RIDER_PARTS(temp_s1)[3].unk10.z);
    arg1->unk1D4.unk0.x = (f32) (RIDER_PARTS(temp_s1)[11].unk10.x - temp_fs3_3);
    arg1->unk1D4.unk0.y = (f32) (RIDER_PARTS(temp_s1)[11].unk10.y - temp_fs1_4);
    arg1->unk1D4.unk0.z = (f32) (RIDER_PARTS(temp_s1)[11].unk10.z - temp_fs2_3);
    do {
        temp_fs3_4 = arg1->unk168.unk0.x - RIDER_PARTS(temp_s1)[6].unk10.x;
        temp_fs1_5 = arg1->unk168.unk0.y - RIDER_PARTS(temp_s1)[6].unk10.y;
        temp_fs2_4 = arg1->unk168.unk0.z - RIDER_PARTS(temp_s1)[6].unk10.z;
        temp_fs0_3 = (temp_fs3_4 * temp_fs3_4) + (temp_fs1_5 * temp_fs1_5) + (temp_fs2_4 * temp_fs2_4);
        temp_fv0_5 = (f64) temp_fs0_3;
        if (temp_fv0_5 > 420.25008200000406) {
            temp_fv1_4 = (f32) (20.500002000000002 / (f64) sqrtf(temp_fs0_3));
            arg1->unk168.unk0.x = (f32) (RIDER_PARTS(temp_s1)[6].unk10.x + (temp_fv1_4 * temp_fs3_4));
            arg1->unk168.unk0.y = (f32) (RIDER_PARTS(temp_s1)[6].unk10.y + (temp_fv1_4 * temp_fs1_5));
            arg1->unk168.unk0.z = (f32) (RIDER_PARTS(temp_s1)[6].unk10.z + (temp_fv1_4 * temp_fs2_4));
        } else if (temp_fv0_5 < 109.34884900000002) {
            temp_fv1_5 = (f32) (10.457 / (f64) sqrtf(temp_fs0_3));
            arg1->unk168.unk0.x = (f32) (RIDER_PARTS(temp_s1)[6].unk10.x + (temp_fv1_5 * temp_fs3_4));
            arg1->unk168.unk0.y = (f32) (RIDER_PARTS(temp_s1)[6].unk10.y + (temp_fv1_5 * temp_fs1_5));
            arg1->unk168.unk0.z = (f32) (RIDER_PARTS(temp_s1)[6].unk10.z + (temp_fv1_5 * temp_fs2_4));
        }
        temp_fs3_5 = arg1->unk1D4.unk0.x - RIDER_PARTS(temp_s1)[14].unk10.x;
        temp_fs1_6 = arg1->unk1D4.unk0.y - RIDER_PARTS(temp_s1)[14].unk10.y;
        temp_fs2_5 = arg1->unk1D4.unk0.z - RIDER_PARTS(temp_s1)[14].unk10.z;
        temp_fs0_4 = (temp_fs3_5 * temp_fs3_5) + (temp_fs1_6 * temp_fs1_6) + (temp_fs2_5 * temp_fs2_5);
        temp_fv0_6 = (f64) temp_fs0_4;
        if (temp_fv0_6 > 420.25008200000406) {
            temp_fv1_6 = (f32) (20.500002000000002 / (f64) sqrtf(temp_fs0_4));
            arg1->unk1D4.unk0.x = (f32) (RIDER_PARTS(temp_s1)[14].unk10.x + (temp_fv1_6 * temp_fs3_5));
            arg1->unk1D4.unk0.y = (f32) (RIDER_PARTS(temp_s1)[14].unk10.y + (temp_fv1_6 * temp_fs1_6));
            arg1->unk1D4.unk0.z = (f32) (RIDER_PARTS(temp_s1)[14].unk10.z + (temp_fv1_6 * temp_fs2_5));
        } else if (temp_fv0_6 < 109.34884900000002) {
            temp_fv1_7 = (f32) (10.457 / (f64) sqrtf(temp_fs0_4));
            arg1->unk1D4.unk0.x = (f32) (RIDER_PARTS(temp_s1)[14].unk10.x + (temp_fv1_7 * temp_fs3_5));
            arg1->unk1D4.unk0.y = (f32) (RIDER_PARTS(temp_s1)[14].unk10.y + (temp_fv1_7 * temp_fs1_6));
            arg1->unk1D4.unk0.z = (f32) (RIDER_PARTS(temp_s1)[14].unk10.z + (temp_fv1_7 * temp_fs2_5));
        }
        spE4 = arg1->unk1D4.unk0.x - arg1->unk168.unk0.x;
        spE0 = arg1->unk1D4.unk0.y - arg1->unk168.unk0.y;
        spDC = arg1->unk1D4.unk0.z - arg1->unk168.unk0.z;
        temp_fa0_6 = (arg1->unk168.unk0.x + arg1->unk1D4.unk0.x) * 0.5f;
        var_s2 -= 1;
        temp_fv1_8 = (f32) (7.0 / (f64) sqrtf(temp_fs0_4));
        temp_fs2_6 = spE4 * temp_fv1_8;
        temp_fa0_7 = (arg1->unk168.unk0.y + arg1->unk1D4.unk0.y) * 0.5f;
        temp_fs1_7 = spE0 * temp_fv1_8;
        arg1->unk1D4.unk0.x = (f32) (temp_fs2_6 + temp_fa0_6);
        temp_fa0_8 = (arg1->unk168.unk0.z + arg1->unk1D4.unk0.z) * 0.5f;
        temp_ft5_4 = spDC * temp_fv1_8;
        arg1->unk1D4.unk0.y = (f32) (temp_fs1_7 + temp_fa0_7);
        spD0 = temp_fa0_8;
        arg1->unk1D4.unk0.z = (f32) (temp_ft5_4 + temp_fa0_8);
        spE4 = temp_fs2_6;
        spE0 = temp_fs1_7;
        arg1->unk168.unk0.x = (f32) (temp_fa0_6 - spE4);
        arg1->unk168.unk0.z = (f32) (temp_fa0_8 - temp_ft5_4);
        arg1->unk168.unk0.y = (f32) (temp_fa0_7 - spE0);
    } while (var_s2 != 0);
    RIDER_PARTS(temp_s1)[2].unk10.x = (RIDER_PARTS(temp_s1)[2].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[2].unk4.x;
    RIDER_PARTS(temp_s1)[2].unk10.y = (RIDER_PARTS(temp_s1)[2].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[2].unk4.y + D_800D4A18;
    temp_fs3_6 = temp_fa0_6 - RIDER_PARTS(temp_s1)[2].unk10.x;
    RIDER_PARTS(temp_s1)[2].unk10.z = (RIDER_PARTS(temp_s1)[2].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[2].unk4.z;
    temp_fs1_8 = temp_fa0_7 - RIDER_PARTS(temp_s1)[2].unk10.y;
    temp_fs2_7 = temp_fa0_8 - RIDER_PARTS(temp_s1)[2].unk10.z;
    arg1->unk1F8.unk14.x = (f32) ((temp_fs1_8 * temp_ft5_4) - (temp_fs2_7 * spE0));
    temp_fa1_4 = arg1->unk1F8.unk14.x;
    temp_fv1_9 = (temp_fs2_7 * spE4) - (temp_fs3_6 * temp_ft5_4);
    arg1->unk1F8.unk14.y = temp_fv1_9;
    temp_fv0_7 = (temp_fs3_6 * spE0) - (temp_fs1_8 * spE4);
    arg1->unk1F8.unk14.z = temp_fv0_7;
    arg1->unk1F8.unkC.x = (f32) ((temp_fv0_7 * spE0) - (temp_ft5_4 * temp_fv1_9));
    arg1->unk1F8.unkC.y = (f32) ((temp_fa1_4 * temp_ft5_4) - (spE4 * temp_fv0_7));
    arg1->unk1F8.unkC.z = (f32) ((arg1->unk1F8.unk14.y * spE4) - (spE0 * temp_fa1_4));
    spDC = temp_ft5_4;
    spD4 = temp_fa0_7;
    func_80052A20(&arg1->unk1F8);
    temp_fv1_10 = (f64) arg1->unk1F8.unkC.x;
    temp_fv0_8 = (f64) temp_fa0_6;
    temp_fs5_2 = (f64) arg1->unk1F8.unkC.y;
    temp_fs4_2 = (f64) temp_fa0_7;
    temp_fs2_8 = (f64) arg1->unk1F8.unkC.z;
    temp_fa0_9 = (f32) (temp_fv0_8 - (12.546404 * temp_fv1_10));
    arg1->unkD8.unk0.x = temp_fa0_9;
    arg1->unk1F8.unk0.x = temp_fa0_9;
    temp_fa0_10 = (f32) (temp_fs4_2 - (12.546404 * temp_fs5_2));
    arg1->unkD8.unk0.y = temp_fa0_10;
    arg1->unk1F8.unk0.y = temp_fa0_10;
    temp_fs1_9 = (f64) spD0;
    temp_fa0_11 = (f32) (temp_fs1_9 - (12.546404 * temp_fs2_8));
    arg1->unkD8.unk0.z = temp_fa0_11;
    arg1->unk1F8.unk0.z = temp_fa0_11;
    arg1->unkFC.unk0.x = (f32) (temp_fv0_8 + (1.936598 * temp_fv1_10));
    sp88 = temp_fs2_8;
    sp90 = temp_fs1_9;
    arg1->unkFC.unk0.y = (f32) (temp_fs4_2 + (1.936598 * temp_fs5_2));
    arg1->unkFC.unk0.z = (f32) (sp90 + (1.936598 * sp88));
    arg1->unkFC.unkC.y = 0.0f;
    arg1->unkFC.unkC.x = (f32) temp_s1->unk1434;
    arg1->unkFC.unk14.x = 0.0f;
    arg1->unkFC.unk14.z = 0.0f;
    arg1->unkFC.unk14.y = 1.0f;
    arg1->unkFC.unkC.z = (f32) temp_s1->unk1438;
    temp_fs3_7 = RIDER_PARTS(temp_s1)[6].unk10.x - arg1->unk168.unk0.x;
    temp_fs1_10 = RIDER_PARTS(temp_s1)[6].unk10.y - arg1->unk168.unk0.y;
    spDC = temp_ft5_4;
    temp_fs2_9 = RIDER_PARTS(temp_s1)[6].unk10.z - arg1->unk168.unk0.z;
    temp_fs0_5 = (f32) (3.5 / (f64) sqrtf((temp_fs3_7 * temp_fs3_7) + (temp_fs1_10 * temp_fs1_10) + (temp_fs2_9 * temp_fs2_9)));
    temp_fs4_3 = temp_fs0_5 * temp_fs3_7;
    arg1->unk120.unkC.x = temp_fs4_3;
    temp_fs5_3 = temp_fs0_5 * temp_fs1_10;
    temp_fv1_11 = temp_fs0_5 * temp_fs2_9;
    arg1->unk120.unkC.y = temp_fs5_3;
    arg1->unk120.unk0.x = (f32) (RIDER_PARTS(temp_s1)[6].unk10.x - temp_fs4_3);
    arg1->unk120.unkC.z = temp_fv1_11;
    arg1->unk120.unk0.y = (f32) (RIDER_PARTS(temp_s1)[6].unk10.y - temp_fs5_3);
    arg1->unk120.unk0.z = (f32) (RIDER_PARTS(temp_s1)[6].unk10.z - temp_fv1_11);
    temp_fs3_8 = RIDER_PARTS(temp_s1)[14].unk10.x - arg1->unk1D4.unk0.x;
    temp_fs1_11 = RIDER_PARTS(temp_s1)[14].unk10.y - arg1->unk1D4.unk0.y;
    temp_fs2_10 = RIDER_PARTS(temp_s1)[14].unk10.z - arg1->unk1D4.unk0.z;
    temp_fa0_12 = arg1->unk264.unk14.x;
    temp_fs0_6 = (f32) (3.5 / (f64) sqrtf((temp_fs3_8 * temp_fs3_8) + (temp_fs1_11 * temp_fs1_11) + (temp_fs2_10 * temp_fs2_10)));
    temp_fs4_4 = temp_fs0_6 * temp_fs3_8;
    arg1->unk18C.unkC.x = temp_fs4_4;
    temp_fs5_4 = temp_fs0_6 * temp_fs1_11;
    temp_fv1_12 = temp_fs0_6 * temp_fs2_10;
    arg1->unk18C.unkC.y = temp_fs5_4;
    arg1->unk18C.unk0.x = (f32) (RIDER_PARTS(temp_s1)[14].unk10.x - temp_fs4_4);
    arg1->unk18C.unkC.z = temp_fv1_12;
    arg1->unk18C.unk0.y = (f32) (RIDER_PARTS(temp_s1)[14].unk10.y - temp_fs5_4);
    arg1->unk120.unk14.x = temp_fa0_12;
    arg1->unk18C.unk14.x = temp_fa0_12;
    temp_fa0_13 = arg1->unk264.unk14.y;
    arg1->unk18C.unk14.y = temp_fa0_13;
    arg1->unk120.unk14.y = temp_fa0_13;
    temp_fa0_14 = arg1->unk264.unk14.z;
    arg1->unk18C.unk0.z = (f32) (RIDER_PARTS(temp_s1)[14].unk10.z - temp_fv1_12);
    arg1->unk18C.unk14.z = temp_fa0_14;
    arg1->unk120.unk14.z = temp_fa0_14;
    spDC = temp_ft5_4;
    func_80052A20(spB8);
    func_80052A20(spB4);
    temp_fv1_13 = 1.0f / sqrtf((spE4 * spE4) + (spE0 * spE0) + (temp_ft5_4 * temp_ft5_4));
    temp_s2 = &arg1->unk144;
    temp_fs1_12 = spE4 * temp_fv1_13;
    temp_fs0_7 = spE0 * temp_fv1_13;
    temp_ft5_5 = temp_ft5_4 * temp_fv1_13;
    spDC = temp_ft5_5;
    func_800534AC(temp_s2, &arg1->unk144.unk0.y, &arg1->unk144.unk0.z, arg1->unk168.unk0.x, arg1->unk168.unk0.y, arg1->unk168.unk0.z, arg1->unk120.unk0.x, arg1->unk120.unk0.y, arg1->unk120.unk0.z, 72.98288f, 109.34885f, arg1->unk1F8.unk14.x - temp_fs1_12, arg1->unk1F8.unk14.y - temp_fs0_7, arg1->unk1F8.unk14.z - temp_ft5_5);
    temp_a0 = &arg1->unk1B0;
    spB8 = temp_a0;
    func_800534AC(temp_a0, &arg1->unk1B0.unk0.y, &arg1->unk1B0.unk0.z, arg1->unk1D4.unk0.x, arg1->unk1D4.unk0.y, arg1->unk1D4.unk0.z, arg1->unk18C.unk0.x, arg1->unk18C.unk0.y, arg1->unk18C.unk0.z, 72.98288f, 109.34885f, arg1->unk1F8.unk14.x + temp_fs1_12, arg1->unk1F8.unk14.y + temp_fs0_7, arg1->unk1F8.unk14.z + temp_ft5_5);
    temp_fv1_14 = arg1->unk144.unk0.y;
    temp_fv0_9 = arg1->unk144.unk0.x;
    temp_fa0_15 = arg1->unk144.unk0.z;
    arg1->unk168.unkC.y = (f32) (temp_fv1_14 - arg1->unk168.unk0.y);
    arg1->unk168.unkC.x = (f32) (temp_fv0_9 - arg1->unk168.unk0.x);
    arg1->unk144.unkC.x = (f32) (arg1->unk120.unk0.x - temp_fv0_9);
    temp_fa0_16 = arg1->unk120.unk14.x;
    arg1->unk168.unkC.z = (f32) (temp_fa0_15 - arg1->unk168.unk0.z);
    arg1->unk144.unk14.x = temp_fa0_16;
    arg1->unk168.unk14.x = temp_fa0_16;
    temp_fa0_17 = arg1->unk120.unk14.y;
    temp_fa1_5 = arg1->unk1B0.unk0.x;
    arg1->unk144.unk14.y = temp_fa0_17;
    arg1->unk168.unk14.y = temp_fa0_17;
    temp_fa0_18 = arg1->unk120.unk14.z;
    temp_fv0_10 = arg1->unk1B0.unk0.y;
    arg1->unk144.unkC.y = (f32) (arg1->unk120.unk0.y - temp_fv1_14);
    arg1->unk144.unkC.z = (f32) (arg1->unk120.unk0.z - temp_fa0_15);
    arg1->unk144.unk14.z = temp_fa0_18;
    arg1->unk168.unk14.z = temp_fa0_18;
    temp_fa0_19 = arg1->unk18C.unk14.x;
    temp_fv1_15 = arg1->unk1B0.unk0.z;
    arg1->unk1D4.unkC.x = (f32) (temp_fa1_5 - arg1->unk1D4.unk0.x);
    arg1->unk1D4.unkC.y = (f32) (temp_fv0_10 - arg1->unk1D4.unk0.y);
    arg1->unk1B0.unk14.x = temp_fa0_19;
    arg1->unk1D4.unk14.x = temp_fa0_19;
    temp_fa0_20 = arg1->unk18C.unk14.y;
    arg1->unk1D4.unkC.z = (f32) (temp_fv1_15 - arg1->unk1D4.unk0.z);
    arg1->unk1B0.unk14.y = temp_fa0_20;
    arg1->unk1B0.unkC.x = (f32) (arg1->unk18C.unk0.x - temp_fa1_5);
    arg1->unk1D4.unk14.y = temp_fa0_20;
    temp_fa0_21 = arg1->unk18C.unk14.z;
    arg1->unk1B0.unkC.y = (f32) (arg1->unk18C.unk0.y - temp_fv0_10);
    arg1->unk1B0.unk14.z = temp_fa0_21;
    arg1->unk1D4.unk14.z = temp_fa0_21;
    arg1->unk1B0.unkC.z = (f32) (arg1->unk18C.unk0.z - temp_fv1_15);
    func_80052A20(&arg1->unk168);
    func_80052A20(&arg1->unk1D4);
    func_80052A20(temp_s2);
    func_80052A20(temp_a0);
    RIDER_PARTS(temp_s1)[7].unk10.x = (RIDER_PARTS(temp_s1)[7].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[7].unk4.x;
    RIDER_PARTS(temp_s1)[7].unk10.y = (RIDER_PARTS(temp_s1)[7].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[7].unk4.y + D_800D4A18;
    RIDER_PARTS(temp_s1)[7].unk10.z = (RIDER_PARTS(temp_s1)[7].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[7].unk4.z;
    RIDER_PARTS(temp_s1)[15].unk10.x = (RIDER_PARTS(temp_s1)[15].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[15].unk4.x;
    RIDER_PARTS(temp_s1)[15].unk10.y = (RIDER_PARTS(temp_s1)[15].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[15].unk4.y + D_800D4A18;
    RIDER_PARTS(temp_s1)[15].unk10.z = (RIDER_PARTS(temp_s1)[15].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[15].unk4.z;
    temp_fs3_9 = ((RIDER_PARTS(temp_s1)[15].unk10.x + RIDER_PARTS(temp_s1)[7].unk10.x) * 0.5f) - arg1->unkD8.unk0.x;
    temp_fs1_13 = ((RIDER_PARTS(temp_s1)[15].unk10.y + RIDER_PARTS(temp_s1)[7].unk10.y) * 0.5f) - arg1->unkD8.unk0.y;
    temp_fs2_11 = ((RIDER_PARTS(temp_s1)[15].unk10.z + RIDER_PARTS(temp_s1)[7].unk10.z) * 0.5f) - arg1->unkD8.unk0.z;
    temp_fs4_5 = arg1->unk21C.unkC.z;
    temp_fs0_8 = arg1->unk21C.unkC.y;
    temp_ft5_6 = arg1->unk21C.unkC.x;
    temp_fv1_16 = (f32) (2.729486 / (f64) sqrtf((temp_fs3_9 * temp_fs3_9) + (temp_fs1_13 * temp_fs1_13) + (temp_fs2_11 * temp_fs2_11)));
    temp_fa0_22 = temp_fv1_16 * temp_fs3_9;
    temp_fa1_6 = temp_fv1_16 * temp_fs1_13;
    temp_ft4_5 = temp_fv1_16 * temp_fs2_11;
    arg1->unkD8.unkC.x = temp_fa0_22;
    arg1->unkD8.unkC.y = temp_fa1_6;
    arg1->unkD8.unkC.z = temp_ft4_5;
    temp_fv1_17 = arg1->unkD8.unkC.z;
    temp_ft4_6 = arg1->unkD8.unkC.y;
    arg1->unkD8.unk14.x = (f32) ((temp_fa1_6 * temp_fs4_5) - (temp_ft4_5 * temp_fs0_8));
    temp_fs0_9 = arg1->unkD8.unkC.x;
    temp_fs1_14 = arg1->unkD8.unk14.x;
    arg1->unkD8.unk14.y = (f32) ((temp_ft4_5 * temp_ft5_6) - (temp_fa0_22 * temp_fs4_5));
    temp_fv0_11 = arg1->unkD8.unk14.y;
    arg1->unkD8.unk14.z = (f32) ((temp_fa0_22 * temp_fs0_8) - (temp_fa1_6 * temp_ft5_6));
    temp_fa1_7 = arg1->unkD8.unk14.z;
    temp_fs3_10 = (temp_fv0_11 * temp_fv1_17) - (temp_fa1_7 * temp_ft4_6);
    temp_fs2_12 = (temp_fa1_7 * temp_fs0_9) - (temp_fs1_14 * temp_fv1_17);
    temp_ft5_7 = (temp_fs1_14 * temp_ft4_6) - (temp_fv0_11 * temp_fs0_9);
    spDC = temp_ft5_7;
    temp_fs0_10 = arg1->unkD8.unk0.x + arg1->unkD8.unkC.x;
    temp_ft4_7 = arg1->unkD8.unk0.y + arg1->unkD8.unkC.y;
    temp_fv1_18 = (f32) (3.133 / (f64) sqrtf((temp_fs3_10 * temp_fs3_10) + (temp_fs2_12 * temp_fs2_12) + (temp_ft5_7 * temp_ft5_7)));
    temp_fs3_11 = temp_fs3_10 * temp_fv1_18;
    temp_fs2_13 = temp_fs2_12 * temp_fv1_18;
    arg1->unk48.unk0.x = (f32) (temp_fs3_11 + temp_fs0_10);
    temp_ft5_8 = temp_ft5_7 * temp_fv1_18;
    temp_fa0_23 = arg1->unkD8.unk0.z + arg1->unkD8.unkC.z;
    arg1->unk48.unk0.y = (f32) (temp_fs2_13 + temp_ft4_7);
    arg1->unkB4.unk0.x = (f32) (temp_fs0_10 - temp_fs3_11);
    arg1->unk48.unk0.z = (f32) (temp_ft5_8 + temp_fa0_23);
    arg1->unkB4.unk0.y = (f32) (temp_ft4_7 - temp_fs2_13);
    arg1->unkB4.unk0.z = (f32) (temp_fa0_23 - temp_ft5_8);
    spE4 = temp_fs3_11;
    spE0 = temp_fs2_13;
    spDC = temp_ft5_8;
    func_80052A20(&arg1->unkD8);
    RIDER_PARTS(temp_s1)[9].unk10.x = (RIDER_PARTS(temp_s1)[9].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[9].unk4.x;
    RIDER_PARTS(temp_s1)[9].unk10.y = (RIDER_PARTS(temp_s1)[9].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[9].unk4.y + (0.5f * D_800D4A18);
    RIDER_PARTS(temp_s1)[9].unk10.z = (RIDER_PARTS(temp_s1)[9].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[9].unk4.z;
    RIDER_PARTS(temp_s1)[17].unk10.x = (RIDER_PARTS(temp_s1)[17].unk1C.x * D_800D4A1C) + RIDER_PARTS(temp_s1)[17].unk4.x;
    RIDER_PARTS(temp_s1)[17].unk10.y = (RIDER_PARTS(temp_s1)[17].unk1C.y * D_800D4A1C) + RIDER_PARTS(temp_s1)[17].unk4.y + (0.5f * D_800D4A18);
    RIDER_PARTS(temp_s1)[17].unk10.z = (RIDER_PARTS(temp_s1)[17].unk1C.z * D_800D4A1C) + RIDER_PARTS(temp_s1)[17].unk4.z;
    temp_fs3_12 = arg1->unk48.unk0.x - arg1->unkB4.unk0.x;
    temp_fs1_15 = arg1->unk48.unk0.y - arg1->unkB4.unk0.y;
    spDC = temp_ft5_8;
    temp_fs2_14 = arg1->unk48.unk0.z - arg1->unkB4.unk0.z;
    temp_fv1_19 = 0.5f / sqrtf((temp_fs3_12 * temp_fs3_12) + (temp_fs1_15 * temp_fs1_15) + (temp_fs2_14 * temp_fs2_14));
    var_ft5 = temp_ft5_8;
    temp_fa1_8 = temp_fs3_12 * temp_fv1_19;
    temp_ft4_8 = temp_fs1_15 * temp_fv1_19;
    temp_fs0_11 = temp_fs2_14 * temp_fv1_19;
    RIDER_PARTS(temp_s1)[9].unk10.x += temp_fa1_8;
    RIDER_PARTS(temp_s1)[9].unk10.y += temp_ft4_8;
    RIDER_PARTS(temp_s1)[9].unk10.z += temp_fs0_11;
    RIDER_PARTS(temp_s1)[17].unk10.x -= temp_fa1_8;
    RIDER_PARTS(temp_s1)[17].unk10.y -= temp_ft4_8;
    RIDER_PARTS(temp_s1)[17].unk10.z -= temp_fs0_11;
    var_fs3 = RIDER_PARTS(temp_s1)[9].unk10.x - arg1->unk48.unk0.x;
    var_fs1 = RIDER_PARTS(temp_s1)[9].unk10.y - arg1->unk48.unk0.y;
    var_fs2 = RIDER_PARTS(temp_s1)[9].unk10.z - arg1->unk48.unk0.z;
    temp_fs0_12 = (var_fs3 * var_fs3) + (var_fs1 * var_fs1) + (var_fs2 * var_fs2);
    if ((f64) temp_fs0_12 > 1164.505046274025) {
        spDC = var_ft5;
        temp_fv1_20 = (f32) (34.124845 / (f64) sqrtf(temp_fs0_12));
        var_fs3 *= temp_fv1_20;
        var_fs1 *= temp_fv1_20;
        var_fs2 *= temp_fv1_20;
    }
    arg1->unk0.unk0.x = arg1->unk48.unk0.x + var_fs3;
    temp_fv0_12 = arg1->unkB4.unk0.z;
    arg1->unk0.unk0.y = arg1->unk48.unk0.y + var_fs1;
    arg1->unk0.unk0.z = arg1->unk48.unk0.z + var_fs2;
    var_fs3_2 = RIDER_PARTS(temp_s1)[17].unk10.x - arg1->unkB4.unk0.x;
    sp84 = temp_fv0_12;
    var_ft4 = sp84;
    var_fs1_2 = RIDER_PARTS(temp_s1)[17].unk10.y - arg1->unkB4.unk0.y;
    var_fs2_2 = RIDER_PARTS(temp_s1)[17].unk10.z - temp_fv0_12;
    temp_fs0_13 = (var_fs3_2 * var_fs3_2) + (var_fs1_2 * var_fs1_2) + (var_fs2_2 * var_fs2_2);
    if ((f64) temp_fs0_13 > 1164.505046274025) {
        spDC = var_ft5;
        var_ft4 = arg1->unkB4.unk0.z;
        temp_fv1_21 = (f32) (34.124845 / (f64) sqrtf(temp_fs0_13));
        var_fs3_2 *= temp_fv1_21;
        var_fs1_2 *= temp_fv1_21;
        var_fs2_2 *= temp_fv1_21;
    }
    arg1->unk6C.unk0.x = (f32) (arg1->unkB4.unk0.x + var_fs3_2);
    arg1->unk6C.unk0.z = (f32) (var_ft4 + var_fs2_2);
    arg1->unk6C.unk0.y = (f32) (arg1->unkB4.unk0.y + var_fs1_2);
    spDC = var_ft5;
    temp_fv1_22 = 0.1f / sqrtf((spE4 * spE4) + (spE0 * spE0) + (var_ft5 * var_ft5));
    temp_s1_2 = &arg1->unk24;
    temp_fs1_16 = spE4 * temp_fv1_22;
    temp_fs0_14 = spE0 * temp_fv1_22;
    temp_ft5_9 = var_ft5 * temp_fv1_22;
    spDC = temp_ft5_9;
    func_800534AC(temp_s1_2, &arg1->unk24.unk0.y, &arg1->unk24.unk0.z, arg1->unk48.unk0.x, arg1->unk48.unk0.y, arg1->unk48.unk0.z, arg1->unk0.unk0.x, arg1->unk0.unk0.y, arg1->unk0.unk0.z, 298.01123f, 355.76913f, arg1->unkD8.unk14.x + temp_fs1_16, arg1->unkD8.unk14.y + temp_fs0_14, arg1->unkD8.unk14.z + temp_ft5_9);
    temp_s2_2 = &arg1->unk90;
    func_800534AC(temp_s2_2, &arg1->unk90.unk0.y, &arg1->unk90.unk0.z, arg1->unkB4.unk0.x, arg1->unkB4.unk0.y, arg1->unkB4.unk0.z, arg1->unk6C.unk0.x, arg1->unk6C.unk0.y, arg1->unk6C.unk0.z, 298.01123f, 355.76913f, arg1->unkD8.unk14.x - temp_fs1_16, arg1->unkD8.unk14.y - temp_fs0_14, arg1->unkD8.unk14.z - temp_ft5_9);
    temp_fa1_9 = arg1->unk24.unk0.x;
    temp_fv0_13 = arg1->unk24.unk0.y;
    temp_fa0_24 = temp_fa1_9 - arg1->unk48.unk0.x;
    arg1->unk48.unkC.x = temp_fa0_24;
    arg1->unk0.unkC.x = temp_fa0_24;
    temp_fa0_25 = temp_fv0_13 - arg1->unk48.unk0.y;
    temp_fs2_15 = arg1->unk90.unk0.y;
    temp_fs3_13 = arg1->unk90.unk0.z;
    arg1->unk48.unkC.y = temp_fa0_25;
    arg1->unk0.unkC.y = temp_fa0_25;
    temp_fa0_26 = arg1->unk24.unk0.z - arg1->unk48.unk0.z;
    temp_ft4_9 = arg1->unk0.unk0.x;
    arg1->unk48.unkC.z = temp_fa0_26;
    arg1->unk0.unkC.z = temp_fa0_26;
    temp_fa0_27 = arg1->unk90.unk0.x - arg1->unkB4.unk0.x;
    temp_fs0_15 = arg1->unk24.unk0.z;
    arg1->unkB4.unkC.x = temp_fa0_27;
    arg1->unk6C.unkC.x = temp_fa0_27;
    temp_fa0_28 = temp_fs2_15 - arg1->unkB4.unk0.y;
    temp_ft5_10 = arg1->unk6C.unk0.x;
    temp_fs1_17 = arg1->unk90.unk0.x;
    arg1->unkB4.unkC.y = temp_fa0_28;
    arg1->unk6C.unkC.y = temp_fa0_28;
    temp_fa0_29 = temp_fs3_13 - arg1->unkB4.unk0.z;
    arg1->unk24.unkC.y = (f32) (arg1->unk0.unk0.y - temp_fv0_13);
    arg1->unk24.unkC.x = (f32) (temp_ft4_9 - temp_fa1_9);
    arg1->unkB4.unkC.z = temp_fa0_29;
    arg1->unk6C.unkC.z = temp_fa0_29;
    temp_fa0_30 = arg1->unk0.unk0.z;
    arg1->unk90.unkC.y = (f32) (arg1->unk6C.unk0.y - temp_fs2_15);
    arg1->unk24.unkC.z = (f32) (temp_fa0_30 - temp_fs0_15);
    arg1->unk90.unkC.x = (f32) (temp_ft5_10 - temp_fs1_17);
    arg1->unk90.unkC.z = (f32) (arg1->unk6C.unk0.z - temp_fs3_13);
    temp_fv0_14 = (f32) ((f64) temp_fa1_9 - (0.5 * (f64) (arg1->unk48.unk0.x + temp_ft4_9)));
    arg1->unk24.unk14.x = temp_fv0_14;
    arg1->unk48.unk14.x = temp_fv0_14;
    arg1->unk0.unk14.x = temp_fv0_14;
    temp_fv0_15 = (f32) ((f64) arg1->unk24.unk0.y - (0.5 * (f64) (arg1->unk48.unk0.y + arg1->unk0.unk0.y)));
    arg1->unk24.unk14.y = temp_fv0_15;
    arg1->unk48.unk14.y = temp_fv0_15;
    arg1->unk0.unk14.y = temp_fv0_15;
    temp_fv0_16 = (f32) ((f64) temp_fs0_15 - (0.5 * (f64) (arg1->unk48.unk0.z + temp_fa0_30)));
    arg1->unk24.unk14.z = temp_fv0_16;
    arg1->unk48.unk14.z = temp_fv0_16;
    arg1->unk0.unk14.z = temp_fv0_16;
    temp_fv0_17 = (f32) ((f64) temp_fs1_17 - (0.5 * (f64) (arg1->unkB4.unk0.x + temp_ft5_10)));
    arg1->unk90.unk14.x = temp_fv0_17;
    arg1->unkB4.unk14.x = temp_fv0_17;
    arg1->unk6C.unk14.x = temp_fv0_17;
    temp_fv0_18 = (f32) ((f64) arg1->unk90.unk0.y - (0.5 * (f64) (arg1->unkB4.unk0.y + arg1->unk6C.unk0.y)));
    arg1->unk90.unk14.y = temp_fv0_18;
    arg1->unkB4.unk14.y = temp_fv0_18;
    arg1->unk6C.unk14.y = temp_fv0_18;
    temp_fv0_19 = (f32) ((f64) arg1->unk90.unk0.z - (0.5 * (f64) (arg1->unkB4.unk0.z + arg1->unk6C.unk0.z)));
    arg1->unk90.unk14.z = temp_fv0_19;
    arg1->unkB4.unk14.z = temp_fv0_19;
    arg1->unk6C.unk14.z = temp_fv0_19;
    func_80052A20(&arg1->unk48);
    func_80052A20(&arg1->unkB4);
    func_80052A20(temp_s1_2);
    func_80052A20(temp_s2_2);
    func_80052A20(&arg1->unk0);
    func_80052A20(&arg1->unk6C);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8005B510.s")
#endif

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
            func_8005B510(arg0, arg1);
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

#ifdef NON_MATCHING
// Score 94453 of 280200: far off in registers and scheduling (0x138 bytes shorter); kept for reading. Control flow
// follows the original: the pose-buffer rotation (unk1420/1424/1428), the unk16C8 choice by game mode, the unk1608 /
// unk16E0 timers and the unkC54 cases that pick the next func_80053EAC state, the func_8005CD24 frame step and
// blend, then the per-entry update by state word, the link passes (D_800D4A08/D_800D4A0C times) and the copy of the
// entries into the pose.
void func_8005DE24(s32 arg0) {
    UnkStruct_80192690* rider;
    RiderPart* part;
    RiderPart* first;
    RiderPart* last;
    RiderPart* a;
    RiderPart* b;
    RiderLink* link;
    UnkStruct_8004B0F8_1* pt;
    UnkStruct_80052E90_arg1_s* pose;
    s16* seq;
    s16* e;
    s32 i;
    s32 frame;
    f32 sp80;
    f32 sp8C;
    f32 sp90;
    f32 spC0;
    f32 spC4;
    s32 spEC;
    struct UnkStruct_801C2938* temp_a0;
    struct UnkStruct_801C2938* temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa0_7;
    f32 temp_fa0_8;
    f32 temp_fa0_9;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fa1_5;
    f32 temp_fa1_6;
    f32 temp_fa1_7;
    f32 temp_fa1_8;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fs0_7;
    f32 temp_fs0_8;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs1_3;
    f32 temp_fs1_4;
    f32 temp_fs1_5;
    f32 temp_fs1_6;
    f32 temp_fs2;
    f32 temp_fs2_2;
    f32 temp_fs2_3;
    f32 temp_fs2_4;
    f32 temp_fs2_5;
    f32 temp_fs3;
    f32 temp_fs3_2;
    f32 temp_fs3_3;
    f32 temp_fs3_4;
    f32 temp_fs4;
    f32 temp_fs4_2;
    f32 temp_fs4_3;
    f32 temp_fs4_4;
    f32 temp_fs4_5;
    f32 temp_fs4_6;
    f32 temp_fs5;
    f32 temp_fs5_2;
    f32 temp_ft4;
    f32 temp_ft4_10;
    f32 temp_ft4_11;
    f32 temp_ft4_12;
    f32 temp_ft4_13;
    f32 temp_ft4_14;
    f32 temp_ft4_15;
    f32 temp_ft4_2;
    f32 temp_ft4_3;
    f32 temp_ft4_4;
    f32 temp_ft4_5;
    f32 temp_ft4_6;
    f32 temp_ft4_7;
    f32 temp_ft4_8;
    f32 temp_ft4_9;
    f32 temp_ft5;
    f32 temp_ft5_2;
    f32 temp_ft5_3;
    f32 temp_ft5_4;
    f32 temp_ft5_5;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_10;
    f32 temp_fv1_11;
    f32 temp_fv1_12;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_8;
    f32 temp_fv1_9;
    u16 temp_t1;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t7;
    u16 temp_t7_2;
    s32 temp_t8;
    s32 temp_t9;
    u16 temp_v0;
    s32 temp_v0_12;
    s8 temp_v0_13;
    s8 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_16;
    s32 temp_v0_17;
    u16 temp_v0_2;
    s32 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_6;
    s8 temp_v0_7;
    s8 temp_v0_8;
    s32 temp_v0_9;
    struct UnkStruct_801C2938* temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    struct UnkStruct_801C2938* temp_v1_4;
    struct UnkStruct_801C2938* temp_v1_5;
    struct UnkStruct_801C2938* temp_v1_6;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    f32 var_fs4;
    f32 var_ft4;
    f32 var_ft4_2;
    f32 var_ft4_3;
    f32 var_ft4_4;
    f32 var_ft5;

    rider = &D_80192690[arg0];
    if (gRiderGameModes == PAUSE_MODE) {
        func_8005DACC(arg0, (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424]);
        return;
    }
    temp_t9 = rider->unk1428;
    rider->unk1428 = rider->unk1420;
    rider->unk1420 = rider->unk1424;
    rider->unk1424 = temp_t9;
    temp_fv0 = rider->unk158C * ((rider->unk84 * rider->unkC20) + (rider->unk88 * rider->unkC24) + (rider->unk8C * rider->unkC28));
    rider->unk16B8 = temp_fv0;
    if (temp_fv0 < -1.0f) {
        rider->unk16B8 = -1.0f;
    } else if (rider->unk16B8 > 1.0f) {
        rider->unk16B8 = 1.0f;
    }
    temp_fv1 = rider->unkC0C;
    temp_fs4 = (rider->unkC00 + (D_800D4A24 * ((rider->unk78 * rider->unkC2C) + (rider->unk7C * rider->unkC30) + (rider->unk80 * rider->unkC34)))) - temp_fv1;
    if (temp_fs4 < 0.0f) {
        rider->unkC0C = temp_fv1 + (temp_fs4 * D_800D4A30);
    } else {
        rider->unkC0C = temp_fv1 + (temp_fs4 * D_800D4A34);
    }
    if (rider->unkC0C < 10.0f) {
        rider->unkC0C = 10.0f;
    }
    temp_fv0_2 = rider->unkC10;
    rider->unk16BC = rider->unkC0C / rider->unkC00;
    rider->unkC10 = temp_fv0_2 + ((((f32) ((f64) (((rider->unk6C * rider->unkC2C) + (rider->unk70 * rider->unkC30) + (rider->unk74 * rider->unkC34)) * D_800D4A28) + -27.300001) - temp_fv0_2) * D_800D4A38) + ((f32) rider->unkB5F / D_800D49E0));
    rider->unk16C0 = (f32) ((f64) rider->unkC10 / -27.300001);
    if (rider->unk16C8 < 0) {
        temp_v1 = &gRiderRaceState[arg0];
        if (temp_v1->unk2F4 != 0) {
            if (gGameModes == GMODE_TIME_TRIALS) {
                if (D_801C2650 == 1) {
                    rider->unk16C8 = 6;
                } else {
                    rider->unk16C8 = 3;
                }
            } else if (gGameModes == GMODE_STUNT) {
                if (D_801C2928 == 0) {
                    rider->unk16C8 = 3;
                } else if (D_801C2928 == 1) {
                    rider->unk16C8 = 1;
                } else {
                    rider->unk16C8 = 2;
                }
            } else if (gPlayers == ONE_PLAYER) {
                if (D_801CB3F8[arg0] == 0) {
                    rider->unk16C8 = 4;
                } else {
                    temp_t7 = D_800D4800[temp_v1->unk4];
                    rider->unk16C8 = temp_t7;
                    if (temp_t7 == 4) {
                        rider->unk16C8 = 3;
                    }
                }
            } else {
                temp_a0 = &gRiderRaceState[gPlayer1Rider];
                if ((temp_a0->unk2F4 != 0) && (temp_a1 = &gRiderRaceState[gPlayer2Rider], (temp_a1->unk2F4 != 0)) && (temp_a0->raceTime == temp_a1->raceTime)) {
                    D_80192690[gPlayer2Rider].unk16C8 = 3;
                    D_80192690[gPlayer1Rider].unk16C8 = 3;
                } else {
                    D_80192690[gPlayer1Rider].unk16C8 = D_800D4818[temp_a0->unk4];
                    D_80192690[gPlayer2Rider].unk16C8 = D_800D4818[gRiderRaceState[gPlayer2Rider].unk4];
                }
            }
        } else if ((temp_v1->finishState != 0) && (gRiderGameModes != UNACTIVE_MODE)) {
            if (gPlayers == ONE_PLAYER) {
                if (func_8005DD04(rider->unk90[0].unk0, rider->unk90[0].unk4, rider->unk90[0].unk8) != 0) {
                    rider->unk16C8 = 4;
                } else {
                    rider->unk16C8 = 5;
                }
            } else if ((gRiderRaceState[gPlayer1Rider].finishState != 0) && (gRiderRaceState[gPlayer2Rider].finishState != 0)) {
                D_80192690[gPlayer2Rider].unk16C8 = 3;
                D_80192690[gPlayer1Rider].unk16C8 = 3;
            } else if (arg0 == gPlayer1Rider) {
                D_80192690[gPlayer1Rider].unk16C8 = 4;
                D_80192690[gPlayer2Rider].unk16C8 = 1;
            } else {
                D_80192690[gPlayer1Rider].unk16C8 = 1;
                D_80192690[gPlayer2Rider].unk16C8 = 4;
            }
        } else if (D_8022393C != 0) {
            rider->unk16C8 = D_800D4800[D_8022393C - 1];
        }
    }
    temp_v0 = rider->unk1608;
    temp_v1_2 = rider->unkB64;
    if (temp_v0 != 0) {
        temp_t7_2 = temp_v0 - 1;
        rider->unk1608 = temp_t7_2;
        if (!(temp_t7_2 & 0xFFFF)) {
            func_80053EAC(arg0, 0x17, 0, 1.0f, 0U);
            for (part = &RIDER_PARTS(rider)[18]; part >= &RIDER_PARTS(rider)[0]; part--) {
                part->unk1C.x *= 0.8f;
                part->unk1C.z *= 0.8f;
                if ((part->unk1C.y < 0.0f) && (rider->unk7C > 0.6f)) {
                    part->unk1C.y = 0.0f;
                }
            }
            rider->unkC74 = -1;
            rider->unkC70 = -1;
        }
    } else {
        temp_v0_2 = rider->unk16E0;
        temp_t1 = temp_v0_2 - 1;
        if (temp_v0_2 != 0) {
            rider->unk16E0 = temp_t1;
            if (!(temp_t1 & 0xFFFF) || (rider->unk1598 != 0)) {
                func_80053EAC(arg0, 0x18, 0, 1.0f, 1U);
                first = &RIDER_PARTS(rider)[0];
                for (part = &RIDER_PARTS(rider)[18]; part >= first; part--) {
                    part->unk1C.x *= 0.8f;
                    part->unk1C.z *= 0.8f;
                    if ((part->unk1C.y < 0.0f) && (rider->unk7C > 0.6f)) {
                        part->unk1C.y = 0.0f;
                    }
                    part->unk1C.x -= rider->unk6C;
                    part->unk1C.y -= rider->unk70;
                    part->unk1C.z -= rider->unk74;
                }
                rider->unkC74 = -1;
                rider->unkC70 = -1;
                rider->unk1602 = 0;
                rider->unk16E0 = 0;
            } else {
                temp_fv0_3 = (&D_800D4938)[1]; // FAKE: D_800D493C has no symbol of its own
                if (((D_800D93C0[temp_v1_2] * (1.0f - temp_fv0_3)) + temp_fv0_3) < rider->unk7C) {
                    rider->unk16E0 = 0;
                    rider->unk1602 = 0;
                }
            }
        } else {
            temp_fv1_2 = rider->unkB90;
            if ((((temp_fv1_2 > 22.222223f) && (gRiderRaceState[arg0].unk2F4 == 0) &&
                  ((temp_fv0_4 = rider->unk169C, (temp_fv0_4 < rider->unkC38)) || (temp_fv0_4 < rider->unkC50) ||
                   (rider->unk16A0 < rider->unkC3C) || (rider->unk16A4 < rider->unkC44) ||
                   (rider->unk16A8 < rider->unkC4C) || (rider->unk16AC < rider->unkC48))) ||
                 ((temp_v0_3 = rider->unkC78, (temp_v0_3 > 0)) && (temp_v0_3 < 8) && (rider->unk7C < D_800D9350[temp_v1_2])) ||
                 (rider->unk16B0 < rider->unkC40)) &&
                (temp_a2 = rider->unkC54, (temp_a2 != 7)) && (temp_a2 != 0x17)) {
                pt = &rider->unk90[11];
                rider->unk1608 = (u16) D_800D497C;
                if ((u16) rider->unk160A == 0) {
                    for (; pt >= &rider->unk90[0]; pt--) {
                        pt->unk18 = 0.999f;
                        temp_fa1 = rider->unk15B4;
                        temp_fv0_5 = pt->unkC;
                        temp_fv1_3 = pt->unk10;
                        temp_fa0 = pt->unk14;
                        temp_fs4_2 = ((temp_fa1 * temp_fv0_5) + (rider->unk15B8 * temp_fv1_3) + (rider->unk15BC * temp_fa0)) * -1.0f;
                        pt->unkC = (temp_fv0_5 * 1.5f) + (temp_fs4_2 * temp_fa1);
                        pt->unk10 = (temp_fv1_3 * 1.5f) + (temp_fs4_2 * rider->unk15B8);
                        pt->unk14 = (temp_fa0 * 1.5f) + (temp_fs4_2 * rider->unk15BC);
                    }
                    rider->unk160A = 1;
                }
                if ((u16) rider->unk1602 == 0) {
                    rider->unk1602 = 1;
                }
            } else {
                temp_a2_2 = rider->unkC54;
                if ((temp_a2_2 == 0x16) || (temp_a2_2 == 0xF)) {
                    temp_a1_2 = rider->unk16C8;
                    if ((temp_a1_2 >= 0) && (temp_v0_4 = rider->unk1446, (temp_v0_4 >= 0))) {
                        if (temp_v0_4 == 0) {
                            func_80053EAC(arg0, temp_a1_2, 1, 0.15f, 1U);
                        } else {
                            rider->unk1446 = temp_v0_4 - 1;
                        }
                    } else if ((((temp_fv1_2 > 22.222223f) && (gRiderRaceState[arg0].unk2F4 == 0) &&
                                 ((D_800D9360[temp_v1_2] < rider->unkC50) || (D_800D9370[temp_v1_2] < rider->unkC3C) ||
                                  (D_800D9390[temp_v1_2] < rider->unkC44) || (D_800D93B0[temp_v1_2] < rider->unkC4C) ||
                                  (D_800D93A0[temp_v1_2] < rider->unkC48))) ||
                                (D_800D9380[temp_v1_2] < rider->unkC40)) &&
                               (temp_a2_2 != 7) && (temp_a2_2 != 0x18)) {
                        rider->unk16E0 = 1;
                    } else if ((((temp_fv1_2 > 22.222223f) && (gRiderRaceState[arg0].unk2F4 == 0) && (D_800D9360[temp_v1_2] < rider->unkC38)) ||
                                ((rider->unkC7C != 0) && (rider->unk7C < D_800D93C0[temp_v1_2]))) &&
                               (temp_a2_2 != 7) && (temp_a2_2 != 0x18)) {
                        rider->unk16E0 = (u16) D_800D4980;
                        if ((u16) rider->unk1602 == 0) {
                            rider->unk1602 = 2;
                        }
                    } else if (rider->unk1598 == 3) {
                        func_80053EAC(arg0, 0x19, 0, 0.15f, 0U);
                    } else if ((!(rider->unkB56 & 0xA000) && (rider->unkB50.stick_y >= 0x46) &&
                                ((u32) (gFrameCounter - rider->unk15F0) < (u32) D_800D4944) && ((u16) rider->unk1600 == 0)) ||
                               (temp_v0_6 = rider->unk16F4, (temp_v0_6 == 1))) {
                        rider->unk16F4 = 0;
                        if ((rider->unk16CC == 0) && (gGameModeState == GMODE_STATE_STARTED)) {
                            func_80053EAC(arg0, 8, 1, 0.15f, 1U);
                        }
                    } else if (((s32) rider->unk15FA >= 4) || (temp_v0_6 == 2)) {
                        rider->unk16F4 = 0;
                        if ((rider->unk16CC == 0) && (gGameModeState == GMODE_STATE_STARTED)) {
                            func_80053EAC(arg0, 9, 1, 0.15f, 1U);
                        }
                    } else if (((s32) rider->unk15F8 >= 4) || (temp_v0_6 == 9)) {
                        rider->unk16F4 = 0;
                        if ((rider->unk16CC == 0) && (gGameModeState == GMODE_STATE_STARTED)) {
                            func_80053EAC(arg0, 0x11, 1, 0.15f, 1U);
                        }
                    } else if ((temp_a2_2 == 0x16) && (rider->unk16CC == 0) && (temp_fv1_2 < 2.777778f) && ((f64) rider->unk7C > 0.95)) {
                        temp_v0_7 = rider->unkB5E;
                        if ((temp_v0_7 < 0xC) && (temp_v0_7 >= -0xB)) {
                            temp_v0_8 = rider->unkB5F;
                            if ((temp_v0_8 < 0xC) && (temp_v0_8 >= -0xB)) {
                                temp_t2 = rider->unkC6C + 1;
                                rider->unkC6C = temp_t2;
                                if (D_800D4998 < temp_t2) {
                                    temp_v1_3 = SysUtils_Rand() & 3;
                                    rider->unk16C4 = temp_v1_3;
                                    if ((temp_v1_3 == 0) || (temp_v1_3 == 1)) {
                                        func_80053EAC(arg0, 0xA, 0x1A, 1.0f, 1U);
                                    } else {
                                        func_80053EAC(arg0, 0xA, 1, 1.0f, 1U);
                                    }
                                }
                            }
                        }
                    }
                } else if (temp_a2_2 == 0x18) {
                    if (((rider->unkC7C != 0) || (rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) &&
                        ((temp_t8 = rider->unk1574 + 1, rider->unk1574 = temp_t8, (temp_t8 >= 0x29)) ||
                         ((temp_t8 >= 0xB) && ((rider->unkC66 == 0) || (rider->unkB90 < 11.111112f))))) {
                        if (rider->unk16CC == 0) {
                            rider->unk157C = 1;
                            func_80053EAC(arg0, 7, 0x39, 0.15f, 0U);
                        } else {
                            func_80053EAC(arg0, 0x16, 0, 0.075f, 0U);
                        }
                    }
                } else if (temp_a2_2 == 0x17) {
                    temp_v0_9 = rider->unkC74;
                    if (temp_v0_9 < 0) {
                        if (RIDER_PARTS(rider)[2].unk4.y < (f32) gWaterLevel) {
                            rider->unkC74 = 0;
                        }
                    } else {
                        part = &RIDER_PARTS(rider)[18];
                        temp_t6 = temp_v0_9 + D_800D4994;
                        rider->unkC74 = temp_t6;
                        if ((temp_t6 >= 0x64) || ((temp_t6 >= D_800D4990) && (rider->unkC78 >= 8) && (rider->unk7C > 0.9f) && (rider->unkB90 < 8.333334f))) {
                            for (; part >= &RIDER_PARTS(rider)[0]; part--) {
                                part->unk1C.z = 0.0f;
                                part->unk1C.y = 0.0f;
                                part->unk1C.x = 0.0f;
                            }
                            rider->unk157C = 0;
                            if (func_80053EAC(arg0, 7, 0, 1.0f, 0U) == 0) {
                                rider->unkC74 = -1;
                            }
                            if ((u16) rider->unk1602 != 0) {
                                rider->unk1602 = 0;
                            }
                        }
                    }
                } else if (temp_a2_2 == 0x19) {
                    if (rider->unk1598 == 0) {
                        func_80053EAC(arg0, 0x16, 0, 0.15f, 0U);
                        rider->unkC70 = -1;
                    }
                } else if ((temp_a2_2 == 5) && (rider->unkC58 == 0x1D)) {
                    func_800AF40C(RIDER_PARTS(rider)[2].unk4.x, RIDER_PARTS(rider)[2].unk4.y, 0x16, RIDER_PARTS(rider)[2].unk4.z);
                }
            }
        }
    }
    last = &RIDER_PARTS(rider)[18];
    first = &RIDER_PARTS(rider)[0];
    part = last;
    frame = func_8005CD24(arg0, (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424], rider->unkC54, rider->unkC58);
    spEC = frame;
    if (rider->unk142C != 0.0f) {
        if (frame >= 0) {
            rider->unkC58 = frame;
        }
        temp_v0_12 = func_8005CD24(arg0, (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1428], rider->unkC5C, rider->unkC60);
        if ((rider->unkC64 == 0) && (temp_v0_12 >= 0)) {
            rider->unkC60 = temp_v0_12;
        }
        pose = (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424];
        func_80053A5C(pose, rider->unk142C, pose, (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1428]);
        rider->unk142C += rider->unk1430;
        if (rider->unk142C >= 1.0f) {
            temp_a1_3 = rider->unkC5C;
            rider->unk142C = 0.0f;
            rider->unkC5C = -1;
            rider->unkC54 = temp_a1_3;
            rider->unkC58 = rider->unkC60;
            Rider_SetPartsState(arg0, temp_a1_3);
        }
    } else if (frame < 0) {
        temp_a2_3 = rider->unkC54;
        if ((temp_a2_3 > 0) && (temp_a2_3 < 7)) {
            rider->unk1446 = -1;
        }
        if (rider->unkC54 == 5) {
            rider->unk157C = 0;
            func_80053EAC(arg0, 7, 0, 0.05f, 1U);
        } else if ((rider->unkC54 >= 0x12) && (rider->unkC54 < 0x16)) {
            // FAKE: the s16 sequence table sits at gColorRed's address in the symbol map
            rider->unkC58 = ((s16**) &gColorRed)[rider->unkC54][0] - 1;
        } else {
            func_80053EAC(arg0, 0x16, 0, 0.15f, 0U);
        }
    } else {
        temp_a2_4 = rider->unkC54;
        if (temp_a2_4 == 0xF) {
            if ((gGameModeState == GMODE_STATE_2) || (gGameModeState == GMODE_STATE_STARTED)) {
                goto block_299; // m2c goto, see the label
            }
        } else if (temp_a2_4 == 7) {
            if (frame >= 0x4D) {
                func_80053EAC(arg0, 0x16, 0, 0.15f, 0U);
            } else if (frame >= 0x38) {
                if ((u16) rider->unk160A != 0) {
                    for (i = 11; i >= 0; i--) {
                        rider->unk90[i].unk18 = rider->unk630[i];
                    }
                    rider->unk160A = 0;
                }
            }
            if (rider->unk157C == 0) {
                if ((rider->unkB58 | rider->unkB5A) & 0xA000) {
                    rider->unkC58 = spEC + 1;
                } else {
                    rider->unkC58 = spEC;
                }
            } else {
                rider->unkC58 = spEC;
            }
        } else if (temp_a2_4 == 0xA) {
            if ((rider->unkB56 != 0) || (temp_v0_13 = rider->unkB5E, (temp_v0_13 >= 0xD)) || (temp_v0_13 < -0xC) ||
                (temp_v0_14 = rider->unkB5F, (temp_v0_14 >= 0xD)) || (temp_v0_14 < -0xC)) {
                func_80053EAC(arg0, 0x16, 0, 0.15f, 0U);
            }
            rider->unkC58 = spEC;
        } else if (temp_a2_4 == 0x11) {
            if (frame == 0x17) {
                rider->unkC58 = frame;
                if ((arg0 == gPlayer1Rider) && (gRiderGameModes != UNACTIVE_MODE)) {
                    func_800C3548();
                }
                for (; part >= first; part--) {
                    part->unk0 = 1;
                }
                part = last;
                rider->unkC68 = 1;
                RIDER_PARTS(rider)[6].unk0 = 2;
                RIDER_PARTS(rider)[14].unk0 = 3;
                RIDER_PARTS(rider)[18].unk0 = 0;
                RIDER_PARTS(rider)[17].unk0 = 0;
                RIDER_PARTS(rider)[10].unk0 = 0;
                RIDER_PARTS(rider)[9].unk0 = 0;
            } else if (frame == 0x18) {
                temp_v1_4 = &gRiderRaceState[arg0];
                if ((temp_v1_4->unk2F4 != 0) || (temp_v1_4->finishState != 0)) {
                    goto block_299; // m2c goto, see the label
                }
                if (rider->unkB50.stick_y < 0x23) {
                    rider->unkC68 = 0;
                    for (; part >= first; part--) {
                        part->unk0 = 0;
                    }
                    part = last;
                    if (rider->unkB50.stick_y < -0x23) {
                        rider->unkC58 = 0x28;
                    } else {
                        goto block_299; // m2c goto, see the label
                    }
                }
            } else {
                goto block_299; // m2c goto, see the label
            }
        } else if (temp_a2_4 == 9) {
            if (frame >= 0x54) {
                RIDER_PARTS(rider)[6].unk0 = 2;
                RIDER_PARTS(rider)[14].unk0 = 3;
            } else if (frame >= 0x3C) {
                RIDER_PARTS(rider)[14].unk0 = 1;
                RIDER_PARTS(rider)[6].unk0 = 1;
            } else if (frame >= 0x17) {
                RIDER_PARTS(rider)[6].unk0 = 3;
                RIDER_PARTS(rider)[14].unk0 = 2;
            }
            if (frame == 0x19) {
                if (rider->unk15F6 & 0x400) {
                    rider->unkC58 = frame;
                } else {
                    rider->unkC58 = 0x3E;
                }
                if ((arg0 == gPlayer1Rider) && (gRiderGameModes != UNACTIVE_MODE)) {
                    func_800C3548();
                }
            } else if (frame == 0x2E) {
                if ((rider->unkB50.stick_y >= -0x22) || (temp_v1_5 = &gRiderRaceState[arg0], (temp_v1_5->unk2F4 != 0)) || (temp_v1_5->finishState != 0)) {
                    goto block_299; // m2c goto, see the label
                }
            } else {
                goto block_299; // m2c goto, see the label
            }
        } else if (temp_a2_4 == 8) {
            if (frame == 0x1E) {
                rider->unkC58 = frame;
                if ((arg0 == gPlayer1Rider) && (gRiderGameModes != UNACTIVE_MODE)) {
                    func_800C3548();
                }
            } else if (frame == 0x1F) {
                if ((rider->unkB50.stick_y < 0x23) || (temp_v1_6 = &gRiderRaceState[arg0], (temp_v1_6->unk2F4 != 0)) || (temp_v1_6->finishState != 0)) {
                    goto block_299; // m2c goto, see the label
                }
            } else {
                goto block_299; // m2c goto, see the label
            }
        } else if ((temp_a2_4 >= 0x12) && (temp_a2_4 < 0x16)) {
            rider->unkC58 = frame;
            // FAKE: the s16 sequence table sits at gColorRed's address in the symbol map
            seq = ((s16**) &gColorRed)[temp_a2_4];
            spEC = 1;
            // Entries of three s16 after the first: (next, frame, repeat count), ended by a 0.
            for (e = &seq[1]; e[0] != 0; e += 3) {
                if (rider->unkC58 == e[1]) {
                    rider->unk16E4++;
                    if (rider->unk16E4 == e[2]) {
                        rider->unk16E4 = 0;
                    } else {
                        rider->unkC58 = e[0] - 1;
                    }
                    break;
                }
            }
        } else {
        block_299: // m2c label name: several cases above end in the plain frame store
            rider->unkC58 = frame;
        }
    }
    func_8005CEF8((UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424], (UnkStruct_8005CEF8*) first);
    temp_v0_15 = rider->unkC68;
    RIDER_PARTS(rider)[19].unk4.x = RIDER_PARTS(rider)[19].unk10.x;
    RIDER_PARTS(rider)[19].unk4.z = RIDER_PARTS(rider)[19].unk10.z;
    RIDER_PARTS(rider)[24].unk4.x = RIDER_PARTS(rider)[24].unk10.x;
    RIDER_PARTS(rider)[19].unk4.y = RIDER_PARTS(rider)[19].unk10.y;
    RIDER_PARTS(rider)[24].unk4.y = RIDER_PARTS(rider)[24].unk10.y;
    RIDER_PARTS(rider)[24].unk4.z = RIDER_PARTS(rider)[24].unk10.z;
    RIDER_PARTS(rider)[20].unk4.y = RIDER_PARTS(rider)[20].unk10.y;
    RIDER_PARTS(rider)[20].unk4.x = RIDER_PARTS(rider)[20].unk10.x;
    RIDER_PARTS(rider)[20].unk4.z = RIDER_PARTS(rider)[20].unk10.z;
    switch (temp_v0_15) {
        case 0:
            RIDER_PARTS(rider)[21].unk4.x = RIDER_PARTS(rider)[21].unk10.x;
            RIDER_PARTS(rider)[21].unk4.z = RIDER_PARTS(rider)[21].unk10.z;
            RIDER_PARTS(rider)[22].unk4.x = RIDER_PARTS(rider)[22].unk10.x;
            RIDER_PARTS(rider)[22].unk4.z = RIDER_PARTS(rider)[22].unk10.z;
            RIDER_PARTS(rider)[21].unk4.y = RIDER_PARTS(rider)[21].unk10.y;
            RIDER_PARTS(rider)[22].unk4.y = RIDER_PARTS(rider)[22].unk10.y;
            RIDER_PARTS(rider)[23].unk4.x = RIDER_PARTS(rider)[23].unk10.x;
            RIDER_PARTS(rider)[23].unk4.y = RIDER_PARTS(rider)[23].unk10.y;
            RIDER_PARTS(rider)[23].unk4.z = RIDER_PARTS(rider)[23].unk10.z;
            break;
        case 1:
            temp_fa0_2 = RIDER_PARTS(rider)[21].unk4.x;
            temp_fs1 = RIDER_PARTS(rider)[21].unk4.y;
            temp_fv1_4 = rider->unk78;
            temp_fs2 = RIDER_PARTS(rider)[21].unk4.z;
            temp_fs3 = RIDER_PARTS(rider)[21].unk10.x - temp_fa0_2;
            temp_fv0_6 = rider->unk7C;
            temp_fa1_2 = RIDER_PARTS(rider)[21].unk10.y - temp_fs1;
            temp_fs0 = rider->unk80;
            temp_ft5 = RIDER_PARTS(rider)[21].unk10.z - temp_fs2;
            temp_ft4 = (RIDER_PARTS(rider)[21].unk1C.z * temp_fs0) + ((temp_fv1_4 * RIDER_PARTS(rider)[21].unk1C.x) + (temp_fv0_6 * RIDER_PARTS(rider)[21].unk1C.y));
            if (temp_ft4 < 0.0f) {
                var_ft4 = temp_ft4 * D_800D49FC;
            } else {
                var_ft4 = temp_ft4 * D_800D49F8;
            }
            temp_ft4_2 = var_ft4 + (((temp_fv1_4 * temp_fs3) + (temp_fv0_6 * temp_fa1_2) + (temp_fs0 * temp_ft5)) * (D_800D49F0 - 1.0f));
            RIDER_PARTS(rider)[21].unk4.x = temp_fa0_2 + (temp_fs3 + (temp_ft4_2 * temp_fv1_4));
            RIDER_PARTS(rider)[21].unk4.y = temp_fs1 + (temp_fa1_2 + (temp_ft4_2 * temp_fv0_6));
            RIDER_PARTS(rider)[21].unk4.z = temp_fs2 + (temp_ft5 + (temp_ft4_2 * temp_fs0));
            break;
    }
    if (rider->unkC68 != 0) {
        temp_ft4_3 = RIDER_PARTS(rider)[24].unk4.x;
        temp_fs4_3 = RIDER_PARTS(rider)[20].unk4.x;
        temp_fv1_5 = RIDER_PARTS(rider)[20].unk4.y;
        temp_ft5_2 = RIDER_PARTS(rider)[24].unk4.y;
        temp_fa0_3 = RIDER_PARTS(rider)[20].unk4.z;
        temp_fv0_7 = RIDER_PARTS(rider)[24].unk4.z;
        sp8C = temp_ft4_3 - RIDER_PARTS(rider)[19].unk4.x;
        temp_fs1_2 = temp_fv1_5 - temp_ft5_2;
        temp_fs2_2 = temp_fa0_3 - temp_fv0_7;
        sp80 = temp_ft5_2 - RIDER_PARTS(rider)[19].unk4.y;
        temp_fs0_2 = temp_fs4_3 - temp_ft4_3;
        sp90 = temp_fv0_7 - RIDER_PARTS(rider)[19].unk4.z;
        temp_fs3_2 = (temp_fs1_2 * sp90) - (temp_fs2_2 * sp80);
        temp_fa1_3 = (temp_fs2_2 * sp8C) - (temp_fs0_2 * sp90);
        temp_ft5_3 = (temp_fs0_2 * sp80) - (temp_fs1_2 * sp8C);
        temp_fs5 = RIDER_PARTS(rider)[21].unk4.x - temp_fs4_3;
        spC4 = RIDER_PARTS(rider)[21].unk4.y - temp_fv1_5;
        var_fs0 = sp8C;
        spC0 = RIDER_PARTS(rider)[21].unk4.z - temp_fa0_3;
        var_fs1 = sp80;
        if (((temp_fs5 * ((sp80 * temp_ft5_3) - (sp90 * temp_fa1_3))) + (spC4 * ((sp90 * temp_fs3_2) - (sp8C * temp_ft5_3))) +
             (spC0 * ((sp8C * temp_fa1_3) - (sp80 * temp_fs3_2)))) < 0.0f) {
            var_fs2 = sp90;
            if (((temp_fs5 * var_fs0) + (spC4 * var_fs1) + (spC0 * var_fs2)) < 0.0f) {
                var_ft4_2 = -41.071f;
            } else {
                var_ft4_2 = 41.071f;
            }
        } else {
            temp_fv1_6 = 1.0f / sqrtf((temp_fs3_2 * temp_fs3_2) + (temp_fa1_3 * temp_fa1_3) + (temp_ft5_3 * temp_ft5_3));
            temp_fs3_3 = temp_fs3_2 * temp_fv1_6;
            temp_fa1_4 = temp_fa1_3 * temp_fv1_6;
            temp_ft5_4 = temp_ft5_3 * temp_fv1_6;
            temp_fa0_4 = (temp_fs5 * temp_fs3_3) + (spC4 * temp_fa1_4) + (spC0 * temp_ft5_4);
            spC4 -= temp_fa0_4 * temp_fa1_4;
            spC0 -= temp_fa0_4 * temp_ft5_4;
            temp_fs4_4 = RIDER_PARTS(rider)[20].unk4.x;
            temp_fv1_7 = RIDER_PARTS(rider)[20].unk4.y;
            temp_fa0_5 = RIDER_PARTS(rider)[20].unk4.z;
            RIDER_PARTS(rider)[21].unk4.x = temp_fs4_4 + (temp_fs5 - (temp_fa0_4 * temp_fs3_3));
            temp_fv0_8 = temp_fv1_7 + spC4;
            var_fs0 = RIDER_PARTS(rider)[21].unk4.x - temp_fs4_4;
            RIDER_PARTS(rider)[21].unk4.y = temp_fv0_8;
            var_fs1 = temp_fv0_8 - temp_fv1_7;
            temp_fa1_5 = temp_fa0_5 + spC0;
            RIDER_PARTS(rider)[21].unk4.z = temp_fa1_5;
            var_ft4_2 = 41.071f;
            var_fs2 = temp_fa1_5 - temp_fa0_5;
        }
        temp_ft4_4 = var_ft4_2 / sqrtf((var_fs0 * var_fs0) + (var_fs1 * var_fs1) + (var_fs2 * var_fs2));
        temp_fv1_8 = RIDER_PARTS(rider)[20].unk4.x + (temp_ft4_4 * var_fs0);
        RIDER_PARTS(rider)[21].unk4.x = temp_fv1_8;
        temp_fa0_6 = RIDER_PARTS(rider)[20].unk4.y + (temp_ft4_4 * var_fs1);
        temp_fa1_6 = RIDER_PARTS(rider)[20].unk4.z + (temp_ft4_4 * var_fs2);
        temp_fs1_3 = temp_fa0_6 - RIDER_PARTS(rider)[21].unk10.y;
        RIDER_PARTS(rider)[21].unk4.y = temp_fa0_6;
        temp_fs0_3 = temp_fv1_8 - RIDER_PARTS(rider)[21].unk10.x;
        RIDER_PARTS(rider)[21].unk4.z = temp_fa1_6;
        temp_fs2_3 = temp_fa1_6 - RIDER_PARTS(rider)[21].unk10.z;
        RIDER_PARTS(rider)[22].unk4.x = RIDER_PARTS(rider)[22].unk10.x + temp_fs0_3;
        RIDER_PARTS(rider)[22].unk4.y = RIDER_PARTS(rider)[22].unk10.y + temp_fs1_3;
        RIDER_PARTS(rider)[22].unk4.z = RIDER_PARTS(rider)[22].unk10.z + temp_fs2_3;
        RIDER_PARTS(rider)[23].unk4.x = RIDER_PARTS(rider)[23].unk10.x + temp_fs0_3;
        RIDER_PARTS(rider)[23].unk4.y = RIDER_PARTS(rider)[23].unk10.y + temp_fs1_3;
        RIDER_PARTS(rider)[23].unk4.z = RIDER_PARTS(rider)[23].unk10.z + temp_fs2_3;
    }
    if (rider->unk15D8 < 1.0f) {
        for (; part >= first; part--) {
            temp_fv0_9 = rider->unk44.x;
            temp_fs0_4 = part->unk10.x - temp_fv0_9;
            temp_fv1_9 = rider->unk78;
            temp_fs1_4 = part->unk10.y - rider->unk44.y;
            temp_fs2_4 = part->unk10.z - rider->unk44.z;
            temp_ft4_5 = (temp_fv1_9 * temp_fs0_4) + (temp_fs1_4 * rider->unk7C) + (temp_fs2_4 * rider->unk80);
            temp_fs4_5 = (f32) ((((f64) temp_ft4_5 - 0.1806645) * (f64) rider->unk15D8) + 0.1806645);
            part->unk10.x = temp_fv0_9 + (temp_fs4_5 * temp_fv1_9) + (temp_fs0_4 - (temp_ft4_5 * temp_fv1_9));
            temp_fv0_10 = rider->unk7C;
            part->unk10.y = rider->unk44.y + (temp_fs4_5 * temp_fv0_10) + (temp_fs1_4 - (temp_ft4_5 * temp_fv0_10));
            temp_fs0_5 = rider->unk80;
            part->unk10.z = rider->unk44.z + (temp_fs4_5 * temp_fs0_5) + (temp_fs2_4 - (temp_ft4_5 * temp_fs0_5));
            part->unk1C.x += D_800D4940 * rider->unk78;
            part->unk1C.y += D_800D4940 * rider->unk7C;
            part->unk1C.z += D_800D4940 * rider->unk80;
        }
        part = last;
        if (rider->unkB56 & 0x4000) {
            rider->unk15D8 += 0.01f;
            if (rider->unk15D8 > 1.0f) {
                rider->unk15D8 = 1.0f;
            }
        } else {
            rider->unk15D8 = 1.0f;
        }
    }
    temp_fs5_2 = rider->unk78;
    spC4 = rider->unk7C;
    spC0 = rider->unk80;
    for (; part >= &RIDER_PARTS(rider)[0]; part--) {
        switch (part->unk0) {
            case 0:
                part->unk4.x = part->unk10.x;
                part->unk4.y = part->unk10.y;
                part->unk4.z = part->unk10.z;
                break;
            case 1:
                var_fs3 = part->unk10.x - part->unk4.x;
                var_fa1 = part->unk10.y - part->unk4.y;
                var_ft5 = part->unk10.z - part->unk4.z;
                temp_fs1_5 = (var_fs3 * var_fs3) + (var_fa1 * var_fa1) + (var_ft5 * var_ft5);
                if ((D_800D4984 * D_800D4984) < temp_fs1_5) {
                    temp_ft4_6 = D_800D4984 / sqrtf(temp_fs1_5);
                    var_fs3 *= temp_ft4_6;
                    var_fa1 *= temp_ft4_6;
                    var_ft5 *= temp_ft4_6;
                    part->unk4.x = part->unk10.x - var_fs3;
                    part->unk4.y = part->unk10.y - var_fa1;
                    part->unk4.z = part->unk10.z - var_ft5;
                }
                temp_ft4_7 = (part->unk1C.x * temp_fs5_2) + (spC4 * part->unk1C.y) + (spC0 * part->unk1C.z);
                if (temp_ft4_7 < 0.0f) {
                    var_ft4_3 = temp_ft4_7 * D_800D49FC;
                } else {
                    var_ft4_3 = temp_ft4_7 * D_800D49F8;
                }
                temp_ft4_8 = var_ft4_3 + (((temp_fs5_2 * var_fs3) + (spC4 * var_fa1) + (spC0 * var_ft5)) * (D_800D49F0 - 1.0f));
                part->unk4.x += var_fs3 + (temp_ft4_8 * temp_fs5_2);
                part->unk4.y += var_fa1 + (temp_ft4_8 * spC4);
                part->unk4.z += var_ft5 + (temp_ft4_8 * spC0);
                break;
            case 2:
                part->unk4.x = RIDER_PARTS(rider)[22].unk4.x;
                part->unk4.y = RIDER_PARTS(rider)[22].unk4.y;
                part->unk4.z = RIDER_PARTS(rider)[22].unk4.z;
                break;
            case 3:
                part->unk4.x = RIDER_PARTS(rider)[23].unk4.x;
                part->unk4.y = RIDER_PARTS(rider)[23].unk4.y;
                part->unk4.z = RIDER_PARTS(rider)[23].unk4.z;
                break;
            case 4:
            case 5:
                temp_fv1_10 = part->unk4.x;
                temp_fa0_7 = part->unk4.y;
                temp_fs3_4 = part->unk10.x - temp_fv1_10;
                temp_fs0_6 = part->unk4.z;
                temp_fa1_7 = part->unk10.y - temp_fa0_7;
                temp_ft5_5 = part->unk10.z - temp_fs0_6;
                temp_ft4_9 = (part->unk1C.x * temp_fs5_2) + (spC4 * part->unk1C.y) + (spC0 * part->unk1C.z);
                if (temp_ft4_9 < 0.0f) {
                    var_ft4_4 = temp_ft4_9 * D_800D49FC;
                } else {
                    var_ft4_4 = temp_ft4_9 * D_800D49F8;
                }
                temp_ft4_10 = var_ft4_4 + (((temp_fs5_2 * temp_fs3_4) + (spC4 * temp_fa1_7) + (spC0 * temp_ft5_5)) * (D_800D49F0 - 1.0f));
                part->unk4.x = temp_fv1_10 + (temp_fs3_4 + (temp_ft4_10 * temp_fs5_2));
                temp_fv1_11 = part->unk4.x;
                part->unk4.y = temp_fa0_7 + (temp_fa1_7 + (temp_ft4_10 * spC4));
                temp_fa0_8 = part->unk4.y;
                part->unk4.z = temp_fs0_6 + (temp_ft5_5 + (temp_ft4_10 * spC0));
                temp_fs0_7 = part->unk4.z;
                temp_ft4_11 = ((temp_fv1_11 - rider->unk44.x) * temp_fs5_2) + ((temp_fa0_8 - rider->unk44.y) * spC4) + ((temp_fs0_7 - rider->unk44.z) * spC0);
                if (part->unk0 == 4) {
                    var_fs4 = 0.107405f;
                } else {
                    var_fs4 = 3.107405f;
                }
                if (temp_ft4_11 < var_fs4) {
                    temp_ft4_12 = var_fs4 - temp_ft4_11;
                    part->unk4.x = temp_fv1_11 + (temp_ft4_12 * temp_fs5_2);
                    part->unk4.y = temp_fa0_8 + (temp_ft4_12 * spC4);
                    part->unk4.z = temp_fs0_7 + (temp_ft4_12 * spC0);
                }
                break;
        }
    }
    temp_fs4_6 = 0.5f / ((D_800D4A04 * 17.0f) + 1.0f);
    if ((arg0 == gPlayer1Rider) || ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider))) {
        spEC = D_800D4A08;
    } else {
        spEC = D_800D4A0C;
    }
    if (spEC != 0) {
        do {
            for (part = last; part >= first; part--) {
                part->unk1C.z = 0.0f;
                part->unk1C.y = 0.0f;
                part->unk1C.x = 0.0f;
            }
            // Pull each linked pair of entries toward the link's length; entries in state 0, 2 or 3 stay put.
            for (link = &RIDER_LINKS(rider)[21]; link >= &RIDER_LINKS(rider)[0]; link--) {
                a = link->unk0;
                b = link->unk4;
                temp_fs0_8 = b->unk4.x - a->unk4.x;
                temp_fs1_6 = b->unk4.y - a->unk4.y;
                temp_fs2_5 = b->unk4.z - a->unk4.z;
                temp_v0_16 = a->unk0;
                temp_ft4_13 = (link->unk8 / sqrtf((temp_fs0_8 * temp_fs0_8) + (temp_fs1_6 * temp_fs1_6) + (temp_fs2_5 * temp_fs2_5))) - temp_fs4_6;
                if ((temp_v0_16 == 0) || (temp_v0_16 == 2) || (temp_v0_16 == 3)) {
                    temp_ft4_14 = temp_ft4_13 * 2.0f;
                    b->unk1C.x += temp_ft4_14 * temp_fs0_8;
                    b->unk1C.y += temp_ft4_14 * temp_fs1_6;
                    b->unk1C.z += temp_ft4_14 * temp_fs2_5;
                } else {
                    temp_v0_17 = b->unk0;
                    if ((temp_v0_17 == 0) || (temp_v0_17 == 2) || (temp_v0_17 == 3)) {
                        temp_ft4_15 = temp_ft4_13 * 2.0f;
                        a->unk1C.x -= temp_ft4_15 * temp_fs0_8;
                        a->unk1C.y -= temp_ft4_15 * temp_fs1_6;
                        a->unk1C.z -= temp_ft4_15 * temp_fs2_5;
                    } else {
                        temp_fv1_12 = temp_fs0_8 * temp_ft4_13;
                        temp_fa0_9 = temp_fs1_6 * temp_ft4_13;
                        temp_fa1_8 = temp_fs2_5 * temp_ft4_13;
                        b->unk1C.x += temp_fv1_12;
                        b->unk1C.y += temp_fa0_9;
                        b->unk1C.z += temp_fa1_8;
                        a->unk1C.x -= temp_fv1_12;
                        a->unk1C.z -= temp_fa1_8;
                        a->unk1C.y -= temp_fa0_9;
                    }
                }
            }
            for (part = last; part >= first; part--) {
                part->unk4.x += part->unk1C.x;
                part->unk4.y += part->unk1C.y;
                part->unk4.z += part->unk1C.z;
            }
        } while (--spEC != 0);
    }
    func_8005CEF8((UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1420], (UnkStruct_8005CEF8*) first);
    for (part = &RIDER_PARTS(rider)[24]; part >= first; part--) {
        part->unk1C.x = part->unk4.x - part->unk10.x;
        part->unk1C.y = part->unk4.y - part->unk10.y;
        part->unk1C.z = part->unk4.z - part->unk10.z;
    }
    pose = (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424];
    rider->unkC04 = ((RIDER_PARTS(rider)[2].unk4.z - rider->unk44.z) * rider->unk80) +
                    ((rider->unk78 * (RIDER_PARTS(rider)[2].unk4.x - rider->unk44.x)) + (rider->unk7C * (RIDER_PARTS(rider)[2].unk4.y - rider->unk44.y)));
    pose->unkFC.unk0.x = RIDER_PARTS(rider)[1].unk4.x;
    pose->unkFC.unk0.y = RIDER_PARTS(rider)[1].unk4.y;
    pose->unkFC.unk0.z = RIDER_PARTS(rider)[1].unk4.z;
    temp_fv0_11 = RIDER_PARTS(rider)[2].unk4.x;
    pose->unk1F8.unk0.x = temp_fv0_11;
    pose->unkD8.unk0.x = temp_fv0_11;
    temp_fv0_12 = RIDER_PARTS(rider)[2].unk4.y;
    pose->unk1F8.unk0.y = temp_fv0_12;
    pose->unkD8.unk0.y = temp_fv0_12;
    temp_fv0_13 = RIDER_PARTS(rider)[2].unk4.z;
    pose->unk1F8.unk0.z = temp_fv0_13;
    pose->unkD8.unk0.z = temp_fv0_13;
    pose->unk168.unk0.x = RIDER_PARTS(rider)[3].unk4.x;
    pose->unk168.unk0.y = RIDER_PARTS(rider)[3].unk4.y;
    pose->unk168.unk0.z = RIDER_PARTS(rider)[3].unk4.z;
    pose->unk144.unk0.x = RIDER_PARTS(rider)[4].unk4.x;
    pose->unk144.unk0.y = RIDER_PARTS(rider)[4].unk4.y;
    pose->unk144.unk0.z = RIDER_PARTS(rider)[4].unk4.z;
    pose->unk120.unk0.x = RIDER_PARTS(rider)[5].unk4.x;
    pose->unk120.unk0.y = RIDER_PARTS(rider)[5].unk4.y;
    pose->unk120.unk0.z = RIDER_PARTS(rider)[5].unk4.z;
    pose->unk48.unk0.x = RIDER_PARTS(rider)[7].unk4.x;
    pose->unk48.unk0.y = RIDER_PARTS(rider)[7].unk4.y;
    pose->unk48.unk0.z = RIDER_PARTS(rider)[7].unk4.z;
    pose->unk24.unk0.x = RIDER_PARTS(rider)[8].unk4.x;
    pose->unk24.unk0.y = RIDER_PARTS(rider)[8].unk4.y;
    pose->unk24.unk0.z = RIDER_PARTS(rider)[8].unk4.z;
    pose->unk0.unk0.x = RIDER_PARTS(rider)[9].unk4.x;
    pose->unk0.unk0.y = RIDER_PARTS(rider)[9].unk4.y;
    pose->unk0.unk0.z = RIDER_PARTS(rider)[9].unk4.z;
    pose->unk1D4.unk0.x = RIDER_PARTS(rider)[11].unk4.x;
    pose->unk1D4.unk0.y = RIDER_PARTS(rider)[11].unk4.y;
    pose->unk1D4.unk0.z = RIDER_PARTS(rider)[11].unk4.z;
    pose->unk1B0.unk0.x = RIDER_PARTS(rider)[12].unk4.x;
    pose->unk1B0.unk0.y = RIDER_PARTS(rider)[12].unk4.y;
    pose->unk1B0.unk0.z = RIDER_PARTS(rider)[12].unk4.z;
    pose->unk18C.unk0.x = RIDER_PARTS(rider)[13].unk4.x;
    pose->unk18C.unk0.y = RIDER_PARTS(rider)[13].unk4.y;
    pose->unk18C.unk0.z = RIDER_PARTS(rider)[13].unk4.z;
    pose->unkB4.unk0.x = RIDER_PARTS(rider)[15].unk4.x;
    pose->unkB4.unk0.y = RIDER_PARTS(rider)[15].unk4.y;
    pose->unkB4.unk0.z = RIDER_PARTS(rider)[15].unk4.z;
    pose->unk90.unk0.x = RIDER_PARTS(rider)[16].unk4.x;
    pose->unk90.unk0.y = RIDER_PARTS(rider)[16].unk4.y;
    pose->unk90.unk0.z = RIDER_PARTS(rider)[16].unk4.z;
    pose->unk6C.unk0.x = RIDER_PARTS(rider)[17].unk4.x;
    pose->unk6C.unk0.y = RIDER_PARTS(rider)[17].unk4.y;
    pose->unk6C.unk0.z = RIDER_PARTS(rider)[17].unk4.z;
    pose->unk264.unk0.x = RIDER_PARTS(rider)[19].unk4.x;
    pose->unk264.unk0.y = RIDER_PARTS(rider)[19].unk4.y;
    pose->unk264.unk0.z = RIDER_PARTS(rider)[19].unk4.z;
    pose->unk240.unk0.x = RIDER_PARTS(rider)[20].unk4.x;
    pose->unk240.unk0.y = RIDER_PARTS(rider)[20].unk4.y;
    pose->unk240.unk0.z = RIDER_PARTS(rider)[20].unk4.z;
    pose->unk21C.unk0.x = RIDER_PARTS(rider)[21].unk4.x;
    pose->unk21C.unk0.y = RIDER_PARTS(rider)[21].unk4.y;
    pose->unk21C.unk0.z = RIDER_PARTS(rider)[21].unk4.z;
    pose->unkFC.unkC.x = RIDER_PARTS(rider)[0].unk4.x - RIDER_PARTS(rider)[1].unk4.x;
    pose->unkFC.unkC.y = RIDER_PARTS(rider)[0].unk4.y - RIDER_PARTS(rider)[1].unk4.y;
    pose->unkFC.unkC.z = RIDER_PARTS(rider)[0].unk4.z - RIDER_PARTS(rider)[1].unk4.z;
    pose->unk1F8.unkC.x = RIDER_PARTS(rider)[1].unk4.x - RIDER_PARTS(rider)[2].unk4.x;
    pose->unk1F8.unkC.y = RIDER_PARTS(rider)[1].unk4.y - RIDER_PARTS(rider)[2].unk4.y;
    pose->unk1F8.unkC.z = RIDER_PARTS(rider)[1].unk4.z - RIDER_PARTS(rider)[2].unk4.z;
    pose->unkD8.unkC.x = (f32) ((0.5 * (f64) (RIDER_PARTS(rider)[7].unk4.x + RIDER_PARTS(rider)[15].unk4.x)) - (f64) RIDER_PARTS(rider)[2].unk4.x);
    pose->unkD8.unkC.y = (f32) ((0.5 * (f64) (RIDER_PARTS(rider)[7].unk4.y + RIDER_PARTS(rider)[15].unk4.y)) - (f64) RIDER_PARTS(rider)[2].unk4.y);
    pose->unkD8.unkC.z = (f32) ((0.5 * (f64) (RIDER_PARTS(rider)[7].unk4.z + RIDER_PARTS(rider)[15].unk4.z)) - (f64) RIDER_PARTS(rider)[2].unk4.z);
    pose->unk168.unkC.x = RIDER_PARTS(rider)[4].unk4.x - RIDER_PARTS(rider)[3].unk4.x;
    pose->unk168.unkC.y = RIDER_PARTS(rider)[4].unk4.y - RIDER_PARTS(rider)[3].unk4.y;
    pose->unk168.unkC.z = RIDER_PARTS(rider)[4].unk4.z - RIDER_PARTS(rider)[3].unk4.z;
    pose->unk144.unkC.x = RIDER_PARTS(rider)[5].unk4.x - RIDER_PARTS(rider)[4].unk4.x;
    pose->unk144.unkC.y = RIDER_PARTS(rider)[5].unk4.y - RIDER_PARTS(rider)[4].unk4.y;
    pose->unk144.unkC.z = RIDER_PARTS(rider)[5].unk4.z - RIDER_PARTS(rider)[4].unk4.z;
    pose->unk120.unkC.x = RIDER_PARTS(rider)[6].unk4.x - RIDER_PARTS(rider)[5].unk4.x;
    pose->unk120.unkC.y = RIDER_PARTS(rider)[6].unk4.y - RIDER_PARTS(rider)[5].unk4.y;
    pose->unk120.unkC.z = RIDER_PARTS(rider)[6].unk4.z - RIDER_PARTS(rider)[5].unk4.z;
    pose->unk48.unkC.x = RIDER_PARTS(rider)[8].unk4.x - RIDER_PARTS(rider)[7].unk4.x;
    pose->unk48.unkC.y = RIDER_PARTS(rider)[8].unk4.y - RIDER_PARTS(rider)[7].unk4.y;
    pose->unk48.unkC.z = RIDER_PARTS(rider)[8].unk4.z - RIDER_PARTS(rider)[7].unk4.z;
    pose->unk24.unkC.x = RIDER_PARTS(rider)[9].unk4.x - RIDER_PARTS(rider)[8].unk4.x;
    pose->unk24.unkC.y = RIDER_PARTS(rider)[9].unk4.y - RIDER_PARTS(rider)[8].unk4.y;
    pose->unk24.unkC.z = RIDER_PARTS(rider)[9].unk4.z - RIDER_PARTS(rider)[8].unk4.z;
    pose->unk0.unkC.x = RIDER_PARTS(rider)[10].unk4.x - RIDER_PARTS(rider)[9].unk4.x;
    pose->unk0.unkC.y = RIDER_PARTS(rider)[10].unk4.y - RIDER_PARTS(rider)[9].unk4.y;
    pose->unk0.unkC.z = RIDER_PARTS(rider)[10].unk4.z - RIDER_PARTS(rider)[9].unk4.z;
    pose->unk1D4.unkC.x = RIDER_PARTS(rider)[12].unk4.x - RIDER_PARTS(rider)[11].unk4.x;
    pose->unk1D4.unkC.y = RIDER_PARTS(rider)[12].unk4.y - RIDER_PARTS(rider)[11].unk4.y;
    pose->unk1D4.unkC.z = RIDER_PARTS(rider)[12].unk4.z - RIDER_PARTS(rider)[11].unk4.z;
    pose->unk1B0.unkC.x = RIDER_PARTS(rider)[13].unk4.x - RIDER_PARTS(rider)[12].unk4.x;
    pose->unk1B0.unkC.y = RIDER_PARTS(rider)[13].unk4.y - RIDER_PARTS(rider)[12].unk4.y;
    pose->unk1B0.unkC.z = RIDER_PARTS(rider)[13].unk4.z - RIDER_PARTS(rider)[12].unk4.z;
    pose->unk18C.unkC.x = RIDER_PARTS(rider)[14].unk4.x - RIDER_PARTS(rider)[13].unk4.x;
    pose->unk18C.unkC.y = RIDER_PARTS(rider)[14].unk4.y - RIDER_PARTS(rider)[13].unk4.y;
    pose->unk18C.unkC.z = RIDER_PARTS(rider)[14].unk4.z - RIDER_PARTS(rider)[13].unk4.z;
    pose->unkB4.unkC.x = RIDER_PARTS(rider)[16].unk4.x - RIDER_PARTS(rider)[15].unk4.x;
    pose->unkB4.unkC.y = RIDER_PARTS(rider)[16].unk4.y - RIDER_PARTS(rider)[15].unk4.y;
    pose->unkB4.unkC.z = RIDER_PARTS(rider)[16].unk4.z - RIDER_PARTS(rider)[15].unk4.z;
    pose->unk90.unkC.x = RIDER_PARTS(rider)[17].unk4.x - RIDER_PARTS(rider)[16].unk4.x;
    pose->unk90.unkC.y = RIDER_PARTS(rider)[17].unk4.y - RIDER_PARTS(rider)[16].unk4.y;
    pose->unk90.unkC.z = RIDER_PARTS(rider)[17].unk4.z - RIDER_PARTS(rider)[16].unk4.z;
    pose->unk6C.unkC.x = RIDER_PARTS(rider)[18].unk4.x - RIDER_PARTS(rider)[17].unk4.x;
    pose->unk6C.unkC.y = RIDER_PARTS(rider)[18].unk4.y - RIDER_PARTS(rider)[17].unk4.y;
    pose->unk6C.unkC.z = RIDER_PARTS(rider)[18].unk4.z - RIDER_PARTS(rider)[17].unk4.z;
    pose->unk264.unkC.x = RIDER_PARTS(rider)[24].unk4.x - RIDER_PARTS(rider)[19].unk4.x;
    pose->unk264.unkC.y = RIDER_PARTS(rider)[24].unk4.y - RIDER_PARTS(rider)[19].unk4.y;
    pose->unk264.unkC.z = RIDER_PARTS(rider)[24].unk4.z - RIDER_PARTS(rider)[19].unk4.z;
    pose->unk240.unkC.x = RIDER_PARTS(rider)[21].unk4.x - RIDER_PARTS(rider)[20].unk4.x;
    pose->unk240.unkC.y = RIDER_PARTS(rider)[21].unk4.y - RIDER_PARTS(rider)[20].unk4.y;
    pose->unk240.unkC.z = RIDER_PARTS(rider)[21].unk4.z - RIDER_PARTS(rider)[20].unk4.z;
    pose->unk21C.unkC.x = RIDER_PARTS(rider)[22].unk4.x - RIDER_PARTS(rider)[23].unk4.x;
    pose->unk21C.unkC.y = RIDER_PARTS(rider)[22].unk4.y - RIDER_PARTS(rider)[23].unk4.y;
    pose->unk21C.unkC.z = RIDER_PARTS(rider)[22].unk4.z - RIDER_PARTS(rider)[23].unk4.z;
    func_80052BB8(pose);
    func_8005DACC(arg0, pose);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8005DE24.s")
#endif

#ifdef NON_MATCHING
// Score 6384 of 48600: register allocation differs: the original uses $s8 and a 0xD8 frame (this version 0xC8),
// keeps the chain base pointer in $s1 and reads cur->pos through an index register. Control flow matches.
void func_800609EC(s32 arg0) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    UnkStruct_80052C6C_2* prev;
    UnkStruct_80052C6C_2* cur;
    UnkStruct_80192690_C88* base;
    UnkStruct_80192690_C88* p14;
    f32* lengths;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 yOff;
    f32 yOffStep;
    f32 grav;
    f32 gravStep;
    f32 limit;
    f32 limitStep;
    f32 k1;
    f32 k2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    f32 dot;
    f32 s;
    s32 i;

    yOffStep = (D_800D4910 - D_800D490C) / 4;
    yOff = D_800D490C;
    grav = D_800D4914;
    limit = D_800D491C;
    gravStep = (D_800D4918 - D_800D4914) / 4;
    limitStep = (D_800D4920 - D_800D491C) / 4;
    prev = &rider->unk1448[0];
    base = (UnkStruct_80192690_C88*) ((u8*) rider + rider->unk1424 * 0x288 + 0xD84);
    nx = (base->unk18.y * base->unkC.z) - (base->unk18.z * base->unkC.y);
    ny = (base->unk18.z * base->unkC.x) - (base->unk18.x * base->unkC.z);
    nz = (base->unk18.x * base->unkC.y) - (base->unk18.y * base->unkC.x);
    if (D_801CE638 == 21) {
        k1 = 7.942f;
        k2 = -2.746f;
    } else {
        k1 = 2.0f;
        k2 = -2.1f;
    }
    prev->unk0.x = RIDER_PARTS(rider)[1].unk4.x + (k1 * base->unk18.x) + (k2 * base->unkC.x);
    prev->unk0.y = RIDER_PARTS(rider)[1].unk4.y + (k1 * base->unk18.y) + (k2 * base->unkC.y);
    prev->unk0.z = RIDER_PARTS(rider)[1].unk4.z + (k1 * base->unk18.z) + (k2 * base->unkC.z);
    p14 = (UnkStruct_80192690_C88*) ((u8*) rider + rider->unk1424 * 0x288 + 0xE80);
    dx = p14->unk18.x + base->unkC.x;
    dy = p14->unk18.y + base->unkC.y;
    dz = p14->unk18.z + base->unkC.z;
    len = 1.0f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    prev->unkC.x = len * dx;
    prev->unkC.y = len * dy;
    prev->unkC.z = len * dz;
    if (arg0 == gPlayer1Rider) {
        if (D_801CE6F4[0] != 0) {
            lengths = D_800D48F8;
        } else {
            lengths = D_800D48E4;
        }
    } else if (arg0 == gPlayer2Rider) {
        if (D_801CE6F4[1] != 0) {
            lengths = D_800D48F8;
        } else {
            lengths = D_800D48E4;
        }
    } else {
        lengths = D_800D48E4;
    }
    for (i = 1, cur = &rider->unk1448[1]; i != 6; i++, prev = cur, cur++) {
        dx = prev->unk0.x - ((rider->unk1520[i].x * grav) + cur->unk0.x);
        dy = prev->unk0.y - ((rider->unk1520[i].y * grav) + cur->unk0.y + yOff);
        dz = prev->unk0.z - ((rider->unk1520[i].z * grav) + cur->unk0.z);
        len = SQ(dx) + SQ(dy) + SQ(dz);
        if (len != 0.0f) {
            len = 1.0f / sqrtf(len);
            cur->unkC.x = len * dx;
            cur->unkC.y = len * dy;
            cur->unkC.z = len * dz;
            dot = (cur->unkC.x * prev->unkC.x) + (cur->unkC.y * prev->unkC.y) + (cur->unkC.z * prev->unkC.z);
            if (dot < limit) {
                dx = cur->unkC.x - (dot * prev->unkC.x);
                dy = cur->unkC.y - (dot * prev->unkC.y);
                dz = cur->unkC.z - (dot * prev->unkC.z);
                len = SQ(dx) + SQ(dy) + SQ(dz);
                if (len != 0.0f) {
                    s = sqrtf((1.0f - SQ(limit)) / len);
                    cur->unkC.x = (prev->unkC.x * limit) + (s * dx);
                    cur->unkC.y = (prev->unkC.y * limit) + (s * dy);
                    cur->unkC.z = (prev->unkC.z * limit) + (s * dz);
                }
            }
            cur->unk14.x = (cur->unkC.y * nz) - (cur->unkC.z * ny);
            cur->unk14.y = (cur->unkC.z * nx) - (cur->unkC.x * nz);
            cur->unk14.z = (cur->unkC.x * ny) - (cur->unkC.y * nx);
            s = prev->unk0.x - (lengths[i - 1] * cur->unkC.x);
            rider->unk1520[i].x = s - cur->unk0.x;
            cur->unk0.x = s;
            s = prev->unk0.y - (lengths[i - 1] * cur->unkC.y);
            rider->unk1520[i].y = s - cur->unk0.y;
            cur->unk0.y = s;
            s = prev->unk0.z - (lengths[i - 1] * cur->unkC.z);
            rider->unk1520[i].z = s - cur->unk0.z;
            cur->unk0.z = s;
            func_80052A20(cur);
        }
        yOff += yOffStep;
        limit += limitStep;
        grav += gravStep;
    }
    func_80048A88(&gGfxPool->unkF308[arg0], rider->unk1448[1].unkC.x, rider->unk1448[1].unkC.y, rider->unk1448[1].unkC.z,
                  rider->unk1448[1].unk14.x, rider->unk1448[1].unk14.y, rider->unk1448[1].unk14.z, rider->unk1448[1].unk0.x,
                  rider->unk1448[1].unk0.y, rider->unk1448[1].unk0.z, 0.1f);
    func_80048A88(&gGfxPool->unkF408[arg0], rider->unk1448[2].unkC.x, rider->unk1448[2].unkC.y, rider->unk1448[2].unkC.z,
                  rider->unk1448[2].unk14.x, rider->unk1448[2].unk14.y, rider->unk1448[2].unk14.z, rider->unk1448[2].unk0.x,
                  rider->unk1448[2].unk0.y, rider->unk1448[2].unk0.z, 0.1f);
    func_80048A88(&gGfxPool->unkF508[arg0], rider->unk1448[3].unkC.x, rider->unk1448[3].unkC.y, rider->unk1448[3].unkC.z,
                  rider->unk1448[3].unk14.x, rider->unk1448[3].unk14.y, rider->unk1448[3].unk14.z, rider->unk1448[3].unk0.x,
                  rider->unk1448[3].unk0.y, rider->unk1448[3].unk0.z, 0.1f);
    func_80048A88(&gGfxPool->unkF608[arg0], rider->unk1448[4].unkC.x, rider->unk1448[4].unkC.y, rider->unk1448[4].unkC.z,
                  rider->unk1448[4].unk14.x, rider->unk1448[4].unk14.y, rider->unk1448[4].unk14.z, rider->unk1448[4].unk0.x,
                  rider->unk1448[4].unk0.y, rider->unk1448[4].unk0.z, 0.1f);
    func_80048A88(&gGfxPool->unkF708[arg0], rider->unk1448[5].unkC.x, rider->unk1448[5].unkC.y, rider->unk1448[5].unkC.z,
                  rider->unk1448[5].unk14.x, rider->unk1448[5].unk14.y, rider->unk1448[5].unk14.z, rider->unk1448[5].unk0.x,
                  rider->unk1448[5].unk0.y, rider->unk1448[5].unk0.z, 0.1f);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800609EC.s")
#endif

#ifdef NON_MATCHING
// Score 3938 of 30400: register allocation differs: the original reads unkB56/unkB5E/unkB5F through a pointer kept
// in $a1 (saved across SysUtils_Round); IDO folds this version's pointer into arg0. Control flow matches.
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

void Rider_ReadController(s32 arg0, s32 arg1) {
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

void Rider_MovePoints(UnkStruct_80192690* arg0, f32 arg1, f32 arg2, f32 arg3) {
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

void Riders_PushApart(void) {
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

#ifdef NON_MATCHING
// Score 7832 of 27500: float register allocation differs (unk6C/unk70 swap $f16/$f18 from the cross product on, and
// the 1/len and 0.5 temps swap $f2/$f12); the frame is 8 bytes larger. Control flow and operation order match.
void func_800624CC(UnkStruct_80192690* arg0) {
    f32 len;
    f32 inv;
    f32 t;
    f32 px;
    f32 py;
    f32 pz;

    arg0->unk6C = arg0->unk90[8].unk0 - arg0->unk90[11].unk0;
    arg0->unk70 = arg0->unk90[8].unk4 - arg0->unk90[11].unk4;
    arg0->unk74 = arg0->unk90[8].unk8 - arg0->unk90[11].unk8;
    inv = 1.0f / sqrtf(SQ(arg0->unk6C) + SQ(arg0->unk70) + SQ(arg0->unk74));
    arg0->unk6C *= inv;
    arg0->unk70 *= inv;
    arg0->unk74 *= inv;
    arg0->unk78 = arg0->unk90[11].unk0 - (arg0->unk90[9].unk0 + arg0->unk90[10].unk0) * 0.5;
    arg0->unk7C = arg0->unk90[11].unk4 - (arg0->unk90[9].unk4 + arg0->unk90[10].unk4) * 0.5;
    arg0->unk80 = arg0->unk90[11].unk8 - (arg0->unk90[9].unk8 + arg0->unk90[10].unk8) * 0.5;
    arg0->unk84 = (arg0->unk7C * arg0->unk74) - (arg0->unk80 * arg0->unk70);
    arg0->unk88 = (arg0->unk80 * arg0->unk6C) - (arg0->unk78 * arg0->unk74);
    arg0->unk8C = (arg0->unk78 * arg0->unk70) - (arg0->unk7C * arg0->unk6C);
    inv = 1.0f / sqrtf(SQ(arg0->unk84) + SQ(arg0->unk88) + SQ(arg0->unk8C));
    arg0->unk84 *= inv;
    arg0->unk88 *= inv;
    arg0->unk8C *= inv;
    arg0->unk78 = (arg0->unk70 * arg0->unk8C) - (arg0->unk74 * arg0->unk88);
    arg0->unk7C = (arg0->unk74 * arg0->unk84) - (arg0->unk6C * arg0->unk8C);
    arg0->unk80 = (arg0->unk6C * arg0->unk88) - (arg0->unk70 * arg0->unk84);
    len = SQ(arg0->unk6C) + SQ(arg0->unk74);
    if (len != 0.0f) {
        inv = 1.0f / sqrtf(len);
        t = arg0->unk6C * inv;
        arg0->unk1434 = t;
        arg0->unk1440 = -t;
        t = arg0->unk74 * inv;
        arg0->unk1438 = t;
        arg0->unk143C = t;
    }
    len = 1.0f - SQ(arg0->unk88);
    if (len > 0.0f) {
        arg0->unkBFC = ((arg0->unk50 * arg0->unk84) + (arg0->unk58 * arg0->unk8C)) / sqrtf(len);
    }
    px = arg0->unk44.x + (2.0f * arg0->unk78);
    py = arg0->unk44.y + (2.0f * arg0->unk7C);
    pz = arg0->unk44.z + (2.0f * arg0->unk80);
    t = RIDER_SPHERES(arg0)[0].pos.x;
    RIDER_SPHERES(arg0)[0].pos.x = (arg0->unk6C * 27.0f) + px;
    RIDER_SPHERES(arg0)[0].vel.x = RIDER_SPHERES(arg0)[0].pos.x - t;
    t = RIDER_SPHERES(arg0)[0].pos.y;
    RIDER_SPHERES(arg0)[0].pos.y = (arg0->unk70 * 27.0f) + py;
    RIDER_SPHERES(arg0)[0].vel.y = RIDER_SPHERES(arg0)[0].pos.y - t;
    t = RIDER_SPHERES(arg0)[0].pos.z;
    RIDER_SPHERES(arg0)[0].pos.z = (arg0->unk74 * 27.0f) + pz;
    RIDER_SPHERES(arg0)[0].vel.z = RIDER_SPHERES(arg0)[0].pos.z - t;
    t = RIDER_SPHERES(arg0)[1].pos.x;
    RIDER_SPHERES(arg0)[1].pos.x = (arg0->unk6C * 9.0f) + px;
    RIDER_SPHERES(arg0)[1].vel.x = RIDER_SPHERES(arg0)[1].pos.x - t;
    t = RIDER_SPHERES(arg0)[1].pos.y;
    RIDER_SPHERES(arg0)[1].pos.y = (arg0->unk70 * 9.0f) + py;
    RIDER_SPHERES(arg0)[1].vel.y = RIDER_SPHERES(arg0)[1].pos.y - t;
    t = RIDER_SPHERES(arg0)[1].pos.z;
    RIDER_SPHERES(arg0)[1].pos.z = (arg0->unk74 * 9.0f) + pz;
    RIDER_SPHERES(arg0)[1].vel.z = RIDER_SPHERES(arg0)[1].pos.z - t;
    t = RIDER_SPHERES(arg0)[2].pos.x;
    RIDER_SPHERES(arg0)[2].pos.x = (arg0->unk6C * -9.0f) + px;
    RIDER_SPHERES(arg0)[2].vel.x = RIDER_SPHERES(arg0)[2].pos.x - t;
    t = RIDER_SPHERES(arg0)[2].pos.y;
    RIDER_SPHERES(arg0)[2].pos.y = (arg0->unk70 * -9.0f) + py;
    RIDER_SPHERES(arg0)[2].vel.y = RIDER_SPHERES(arg0)[2].pos.y - t;
    t = RIDER_SPHERES(arg0)[2].pos.z;
    RIDER_SPHERES(arg0)[2].pos.z = (arg0->unk74 * -9.0f) + pz;
    RIDER_SPHERES(arg0)[2].vel.z = RIDER_SPHERES(arg0)[2].pos.z - t;
    t = RIDER_SPHERES(arg0)[3].pos.x;
    RIDER_SPHERES(arg0)[3].pos.x = (arg0->unk6C * -27.0f) + px;
    RIDER_SPHERES(arg0)[3].vel.x = RIDER_SPHERES(arg0)[3].pos.x - t;
    t = RIDER_SPHERES(arg0)[3].pos.y;
    RIDER_SPHERES(arg0)[3].pos.y = (arg0->unk70 * -27.0f) + py;
    RIDER_SPHERES(arg0)[3].vel.y = RIDER_SPHERES(arg0)[3].pos.y - t;
    t = RIDER_SPHERES(arg0)[3].pos.z;
    RIDER_SPHERES(arg0)[3].pos.z = (arg0->unk74 * -27.0f) + pz;
    RIDER_SPHERES(arg0)[3].vel.z = RIDER_SPHERES(arg0)[3].pos.z - t;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800624CC.s")
#endif

void func_80062918(Vec3f* arg0) {
    f32 temp_f20;
    s32 i;

    temp_f20 = 0.5f / ((D_800D4A04 * 17.0f) + 1.0f);
    for (i = 0; i < 22; i++) {
        arg0[i + 220].x = sqrtf(D_800D4A68[i]) * temp_f20;
    }
}

#ifdef NON_MATCHING
// Score 1690 of 29800: the original loads 11.0f again for t = unkB70 / 11.0f (into $f4) instead of reusing the copy
// in $f18, and schedules the unk16CE load later, so this version is 0x10 bytes shorter. Before t the code matches;
// after it, this version keeps t in $f16 (the original: $f0) and the float registers of the unk16CE blocks shift
// with it. Control flow matches.
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

#ifdef NON_MATCHING
// Score 37161 of 68700: far off: the original clears the state with long chained assignments in an order not yet
// reproduced, and the register allocation differs. Control flow follows the original.
void func_80062E50(s32 arg0, Mtx* arg1, s32 arg2) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    MtxF mf;
    UnkStruct_8004B0F8_1* point;
    Vec3f* tmpl;
    UnkStruct_80192690_C88* base;
    f32* lengths;
    f32 x;
    f32 y;
    f32 z;
    RiderPart* part;
    s32 i;

    if (arg2 != 0) {
        rider->unkBE4 = rider->unk44.x;
        rider->unkBEC = rider->unk44.z;
    } else {
        rider->unkBF4 = rider->unkBF0 = 0.0f;
    }
    for (point = rider->unk30, tmpl = D_800D4840; tmpl < &D_800D4840[12]; tmpl++, point++) {
        point->unk0 = tmpl->x;
        point->unk4 = tmpl->y;
        point->unk8 = tmpl->z;
    }
    func_8004B0F8((struct UnkStruct_8004B0F8*) rider);
    SysUtils_MtxToMtxF(arg1, &mf);
    x = rider->unk44.x;
    y = rider->unk44.y;
    z = rider->unk44.z;
    rider->unk44.x = mf.mf[3][0] + ((mf.mf[0][0] * x) + (mf.mf[1][0] * y) + (mf.mf[2][0] * z));
    rider->unk44.y = mf.mf[3][1] + ((mf.mf[0][1] * x) + (mf.mf[1][1] * y) + (mf.mf[2][1] * z));
    rider->unk44.z = mf.mf[3][2] + ((mf.mf[0][2] * x) + (mf.mf[1][2] * y) + (mf.mf[2][2] * z));
    if (arg2 != 0) {
        rider->unkBF0 = rider->unk44.x - rider->unkBE4;
        rider->unkBF4 = rider->unk44.z - rider->unkBEC;
    }
    for (point = &rider->unk90[11]; point >= rider->unk90; point--) {
        x = point->unk0;
        y = point->unk4;
        z = point->unk8;
        point->unk0 = mf.mf[3][0] + ((mf.mf[0][0] * x) + (mf.mf[1][0] * y) + (mf.mf[2][0] * z));
        point->unk4 = mf.mf[3][1] + ((mf.mf[0][1] * x) + (mf.mf[1][1] * y) + (mf.mf[2][1] * z));
        point->unk8 = mf.mf[3][2] + ((mf.mf[0][2] * x) + (mf.mf[1][2] * y) + (mf.mf[2][2] * z));
    }
    // The original assigns most of these in long chains.
    rider->unk142C = rider->unkBFC = rider->unkB98 = 0.0f;
    rider->unk1444 = 0;
    rider->unk15FA = rider->unk15F8 = 0;
    rider->unk1602 = 0;
    rider->unk160A = 0;
    rider->unk16E0 = rider->unk1608 = 0;
    rider->unk16E2 = rider->unk1606 = 0;
    rider->unk16F2 = rider->unk1604 = 0;
    rider->unkB58 = rider->unkB56 = 0;
    rider->unkB8C = rider->unkB88 = rider->unkB84 = 0.0f;
    rider->unkB80 = rider->unkB7C = rider->unkB78 = 0.0f;
    rider->unkB94 = rider->unkB90 = 0.0f;
    rider->unkB5F = rider->unkB5E = 0;
    rider->unk16E4 = rider->unk16D0 = rider->unk16B4 = rider->unk1574 = 0;
    rider->unkC6C = rider->unkC58 = 0;
    rider->unk16EC = rider->unk16E8 = 0;
    rider->unkB60 = 0;
    rider->unkC86 = rider->unkC84 = 0;
    rider->unkB50.button = 0;
    rider->unkB50.stick_y = rider->unkB50.stick_x = 0;
    rider->unk1446 = 10;
    rider->unk16C8 = -1;
    rider->unk15FC = 0x800;
    rider->unk1598 = 0;
    rider->unk16F0 = rider->unk16F2;
    rider->unk16F4 = rider->unk1604;
    rider->unk15D8 = 1.0f;
    rider->unkC74 = rider->unkC70 = rider->unk15B0 = -1;
    rider->unkC7E = 0;
    rider->unkC80 = 0;
    rider->unkC7C = 1;
    rider->unkC82 = 1;
    rider->unkC78 = 8;
    rider->unk1578 = 1.0f;
    rider->unk15F0 = rider->unk15A8 = rider->unk15A4 = rider->unk15A0 = rider->unk159C = gFrameCounter;
    rider->unkC54 = 22;
    rider->unkC00 = 34.11f;
    func_800624CC(rider);
    rider->unkBA0 = rider->unk6C;
    rider->unkBA4 = rider->unk70;
    rider->unkBA8 = rider->unk74;
    rider->unkBAC = 0.0f;
    rider->unkBB0 = 0.0f;
    rider->unkBB4 = 0.0f;
    rider->unkC68 = 1;
    x = rider->unk44.x + (2.0f * rider->unk78);
    y = rider->unk44.y + (2.0f * rider->unk7C);
    z = rider->unk44.z + (2.0f * rider->unk80);
    RIDER_SPHERES(rider)[0].pos.x = (rider->unk6C * 27.0f) + x;
    RIDER_SPHERES(rider)[0].pos.y = (rider->unk70 * 27.0f) + y;
    RIDER_SPHERES(rider)[0].pos.z = (rider->unk74 * 27.0f) + z;
    RIDER_SPHERES(rider)[1].pos.x = (rider->unk6C * 9.0f) + x;
    RIDER_SPHERES(rider)[1].pos.y = (rider->unk70 * 9.0f) + y;
    RIDER_SPHERES(rider)[1].pos.z = (rider->unk74 * 9.0f) + z;
    RIDER_SPHERES(rider)[2].pos.x = (rider->unk6C * -9.0f) + x;
    RIDER_SPHERES(rider)[2].pos.y = (rider->unk70 * -9.0f) + y;
    RIDER_SPHERES(rider)[2].pos.z = (rider->unk74 * -9.0f) + z;
    RIDER_SPHERES(rider)[3].pos.x = (rider->unk6C * -27.0f) + x;
    RIDER_SPHERES(rider)[3].pos.y = (rider->unk70 * -27.0f) + y;
    RIDER_SPHERES(rider)[3].pos.z = (rider->unk74 * -27.0f) + z;
    RIDER_SPHERES(rider)[0].vel.x = 0.0f;
    RIDER_SPHERES(rider)[0].vel.y = 0.0f;
    RIDER_SPHERES(rider)[0].vel.z = 0.0f;
    RIDER_SPHERES(rider)[1].vel.x = 0.0f;
    RIDER_SPHERES(rider)[1].vel.y = 0.0f;
    RIDER_SPHERES(rider)[1].vel.z = 0.0f;
    RIDER_SPHERES(rider)[2].vel.x = 0.0f;
    RIDER_SPHERES(rider)[2].vel.y = 0.0f;
    RIDER_SPHERES(rider)[2].vel.z = 0.0f;
    RIDER_SPHERES(rider)[3].vel.x = 0.0f;
    RIDER_SPHERES(rider)[3].vel.y = 0.0f;
    RIDER_SPHERES(rider)[3].vel.z = 0.0f;
    for (part = &RIDER_PARTS(rider)[24]; part >= RIDER_PARTS(rider); part--) {
        part->unk1C.x = part->unk1C.y = part->unk1C.z = 0.0f;
    }
    rider->unk1420 = 0;
    rider->unk1424 = 1;
    rider->unk1428 = 2;
    rider->unkC5C = -1;
    rider->unkC54 = -1;
    if ((D_801CE638 == 1) && (rider->unk16CC == 0)) {
        func_80053EAC(arg0, 15, 56, 1.0f, 0);
    } else if (D_801CE638 == 21) {
        func_80053EAC(arg0, gRiderRaceState[arg0].unk338 + 18, 0, 1.0f, 0);
    } else {
        func_80053EAC(arg0, 22, 0, 1.0f, 0);
    }
    rider->unkC58 = func_8005CD24(arg0, (UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424], rider->unkC54,
                                  rider->unkC58) - 1;
    func_8005D390((UnkStruct_80052E90_arg1_s*) RIDER_C88(rider)[rider->unk1424], (UnkStruct_8005CEF8*) rider->unk660);
    rider->unkC20 = 0.0f;
    rider->unkC24 = 0.0f;
    rider->unkC28 = 0.0f;
    rider->unkC2C = 0.0f;
    rider->unkC30 = 0.0f;
    rider->unkC34 = 0.0f;
    rider->unkC08 = 0.0f;
    rider->unkC14 = rider->unk44.x + (-26.9998535 * rider->unk6C) + (0.1806645 * rider->unk78);
    rider->unkC18 = rider->unk44.y + (-26.9998535 * rider->unk70) + (0.1806645 * rider->unk7C);
    rider->unkC1C = rider->unk44.z + (-26.9998535 * rider->unk74) + (0.1806645 * rider->unk80);
    rider->unkC0C = rider->unkC04 = 34.11f;
    rider->unkC10 = -27.300001f;
    base = &RIDER_C88(rider)[rider->unk1424][7];
    rider->unk1448[0].unkC.x = base->unkC.x;
    rider->unk1448[0].unk0.x = (base->unkC.x * -2.1f) + (RIDER_PARTS(rider)[1].unk4.x + (2.0f * base->unk18.x));
    rider->unk1448[0].unkC.y = base->unkC.y;
    rider->unk1448[0].unk0.y = (base->unkC.y * -2.1f) + (RIDER_PARTS(rider)[1].unk4.y + (2.0f * base->unk18.y));
    rider->unk1448[0].unkC.z = base->unkC.z;
    rider->unk1448[0].unk0.z = (base->unkC.z * -2.1f) + (RIDER_PARTS(rider)[1].unk4.z + (2.0f * base->unk18.z));
    if (arg0 == gPlayer1Rider) {
        if (D_801CE6F4[0] != 0) {
            lengths = D_800D48F8;
        } else {
            lengths = D_800D48E4;
        }
    } else {
        lengths = D_800D48E4;
        if (arg0 == gPlayer2Rider) {
            if (D_801CE6F4[1] != 0) {
                lengths = D_800D48F8;
            } else {
                lengths = D_800D48E4;
            }
        }
    }
    for (i = 1; i < 6; i++) {
        base = &RIDER_C88(rider)[rider->unk1424][7];
        rider->unk1448[i].unkC.x = base->unkC.x;
        rider->unk1448[i].unk0.x = rider->unk1448[i - 1].unk0.x - (base->unkC.x * lengths[i - 1]);
        rider->unk1448[i].unkC.y = base->unkC.y;
        rider->unk1448[i].unk0.y = rider->unk1448[i - 1].unk0.y - (base->unkC.y * lengths[i - 1]);
        rider->unk1448[i].unkC.z = base->unkC.z;
        rider->unk1448[i].unk0.z = rider->unk1448[i - 1].unk0.z - (base->unkC.z * lengths[i - 1]);
        rider->unk1448[i].unk14.x = base->unk18.x;
        rider->unk1448[i].unk14.y = base->unk18.y;
        rider->unk1448[i].unk14.z = base->unk18.z;
        rider->unk1520[i].x = rider->unk1520[i].y = rider->unk1520[i].z = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80062E50.s")
#endif

#ifdef NON_MATCHING
// Score 6123 of 22300: the original's unkA48 loop is unrolled by 2 (first entry peeled); IDO does not unroll this
// pointer loop, and unrolls the indexed forms by 4. Before the loop only the stack slot of `first` differs (sp20,
// original sp24).
void func_8006390C(s32 arg0, void* arg1) {
    UnkStruct_80192690* rider;
    UnkStruct_8004B0F8_1* first;
    UnkStruct_80192690_A48* e;
    s8 (*t)[4];

    rider = &D_80192690[arg0];
    if ((gCourseID == DOLPHIN_PARK) && (D_800DAB60 != 0) && (gGameModes != GMODE_STUNT) &&
        ((D_800DAB64 != 0) || ((D_801CE638 == 0) && (D_800D4928 != 0)))) {
        rider->unk16CC = 1;
    } else {
        rider->unk16CC = 0;
    }
    if ((D_801CE638 == 0) || (D_801CE638 == 8)) {
        rider->unkB64 = 0;
    } else {
        rider->unkB64 = rider->unkB68;
    }
    rider->unk0.f = D_800D4AC0;
    rider->unkC = D_800D4AC4;
    rider->unk10 = D_800D4AD0;
    rider->unk18 = D_800D4AD8;
    rider->unk1C = D_800D4ADC;
    rider->unk20 = D_800D4AE0;
    rider->unk24 = D_800D4AE4;
    rider->unk28 = 11;
    rider->unk2C = 65;
    rider->unk30 = first = &rider->unk90[0];
    rider->unk34 = (UnkStruct_8004B0F8_unk34*) &rider->unk90[12];
    rider->unk38 = rider->unk528;
    func_80062E50(arg0, arg1, 0);
    func_8004AFE8((struct UnkStruct_8004B0F8*) rider, 0, 11);
    func_8004AE88((struct UnkStruct_8004B0F8*) rider);
    RIDER_SPHERES(rider)[0].unk18 = &rider->unk90[4];
    RIDER_SPHERES(rider)[0].unk1C = &rider->unk90[5];
    RIDER_SPHERES(rider)[0].unk20 = &rider->unk90[3];
    RIDER_SPHERES(rider)[1].unk18 = &rider->unk90[8];
    RIDER_SPHERES(rider)[1].unk1C = &rider->unk90[7];
    RIDER_SPHERES(rider)[1].unk20 = &rider->unk90[6];
    RIDER_SPHERES(rider)[2].unk18 = &rider->unk90[11];
    RIDER_SPHERES(rider)[2].unk1C = &rider->unk90[10];
    RIDER_SPHERES(rider)[2].unk20 = &rider->unk90[9];
    RIDER_SPHERES(rider)[3].unk18 = &rider->unk90[1];
    RIDER_SPHERES(rider)[3].unk1C = &rider->unk90[2];
    RIDER_SPHERES(rider)[3].unk20 = first;
    func_800629A8(rider);
    for (e = rider->unkA48, t = D_800D4A3C; t != &D_800D4A3C[11]; e++, t++) {
        e->unk0 = &RIDER_PARTS(rider)[(*t)[0]];
        e->unk4 = &RIDER_PARTS(rider)[(*t)[1]];
        e->unkC = &RIDER_PARTS(rider)[(*t)[2]];
        e->unk10 = &RIDER_PARTS(rider)[(*t)[3]];
    }
    func_80062918((Vec3f*) rider);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_8006390C.s")
#endif

#ifdef NON_MATCHING
// Score 5762 of 99300: close in structure: register allocation and a few constant loads differ (1.0f, D_800D4AC0,
// 0.9f), so the original is 0x18 bytes longer. Control flow matches, including the switch on unk1598.
// Starts a timed stick move (unk1598) for the rider.
#define MOVE_START(r)          \
    if ((r)->unk16E2 == 0) {    \
        (r)->unk16D4 = 0;       \
        (r)->unk16DC = 0;       \
        (r)->unk16E2 = 1;       \
        (r)->unk15EC = 0.0f;    \
    }

void func_80063C88(s32 arg0) {
    UnkStruct_80192690* rider;
    struct UnkStruct_801C2938* stats;
    f32 f;
    f32 d;
    f32 speed;
    f32 dx;
    f32 dz;
    f32 max;

    if (D_801CE638 == 4) {
        D_80192690[arg0].unkB64 = D_80192690[arg0].unkB68;
        func_800629A8(&D_80192690[arg0]);
    }
    stats = &gRiderRaceState[arg0];
    rider = &D_80192690[arg0];
    if (stats->unk318 != 0) {
        rider->unkC = D_800D4AC8;
    } else {
        rider->unkC = D_800D4AC4;
    }
    if (rider->unkB56 & 0x10) {
        rider->unk14 = (rider->unk15E8 * 0.2f) + 0.8f;
    } else if ((u16) rider->unk1602 != 0) {
        if ((u16) rider->unk1602 == 1) {
            rider->unk14 = 0.999f;
        } else {
            rider->unk14 = ((1.0f - rider->unk15E8) * D_800D4938) + rider->unk15E8;
        }
        rider->unk1590 = rider->unk1594 * 0.01f;
    } else {
        d = rider->unk15E8 - rider->unk14;
        if (d < -0.01f) {
            d = -0.01f;
        } else if (d > 0.01f) {
            d = 0.01f;
        }
        rider->unk14 += d;
        rider->unk1590 = rider->unk1594;
    }
    if (rider->unkC54 == 8) {
        f = 0.1f;
    } else if (rider->unkC54 == 9) {
        f = 0.15f;
    } else if (rider->unkC54 == 17) {
        f = 0.2f;
    } else {
        f = 1.0f;
    }
    rider->unk169C = D_800D92F0[rider->unkB64] * f;
    rider->unk16A0 = D_800D9300[rider->unkB64] * f;
    rider->unk16A4 = D_800D9320[rider->unkB64] * f;
    rider->unk16A8 = D_800D9340[rider->unkB64] * f;
    rider->unk16AC = D_800D9330[rider->unkB64] * f;
    rider->unk16B0 = D_800D9310[rider->unkB64] * f;
    if ((rider->unkB58 & 0x4000) && (rider->unkC54 == 22) && (rider->unk15D8 == 1.0f)) {
        rider->unk15D8 = 0.9f;
    }
    if (rider->unkB64 == 1) {
        if (rider->unkC7C != 0) {
            f = D_800D4AC0;
        } else {
            f = 1.2f * D_800D4AC0;
        }
    } else if (rider->unkB64 == 2) {
        if (rider->unkC7C != 0) {
            f = D_800D4AC0;
        } else {
            f = 0.9f * D_800D4AC0;
        }
    } else {
        f = D_800D4AC0;
    }
    if (rider->unkC54 == 23) {
        f *= 0.7f;
    }
    if (rider->unk15D8 < 1.0f) {
        f *= ((1.0f - rider->unk15D8) * 7.5f) + 1.0f;
    }
    rider->unk0.f = f;
    if (rider->unk1580 <= rider->unkB90) {
        rider->unk1588 = rider->unkBB8;
    } else {
        rider->unk1588 = (((1.0f - (rider->unkB90 / rider->unk1580)) * rider->unk1584) + 1.0f) * rider->unkBB8;
    }
    if (stats->timeLeft == 0) {
        rider->unk1578 = 0.0f;
    } else {
        if (rider->unk16CE != 0) {
            f = D_800D95C0[rider->unkB64];
        } else {
            f = D_800D95B0[rider->unkB64];
        }
        rider->unkB9C = (stats->power / 5.0f) * f;
        if ((gPlayers == TWO_PLAYERS) && ((u16) D_800D4970 != 0)) {
            if (stats->unk4 != 0) {
                dx = D_80192690[gPlayer1Rider].unk44.x - D_80192690[gPlayer2Rider].unk44.x;
                dz = D_80192690[gPlayer1Rider].unk44.z - D_80192690[gPlayer2Rider].unk44.z;
                if (rider->unkB64 == 1) {
                    max = 1.05f;
                } else if (rider->unkB64 == 2) {
                    max = 1.15f;
                } else {
                    max = 1.1f;
                }
                f = ((sqrtf(SQ(dx) + SQ(dz)) * (max - 0.9f)) / 200.0f) + 0.9f;
                if (max < f) {
                    f = max;
                }
            } else {
                f = 0.9f;
            }
            rider->unk1578 *= f;
            if (rider->unkB64 == 0) {
                rider->unk1588 /= f;
            } else if (rider->unkB64 == 1) {
                rider->unk1588 /= sqrtf(f);
            } else if (rider->unkB64 == 2) {
                rider->unk1588 /= f * f;
            } else {
                rider->unk1588 /= f * sqrtf(f);
            }
        }
        if (rider->unkC78 == 12) {
            rider->unk1578 *= D_800D49C0;
        }
    }
    {
        s32 ang = DEG_TO_BINANG((((f32) rider->unkB5E * rider->unk1588) / 70.0f));
        rider->unk15E4 = SIN(ang);
        rider->unk15E0 = COS(ang);
    }
    if (rider->unk1598 != 0) {
        rider->unk15E4 = 0.0f;
        rider->unk15E0 = 1.0f;
    }
    if (((rider->unkB90 < 11.111112f) && ((rider->unkC54 == 22) || (rider->unkC54 == 7))) || (rider->unkC44 != 0.0f)) {
        rider->unkBF8 = D_800D9480[rider->unkB64] * (f32) rider->unkB5E;
    } else {
        rider->unkBF8 = 0.0f;
    }
    speed = sqrtf(SQ(rider->unkB78) + SQ(rider->unkB80));
    if ((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) {
        if (rider->unk70 > 0.8f) {
            rider->unk15C4 = rider->unk156C * 70.0f;
        } else {
            rider->unk15C4 = 0.0f;
        }
    } else if ((rider->unkC78 == 12) || ((rider->unkC54 != 22) && (rider->unkC54 != 25))) {
        rider->unk15C4 = 0.0f;
    } else {
        rider->unk15C4 = sqrtf(SQ(rider->unk6C) + SQ(rider->unk74)) * (f32) rider->unkB5F;
        if (rider->unk15C4 < 0.0f) {
            rider->unk15C4 *= rider->unk1570;
        } else {
            rider->unk15C4 *= rider->unk156C;
            if (rider->unkC7C != 0) {
                rider->unk15C4 *= 0.5f;
            }
            rider->unk15C4 *= 1.0f - ((0.25f * (f32) rider->unkB5E * (f32) rider->unkB5E) / 4900.0f);
        }
        if (speed < 16.666668f) {
            f = speed / 16.666668f;
            if (f < 0.7f) {
                f = 0.7f;
            }
            rider->unk15C4 *= f;
        }
    }
    if (speed < 16.666668f) {
        rider->unk15CC = D_800D494C * (1.0f - (speed / 16.666668f)) * (f32) rider->unkB5E;
    } else {
        rider->unk15CC = 0.0f;
    }
    if (rider->unk16CC != 0) {
        rider->unk15D4 = (f32) gWaterLevel - 10.0f;
    } else {
        if (speed < 33.333336f) {
            rider->unk15D4 = (f32) gWaterLevel + (D_800D4954 * (speed / 33.333336f));
        } else {
            rider->unk15D4 = (f32) gWaterLevel + D_800D4954;
        }
        if (rider->unkB68 == 1) {
            rider->unk15D4 -= 5.0f;
        } else if (rider->unkB68 == 2) {
            rider->unk15D4 += 2.0f;
        }
    }
    rider->unk16F2 = rider->unk16F0;
    if (rider->unk7C < 0.0f) {
        rider->unk16F0 = 1;
    } else {
        rider->unk16F0 = 0;
    }
    if ((rider->unk16F0 != rider->unk16F2) && (rider->unkC54 == 22)) {
        rider->unk16D4++;
    }
    if ((rider->unkC54 == 22) || (rider->unkC54 == 25)) {
        switch (rider->unk1598) {
            case 0:
                if ((rider->unkC78 == 0) && (rider->unkB90 > 33.333336f) && (rider->unkC66 != 0)) {
                    if (rider->unkB50.stick_x < -69) {
                    if (((u32) (gFrameCounter - rider->unk15A0) < D_800D4944) || (rider->unk16F4 == 3)) {
                        rider->unk16F4 = 0;
                        rider->unk1598 = 2;
                        rider->unk15AC = -D_800D9400[rider->unkB64];
                        MOVE_START(rider);
                        rider->unk16E8 = 3;
                        rider->unk16EC = 0;
                    }
                    } else if (rider->unkB50.stick_x >= 70) {
                    if (((u32) (gFrameCounter - rider->unk159C) < D_800D4944) || (rider->unk16F4 == 4)) {
                        rider->unk16F4 = 0;
                        rider->unk1598 = 1;
                        rider->unk15AC = D_800D9400[rider->unkB64];
                        MOVE_START(rider);
                        rider->unk16E8 = 3;
                        rider->unk16EC = 0;
                    }
                    } else if (rider->unkB50.stick_y < -69) {
                    if (((u32) (gFrameCounter - rider->unk15A4) < D_800D4944) || (rider->unk16F4 == 5)) {
                        rider->unk16F4 = 0;
                        rider->unk1598 = 4;
                        rider->unk15AC = D_800D9410[rider->unkB64];
                        MOVE_START(rider);
                        rider->unk16E8 = 3;
                        rider->unk16EC = 0;
                    }
                    } else if ((rider->unkB50.stick_y >= 70) && ((u32) (gFrameCounter - rider->unk15A8) < D_800D4944)) {
                        rider->unk1598 = 3;
                        rider->unk15C8 = 0;
                        MOVE_START(rider);
                    }
                }
                break;
            case 2:
                if ((rider->unkB50.stick_x >= -69) ||
                    (((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) && (rider->unk16DC >= 6))) {
                    rider->unk1598 = 0;
                    rider->unk1606 = -1;
                } else {
                    rider->unkB5E = 0;
                }
                break;
            case 1:
                if ((rider->unkB50.stick_x < 70) ||
                    (((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) && (rider->unk16DC >= 6))) {
                    rider->unk1598 = 0;
                    rider->unk1606 = -1;
                } else {
                    rider->unkB5E = 0;
                }
                break;
            case 3:
                if (rider->unkC78 >= 8) {
                    rider->unk15C8++;
                    if (D_800D4948 < rider->unk15C8) {
                        rider->unk1598 = 0;
                    }
                }
                if (rider->unkB50.stick_y < 70) {
                    rider->unk1598 = 0;
                }
                break;
            case 4:
                if ((rider->unkB50.stick_y >= -69) ||
                    (((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) && (rider->unk16DC >= 6))) {
                    rider->unk1598 = 0;
                    rider->unk1606 = -1;
                } else {
                    rider->unkB5F = 0;
                }
                break;
        }
    } else if (rider->unk1598 != 0) {
        rider->unk1598 = 0;
        rider->unk1606 = -1;
    }
    rider->unkBE4 = rider->unk44.x;
    rider->unkBE8 = rider->unk44.y;
    rider->unkBEC = rider->unk44.z;
    if ((rider->unkC4C + rider->unkC48 + rider->unkC44 + rider->unkC40 + rider->unkC3C + rider->unkC50 + rider->unkC38) != 0.0f) {
        func_80051EC0(arg0);
    }
    if (gRiderGameModes != PAUSE_MODE) {
        rider->unk15DE = 0;
        rider->unkC38 = 0.0f;
        rider->unkC50 = 0.0f;
        rider->unkC3C = 0.0f;
        rider->unkC40 = 0.0f;
        rider->unkC44 = 0.0f;
        rider->unkC48 = 0.0f;
        rider->unkC4C = 0.0f;
        rider->unk15BC = 0.0f;
        rider->unk15B8 = 0.0f;
        rider->unk15B4 = 0.0f;
    }
}

#undef MOVE_START
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80063C88.s")
#endif

#ifdef NON_MATCHING
// Score 1805 of 102700: same size as the original and close: float register allocation differs in a few blocks
// (thrust sits in $f2 rather than $f18, the g +/- f sums, the 0.5f moves). Control flow matches.
void func_80064C0C(s32 arg0) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    UnkStruct_8004B0F8_1* point;
    f32 thrust;
    f32 x;
    f32 y;
    f32 z;
    f32 f;
    f32 g;
    s32 ang;

    if (rider->unk16B4 >= 40) {
        thrust = rider->unkBBC;
    } else if (rider->unkC4C != 0.0f) {
        thrust = rider->unkBBC * D_800D9630;
    } else {
        if (rider->unk68 >= 11.111112f) {
            thrust = rider->unkBCC * rider->unkBC4;
        } else if (rider->unkBD0 <= rider->unk68) {
            ang = (rider->unk68 - rider->unkBD0) * rider->unkBDC;
            thrust = (1.0f - ((1.0f - COS(ang)) * rider->unkBE0)) * rider->unkBC4;
        } else {
            ang = (rider->unkBD0 - rider->unk68) * rider->unkBD4;
            thrust = (1.0f - ((1.0f - COS(ang)) * rider->unkBD8)) * rider->unkBC4;
        }
        thrust += rider->unkB9C;
        thrust *= sqrtf(1.0f - SQ(rider->unk70));
        if (!((rider->unk90[2].unk1C | rider->unk90[0].unk1C) & 1)) {
            thrust *= D_800D49C4;
        }
        thrust *= rider->unk1578;
    }
    if (rider->unkC66 != 0) {
        rider->unkB98 = thrust;
    } else if ((D_800D49C8 < rider->unkB98) && (rider->unkC54 != 23)) {
        rider->unkB98 -= D_800D49C8;
    } else {
        rider->unkB98 = 0.0f;
    }
    rider->unkBA0 = rider->unk15E0 * rider->unk6C;
    rider->unkBA4 = rider->unk15E0 * rider->unk70;
    rider->unkBA8 = rider->unk15E0 * rider->unk74;
    rider->unkBAC = rider->unk15E4 * rider->unk84;
    rider->unkBB0 = rider->unk15E4 * rider->unk88;
    rider->unkBB4 = rider->unk15E4 * rider->unk8C;
    x = rider->unkBA0 + rider->unkBAC;
    y = rider->unkBA4 + rider->unkBB0;
    z = rider->unkBA8 + rider->unkBB4;
    f = SQ(x) + SQ(z);
    if (f != 0.0f) {
        f = rider->unkB98 / sqrtf(f);
    } else {
        f = 0.0f;
    }
    x *= f;
    y *= rider->unkB98;
    z *= f;
    rider->unk90[2].unkC += x;
    rider->unk90[2].unk10 += y;
    rider->unk90[2].unk14 += z;
    rider->unk90[0].unkC += x;
    rider->unk90[0].unk10 += y;
    rider->unk90[0].unk14 += z;
    if (rider->unk15C4 != 0.0f) {
        x = RIDER_PARTS(rider)[2].unk4.x - rider->unk44.x;
        y = RIDER_PARTS(rider)[2].unk4.y - rider->unk44.y;
        z = RIDER_PARTS(rider)[2].unk4.z - rider->unk44.z;
        f = (rider->unk6C * x) + (y * rider->unk70) + (z * rider->unk74);
        x -= f * rider->unk6C;
        y -= f * rider->unk70;
        z -= f * rider->unk74;
        f = 1.0f / sqrtf(SQ(x) + SQ(y) + SQ(z));
        x *= f;
        y *= f;
        z *= f;
        f = (rider->unk78 * x) + (y * rider->unk7C) + (z * rider->unk80);
        f = SQ(f);
        if (f > 1.0f) {
            f = 1.0f;
        }
        f = (1.0f - (sqrtf(1.0f - SQ(f)) * rider->unk1568)) * rider->unk15C4;
        x *= f;
        y *= f;
        z *= f;
        rider->unk90[7].unkC -= x;
        rider->unk90[7].unk10 -= y;
        rider->unk90[7].unk14 -= z;
        rider->unk90[6].unkC -= x;
        rider->unk90[6].unk10 -= y;
        rider->unk90[6].unk14 -= z;
        rider->unk90[10].unkC += x;
        rider->unk90[10].unk10 += y;
        rider->unk90[10].unk14 += z;
        rider->unk90[9].unkC += x;
        rider->unk90[9].unk10 += y;
        rider->unk90[9].unk14 += z;
        x *= 3.0f;
        y *= 3.0f;
        z *= 3.0f;
        rider->unk90[5].unkC -= x;
        rider->unk90[5].unk10 -= y;
        rider->unk90[5].unk14 -= z;
        rider->unk90[3].unkC -= x;
        rider->unk90[3].unk10 -= y;
        rider->unk90[3].unk14 -= z;
        rider->unk90[2].unkC += x;
        rider->unk90[2].unk10 += y;
        rider->unk90[2].unk14 += z;
        rider->unk90[0].unkC += x;
        rider->unk90[0].unk10 += y;
        rider->unk90[0].unk14 += z;
    }
    if (rider->unkC54 == 23) {
        if ((rider->unk7C < 0.6f) && (rider->unk7C > -0.6f) &&
            (((rider->unkB90 < 8.333334f) && (rider->unkC78 >= 4)) || (rider->unkC74 >= D_800D4990))) {
            g = rider->unk0.f;
            rider->unk90[1].unk10 += D_800D4950;
            rider->unk90[4].unk10 += D_800D4950;
            rider->unk90[8].unk10 += D_800D4950;
            rider->unk90[11].unk10 += D_800D4950;
        } else {
            g = rider->unk0.f * 0.6666667f;
            rider->unk90[1].unk10 += g;
            rider->unk90[4].unk10 += g;
            rider->unk90[8].unk10 += g;
            rider->unk90[11].unk10 += g;
        }
        rider->unk90[5].unk10 += g;
        rider->unk90[7].unk10 += g;
        rider->unk90[10].unk10 += g;
        rider->unk90[2].unk10 += g;
        rider->unk90[3].unk10 += g;
        rider->unk90[6].unk10 += g;
        rider->unk90[9].unk10 += g;
        rider->unk90[0].unk10 += g;
    } else {
        f = (rider->unk1590 * ((rider->unk84 * rider->unkC20) + (rider->unk88 * rider->unkC24) + (rider->unk8C * rider->unkC28))) +
            rider->unk15CC;
        rider->unk90[5].unk10 += rider->unk0.f + f;
        rider->unk90[7].unk10 += rider->unk0.f + f;
        rider->unk90[10].unk10 += rider->unk0.f + f;
        rider->unk90[2].unk10 += rider->unk0.f + f;
        rider->unk90[3].unk10 += rider->unk0.f - f;
        rider->unk90[6].unk10 += rider->unk0.f - f;
        rider->unk90[9].unk10 += rider->unk0.f - f;
        rider->unk90[0].unk10 += rider->unk0.f - f;
    }
    if (rider->unkBF8 != 0.0f) {
        x = rider->unkBF8 * rider->unk84;
        y = rider->unkBF8 * rider->unk88;
        z = rider->unkBF8 * rider->unk8C;
        rider->unk90[3].unkC -= x;
        rider->unk90[3].unk10 -= y;
        rider->unk90[3].unk14 -= z;
        rider->unk90[4].unkC -= x;
        rider->unk90[4].unk10 -= y;
        rider->unk90[4].unk14 -= z;
        rider->unk90[5].unkC -= x;
        rider->unk90[5].unk10 -= y;
        rider->unk90[5].unk14 -= z;
        rider->unk90[0].unkC += x;
        rider->unk90[0].unk10 += y;
        rider->unk90[0].unk14 += z;
        rider->unk90[1].unkC += x;
        rider->unk90[1].unk10 += y;
        rider->unk90[1].unk14 += z;
        rider->unk90[2].unkC += x;
        rider->unk90[2].unk10 += y;
        rider->unk90[2].unk14 += z;
    }
    if ((rider->unk1598 == 2) || (rider->unk1598 == 1)) {
        x = rider->unk15AC * rider->unk84;
        z = rider->unk15AC * rider->unk8C;
        g = rider->unk0.f;
        g *= 0.5f;
        y = (rider->unk15AC * rider->unk88) - g;
        rider->unk90[2].unkC += x;
        rider->unk90[2].unk10 += y;
        rider->unk90[2].unk14 += z;
        rider->unk90[10].unkC += x;
        rider->unk90[10].unk10 += y;
        rider->unk90[10].unk14 += z;
        rider->unk90[0].unkC += x;
        rider->unk90[0].unk10 += y;
        rider->unk90[0].unk14 += z;
        rider->unk90[9].unkC += x;
        rider->unk90[9].unk10 += y;
        rider->unk90[9].unk14 += z;
        rider->unk90[1].unkC -= x;
        rider->unk90[1].unk10 -= y;
        rider->unk90[1].unk14 -= z;
        rider->unk90[11].unkC -= x;
        rider->unk90[11].unk10 -= y;
        rider->unk90[11].unk14 -= z;
        rider->unk90[4].unk10 += g;
        rider->unk90[8].unk10 += g;
    } else if (rider->unk1598 == 4) {
        x = rider->unk15AC * rider->unk78;
        f = rider->unk15AC * rider->unk7C;
        z = rider->unk15AC * rider->unk80;
        g = rider->unk0.f * 0.5f;
        y = f - g;
        f = f + g;
        rider->unk90[3].unkC += x;
        rider->unk90[3].unk10 += y;
        rider->unk90[3].unk14 += z;
        rider->unk90[4].unkC += x;
        rider->unk90[4].unk10 += f;
        rider->unk90[4].unk14 += z;
        rider->unk90[5].unkC += x;
        rider->unk90[5].unk10 += y;
        rider->unk90[5].unk14 += z;
        rider->unk90[0].unkC -= x;
        rider->unk90[0].unk10 -= f;
        rider->unk90[0].unk14 -= z;
        rider->unk90[1].unkC -= x;
        rider->unk90[1].unk10 -= y;
        rider->unk90[1].unk14 -= z;
        rider->unk90[2].unkC -= x;
        rider->unk90[2].unk10 -= f;
        rider->unk90[2].unk14 -= z;
        rider->unk90[8].unk10 += g;
        rider->unk90[6].unk10 -= g;
        rider->unk90[11].unk10 += g;
        rider->unk90[9].unk10 -= g;
        rider->unk90[7].unk10 -= g;
        rider->unk90[10].unk10 -= g;
    }
    if ((rider->unkC78 == 0) && (rider->unk1598 == 0)) {
        f = ((rider->unk50 * rider->unk78) + (rider->unk58 * rider->unk80)) * D_800D498C;
        x = (rider->unk78 * f) * 0.1;
        y = rider->unk7C * f;
        z = (rider->unk80 * f) * 0.1;
        for (point = &rider->unk90[rider->unk28]; point >= rider->unk90; point--) {
            point->unkC += x;
            point->unk10 += y;
            point->unk14 += z;
        }
    }
    if (rider->unk1598 == 3) {
        rider->unk18 = D_800D49D8;
    } else {
        f = rider->unk70 * D_800D4988 *
            ((rider->unk50 * rider->unk6C) + (rider->unk54 * rider->unk70) + (rider->unk58 * rider->unk74));
        if (f < 0.0f) {
            f = D_800D49D0;
        } else if (f > 1.0f) {
            f = D_800D49D4;
        } else {
            f = ((D_800D49D4 - D_800D49D0) * f) + D_800D49D0;
        }
        if (rider->unk18 < D_800D49D4) {
            rider->unk18 += 0.001f;
        } else {
            rider->unk18 = f;
        }
    }
    if (D_801C3D14[arg0].unk0 != 0) {
        func_8004E0A4(rider, rider->unk15D4);
    } else {
        func_8004E548((struct UnkStruct_8004B0F8*) rider, rider->unk15D4);
    }
    f = rider->unkB5F / 70.0f;
    if (f < 0.0f) {
        rider->unk10 = ((D_800D4ACC - D_800D4AD0) * SQ(f)) + D_800D4AD0;
    } else {
        f *= (rider->unk18 - D_800D49D4) / (D_800D49D0 - D_800D49D4);
        rider->unk10 = ((D_800D4AD4 - D_800D4AD0) * f) + D_800D4AD0;
    }
    if ((u16) D_800D496C != 0) {
        func_80051740((struct UnkStruct_801C3C50*) rider, (struct UnkStruct_8004B0F8*) rider);
    }
    if ((u16) D_800D4974 != 0) {
        func_8007F030(rider, rider);
    }
    func_8007F700(rider);
    if ((u16) D_800D4978 != 0) {
        func_8007E8C8(rider);
    }
    func_8007EF80(rider);
    func_8007ECBC(rider);
    func_8004B1B4((struct UnkStruct_8004B0F8*) rider);
    func_800624CC(rider);
    if (rider->unkC7C != 0) {
        f = rider->unkB90 * -0.018f;
        if (f < -1.0f) {
            f = -1.0f;
        } else if ((f > -0.5f) && (rider->unkC66 != 0)) {
            f = -0.5f;
        }
        func_8004F3D4(rider->unk44.x - (120.0f * rider->unk5C), rider->unk44.z - (120.0f * rider->unk64),
                      (s32) (rider->unk15D0 * f));
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80064C0C.s")
#endif

#ifdef NON_MATCHING
// Score 6824 of 61400: register allocation and scheduling differ in places (dx/dz in $f2/$f0 rather than $f16/$f14,
// the C14..C34 block, the zero constants); control flow follows the original.
void func_80065C18(s32 arg0) {
    UnkStruct_80192690* rider = &D_80192690[arg0];
    camera_unk_1* cam;
    UnkStruct_8004B0F8_1* point;
    f32 dx;
    f32 dz;
    f32 x;
    f32 y;
    f32 z;
    f32 len;
    f32 scale;
    s32 count;

    if (rider->unk44.x < D_801924B0) {
        dx = D_801924B4;
    } else if (D_801924AC < rider->unk44.x) {
        dx = -D_801924B4;
    } else {
        dx = 0.0f;
    }
    if (rider->unk44.z < D_801924BC) {
        dz = D_801924C0;
    } else if (D_801924B8 < rider->unk44.z) {
        dz = -D_801924C0;
    } else {
        dz = 0.0f;
    }
    rider->unkBF0 = dx;
    rider->unkBF4 = dz;
    if (arg0 == gPlayer1Rider) {
        cam = &gCameraPerspective[D_80223930];
        cam->eyeX += dx;
        cam->eyeZ += dz;
    } else if ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider)) {
        cam = &gCameraPerspective[D_80223934];
        cam->eyeX += dx;
        cam->eyeZ += dz;
    }
    Rider_MovePoints(rider, dx, 0.0f, dz);
    if (gRiderGameModes != PAUSE_MODE) {
        x = rider->unk44.x - rider->unkBE4;
        rider->unkB84 = x - rider->unkB78;
        rider->unkB78 = x;
        y = rider->unk44.y - rider->unkBE8;
        rider->unkB88 = y - rider->unkB7C;
        rider->unkB7C = y;
        z = rider->unk44.z - rider->unkBEC;
        rider->unkB8C = z - rider->unkB80;
        rider->unkB80 = z;
        rider->unkB90 = sqrtf(SQ(x) + SQ(y) + SQ(z));
        if (rider->unkB94 < rider->unkB90) {
            rider->unkB94 = rider->unkB90;
        }
    }
    if (((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) && (rider->unkC66 != 0)) {
        if ((rider->unk16B4 < 40) && (rider->unkB90 < 2.777778f)) {
            rider->unk16B4++;
        }
    } else {
        rider->unk16B4 = 0;
    }
    if (gRiderGameModes != PAUSE_MODE) {
        x = rider->unk44.x + (0.1806645 * rider->unk78) + (-26.9998535 * rider->unk6C);
        y = x - rider->unkC14;
        rider->unkC14 = x;
        rider->unkC2C = y - rider->unkC20;
        rider->unkC20 = y;
        x = rider->unk44.y + (0.1806645 * rider->unk7C) + (-26.9998535 * rider->unk70);
        y = x - rider->unkC18;
        rider->unkC18 = x;
        rider->unkC30 = y - rider->unkC24;
        rider->unkC24 = y;
        x = rider->unk44.z + (0.1806645 * rider->unk80) + (-26.9998535 * rider->unk74);
        y = x - rider->unkC1C;
        rider->unkC1C = x;
        rider->unkC34 = y - rider->unkC28;
        rider->unkC28 = y;
    }
    count = 0;
    for (point = &rider->unk90[11]; point >= rider->unk90; point--) {
        if (point->unk1C & 1) {
            count++;
        }
    }
    rider->unkC82 = rider->unkC7C;
    if (count != 0) {
        rider->unkC7C = 1;
    } else {
        rider->unkC7C = 0;
    }
    rider->unkC78 = count;
    rider->unkC7E = rider->unkC7C & (rider->unkC82 ^ rider->unkC7C);
    rider->unkC80 = rider->unkC82 & (rider->unkC82 ^ rider->unkC7C);
    if ((rider->unkC7C == 0) &&
        ((rider->unkC4C != 0.0f) || ((rider->unkC48 != 0.0f) && (rider->unk15DE == 0)) || (rider->unkC44 != 0.0f))) {
        rider->unk16D0++;
    } else {
        rider->unk16D0 = 0;
    }
    if ((rider->unkC7C != 0) || ((rider->unkC4C + rider->unkC48 + rider->unkC44) != 0.0f)) {
        if (rider->unk1598 == 0) {
            rider->unk16E2 = 0;
            rider->unk16D4 = 0;
        }
    } else {
        rider->unk16DC++;
    }
    if ((rider->unk16E2 != 0) && (gRiderGameModes != PAUSE_MODE)) {
        x = rider->unk90[4].unkC - rider->unk50;
        y = rider->unk90[4].unk10 - rider->unk54;
        z = rider->unk90[4].unk14 - rider->unk58;
        len = sqrtf(SQ(x) + SQ(y) + SQ(z));
        x = rider->unk90[1].unkC - rider->unk50;
        y = rider->unk90[1].unk10 - rider->unk54;
        z = rider->unk90[1].unk14 - rider->unk58;
        len += sqrtf(SQ(x) + SQ(y) + SQ(z));
        if (rider->unk88 < 0.0f) {
            scale = 1.0 - (rider->unk88 * 0.5f);
        } else {
            scale = (rider->unk88 * 0.5f) + 1.0;
        }
        len *= scale;
        if ((rider->unk1598 == 2) || (rider->unk1598 == 1)) {
            rider->unk15EC += 2.8f * len;
        } else {
            rider->unk15EC += len;
        }
    }
    if (rider->unk16CE != 0) {
        if (rider->unkC40 != 0.0f) {
            rider->unk1602 = 1;
        } else {
            rider->unk1602 = 0;
        }
    }
    func_8005DE24(arg0);
    if ((rider->unkB68 == 2) || (D_801CE64C == 2)) {
        func_800609EC(arg0);
    }
    rider->unkC84 = rider->unkC86;
    if ((rider->unkC54 == 23) || (rider->unkC54 == 5)) {
        if (RIDER_PARTS(rider)[2].unk4.y < func_8004D30C(RIDER_PARTS(rider)[2].unk4.x, RIDER_PARTS(rider)[2].unk4.z)) {
            rider->unkC86 = 1;
        } else {
            rider->unkC86 = 0;
        }
    } else {
        rider->unkC86 = 0;
    }
    if ((rider->unk1606 > 0) && (--rider->unk1606 == 0)) {
        if (((rider->unkC54 == 7) && (rider->unk157C == 0)) || (rider->unkC54 == 23) || (rider->unk1608 != 0)) {
            rider->unk1604 = 8;
        } else if (((rider->unkC54 == 7) && (rider->unk157C == 1)) || (rider->unkC54 == 24) || (rider->unk16E0 != 0)) {
            rider->unk1604 = 7;
        } else {
            rider->unk1604 = 6;
            rider->unk15EC *= rider->unk7C;
            if (arg0 == gPlayer1Rider) {
                func_800C35B4();
            }
        }
        func_80051EC0(arg0);
    } else {
        if ((rider->unk1606 < 0) &&
            ((rider->unkC7C != 0) || (((rider->unkC4C != 0.0f) || (rider->unkC48 != 0.0f)) && (rider->unk16DC >= 6)))) {
            rider->unk1606 = 5;
        }
        if (rider->unkC54 == 8) {
            rider->unk1604 = 1;
        } else if (rider->unkC54 == 9) {
            rider->unk1604 = 2;
        } else if (rider->unkC54 == 17) {
            if (rider->unkC58 == 60) {
                rider->unk1604 = 10;
            } else if (rider->unkC58 == 37) {
                rider->unk1604 = 0;
            } else {
                rider->unk1604 = 9;
            }
        } else if (rider->unk1598 == 2) {
            rider->unk1604 = 3;
        } else if (rider->unk1598 == 1) {
            rider->unk1604 = 4;
        } else if (rider->unk1598 == 4) {
            rider->unk1604 = 5;
        } else if ((rider->unk1598 == 3) && (rider->unkC78 == 12)) {
            rider->unk1604 = 11;
        } else {
            rider->unk1604 = 0;
        }
    }
    if (rider->unkC54 == 23) {
        rider->unk15C0 = 2;
    } else if (rider->unkC54 == 24) {
        rider->unk15C0 = 1;
    } else if (rider->unkC54 == 7) {
        if (rider->unk157C == 0) {
            rider->unk15C0 = 2;
        } else {
            rider->unk15C0 = 1;
        }
    } else {
        rider->unk15C0 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_80065C18.s")
#endif

#ifdef NON_MATCHING
// Score 9093 of 76300: register allocation and scheduling differ (the original keeps &D_80192650/&D_80192670 and the
// nearest rider in saved registers); control flow follows the original.
void func_800665B0(void) {
    UnkStruct_80192690* player;
    UnkStruct_80192690* other;
    camera_unk_1* cam;
    s32 i;
    s32 n;
    s32 nearest;
    s32 level;
    s32 flag;
    u8 pan;
    f32 best;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 lim;
    f32 r;
    f32 sx;
    f32 sz;

    if (D_801CE638 != 21) {
        for (i = gRiders - 1; i >= 0; i--) {
            if (i == gPlayer1Rider) {
                if ((D_800D4964 != 0) || (gRiderGameModes == AI_MODE)) {
                    func_800616B0(i);
                } else {
                    Rider_ReadController(i, 0);
                }
            } else if (i == gPlayer2Rider) {
                if ((D_800D4964 != 0) || (gRiderGameModes == AI_MODE) || (gPlayers == ONE_PLAYER)) {
                    func_800616B0(i);
                } else {
                    Rider_ReadController(i, 1);
                }
            } else {
                func_800616B0(i);
            }
        }
    }
    for (i = gRiders - 1; i >= 0; i--) {
        func_80063C88(i);
    }
    if ((D_801CE638 != 21) && (gRiderGameModes != PAUSE_MODE)) {
        for (n = D_800D4924; n != 0; n--) {
            if (D_800D4968 != 0) {
                Riders_PushApart();
            }
            for (i = gRiders - 1; i >= 0; i--) {
                func_80064C0C(i);
            }
        }
    }
    for (i = gRiders - 1; i >= 0; i--) {
        func_80065C18(i);
    }
    func_80052480(gPlayer1Rider, (struct UnkStruct_80052480*) &D_80192610);
    func_800C118C(&D_80192610);
    if (gPlayers == TWO_PLAYERS) {
        func_80052480(gPlayer2Rider, (struct UnkStruct_80052480*) D_80192630);
        func_800C11CC(D_80192630);
    } else if (gRiders >= 2) {
        best = 1e10f;
        player = &D_80192690[gPlayer1Rider];
        for (i = gRiders - 1; i >= 0; i--) {
            if (i != gPlayer1Rider) {
                dx = player->unk44.x - D_80192690[i].unk44.x;
                dz = player->unk44.z - D_80192690[i].unk44.z;
                if (SQ(dx) + SQ(dz) < best) {
                    best = SQ(dx) + SQ(dz);
                    nearest = i;
                }
            }
        }
        func_80052480(nearest, (struct UnkStruct_80052480*) D_80192630);
        func_800C11CC(D_80192630);
        D_80192650.x = player->unk44.x;
        D_80192650.y = player->unk44.y;
        D_80192650.z = player->unk44.z;
        D_80192660.x = player->unkB78;
        D_80192660.y = player->unkB7C;
        D_80192660.z = player->unkB80;
        other = &D_80192690[nearest];
        D_80192670.x = other->unk44.x;
        D_80192670.y = other->unk44.y;
        D_80192670.z = other->unk44.z;
        D_80192680.x = other->unkB78;
        D_80192680.y = other->unkB7C;
        D_80192680.z = other->unkB80;
        dx = D_80192670.x - D_80192650.x;
        dz = D_80192670.z - D_80192650.z;
        dist = SQ(dx) + SQ(dz);
        if (dist == 0.0f) {
            pan = 64;
        } else {
            dist = sqrtf(dist);
            cam = &gCameraPerspective[D_80223930];
            pan = 127 - (s32) (((((1.0f / dist) * ((cam->unkF4 * dx) - (cam->unkF0 * dz))) + 1.0f) * 63.5f) + 0.5f);
        }
        func_800BFB84(&D_80192650, &D_80192670, &D_80192660, &D_80192680, pan);
    }
    if (gRiderGameModes != PAUSE_MODE) {
        r = D_80192498;
        cam = &gCameraPerspective[D_80223930];
        sx = gWaterWindow[0].unk0 + (r * cam->unkF0);
        sz = gWaterWindow[0].unk4 + (r * cam->unkF4);
        if (gPlayers == ONE_PLAYER) {
            player = &D_80192690[gPlayer1Rider];
            dist = (s32) sqrtf(SQ(player->unk44.z) + SQ(player->unk44.x));
            if (dist <= D_801C1FB4) {
                level = D_800D49B0;
            } else {
                lim = D_801C1FB4 + 4000.0f;
                level = 60;
                if (D_801924AC < lim) {
                    lim = D_801924AC;
                }
                if (dist < lim) {
                    level = (((dist - D_801C1FB4) * (f32) (60 - D_800D49B0)) / (lim - D_801C1FB4)) + (f32) D_800D49B0;
                }
            }
            Water_StampDiagonalSine(sx, sz, level, D_800D49AC, 1);
        } else {
            flag = 1;
            dx = sx - D_80192690[gPlayer2Rider].unk44.x;
            dz = sz - D_80192690[gPlayer2Rider].unk44.z;
            if ((f32) (D_80192498 * D_80192498) < SQ(dx) + SQ(dz)) {
                flag = 0;
                Water_StampDiagonalSine(sx, sz, D_800D49B0, D_800D49AC, 1);
            }
            cam = &gCameraPerspective[D_80223934];
            sx = gWaterWindow[1].unk0 + (r * cam->unkF0);
            sz = gWaterWindow[1].unk4 + (r * cam->unkF4);
            dx = sx - D_80192690[gPlayer1Rider].unk44.x;
            dz = sz - D_80192690[gPlayer1Rider].unk44.z;
            if ((f32) (D_80192498 * D_80192498) < SQ(dx) + SQ(dz)) {
                Water_StampDiagonalSine(sx, sz, D_800D49B0, D_800D49AC, flag);
            }
        }
    }
    cam = &gCameraPerspective[D_80223930];
    cam->unk40 = RIDER_C88(&D_80192690[gPlayer1Rider])[D_80192690[gPlayer1Rider].unk1424][7].unk0.x;
    cam->unk44 = RIDER_C88(&D_80192690[gPlayer1Rider])[D_80192690[gPlayer1Rider].unk1424][7].unk0.y;
    cam->unk48 = RIDER_C88(&D_80192690[gPlayer1Rider])[D_80192690[gPlayer1Rider].unk1424][7].unk0.z;
    cam->unk4 = D_80192690[gPlayer1Rider].unk44.x;
    *(f32*) &cam->unk8 = D_80192690[gPlayer1Rider].unk44.y;
    cam->unkC = D_80192690[gPlayer1Rider].unk44.z;
    cam->unk10 = D_80192690[gPlayer1Rider].unkB78;
    cam->unk14 = D_80192690[gPlayer1Rider].unkB7C;
    cam->unk18 = D_80192690[gPlayer1Rider].unkB80;
    cam->unk1C = D_80192690[gPlayer1Rider].unk6C;
    cam->unk20 = D_80192690[gPlayer1Rider].unk70;
    cam->unk24 = D_80192690[gPlayer1Rider].unk74;
    cam->unk28 = D_80192690[gPlayer1Rider].unk78;
    cam->unk2C = D_80192690[gPlayer1Rider].unk7C;
    cam->unk30 = D_80192690[gPlayer1Rider].unk80;
    cam->unk34 = D_80192690[gPlayer1Rider].unk84;
    cam->unk38 = D_80192690[gPlayer1Rider].unk88;
    cam->unk3C = D_80192690[gPlayer1Rider].unk8C;
    if (gPlayers == TWO_PLAYERS) {
        cam = &gCameraPerspective[D_80223934];
        cam->unk40 = RIDER_C88(&D_80192690[gPlayer2Rider])[D_80192690[gPlayer2Rider].unk1424][7].unk0.x;
        cam->unk44 = RIDER_C88(&D_80192690[gPlayer2Rider])[D_80192690[gPlayer2Rider].unk1424][7].unk0.y;
        cam->unk48 = RIDER_C88(&D_80192690[gPlayer2Rider])[D_80192690[gPlayer2Rider].unk1424][7].unk0.z;
        cam->unk4 = D_80192690[gPlayer2Rider].unk44.x;
        *(f32*) &cam->unk8 = D_80192690[gPlayer2Rider].unk44.y;
        cam->unkC = D_80192690[gPlayer2Rider].unk44.z;
        cam->unk10 = D_80192690[gPlayer2Rider].unkB78;
        cam->unk14 = D_80192690[gPlayer2Rider].unkB7C;
        cam->unk18 = D_80192690[gPlayer2Rider].unkB80;
        cam->unk1C = D_80192690[gPlayer2Rider].unk6C;
        cam->unk20 = D_80192690[gPlayer2Rider].unk70;
        cam->unk24 = D_80192690[gPlayer2Rider].unk74;
        cam->unk28 = D_80192690[gPlayer2Rider].unk78;
        cam->unk2C = D_80192690[gPlayer2Rider].unk7C;
        cam->unk30 = D_80192690[gPlayer2Rider].unk80;
        cam->unk34 = D_80192690[gPlayer2Rider].unk84;
        cam->unk38 = D_80192690[gPlayer2Rider].unk88;
        cam->unk3C = D_80192690[gPlayer2Rider].unk8C;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800665B0.s")
#endif

Gfx* Rider_DrawPartsReflect(Gfx* gdl, s32 arg1) {
    gSPClearGeometryMode(gdl++, G_CULL_FRONT);
    gSPSetGeometryMode(gdl++, G_CULL_BACK);
    if ((gRiderRaceState[arg1].unk338 == 0) && (gDifficulty == DIFFICULTY_EXPERT)) {
        guLookAtReflect(&gGfxPool->unkE108[arg1], (LookAt*) &gGfxPool->unkE208[arg1], gCameraPerspective[D_80223930].eyeX,
                        gCameraPerspective[D_80223930].eyeY, gCameraPerspective[D_80223930].eyeZ,
                        gCameraPerspective[D_80223930].atX, gCameraPerspective[D_80223930].atY,
                        gCameraPerspective[D_80223930].atZ, gCameraPerspective[D_80223930].upX,
                        gCameraPerspective[D_80223930].upY, gCameraPerspective[D_80223930].upZ);
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

Gfx* Rider_DrawParts(Gfx* gdl, s32 arg1, s32 arg2) {
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

Gfx* Rider_BuildPartsList(Gfx* gdl, s32 arg1, s32 arg2) {
    gdl = Rider_DrawParts(gdl, arg1, arg2);
    gSPEndDisplayList(gdl++);
    if (D_80193D5C[arg2].unk0.h != 0) {
        gdl += 6;
    }
    return gdl;
}

void Riders_BuildPartsLists(void) {
    Gfx* gdl = (Gfx*) &D_8011EDE0;
    s32 i;
    s32 j;

    if ((D_801CE638 == 0) || ((D_801CE638 == 8) && (gCourseID != SUNNY_BEACH))) {
        gdl = Rider_BuildPartsList(gdl, 0, gPlayer1Rider);
        gdl = Rider_BuildPartsList(gdl, 1, gPlayer2Rider);
        return;
    }
    if (D_801CE64C != 2) {
        if ((gPlayers == ONE_PLAYER) || ((D_801CE638 == 8) && (gCourseID == SUNNY_BEACH))) {
            j = 1;
            for (i = 0; i < gRiders; i++) {
                if (i == gPlayer1Rider) {
                    gdl = Rider_BuildPartsList(gdl, 0, i);
                    gdl = Rider_BuildPartsList(gdl, 0, i);
                } else {
                    gdl = Rider_BuildPartsList(gdl, j, i);
                    gdl = Rider_BuildPartsList(gdl, j + 1, i);
                    j += 2;
                }
            }
        } else {
            gdl = Rider_BuildPartsList(gdl, 0, gPlayer1Rider);
            gdl = Rider_BuildPartsList(gdl, 1, gPlayer2Rider);
            gdl = Rider_BuildPartsList(gdl, 2, gPlayer1Rider);
            gdl = Rider_BuildPartsList(gdl, 3, gPlayer2Rider);
            gdl = Rider_BuildPartsList(gdl, 4, gPlayer1Rider);
            gdl = Rider_BuildPartsList(gdl, 5, gPlayer2Rider);
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
        } else if (i == gPlayer1Rider) {
            if (((D_800D4964 != 0) || (gRiderGameModes == AI_MODE)) && (D_801CE638 != 4)) {
                D_80192690[i].unk16CE = 1;
            } else {
                D_80192690[i].unk16CE = 0;
            }
        } else if (i == gPlayer2Rider) {
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
    Riders_BuildPartsLists();
    cam = &gCameraPerspective[D_80223930];
    cam->unk4 = D_80192690[gPlayer1Rider].unk44.x;
    *(f32*) &cam->unk8 = D_80192690[gPlayer1Rider].unk44.y;
    cam->unkC = D_80192690[gPlayer1Rider].unk44.z;
    cam->unk10 = D_80192690[gPlayer1Rider].unk50;
    cam->unk14 = D_80192690[gPlayer1Rider].unk54;
    cam->unk18 = D_80192690[gPlayer1Rider].unk58;
    cam->unk1C = D_80192690[gPlayer1Rider].unk6C;
    cam->unk20 = D_80192690[gPlayer1Rider].unk70;
    cam->unk24 = D_80192690[gPlayer1Rider].unk74;
    cam->unk28 = D_80192690[gPlayer1Rider].unk78;
    cam->unk2C = D_80192690[gPlayer1Rider].unk7C;
    cam->unk30 = D_80192690[gPlayer1Rider].unk80;
    cam->unk34 = D_80192690[gPlayer1Rider].unk84;
    cam->unk38 = D_80192690[gPlayer1Rider].unk88;
    cam->unk3C = D_80192690[gPlayer1Rider].unk8C;
    cam = &gCameraPerspective[D_80223934];
    cam->unk4 = D_80192690[gPlayer2Rider].unk44.x;
    *(f32*) &cam->unk8 = D_80192690[gPlayer2Rider].unk44.y;
    cam->unkC = D_80192690[gPlayer2Rider].unk44.z;
    cam->unk10 = D_80192690[gPlayer2Rider].unk50;
    cam->unk14 = D_80192690[gPlayer2Rider].unk54;
    cam->unk18 = D_80192690[gPlayer2Rider].unk58;
    cam->unk1C = D_80192690[gPlayer2Rider].unk6C;
    cam->unk20 = D_80192690[gPlayer2Rider].unk70;
    cam->unk24 = D_80192690[gPlayer2Rider].unk74;
    cam->unk28 = D_80192690[gPlayer2Rider].unk78;
    cam->unk2C = D_80192690[gPlayer2Rider].unk7C;
    cam->unk30 = D_80192690[gPlayer2Rider].unk80;
    cam->unk34 = D_80192690[gPlayer2Rider].unk84;
    cam->unk38 = D_80192690[gPlayer2Rider].unk88;
    cam->unk3C = D_80192690[gPlayer2Rider].unk8C;
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
            if (i == gPlayer1Rider) {
                if (D_801CE6F4[0] != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            } else if ((i == gPlayer2Rider) && (gPlayers == TWO_PLAYERS)) {
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

#ifdef NON_MATCHING
// Score 14274 of 73400: register allocation and scheduling differ throughout (the original keeps more of the GBI
// words in registers); control flow and the display lists follow the original.
// Distance of rider r in front of camera c, along the camera's view axis.
#define CAM_DEPTH(c, r)                                                                 \
    (((c)->unk6C * ((r)->unk44.z - (c)->eyeZ)) +                                       \
     ((((r)->unk44.x - (c)->eyeX) * (c)->unk64) + (((r)->unk44.y - (c)->eyeY) * (c)->unk68)))

// Near riders: one-cycle, no fog.
#define RIDER_FOG_OFF(gdl)                                                              \
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);                                               \
    gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);                 \
    gDPSetCombineMode(gdl++, G_CC_MODULATERGBDECALA, G_CC_MODULATERGBDECALA);           \
    gSPClearGeometryMode(gdl++, G_FOG)

// Far riders: two-cycle with shade fog.
#define RIDER_FOG_ON(gdl)                                                               \
    gDPSetCycleType(gdl++, G_CYC_2CYCLE);                                               \
    gDPSetRenderMode(gdl++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);                    \
    gDPSetCombineMode(gdl++, G_CC_MODULATERGBDECALA, G_CC_PASS2);                       \
    gSPSetGeometryMode(gdl++, G_FOG)

// Segment 2 holds two display lists of 0x148 bytes per rider.
#define RIDER_DL(rider, lod) ((Gfx*) ((u8*) D_2000000 + (rider) * 0x290 + (lod) * 0x148))

Gfx* func_800687A4(Gfx* gdl) {
    UnkStruct_80192690* rider;
    camera_unk_1* cam;
    s32 i;
    s32 idx;
    f32 d;

    gSPDisplayList(gdl++, D_10079F0);
    gdl = func_800916B4(gdl);
    if (D_801CE64C == 2) {
        RIDER_FOG_OFF(gdl);
        if (D_800DAB2C != 0) {
            idx = D_80192690[gPlayer2Rider].unkB68;
            if (D_801CE6F4[1] != 0) {
                idx += 4;
            }
            gdl = Rider_DrawParts(gdl, idx, gPlayer2Rider);
        } else {
            idx = D_80192690[gPlayer1Rider].unkB68;
            if (D_801CE6F4[0] != 0) {
                idx += 4;
            }
            gdl = Rider_DrawParts(gdl, idx, gPlayer1Rider);
        }
    } else if ((D_801CE638 == 0) || ((D_801CE638 == 8) && (gCourseID != SUNNY_BEACH))) {
        RIDER_FOG_ON(gdl);
        gSPDisplayList(gdl++, RIDER_DL(0, 0));
        if ((D_801CE638 != 8) || (gCourseID == SUNSET_BAY)) {
            gSPDisplayList(gdl++, RIDER_DL(0, 1));
        }
    } else if (gPlayers == TWO_PLAYERS) {
        RIDER_FOG_OFF(gdl);
        if (D_800DAB2C != 0) {
            gSPDisplayList(gdl++, RIDER_DL(1, 1));
            gDPPipeSync(gdl++);
            cam = &gCameraPerspective[D_80223934];
            rider = &D_80192690[gPlayer1Rider];
            d = CAM_DEPTH(cam, rider);
            if (d > 1000.0f) {
                RIDER_FOG_ON(gdl);
            } else if (d > 0.0f) {
                RIDER_FOG_OFF(gdl);
            }
            if (D_800D49A8 < d) {
                gSPDisplayList(gdl++, RIDER_DL(2, 0));
            } else if (D_800D49A4 < d) {
                gSPDisplayList(gdl++, RIDER_DL(2, 0));
            } else if (d > 0.0f) {
                gSPDisplayList(gdl++, RIDER_DL(1, 0));
            }
        } else {
            gSPDisplayList(gdl++, RIDER_DL(1, 0));
            gDPPipeSync(gdl++);
            cam = &gCameraPerspective[D_80223930];
            rider = &D_80192690[gPlayer2Rider];
            d = CAM_DEPTH(cam, rider);
            if (d > 1000.0f) {
                RIDER_FOG_ON(gdl);
            } else if (d > 0.0f) {
                RIDER_FOG_OFF(gdl);
            }
            if (D_800D49A8 < d) {
                gSPDisplayList(gdl++, RIDER_DL(2, 1));
            } else if (D_800D49A4 < d) {
                gSPDisplayList(gdl++, RIDER_DL(2, 1));
            } else if (d > 0.0f) {
                gSPDisplayList(gdl++, RIDER_DL(1, 1));
            }
        }
    } else if (D_801CE638 != 21) {
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_MODULATERGBDECALA, G_CC_MODULATERGBDECALA);
        gSPDisplayList(gdl++, RIDER_DL(gPlayer1Rider, 0));
        gSPClearGeometryMode(gdl++, G_FOG);
        for (i = 0; i < gRiders; i++) {
            if (i != gPlayer1Rider) {
                gDPPipeSync(gdl++);
                rider = &D_80192690[i];
                if (i == 1) {
                    gdl = func_80091CD8(gdl);
                }
                cam = &gCameraPerspective[D_80223930];
                d = CAM_DEPTH(cam, rider);
                if (d > 1000.0f) {
                    RIDER_FOG_ON(gdl);
                } else if (d > 0.0f) {
                    RIDER_FOG_OFF(gdl);
                } else {
                    continue;
                }
                if (D_800D49A8 < d) {
                    gSPDisplayList(gdl++, RIDER_DL(i, 1));
                } else {
                    gSPDisplayList(gdl++, RIDER_DL(i, 0));
                }
            }
        }
    } else {
        RIDER_FOG_ON(gdl);
        gdl = Rider_DrawPartsReflect(gdl, 0);
        gdl = Rider_DrawPartsReflect(gdl, 1);
        gdl = Rider_DrawPartsReflect(gdl, 2);
        gdl = Rider_DrawPartsReflect(gdl, 3);
    }
    for (i = 0; i < gRiders; i++) {
        if (D_80192690[i].unk16CC != 0) {
            func_800683A0(i);
        }
    }
    return gdl;
}

#undef CAM_DEPTH
#undef RIDER_FOG_OFF
#undef RIDER_FOG_ON
#undef RIDER_DL
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_C6C0/func_800687A4.s")
#endif

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
    arg0 = func_800694B8(arg0, gPlayer1Rider);
    for (var_s0 = 0; var_s0 < gRiders; var_s0++) {
        if (var_s0 != gPlayer1Rider) {
            temp_v0 = &gCameraPerspective[D_80223930];
            temp_v1 = &D_80192690[var_s0];
            temp_f0 = (temp_v0->unk6C * (temp_v1->unk44.z - temp_v0->eyeZ)) +
                      (((temp_v1->unk44.x - temp_v0->eyeX) * temp_v0->unk64) +
                       ((temp_v1->unk44.y - temp_v0->eyeY) * temp_v0->unk68));
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

void Camera_SetOrbitMatrices(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4, void* arg5) {
    f32 eye[3];
    f32 r;
    MtxF lookAt;
    MtxF scaleMtx;
    MtxF result;

    r = CAM->distance * SCALE->y;
    eye[0] = ((r * COS(DEG_TO_BINANG(CAM->pitch))) * COS(DEG_TO_BINANG(CAM->yaw))) + CAM->target.x;
    eye[1] = (SIN(DEG_TO_BINANG(CAM->pitch)) * r) + CAM->target.y;
    eye[2] = ((r * COS(DEG_TO_BINANG(CAM->pitch))) * SIN(DEG_TO_BINANG(CAM->yaw))) + CAM->target.z;
    r = CAM->yaw + (CAM->yawSpeed * SCALE->z);
    CAM->yaw = (r + ((r > 360.0f) ? -360.0f : 0.0f)) + ((r < 0.0f) ? 360.0f : 0.0f);
    func_800484C8(arg0, &lookAt, eye[0], eye[1], eye[2], CAM->target.x, CAM->target.y, CAM->target.z, 0.0f, 1.0f, 0.0f);
    r = CAM->scale * SCALE->x;
    func_801EE91C(scaleMtx.mf, r, r, r);
    SysUtils_MatrixAffineMultiply(&lookAt, &scaleMtx, &result);
    SysUtils_MtxFToMtx(&result, arg0);
    *(UnkStruct_80069798_1*) arg1 = CAM->unk28;
    func_800481E0(arg2, arg3, CAM->fov, 1.0f, D_800D4AF0, D_800D4AF4, 0.0f, 0.0f);
}

#undef CAM
#undef SCALE
