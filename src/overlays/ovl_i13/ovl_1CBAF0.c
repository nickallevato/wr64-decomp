#include "global.h"

extern s32 D_i13_802C8D50;
extern s32 D_i13_802C8D54;
extern s32 D_i13_802C8D58;
extern s32 D_i13_802C8D5C;
extern s32 D_i13_802C8D60[];
extern s32 D_i13_802C8D70;
extern s32 D_i13_802C8D74;
extern s32 D_i13_802C8D7C;
extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_i13_802C8D88;
extern s32 D_i13_802C8D8C;
extern s32 D_i13_802C8D90;
extern s32 D_i13_802C8D94;
extern s32 D_i13_802C8D98;
extern s32 D_i13_802C8DC4;
extern s32 D_i13_802C8DC8;
extern s32 D_i13_802C8DCC;
extern s32 D_i13_802C8DD0;
extern s32 D_i13_802C8DD4;
extern s32 D_i13_802C8DE0[];
// Message box position; u32: func_i13_802C832C only matches with them unsigned (copied into a1/a2 by moves)
extern u32 D_802C8E90;
extern u32 D_802C8E94;
extern s32 D_802C8E9C;
extern u32 D_802C8EA0;
extern u32 D_802C8EA4;
extern u32 D_802C8EA8;
extern u16 D_802C8EAC;
extern s32 D_802C8EB0;
extern s32 D_802C8EB4;
extern s32 D_802C8EB8;
extern s32 D_802C8EBC;

extern u8 D_8065078[];
extern u8 D_8067048[];
extern u8 D_8068E50[];
extern u8 D_806AA78[];
extern u8 D_806C880[];

s32 Save_EepromReset(void);
s32 func_8007D2D4(s32);
s32 func_8007D614(s32);
void func_800C3010(u32);
void func_800C3E6C(s32);
void SaveLoad_Update(void);
s32 func_i13_802C6700(void);
void func_i13_802C7060(void);
Gfx* func_i13_802C711C(Gfx*);
void SaveLoad_OpenResultMessage(s32 arg0);
void SaveLoad_OpenPromptMessage(s32 arg0);
Gfx* func_i13_802C832C(Gfx*);
Gfx* func_i13_802C8484(Gfx* gdl, s32 arg1);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
void SaveLoad_Leave(void);
void GameState_EnterOptionsMenu(void);
s32 Save_PfsCheckFree(void);
s32 Save_PfsDeleteFile(void);
s32 Save_PfsFindFile(void);

void func_i13_802C5800(void) {
    s32 i;
    f32 x;
    f32 z;
    MtxF sp18C;
    MtxF sp14C;
    MtxF sp10C;
    Mtx spC8;
    Mtx sp88;

    if (D_i13_802C8D88 == 0) {
        D_802C8EA0 = (D_i13_802C8D8C * 255.0f) / 4;
    } else {
        D_802C8EA0 = ((4 - (f32) D_i13_802C8D8C) * 255.0f) / 4;
    }
    D_i13_802C8D8C++;
    if (D_i13_802C8D8C >= 4) {
        D_i13_802C8D8C = 0;
        D_i13_802C8D88 ^= 1;
    }

    switch (D_i13_802C8D90) {
        case 0:
            D_802C8EA4 = D_i13_802C8D94 * 255.0f / 2.0f;
            D_802C8EA8 = 0;
            break;

        case 1:
            D_802C8EA4 = 255;
            D_802C8EA8 = D_i13_802C8D94 * 255.0f / 2.0f;
            break;

        case 2:
            D_802C8EA4 = 255;
            D_802C8EA8 = (2 - D_i13_802C8D94) * 255.0f / 2.0f;
            break;

        case 3:
            D_802C8EA4 = (2 - D_i13_802C8D94) * 255.0f / 2.0f;
            D_802C8EA8 = 0;
            break;
    }
    D_i13_802C8D94++;
    if (D_i13_802C8D94 >= 2) {
        D_i13_802C8D94 = 0;
        D_i13_802C8D90++;
        if (D_i13_802C8D90 == 4) {
            D_i13_802C8D90 = 0;
        }
    }

    if ((D_801CE640 == 4) || (D_801CE640 == 7) || (D_801CE640 == 11) || (D_801CE640 == 8)) {
        func_800481E0(D_801CE5F8->unkA40, &D_802C8EAC, 33.0f, 1.0f, 16.0f, 1024.0f, 0.0f, 0.0f);
        func_80048A88(&spC8, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.07f);
        for (i = 0; i < 4; i++) {
            if (i == D_i13_802C8D5C) {
                x = COS(D_i13_802C8D98 % 4096) * 500.0f;
                z = SIN(D_i13_802C8D98 % 4096) * 500.0f;
            } else {
                x = COS(0x200) * 500.0f;
                z = SIN(0x200) * 500.0f;
            }
            func_800484C8(&sp88, &sp14C, x, 500.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            SysUtils_MtxToMtxF(&spC8, &sp18C);
            SysUtils_MatrixAffineMultiply(&sp14C, &sp18C, &sp10C);
            SysUtils_MtxFToMtx(&sp10C, &D_801CE5F8->unkA80[i]);
        }
        D_i13_802C8D98 += 0x18;
        if (D_i13_802C8D98 >= 0x1000) {
            D_i13_802C8D98 -= 0x1000;
        }
    }
}

Gfx* func_i13_802C5F6C(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_OPTIONS_SAVE_AND_LOAD) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gdl = func_i13_802C711C(gdl);
    if (D_i13_802C8D74 != 0) {
        SaveLoad_OpenResultMessage(D_i13_802C8D74);
        D_i13_802C8D74 = 0;
    }
    gdl = func_i13_802C832C(gdl);

    if (gGameState == GAME_STATE_OPTIONS_SAVE_AND_LOAD) {
        if (D_i13_802C8D78 == 0) {
            SaveLoad_Update();
        } else {
            func_i13_802C7060();
        }
    } else if (D_80228A16 == 1) {
        GameState_EnterOptionsMenu();
    }

    return gdl;
}

