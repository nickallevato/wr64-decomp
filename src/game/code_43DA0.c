#include "global.h"
#include "camera.h"

typedef struct RgbaColors_s {
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
} RgbaColors;

typedef struct UnkStruct_8008962C_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
} UnkStruct_8008962C; // Might be the same as UnkStruct_801CEFF8

typedef struct UnkStruct_801CB058_s {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s32 unk34;
    /* 0x038 */ s32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ s32 unk48;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
    /* 0x05C */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ char pad64[4];
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ char pad74[4];
    /* 0x078 */ s32 unk78;
    /* 0x07C */ s32 unk7C;
    /* 0x080 */ char pad80[8];
    /* 0x088 */ s32 unk88;        /* inferred */
    /* 0x08C */ s32 unk8C;        /* inferred */
    /* 0x090 */ s32 unk90;        /* inferred */
    /* 0x094 */ s32 unk94;        /* inferred */
    /* 0x098 */ s32 unk98;        /* inferred */
    /* 0x09C */ s32 unk9C;        /* inferred */
    /* 0x0A0 */ s32 unkA0;
    /* 0x0A4 */ char padA4[4];
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ f32 unkAC;
    /* 0x0B0 */ f32 unkB0;
    /* 0x0B4 */ f32 unkB4;
    /* 0x0B8 */ s32 unkB8;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ char padC4[8];
    /* 0x0CC */ s32 unkCC;
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ s32 unkD4;
    /* 0x0D8 */ s32 unkD8;
    /* 0x0DC */ s32 unkDC;
    /* 0x0E0 */ s32 unkE0;
    /* 0x0E4 */ s32 unkE4;
    /* 0x0E8 */ s32 unkE8;
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0;
    /* 0x0F4 */ s32 unkF4;
    /* 0x0F8 */ s32 unkF8;
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10C */ s32 unk10C;
} UnkStruct_801CB058; /* size = 0x110 */

typedef struct UnkStruct_800DA624_s {
    u8 alpha[3];
} UnkStruct_800DA624;

typedef struct UnkStruct_80192420_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
} UnkStruct_80192420; /* size = 0x1C, as in water_69D0.c */

typedef struct UnkStruct_800DA8B4_s {
    s32 unk0[3];
} UnkStruct_800DA8B4;

typedef struct UnkStruct_801C41A0_s {
    f32 fwork[0xD0];
} UnkStruct_801C41A0;

extern UnkStruct_8008962C D_801C4278[];
extern UnkStruct_8008962C D_801C4290;
extern UnkStruct_8008962C D_801C42A8;
extern UnkStruct_8008962C D_801C42C0;
extern UnkStruct_8008962C D_801C42D8;
extern UnkStruct_8008962C D_801C42F0;
extern UnkStruct_8008962C D_801C4308;
extern UnkStruct_8008962C D_801C4320;
extern UnkStruct_8008962C D_801C4338;
extern UnkStruct_8008962C D_801C4350;
extern UnkStruct_8008962C D_801C4368;
extern UnkStruct_8008962C D_801C4380;
extern UnkStruct_8008962C D_801C4398;
extern UnkStruct_8008962C D_801C43B0;
extern UnkStruct_8008962C D_801C43C8;
extern UnkStruct_8008962C D_801C43E0;

extern UnkStruct_801CB058 D_801CB058[];
extern UnkStruct_801CB058 D_800D9964[];
extern UnkStruct_801CB058 D_800DA404;
extern s32 D_801C4160;
extern s32 D_801C4164;
extern s32 D_801C4168;
extern s32 D_80192498;
extern struct UnkStruct_801C3C60 D_801C3C60[];
extern UnkStruct_800DA624 D_800DA624;
extern s32 D_800D47E0[];
extern s16 gColorRed;
extern s16 gColorGreen;
extern s16 gColorBlue;
extern s16 gColorAlpha;
extern u8 D_100FAB0[];
extern s8 D_800D988C;
extern s32 D_800D9898[6];
extern s32 D_800D98B0[6];
extern s32 D_800D9914;
extern f32 D_800DA8B0;
extern UnkStruct_80192420 gWaterWindow[];
extern s32 D_80192460[];
extern RiderStruct gRiderRaceState[];
extern s32 D_80223934;
extern UnkStruct_800DA8B4 D_800DA8B4;
extern Vp D_800DA8C0;
extern Vp D_800DA8D0;
extern Vp D_800DA8E0;
extern Vp D_800DA8F0;
extern Vp D_800DA900;
extern s8 D_800D9888;
extern s32 D_801C1FD0;
extern s16 D_801CE60C;
extern u8 D_3000000[];
extern Gfx D_10102D0[];
extern Gfx D_1010330[];
extern Gfx D_10103B8[];
extern Gfx D_10103F0[];
extern Gfx D_1010430[];
extern Gfx D_1010470[];
extern Vtx D_60000E0[];
extern Vtx D_6000150[];
extern Vtx D_6000350[];
extern Vtx D_6000390[];
extern Vtx D_60003D0[];
extern Vtx D_6000410[];
extern Vtx D_6000450[];
extern Vtx D_6000490[];
extern Vtx D_60004D0[];
extern Vtx D_6000510[];
extern Vtx D_6000550[];
extern Vtx D_6000590[];
void func_8004A3C0(MtxF* arg0, MtxF* arg1, f32 x, f32 y, f32 z, f32 angle);
extern u8 D_8000000[];
extern u8 D_8000200[];
extern u8 D_8001400[];
extern u8 D_8007400[];
void func_8004C1D0(s32 view, Vtx* vtx);
void func_8004C998(s32 view, Vtx* skirt);
Gfx* func_8008D454(Gfx* gdl);
Gfx* func_8008D94C(Gfx* gdl);
Gfx* func_8008DFD0(Gfx* gdl);
Gfx* func_8008CFEC(Gfx* gdl);
Gfx* func_8008A0E0(Gfx* gdl);
extern s32 D_800D98CC;
extern s32 D_800D98D0;
extern s32 D_800D98D4;
extern u8 D_2000A40[];
extern Vtx D_6000310[];
extern u8 D_8004400[];
extern u8 D_8004C00[];
extern s32 D_800D9944[];
extern s8 D_800D9918[][3];
extern s32 D_800DA914;
extern s32 D_8035C800[];
extern s32 D_8035D200[];
extern s32 D_8035DC00[];
extern s32 D_8035E600[];
extern s32 D_8035F000[];
extern s32 D_8035FA00[];
extern s32 D_80360400[];
extern s32 D_80360E00[];
extern u16 D_1008290[];
extern u16 D_10082F0[];
extern u16 D_100B590[];
extern u16 D_100D258[];
extern u16 D_100E680[];
extern u16 D_8000400[];
extern s16 D_800D9890;
extern s32 D_800D9894;
extern f32 D_801CB160;
extern s32 D_800D9924[];
extern UnkStruct_8008962C D_801C4170;
extern UnkStruct_8008962C D_801C4188;
extern u16 D_10102B0[];
extern s32 D_800DA628[];
extern RgbaColors D_800DA6A8[];
extern UnkStruct_8008962C D_801C4278[];

extern UnkStruct_801C41A0 D_801C41A0;

void* func_80091DBC(Gfx* arg0);

void func_800895A0(f64* arg0, f64* arg1, f32 arg2, f32 arg3) {
    f64 sp0;
    f64 temp_f0;
    s32 pad[4];

    temp_f0 = (*arg0 * arg2) + (*arg1 * arg3);

    if (1000 <= temp_f0) {
        f64 temp;

        sp0 = *arg0 - (arg2 * temp_f0);
        temp = *arg1 - (arg3 * temp_f0);
        *arg0 = (arg2 * (f64) 1000) + sp0;
        *arg1 = (arg3 * (f64) 1000) + temp;
    }
}

f32 func_8008962C(f32 arg0, f32 arg1, f32 arg2, UnkStruct_8008962C* arg3) {
    MtxF spD0;
    MtxF sp90;
    camera_unk_1* cam;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 temp_fv1;
    f64 temp_fa0;
    f64 temp_fv0;
    f64 var_ft4 = 0;
    f32 temp_fv1_1;
    f32 temp_ft4;
    UNUSED s32 pad;

    cam = &gCameraPerspective[D_80223930];
    temp_fv1_1 = cam->unkF0;
    temp_ft4 = cam->unkF4;
    arg3->unk14 = (temp_fv1_1 * COS(ANGLE_TO_CUSTOM_UNITS(arg1))) + (SIN(ANGLE_TO_CUSTOM_UNITS(arg1)) * temp_ft4);
    if (arg3->unk14 < 0.5f) {
        arg3->unk0 = 0.0f;
        arg3->unk4 = 0.0f;
        arg3->unk8 = 0.0f;
        arg3->unkC = 0.0f;
        arg3->unk10 = 0.0f;
        arg3->unk14 = -1.0f;
    } else {
        SysUtils_MtxToMtxF(&gGfxPool->unkE008[D_80223930], &spD0);
        SysUtils_MtxToMtxF(&gGfxPool->unkE088[D_80223930], &sp90);
        temp_fv0 = arg0;
        sp80 = COS(ANGLE_TO_CUSTOM_UNITS(arg1)) * temp_fv0;
        sp70 = SIN(ANGLE_TO_CUSTOM_UNITS(arg1)) * temp_fv0;

        if (gCourseID != DOLPHIN_PARK) {
            func_800895A0(&sp80, &sp70, temp_fv1_1, temp_ft4);
        }
        sp80 += cam->eyeX;
        sp70 += cam->eyeZ;

        temp_fv0 = ((sp90.mf[0][0] * sp80) + var_ft4 + (sp90.mf[2][0] * sp70)) + sp90.mf[3][0];
        temp_fv1 = ((sp90.mf[0][1] * sp80) + var_ft4 + (sp90.mf[2][1] * sp70)) + sp90.mf[3][1];
        temp_fa0 = ((sp90.mf[0][2] * sp80) + var_ft4 + (sp90.mf[2][2] * sp70)) + sp90.mf[3][2];
        sp80 = ((spD0.mf[0][0] * temp_fv0) + (spD0.mf[1][0] * temp_fv1) + (spD0.mf[2][0] * temp_fa0)) + spD0.mf[3][0];
        sp78 = ((spD0.mf[0][1] * temp_fv0) + (spD0.mf[1][1] * temp_fv1) + (spD0.mf[2][1] * temp_fa0)) + spD0.mf[3][1];
        sp70 = ((spD0.mf[0][2] * temp_fv0) + (spD0.mf[1][2] * temp_fv1) + (spD0.mf[2][2] * temp_fa0)) + spD0.mf[3][2];
        var_ft4 =
            ((spD0.mf[0][3] * temp_fv0) + (spD0.mf[1][3] * temp_fv1) + (spD0.mf[2][3] * temp_fa0)) + spD0.mf[3][3];
        if ((var_ft4 < 0.01) && (var_ft4 > -0.01)) {
            if (var_ft4 >= 0.0) {
                var_ft4 = 0.01;
            }
            if (var_ft4 < 0.0) {
                var_ft4 = -0.01;
            }
        }
        if ((sp80 > 1000000000.0) || (sp80 < -1000000000.0)) {
            sp80 = 511.0;
        }
        if ((sp78 > 1000000000.0) || (sp78 < -1000000000.0)) {
            sp78 = 511.0;
        }
        if ((sp70 > 1000000000.0) || (sp70 < -1000000000.0)) {
            sp70 = 511.0;
        }
        arg3->unkC = sp90.mf[1][0] * arg2;
        arg3->unk10 = sp90.mf[1][1] * arg2;
        arg3->unk0 = ((sp80 * 320.0 * 0.5) / var_ft4) + 160.0;
        arg3->unk4 = 239.0 - (((sp78 * 240.0 * 0.5) / var_ft4) + 120.0);
        arg3->unk8 = sp70 / var_ft4;
        if ((var_ft4 < 1e-08) && (var_ft4 > -1e-08)) {
            arg3->unk0 = 1e8f;
            arg3->unk4 = 1e8f;
            arg3->unk8 = 1e8f;
        }

        if (((arg3->unkC + arg3->unk0) < -511.0f) || ((arg3->unkC + arg3->unk0) > 511.0f) ||
            (((arg3->unk10 + arg3->unk4) < -511.0f)) || ((arg3->unk10 + arg3->unk4) > 511.0f)) {
            arg3->unk0 = -64.0f;
            arg3->unk4 = -64.0f;
            arg3->unkC = 0.0f;
            arg3->unk10 = 0.0f;
            arg3->unk14 = -1.0f;
        }
    }
}

