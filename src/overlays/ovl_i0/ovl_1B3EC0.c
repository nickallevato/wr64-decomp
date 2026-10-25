#include "libc/stdio.h"
#include "global.h"
#include "rider.h"

void func_i0_802C6878(void);
void func_i0_802C6A1C(s32 arg0);
Gfx* func_i0_802C6AE4(Gfx*);
void GameState_EnterDemo(void);
extern s32 D_801519D4;
extern s32 D_80154344;
extern s32 D_805AF88;
extern s32 D_802C6F08;
extern s32 D_802C6F0C;

typedef struct {
    /* 0x00 */ s16 unk0; // -1, or the index of the menu it opens in D_i0_802C6E08
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s32 gameMode;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s16 player;
    /* 0x12 */ s16 rider;
    /* 0x14 */ s16 difficulty;
    /* 0x16 */ s16 unk16;
} UnkStruct_i0_802C6C28; // size = 0x18

typedef struct {
    /* 0x00 */ UnkStruct_i0_802C6C28* items;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} UnkStruct_i0_802C6E08; // size = 0x18

typedef struct {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 width;
    /* 0x8 */ s32 id;
} UnkStruct_i0_802C6BF0; // size = 0xC

s32 D_i0_802C6BC0 = 0;
s32 D_i0_802C6BC4 = 0;
s32 D_i0_802C6BC8 = 0;
s32 D_i0_802C6BCC = 0;
s32 D_i0_802C6BD0 = 78;
s32 D_i0_802C6BD4[3] = { 1, 0, 0 };
s32 D_i0_802C6BE0 = 0;
s32 D_i0_802C6BE4 = 0;
s32 D_i0_802C6BE8 = 0;
s32 D_i0_802C6BEC = 0;
UnkStruct_i0_802C6BF0 D_i0_802C6BF0[2] = { { 311, 392, 30 }, { 703, 424, 31 } };
// Nothing refers to these by name.
s16 D_i0_802C6C08[16] = { 0, 0, 2, 2, 2, 1, 1, 1, 8, 8, 8, 8, 8, 8, 8, 0 };

UnkStruct_i0_802C6C28 D_i0_802C6C28[5] = {
    { 1, 0, -1, 18, 14, 0, 0, 0, 3 }, { -1, 0, 0, 19, 23, 1, 1, 0, 0 }, { -1, 0, 11, 59, 22, 1, 1, 2, 0 },
    { -1, 0, 1, 20, 43, 2, 2, 0, 0 }, { -1, 0, 5, 21, 34, 1, 1, 0, 0 },
};

UnkStruct_i0_802C6C28 D_i0_802C6CA0[3] = {
    { 2, 0, 4, 22, 35, 0, 0, 0, 1 },
    { -1, 0, 4, 23, 43, 1, 4, 1, 0 },
    { -1, 0, 4, 24, 35, 1, 4, 2, 0 },
};

UnkStruct_i0_802C6C28 D_i0_802C6CE8[2] = {
    { -1, 0, 4, 70, 29, 1, 1, 0, 0 },
    { -1, 0, 4, 69, 4, 1, 4, 0, 2 },
};

UnkStruct_i0_802C6C28 D_i0_802C6D18[3] = {
    { -1, 0, 0, 22, 35, 1, 1, 0, 0 },
    { -1, 0, 0, 23, 43, 1, 1, 1, 0 },
    { -1, 0, 0, 24, 35, 1, 1, 2, 0 },
};

UnkStruct_i0_802C6C28 D_i0_802C6D60[3] = {
    { -1, 0, 1, 22, 35, 2, 2, 0, 0 },
    { -1, 0, 1, 23, 43, 2, 2, 1, 0 },
    { -1, 0, 1, 24, 35, 2, 2, 2, 0 },
};

UnkStruct_i0_802C6C28 D_i0_802C6DA8[4] = {
    { 2, 0, 4, 22, 35, 0, 0, 0, 0 },
    { -1, 0, 4, 23, 43, 1, 4, 1, 0 },
    { -1, 0, 4, 24, 35, 1, 4, 2, 0 },
    { -1, 0, 4, 89, 33, 1, 4, 2, 4 },
};

UnkStruct_i0_802C6E08 D_i0_802C6E08[6] = {
    { D_i0_802C6C28, 5, 5, 98, 78, 0 }, { D_i0_802C6CA0, 3, 1, 98, 78, 1 }, { D_i0_802C6CE8, 2, 2, 98, 78, 0 },
    { D_i0_802C6D18, 3, 1, 98, 78, 1 }, { D_i0_802C6D60, 3, 1, 98, 78, 1 }, { D_i0_802C6DA8, 4, 4, 98, 78, 0 },
};

