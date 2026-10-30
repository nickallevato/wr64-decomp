#include "common.h"

typedef struct UnkStruct_80228C30_sub {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} UnkStruct_80228C30_sub; /* size = 0x1C */

typedef struct UnkStruct_80228C30 {
    /* 0x00 */ UnkStruct_80228C30_sub unk0[3];
} UnkStruct_80228C30; /* size = 0x54 */

typedef struct PortraitPos {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 unk8; /* target x */
    /* 0x0C */ s32 unkC; /* target y */
    /* 0x10 */ s32 bobPhase; /* index into gPortraitBob (& 7) */
} PortraitPos; /* size = 0x14 */

typedef struct UnkStruct_80228B88 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} UnkStruct_80228B88; /* size = 0x14 */

void func_801F25E0(Gfx** gdlp, s32 x, s32 y, s32 time, s32 style, s32 arg5, s32 color);

// This file's .bss, the end of codeseg's: 0x80228A90..0x80228E0F (yaml split). Sizes run to the next variable.
// In-object addresses the code names are in resolve.txt: D_80228AFC, D_80228B18 and D_80228B34 (D_80228AE0[1..3]),
// D_80228CE0, D_80228CE8, D_80228CEC and D_80228CF0 (D_80228CD8 + 8, + 0x10, + 0x14 and the end of its six digits),
// D_80228CF7, D_80228CFC and D_80228CFD (D_80228CF8 - 1, + 4 and + 5: the number buffer's digit loops).
s32 gStartCountdown;
s32 D_80228A94;
s32 D_80228A98;
s32 D_80228A9C;
s32 D_80228AA0;
s32 D_80228AA4;
s32 D_80228AA8;
s32 D_80228AAC;
s32 D_80228AB0;
s32 D_80228AB4;
s32 D_80228AB8;
s32 D_80228ABC;
s32 D_80228AC0;
s32 D_80228AC4;
s32 D_80228AC8;
s32 D_80228ACC;
s32 D_80228AD0;
s32 D_80228AD4;
s32 D_80228AD8;
s32 D_80228ADC; // FAKE pad: no code names 0x80228ADC (splat sized D_80228AD8 0x8); keeps D_80228AE0 at its address
UnkStruct_80228AE0 D_80228AE0[4];
s32 D_80228B50;
s32 D_80228B54;
s8 D_80228B58[4];
s32 D_80228B5C;
s32 D_80228B60[2];
s32 D_80228B68[2];
s32 D_80228B70[2];
s32 D_80228B78;
s32 D_80228B7C;
s32 D_80228B80;
s32 D_80228B84; // FAKE pad: no code names 0x80228B84 (splat sized D_80228B80 0x8); keeps D_80228B88 at its address
UnkStruct_80228B88 D_80228B88[2][4];
s32 gHudMarkerColorFrame;
s32 gHudMarkerColorStep;
UnkStruct_80228C30 gHudMarkers[2];
s32 D_80228CD8[8];
s8 D_80228CF8[16];
s32 gStartLightsState;
s32 gStartLightsOffset;
s32 gStartLightsOffsetMax;
s32 D_80228D14;
s32 D_80228D18;
s32 gHudColorStep;
s32 gHudColorFrame;
u16 gHudPerspNorm;
PortraitPos gPortraitPos[2][4];
s32 D_80228DC8[4];
s32 D_80228DD8[4];
s32 D_80228DE8[4];
s32 D_80228DF8;
s32 D_80228DFC;
s32 D_80228E00[2];
s32 D_80228E08[2];


extern Gfx D_1014708[];
extern Gfx D_1014760[];
extern Gfx D_1014790[];
extern u8 D_102DF50[];
extern u8 D_102E3D8[];
extern u8 D_102E620[];
extern u8 D_102E868[];
extern u32 D_102EE70[];
extern u8 D_1032078[];
extern u8 D_1032500[];
extern u8 D_1032B08[];
extern u8 D_10331D0[];
extern u8 D_10337D8[];
extern u8 D_1033C60[];
extern u8 D_10387C0[];
extern u8 D_1039248[];
extern u8 D_103B4D0[];
extern u8 D_103D5D0[];
extern u8 D_103D8D8[];
extern u8 D_1040FE0[];
extern u8 D_10416A8[];
extern u8 D_1041BB0[];
extern u8 D_10420B8[];
extern u8 D_1042780[];
extern u8 D_8024008[];
extern u8 D_8024BC8[];
extern u8 D_80273D8[];
extern u8 D_802A5E0[];
extern u8 D_802C3E8[];
extern s32 D_800D4B00;
extern s32 D_801C1FDC;
extern s32 D_801C1FE4;
extern s32 D_801C1FE8;
extern RiderStruct gRiderRaceState[];
extern u8* gPortraitFaces[];
extern f32 gPortraitBob[];

// The asm names this word D_801CE6FC + 8; its symbol is in linker_scripts/us/rev1/resolve.txt.
extern s32 D_801CE704;

// Draw a 16x20 (1P) or 12x16 (2P) RGBA32 digit image at (x, y).
#define HUD_DIGIT(gdl, img, w, h, x, y)                                                                         \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP,         \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);         \
    gSPTextureRectangle(gdl++, (x) << 2, (y) << 2, ((x) + (w)) << 2, ((y) + (h)) << 2, G_TX_RENDERTILE, 0, 0, \
                        1 << 10, 1 << 10)

#define HUD_LOAD32(gdl, img, w, h)                                                                      \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_32b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP, \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD)

#define HUD_RECT(gdl, x, y, w, h) \
    gSPTextureRectangle(gdl++, (x) << 2, (y) << 2, ((x) + (w)) << 2, ((y) + (h)) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10)

#define HUD_SCISRECT(gdl, x, y, w, h)                                                                            \
    gSPScisTextureRectangle(gdl++, ((x) << 2), ((y) << 2), (((x) + (w)) << 2), (((y) + (h)) << 2), G_TX_RENDERTILE, 0, \
                            0, 1 << 10, 1 << 10)

extern s32 D_801C1FD8;
extern s32 D_80227888[][3];
extern s32 D_802278C4[][3];
extern s32 D_80227900[][3];
extern s32 D_8022793C[][3];

// Blend the HUD colour sets between the current palette step and the next (two frames a step while unpaused).
void Hud_BlendColorSets(void) {
    f32 f;
    f32 g;
    s32 idx;

    f = (2 - gHudColorFrame) / (f32) 2;
    g = 1.0f - f;
    D_80228AAC = D_80227888[gHudColorStep][0] * f + D_80227888[gHudColorStep + 1][0] * g;
    D_80228AB0 = D_80227888[gHudColorStep][1] * f + D_80227888[gHudColorStep + 1][1] * g;
    D_80228AB4 = D_80227888[gHudColorStep][2] * f + D_80227888[gHudColorStep + 1][2] * g;
    D_80228AB8 = D_802278C4[gHudColorStep][0] * f + D_802278C4[gHudColorStep + 1][0] * g;
    D_80228ABC = D_802278C4[gHudColorStep][1] * f + D_802278C4[gHudColorStep + 1][1] * g;
    D_80228AC0 = D_802278C4[gHudColorStep][2] * f + D_802278C4[gHudColorStep + 1][2] * g;
    if (D_801C1FD8 != 0) {
        g = 0.0f;
        idx = 0;
        f = 1.0f;
    } else {
        idx = gHudColorStep;
    }
    D_80228AC4 = D_80227900[idx][0] * f + D_80227900[idx + 1][0] * g;
    D_80228AC8 = D_80227900[idx][1] * f + D_80227900[idx + 1][1] * g;
    D_80228ACC = D_80227900[idx][2] * f + D_80227900[idx + 1][2] * g;
    D_80228AD0 = D_8022793C[idx][0] * f + D_8022793C[idx + 1][0] * g;
    D_80228AD4 = D_8022793C[idx][1] * f + D_8022793C[idx + 1][1] * g;
    D_80228AD8 = D_8022793C[idx][2] * f + D_8022793C[idx + 1][2] * g;
    if (gCurrentPauseMenuOption == -1) {
        gHudColorFrame++;
        if (gHudColorFrame >= 2) {
            gHudColorStep++;
            gHudColorFrame = 0;
            gHudColorStep &= 3;
        }
    }
}

// HUD_Init
#ifdef NON_MATCHING
// Score 7041 of 40500: the zeroing runs are chained assignments (stored last to first), which keeps the globals'
// addresses in registers as in the original; the Vtx copy pointers are set up in the order found by a move search.
// Left: the original stores before incrementing in the Vtx copy loop and rebuilds the 0xB240.. offsets inside it,
// keeps gCourseID in a3 and spills it (frame 0x40, not 0x28, here s2), and B50/B54 at the top also go through
// registers there.
extern UnkStruct_801AE948 D_80198368[];
extern Vtx D_80227788[4][4];
extern s32 D_80227998;
extern s32 D_80228A94;
extern s32 D_80228A98;
extern s32 D_80228AA0;
extern s32 D_80228AA4;
extern s32 D_80228AA8;
extern s8 D_80228B58[];
extern s32 D_80228B5C;
extern UnkStruct_80228AE0 D_80228AE0[4];
extern s32 D_80228B60[2];
extern s32 D_80228B68[2];
extern s32 D_80228B70[2];
extern s32 D_80228B78;
extern s32 D_80228B7C;
extern s32 D_80228B80;
extern s32 gHudMarkerColorFrame;
extern s32 gHudMarkerColorStep;
extern s32 gStartLightsState;
extern s32 gStartLightsOffset;
extern s32 gStartLightsOffsetMax;
extern s32 gHudColorStep;
extern s32 gHudColorFrame;
extern s32 D_80228DD8[4];
extern s32 D_80228DE8[4];
extern s32 D_80228DFC;
extern s32 D_80228E00[2];

void Hud_BlendColorSets(void);

