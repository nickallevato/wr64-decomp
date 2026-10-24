#include "common.h"

void func_801EC830(s32*);

extern u32 D_802288F0;
extern s32 D_802288F4;
extern s32 D_802288F8;
extern s32 D_802288FC;
extern f32 D_80226334;
extern Vp D_80226340;
extern u16 D_80228900;
extern UnkStruct_801CE5F8* D_801CE5F8;

f32 func_801E31A0(void) {
    int temp;
    f32 var_f2;
    s32 var_v0;
    var_v0 = gControllerOne[D_80154330[0]].unk_8;

    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    temp = 0x3A;
    if (var_v0 >= 0x47) {
        var_v0 = 0x46;
    } else if (var_v0 < 0xC) {
        var_v0 = 0xC;
    }

    var_v0 -= 0xC;
    var_f2 = (2.0f * var_v0) / temp;
    if (var_f2 > 2.0f) {
        var_f2 = 2.0f;
    }
    if (var_f2 < D_80226334) {
        var_f2 = D_80226334;
    }
    return var_f2;
}

void func_801E3250(void) {
    s32 i;
    s32 var_s0;
    MtxF sp170;
    MtxF sp130;
    MtxF spF0;
    Mtx spB0;
    Mtx sp70;

    if (D_801CE63C != 0) {
        D_802288F4 = 0;
        D_802288F0 = 0;
        D_802288F8 = 0x140;
        D_802288FC = -0x108;
    }
    func_800481E0(D_801CE5F8->unkA40, &D_80228900, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.025f);
    func_800484C8(&sp70, &sp130, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB0, &sp170);
    SysUtils_MatrixAffineMultiply(&sp130, &sp170, &spF0);

    for (i = 0; i < 3; i++) {
        if (i & 1) {
            var_s0 = D_802288FC;
        } else {
            var_s0 = D_802288F8;
        }
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_80226340;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = ((var_s0 + 0x38) << 2);
        D_801CE5F8->unk1280[i].vp.vtrans[1] = ((i + 7) * 0x12 - 4) << 2;
    }

    if (D_801C2928 == 0) {
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_80226340;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = ((D_802288FC + 0x38) << 2);
        D_801CE5F8->unk1280[i].vp.vtrans[1] = 0x338;
    }
}

Gfx* func_801E34F8(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    gdl = func_801E3698(Draw_WaterEffects(func_800949B8(func_8008FB74(gdl), gCourseID)));
    func_801E355C();
    return gdl;
}

void func_801E355C(void) {
    s32 var_a1;

    var_a1 = false;
    switch (D_802288F0) {
        case 0:
            var_a1 = true;
            D_802288F0 = 1;
            break;
        case 1:
            D_802288F8 = D_802288F8 - 0x14;
            if (D_802288F8 < 0x14) {
                D_802288F0 = 2;
                D_802288F8 = 0x14;
            }
            break;
        case 2:
            if (D_801CE65A->unk0 & 0xB000) {
                D_802288F0 = 3;
                var_a1 = true;
            }
            break;
        case 3:
            D_802288F8 = D_802288F8 - 0x14;
            if (D_802288F8 < -0x108) {
                D_802288F8 = -0x108;
                D_802288F0 = 4;
                D_802288F4 = 0;
            }
            break;
        case 4:
            D_802288F4 = D_802288F4 + 1;
            if (D_802288F4 >= 3) {
                func_801EC830(&D_802288F4);
                var_a1 = false;
            }
            break;
    }
    if (var_a1) {
        AudioGeneral_PlaySound(0x31, 0);
    }
    D_802288FC = 0x28 - D_802288F8;
}

#ifdef NON_MATCHING
// Score 2848: saved-register assignment differs (gdl in s2, not s3) and the frame is 0xC0, not 0xB8.
typedef struct CourseRecord {
    /* 0x0 */ s32 time;
    /* 0x4 */ s32 rider;
    /* 0x8 */ s32 flag; /* drawn as "C" when set, else "N" */
    /* 0xC */ char name[4];
} CourseRecord; /* size = 0x10 */

extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];
extern CourseRecord D_801C26E8[][3];
extern s32 D_80226350[];
extern s8 D_80226E44[];

Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);

// Draw the course records screen.
Gfx* func_801E3698(Gfx* gdl) {
    char buf[8];
    CourseRecord* rec;
    s32 x;
    s32 y;
    s32 i;
    s32 mode;

    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, D_802288F8 + 8, 30, 264, 24);
    gdl = func_80094338(gdl, 0, D_802288FC + 8, 88, 264, 16);
    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        gdl = func_80094338(gdl, 0, x + 8, 110 + i * 18, 264, 16);
    }
    if (D_801C2928 == 0) {
        gdl = func_80094338(gdl, 0, D_802288FC + 8, 183, 264, 10);
        gdl = func_80094338(gdl, 0, D_802288FC + 8, 194, 264, 16);
    }
    gdl = func_801E7E74(gdl, 0, 0, 0, 255);
    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        gdl = func_801E7FD8(gdl, x + 40, 112 + i * 18, x + 66, 124 + i * 18);
    }
    if (D_801C2928 == 0) {
        gdl = func_801E7FD8(gdl, D_802288FC + 40, 196, D_802288FC + 66, 208);
    }
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 310, 218);
    gSPPerspNormalize(gdl++, D_80228900);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    for (i = 0; i < 3; i++) {
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, D_801C26E8[gCourseID][i].rider, 0, 0, &D_801CE5F8->unkC80[i * 3]);
    }
    if (D_801C2928 == 0) {
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, D_800DA9B0[D_800D48DC], 0, 0, &D_801CE5F8->unkC80[i * 3]);
    }
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, D_800DAA34[gCourseID], D_80226350[gCourseID] + D_802288F8 + 56, 33, 0);
    gdl = func_801E3EE0(gdl, 1, 31, D_802288FC + 23, 91, 0);
    gdl = func_801E3EE0(gdl, 1, 32, D_802288FC + 119, 91, 0);
    gdl = func_801E3EE0(gdl, 1, 62, D_802288FC + 218, 91, 0);
    if (D_801C2928 == 0) {
        gdl = func_801E3EE0(gdl, 0, 26, D_802288FC + 18, 184, 0);
    }
    for (i = 0, y = 112; i < 3; i++, y += 18) {
        if (D_801C2928 != 0) {
            if (D_801C2928 == 1) {
                if (i + 1 == D_801C2928) {
                    mode = 4;
                } else {
                    mode = 0;
                }
            } else if (i + 1 == D_801C2928) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        rec = &D_801C26E8[gCourseID][i];
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        sprintf(buf, "%1d", i + 1);
        gdl = func_801E9858(gdl, 2, buf, D_80226E44[i + 1] + x + 17, y);
        if (rec->flag == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        gdl = func_801E9858(gdl, 1, buf, x + 59, y);
        gdl = func_801E9858(gdl, 2, rec->name, x + 119, y);
        gdl = func_80094200(gdl, 2, rec->time, x + 208, y);
    }
    if (D_801C2928 == 0) {
        gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        if (D_801CB32C == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        gdl = func_801E9858(gdl, 1, buf, D_802288FC + 59, 196);
        gdl = func_80094200(gdl, 2, D_801C26D0, D_802288FC + 208, 196);
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B17D0/func_801E3698.s")
#endif
