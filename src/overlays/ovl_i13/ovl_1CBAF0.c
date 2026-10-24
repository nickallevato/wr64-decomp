#include "global.h"

extern s32 D_i13_802C8DD4;

extern s32 D_i13_802C8DC4;
extern s32 D_i13_802C8DC8;
extern s32 D_i13_802C8DCC;
extern s32 D_i13_802C8DD0;

extern s32 D_i13_802C8D5C;
extern s32 D_i13_802C8D98;

extern s32 D_i13_802C8D58;
extern s32 D_i13_802C8D70;
extern s32 D_i13_802C8D74;

extern s32 D_i13_802C8D54;

extern s32 D_i13_802C8D50;

extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_802C8E90;
extern s32 D_802C8E94;
extern s32 D_802C8E9C;

void func_i13_802C82A4(s32 arg0);

s32 Save_PfsCheckFree(void);
s32 Save_PfsFindFile(void);

void func_i13_802C8CBC(void);

void func_800C3E6C(s32);

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5800.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5F6C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6068.s")

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
            func_i13_802C8CBC();
        }
        var_v1 = 1;
    } else if (D_801CE65A[0].unk0 & B_BUTTON) {
        var_v1 = 2;
        func_i13_802C8CBC();
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
                func_i13_802C82A4(2);
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6700.s")

s32 func_i13_802C69CC(void) {
    s32 var_v1 = 0;

    if (D_801CE65A[0].unk0 & (A_BUTTON | Z_TRIG | START_BUTTON)) {
        var_v1 = 1;
        if (D_i13_802C8D70 == 0) {
            var_v1 = 5;
            D_801CE640 = 9;
            func_i13_802C82A4(4);
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
            func_i13_802C82A4(3);
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
            func_i13_802C82A4(3);
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6CE4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6E48.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6F0C.s")

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

void func_i13_802C81AC(s32 arg0) {
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

void func_i13_802C82A4(s32 arg0) {
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C832C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C8484.s")

void func_i13_802C8CBC(void) {
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
