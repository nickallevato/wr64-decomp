#include "global.h"

extern UnkStruct_menu_buffer_1 D_80226C50;

extern UnkStruct_menu_buffer_1 menu_buffer_1[];

void func_801E5470(void) {
    UnkStruct_menu_buffer_1* var_s0;
    s32 i;

    for (i = 0; i < 5; i++) {
        switch (menu_buffer_1[i].unk_0) {
            case 1:
                menu_buffer_1[i].unk_6 = 1;
                func_801E6074(&menu_buffer_1[i]);
                break;
            case 2:
                menu_buffer_1[i].unk_6 = 1;
                func_801E62A8(&menu_buffer_1[i]);
                break;
            case 3:
                menu_buffer_1[i].unk_6 = 1;
                func_801E66F4(&menu_buffer_1[i]);
                break;
            case 4:
                menu_buffer_1[i].unk_6 = 1;
                func_801E68EC(&menu_buffer_1[i]);
                break;
        }
    }
}

#ifdef NON_MATCHING
// Regalloc only: case 4's loop counter and its texture-offset induction temp swap $t0/$t1 (6 instructions).
extern Gfx D_106F030[];
extern Gfx D_106F0A8[];
extern Gfx D_106F3A0[];
extern Gfx D_106F408[];
extern u8 D_7000000[];
extern u32 D_8042008[];
extern u32 D_8049008[];
extern u32 D_8058008[];
extern u32 D_8071008[];
extern RiderStruct D_801C2938[];

Gfx* func_801E8800(Gfx*, u32, s32, s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, f32);

