#include "global.h"

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E229C.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2C14.s")
