#include "global.h"

extern s32 D_800D45DC[]; // array pointing to some mio0 adresses

void func_1B1FB0_802C5DF4(void);
Gfx* func_1B1FB0_802C62E4(Gfx*);
Gfx* func_1B1FB0_802C67BC(Gfx*, s32, s32);
Gfx* func_1B1FB0_802C6970(Gfx*);
Gfx* func_1B1FB0_802C6C1C(Gfx*);
Gfx* func_1B1FB0_802C6E40(Gfx*, s32, s32);
Gfx* func_1B1FB0_802C6FF8(Gfx*);
Gfx* func_1B1FB0_802C71B8(Gfx*, char, s32, s32);
s32 func_1B1FB0_802C7304(s32, s8*, s32, s32, s32);
Gfx* func_1B1FB0_802C73B0(Gfx*);
void func_1B1FB0_802C7510(void);
void* func_1B1FB0_802C7578(Gfx*, s32, s32, s32, s32, s32);
extern s32 D_802C7718;
extern u8 D_8000008[];
extern u8 D_804A460[];
extern u8 D_8008510[];
extern u8 D_800A618[];
extern s32 D_1B1FB0_802C76B0;
extern s32 D_1B1FB0_802C76BC;
extern s32 D_1B1FB0_802C76C0;
extern s32 D_1B1FB0_802C76C4[];
extern s32 D_1B1FB0_802C76E8;
extern s32 D_1B1FB0_802C76EC;
extern s32 D_1B1FB0_802C7660;
extern u8* D_1B1FB0_802C7664[];
extern u8* D_1B1FB0_802C767C[];
extern s32 D_1B1FB0_802C76A4;
extern s32 D_1B1FB0_802C76A8;
extern s32 D_1B1FB0_802C76AC;
extern s32 D_1B1FB0_802C76B4[];
extern u32 D_1B1FB0_802C76F0;
extern s32 D_1B1FB0_802C76F4;
extern s32 D_802C7710;
extern s32 D_802C771C;
extern s32 D_802C7720;
extern s32 D_802C7724;
extern Gfx D_8066180[];
extern Gfx D_80661F8[];
extern Gfx D_8066A80[];
extern Gfx D_80671B8[];
extern Gfx D_80675B8[];
extern Gfx D_80675E8[];

void func_1B1FB0_802C5800(void) {
    s32 i;

    if (D_1B1FB0_802C76BC == 0) {
        D_802C7710 = (u32) ((12 - D_1B1FB0_802C76C0) * 127.0f / 12.0f + 128.0f);
    } else {
        D_802C7710 = (u32) ((f32) D_1B1FB0_802C76C0 * 127.0 / 12.0 + 128.0);
    }
    D_1B1FB0_802C76C0++;
    if (D_1B1FB0_802C76C0 >= 12) {
        D_1B1FB0_802C76C0 = 0;
        D_1B1FB0_802C76BC ^= 1;
    }
    if (D_1B1FB0_802C76E8 == 1) {
        D_1B1FB0_802C76EC -= 4;
        if (D_1B1FB0_802C76EC < 191) {
            D_1B1FB0_802C76EC = 210;
            D_1B1FB0_802C76E8 = 0;
            for (i = 0; i < 8; i++) {
                if (i < 7) {
                    D_1B1FB0_802C76C4[i] = D_1B1FB0_802C76C4[i + 1];
                } else if (D_1B1FB0_802C76C4[i - 1] == 16 || D_1B1FB0_802C76C4[i - 1] == 0) {
                    D_1B1FB0_802C76C4[i] = 0;
                } else {
                    D_1B1FB0_802C76C4[i] = D_1B1FB0_802C76C4[i - 1] + 1;
                }
            }
            D_1B1FB0_802C76C4[0] = D_1B1FB0_802C76C4[8] = 0;
        }
    } else if (D_1B1FB0_802C76E8 == 2) {
        D_1B1FB0_802C76EC += 4;
        if (D_1B1FB0_802C76EC >= 230) {
            D_1B1FB0_802C76EC = 210;
            D_1B1FB0_802C76E8 = 0;
            for (i = 8; i > 0; i--) {
                if (i >= 2) {
                    D_1B1FB0_802C76C4[i] = D_1B1FB0_802C76C4[i - 1];
                } else if (D_1B1FB0_802C76C4[i + 1] == 1 || D_1B1FB0_802C76C4[i + 1] == 0) {
                    D_1B1FB0_802C76C4[i] = 0;
                } else {
                    D_1B1FB0_802C76C4[i] = D_1B1FB0_802C76C4[i + 1] - 1;
                }
            }
            D_1B1FB0_802C76C4[0] = D_1B1FB0_802C76C4[8] = 0;
        }
    }
}

