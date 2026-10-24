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
extern s32 D_80228D08;
extern s32 D_80227740;
extern s32 D_80228AA8;
extern s32 D_80228B50;
extern s32 D_80228B54;
extern s32 D_80228E00[];
extern s32 D_80228E08[];
extern UnkStruct_80228AE0 D_80228AE0[];
extern s32 D_80228D14;
extern s32 D_80228D18;

void func_801EE9C0(void);
void func_801EF3C4(void);
void func_801EFFD8(Gfx**);
void func_801F06A0(Gfx**);
void func_801F14B4(Gfx**);
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
// Score 3409: f and g swap float registers, and the colour bytes convert and mask in a different order.
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
extern char D_80228CF8[];

// Flash "LAP n" (or the final-lap message) for each player when a lap starts.
void func_801FAEB8(Gfx** gdlp) {
    Gfx* gdl;
    RiderStruct* rider;
    s32 i;
    f32 f;
    f32 g;
    u8(*c)[3];
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
            c = &D_80227744[D_80228B68[i]];
            r0 = c[0][0] * f + c[1][0] * g;
            g0 = c[0][1] * f + c[1][1] * g;
            b0 = c[0][2] * f + c[1][2] * g;
            c = &D_80227754[D_80228B68[i]];
            r1 = c[0][0] * f + c[1][0] * g;
            g1 = c[0][1] * f + c[1][1] * g;
            b1 = c[0][2] * f + c[1][2] * g;
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
                gdl = func_801E93B4(gdl, 0, D_802279F8, x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1, g1, b1, scale);
                sprintf(D_80228CF8, D_802279FC, rider->lapCount);
                gdl = func_801E9858(gdl, 0, D_80228CF8, x + w, y);
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
                gdl = func_801E9858(func_801E93B4(gdl, 0, D_80227A00, x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1,
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/C94E0/func_801FB514.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/C94E0/func_801FBFB4.s")

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
        func_801EE9C0();
        func_801EF3C4();
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
        if (((gGameModeState != 3) || (D_80228D08 == 2)) && (D_801C2938[D_800D48DC].unk2EC == 0) &&
            ((gPlayers != TWO_PLAYERS) || (D_801C2938[D_800D48E0].unk2EC == 0))) {
            func_801F06A0(&sp2C);
        }
        if ((D_801CE638 == 1) && (gCurrentPauseMenuOption == -1) && (gGameModeState == 3) &&
            ((gPlayers != TWO_PLAYERS) || (D_801CE6F0 == 0))) {
            func_801EFFD8(&sp2C);
        }
        if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
            func_801F14B4(&sp2C);
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
