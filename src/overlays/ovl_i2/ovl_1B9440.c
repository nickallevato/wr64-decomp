#include "common.h"

extern s32 D_800DA9C8[];

extern s32 D_i2_802C8BD8[];
extern u16 D_80B0008[];
extern u16 D_80B77A0[];

struct SelectionState {
    s32 ready[2];
};

// .bss
u16 D_i2_802C8C50;
struct SelectionState D_i2_802C8C58;
s32 D_i2_802C8C60[2];
s16 D_i2_802C8C68;
s16 D_i2_802C8C6A;
s16 D_i2_802C8C70[4];

void func_i2_802C5AE4(void);

void func_i2_802C5800(void) {
    s32 i;
    s32 j;
    s32 found;
    f32 x;
    f32 z;
    MtxF sp1A4;
    MtxF sp164;
    MtxF sp124;
    Mtx spE0;
    Mtx spA0;
    s32 angle;

    if ((D_801CE63C != 0) && (gGameState == GAME_STATE_RIDER_SELECT)) {
        func_i2_802C5AE4();
    }
    func_800481E0(D_801CE5F8->unkA40, &D_i2_802C8C50, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spE0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.07f);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_801CE608.player; j++) {
            found = 0;
            if (i == D_800DA9C0[j]) {
                found = 1;
            }
            if (found) {
                angle = D_i2_802C8C60[j] % 4096;
                x = COS(angle) * 500.0f;
                z = SIN(angle) * 500.0f;
            } else {
                x = COS(0x200) * 500.0f;
                z = SIN(0x200) * 500.0f;
            }
            if (found) {
                break;
            }
        }
        func_800484C8(&spA0, &sp164, x, 500.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        SysUtils_MtxToMtxF(&spE0, &sp1A4);
        SysUtils_MatrixAffineMultiply(&sp164, &sp1A4, &sp124);
        SysUtils_MtxFToMtx(&sp124, &D_801CE5F8->unkA80[i]);
    }
    for (i = 0; i < D_801CE608.player; i++) {
        D_i2_802C8C60[i] += 0x30;
        if (D_i2_802C8C60[i] >= 0x1000) {
            D_i2_802C8C60[i] -= 0x1000;
        }
    }
}

void func_i2_802C5AE4(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_i2_802C8C58.ready[i] = 0;
        D_i2_802C8C60[i] = 0;
        D_801CE6F4[i] = i;
    }
    // A do-while: the same for loop unrolls in another store order.
    i = 0;
    do {
        D_i2_802C8C70[i] = 0;
    } while (++i < 4);
    D_i2_802C8C68 = 0;
    D_i2_802C8C6A = 0;
}

void* Save_EepromWriteNames();
void* GameState_EnterCourseOverview();
void func_i2_802C5E28(void);
Gfx* func_i2_802C6ADC(Gfx*);
Gfx* func_i2_802C7C50(Gfx*);
Gfx* func_i2_802C88DC(Gfx*);
void func_i2_802C84EC(s32 arg0);
extern Gfx* D_106F808;
extern Gfx D_106FAF0[];
extern Vtx* D_2000A40;
extern Mtx* D_7000000;
extern s16 D_801CE60C;
extern s32 D_i2_802C8C5C;
extern Gfx D_80BE4A8[];
extern Gfx D_80BE500[];
extern s32 D_i2_802C8BC0;

