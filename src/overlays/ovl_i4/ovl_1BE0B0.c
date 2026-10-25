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
extern s32 D_802C76A4;
extern s32 D_802C76B4;
extern s32 D_802C76B8;
extern s32 D_802C76BC;
extern s32 D_802C76C0;
extern s32 D_802C76C4;
extern s32 D_802C76C8;
extern s32 D_802C76CC;
extern s32 D_802C76D0;
extern Gfx D_80A6E00[];
extern Mtx D_7000A40[];
extern Vp D_106F738;
extern Gfx D_106F748[];
extern u32 D_800DB5B0[][2];
extern u32 D_800DB5F8[][2];
extern u32 D_800DB6D0[][2];

void func_i4_802C7344(void);

void func_i4_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_COURSE_SELECT)) {
        func_i4_802C58F8();
    }

    if (D_i4_802C7530 != 0) {
        D_i4_802C7530 = 0;
        func_80069740(&D_80198310, D_800DAAB4[D_800DAAD8[D_800DA9D0]]);
        func_8006977C(&D_80198350, D_i4_802C760C[D_800DAAD8[D_800DA9D0]]);
    }

    Camera_SetOrbitMatrices(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C76AC, &D_80198310, &D_80198350);
}

void func_i4_802C58F8(void) {
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
        D_802C76B0 = 0;
        if (D_801CB280 & 8) {
            D_802C76C8 = 1;
            D_802C76D0 = 4;
            D_802C76C4 = 1;
        } else {
            D_802C76C8 = 0;
            D_802C76D0 = 3;
            D_802C76C4 = 0;
        }
    } else {
        D_802C76B0 = 2;
        if (D_801CB280 & 8) {
            D_802C76C8 = 3;
            D_802C76D0 = 4;
            D_802C76C4 = 1;
        } else {
            D_802C76C8 = 2;
            D_802C76D0 = 3;
            D_802C76C4 = 0;
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
            D_802C76A4 = 1;
        } else {
            D_802C76A4 = 0;
        }
    } else {
        D_802C76A4 = 1;
    }

    if (D_800DA9D0 < D_802C76A4) {
        D_800DA9D0 = D_802C76A4;
    }
}

