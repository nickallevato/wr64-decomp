#include "global.h"

extern s32 D_80223938;
extern s32 D_i3_802C7028;
extern s32 D_i3_802C702C;
extern s32 D_i3_802C6F84;
extern s32 D_i3_802C6F88;
extern s32 D_801CB330;
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern s32 D_801CB350[][4];
extern s32 D_801CB3D0[];
extern RiderStruct gRiderRaceState[];
extern const s16 D_800EABB0[];
extern const s16 D_800EABBC[][8];
extern s32 D_800E9AB0;
// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;
// The asm names this array D_801CE6FC + 0xC; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE708[4];
extern s32 D_i3_802C7020;
extern s32 D_i3_802C6F8C;
extern s32 D_i3_802C6FE4[];
extern s32 D_i3_802C6F64;
extern s32 D_i3_802C6F68;
extern s32 D_i3_802C6F6C;
extern s32 D_i3_802C6F70;
extern s32 D_i3_802C6F74;
extern s32 D_i3_802C6F78;
extern s32 D_i3_802C6F7C;

extern TexLabel D_i3_802C6FB4[];
extern TexLabel D_i3_802C6FCC;
extern s32 D_i3_802C6F80;
extern s32 D_i3_802C6F90[];
extern s32 D_i3_802C6FD4[];
extern u8* D_i3_802C6F50[];
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern Gfx D_804E4E0[];
extern Gfx D_804E418[];
extern Mtx D_7000A40[];
extern Vp D_106F728;
extern Gfx D_106F748[];
extern u32 D_800DB5B0[][2];
extern u32 D_800DB5F8[][2];
extern u32 D_800DB640[][2];
extern u32 D_800DB688[][2];
extern u32 D_800DB718[][2];

Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);

void func_i3_802C5AE8(void);
void CourseOverview_SetCamera(void);
Gfx* func_i3_802C5D54(Gfx*);
Gfx* func_i3_802C6344(Gfx*);
void GameState_EnterCourseOverview(void);
void CourseOverview_Leave(void);

void CourseOverview_OverlayUpdate(void) {
    s32 i;
    s32 j;

    if ((D_801CE63C != 0) && (gGameState == 30)) {
        if (D_801CB334 == D_i3_802C6FE4[gDifficulty]) {
            for (i = 0; i < 8; i++) {
                // A do-while: a for loop over j unrolls into another store order.
                j = 0;
                do {
                    D_801CB350[i][j] = 0;
                } while (++j < 4);
                D_801CB3D0[i] = 0;
            }
            for (i = 0; i < 4; i++) {
                D_801CB340[i] = 0;
            }
            for (i = 0; i < 4; i++) {
                gRiderRaceState[i].unk338 = 0;
            }
        }

        D_i3_802C7028 = 1;
        D_i3_802C6F84 = 0;
        if (gDifficulty == DIFFICULTY_NORMAL) {
            if (D_801CB334 == 1) {
                D_i3_802C7028 = 0;
                D_i3_802C702C = 240;
            } else {
                D_i3_802C702C = 180;
            }
        } else if (D_801CB334 == 0) {
            D_i3_802C7028 = 0;
            D_i3_802C702C = 240;
        } else {
            D_i3_802C702C = 180;
        }

        if (D_801CB330 == 0) {
            D_i3_802C7020 = 0;
            for (i = 0; i < 4; i++) {
                D_801CE708[i] = 4;
            }
            D_801CE704 = D_801CE708[gPlayer1Rider];
        } else {
            for (i = 0; i < 4; i++) {
                D_i3_802C7020 = D_800EABBC[gDifficulty][D_801CB334] - D_801CB340[i];
                for (j = 1; j < 5; j++) {
                    if (D_800EABB0[j] < D_i3_802C7020) {
                        break;
                    }
                }
                D_801CE708[i] = j - 1;
            }
            D_801CE704 = D_801CE708[gPlayer1Rider];
        }

        func_80069740((UnkStruct_80069740*) &D_80198310, D_800DAAB4[gCourseID]);
        func_8006977C(&D_80198350, (s32) &D_800E9AB0);
        if (D_800DAB68 != 0) {
            D_i3_802C6F8C = 2;
        } else {
            D_i3_802C6F8C = 0;
        }
    }

    switch (D_i3_802C7028) {
        case 0:
            func_i3_802C5AE8();
            break;
        case 1:
            CourseOverview_SetCamera();
            break;
    }
}