void func_80089C08(void) {
    func_8008962C(2000.0f, 0.0f, 80.0f, D_801C4278);
    func_8008962C(2000.0f, 22.5f, 40.0f, &D_801C4290);
    func_8008962C(2000.0f, 45.0f, 50.0f, &D_801C42A8);
    func_8008962C(2000.0f, 67.5f, 30.0f, &D_801C42C0);
    func_8008962C(2000.0f, 90.0f, 80.0f, &D_801C42D8);
    func_8008962C(2000.0f, 112.5f, 20.0f, &D_801C42F0);
    func_8008962C(2000.0f, 135.0f, 80.0f, &D_801C4308);
    func_8008962C(2000.0f, 157.5f, 70.0f, &D_801C4320);
    func_8008962C(2000.0f, 180.0f, 80.0f, &D_801C4338);
    func_8008962C(2000.0f, 202.5f, 60.0f, &D_801C4350);
    func_8008962C(2000.0f, 225.0f, 30.0f, &D_801C4368);
    func_8008962C(2000.0f, 257.5f, 50.0f, &D_801C4380);
    func_8008962C(2000.0f, 270.0f, 80.0f, &D_801C4398);
    func_8008962C(2000.0f, 292.5f, 90.0f, &D_801C43B0);
    func_8008962C(2000.0f, 315.0f, 20.0f, &D_801C43C8);
    func_8008962C(2000.0f, 337.5f, 30.0f, &D_801C43E0);
}

void func_80089DEC(void) {
    func_8008962C(2000.0f, 315.0f, 90.0f, &D_801C4188);
}

void func_80089E24(void) {
    switch (gCourseID) { /* irregular */
        case DOLPHIN_PARK:
            func_8008962C(2000.0f, 5.0f, D_800D9924[gCourseID], &D_801C4170);
            break;
        case SUNSET_BAY:
            func_8008962C(2000.0f, 315.0f, D_800D9924[gCourseID], &D_801C4170);
            break;
        case GLACIER_COAST:
            func_8008962C(2000.0f, 196.0f, D_800D9924[gCourseID], &D_801C4170);
            break;
        default:
            break;
    }
}

void func_80089F28(void) {
    MtxF sp80;
    MtxF sp40;
    char pad[0x20];
    SysUtils_MtxToMtxF(&gGfxPool->unkE008[D_80223930], &sp80);
    SysUtils_MtxToMtxF(&gGfxPool->unkE088[D_80223930], &sp40);

    D_801C41A0.fwork[3] = sp40.mf[1][0] * (D_800D9924[gCourseID] + 0x3C);
    D_801C41A0.fwork[4] = sp40.mf[1][1] * (D_800D9924[gCourseID] + 0x3C);
    D_801C41A0.fwork[9] = sp40.mf[1][0] * (D_800D9924[gCourseID] + 0x1E);
    D_801C41A0.fwork[0xA] = sp40.mf[1][1] * (D_800D9924[gCourseID] + 0x1E);
    D_801C41A0.fwork[0xF] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0xA);
    D_801C41A0.fwork[0x10] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0xA);
    D_801C41A0.fwork[0x15] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0x14);
    D_801C41A0.fwork[0x16] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0x14);
    D_801C41A0.fwork[0x1B] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0x28);
    D_801C41A0.fwork[0x1C] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0x28);
    D_801C41A0.fwork[0x21] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0x32);
    D_801C41A0.fwork[0x22] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0x32);
    D_801C41A0.fwork[0x27] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0x3C);
    D_801C41A0.fwork[0x28] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0x3C);
    D_801C41A0.fwork[0x2D] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0xF);
    D_801C41A0.fwork[0x2E] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0xF);
    D_801C41A0.fwork[0x33] = sp40.mf[1][0] * (D_800D9924[gCourseID] - 0x1E);
    D_801C41A0.fwork[0x34] = sp40.mf[1][1] * (D_800D9924[gCourseID] - 0x1E);
}

