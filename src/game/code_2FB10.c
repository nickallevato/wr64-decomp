#include "common.h"

// A course record (0x14 bytes): the time, the rider (D_800DA9B0[0]), the flag drawn as "C"
// or "N" (D_801CB32C), the difficulty, and the initials.
typedef struct UnkStruct_801C1FF0 {
    /* 0x00 */ s32 time;
    /* 0x04 */ s32 rider;
    /* 0x08 */ s32 flag;
    /* 0x0C */ s32 difficulty;
    /* 0x10 */ s8 name[4];
} UnkStruct_801C1FF0; /* size = 0x14 */

// A stunt record (0x10 bytes), as B17D0's CourseRecord.
typedef struct UnkStruct_801C26E8 {
    /* 0x00 */ s32 score;
    /* 0x04 */ s32 rider;
    /* 0x08 */ s32 flag;
    /* 0x0C */ s8 name[4];
} UnkStruct_801C26E8; /* size = 0x10 */

typedef struct UnkStruct_80228AE0 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ char pad4[0x18];
} UnkStruct_80228AE0; /* size = 0x1C */

extern s32 D_800D48E0;
extern UnkStruct_801C1FF0 D_801C1FF0[][3];
extern UnkStruct_801C1FF0 D_801C22C0[];
extern UnkStruct_801C1FF0 D_801C23B0[];
extern s32 D_801C24A0[][9];
extern UnkStruct_801C26E8 D_801C26E8[][3];

extern UnkStruct_801AEE20 D_801AEE20[];
extern s32 D_801BB120;
extern RiderStruct D_801C2938[];

static const char devstr1[] = "dolphin condition full at goal\n";
static const char devstr2[] = "dolphin condition full\n";
static const char devstr3[] = "rank value adjust\n";
static const char devstr4[] = "simultaneously goal !!\n";

typedef struct UnkStruct_801BB138 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ char padC[0xC];
} UnkStruct_801BB138; /* size = 0x18 */

extern UnkStruct_801BB138 D_801BB138[];
extern UnkStruct_801C1FF0 D_800D81B0;
extern UnkStruct_801C26E8 D_800D81C4;
extern s32 D_800D8224;
extern s32 D_800D8228;
extern s32 D_800D817C;
extern f32 D_800D8180[];
extern u8 D_800D9280[];
extern s32 D_800D5438;
extern s32 D_801BB12C;
extern s32 D_801BC938;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern f32 D_801C1F94;
extern f32 D_801C1F98;
extern f32 D_801C1F9C;
extern f32 D_801C1FA0;
extern f32 D_801C1FA4;
extern f32 D_801C1FA8;
extern f32 D_801C1FAC;
extern f32 D_801C1FB0;
extern f32 D_801C1FB4;
extern s32 D_801C1FC0;
extern s32 D_801C1FC4;
extern s32 D_801C1FC8;
extern s32 D_801C1FCC;
extern s32 D_801C1FD0;
extern s32 D_801C1FD4;
extern s32 D_801C1FD8;
extern s32 D_801C1FDC;
extern s32 D_801C1FE0;
extern s32 D_801C1FE4;
extern s32 D_801C1FE8;
extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801C2658;
extern s32 D_801C26C0[];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern s32 D_801C26C4;
extern s32 D_801C26C8;
extern s32 D_801C26E0;
extern s32 D_801C26E4;
extern s32 D_801C292C;
extern s32 D_801C2930;
extern s32 D_801C3718;
extern s32 D_801C378C;
extern s32 D_801C3790[];
extern s32 D_801C3890[];
extern f32 D_801C39B0;
extern s32 D_801C39B8;
extern s32 D_801C39C0;
extern f32 D_801C39C4;
extern s32 D_801C39C8;
extern s32 D_801C39CC;
extern s32 D_801C39D0;
extern s32 D_801C39D4;
extern s32 D_801C39D8;
extern s32 D_801C39DC;
extern s32 D_801C39E0;
extern s32 D_801C39E4;
extern s32 D_801C39E8;
extern s32 D_801C39EC;
extern s32 D_801C39F0;
extern s32 D_801C39F4;
extern s32 D_801C39F8;
extern s32 D_801C39FC;
extern s32 D_801C3A00;
extern s32 D_801C3A04;

void func_801EED70(void);

