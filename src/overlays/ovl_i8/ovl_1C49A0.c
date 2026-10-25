#include "global.h"

extern u8 D_7000000[];
extern u8 D_2000A40[];
extern Gfx D_106F550[];
extern Gfx D_8062290[];
extern u8 gPrinterWidthsFont2[]; /* glyph widths, font 2 */
extern s32 D_i8_802C7044;
extern s32 D_i8_802C7048;
extern s32 D_i8_802C7050;
extern u16 D_i8_802C7530;
extern u32 D_i8_802C7534;
extern s32 D_i8_802C7568;
extern f32 D_i8_802C750C;

void Save_EepromWriteNames();
void ChangeNames_Input();
Gfx* ChangeNames_DrawScreen(Gfx* gdl);
void ChangeNames_PressKey(void);
void ChangeNames_ClearName(void);
void ChangeNames_Leave(void);
void ChangeNames_DeleteChar(void);
void ChangeNames_StoreName(void);
void ChangeNames_LoadName(void* arg0);
s32 ChangeNames_StringWidth(s8* str, s32 arg1);

/* One key of the name-entry grid (7 keys a row). */
typedef struct {
    /* 0x00 */ u8 unk0;  /* 1: the cursor can stop on it; 2: drawn; 4: drawn as texture unk18; 8: unk4/unk6 absolute */
    /* 0x01 */ u8 unk1;  /* 0, 3: insert unkC (3: a space); 1: clear; 2: delete; 4, 5: cursor left, right;
                            6: load the name from D_800DA950; 7: store the name */
    /* 0x02 */ u16 unk2; /* font of unkC */
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s8 unkC[0xC]; /* its label; the first character is the one inserted */
    /* 0x18 */ s32 unk18;
} UnkStruct_i8_802C7054; // size = 0x1C

extern UnkStruct_i8_802C7054 D_i8_802C7054[];
extern s32 D_i8_802C7538;
extern s32 D_i8_802C753C;
extern s8 D_i8_802C7558[];
extern s32 D_i8_802C704C;
extern s32 D_i8_802C7540;
extern s16 D_i8_802C74F0[];
extern char D_i8_802C7508[];
extern Gfx D_8061E50[];
extern Gfx D_8061EC0[];
extern Gfx D_8061F70[];
extern Gfx D_8061F80[];
extern Gfx D_8061F90[];
extern Gfx D_8061FA0[];
extern Gfx D_8061FB0[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];

Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);