#ifdef NON_MATCHING
// Score 75211 of 181100, one instruction long: float register allocation and stack layout throughout (frame 0x2E0,
// not 0x2C0; the original keeps the camera's unk70/unk74/unk78, the squared dot product and the direction on
// the stack, and saves four FP registers).
Gfx* func_8008A0E0(Gfx* gdl) {
    UnkStruct_801C43F8* p;
    camera_unk_1* cam;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 inv;
    f32 dot;
    f32 glare;
    f32 alpha;
    f32 angle;
    f32 rx;
    f32 ry;
    f32 rz;
    MtxF sp240;
    MtxF sp200;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 o0x;
    f32 o0y;
    f32 o0z;
    f32 o1x;
    f32 o1y;
    f32 o1z;
    f32 o2x;
    f32 o2y;
    f32 o2z;
    f32 o3x;
    f32 o3y;
    f32 o3z;

    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
    gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetTexturePersp(gdl++, G_TP_PERSP);
    p = &D_801C43F8[D_8011F8E0];
    cam = &gCameraPerspective[D_80223930];
    dx = D_800D98CC - cam->eyeX;
    dy = D_800D98D0 - cam->eyeY;
    dz = D_800D98D4 - cam->eyeZ;
    inv = 1.0f / sqrtf((dx * dx) + (dy * dy) + (dz * dz));
    dot = (cam->unk64 * (dx * inv)) + ((dy * inv) * cam->unk68) + ((dz * inv) * cam->unk6C);
    glare = dot * dot;
    glare = glare * glare;
    glare = glare * glare;
    if (dot > 0.8f) {
        D_800D47E0[0] = 2;
        gColorAlpha = 200.0f * (glare * glare);
        gColorRed = 0xF5;
        gColorGreen = 0xFF;
        gColorBlue = 0xD7;
    } else {
        D_800D47E0[0] = 0;
    }
    angle = cam->unk68 * 2.0f * 3.141592653589793;
    alpha = 160.0f * dot * dot * dot * dot * dot * dot * dot * dot * dot * dot * dot * dot;
    if (alpha < 15.0f) {
        alpha = 0.0f;
    }
    rx = (cam->unk68 * cam->upZ) - (cam->unk6C * cam->upY);
    ry = (cam->unk6C * cam->upX) - (cam->unk64 * cam->upZ);
    rz = (cam->unk64 * cam->upY) - (cam->unk68 * cam->upX);
    func_8004A3C0(&sp240, &sp200, cam->unk64, cam->unk68, cam->unk6C, angle);
    vx = (sp200.mf[2][0] * rz) + ((sp200.mf[0][0] * rx) + (sp200.mf[1][0] * ry));
    vy = (sp200.mf[2][1] * rz) + ((sp200.mf[0][1] * rx) + (sp200.mf[1][1] * ry));
    vz = (sp200.mf[2][2] * rz) + ((sp200.mf[0][2] * rx) + (sp200.mf[1][2] * ry));
    cx = (cam->unk68 * vz) - (cam->unk6C * vy);
    cy = (cam->unk6C * vx) - (cam->unk64 * vz);
    cz = (cam->unk64 * vy) - (cam->unk68 * vx);
    o0x = (-1.0f * vx) - cx;
    o0y = (-1.0f * vy) - cy;
    o0z = (-1.0f * vz) - cz;
    o1x = vx - cx;
    o1y = vy - cy;
    o1z = vz - cz;
    o2x = (-1.0f * vx) + cx;
    o2y = (-1.0f * vy) + cy;
    o2z = (-1.0f * vz) + cz;
    o3x = vx + cx;
    o3y = vy + cy;
    o3z = vz + cz;
    p->unk350[0][0].v.ob[0] = (s16) (s32) (32.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o0x);
    p->unk350[0][0].v.ob[1] = (s16) (s32) (32.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o0y);
    p->unk350[0][0].v.ob[2] = (s16) (s32) (32.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o0z);
    p->unk350[0][0].v.tc[0] = 0;
    p->unk350[0][0].v.tc[1] = 0;
    p->unk350[0][1].v.ob[0] = (s16) (s32) (32.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o1x);
    p->unk350[0][1].v.ob[1] = (s16) (s32) (32.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o1y);
    p->unk350[0][1].v.ob[2] = (s16) (s32) (32.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o1z);
    p->unk350[0][1].v.tc[0] = 0x800;
    p->unk350[0][1].v.tc[1] = 0;
    p->unk350[0][2].v.ob[0] = (s16) (s32) (32.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o2x);
    p->unk350[0][2].v.ob[1] = (s16) (s32) (32.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o2y);
    p->unk350[0][2].v.ob[2] = (s16) (s32) (32.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o2z);
    p->unk350[0][2].v.tc[0] = 0;
    p->unk350[0][2].v.tc[1] = 0x800;
    p->unk350[0][3].v.ob[0] = (s16) (s32) (32.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o3x);
    p->unk350[0][3].v.ob[1] = (s16) (s32) (32.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o3y);
    p->unk350[0][3].v.ob[2] = (s16) (s32) (32.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o3z);
    p->unk350[0][3].v.tc[0] = 0x800;
    p->unk350[0][3].v.tc[1] = 0x800;
    p->unk350[1][0].v.ob[0] = (s16) (s32) (48.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o0x);
    p->unk350[1][0].v.ob[1] = (s16) (s32) (48.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o0y);
    p->unk350[1][0].v.ob[2] = (s16) (s32) (48.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o0z);
    p->unk350[1][0].v.tc[0] = 0;
    p->unk350[1][0].v.tc[1] = 0;
    p->unk350[1][1].v.ob[0] = (s16) (s32) (48.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o1x);
    p->unk350[1][1].v.ob[1] = (s16) (s32) (48.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o1y);
    p->unk350[1][1].v.ob[2] = (s16) (s32) (48.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o1z);
    p->unk350[1][1].v.tc[0] = 0x800;
    p->unk350[1][1].v.tc[1] = 0;
    p->unk350[1][2].v.ob[0] = (s16) (s32) (48.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o2x);
    p->unk350[1][2].v.ob[1] = (s16) (s32) (48.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o2y);
    p->unk350[1][2].v.ob[2] = (s16) (s32) (48.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o2z);
    p->unk350[1][2].v.tc[0] = 0;
    p->unk350[1][2].v.tc[1] = 0x800;
    p->unk350[1][3].v.ob[0] = (s16) (s32) (48.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o3x);
    p->unk350[1][3].v.ob[1] = (s16) (s32) (48.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o3y);
    p->unk350[1][3].v.ob[2] = (s16) (s32) (48.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o3z);
    p->unk350[1][3].v.tc[0] = 0x800;
    p->unk350[1][3].v.tc[1] = 0x800;
    p->unk350[2][0].v.ob[0] = (s16) (s32) (64.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o0x);
    p->unk350[2][0].v.ob[1] = (s16) (s32) (64.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o0y);
    p->unk350[2][0].v.ob[2] = (s16) (s32) (64.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o0z);
    p->unk350[2][0].v.tc[0] = 0;
    p->unk350[2][0].v.tc[1] = 0;
    p->unk350[2][1].v.ob[0] = (s16) (s32) (64.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o1x);
    p->unk350[2][1].v.ob[1] = (s16) (s32) (64.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o1y);
    p->unk350[2][1].v.ob[2] = (s16) (s32) (64.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o1z);
    p->unk350[2][1].v.tc[0] = 0x800;
    p->unk350[2][1].v.tc[1] = 0;
    p->unk350[2][2].v.ob[0] = (s16) (s32) (64.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o2x);
    p->unk350[2][2].v.ob[1] = (s16) (s32) (64.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o2y);
    p->unk350[2][2].v.ob[2] = (s16) (s32) (64.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o2z);
    p->unk350[2][2].v.tc[0] = 0;
    p->unk350[2][2].v.tc[1] = 0x800;
    p->unk350[2][3].v.ob[0] = (s16) (s32) (64.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o3x);
    p->unk350[2][3].v.ob[1] = (s16) (s32) (64.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o3y);
    p->unk350[2][3].v.ob[2] = (s16) (s32) (64.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o3z);
    p->unk350[2][3].v.tc[0] = 0x800;
    p->unk350[2][3].v.tc[1] = 0x800;
    p->unk350[3][0].v.ob[0] = (s16) (s32) (96.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o0x);
    p->unk350[3][0].v.ob[1] = (s16) (s32) (96.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o0y);
    p->unk350[3][0].v.ob[2] = (s16) (s32) (96.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o0z);
    p->unk350[3][0].v.tc[0] = 0;
    p->unk350[3][0].v.tc[1] = 0;
    p->unk350[3][1].v.ob[0] = (s16) (s32) (96.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o1x);
    p->unk350[3][1].v.ob[1] = (s16) (s32) (96.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o1y);
    p->unk350[3][1].v.ob[2] = (s16) (s32) (96.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o1z);
    p->unk350[3][1].v.tc[0] = 0x800;
    p->unk350[3][1].v.tc[1] = 0;
    p->unk350[3][2].v.ob[0] = (s16) (s32) (96.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o2x);
    p->unk350[3][2].v.ob[1] = (s16) (s32) (96.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o2y);
    p->unk350[3][2].v.ob[2] = (s16) (s32) (96.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o2z);
    p->unk350[3][2].v.tc[0] = 0;
    p->unk350[3][2].v.tc[1] = 0x800;
    p->unk350[3][3].v.ob[0] = (s16) (s32) (96.0f * vx) + D_800D98CC + (s16) (s32) (16.0f * o3x);
    p->unk350[3][3].v.ob[1] = (s16) (s32) (96.0f * vy) + D_800D98D0 + (s16) (s32) (16.0f * o3y);
    p->unk350[3][3].v.ob[2] = (s16) (s32) (96.0f * vz) + D_800D98D4 + (s16) (s32) (16.0f * o3z);
    p->unk350[3][3].v.tc[0] = 0x800;
    p->unk350[3][3].v.tc[1] = 0x800;
    p->unk350[4][0].v.ob[0] = (s16) (s32) (128.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o0x);
    p->unk350[4][0].v.ob[1] = (s16) (s32) (128.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o0y);
    p->unk350[4][0].v.ob[2] = (s16) (s32) (128.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o0z);
    p->unk350[4][0].v.tc[0] = 0;
    p->unk350[4][0].v.tc[1] = 0;
    p->unk350[4][1].v.ob[0] = (s16) (s32) (128.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o1x);
    p->unk350[4][1].v.ob[1] = (s16) (s32) (128.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o1y);
    p->unk350[4][1].v.ob[2] = (s16) (s32) (128.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o1z);
    p->unk350[4][1].v.tc[0] = 0x800;
    p->unk350[4][1].v.tc[1] = 0;
    p->unk350[4][2].v.ob[0] = (s16) (s32) (128.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o2x);
    p->unk350[4][2].v.ob[1] = (s16) (s32) (128.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o2y);
    p->unk350[4][2].v.ob[2] = (s16) (s32) (128.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o2z);
    p->unk350[4][2].v.tc[0] = 0;
    p->unk350[4][2].v.tc[1] = 0x800;
    p->unk350[4][3].v.ob[0] = (s16) (s32) (128.0f * vx) + D_800D98CC + (s16) (s32) (32.0f * o3x);
    p->unk350[4][3].v.ob[1] = (s16) (s32) (128.0f * vy) + D_800D98D0 + (s16) (s32) (32.0f * o3y);
    p->unk350[4][3].v.ob[2] = (s16) (s32) (128.0f * vz) + D_800D98D4 + (s16) (s32) (32.0f * o3z);
    p->unk350[4][3].v.tc[0] = 0x800;
    p->unk350[4][3].v.tc[1] = 0x800;
    p->unk350[5][0].v.ob[0] = (s16) (s32) (160.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o0x);
    p->unk350[5][0].v.ob[1] = (s16) (s32) (160.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o0y);
    p->unk350[5][0].v.ob[2] = (s16) (s32) (160.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o0z);
    p->unk350[5][0].v.tc[0] = 0;
    p->unk350[5][0].v.tc[1] = 0;
    p->unk350[5][1].v.ob[0] = (s16) (s32) (160.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o1x);
    p->unk350[5][1].v.ob[1] = (s16) (s32) (160.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o1y);
    p->unk350[5][1].v.ob[2] = (s16) (s32) (160.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o1z);
    p->unk350[5][1].v.tc[0] = 0x800;
    p->unk350[5][1].v.tc[1] = 0;
    p->unk350[5][2].v.ob[0] = (s16) (s32) (160.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o2x);
    p->unk350[5][2].v.ob[1] = (s16) (s32) (160.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o2y);
    p->unk350[5][2].v.ob[2] = (s16) (s32) (160.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o2z);
    p->unk350[5][2].v.tc[0] = 0;
    p->unk350[5][2].v.tc[1] = 0x800;
    p->unk350[5][3].v.ob[0] = (s16) (s32) (160.0f * vx) + D_800D98CC + (s16) (s32) (8.0f * o3x);
    p->unk350[5][3].v.ob[1] = (s16) (s32) (160.0f * vy) + D_800D98D0 + (s16) (s32) (8.0f * o3y);
    p->unk350[5][3].v.ob[2] = (s16) (s32) (160.0f * vz) + D_800D98D4 + (s16) (s32) (8.0f * o3z);
    p->unk350[5][3].v.tc[0] = 0x800;
    p->unk350[5][3].v.tc[1] = 0x800;
    p->unk350[6][0].v.ob[0] = (s16) (s32) (232.0f * vx) + D_800D98CC + (s16) (s32) (64.0f * o0x);
    p->unk350[6][0].v.ob[1] = (s16) (s32) (232.0f * vy) + D_800D98D0 + (s16) (s32) (64.0f * o0y);
    p->unk350[6][0].v.ob[2] = (s16) (s32) (232.0f * vz) + D_800D98D4 + (s16) (s32) (64.0f * o0z);
    p->unk350[6][0].v.tc[0] = 0;
    p->unk350[6][0].v.tc[1] = 0;
    p->unk350[6][1].v.ob[0] = (s16) (s32) (232.0f * vx) + D_800D98CC + (s16) (s32) (64.0f * o1x);
    p->unk350[6][1].v.ob[1] = (s16) (s32) (232.0f * vy) + D_800D98D0 + (s16) (s32) (64.0f * o1y);
    p->unk350[6][1].v.ob[2] = (s16) (s32) (232.0f * vz) + D_800D98D4 + (s16) (s32) (64.0f * o1z);
    p->unk350[6][1].v.tc[0] = 0x800;
    p->unk350[6][1].v.tc[1] = 0;
    p->unk350[6][2].v.ob[0] = (s16) (s32) (232.0f * vx) + D_800D98CC + (s16) (s32) (64.0f * o2x);
    p->unk350[6][2].v.ob[1] = (s16) (s32) (232.0f * vy) + D_800D98D0 + (s16) (s32) (64.0f * o2y);
    p->unk350[6][2].v.ob[2] = (s16) (s32) (232.0f * vz) + D_800D98D4 + (s16) (s32) (64.0f * o2z);
    p->unk350[6][2].v.tc[0] = 0;
    p->unk350[6][2].v.tc[1] = 0x800;
    p->unk350[6][3].v.ob[0] = (s16) (s32) (232.0f * vx) + D_800D98CC + (s16) (s32) (64.0f * o3x);
    p->unk350[6][3].v.ob[1] = (s16) (s32) (232.0f * vy) + D_800D98D0 + (s16) (s32) (64.0f * o3y);
    p->unk350[6][3].v.ob[2] = (s16) (s32) (232.0f * vz) + D_800D98D4 + (s16) (s32) (64.0f * o3z);
    p->unk350[6][3].v.tc[0] = 0x800;
    p->unk350[6][3].v.tc[1] = 0x800;
    p->unk350[7][0].v.ob[0] = (D_800D98CC - (s16) (s32) (72.0f * vx)) - (s16) (s32) (8.0f * o0x);
    p->unk350[7][0].v.ob[1] = (D_800D98D0 - (s16) (s32) (72.0f * vy)) - (s16) (s32) (8.0f * o0y);
    p->unk350[7][0].v.ob[2] = (D_800D98D4 - (s16) (s32) (72.0f * vz)) - (s16) (s32) (8.0f * o0z);
    p->unk350[7][0].v.tc[0] = 0;
    p->unk350[7][0].v.tc[1] = 0;
    p->unk350[7][1].v.ob[0] = (D_800D98CC - (s16) (s32) (72.0f * vx)) - (s16) (s32) (8.0f * o1x);
    p->unk350[7][1].v.ob[1] = (D_800D98D0 - (s16) (s32) (72.0f * vy)) - (s16) (s32) (8.0f * o1y);
    p->unk350[7][1].v.ob[2] = (D_800D98D4 - (s16) (s32) (72.0f * vz)) - (s16) (s32) (8.0f * o1z);
    p->unk350[7][1].v.tc[0] = 0x800;
    p->unk350[7][1].v.tc[1] = 0;
    p->unk350[7][2].v.ob[0] = (D_800D98CC - (s16) (s32) (72.0f * vx)) - (s16) (s32) (8.0f * o2x);
    p->unk350[7][2].v.ob[1] = (D_800D98D0 - (s16) (s32) (72.0f * vy)) - (s16) (s32) (8.0f * o2y);
    p->unk350[7][2].v.ob[2] = (D_800D98D4 - (s16) (s32) (72.0f * vz)) - (s16) (s32) (8.0f * o2z);
    p->unk350[7][2].v.tc[0] = 0;
    p->unk350[7][2].v.tc[1] = 0x800;
    p->unk350[7][3].v.ob[0] = (D_800D98CC - (s16) (s32) (72.0f * vx)) - (s16) (s32) (8.0f * o3x);
    p->unk350[7][3].v.ob[1] = (D_800D98D0 - (s16) (s32) (72.0f * vy)) - (s16) (s32) (8.0f * o3y);
    p->unk350[7][3].v.ob[2] = (D_800D98D4 - (s16) (s32) (72.0f * vz)) - (s16) (s32) (8.0f * o3z);
    p->unk350[7][3].v.tc[0] = 0x800;
    p->unk350[7][3].v.tc[1] = 0x800;
    p->unk350[8][0].v.ob[0] = (D_800D98CC - (s16) (s32) (128.0f * vx)) - (s16) (s32) (48.0f * o0x);
    p->unk350[8][0].v.ob[1] = (D_800D98D0 - (s16) (s32) (128.0f * vy)) - (s16) (s32) (48.0f * o0y);
    p->unk350[8][0].v.ob[2] = (D_800D98D4 - (s16) (s32) (128.0f * vz)) - (s16) (s32) (48.0f * o0z);
    p->unk350[8][0].v.tc[0] = 0;
    p->unk350[8][0].v.tc[1] = 0;
    p->unk350[8][1].v.ob[0] = (D_800D98CC - (s16) (s32) (128.0f * vx)) - (s16) (s32) (48.0f * o1x);
    p->unk350[8][1].v.ob[1] = (D_800D98D0 - (s16) (s32) (128.0f * vy)) - (s16) (s32) (48.0f * o1y);
    p->unk350[8][1].v.ob[2] = (D_800D98D4 - (s16) (s32) (128.0f * vz)) - (s16) (s32) (48.0f * o1z);
    p->unk350[8][1].v.tc[0] = 0x800;
    p->unk350[8][1].v.tc[1] = 0;
    p->unk350[8][2].v.ob[0] = (D_800D98CC - (s16) (s32) (128.0f * vx)) - (s16) (s32) (48.0f * o2x);
    p->unk350[8][2].v.ob[1] = (D_800D98D0 - (s16) (s32) (128.0f * vy)) - (s16) (s32) (48.0f * o2y);
    p->unk350[8][2].v.ob[2] = (D_800D98D4 - (s16) (s32) (128.0f * vz)) - (s16) (s32) (48.0f * o2z);
    p->unk350[8][2].v.tc[0] = 0;
    p->unk350[8][2].v.tc[1] = 0x800;
    p->unk350[8][3].v.ob[0] = (D_800D98CC - (s16) (s32) (128.0f * vx)) - (s16) (s32) (48.0f * o3x);
    p->unk350[8][3].v.ob[1] = (D_800D98D0 - (s16) (s32) (128.0f * vy)) - (s16) (s32) (48.0f * o3y);
    p->unk350[8][3].v.ob[2] = (D_800D98D4 - (s16) (s32) (128.0f * vz)) - (s16) (s32) (48.0f * o3z);
    p->unk350[8][3].v.tc[0] = 0x800;
    p->unk350[8][3].v.tc[1] = 0x800;
    p->unk350[9][0].v.ob[0] = (D_800D98CC - (s16) (s32) (232.0f * vx)) - (s16) (s32) (64.0f * o0x);
    p->unk350[9][0].v.ob[1] = (D_800D98D0 - (s16) (s32) (232.0f * vy)) - (s16) (s32) (64.0f * o0y);
    p->unk350[9][0].v.ob[2] = (D_800D98D4 - (s16) (s32) (232.0f * vz)) - (s16) (s32) (64.0f * o0z);
    p->unk350[9][0].v.tc[0] = 0;
    p->unk350[9][0].v.tc[1] = 0;
    p->unk350[9][1].v.ob[0] = (D_800D98CC - (s16) (s32) (232.0f * vx)) - (s16) (s32) (64.0f * o1x);
    p->unk350[9][1].v.ob[1] = (D_800D98D0 - (s16) (s32) (232.0f * vy)) - (s16) (s32) (64.0f * o1y);
    p->unk350[9][1].v.ob[2] = (D_800D98D4 - (s16) (s32) (232.0f * vz)) - (s16) (s32) (64.0f * o1z);
    p->unk350[9][1].v.tc[0] = 0x800;
    p->unk350[9][1].v.tc[1] = 0;
    p->unk350[9][2].v.ob[0] = (D_800D98CC - (s16) (s32) (232.0f * vx)) - (s16) (s32) (64.0f * o2x);
    p->unk350[9][2].v.ob[1] = (D_800D98D0 - (s16) (s32) (232.0f * vy)) - (s16) (s32) (64.0f * o2y);
    p->unk350[9][2].v.ob[2] = (D_800D98D4 - (s16) (s32) (232.0f * vz)) - (s16) (s32) (64.0f * o2z);
    p->unk350[9][2].v.tc[0] = 0;
    p->unk350[9][2].v.tc[1] = 0x800;
    p->unk350[9][3].v.ob[0] = (D_800D98CC - (s16) (s32) (232.0f * vx)) - (s16) (s32) (64.0f * o3x);
    p->unk350[9][3].v.ob[1] = (D_800D98D0 - (s16) (s32) (232.0f * vy)) - (s16) (s32) (64.0f * o3y);
    p->unk350[9][3].v.ob[2] = (D_800D98D4 - (s16) (s32) (232.0f * vz)) - (s16) (s32) (64.0f * o3z);
    p->unk350[9][3].v.tc[0] = 0x800;
    p->unk350[9][3].v.tc[1] = 0x800;
    gDPLoadTextureBlock(gdl++, D_100FAB0, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gSPVertex(gdl++, D_6000350, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xC8, 0x7F, 0xFF, alpha);
    gSPVertex(gdl++, D_6000390, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gSPVertex(gdl++, D_60003D0, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0x3B, 0xD4, 0x6B, alpha);
    gSPVertex(gdl++, D_6000410, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0x80, 0xEB, alpha);
    gSPVertex(gdl++, D_6000450, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0x5C, alpha);
    gSPVertex(gdl++, D_6000490, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gSPVertex(gdl++, D_60004D0, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gSPVertex(gdl++, D_6000510, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0x3B, 0xD4, 0x6B, alpha);
    gSPVertex(gdl++, D_6000550, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
    gSPVertex(gdl++, D_6000590, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_8008A0E0.s")
#endif

#ifdef NON_MATCHING
// Score 2641 of 120000, one instruction long: in the Dolphin Park block the second element reloads %hi(D_801C4170)
// for its unk4 load, where the original shares the lui with the unk0 load; temps are renumbered from there on, and
// scale sits 8 bytes higher on the stack.
Gfx* func_8008BD2C(Gfx* gdl) {
    s32 pad[2]; // stack pad
    f32 scale;
    UnkStruct_800DA624 flareAlpha;
    s32 alpha;
    f32 mirror;
    s32 x;
    s32 y;

    flareAlpha = D_800DA624; // probably a local array initialised from this file's data in the original
    switch (gCourseID) {
        case DOLPHIN_PARK:
            scale = (gCameraPerspective[D_80223930].atY - 20.0f) / 100.0f;
            if (scale > 1.0f) {
                scale = 1.0f;
            }
            if (scale < 0.0f) {
                scale = 0; // integer 0: a separate constant load from the 0.0f above
            }
            break;
        case SUNSET_BAY:
            scale = 1.0f;
            break;
        case GLACIER_COAST:
            if (D_801CE638 == 0x15) {
                return func_8008A0E0(gdl);
            }
            break;
    }
    // On other courses scale is used uninitialized, as in the original.
    if ((gCourseID != DOLPHIN_PARK) && (gCourseID != SUNSET_BAY)) {
        return gdl;
    }
    { // FAKE: the early return and this block give the original's branch layout
        gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
        gSPSetGeometryMode(gdl++, G_SHADE);
        gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetTexturePersp(gdl++, G_TP_NONE);
        alpha = 160.0f * D_801C4170.unk14 * D_801C4170.unk14 * scale;
        if (D_801C4170.unk14 > 0.7) {
            D_800D47E0[0] = 2;
            gColorAlpha = flareAlpha.alpha[gCourseID] * D_801C4170.unk14 * D_801C4170.unk14 * D_801C4170.unk14 *
                          D_801C4170.unk14 * scale;
            gColorRed = 0xF5;
            gColorGreen = 0xFF;
            gColorBlue = 0xD7;
        } else {
            D_800D47E0[0] = 0;
        }
        if (D_801C4170.unk14 >= 0.0f) {
            gDPLoadTextureBlock(gdl++, D_100FAB0, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
            mirror = 319 - (s32) (D_801C4170.unk0 + D_801C4170.unkC);
            x = D_801C4170.unk0 - ((D_801C4170.unk0 - mirror) / 6.0f);
            y = D_801C4170.unk4 - D_801C41A0.fwork[0x10];
            if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0x5C, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 4) << 2, 0), MAX((y - 4) << 2, 0), MAX((x + 4) << 2, 0),
                                    MAX((y + 4) << 2, 0), 0, 0 - MIN((((x - 4) << 18) >> 7), 0),
                                    0 - MIN((((y - 4) << 18) >> 7), 0), 0x1000, 0x1000);
            }
            x = D_801C4170.unk0 - ((D_801C4170.unk0 - mirror) / 3.0f);
            y = D_801C4170.unk4 - D_801C41A0.fwork[0x16];
            if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 0x14) << 2, 0), MAX((y - 0x14) << 2, 0), MAX((x + 0x14) << 2, 0),
                                    MAX((y + 0x14) << 2, 0), 0, 0 - MIN((((x - 0x14) << 14) >> 7), 0),
                                    0 - MIN((((y - 0x14) << 14) >> 7), 0), 0x300, 0x300);
            }
            x = D_801C4170.unk0 - (((D_801C4170.unk0 - mirror) * 2) / 3.0f);
            y = D_801C4170.unk4 - D_801C41A0.fwork[0x1C];
            if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0x80, 0xEB, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 0x10) << 2, 0), MAX((y - 0x10) << 2, 0), MAX((x + 0x10) << 2, 0),
                                    MAX((y + 0x10) << 2, 0), 0, 0 - MIN(((((x - 0x10) << 2) * 0x400) >> 7), 0),
                                    0 - MIN(((((y - 0x10) << 2) * 0x400) >> 7), 0), 0x400, 0x400);
            }
            x = D_801C4170.unk0 - (((D_801C4170.unk0 - mirror) * 5.0f) / 6.0f);
            y = D_801C4170.unk4 - D_801C41A0.fwork[0x22];
            if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0x5C, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 4) << 2, 0), MAX((y - 4) << 2, 0), MAX((x + 4) << 2, 0),
                                    MAX((y + 4) << 2, 0), 0, 0 - MIN((((x - 4) << 18) >> 7), 0),
                                    0 - MIN((((y - 4) << 18) >> 7), 0), 0x1000, 0x1000);
            }
            x = 319 - (s32) (D_801C4170.unk0 + D_801C4170.unkC);
            y = D_801C4170.unk4 - D_801C41A0.fwork[0x28];
            if ((x >= -64) && (x < SCREEN_WIDTH) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 0x20) << 2, 0), MAX((y - 0x20) << 2, 0), MAX((x + 0x20) << 2, 0),
                                    MAX((y + 0x20) << 2, 0), 0, 0 - MIN(((((x - 0x20) << 2) * 0x200) >> 7), 0),
                                    0 - MIN(((((y - 0x20) << 2) * 0x200) >> 7), 0), 0x200, 0x200);
            }
            x = (2.0f * D_801C4170.unk0) - x;
            y = D_801C4170.unk4 - D_801C41A0.fwork[4];
            if ((x >= -32) && (x < SCREEN_WIDTH) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0x5C, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 8) << 2, 0), MAX((y - 8) << 2, 0), MAX((x + 8) << 2, 0),
                                    MAX((y + 8) << 2, 0), 0, 0 - MIN((((x - 8) << 14) >> 7), 0),
                                    0 - MIN((((y - 8) << 14) >> 7), 0), 0x800, 0x800);
            }
            x = ((x - D_801C4170.unk0) / 2) + D_801C4170.unk0;
            y = D_801C4170.unk4 - D_801C41A0.fwork[0xA];
            if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                (y < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
                gSPTextureRectangle(gdl++, MAX((x - 4) << 2, 0), MAX((y - 4) << 2, 0), MAX((x + 4) << 2, 0),
                                    MAX((y + 4) << 2, 0), 0, 0 - MIN((((x - 4) << 18) >> 7), 0),
                                    0 - MIN((((y - 4) << 18) >> 7), 0), 0x1000, 0x1000);
            }
            if (gCourseID == DOLPHIN_PARK) {
                mirror = 319 - (s32) (D_801C4170.unk0 + D_801C4170.unkC);
                x = D_801C4170.unk0 - ((D_801C4170.unk0 - mirror) / 4);
                y = D_801C4170.unk4 - D_801C41A0.fwork[0x2E];
                if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                    (y < SCREEN_HEIGHT)) {
                    gDPSetPrimColor(gdl++, 0, 0, 0xC8, 0x7F, 0xFF, alpha);
                    gSPTextureRectangle(gdl++, MAX((x - 8) << 2, 0), MAX((y - 8) << 2, 0), MAX((x + 8) << 2, 0),
                                        MAX((y + 8) << 2, 0), 0, 0 - MIN((((x - 8) << 14) >> 7), 0),
                                        0 - MIN((((y - 8) << 14) >> 7), 0), 0x800, 0x800);
                }
                x = D_801C4170.unk0 - ((D_801C4170.unk0 - mirror) / 2);
                y = D_801C4170.unk4 - D_801C41A0.fwork[0x34];
                if ((D_801C4170.unk0 >= -32.0f) && (D_801C4170.unk0 < 320.0f) && (x >= -32) && (x < SCREEN_WIDTH) && (y >= 0) &&
                    (y < SCREEN_HEIGHT)) {
                    gDPSetPrimColor(gdl++, 0, 0, 0x3B, 0xD4, 0x6B, alpha);
                    gSPTextureRectangle(gdl++, MAX((x - 8) << 2, 0), MAX((y - 8) << 2, 0), MAX((x + 8) << 2, 0),
                                        MAX((y + 8) << 2, 0), 0, 0 - MIN((((x - 8) << 14) >> 7), 0),
                                        0 - MIN((((y - 8) << 14) >> 7), 0), 0x800, 0x800);
                }
            }
        }
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_8008BD2C.s")
#endif