Gfx* func_1B1FB0_802C5BA4(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_BOOT_UP) {
            return func_1B1FB0_802C73B0(gdl);
        }
    }
    D_800DAB2C = 0;
    gSPDisplayList(gdl++, D_8066180);
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);
    gSPDisplayList(gdl++, D_80661F8);
    gdl = func_1B1FB0_802C62E4(gdl);
    gSPDisplayList(gdl++, D_8066A80);
    gSPDisplayList(gdl++, D_80671B8);
    gdl = func_1B1FB0_802C6970(gdl);
    gdl = func_1B1FB0_802C6C1C(gdl);
    gDPSetPrimColor(gdl++, 0, 0, 255, D_802C7710, 0, 255);
    gdl = func_1B1FB0_802C6E40(gdl, D_1B1FB0_802C76B4[D_1B1FB0_802C76A8], 134);
    if (D_1B1FB0_802C76A4 == 2) {
        gdl = func_1B1FB0_802C6E40(gdl, D_1B1FB0_802C76B4[D_1B1FB0_802C76AC], 394);
    }
    if (gGameState == GAME_STATE_6) {
        gdl = func_1B1FB0_802C7578(gdl, 64, 50, 576, 432, D_1B1FB0_802C76F0);
    }
    if (gGameState == GAME_STATE_BOOT_UP) {
        func_1B1FB0_802C5DF4();
    } else {
        D_1B1FB0_802C76F0 = D_1B1FB0_802C76F4 * 255 / 10;
        if (D_1B1FB0_802C76F0 > 255) {
            D_1B1FB0_802C76F0 = 255;
        }
        D_1B1FB0_802C76F4++;
        if (D_1B1FB0_802C76F0 == 255) {
            osViBlack(true);
        }
        if (D_1B1FB0_802C76F4 >= 14) {
            GameState_EnterTitleScreen();
        }
    }
    return gdl;
}

