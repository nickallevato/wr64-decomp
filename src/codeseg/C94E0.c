#include "common.h"

typedef struct UnkStruct_80228AE0_s {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ s32 unk18; /* inferred */
} UnkStruct_80228AE0;     /* size = 0x1C */

extern Vp D_1014450;
extern s32 D_800D48E0;
extern s32 D_801C1FD8;
extern struct RiderStruct D_801C2938[];
extern s16 D_801CE6F0;
extern s32 gStartLightsState;
extern s32 D_80227740;
extern s32 D_80228AA8;
extern s32 D_80228B50;
extern s32 D_80228B54;
extern s32 D_80228E00[];
extern s32 D_80228E08[];
extern UnkStruct_80228AE0 D_80228AE0[];
extern s32 D_80228D14;
extern s32 D_80228D18;
extern s8 D_80228CF8[];

void Hud_BlendColorSets(void);
void Hud_SetupMatrices(void);
void Hud_DrawGuideArrow(Gfx**);
void Hud_DrawStartLights(Gfx**);
void Hud_DrawMarkers(Gfx**);
void func_801F2060(Gfx**);
void func_801F4120(Gfx**);
void func_801F9520(Gfx**);
void func_801FA3C0(Gfx**);
void func_801FAEB8(Gfx**);
void func_801FB514(Gfx**);
void func_801FBFB4(Gfx**);

void func_801FAEB0(s32 arg0) {
}

#ifdef NON_MATCHING
// Score 1287: the float constants (1.0f, 3.0f, the literal) take different saved FP registers, and the int 3 is not hoisted into s0; the literal is a FAKE local (its rodata is in the F6010 data blob).
extern u8 D_80227744[][3];
extern u8 D_80227754[][3];
extern char D_802279F8[];
extern char D_802279FC[];
extern char D_80227A00[];
extern char D_80227A08[];
extern f32 D_80227A54;
extern s32 D_80228B60[2];
extern s32 D_80228B68[2];
extern s32 D_80228B70[2];

// Flash "LAP n" (or the final-lap message) for each player when a lap starts.
void func_801FAEB8(Gfx** gdlp) {
    Gfx* gdl;
    RiderStruct* rider;
    s32 i;
    f32 f;
    f32 g;
    s32 r0;
    s32 g0;
    s32 b0;
    s32 r1;
    s32 g1;
    s32 b1;
    s32 x;
    s32 y;
    s32 w;
    f32 scale;
    f32 big;

    gdl = *gdlp;
    big = D_80227A54; // FAKE: a float literal in the original (its rodata is still in the F6010 data blob)
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &D_801C2938[D_800D48DC];
        } else {
            rider = &D_801C2938[D_800D48E0];
        }
        if (rider->unk308 != 0) {
            rider->unk308 = 0;
            D_80228B60[i] = 40;
            D_80228B70[i] = 0;
            D_80228B68[i] = 0;
        }
        if (D_80228B60[i] > 0) {
            D_80228B60[i]--;
            f = (3 - D_80228B70[i]) / 3.0f;
            g = 1.0f - f;
            r0 = D_80227744[D_80228B68[i]][0] * f + D_80227744[D_80228B68[i] + 1][0] * g;
            g0 = D_80227744[D_80228B68[i]][1] * f + D_80227744[D_80228B68[i] + 1][1] * g;
            b0 = D_80227744[D_80228B68[i]][2] * f + D_80227744[D_80228B68[i] + 1][2] * g;
            r1 = D_80227754[D_80228B68[i]][0] * f + D_80227754[D_80228B68[i] + 1][0] * g;
            g1 = D_80227754[D_80228B68[i]][1] * f + D_80227754[D_80228B68[i] + 1][1] * g;
            b1 = D_80227754[D_80228B68[i]][2] * f + D_80227754[D_80228B68[i] + 1][2] * g;
            D_80228B70[i]++;
            if (D_80228B70[i] >= 3) {
                D_80228B68[i]++;
                D_80228B70[i] = 0;
                D_80228B68[i] &= 3;
            }
            if (rider->lapCount < D_801CE728[0]) {
                if (gPlayers == ONE_PLAYER) {
                    x = 116;
                    y = 70;
                    w = 60;
                    scale = big;
                } else {
                    x = 125;
                    w = 48;
                    scale = 1.0f;
                    if (i == 0) {
                        y = 40;
                    } else {
                        y = 150;
                    }
                }
                gdl = Printer_PrintScaled(gdl, 0, D_802279F8, x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1, g1, b1, scale);
                sprintf((char*) D_80228CF8, D_802279FC, rider->lapCount);
                gdl = Printer_DrawString(gdl, 0, (char*) D_80228CF8, x + w, y);
            } else {
                x = 100;
                if (gPlayers == ONE_PLAYER) {
                    x = 82;
                    y = 70;
                    w = 98;
                    scale = big;
                } else {
                    scale = 1.0f;
                    w = 77;
                    if (i == 0) {
                        y = 40;
                    } else {
                        y = 150;
                    }
                }
                gdl = Printer_DrawString(Printer_PrintScaled(gdl, 0, D_80227A00, x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1,
                                                  g1, b1, scale),
                                    0, D_80227A08, x + w, y);
            }
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/C94E0/func_801FAEB8.s")
#endif

void func_801FB488(s32 arg0, s32 arg1, s32 arg2) {
    UnkStruct_80228AE0* var_v1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_80228AE0[i].unk0 == 0) {
            break;
        }
    }

    if (i >= 4) {
        i = 0;
    }

    D_80228AE0[i].unk0 = arg0;
    D_80228AE0[i].unk4 = arg1;
    D_80228AE0[i].unk10 = 0;
    D_80228AE0[i].unkC = 0;
    D_80228AE0[i].unk8 = 0;
    D_80228AE0[i].unk14 = -8;
    if (arg2 == 0) {
        D_80228AE0[i].unk18 = 0;
    } else {
        D_80228AE0[i].unk18 = -0x20;
    }
    D_80228D14 = D_80228D18 = 0;
}

