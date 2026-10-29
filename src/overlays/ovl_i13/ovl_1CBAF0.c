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
extern TexLabel D_i13_802C8D9C[3]; // the three tabs
extern s32 D_i13_802C8DB4[3];
extern s32 D_i13_802C8DC4;
extern s32 D_i13_802C8DC8;
extern s32 D_i13_802C8DCC;
extern s32 D_i13_802C8DD0;
extern s32 D_i13_802C8DD4;
extern s32 D_i13_802C8DE0[];
// Message box position; u32: SaveLoad_DrawMessageBox only matches with them unsigned (copied into a1/a2 by moves)
extern u32 D_i13_802C8E90;
extern u32 D_i13_802C8E94;
extern s32 D_i13_802C8E9C;
extern u32 D_i13_802C8EA0;
extern u32 D_i13_802C8EA4;
extern u32 D_i13_802C8EA8;
extern u16 D_i13_802C8EAC;
// Pop-up box position (u32 like D_i13_802C8E90) and size
extern u32 D_i13_802C8EB0;
extern u32 D_i13_802C8EB4;
extern s32 D_i13_802C8EB8;
extern s32 D_i13_802C8EBC;

extern Mtx D_7000000[];
extern Mtx D_2000A40[];
extern Gfx D_106F550[];
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Mtx D_7000AC0[];
extern Mtx D_7000B00[];
extern Mtx D_7000B40[];
extern u8 D_8061B10[];
extern Gfx D_806FAB0[];
extern Gfx D_806FB30[];
extern Gfx D_806FB88[];
extern Gfx D_806FBE0[];
extern Gfx D_806FC08[];
extern Gfx D_806FC48[];
extern Gfx D_806FC68[];
extern Gfx D_806FCA8[];
extern Gfx D_806FCC8[];
extern Gfx D_806FD08[];
extern Gfx D_806FDD0[];
extern Gfx D_806FDE0[];
extern Gfx D_806FDF0[];
extern Gfx D_806FE00[];
extern u8 D_8065078[];
extern u8 D_8067048[];
extern u8 D_8068E50[];
extern u8 D_806AA78[];
extern u8 D_806C880[];

s32 Save_EepromReset(void);
s32 Save_PfsRead(s32);
s32 Save_PfsWrite(s32);
void func_800C3010(u32);
void func_800C3E6C(s32);
void SaveLoad_Update(void);
s32 SaveLoad_Step8Popup(void);
void SaveLoad_UpdateMessageBox(void);
Gfx* func_i13_802C711C(Gfx*);
void SaveLoad_OpenResultMessage(s32 arg0);
void SaveLoad_OpenPromptMessage(s32 arg0);
Gfx* SaveLoad_DrawMessageBox(Gfx*);
Gfx* SaveLoad_DrawMessage(Gfx* gdl, s32 arg1);
Gfx* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry);
Gfx* func_80093AFC(Gfx*);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);
void SaveLoad_Leave(void);
void GameState_EnterOptionsMenu(void);
s32 Save_PfsCheckFree(void);
s32 Save_PfsDeleteFile(void);
s32 Save_PfsFindFile(void);