void func_1B1FB0_802C5DF4(void) {
    s32 pad; // stack pad: puts note at 0x20(sp), as in the original
    OSPfsState* note;

    if (D_1B1FB0_802C76A4 == 4) {
        if (D_802C7724 == 0) {
            D_802C7724 = 1;
        } else {
            D_802C771C = 0;
            note = (OSPfsState*) D_801CB418 + D_802C7720;
            D_802C771C = osPfsDeleteFile((OSPfs*) D_801CB658, note->company_code, note->game_code,
                                         (u8*) note->game_name, (u8*) note->ext_name);
            switch (D_802C771C) {
                case 0:
                    D_801CB618[D_802C7720] = -1;
                    D_801CB410 += (u8) ((note->file_size + 255) >> 8);
                    D_1B1FB0_802C76A4 = 0;
                    D_1B1FB0_802C7660 = 0;
                    break;
                case 1:
                    D_1B1FB0_802C76A4 = 3;
                    D_1B1FB0_802C7660 = 3;
                    break;
                case 2:
                    D_1B1FB0_802C76A4 = 3;
                    D_1B1FB0_802C7660 = 4;
                    break;
                default:
                    D_1B1FB0_802C76A4 = 3;
                    D_1B1FB0_802C7660 = 2;
                    break;
            }
        }
    }
    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        switch (D_1B1FB0_802C76A4) {
            case 0:
                if (D_1B1FB0_802C76A8 == 0) {
                    D_1B1FB0_802C76A4 = 1;
                    D_1B1FB0_802C76B0 = 0;
                } else {
                    func_1B1FB0_802C7510();
                }
                break;
            case 1:
                D_802C7720 = D_1B1FB0_802C76C4[D_1B1FB0_802C76B0 + 2] - 1;
                if (D_801CB618[D_802C7720] == 0) {
                    D_1B1FB0_802C76A4 = 2;
                    D_1B1FB0_802C76AC = 1;
                    D_1B1FB0_802C7660 = 1;
                }
                break;
            case 2:
                D_1B1FB0_802C76A4 = 1;
                D_1B1FB0_802C7660 = 0;
                if (D_1B1FB0_802C76AC == 0) {
                    D_1B1FB0_802C76A4 = 4;
                    D_1B1FB0_802C7660 = 5;
                    D_802C7724 = 0;
                }
                break;
            case 3:
                D_1B1FB0_802C76A4 = 0;
                D_1B1FB0_802C7660 = 0;
                break;
        }
        AudioGeneral_PlaySound(0x11, 0);
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        switch (D_1B1FB0_802C76A4) {
            case 1:
                if (D_1B1FB0_802C76E8 == 0) {
                    D_1B1FB0_802C76A4 = 0;
                    D_1B1FB0_802C7660 = 0;
                }
                break;
            case 2:
                D_1B1FB0_802C76A4 = 1;
                D_1B1FB0_802C7660 = 0;
                break;
        }
        AudioGeneral_PlaySound(0x16, 0);
    } else if (D_801CE65A[0].unk0 & L_JPAD) {
        switch (D_1B1FB0_802C76A4) {
            case 0:
                D_1B1FB0_802C76A8++;
                if (D_1B1FB0_802C76A8 == 2) {
                    D_1B1FB0_802C76A8 = 0;
                }
                AudioGeneral_PlaySound(0x10, 0);
                break;
            case 2:
                D_1B1FB0_802C76AC ^= 1;
                AudioGeneral_PlaySound(0x10, 0);
                break;
        }
    } else if (D_801CE65A[0].unk0 & R_JPAD) {
        switch (D_1B1FB0_802C76A4) {
            case 0:
                D_1B1FB0_802C76A8--;
                if (D_1B1FB0_802C76A8 < 0) {
                    D_1B1FB0_802C76A8 = 1;
                }
                AudioGeneral_PlaySound(0x10, 0);
                break;
            case 2:
                D_1B1FB0_802C76AC ^= 1;
                AudioGeneral_PlaySound(0x10, 0);
                break;
        }
    } else if (D_801CE65A[0].unk0 & U_JPAD) {
        if (D_1B1FB0_802C76A4 == 1 && D_1B1FB0_802C76E8 == 0) {
            D_1B1FB0_802C76B0--;
            AudioGeneral_PlaySound(0x10, 0);
            if (D_1B1FB0_802C76B0 < 0) {
                D_1B1FB0_802C76B0 = 0;
                if (D_1B1FB0_802C76C4[D_1B1FB0_802C76B0 + 2] != 1) {
                    D_1B1FB0_802C76E8 = 2;
                    AudioGeneral_PlaySound(0x1D, 0);
                }
            }
        }
    } else if (D_801CE65A[0].unk0 & D_JPAD) {
        if (D_1B1FB0_802C76A4 == 1 && D_1B1FB0_802C76E8 == 0) {
            D_1B1FB0_802C76B0++;
            AudioGeneral_PlaySound(0x10, 0);
            if (D_1B1FB0_802C76B0 > 4) {
                D_1B1FB0_802C76B0 = 4;
                if (D_1B1FB0_802C76C4[D_1B1FB0_802C76B0 + 2] != 16) {
                    D_1B1FB0_802C76E8 = 1;
                    AudioGeneral_PlaySound(0x1D, 0);
                }
            }
        }
    }
}