#ifdef NON_MATCHING
// 17378: same blocks, loops and calls; register allocation and scheduling differ throughout,
// and this C is 21 instructions shorter.
void func_80075310(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 depth;
    s32 type;
    s32 n;
    f32 x;
    f32 z;
    f32 a;
    RiderStruct* rider;

    // First call: the default records of slots 9 to 11.
    if (D_800D8224 != 0) {
        D_800D8224 = 0;
        for (i = 9; i < 12; i++) {
            for (j = 0; j < 3; j++) {
                D_801C1FF0[i][j] = D_800D81B0;
            }
            for (j = 0; j < 9; j++) {
                D_801C24A0[i][j] = -1;
            }
            D_801C22C0[i] = D_800D81B0;
            D_801C23B0[i] = D_800D81B0;
        }
        for (i = 9; i < 12; i++) {
            for (j = 0; j < 3; j++) {
                D_801C26E8[i][j] = D_800D81C4;
            }
        }
        D_801C26C4 = 2;
        D_801C26C4 = 3;
        D_801C26C8 = 1;
        D_801C26C8 = 0;
    }

    // The course's extent from both buoy tables: the bounding box and the largest |x| or |z|
    // (at least 4096), and from them the map scale.
    D_801C1FC4 = 0;
    D_801C1FA4 = 32767.0f;
    D_801C1FA8 = -32768.0f;
    D_801C1F9C = D_801C1FA4;
    D_801C1FA0 = D_801C1FA8;
    D_801C1F94 = 0.0f;
    for (i = 0; i < D_801BB120; i++) {
        x = D_801AEE20[i].unk24;
        if (x < D_801C1F9C) {
            D_801C1F9C = x;
        }
        if (D_801C1FA0 < x) {
            D_801C1FA0 = x;
        }
        z = D_801AEE20[i].unk28;
        if (z < D_801C1FA4) {
            D_801C1FA4 = z;
        }
        if (D_801C1FA8 < z) {
            D_801C1FA8 = z;
        }
        a = (x >= 0.0f) ? x : -x;
        if (D_801C1F94 < a) {
            D_801C1F94 = a;
        }
        a = (z >= 0.0f) ? z : -z;
        if (D_801C1F94 < a) {
            D_801C1F94 = a;
        }
    }
    for (i = 0; i < D_801BC938; i++) {
        x = D_801BB138[i].unk0;
        if (x < D_801C1F9C) {
            D_801C1F9C = x;
        }
        if (D_801C1FA0 < x) {
            D_801C1FA0 = x;
        }
        z = D_801BB138[i].unk8;
        if (z < D_801C1FA4) {
            D_801C1FA4 = z;
        }
        if (D_801C1FA8 < z) {
            D_801C1FA8 = z;
        }
        a = (x >= 0.0f) ? x : -x;
        if (D_801C1F94 < a) {
            D_801C1F94 = a;
        }
        a = (z >= 0.0f) ? z : -z;
        if (D_801C1F94 < a) {
            D_801C1F94 = a;
        }
    }
    if (D_801C1F94 < 4096.0f) {
        D_801C1F94 = 4096.0f;
        D_801C1F9C = -4096.0f;
        D_801C1FA4 = -4096.0f;
        D_801C1FA0 = -D_801C1F9C;
        D_801C1FA8 = -D_801C1FA4;
    }
    D_801C1FAC = D_801C1FA0 - D_801C1F9C;
    D_801C1FB0 = D_801C1FA8 - D_801C1FA4;
    D_801C1F98 = 160.0f / (2.0f * D_801C1F94);
    D_801C1FB4 = (D_801C1F94 * 1.4142f) + 2048.0f;

    // D_801C3890: 1 for table B records that are not reached from exactly one record
    // (unkA0 or unkA4).
    for (i = 0; i < D_801BB120; i++) {
        D_801C3890[i] = 0;
    }
    for (i = 0; i < D_801BB120; i++) {
        D_801C3890[D_801AEE20[i].unkA0]++;
        if (D_801AEE20[i].unkA4 != -1) {
            D_801C3890[D_801AEE20[i].unkA4]++;
        }
    }
    for (i = 0; i < D_801BB120; i++) {
        if (D_801C3890[i] == 1) {
            D_801C3890[i] = 0;
        } else {
            D_801C3890[i] = 1;
        }
    }
    // D_801C3790: the records of one lap from D_801BB12C, outside the stretches that start at
    // a type 6 record and end at a record from the previous step.
    depth = 0;
    n = 0;
    i = D_801BB12C;
    do {
        if (D_801AEE20[i].unk98 != 6) {
            if ((D_801C3890[i] != 0) && (depth > 0)) {
                depth--;
            }
            if (depth == 0) {
                D_801C3790[n++] = i;
            }
        } else {
            if (depth == 0) {
                D_801C3790[n++] = i;
            }
            depth++;
        }
        i = D_801AEE20[i].unkA0;
    } while (i != D_801BB12C);
    D_801C378C = n;
    D_801C1FC0 = 0;
    for (i = 0; i < D_801BB120; i++) {
        if (D_801AEE20[i].unk9C == 1) {
            D_801C1FC0++;
        }
    }

    // Reset the standings of every rider.
    D_801C3718 = gRiders;
    for (i = 0; i < gRiders; i++) {
        rider = &D_801C2938[i];
        rider->unk174 = 0;
        rider->lapCount = 0;
        rider->racePosition = 0;
        rider->unk324 = 0;
        rider->unk8 = 0;
        rider->unk320 = 0;
        rider->unk32C = 0.0f;
        rider->unk1C = -1;
        rider->unk20 = 0;
        rider->unk24 = 0;
        rider->unk28 = 0;
        rider->unkC = rider->unk10 = rider->unk310 = D_801BB12C;
        if ((gCourseID == DOLPHIN_PARK) || (gGameModes == GMODE_STUNT)) {
            rider->unk12C = 5;
        } else {
            rider->unk12C = 0;
        }
        rider->unk138 = 0;
        rider->unk130 = 0;
        rider->unk134 = 0;
        rider->unk13C = 0;
        if (gGameModes == GMODE_STUNT) {
            rider->unk164 = 1;
        } else {
            rider->unk164 = 0;
        }
        rider->unk33C = 0;
        rider->unk2F8 = 0;
        rider->unk300 = 0;
        rider->unk2FC = 0;
        rider->unk2C8 = 0;
        rider->unk2E0 = 0;
        rider->unk2DC = 0;
        rider->unk2D8 = 0;
        rider->unk2D0 = 0;
        rider->unk328 = 0;
        rider->unk2E8 = 0;
        rider->unk2E4 = 0;
        rider->unk334 = 0;
        rider->unk2EC = 0;
        rider->unk2F0 = 0;
        rider->unk2F4 = 0;
        rider->unk304 = 0;
        for (j = 0; j < D_801BB120; j++) {
            rider->unk2C[j] = 0;
        }
        rider->unk168 = 0;
        rider->unk16C = 0;
        rider->unk19C = 0;
        rider->unk170 = 599999;
        rider->unk2C4 = D_800D9280[gCourseID] * 1000;
        for (j = 0; j < 9; j++) {
            rider->unk140[j] = 0;
            rider->unk178[j] = 0;
            for (k = 0; k < 8; k++) {
                rider->unk1A4[j][k] = 0;
            }
        }
        rider->unk330 = 0.0f;
        rider->unk308 = 0;
        rider->unk30C = 0;
        rider->unk31C = 0;
        rider->unk314 = 0;
        rider->unk318 = 0;
        rider->unk350 = (struct UnkStruct_801C3C54*) D_801AEE20;
        // D_801CE638 8: each rider starts at the record after one of type 11..14.
        if (D_801CE638 == 8) {
            switch ((i + D_800D5438) & 3) {
                case 0:
                    type = 11;
                    break;
                case 1:
                    type = 12;
                    break;
                case 2:
                    type = 13;
                    break;
                case 3:
                    type = 14;
                    break;
            }
            for (j = 0; j < D_801BB120; j++) {
                if (type == D_801AEE20[j].unk98) {
                    break;
                }
            }
            if (j >= D_801BB120) {
                j = D_801BB12C;
            } else {
                j = D_801AEE20[j].unkB4;
            }
            for (k = j, n = D_801BB120 - 1; (D_801AEE20[k].unk98 >= 2) && (n > 0); n--) {
                k = D_801AEE20[k].unkB4;
            }
            rider->unkC = rider->unk310 = k;
            k = j;
            if (D_801AEE20[j].unk98 == 1) {
                for (n = D_801BB120 - 1; n > 0; n--) {
                    k = D_801AEE20[k].unkB4;
                    if (D_801AEE20[k].unk98 != 1) {
                        break;
                    }
                }
            }
            rider->unk10 = k;
        }
    }

    D_800D817C = 1;
    D_801C1FD8 = 0;
    D_801C1FD4 = 0;
    D_801C1FDC = 0;
    D_801C39C4 = D_800D8180[gCourseID];
    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_801C39B8 = 0;
    } else if (gDifficulty == DIFFICULTY_HARD) {
        D_801C39B8 = 4;
    } else {
        D_801C39B8 = 5;
    }
    D_801C1FD0 = 0;
    D_801C1FCC = 0;
    D_801C1FC8 = 0;
    if (gCourseID == MARINE_FORTRESS) {
        for (i = 0; i < D_801BFA40; i++) {
            if (D_801BC940[i].unk4C == 2) {
                break;
            }
        }
        if (i < D_801BFA40) {
            D_801C39C0 = i;
        } else {
            D_801C39C0 = 0;
        }
    }
    D_801C2930 = 0;
    if (gGameModes == GMODE_STUNT) {
        D_801C26DC = D_801C26D8 = D_801C26D4 = D_801C26D0 = 0;
        D_801C26E4 = D_801C26E0 = 0;
        D_801C39D4 = D_801C39D0 = D_801C39CC = 0;
        D_801C39E4 = D_801C39E0 = D_801C39DC = D_801C39D8 = 0;
        D_801C39F8 = D_801C39F4 = D_801C39F0 = D_801C39EC = D_801C39E8 = 0;
        D_801C3A04 = 0;
        D_801C3A00 = 0;
        D_801C39FC = D_801C3A00;
        D_801C292C = 0;
        D_801C39C8 = 0;
    }
    D_801C39B0 = 100000.0f;
    D_801C39B4 = -100000.0f;
    D_801C2928 = 0;
    D_801C2658 = 0;
    D_801C2654 = 0;
    D_801C2650 = 0;
    if (D_800DAB68 == 0) {
        D_801C1FE4 = D_801C1FF0[gCourseID][0].time;
        D_801C1FE0 = D_801C1FE8 = D_801C22C0[gCourseID].time;
    } else {
        D_801C1FE4 = D_801C23B0[gCourseID].time;
        D_801C1FE0 = D_801C1FE8 = 0;
    }

    // The starting order D_801C26C0.
    if (D_801CE6F8 != 0) {
        for (i = 0; i < 4; i++) {
            D_801C26C0[i] = 3 - i;
        }
        D_801C26C0[1] = 0;
        D_801C26C0[3] = 2;
        for (i = 0; i < 12; i++) {
            D_801C2690[i] = 0;
            D_801C2660[i] = 0;
        }
    } else if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gRiders; i++) {
            D_801C26C0[i] = i;
        }
    } else if (gCourseID == RIDER_SELECTION) {
        for (i = 0; i < gRiders; i++) {
            D_801C26C0[i] = i;
        }
    }
    // D_800D8228 (1-4) puts that slot on the human's rider.
    if (D_800D8228 != 0) {
        for (i = 0; i < gRiders; i++) {
            if (D_800D8228 - 1 == D_801C26C0[i]) {
                break;
            }
        }
        if ((i < gRiders) && (i != D_800D48DC)) {
            D_801C26C0[i] = D_801C26C0[D_800D48DC];
            D_801C26C0[D_800D48DC] = D_800D8228 - 1;
        }
    }
    if (gCourseID != DOLPHIN_PARK) {
        for (i = 0; i < gRiders; i++) {
            D_801C2938[i].racePosition = D_801C26C0[i];
        }
    }
    func_801EED70();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80075310.s")
#endif

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

typedef struct UnkStruct_801C3720 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ char padC[0xC];
} UnkStruct_801C3720; /* size = 0x18 */

typedef struct UnkStruct_800D81D4 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
} UnkStruct_800D81D4; /* size = 0x8 */

typedef struct UnkStruct_800D8204 {
    /* 0x00 */ f32 minX;
    /* 0x04 */ f32 maxX;
    /* 0x08 */ f32 minZ;
    /* 0x0C */ f32 maxZ;
} UnkStruct_800D8204; /* size = 0x10 */

extern UnkStruct_800D81D4 D_800D81D4[];
extern UnkStruct_800D8204 D_800D8204;
extern UnkStruct_800D8204 D_800D8214;
extern UnkStruct_801C3720 D_801C3720[];
extern f32 D_801C3780;
extern f32 D_801C3784;
extern f32 D_801C3788;