void SaveLoad_Update(void) {
    s32 pad; // stack pad: needed for match (shifts var_v1 stack slot)
    s32 var_v1;

    switch (D_801CE640) {
        case 0:
            var_v1 = func_i13_802C61E0();
            break;
        case 1:
        case 2:
            var_v1 = func_i13_802C62EC();
            break;
        case 3:
            var_v1 = func_i13_802C64AC();
            break;
        case 4:
            var_v1 = func_i13_802C65D4();
            break;
        case 8:
            var_v1 = func_i13_802C6700();
            break;
        case 5:
            var_v1 = func_i13_802C69CC();
            break;
        case 6:
            var_v1 = func_i13_802C6ABC();
            break;
        case 7:
            var_v1 = func_i13_802C6BC4();
            break;
        case 11:
            var_v1 = SaveLoad_PakTransfer();
            break;
        case 10:
            var_v1 = SaveLoad_PakTransferRecords();
            break;
        case 9:
            var_v1 = SaveLoad_EraseOrReset();
            break;
    }

    if (var_v1 == 1) {
        AudioGeneral_PlaySound(0x11, 0);
    } else if (var_v1 == 2) {
        AudioGeneral_PlaySound(0x16, 0);
    } else if (var_v1 == 3) {
        AudioGeneral_PlaySound(0x10, 0);
    } else if (var_v1 == 4) {
        AudioGeneral_PlaySound(0x10, 0);
    } else if (var_v1 == 5) {
        AudioGeneral_PlaySound(0x37, 0);
    }
}