void SaveLoad_OverlayUpdate(void) {
    s32 i;
    f32 x;
    f32 z;
    MtxF sp18C;
    MtxF sp14C;
    MtxF sp10C;
    Mtx spC8;
    Mtx sp88;

    if (D_i13_802C8D88 == 0) {
        D_i13_802C8EA0 = (D_i13_802C8D8C * 255.0f) / 4;
    } else {
        D_i13_802C8EA0 = ((4 - (f32) D_i13_802C8D8C) * 255.0f) / 4;
    }
    D_i13_802C8D8C++;
    if (D_i13_802C8D8C >= 4) {
        D_i13_802C8D8C = 0;
        D_i13_802C8D88 ^= 1;
    }

    switch (D_i13_802C8D90) {
        case 0:
            D_i13_802C8EA4 = D_i13_802C8D94 * 255.0f / 2.0f;
            D_i13_802C8EA8 = 0;
            break;

        case 1:
            D_i13_802C8EA4 = 255;
            D_i13_802C8EA8 = D_i13_802C8D94 * 255.0f / 2.0f;
            break;

        case 2:
            D_i13_802C8EA4 = 255;
            D_i13_802C8EA8 = (2 - D_i13_802C8D94) * 255.0f / 2.0f;
            break;

        case 3:
            D_i13_802C8EA4 = (2 - D_i13_802C8D94) * 255.0f / 2.0f;
            D_i13_802C8EA8 = 0;
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
        func_800481E0(D_801CE5F8->unkA40, &D_i13_802C8EAC, 33.0f, 1.0f, 16.0f, 1024.0f, 0.0f, 0.0f);
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

Gfx* SaveLoad_Draw(Gfx* gdl) {
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
    gdl = SaveLoad_DrawMessageBox(gdl);

    if (gGameState == GAME_STATE_OPTIONS_SAVE_AND_LOAD) {
        if (D_i13_802C8D78 == 0) {
            SaveLoad_Update();
        } else {
            SaveLoad_UpdateMessageBox();
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
            var_v1 = SaveLoad_Step0();
            break;
        case 1:
        case 2:
            var_v1 = SaveLoad_Step1();
            break;
        case 3:
            var_v1 = SaveLoad_Step3();
            break;
        case 4:
            var_v1 = SaveLoad_Step4();
            break;
        case 8:
            var_v1 = SaveLoad_Step8Popup();
            break;
        case 5:
            var_v1 = SaveLoad_Step5();
            break;
        case 6:
            var_v1 = SaveLoad_Step6();
            break;
        case 7:
            var_v1 = SaveLoad_Step7();
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

s32 SaveLoad_Step0(void) {
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

s32 SaveLoad_Step1(void) {
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

s32 SaveLoad_Step3(void) {
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

s32 SaveLoad_Step4(void) {
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

s32 SaveLoad_Step8Popup(void) {
    s32 var_a2 = 0;
    f32 pos;
    f32 size;

    switch (D_i13_802C8DD0) {
        case 0:
            D_i13_802C8DC8 = 1;
            D_i13_802C8DCC++;
            pos = (f32) (5 - D_i13_802C8DCC) / 5.0f;
            size = (f32) D_i13_802C8DCC / 5.0f;
            D_i13_802C8EB0 = (s32) (129.0f * pos) + 31;
            D_i13_802C8EB4 = (s32) (20.0f * pos) + 137;
            D_i13_802C8EB8 = 258.0f * size;
            D_i13_802C8EBC = 40.0f * size;
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
            D_i13_802C8EB0 = (s32) (129.0f * pos) + 31;
            D_i13_802C8EB4 = (s32) (20.0f * pos) + 137;
            D_i13_802C8EB8 = 258.0f * size;
            D_i13_802C8EBC = 40.0f * size;
            if (D_i13_802C8DCC >= 5) {
                D_i13_802C8DD0 = 0;
                D_801CE640 = 4;
            }
            break;
    }
    return var_a2;
}

s32 SaveLoad_Step5(void) {
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

s32 SaveLoad_Step6(void) {
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

s32 SaveLoad_Step7(void) {
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
        D_i13_802C8D74 = Save_PfsRead(var_a0);
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
        D_i13_802C8D74 = Save_PfsWrite(D_i13_802C8D60[D_i13_802C8DE0[D_i13_802C8D5C]]);
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
        D_i13_802C8D74 = Save_PfsRead(5);
    } else {
        D_i13_802C8D74 = Save_PfsWrite(5);
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

void SaveLoad_UpdateMessageBox(void) {
    switch (D_i13_802C8D78) {
        case 1:
            if (D_i13_802C8E98 >= 5) {
                D_i13_802C8D78 = 2;
                D_i13_802C8E98 = 0;
            }
            break;

        case 2:
            if (++D_i13_802C8E98 >= 0xA) {
                D_i13_802C8D78 = 3;
                D_i13_802C8E98 = 0;
            }
            break;

        case 3:
            if (++D_i13_802C8DC0 >= 0x5B) {
                D_i13_802C8D78 = 0;
                D_i13_802C8E98 = 0;
                D_i13_802C8DC0 = 0;
            }
            break;
    }
}

#ifdef NON_MATCHING
// Score 310 of 106000. The original keeps y (the bottom row, 186) as a variable it does not fold:
// stored at its first use, reloaded for the second panel and for y + 3. Written plainly (y = 186)
// IDO folds it (score 7011); the two FAKE lines below get most of it back. The rest is register
// allocation: the D_i13_802C8DB4 load register ($a3 for the original's $t0), the first call's 186 ($a3, stored to y)
// and one hoisted lui t0, 0x600 the original keeps before a display-list block.
Gfx* func_i13_802C711C(Gfx* gdl) {
    s32 i;
    s32 y;
    s32 x;
    s32 pad1; // stack pad
    s32 height;
    s32 pad2[2]; // stack pad
    s32 mode3;
    s32 mode;
    s32 mode2;
    s8 drawRow1;
    s8 drawModels;
    s8 pad3; // stack pad
    s8 active;
    s8 drawRow2;
    TexLabel* tab;

    drawRow1 = false;
    drawModels = false;
    active = false;
    if (D_801CE640 != 0) {
        active = true;
    }
    drawRow2 = false;
    switch (D_801CE640) {
        case 0:
        case 1:
        case 2:
            break;

        case 3:
            drawRow1 = true;
            break;

        case 4:
        case 8:
            drawRow1 = true;
            drawModels = true;
            break;

        case 6:
        case 10:
            drawRow1 = true;
            drawRow2 = true;
            break;

        case 7:
        case 11:
            drawRow1 = true;
            drawModels = true;
            drawRow2 = true;
            break;

        case 5:
        case 9:
            drawRow2 = true;
            break;
    }

    gSPMatrix(gdl++, D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_106F550);
    gSPDisplayList(gdl++, D_106F628);
    for (i = 0; i < 3; i++) {
        gdl = func_80094338(gdl, 0, 28 + i * 89, 48, 86, 16);
    }
    gdl = func_80094338(gdl, 0, 28, 68, 264, 40);
    x = 186; // FAKE: y is copied from another variable, so IDO does not fold it
    if (drawRow1) {
        gdl = func_80094338(gdl, 0, 56, 112, 100, 16);
        gdl = func_80094338(gdl, 0, 164, 112, 100, 16);
        if (1) {} if (1) {} if (1) {} if (1) {} // FAKE: four empty tests move the register allocation (found with the permuter); any four blocks here do
    }
    if (drawModels) {
        gdl = func_80094338(gdl, 0, 28, 132, 264, 50);
    }
    y = x;
    gdl = func_80094338(gdl, 0, 56, y, 100, 16);
    x = 0; // FAKE: with x redefined here the second panel reloads y too
    gdl = func_80094338(gdl, 0, 164, y, 100, 16);

    if (drawModels) {
        gSPDisplayList(gdl++, D_806FD08);
    }
    if (drawModels) {
        gdl = func_80093AFC(gdl);
        gDPPipeSync(gdl++);
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_K0_TO_PHYSICAL(gFrameBuffers[gFramebuffersIdx]));
        gSPPerspNormalize(gdl++, D_i13_802C8EAC);
        gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPDisplayList(gdl++, D_106F488);
        gSPDisplayList(gdl++, D_806FDD0);
        gSPMatrix(gdl++, D_7000A80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, 0, 0, 0, D_801CE5F8->unkC80[0]);
        gSPDisplayList(gdl++, D_806FDE0);
        gSPMatrix(gdl++, D_7000AC0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, 2, 0, 0, D_801CE5F8->unkC80[1]);
        gSPDisplayList(gdl++, D_806FDF0);
        gSPMatrix(gdl++, D_7000B00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, 3, 0, 0, D_801CE5F8->unkC80[2]);
        gSPDisplayList(gdl++, D_806FE00);
        gSPMatrix(gdl++, D_7000B40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gdl = func_801E4FE8(gdl, 1, 0, 0, D_801CE5F8->unkC80[3]);
    }

    gSPDisplayList(gdl++, D_806FAB0);
    gSPDisplayList(gdl++, D_806FB30);
    gSPDisplayList(gdl++, D_806FB88);
    if (active) {
        gSPDisplayList(gdl++, D_806FBE0);
        if (D_i13_802C8D50 == 0) {
            if (D_i13_802C8D54 == 0) {
                gSPDisplayList(gdl++, D_806FC08);
            } else {
                gSPDisplayList(gdl++, D_806FC68);
            }
            gDPSetPrimColor(gdl++, 0, 0, D_i13_802C8EA0, 255, D_i13_802C8EA0, 255);
            gSPDisplayList(gdl++, D_806FC48);
            gSPDisplayList(gdl++, D_806FCA8);
        } else {
            if (D_801CE640 != 0) {
                if (D_i13_802C8D54 == 0) {
                    gDPSetPrimColor(gdl++, 0, 0, D_i13_802C8EA0, 255, D_i13_802C8EA0, 255);
                } else {
                    gDPSetPrimColor(gdl++, 0, 0, 128, 128, 128, 255);
                }
            }
            gSPDisplayList(gdl++, D_806FC08);
            gSPDisplayList(gdl++, D_806FC48);
            if (D_801CE640 != 0) {
                if ((D_i13_802C8D54 == 1) && (D_801CE640 != 0)) {
                    gDPSetPrimColor(gdl++, 0, 0, D_i13_802C8EA0, 255, D_i13_802C8EA0, 255);
                } else {
                    gDPSetPrimColor(gdl++, 0, 0, 64, 64, 64, 255);
                }
            }
            gSPDisplayList(gdl++, D_806FC68);
            gSPDisplayList(gdl++, D_806FCA8);
        }
    }

    if (D_801CE640 != 0) {
        gSPDisplayList(gdl++, D_806FCC8);
        gDPSetPrimColor(gdl++, 0, 0, D_i13_802C8EA4, D_i13_802C8EA8, 0, 255);
        if (D_i13_802C8D54 == 0) {
            x = 24;
        } else {
            x = 248;
        }
        gSPTextureRectangle(gdl++, (x + 8) << 2, 72 << 2, (x + 40) << 2, 104 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    if (drawModels) {
        gDPSetPrimColor(gdl++, 0, 0, D_i13_802C8EA0, 255, D_i13_802C8EA0, 255);
        gDPLoadTextureTile(gdl++, D_8061B10, G_IM_FMT_IA, G_IM_SIZ_8b, 63, 40, 0, 0, 62, 39, 0, G_TX_CLAMP, G_TX_CLAMP,
                           0, 0, 0, 0);
        gSPTextureRectangle(gdl++, (D_i13_802C8D5C * 65 + 31) << 2, 137 << 2, (D_i13_802C8D5C * 65 + 94) << 2, 177 << 2,
                            0, 0, 0, 1 << 10, 1 << 10);
    }

    gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 2, 0, 66, 22, 0);
    gdl = TexLabel_Draw(gdl, 4, 12, 87, 206, 0);
    gdl = TexLabel_Draw(gdl, 4, 13, 169, 206, 0);
    gdl = TexLabel_Draw(gdl, 1, D_i13_802C8D9C[D_i13_802C8D50].texture, D_i13_802C8DB4[D_i13_802C8D50] + 139, 82, 0);
    gdl = TexLabel_Draw(gdl, 0, 0, 67, 95, 0);
    gdl = TexLabel_Draw(gdl, 0, 1, 161, 95, 0);
    tab = D_i13_802C8D9C;
    for (i = 0; i < 3; i++, tab++) {
        if (i == D_i13_802C8D50) {
            mode = 6;
        } else {
            mode = 0;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, tab->texture, i * 89 + tab->x + 53, 51, 0);
    }

    if (drawRow1) {
        if (D_i13_802C8D58 == 0) {
            mode = 6;
            mode2 = 0;
        } else {
            mode = 0;
            mode2 = 6;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, 2, 68, 115, 0);
        gdl = Printer_SetMode(gdl, mode2, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, 64, 170, 115, 0);
    }

    if (drawRow2) {
        if (D_i13_802C8D70 == 0) {
            mode = 6;
            mode2 = 0;
        } else {
            mode = 0;
            mode2 = 6;
        }
    } else {
        mode2 = 7;
        mode = 7;
    }
    gdl = Printer_SetMode(gdl, mode, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 1, 4, 76, y + 3, 0);
    gdl = Printer_SetMode(gdl, mode2, 128, 128, 128, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    gdl = TexLabel_Draw(gdl, 1, 5, 187, y + 3, 0);

    if (D_i13_802C8DC8 != 0) {
        gdl = func_801E7E74(gdl, 0, 0, 0, 255);
        // FAKE: the (u32) casts are no-ops on the u32 globals; they give the original's operand order
        gdl = func_801E7FD8(gdl, D_i13_802C8EB0, D_i13_802C8EB4, (u32) D_i13_802C8EB0 + D_i13_802C8EB8,
                            (u32) D_i13_802C8EB4 + D_i13_802C8EBC);
    }

    if (D_i13_802C8DD4 != 0) {
        gSPDisplayList(gdl++, D_106F628);
        gdl = func_80094338(gdl, 0, 56, 147, 100, 16);
        gdl = func_80094338(gdl, 0, 164, 147, 100, 16);
        if (D_i13_802C8DC4 == 0) {
            mode = 6;
            mode3 = 0;
        } else {
            mode = 0;
            mode3 = 6;
        }
        gdl = Printer_SetMode(gdl, mode, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, 38, 84, 150, 0);
        gdl = Printer_SetMode(gdl, mode3, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
        gdl = TexLabel_Draw(gdl, 1, 39, 192, 150, 0);
    }

    switch (D_i13_802C8D84) {
        case 1:
            D_i13_802C8E98++;
            height = D_i13_802C8E98 * 20 / 5;
            if (D_i13_802C8E98 >= 5) {
                D_i13_802C8E90 = 0x1C;
                D_i13_802C8E94 = 0x44;
                D_i13_802C8D84 = 5;
                D_i13_802C8E98 = 0;
            } else {
                D_i13_802C8E94 = 0x58 - height;
            }
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl =
                func_801E7FD8(gdl, D_i13_802C8E90, D_i13_802C8E94, D_i13_802C8E90 + 0x108, height * 2 + D_i13_802C8E94);
            break;

        case 5:
        case 6:
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl = func_801E7FD8(gdl, D_i13_802C8E90, D_i13_802C8E94, D_i13_802C8E90 + 0x108, D_i13_802C8E94 + 0x28);
            gdl = SaveLoad_DrawMessage(gdl, 1);
            if (D_i13_802C8D84 == 5) {
                D_i13_802C8E98++;
                if (D_i13_802C8E98 >= 2) {
                    D_i13_802C8D84 = 6;
                }
            } else {
                D_i13_802C8D80 = 1;
            }
            break;
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")
#endif

void SaveLoad_OpenResultMessage(s32 arg0) {
    s32 var_v0;

    D_i13_802C8D84 = 0;
    D_i13_802C8D78 = 1;
    D_i13_802C8E90 = 0x1C;
    D_i13_802C8E94 = 0x44;
    D_i13_802C8E98 = 0;
    var_v0 = 0;
    switch (arg0) {
        case 1:
            var_v0 = 1;
            D_i13_802C8E9C = 4;
            break;
        case 6:
            var_v0 = 1;
            D_i13_802C8E9C = 6;
            break;
        case 3:
            var_v0 = 1;
            D_i13_802C8E9C = 0;
            break;
        case 4:
            var_v0 = 1;
            D_i13_802C8E9C = 2;
            break;
        case 2:
        case 5:
            var_v0 = 1;
            if (D_i13_802C8D50 == 0) {
                D_i13_802C8E9C = 1;
            } else {
                D_i13_802C8E9C = 3;
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
    D_i13_802C8E90 = 0x1C;
    D_i13_802C8E94 = 0x44;
    D_i13_802C8E98 = 0;
    switch (arg0) {
        case 2:
            D_i13_802C8E9C = 5;
            break;
        case 3:
            D_i13_802C8E9C = 7;
            break;
        case 4:
            D_i13_802C8E9C = 8;
            break;
    }
}

Gfx* SaveLoad_DrawMessageBox(Gfx* gdl) {
    s32 height;

    switch (D_i13_802C8D78) {
        case 1:
            D_i13_802C8E98++;
            height = D_i13_802C8E98 * 20 / 5;
            if (D_i13_802C8E98 >= 5) {
                D_i13_802C8E90 = 0x1C;
                D_i13_802C8E94 = 0x44;
            }
            D_i13_802C8E94 = 0x58 - height;
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl =
                func_801E7FD8(gdl, D_i13_802C8E90, D_i13_802C8E94, D_i13_802C8E90 + 0x108, height * 2 + D_i13_802C8E94);
            break;

        case 2:
        case 3:
        case 5:
            gdl = func_801E7E74(gdl, 0, 0, 0, 255);
            gdl = func_801E7FD8(gdl, D_i13_802C8E90, D_i13_802C8E94, D_i13_802C8E90 + 0x108, D_i13_802C8E94 + 0x28);
            gdl = SaveLoad_DrawMessage(gdl, 0);
            break;
    }
    return gdl;
}

Gfx* SaveLoad_DrawMessage(Gfx* gdl, s32 arg1) {
    s32 i;

    if (arg1 == 0) {
        gdl = Printer_SetMode(gdl, 4, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    } else {
        gdl = Printer_SetMode(gdl, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
    }

    switch (D_i13_802C8E9C) {
        case 0:
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gdl++, &D_806AA78[i * 256 * 15], G_IM_FMT_IA, G_IM_SIZ_8b, 256, 15, 0, 0, 255, 14, 0,
                                   G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
                gSPTextureRectangle(gdl++, 32 << 2, (73 + i * 15) << 2, 288 << 2, (88 + i * 15) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);
            }
            break;

        case 1:
            gdl = TexLabel_Draw(gdl, 3, 7, 72, 80, 2);
            break;

        case 3:
            gdl = TexLabel_Draw(gdl, 3, 9, 68, 80, 2);
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
            gdl = TexLabel_Draw(gdl, 3, 15, 119, 80, 2);
            break;

        case 8:
            gdl = TexLabel_Draw(gdl, 3, 16, 120, 80, 2);
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
