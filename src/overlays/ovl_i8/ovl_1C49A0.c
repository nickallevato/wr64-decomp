#include "global.h"

extern u8 D_7000000[];
extern u8 D_2000A40[];
extern Gfx D_106F550[];
extern Gfx D_8062290[];
extern u8 gPrinterWidthsFont2[]; /* glyph widths, font 2 */
extern s32 D_i8_802C7044;
extern s32 D_i8_802C7048;
extern s32 D_i8_802C7050;
extern u16 D_802C7530;
extern u32 D_802C7534;
extern s32 D_802C7568;
extern f32 D_i8_802C750C;

void Save_EepromWriteNames();
void func_i8_802C5EB8();
void func_i8_802C6D58(void);
void ChangeNames_DeleteChar(void);
void ChangeNames_StoreName(void);
void ChangeNames_LoadName(void* arg0);
s32 ChangeNames_StringWidth(s8* str, s32 arg1);

/* One key of the name-entry grid (7 keys a row). */
typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1; /* 0, 3: insert unkC (3: a space); 1: clear; 2: delete; 4, 5: cursor left, right;
                           6: load the name from D_800DA950; 7: store the name */
    /* 0x02 */ u8 unk2[0xA];
    /* 0x0C */ s8 unkC;
    /* 0x0D */ u8 unkD[0xF];
} UnkStruct_i8_802C7054; // size = 0x1C

extern UnkStruct_i8_802C7054 D_i8_802C7054[];
extern s32 D_802C7538;
extern s32 D_802C753C;
extern s8 D_802C7558[];

void func_i8_802C5800(void) {
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
        func_i8_802C6FD4(gPlayerNames[D_i8_802C74F8[D_i8_802C7040]].unk_0, D_802C7548, 11);
        D_80192690[gPlayer1Rider].unkB68 = D_i8_802C74F8[D_i8_802C7040];
        D_80192690[gPlayer1Rider].unkB6C = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[0];
        D_80192690[gPlayer1Rider].unkB70 = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[1];
        D_80192690[gPlayer1Rider].unkB74 = D_800DA950[D_i8_802C74F8[D_i8_802C7040]].unk_B[2];
    }

    if (D_i8_802C7044 == 0) {
        D_802C7534 = (D_i8_802C7048 * 255.0f) / 4;
    } else {
        D_802C7534 = ((4 - (f32) D_i8_802C7048) * 255.0f) / 4;
    }
    D_i8_802C7048++;
    if (D_i8_802C7048 >= 4) {
        D_i8_802C7048 = 0;
        D_i8_802C7044 ^= 1;
    }

    D_802C7568 = 0;
    for (i = 0; i < D_802C7564; i++) {
        glyph = Printer_GetGlyph(2, D_802C7548[i]);
        if (glyph == 0xFF) {
            glyph = 12; // the width
        } else {
            glyph = gPrinterWidthsFont2[glyph];
        }
        D_802C7568 += glyph;
    }

    func_800481E0(D_801CE5F8->unkA40, &D_802C7530, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
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

Gfx* func_i8_802C5D3C(Gfx* gdl) {
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

    q = func_i8_802C63E4(p);
    gSPDisplayList(q++, D_8062290);
    gdl = q;

    if (gGameState == 0x3E) {
        func_i8_802C5EB8();
    } else if (D_80228A16 == 1) {
        Save_EepromWriteNames();
        GameState_EnterOptionsMenu();
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5EB8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C63E4.s")

void func_i8_802C6ADC(void) {
    s32 i;
    s32 ok;
    s32 idx = D_802C753C * 7 + D_802C7538;
    UnkStruct_i8_802C7054* key = &D_i8_802C7054[idx];
    s8* p;
    s32 pad; // stack pad: the frame is 0x38

    switch (key->unk1) {
        case 0:
        case 3:
            ok = 1;
            if (Strlen2(D_802C7548) >= 10) {
                ok = 0;
            } else if (ChangeNames_StringWidth(D_802C7548, 2) >= 119) {
                ok = 0;
            }
            if (ok) {
                func_i8_802C6FD4(D_802C7548, D_802C7558, 11);
                for (i = D_802C7564 + 1; i < 11; i++) {
                    D_802C7548[i] = D_802C7558[i - 1];
                }
                p = &D_802C7548[D_802C7564];
                if (key->unk1 == 3) {
                    *p = ' ';
                } else {
                    *p = key->unkC;
                }
                if (ChangeNames_StringWidth(D_802C7548, 2) >= 124) {
                    func_i8_802C6FD4(D_802C7558, D_802C7548, 11);
                } else if (D_802C7558[D_802C7564] == 0) {
                    D_802C7564++;
                }
            }
            break;
        case 1:
            func_i8_802C6D58();
            break;
        case 2:
            ChangeNames_DeleteChar();
            break;
        case 5:
            if (D_802C7548[D_802C7564] != 0 && D_802C7564 < 10) {
                D_802C7564++;
            }
            break;
        case 4:
            if (D_802C7564 > 0) {
                D_802C7564--;
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

void func_i8_802C6D58(void) {
    s32 i;
    s8* p;

    D_802C7564 = 0;
    i = 0;
    p = D_802C7548;
    while (i < 11) {
        *p = 0;
        i++;
        p++;
    }
}

void ChangeNames_DeleteChar(void) {
    s8* src;
    s8* dst;

    if (D_802C7564 > 0) {
        src = &D_802C7548[D_802C7564];
        D_802C7564--;
        dst = &D_802C7548[D_802C7564];
        while (*src != 0) {
            *dst = *src;
            dst++;
            src++;
        }
        *dst = 0;
    }
}

void ChangeNames_StoreName(void) {
    if (D_802C7548[0] != 0) {
        func_i8_802C6FD4(D_802C7548, (s8*) &gPlayerNames[D_i8_802C74F8[D_i8_802C7040]].unk_0, 11);
    }
    D_802C756C = 1;
}

void ChangeNames_LoadName(void* arg0) {
    func_i8_802C6FD4(arg0, D_802C7548, 0xB);
    D_802C7564 = Strlen2(D_802C7548);
    if (D_802C7564 >= 9) {
        D_802C7564 = 9;
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

void func_i8_802C6F4C(void) {
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

void func_i8_802C6FD4(s8* src, s8* dest, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dest++ = *src++;
    }
}