Gfx* func_1B1FB0_802C62E4(Gfx* gdl) {
    s32 i;
    OSPfsState* note;
    s32 d;
    s32 pages;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 389);
    for (i = 0; i < 9; i++) {
        if (D_1B1FB0_802C76E8 != 0 || (i != 0 && i != 8)) {
            gdl = func_1B1FB0_802C67BC(gdl, 64, i * 20 + D_1B1FB0_802C76EC);
        }
    }
    gSPDisplayList(gdl++, D_80675E8);
    gDPSetPrimColor(gdl++, 0, 0, 255, D_802C7710, 0, 255);
    if (D_1B1FB0_802C76A4 != 0) {
        gdl = func_1B1FB0_802C6FF8(gdl);
    }
    gDPPipeSync(gdl++);
    gDPSetPrimColor(gdl++, 0, 0, 0, 0, 50, 255);
    for (i = 0; i < 9; i++) {
        if (D_1B1FB0_802C76C4[i] != 0) {
            if (D_1B1FB0_802C76C4[i] < 10) {
                gdl = func_1B1FB0_802C71B8(gdl, (char) D_1B1FB0_802C76C4[i] + 16, 101, i * 20 + D_1B1FB0_802C76EC + 2);
            } else {
                d = D_1B1FB0_802C76C4[i] % 10;
                gdl = func_1B1FB0_802C71B8(gdl, (char) d + 16, 106, i * 20 + D_1B1FB0_802C76EC + 2);
                gdl = func_1B1FB0_802C71B8(gdl, 17, 96, i * 20 + D_1B1FB0_802C76EC + 2);
            }
            if (D_801CB618[D_1B1FB0_802C76C4[i] - 1] == 0) {
                note = (OSPfsState*) D_801CB418 + D_1B1FB0_802C76C4[i] - 1;
                gdl = (Gfx*) func_1B1FB0_802C7304((s32) gdl, (s8*) note->game_name, 16, 159,
                                                  i * 20 + D_1B1FB0_802C76EC + 2);
                if ((s8) note->ext_name[0] != 0) { // tested with lb, passed with lbu
                    gdl = func_1B1FB0_802C71B8(gdl, 60, D_802C7718 * 16 + 159, i * 20 + D_1B1FB0_802C76EC + 2);
                    gdl = func_1B1FB0_802C71B8(gdl, note->ext_name[0], D_802C7718 * 16 + 175,
                                               i * 20 + D_1B1FB0_802C76EC + 2);
                }
                pages = (note->file_size + 255) >> 8;
                gdl = func_1B1FB0_802C71B8(gdl, (char) (pages % 10) + 16, 538, i * 20 + D_1B1FB0_802C76EC + 2);
                if (pages >= 10) {
                    d = pages / 10;
                    gdl = func_1B1FB0_802C71B8(gdl, (char) (d % 10) + 16, 522, i * 20 + D_1B1FB0_802C76EC + 2);
                }
                if (pages >= 100) {
                    d /= 10;
                    gdl = func_1B1FB0_802C71B8(gdl, (char) (d % 10) + 16, 506, i * 20 + D_1B1FB0_802C76EC + 2);
                }
            }
        }
    }
    gSPDisplayList(gdl++, D_80675B8);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);
    return gdl;
}

Gfx* func_1B1FB0_802C67BC(Gfx* gdl, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < 5; i++) {
        gDPLoadTextureBlock(gdl++, &D_804A460[i * 0x1000], G_IM_FMT_RGBA, G_IM_SIZ_16b, 512, 4, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, x << 2, (y + i * 4) << 2, (x + 511) << 2, (y + i * 4 + 3) << 2, G_TX_RENDERTILE,
                            0, 0, 4 << 10, 1 << 10);
    }
    return gdl;
}

