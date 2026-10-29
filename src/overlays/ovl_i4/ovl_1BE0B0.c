#include "global.h"

extern u16 D_80A0008[];
extern const s16 D_800EAC14[][8];
extern s32 D_801CB288[];
extern s16 D_801CE60C;
extern s32 D_i4_802C7534;
extern s32 D_i4_802C7540;
extern s32 D_i4_802C7544;
extern s32 D_i4_802C7548;
extern s32 D_i4_802C754C;
extern s32 D_i4_802C7550;
extern s32 D_i4_802C7558[];
extern s32 D_i4_802C757C[][4];
extern s32 D_i4_802C76A4;
extern s32 D_i4_802C76B4;
extern s32 D_i4_802C76B8;
extern s32 D_i4_802C76BC;
extern s32 D_i4_802C76C0;
extern s32 D_i4_802C76C4;
extern s32 D_i4_802C76C8;
extern s32 D_i4_802C76CC;
extern s32 D_i4_802C76D0;
extern Gfx D_80A6E00[];
extern Mtx D_7000A40[];
extern Vp D_106F738;
extern Gfx D_106F748[];
extern u32 D_800DB5B0[][2];
extern u32 D_800DB5F8[][2];
extern u32 D_800DB6D0[][2];

extern u16 D_80A3DD8[];
extern Gfx D_80A6DB0[];
extern TexLabel D_i4_802C7630[];
extern TexLabel D_i4_802C7650[];
extern s32 D_i4_802C7660[];
extern s32 D_800DAA10[];
extern UnkStruct_AF8C0_14 gBestTimes[][3];
extern UnkStruct_AF8C0_14 gBestLaps[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 gStuntRecords[][3];

void CourseSelect_Step3Input(void);
Gfx* func_i4_802C6778(Gfx*);
Gfx* func_i4_802C69C4(Gfx*, s32, s32);

void CourseSelect_OverlayUpdate(void) {
    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_COURSE_SELECT)) {
        CourseSelect_Init();
    }

    if (D_i4_802C7530 != 0) {
        D_i4_802C7530 = 0;
        func_80069740(&D_80198310, D_800DAAB4[D_800DAAD8[D_800DA9D0]]);
        func_8006977C(&D_80198350, D_i4_802C760C[D_800DAAD8[D_800DA9D0]]);
    }

    Camera_SetOrbitMatrices(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_i4_802C76AC, &D_80198310, &D_80198350);
}

void CourseSelect_Init(void) {
    s32 idx;
    s32 i;
    s32 j;
    s32 isFound;

    if (D_801CE608.gameMode == 11) {
        D_i4_802C7534 = 1;
    } else {
        D_i4_802C7534 = 0;
    }

    if (D_801CE608.player == 1) {
        D_i4_802C76B0 = 0;
        if (D_801CB280 & 8) {
            D_i4_802C76C8 = 1;
            D_i4_802C76D0 = 4;
            D_i4_802C76C4 = 1;
        } else {
            D_i4_802C76C8 = 0;
            D_i4_802C76D0 = 3;
            D_i4_802C76C4 = 0;
        }
    } else {
        D_i4_802C76B0 = 2;
        if (D_801CB280 & 8) {
            D_i4_802C76C8 = 3;
            D_i4_802C76D0 = 4;
            D_i4_802C76C4 = 1;
        } else {
            D_i4_802C76C8 = 2;
            D_i4_802C76D0 = 3;
            D_i4_802C76C4 = 0;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_801CB288[i] + 1; j++) {
            idx = (i == 3) ? D_800EAC14[i - 1][j] : D_800EAC14[i][j];
            D_i4_802C757C[idx][i] = 1;
        }
    }

    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 1)) {
        if (!(D_801CB280 & 1)) {
            D_i4_802C757C[1][1] = 0;
        }
        if (!(D_801CB280 & 2)) {
            D_i4_802C757C[1][2] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        isFound = 0;
        for (j = 0; j < 4; j++) {
            if (D_i4_802C757C[i][j] != 0) {
                isFound = 1;
                break;
            }
        }
        if (isFound) {
            D_i4_802C7558[i] = 1;
        }
    }

    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 1)) {
        D_i4_802C7558[0] = 0;
    }

    if (D_801CE608.player == 1) {
        if (D_801CE608.gameMode == 0) {
            D_i4_802C76A4 = 1;
        } else {
            D_i4_802C76A4 = 0;
        }
    } else {
        D_i4_802C76A4 = 1;
    }

    if (D_800DA9D0 < D_i4_802C76A4) {
        D_800DA9D0 = D_i4_802C76A4;
    }
}