Gfx* func_i2_802C5B4C(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_RIDER_SELECT) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gSPDisplayList(gdl++, &D_106FAF0);

    gdl = func_i2_802C88DC(gdl);
    gSPMatrix(gdl++, &D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, &D_106F808);

    if (D_801CE60C == 1) {
        gdl = func_8009328C(gdl);
    } else {
        if (D_i2_802C8C58.ready[0] == 0) {
            D_800DAB2C = 0;
            gdl = func_800933C4(gdl);
        }
        if (D_i2_802C8C5C == 0) {
            D_800DAB2C = 1;
            gdl = func_800933C4(gdl);
        }
        D_800DAB2C = 0;
    }

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    if (D_801CE60C == 1) {
        gdl = func_i2_802C6ADC(gdl);
        gSPDisplayList(gdl++, &D_80BE500);
    } else {
        gdl = func_i2_802C7C50(gdl);
        if (D_i2_802C8C58.ready[0] == 0) {
            gSPDisplayList(gdl++, &D_80BE4A8);
        }
        if (D_i2_802C8C58.ready[1] == 0) {
            gSPDisplayList(gdl++, &D_80BE500);
        }
    }
    if (gGameState == GAME_STATE_RIDER_SELECT) {
        func_i2_802C5E28();
        if (D_80228A16 == 1) {
            D_i2_802C8BC0 = 1;
        }
    } else if (D_80228A16 == 1) {
        Save_EepromWriteNames();
        switch (D_801CE630) {
            case 2:
                GameState_EnterTitleScreen();
                break;
            case 30:
                GameState_EnterCourseOverview();
                break;
            case 20:
                GameState_EnterCourseSelect();
                break;
        }
    }
    return gdl;
}

s32 func_i2_802C676C(s32 arg0, s32 arg1);
s32 func_i2_802C67E4(s32 arg0, s32 arg1);
void func_i2_802C6864(s32 arg0);
extern s32 D_i2_802C8BB0[];
extern s32 D_i2_802C8BB8[];
extern s16 D_80228A32;

