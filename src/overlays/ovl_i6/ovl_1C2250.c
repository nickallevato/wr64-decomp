#include "common.h"

extern s32 D_802C6D30;
extern s32 D_802C6D34;
extern s32 D_802C6D38;
extern s32 D_802C6D3C;
extern u16 D_802C6D40;
extern s32 D_801C2650;
extern Vp D_i6_802C6C70;
extern s32 D_801C2654;
extern s32 D_i6_802C6C80[];
extern s32 D_i6_802C6C8C[];
extern s8 D_80226E44[];
extern RiderStruct D_801C2948[];
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];

Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);

void func_i6_802C6B34(void);
Gfx* func_i6_802C5C2C(Gfx*);

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

Gfx* func_i6_802C5C2C(Gfx* gdl) {
    UnkStruct_AF8C0_14* rec;
    s32 x;
    s32 lapX;
    s32 i;
    s32 mode;
    char buf[4];

    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, D_802C6D34 + 8, 30, 264, 24);
    gdl = func_80094338(gdl, 0, D_802C6D38 + 8, 68, 264, 16);
    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802C6D38;
        } else {
            x = D_802C6D34;
        }
        gdl = func_80094338(gdl, 0, x + 8, 90 + i * 18, 264, 16);
    }
    if (D_801C2650 == 0) {
        gdl = func_80094338(gdl, 0, D_802C6D38 + 8, 147, 264, 10);
        gdl = func_80094338(gdl, 0, D_802C6D38 + 8, 158, 264, 16);
    }
    if (D_801C2650 == 0) {
        lapX = D_802C6D34;
    } else {
        lapX = D_802C6D38;
    }
    gdl = func_80094338(gdl, 0, lapX + 8, 183, 264, 10);
    gdl = func_80094338(gdl, 0, lapX + 8, 194, 264, 16);
    gdl = func_801E7E74(gdl, 0, 0, 0, 255);
    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802C6D38;
        } else {
            x = D_802C6D34;
        }
        gdl = func_801E7FD8(gdl, x + 40, 92 + i * 18, x + 66, 104 + i * 18);
    }
    if (D_801C2650 == 0) {
        gdl = func_801E7FD8(gdl, D_802C6D38 + 40, 160, D_802C6D38 + 66, 172);
    }
    gdl = func_801E7FD8(gdl, lapX + 40, 196, lapX + 66, 208);
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 310, 218);
    gSPPerspNormalize(gdl++, D_802C6D40);
    // Each rider model has three matrices in unkC80, indexed here as one 0xC0-byte element (the asm multiplies
    // by 0xC0 once), as in func_i9_802C71AC.
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    for (i = 0; i < 3; i++) {
        if (D_800DAB68 != 0) {
            rec = &D_801C23B0[gCourseID];
        } else {
            rec = &gBestTimes[gCourseID][i];
        }
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (D_800DAB68 != 0) {
            if (i == 0) {
                gdl = func_801E4FE8(gdl, rec->unk4, 0, 0, ((Mtx(*)[3]) D_801CE5F8->unkC80)[i]);
            }
        } else {
            gdl = func_801E4FE8(gdl, rec->unk4, 0, 0, ((Mtx(*)[3]) D_801CE5F8->unkC80)[i]);
        }
    }
    if (D_801C2650 == 0) {
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, D_800DA9B0[gPlayer1Rider], 0, 0, ((Mtx(*)[3]) D_801CE5F8->unkC80)[i]);
        i++;
    }
    if (D_800DAB68 == 0) {
        rec = &gBestLaps[gCourseID];
        gSPViewport(gdl++, &D_7001280[i]);
        gSPMatrix(gdl++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, rec->unk4, 0, 0, ((Mtx(*)[3]) D_801CE5F8->unkC80)[i]);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, D_800DAA34[gCourseID], D_i6_802C6C8C[gCourseID] + D_802C6D34 + 56, 33, 0);
    gdl = func_801E3EE0(gdl, 1, 31, D_802C6D38 + 23, 71, 0);
    gdl = func_801E3EE0(gdl, 1, 17, D_802C6D38 + 75, 71, 0);
    gdl = func_801E3EE0(gdl, 1, 32, D_802C6D38 + 135, 71, 0);
    gdl = func_801E3EE0(gdl, 1, 3, D_802C6D38 + 218, 71, 0);
    if (D_801C2650 == 0) {
        gdl = func_801E3EE0(gdl, 0, 25, D_802C6D38 + 18, 148, 0);
    }
    gdl = func_801E3EE0(gdl, 0, 13, lapX + 18, 184, 0);

    for (i = 0; i < 3; i++) {
        if (D_800DAB68 != 0) {
            if (i == 0) {
                if (D_801C2650 != 0) {
                    mode = 4;
                } else {
                    mode = 0;
                }
            } else {
                mode = 7;
            }
        } else if (D_801C2650 != 0) {
            if (D_801C2650 == 1) {
                if (i + 1 == D_801C2650) {
                    mode = 4;
                } else {
                    mode = 0;
                }
            } else if (i + 1 == D_801C2650) {
                mode = 6;
            } else {
                mode = 0;
            }
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        if (D_800DAB68 != 0) {
            rec = &D_801C23B0[gCourseID];
        } else {
            rec = &gBestTimes[gCourseID][i];
        }
        if (i & 1) {
            x = D_802C6D38;
        } else {
            x = D_802C6D34;
        }
        sprintf(buf, "%1d", i + 1);
        gdl = Printer_DrawString(gdl, 2, buf, D_80226E44[i + 1] + x + 17, 92 + i * 18);
        if (D_800DAB68 != 0) {
            if (i == 0) {
                if (rec->unk8 == 0) {
                    sprintf(buf, "%s", "N");
                } else {
                    sprintf(buf, "%s", "C");
                }
                gdl = Printer_DrawString(gdl, 1, buf, x + 59, 92 + i * 18);
                gdl = Printer_DrawString(gdl, 2, rec->unk10, x + 135, 92 + i * 18);
                gdl = Printer_DrawTime(gdl, 2, rec->unk0, x + 198, 92 + i * 18);
            } else {
                gdl = Printer_DrawString(gdl, 2, "---", x + 135, 92 + i * 18);
                gdl = Printer_DrawString(gdl, 2, "-'--@---", x + 198, 92 + i * 18);
            }
            gdl = func_801E3EE0(gdl, 0, 36, x + 75, 93 + i * 18, 0);
        } else {
            if (rec->unk8 == 0) {
                sprintf(buf, "%s", "N");
            } else {
                sprintf(buf, "%s", "C");
            }
            gdl = Printer_DrawString(gdl, 1, buf, x + 59, 92 + i * 18);
            gdl = Printer_DrawString(gdl, 2, rec->unk10, x + 135, 92 + i * 18);
            gdl = Printer_DrawTime(gdl, 2, rec->unk0, x + 198, 92 + i * 18);
            gdl = func_801E3EE0(gdl, 0, D_i6_802C6C80[rec->unkC], x + 75, 93 + i * 18, 0);
        }
    }

    if (D_801C2650 == 0) {
        gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        if (D_801CB32C == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        gdl = Printer_DrawString(gdl, 1, buf, D_802C6D38 + 59, 160);
        gdl = Printer_DrawTime(gdl, 2, D_801C2948[gPlayer1Rider].lapTimes[5], D_802C6D38 + 198, 160);
        if (D_800DAB68 != 0) {
            gdl = func_801E3EE0(gdl, 0, 36, D_802C6D38 + 75, 160, 0);
        } else {
            gdl = func_801E3EE0(gdl, 0, D_i6_802C6C80[gDifficulty], D_802C6D38 + 75, 161, 0);
        }
    }

    if (D_800DAB68 != 0) {
        gdl = Printer_SetMode(gdl, 7, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = Printer_DrawString(gdl, 2, "---", lapX + 135, 196);
        gdl = Printer_DrawString(gdl, 2, "-'--@---", lapX + 198, 196);
        gdl = func_801E3EE0(gdl, 0, 36, lapX + 75, 197, 0);
    } else {
        if (D_801C2654 != 0) {
            gdl = Printer_SetMode(gdl, 4, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        } else {
            gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        }
        rec = &gBestLaps[gCourseID];
        if (rec->unk8 == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        gdl = Printer_DrawString(gdl, 1, buf, lapX + 59, 196);
        gdl = Printer_DrawString(gdl, 2, rec->unk10, lapX + 135, 196);
        gdl = Printer_DrawTime(gdl, 2, rec->unk0, lapX + 198, 196);
        gdl = func_801E3EE0(gdl, 0, D_i6_802C6C80[rec->unkC], lapX + 75, 197, 0);
    }
    return gdl;
}

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