Gfx* func_i4_802C5B78(Gfx* dList) {
    Gfx* temp_v0;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_COURSE_SELECT) {
            osViBlack(0);
            return func_80093C44(dList);
        }
    }
    D_802C76A8 = D_800DA9D0;
    D_800DAB2C = 0;
    temp_v0 = func_i4_802C5CDC(Draw_WaterEffects(func_800949B8(func_8008FB74(dList), gCourseID)));

    dList = temp_v0 + 1;

    gSPDisplayList(temp_v0++, &D_106F168);

    if (gGameState == GAME_STATE_COURSE_SELECT) {
        func_i4_802C6BAC();
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i4/ovl_1BE0B0/func_i4_802C5CDC.s")

#ifdef NON_MATCHING
// Score 5050 of 14700. The commands and their order match; IDO here keeps the second 0xB6000000 (clear geometry
// mode) word in a register, runs out of registers and spills five display-list pointers to a 0x70 stack frame,
// where the original needs no frame.
Gfx* func_i4_802C6778(Gfx* dList) {
    s32 course = D_800DAAD8[D_800DA9D0];
    u32* models;
    s32 offset;

    if (D_i4_802C7534 == 0) {
        models = D_800DB5F8[course];
    } else {
        models = D_800DB6D0[course];
    }

    gSPDisplayList(dList++, D_80A6E00);
    gDPPipeSync(dList++);
    gDPSetColorImage(dList++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
    gSPPerspNormalize(dList++, D_802C76AC);
    gSPMatrix(dList++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(dList++, D_801CE5F8->unkA80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPViewport(dList++, &D_106F738);
    gSPDisplayList(dList++, D_106F748);
    gDPSetEnvColor(dList++, 255, 255, 255, 255);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 150, 53, 292, 159);
    offset = course * 0x8000 + 0x10000;
    gSPDisplayList(dList++, D_800DB5B0[course][0] + offset);
    gSPClearGeometryMode(dList++, G_LIGHTING);
    gSPDisplayList(dList++, models[0] + offset);
    gSPSetGeometryMode(dList++, G_LIGHTING);
    gDPPipeSync(dList++);
    gDPSetRenderMode(dList++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gSPDisplayList(dList++, D_800DB5B0[course][1] + offset);
    gSPClearGeometryMode(dList++, G_LIGHTING);
    gSPDisplayList(dList++, models[1] + offset);
    gDPPipeSync(dList++);
    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
    return dList;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i4/ovl_1BE0B0/func_i4_802C6778.s")
#endif

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

void func_i4_802C6BAC(void) {
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
            func_i4_802C7344();
            break;
    }
}

void CourseSelect_Input(void) {
    s32 i;

    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        D_800D8240 = 0;
        if (D_801CE608.gameMode == 11) {
            func_i4_802C7474(0x28);
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
            D_802C76CC = D_i4_802C754C = i;
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        func_i4_802C7474(10);
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE65A[D_802C76B0].unk0 & U_JPAD) {
        if (--D_800DA9D0 < D_802C76A4) {
            D_800DA9D0 = 8;
        }
        while (1) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (--D_800DA9D0 < D_802C76A4) {
                D_800DA9D0 = 8;
            }
        }
        if (D_800DA9D0 != D_802C76A8) {
            D_i4_802C7530 = 1;
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A[D_802C76B0].unk0 & D_JPAD) {
        if (++D_800DA9D0 >= 9) {
            D_800DA9D0 = D_802C76A4;
        }
        while (1) {
            if (D_i4_802C7558[D_800DAAD8[D_800DA9D0]] != 0) {
                break;
            }
            if (++D_800DA9D0 >= 9) {
                D_800DA9D0 = D_802C76A4;
            }
        }
        if (D_800DA9D0 != D_802C76A8) {
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
            D_802C76B4 = (s32) (71.0f * temp_fv0) + 0x8E;
            D_802C76B8 = (s32) (53.0f * temp_fv0) + 0x21;
            D_802C76BC = (s32) (142.0f * temp_fv1);
            D_802C76C0 = (s32) (106.0f * temp_fv1);
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 2;
                D_i4_802C753C = 0;
                D_i4_802C7548 = 1;
            }
            break;
        case 2:
            temp_fv0 = (f32) (5 - D_i4_802C753C) / 5.0f;
            temp_fv1 = (f32) D_i4_802C753C / 5.0f;
            D_802C76B4 = (s32) (71.0f * temp_fv1) + 0x8E;
            D_802C76B8 = (s32) (53.0f * temp_fv1) + 0x21;
            D_802C76BC = (s32) (142.0f * temp_fv0);
            D_802C76C0 = (s32) (106.0f * temp_fv0);
            if (++D_i4_802C753C >= 6) {
                D_i4_802C7538 = 0;
                D_i4_802C753C = 0;
            }
            break;
    }
}

void CourseSelect_DifficultyInput(void) {
    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_i4_802C754C == 3) {
            gDifficulty = DIFFICULTY_EXPERT;
            D_800DAB68 = 1;
        } else {
            gDifficulty = D_i4_802C754C;
            D_800DAB68 = 0;
        }
        if (D_801CE60C == 1) {
            func_i4_802C7474(0x28);
            AudioGeneral_PlaySound(0x37, 0);
            return;
        }
        D_i4_802C7554 = 1;
        D_i4_802C7538 = 3;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7538 = 1;
        D_i4_802C753C = 0;
        D_i4_802C7544 = 2;
        D_i4_802C7548 = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & U_JPAD) {
        if (--D_i4_802C754C < D_802C76CC) {
            D_i4_802C754C = D_802C76D0 - 1;
        }
        while (1) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (--D_i4_802C754C < D_802C76CC) {
                D_i4_802C754C = D_802C76D0 - 1;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & D_JPAD) {
        if (++D_i4_802C754C >= D_802C76D0) {
            D_i4_802C754C = D_802C76CC;
        }
        while (1) {
            if (D_i4_802C757C[D_800DAAD8[D_800DA9D0]][D_i4_802C754C] != 0) {
                break;
            }
            if (++D_i4_802C754C >= D_802C76D0) {
                D_i4_802C754C = D_802C76CC;
            }
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_i4_802C7344(void) {
    if (D_801CE65A[D_802C76B0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_800DAA04 == 0) {
            D_801CE61C = 1;
        } else {
            D_801CE61C = 0;
        }
        func_i4_802C7474(0x28);
        AudioGeneral_PlaySound(0x37, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & B_BUTTON) {
        D_i4_802C7554 = 0;
        D_i4_802C7538 = 2;
        D_i4_802C753C = 0;
        AudioGeneral_PlaySound(0x16, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & L_JPAD) {
        if (--D_800DAA04 < 0) {
            D_800DAA04 = 1;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE65A[D_802C76B0].unk0 & R_JPAD) {
        if (++D_800DAA04 >= 2) {
            D_800DAA04 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_i4_802C7474(s32 arg0) {
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