s32 func_i13_802C61E0(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        if (D_i13_802C8D50 == 0) {
            D_801CE640 = 1;
            D_i13_802C8D54 = 0;
        } else if (D_i13_802C8D50 == 1) {
            D_801CE640 = 2;
            D_i13_802C8D54 = 0;
        } else {
            SaveLoad_Leave();
        }
        var_v1 = 1;
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        var_v1 = 2;
        SaveLoad_Leave();
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_v1 = 3;
        if (--D_i13_802C8D50 < 0) {
            D_i13_802C8D50 = 2;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_v1 = 4;
        if (++D_i13_802C8D50 >= 3) {
            D_i13_802C8D50 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C62EC(void) {
    s32 var_a1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_a1 = 1;
        if (D_801CE640 == 1) {
            if (D_i13_802C8D54 == 0) {
                D_i13_802C8D74 = Save_PfsFindFile();
            } else {
                D_i13_802C8D74 = Save_PfsFindFile();
                if (D_i13_802C8D74 == 4) {
                    D_i13_802C8D74 = Save_PfsCheckFree();
                }
            }
            if (D_i13_802C8D74 == 0) {
                D_801CE640 = 3;
                D_i13_802C8D58 = 0;
            }
        } else {
            if (D_i13_802C8D54 == 1) {
                D_i13_802C8D74 = Save_PfsFindFile();
            }
            if (D_i13_802C8D74 == 0) {
                D_801CE640 = 5;
                D_i13_802C8D70 = 1;
                func_800C3E6C(3);
            }
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        D_801CE640 = 0;
        var_a1 = 2;
        D_i13_802C8D54 = 0;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_a1 = 3;
        if (--D_i13_802C8D54 < 0) {
            D_i13_802C8D54 = 1;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_a1 = 4;
        if (++D_i13_802C8D54 >= 2) {
            D_i13_802C8D54 = 0;
        }
    }
    return var_a1;
}

s32 func_i13_802C64AC(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_v1 = 1;
        if (D_i13_802C8D58 == 0) {
            D_801CE640 = 4;
            D_i13_802C8D5C = 0;
            D_i13_802C8D98 = 0x200;
        } else {
            D_801CE640 = 6;
            D_i13_802C8D70 = 1;
            if (D_i13_802C8D54 == 0) {
                SaveLoad_OpenPromptMessage(2);
            }
            func_800C3E6C(3);
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        var_v1 = 2;
        D_801CE640 = 1;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_v1 = 3;
        if (--D_i13_802C8D58 < 0) {
            D_i13_802C8D58 = 1;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_v1 = 4;
        if (++D_i13_802C8D58 >= 2) {
            D_i13_802C8D58 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C65D4(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_v1 = 1;
        if (D_i13_802C8D54 == 0) {
            D_801CE640 = 8;
            D_i13_802C8DC4 = 0;
            D_i13_802C8DC8 = 0;
            D_i13_802C8DCC = 0;
            D_i13_802C8DD0 = 0;
        } else {
            D_801CE640 = 7;
            D_i13_802C8D70 = 1;
            func_800C3E6C(3);
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        var_v1 = 2;
        D_801CE640 = 3;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        D_i13_802C8D98 = 0x200;
        var_v1 = 3;
        if (--D_i13_802C8D5C < 0) {
            D_i13_802C8D5C = 3;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        D_i13_802C8D98 = 0x200;
        var_v1 = 4;
        if (++D_i13_802C8D5C >= 4) {
            D_i13_802C8D5C = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C6700(void) {
    s32 var_a2 = 0;
    f32 pos;
    f32 size;

    switch (D_i13_802C8DD0) {
        case 0:
            D_i13_802C8DC8 = 1;
            D_i13_802C8DCC++;
            pos = (f32) (5 - D_i13_802C8DCC) / 5.0f;
            size = (f32) D_i13_802C8DCC / 5.0f;
            D_802C8EB0 = (s32) (129.0f * pos) + 31;
            D_802C8EB4 = (s32) (20.0f * pos) + 137;
            D_802C8EB8 = 258.0f * size;
            D_802C8EBC = 40.0f * size;
            if (D_i13_802C8DCC >= 5) {
                D_i13_802C8DD0 = 1;
                D_i13_802C8DD4 = 1;
            }
            break;

        case 1:
            if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
                D_801CE640 = 7;
                D_i13_802C8D70 = 1;
                var_a2 = 1;
                func_800C3E6C(3);
            } else if (D_801CE65A[0].unk0 & B_BUTTON) {
                D_i13_802C8DD0 = 2;
                D_i13_802C8DCC = 0;
                var_a2 = 2;
                D_i13_802C8DD4 = 0;
            } else if (D_801CE65A[0].unk0 & L_JPAD) {
                var_a2 = 3;
                D_i13_802C8DC4 ^= 1;
            } else if (D_801CE65A[0].unk0 & R_JPAD) {
                var_a2 = 4;
                D_i13_802C8DC4 ^= 1;
            }
            break;

        case 2:
            D_i13_802C8DC8 = 1;
            D_i13_802C8DCC++;
            size = (f32) (5 - D_i13_802C8DCC) / 5.0f;
            pos = (f32) D_i13_802C8DCC / 5.0f;
            D_802C8EB0 = (s32) (129.0f * pos) + 31;
            D_802C8EB4 = (s32) (20.0f * pos) + 137;
            D_802C8EB8 = 258.0f * size;
            D_802C8EBC = 40.0f * size;
            if (D_i13_802C8DCC >= 5) {
                D_i13_802C8DD0 = 0;
                D_801CE640 = 4;
            }
            break;
    }
    return var_a2;
}

s32 func_i13_802C69CC(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 9;
            SaveLoad_OpenPromptMessage(4);
        } else {
            D_801CE640 = 2;
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        var_v1 = 2;
        D_801CE640 = 2;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_v1 = 3;
        if (--D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_v1 = 4;
        if (++D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C6ABC(void) {
    s32 var_v1 = 0;

    D_i13_802C8D80 = 0;
    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        D_i13_802C8D84 = 0;
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 0xA;
            SaveLoad_OpenPromptMessage(3);
        } else {
            D_801CE640 = 1;
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        D_801CE640 = 3;
        var_v1 = 2;
        D_i13_802C8D84 = 0;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_v1 = 3;
        if (--D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_v1 = 4;
        if (++D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}

s32 func_i13_802C6BC4(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 0xB;
            SaveLoad_OpenPromptMessage(3);
        } else {
            D_801CE640 = 4;
            D_i13_802C8DC8 = 0;
            D_i13_802C8DD4 = 0;
            D_i13_802C8DD0 = 0;
        }
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        D_801CE640 = 4;
        D_i13_802C8DC8 = 0;
        D_i13_802C8DD4 = 0;
        var_v1 = 2;
        D_i13_802C8DD0 = 0;
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        var_v1 = 3;
        if (--D_i13_802C8D70 < 0) {
            D_i13_802C8D70 = 1;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        var_v1 = 4;
        if (++D_i13_802C8D70 >= 2) {
            D_i13_802C8D70 = 0;
        }
    }
    return var_v1;
}

s32 SaveLoad_PakTransfer(void) {
    s32 var_a1 = 0;
    s32 var_a0;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        var_a0 = D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]];
        if (D_i13_802C8DC4 != 0) {
            var_a0 += 0x80;
        }
        D_i13_802C8D74 = func_8007D2D4(var_a0);
        if (D_i13_802C8D74 == 0) {
            D_801CE640 = 0;
            D_i13_802C8D7C = 3;
            var_a1 = 1;
        } else {
            D_801CE640 = 4;
        }
        D_i13_802C8DC8 = 0;
        D_i13_802C8DD4 = 0;
        D_i13_802C8DD0 = 0;
    } else {
        D_i13_802C8D74 = func_8007D614(D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]]);
        if (D_i13_802C8D74 == 0) {
            D_801CE640 = 0;
            D_i13_802C8D7C = 3;
            var_a1 = 1;
        } else {
            D_801CE640 = 4;
        }
    }
    if (var_a1 != 0) {
        func_800C3E6C(1);
    }
    return 0;
}

s32 SaveLoad_PakTransferRecords(void) {
    s32 var_v1 = 0;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        D_i13_802C8D74 = func_8007D2D4(5);
    } else {
        D_i13_802C8D74 = func_8007D614(5);
    }
    if (D_i13_802C8D74 == 0) {
        D_801CE640 = 1;
        var_v1 = 1;
    } else {
        D_801CE640 = 3;
    }
    if (var_v1 != 0) {
        func_800C3E6C(1);
    }
    return 0;
}

s32 SaveLoad_EraseOrReset(void) {
    s32 var_a1 = 0;
    s8 temp_v1;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;
    if (D_i13_802C8D54 == 0) {
        Save_EepromReset();
        var_a1 = 1;
        temp_v1 = D_801CB280 & 0xC0;
        D_801CE640 = 0;
        if (temp_v1 & 0x40) {
            D_800DA9EC[0] = 1;
            func_800C3010(3);
        } else if (temp_v1 & 0x80) {
            D_800DA9EC[0] = 2;
            func_800C3010(1);
        } else {
            D_800DA9EC[0] = 0;
            func_800C3010(0);
        }
        if (D_801CB280 & 0x20) {
            D_800DA9EC[1] = 0;
            func_800C3044();
        } else {
            D_800DA9EC[1] = 1;
            func_800C3034();
        }
    } else {
        D_i13_802C8D74 = Save_PfsDeleteFile();
        if (D_i13_802C8D74 == 0) {
            var_a1 = 1;
        }
        D_801CE640 = 0;
    }
    if (var_a1 != 0) {
        func_800C3E6C(2);
    }
    return 0;
}

void func_i13_802C7060(void) {
    switch (D_i13_802C8D78) {
        case 1:
            if (D_802C8E98 >= 5) {
                D_i13_802C8D78 = 2;
                D_802C8E98 = 0;
            }
            break;

        case 2:
            if (++D_802C8E98 >= 0xA) {
                D_i13_802C8D78 = 3;
                D_802C8E98 = 0;
            }
            break;

        case 3:
            if (++D_i13_802C8DC0 >= 0x5B) {
                D_i13_802C8D78 = 0;
                D_802C8E98 = 0;
                D_i13_802C8DC0 = 0;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")

void SaveLoad_OpenResultMessage(s32 arg0) {
    s32 var_v0;

    D_i13_802C8D84 = 0;
    D_i13_802C8D78 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    var_v0 = 0;
    switch (arg0) {
        case 1:
            var_v0 = 1;
            D_802C8E9C = 4;
            break;
        case 6:
            var_v0 = 1;
            D_802C8E9C = 6;
            break;
        case 3:
            var_v0 = 1;
            D_802C8E9C = 0;
            break;
        case 4:
            var_v0 = 1;
            D_802C8E9C = 2;
            break;
        case 2:
        case 5:
            var_v0 = 1;
            if (D_i13_802C8D50 == 0) {
                D_802C8E9C = 1;
            } else {
                D_802C8E9C = 3;
            }
            break;
    }
    if (var_v0 != 0) {
        func_800C3E6C(0);
    }
}

void SaveLoad_OpenPromptMessage(s32 arg0) {
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    switch (arg0) {
        case 2:
            D_802C8E9C = 5;
            break;
        case 3:
            D_802C8E9C = 7;
            break;
        case 4:
            D_802C8E9C = 8;
            break;
    }
}

Gfx* func_i13_802C832C(Gfx* gdl) {
    s32 height;

    switch (D_i13_802C8D78) {
        case 1:
            D_802C8E98++;
            height = D_802C8E98 * 20 / 5;
            if (D_802C8E98 >= 5) {
                D_802C8E90 = 0x1C;
                D_802C8E94 = 0x44;
            }
            D_802C8E94 = 0x58 - height;
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl = func_801E7FD8(gdl, D_802C8E90, D_802C8E94, D_802C8E90 + 0x108, height * 2 + D_802C8E94);
            break;

        case 2:
        case 3:
        case 5:
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl = func_801E7FD8(gdl, D_802C8E90, D_802C8E94, D_802C8E90 + 0x108, D_802C8E94 + 0x28);
            gdl = func_i13_802C8484(gdl, 0);
            break;
    }
    return gdl;
}

Gfx* func_i13_802C8484(Gfx* gdl, s32 arg1) {
    s32 i;

    if (arg1 == 0) {
        gdl = Printer_SetMode(gdl, 4, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    } else {
        gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    }

    switch (D_802C8E9C) {
        case 0:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_806AA78[i * 256 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 256, 15, 0, 0, 255, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 32 << 2, (73 + i * 15) << 2, 288 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 1:
            gdl = func_801E3EE0(gdl, 3, 7, 72, 80, 2);
            break;

        case 3:
            gdl = func_801E3EE0(gdl, 3, 9, 68, 80, 2);
            break;

        case 2:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_806C880[i * 192 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 192, 15, 0, 0, 191, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 67 << 2, (73 + i * 15) << 2, 259 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 4:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_8068E50[i * 240 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 240, 15, 0, 0, 239, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 46 << 2, (73 + i * 15) << 2, 286 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 5:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_8067048[i * 256 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 256, 15, 0, 0, 255, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 33 << 2, (73 + i * 15) << 2, 289 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 6:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_8065078[i * 224 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 224, 15, 0, 0, 223, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 53 << 2, (73 + i * 15) << 2, 277 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 7:
            gdl = func_801E3EE0(gdl, 3, 15, 119, 80, 2);
            break;

        case 8:
            gdl = func_801E3EE0(gdl, 3, 16, 120, 80, 2);
            break;
    }
    return gdl;
}

void SaveLoad_Leave(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x41;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 2;

    FadeTransition_SetProps(1, 4, 0);
}
