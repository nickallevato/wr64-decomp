#include "common.h"

extern struct_801C1F84* D_801C1F80;
extern struct_801C1F84* D_801C1F84;
extern struct_801C1F84* D_801C1F88;
extern UnkStruct_801AEE20 D_801B2F20;
extern UnkStruct_801AEE20 D_801B7020;
extern s32 D_801BB120;
extern s32 D_801BB124;
extern s32 D_801BB128;
extern s32 D_801CE638;

extern f32 D_801C1CE8;
extern f32 D_801C1CEC;
extern f32 D_801C1CF8;
extern f32 D_801C1CFC;
extern u8 D_801C1D00[];
extern s32 D_801C1F00[4][4];
extern s32 D_801C1F40[4][4];

static const char devstr1[] = "Error: number of buoy2\n";
static const char devstr2[] = "Error: number of buoy3\n";

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_80071E70.s")

extern s32 D_801BB12C;
f32 func_801ED090(f32 arg0);

#ifdef NON_MATCHING
// 5535: same loops and calls. The original walks the last loop with two pointers (one for the
// record, one for its link fields), saves s8 and has a 0xB0 frame (here 0x90), and numbers the
// saved registers differently from the first loop on.
void func_800735EC(UnkStruct_801AEE20* arg0, s32 arg1) {
    s32 i;
    s32 k;
    s32 n;
    s32 path;
    s32 type;
    f32 dx;
    f32 dz;
    f32 px;
    f32 pz;
    f32 width;
    f32 half;
    f32 ax;
    f32 az;
    f32 len;
    f32 angle;
    f32 ox;
    f32 oz;
    f32 x;
    f32 z;

    for (i = 0; i < arg1; i++) {
        arg0[i].unk4 = 0.0f;
        arg0[i].unk0 = arg0[i].unk24;
        arg0[i].unk8 = arg0[i].unk28;
        arg0[arg0[i].unkB4].unkB8 = i;
    }
    for (i = 0; i < arg1; i++) {
        arg0[i].unkA0 = arg0[i].unkAC = arg0[i].unkB4;
        arg0[i].unkA8 = arg0[i].unkB0 = arg0[i].unkB8;
        for (path = 0; path < 4; path++) {
            arg0[i].unkCC[path] = arg0[i].unkB4;
            arg0[i].unkF4[path] = arg0[i].unkB8;
        }
    }
    for (i = 0; i < arg1; i++) {
        if (arg0[i].unkC0 < 2) {
            for (k = arg0[i].unkB4, n = arg1 - 1; (arg0[k].unkC0 >= 2) && (n > 0); n--) {
                k = arg0[k].unkB4;
            }
            arg0[i].unkA0 = k;
            arg0[k].unkA8 = i;
        }
    }
    for (i = 0; i < arg1; i++) {
        if (arg0[i].unkC0 != 1) {
            for (k = arg0[i].unkB4, n = arg1 - 1; (arg0[k].unkC0 == 1) && (n > 0); n--) {
                k = arg0[k].unkB4;
            }
            arg0[i].unkAC = k;
            arg0[k].unkB0 = i;
        }
    }
    for (path = 0; path < 4; path++) {
        for (i = 0; i < arg1; i++) {
            if ((arg0[i].unkC0 == 0) || (arg0[i].unkC0 == 2) || (arg0[i].unkC0 == path + 3)) {
                for (k = arg0[i].unkB4, n = arg1 - 1;
                     (arg0[k].unkC0 != 0) && (arg0[k].unkC0 != 2) && (arg0[k].unkC0 != path + 3) && (n > 0); n--) {
                    k = arg0[k].unkB4;
                }
                arg0[i].unkCC[path] = k;
                arg0[k].unkF4[path] = i;
            }
        }
    }
    for (i = 0; i < arg1; i++) {
        if ((arg0[i].unk98 != 2) && (arg0[i].unk98 != 3) && (arg0[i].unk98 != 5)) {
            arg0[i].unk9C = 0;
        } else {
            arg0[i].unk9C = 1;
        }
        if ((arg0[i].unkC0 >= 2) || (arg0[i].unkBC != 0)) {
            arg0[i].unkC4 = 0;
        } else if ((arg0[i].unk98 != 0) && (arg0[i].unk98 != 1) && (arg0[i].unk98 != 2) && (arg0[i].unk98 != 3)) {
            arg0[i].unkC4 = 0;
        } else {
            arg0[i].unkC4 = 1;
        }
        if ((arg0[i].unkC0 >= 2) || (arg0[i].unkBC != 0)) {
            arg0[i].unkC8 = 0;
        } else if ((arg0[i].unk98 != 0) && (arg0[i].unk98 != 1) && (arg0[i].unk98 != 2) && (arg0[i].unk98 != 3)) {
            arg0[i].unkC8 = 0;
        } else {
            arg0[i].unkC8 = 1;
        }
        type = arg0[i].unk98;
        arg0[i].unk3C = arg0[i].unk40 = arg0[i].unk44 = 0.0f;
        arg0[i].unk48 = arg0[i].unk4C = arg0[i].unk50 = 0.0f;
        arg0[i].unk54 = arg0[i].unk58 = arg0[i].unk5C = 0.0f;
        dx = arg0[i].unk74;
        dz = -arg0[i].unk70;
        switch (type) {
            case 0:
                px = -dx;
                pz = -dz;
                break;
            case 1:
                px = dx;
                pz = dz;
                break;
            default:
                pz = 0.0f;
                px = 0.0f;
                break;
        }
        arg0[i].unk78 = dx;
        arg0[i].unk7C = dz;
        arg0[i].unk80 = px;
        arg0[i].unk84 = pz;
        switch (type) {
            case 2:
                width = 1600.0f;
                break;
            case 3:
                if ((gCourseID == DOLPHIN_PARK) && (gGameModes != GMODE_STUNT)) {
                    width = 740.0f;
                } else {
                    width = 1000.0f;
                }
                break;
            case 8:
            case 9:
                width = 800.0f;
                break;
            default:
                width = 0.0f;
                break;
        }
        half = width * 0.5f;
        arg0[i].unk8C = half;
        ax = arg0[arg0[i].unkA0].unk0 - arg0[i].unk0;
        az = arg0[arg0[i].unkA0].unk8 - arg0[i].unk8;
        arg0[i].unk88 = sqrtf((ax * ax) + (az * az));
        ax = arg0[arg0[i].unkAC].unk0 - arg0[i].unk0;
        az = arg0[arg0[i].unkAC].unk8 - arg0[i].unk8;
        arg0[i].unk90 = sqrtf((ax * ax) + (az * az));
        if (arg0[i].unk90 > 0.0f) {
            ax /= arg0[i].unk90;
            az /= arg0[i].unk90;
        }
        angle = 2.0f * func_801ED090((ax * dx) + (az * dz));
        if (arg0[i].unk98 == 0) {
            angle = 360.0f - angle;
        }
        arg0[i].unk94 = angle;
        ax = arg0[i].unk0 - arg0[arg0[i].unkB0].unk0;
        az = arg0[i].unk8 - arg0[arg0[i].unkB0].unk8;
        len = sqrtf((ax * ax) + (az * az));
        if (len > 0.0f) {
            ax /= len;
            az /= len;
        }
        arg0[i].unkE4 = ax;
        arg0[i].unkE8 = az;
        switch (arg0[i].unk98) {
            case 0:
                arg0[i].unkF0 = arg0[i].unkE4;
                arg0[i].unkEC = -arg0[i].unkE8;
                break;
            case 1:
                arg0[i].unkEC = arg0[i].unkE8;
                arg0[i].unkF0 = -arg0[i].unkE4;
                break;
            default:
                arg0[i].unkF0 = 0.0f;
                arg0[i].unkEC = 0.0f;
                break;
        }
        ox = -142.0f * px;
        oz = -142.0f * pz;
        if (arg0[i].unk98 == 4) {
            ox = 1.0f;
            oz = 1.0f;
        }
        x = arg0[i].unk0;
        z = arg0[i].unk8;
        arg0[i].unkC = arg0[i].unk2C = x + (dx * half);
        arg0[i].unk10 = 0.0f;
        arg0[i].unk1C = 0.0f;
        arg0[i].unk14 = arg0[i].unk30 = z + (dz * half);
        arg0[i].unk60 = x + ox;
        arg0[i].unk68 = z + oz;
        arg0[i].unk18 = arg0[i].unk34 = x - (dx * half);
        arg0[i].unk64 = 46.0f;
        arg0[i].unk20 = arg0[i].unk38 = z - (dz * half);
        if ((i == D_801BB12C) && (gCourseID == GLACIER_COAST)) {
            arg0[i].unk10 = -110.0f;
            arg0[i].unk1C = -160.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_800735EC.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_80073E6C.s")

s32 func_800741A4(f32 arg0, f32 arg1, u8** arg2) {
    s32 row = (arg0 - D_801C1CE8) / D_801C1CF8 * 4.0f;
    s32 col = (arg1 - D_801C1CEC) / D_801C1CFC * 4.0f;

    if (row < 0 || row >= 4 || col < 0 || col >= 4) {
        return 0;
    }
    *arg2 = D_801C1D00 + D_801C1F00[row][col];
    return D_801C1F40[row][col];
}

s32 func_80074264(f32 arg0, f32 arg1) {
    s32 i;
    s32 ret;

    ret = true;
    if (gCourseID == DOLPHIN_PARK) {
        if (sqrtf(SQ(arg0) + SQ(arg1)) <= 7700.0f) {
            ret = false;
        }
    } else {
        for (i = 0; D_801C1F80[i].unk0 != D_801C1F80[i].unk4; i++) {
            if ((D_801C1F80[i].unk0 <= arg0) && (D_801C1F80[i].unk4 >= arg0) && (D_801C1F80[i].unk8 <= arg1) &&
                (D_801C1F80[i].unkC >= arg1)) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

void func_80074368(f32 arg0, f32 arg1, s32* firstMatchIndex, s32* lastMatchIndex) {
    s32 firstMatchFound;
    s32 i;

    *lastMatchIndex = -1; // Default to -1, which means no match found
    *firstMatchIndex = -1;
    firstMatchFound = false;
    for (i = 0; (D_801C1F84[i].unk0 != D_801C1F84[i].unk4); i++) {
        if ((D_801C1F84[i].unk0 <= arg0) && (D_801C1F84[i].unk4 >= arg0) && (D_801C1F84[i].unk8 <= arg1) &&
            (D_801C1F84[i].unkC >= arg1)) {
            if (firstMatchFound == false) {
                *firstMatchIndex = i;
                firstMatchFound = true;
            } else {
                *lastMatchIndex = i;
            }
        }
    }
}

s32 func_80074448(f32 arg0, f32 arg1) {
    s32 matchFound;
    s32 i;

    matchFound = false;
    for (i = 0; D_801C1F88[i].unk0 != D_801C1F88[i].unk4; i++) {
        if ((D_801C1F88[i].unk0 <= arg0) && (D_801C1F88[i].unk4 >= arg0) && (D_801C1F88[i].unk8 <= arg1) &&
            (D_801C1F88[i].unkC >= arg1)) {
            matchFound = true;
            break;
        }
    }
    return matchFound;
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_800744EC.s")

void func_80075274(void) {
    func_80071E70();
    if (D_801CE638 != 21) {
        func_800735EC(D_801AEE20, D_801BB120);
        if (D_801BB124 != 0) {
            func_800735EC(&D_801B2F20, D_801BB124);
        }
        if (D_801BB128 != 0) {
            func_800735EC(&D_801B7020, D_801BB128);
        }
        func_80073E6C();
        func_800744EC();
        func_80075310();
        func_801FAEA8();
    }
}
