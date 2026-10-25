#include "common.h"

extern s32 D_802C6D30;
extern s32 D_802C6D34;
extern s32 D_802C6D38;
extern s32 D_802C6D3C;
extern u16 D_802C6D40;
extern s32 D_801C2650;
extern Vp D_i6_802C6C70;

void func_i6_802C6B34(void);

void func_i6_802C5800(void) {
    s32 i;
    s32 x;
    MtxF sp170;
    MtxF sp130;
    MtxF spF0;
    Mtx spB0;
    Mtx sp70;

    if ((D_801CE63C != 0) && (gGameState == 0x32)) {
        if (gPrevGameState == 100) {
            D_802C6D30 = 0;
            D_802C6D34 = 320;
            D_802C6D38 = -264;
        } else {
            D_802C6D30 = 2;
            D_802C6D34 = 20;
            D_802C6D38 = 20;
        }
    }

    func_800481E0(D_801CE5F8->unkA40, &D_802C6D40, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.025f);
    func_800484C8(&sp70, &sp130, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB0, &sp170);
    SysUtils_MatrixAffineMultiply(&sp130, &sp170, &spF0);

    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802C6D38;
        } else {
            x = D_802C6D34;
        }
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_i6_802C6C70;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = (x + 56) << 2;
        D_801CE5F8->unk1280[i].vp.vtrans[1] = (102 + i * 18) << 2;
    }
    if (D_801C2650 == 0) {
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_i6_802C6C70;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = (D_802C6D38 + 56) << 2;
        D_801CE5F8->unk1280[i].vp.vtrans[1] = 170 << 2;
        i++;
    }
    if (D_801C2650 == 0) {
        x = D_802C6D34;
    } else {
        x = D_802C6D38;
    }
    SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
    D_801CE5F8->unk1280[i] = D_i6_802C6C70;
    D_801CE5F8->unk1280[i].vp.vtrans[0] = (x + 56) << 2;
    D_801CE5F8->unk1280[i].vp.vtrans[1] = 206 << 2;
}

Gfx* func_i6_802C5B74(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if ((gGameState == 0x32) && (gPrevGameState != 0x64)) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;
    gdl = func_i6_802C5C2C(Draw_WaterEffects(func_800949B8(func_8008FB74(gdl), gCourseID)));

    if (gGameState == 0x32) {
        func_i6_802C6B34();
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5C2C.s")

void func_i6_802C6B34(void) {
    s32 var_a2 = 0;

    switch (D_802C6D30) {
        case 0:
            D_802C6D30 = 1;
            break;
        case 1:
            D_802C6D34 -= 0x14;
            if (D_802C6D34 < 0x14) {
                D_802C6D30 = 2;
                D_802C6D34 = 0x14;
            }
            D_802C6D38 = 0x28 - D_802C6D34;
            break;
        case 2:
            if (D_801CE692[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
                var_a2 = 1;
                D_802C6D30 = 3;
            }
            break;
        case 3:
            D_802C6D34 -= 0x14;
            if (D_802C6D34 < -0x108) {
                D_802C6D30 = 4;
                D_802C6D34 = -0x108;
                D_802C6D3C = 0;
            }
            D_802C6D38 = 0x28 - D_802C6D34;
            break;
        case 4:
            if (++D_802C6D3C >= 3) {
                func_801EC830();
            }
            break;
    }

    if (var_a2 != 0) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}