Gfx* func_i0_802C5800(Gfx* arg0) {

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (D_80154344 == 0) {
            D_i0_802C6BEC = 1;
        }

        arg0 = func_80093C44(arg0);
        return arg0;
    }
    arg0 = func_8009328C(arg0);

    gSPDisplayList(arg0++, &D_805AF88);
    gSPDisplayList(arg0++, &D_106F168);

    if (D_i0_802C6BC4 != 0) {
        char buf[10];

        arg0 = Printer_SetMode(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(buf, "%8XH", D_801519D4);
        arg0 = Printer_DrawString(arg0, 1, buf, 0x1C, 0x28);
        sprintf(buf, "%dKB", (s32) D_801519D4 / 1024);
        arg0 = Printer_DrawString(arg0, 1, buf, 0x1C, 0x3C);
    }
    if (D_i0_802C6BEC != 0) {
        arg0 = func_i0_802C6AE4(
            Printer_SetMode(arg0, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
    }
    if (D_i0_802C6BC8 < 0x14) {
        D_i0_802C6BC8 = D_i0_802C6BC8 + 1;
        if (D_i0_802C6BC8 == 0x14) {
            gRiderGameModes = AI_MODE;
        }
    }
    if ((D_801CE65A->unk0 & 0xB000) || (D_800DAB0C != 0)) {
        D_800DAB0C = 0;
        func_i0_802C6878();
    }
    SysUtils_Rand();
    return arg0;
}

void stub_func_i0_802C5800() {
}

Gfx* func_i0_802C6044(Gfx* gdl);
void func_i0_802C63AC(void);
extern Gfx D_805A6F8[];
extern u8 D_803D610[];

Gfx* func_i0_802C5A7C(Gfx* gdl) {
    s32 i;
    s32 y;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        D_802C6F08 = 1;
        if (D_801CB280 & 1) {
            D_802C6F08++;
            D_i0_802C6BD4[1] = 1;
        }
        if (D_801CB280 & 2) {
            D_802C6F08++;
            D_i0_802C6BD4[2] = 1;
        }
        if (D_801CB280 & 8) {
            D_i0_802C6BC0 = 1;
        }
    }
    gdl = func_8009328C(gdl);
    switch (D_i0_802C6BE0) {
        case 0:
            gSPDisplayList(gdl++, D_805A6F8);
            gdl = Printer_SetMode(
                Printer_SetMode(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF), 0,
                0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            if (D_i0_802C6BEC == 0) {
                y = 166;
            } else {
                y = 140;
            }
            gdl = func_801E3EE0(gdl, 1, 88, 95, y + 20, 2);
            gDPLoadTextureBlock(gdl++, D_803D610, G_IM_FMT_IA, G_IM_SIZ_8b, 256, 6, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0,
                                0);
            gSPTextureRectangle(gdl++, 32 << 2, (y + 44) << 2, 288 << 2, (y + 50) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            if ((D_i0_802C6BEC == 0) && (D_i0_802C6BE8 == 20)) {
                if ((D_i0_802C6BE4 % 30) < 20) {
                    gdl = func_801E3EE0(
                        Printer_SetMode(gdl, 7, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF), 1,
                        86, 94, 166, 2);
                }
                D_i0_802C6BE4++;
                if (D_i0_802C6BE4 >= 30) {
                    D_i0_802C6BE4 = 0;
                }
            }
            gSPDisplayList(gdl++, D_106F168);
            break;
        case 1:
            gdl = func_i0_802C6044(gdl);
            gSPDisplayList(gdl++, D_106F168);
            for (i = 0; i < D_802C6F0C; i++) {
                gDPFillRectangle(gdl++, 89, D_i0_802C6BD0 + i * 20 - 3, 231, D_i0_802C6BD0 + i * 20 + 14);
            }
            break;
    }
    if (D_i0_802C6BEC != 0) {
        gdl = func_i0_802C6AE4(
            Printer_SetMode(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF));
    }
    if (D_i0_802C6BC8 < 20) {
        D_i0_802C6BC8 = D_i0_802C6BC8 + 1;
        if (D_i0_802C6BC8 == 20) {
            gRiderGameModes = AI_MODE;
        }
    }
    switch (D_i0_802C6BE0) {
        case 0:
            if (D_i0_802C6BE8 < 20) {
                D_i0_802C6BE8++;
            }
            if ((D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) && (D_i0_802C6BE8 == 20)) {
                D_i0_802C6BE0 = 1;
                D_802C6F14 = 0;
                AudioGeneral_PlaySound(0x11, 0);
            } else {
                D_802C6F14++;
                if (D_802C6F14 >= 600) {
                    func_i0_802C6A1C(7);
                }
            }
            break;
        case 1:
            func_i0_802C63AC();
            break;
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C6044.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i0/ovl_1B3EC0/func_i0_802C63AC.s")

void func_i0_802C6878(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 3;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    D_802C6EE4 = D_800DA9D8;
    D_802C6EE0 = 0;

    Printer_ResetColorCycle();
    Popup_Spawn(0, 0);
    Popup_Spawn(3, 0);
    Popup_Spawn(3, 1);

    D_i0_802C6BE0 = 0;
    D_802C6F14 = 0;

    AudioGeneral_PlaySound(0x2D, 0);
}

Gfx* func_i0_802C6944(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    arg0 = func_8009328C(arg0);
    gSPDisplayList(arg0++, &D_106F168);

    if (D_80228A16 == 1) {
        switch (D_801CE630) { /* irregular */
            case 0xA:
                GameState_EnterRiderSelect();
                break;
            case 0x3C:
                GameState_EnterOptionsMenu();
                break;
            case 0x2:
                GameState_EnterTitleScreen();
                break;
            case 0x7:
                GameState_EnterDemo();
                break;
        }
    }
    return arg0;
}

void func_i0_802C6A1C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 4;
    D_801CE638 = 0;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    FadeTransition_SetProps(1, 4, 0);
    Popup_Spawn(0, 0);

    if (D_801CE630 == 10) {
        func_800C1F60(1);
        return;
    }

    if (D_801CE630 == 60) {
        func_800C1F60(9);
    }
}

Gfx* func_i0_802C6AE4(Gfx* gdl) {
    s32 i;
    s32 gone = 0;
    UnkStruct_i0_802C6BF0* item;

    for (i = 0, item = D_i0_802C6BF0; i < 2; i++, item++) {
        item->x -= 2;
        if (item->x >= 8 - item->width) {
            gdl = func_801E3EE0(gdl, 3, item->id, item->x, 196, 6);
        } else {
            gone++;
        }
    }
    if (gone == 2) {
        D_i0_802C6BF0[0].x = 311;
        D_i0_802C6BF0[1].x = 703;
    }
    return gdl;
}
