#include "global.h"

// A 0x14-byte record entry; unk10 receives the entered initials. func_801E2C14 also
// clears unk10[4], which is the first byte of the next entry.
typedef struct UnkStruct_AF8C0_14 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s8 unk10[4];
} UnkStruct_AF8C0_14; // size = 0x14

// A 0x10-byte record entry; unkC receives the entered initials (and unkC[4], as above).
typedef struct UnkStruct_AF8C0_10 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8 unkC[4];
} UnkStruct_AF8C0_10; // size = 0x10

extern s32 gVIsPerFrame;
extern s32 D_800DAB1C;
extern s32 D_801CE630;
extern s32 gPrevGameState;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;
extern s32 D_801CB334;
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern const s16 D_800EAC14[][8];
extern Mtx D_8011F820;
extern Gfx D_106F6C0[];
extern Gfx* D_80226040[];
extern s32 D_802261F8;
extern s32 D_802287E0;
extern s32 D_802287E4;
extern s32 D_802287E8[];
extern s8 D_80226130[];
extern s32 D_80226150[];
extern s32 D_802261E4;
extern s32 D_802261E8;
extern Gfx* D_802261EC[];
extern s8 D_802288E8[];
extern s16 D_800DAB6C;
extern UnkStruct_AF8C0_14 D_801C1FF0[][3];
extern UnkStruct_AF8C0_14 D_801C22C0[];
extern UnkStruct_AF8C0_14 D_801C23B0[];
extern UnkStruct_AF8C0_10 D_801C26E8[][3];

s32 func_8007BEA4(s32);
s32 func_8007C204(s32);
void func_8006DE24(Gfx**);
Gfx* func_80094A44(Gfx*, s32);
void func_801EC500(void);
Gfx* func_801E2058(Gfx*);
Gfx* func_801E229C(Gfx*);
void func_801E2530(void);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1290.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1BA8.s")