#ifdef NON_MATCHING
// Score 590 of 59400: the "held" check before the repeat counter is scheduled as
// li -3 / beqzl instead of beqz with li -3 in the delay slot, which makes the function one
// instruction longer and shifts everything after it; the rest matches.
void func_i2_802C5E28(void) {
    s32 i;
    s32 ctrl;
    u32 allowMove; // FAKE (maybe): u32 gives li 1, not move from s3; also holds the rider index (one temp)
    s32 rider;
    s32 locked;
    s32 sound;
    s32 state;

    for (i = 0; i < D_801CE60C; i++) {
        if (i == 0) {
            ctrl = 0;
            rider = gPlayer1Rider;
        } else {
            ctrl = 1;
            rider = gPlayer2Rider;
        }
        if ((D_801CE658[ctrl].unk_00.unk_2 & 0xB000) && (D_i2_802C8BC0 != 0)) {
            sound = 1;
            switch (D_i2_802C8C58.ready[i]) {
                case 0:
                    D_i2_802C8C58.ready[i] = 1;
                    if ((D_800DAB64 != 0) && (D_801CE658[ctrl].unk_00.unk_2 & 0x2000)) {
                        D_801CE6F4[i] = 1;
                    }
                    if (D_801CE6F4[i] != 0) {
                        D_i2_802C8C70[D_800DA9C0[i]] |= 2;
                    } else {
                        D_i2_802C8C70[D_800DA9C0[i]] |= 1;
                    }
                    break;
                case 1:
                    if (D_800DA9C8[i] == 0) {
                        if (i == 0) {
                            D_801CB32C = 0;
                        }
                        if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
                            func_i2_802C6864(i);
                            sound = 2;
                        } else {
                            D_i2_802C8C58.ready[i] = 5;
                        }
                    } else {
                        if (i == 0) {
                            D_801CB32C = 1;
                        }
                        D_i2_802C8C58.ready[i] = 2;
                    }
                    break;
                case 2:
                    D_i2_802C8C58.ready[i] = 3;
                    break;
                case 3:
                    D_i2_802C8C58.ready[i] = 4;
                    break;
                case 4:
                    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
                        func_i2_802C6864(i);
                        sound = 2;
                    } else {
                        D_i2_802C8C58.ready[i] = 5;
                    }
                    break;
                case 5:
                    func_i2_802C6864(i);
                    break;
            }
            if (sound != 0) {
                if (D_80228A32 == 1) {
                    AudioGeneral_PlaySound(0x2A, 0);
                } else if (sound == 1) {
                    AudioGeneral_PlaySound(0x11, 0);
                } else {
                    AudioGeneral_PlaySound(0x37, 0);
                }
            }
        } else if (D_801CE658[ctrl].unk_00.unk_2 & 0x4000) {
            sound = 1;
            switch (D_i2_802C8C58.ready[i]) {
                case 0:
                    func_i2_802C84EC(2);
                    break;
                case 1:
                    D_i2_802C8C58.ready[i] = 0;
                    if (D_801CE6F4[i] != 0) {
                        D_i2_802C8C70[D_800DA9C0[i]] &= ~2;
                    } else {
                        D_i2_802C8C70[D_800DA9C0[i]] &= ~1;
                    }
                    break;
                case 5:
                    if (D_800DA9C8[i] == 0) {
                        D_i2_802C8C58.ready[i] = 1;
                    } else {
                        D_i2_802C8C58.ready[i] = 4;
                    }
                    break;
                case 2:
                    D_i2_802C8C58.ready[i] = 1;
                    break;
                case 3:
                    D_i2_802C8C58.ready[i] = 2;
                    break;
                case 4:
                    D_i2_802C8C58.ready[i] = 3;
                    break;
                default:
                    sound = 0;
                    break;
            }
            if (sound != 0) {
                AudioGeneral_PlaySound(0x16, 0);
            }
        } else {
            allowMove = 1;
            if (D_801CE658[ctrl].unk_00.unk_2 & 0xF) {
                allowMove = D_i2_802C8BD8[D_800DA9C0[i]];
                switch (D_i2_802C8C58.ready[i]) {
                    case 2:
                        ((UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames)[i][allowMove].unk_B[0] =
                            D_800DA950[allowMove].unk_B[0];
                        break;
                    case 3:
                        ((UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames)[i][allowMove].unk_B[1] =
                            D_800DA950[allowMove].unk_B[1];
                        break;
                    case 4:
                        ((UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames)[i][allowMove].unk_B[2] =
                            D_800DA950[allowMove].unk_B[2];
                        break;
                }
            } else {
                if ((gPlayers != ONE_PLAYER) && (D_800DA9C0[0] == D_800DA9C0[1])) {
                    allowMove = 0;
                }
                locked = 0;
                state = D_i2_802C8C58.ready[i];
                if (state == 0) {
                    if (allowMove) {
                        if (D_801CE658[ctrl].unk_00.unk_0 & 0x800) {
                            locked = 1;
                            D_801CE6F4[i] = i ^ 1;
                        } else {
                            D_801CE6F4[i] = i;
                        }
                    } else if (D_i2_802C8C70[D_800DA9C0[i]] == 0) {
                        D_801CE6F4[i] = i;
                    } else if (D_i2_802C8C70[D_800DA9C0[i]] & 1) {
                        D_801CE6F4[i] = 1;
                    } else {
                        D_801CE6F4[i] = 0;
                    }
                    if ((D_800DAB60 != 0) && (D_801CE60C == 1)) {
                        if (D_801CE658[ctrl].unk_00.unk_0 & 0x400) {
                            D_800DAB64 = 1;
                        } else {
                            D_800DAB64 = 0;
                        }
                    }
                }
                D_i2_802C8BB0[i] = 0;
                if (D_801CE658[ctrl].unk_00.unk_2 & 0x200) {
                    sound = 1;
                    switch (state) {
                        case 0:
                            if (locked) {
                                sound = 0;
                            } else {
                                D_800DA9C0[i]--;
                                if (D_800DA9C0[i] < 0) {
                                    D_800DA9C0[i] = 3;
                                }
                                D_i2_802C8C60[i] = 0x200;
                            }
                            break;
                        case 1:
                            D_800DA9C8[i]--;
                            if (D_800DA9C8[i] < 0) {
                                D_800DA9C8[i] = 1;
                            }
                            break;
                        case 2:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C676C(i, 0);
                            break;
                        case 3:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C676C(i, 1);
                            break;
                        case 4:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C676C(i, 2);
                            break;
                        default:
                            sound = 0;
                            break;
                    }
                    if (sound != 0) {
                        AudioGeneral_PlaySound(0x10, 0);
                    }
                } else if (D_801CE658[ctrl].unk_00.unk_2 & 0x100) {
                    sound = 1;
                    switch (state) {
                        case 0:
                            if (locked) {
                                sound = 0;
                            } else {
                                D_800DA9C0[i]++;
                                if (D_800DA9C0[i] == 4) {
                                    D_800DA9C0[i] = 0;
                                }
                                D_i2_802C8C60[i] = 0x200;
                            }
                            break;
                        case 1:
                            D_800DA9C8[i]++;
                            if (D_800DA9C8[i] == 2) {
                                D_800DA9C8[i] = 0;
                            }
                            break;
                        case 2:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C67E4(i, 0);
                            break;
                        case 3:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C67E4(i, 1);
                            break;
                        case 4:
                            D_i2_802C8BB0[i] = 1;
                            sound = func_i2_802C67E4(i, 2);
                            break;
                        default:
                            sound = 0;
                            break;
                    }
                    if (sound != 0) {
                        AudioGeneral_PlaySound(0x10, 0);
                    }
                }
                if (D_i2_802C8BB0[i] != 0) {
                    D_i2_802C8BB8[i] = -3;
                } else {
                    D_i2_802C8BB8[i]++;
                    if (D_i2_802C8BB8[i] >= 4) {
                        D_i2_802C8BB8[i] = 0;
                        if (D_801CE658[ctrl].unk_00.unk_0 & 0x200) {
                            switch (D_i2_802C8C58.ready[i]) {
                                case 2:
                                    sound = func_i2_802C676C(i, 0);
                                    break;
                                case 3:
                                    sound = func_i2_802C676C(i, 1);
                                    break;
                                case 4:
                                    sound = func_i2_802C676C(i, 2);
                                    break;
                                default:
                                    sound = 0;
                                    break;
                            }
                            if (sound != 0) {
                                AudioGeneral_PlaySound(0x10, 0);
                            }
                        } else if (D_801CE658[ctrl].unk_00.unk_0 & 0x100) {
                            switch (D_i2_802C8C58.ready[i]) {
                                case 2:
                                    sound = func_i2_802C67E4(i, 0);
                                    break;
                                case 3:
                                    sound = func_i2_802C67E4(i, 1);
                                    break;
                                case 4:
                                    sound = func_i2_802C67E4(i, 2);
                                    break;
                                default:
                                    sound = 0;
                                    break;
                            }
                            if (sound != 0) {
                                AudioGeneral_PlaySound(0x10, 0);
                            }
                        }
                    }
                }
            }
        }
        if (D_i2_802C8C58.ready[i] == 0) {
            D_80192690[rider].unkB68 = D_i2_802C8BD8[D_800DA9C0[i]];
            D_80192690[rider].unkB6C = D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]].unk_B[0];
            D_80192690[rider].unkB70 = D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]].unk_B[1];
            D_80192690[rider].unkB74 = D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]].unk_B[2];
        }
    }
    SysUtils_Rand();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C5E28.s")
