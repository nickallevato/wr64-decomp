#include "common.h"

/* An animation in segment 8 (D_80B0E28, D_80B1550): eight objects' key indices per frame */
typedef struct {
    /* 0x00 */ s16 frameCount;
    /* 0x04 */ u32 keys;      // segmented, UnkStruct_i5_802C7B80[]
    /* 0x08 */ u32 frames[8]; // segmented, s16[frameCount] per object
} UnkStruct_i5_802C7B38;      // size = 0x28

/* One key of an animated object: position * 10, then two direction vectors */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s8 fx;
    /* 0x7 */ s8 fy;
    /* 0x8 */ s8 fz;
    /* 0x9 */ s8 ux;
    /* 0xA */ s8 uy;
    /* 0xB */ s8 uz;
} UnkStruct_i5_802C7B80; // size = 0xC

extern Gfx D_106F6C0[];
extern Mtx D_7001380[];
extern Gfx* D_i5_802C7AA8[];
extern s32 D_i5_802C7AA0;
extern s32 D_i5_802C7AC8;
extern s32 D_i5_802C7ACC;
extern s32 D_i5_802C7AD0;
extern f32 D_i5_802C7B10[8];
extern s32 D_i5_802C7B30;
extern s32 D_i5_802C7B34;
extern UnkStruct_i5_802C7B38* D_i5_802C7B38[2];
extern s16* D_i5_802C7B40[2][8];
extern UnkStruct_i5_802C7B80* D_i5_802C7B80[2];
extern s32 D_i5_802C7B88;
extern s32 D_i5_802C7B8C;
extern s32 D_i5_802C7B90;
extern Mtx D_8011F820;
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern const s16 D_800EABBC[][8];
extern const s16 D_800EAC14[][8];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern u8 D_80B0E28[];
extern u8 D_80B1550[];

Gfx* func_80094A44(Gfx*, s32);
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);
void func_801EC830(void);
void Water_StampPoint(f32, f32, s32);
void func_801E4C60(Mtx* mtx, f32 fx, f32 fy, f32 fz, f32 ux, f32 uy, f32 uz, f32 x, f32 y, f32 z, f32 scale);
Gfx* NotQualified_DrawObjects(Gfx* gdl);
Gfx* NotQualified_DrawPanels(Gfx* gdl);
void NotQualified_Update(void);

void NotQualified_UpdateAnimation(void) {
    s32 i;
    s32 j;
    s32 anim;
    s32 course;
    s16* row;
    s32 idx;
    UnkStruct_i5_802C7B80* key;
    f32 x;
    f32 y;
    f32 z;

    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_5A)) {
        D_i5_802C7B30 = D_801CB340[gPlayer1Rider];
        D_i5_802C7B34 = D_800EABBC[gDifficulty][D_801CB334];
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                D_i5_802C7B38[i] = (UnkStruct_i5_802C7B38*) SegmentedToVirtual((u32) D_80B0E28);
            } else {
                D_i5_802C7B38[i] = (UnkStruct_i5_802C7B38*) SegmentedToVirtual((u32) D_80B1550);
            }
            for (j = 0; j < 8; j++) {
                D_i5_802C7B40[i][j] = (s16*) SegmentedToVirtual(D_i5_802C7B38[i]->frames[j]);
            }
            D_i5_802C7B80[i] = (UnkStruct_i5_802C7B80*) SegmentedToVirtual(D_i5_802C7B38[i]->keys);
        }
        D_i5_802C7B8C = D_i5_802C7B90 = 0;
        for (j = 0; j < D_801CB334 + 1; j++) {
            course = D_800EAC14[gDifficulty][j];
            if (D_801C2660[course] != 0) {
                D_i5_802C7B8C = 1;
            }
            if (D_801C2690[course] != 0) {
                D_i5_802C7B90 = 1;
            }
        }
        j = 0;
        do { // a for loop unrolls with the stores rotated
            D_i5_802C7B10[j] = 0.0f;
            j++;
        } while (j < 8);
    }

    if ((D_i5_802C7AC8 != 2) && (D_i5_802C7AC8 != 3)) {
        anim = 1;
    } else {
        anim = 0;
    }
    for (j = 0; j < 8; j++) {
        row = D_i5_802C7B40[anim][j];
        row += D_i5_802C7AA0;
        idx = *row;
        key = D_i5_802C7B80[anim];
        key += idx;
        x = key->x / 10.0f;
        y = key->y / 10.0f;
        z = key->z / 10.0f;
        // `== 0` (int): with 0.0f IDO reuses the register of the `y >= 0.0f` constant
        if ((y >= 0.0f) && (D_i5_802C7B10[j] == 0) && (D_i5_802C7AA0 > 0)) {
            D_i5_802C7B10[j] = 1.0f;
            Water_StampPoint(x, z, 50);
        }
        func_801E4C60(&D_801CE5F8->unk1380[j], key->fx, key->fy, key->fz, key->ux, key->uy, key->uz, x, y, z, 0.05f);
    }
}