Gfx* func_801E5554(Gfx* gdl) {
    s32 off;
    u32 width;
    s32 j;
    s32 i;
    s32 xoff;
    UnkStruct_menu_buffer_1* slot;
    u32* tex;
    s32 row;
    s32 h;

    for (j = 0; j < 5; j++) {
        slot = &menu_buffer_1[j];
        if (slot->unk_6 != 0) {
            switch (slot->unk_0) {
                case 1:
                    if (slot->unk2 == 1) {
                        gSPDisplayList(gdl++, D_106F030);
                    } else {
                        gSPDisplayList(gdl++, D_106F0A8);
                        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                        gSPMatrix(gdl++, D_7000000 + ((u16) slot->unk4 << 6) + 0x900,
                                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    }
                    off = 0;
                    row = 0;
                    do {
                        gDPLoadTextureTile(gdl++, D_8042008 + off, G_IM_FMT_RGBA, G_IM_SIZ_32b, 160, 0, 0, 0, 159, 4, 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        if (slot->unk2 == 1) {
                            gSPTextureRectangle(gdl++, slot->unk8 << 2, (slot->unkC + row) << 2,
                                                (slot->unk8 + 160) << 2, (slot->unkC + row + 5) << 2, G_TX_RENDERTILE,
                                                0, 0, 1 << 10, 1 << 10);
                        } else {
                            gdl = func_801E8800(gdl, 160, 6, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                                0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
                        }
                        row += 5;
                        off += 160 * 5;
                    } while (row != 40);
                    break;
                case 2:
                    if (slot->unk2 == 1) {
                        gSPDisplayList(gdl++, D_106F030);
                    } else {
                        gSPDisplayList(gdl++, D_106F0A8);
                        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                        gSPMatrix(gdl++, D_7000000 + ((u16) slot->unk4 << 6) + 0x900,
                                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    }
                    if (slot->unk28 != 0) {
                        row = 0;
                        off = 0;
                        do {
                            gDPLoadTextureTile(gdl++, D_8049008 + off, G_IM_FMT_RGBA, G_IM_SIZ_32b, 204, 0, 0, 0, 203,
                                               4, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            if (slot->unk2 == 1) {
                                gSPTextureRectangle(gdl++, slot->unk8 << 2, (slot->unkC + row) << 2,
                                                    (slot->unk8 + 204) << 2, (slot->unkC + row + 5) << 2,
                                                    G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                            } else {
                                h = (off == 204 * 25) ? 4 : 6;
                                gdl = func_801E8800(gdl, 204, h, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                                    0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
                            }
                            off += 204 * 5;
                            row += 5;
                        } while (off != 204 * 30);
                    } else {
                        off = 0;
                        row = 0;
                        do {
                            gDPLoadTextureTile(gdl++, D_8049008 + D_801C2938[D_800D48DC].racePosition * 3200 + off,
                                               G_IM_FMT_RGBA, G_IM_SIZ_32b, 80, 0, 0, 0, 79, 2, 0,
                                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            h = (row == 38) ? 1 : 3;
                            if (slot->unk2 == 1) {
                                gSPTextureRectangle(gdl++, slot->unk8 << 2, (slot->unkC + row) << 2,
                                                    (slot->unk8 + 80) << 2, (slot->unkC + row + 2) << 2,
                                                    G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                            } else {
                                gdl = func_801E8800(gdl, 80, h, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                                    0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
                            }
                            row += 2;
                            off += 80 * 2;
                        } while (row != 40);
                    }
                    break;
                case 3:
                    gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                    gSPMatrix(gdl++, D_7000000 + ((u16) slot->unk4 << 6) + 0x900,
                              G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    gSPDisplayList(gdl++, D_106F3A0);
                    gSPDisplayList(gdl++, D_106F408);
                    break;
                case 4:
                    if (slot->unk28 != 0) {
                        xoff = -8;
                        width = 176;
                        tex = D_8071008;
                    } else {
                        xoff = 0;
                        width = 160;
                        tex = D_8058008;
                    }
                    gSPDisplayList(gdl++, D_106F030);
                    for (i = 0, row = 0; i != 8; i++, row += 5) {
                        gDPLoadTextureTile(gdl++, tex + width * 5 * i, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, 0, 0, 0,
                                           width - 1, 4, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        gSPScisTextureRectangle(gdl++, (slot->unk8 + xoff) << 2, (slot->unkC + row) << 2,
                                                (slot->unk8 + xoff + width) << 2, (slot->unkC + row + 5) << 2,
                                                G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                    }
                    break;
            }
        }
    }
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3AA0/func_801E5554.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3AA0/func_801E6074.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3AA0/func_801E62A8.s")

extern s32 D_802C6BD0;

void func_80049A94(Mtx*, MtxF*, f32, f32, f32, f32, f32, f32);

void func_801E66F4(UnkStruct_menu_buffer_1* arg0) {
    MtxF mf;
    MtxF unused[2]; // never touched; keeps the 0x100 frame
    f32 angle;

    switch (arg0->unk2) {
        case 0:
            arg0->unkC = D_802C6BD0 + 6 + D_802C6EE4 * 20;
            angle = 2.0f * (arg0->unk18 / 40.0f) * 3.1415927f;
            // The last argument is the double 0.0: with 0.0f IDO shares one zero register for both.
            func_80049A94((Mtx*) ((u8*) D_801CE5F8 + ((u16) arg0->unk4 << 6) + 0x900), &mf, angle, angle, 0.0f,
                          arg0->unk8, arg0->unkC, 0.0);
            arg0->unk18++;
            if (arg0->unk18 >= 40) {
                arg0->unk18 -= 40;
            }
            arg0->unk20 += 4;
            break;
        case 1:
            if (gCurrentPauseMenuOption == -1) {
                arg0->unk_0 = 0;
                break;
            }
            arg0->unkC = arg0->unk24 + gCurrentPauseMenuOption * 15;
            angle = 2.0f * (arg0->unk18 / 40.0f) * 3.1415927f;
            func_80049A94((Mtx*) ((u8*) D_801CE5F8 + ((u16) arg0->unk4 << 6) + 0x900), &mf, angle, angle, 0.0f,
                          arg0->unk8, arg0->unkC, 0.0);
            arg0->unk18++;
            if (arg0->unk18 >= 40) {
                arg0->unk18 -= 40;
            }
            arg0->unk20 += 4;
            break;
    }
}

void func_801E68EC(UnkStruct_menu_buffer_1* arg0) {
    switch (arg0->unk2) { /* irregular */
        case 0:
            arg0->unkC = (s32) ((arg0->unk18++) * 3.0f * arg0->unk18) - 0x28;
            if (arg0->unkC >= 0x3F) {
                arg0->unk2 = 1U;
                arg0->unkC = 0x3F;
                arg0->unk18 = 1;
                arg0->unk1C = 1;
                arg0->unk14 = 16.0f;
                func_800C30BC();
                return;
            }
        case 2:
            return;
        case 1:
            // FAKE
            arg0->unkC = (0x3F - (s32) ((arg0->unk18++) * (0, arg0->unk14))) + (s32) (1.5f * arg0->unk18 * arg0->unk18);
            if (arg0->unkC >= 0x40) {
                arg0->unkC = 0x3F;
                arg0->unk14 = (f32) (arg0->unk14 * 0.7f);
                arg0->unk18 = 1;
                arg0->unk1C = (s32) (arg0->unk1C + 1);
                if (arg0->unk14 < 1.5f) {
                    arg0->unk2 = 2U;
                    arg0->unk1C = 0;
                    arg0->unk18 = 0;
                }
            }
            break;
    }
}
void func_801E6A4C(u16 arg0, u16 arg1) {
    s32 i;
    s32 idx;
    s32 t3;
    UnkStruct_menu_buffer_1* temp_a0;

    switch (arg0) {
        case 0:
            if (arg1 == 0) {
                for (i = 0; i < 5; i++) {
                    menu_buffer_1[i] = D_80226C50;
                }
                return;
            }
        default:
            return;
        case 1:
            idx = func_801E6F6C();
            if (idx != -1) {
                temp_a0 = &menu_buffer_1[idx];
                *temp_a0 = D_80226C50;
                temp_a0->unk4 = idx;
                temp_a0->unk_0 = 1;
                temp_a0->unk2 = 0;
                temp_a0->unk8 = 0x50;
                temp_a0->unkC = 0x5D;
                temp_a0->unk18 = 0;
                return;
            }
            break;
        case 2:
            idx = func_801E6F6C();
            if (idx != -1) {
                temp_a0 = &menu_buffer_1[idx];
                *temp_a0 = D_80226C50;
                temp_a0->unk4 = idx;
                temp_a0->unk_0 = 2;
                temp_a0->unk2 = 0;
                if (arg1) {
                    temp_a0->unk8 = 0x3A;
                } else {
                    temp_a0->unk8 = 0x78;
                }
                temp_a0->unkC = 0x5D;
                temp_a0->unk28 = arg1;
            }
            break;
        case 3:
            idx = func_801E6F6C();
            if (idx != -1) {
                temp_a0 = &menu_buffer_1[idx];
                *temp_a0 = D_80226C50;
                temp_a0->unk4 = idx;
                temp_a0->unk_0 = 3;
                switch (arg1) { /* switch 2 */
                    case 0:
                        temp_a0->unk2 = 0;
                        temp_a0->unk8 = 0x52;
                        temp_a0->unkC = 0x54;
                        break;
                    case 1:
                        temp_a0->unk2 = 0;
                        temp_a0->unk8 = 0xEF;
                        temp_a0->unkC = 0x54;
                        break;
                    case 2:
                    case 4:
                    case 6:
                        temp_a0->unk2 = 1;
                        temp_a0->unk8 = 0x50;
                        if (arg1 == 2) {
                            temp_a0->unkC = 0x65;
                        } else if (arg1 == 4) {
                            temp_a0->unkC = 0x4C;
                        } else {
                            temp_a0->unkC = 0xBA;
                        }
                        temp_a0->unk24 = (s32) temp_a0->unkC;
                        break;
                    case 3:
                    case 5:
                    case 7:
                        temp_a0->unk2 = 1;
                        temp_a0->unk8 = 0xF0;
                        if (arg1 == 3) {
                            temp_a0->unkC = 0x65;
                        } else if (arg1 == 5) {
                            temp_a0->unkC = 0x4C;
                        } else {
                            temp_a0->unkC = 0xBA;
                        }
                        temp_a0->unk24 = (s32) temp_a0->unkC;
                        break;
                }
                temp_a0->unk20 = 0xFF;
                return;
            }
            break;
        case 4:
            idx = func_801E6F6C();
            if (idx != -1) {
                temp_a0 = &menu_buffer_1[idx];
                *temp_a0 = D_80226C50;
                ;
                temp_a0->unk4 = idx;
                temp_a0->unk_0 = 4;
                temp_a0->unk2 = 0;
                temp_a0->unk8 = 0x50;
                temp_a0->unkC = -0x28;
                temp_a0->unk28 = arg1;
            }
            break;
    }
}

s32 func_801E6F6C(void) {
    s32 var_v0;
    UnkStruct_menu_buffer_1* var_v1 = menu_buffer_1;

    for (var_v0 = 0; var_v0 != 5; var_v0++) {
        if (var_v1[var_v0].unk_0 == 0) {
            break;
        }
    }

    return var_v0 == 5 ? -1 : var_v0;
}