#endif

s32 func_i2_802C676C(s32 arg0, s32 arg1) {
    UnkStruct_func_i8_802C6E00(*tbl)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames;
    s32 idx = D_i2_802C8BD8[D_800DA9C0[arg0]];
    s32 ret = 1;

    tbl[arg0][idx].unk_B[arg1]--;
    if (tbl[arg0][idx].unk_B[arg1] < 0) {
        ret = 0;
        tbl[arg0][idx].unk_B[arg1] = 0;
    }
    return ret;
}

s32 func_i2_802C67E4(s32 arg0, s32 arg1) {
    UnkStruct_func_i8_802C6E00(*tbl)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames;
    s32 idx = D_i2_802C8BD8[D_800DA9C0[arg0]];
    s32 ret = 1;

    tbl[arg0][idx].unk_B[arg1]++;
    if (tbl[arg0][idx].unk_B[arg1] == 12) {
        ret = 0;
        tbl[arg0][idx].unk_B[arg1] = 11;
    }
    return ret;
}

void func_i2_802C6864(s32 arg0) {
    s32 ready = 0;
    s32 i;
    s32 j;
    s32 arg;
    s8 used[4];

    if (D_801CE608.player == 1) {
        ready = 1;
    } else {
        D_i2_802C8C58.ready[arg0] = 6;
        if (D_i2_802C8C58.ready[0] == 6 && D_i2_802C8C58.ready[1] == 6) {
            ready = 1;
        }
    }

    if (ready) {
        switch (D_801CE608.gameMode) {
            case 4:
                for (i = 0; i < 4; i++) {
                    used[i] = 0;
                }
                used[D_800DA9C0[0]] = 1;
                for (i = 0; i < 4; i++) {
                    if (i != gPlayer1Rider) {
                        for (j = 0; j < 4; j++) {
                            if (used[j] == 0) {
                                used[j] = 1;
                                break;
                            }
                        }
                        if (j == 4) {
                            j--;
                        }
                        D_800DA9B0[i] = D_i2_802C8BD8[j];
                        D_80192690[i].unkB68 = D_800DA9B0[i];
                        D_80192690[i].unkB6C = D_800D96A4[gCourseID][D_800DA9B0[i]].unk0;
                        D_80192690[i].unkB70 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk4;
                        D_80192690[i].unkB74 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk8;
                    } else {
                        D_800DA9B0[i] = D_i2_802C8BD8[D_800DA9C0[0]];
                    }
                }
                arg = 0x1E;
                break;
            case 0:
            case 11:
                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
                D_800DA9B0[1] = 0;
                D_800DA9B0[2] = 0;
                D_800DA9B0[3] = 0;
                arg = 0x14;
                break;
            case 1:
                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
                D_800DA9B0[1] = D_i2_802C8BD8[D_800DA9C0[1]];
                D_800DA9B0[2] = 0;
                D_800DA9B0[3] = 0;
                arg = 0x14;
                break;
        }
        func_i2_802C84EC(arg);
    }
}