Gfx* NotQualified_Draw(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    gdl = func_80093F78(gdl);
    D_800DAB2C = 0;
    gdl = func_800949B8(gdl, gCourseID);
    gdl = func_8008FB74(gdl);
    if ((D_i5_802C7AC8 == 2) || (D_i5_802C7AC8 == 3) || (D_i5_802C7AC8 == 4)) {
        gdl = NotQualified_DrawObjects(gdl);
    }
    gSPMatrix(gdl++, &D_8011F820, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_80094A44(gdl, gCourseID);
    gdl = Draw_WaterEffects(gdl);
    gdl = NotQualified_DrawPanels(gdl);
    if (gGameState == GAME_STATE_5A) {
        NotQualified_Update();
    } else if (D_80228A16 == 1) {
        GameState_EnterTitleScreen();
    }
    return gdl;
}

Gfx* NotQualified_DrawObjects(Gfx* gdl) {
    s32 i;

    gSPDisplayList(gdl++, D_106F6C0);
    for (i = 0; i < 8; i++) {
        gSPMatrix(gdl++, &D_7001380[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gdl++, D_i5_802C7AA8[i]);
    }
    return gdl;
}

Gfx* NotQualified_DrawPanels(Gfx* gdl) {
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, D_i5_802C7ACC, 145, 208, 15);
    gdl = func_80094338(gdl, 0, D_i5_802C7AD0, 166, 208, 15);
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 1, 6, D_i5_802C7ACC + 10, 147, 0);
    gdl = TexLabel_Draw(gdl, 1, 7, D_i5_802C7AD0 + 10, 168, 0);
    gdl = Printer_DrawNumber(gdl, 2, D_i5_802C7B34, D_i5_802C7ACC + 186, 147);
    gdl = Printer_DrawNumber(gdl, 2, D_i5_802C7B30, D_i5_802C7AD0 + 186, 168);
    return gdl;
}

void NotQualified_Update(void) {
    s32 done;

    switch (D_i5_802C7AC8) {
        case 0:
            D_i5_802C7ACC -= 30;
            if (D_i5_802C7ACC < 56) {
                D_i5_802C7AC8 = 1;
                D_i5_802C7ACC = 56;
            }
            break;

        case 1:
            D_i5_802C7AC8 = 2;
            break;

        case 2:
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == D_i5_802C7B38[0]->frameCount) {
                D_i5_802C7AA0--;
                D_i5_802C7AC8 = 3;
            }
            break;

        case 3:
            if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
                D_i5_802C7AC8 = 4;
                D_i5_802C7AA0 = 0;
                D_i5_802C7B88 = 0;
            }
            break;

        case 4:
            done = 0;
            D_i5_802C7ACC -= 30;
            if (D_i5_802C7ACC < -208) {
                done = 1;
                D_i5_802C7ACC = -208;
            }
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == D_i5_802C7B38[1]->frameCount) {
                done++;
                D_i5_802C7AA0--;
            }
            if (done == 2) {
                D_i5_802C7B88++;
            }
            if (D_i5_802C7B88 >= 4) {
                if ((D_i5_802C7B8C != 0) || (D_i5_802C7B90 != 0)) {
                    func_801EC9C8();
                } else {
                    func_801EC830();
                }
            }
            break;
    }
    D_i5_802C7AD0 = 112 - D_i5_802C7ACC;
}

void func_i5_802C79F4(void) {
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