void func_i3_802C5AE8(void) {
}

void CourseOverview_SetCamera(void) {
    Camera_SetOrbitMatrices(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_i3_802C7024, &D_80198310, &D_80198350);
}

Gfx* CourseOverview_Draw(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 30) {
            return func_80093C44(arg0);
        }
    }
    D_800DAB2C = 0;
    arg0 = func_8009328C(arg0);

    if (D_80223938 != 0) {
        switch (D_i3_802C7028) {
            case 0:
                arg0 = func_i3_802C5D54(arg0);
                break;
            case 1:
                arg0 = func_i3_802C6344(arg0);
                break;
        }
    }
    gSPDisplayList(arg0++, D_106F168);

    if (gGameState == 30) {
        if (D_i3_802C6F88 != 0) {
            D_i3_802C6F88 = 0;
            GameState_EnterCourseOverview();
        } else {
            if (D_801CE692[0].unk0 & 0xB000) {
                if (D_i3_802C6F84 != 0) {
                    CourseOverview_Leave();
                }
            } else if (D_80223938 != 0) {
                if (D_801CE644 >= D_i3_802C702C) {
                    CourseOverview_Leave();
                }
            }
            SysUtils_Rand();
        }
    } else {
        if (D_801CE644 >= 0) {
            D_801CE644--;
        }
        if (D_801CE644 == 0) {
            func_800C1F60(7);
        }
        if (D_80228A16 == 1) {
            gCourseID = D_801CB330;
            func_8009345C();
        }
    }
    if (D_801CE638 != 8) {
        func_800AD3C4();
    }
    if (gGameState == 30) {
        D_801CE644++;
    }
    return arg0;
}

