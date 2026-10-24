#include "common.h"

extern s32 D_800D48E0;

extern UnkStruct_801AEE20 D_801AEE20[];
extern s32 D_801BB120;
extern RiderStruct D_801C2938[];

static const char devstr1[] = "dolphin condition full at goal\n";
static const char devstr2[] = "dolphin condition full\n";
static const char devstr3[] = "rank value adjust\n";
static const char devstr4[] = "simultaneously goal !!\n";

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80075310.s")

s32 func_80076240(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_80074368(arg0, arg1, &sp24, &sp20);
    func_80074368(arg2, arg3, &sp1C, &sp18);
    if ((sp24 != -1) && ((sp24 == sp1C) || (sp24 == sp18))) {
        return 1;
    }
    if ((sp20 != -1) && ((sp20 == sp1C) || (sp20 == sp18))) {
        return 1;
    }
    return 0;
}

void func_800762D0(struct_800762D0* arg0) {
    if (D_801CE638 == 1) {
        if ((gGameModes == GMODE_STUNT) && (arg0->unk2C4 <= 0)) {
            arg0->unk2EC = 2;
        } else if (arg0->unk19C >= 599999) {
            arg0->unk2EC = 2;
        } else {
            arg0->unk2EC = 1;
        }
        if ((gGameModes != GMODE_2P_VS) || (arg0->unk2EC != 2)) {
            arg0->unk32C = D_801C39B4;
            D_801C39B4 += 10000.0f;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80076378.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_8007687C.s")

extern s32 D_801C1FD4;
extern s32 D_801C26C0[];

void func_80077F5C(void) {
    s32 i;
    s32 j;
    s32 lap;
    f32 dist;
    f32 speed;
    UnkStruct_801AEE20* prev;
    UnkStruct_80192690* craft;
    RiderStruct* rider;

    if (D_801C1FD4 == 0) {
        D_801C1FD4 = 1;
        for (i = 0, rider = D_801C2938; i < gRiders; i++, rider++) {
            if ((rider->unk2F4 == 0) && (rider->unk2EC == 0)) {
                j = rider->unkC;
                lap = D_801AEE20[j].unkA8; // lap holds the previous record's index here
                prev = &D_801AEE20[lap];
                craft = &D_80192690[i];
                dist = (prev->unk74 * (craft->unk44.z - prev->unk8)) + ((craft->unk44.x - prev->unk0) * prev->unk70);
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
                dist = 1.0f - (dist / prev->unk88);
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
                dist *= 20.0f;
                speed = 80.0f - (rider->racePosition * 5.0f);
                lap = rider->lapCount;
                while ((D_801AEE20[j].unk98 != 3) || (lap < D_801CE728[0])) {
                    if (D_801AEE20[j].unk98 == 3) {
                        lap++;
                    }
                    dist += D_801AEE20[j].unk88;
                    j = D_801AEE20[j].unkA0;
                }
                rider->unk19C += (dist / (speed / 1.8f)) * 50.0f;
            }
        }
        for (i = 0; i < gRiders; i++) {
            if (D_801C2938[i].unk19C >= 600000) {
                D_801C2938[i].unk19C = 599999;
            }
            if ((D_801C2938[i].unk2F4 == 0) && (D_801C2938[i].unk2EC == 0)) {
                for (j = 0; j < gRiders; j++) {
                    if ((D_801C2938[j].unk2F4 == 0) && (D_801C2938[j].unk2EC == 0) && (j != i)) {
                        if ((D_801C2938[i].racePosition < D_801C2938[j].racePosition) &&
                            (D_801C2938[j].unk19C < D_801C2938[i].unk19C)) {
                            lap = D_801C2938[i].racePosition;
                            D_801C2938[i].racePosition = D_801C2938[j].racePosition;
                            D_801C2938[j].racePosition = lap;
                        }
                    }
                }
            }
        }
        if (gCourseID != DOLPHIN_PARK) {
            for (i = 0; i < gRiders; i++) {
                D_801C26C0[i] = D_801C2938[i].racePosition;
            }
        }
    }
}

void func_80078264(void) {
    RiderStruct* temp_a0;
    RiderStruct* temp_v1;
    s32 var_v0;
    f32 var_fv0;
    s32 lapCount;
    s32 lapCount2;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_801BB120;
    var_fv0 = 0.0f;
    temp_v1 = &D_801C2938[D_800D48DC];
    temp_a0 = &D_801C2938[D_800D48E0];
    lapCount = temp_v1->lapCount;
    lapCount2 = temp_a0->lapCount;
    var_a3 = temp_v1->unkC;
    var_t0 = temp_a0->unkC;

    if (temp_a0->racePosition >= temp_v1->racePosition) {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_t0].unk88;
                if (D_801AEE20[var_t0].unk98 == 3) {
                    lapCount2++;
                }
                var_t0 = D_801AEE20[var_t0].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }
        temp_v1->unk330 = -var_fv0;
        temp_a0->unk330 = var_fv0;
    } else {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_a3].unk88;
                if (D_801AEE20[var_a3].unk98 == 3) {
                    lapCount++;
                }
                var_a3 = D_801AEE20[var_a3].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }

        temp_v1->unk330 = var_fv0;
        temp_a0->unk330 = -var_fv0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_800783AC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80079528.s")