Gfx* func_801E1E8C(Gfx* gdl) {
    s32 i;
    s16 course;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    gdl = func_801E2058(func_8008FB74(func_80093F78(gdl)));
    gSPMatrix(gdl++, &D_8011F820, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gdl = func_801E229C(Draw_WaterEffects(func_80094A44(gdl, gCourseID)));
    if (gGameState == GAME_STATE_64) {
        func_801E2530();
    } else if (D_80228A16 == 1) {
        if (D_801CE608.gameMode == 4) {
            for (i = 0; i < D_801CB334 + 1; i++) {
                course = D_800EAC14[gDifficulty][i];
                if ((D_801C2660[course] != 0) || (D_801C2690[course] != 0)) {
                    if (D_800DAB68 != 0) {
                        func_8007C204(course);
                    } else {
                        func_8007BEA4(course);
                    }
                }
            }
        }
        func_801EC500();
    }
    return gdl;
}

Gfx* func_801E2058(Gfx* gdl) {
    s32 i;
    s32 wrap;
    s32 draw;

    gdl = func_800949B8(gdl, gCourseID);
    gSPDisplayList(gdl++, D_106F6C0);
    if (D_802261F8 != 0) {
        func_8006DE24(&gdl);
    }
    if (D_802287E0 < D_802287E4) {
        wrap = 0;
    } else {
        wrap = 1;
    }
    for (i = 0; i < 16; i += 2) {
        draw = 0;
        if (wrap == 0) {
            if ((i >= D_802287E0) && (i <= D_802287E4)) {
                draw = 1;
            }
        } else if ((i >= D_802287E0) || (i <= D_802287E4)) {
            draw = 1;
            if (1) {} // FAKE
            if (1) {}
            if (1) {}
            if (1) {}
        }
        if (draw != 0) {
            gSPMatrix(gdl++, &D_801CE5F8->unk1380[i], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(gdl++, D_80226040[D_802287E8[i]]);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
        draw = 0;
        if (wrap == 0) {
            if ((i >= D_802287E0 - 1) && (i < D_802287E4)) {
                draw = 1;
            }
        } else if ((i >= D_802287E0 - 1) || (i < D_802287E4)) {
            draw = 1;
        }
        if (draw) {
            gSPMatrix(gdl++, &D_801CE5F8->unk1380[i + 1], G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_PUSH);
            gSPDisplayList(gdl++, D_80226040[D_802287E8[i + 1]]);
            gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
        }
    }
    return gdl;
}

Gfx* func_801E229C(Gfx* gdl) {
    s32 mode;
    s32 i;
    s32 j;
    s32 offset;
    s8 str[2];

    if (D_802261E8 == 0) {
        return gdl;
    }
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 0x36, 0x20, 0xD3, 0x18);
    gdl = func_80094338(gdl, 0, 0x65, 0xB1, 0x75, 0x1C);
    for (i = 0; i < 3; i++) {
        mode = (i == D_802261E4) ? 6 : 0;
        gdl = func_801E946C(gdl, mode, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPDisplayList(gdl++, D_802261EC[i]);
    }
    gdl = func_801E946C(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    gdl = func_801E3EE0(gdl, 2, 0x1D, 0x48, 0x23, 0);
    for (i = 0; i < 3; i++) {
        str[1] = 0;
        str[0] = D_802288E8[i];
        for (j = 0; j < 29; j++) {
            if (str[0] == D_80226130[j]) {
                break;
            }
        }
        if (j == 29) {
            offset = 0;
        } else {
            offset = D_80226150[j];
        }
        gdl = func_801E9858(gdl, 0, (char*) str, i * 26 + offset + 0x7A, 0xB4);
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226210.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226214.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226218.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022621C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226220.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226224.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226228.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022622C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226230.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226234.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226238.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022623C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226240.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226244.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226248.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022624C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226250.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226254.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226258.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022625C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226260.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226264.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226268.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022626C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226270.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226274.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226278.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022627C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226280.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2530.s")

void func_801E2B8C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = GAME_STATE_65;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;
    FadeTransition_SetProps(1, 0xE, 0x14);
}

void func_801E2C14(void) {
    s32 i;
    s32 j;
    s32 course;

    if (D_802288E8[0] == 0) {
        for (i = 0; i < 3; i++) {
            D_802288E8[i] = D_801CB298[D_800DA9B0[0]].unk_0[i];
        }
        D_802288E8[i] = 0;
        D_800DAB6C = 1;
    }
    if (D_801CE608.gameMode == 4) {
        for (j = 0; j < D_801CB334 + 1; j++) {
            course = D_800EAC14[gDifficulty][j];
            if (D_801C2660[course] != 0) {
                for (i = 0; i < 4; i++) {
                    if (D_800DAB68 != 0) {
                        D_801C23B0[course].unk10[i] = D_802288E8[i];
                    } else {
                        D_801C1FF0[course][D_801C2660[course] - 1].unk10[i] = D_802288E8[i];
                    }
                }
                if (D_800DAB68 != 0) {
                    D_801C23B0[course].unk10[i] = 0;
                } else {
                    D_801C1FF0[course][D_801C2660[course] - 1].unk10[i] = 0;
                }
            }
            if (D_801C2690[course] != 0) {
                for (i = 0; i < 4; i++) {
                    D_801C22C0[course].unk10[i] = D_802288E8[i];
                }
                D_801C22C0[course].unk10[i] = 0;
            }
        }
    } else if (D_801CE608.gameMode == 11) {
        if (D_801C2928 != 0) {
            for (i = 0; i < 4; i++) {
                D_801C26E8[gCourseID][D_801C2928 - 1].unkC[i] = D_802288E8[i];
            }
            D_801C26E8[gCourseID][D_801C2928 - 1].unkC[i] = 0;
        }
    } else {
        if (D_801C2660[gCourseID] != 0) {
            for (i = 0; i < 4; i++) {
                if (D_800DAB68 != 0) {
                    D_801C23B0[gCourseID].unk10[i] = D_802288E8[i];
                } else {
                    D_801C1FF0[gCourseID][D_801C2660[gCourseID] - 1].unk10[i] = D_802288E8[i];
                }
            }
            if (D_800DAB68 != 0) {
                D_801C23B0[gCourseID].unk10[i] = 0;
            } else {
                D_801C1FF0[gCourseID][D_801C2660[gCourseID] - 1].unk10[i] = 0;
            }
        }
        if (D_801C2690[gCourseID] != 0) {
            for (i = 0; i < 4; i++) {
                D_801C22C0[gCourseID].unk10[i] = D_802288E8[i];
            }
            D_801C22C0[gCourseID].unk10[i] = 0;
        }
    }
}