Gfx* func_8008CFEC(Gfx* gdl) {
    UnkStruct_8008962C* var_t1;
    s32 var_t2;
    s32 temp_a2;
    s32 temp_a1;
    s32 temp;

    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetPrimColor(gdl++, 0, 0, 0xF0, 0xD3, 0xF8, 0xFF);
    gDPLoadTextureBlock(gdl++, &D_10102B0, G_IM_FMT_IA, G_IM_SIZ_16b, 4, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 2, 2, G_TX_NOLOD, G_TX_NOLOD);

    // var_t1 = &D_801C4278;
    // var_t2 = 0;
    var_t1 = D_801C4278;
    var_t2 = 0;
    for (; var_t2 < 0x10; var_t2++, var_t1++) {
        if (var_t1->unk14 >= 0.0f) {
            temp_a1 = var_t1->unkC + var_t1->unk0;
            temp_a2 = var_t1->unk4 - var_t1->unk10;
            if ((temp_a1 >= -2) && (temp_a1 < SCREEN_WIDTH) && (temp_a2 >= 0) && (temp_a2 < SCREEN_HEIGHT)) {
                gDPSetPrimColor(gdl++, 0, 0, D_800DA6A8[var_t2].red, D_800DA6A8[var_t2].green, D_800DA6A8[var_t2].blue,
                                D_800DA6A8[var_t2].alpha);
                if (D_800DA628[var_t2] != 0) {
                    gSPTextureRectangle(gdl++, MAX((temp_a1 - 2) << 2, 0), MAX((temp_a2 - 2) << 2, 0),
                                        MAX((temp_a1 + 2) << 2, 0), MAX((temp_a2 + 2) << 2, 0), 0,
                                        0 - MIN(((((temp_a1 - 2) << 2) * (1 << 10)) >> 7), 0),
                                        0 - MIN(((((temp_a2 - 2) << 2) * (1 << 10)) >> 7), 0), 1 << 10, 1 << 10);
                } else {
                    gSPTextureRectangle(gdl++, MAX((temp_a1 - 1) << 2, 0), MAX((temp_a2 - 1) << 2, 0),
                                        MAX((temp_a1 + 1) << 2, 0), MAX((temp_a2 + 1) << 2, 0), 0,
                                        0 - MIN(((((temp_a1 - 1) << 3) * (0x800)) >> 7), 0),
                                        0 - MIN(((((temp_a2 - 1) << 3) * (0x800)) >> 7), 0), 0x800, 0x800);
                }
            }
        }
    }
    return gdl;
}

