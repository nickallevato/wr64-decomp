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
// 4195: same blocks and calls. With the FAKE empty if below, x, z and the distances stay on the
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
        rider = &D_801C2938[arg0];
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
        rider = &D_801C2938[arg0];
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
        rider = &D_801C2938[arg0];
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_8007687C.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_800783AC.s")

extern s32 D_801C1FD8;
extern s32 D_801C1FDC;
extern s32 D_801C2650;
extern s32 D_801C2654;
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern s32 D_801C3990[];
extern s32 D_801C39CC;
extern u64 D_801C3A08;
extern s16 D_801CE628;
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
// 11395: same blocks and calls. Register allocation differs throughout; the original spills the
// gGameModes value to the stack across the calls, keeps the D_800D48DC address in a register
// in the gap loops; this C is 4 instructions longer.
void func_80079528(void) {
    s32 i;
    s32 j;
    s32 allClear;
    s32 place;
    s32 time;
    s32 other;
    s32 tmp;
    RiderStruct* rider;
    RiderStruct* rider2;

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
                rider = &D_801C2938[i];
                if ((rider->unk2F4 != 0) && (rider->unk2EC == 0) && (rider->unk304 == 0)) {
                    rider->unk304 = 1;
                    for (j = 0; j < gRiders; j++) {
                        rider2 = &D_801C2938[j];
                        if ((rider2->unk2F4 != 0) && (rider2->unk2EC == 0) && (j != i)) {
                            if ((rider->unk32C < rider2->unk32C) && (rider->unk19C < rider2->unk19C)) {
                                tmp = rider->unk32C;
                                rider->unk32C = rider2->unk32C;
                                rider2->unk32C = tmp;
                            } else if ((rider->unk19C == rider2->unk19C) &&
                                       (rider->racePosition < rider2->racePosition) && (j != D_800D48DC)) {
                                rider2->unk19C++;
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
            rider = &D_801C2938[i];
            if (rider->unk2FC == 10) {
                if (rider->racePosition == 1) {
                    time = RIDER_CP_TIME(rider, rider->lapCount, rider->unk164);
                    if (i == D_800D48DC) {
                        other = RIDER_CP_TIME(&D_801C2938[D_800D48E0], rider->lapCount, rider->unk164);
                        if (other == 0) {
                            other = time;
                        }
                        rider->unk2FC = 1;
                        rider->unk2F8 = time - other;
                        rider->unk300 = 40;
                        rider2 = &D_801C2938[D_800D48E0];
                        rider2->unk2FC = 2;
                        rider2->unk2F8 = time - other;
                        rider2->unk300 = 40;
                        func_800C3EF4(-((rider->unk2F8 + 500) / 1000));
                    } else {
                        other = RIDER_CP_TIME(&D_801C2938[D_800D48DC], rider->lapCount, rider->unk164);
                        if (other == 0) {
                            other = time;
                        }
                        rider->unk2FC = 1;
                        rider->unk2F8 = time - other;
                        rider->unk300 = 40;
                        rider2 = &D_801C2938[D_800D48DC];
                        rider2->unk2FC = 2;
                        rider2->unk2F8 = time - other;
                        rider2->unk300 = 40;
                        func_800C3EF4(-((rider->unk2F8 + 500) / 1000));
                    }
                } else {
                    rider->unk2FC = 0;
                }
            }
        }
    }
    if ((gGameModes == GMODE_2P_VS) && (D_801CE638 == 1)) {
        if (D_801C1FD4 == 0) {
            rider = &D_801C2938[D_800D48DC];
            if (rider->unk2F4 != 0) {
                rider2 = &D_801C2938[D_800D48E0];
                if (rider2->unk2F4 != 0) {
                    D_801C1FD4 = 1;
                    if (rider2->unk19C >= rider->unk19C) {
                        rider->racePosition = 0;
                        rider2->racePosition = 1;
                    } else {
                        rider->racePosition = 1;
                        rider2->racePosition = 0;
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