void func_801EED70(void) {
    s32 i;
    s32 j;
    s8 flag;
    UnkStruct_801AE948* gfxPool;
    Vtx* d0;
    Vtx* d1;
    Vtx* d2;
    Vtx* d3;
    Vtx* s0;
    Vtx* s1;
    Vtx* s2;
    Vtx* s3;

    if (D_80227998 != 0) {
        D_80227998 = 0;
    }
    Hud_BlendColorSets();
    D_80228B54 = D_80228B50 = 0;
    D_80228AA4 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gHudMarkers[i].unk0[j].unk14 = 0;
            gHudMarkers[i].unk0[j].unk18 = 0;
            gHudMarkers[i].unk0[j].unkC = 0.0f;
            gHudMarkers[i].unk0[j].unk8 = 0.0f;
            gHudMarkers[i].unk0[j].unk4 = 0.0f;
            gHudMarkers[i].unk0[j].unk0 = 0.0f;
        }
    }
    for (gfxPool = D_80198368; gfxPool < &D_80198368[2]; gfxPool++) {
        d1 = gfxPool->unkB1C0;
        d0 = gfxPool->unkB240;
        s2 = D_80227788[2];
        s3 = D_80227788[3];
        d2 = gfxPool->unkB200;
        d3 = gfxPool->unkB280;
        s0 = D_80227788[0];
        s1 = D_80227788[1];
        do {
            *d0++ = *s0++;
            *d1++ = *s1++;
            *d2++ = *s2++;
            *d3++ = *s3++;
        } while (s3 < D_80227788[4]);
    }
    gStartLightsState = 0;
    gStartCountdown = 60;
    if ((gCourseID == DOLPHIN_PARK) || (gGameModes == GMODE_STUNT)) {
        flag = 1;
    } else {
        flag = 0;
    }
    for (i = 0; i < gRiders; i++) {
        D_80228B58[i] = flag;
    }
    if (gPlayers == ONE_PLAYER) {
        gStartLightsOffsetMax = 100;
    } else {
        gStartLightsOffsetMax = 50;
    }
    if ((gGameModes == GMODE_TIME_TRIALS) || (gGameModes == GMODE_STUNT)) {
        gStartLightsOffset = 0;
    } else {
        gStartLightsOffset = gStartLightsOffsetMax;
    }
    gHudColorStep = gHudMarkerColorStep = gHudMarkerColorFrame = gHudColorFrame = 0;
    D_80228A98 = D_80228B78 = D_80228B7C = D_80228B80 = 0;
    for (i = 0; i < 2; i++) {
        D_80228B70[i] = 0;
        D_80228B68[i] = 0;
        D_80228B60[i] = 0;
    }
    D_80228AA0 = 0;
    for (i = 0; i < gPlayers; i++) {
        for (j = 0; j < gRiders; j++) {
            gPortraitPos[i][j].unkC = gRiderRaceState[j].racePosition * 24;
        }
        for (j = 0; j < gRiders; j++) {
            if (gPlayers == ONE_PLAYER) {
                if (gRiderRaceState[gPlayer1Rider].racePosition < gRiderRaceState[j].racePosition) {
                    gPortraitPos[i][j].unkC += 4;
                }
            } else if (i == 0) {
                if (gRiderRaceState[gPlayer1Rider].racePosition < gRiderRaceState[j].racePosition) {
                    gPortraitPos[i][j].unkC += 4;
                }
            } else if (gRiderRaceState[gPlayer2Rider].racePosition < gRiderRaceState[j].racePosition) {
                gPortraitPos[i][j].unkC += 4;
            }
        }
        for (j = 0; j < gRiders; j++) {
            gPortraitPos[i][j].bobPhase = 0;
            gPortraitPos[i][j].unk8 = 0;
            gPortraitPos[i][j].x = 0;
            gPortraitPos[i][j].y = gPortraitPos[i][j].unkC;
        }
    }
    for (i = 0; i < 4; i++) {
        D_80228DD8[i] = 0;
        D_80228DC8[i] = 0;
        D_80228DE8[i] = 1;
    }
    D_80228AE0[0].unk0 = 0;
    D_80228AE0[1].unk0 = 0;
    D_80228AE0[2].unk0 = 0;
    D_80228AE0[3].unk0 = 0;
    D_80228A9C = 0;
    D_80228A94 = 0;
    D_80228DFC = 0;
    D_80228DF8 = 0;
    for (i = 0; i < gPlayers; i++) {
        for (j = 0; j < gRiders; j++) {
            D_80228B88[i][j].unkC = 0;
            D_80228B88[i][j].unk10 = 0;
            D_80228B88[i][j].unk8 = 0.0f;
            D_80228B88[i][j].unk4 = 0.0f;
            D_80228B88[i][j].unk0 = 0.0f;
        }
    }
    if ((gGameModes != GMODE_STUNT) && (gCourseID == DOLPHIN_PARK)) {
        D_80228B5C = 219;
    } else {
        D_80228B5C = 119;
    }
    D_80228AA8 = 0;
    for (i = 0; i < 2; i++) {
        D_80228E00[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EED70.s")
#endif

// Set up the HUD projection matrices in the current Gfx pool.

void Hud_SetupMatrices(void) {
    MtxF sp40;

    func_800481E0(&D_801AE948->unk4080, &gHudPerspNorm, 24.0f, 1.3333334f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_800484C8(&D_801AE948->unk40C0, &sp40, 0.0f, 512.0f, 1500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    guOrtho(&D_801AE948->unk4000, -160.0f, 160.0f, -120.0f, 120.0f, -1024.0f, 1024.0f, 1.0f);
    guOrtho(&D_801AE948->unk4040, 0.0f, 320.0f, 240.0f, 0.0f, -1024.0f, 1024.0f, 1.0f);
}

// Per-frame update of the guide arrow
#ifdef NON_MATCHING
// Score 7828 of 69300: calls, branches and the frame agree. The two waypoint tests compute dx/dz first, as the
// original's operand order shows. The stunt-object search is a do-while guarded by D_801BFA40 > 0 that skips other
// kinds with a goto to the increment (the original's skip path jumps to the loop test). Left: &D_801AEE20 is hoisted
// into s8 here (the original rebuilds it at each use), so the saved registers shift; and IDO folds
// `dirX * dz - dirZ * dx > 0.0f` into one compare here where the original keeps the sub.s and compares with 0.0f.
extern s32 D_80223934;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;

f32 func_801ED090(f32 arg0);
s32 func_801ED388(s32 arg0, s32 arg1);
s32 func_801ED4E0(s32 arg0, s32 arg1);

void func_801EF504(void) {
    s32 i;
    camera_unk_1* cam;
    UnkStruct_80192690* p;
    RiderStruct* rider;
    UnkStruct_801AEE20* node;
    UnkStruct_801BC940* obj;
    s32 show;
    s32 found;
    f32 dirX;
    f32 dirZ;
    f32 dx;
    f32 dz;
    f32 fwd;
    f32 cross;
    s32 angle;
    s32 diff;
    s32 step;
    f32 dist;
    f32 dot;

    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            cam = &gCameraPerspective[D_80223930];
            p = &D_80192690[gPlayer1Rider];
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            cam = &gCameraPerspective[D_80223934];
            p = &D_80192690[gPlayer2Rider];
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        dirX = cam->unk64;
        dirZ = cam->unk6C;
        dist = sqrtf(dirX * dirX + dirZ * dirZ);
        if (dist > 0.0f) {
            dirX /= dist;
            dirZ /= dist;
        }
        if (rider->unk2F0 != 0) {
            node = &D_801AEE20[rider->unkC];
        } else if ((rider->unkC == rider->nearestRecord) && (rider->lapCount == rider->unk320)) {
            node = &D_801AEE20[rider->unkC];
            dx = p->unk44.x - node->unk0;
            dz = p->unk44.z - node->unk8;
            if (dx * node->unk70 + dz * node->unk74 > 0.0f) {
                node = &D_801AEE20[node->unkA0];
            }
        } else {
            node = &D_801AEE20[rider->nearestRecord];
            dx = p->unk44.x - node->unk0;
            dz = p->unk44.z - node->unk8;
            if (dx * node->unk70 + dz * node->unk74 > -256.0f) {
                node = &D_801AEE20[node->unkA0];
            }
        }
        dx = node->unk0 - cam->eyeX;
        dz = node->unk8 - cam->eyeZ;
        dist = sqrtf(dx * dx + dz * dz);
        if (dist > 0.0f) {
            dx /= dist;
            dz /= dist;
        }
        if ((node->unk9C == 0) && (rider->unk2DC == 0)) {
            dot = node->unk70 * dirX + node->unk74 * dirZ;
            cross = node->unk70 * dz - node->unk74 * dx;
            if (((node->unk98 == 0) && (cross > 0.0f)) || ((node->unk98 == 1) && (cross < 0.0f)) || (dot < 0.0f)) {
                show = 0;
            } else {
                show = 1;
            }
        } else {
            show = 0;
        }
        fwd = dirX * dx + dirZ * dz;
        dot = fwd;
        angle = func_801ED090(fwd);
        rider->unk2D4 = angle;
        cross = dirX * dz - dirZ * dx;
        if (cross > 0.0f) {
            rider->unk2D4 = 360 - angle;
        }
        diff = func_801ED388(rider->unk2D4, rider->unk2D0);
        step = diff / 8;
        if (step < 2) {
            step = 2;
        }
        if (step >= diff) {
            rider->unk2D0 = rider->unk2D4;
        } else {
            rider->unk2D0 += func_801ED4E0(rider->unk2D4, rider->unk2D0) * step;
        }
        if ((fwd < 0.7f) && (node->unk9C == 1)) {
            dx = node->unkC - cam->eyeX;
            dz = node->unk14 - cam->eyeZ;
            dist = sqrtf(dx * dx + dz * dz);
            if (dist > 0.0f) {
                dx /= dist;
                dz /= dist;
            }
            cross = dirX * dz - dirZ * dx;
            dot = dirX * dx + dirZ * dz;
            if (dot < 0.7f) {
                dx = node->unk18 - cam->eyeX;
                dz = node->unk20 - cam->eyeZ;
                dist = sqrtf(dx * dx + dz * dz);
                if (dist > 0.0f) {
                    dx /= dist;
                    dz /= dist;
                }
                if ((cross < 0.0f) && (dirX * dz - dirZ * dx > 0.0f)) {
                    dot = 1.0f;
                } else {
                    dot = dirX * dx + dirZ * dz;
                }
            }
        }
        show = (dot < 0.7f) && ((dist > 2048.0f) || !show);
        if (rider->inBox != 0) {
            show = 0;
        }
        if (func_80074448(cam->eyeX, cam->eyeZ) != 0) {
            show = 0;
        }
        if (gGameModes == GMODE_STUNT) {
            found = 0;
            obj = D_801BC940;
            if (D_801BFA40 > 0) {
                do {
                    if (obj->unk4C != 8) {
                        goto next; // goto: skips to the increment, as the original's skip path does
                    }
                    dx = obj->unk0 - cam->eyeX;
                    dz = obj->unk8 - cam->eyeZ;
                    dist = sqrtf(dx * dx + dz * dz);
                    if (dist > 0.0f) {
                        dx /= dist;
                        dz /= dist;
                    }
                    if ((0.7f <= dirX * dx + dirZ * dz) && (dist < 4096.0f)) {
                        found = 1;
                        break;
                    }
                next:
                    obj++;
                } while (obj < &D_801BC940[D_801BFA40]);
            }
            if (found) {
                show = 0;
            }
        }
        if ((rider->unk2F0 != 0) || (rider->unk2E4 != 0) || (rider->unk328 >= 40)) {
            show = 1;
        }
        if ((gGameModes != GMODE_STUNT) && (gCourseID == DOLPHIN_PARK)) {
            show = 0;
        }
        if (show && (D_800DAB68 != 0) && (gCourseID == MARINE_FORTRESS) && (rider->lapCount >= 2)) {
            dx = p->unk44.x - (-2500.0f);
            dz = p->unk44.z - 2800.0f;
            if (dx * dx + dz * dz < 490000.0f) {
                show = 0;
            }
        }
        if (show) {
            if (rider->unk2D8 < 0x7FFFFFFF) {
                rider->unk2D8++;
            }
        } else {
            rider->unk2D8 = 0;
        }
        if ((rider->unk2D8 >= 8) || (rider->unk2E0 >= 2)) {
            if (rider->unk2E0 == 0) {
                rider->unk2E0 = 8;
            }
            if (rider->unk2DC < 4) {
                rider->unk2DC++;
            }
            if (rider->unk2E0 >= 2) {
                rider->unk2E0--;
            }
        } else if (rider->unk2E0 == 0) {
            if (rider->unk2DC > 0) {
                rider->unk2DC--;
            }
        } else {
            rider->unk2E0--;
        }
        dirX = p->unk6C;
        dirZ = p->unk74;
        dist = sqrtf(dirX * dirX + dirZ * dirZ);
        if (dist > 0.0f) {
            dirX /= dist;
            dirZ /= dist;
        }
        dx = node->unk0 - p->unk44.x;
        dz = node->unk8 - p->unk44.z;
        dist = sqrtf(dx * dx + dz * dz);
        if (dist > 0.0f) {
            dx /= dist;
            dz /= dist;
        }
        if ((func_801ED090(dirX * dx + dirZ * dz) >= 100.0f) && (p->unkB90 * 1.8f >= 10.0f) &&
            (func_80074448(p->unk44.x, p->unk44.z) == 0) && (gCourseID != DOLPHIN_PARK)) {
            if (rider->unk328 < 0x7FFFFFFF) {
                rider->unk328++;
            }
        } else {
            rider->unk328 = 0;
        }
        if ((rider->unk328 >= 40) && ((rider->unk328 % 20) == 0) && (gGameModeState == GMODE_STATE_STARTED)) {
            AudioGeneral_PlaySound(0x35, i);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801EF504.s")
#endif

// Draw the guide arrow (next-buoy compass) for each player.
extern Gfx D_1010528[];
extern Vp D_1014450;
extern Vp D_1014460;
extern Vp D_1014470;
extern Vp D_1014480;
extern Gfx D_1014618[];
extern Mtx D_300E008;
extern Mtx D_300E088;
extern s32 D_801AE950;

void func_801EE228(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

void Hud_DrawGuideArrow(Gfx** gdlp) {
    Gfx* gdl;
    RiderStruct* rider;
    s32 i;
    s32 alpha;

    gdl = *gdlp;
    gSPDisplayList(gdl++, D_1014618);
    gSPPerspNormalize(gdl++, gHudPerspNorm);
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        alpha = rider->unk2DC * 255 / 4;
        if ((alpha > 0) && (rider->unk2F4 == 0) && (rider->finishState == 0)) {
            if (gPlayers == ONE_PLAYER) {
                gSPViewport(gdl++, &D_1014460);
            } else if (i == 0) {
                gSPViewport(gdl++, &D_1014470);
            } else {
                gSPViewport(gdl++, &D_1014480);
            }
            gDPPipeSync(gdl++);
            if ((rider->unk328 >= 40) && ((rider->unk328 % 20) == 0)) {
                gDPSetCombineMode(gdl++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
            } else {
                gDPSetCombineLERP(gdl++, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE);
            }
            func_801EE228(&D_801AE948->unk4140[D_801AE950], rider->unk2D0, 0.0f, 1.0f, 0.0f);
            gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            gDPPipeSync(gdl++);
            gDPSetPrimColor(gdl++, 0, 0, 255, 150, 150, alpha);
            if (alpha < 255) {
                gDPSetRenderMode(gdl++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
            } else {
                gDPSetRenderMode(gdl++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
            }
            gSPDisplayList(gdl++, D_1010528);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
    }
    gSPViewport(gdl++, &D_1014450);
    gSPMatrix(gdl++, &D_300E008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_300E088, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
    *gdlp = gdl;
}

extern s32 D_800D817C;
extern s8 D_80228B58[];
extern s32 gStartLightsState;
extern s32 gStartLightsOffset;
extern s32 gStartLightsOffsetMax;

void Hud_UpdateStartCountdown(void) {
    s32 d;
    s32 i;

    if ((gGameModeState == GMODE_STATE_1) || (gGameModeState == GMODE_STATE_2)) {
        if (gStartLightsState == 0) {
            gStartLightsOffset -= 3;
            if (gStartLightsOffset <= 0) {
                gStartLightsOffset = 0;
                gStartLightsState = 1;
            }
        } else {
            if ((gStartCountdown % 15) == 0) {
                if (gGameModeState != GMODE_STATE_2) {
                    AudioGeneral_PlaySound(0x22, (gStartCountdown / 15) - 1);
                } else {
                    AudioGeneral_PlaySound(0x23, 0);
                }
            }
            d = gStartCountdown - 15;
            if (d < 0) {
                d = -d;
            }
            if (d < 15) {
                for (i = 0; i < gRiders; i++) {
                    if ((D_80192690[i].unkB58 & 0xA000) && (D_80228B58[i] == 0)) {
                        if (d <= 0) {
                            gRiderRaceState[i].power = 5;
                        } else if (d < 2) {
                            gRiderRaceState[i].power = 4;
                        } else if (d < 3) {
                            gRiderRaceState[i].power = 3;
                        } else if (d < 4) {
                            gRiderRaceState[i].power = 2;
                        } else if (d < 5) {
                            gRiderRaceState[i].power = 1;
                        }
                        if (d < 5) {
                            gRiderRaceState[i].unk314 = 1;
                            gRiderRaceState[i].unk28 = 1;
                        }
                        D_80228B58[i] = 1;
                    }
                }
            }
            gStartCountdown--;
            if (gStartCountdown == 15) {
                gGameModeState = GMODE_STATE_2;
                D_800D817C = 0;
            } else if (gStartCountdown <= 0) {
                gGameModeState = GMODE_STATE_STARTED;
                gStartLightsState = 2;
            }
        }
    } else if ((gStartLightsState == 2) && (gCurrentPauseMenuOption == -1)) {
        gStartLightsOffset += 6;
        if (gStartLightsOffset >= gStartLightsOffsetMax) {
            gStartLightsState = 0;
        }
    }
}

extern Gfx D_10106C0[];
extern Gfx D_1010730[];
extern Gfx D_1010998[];
extern Gfx D_10109F8[];
extern u8 D_10123A8[];
extern u8 D_1012BA8[];
extern u8 D_10133A8[];
extern u8 D_1013BA8[];
extern Vp D_1014490;
extern Vp D_10144A0;
extern Vp D_10144B0;
extern Gfx D_1014658[];

void func_801EDFFC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3);

#define LIGHT_TEX(gdl, img)                                                                                    \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,       \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD)

// Draw the start lights: three red lamps lit one by one as the countdown runs, then the green one.
void Hud_DrawStartLights(Gfx** gdlp) {
    s32 i;
    f32 angle;
    s32 n;
    u8* lamp1;
    u8* lamp2;
    u8* lamp3;
    u8* go;
    Gfx* gdl;
    MtxF mf;

    n = (gStartCountdown - 1) / 15;
    gdl = *gdlp;
    if (n < 0) {
        n = 0;
    }
    if (gStartLightsState == 0) {
        n = 4;
    }
    if ((n > 0) && (n < 4)) {
        lamp1 = D_1013BA8;
    } else {
        lamp1 = D_10133A8;
    }
    if ((n > 0) && (n < 3)) {
        lamp2 = D_1013BA8;
    } else {
        lamp2 = D_10133A8;
    }
    if (n == 1) {
        lamp3 = D_1013BA8;
    } else {
        lamp3 = D_10133A8;
    }
    if (n == 0) {
        go = D_1012BA8;
    } else {
        go = D_10123A8;
    }
    gSPDisplayList(gdl++, D_1014658);
    func_800481E0(&D_801AE948->unk4140[D_801AE950], &gHudPerspNorm, 120.0f, 1.3333334f, 16.0f, 1024.0f, 0.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    func_800484C8(&D_801AE948->unk4140[D_801AE950], &mf, 0.0f, 0.0f, (gPlayers == TWO_PLAYERS) * 20.0f + 60.0f,
                  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPPerspNormalize(gdl++, gHudPerspNorm);
    func_801EDFFC(&D_801AE948->unk4140[D_801AE950], 0.0f, gStartLightsOffset, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    angle = (gStartLightsOffset / 100.0f) * 120.0f;
    if (gStartLightsState == 2) {
        angle = -angle;
    }
    func_801EE228(&D_801AE948->unk4140[D_801AE950], angle, 0.0f, 1.0f, 0.0f);
    gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    for (i = 0; i < gPlayers; i++) {
        if (gPlayers == ONE_PLAYER) {
            gSPViewport(gdl++, &D_1014490);
        } else if (i == 0) {
            gSPViewport(gdl++, &D_10144A0);
        } else {
            gDPPipeSync(gdl++);
            gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 122, 311, 229);
            gSPViewport(gdl++, &D_10144B0);
        }
        LIGHT_TEX(gdl, lamp1);
        gSPDisplayList(gdl++, D_10106C0);
        LIGHT_TEX(gdl, lamp2);
        gSPDisplayList(gdl++, D_1010730);
        LIGHT_TEX(gdl, lamp3);
        gSPDisplayList(gdl++, D_1010998);
        LIGHT_TEX(gdl, go);
        gSPDisplayList(gdl++, D_10109F8);
    }
    gSPViewport(gdl++, &D_1014450);
    if (gPlayers == TWO_PLAYERS) {
        gDPPipeSync(gdl++);
        gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 12, 311, 229);
    }
    gSPMatrix(gdl++, &D_300E008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_300E088, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gdl++, gCameraPerspective[D_80223930].perspNorm);
    *gdlp = gdl;
}

extern s32 gHudMarkerColorFrame;
extern s32 gHudMarkerColorStep;

void func_801F0E7C(void) {
    s32 i;
    s32 j;
    RiderStruct* rider;
    UnkStruct_80228C30* m;
    UnkStruct_80228C30_sub* e;
    s32 tx;
    s32 ty;
    s32 pad; // stack pad

    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        if ((rider->unk28 != 0) && (((m = &gHudMarkers[i])->unk0[0].unk18 == 0) || (rider->unk13C == 0))) {
            gHudMarkerColorFrame = 0;
            gHudMarkerColorStep = gHudMarkerColorFrame; // reading it back keeps its address in a register
            if ((rider->unk28 == 1) && ((rider->unk314 != 0) || (m->unk0[1].unk18 == 3))) {
                e = &m->unk0[2];
                if (m->unk0[1].unk18 == 3) {
                    m->unk0[1].unk18 = 0;
                    rider->power = 1;
                }
                gHudMarkers[i].unk0[2].unk18 = 2;
                if (gPlayers == ONE_PLAYER) {
                    e->unk10 = 1.0f;
                } else {
                    e->unk10 = 0.7f;
                }
                e->unk8 = e->unk10 * 64.0f;
                e->unkC = e->unk10 * 10.0f;
                if (gPlayers == ONE_PLAYER) {
                    if (1) {} // FAKE: without this block the stores schedule differently
                    e->unk0 = 300.0f;
                    e->unk4 = 206.0f;
                } else if (i == 0) {
                    e->unk0 = 300.0f;
                    e->unk4 = 105.0f;
                } else {
                    e->unk0 = 300.0f;
                    e->unk4 = 215.0f;
                }
                if (rider->power < 5) {
                    e->unk14 = 12;
                } else {
                    e->unk14 = 0;
                }
            } else if ((rider->unk28 == 2) && (gBuoyMisses >= rider->unk134)) {
                gHudMarkers[i].unk0[0].unk18 = 1;
                if (rider->power >= 5) {
                    gHudMarkers[i].unk0[2].unk18 = 0;
                }
                if (gPlayers == ONE_PLAYER) {
                    m->unk0[0].unk0 = 160.0f;
                    m->unk0[0].unk4 = 77.0f;
                    ty = 211;
                    tx = (gBuoyMisses - rider->unk134) * 14 + 62;
                } else if (i == 0) {
                    m->unk0[0].unk0 = 160.0f;
                    m->unk0[0].unk4 = 36.0f;
                    ty = 110;
                    tx = (gBuoyMisses - rider->unk134) * 14 + 30;
                } else {
                    m->unk0[0].unk0 = 160.0f;
                    m->unk0[0].unk4 = 146.0f;
                    ty = 220;
                    tx = (gBuoyMisses - rider->unk134) * 14 + 30;
                }
                m->unk0[0].unk14 = 16;
                m->unk0[0].unk8 = (tx - m->unk0[0].unk0) / 8;
                m->unk0[0].unkC = (ty - m->unk0[0].unk4) / 8;
                if ((rider->power > 0) && (m->unk0[1].unk18 != 3)) {
                    m->unk0[1].unk18 = 3;
                    e = &m->unk0[1];
                    tx = 198;
                    if (gPlayers == ONE_PLAYER) {
                        e->unk0 = 160.0f;
                        ty = 211;
                        e->unk4 = 121.0f;
                    } else if (i == 0) {
                        e->unk0 = 160.0f;
                        ty = 110;
                        e->unk4 = 78.0f;
                    } else {
                        e->unk0 = 160.0f;
                        ty = 220;
                        e->unk4 = 188.0f;
                    }
                    e->unk14 = 16;
                    e->unk10 = 1.0f;
                    e->unk8 = (tx - e->unk0) / 8;
                    e->unkC = (ty - e->unk4) / 8;
                }
            }
        }
        for (j = 0; j < 3; j++) {
            e = &gHudMarkers[i].unk0[j];
            if (e->unk18 == 0) {
                // nothing to update
            } else if (e->unk18 == 1) {
                if (e->unk14 < 9) {
                    e->unk0 += e->unk8;
                    e->unk4 += e->unkC;
                }
                e->unk10 = (e->unk14 + 0.5f) / 8.5f;
                if (e->unk10 > 1.0f) {
                    e->unk10 = 1.0f;
                }
                e->unk14--;
                if (e->unk14 < 0) {
                    e->unk18 = 0;
                    if (rider->unk13C != 0) {
                        Rider_SetFinishState((struct_800762D0*) rider);
                    }
                }
            } else if (e->unk18 == 3) {
                if (e->unk14 < 9) {
                    e->unk0 += e->unk8;
                    e->unk4 += e->unkC;
                }
                e->unk10 = (e->unk14 + 0.5f) / 8.5f;
                if (e->unk10 > 1.0f) {
                    e->unk10 = 1.0f;
                }
                e->unk14--;
                if (e->unk14 < 0) {
                    e->unk18 = 0;
                    rider->power = 0;
                }
            } else if (e->unk18 == 2) {
                if (rider->power < 5) {
                    e->unk14--;
                    if (e->unk14 < 0) {
                        e->unk18 = 0;
                    }
                } else {
                    if (e->unk14 < 255) {
                        e->unk14++;
                    }
                    if (e->unk14 >= 20) {
                        e->unk10 -= 0.08f;
                        if (e->unk10 < 0.7f) {
                            e->unk10 = 0.7f;
                        }
                    }
                }
            }
        }
    }
}

extern Gfx D_1014820[];
extern Gfx D_1014870[];
extern Gfx D_10148C0[];
extern Gfx D_1014910[];
extern u8 D_80227744[][3];
extern u8 D_80227754[][3];
extern u8 D_80227764[][3];
extern u8 D_80227774[][3];

// Draw the HUD markers of gHudMarkers (missed buoys, boosts), after cycling their vertex colours.
void Hud_DrawMarkers(Gfx** gdlp) {
    Gfx* gdl;
    s32 j;
    f32 f;
    s32 r0;
    s32 g0;
    s32 b0;
    s32 r1;
    s32 g1;
    s32 b1;
    f32 g;
    Vtx* vtx;
    u8(*top)[3];
    u8(*bottom)[3];
    UnkStruct_80228C30* m;      // unused; m and e keep the frame at 0xE8
    UnkStruct_80228C30_sub* e;  // unused
    RiderStruct* rider;
    s32 i;

    gdl = *gdlp;
    f = (2 - gHudMarkerColorFrame) / (f32) 2; // (f32) 2: with 2.0f IDO multiplies by 0.5f
    g = 1.0f - f;
    for (j = 0; j < 4; j++) {
        if (j == 0) {
            top = D_80227744;
            bottom = D_80227754;
            vtx = D_801AE948->unkB1C0;
        } else if (j == 1) {
            vtx = D_801AE948->unkB280;
        } else if (j == 2) {
            top = D_80227764;
            bottom = D_80227774;
            vtx = D_801AE948->unkB200;
        } else {
            vtx = D_801AE948->unkB240;
        }
        if ((j == 0) || (j == 2)) {
            r0 = top[gHudMarkerColorStep][0] * f;
            g0 = top[gHudMarkerColorStep][1] * f;
            b0 = top[gHudMarkerColorStep][2] * f;
            r0 += top[gHudMarkerColorStep + 1][0] * g;
            g0 += top[gHudMarkerColorStep + 1][1] * g;
            b0 += top[gHudMarkerColorStep + 1][2] * g;
            r1 = bottom[gHudMarkerColorStep][0] * f;
            g1 = bottom[gHudMarkerColorStep][1] * f;
            b1 = bottom[gHudMarkerColorStep][2] * f;
            r1 += bottom[gHudMarkerColorStep + 1][0] * g;
            g1 += bottom[gHudMarkerColorStep + 1][1] * g;
            b1 += bottom[gHudMarkerColorStep + 1][2] * g;
        }
        vtx[0].v.cn[0] = r0;
        vtx[0].v.cn[1] = g0;
        vtx[0].v.cn[2] = b0;
        vtx[1].v.cn[0] = r0;
        vtx[1].v.cn[1] = g0;
        vtx[1].v.cn[2] = b0;
        vtx[2].v.cn[0] = r1;
        vtx[2].v.cn[1] = g1;
        vtx[2].v.cn[2] = b1;
        vtx += 3; // the original steps to the last vertex rather than indexing it
        vtx->v.cn[0] = r1;
        vtx->v.cn[1] = g1;
        vtx->v.cn[2] = b1;
    }
    if (gCurrentPauseMenuOption == -1) {
        gHudMarkerColorFrame++;
        if (gHudMarkerColorFrame >= 2) {
            gHudMarkerColorFrame = 0;
            gHudMarkerColorStep++;
            gHudMarkerColorStep &= 3;
        }
    }
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK);
    gSPTexture(gdl++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gdl++, G_TP_PERSP);
    gDPSetTextureFilter(gdl++, G_TF_BILERP);
    gDPSetCombineMode(gdl++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gSPMatrix(gdl++, &D_5000000->unk4040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        for (j = 0; j < 3; j++) {
            if (gHudMarkers[i].unk0[j].unk18 != 0) {
                func_801EDFFC(&D_801AE948->unk4140[D_801AE950], gHudMarkers[i].unk0[j].unk0 + D_80228B54,
                              gHudMarkers[i].unk0[j].unk4, 0.0f);
                gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                func_801EE97C(&D_801AE948->unk4140[D_801AE950], gHudMarkers[i].unk0[j].unk10,
                              gHudMarkers[i].unk0[j].unk10, 1.0f);
                gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                switch (gHudMarkers[i].unk0[j].unk18) {
                    case 1:
                        gSPDisplayList(gdl++, D_1014820);
                        break;
                    case 2:
                        if (rider->power >= 5) {
                            gSPDisplayList(gdl++, D_1014910);
                        } else {
                            gSPDisplayList(gdl++, D_1014870);
                        }
                        break;
                    case 3:
                        gSPDisplayList(gdl++, D_10148C0);
                        break;
                }
            }
        }
    }
    *gdlp = gdl;
}

extern s32 D_80228B5C;

void Hud_UpdateOffCourseCountdown(void) {
    f32 x;
    f32 z;
    s32 blocked;
    RiderStruct* rider;
    UnkStruct_80192690* p;
    s32 i;
    s32 inZone;
    s32 show;
    s32 add;

    if ((gGameModes == GMODE_2P_VS) &&
        ((gRiderRaceState[gPlayer1Rider].unk2F4 != 0) || (gRiderRaceState[gPlayer1Rider].finishState != 0) ||
         (gRiderRaceState[gPlayer2Rider].unk2F4 != 0) || (gRiderRaceState[gPlayer2Rider].finishState != 0))) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            p = &D_80192690[gPlayer1Rider];
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            p = &D_80192690[gPlayer2Rider];
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        if ((rider->finishState != 0) || (rider->unk2F4 != 0)) {
            continue;
        }
        x = p->unk44.x;
        z = p->unk44.z;
        inZone = (gCourseID != SOUTHERN_ISLAND) && (p->unk16D0 > 80);
        show = (func_80074264(x, z) || inZone) && (blocked == 0) && (D_801CE72E != 0);
        if (rider->unk2E4 != 0) {
            if (!show) {
                rider->unk2E4 = 0;
            } else if ((p->unkC54 != 23) && (p->unkC54 != 7)) {
                if (rider->unk2E8 > 0) {
                    if (D_80228B5C >= rider->unk2E8) {
                        add = inZone ? 0x80 : 0;
                        if (rider->unk2E8 == D_80228B5C) {
                            AudioGeneral_PlaySound(10, rider->unk2E8 / 20 + add);
                        } else if ((rider->unk2E8 % 20) == 0) {
                            AudioGeneral_PlaySound(10, rider->unk2E8 / 20 + add - 1);
                        }
                    }
                    rider->unk2E8--;
                } else if (rider->unk2E8 == 0) {
                    Rider_SetFinishState((struct_800762D0*) rider);
                }
            }
        } else if (show) {
            rider->unk2E4 = 1;
            rider->unk2E8 = D_80228B5C + 20;
        }
    }
}

#ifdef NON_MATCHING
// Score 10 of 20800: only the lui before the gPlayer1Rider load differs (t8 here, v0 in the original); the loaded value is
// in v0 for both index products, as the original. The pointer to gPlayer1Rider and the copy t are FAKEs found by the
// permuter: they take the extra early temp the original spends. The s32 return type with no return statement (its caller,
// func_801FC4D4, ignores the result) keeps v0 live to the end, so the assembler moves the load into v0 instead of t8.

s32 func_801F2060(Gfx** gdlp) { // FAKE: s32 with no return, see the note above
    RiderStruct* rider;
    UnkStruct_80192690* p;
    s32 i;
    s32 y;
    s32 mode;
    s32 r0;
    s32 g0;
    s32 r1;
    s32 g1;
    s32 n;
    s32 x;
    s32 t; // with x it fills the 0x30 bytes of locals above gdl (a FAKE copy of gPlayer1Rider, see the note)
    Gfx* gdl;
    s32* new_var; // FAKE: pointer to gPlayer1Rider, see the note above

    new_var = &gPlayer1Rider;
    gdl = *gdlp;
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            t = *new_var; // FAKE: see the note above
            p = &D_80192690[gPlayer1Rider];
            rider = &gRiderRaceState[t];
        } else {
            p = &D_80192690[gPlayer2Rider];
            rider = &gRiderRaceState[gPlayer2Rider];
        }
        if ((rider->unk2E4 != 0) && (rider->unk2E8 <= D_80228B5C) && (rider->finishState == 0) && (rider->unk2F4 == 0)) {
            if (gPlayers == ONE_PLAYER) {
                y = 90;
            } else if (i == 0) {
                y = 50;
            } else {
                y = 160;
            }
            if (((rider->unk2E8 % 20) != 0) || (p->unkC54 == 23) || (p->unkC54 == 7)) {
                mode = 2;
                r0 = 255;
                g0 = 0;
                r1 = 0;
                g1 = 0;
            } else {
                mode = 1;
                r0 = 128;
                g0 = 128;
                r1 = 255;
                g1 = 255;
            }
            gdl = Printer_Print(gdl, 0, "COURSE", 68, y, mode, r0, 255, g0, r0, 255, g0, 255, r1, g1, 255, r1, g1);
            gdl = Printer_Print(gdl, 0, "OUT", 164, y, mode, r0, 255, g0, r0, 255, g0, 255, r1, g1, 255, r1, g1);
            n = rider->unk2E8 / 20;
            sprintf((char*) D_80228CF8, "%d", n);
            x = 223 - (n >= 10) * 5;
            gdl = Printer_Print(gdl, 0, (char*) D_80228CF8, x, y, mode, r0, 255, g0, r0, 255, g0,
                                255, r1, g1, 255, r1, g1);
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F2060.s")
#endif

void func_801F23A0(void) {
    s32 i;
    UnkStruct_80192690* p;
    RiderStruct* rider;
    f32 lo;
    f32 range;
    f32 f;
    s32 diff;
    s32 dist;
    s32 step;

    for (i = 0; i < gRiders; i++) {
        p = &D_80192690[i];
        rider = &gRiderRaceState[i];
        f = p->unkBBC - p->unkBC0;
        lo = p->unkBC0 - f / 5.0f;
        range = (f * 6.0f) / 5.0f;
        f = p->unkB98;
        if (lo <= p->unkB98) {
            if (range > 0.0f) {
                f = (p->unkB98 - lo) / range;
            }
            if (f < 0.0f) {
                f = 0.0f;
            }
            if (f > 1.0f) {
                f = 1.0f;
            }
            rider->unk2CC = f * 180.0f;
            rider->unk2CC += Math_Rand(3) * 2 - 2;
            if (rider->unk2CC > 180) {
                rider->unk2CC = 180;
            }
        } else {
            rider->unk2CC = (p->unkB98 / lo) * 36.0f;
        }
        step = rider->unk2CC; // FAKE: step holds the target first, for the register allocation
        diff = step - rider->unk2C8;
        dist = (diff >= 0) ? diff : -diff;
        step = dist / 4;
        if (step < 2) {
            step = 2;
        }
        if (rider->unk2C8 < rider->unk2CC && step > 4) {
            step = 4;
        }
        if (dist <= step) {
            rider->unk2C8 = rider->unk2CC;
        } else {
            rider->unk2C8 += ((diff == 0) ? 0 : (diff > 0) ? 1 : -1) * step;
        }
    }
}

#ifdef NON_MATCHING
// Score 6415 of 174400: y is copied into a local (py), which the original keeps in s0 (the big-digit loop still reads
// y, which orders its hoisted y << 2 terms as in the original), a stack pad gives the original's 0x2C8 frame, sec is
// reduced mod 60 before ms is taken, and the paired digit stores are chained assignments. Left: temp registers numbered
// differently from the style 0/2 branch on.
extern u8 D_1038D00[];
extern u8 D_10390C0[];
extern u8 D_1039100[];
extern u8 D_1039140[];
extern u8 D_1039180[];
extern u8 D_103AE08[];
extern u8 D_103AEC8[];
extern u8 D_103AF88[];
extern u8 D_103B408[];
extern u8 D_103D2D0[];
extern s32 D_801C1FE0;
extern s32 D_80228AA0;
extern s32 D_80228AC4;
extern s32 D_80228AC8;
extern s32 D_80228ACC;
extern s32 D_80228AD0;
extern s32 D_80228AD4;
extern s32 D_80228AD8;

#define HUD_LOAD8(gdl, img, w, h)                                                                     \
    gDPLoadTextureBlock(gdl++, img, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0, G_TX_NOMIRROR | G_TX_CLAMP, \
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD)

// Draw a time as m'ss"cc. Style 0 is the lap list (with the lap number), 1 the big
// RGBA digits, 2 and 3 the small and medium IA digits; arg5 picks the icon.
void func_801F25E0(Gfx** gdlp, s32 x, s32 y, s32 time, s32 style, s32 arg5, s32 color) {
    Gfx* gdl;
    s32 sec;
    s32 min;
    s32 ms;
    s32 i;
    s32 px;
    s32 lap;
    s32 skip;
    s32 ix;
    RiderStruct* rider;
    s32 py;
    s32 pad[2]; // stack pad

    gdl = *gdlp;
    py = y;
    if (time < 0) {
        time = 0;
    }
    if (time >= 600000) {
        time = 599999;
    }
    sec = time / 1000;
    min = sec / 60;
    sec %= 60;
    ms = time % 1000;
    D_80228CD8[0] = min;
    D_80228CD8[1] = sec / 10;
    D_80228CD8[2] = sec % 10;
    D_80228CD8[3] = ms / 100;
    if ((style != 1) || (arg5 != 1)) {
        D_80228CD8[4] = (ms % 100) / 10;
        D_80228CD8[5] = ms % 10;
    } else if (time == 0) {
        D_80228CD8[4] = D_80228CD8[5] = 0;
    } else if (time == 599999) {
        D_80228CD8[4] = D_80228CD8[5] = 9;
    } else {
        D_80228CD8[4] = (color + 5) % 10;
        D_80228CD8[5] = color % 10;
    }
    px = x;
    if ((style == 2) || (style == 3)) {
        if (time < 10000) {
            skip = 2;
        } else if (min == 0) {
            skip = 1;
        } else {
            skip = 0;
        }
    } else {
        skip = 0;
    }
    if (style == 1) {
        gDPPipeSync(gdl++);
        gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, 255);
        for (i = 0; i < 6; i++) {
            HUD_DIGIT(gdl, &((u32*) D_103B4D0)[D_80228CD8[i] * 0xC0], 12, 16, px, y);
            px += 13;
            if (i == 0) {
                px += 6;
            } else if (i == 2) {
                px += 7;
            }
        }
        HUD_DIGIT(gdl, D_103D2D0, 12, 16, x + 12, py);
        HUD_DIGIT(gdl, D_103D5D0, 12, 16, x + 44, py);
    } else if ((style == 0) || (style == 2)) {
        gDPPipeSync(gdl++);
        gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, 255);
        if (style == 0) {
            rider = &gRiderRaceState[gPlayer1Rider];
            if (rider->unk2F4 != 0) {
                lap = rider->lapCount;
            } else {
                lap = rider->lapCount - 1;
            }
            gDPPipeSync(gdl++);
            if ((D_80228AA0 != 0) && (arg5 == lap)) {
                gDPSetPrimColor(gdl++, 0, 0, D_80228AB8, D_80228ABC, D_80228AC0, 255);
            } else if (D_801C1FE0 >= time) {
                gDPSetPrimColor(gdl++, 0, 0, D_80228AAC, D_80228AB0, D_80228AB4, 255);
            } else {
                gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, 255);
            }
        } else if (arg5 != 3) {
            if (arg5 == 1) {
                HUD_LOAD8(gdl, D_1039180, 8, 8);
            } else {
                HUD_LOAD8(gdl, D_10390C0, 8, 8);
            }
            if (skip == 0) {
                ix = x - 8;
            } else if (skip == 1) {
                ix = x + 4;
            } else {
                ix = x + 10;
            }
            HUD_SCISRECT(gdl, ix, py, 8, 8);
        }
        for (i = 0; i < 6; i++) {
            if ((skip == 0) || (i >= skip)) {
                HUD_LOAD8(gdl, &D_10387C0[D_80228CD8[i] << 6], 8, 8);
                HUD_SCISRECT(gdl, px, py, 8, 8);
            }
            px += 7;
            if ((i == 0) || (i == 2)) {
                px += 5;
            }
        }
        if (skip == 0) {
            HUD_LOAD8(gdl, D_1039100, 8, 8);
            HUD_SCISRECT(gdl, x + 6, py, 8, 8);
        }
        HUD_LOAD8(gdl, D_1039140, 8, 8);
        HUD_SCISRECT(gdl, x + 25, py, 8, 8);
        if (style == 0) {
            HUD_LOAD8(gdl, D_1038D00, 8, 8);
            HUD_SCISRECT(gdl, x + 60, py, 8, 8);
            HUD_LOAD8(gdl, &D_10387C0[arg5 << 6], 8, 8);
            HUD_SCISRECT(gdl, x + 66, py, 8, 8);
        }
    } else if (style == 3) {
        gDPPipeSync(gdl++);
        if (color == 0) {
            gDPSetPrimColor(gdl++, 0, 0, 255, 255, 255, 255);
        } else if (color == 1) {
            gDPSetPrimColor(gdl++, 0, 0, D_80228AC4, D_80228AC8, D_80228ACC, 255);
        } else {
            gDPSetPrimColor(gdl++, 0, 0, D_80228AD0, D_80228AD4, D_80228AD8, 255);
        }
        if (arg5 != 3) {
            if (arg5 == 1) {
                HUD_LOAD8(gdl, D_103B408, 16, 12);
            } else {
                HUD_LOAD8(gdl, D_103AE08, 16, 12);
            }
            if (skip == 0) {
                ix = x - 10;
            } else if (skip == 1) {
                ix = x + 5;
            } else {
                ix = x + 16;
            }
            HUD_RECT(gdl, ix, py, 16, 12);
        }
        for (i = 0; i < 6; i++) {
            if ((skip == 0) || (i >= skip)) {
                HUD_LOAD8(gdl, &D_1039248[D_80228CD8[i] * 0xC0], 16, 12);
                HUD_RECT(gdl, px, py, 16, 12);
            }
            px += 11;
            if ((i == 0) || (i == 2)) {
                px += 4;
            }
        }
        if (skip == 0) {
            HUD_LOAD8(gdl, D_103AEC8, 16, 12);
            HUD_RECT(gdl, x + 10, py, 16, 12);
        }
        HUD_LOAD8(gdl, D_103AF88, 16, 12);
        HUD_RECT(gdl, x + 36, py, 16, 12);
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F25E0.s")
#endif

#ifdef NON_MATCHING
// Score 56483 of 490800: same stack frame and nearly the same branches (structure diff): where the original
// keeps 6 (and 0xA0) in saved registers in the five-mark D_102EE70 loop it divides with the divide-by-zero checks, two
// if / else joins end in an extra branch there, and the lap-split popup reuses its gapRequest load. Register
// allocation and scheduling differ throughout:
// IDO hoists constants and global addresses into saved registers here that the original reloads (&D_80228B54 in the
// lap-split loop, the constant 1 in the lap-split popup), so the saved and temporary registers of every display-list
// block differ. The 1.8f below is D_80227A4C in the original.
// Draw the race HUD: lap splits and total time, the TIME, LAP, RANK and SPEED readouts, the missed-buoy
// marks, the boost meter, the stunt score and the best times.
void func_801F4120(Gfx** gdlp) {
    s32 i;
    s32 k;
    s32 j;
    s32 x;
    s32 y;
    s32 n;
    PortraitPos* pos;
    s32 value;
    s32 color;
    RiderStruct* rider;
    UnkStruct_80228C30* boost;
    s8* digit;
    s32 x2;
    s32 y2;
    Gfx* gdl = *gdlp;

    gSPDisplayList(gdl++, D_1014708);

    // Lap splits and the total race time.
    if (((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) && (gCourseID != DOLPHIN_PARK)) {
        rider = &gRiderRaceState[gPlayer1Rider];
        if ((rider->lapCount >= 2) || (D_800D8178 != 0)) {
            n = rider->lapCount - 1;
            y = 0x34;
            if (n >= 10) {
                k = n - 9;
                n = 9;
            } else {
                k = 0;
            }
            if ((rider->unk2F4 != 0) || (D_800D8178 != 0)) {
                n++;
            }
            for (j = 0; j < n; j++) {
                func_801F25E0(&gdl, D_80228B54 + 0x18, y, rider->lapTimes[j], 0, (k + j + 1) % 10, 0);
                y += 10;
            }
        }
        if ((rider->unk2F4 != 0) || (rider->finishState == 2)) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, D_80228B50 + 0x18, 0x22, rider->raceTime, 1, i, rider->unk16C);
    } else if (gGameModes == GMODE_2P_VS) {
        rider = &gRiderRaceState[gPlayer1Rider];
        if (rider->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, 0x18, 0xE, rider->raceTime, 1, i, rider->unk16C);
        rider = &gRiderRaceState[gPlayer2Rider];
        if (rider->unk2F4 != 0) {
            i = 0;
        } else {
            i = 1;
        }
        func_801F25E0(&gdl, 0x18, 0x7C, rider->raceTime, 1, i, rider->unk16C);
    }

    // Championship: the leader's time and the others' gaps to it, beside the portrait column.
    // k: the leader, value: the leader's time.
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (gCourseID != DOLPHIN_PARK) && (D_801C1FDC >= 0x28)) {
        for (k = 0; k < gRiders; k++) {
            if ((gRiderRaceState[k].unk2F4 != 0) && (gRiderRaceState[k].racePosition == 0)) {
                break;
            }
        }
        if (k >= gRiders) {
            k = 0;
        }
        value = gRiderRaceState[k].raceTime;
        for (i = 0; i < gRiders; i++) {
            rider = &gRiderRaceState[i];
            if (D_801C1FDC >= (rider->racePosition * 10) + 0x28) {
                pos = &gPortraitPos[0][i];
                x = pos->x + 0xB0;
                y = pos->y + 0x3F;
                if (i == gPlayer1Rider) {
                    color = 2;
                } else {
                    color = 1;
                }
                if (i == k) {
                    func_801F25E0(&gdl, x + D_80228B50, y, rider->raceTime, 3, 3, color);
                } else if (rider->unk2F4 != 0) {
                    func_801F25E0(&gdl, x + D_80228B50, y, rider->raceTime - value, 3, 1, color);
                }
            }
        }
    }

    // 2P VS: the lap split popups.
    if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gPlayers; i++) {
            y = 0xB2;
            if (i == 0) {
                y = 0x44;
                rider = &gRiderRaceState[gPlayer1Rider];
            } else {
                rider = &gRiderRaceState[gPlayer2Rider];
            }
            if (rider->gapTimer != 0) {
                value = rider->checkpointGap;
                if (value < 10000) {
                    x = -0xF;
                } else if (value < 60000) {
                    x = -0xA;
                } else {
                    x = 0;
                }
                if (rider->gapRequest == 1) {
                    color = 1;
                } else {
                    color = 2;
                }
                func_801F25E0(&gdl, x + 0x80, y, value, 3, rider->gapRequest, color);
            }
        }
    }

    // Championship: the other riders' lap split popups.
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (gCourseID != DOLPHIN_PARK)) {
        for (i = 0; i < gRiders; i++) {
            if (i != gPlayer1Rider) {
                rider = &gRiderRaceState[i];
                pos = &gPortraitPos[0][i];
                x = pos->x + 0xBA;
                y = pos->y + 0x3F;
                if (rider->gapTimer != 0) {
                    func_801F25E0(&gdl, x, y, rider->checkpointGap, 3, rider->gapRequest, 1);
                }
            }
        }
    }

    // Championship and time trials: the player's lap split popup, with a portrait (or a record icon).
    // j: how many leading digits the time drops (2 under 10 s, 1 under 60 s).
    if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) {
        rider = &gRiderRaceState[gPlayer1Rider];
        if (rider->gapTimer != 0) {
            value = rider->checkpointGap;
            color = 2;
            if (value < 10000) {
                j = 2;
            } else if (value < 60000) {
                j = 1;
            } else {
                j = 0;
            }
            x = 0x8C;
            if (j == 1) {
                x = 0x85;
            } else if (j == 2) {
                x = 0x7F;
            }
            if ((gGameModes == GMODE_TIME_TRIALS) && (rider->gapRequest == 1)) {
                color = 1;
            }
            func_801F25E0(&gdl, x, 0x7E, value, 3, rider->gapRequest, color);
            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            // n, y: the icon's position.
            n = x - 0x28;
            y = 0x7A;
            if (j == 1) {
                n += 0xF;
            } else if (j == 2) {
                n += 0x1A;
            }
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                gDPLoadTextureBlock(gdl++, D_10416A8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
                n += 9;
                y += 2;
                gDPLoadTextureBlock(gdl++, gPortraitFaces[D_80192690[rider->unk33C].unkB68], G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x10) << 2, (y + 0x10) << 2, G_TX_RENDERTILE, 0, 0,
                                    0x500, 0x500);
            } else {
                n -= 6;
                gDPLoadTextureBlock(gdl++, D_1042780, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, n << 2, y << 2, (n + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
            }
        }
    }

    gDPPipeSync(gdl++);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    // TIME label.
    if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_TIME_TRIALS)) {
        if (gCourseID != DOLPHIN_PARK) {
            HUD_LOAD32(gdl, D_1032500, 32, 12);
            HUD_RECT(gdl, D_80228B50 + 0x38, 0x15, 32, 12);
        }
    }

    // LAP label and the lap number (n).
    if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
        if (gPlayers == ONE_PLAYER) {
            y = 0x15;
            if (gGameModes == GMODE_CHAMPIONSHIP) {
                x = D_80228B50 + 0xBC;
            } else {
                x = 0x84;
            }
        } else {
            x = 0xCA;
            y = 0xD;
            x2 = 0xCA;
            y2 = 0x7B;
        }
        HUD_LOAD32(gdl, D_1032078, 24, 12);
        HUD_RECT(gdl, x, y, 24, 12);
        if (gPlayers == TWO_PLAYERS) {
            HUD_RECT(gdl, x2, y2, 24, 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0x22;
                if (gGameModes == GMODE_CHAMPIONSHIP) {
                    x = D_80228B50 + 0xC0;
                } else {
                    x = 0x88;
                }
                n = gRiderRaceState[gPlayer1Rider].lapCount;
            } else {
                x = 0xD0;
                if (i == 0) {
                    y = 0x19;
                    n = gRiderRaceState[gPlayer1Rider].lapCount;
                } else {
                    y = 0x87;
                    n = gRiderRaceState[gPlayer2Rider].lapCount;
                }
            }
            if (D_801CE728[0] < n) {
                n = D_801CE728[0];
            }
            if (gPlayers == ONE_PLAYER) {
                HUD_DIGIT(gdl, &D_103D8D8[(n % 10) * 0x500], 16, 20, x, y);
            } else {
                HUD_DIGIT(gdl, &D_103B4D0[(n % 10) * 0x300], 12, 16, x, y);
            }
        }
    }

    // RANK: label, position digit (zooming when it changes), "/" and the number of riders.
    if (gGameModes == GMODE_CHAMPIONSHIP) {
        if (gCourseID != DOLPHIN_PARK) {
            HUD_LOAD32(gdl, D_1032B08, 36, 12);
            HUD_RECT(gdl, D_80228B50 + 0x84, 0x15, 36, 12);
            HUD_LOAD32(gdl, &D_103D8D8[(gRiderRaceState[gPlayer1Rider].racePosition + 1) * 0x500], 16, 20);
            x = D_80228B50 + 0x88;
            if (D_80228A9C == 0) {
                HUD_RECT(gdl, x, 0x22, 16, 20);
            } else {
                color = D_80228DF8 * 6;
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_BILERP);
                gSPTextureRectangle(gdl++, (x - color) << 2, 0x22 << 2, (x + 0x10) << 2, (color + 0x36) << 2,
                                    G_TX_RENDERTILE, 0, 0, 0x4000 / (color + 0x10), 0x5000 / (color + 0x14));
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_POINT);
            }
            gDPPipeSync(gdl++);
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0,
                              TEXEL0, 0, ENVIRONMENT, 0);
            if (D_801CE704 < gRiderRaceState[gPlayer1Rider].racePosition) {
                gDPSetEnvColor(gdl++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
            } else {
                gDPSetEnvColor(gdl++, 255, 255, 255, 255);
            }
            gDPLoadTextureBlock(gdl++, D_1033C60, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 10, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            HUD_RECT(gdl, D_80228B50 + 0x9B, 0x20, 8, 10);
            if (D_801CE704 < 4) {
                n = D_801CE704 + 1;
            } else {
                n = 0x25;
            }
            gDPLoadTextureBlock(gdl++, &D_1039248[n * 0xC0], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 12, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            HUD_RECT(gdl, D_80228B50 + 0x9A, 0x2A, 16, 12);
            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        }
    }

    // SPEED label.
    HUD_LOAD32(gdl, D_10331D0, 32, 12);
    if (gGameModes == GMODE_STUNT) {
        HUD_RECT(gdl, 0xEC, 0x16, 32, 12);
    } else if (gPlayers == ONE_PLAYER) {
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x97;
        } else {
            x = 0xD9;
        }
        HUD_RECT(gdl, x + D_80228B50 + 0x18, 0x15, 32, 12);
    } else {
        HUD_RECT(gdl, 0xF2, 0xD, 32, 12);
        HUD_RECT(gdl, 0xF2, 0x7B, 32, 12);
    }

    // The speed (value, km/h), three digits.
    for (i = 0; i < gPlayers; i++) {
        if (gPlayers == ONE_PLAYER) {
            y = 0x22;
            x = D_80228B50 + 0xE1;
            value = D_80192690[gPlayer1Rider].unkB90;
        } else if (i == 0) {
            x = 0xEC;
            y = 0x19;
            value = D_80192690[gPlayer1Rider].unkB90;
        } else {
            x = 0xEC;
            y = 0x87;
            value = D_80192690[gPlayer2Rider].unkB90;
        }
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xE1;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x9F;
        }
        value = value * 1.8f;
        if (value >= 1000) {
            value = 999;
        }
        if (gGameModes == GMODE_STUNT) {
            x = 0xE4;
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_802C3E8[(value / 100) * 0x300], 12, 16, x, 0x26);
            }
            x += 0xE;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_802C3E8[((value % 100) / 10) * 0x300], 12, 16, x, 0x26);
            }
            x += 0xE;
            HUD_DIGIT(gdl, &D_802C3E8[(value % 10) * 0x300], 12, 16, x, 0x26);
        } else if (gPlayers == ONE_PLAYER) {
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_103D8D8[(value / 100) * 0x500], 16, 20, x, y);
            }
            x += 0x10;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_103D8D8[((value % 100) / 10) * 0x500], 16, 20, x, y);
            }
            x += 0x10;
            HUD_DIGIT(gdl, &D_103D8D8[(value % 10) * 0x500], 16, 20, x, y);
        } else {
            if (value >= 100) {
                HUD_DIGIT(gdl, &D_103B4D0[(value / 100) * 0x300], 12, 16, x, y);
            }
            x += 0xD;
            if (value >= 10) {
                HUD_DIGIT(gdl, &D_103B4D0[((value % 100) / 10) * 0x300], 12, 16, x, y);
            }
            x += 0xD;
            HUD_DIGIT(gdl, &D_103B4D0[(value % 10) * 0x300], 12, 16, x, y);
        }
    }

    // km/h label.
    HUD_LOAD32(gdl, D_10337D8, 24, 12);
    if (gGameModes == GMODE_STUNT) {
        HUD_RECT(gdl, 0x10E, 0x2B, 24, 12);
    } else if (gPlayers == ONE_PLAYER) {
        if (gCourseID == DOLPHIN_PARK) {
            x = 0xD9;
        } else if (gGameModes == GMODE_TIME_TRIALS) {
            x = 0x97;
        } else {
            x = 0xD9;
        }
        HUD_RECT(gdl, x + D_80228B50 + 0x39, 0x2A, 24, 12);
    } else {
        HUD_RECT(gdl, 0x114, 0x1E, 24, 12);
        HUD_RECT(gdl, 0x114, 0x8C, 24, 12);
    }

    // Buoy marks: the label, k = gBuoyMisses (at most 28) marks D_102E3D8, then the rider's unk134 (n)
    // marks D_102E620 over the right end of the row (one fewer while gHudMarkers[player].unk0[0].unk18 == 1).
    if ((gGameModes != GMODE_STUNT) && (gCourseID != DOLPHIN_PARK)) {
        if (gPlayers == ONE_PLAYER) {
            x = D_80228B54 + 0x18;
            HUD_LOAD32(gdl, D_102DF50, 24, 12);
            y = 0xCD;
            HUD_SCISRECT(gdl, x, y, 24, 12);
        }
        HUD_LOAD32(gdl, D_102E3D8, 12, 12);
        k = gBuoyMisses;
        if (k > 28) {
            k = 28;
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCD;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                if (i == 0) {
                    y = 0x68;
                } else {
                    y = 0xD6;
                }
            }
            for (j = 0; j < k; j++) {
                HUD_SCISRECT(gdl, x, y, 12, 12);
                x += 0xE;
            }
        }
        boost = gHudMarkers;
        HUD_LOAD32(gdl, D_102E620, 12, 12);
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCD;
                n = gRiderRaceState[gPlayer1Rider].unk134;
                x = D_80228B54 + 0x38;
            } else {
                x = 0x18;
                if (i == 0) {
                    y = 0x68;
                    n = gRiderRaceState[gPlayer1Rider].unk134;
                } else {
                    y = 0xD6;
                    n = gRiderRaceState[gPlayer2Rider].unk134;
                }
            }
            if (boost->unk0[0].unk18 == 1) {
                n--;
            }
            j = k - n;
            if (j < 0) {
                j = 0;
            }
            for (x += j * 0xE; j < k; j++) {
                HUD_SCISRECT(gdl, x, y, 12, 12);
                x += 0xE;
            }
            boost++;
        }
    }

    // Power meter: the label and five chevrons, n = the rider's unk138 of them lit, the n-th one
    // animating (color: the chevron's image, 0-3).
    if ((gCourseID != DOLPHIN_PARK) && (gGameModes != GMODE_STUNT)) {
        if (gPlayers == ONE_PLAYER) {
            x = D_80228B54 + 0x94;
            HUD_LOAD32(gdl, D_102E868, 32, 12);
            y = 0xCD;
            HUD_SCISRECT(gdl, x, y, 32, 12);
        }
        for (i = 0; i < gPlayers; i++) {
            if (gPlayers == ONE_PLAYER) {
                y = 0xCF;
                n = gRiderRaceState[gPlayer1Rider].unk138;
                x = D_80228B54 + 0xBC;
            } else {
                y = 0x6A;
                x = 0xBC;
                if (i == 0) {
                    x = 0xBC;
                    n = gRiderRaceState[gPlayer1Rider].unk138;
                } else {
                    y = 0xD8;
                    n = gRiderRaceState[gPlayer2Rider].unk138;
                }
            }
            for (j = 0; j < 5; j++) {
                if (j + 1 == n) {
                    color = D_800D4B00 % 6;
                    if (color >= 4) {
                        color = 6 - color;
                    }
                } else {
                    color = 0;
                    if (j < n) {
                        color = 3;
                    }
                }
                HUD_LOAD32(gdl, &D_102EE70[(color + j * 4) * (20 * 8)], 20, 8);
                HUD_SCISRECT(gdl, x, y, 20, 8);
                x += 0x16;
            }
        }
    }

    // Stunt mode: the score (value), five digits.
    if (gGameModes == GMODE_STUNT) {
        HUD_LOAD32(gdl, D_8024008, 36, 12);
        HUD_RECT(gdl, 0x2D, 0x16, 36, 12);
        value = D_801C26D0;
        x = 0x1C;
        if (value >= 100000) {
            value = 99999;
        }
        for (digit = &D_80228CF8[4]; digit > &D_80228CF8[-1]; digit--) {
            *digit = value % 10;
            value /= 10;
        }
        for (digit = D_80228CF8; digit != &D_80228CF8[5]; digit++) {
            HUD_DIGIT(gdl, &D_8024BC8[*digit * 0x300], 12, 16, x, 0x26);
            x += 0xE;
        }
    }

    // Stunt mode: the time left (value): n seconds and k thousandths; under six seconds the seconds
    // digit zooms out over each second (color: the shrink, x/y: the drawn size).
    if (gGameModes == GMODE_STUNT) {
        HUD_LOAD32(gdl, D_1032500, 32, 12);
        HUD_RECT(gdl, 0x8D, 0x16, 32, 12);
        value = gRiderRaceState[gPlayer1Rider].timeLeft;
        k = value % 1000;
        n = value / 1000;
        HUD_DIGIT(gdl, &D_103B4D0[(k / 100) * 0x300], 12, 16, 0xAA, 0x26);
        HUD_DIGIT(gdl, D_103D5D0, 12, 16, 0xA2, 0x23);
        if ((n >= 6) || (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) || (gRiderRaceState[gPlayer1Rider].finishState != 0)) {
            x = 0x84;
            if (n >= 10) {
                HUD_DIGIT(gdl, &D_80273D8[(n / 10) * 0x500], 16, 20, x, 0x26);
            }
            x += 0x10;
            HUD_DIGIT(gdl, &D_80273D8[(n % 10) * 0x500], 16, 20, x, 0x26);
        } else {
            k -= 700;
            if (k < 0) {
                k = 0;
            }
            color = (k * 16) / 300;
            x = 0x20 - color * 2;
            y = 0x28 - color * 2;
            if ((x > 0) && (y > 0)) {
                gDPPipeSync(gdl++);
                gDPSetTextureFilter(gdl++, G_TF_BILERP);
                gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT,
                                  0, TEXEL0, 0, ENVIRONMENT, 0);
                gDPSetEnvColor(gdl++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
                gDPLoadTextureBlock(gdl++, &D_802A5E0[n * 0x500], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 40, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, (color + 0x84) << 2, (color + 0x26) << 2, (0xA4 - color) << 2,
                                    (0x4E - color) << 2, G_TX_RENDERTILE, 0, 0, 0x8000 / x, 0xA000 / y);
            }
        }
    }

    // Time trials: the best times.
    if ((gGameModes == GMODE_TIME_TRIALS) && (gCourseID != DOLPHIN_PARK)) {
        y = 0x16;
        gdl = Printer_Print(gdl, 1, "BEST TIME", 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        y += 9;
        gdl = Printer_PrintTime(gdl, 1, D_801C1FE4, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (D_800DAB68 == 0) {
            y += 0xB;
            gdl = Printer_Print(gdl, 1, "BEST LAP", 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            y += 9;
            gdl = Printer_PrintTime(gdl, 1, D_801C1FE8, 0xEE, y, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F4120.s")
#endif

#ifdef NON_MATCHING
// Score 30 of 46800: only the bob counter (d) takes $v0 where the original has $v1; everything else matches.
extern s32 D_801C1FD4;
extern s32 D_80228DD8[4];
extern s32 D_80228DE8[4];
extern s32 D_80228DFC;

void func_801F8DD0(void) {
    s32 i;
    s32 j;
    PortraitPos* pos;
    s32 me;
    s32 ad;
    s32 d;
    f32 dx;
    f32 dz;
    f32 dist;

    for (i = 0; i < gPlayers; i++) {
        for (j = 0; j < gRiders; j++) {
            gPortraitPos[i][j].unkC = gRiderRaceState[j].racePosition * 24;
        }
        for (j = 0; j < gRiders; j++) {
            if (gPlayers == ONE_PLAYER) {
                if (gRiderRaceState[gPlayer1Rider].racePosition < gRiderRaceState[j].racePosition) {
                    gPortraitPos[i][j].unkC += 4;
                }
            } else if (i == 0) {
                if (gRiderRaceState[gPlayer1Rider].racePosition < gRiderRaceState[j].racePosition) {
                    gPortraitPos[i][j].unkC += 4;
                }
            } else if (gRiderRaceState[gPlayer2Rider].racePosition < gRiderRaceState[j].racePosition) {
                gPortraitPos[i][j].unkC += 4;
            }
        }
        for (j = 0; j < gRiders; j++) {
            pos = &gPortraitPos[i][j];
            d = pos->unkC - pos->y;
            if (pos->y != pos->unkC) {
                ad = (d >= 0) ? d : -d;
                if (ad < 5) {
                    pos->y = pos->unkC;
                    pos->unk8 = 0;
                } else {
                    pos->y += ((d == 0) ? 0 : (d > 0) ? 1 : -1) * 4;
                    if (d < 0) {
                        pos->unk8 = 0;
                    } else if (ad < 16) {
                        pos->unk8 = ad / 2;
                    } else {
                        pos->unk8 = 8;
                    }
                }
            } else {
                pos->unk8 = 0;
            }
            d = pos->unk8 - pos->x;
            if (pos->x != pos->unk8) {
                ad = (d >= 0) ? d : -d;
                if (ad < 3) {
                    pos->x = pos->unk8;
                } else {
                    pos->x += ((d == 0) ? 0 : (d > 0) ? 1 : -1) * 2;
                }
            }
        }
    }
    for (j = 0; j < gRiders; j++) {
        me = D_80192690[j].unk15C0;
        if (me == 2) {
            D_80228DD8[j] = -15;
        } else if (me == 1) {
            D_80228DD8[j] = -5;
        } else {
            D_80228DE8[j] = 1;
            D_80228DD8[j] = 0;
        }
        d = D_80228DC8[j]; // FAKE: loads D_80228DC8 before D_80228DD8
        d = D_80228DD8[j] - d;
        if (D_80228DC8[j] != D_80228DD8[j]) {
            me = (d >= 0) ? d : -d;
            D_80228DE8[j]++;
            if (d > 0) {
                D_80228DC8[j]++;
            } else if (D_80228DE8[j] >= me) {
                D_80228DC8[j] = D_80228DD8[j];
            } else {
                D_80228DC8[j] -= D_80228DE8[j];
            }
            if (D_80228DC8[j] == D_80228DD8[j]) {
                D_80228DE8[j] = 1;
            }
        }
    }
    for (i = 0; i < gPlayers; i++) {
        for (j = 0; j < gRiders; j++) {
            if ((gPortraitPos[i][j].x == gPortraitPos[i][j].unk8) && (gPortraitPos[i][j].y == gPortraitPos[i][j].unkC) && (D_801C1FD4 == 0)) {
                if ((gRiderRaceState[j].unk2F4 == 0) && (((i == 0) && (gRiderRaceState[j].unk320 == gRiderRaceState[gPlayer1Rider].unk320) &&
                                          (gRiderRaceState[j].racePosition == gRiderRaceState[gPlayer1Rider].racePosition + 1)) ||
                                         ((i == 1) && (gRiderRaceState[j].unk320 == gRiderRaceState[gPlayer2Rider].unk320) &&
                                          (gRiderRaceState[j].racePosition == gRiderRaceState[gPlayer2Rider].racePosition + 1)))) {
                    if (i == 0) {
                        me = gPlayer1Rider;
                    } else {
                        me = gPlayer2Rider;
                    }
                    if ((gRiderRaceState[j].nearestRecord == gRiderRaceState[me].nearestRecord) && (gGameModeState == GMODE_STATE_STARTED)) {
                        dx = D_80192690[me].unk44.x - D_80192690[j].unk44.x;
                        dz = D_80192690[me].unk44.z - D_80192690[j].unk44.z;
                        dist = sqrtf(dx * dx + dz * dz);
                        if (dist < 512.0f) {
                            d = gPortraitPos[i][j].bobPhase;
                            if (dist < 256.0f) {
                                d += 2;
                            } else {
                                d += 1;
                            }
                            gPortraitPos[i][j].bobPhase = d & 7;
                        }
                    }
                }
            }
            if (gPortraitPos[i][j].bobPhase != 0) {
                gPortraitPos[i][j].bobPhase++;
                if (gPortraitPos[i][j].bobPhase >= 8) {
                    gPortraitPos[i][j].bobPhase = 0;
                }
            }
        }
    }
    if (D_80228A9C == 1) {
        D_80228A9C = 2;
        D_80228DFC = 4;
    }
    if (D_80228DF8 != D_80228DFC) {
        D_80228DF8 += ((D_80228DFC - D_80228DF8) == 0) ? 0 : ((D_80228DFC - D_80228DF8) > 0) ? 1 : -1;
    }
    if (D_80228DF8 == D_80228DFC) {
        if (D_80228DF8 > 0) {
            D_80228A9C = 3;
            D_80228DFC = 0;
        } else {
            D_80228A9C = 0;
            D_80228DFC = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F8DD0.s")
#endif

// Draw the column of rider portraits, with their race positions.
void func_801F9520(Gfx** gdlp) {
    Gfx* gdl = *gdlp;
    s32 i;
    s32 idx;
    s32 player;
    s32 x;
    s32 y;
    s32 xOff;
    s32 yOff;
    s32 highlight;
    s32 face;
    s32 numX;
    s32 numY;
    u8* img;
    PortraitPos* pos;
    f32 bob;

    if (gPlayers == ONE_PLAYER) {
        gSPDisplayList(gdl++, D_1014760);
    } else {
        gSPDisplayList(gdl++, D_1014790);
    }

    for (player = 0; player < gPlayers; player++) {
        if (gPlayers == ONE_PLAYER) {
            xOff = D_80228B50 + 0x106;
            yOff = 0x3C;
        } else {
            xOff = 0x108;
            if (player == 0) {
                yOff = 0x2B;
            } else {
                yOff = 0x99;
            }
        }
        for (i = 0; i < gRiders; i++) {
            if (player == 0) {
                idx = gRiders - i - 1;
            } else {
                idx = i;
            }
            pos = &gPortraitPos[player][idx];
            x = pos->x + xOff;
            y = pos->y + yOff;
            bob = gPortraitBob[pos->bobPhase & 7] * 4.0f;
            y = y - bob;

            if (((player == 0) && (idx == gPlayer1Rider)) || ((player == 1) && (idx == gPlayer2Rider))) {
                highlight = 1;
            } else {
                highlight = 0;
            }

            gDPPipeSync(gdl++);
            gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetRenderMode(gdl++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);

            if (highlight) {
                if (gRiderRaceState[idx].unk2F4 == 0) {
                    img = D_1040FE0;
                } else {
                    img = D_10420B8;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 36, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, (x - 7) << 2, y << 2, (x + 0x1D) << 2, (y + 0x18) << 2, G_TX_RENDERTILE, 0,
                                    0, 1 << 10, 1 << 10);
            } else {
                if (gRiderRaceState[idx].unk2F4 == 0) {
                    img = D_10416A8;
                } else {
                    img = D_1041BB0;
                }
                gDPLoadTextureBlock(gdl++, img, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 0x20) << 2, (y + 0x14) << 2, G_TX_RENDERTILE, 0, 0,
                                    1 << 10, 1 << 10);
            }

            if (((idx == gPlayer1Rider) && (D_801CE6F4[0] != 0)) ||
                ((gPlayers == TWO_PLAYERS) && (idx == gPlayer2Rider) && (D_801CE6F4[1] != 0))) {
                face = 4;
            } else {
                face = 0;
            }
            gDPLoadTextureBlock(gdl++, gPortraitFaces[D_80192690[idx].unkB68 + face], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20,
                                0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            if (highlight) {
                gSPTextureRectangle(gdl++, (x + 5) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x16) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 1 << 10, 1 << 10);
            } else {
                gSPTextureRectangle(gdl++, (x + 9) << 2, (y + 2) << 2, (x + 0x19) << 2, (y + 0x12) << 2,
                                    G_TX_RENDERTILE, 0, D_80228DC8[idx] << 5, 0x500, 0x500);
            }

            gDPPipeSync(gdl++);
            gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            gDPSetCombineLERP(gdl++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0,
                              TEXEL0);
            if (highlight) {
                gDPSetEnvColor(gdl++, D_80228AB8, D_80228ABC, D_80228AC0, 255);
                numX = x - 4;
                numY = y + 4;
            } else {
                gDPSetEnvColor(gdl++, 255, 255, 255, 255);
                numX = x + 2;
                numY = y + 2;
            }
            gDPLoadTextureBlock(gdl++, &D_10387C0[(gRiderRaceState[idx].racePosition + 1) * 64], G_IM_FMT_IA, G_IM_SIZ_8b, 8,
                                8, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gdl++, numX << 2, numY << 2, (numX + 8) << 2, (numY + 8) << 2, G_TX_RENDERTILE, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    *gdlp = gdl;
}

#ifdef NON_MATCHING
// Score 120 of 32800: side is computed first, then the forward dot product (copied to fwd); the direction is
// normalised in place (dx /= dist); dot holds side / scale once the angle test is done, and a holds the clamped fwd
// before it holds the angle (with these the saved FP registers are coloured as in the original). The zero tests of
// a use the integer literal 0. A differently spelled zero is a separate constant here (0.f, 0.00f and 0e0f all
// work; 0.0F does not): sgn's 0.f is its own, while written 0.0f it shares aa > 0.0f's zero, which is then loaded in
// both arms of sgn instead of once at the top. Left: the
// lui of gRiders' address is scheduled two instructions later than in the original (after the b->unk4 store).
extern s32 D_80223934;
extern f32 gSinTable[0x1000];

f32 func_801ED090(f32 arg0);
f32 func_801ED154(f32 arg0, f32 arg1);

// Place each rider ahead of the player on the radar: side offset, distance and heading.
void func_801F9EA0(void) {
    s32 pad; // stack pad
    s32 i;
    s32 j;
    s32 me;
    camera_unk_1* cam;
    f32 camX;
    f32 camZ;
    f32 dirX;
    f32 dirZ;
    UnkStruct_80228B88* b;
    UnkStruct_80192690* p;
    f32 dx;
    f32 dz;
    f32 fwd;
    f32 dot;
    f32 dist;
    f32 scale;
    f32 side;
    f32 sx;
    f32 a;
    f32 aa;
    f32 sgn;
    f32 ox;
    f32 oy;
    s32 k;

    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            me = gPlayer1Rider;
            cam = &gCameraPerspective[D_80223930];
        } else {
            me = gPlayer2Rider;
            cam = &gCameraPerspective[D_80223934];
        }
        camX = cam->eyeX;
        camZ = cam->eyeZ;
        dirX = -cam->unkF0;
        dirZ = -cam->unkF4;
        dx = cam->atX - camX;
        dz = cam->atZ - camZ;
        sqrtf(dx * dx + dz * dz);
        for (j = 0; j < gRiders; j++) {
            b = &D_80228B88[i][j];
            b->unk10 = 0;
            if ((j != me) && (gRiderRaceState[j].racePosition >= gRiderRaceState[me].racePosition)) {
                p = &D_80192690[j];
                dx = p->unk44.x - camX;
                dz = p->unk44.z - camZ;
                side = dx * dirZ + dz * -dirX;
                dot = dx * dirX + dz * dirZ;
                fwd = dot;
                dist = sqrtf(dx * dx + dz * dz);
                if (dist > 0.0f) {
                    dx /= dist;
                    dz /= dist;
                    dot = dx * dirX + dz * dirZ;
                }
                dot = func_801ED090(dot);
                if ((dist > 1024.0f) || (dot > 135.0f)) {
                    continue;
                }
                a = fwd;
                if (fwd < 0.0f) {
                    a = 0.0f;
                }
                scale = a * 0.0009765625f * 1024.0f + 60.0f;
                dot = side / scale;
                sx = dot;
                if (dot > 1.0f) {
                    a = func_801ED154(dot - 1.0f, fwd / scale);
                    sx = 1.0f;
                } else if (dot < -1.0f) {
                    a = func_801ED154(dot + 1.0f, fwd / scale);
                    sx = -1.0f;
                } else {
                    a = 0; // integer literal: with 0.0f the zero is shared with the other tests
                }
                if (a > 180.0f) {
                    a -= 360.0f;
                }
                aa = (a >= 0) ? a : -a;
                sgn = (a == 0) ? 0.f : ((a > 0) ? 1 : -1); // odd literal: 0.f, not 0.0f (see the note)
                if (aa > 0.0f) {
                    aa *= 0.6666667f;
                    if (aa > 90.0f) {
                        aa = 90.0f;
                    }
                    k = (aa / 360.0f) * 4096.0f;
                    ox = gSinTable[k & 0xFFF] * sgn * 32.0f;
                    oy = -(1.0f - gSinTable[(k + 0x400) & 0xFFF]) * 24.0f;
                } else {
                    oy = 0.0f;
                    ox = 0.0f;
                }
                b->unk4 = oy;
                b->unk10 = 1;
                b->unk8 = sgn * aa;
                b->unk0 = sx * 94.0f + ox;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801F9EA0.s")
#endif

#ifdef NON_MATCHING
// Score 5665 of 61800: face is zeroed after the position is set (inside the drawn-rider branch). Left: the first
// two rider loops count by 1, where the original counts a second induction variable in 0x14-byte steps against
// gRiders * 20 (written that way, the frame and loop tests match but the guards and registers do not). Each loop with
// its own counter is closest; the original keeps the first two counters in s3.
extern Gfx D_10147C8[];
extern Gfx D_10149F8[];
extern u8 D_10448D0[];

// Draw the radar: a white square, an arrow and a face per rider other than the player.
void func_801FA3C0(Gfx** gdlp) {
    Gfx* gdl;
    UnkStruct_80228B88* b;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 x;
    s32 y;
    s32 face;

    gdl = *gdlp;
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdl++, G_SHADE);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE);
    gDPSetCombineMode(gdl++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gdl++, IM_RD | CVG_DST_FULL | CVG_X_ALPHA | FORCE_BL | GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                     GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gDPSetFillColor(gdl++, 0xFFFFFFFF);
    for (i = 0; i < gPlayers; i++) {
        for (k = 0; k < gRiders; k++) {
            b = &D_80228B88[i][k];
            if (b->unk10 != 0) {
                if (gPlayers == ONE_PLAYER) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 190.0f;
                } else if (i == 0) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 96.0f;
                } else {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 206.0f;
                }
                gDPFillRectangle(gdl++, x - 10, y - 10, x + 10, y + 10);
            }
        }
    }
    gSPDisplayList(gdl++, D_10147C8);
    gDPSetEnvColor(gdl++, D_80228AAC, D_80228AB0, D_80228AB4, 255);
    gDPLoadTextureBlock(gdl++, D_10448D0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPMatrix(gdl++, &D_5000000->unk4040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    for (i = 0; i < gPlayers; i++) {
        for (l = 0; l < gRiders; l++) {
            b = &D_80228B88[i][l];
            if (b->unk10 != 0) {
                if (gPlayers == ONE_PLAYER) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 190.0f;
                } else if (i == 0) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 96.0f;
                } else {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 206.0f;
                }
                func_801EDFFC(&D_801AE948->unk4140[D_801AE950], x, y, 0.0f);
                gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                func_801EE228(&D_801AE948->unk4140[D_801AE950], -b->unk8, 0.0f, 0.0f, 1.0f);
                gSPMatrix(gdl++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                gSPDisplayList(gdl++, D_10149F8);
            }
        }
    }
    gDPPipeSync(gdl++);
    gDPSetTexturePersp(gdl++, G_TP_NONE);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    for (i = 0; i < gPlayers; i++) {
        for (j = 0; j < gRiders; j++) {
            b = &D_80228B88[i][j];
            if (b->unk10 != 0) {
                if (gPlayers == ONE_PLAYER) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 190.0f;
                } else if (i == 0) {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 96.0f;
                } else {
                    x = b->unk0 + 160.0f;
                    y = b->unk4 + 206.0f;
                }
                face = 0;
                if ((gPlayers == TWO_PLAYERS) &&
                    (((j == gPlayer1Rider) && (D_801CE6F4[0] != 0)) || ((j == gPlayer2Rider) && (D_801CE6F4[1] != 0)))) {
                    face = 4;
                }
                gDPLoadTextureBlock(gdl++, gPortraitFaces[D_80192690[j].unkB68 + face], G_IM_FMT_RGBA, G_IM_SIZ_16b,
                                    20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                x -= 5;
                y -= 5;
                gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 10) << 2, (y + 10) << 2, G_TX_RENDERTILE, 0, 0,
                                    2 << 10, 2 << 10);
            }
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FA3C0.s")
#endif

// Rasterise a line from (x0, y0) to (x1, y1) (Bresenham): writes the points into xs/ys and their count.
void func_801FAD68(s32 x0, s32 y0, s32 x1, s32 y1, s32* count, s32* xs, s32* ys) {
    s32 dx;
    s32 dy;
    s32 adx;
    s32 ady;
    s32 sx;
    s32 sy;
    s32 err;
    s32 x;
    s32 y;
    s32 n;

    dx = adx = x1 - x0;
    dy = ady = y1 - y0;
    sx = SIGNUM(dx);
    sy = SIGNUM(dy);
    err = 0;
    if (dx < 0) {
        adx = -dx;
    }
    if (dy < 0) {
        ady = -dy;
    }
    x = x0;
    y = y0;
    xs[0] = x;
    ys[0] = y;
    n = 1;
    if (adx >= ady) {
        while (x != x1) {
            err += ady;
            x += sx;
            if (err * 2 >= adx) {
                err -= adx;
                y += sy;
            }
            xs[n] = x;
            ys[n] = y;
            n++;
        }
    } else {
        while (y != y1) {
            err += adx;
            y += sy;
            if (err * 2 >= ady) {
                err -= ady;
                x += sx;
            }
            xs[n] = x;
            ys[n] = y;
            n++;
        }
    }
    *count = n;
}

void func_801FAEA8(void) {
}

// From here on, the code splat had split off as C94E0.c (0xC94E0): its strings and float constants sit
// between BCFF0's in the one .rodata block at 0x802279D0, so both are one translation unit.

extern Vp D_1014450;
extern s32 gPlayer2Rider;
extern s32 D_801C1FD8;
extern struct RiderStruct gRiderRaceState[];
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

s32 func_801F2060(Gfx**); // void in effect; s32 for its set-aside's FAKE return type (see its note)
void func_801FAEB8(Gfx**);
void func_801FB514(Gfx**);
void func_801FBFB4(Gfx**);

void func_801FAEB0(s32 arg0) {
}

#ifdef NON_MATCHING
// Score 445 of 37200: only the three hoisted float constants take other saved FP registers (the original: 1.0f in f24,
// 3.0f in f22, 1.3f in f20; here 3.0f, 1.3f, 1.0f in that order).
extern u8 D_80227744[][3];
extern u8 D_80227754[][3];
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
    s32 step;
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
    s32 next;

    gdl = *gdlp;
    for (i = 0; i < gPlayers; i++) {
        if (i == 0) {
            rider = &gRiderRaceState[gPlayer1Rider];
        } else {
            rider = &gRiderRaceState[gPlayer2Rider];
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
            step = D_80228B68[i];
            next = step + 1;
            r0 = D_80227744[step][0] * f + D_80227744[next][0] * g;
            g0 = D_80227744[step][1] * f + D_80227744[next][1] * g;
            b0 = D_80227744[step][2] * f + D_80227744[next][2] * g;
            r1 = D_80227754[step][0] * f + D_80227754[next][0] * g;
            g1 = D_80227754[step][1] * f + D_80227754[next][1] * g;
            b1 = D_80227754[step][2] * f + D_80227754[next][2] * g;
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
                    scale = 1.3f;
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
                gdl = Printer_PrintScaled(gdl, 0, "LAP", x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1, g1, b1, scale);
                sprintf((char*) D_80228CF8, "%d", rider->lapCount);
                gdl = Printer_DrawString(gdl, 0, (char*) D_80228CF8, x + w, y);
            } else {
                x = 100;
                if (gPlayers == ONE_PLAYER) {
                    x = 82;
                    y = 70;
                    w = 98;
                    scale = 1.3f;
                } else {
                    scale = 1.0f;
                    w = 77;
                    if (i == 0) {
                        y = 40;
                    } else {
                        y = 150;
                    }
                }
                gdl = Printer_DrawString(Printer_PrintScaled(gdl, 0, "FINAL", x, y, 2, r0, g0, b0, r0, g0, b0, r1, g1, b1, r1,
                                                  g1, b1, scale),
                                    0, "LAP", x + w, y);
            }
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FAEB8.s")
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
// Score 11823 of 68000: calls and branches agree (the fade-out alpha is an if / else-if / else chain, giving the
// original's b-to-next). The original keeps the unused (2 - D_80228D18) / 2.0f and 1.0f - f (IDO deletes them here;
// as dead stores, expression statements, register or volatile they stay deleted or turn into stores), so every temp
// after the prologue is renumbered; our frame is 0xB0 against 0xB8.
extern u8 D_80246D0[];
extern u8 D_8024858[];
extern u8 D_8024A40[];
extern u8 D_80269D0[];
extern s32 D_801C26E4;
extern s32 D_80228A94;

// Draw the stunt-score popups (D_80228AE0) and add them to the stunt totals as they finish.
void func_801FB514(Gfx** gdlp) {
    Gfx* gdl;
    UnkStruct_80228AE0* p;
    f32 f;
    f32 g;
    s32 w;
    s32 x;
    s32 y;
    s32 alpha;
    s32 n;
    s32 count;
    s32 k;
    s8* digit;
    u8* img;

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
        } else if (p->unk8 >= 20) {
            alpha = (23 - p->unk8) * 255 / 4;
        } else {
            alpha = 255;
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
        gdl = Printer_Print(Printer_Print(gdl, 0, "TIME", 80, 60, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 0,
                            "EXTEND", 153, 60, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    if ((D_80227740 != 0) && (D_801C26E4 != 0)) {
        sprintf((char*) D_80228CF8, "%04d", D_801C26E4);
        gdl = Printer_Print(gdl, 0, (char*) D_80228CF8, 224, 188, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FB514.s")
#endif

#ifdef NON_MATCHING
// Score 5485 of 25000: x * 4 (an int literal, a separate constant to IDO; from a literal search) in the first
// rectangle coordinate. Left: w is in s3 in the original (v1 here); the original sets tex and w = 96 after reading
// D_80228E08[i] (here tex is hoisted to the loop top unless case 1 sets them); the inner loop recomputes w << 3 where
// IDO here hoists it. A 12-byte pad gives the original's frame (0xE0) and spill slots.
extern Gfx D_10146B0[];
extern u32 D_804C008[];
extern u32 D_804F010[];
extern u32 D_8052018[];

void func_801FBFB4(Gfx** gdlp) {
    Gfx* gdl;
    s32 i;
    s32 pad[3]; // stack pad: the frame is 0xE0 as in the original
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

    gdl = *gdlp;
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
        if (D_80228E08[i] < 6) {
            scale = (D_80228E08[i] / 5.0f) * 1.3f;
        } else {
            scale = 1.0f;
        }
        switch (D_80228E00[i]) {
            case 1:
                tex = D_804F010;
                w = 96;
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
            gSPTextureRectangle(gdl++, (s32) (x * 4), (s32) (y * 4.0f), (s32) ((x + width) * 4.0f), // odd literal: int 4
                                (s32) (nextY * 4.0f), G_TX_RENDERTILE, 0, 0, (s32) ((w << 10) / width),
                                (s32) (32768.0f / height));
            y = nextY;
        }
    }
    *gdlp = gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/BCFF0/func_801FBFB4.s")
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
    s32 pad; // stack pad
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
            gRiderRaceState[gPlayer1Rider].raceTime += 0x32;
            *arg0 = sp2C;
            return;
        }
        if (((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS)) && (gGameModeState == 3) &&
            (gCourseID != DOLPHIN_PARK) && (D_801C1FD8 == 0)) {
            func_801FA3C0(&sp2C);
        }
        if (((gGameModeState != 3) || (gStartLightsState == 2)) && (gRiderRaceState[gPlayer1Rider].finishState == 0) &&
            ((gPlayers != TWO_PLAYERS) || (gRiderRaceState[gPlayer2Rider].finishState == 0))) {
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