#ifdef NON_MATCHING
// Score 10384: the original keeps the unused (2 - D_80228D18) / 2.0f and 1.0f - f (IDO deletes them here), so every temp after the prologue is renumbered.
extern u8 D_80246D0[];
extern u8 D_8024858[];
extern u8 D_8024A40[];
extern u8 D_80269D0[];
extern s32 D_801C26E4;
extern char D_80227A0C[];
extern char D_80227A14[];
extern char D_80227A1C[];
extern s32 D_80228A94;

// Draw the stunt-score popups (D_80228AE0) and add them to the stunt totals as they finish.
void func_801FB514(Gfx** gdlp) {
    Gfx* gdl;
    UnkStruct_80228AE0* p;
    f32 f;
    f32 g;
    u8* img;
    s32 w;
    s32 x;
    s32 y;
    s32 alpha;
    s32 n;
    s32 count;
    s32 k;
    s8* digit;

    gdl = *gdlp;
    f = (2 - D_80228D18) / (f32) 2;
    g = 1.0f - f;
    D_80228D18++;
    if (D_80228D18 >= 2) {
        D_80228D14++;
        D_80228D18 = 0;
        D_80228D14 &= 3;
    }
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdl++, G_SHADE);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetTextureFilter(gdl++, G_TF_BILERP);
    gDPSetCombineMode(gdl++, G_CC_FADEA, G_CC_FADEA);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    for (p = D_80228AE0; p != &D_80228AE0[4]; p++) {
        if (p->unk0 == 0) {
            continue;
        }
        count = 0;
        if (p->unk8 < 4) {
            alpha = p->unk8 * 255 / 4;
        } else {
            alpha = 255;
            if (p->unk8 >= 20) {
                alpha = (23 - p->unk8) * 255 / 4;
            }
        }
        gDPPipeSync(gdl++);
        switch (p->unk0) {
            case 1:
                img = D_80246D0;
                w = 32;
                x = 144;
                gDPSetEnvColor(gdl++, 255, 133, 255, alpha);
                break;
            case 2:
                img = D_8024858;
                w = 40;
                x = 140;
                gDPSetEnvColor(gdl++, 100, 255, 100, alpha);
                break;
            case 3:
                img = D_8024A40;
                w = 32;
                x = 144;
                gDPSetEnvColor(gdl++, 255, 255, 128, alpha);
                break;
        }
        gDPLoadTextureBlock(gdl++, img, G_IM_FMT_IA, G_IM_SIZ_8b, w, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        y = p->unk10 + p->unk18 + 116;
        x += p->unkC;
        gSPTextureRectangle(gdl++, x << 2, y << 2, (x + w) << 2, (y + 12) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
        n = p->unk4;
        digit = &D_80228CF8[4];
        for (;;) {
            *digit = n % 10;
            n /= 10;
            if (n == 0) {
                break;
            }
            count++;
            digit--;
            if (count >= 5) {
                break;
            }
        }
        count++;
        if (count >= 6) {
            count = 5;
        }
        x = (304 - count * 14) / 2 + p->unkC + 8;
        y = p->unk10 + p->unk18 + 128;
        for (k = 0; k < count; k++) {
            gDPLoadTextureBlock(gdl++, &D_80269D0[D_80228CF8[5 - count + k] << 8], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                                1 << 10);
            x += 14;
        }
        p->unk10 += p->unk14;
        if (p->unk14 >= -8) {
            p->unk14++;
        }
        if (p->unk10 >= 0) {
            p->unk14 = -10;
            p->unk10 = 0;
        }
        if (p->unk14 == -10) {
            p->unkC -= 10;
        }
        p->unk8++;
        if (p->unk8 >= 23) {
            D_801C26D0 += p->unk4;
            if (D_801C26D0 >= 100000) {
                D_801C26D0 = 99999;
            }
            switch (p->unk0) {
                case 1:
                    D_801C26D4 += p->unk4;
                    if (D_801C26D4 >= 100000) {
                        D_801C26D4 = 99999;
                    }
                    break;
                case 2:
                    D_801C26DC += p->unk4;
                    if (D_801C26DC >= 100000) {
                        D_801C26DC = 99999;
                    }
                    break;
                case 3:
                    D_801C26D8 += p->unk4;
                    if (D_801C26D8 >= 100000) {
                        D_801C26D8 = 99999;
                    }
                    break;
            }
            p->unk0 = 0;
        }
    }
    if (D_80228A94 != 0) {
        D_80228A94--;
        gdl = Printer_Print(Printer_Print(gdl, 0, D_80227A0C, 80, 60, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 0,
                            D_80227A14, 153, 60, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    if ((D_80227740 != 0) && (D_801C26E4 != 0)) {
        sprintf((char*) D_80228CF8, D_80227A1C, D_801C26E4);
        gdl = Printer_Print(gdl, 0, (char*) D_80228CF8, 224, 188, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/C94E0/func_801FB514.s")
#endif

#ifdef NON_MATCHING
// Score 9598: the loop's register allocation and constant hoisting differ throughout; frame 0xD8, not 0xE0.
extern Gfx D_10146B0[];
extern f32 D_80227A58;
extern u32 D_804C008[];
extern u32 D_804F010[];
extern u32 D_8052018[];

void func_801FBFB4(Gfx** gdlp) {
    Gfx* gdl;
    s32 i;
    s32 j;
    s32 cx;
    s32 cy;
    s32 w;
    u32* tex;
    f32 scale;
    f32 width;
    f32 height;
    f32 x;
    f32 y;
    f32 nextY;
    f32 big;

    gdl = *gdlp;
    big = D_80227A58; // FAKE: a float literal in the original (its rodata is still in the F6010 data blob)
    gSPDisplayList(gdl++, D_10146B0);
    for (i = 0; i < 2; i++) {
        if (D_80228E00[i] == 0) {
            continue;
        }
        cx = 160;
        if (i == 0) {
            cy = 64;
        } else {
            cy = 174;
        }
        tex = D_804F010;
        w = 96;
        if (D_80228E08[i] < 6) {
            scale = (D_80228E08[i] / 5.0f) * big;
        } else {
            scale = 1.0f;
        }
        switch (D_80228E00[i]) {
            case 1:
                break;
            case 2:
                tex = D_804C008;
                w = 96;
                break;
            case 3:
            default:
                tex = D_8052018;
                w = 112;
                break;
        }
        height = 32.0f * scale;
        width = w * scale;
        y = cy - height * 0.5f;
        x = cx - width * 0.5f;
        for (j = 0; j < 4; j++) {
            nextY = y + height * 0.25f;
            gDPLoadTextureTile(gdl++, &tex[j * w * 8], G_IM_FMT_RGBA, G_IM_SIZ_32b, w, 8, 0, 0, w - 1, 7, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gdl++, (s32) (x * 4.0f), (s32) (y * 4.0f), (s32) ((x + width) * 4.0f),
                                (s32) (nextY * 4.0f), G_TX_RENDERTILE, 0, 0, (s32) ((w << 10) / width),
                                (s32) (32768.0f / height));
            y = nextY;
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/C94E0/func_801FBFB4.s")
#endif

void func_801FC39C(void) {
    Players player;

    if (D_80228AA4 == 1) {
        D_80228B50 += 0x1E;
        D_80228B54 -= 0x1E;
        if (D_80228B50 >= 0x140) {
            D_80228AA4 = 2;
        }
    }
    if (gGameModes == GMODE_2P_VS) {
        if (D_80228AA8 != 0) {
            if (D_80228AA8 == 1) {
                D_80228E00[0] = 1;
                D_80228E00[1] = 2;
            } else if (D_80228AA8 == 2) {
                D_80228E00[0] = 2;
                D_80228E00[1] = 1;
            } else {
                D_80228E00[0] = D_80228E00[1] = 3;
            }
            D_80228AA8 = 0;
            D_80228E08[0] = D_80228E08[1] = 0;
        }

        for (player = NO_PLAYERS; player < gPlayers; player++) {
            if (D_80228E00[player] != 0) {
                if (D_80228E08[player] < 0x7FFFFFFF) {
                    D_80228E08[player]++;
                }
            }
        }
    }
}

void func_801FC4D4(Gfx** arg0) {
    struct RiderStruct* temp_v0;
    s32 pad;
    Gfx* sp2C;

    sp2C = *arg0;
    if ((D_801CE638 == 1) || (D_801CE638 == 8)) {
        Hud_BlendColorSets();
        Hud_SetupMatrices();
        gSPViewport(sp2C++, &D_1014450);
        gDPPipeSync(sp2C++);

        if (gPlayers == ONE_PLAYER) {
            gDPSetScissor(sp2C++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
        } else {
            gDPSetScissor(sp2C++, G_SC_NON_INTERLACE, 8, 12, 311, 229);
        }
        if (D_801CE638 == 8) {
            D_801C2938[D_800D48DC].unk19C += 0x32;
            *arg0 = sp2C;
            return;
        }
        if (((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS)) && (gGameModeState == 3) &&
            (gCourseID != DOLPHIN_PARK) && (D_801C1FD8 == 0)) {
            func_801FA3C0(&sp2C);
        }
        if (((gGameModeState != 3) || (gStartLightsState == 2)) && (D_801C2938[D_800D48DC].unk2EC == 0) &&
            ((gPlayers != TWO_PLAYERS) || (D_801C2938[D_800D48E0].unk2EC == 0))) {
            Hud_DrawStartLights(&sp2C);
        }
        if ((D_801CE638 == 1) && (gCurrentPauseMenuOption == -1) && (gGameModeState == 3) &&
            ((gPlayers != TWO_PLAYERS) || (D_801CE6F0 == 0))) {
            Hud_DrawGuideArrow(&sp2C);
        }
        if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
            Hud_DrawMarkers(&sp2C);
        }
        if (gCurrentPauseMenuOption == -1) {
            func_801F2060(&sp2C);
            func_801FAEB8(&sp2C);
            if (gGameModes == GMODE_STUNT) {
                func_801FB514(&sp2C);
            }
        }
        func_801F4120(&sp2C);

        if (((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS)) && (gCourseID != DOLPHIN_PARK)) {
            func_801F9520(&sp2C);
        }
        if (gGameModes == GMODE_2P_VS) {
            func_801FBFB4(&sp2C);
        }
        if ((gPlayers == ONE_PLAYER) && (D_80227740 != 0)) {
            func_801FAEB0(&sp2C);
        }
        *arg0 = sp2C;
    }
}
