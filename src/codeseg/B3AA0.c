#include "global.h"

extern UnkStruct_menu_buffer_1 gPopupSlotInit;

// This file's .bss, 0x80228930..0x80228A0B (yaml split): five 0x2C popup slots. Nothing names 0x80228A0C;
// the object's 16-byte alignment puts wr64_fade's .bss at 0x80228A10.
UnkStruct_menu_buffer_1 menu_buffer_1[5];

void Popup_UpdateAll(void) {
    UnkStruct_menu_buffer_1* var_s0;
    s32 i;

    for (i = 0; i < 5; i++) {
        switch (menu_buffer_1[i].type) {
            case 1:
                menu_buffer_1[i].active = 1;
                Popup_UpdateCard1(&menu_buffer_1[i]);
                break;
            case 2:
                menu_buffer_1[i].active = 1;
                Popup_UpdateCard2(&menu_buffer_1[i]);
                break;
            case 3:
                menu_buffer_1[i].active = 1;
                Popup_UpdatePauseCursor(&menu_buffer_1[i]);
                break;
            case 4:
                menu_buffer_1[i].active = 1;
                Popup_UpdateCard4(&menu_buffer_1[i]);
                break;
        }
    }
}

extern Gfx D_106F030[];
extern Gfx D_106F0A8[];
extern Gfx D_106F3A0[];
extern Gfx D_106F408[];
extern u8 D_7000000[];
extern u32 D_8042008[];
extern u32 D_8049008[];
extern u32 D_8058008[];
extern u32 D_8071008[];
extern RiderStruct gRiderRaceState[];

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
                            gdl = Printer_DrawQuad(gdl, 160, 6, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                                0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
                        }
                        row += 5;
                        off += 160 * 5;
                    } while (row != 40);
                    break;
                case 2:
                    i = slot->state == 1; // FAKE: i is case 4's loop counter; using it here swaps its register with the offset temp
                    if (i) {
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
                                gdl = Printer_DrawQuad(gdl, 204, h, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                                    0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
                            }
                            off += 204 * 5;
                            row += 5;
                        } while (off != 204 * 30);
                    } else {
                        off = 0;
                        row = 0;
                        do {
                            gDPLoadTextureTile(gdl++, D_8049008 + gRiderRaceState[gPlayer1Rider].racePosition * 3200 + off,
                                               G_IM_FMT_RGBA, G_IM_SIZ_32b, 80, 0, 0, 0, 79, 2, 0,
                                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                                               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            h = (row == 38) ? 1 : 3;
                            if (slot->state == 1) {
                                gSPTextureRectangle(gdl++, slot->x << 2, (slot->y + row) << 2,
                                                    (slot->x + 80) << 2, (slot->y + row + 2) << 2,
                                                    G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                            } else {
                                gdl = Printer_DrawQuad(gdl, 80, h, 0, row, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
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

extern s32 D_801C2650;

void Popup_UpdateCard1(UnkStruct_menu_buffer_1* slot) {
    MtxF mf;
    f32 t;

    switch (slot->state) {
        case 0:
            t = (slot->frame / 5.0f) * 1.5f;
            // An int 1, not 1.0f: IDO then loads its own 1.0f instead of reusing the argument's.
            slot->x = ((1 - t) * 74.0f) + 80.0f;
            slot->y = ((1 - t) * 20.0f) + 93.0f;
            func_80048A88((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), 0.0f, 0.0f, 1.0f, 0.0f,
                          1.0f, 0.0f, slot->x, slot->y, 0.0f, t);
            slot->frame++;
            if (slot->frame >= 6) {
                slot->state = 1;
                slot->x = 80;
                slot->y = 93;
                slot->frame = 0;
            }
            break;
        case 1:
            SysUtils_MatrixLookAt((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), &mf, 0.0f, 0.0f,
                                  1.0f, 0.0f, 1.0f, 0.0f, slot->x, slot->y, 0.0f);
            slot->frame++;
            if (D_801CE608.gameMode == 4) {
                if (slot->frame >= 11) {
                    slot->type = 0;
                    Popup_Spawn(2, 0);
                }
            } else if ((D_801CE608.gameMode == 0) && (slot->frame >= 11)) {
                slot->type = 0;
                if (D_801C2650 == 1) {
                    Popup_Spawn(2, 1);
                }
            }
            break;
    }
}

void Popup_UpdateCard2(UnkStruct_menu_buffer_1* slot) {
    MtxF mf;
    f32 t;

    switch (slot->state) {
        case 0:
            t = (slot->frame / 5.0f) * 1.5f;
            // An int 1, as in Popup_UpdateCard1; the asm converts to unsigned, hence the (u32) casts.
            if (slot->variant != 0) {
                slot->x = (u32) (((1 - t) * 102.0f) + 58.0f);
                slot->y = (u32) (((1 - t) * 15.0f) + 93.0f);
            } else {
                slot->x = (u32) (((1 - t) * 38.0f) + 120.0f);
                slot->y = (u32) (((1 - t) * 20.0f) + 93.0f);
            }
            func_80048A88((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), 0.0f, 0.0f, 1.0f, 0.0f,
                          1.0f, 0.0f, slot->x, slot->y, 0.0f, t);
            slot->frame++;
            if (slot->frame >= 6) {
                slot->state = 1;
                if (slot->variant != 0) {
                    slot->x = 58;
                } else {
                    slot->x = 120;
                }
                slot->y = 93;
                slot->frame = 0;
            }
            break;
        case 1:
            SysUtils_MatrixLookAt((Mtx*) ((u8*) D_801CE5F8 + ((u16) slot->index << 6) + 0x900), &mf, 0.0f, 0.0f,
                                  1.0f, 0.0f, 1.0f, 0.0f, slot->x, slot->y, 0.0f);
            slot->frame++;
            if (slot->frame >= 31) {
                slot->type = 0;
            }
            break;
    }
}

extern s32 D_i0_802C6BD0; // ovl_i0's menu y (78)

void func_80049A94(Mtx*, MtxF*, f32, f32, f32, f32, f32, f32);

void Popup_UpdatePauseCursor(UnkStruct_menu_buffer_1* slot) {
    MtxF mf;
    MtxF unused[2]; // never touched; keeps the 0x100 frame
    f32 angle;

    switch (slot->state) {
        case 0:
            slot->y = D_i0_802C6BD0 + 6 + D_i0_802C6EE4 * 20; // the main menu (ovl_i0) cursor row
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

void Popup_UpdateCard4(UnkStruct_menu_buffer_1* slot) {
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
void Popup_Spawn(u16 kind, u16 param) {
    s32 i;
    s32 idx;
    s32 t3;
    UnkStruct_menu_buffer_1* slot;

    switch (kind) {
        case 0:
            if (param == 0) {
                for (i = 0; i < 5; i++) {
                    menu_buffer_1[i] = gPopupSlotInit;
                }
                return;
            }
        default:
            return;
        case 1:
            idx = Popup_FindFreeSlot();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = gPopupSlotInit;
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
            idx = Popup_FindFreeSlot();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = gPopupSlotInit;
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
            idx = Popup_FindFreeSlot();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = gPopupSlotInit;
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
            idx = Popup_FindFreeSlot();
            if (idx != -1) {
                slot = &menu_buffer_1[idx];
                *slot = gPopupSlotInit;
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

s32 Popup_FindFreeSlot(void) {
    s32 i;
    UnkStruct_menu_buffer_1* slots = menu_buffer_1;

    for (i = 0; i != 5; i++) {
        if (slots[i].type == 0) {
            break;
        }
    }

    return i == 5 ? -1 : i;
}