#ifdef NON_MATCHING
// Score 1095 of 38000. The control flow and arithmetic match. The order of the stores and chains is from a greedy
// search: the 255 value (D_i3_802C6F6C/78) is set before the 170 value (D_i3_802C6F70/7C) everywhere. Left:
// register numbering, and case 0's chain stores D_i3_802C6F6C last here, first in the original (none of the 24
// chain orders gives that).
Gfx* func_i3_802C5D54(Gfx* gdl) {
    TexLabel* label;

    switch (D_i3_802C6F64) {
        case 0:
            if (++D_i3_802C6F68 >= 5) {
                D_i3_802C6F64 = 1;
                D_i3_802C6F74 = 0;
                D_i3_802C6F68 = 0;
            }
            D_i3_802C6F6C = D_i3_802C6F70 = D_i3_802C6F7C = D_i3_802C6F78 = 0;
            break;

        case 1:
            if (++D_i3_802C6F68 >= 20) {
                D_i3_802C6F74++;
            }
            if (D_i3_802C6F68 >= 10) {
                D_i3_802C6F6C = 255;
                D_i3_802C6F70 = 170;
            } else {
                D_i3_802C6F6C = D_i3_802C6F68 * 255 / 10;
                D_i3_802C6F70 = D_i3_802C6F68 * 170 / 10;
            }
            if (D_i3_802C6F74 >= 10) {
                D_i3_802C6F78 = 255;
                D_i3_802C6F7C = 170;
            } else {
                D_i3_802C6F78 = D_i3_802C6F74 * 255 / 10;
                D_i3_802C6F7C = D_i3_802C6F74 * 170 / 10;
            }
            if ((D_i3_802C6F68 >= 10) && (D_i3_802C6F74 >= 10)) {
                D_i3_802C6F64 = 2;
                D_i3_802C6F6C = D_i3_802C6F78 = 255;
                D_i3_802C6F70 = D_i3_802C6F7C = 170;
                D_i3_802C6F68 = 0;
                D_i3_802C6F74 = 0;
            }
            break;

        case 2:
            if (++D_i3_802C6F68 >= 25) {
                D_i3_802C6F64 = 3;
                D_i3_802C6F74 = 0;
                D_i3_802C6F68 = 0;
            }
            D_i3_802C6F6C = D_i3_802C6F78 = 255;
            D_i3_802C6F70 = D_i3_802C6F7C = 170;
            break;

        case 3:
            if (++D_i3_802C6F68 >= 10) {
                D_i3_802C6F64 = 0;
                D_i3_802C6F68 = 0;
                D_i3_802C6F6C = 0;
                D_i3_802C6F70 = 0;
                D_i3_802C7028 = 1;
            } else {
                D_i3_802C6F6C = (10 - D_i3_802C6F68) * 255 / 10;
                D_i3_802C6F70 = (10 - D_i3_802C6F68) * 170 / 10;
            }
            D_i3_802C6F78 = D_i3_802C6F6C;
            D_i3_802C6F7C = D_i3_802C6F70;
            break;
    }

    gSPDisplayList(gdl++, D_106F628);
    gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i3_802C6F70);
    gdl = func_80094338(gdl, 2, 32, 75, 256, 32);
    gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i3_802C6F7C);
    gdl = func_80094338(gdl, 0, 32, 133, 256, 32);
    gdl = Printer_SetMode(gdl, 10, D_i3_802C6F6C, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 34, 72, 81, 0);
    gdl = Printer_SetMode(gdl, 10, D_i3_802C6F78, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    if (D_800DAB68 != 0) {
        label = &D_i3_802C6FCC;
    } else {
        label = &D_i3_802C6FB4[gDifficulty];
    }
    return func_801E3EE0(gdl, 2, label->texture, label->x + 50, 139, 0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5D54.s")
#endif

Gfx* func_i3_802C6344(Gfx* gdl) {
    s32 race;
    s32 drawModels;
    u32* water;
    s32 pad[2]; // stack pad: lastRace is at sp+0x50
    s32 lastRace;
    s32 pad2; // stack pad
    s32 xOffset;
    s32 pad3; // stack pad
    u32* models;

    lastRace = D_i3_802C6FD4[gDifficulty];
    switch (D_i3_802C6F64) {
        case 0:
            if (++D_i3_802C6F68 >= 20) {
                D_i3_802C6F64 = 1;
                D_i3_802C6F68 = 0;
            }
            D_i3_802C6F6C = 0;
            D_i3_802C6F70 = 0;
            break;

        case 1:
            if (++D_i3_802C6F68 >= 20) {
                D_i3_802C6F64 = 2;
                D_i3_802C6F68 = 0;
                D_i3_802C6F6C = 255;
                D_i3_802C6F70 = 170;
                D_i3_802C6F80 = 1;
                D_i3_802C6F84 = 1;
            } else {
                D_i3_802C6F6C = D_i3_802C6F68 * 255 / 20;
                D_i3_802C6F70 = D_i3_802C6F68 * 170 / 20;
            }
            break;
    }

    gSPDisplayList(gdl++, D_106F628);
    gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, D_i3_802C6F70);
    gdl = func_80094338(gdl, 0, 28, 30, 264, 24);
    gdl = func_80094338(gdl, 0, 187, 60, 105, 12);
    gdl = func_80094338(gdl, 0, 187, 86, 105, 12);
    gdl = func_80094338(gdl, 0, 187, 99, 105, 22);
    gdl = func_80094338(gdl, 0, 187, 134, 105, 12);
    gdl = func_80094338(gdl, 0, 187, 147, 105, 22);
    gdl = func_80094338(gdl, 0, 28, 176, 191, 34);
    gdl = func_80094338(gdl, 0, 222, 176, 70, 34);
    gSPDisplayList(gdl++, D_804E4E0);
    gdl = func_801E7C58(gdl, 31, 63, 180, 167, 0, 0, 0, D_i3_802C6F70);
    gdl = Printer_SetMode(gdl, 10, D_i3_802C6F6C, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);

    race = D_801CB334;
    if (gDifficulty == DIFFICULTY_NORMAL) {
        race--;
    }
    if (D_801CB330 == 0) {
        xOffset = -33;
    } else if (race >= 0) {
        if (lastRace == D_801CB334) {
            race = 8;
            xOffset = 22;
        } else {
            xOffset = 0;
        }
        gdl = func_801E3EE0(gdl, 1, D_i3_802C6F90[race], 37, 37, 1);
    }
    gdl = func_801E3EE0(gdl, 2, D_800DAA34[D_801CB330], xOffset + 103, 33, 0);
    gdl = func_801E3EE0(gdl, 0, 22, 195, 62, 0);
    gdl = func_801E3EE0(gdl, 0, 14, 212, 88, 0);
    gdl = func_801E3EE0(gdl, 0, 13, 212, 136, 0);
    if (1) {} // FAKE: the original stores this call's arguments in another order
    gdl = func_801E3EE0(gdl, 1, 6, 34, 181, 0);
    if (1) {} // FAKE: as above
    gdl = func_801E3EE0(gdl, 1, 7, 34, 194, 0);
    if (D_801CB330 == 0) {
        gdl = Printer_DrawString(gdl, 2, "-'--@---", 203, 105);
        gdl = Printer_DrawString(gdl, 2, "-'--@---", 203, 153);
    } else if (D_800DAB68 != 0) {
        gdl = Printer_DrawTime(gdl, 2, D_801C23B0[D_801CB330].unk0, 203, 105);
        gdl = Printer_DrawString(gdl, 2, "-'--@---", 203, 153);
    } else {
        gdl = Printer_DrawTime(gdl, 2, gBestTimes[D_801CB330][0].unk0, 203, 105);
        gdl = Printer_DrawTime(gdl, 2, gBestLaps[D_801CB330].unk0, 203, 153);
    }
    gdl = Printer_DrawNumber(gdl, 2, D_801CB340[gPlayer1Rider], 202, 194);
    if (D_i3_802C6FE0 != 0) {
        gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    } else {
        gdl = Printer_SetMode(gdl, 10, D_i3_802C6F6C, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    }
    gdl = Printer_DrawNumber(gdl, 2, D_800EABBC[gDifficulty][D_801CB334], 202, 181);
    if (1) {} // FAKE: the texture commands below then use a running pointer, as in the original

    gDPLoadTextureBlock(gdl++, D_i3_802C6F50[D_801CE704], G_IM_FMT_IA, G_IM_SIZ_8b, 64, 22, 0, G_TX_CLAMP, G_TX_CLAMP,
                        0, 0, 0, 0);
    gSPTextureRectangle(gdl++, 225 << 2, 182 << 2, 289 << 2, 204 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    water = D_800DB5B0[gCourseID];
    drawModels = true;
    if (D_i3_802C6F8C == 0) {
        models = D_800DB5F8[gCourseID];
        if (gCourseID == DOLPHIN_PARK) {
            drawModels = false;
        } else if (gCourseID == PORT_BLUE) {
            if (gDifficulty == DIFFICULTY_EXPERT) {
                models = D_800DB640[gCourseID];
            } else if (gDifficulty == DIFFICULTY_HARD) {
                models = D_800DB688[gCourseID];
            }
        } else if ((gCourseID == MARINE_FORTRESS) &&
                   ((gDifficulty == DIFFICULTY_HARD) || (gDifficulty == DIFFICULTY_EXPERT))) {
            models = D_800DB640[gCourseID];
        }
    } else if (D_i3_802C6F8C == 2) {
        models = D_800DB718[gCourseID];
        if (gCourseID == DOLPHIN_PARK) {
            drawModels = false;
        }
    }

    gSPDisplayList(gdl++, D_804E418);
    gDPPipeSync(gdl++);
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gSPPerspNormalize(gdl++, D_i3_802C7024);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_801CE5F8->unkA80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPViewport(gdl++, &D_106F728);
    gSPDisplayList(gdl++, D_106F748);
    gDPSetEnvColor(gdl++, 255, 255, 255, D_i3_802C6F6C);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 31, 63, 180, 167);
    if (D_i3_802C6F80 == 0) {
        gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }
    if (drawModels) {
        gSPClearGeometryMode(gdl++, G_LIGHTING);
        gSPDisplayList(gdl++, models[0] + 0x50000);
    }
    gSPSetGeometryMode(gdl++, G_LIGHTING);
    gSPDisplayList(gdl++, water[0] + 0x50000);
    if (D_i3_802C6F80 != 0) {
        gDPPipeSync(gdl++);
        gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }
    if (drawModels) {
        gSPClearGeometryMode(gdl++, G_LIGHTING);
        gSPDisplayList(gdl++, models[1] + 0x50000);
    }
    gSPSetGeometryMode(gdl++, G_LIGHTING);
    gSPDisplayList(gdl++, water[1] + 0x50000);
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    return gdl;
}

// An empty function after func_i3_802C6344, without a symbol in splat's output (its 8 bytes were counted in
// func_i3_802C6344's size).
void func_i3_802C6E94(void) {
}

void CourseOverview_Leave(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    Popup_Spawn(0, 0);
    AudioGeneral_PlaySound(58, 0);
}