Gfx* func_1B1FB0_802C6970(Gfx* gdl) {
    u8* tex;
    s32 i;

    for (i = 0, tex = D_1B1FB0_802C7664[D_1B1FB0_802C7660]; i < 8; i++) {
        gDPLoadTextureTile(gdl++, tex, G_IM_FMT_IA, G_IM_SIZ_8b, 360, 8, 0, 0, 359, 7, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, 140 << 2, (59 + i * 8) << 2, 500 << 2, (67 + i * 8) << 2, G_TX_RENDERTILE, 0, 0,
                            1 << 10, 1 << 10);
        tex += 0xB40;
    }
    return gdl;
}

Gfx* func_1B1FB0_802C6C1C(Gfx* gdl) {
    s32 n;
    s32 digits;
    s32 i;
    s32 d;
    s32 x;

    n = D_801CB410;
    if (n < 10) {
        digits = 1;
    } else if (n < 100) {
        digits = 2;
    } else {
        digits = 3;
    }
    for (i = 0; i < digits; i++) {
        d = n % 10;
        n /= 10;
        gDPLoadTextureBlock(gdl++, D_1B1FB0_802C767C[d], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 18, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        x = 560 - i * 18; // right edge; digits are drawn right to left
        gSPTextureRectangle(gdl++, (x - 16) << 2, 368 << 2, x << 2, 386 << 2,
                            G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}

Gfx* func_1B1FB0_802C6E40(Gfx* gdl, s32 x, s32 y) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gdl++, &D_8008510[i * 0x840], G_IM_FMT_IA, G_IM_SIZ_8b, 192, 11, 0, 0, 191, 10, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, x << 2, (y + i * 11) << 2, (x + 192) << 2, (y + i * 11 + 11) << 2,
                            G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}

Gfx* func_1B1FB0_802C6FF8(Gfx* gdl) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gdl++, &D_800A618[i * 0x9B0], G_IM_FMT_IA, G_IM_SIZ_8b, 496, 5, 0, 0, 495, 4, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, 72 << 2, (D_1B1FB0_802C76B0 * 20 + i * 5 + 248) << 2, 568 << 2,
                            (D_1B1FB0_802C76B0 * 20 + i * 5 + 253) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}

Gfx* func_1B1FB0_802C71B8(Gfx* gdl, char c, s32 x, s32 y) {
    s32 mask = G_TX_NOMASK; // FAKE: found by the permuter; with the masks in a local, gdl is not copied

    if (c < 16) {
        return gdl;
    }
    if (c >= 0x42) {
        c = 0x3B;
    }
    c -= 16;
    gDPLoadTextureBlock(gdl++, &D_8000008[c << 8], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, mask, mask, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gdl++, x << 2, y << 2, (x + 16) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                        1 << 10);
    return gdl;
}

s32 func_1B1FB0_802C7304(s32 arg0, s8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s1 = arg3;

    D_802C7718 = 0;

    while (arg2) {
        if (*arg1 != 0) {
            D_802C7718++;
        }
        arg0 = (s32) func_1B1FB0_802C71B8((Gfx*) arg0, *(arg1++), s1, arg4);
        arg2--;
        s1 += 0x10;
    }
    return arg0;
}

Gfx* func_1B1FB0_802C73B0(Gfx* gdl) {
    size_t i;

    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);

    gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE | 0x300000);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gdl++);
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 640, VIRTUAL_TO_PHYSICAL2(D_800D45DC[i]));

        gDPSetFillColor(gdl++, 0x10001);
        gDPFillRectangle(gdl++, 0, 0, 639, 479);
    }

    return gdl;
}

void func_1B1FB0_802C7510(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 6;
    D_801CE638 = 0x13;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 3;
    gVIsPerFrame = 2;
}

void* func_1B1FB0_802C7578(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {

    gSPTexture(arg0++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(arg0++);
    gDPSetCycleType(arg0++, G_CYC_1CYCLE);
    gDPSetPrimColor(arg0++, 0, 0, 0, 0, 0, arg5);
    gDPSetCombineMode(arg0++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(arg0++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(arg0++, G_AC_NONE);
    gDPFillRectangle(arg0++, arg1, arg2, arg3, arg4);

    return arg0;
}
