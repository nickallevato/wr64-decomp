#include "global.h"

extern UnkStruct_menu_buffer_1 D_80226C50;

extern UnkStruct_menu_buffer_1 menu_buffer_1[];

void func_801E5470(void) {
    UnkStruct_menu_buffer_1* var_s0;
    s32 i;

    for (i = 0; i < 5; i++) {
        switch (menu_buffer_1[i].type) {
            case 1:
                menu_buffer_1[i].active = 1;
                func_801E6074(&menu_buffer_1[i]);
                break;
            case 2:
                menu_buffer_1[i].active = 1;
                func_801E62A8(&menu_buffer_1[i]);
                break;
            case 3:
                menu_buffer_1[i].active = 1;
                func_801E66F4(&menu_buffer_1[i]);
                break;
            case 4:
                menu_buffer_1[i].active = 1;
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
        if (slot->active != 0) {
            switch (slot->type) {
                case 1:
                    if (slot->state == 1) {
                        gSPDisplayList(gdl++, D_106F030);
                    } else {
                        gSPDisplayList(gdl++, D_106F0A8);
                        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                        gSPMatrix(gdl++, D_7000000 + ((u16) slot->index << 6) + 0x900,
                                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    }
                    off = 0;
                    row = 0;
                    do {
                        gDPLoadTextureTile(gdl++, D_8042008 + off, G_IM_FMT_RGBA, G_IM_SIZ_32b, 160, 0, 0, 0, 159, 4, 0,
                                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        if (slot->state == 1) {
                            gSPTextureRectangle(gdl++, slot->x << 2, (slot->y + row) << 2,
                                                (slot->x + 160) << 2, (slot->y + row + 5) << 2, G_TX_RENDERTILE,
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
                    if (slot->state == 1) {
                        gSPDisplayList(gdl++, D_106F030);
                    } else {
                        gSPDisplayList(gdl++, D_106F0A8);
                        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                        gSPMatrix(gdl++, D_7000000, G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
                        gSPMatrix(gdl++, D_7000000 + ((u16) slot->index << 6) + 0x900,
                                  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    }
                    if (slot->variant != 0) {
                        row = 0;
                        off = 0;
                        do {
                            gDPLoadTextureTile(gdl++, D_8049008 + off, G_IM_FMT_RGBA, G_IM_SIZ_32b, 204, 0, 0, 0, 203,
                                               4, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            if (slot->state == 1) {
                                gSPTextureRectangle(gdl++, slot->x << 2, (slot->y + row) << 2,
                                                    (slot->x + 204) << 2, (slot->y + row + 5) << 2,
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
                            if (slot->state == 1) {
                                gSPTextureRectangle(gdl++, slot->x << 2, (slot->y + row) << 2,
                                                    (slot->x + 80) << 2, (slot->y + row + 2) << 2,
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
                    gSPMatrix(gdl++, D_7000000 + ((u16) slot->index << 6) + 0x900,
                              G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
                    gSPDisplayList(gdl++, D_106F3A0);
                    gSPDisplayList(gdl++, D_106F408);
                    break;
                case 4:
                    if (slot->variant != 0) {
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
                        gSPScisTextureRectangle(gdl++, (slot->x + xoff) << 2, (slot->y + row) << 2,
                                                (slot->x + xoff + width) << 2, (slot->y + row + 5) << 2,
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

void func_801E66F4(UnkStruct_menu_buffer_1* slot) {
    MtxF mf;
    MtxF unused[2]; // never touched; keeps the 0x100 frame
    f32 angle;

    switch (slot->state) {
        case 0:
            slot->y = D_802C6BD0 + 6 + D_802C6EE4 * 20;
            angle = 2.0f * (slot->frame / 40.0f) * 3.1415927f;
            // The last argument is the double 0.0: with 0.0f IDO shares one zero register for both.
            func_80049A94((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), &mf, angle, angle, 0.0f,
                          slot->x, slot->y, 0.0);
            slot->frame++;
            if (slot->frame >= 40) {
                slot->frame -= 40;
            }
            slot->unk20 += 4;
            break;
        case 1:
            if (gCurrentPauseMenuOption == -1) {
                slot->type = 0;
                break;
            }
            slot->y = slot->menuY + gCurrentPauseMenuOption * 15;
            angle = 2.0f * (slot->frame / 40.0f) * 3.1415927f;
            func_80049A94((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), &mf, angle, angle, 0.0f,
                          slot->x, slot->y, 0.0);
            slot->frame++;
            if (slot->frame >= 40) {
                slot->frame -= 40;
            }
            slot->unk20 += 4;
            break;
    }
}

void func_801E68EC(UnkStruct_menu_buffer_1* slot) {
    switch (slot->state) { /* irregular */
        case 0:
            slot->y = (s32) ((slot->frame++) * 3.0f * slot->frame) - 0x28;
            if (slot->y >= 0x3F) {
                slot->state = 1U;
                slot->y = 0x3F;
                slot->frame = 1;
                slot->unk1C = 1;
                slot->unk14 = 16.0f;
                func_800C30BC();
                return;
            }
        case 2:
            return;
        case 1:
            // FAKE
            slot->y = (0x3F - (s32) ((slot->frame++) * (0, slot->unk14))) + (s32) (1.5f * slot->frame * slot->frame);
            if (slot->y >= 0x40) {
                slot->y = 0x3F;
                slot->unk14 = (f32) (slot->unk14 * 0.7f);
                slot->frame = 1;
                slot->unk1C = (s32) (slot->unk1C + 1);
                if (slot->unk14 < 1.5f) {
                    slot->state = 2U;
                    slot->unk1C = 0;
                    slot->frame = 0;
                }
            }
            break;
    }
}
void func_801E6A4C(u16 kind, u16 param) {
    s32 i;
    s32 idx;
    s32 t3;
    UnkStruct_menu_buffer_1* slot;

    switch (kind) {
        case 0:
            if (param == 0) {
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
                slot = &menu_buffer_1[idx];
                *slot = D_80226C50;
                slot->index = idx;
                slot->type = 1;
                slot->state = 0;
                slot->x = 0x50;
                slot->y = 0x5D;
                slot->frame = 0;
                return;
            }
            break;
        case 2:
            idx = func_801E6F6C();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = D_80226C50;
                slot->index = idx;
                slot->type = 2;
                slot->state = 0;
                if (param) {
                    slot->x = 0x3A;
                } else {
                    slot->x = 0x78;
                }
                slot->y = 0x5D;
                slot->variant = param;
            }
            break;
        case 3:
            idx = func_801E6F6C();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = D_80226C50;
                slot->index = idx;
                slot->type = 3;
                switch (param) { /* switch 2 */
                    case 0:
                        slot->state = 0;
                        slot->x = 0x52;
                        slot->y = 0x54;
                        break;
                    case 1:
                        slot->state = 0;
                        slot->x = 0xEF;
                        slot->y = 0x54;
                        break;
                    case 2:
                    case 4:
                    case 6:
                        slot->state = 1;
                        slot->x = 0x50;
                        if (param == 2) {
                            slot->y = 0x65;
                        } else if (param == 4) {
                            slot->y = 0x4C;
                        } else {
                            slot->y = 0xBA;
                        }
                        slot->menuY = (s32) slot->y;
                        break;
                    case 3:
                    case 5:
                    case 7:
                        slot->state = 1;
                        slot->x = 0xF0;
                        if (param == 3) {
                            slot->y = 0x65;
                        } else if (param == 5) {
                            slot->y = 0x4C;
                        } else {
                            slot->y = 0xBA;
                        }
                        slot->menuY = (s32) slot->y;
                        break;
                }
                slot->unk20 = 0xFF;
                return;
            }
            break;
        case 4:
            idx = func_801E6F6C();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = D_80226C50;
                ;
                slot->index = idx;
                slot->type = 4;
                slot->state = 0;
                slot->x = 0x50;
                slot->y = -0x28;
                slot->variant = param;
            }
            break;
    }
}

s32 func_801E6F6C(void) {
    s32 i;
    UnkStruct_menu_buffer_1* slots = menu_buffer_1;

    for (i = 0; i != 5; i++) {
        if (slots[i].type == 0) {
            break;
        }
    }

    return i == 5 ? -1 : i;
}