void func_800C1904(s32);
void func_800C1A20(s32);

#ifdef NON_MATCHING
// 2675: same blocks and calls. With the FAKE empty if below, x, z and the distances stay on the
// stack as in the original; the frame is 0x98, not 0x88, and the registers differ.
void func_80076378(s32 arg0) {
    s32 best;
    s32 prev;
    s32 next;
    f32 dx0;
    f32 dz0;
    f32 dxp;
    s32 cur;
    s32 zoneA;
    s32 zoneB;
    s32 zoneC;
    s32 zoneD;
    f32 bestDist;
    f32 dzp;
    f32 dxn;
    s32 n;
    s32 i;
    f32 dzn;
    s32 wasIn;
    s32 player;
    UnkStruct_800D8204* rect;
    f32 dx;
    s32 isHuman;
    RiderStruct* rider;
    f32 x;
    f32 z;
    f32 d;
    f32 dz;

    rider = &D_801C2938[arg0];
    if (D_801CE638 == 2) {
        D_801C3780 = D_801C3720[arg0].unk0;
        D_801C3784 = 0.0f;
        D_801C3788 = D_801C3720[arg0].unk8;
    } else {
        D_801C3780 = D_80192690[arg0].unk44.x;
        D_801C3784 = D_80192690[arg0].unk44.y;
        D_801C3788 = D_80192690[arg0].unk44.z;
    }
    isHuman = (arg0 == D_800D48DC) || ((gPlayers == TWO_PLAYERS) && (arg0 == D_800D48E0));
    if (D_801CE638 == 1) {
        cur = rider->unk310;
        best = cur;
        x = D_801C3780;
        z = D_801C3788;
        prev = D_801AEE20[cur].unkA8;
        next = D_801AEE20[cur].unkA0;
        dx0 = D_801AEE20[cur].unk0 - x;
        dxp = D_801AEE20[prev].unk0 - x;
        dzp = D_801AEE20[prev].unk8 - z;
        dz0 = D_801AEE20[cur].unk8 - z;
        dxn = D_801AEE20[next].unk0 - x;
        dzn = D_801AEE20[next].unk8 - z;
        bestDist = (dx0 * dx0) + (dz0 * dz0);
        d = (dxp * dxp) + (dzp * dzp);
        if (d < bestDist) {
            bestDist = d;
            if (cur && cur && cur) {} // FAKE
            best = prev;
        }
        if (((dxn * dxn) + (dzn * dzn)) < bestDist) {
            best = next;
        }
        func_80074368(x, z, &zoneA, &zoneB);
        if (cur != best) {
            func_80074368(D_801AEE20[best].unk0, D_801AEE20[best].unk8, &zoneC, &zoneD);
            if (((zoneA != -1) && ((zoneA == zoneC) || (zoneA == zoneD))) ||
                ((zoneB != -1) && ((zoneB == zoneC) || (zoneB == zoneD)))) {
                rider->unk310 = best;
            }
        }
    }
    if (gCourseID == DRAKE_LAKE) {
        rider->unk318 = 0;
        n = 6;
        if (gDifficulty < 2) {
            n = 3;
        }
        for (i = 0; i < n; i++) {
            if (!(D_801C3784 > 40.0f)) {
                dx = D_801C3780 - D_800D81D4[i].x;
                dz = D_801C3788 - D_800D81D4[i].z;
                if (((dx * dx) + (dz * dz)) <= 22500.0f) {
                    rider->unk318 = 1;
                    break;
                }
            }
        }
    }
    if ((gCourseID == PORT_BLUE) || (gCourseID == TWILIGHT_CITY)) {
        wasIn = rider->unk31C;
        if (gCourseID == PORT_BLUE) {
            rect = &D_800D8204;
        } else {
            rect = &D_800D8214;
        }
        if ((rect->minX <= D_801C3780) && (D_801C3780 <= rect->maxX) && (rect->minZ <= D_801C3788) &&
            (D_801C3788 <= rect->maxZ)) {
            rider->unk31C = 1;
        } else {
            rider->unk31C = 0;
        }
        if (isHuman && (wasIn != rider->unk31C)) {
            player = 1;
            if (arg0 == D_800D48DC) {
                player = 0;
            }
            if (rider->unk31C != 0) {
                func_800C1904(player);
            } else {
                func_800C1A20(player);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80076378.s")
#endif

extern s32 D_800D4B00;
extern s32 D_801B2F20[];
extern s32 D_801B7020[];
extern s16 D_801CE628;
extern s32 D_80223934;
extern s16 D_801CE72E;
extern s32 D_80228A98;
extern f32 D_801C39A0[];

void func_800C1B30(void);
void func_800C1EB8(s32);

#ifdef NON_MATCHING
// 43091: same blocks and calls, 4 instructions shorter; register allocation and scheduling differ
// throughout.
void func_8007687C(s32 arg0) {
    s32 isHuman;
    s32 cur;
    s32 inGate;
    s32 passed;
    s32 sameZone;
    s32 zoneA;
    s32 zoneB;
    s32 zoneC;
    s32 zoneD;
    s32 type;
    s32 frac;
    s32 time;
    s32 ref;
    s32 sfx;
    s32 laps;
    s32 i;
    s32 r;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 beyond;
    s32 nearLine;
    f32 px;
    f32 pz;
    f32 dirX;
    f32 dirZ;
    f32 dx;
    f32 dz;
    f32 len;
    f32 dot;
    f32 dPos;
    f32 dPrev;
    f32 progress;
    f32 segLen;
    RiderStruct* rider;
    UnkStruct_801AEE20* e;
    UnkStruct_801AEE20* next;
    UnkStruct_801AEE20* from;

    if (arg0 == D_800D48DC) {
        D_801C2658 = 0;
    }
    isHuman = (arg0 == D_800D48DC) || ((gPlayers == TWO_PLAYERS) && (arg0 == D_800D48E0));
    rider = &D_801C2938[arg0];
    rider->unk314 = 0;
    if (rider->unk300 != 0) {
        rider->unk300--;
    }
    if ((gCourseID == DRAKE_LAKE) && (D_801C1FD0 == 0) && isHuman && (rider->unk19C >= 50001)) {
        D_801C1FD0 = 1;
    }
    if (gCourseID == GLACIER_COAST) {
        if (D_801C1FCC >= 2) {
            rider->unk350 = (struct UnkStruct_801C3C54*) D_801B7020;
        } else if (D_801C1FCC > 0) {
            rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
        }
    }
    if ((gCourseID == RIDER_SELECTION) && (arg0 == D_800D48E0)) {
        rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
    }
    if (((D_801CE628 == 1) && (arg0 == D_800D48DC)) ||
        ((gPlayers == TWO_PLAYERS) && (D_801CE628 == 2) && (arg0 == D_800D48E0))) {
        if (rider->unk2EC == 0) {
            func_800762D0((struct_800762D0*) rider);
        }
        return;
    }
    // The race clock; 9'59"99 retires (except in Dolphin Park).
    if ((D_801CE638 == 1) && (rider->unk2F4 == 0) && (rider->unk2EC == 0) && (D_800D817C == 0) && (D_801C1FD4 == 0)) {
        rider->unk168 += 50;
        if (rider->unk168 >= 599999) {
            rider->unk168 = 599999;
        }
        rider->unk19C += 50;
        if (rider->unk19C >= 599999) {
            rider->unk19C = 599999;
            if (gCourseID != DOLPHIN_PARK) {
                func_800762D0((struct_800762D0*) rider);
            }
        }
        rider->unk16C = D_800D4B00 & 0xFFFF;
    }

    // The next record (unkC): a point 25 behind it on its side (unk80/unk84), and for gates
    // whether the rider is between the posts (with D_801C39C4 of slack).
    cur = rider->unkC;
    e = &D_801AEE20[cur];
    px = e->unk0 - (e->unk80 * 50.0f * 0.5f);
    pz = e->unk8 - (e->unk84 * 50.0f * 0.5f);
    if (e->unk9C == 1) {
        dx = e->unkC - e->unk18;
        dz = e->unk14 - e->unk20;
        len = sqrtf((dx * dx) + (dz * dz));
        if (len > 0.0f) {
            dx /= len;
            dz /= len;
        }
        dot = ((D_801C3780 - e->unk18) * dx) + ((D_801C3788 - e->unk20) * dz);
        if (dot >= 0.0f) {} // an empty test, as in the original
        if (D_801C1F90 == 0) {
            inGate = dot <= ((e->unk8C * 2.0f) + D_801C39C4);
        } else {
            inGate = -D_801C39C4 <= dot;
        }
    } else {
        type = e->unk98;
        if ((type == 8) || (type == 9)) {
            dot = ((D_801C3780 - e->unk0) * e->unk78) + ((D_801C3788 - e->unk8) * e->unk7C);
            if (!(dot >= 0.0f)) {
                dot = -dot;
            }
            if (dot <= e->unk8C) {} // an empty test, as in the original
        }
    }
    dirX = e->unk70;
    dirZ = e->unk74;
    dx = D_801C3780 - px;
    dz = D_801C3788 - pz;
    len = sqrtf((dx * dx) + (dz * dz));
    if (len > 0.0f) {
        dx /= len;
        dz /= len;
    }
    if ((rider->unk1C == -1) && (((dirX * dx) + (dirZ * dz)) > 0.0f)) {
        if (((dirZ * dx) - (dirX * dz)) >= 0.0f) {
            rider->unk1C = 1;
        } else {
            rider->unk1C = 0;
        }
    } else if (((dirX * dx) + (dirZ * dz)) <= 0.0f) {
        rider->unk1C = -1;
    }
    if ((rider->unk20 == 0) && (rider->unk1C == -1)) {
        rider->unk20 = 1;
    }
    func_80074368(D_801C3780, D_801C3788, &zoneA, &zoneB);
    func_80074368(e->unk0, e->unk8, &zoneC, &zoneD);
    if ((zoneA != -1) && ((zoneA == zoneC) || (zoneA == zoneD))) {
        sameZone = true;
    } else {
        sameZone = false;
        if ((zoneB != -1) && ((zoneB == zoneC) || (zoneB == zoneD))) {
            sameZone = true;
        }
    }
    passed = false;
    rider->unk28 = 0;
    if ((rider->unk20 != 0) && (rider->unk1C >= 0)) {
        type = e->unk98;
        if (rider->unk320 != rider->lapCount) {
            rider->unk20 = 0;
        }
        if ((e->unk9C == 1) && !inGate) {
            rider->unk20 = 0;
        }
        if ((e->unkC8 != 0) && !sameZone) {
            rider->unk20 = 0;
        }
        if ((gCourseID == MARINE_FORTRESS) && (gGameModes != GMODE_STUNT) && (type == 4) && !sameZone) {
            rider->unk20 = 0;
        }
        passed = true;
        rider->unk2F0 = 0;
        // A buoy: power up on the correct side (type 0 on the left, 1 on the right), else a miss.
        if ((e->unk9C == 0) && (rider->unk2F4 == 0) && (rider->unk2EC == 0) && (type != 8) && (type != 9)) {
            if (((type == 0) && (rider->unk1C == 0)) || ((type == 1) && (rider->unk1C == 1))) {
                if (e->unkC8 != 0) {
                    if (rider->unk12C < 5) {
                        rider->unk12C++;
                        rider->unk314 = 1;
                    }
                    rider->unk28 = 1;
                    if (isHuman) {
                        if ((gPlayers == TWO_PLAYERS) && (arg0 == D_800D48E0)) {
                            sfx = 0x80;
                        } else {
                            sfx = 0;
                        }
                        if (type == 0) {
                            AudioGeneral_PlaySound(0x26, sfx);
                        } else {
                            AudioGeneral_PlaySound(0x27, sfx);
                        }
                    }
                }
            } else if (((type == 0) || (type == 1)) && (D_801CE72E != 0) && (D_801CE638 == 1) && (e->unkC8 != 0)) {
                if (isHuman) {
                    rider->unk130++;
                    rider->unk134++;
                }
                if (rider->unk134 >= gBuoyMisses) {
                    rider->unk13C = 1;
                    if (isHuman && (gBuoyMisses == 0)) {
                        func_800762D0((struct_800762D0*) rider);
                    }
                }
                rider->unk28 = 2;
                if (isHuman) {
                    sfx = gBuoyMisses - rider->unk134;
                    if (sfx < 0) {
                        sfx = 0;
                    }
                    if ((gPlayers == TWO_PLAYERS) && (arg0 == D_800D48E0)) {
                        sfx += 0x80;
                    }
                    if (type == 0) {
                        AudioGeneral_PlaySound(0x29, sfx);
                    } else {
                        AudioGeneral_PlaySound(0x28, sfx);
                    }
                }
            }
        }
        rider->unkC = e->unkA0;
        if (sameZone) {
            rider->unk310 = cur;
        }
        rider->unk1C = -1;
        rider->unk20 = 1;
        // Marine Fortress, above normal difficulty: once, near the type 2 object, a sound cue.
        if ((gCourseID == MARINE_FORTRESS) && (gDifficulty > 0) && (D_801C1FC8 == 0) && (rider->lapCount >= 2) &&
            (((D_800DAB68 == 0) && (e->unk98 == 6)) || (D_800DAB68 != 0))) {
            D_801C1FC8 = 1;
            dx = D_801BC940[D_801C39C0].unk0 - gCameraPerspective[D_80223930].unk4C;
            dz = D_801BC940[D_801C39C0].unk8 - gCameraPerspective[D_80223930].unk54;
            if (((dx * dx) + (dz * dz)) < 1.6e7f) {
                func_800C1B30();
            } else if (gPlayers == TWO_PLAYERS) {
                dx = D_801BC940[D_801C39C0].unk0 - gCameraPerspective[D_80223934].unk4C;
                dz = D_801BC940[D_801C39C0].unk8 - gCameraPerspective[D_80223934].unk54;
                if (((dx * dx) + (dz * dz)) < 1.6e7f) {
                    func_800C1B30();
                }
            }
        }
    }
    if (passed && (rider->unk13C == 0) && (rider->unk2F4 == 0) && (rider->unk2EC == 0) && (gCourseID != DOLPHIN_PARK)) {
        // A checkpoint gate: its time, and the gap shown against the time trial record
        // (D_801C24A0) or, in a race, asked of func_80079528 (unk2FC 10).
        if ((e->unk9C == 1) && (rider->lapCount > 0)) {
            dPos = ((D_801C3780 - e->unk0) * dirX) + ((D_801C3788 - e->unk8) * dirZ);
            if (!(dPos >= 0.0f)) {
                dPos = -dPos;
            }
            dPrev = ((D_80192690[arg0].unkBE4 - e->unk0) * dirX) + ((D_80192690[arg0].unkBEC - e->unk8) * dirZ);
            if (!(dPrev >= 0.0f)) {
                dPrev = -dPrev;
            }
            frac = (dPos / (dPos + dPrev)) * 50.0f;
            if (e->unk98 == 3) {
                rider->unk164 = 0;
            }
            time = rider->unk19C - frac;
            rider->unk1A4[rider->lapCount - 1][rider->unk164] = time;
            if ((D_801CE638 == 1) && (D_801C1FC4 == 0) && (D_801C1FD8 == 0) &&
                ((cur != D_801BB12C) || (rider->lapCount < D_801CE728[0]))) {
                if ((gGameModes == GMODE_TIME_TRIALS) && (D_800DAB68 == 0) && (cur == D_801BB12C) &&
                    (rider->lapCount < 3)) {
                    ref = D_801C24A0[gCourseID][rider->lapCount - 1];
                    if (ref > 0) {
                        if (ref < time) {
                            rider->unk2FC = 1;
                            rider->unk2F8 = time - ref;
                        } else {
                            rider->unk2FC = 2;
                            rider->unk2F8 = ref - time;
                        }
                        rider->unk300 = 40;
                    }
                } else if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS)) {
                    rider->unk2FC = 10;
                } else {
                    rider->unk2FC = 0;
                }
            }
        }
        // The line: the lap time and best lap, lap sounds, the last lap.
        if (cur == D_801BB12C) {
            if (rider->lapCount > 0) {
                rider->unk168 -= frac;
                if (D_801CE638 == 1) {
                    if (rider->lapCount < 10) {
                        rider->unk178[rider->lapCount - 1] = rider->unk168;
                        rider->unk140[rider->lapCount - 1] = rider->unk130;
                    } else {
                        for (i = 0; i < 8; i++) {
                            rider->unk178[i] = rider->unk178[i + 1];
                            rider->unk140[i] = rider->unk140[i + 1];
                        }
                        rider->unk178[8] = rider->unk168;
                        rider->unk140[8] = rider->unk130;
                    }
                    if (rider->unk168 < rider->unk170) {
                        rider->unk170 = rider->unk168;
                        rider->unk174 = rider->lapCount;
                    }
                    if ((gPlayers == ONE_PLAYER) && (arg0 == D_800D48DC)) {
                        if (rider->unk170 < D_801C1FE0) {
                            D_801C1FE0 = rider->unk170;
                            D_801C2658 = 1;
                            if ((gGameModes == GMODE_TIME_TRIALS) && (rider->lapCount < D_801CE728[0])) {
                                D_80228A98 = 1;
                            }
                            if (rider->lapCount < D_801CE728[0]) {
                                sfx = 1;
                                if (D_801CE728[0] == rider->lapCount + 1) {
                                    sfx = 0x81;
                                }
                                AudioGeneral_PlaySound(0x21, sfx);
                            }
                        } else if (rider->lapCount < D_801CE728[0]) {
                            sfx = 0;
                            if (D_801CE728[0] == rider->lapCount + 1) {
                                sfx = 0x80;
                            }
                            if ((gGameModes == GMODE_TIME_TRIALS) && (rider->unk2FC == 2)) {
                                sfx += 2;
                            }
                            AudioGeneral_PlaySound(0x21, sfx);
                        }
                    } else if ((gPlayers == TWO_PLAYERS) && isHuman) {
                        if (rider->lapCount < D_801CE728[0]) {
                            sfx = 0;
                            if (D_801CE728[0] == rider->lapCount + 1) {
                                sfx = 0x80;
                            }
                            AudioGeneral_PlaySound(0x21, sfx);
                        }
                    }
                }
                rider->unk168 = frac;
                if ((gCourseID == MARINE_FORTRESS) && (gDifficulty > 0) && (D_800D8240 == 0) && (rider->lapCount > 0)) {
                    rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
                }
                if ((gCourseID == GLACIER_COAST) && isHuman && (D_801C1FCC < rider->lapCount)) {
                    D_801C1FCC++;
                }
                if (isHuman && (rider->lapCount < D_801CE728[0])) {
                    switch (rider->racePosition) {
                        case 0:
                            func_800C1EB8(2);
                            break;
                        case 1:
                            func_800C1EB8(1);
                            break;
                        case 2:
                            func_800C1EB8(0);
                            break;
                    }
                }
                if ((rider->lapCount >= D_801CE728[0]) && (D_800D8178 == 0) && (D_801C1FD4 == 0)) {
                    rider->unk2F4 = 1;
                    rider->unk32C = D_801C39B0;
                    D_801C39B0 -= 10000.0f;
                    laps = D_801CE728[0];
                    if (laps >= 10) {
                        laps = 9;
                    }
                    rider->unk19C = 0;
                    for (i = 0; i < laps; i++) {
                        rider->unk19C += rider->unk178[i];
                    }
                    if (!isHuman) {
                        rider->unk12C = 0;
                    }
                }
            }
            if ((D_800D8178 == 0) || (rider->lapCount == 0)) {
                if (rider->lapCount < D_801CE728[0]) {
                    rider->lapCount++;
                    rider->unk320 = rider->lapCount;
                }
            }
            rider->unk130 = 0;
            for (i = 1; i < D_801BB120; i++) {
                rider->unk2C[i] = 0;
            }
            if ((rider->lapCount >= 2) && (rider->unk2F4 == 0)) {
                rider->unk308 = 1;
            }
        }
        rider->unk2C[cur] = 1;
    }
    if (rider->unk12C != rider->unk138) {
        if (rider->unk12C - rider->unk138 == 0) {
            i = 0;
        } else if (rider->unk12C - rider->unk138 > 0) {
            i = 1;
        } else {
            i = -1;
        }
        rider->unk138 += i;
    }
    if ((D_801CE638 != 1) || (gCourseID == DOLPHIN_PARK)) {
        rider->unk8 = 0;
        rider->unk32C = 0.0f;
        D_801C39A0[arg0] = 0.0f;
    }

    // Crossing the line backwards or forwards near it (within one record of it, four on
    // Sunset Bay) moves the lap counter unk320.
    r1 = D_801AEE20[rider->unk310].unkA0;
    r2 = D_801AEE20[r1].unkA0;
    r3 = D_801AEE20[r2].unkA0;
    beyond = false;
    if (((D_801AEE20[D_801BB12C].unk74 * (D_801C3788 - D_801AEE20[D_801BB12C].unk8)) +
         ((D_801C3780 - D_801AEE20[D_801BB12C].unk0) * D_801AEE20[D_801BB12C].unk70)) > 0.0f) {
        beyond = true;
    }
    nearLine = (D_801BB12C == rider->unk310) || (r1 == D_801BB12C);
    if (gCourseID == SUNSET_BAY) {
        nearLine = nearLine || (r2 == D_801BB12C) || (r3 == D_801BB12C) || (D_801AEE20[r3].unkA0 == D_801BB12C);
    }
    if (func_80076240(D_801C3780, D_801C3788, D_801AEE20[D_801BB12C].unk0, D_801AEE20[D_801BB12C].unk8) &&
        nearLine) {
        if (beyond && (rider->unk324 == 0) && (rider->unk320 < rider->lapCount)) {
            rider->unk320++;
        } else if (!beyond && (rider->unk324 != 0)) {
            if (rider->unk320 >= -49) {
                rider->unk320--;
            }
        }
    }
    rider->unk324 = beyond;

    // Progress: the last record the rider is past (walking back from unk310), and how far along
    // the segment to the next one; unk32C orders the riders.
    r = rider->unk310;
    segLen = 0.0f;
    progress = 0.0f;
    for (i = 0; i < D_801BB120; i++) {
        e = &D_801AEE20[r];
        dz = D_801C3788 - e->unk8;
        dx = D_801C3780 - e->unk0;
        if (!(((e->unk74 * dz) + (dx * e->unk70)) <= 0.0f)) {
            if ((gCourseID == MARINE_FORTRESS) && (e->unk98 == 4) && (e->unkC0 == 1) &&
                (func_80074448(D_801C3780, D_801C3788) != 0)) {
                from = &D_801AEE20[e->unkA8];
            } else {
                from = &D_801AEE20[r];
            }
            next = &D_801AEE20[e->unkA0];
            dirX = next->unk0 - from->unk0;
            dirZ = next->unk8 - from->unk8;
            segLen = sqrtf((dirX * dirX) + (dirZ * dirZ));
            if (segLen > 0.0f) {
                dirX /= segLen;
                dirZ /= segLen;
            }
            progress = (dx * dirX) + (dz * dirZ);
            break;
        }
        r = e->unkA8;
    }
    rider->unk8 = r;
    if (segLen > 0.0f) {
        len = progress / segLen;
    } else {
        len = 0.0f;
    }
    if (len >= 1.0f) {
        len = 1.0f;
    }
    if ((rider->unk2F4 == 0) && (rider->unk2EC == 0)) {
        rider->unk32C = ((rider->unk320 * 1000) + (r * 10)) + len;
        D_801C39A0[arg0] = progress;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_8007687C.s")
#endif

extern s32 D_801C1FD4;

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

// Stunt points per trick (craft unk1604), the second of each pair after another trick.
typedef struct UnkStruct_800D92BC {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
} UnkStruct_800D92BC;

extern UnkStruct_800D92BC D_800D92BC;
extern s32 D_800D92B8;
extern s32 D_800D8178;
extern s16 D_800DAB60;
extern s32 D_801BB134;
extern s32 D_80228A94;

void func_801FB488(s32 arg0, s32 arg1, s32 arg2);

#ifdef NON_MATCHING
// 23154: same blocks, switches and calls. Register allocation differs from the start (the
// original keeps more values on the stack; frame 0xB0, here 0x78), and this C is shorter.
void func_800783AC(s32 arg0) {
    s32 trick;
    s32 points;
    s32 cur;
    s32 passed;
    s32 inGate;
    s32 frac;
    s32 bonus;
    s32 laps;
    s32 i;
    s32 sfx;
    f32 dx;
    f32 dz;
    f32 len;
    f32 dot;
    f32 dPos;
    f32 dPrev;
    RiderStruct* rider;
    UnkStruct_801AEE20* e;

    if (arg0 != D_800D48DC) {} // an empty test, as in the original
    rider = &D_801C2938[arg0];
    rider->unk314 = 0;
    if ((gCourseID == RIDER_SELECTION) && (arg0 == D_800D48E0)) {
        rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
    }
    if (((D_801CE628 == 1) && (arg0 == D_800D48DC)) ||
        ((gPlayers == TWO_PLAYERS) && (D_801CE628 == 2) && (arg0 == D_800D48E0))) {
        if (rider->unk2EC == 0) {
            func_800762D0((struct_800762D0*) rider);
        }
        return;
    }
    // The points of the last trick, shown when its timer runs out.
    if ((D_801C39D0 > 0) && (--D_801C39D0 <= 0)) {
        func_801FB488(2, D_801C39CC, 1);
        D_801C39CC = 0;
    }
    // The clock: race time up, time left (unk2C4) down; out of time and slow, or out of
    // time for 200 frames, retires.
    if ((rider->unk2F4 == 0) && (rider->unk2EC == 0) && (D_800D817C == 0) && (D_801C1FD4 == 0)) {
        rider->unk168 += 50;
        if (rider->unk168 >= 299999) {
            rider->unk168 = 299999;
        }
        rider->unk19C += 50;
        if (rider->unk19C >= 299999) {
            rider->unk19C = 299999;
        }
        rider->unk16C = D_800D4B00 & 0xFFFF;
        rider->unk2C4 -= 50;
        if (rider->unk2C4 <= 0) {
            rider->unk2C4 = 0;
        }
        if (rider->unk2C4 > 0) {
            rider->unk334 = 0;
        } else {
            rider->unk334++;
            if (((D_80192690[arg0].unkB90 * 1.8f) < 10.0f) || (rider->unk334 >= 201)) {
                func_800762D0((struct_800762D0*) rider);
            }
        }
    }
    // unk138 follows unk12C one step a frame.
    if (rider->unk12C != rider->unk138) {
        if (rider->unk12C - rider->unk138 == 0) {
            i = 0;
        } else if (rider->unk12C - rider->unk138 > 0) {
            i = 1;
        } else {
            i = -1;
        }
        rider->unk138 += i;
    }
    // Trick points (D_801C26E4) from the craft's trick state unk1604.
    if ((rider->unk2F4 == 0) && (rider->unk2EC == 0)) {
        points = 0;
        trick = D_80192690[arg0].unk1604;
        if (trick == 3) {
            D_801C26E0 = 1;
        } else if (trick == 4) {
            D_801C26E0 = 2;
        } else if (trick == 5) {
            D_801C26E0 = 3;
        } else if (trick == 6) {
            points = D_80192690[D_800D48DC].unk15EC * 14.3f;
            if (points > 0) {
                switch (D_801C26E0) {
                    case 1:
                        D_801C39FC = 1;
                        break;
                    case 2:
                        D_801C3A00 = 1;
                        break;
                    case 3:
                        D_801C3A04 = 1;
                        break;
                }
            }
            D_801C26E0 = 0;
        } else if (trick == 7) {
            D_801C26E0 = 0;
            points = D_80192690[D_800D48DC].unk15EC * 7.15f;
        } else if (trick == 8) {
            D_801C26E0 = 0;
        } else if ((D_801C26E0 == 0) && (D_801C39C8 != 0) && (trick == 0)) {
            switch (D_801C39C8) {
                case 1:
                    if (D_801C39D8 == 0) {
                        D_801C39D8 = 1;
                        points = D_801C26E4;
                    } else {
                        points = 10;
                    }
                    D_801C26E0 = 0;
                    D_801C39E8 = 1;
                    break;
                case 2:
                    if (D_801C39DC == 0) {
                        D_801C39DC = 1;
                        points = D_801C26E4;
                    } else {
                        points = 10;
                    }
                    D_801C26E0 = 0;
                    D_801C39EC = 1;
                    break;
                case 9:
                    if (D_801C39E0 == 0) {
                        D_801C39E0 = 1;
                        points = D_801C26E4;
                    } else {
                        points = 10;
                    }
                    D_801C26E0 = 0;
                    D_801C39F0 = 1;
                    break;
                case 11:
                    if (D_801C39E4 == 0) {
                        D_801C39E4 = 1;
                        points = D_801C26E4;
                    } else {
                        points = 10;
                    }
                    D_801C26E0 = 0;
                    D_801C39F8 = 1;
                    break;
            }
        } else if ((D_801C39C8 == 9) && (trick == 10)) {
            if (D_801C39E0 == 0) {
                D_801C39E0 = 1;
                points = D_801C26E4 + D_800D92BC.unk20;
            } else {
                points = 10;
            }
            D_801C26E0 = 0;
            D_801C39F0 = 1;
            D_801C39F4 = 1;
        }
        if (points > 0) {
            func_801FB488(2, points, 0);
            D_801C26E4 = 0;
        }
        if (D_801C26E0 == 0) {
            switch (trick) {
                case 1:
                    if (D_801C39C8 == 0) {
                        D_801C26E4 += D_800D92BC.unk0;
                    } else {
                        D_801C26E4 += D_800D92BC.unk4;
                    }
                    break;
                case 2:
                    if (D_801C39C8 == 0) {
                        D_801C26E4 += D_800D92BC.unk8;
                    } else {
                        D_801C26E4 += D_800D92BC.unkC;
                    }
                    break;
                case 3:
                case 4:
                    D_801C26E4 += D_800D92BC.unk10;
                    break;
                case 5:
                    D_801C26E4 += D_800D92BC.unk14;
                    break;
                case 9:
                    if (D_801C39C8 == 0) {
                        D_801C26E4 += D_800D92BC.unk18;
                    } else {
                        D_801C26E4 += D_800D92BC.unk1C;
                    }
                    break;
                case 11:
                    if (D_801C39C8 == 0) {
                        D_801C26E4 += D_800D92BC.unk24;
                    } else {
                        D_801C26E4 += D_800D92BC.unk28;
                    }
                    break;
                default:
                    D_801C26E4 = 0;
                    break;
            }
        } else if ((D_801C26E0 == 1) || (D_801C26E0 == 2)) {
            D_801C26E4 += D_800D92BC.unk10;
        } else if (D_801C26E0 == 3) {
            D_801C26E4 += D_800D92BC.unk14;
        }
        D_801C39C8 = trick;
    }
    // The record (buoy or gate) the rider heads for: passed once the rider is beyond it and
    // was behind it, through the gate for gates (unk9C).
    cur = rider->unkC;
    e = &D_801AEE20[cur];
    if (e->unk9C == 1) {
        dot = (e->unk78 * (D_801C3780 - e->unk18)) + ((D_801C3788 - e->unk20) * e->unk7C);
        inGate = (dot >= 0.0f) && (dot <= (2.0f * e->unk8C));
    }
    dx = D_801C3780 - e->unk0;
    dz = D_801C3788 - e->unk8;
    len = sqrtf((dx * dx) + (dz * dz));
    if (len > 0.0f) {
        dx /= len;
        dz /= len;
    }
    passed = false;
    dot = (e->unk70 * dx) + (e->unk74 * dz);
    if ((rider->unk1C == -1) && (dot > 0.0f)) {
        if (((e->unk74 * dx) - (e->unk70 * dz)) >= 0.0f) {
            rider->unk1C = 1;
        } else {
            rider->unk1C = 0;
        }
    } else if (dot <= 0.0f) {
        rider->unk1C = -1;
    }
    if ((rider->unk20 == 0) && (rider->unk1C == -1)) {
        rider->unk20 = 1;
    }
    rider->unk28 = 0;
    if ((rider->unk20 != 0) && (rider->unk1C >= 0)) {
        if ((e->unk9C == 1) && !inGate) {
            rider->unk20 = 0;
            rider->unk2F0 = 1;
        } else {
            passed = true;
            rider->unk2F0 = 0;
        }
    }
    if (passed) {
        rider->unk1C = -1;
        rider->unk20 = 1;
        rider->unkC = e->unkA0;
    }
    if (passed && (rider->unk2F4 == 0) && (rider->unk2EC == 0)) {
        // A checkpoint gate: its time (interpolated between this frame and the last), and the
        // time left as bonus points.
        if ((e->unk9C == 1) && (rider->lapCount > 0)) {
            if (cur != D_801BB12C) {
                D_801C39E4 = D_801C39E0 = D_801C39DC = D_801C39D8 = 0;
            }
            dPos = (e->unk70 * (D_801C3780 - e->unk0)) + ((D_801C3788 - e->unk8) * e->unk74);
            if (!(dPos >= 0.0f)) {
                dPos = -dPos;
            }
            dPrev = (e->unk70 * (D_80192690[arg0].unkBE4 - e->unk0)) +
                    ((D_80192690[arg0].unkBEC - e->unk8) * e->unk74);
            if (!(dPrev >= 0.0f)) {
                dPrev = -dPrev;
            }
            frac = (dPos / (dPos + dPrev)) * 50.0f;
            rider->unk1A4[rider->lapCount - 1][rider->unk164] = rider->unk19C - frac;
            rider->unk334 = 0;
            bonus = ((rider->unk2C4 + (frac / 2)) / 100) * D_800D92B8;
            if (bonus > 0) {
                func_801FB488(1, bonus, cur == D_801BB12C);
            }
            if (cur == D_801BB12C) {
                D_801C39D4 = bonus;
            }
            if (cur != D_801BB12C) {
                rider->unk2C4 = D_800D9280[(gCourseID * 4) + rider->unk164] * 1000;
                D_80228A94 = 20;
                AudioGeneral_PlaySound(0x33, 0);
            }
            rider->unk164++;
            if (e->unk98 == 3) {
                rider->unk164 = 0;
            }
        }
        // The start/finish line.
        if (cur == D_801BB12C) {
            if (rider->lapCount > 0) {
                rider->unk168 = frac;
                if ((rider->lapCount >= D_801CE728[0]) && (D_800D8178 == 0)) {
                    rider->unk2F4 = 1;
                    if (D_801C26E4 > 0) {
                        switch (trick) {
                            case 1:
                                D_801C39E8 = 1;
                                break;
                            case 2:
                                D_801C39EC = 1;
                                break;
                            case 9:
                                D_801C39F0 = 1;
                                break;
                            case 10:
                                D_801C39F0 = 1;
                                D_801C39F4 = 1;
                                break;
                            case 11:
                                D_801C39F8 = 1;
                                break;
                        }
                        if (((trick == 1) && (D_801C39D8 != 0)) || ((trick == 2) && (D_801C39DC != 0)) ||
                            ((trick == 9) && (D_801C39E0 != 0)) || ((trick == 10) && (D_801C39E0 != 0)) ||
                            ((trick == 11) && (D_801C39E4 != 0))) {
                            D_801C39CC = 10;
                        } else {
                            D_801C39CC = D_801C26E4;
                        }
                        D_801C39D0 = 20;
                        D_801C26E4 = 0;
                    } else {
                        D_801C39CC = 0;
                    }
                    if ((D_801C2930 == 0) && (gCourseID == DOLPHIN_PARK) && (D_801C292C >= D_801BB134) &&
                        (D_801C39E8 != 0) && (D_801C39EC != 0) && (D_801C39F0 != 0) && (D_801C39F4 != 0) &&
                        (D_801C39F8 != 0) && (D_801C39FC != 0) && (D_801C3A00 != 0) && (D_801C3A04 != 0)) {
                        D_801C2930 = 1;
                    }
                    laps = D_801CE728[0];
                    if (laps >= 10) {
                        laps = 9;
                    }
                    rider->unk19C = 0;
                    for (i = 0; i < laps; i++) {
                        rider->unk19C += rider->unk178[i];
                    }
                    D_801C2928 = 0;
                    if (D_801CE600 == 0) {
                        for (i = 0; i < 3; i++) {
                            if (D_801C26E8[gCourseID][i].score < D_801C26D0 + D_801C39CC + D_801C39D4) {
                                D_801C2928 = i + 1;
                                break;
                            }
                        }
                    }
                    sfx = 1;
                    if (D_801C2928 == 1) {
                        sfx = 0;
                    }
                    if ((D_800DAB60 == 0) && (D_801C2930 != 0)) {
                        sfx += 0x80;
                    }
                    func_800C1F60(6);
                    func_800C21F4(6, sfx);
                }
            }
            if ((D_800D8178 == 0) || (rider->lapCount == 0)) {
                if (rider->lapCount < D_801CE728[0]) {
                    rider->lapCount++;
                }
            }
            rider->unk320 = rider->lapCount;
            for (i = 1; i < D_801BB120; i++) {
                rider->unk2C[i] = 0;
            }
        }
        rider->unk2C[cur] = 1;
    }
    if ((D_801C2930 == 0) && (gCourseID == DOLPHIN_PARK) && (D_801C292C >= D_801BB134) && (D_801C39E8 != 0) &&
        (D_801C39EC != 0) && (D_801C39F0 != 0) && (D_801C39F4 != 0) && (D_801C39F8 != 0) && (D_801C39FC != 0) &&
        (D_801C3A00 != 0) && (D_801C3A04 != 0)) {
        D_801C2930 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_800783AC.s")
#endif

extern s32 D_801C1FD8;
extern s32 D_801C1FDC;
extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern s32 D_801C3990[];
extern s32 D_801C39CC;
extern u64 D_801C3A08;
extern UnkStruct_80228AE0 D_80228AE0[4];
extern s32 D_80228A9C;

void func_80076378(s32);
void func_8007687C(s32);
void func_800783AC(s32);
void func_800C3EF4(s32);
void func_801EF504(void);
void func_801F0E7C(void);
void func_801F23A0(void);
void func_801F8DD0(void);
void func_801F9EA0(void);
void func_801FC39C(void);
void Hud_UpdateStartCountdown(void);
void Hud_UpdateOffCourseCountdown(void);

// The checkpoint time of a rider for a lap and checkpoint. The original indexes unk1A4 with
// the lap minus 2 (row 0 is the time at the start of lap 2).
#define RIDER_CP_TIME(rider, lap, cp) ((rider)->unk1A4[(lap) - 2][cp])

#ifdef NON_MATCHING
// 3995: same blocks and calls. In the 2P gap loop the original reads D_800D48E0 / D_800D48DC
// again after the rider's stores and indexes with multu; elsewhere only register numbers and
// the scheduling of the D_801C3A08 stores differ.
void func_80079528(void) {
    s32 i;
    s32 j;
    s32 allClear;
    s32 place;
    s32 time;
    s32 other;
    s32 tmp;
    RiderStruct* rider;

    D_801C3A08 = osGetTime();
    if (gCurrentPauseMenuOption != -1) {
        return;
    }
    if (gGameModes == GMODE_STUNT) {
        for (i = 0; i < gRiders; i++) {
            func_80076378(i);
            func_800783AC(i);
        }
        allClear = true;
        for (i = 0; i < 4; i++) {
            if (D_80228AE0[i].unk0 != 0) {
                allClear = false;
                break;
            }
        }
        // A new stunt record.
        if ((D_801C1FD8 == 0) && (D_801C2938[D_800D48DC].unk2F4 != 0) && (D_801CE638 == 1) && (D_801CE600 == 0) &&
            (D_801C39CC == 0) && allClear) {
            D_801C1FD8 = 1;
            D_801C2928 = 0;
            for (i = 0; i < 3; i++) {
                if (D_801C26E8[gCourseID][i].score < D_801C26D0) {
                    D_801C2928 = i + 1;
                    for (j = 2; j > i; j--) {
                        D_801C26E8[gCourseID][j] = D_801C26E8[gCourseID][j - 1];
                    }
                    D_801C26E8[gCourseID][i].score = D_801C26D0;
                    D_801C26E8[gCourseID][i].rider = D_800DA9B0[0];
                    D_801C26E8[gCourseID][i].flag = D_801CB32C;
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < gRiders; i++) {
            func_80076378(i);
            func_8007687C(i);
        }
        // Riders who finished at once: the earlier unk19C gets the better unk32C, and a tie
        // goes to the rider ahead ("simultaneously goal").
        if ((D_801CE638 == 1) && (gGameModes == GMODE_CHAMPIONSHIP)) {
            for (i = 0; i < gRiders; i++) {
                if ((D_801C2938[i].unk2F4 != 0) && (D_801C2938[i].unk2EC == 0) && (D_801C2938[i].unk304 == 0)) {
                    D_801C2938[i].unk304 = 1;
                    for (j = 0; j < gRiders; j++) {
                        if ((D_801C2938[j].unk2F4 != 0) && (D_801C2938[j].unk2EC == 0) && (j != i)) {
                            if ((D_801C2938[i].unk32C < D_801C2938[j].unk32C) &&
                                (D_801C2938[i].unk19C < D_801C2938[j].unk19C)) {
                                tmp = D_801C2938[i].unk32C;
                                D_801C2938[i].unk32C = D_801C2938[j].unk32C;
                                D_801C2938[j].unk32C = tmp;
                            } else if ((D_801C2938[i].unk19C == D_801C2938[j].unk19C) &&
                                       (D_801C2938[i].racePosition < D_801C2938[j].racePosition) && (j != D_800D48DC)) {
                                D_801C2938[j].unk19C++;
                            }
                        }
                    }
                }
            }
        }
        // The human's finish with one player: best lap (D_801C22C0), the top three
        // (D_801C1FF0, with the checkpoint times of a new best in D_801C24A0), or
        // D_801C23B0 when D_800DAB68 is set.
        if (D_801C1FD8 == 0) {
            rider = &D_801C2938[D_800D48DC];
            if ((rider->unk2F4 != 0) && (D_801CE638 == 1) && (gPlayers == ONE_PLAYER) && (D_801CE600 == 0)) {
                D_801C1FD8 = 1;
                if (D_800DAB68 == 0) {
                    if (rider->unk170 < D_801C22C0[gCourseID].time) {
                        D_801C22C0[gCourseID].time = rider->unk170;
                        D_801C22C0[gCourseID].rider = D_800DA9B0[0];
                        D_801C22C0[gCourseID].flag = D_801CB32C;
                        D_801C22C0[gCourseID].difficulty = gDifficulty;
                        D_801C2654 = 1;
                    }
                    for (i = 0; i < 3; i++) {
                        if (rider->unk19C < D_801C1FF0[gCourseID][i].time) {
                            D_801C2650 = i + 1;
                            for (j = 2; j > i; j--) {
                                D_801C1FF0[gCourseID][j] = D_801C1FF0[gCourseID][j - 1];
                            }
                            D_801C1FF0[gCourseID][i].time = rider->unk19C;
                            D_801C1FF0[gCourseID][i].rider = D_800DA9B0[0];
                            D_801C1FF0[gCourseID][i].flag = D_801CB32C;
                            D_801C1FF0[gCourseID][i].difficulty = gDifficulty;
                            if (i + 1 == 1) {
                                for (j = 0; j < 9; j++) {
                                    D_801C24A0[gCourseID][j] = rider->unk1A4[j][0];
                                }
                            }
                            break;
                        }
                    }
                } else if (rider->unk19C < D_801C23B0[gCourseID].time) {
                    D_801C23B0[gCourseID].time = rider->unk19C;
                    D_801C23B0[gCourseID].rider = D_800DA9B0[0];
                    D_801C23B0[gCourseID].flag = D_801CB32C;
                    D_801C23B0[gCourseID].difficulty = gDifficulty;
                    D_801C2650 = 1;
                }
                D_801C2660[gCourseID] = D_801C2650;
                D_801C2690[gCourseID] = D_801C2654;
            }
        }
    }
    place = D_801C2938[D_800D48DC].racePosition;
    // While racing, the places follow unk32C ("rank value adjust").
    if ((D_801CE638 == 1) && (D_801C1FD4 == 0) && (gGameModeState == GMODE_STATE_STARTED) &&
        ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS))) {
        for (i = 0; i < gRiders; i++) {
            D_801C3990[i] = i;
        }
        for (i = 0; i < gRiders - 1; i++) {
            for (j = i + 1; j < gRiders; j++) {
                if (D_801C2938[D_801C3990[i]].unk32C < D_801C2938[D_801C3990[j]].unk32C) {
                    tmp = D_801C3990[i];
                    D_801C3990[i] = D_801C3990[j];
                    D_801C3990[j] = tmp;
                }
            }
        }
        for (i = 0; i < gRiders; i++) {
            D_801C2938[D_801C3990[i]].racePosition = i;
        }
    }
    // A checkpoint gap (unk2FC 10 asks for one): to the rider one place ahead for the
    // human, or to the human for a rider behind; unk2F8 is the gap, unk300 its timer.
    if (gGameModes == GMODE_CHAMPIONSHIP) {
        for (i = 0; i < gRiders; i++) {
            rider = &D_801C2938[i];
            if (rider->unk2FC == 10) {
                time = RIDER_CP_TIME(rider, rider->lapCount, rider->unk164);
                if ((i == D_800D48DC) && (rider->racePosition > 0)) {
                    for (j = 0; j < gRiders; j++) {
                        if (rider->racePosition - 1 == D_801C2938[j].racePosition) {
                            break;
                        }
                    }
                    other = RIDER_CP_TIME(&D_801C2938[j], rider->lapCount, rider->unk164);
                    if (other > 0) {
                        rider->unk2FC = 1;
                        rider->unk2F8 = time - other;
                        rider->unk300 = 40;
                        rider->unk33C = j;
                        if (rider->racePosition == 1) {
                            func_800C3EF4(-((rider->unk2F8 + 500) / 1000));
                        }
                    } else {
                        rider->unk2FC = 0;
                    }
                } else if ((i != D_800D48DC) && (D_801C2938[D_800D48DC].racePosition < rider->racePosition)) {
                    other = RIDER_CP_TIME(&D_801C2938[D_800D48DC], rider->lapCount, rider->unk164);
                    if (other > 0) {
                        rider->unk2FC = 1;
                        rider->unk2F8 = time - other;
                        rider->unk300 = 40;
                        if ((D_801C2938[D_800D48DC].racePosition == 0) && (rider->racePosition == 1)) {
                            func_800C3EF4((rider->unk2F8 + 500) / 1000);
                        }
                    } else {
                        rider->unk2FC = 0;
                    }
                } else {
                    rider->unk2FC = 0;
                }
            }
        }
    } else if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gRiders; i++) {
            if (D_801C2938[i].unk2FC == 10) {
                if (D_801C2938[i].racePosition == 1) {
                    time = RIDER_CP_TIME(&D_801C2938[i], D_801C2938[i].lapCount, D_801C2938[i].unk164);
                    if (i == D_800D48DC) {
                        other = RIDER_CP_TIME(&D_801C2938[D_800D48E0], D_801C2938[i].lapCount, D_801C2938[i].unk164);
                        if (other == 0) {
                            other = time;
                        }
                        D_801C2938[i].unk2FC = 1;
                        D_801C2938[i].unk2F8 = time - other;
                        D_801C2938[i].unk300 = 40;
                        D_801C2938[D_800D48E0].unk2FC = 2;
                        D_801C2938[D_800D48E0].unk2F8 = time - other;
                        D_801C2938[D_800D48E0].unk300 = 40;
                        func_800C3EF4(-((D_801C2938[i].unk2F8 + 500) / 1000));
                    } else {
                        other = RIDER_CP_TIME(&D_801C2938[D_800D48DC], D_801C2938[i].lapCount, D_801C2938[i].unk164);
                        if (other == 0) {
                            other = time;
                        }
                        D_801C2938[i].unk2FC = 1;
                        D_801C2938[i].unk2F8 = time - other;
                        D_801C2938[i].unk300 = 40;
                        D_801C2938[D_800D48DC].unk2FC = 2;
                        D_801C2938[D_800D48DC].unk2F8 = time - other;
                        D_801C2938[D_800D48DC].unk300 = 40;
                        func_800C3EF4(-((D_801C2938[i].unk2F8 + 500) / 1000));
                    }
                } else {
                    D_801C2938[i].unk2FC = 0;
                }
            }
        }
    }
    if ((gGameModes == GMODE_2P_VS) && (D_801CE638 == 1)) {
        if (D_801C1FD4 == 0) {
            if (D_801C2938[D_800D48DC].unk2F4 != 0) {
                if (D_801C2938[D_800D48E0].unk2F4 != 0) {
                    D_801C1FD4 = 1;
                    if (D_801C2938[D_800D48E0].unk19C >= D_801C2938[D_800D48DC].unk19C) {
                        D_801C2938[D_800D48DC].racePosition = 0;
                        D_801C2938[D_800D48E0].racePosition = 1;
                    } else {
                        D_801C2938[D_800D48DC].racePosition = 1;
                        D_801C2938[D_800D48E0].racePosition = 0;
                    }
                }
            }
        }
        if ((D_801C1FD8 == 0) &&
            ((D_801C2938[D_800D48DC].unk2F4 != 0) || (D_801C2938[D_800D48DC].unk2EC != 0) ||
             (D_801C2938[D_800D48E0].unk2F4 != 0) || (D_801C2938[D_800D48E0].unk2EC != 0))) {
            D_801C1FD8 = 1;
        }
    }
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (place != D_801C2938[D_800D48DC].racePosition)) {
        D_80228A9C = 1;
    }
    if ((D_801CE638 == 1) && (gGameModes == GMODE_2P_VS)) {
        func_80078264();
    }
    D_801C3A08 = osGetTime() - D_801C3A08;
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (D_801C2938[D_800D48DC].unk2F4 != 0) && (D_801C1FDC < 0x7FFFFFFF)) {
        D_801C1FDC++;
    }
    func_801FC39C();
    func_801EF504();
    func_801F23A0();
    if ((D_801C2938[D_800D48DC].unk2EC == 0) &&
        ((gPlayers != TWO_PLAYERS) || (D_801C2938[D_800D48E0].unk2EC == 0)) && (D_801CE628 == 0)) {
        Hud_UpdateStartCountdown();
    }
    func_801F8DD0();
    func_801F9EA0();
    func_801F0E7C();
    Hud_UpdateOffCourseCountdown();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80079528.s")
#endif