void ChangeNames_OverlayUpdate(void) {
    s32 i;
    s32 angle;
    s32 glyph;
    f32 x;
    f32 z;
    MtxF sp184;
    MtxF sp144;
    MtxF sp104;
    Mtx spC0;
    Mtx sp80;

    if (D_801CE63C != 0 && gGameState == GAME_STATE_OPTIONS_CHANGE_NAMES) {
        D_801CE640 = 0;
    }
    if (D_801CE640 == 0) {
        ChangeNames_CopyBytes(gPlayerNames[D_i8_802C74F8[D_i8_802C7040]].unk_0, D_i8_802C7548, 11);
        D_80192690[gPlayer1Rider].unkB68 = D_i8_802C74F8[D_i8_802C7040];
        D_80192690[gPlayer1Rider].unkB6C = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[0];
        D_80192690[gPlayer1Rider].unkB70 = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[1];
        D_80192690[gPlayer1Rider].unkB74 = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[2];
    }

    if (D_i8_802C7044 == 0) {
        D_i8_802C7534 = (D_i8_802C7048 * 255.0f) / 4;
    } else {
        D_i8_802C7534 = ((4 - (f32) D_i8_802C7048) * 255.0f) / 4;
    }
    D_i8_802C7048++;
    if (D_i8_802C7048 >= 4) {
        D_i8_802C7048 = 0;
        D_i8_802C7044 ^= 1;
    }

    D_i8_802C7568 = 0;
    for (i = 0; i < D_i8_802C7564; i++) {
        glyph = Printer_GetGlyph(2, D_i8_802C7548[i]);
        if (glyph == 0xFF) {
            glyph = 12; // the width
        } else {
            glyph = gPrinterWidthsFont2[glyph];
        }
        D_i8_802C7568 += glyph;
    }

    func_800481E0(D_801CE5F8->unkA40, &D_i8_802C7530, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spC0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, D_i8_802C750C);
    for (i = 0; i < 4; i++) {
        if (i == D_i8_802C7040) {
            angle = D_i8_802C7050 % 4096;
            x = COS(angle) * 500.0f;
            z = SIN(angle) * 500.0f;
        } else {
            x = COS(0x200) * 500.0f;
            z = SIN(0x200) * 500.0f;
        }
        func_800484C8(&sp80, &sp144, x, 500.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        SysUtils_MtxToMtxF(&spC0, &sp184);
        SysUtils_MatrixAffineMultiply(&sp144, &sp184, &sp104);
        SysUtils_MtxFToMtx(&sp104, &D_801CE5F8->unkA80[i]);
    }
    D_i8_802C7050 += 0x30;
    if (D_i8_802C7050 >= 0x1000) {
        D_i8_802C7050 -= 0x1000;
    }
}

Gfx* ChangeNames_Draw(Gfx* gdl) {
    Gfx* p;
    Gfx* q;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_OPTIONS_CHANGE_NAMES) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gSPMatrix(gdl++, D_7000000, (G_MTX_PROJECTION | G_MTX_LOAD) | G_MTX_NOPUSH);
    gSPMatrix(gdl++, D_2000A40, (G_MTX_MODELVIEW | G_MTX_LOAD) | G_MTX_NOPUSH);
    gSPDisplayList(gdl++, D_106F550);

    p = func_8009328C(gdl);
    gDPPipeSync(p++);
    gDPSetScissor(p++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    q = ChangeNames_DrawScreen(p);
    gSPDisplayList(q++, D_8062290);
    gdl = q;

    if (gGameState == 0x3E) {
        ChangeNames_Input();
    } else if (D_80228A16 == 1) {
        Save_EepromWriteNames();
        GameState_EnterOptionsMenu();
    }
    return gdl;
}

void ChangeNames_Input(void) {
    s32 pad[2]; // stack pad: the frame is 0x28
    s32 sound = false;
    s32 idx;

    if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
        switch (D_801CE640) {
            case 0:
                D_801CE640 = 1;
                D_i8_802C753C = D_i8_802C7538 = 0;
                sound = true;
                ChangeNames_ClearName();
                break;
            case 1:
                sound = true;
                D_i8_802C756C = 0;
                if (D_801CE65A->unk0 & (CONT_A | CONT_G)) {
                    ChangeNames_PressKey();
                } else if (D_801CE65A->unk0 & CONT_START) {
                    ChangeNames_StoreName();
                }
                if (D_i8_802C756C != 0) {
                    ChangeNames_Leave();
                }
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_B) {
        switch (D_801CE640) {
            case 0:
                sound = true;
                ChangeNames_Leave();
                break;
            case 1:
                sound = true;
                ChangeNames_DeleteChar();
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x16, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_UP) {
        if (D_801CE640 == 1) {
            D_i8_802C7540 = D_i8_802C753C;
            sound = true;
            D_i8_802C753C--;
            if (D_i8_802C753C < 0) {
                D_i8_802C753C = 5;
            }
            for (;;) {
                idx = D_i8_802C753C * 7 + D_i8_802C7538;
                if (D_i8_802C7054[idx].unk0 & 1) {
                    break;
                }
                D_i8_802C7538--;
            }
            if (D_i8_802C7540 == 4 && D_i8_802C753C == 3 && D_i8_802C704C != -1) {
                D_i8_802C7538 = D_i8_802C704C;
                D_i8_802C704C = -1;
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_DOWN) {
        if (D_801CE640 == 1) {
            D_i8_802C7540 = D_i8_802C753C;
            sound = true;
            D_i8_802C753C++;
            if (D_i8_802C753C >= 6) {
                D_i8_802C753C = 0;
            }
            if (D_i8_802C7540 == 3 && D_i8_802C753C == 4) {
                D_i8_802C704C = D_i8_802C7538;
            }
            for (;;) {
                idx = D_i8_802C753C * 7 + D_i8_802C7538;
                if (D_i8_802C7054[idx].unk0 & 1) {
                    break;
                }
                if (D_i8_802C753C == 5) {
                    D_i8_802C7538++;
                } else {
                    D_i8_802C7538--;
                }
            }
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_LEFT) {
        switch (D_801CE640) {
            case 0:
                sound = true;
                D_i8_802C7040--;
                if (D_i8_802C7040 < 0) {
                    D_i8_802C7040 = 3;
                }
                D_i8_802C7050 = 0x200;
                break;
            case 1:
                D_i8_802C704C = -1;
                sound = true;
                do {
                    D_i8_802C7538--;
                    if (D_i8_802C7538 < 0) {
                        D_i8_802C7538 = 6;
                    }
                    idx = D_i8_802C753C * 7 + D_i8_802C7538;
                } while (!(D_i8_802C7054[idx].unk0 & 1));
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_801CE65A->unk0 & CONT_RIGHT) {
        switch (D_801CE640) {
            case 0:
                sound = true;
                D_i8_802C7040++;
                if (D_i8_802C7040 >= 4) {
                    D_i8_802C7040 = 0;
                }
                D_i8_802C7050 = 0x200;
                break;
            case 1:
                D_i8_802C704C = -1;
                sound = true;
                do {
                    D_i8_802C7538++;
                    if (D_i8_802C7538 >= 7) {
                        D_i8_802C7538 = 0;
                    }
                    idx = D_i8_802C753C * 7 + D_i8_802C7538;
                } while (!(D_i8_802C7054[idx].unk0 & 1));
                break;
        }
        if (sound) {
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}

Gfx* ChangeNames_DrawScreen(Gfx* gdl) {
    UnkStruct_i8_802C7054* key;
    s32 i;
    s32 x;
    s32 y;
    s32 sel;

    gSPDisplayList(gdl++, D_8061E50);
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 27, 22, 265, 23);
    gdl = func_80094338(gdl, 0, 27, 96, 130, 16);
    gdl = func_80094338(gdl, 1, 33, 176, 67, 14);
    gdl = func_80094338(gdl, 0, 101, 176, 50, 14);
    gdl = func_80094338(gdl, 1, 33, 192, 67, 14);
    gdl = func_80094338(gdl, 1, 118, 192, 33, 14);

    gSPDisplayList(gdl++, D_8061FB0);
    gSPPerspNormalize(gdl++, D_i8_802C7530);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    gSPDisplayList(gdl++, D_8061F70);
    gSPMatrix(gdl++, &D_7000A80[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 0, 0, 0, D_801CE5F8->unkC80[0]);
    gSPDisplayList(gdl++, D_8061F80);
    gSPMatrix(gdl++, &D_7000A80[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 2, 0, 0, D_801CE5F8->unkC80[1]);
    gSPDisplayList(gdl++, D_8061F90);
    gSPMatrix(gdl++, &D_7000A80[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 3, 0, 0, D_801CE5F8->unkC80[2]);
    gSPDisplayList(gdl++, D_8061FA0);
    gSPMatrix(gdl++, &D_7000A80[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 1, 0, 0, D_801CE5F8->unkC80[3]);

    gSPDisplayList(gdl++, D_8061EC0);
    gDPSetPrimColor(gdl++, 0, 0, D_i8_802C7534, 255, D_i8_802C7534, 255);
    gSPTextureRectangle(gdl++, (D_i8_802C74F0[D_i8_802C7040] + 8) << 2, 48 << 2,
                        (D_i8_802C74F0[D_i8_802C7040] + 71) << 2, 88 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = func_801E3EE0(gdl, 2, 6, 67, 24, 0);
    gdl = Printer_DrawString(gdl, 1, gPlayerNames[D_i8_802C74F8[D_i8_802C7040]].unk_0, 180, 203);
    gdl = Printer_DrawString(gdl, 2, D_i8_802C7548, 31, 98);

    for (i = 0, key = D_i8_802C7054; i != 42; i++, key++) {
        if (!(key->unk0 & 2)) {
            continue;
        }
        if (D_801CE640 == 1) {
            sel = D_i8_802C753C * 7 + D_i8_802C7538;
            if (i == sel) {
                continue;
            }
        }
        if (key->unk0 & 8) {
            x = key->unk4;
            y = key->unk6;
        } else {
            x = key->unk4 + (i % 7) * 17 + 33;
            y = key->unk6 + (i / 7) * 15 + 116;
        }
        if (key->unk0 & 4) {
            gdl = func_801E3EE0(gdl, 0, key->unk18, x, y, 0);
        } else {
            gdl = Printer_DrawString(gdl, key->unk2, key->unkC, x, y);
        }
    }

    gdl = Printer_SetMode(gdl, 6, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    if (D_801CE640 == 1) {
        sel = D_i8_802C753C * 7 + D_i8_802C7538;
        key = &D_i8_802C7054[sel];
        if (key->unk0 & 8) {
            x = key->unk4;
            y = key->unk6;
        } else {
            x = key->unk4 + (sel % 7) * 17 + 33;
            y = key->unk6 + (sel / 7) * 15 + 116;
        }
        if (key->unk0 & 4) {
            gdl = func_801E3EE0(gdl, 0, key->unk18, x, y, 0);
        } else {
            gdl = Printer_DrawString(gdl, key->unk2, key->unkC, x, y);
        }
    }
    if (D_801CE640 == 1) {
        gdl = Printer_DrawString(gdl, 2, D_i8_802C7508, D_i8_802C7568 + 31, 98);
    }
    return gdl;
}

void ChangeNames_PressKey(void) {
    s32 i;
    s32 ok;
    s32 idx = D_i8_802C753C * 7 + D_i8_802C7538;
    UnkStruct_i8_802C7054* key = &D_i8_802C7054[idx];
    s8* p;
    s32 pad; // stack pad: the frame is 0x38

    switch (key->unk1) {
        case 0:
        case 3:
            ok = 1;
            if (Strlen2(D_i8_802C7548) >= 10) {
                ok = 0;
            } else if (ChangeNames_StringWidth(D_i8_802C7548, 2) >= 119) {
                ok = 0;
            }
            if (ok) {
                ChangeNames_CopyBytes(D_i8_802C7548, D_i8_802C7558, 11);
                for (i = D_i8_802C7564 + 1; i < 11; i++) {
                    D_i8_802C7548[i] = D_i8_802C7558[i - 1];
                }
                p = &D_i8_802C7548[D_i8_802C7564];
                if (key->unk1 == 3) {
                    *p = ' ';
                } else {
                    *p = key->unkC[0];
                }
                if (ChangeNames_StringWidth(D_i8_802C7548, 2) >= 124) {
                    ChangeNames_CopyBytes(D_i8_802C7558, D_i8_802C7548, 11);
                } else if (D_i8_802C7558[D_i8_802C7564] == 0) {
                    D_i8_802C7564++;
                }
            }
            break;
        case 1:
            ChangeNames_ClearName();
            break;
        case 2:
            ChangeNames_DeleteChar();
            break;
        case 5:
            if (D_i8_802C7548[D_i8_802C7564] != 0 && D_i8_802C7564 < 10) {
                D_i8_802C7564++;
            }
            break;
        case 4:
            if (D_i8_802C7564 > 0) {
                D_i8_802C7564--;
            }
            break;
        case 6:
            ChangeNames_LoadName(&D_800DA950[D_i8_802C74F8[D_i8_802C7040]]);
            break;
        case 7:
            ChangeNames_StoreName();
            break;
    }
}

void ChangeNames_ClearName(void) {
    s32 i;
    s8* p;

    D_i8_802C7564 = 0;
    i = 0;
    p = D_i8_802C7548;
    while (i < 11) {
        *p = 0;
        i++;
        p++;
    }
}

void ChangeNames_DeleteChar(void) {
    s8* src;
    s8* dst;

    if (D_i8_802C7564 > 0) {
        src = &D_i8_802C7548[D_i8_802C7564];
        D_i8_802C7564--;
        dst = &D_i8_802C7548[D_i8_802C7564];
        while (*src != 0) {
            *dst = *src;
            dst++;
            src++;
        }
        *dst = 0;
    }
}

void ChangeNames_StoreName(void) {
    if (D_i8_802C7548[0] != 0) {
        ChangeNames_CopyBytes(D_i8_802C7548, (s8*) &gPlayerNames[D_i8_802C74F8[D_i8_802C7040]].unk_0, 11);
    }
    D_i8_802C756C = 1;
}

void ChangeNames_LoadName(void* arg0) {
    ChangeNames_CopyBytes(arg0, D_i8_802C7548, 0xB);
    D_i8_802C7564 = Strlen2(D_i8_802C7548);
    if (D_i8_802C7564 >= 9) {
        D_i8_802C7564 = 9;
    }
}

s32 ChangeNames_StringWidth(s8* str, s32 arg1) {
    s32 width = 0;
    s32 idx;
    s32 charWidth;
    s32 i;

    for (i = 0; str[i] != 0; width += charWidth, i++) {
        idx = Printer_GetGlyph(arg1, str[i]);
        if (idx == 0xFF) {
            charWidth = 12;
        } else {
            charWidth = gPrinterWidthsFont2[idx];
        }
    }
    return width;
}

void ChangeNames_Leave(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x3F;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;
    FadeTransition_SetProps(1, 4, 0);
}

void ChangeNames_CopyBytes(s8* src, s8* dest, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dest++ = *src++;
    }
}
