#include "course.h"
#include "common.h"

Gfx* func_1C3D00_802C58DC(Gfx*);
void func_1C3D00_802C5D44(void);
void func_1C3D00_802C5E10(void);
Gfx* func_80093C44(Gfx*);
Gfx* Printer_DrawNumber(Gfx* gdl, s32 font, s32 value, s32 x, s32 y);

extern s16 D_80228A16;
extern s32 D_802C5EF0;
extern TexLabel D_1C3D00_802C5EB0[];
extern s32 D_801CB3F0[2];

Gfx* func_1C3D00_802C5800(Gfx* gDisplayListHead) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x36) {
            D_802C5EF0 = 0;
            osViBlack(false);
            return func_80093C44(gDisplayListHead);
        }
    }
    D_800DAB2C = 0;
    gDisplayListHead =
        func_1C3D00_802C58DC(Draw_WaterEffects(func_800949B8(func_8008FB74(gDisplayListHead), gCourseID)));
    if (gGameState == 0x36) {
        if (D_80228A16 == 1) {
            func_800C30F8();
        }
        func_1C3D00_802C5D44();
    } else {
        func_1C3D00_802C5E10();
    }
    return gDisplayListHead;
}

Gfx* func_1C3D00_802C58DC(Gfx* gdl) {
    s32 i;
    TexLabel* item;
    char buf[32];

    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 53, 38, 214, 26);
    gdl = func_80094338(gdl, 0, 73, 73, 174, 16);
    gdl = func_80094338(gdl, 0, 73, 90, 174, 25);
    for (i = 0; i < 4; i++) {
        gdl = func_80094338(gdl, 0, 73, i * 18 + 140, 174, 16);
    }
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 2, 18, 70, 42, 0);
    gdl = Printer_DrawString(gdl, 2, "1P", 99, 75);
    gdl = Printer_DrawString(gdl, 2, "2P", 202, 75);
    gdl = Printer_DrawString(gdl, 2, "-", 153, 95);
    gdl = TexLabel_Draw(gdl, 0, 21, 144, 77, 0);
    gdl = Printer_DrawNumber(gdl, 0, D_801CB3F0[0], 99, 92);
    sprintf(buf, "%d", D_801CB3F0[1]);
    gdl = Printer_DrawString(gdl, 0, buf, 193, 92);
    for (i = 0, item = D_1C3D00_802C5EB0; i < 4; i++, item++) {
        if (i != D_802C5EF0) {
            gdl = TexLabel_Draw(gdl, 1, item->texture, item->x + 138, i * 18 + 143, 0);
        }
    }
    gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    item = &D_1C3D00_802C5EB0[D_802C5EF0];
    return TexLabel_Draw(gdl, 1, item->texture, item->x + 138, D_802C5EF0 * 18 + 143, 0);
}

void func_1C3D00_802C5C4C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x37;
    D_801CE638 = 0x12;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(5, 1, 0);

    if (D_801CE630 == 2) {
        func_800C1F60(0);
        return;
    }
    if (D_801CE630 == 0xA) {
        func_800C1F60(1);
        return;
    }
    if (D_801CE630 == 0x14) {
        func_800C1F60(0xA);
        return;
    }
    if (D_801CE630 == 0x28) {
        func_800C1F60(7);
    }
}

void func_1C3D00_802C5D44(void) {
    if (D_801CE692[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        func_1C3D00_802C5C4C(D_1C3D00_802C5ED0[D_802C5EF0]);
        AudioGeneral_PlaySound(0x11, 0);
        return;
    }

    if (D_801CE692[0].unk0 & U_JPAD) {
        D_802C5EF0--;
        if (D_802C5EF0 < 0) {
            D_802C5EF0 = 3;
        }
        AudioGeneral_PlaySound(0x10, 0);
        return;
    }

    if (D_801CE692[0].unk0 & D_JPAD) {
        D_802C5EF0++;
        if (D_802C5EF0 == 4) {
            D_802C5EF0 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void func_1C3D00_802C5E10(void) {
    if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 2:
                GameState_EnterTitleScreen();
                return;
            case 40:
                func_8009345C();
                return;
            case 10:
                GameState_EnterRiderSelect();
                return;
            case 20:
                GameState_EnterCourseSelect();
                break;
        }
    }
}