#ifdef NON_MATCHING
// Score 2180 of 31800: same instructions; register allocation differs (x is in t3, not t2, which renumbers the
// temps of both rectangles), and the second rectangle's setup is scheduled differently around the gdl spill.
Gfx* func_8008D454(Gfx* gdl) {
    s32 pad[2]; // stack pad
    s32 x;
    s32 y;

    x = D_801C4188.unk0 + D_801C4188.unkC;
    y = D_801C4188.unk4 - D_801C4188.unk10;

    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    if (D_801C4188.unk14 >= 0.0f) {
        gDPLoadTextureBlock(gdl++, D_8004400, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gdl++, 0, 0, 0xF0, 0xF0, 0x1C, 0x6E);
        if ((x >= -12) && (x < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
            gSPTextureRectangle(gdl++, MAX((x - 12) << 2, 0), MAX((y - 12) << 2, 0), MAX((x + 12) << 2, 0),
                                MAX((y + 12) << 2, 0), 0, 0 - MIN((((x - 12) << 15) >> 7), 0),
                                0 - MIN((((y - 12) << 15) >> 7), 0), 0x600, 0x600);
        }
    }
    if (D_801C4188.unk14 >= 0.0f) {
        gDPLoadTextureBlock(gdl++, D_8004400, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        if ((x >= -12) && (x < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
            gSPTextureRectangle(gdl++, MAX((x - 12) << 2, 0), MAX((y - 12) << 2, 0), MAX((x + 12) << 2, 0),
                                MAX((y + 12) << 2, 0), 0, 0 - MIN((((x - 12) << 15) >> 7), 0),
                                0 - MIN((((y - 12) << 15) >> 7), 0), 0x600, 0x600);
        }
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_8008D454.s")
#endif

Gfx* func_8008D94C(Gfx* gdl) {
    s32 pad; // stack pad
    s32 x;
    s32 y;
    s32 x2;
    s32 s;
    s32 dsdx;

    x = D_801C4170.unk0 + D_801C4170.unkC;
    s = 0;
    y = D_801C4170.unk4 - D_801C4170.unk10;
    x2 = x;
    switch (gCourseID) {
        case DOLPHIN_PARK:
            dsdx = 0x555;
            break;
        case SUNSET_BAY:
            dsdx = 0x29B;
            break;
        case GLACIER_COAST:
            dsdx = 0x555;
            break;
    }
    // On other courses dsdx is used uninitialized, as in the original.
    if ((x - D_800D9944[gCourseID]) < 0) {
        x2 = D_800D9944[gCourseID];
        s = D_800D9944[gCourseID] - x;
    }
    if ((y - D_800D9944[gCourseID]) < 0) {
        s = D_800D9944[gCourseID] - x; // x, not y, as in the original
    }
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    if ((gCourseID == SUNSET_BAY) && (D_801C4170.unk14 >= 0.0f)) {
        gDPLoadTextureBlock(gdl++, D_8004C00, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gdl++, 0, 0, D_800D9918[gCourseID][0], D_800D9918[gCourseID][1], D_800D9918[gCourseID][2], 0);
        if ((x2 >= -24) && (x2 < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
            // The s/t clamp terms shift by dsdx * 2 (a variable shift), as in the original.
            gSPTextureRectangle(gdl++, MAX((x2 - D_800D9944[gCourseID]) << 2, 0), MAX((y - D_800D9944[gCourseID]) << 2, 0),
                                    MAX((x2 + D_800D9944[gCourseID]) << 2, 0), MAX((y + D_800D9944[gCourseID]) << 2, 0), 0,
                                    (s << 5) - MIN((((x2 - D_800D9944[gCourseID]) << (dsdx * 2)) >> 7), 0),
                                    0 - MIN((((y - D_800D9944[gCourseID]) << (dsdx * 2)) >> 7), 0), dsdx, dsdx);
        }
    }
    if ((D_801C4170.unk14 >= 0.0f) && (x2 >= -24) && (x2 < SCREEN_WIDTH) && (y >= 0) && (y < SCREEN_HEIGHT)) {
        gDPLoadTextureBlock(gdl++, D_8004400, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, 0);
        gSPTextureRectangle(gdl++, MAX((x2 - D_800D9944[gCourseID]) << 2, 0), MAX((y - D_800D9944[gCourseID]) << 2, 0),
                                MAX((x2 + D_800D9944[gCourseID]) << 2, 0), MAX((y + D_800D9944[gCourseID]) << 2, 0), 0,
                                (s << 5) - MIN((((x2 - D_800D9944[gCourseID]) << (dsdx * 2)) >> 7), 0),
                                0 - MIN((((y - D_800D9944[gCourseID]) << (dsdx * 2)) >> 7), 0), dsdx, dsdx);
    }
    return gdl;
}

#ifdef NON_MATCHING
// Score 2745 of 31200, 3 instructions longer: the display-list pointer after the texture load is advanced with
// move/addiu pairs here, where the original chains addiu from the previous command's pointer; the setup of the
// texture-load words is also scheduled later.
Gfx* func_8008DFD0(Gfx* gdl) {
    s32 pad[2]; // stack pad
    camera_unk_1* cam;
    Vtx* vtx;
    UnkStruct_801C43F8* p;
    f32 x;
    f32 y;
    f32 z;

    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
    gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gdl++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetTexturePersp(gdl++, G_TP_PERSP);

    cam = &gCameraPerspective[D_80223930];
    p = &D_801C43F8[D_8011F8E0];
    vtx = p->unk310;
    x = (cam->unk68 * cam->upZ) - (cam->unk6C * cam->upY);
    y = (cam->unk6C * cam->upX) - (cam->unk64 * cam->upZ);
    z = (cam->unk64 * cam->upY) - (cam->unk68 * cam->upX);
    vtx[0].v.ob[0] = (s32) (((cam->upX * -1.0f) - x) * 48.0f) + D_800D98CC;
    vtx[0].v.ob[1] = (s32) (((cam->upY * -1.0f) - y) * 48.0f) + D_800D98D0;
    vtx[0].v.ob[2] = (s32) (((cam->upZ * -1.0f) - z) * 48.0f) + D_800D98D4;
    vtx[0].v.tc[0] = 0;
    vtx[0].v.tc[1] = 0;
    vtx[1].v.ob[0] = (s32) ((cam->upX - x) * 48.0f) + D_800D98CC;
    vtx[1].v.ob[1] = (s32) ((cam->upY - y) * 48.0f) + D_800D98D0;
    vtx[1].v.ob[2] = (s32) ((cam->upZ - z) * 48.0f) + D_800D98D4;
    vtx[1].v.tc[0] = 0x800;
    vtx[1].v.tc[1] = 0;
    vtx[2].v.ob[0] = (s32) (((cam->upX * -1.0f) + x) * 48.0f) + D_800D98CC;
    vtx[2].v.ob[1] = (s32) (((cam->upY * -1.0f) + y) * 48.0f) + D_800D98D0;
    vtx[2].v.ob[2] = (s32) (((cam->upZ * -1.0f) + z) * 48.0f) + D_800D98D4;
    vtx[2].v.tc[0] = 0;
    vtx[2].v.tc[1] = 0x800;
    vtx[3].v.ob[0] = (s32) ((cam->upX + x) * 48.0f) + D_800D98CC;
    vtx[3].v.ob[1] = (s32) ((cam->upY + y) * 48.0f) + D_800D98D0;
    vtx[3].v.ob[2] = (s32) ((cam->upZ + z) * 48.0f) + D_800D98D4;
    vtx[3].v.tc[0] = 0x800;
    vtx[3].v.tc[1] = 0x800;

    gDPLoadTextureBlock(gdl++, D_8004400, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor(gdl++, 0, 0, 0xFF, 0xFF, 0xFF, 0x00);
    gSPVertex(gdl++, D_6000310, 4, 0);
    gSP1Triangle(gdl++, 0, 1, 2, 0);
    gSP1Triangle(gdl++, 1, 2, 3, 0);
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_8008DFD0.s")
#endif

void func_8008E4B0(void) {
    s32 i;
    s32 j;
    UnkStruct_801C43F8* p;

    D_801CB058[0] = D_800D9964[gCourseID];
    D_801CB058[1] = D_800D9964[gCourseID];
    if (D_801CE638 == 0x15) {
        D_801CB058[0] = D_800DA404;
    }
    D_801C4160 = D_801CB058[0].unkAC;
    D_801C4164 = D_801CB058[0].unkB0;
    D_801C4168 = D_801CB058[0].unkB4;
    for (i = 0; i < 2; i++) {
        p = &D_801C43F8[i];
        p->unkE0[6].v.ob[1] = D_80192498 * 3;
        p->unkE0[6].v.tc[0] = 0x80;
        p->unkE0[6].v.tc[1] = 0x4FC0;
        p->unkE0[6].v.flag = 0;
        p->unkE0[6].v.cn[0] = 0;
        p->unkE0[6].v.cn[1] = 0;
        p->unkE0[6].v.cn[2] = 0;
        p->unkE0[6].v.cn[3] = 0xFF;
        for (j = 0; j < 6; j++) {
            p->unkE0[j].v.ob[1] = 0;
            p->unkE0[j].v.tc[0] = 0x80;
            p->unkE0[j].v.tc[1] = 0;
            p->unkE0[j].v.flag = 0;
            p->unkE0[j].v.cn[0] = 0;
            p->unkE0[j].v.cn[1] = 0;
            p->unkE0[j].v.cn[2] = 0;
            p->unkE0[j].v.cn[3] = 0xFF;
        }
        p->unk150[6].v.ob[1] = D_80192498 * 3;
        p->unk150[6].v.tc[0] = 0x80;
        p->unk150[6].v.tc[1] = 0x4FC0;
        p->unk150[6].v.flag = 0;
        p->unk150[6].v.cn[0] = 0;
        p->unk150[6].v.cn[1] = 0;
        p->unk150[6].v.cn[2] = 0;
        p->unk150[6].v.cn[3] = 0xFF;
        for (j = 0; j < 6; j++) {
            p->unk150[j].v.ob[1] = 0;
            p->unk150[j].v.tc[0] = 0x80;
            p->unk150[j].v.tc[1] = 0;
            p->unk150[j].v.flag = 0;
            p->unk150[j].v.cn[0] = 0;
            p->unk150[j].v.cn[1] = 0;
            p->unk150[j].v.cn[2] = 0;
            p->unk150[j].v.cn[3] = 0xFF;
        }
    }
}

#ifdef NON_MATCHING
// Score 18577 of 127200, 17 instructions short: register allocation (the original keeps the camera direction on
// the stack across sqrtf and five saved FP registers, frame 0xC8), and in the D_800D988C == 1 loop the original
// reloads D_801C4160/4/8 after storing them where IDO here reuses the stored values.
void func_8008E794(void) {
    f32 dirX;
    f32 dirZ;
    camera_unk_1* cam;
    UnkStruct_801C43F8* p;
    Vtx* arena;
    Vtx* vtx;
    f32 var_fv1;
    f32 var_fa1;
    f32 len;
    f32 scale;
    s32 i;
    s32 angle;
    UnkStruct_801CB058* e;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 k;
    f32 c;
    f32 s;

    D_800D9914 = (D_800D9914 + 1) & 3;
    cam = &gCameraPerspective[D_80223930];
    dirX = cam->unk64;
    dirZ = cam->unk6C;
    p = &D_801C43F8[D_8011F8E0];
    arena = gGfxPool->unk13D68;
    len = sqrtf((dirX * dirX) + (dirZ * dirZ));
    var_fv1 = dirX;
    var_fa1 = dirZ;
    if (len != 0.0f) {
        scale = 4000.0f / len;
        var_fv1 *= scale;
        var_fa1 *= scale;
    }
    vtx = p->unkE0;
    vtx[0].v.ob[0] = arena[D_80192460[1]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[0].v.ob[1] = gWaterLevel;
    vtx[0].v.ob[2] = arena[D_80192460[1]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[1].v.ob[0] = arena[D_80192460[2]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[1].v.ob[1] = gWaterLevel;
    vtx[1].v.ob[2] = arena[D_80192460[2]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[2].v.ob[0] = arena[D_80192460[3]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[2].v.ob[1] = gWaterLevel;
    vtx[2].v.ob[2] = arena[D_80192460[3]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[3].v.ob[0] = arena[D_80192460[4]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[3].v.ob[1] = gWaterLevel;
    vtx[3].v.ob[2] = arena[D_80192460[4]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[4].v.ob[0] = arena[D_80192460[5]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[4].v.ob[1] = gWaterLevel;
    vtx[4].v.ob[2] = arena[D_80192460[5]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[5].v.ob[0] = arena[D_80192460[6]].v.ob[0] - gWaterWindow[0].unk14;
    vtx[5].v.ob[1] = gWaterLevel;
    vtx[5].v.ob[2] = arena[D_80192460[6]].v.ob[2] - gWaterWindow[0].unk18;
    vtx[6].v.ob[0] = (arena[D_80192460[0]].v.ob[0] - var_fv1) - gWaterWindow[0].unk14;
    vtx[6].v.ob[1] = (D_80192498 * 3) + gWaterLevel;
    vtx[6].v.ob[2] = (arena[D_80192460[0]].v.ob[2] - var_fa1) - gWaterWindow[0].unk18;
    if (gPlayers == TWO_PLAYERS) {
        cam = &gCameraPerspective[D_80223934];
        dirX = cam->unk64;
        dirZ = cam->unk6C;
        arena = gGfxPool->unk170D8;
        vtx = p->unk150;
        scale = 4000.0f / sqrtf((dirX * dirX) + (dirZ * dirZ));
        vtx[0].v.ob[0] = arena[D_80192460[1]].v.ob[0] - gWaterWindow[1].unk18; // unk18, not unk14, as in the original
        vtx[0].v.ob[1] = gWaterLevel;
        vtx[0].v.ob[2] = arena[D_80192460[1]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[1].v.ob[0] = arena[D_80192460[2]].v.ob[0] - gWaterWindow[1].unk14;
        vtx[1].v.ob[1] = gWaterLevel;
        vtx[1].v.ob[2] = arena[D_80192460[2]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[2].v.ob[0] = arena[D_80192460[3]].v.ob[0] - gWaterWindow[1].unk14;
        vtx[2].v.ob[1] = gWaterLevel;
        vtx[2].v.ob[2] = arena[D_80192460[3]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[3].v.ob[0] = arena[D_80192460[4]].v.ob[0] - gWaterWindow[1].unk14;
        vtx[3].v.ob[1] = gWaterLevel;
        vtx[3].v.ob[2] = arena[D_80192460[4]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[4].v.ob[0] = arena[D_80192460[5]].v.ob[0] - gWaterWindow[1].unk14;
        vtx[4].v.ob[1] = gWaterLevel;
        vtx[4].v.ob[2] = arena[D_80192460[5]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[5].v.ob[0] = arena[D_80192460[6]].v.ob[0] - gWaterWindow[1].unk14;
        vtx[5].v.ob[1] = gWaterLevel;
        vtx[5].v.ob[2] = arena[D_80192460[6]].v.ob[2] - gWaterWindow[1].unk18;
        vtx[6].v.ob[0] = (arena[D_80192460[0]].v.ob[0] - (dirX * scale)) - gWaterWindow[1].unk14;
        vtx[6].v.ob[1] = (D_80192498 * 3) + gWaterLevel;
        vtx[6].v.ob[2] = (arena[D_80192460[0]].v.ob[2] - (dirZ * scale)) - gWaterWindow[1].unk18;
    }
    if (gPlayers == ONE_PLAYER) {
        switch (gCourseID) {
            case DOLPHIN_PARK:
            case SUNSET_BAY:
            case GLACIER_COAST:
                func_80089E24();
                func_80089F28();
                break;
            case TWILIGHT_CITY:
                func_80089C08();
                func_80089DEC();
                break;
        }
    }
    if (D_800D988C == 1) {
        D_800DA8B0 += 5.0f;
        for (i = 0, e = D_801CB058; i < gPlayers; i++, e++) {
            e->unkAC = 0.0f;
            angle = ANGLE_TO_CUSTOM_UNITS(D_800DA8B0);
            e->unkB0 = SIN(angle) * 64.0f;
            e->unkB4 = COS(angle) * 64.0f;
            D_801C4160 = e->unkAC;
            D_801C4164 = e->unkB0;
            D_801C4168 = e->unkB4;
            len = sqrtf((D_801C4160 * D_801C4160) + (D_801C4164 * D_801C4164) + (D_801C4168 * D_801C4168));
            if (len == 0.0f) {
                D_801C4168 = 120;
            }
            e->unkAC = (D_801C4160 / len) * 120.0f;
            e->unkB0 = (D_801C4164 / len) * 120.0f;
            e->unkB4 = (D_801C4168 / len) * 120.0f;
        }
    } else if (D_800D988C == 2) {
        for (i = 0, e = D_801CB058; i < gPlayers; i++, e++) {
            if (i == 0) {
                cam = &gCameraPerspective[D_80223930];
            } else {
                cam = &gCameraPerspective[D_80223934];
            }
            switch (gCourseID) {
                case SUNSET_BAY:
                    e->unkAC = SIN(0x200) * 64.0f;
                    e->unkB4 = SIN(0xE00) * 64.0f;
                    e->unkFC = SIN(0x200) * 64.0f;
                    e->unkCC = e->unkE4;
                    e->unkD0 = e->unkE8;
                    e->unkD4 = e->unkEC;
                    e->unkD8 = e->unkF0;
                    e->unkDC = e->unkF4;
                    e->unkE0 = e->unkF8;
                    e->unk104 = SIN(0xE00) * 64.0f;
                    break;
                case TWILIGHT_CITY:
                    e->unkAC = cam->unk64 * -1.0f;
                    e->unkB4 = cam->unk6C * -1.0f;
                    D_801C3C50 = (struct UnkStruct_801C3C50*) &D_80192690[i];
                    D_801C3C58 = &D_801C3C60[i].unk0;
                    D_801C3C54 = (struct UnkStruct_801C3C54*) &D_801AEE20[gRiderRaceState[i].nearestRecord];
                    dx = D_801C3C54->unk0 - D_801C3C50->unk44;
                    dz = D_801C3C54->unk8 - D_801C3C50->unk4C;
                    dist = sqrtf((dx * dx) + (dz * dz));
                    if ((dist < 1500.0f) && ((D_801C3C54->unk98 == 1) || (D_801C3C54->unk98 == 0))) {
                        D_801C3C58->unk78 = 1;
                        if (dist != 0.0f) {
                            if (dist < 500.0f) {
                                k = 1.0f;
                            } else {
                                k = sqrtf(100.0f / ((dist - 475.0f) * 4.0f));
                            }
                            e->unkFC = D_801C3C54->unk0 - D_801C3C50->unk44;
                            e->unk104 = D_801C3C54->unk8 - D_801C3C50->unk4C;
                            if (D_801C3C54->unk98 == 0) {
                                e->unkCC = D_800D98B0[0] * k;
                                e->unkD0 = D_800D98B0[1] * k;
                                e->unkD4 = D_800D98B0[2] * k;
                                e->unkD8 = (s32) ((D_800D98B0[3] - e->unkF0) * k) + e->unkF0;
                                e->unkDC = (s32) ((D_800D98B0[4] - e->unkF4) * k) + e->unkF4;
                                e->unkE0 = (s32) ((D_800D98B0[5] - e->unkF8) * k) + e->unkF8;
                            } else if (D_801C3C54->unk98 == 1) {
                                e->unkCC = D_800D9898[0] * k;
                                e->unkD0 = D_800D9898[1] * k;
                                e->unkD4 = D_800D9898[2] * k;
                                e->unkD8 = (s32) ((D_800D9898[3] - e->unkF0) * k) + e->unkF0;
                                e->unkDC = (s32) ((D_800D9898[4] - e->unkF4) * k) + e->unkF4;
                                e->unkE0 = (s32) ((D_800D9898[5] - e->unkF8) * k) + e->unkF8;
                            }
                        }
                    } else {
                        D_801C3C58->unk78 = 0;
                        e->unkFC = cam->unk64 * -1.0f;
                        e->unkCC = e->unkE4;
                        e->unkD0 = e->unkE8;
                        e->unkD4 = e->unkEC;
                        e->unkD8 = e->unkF0;
                        e->unkDC = e->unkF4;
                        e->unkE0 = e->unkF8;
                        e->unk104 = cam->unk6C * -1.0f;
                    }
                    break;
                case SOUTHERN_ISLAND:
                    angle = (e->unk10C << 12) / 360;
                    e->unkB4 = 0.0f;
                    e->unkAC = -64.0f;
                    e->unkFC = (COS(angle) * cam->unk64) - (SIN(angle) * cam->unk6C);
                    e->unkCC = e->unkE4;
                    e->unkD0 = e->unkE8;
                    e->unkD4 = e->unkEC;
                    e->unkD8 = e->unkF0;
                    e->unkDC = e->unkF4;
                    e->unkE0 = e->unkF8;
                    e->unk104 = (COS(angle) * cam->unk6C) + (SIN(angle) * cam->unk64);
                    break;
                default:
                    if (D_800DAB68 != 0) {
                        angle = ((360 - e->unkA8) << 12) / 360;
                        c = COS(angle);
                        s = SIN(angle);
                        e->unkAC = (cam->unk64 * c) - (s * cam->unk6C);
                        e->unkB4 = (cam->unk64 * s) + (c * cam->unk6C);
                        e->unkFC = (cam->unk64 * c) - (s * cam->unk6C);
                        e->unk104 = (cam->unk64 * s) + (c * cam->unk6C);
                    } else {
                        angle = (e->unkA8 << 12) / 360;
                        c = COS(angle);
                        s = SIN(angle);
                        e->unkAC = (cam->unk64 * c) - (s * cam->unk6C);
                        e->unkB4 = (cam->unk64 * s) + (c * cam->unk6C);
                        e->unkFC = (cam->unk64 * c) - (s * cam->unk6C);
                        e->unk104 = (cam->unk64 * s) + (c * cam->unk6C);
                    }
                    e->unkCC = e->unkE4;
                    e->unkD0 = e->unkE8;
                    e->unkD4 = e->unkEC;
                    e->unkD8 = e->unkF0;
                    e->unkDC = e->unkF4;
                    e->unkE0 = e->unkF8;
                    break;
            }
            Math_Normalize_VectorComponents(&D_801CB058[i].unkAC, &D_801CB058[i].unkB4);
            e->unkB0 = 64.0f;
            e->unkAC *= 64.0f;
            e->unkB4 *= 64.0f;
            Math_Normalize_VectorComponents(&D_801CB058[i].unkFC, &D_801CB058[i].unk104);
            e->unk100 = 64.0f;
            e->unkFC *= 64.0f;
            e->unk104 *= 64.0f;
            D_801C4160 = e->unkAC;
            D_801C4164 = e->unkB0;
            D_801C4168 = e->unkB4;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_8008E794.s")
#endif

Gfx* func_8008FB74(Gfx* gdl) {
    UnkStruct_801CB058* e;
    UnkStruct_800DA8B4 sp1B0;
    f32 f;
    UnkStruct_801C43F8* p;
    s32 t;

    sp1B0 = D_800DA8B4; // probably a local array initialised from this file's data in the original; unused
    p = &D_801C43F8[D_8011F8E0];
    func_8004C998(0, p->unk0);
    func_8004C1D0(0, p->unk1C0);
    if ((gPlayers == TWO_PLAYERS) && (gCourseID == RIDER_SELECTION)) {
        func_8004C998(1, p->unk70);
    }
    gSPSegment(gdl++, 0x06, &D_801C43F8[D_8011F8E0]);
    if ((D_801CE638 == 4) || (D_801CE638 == 0xA)) {
        if (D_801CE60C == 1) {
            gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
            gSPViewport(gdl++, &D_800DA8F0);
            gDPPipeSync(gdl++);
            gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 161, 96, 290, 215);
        } else {
            switch (D_800DAB2C) {
                case 0:
                    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
                    gSPViewport(gdl++, &D_800DA900);
                    gDPPipeSync(gdl++);
                    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 27, 96, 156, 215);
                    break;
                case 1:
                    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223934].perspNorm);
                    gSPViewport(gdl++, &D_800DA8F0);
                    gDPPipeSync(gdl++);
                    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 161, 96, 290, 215);
                    break;
            }
        }
    } else if (gPlayers == ONE_PLAYER) {
        gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
        gSPViewport(gdl++, &D_800DA8C0);
        gDPPipeSync(gdl++);
        gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    } else if (D_800DAB2C == 0) {
        gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
        gSPViewport(gdl++, &D_800DA8D0);
        gDPPipeSync(gdl++);
        gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 12, 311, 120);
    } else {
        gSPPerspNormalize(gdl++, gCameraPerspective[D_80223934].perspNorm);
        gSPViewport(gdl++, &D_800DA8E0);
        gDPPipeSync(gdl++);
        gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 122, 311, 229);
    }
    switch (D_800DAB2C) {
        case 0:
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE008[D_80223930],
                      G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE088[D_80223930], G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
            break;
        case 1:
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE008[D_80223934],
                      G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
            gSPMatrix(gdl++, &((GfxPool*) D_3000000)->unkE088[D_80223934], G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
            break;
    }
    if ((gCourseID == DRAKE_LAKE) && (gPlayers == ONE_PLAYER)) {
        gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
        gSPSetGeometryMode(gdl++, G_FOG | G_SHADE | G_SHADING_SMOOTH);
    } else {
        gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
        gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
    }
    gSPDisplayList(gdl++, D_10102D0);
    if (gCourseID == DRAKE_LAKE) {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_2CYCLE);
        gDPSetRenderMode(gdl++, G_RM_FOG_SHADE_A, G_RM_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_PASS2);
        gDPSetFogColor(gdl++, D_801CB058[D_800DAB2C].unk88, D_801CB058[D_800DAB2C].unk8C, D_801CB058[D_800DAB2C].unk90,
                       D_801CB058[D_800DAB2C].unk94);
        gSPFogPosition(gdl++, D_801CB058[D_800DAB2C].unk98, D_801CB058[D_800DAB2C].unk9C);
    } else {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }
    if (((gPlayers == ONE_PLAYER) && (D_801CE64C != 1)) || (gCourseID == RIDER_SELECTION)) {
        gDPPipeSync(gdl++);
        gDPLoadTextureTile(gdl++, D_8001400, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 128, 0, 0, 15, 127, 0,
                           G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 7, G_TX_NOLOD, G_TX_NOLOD);
        gSPDisplayList(gdl++, D_10103F0);
        if (gCourseID == RIDER_SELECTION) {
            gSPDisplayList(gdl++, D_1010430);
        }
    }
    e = &D_801CB058[D_800DAB2C];
    gSPDisplayList(gdl++, D_1010330);
    gDPPipeSync(gdl++);
    gDPLoadTextureBlock(gdl++, D_8000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    if (gPlayers == ONE_PLAYER) {
        gDPLoadMultiBlock(gdl++, D_8000200, 0x100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetEnvColor(gdl++, (s32) e->unk108, (s32) e->unk108, (s32) e->unk108, 0xFF);
        if (D_800D9888 != 0) {
            if (D_801C1FD0 != 0) {
                if (e->unk108 < 255.0f) {
                    f = e->unk108 + 1.5f;
                    if (f > 255.0f) {
                        e->unk108 = 255.0f;
                    } else {
                        e->unk108 = f;
                    }
                }
            }
            t = e->unk108;
            e->unk0 = (((e->unk30 - e->unk18) * t) / 255) + e->unk18;
            e->unk4 = (((e->unk34 - e->unk1C) * t) / 255) + e->unk1C;
            e->unk8 = (((e->unk38 - e->unk20) * t) / 255) + e->unk20;
            e->unkC = (((e->unk3C - e->unk24) * t) / 255) + e->unk24;
            e->unk10 = (((e->unk40 - e->unk28) * t) / 255) + e->unk28;
            e->unk14 = (((e->unk44 - e->unk2C) * t) / 255) + e->unk2C;
            e->unk48 = (((e->unk68 - e->unk58) * t) / 255) + e->unk58;
            e->unk4C = (((e->unk6C - e->unk5C) * t) / 255) + e->unk5C;
            e->unk50 = (((e->unk70 - e->unk60) * t) / 255) + e->unk60;
            e->unk78 = ((t * 0x10) / 255) + 0x3D4;
            e->unk98 = ((t * 0x24) / 255) + 0x3AC;
            e->unk9C = ((t * 0x14) / 255) + 0x3D4;
            e->unkA0 = ((t * 0x898) / 255) + 0x64;
        }
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_2CYCLE);
        gDPSetCombineLERP(gdl++, TEXEL1, TEXEL0, ENVIRONMENT, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, COMBINED, 0, 0, 0,
                          COMBINED);
    } else {
        gDPPipeSync(gdl++);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }
    if (D_800DAB2C == 0) {
        gSPVertex(gdl++, D_60000E0, 7, 0);
    } else {
        gSPVertex(gdl++, D_6000150, 7, 0);
    }
    gSPDisplayList(gdl++, D_10103B8);
    if (gPlayers == ONE_PLAYER) {
        switch (gCourseID) {
            case DOLPHIN_PARK:
            case SUNSET_BAY:
                gdl = func_8008D94C(gdl);
                break;
            case TWILIGHT_CITY:
                gdl = func_8008D454(func_8008CFEC(gdl));
                break;
            case GLACIER_COAST:
                if (D_801CE638 == 0x15) {
                    gdl = func_8008DFD0(gdl);
                }
                break;
        }
    }
    if ((gPlayers == ONE_PLAYER) && (D_801CE64C != 1) && (D_801CE64C != 2)) {
        gSPClearGeometryMode(gdl++, 0xFFFFFFFF);
        gSPSetGeometryMode(gdl++, G_SHADE | G_SHADING_SMOOTH);
        gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(gdl++);
        gDPSetTexturePersp(gdl++, G_TP_PERSP);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetCombineLERP(gdl++, TEXEL0, 0, PRIMITIVE, 0, SHADE, 0, TEXEL0, 0, TEXEL0, 0, PRIMITIVE, 0, SHADE, 0, TEXEL0,
                          0);
        gDPSetPrimColor(gdl++, 0, 0, D_801CB058[0].unkB8, D_801CB058[0].unkBC, D_801CB058[0].unkC0, 0);
        gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPLoadTextureBlock(gdl++, D_8007400, G_IM_FMT_IA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
        gSPDisplayList(gdl++, D_1010470);
    }
    return gdl;
}

Gfx* Draw_WaterEffects(Gfx* gdl) {
    s32 pad; // stack pad

    if ((gCourseID == DRAKE_LAKE) && (gPlayers == ONE_PLAYER)) {
        gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                        G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
        gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    } else {
        gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                        G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
        gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE);
    }
    gSPDisplayList(gdl++, D_1008290);
    if ((gPlayers == ONE_PLAYER) || (gCourseID == RIDER_SELECTION)) {
        gDPPipeSync(gdl++);
        gDPLoadTextureBlock(gdl++, D_8000400, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        if (D_801CE64C == 1) {
            gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                            G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH |
                                            0xFFE0CDF8);
            gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE);
            gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
            gDPPipeSync(gdl++);
            gDPSetCycleType(gdl++, G_CYC_1CYCLE);
            gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetEnvColor(gdl++, (s32) D_801CB160, (s32) D_801CB160, (s32) D_801CB160, D_800D9890);
        } else {
            gDPPipeSync(gdl++);
            gDPSetEnvColor(gdl++, (s32) D_801CB160, (s32) D_801CB160, (s32) D_801CB160, D_800D9890);
            if (gCourseID == DRAKE_LAKE) {
                gDPPipeSync(gdl++);
                gDPSetCycleType(gdl++, G_CYC_2CYCLE);
                gDPSetRenderMode(gdl++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2);
                gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_PASS2);
                gDPSetFogColor(gdl++, D_801CB058[D_800DAB2C].unk88, D_801CB058[D_800DAB2C].unk8C,
                               D_801CB058[D_800DAB2C].unk90, D_801CB058[D_800DAB2C].unk94);
                gSPFogFactor(gdl++, (0x1F4 * 0x100) / (D_801CB058[D_800DAB2C].unk9C - D_801CB058[D_800DAB2C].unk98),
                             ((0x1F4 - D_801CB058[D_800DAB2C].unk98) * 0x100) /
                                 (D_801CB058[D_800DAB2C].unk9C - D_801CB058[D_800DAB2C].unk98));
            } else {
                gDPPipeSync(gdl++);
                gDPSetCycleType(gdl++, G_CYC_1CYCLE);
                gDPSetRenderMode(gdl++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
                gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            }
        }
    } else {
        gDPPipeSync(gdl++);
        gDPLoadTextureBlock(gdl++, D_8000400, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetCycleType(gdl++, G_CYC_1CYCLE);
        gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }
    if (D_800D9894 != 0) {
        switch (D_801CE64C) { /* irregular */
            case 1:
                gSPDisplayList(gdl++, D_10082F0);
                break;
            case 2:
                switch (D_800DAB2C) { /* switch 1; irregular */
                    case 0:           /* switch 1 */
                        gSPDisplayList(gdl++, D_100D258);
                        break;
                    case 1: /* switch 1 */
                        gSPDisplayList(gdl++, D_100E680);
                        break;
                }
                break;
            case 0:
                if (gPlayers == ONE_PLAYER) {
                    gSPDisplayList(gdl++, D_100B590);
                } else {
                    if (D_800DAB2C == 0) {
                        gSPDisplayList(gdl++, D_100D258);
                    } else {
                        gSPDisplayList(gdl++, D_100E680);
                    }
                }
                break;
        }
    }
    return gdl;
}

Gfx* func_800916B4(Gfx* gdl) {
    SysUtils_LightsSetSource((Lights1*) &D_801C43F8[D_8011F8E0].unk35D8[D_800DAB2C], D_801CB058[D_800DAB2C].unkC,
                             D_801CB058[D_800DAB2C].unk10, D_801CB058[D_800DAB2C].unk14, D_801CB058[D_800DAB2C].unk0,
                             D_801CB058[D_800DAB2C].unk4, D_801CB058[D_800DAB2C].unk8, D_801CB058[D_800DAB2C].unkAC,
                             D_801CB058[D_800DAB2C].unkB0, D_801CB058[D_800DAB2C].unkB4);
    SysUtils_LightsSetSource((Lights1*) &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C], D_801CB058[D_800DAB2C].unkD8,
                             D_801CB058[D_800DAB2C].unkDC, D_801CB058[D_800DAB2C].unkE0, D_801CB058[D_800DAB2C].unkCC,
                             D_801CB058[D_800DAB2C].unkD0, D_801CB058[D_800DAB2C].unkD4, D_801CB058[D_800DAB2C].unkFC,
                             D_801CB058[D_800DAB2C].unk100, D_801CB058[D_800DAB2C].unk104);
    if (gCourseID == TWILIGHT_CITY) {
        D_801C3C58 = &D_801C3C60[D_800DAB2C].unk0;
        if (D_801C3C58->unk78 != 0) {
            gSPNumLights(gdl++, NUMLIGHTS_2);
            gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk35D8[D_800DAB2C].l[0], 1);
            gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C].l[0], 2);
            gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C].a, 3);
        } else {
            gSPNumLights(gdl++, NUMLIGHTS_1);
            gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk35D8[D_800DAB2C].l[0], 1);
            gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C].a, 2);
        }
    } else {
        gSPNumLights(gdl++, NUMLIGHTS_1);
        gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C].l[0], 1);
        gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk3600[D_800DAB2C].a, 2);
    }
    gDPPipeSync(gdl++);
    gDPSetFogColor(gdl++, D_801CB058[D_800DAB2C].unk48, D_801CB058[D_800DAB2C].unk4C, D_801CB058[D_800DAB2C].unk50,
                   D_801CB058[D_800DAB2C].unk54);
    gSPFogPosition(gdl++, D_801CB058[D_800DAB2C].unk78, D_801CB058[D_800DAB2C].unk7C);
    return gdl;
}

Gfx* func_80091CD8(Gfx* gdl) {
    gSPNumLights(gdl++, NUMLIGHTS_0);
    gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk35D8[D_800DAB2C].l[0], 1);
    gSPLight(gdl++, &D_801C43F8[D_8011F8E0].unk35D8[D_800DAB2C].a, 2);
    return gdl;
}

#ifdef NON_MATCHING
// Score 30 of 8800: the code matches, only the static's address differs. The static (D_800DA914, 0x800DA914) has
// to be in this file's .data, which is still part of the 0x8F000 data blob. As an extern, IDO no longer sinks the
// store below the gdl writes (score 2610).
void* func_80091DBC(Gfx* gdl) {
    static s32 D_800DA914 = { 0 };

    D_800DA914 = (D_800DA914 % 32) + 1;
    if ((D_800DA914 == 0x1C) || (D_800DA914 == 0x1F)) {
        gSPSegment(gdl++, 0x09, D_8035D200);
    } else {
        gSPSegment(gdl++, 0x09, D_8035C800);
    }
    if ((D_800DA914 == 5) || (D_800DA914 == 9)) {
        gSPSegment(gdl++, 0x0B, D_8035E600);
    } else {
        gSPSegment(gdl++, 0x0B, D_8035DC00);
    }
    if ((D_800DA914 == 0xB) || (D_800DA914 == 0xE)) {
        gSPSegment(gdl++, 0x0C, D_8035FA00);
    } else {
        gSPSegment(gdl++, 0x0C, D_8035F000);
    }
    if ((D_800DA914 == 0x19) || ((D_800DA914 == 0x1C))) {
        gSPSegment(gdl++, 0x0A, D_80360E00);
    } else {
        gSPSegment(gdl++, 0x0A, D_80360400);
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_43DA0/func_80091DBC.s")
#endif