Gfx* func_i2_802C70EC(Gfx* gdl, s32 player);
Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y);
Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx);
extern Gfx D_106F488[];
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern u8 D_80B6590[];
extern Gfx D_80BE248[];
extern Gfx D_80BE2B8[];
extern Gfx D_80BE468[];
extern Gfx D_80BE478[];
extern Gfx D_80BE488[];
extern Gfx D_80BE498[];
extern s16 D_i2_802C8BD0[];

Gfx* func_i2_802C6ADC(Gfx* gdl) {
    u32 shade;

    gSPDisplayList(gdl++, D_80BE248);
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 28, 22, 264, 30);
    gdl = func_80094338(gdl, 0, 28, 96, 130, 13);
    gdl = func_80094338(gdl, 0, 32, 110, 59, 13);
    gdl = func_80094338(gdl, 0, 95, 110, 59, 13);
    gdl = func_i2_802C86E4(gdl, 19, 104);
    if (D_i2_802C8C58.ready[0] != 5) {
        gSPDisplayList(gdl++, D_80BE2B8);
    }
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    if (D_i2_802C8C6A == 0) {
        shade = (D_i2_802C8C68 * 255.0f) / 4;
    } else {
        shade = ((4 - (f32) D_i2_802C8C68) * 255.0f) / 4;
    }
    D_i2_802C8C68++;
    if (D_i2_802C8C68 >= 4) {
        D_i2_802C8C68 = 0;
        D_i2_802C8C6A ^= 1;
    }
    gDPSetPrimColor(gdl++, 0, 0, shade, 255, shade, 255);
    gDPLoadTextureTile(gdl++, D_80B6590, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 63, 35, 0, G_TX_CLAMP, G_TX_CLAMP, 0,
                       0, 0, 0);
    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[0]] + 72) << 2, 91 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gdl = func_i2_802C70EC(gdl, 0);
    gSPPerspNormalize(gdl++, D_i2_802C8C50);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    gSPDisplayList(gdl++, D_80BE468);
    gSPMatrix(gdl++, &D_7000A80[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 0, 0, 0, D_801CE5F8->unkC80[0]);
    gSPDisplayList(gdl++, D_80BE478);
    gSPMatrix(gdl++, &D_7000A80[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 2, 0, 0, D_801CE5F8->unkC80[1]);
    gSPDisplayList(gdl++, D_80BE488);
    gSPMatrix(gdl++, &D_7000A80[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 3, 0, 0, D_801CE5F8->unkC80[2]);
    gSPDisplayList(gdl++, D_80BE498);
    gSPMatrix(gdl++, &D_7000A80[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return func_801E4FE8(gdl, 1, 0, 0, D_801CE5F8->unkC80[3]);
}

extern u16 D_80B6518[];
extern u8 D_80BBFA8[];

Gfx* func_i2_802C70EC(Gfx* gdl, s32 player) {
    s32 showBars;
    s32 showMode;
    s32 showName;
    s32 stateGe2;
    s32 stateLive; // D_i2_802C8C58 entry 1..5
    UnkStruct_func_i8_802C6E00* entry;
    s32 x;
    s32 nameX;

    if (player == 0) {
        x = 19;
    } else {
        x = 153;
    }
    if ((D_800DA9C8[player] == 0) || (D_i2_802C8C58.ready[player] == 0)) {
        entry = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]];
    } else {
        entry = &((UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames)[player][D_i2_802C8BD8[D_800DA9C0[player]]];
    }
    showBars = 0;
    showMode = 0;
    showName = 0;
    stateGe2 = 0;
    stateLive = 0;
    if (D_i2_802C8C58.ready[player] >= 2) {
        stateGe2 = 1;
    }
    if ((D_i2_802C8C58.ready[player] > 0) && (D_i2_802C8C58.ready[player] != 6)) {
        stateLive = 1;
    }
    if (D_801CE60C == 1) {
        if (D_i2_802C8C58.ready[player] != 5) {
            showBars = 1;
        }
        showMode = 1;
        showName = 1;
        nameX = x + 161;
    } else {
        if ((D_i2_802C8C58.ready[player] > 0) && (D_i2_802C8C58.ready[player] < 5)) {
            showBars = 1;
        }
        if (D_i2_802C8C58.ready[player] > 0) {
            showMode = 1;
        }
        if (D_i2_802C8C58.ready[player] == 0) {
            showName = 1;
        }
        nameX = x + 27;
    }
    if (showBars) {
        gDPPipeSync(gdl++);
        gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPLoadTextureTile(gdl++, D_80B6518, G_IM_FMT_RGBA, G_IM_SIZ_16b, 9, 6, 0, 0, 8, 5, 0, G_TX_CLAMP, G_TX_CLAMP,
                           0, 0, 0, 0);
        gSPTextureRectangle(gdl++, (entry->unk_B[0] * 10 + x + 14) << 2, 147 << 2, (entry->unk_B[0] * 10 + x + 23) << 2,
                            153 << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gdl++, (entry->unk_B[1] * 10 + x + 14) << 2, 176 << 2, (entry->unk_B[1] * 10 + x + 23) << 2,
                            182 << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gdl++, (entry->unk_B[2] * 10 + x + 14) << 2, 205 << 2, (entry->unk_B[2] * 10 + x + 23) << 2,
                            211 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    gdl = Printer_SetMode(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    if (player == 0) {
        gdl = func_801E3EE0(gdl, 2, 3, 38, 28, 0);
        gdl = func_801E3EE0(gdl, 4, 12, 222, 26, 0);
        gdl = func_801E3EE0(gdl, 4, 13, 222, 37, 0);
    }
    if (showBars) {
        if ((D_i2_802C8C58.ready[player] != 2) || !stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 9, x + 13, 128, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 6, x + 13, 138, 0);
        gdl = func_801E3EE0(gdl, 0, 7, x + 98, 138, 0);
        if ((D_i2_802C8C58.ready[player] != 3) || !stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 11, x + 13, 156, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 9, x + 13, 167, 0);
        gdl = func_801E3EE0(gdl, 0, 10, x + 89, 167, 0);
        if ((D_i2_802C8C58.ready[player] != 4) || !stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 10, x + 13, 185, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 12, x + 13, 196, 0);
        gdl = func_801E3EE0(gdl, 0, 11, x + 103, 196, 0);
    }
    if (showName) {
        if (player == 0) {
            gdl = Printer_DrawString(gdl, 1, gPlayerNames[D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, nameX, 203);
        } else {
            gdl = Printer_DrawString(gdl, 1, D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, nameX, 203);
        }
    }
    if (showMode) {
        gdl = func_801E3EE0(gdl, 0, 37, x + 12, 98, 0);
        if ((D_800DA9C8[player] != 0) || !stateLive) {
            gdl = func_801E3EE0(gdl, 0, 3, x + 21, 112, 0);
        }
        if ((D_800DA9C8[player] != 1) || !stateLive) {
            gdl = func_801E3EE0(gdl, 0, 38, x + 84, 112, 0);
        }
    }
    if (D_i2_802C8C58.ready[player] >= 5) {
        gdl = Printer_SetMode(gdl, (D_i2_802C8C58.ready[player] == 5) ? 6 : 7, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPLoadTextureTile(gdl++, D_80BBFA8, G_IM_FMT_IA, G_IM_SIZ_8b, 88, 10, 0, 0, 87, 9, 0, G_TX_CLAMP, G_TX_CLAMP,
                           0, 0, 0, 0);
        gSPTextureRectangle(gdl++, (x + 29) << 2, 162 << 2, (x + 117) << 2, 172 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    gdl = Printer_SetMode(gdl, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    if (showBars) {
        if ((D_i2_802C8C58.ready[player] == 2) && stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 9, x + 13, 128, 0);
        }
        if ((D_i2_802C8C58.ready[player] == 3) && stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 11, x + 13, 156, 0);
        }
        if ((D_i2_802C8C58.ready[player] == 4) && stateGe2) {
            gdl = func_801E3EE0(gdl, 4, 10, x + 13, 185, 0);
        }
    }
    if (showMode) {
        if ((D_800DA9C8[player] == 0) && stateLive) {
            gdl = func_801E3EE0(gdl, 0, 3, x + 21, 112, 0);
        }
        if ((D_800DA9C8[player] == 1) && stateLive) {
            gdl = func_801E3EE0(gdl, 0, 38, x + 84, 112, 0);
        }
    }
    return gdl;
}

extern u8 D_80B6E98[];
extern Gfx D_80BE358[];
extern Gfx D_80BE3C8[];

Gfx* func_i2_802C7C50(Gfx* gdl) {
    u32 shade;
    s32 width;

    gSPDisplayList(gdl++, D_80BE358);
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 28, 22, 264, 30);
    if (D_i2_802C8C58.ready[0] != 0) {
        gdl = func_80094338(gdl, 0, 28, 96, 130, 13);
        gdl = func_80094338(gdl, 0, 32, 110, 59, 13);
        gdl = func_80094338(gdl, 0, 95, 110, 59, 13);
    }
    if (D_i2_802C8C58.ready[1] != 0) {
        gdl = func_80094338(gdl, 0, 161, 96, 130, 13);
        gdl = func_80094338(gdl, 0, 165, 110, 59, 13);
        gdl = func_80094338(gdl, 0, 228, 110, 59, 13);
    }
    if (D_i2_802C8C58.ready[0] != 0) {
        gdl = func_i2_802C86E4(gdl, 19, 104);
    }
    if (D_i2_802C8C58.ready[1] != 0) {
        gdl = func_i2_802C86E4(gdl, 153, 104);
    }
    if ((D_i2_802C8C58.ready[0] != 0) && (D_i2_802C8C58.ready[0] < 5)) {
        gSPDisplayList(gdl++, D_80BE2B8);
    }
    if ((D_i2_802C8C58.ready[1] != 0) && (D_i2_802C8C58.ready[1] < 5)) {
        gSPDisplayList(gdl++, D_80BE3C8);
    }
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    if (D_i2_802C8C6A == 0) {
        shade = (D_i2_802C8C68 * 255.0f) / 4;
    } else {
        shade = ((4 - (f32) D_i2_802C8C68) * 255.0f) / 4;
    }
    D_i2_802C8C68++;
    if (D_i2_802C8C68 >= 4) {
        D_i2_802C8C68 = 0;
        D_i2_802C8C6A ^= 1;
    }
    if (D_800DA9C0[0] == D_800DA9C0[1]) {
        width = 32;
    } else {
        width = 64;
    }
    gDPSetPrimColor(gdl++, 0, 0, 255, shade, shade, 255);
    gDPLoadTextureTile(gdl++, D_80B6E98, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 63, 35, 0, G_TX_CLAMP, G_TX_CLAMP, 0,
                       0, 0, 0);
    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[1]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[1]] + 72) << 2, 91 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPSetPrimColor(gdl++, 0, 0, shade, 255, shade, 255);
    gDPLoadTextureTile(gdl++, D_80B6590, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 63, 35, 0, G_TX_CLAMP, G_TX_CLAMP, 0,
                       0, 0, 0);
    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[0]] + width + 8) << 2, 91 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gdl = func_i2_802C70EC(gdl, 0);
    gdl = func_i2_802C70EC(gdl, 1);
    gSPPerspNormalize(gdl++, D_i2_802C8C50);
    gSPMatrix(gdl++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, D_106F488);
    gSPDisplayList(gdl++, D_80BE468);
    gSPMatrix(gdl++, &D_7000A80[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 0, 0, 0, D_801CE5F8->unkC80[0]);
    gSPDisplayList(gdl++, D_80BE478);
    gSPMatrix(gdl++, &D_7000A80[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 2, 0, 0, D_801CE5F8->unkC80[1]);
    gSPDisplayList(gdl++, D_80BE488);
    gSPMatrix(gdl++, &D_7000A80[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 3, 0, 0, D_801CE5F8->unkC80[2]);
    gSPDisplayList(gdl++, D_80BE498);
    gSPMatrix(gdl++, &D_7000A80[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return func_801E4FE8(gdl, 1, 0, 0, D_801CE5F8->unkC80[3]);
}

void func_i2_802C84EC(s32 arg0) {
    UnkStruct_func_i8_802C6E00(*tbl)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) gPlayerNames;
    UnkStruct_func_i8_802C6E00* entry;
    s32 player;
    s32 i;

    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0xB;
    D_801CE638 = 4;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    gVIsPerFrame = 3;

    for (i = 0; i < D_801CE60C; i++) {
        if (D_800DA9C8[i] == 0) {
            entry = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]];
        } else {
            entry = &tbl[i][D_i2_802C8BD8[D_800DA9C0[i]]];
        }

        player = (i == 0) ? gPlayer1Rider : gPlayer2Rider;
        D_80192690[player].unkB6C = entry->unk_B[0];
        D_80192690[player].unkB70 = entry->unk_B[1];
        D_80192690[player].unkB74 = entry->unk_B[2];
    }

    if (D_801CE608.gameMode == 4 && D_801CE630 == 0x1E) {
        FadeTransition_SetProps(5, 0, 0);
    } else {
        FadeTransition_SetProps(1, 4, 0);
    }
    Popup_Spawn(0, 0);
    if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
    }
}

Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {
    s32 offset;
    s32 i;
    s32 height;

    for (offset = 0, i = 0; i < 105; i += 15, offset += 0x79E) {
        if (i != 90) {
            height = 15;
        } else {
            height = 2;
        }
        gDPLoadTextureTile(gdl++, D_80B0008 + offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 130, height, 0, 0, 129, height - 1,
                           0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
        gSPTextureRectangle(gdl++, (x + 8) << 2, (y + i + 20) << 2, (x + 138) << 2, (y + i + height + 20) << 2, 0, 0, 0,
                            1 << 10, 1 << 10);
    }
    return gdl;
}

Gfx* func_i2_802C88DC(Gfx* gdl) {
    s32 pad[15]; // stack pad: the original frame is 0x78
    s32 row;
    s32 offset;
    s32 height;
    s32 i;
    s32 j;

    for (row = 0, offset = 0; row < 100; row += 5, offset += 96 * 5) {
        if (row == 95) {
            height = 1;
        } else {
            height = 5;
        }
        gDPLoadTextureBlock(gdl++, D_80B77A0 + offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, height, 0, G_TX_CLAMP,
                            G_TX_CLAMP, 0, 0, 0, 0);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                gSPScisTextureRectangle(gdl++, (j * 96) << 2, (i * 96 + row) << 2, ((j + 1) * 96) << 2,
                                        (i * 96 + row + height) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            }
        }
    }
    return gdl;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/D_i2_802C8BE0.s")
