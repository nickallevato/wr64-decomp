#include "global.h"

extern s32 D_i11_802C618C[][2];

extern s32 D_i11_802C6154[];
extern TexLabel D_i11_802C6160[];
extern s32 D_i11_802C6178[];
extern s32 D_i11_802C6184[];
extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];

void Save_EepromWriteHeader(void);

void func_800C3050(s32);
void AudioOptions_Input(void);
void AudioOptions_Apply(void);
void AudioOptions_Leave(s32);

Gfx* AudioOptions_Draw(Gfx* gdl) {
    s32 i;
    s32* value;
    // Only set for rows 0 and 1; the original keeps it in a register across the loop.
    s32 texture;
    s32 useString;
    s32 mode;
    TexLabel* item;
    char buf[12];

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x48) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;
    gSPMatrix(gdl++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_106F550);
    gSPDisplayList(gdl++, D_106F628);

    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, 28, i * 21 + 100, 148, 16);
        gdl = func_80094338(gdl, 0, 178, i * 21 + 100, 105, 16);
    }
    gdl = func_80094338(gdl, 0, 106, 163, 107, 16);

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 19, 122, 50, 0);

    for (i = 0, item = D_i11_802C6160, value = D_800DA9EC; i < 3; i++, item++, value++) {
        if (i == D_i11_802C6150) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = func_801E3EE0(gdl, 1, item->texture, item->x + 38, i * 21 + 103, 0);
        gdl = Printer_DrawString(gdl, 2, ">", 158, i * 21 + 102);

        if (i == D_i11_802C6150) {
            if (*value == D_i11_802C6154[i]) {
                mode = 6;
            } else if (i == 2) {
                mode = 6;
            } else {
                mode = 4;
            }
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);

        if (i == 0) {
            useString = false;
            texture = D_i11_802C6178[*value];
        } else if (i == 1) {
            useString = false;
            texture = D_i11_802C6184[*value];
        } else {
            useString = true;
            sprintf(buf, "%d", *value);
        }

        if (!useString) {
            gdl = func_801E3EE0(gdl, 1, texture, 188, i * 21 + 103, 0);
        } else {
            gdl = Printer_DrawString(gdl, 2, buf, 188, i * 21 + 102);
        }
    }

    if (D_i11_802C6150 == 3) {
        mode = 6;
    } else {
        mode = 0;
    }
    gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 1, 63, 144, 166, 0);

    if (gGameState == 0x48) {
        AudioOptions_Input();
    } else if (D_80228A16 == 1) {
        GameState_EnterOptionsMenu();
        Save_EepromWriteHeader();
    }
    return gdl;
}

void AudioOptions_Input(void) {
    s32* limits;
    // Intentionally uninitialised: the original reads this stack slot unset when the
    // selection is 0 or 1. Initialising it to 0 adds a store and breaks the match.
    s32 var_v0;

    if (D_801CE658[2].unk_00.unk_2 & (A_BUTTON | START_BUTTON | Z_TRIG)) {
        if (D_i11_802C6150 == 2) {
            var_v0 = 1;
            func_800C3050(D_800DA9EC[D_i11_802C6150]);
        } else if (D_i11_802C6150 == 3) {
            var_v0 = 1;
            AudioOptions_Leave(60);
        }
        if (var_v0 != 0) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE658[2].unk_00.unk_2 & B_BUTTON) {
        AudioOptions_Leave(60);
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & U_JPAD) {
        D_i11_802C6150--;
        if (D_i11_802C6150 < 0) {
            D_i11_802C6150 = 3;
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & D_JPAD) {
        D_i11_802C6150++;
        if (D_i11_802C6150 >= 4) {
            D_i11_802C6150 = 0;
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & L_JPAD) {
        if (D_i11_802C6150 != 3) {
            limits = D_i11_802C618C[D_i11_802C6150];
            if (--D_800DA9EC[D_i11_802C6150] < limits[0]) {
                D_800DA9EC[D_i11_802C6150] = limits[1];
            }
            AudioOptions_Apply();
        }
        AudioGeneral_PlaySound(0x10, 0);
    } else if (D_801CE658[0].unk_00.unk_2 & R_JPAD) {
        if (D_i11_802C6150 != 3) {
            limits = D_i11_802C618C[D_i11_802C6150];
            if (++D_800DA9EC[D_i11_802C6150] > limits[1]) {
                D_800DA9EC[D_i11_802C6150] = limits[0];
            }
            AudioOptions_Apply();
        }
        AudioGeneral_PlaySound(0x10, 0);
    }
}

void AudioOptions_Apply(void) {
    if (D_i11_802C6150 == 0) {
        if (D_800DA9EC[D_i11_802C6150] == 0) {
            func_800C2FDC(0);
            D_801CB280 &= 0x3F;
        } else if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C2FDC(3);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x40;
        } else {
            func_800C2FDC(1);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x80;
        }
    } else if (D_i11_802C6150 == 1) {
        if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C3034();
            D_801CB280 &= 0xDF;
        } else {
            func_800C3044();
            D_801CB280 |= 0x20;
        }
    }
}

void AudioOptions_Leave(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 73;
    D_801CE638 = 20;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
    Popup_Spawn(0, 0);

    if (D_801CE630 == 60) {
        func_800C1F60(9);
    }
}