Gfx* CourseSelect_Draw(Gfx* dList) {
    Gfx* temp_v0;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_COURSE_SELECT) {
            osViBlack(0);
            return func_80093C44(dList);
        }
    }
    D_i4_802C76A8 = D_800DA9D0;
    D_800DAB2C = 0;
    temp_v0 = CourseSelect_DrawScreen(Draw_WaterEffects(func_800949B8(func_8008FB74(dList), gCourseID)));

    dList = temp_v0 + 1;

    gSPDisplayList(temp_v0++, &D_106F168);

    if (gGameState == GAME_STATE_COURSE_SELECT) {
        CourseSelect_UpdateInput();
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x28:
                gCourseID = D_800DAAD8[D_800DA9D0];
                if (D_800D8240 != 0) {
                    gCourseID = D_801C3A10;
                }
                func_8009345C();
                break;

            case 10:
                GameState_EnterRiderSelect();
                break;

            default:
                break;
        }
    }
    return dList;
}

Gfx* CourseSelect_DrawScreen(Gfx* dList) {
    s32 i;
    s32 mode;
    s32 yOffset;
    s32 y;
    s32 pad[6]; // stack pad: the frame is 0xD8
    s32 j;
    s32 offset;
    s32 height;
    s32 posY;
    TexLabel* item;

    gSPDisplayList(dList++, D_80A6DB0);
    gDPFillRectangle(dList++, 150, 53, 291, 158);
    dList = func_i4_802C6778(dList);
    if (D_i4_802C7540 != 0) {
        gSPDisplayList(dList++, D_80A6DB0);
        gDPFillRectangle(dList++, D_i4_802C76B4 + 8, D_i4_802C76B8 + 20, D_i4_802C76B4 + D_i4_802C76BC + 7,
                         D_i4_802C76B8 + D_i4_802C76C0 + 19);
    }
    gSPDisplayList(dList++, D_106F628);

    dList = func_80094338(dList, 0, 28, 24, 264, 24);
    if (D_801CE608.gameMode == 11) {
        dList = func_80094338(dList, 0, 171, 185, 101, 10);
        dList = func_80094338(dList, 0, 171, 197, 101, 16);
    } else {
        dList = func_80094338(dList, 0, 171, 161, 101, 12);
        dList = func_80094338(dList, 0, 171, 174, 101, 12);
        dList = func_80094338(dList, 0, 171, 188, 101, 12);
        dList = func_80094338(dList, 0, 171, 201, 101, 12);
    }
    // one local serves as this row counter and as the texture offset below
    for (offset = 0; offset < 9; offset++) {
        dList = func_80094338(dList, 0, 28, offset * 18 + 53, 118, 16);
    }

    if (D_i4_802C7548 != 0) {
        switch (D_i4_802C76C8) {
            case 0:
            case 1:
                dList = func_i4_802C69C4(dList, 162, 73);
                break;

            case 2:
            case 3:
                dList = func_i4_802C69C4(dList, 162, 55);
                for (offset = 0, j = 0, posY = 124; posY < 158; j += 17, posY += 17, offset += 0x7D6) {
                    if (posY != 141) {
                        height = 17;
                    } else {
                        height = 16;
                    }
                    gDPLoadTextureTile(dList++, D_80A3DD8 + offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 118, height, 0, 0,
                                       117, height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                    gSPTextureRectangle(dList++, 162 << 2, posY << 2, 280 << 2, (j + height + 124) << 2, 0, 0, 0,
                                        1 << 10, 1 << 10);
                }
                break;
        }
    }

    dList = Printer_SetMode(dList, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    dList = func_801E3EE0(dList, 2, 4, 64, 27, 0);
    if (D_801CE608.gameMode == 11) {
        dList = func_801E3EE0(dList, 0, 30, 191, 186, 0);
        dList = func_80094200(dList, 2, gStuntRecords[D_800DAAD8[D_800DA9D0]][0].unk0, 191, 200);
    } else {
        dList = func_801E3EE0(dList, 0, 14, 195, 163, 0);
        dList = func_801E3EE0(dList, 0, 13, 197, 190, 0);
        if ((D_i4_802C754C == 3) && (D_i4_802C7548 != 0)) {
            dList = Printer_DrawTime(dList, 1, D_801C23B0[D_800DAAD8[D_800DA9D0]].unk0, 195, 176);
            dList = Printer_DrawString(dList, 1, "-'--@---", 195, 203);
        } else {
            dList = Printer_DrawTime(dList, 1, gBestTimes[D_800DAAD8[D_800DA9D0]][0].unk0, 195, 176);
            dList = Printer_DrawTime(dList, 1, gBestLaps[D_800DAAD8[D_800DA9D0]].unk0, 195, 203);
        }
    }

    for (i = 0; i < 9; i++) {
        if (i == D_800DA9D0) {
            mode = 6;
        } else if (D_i4_802C7558[D_800DAAD8[i]] != 0) {
            mode = 0;
        } else {
            mode = 7;
        }
        dList = Printer_SetMode(dList, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        dList = func_801E3EE0(dList, 1, D_800DAA10[D_800DAAD8[i]], D_i4_802C7660[D_800DAAD8[i]] + 48, i * 18 + 56, 0);
    }

    if (D_i4_802C7548 != 0) {
        yOffset = 0;
        if (D_801CE60C == 1) {
            if (D_i4_802C76C4 != 0) {
                yOffset = -6;
            }
            y = 65;
        } else {
            if (D_i4_802C76C4 != 0) {
                yOffset = -8;
            }
            y = 47;
            dList = Printer_SetMode(dList, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
            dList = func_801E3EE0(dList, 0, 32, 195, 128, 0);
            for (i = 0, item = D_i4_802C7650; i < 2; i++, item++) {
                if (D_i4_802C7554 != 0) {
                    if (i == D_800DAA04) {
                        mode = 6;
                    } else {
                        mode = 0;
                    }
                } else {
                    mode = 0;
                }
                dList = Printer_SetMode(dList, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
                dList = func_801E3EE0(dList, 1, item->texture, item->x + 193, 143 - i, 0); // y 143 - i as in the asm
            }
        }
        for (i = 0, item = D_i4_802C7630; i < D_i4_802C76D0; i++, item++) {
            if (D_i4_802C7550 != 0) {
                if (i == D_i4_802C754C) {
                    mode = 6;
                } else if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] == 0) {
                    mode = 7;
                } else {
                    mode = 0;
                }
            } else if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] == 0) {
                mode = 7;
            } else {
                mode = 0;
            }
            dList = Printer_SetMode(dList, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
            dList = func_801E3EE0(dList, 1, item->texture, item->x + 194, y + yOffset + 20 + i * 15, 0);
        }
    }
    return dList;
}

Gfx* func_i4_802C6778(Gfx* dList) {
    s32 course = D_800DAAD8[D_800DA9D0];
    u32* water;
    u32* models;
    s32 offset;
    s32 drawModels;

    water = D_800DB5B0[course];
    // FAKE: never false here (ovl_i3's course overview has the same flag, false for Dolphin Park); its blocks
    // stop IDO keeping the 0xB6000000 command word in a register and spilling.
    drawModels = true;
    if (D_i4_802C7534 == 0) {
        models = D_800DB5F8[course];
    } else {
        models = D_800DB6D0[course];
    }

    gSPDisplayList(dList++, D_80A6E00);
    gDPPipeSync(dList++);
    gDPSetColorImage(dList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gSPPerspNormalize(dList++, D_i4_802C76AC);
    gSPMatrix(dList++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dList++, D_801CE5F8->unkA80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPViewport(dList++, &D_106F738);
    gSPDisplayList(dList++, D_106F748);
    gDPSetEnvColor(dList++, 255, 255, 255, 255);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 150, 53, 292, 159);
    offset = course * 0x8000 + 0x10000;
    gSPDisplayList(dList++, water[0] + offset);
    if (drawModels) {
        gSPClearGeometryMode(dList++, G_LIGHTING);
        gSPDisplayList(dList++, models[0] + offset);
    }
    gSPSetGeometryMode(dList++, G_LIGHTING);
    gDPPipeSync(dList++);
    gDPSetRenderMode(dList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gSPDisplayList(dList++, water[1] + offset);
    if (drawModels) {
        gSPClearGeometryMode(dList++, G_LIGHTING);
        gSPDisplayList(dList++, models[1] + offset);
    }
    gDPPipeSync(dList++);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    return dList;
}

Gfx* func_i4_802C69C4(Gfx* dList, s32 x, s32 y) {
    s32 offset;
    s32 i;
    s32 posY;
    s32 height;

    for (offset = 0, i = 0, posY = y; i < 0x50; i += 0x10, posY += 0x10, offset += 0x760) {
        if (i != 0x40) {
            height = 0x10;
        } else {
            height = 3;
        }
        gDPLoadTextureTile(dList++, D_80A0008 + offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 118, height, 0, 0, 117, height - 1,
                           0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
        gSPTextureRectangle(dList++, x << 2, posY << 2, (x + 0x76) << 2, (posY + height) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    return dList;
}

void CourseSelect_UpdateInput(void) {
    switch (D_i4_802C7538) {
        case 0:
            CourseSelect_Input();
            break;
        case 1:
            func_i4_802C6ED0();
            break;
        case 2:
            CourseSelect_DifficultyInput();
            break;
        case 3:
            CourseSelect_Step3Input();
            break;
    }
}

void CourseSelect_Input(void) {
    s32 i;

    if (D_801CE65A[D_i4_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        D_800D8240 = 0;
        if (D_801CE608.gameMode == 11) {
            CourseSelect_Leave(0x28);
            AudioGeneral_PlaySound(0x37, 0);
        } else {
            D_i4_802C7538 = 1;
            D_i4_802C753C = 0;
            D_i4_802C7540 = 0;
            D_i4_802C7544 = 1;
            D_i4_802C7550 = 1;
            for (i = 0; i < 4; i++) {
                if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][i] != 0) {
                    break;
                }
            }
            D_i4_802C76CC = D_i4_802C754C = i;
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE65A[D_i4_802C76B0].unk0 & B_BUTTON) {
        CourseSelect_Leave(10);
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE65A[D_i4_802C76B0].unk0 & U_JPAD) {
        if (--D_800DA9D0 < D_i4_802C76A4) {
            D_800DA9D0 = 8;
        }
        while (1) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (--D_800DA9D0 < D_i4_802C76A4) {
                D_800DA9D0 = 8;
            }
        }
        if (D_800DA9D0 != D_i4_802C76A8) {
            D_i4_802C7530 = 1;
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[D_i4_802C76B0].unk0 & D_JPAD) {
        if (++D_800DA9D0 >= 9) {
            D_800DA9D0 = D_i4_802C76A4;
        }
        while (1) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (++D_800DA9D0 >= 9) {
                D_800DA9D0 = D_i4_802C76A4;
            }
        }
        if (D_800DA9D0 != D_i4_802C76A8) {
            D_i4_802C7530 = 1;
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
    SysUtils_Rand();
}

void func_i4_802C6ED0(void) {
    f32 temp_fv0;
    f32 temp_fv1;

    switch (D_i4_802C7544) {
        case 1:
            D_i4_802C7540 = 1;
            temp_fv0 = (f32) (5 - D_i4_802C753C) / 5.0f;
            temp_fv1 = (f32) D_i4_802C753C / 5.0f;
            D_i4_802C76B4 = (s32) (71.0f * temp_fv0) + 0x8E;
            D_i4_802C76B8 = (s32) (53.0f * temp_fv0) + 0x21;
            D_i4_802C76BC = (s32) (142.0f * temp_fv1);
            D_i4_802C76C0 = (s32) (106.0f * temp_fv1);
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 2;
                D_i4_802C753C = 0;
                D_i4_802C7548 = 1;
            }
            break;
        case 2:
            temp_fv0 = (f32) (5 - D_i4_802C753C) / 5.0f;
            temp_fv1 = (f32) D_i4_802C753C / 5.0f;
            D_i4_802C76B4 = (s32) (71.0f * temp_fv1) + 0x8E;
            D_i4_802C76B8 = (s32) (53.0f * temp_fv1) + 0x21;
            D_i4_802C76BC = (s32) (142.0f * temp_fv0);
            D_i4_802C76C0 = (s32) (106.0f * temp_fv0);
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 0;
                D_i4_802C753C = 0;
            }
            break;
    }
}

void CourseSelect_DifficultyInput(void) {
    if (D_801CE65A[D_i4_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_i4_802C754C == 3) {
            gDifficulty = DIFFICULTY_EXPERT;
            D_800DAB68 = 1;
        } else {
            gDifficulty = D_i4_802C754C;
            D_800DAB68 = 0;
        }
        if (D_801CE60C == 1) {
            CourseSelect_Leave(0x28);
            AudioGeneral_PlaySound(0x37, 0);
            return;
        }
        D_i4_802C7554 = 1;
        D_i4_802C7538 = 3;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7538 = 1;
        D_i4_802C753C = 0;
        D_i4_802C7544 = 2;
        D_i4_802C7548 = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & U_JPAD) {
        if (--D_i4_802C754C < D_i4_802C76CC) {
            D_i4_802C754C = D_i4_802C76D0 - 1;
        }
        while (1) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (--D_i4_802C754C < D_i4_802C76CC) {
                D_i4_802C754C = D_i4_802C76D0 - 1;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & D_JPAD) {
        if (++D_i4_802C754C >= D_i4_802C76D0) {
            D_i4_802C754C = D_i4_802C76CC;
        }
        while (1) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (++D_i4_802C754C >= D_i4_802C76D0) {
                D_i4_802C754C = D_i4_802C76CC;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void CourseSelect_Step3Input(void) {
    if (D_801CE65A[D_i4_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_800DAA04 == 0) {
            D_801CE61C = 1;
        } else {
            D_801CE61C = 0;
        }
        CourseSelect_Leave(0x28);
        AudioGeneral_PlaySound(0x37, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7554 = 0;
        D_i4_802C7538 = 2;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & L_JPAD) {
        if (--D_800DAA04 < 0) {
            D_800DAA04 = 1;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_i4_802C76B0].unk0 & R_JPAD) {
        if (++D_800DAA04 >= 2) {
            D_800DAA04 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void CourseSelect_Leave(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 21;
    D_801CE638 = 5;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(1, 4, 0);
    Popup_Spawn(0, 0);
    if (D_801CE630 == 40) {
        func_800C1F60(7);
    }
}
