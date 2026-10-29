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

extern s32 gPlayer2Rider;
extern UnkStruct_801C1FF0 gBestTimes[][3];
extern UnkStruct_801C1FF0 gBestLaps[];
extern UnkStruct_801C1FF0 D_801C23B0[];
extern s32 gBestCheckpointTimes[][9];
extern UnkStruct_801C26E8 gStuntRecords[][3];

extern UnkStruct_801AEE20 D_801AEE20[];
extern s32 D_801BB120;
extern RiderStruct gRiderRaceState[];

static const char devstr1[] = "dolphin condition full at goal\n";
static const char devstr2[] = "dolphin condition full\n";
static const char devstr3[] = "rank value adjust\n";
static const char devstr4[] = "simultaneously goal !!\n";

extern UnkStruct_801BB138 gCoursePoints[];
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
extern f32 gMapHalfSize;
extern f32 gMapScale;
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

// The end of code_2FB10's .bss, defined here (the yaml splits it from bss2 at 0x801C3A00; the section is
// 16-aligned). Defined, not extern, the two halves of a D_801C3A08 store share one lui, as in the original.
s32 D_801C3A00;
s32 D_801C3A04;
u64 D_801C3A08;

void func_801EED70(void);

#ifdef NON_MATCHING
// Score 7065 of 97200: same blocks, loops and calls. -1 sits in ra here (t5 in the original) and most
// registers are renamed from the extent loops on; the original stores gMapHalfSize with lui at in the
// extent loops, and does not unroll the 8-step checkpointTimes loop (unrolled here).
void func_80075310(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 depth;
    s32 n;
    s32 type;
    f32 x;
    f32 z;
    f32 a;
    RiderStruct* rider;

    // First call: the default records of slots 9 to 11.
    if (D_800D8224 != 0) {
        D_800D8224 = 0;
        for (i = 9; i < 12; i++) {
            for (j = 0; j < 3; j++) {
                gBestTimes[i][j] = D_800D81B0;
            }
            gBestLaps[i] = D_800D81B0;
            for (j = 0; j < 9; j++) {
                gBestCheckpointTimes[i][j] = -1;
            }
            D_801C23B0[i] = D_800D81B0;
        }
        for (i = 9; i < 12; i++) {
            for (j = 0; j < 3; j++) {
                gStuntRecords[i][j] = D_800D81C4;
            }
        }
        for (i = 0; i < 4; i++) {
            D_801C26C0[i] = 3 - i;
        }
    }

    // The course's extent from both buoy tables: the bounding box and the largest |x| or |z|
    // (at least 4096), and from them the map scale.
    D_801C1FC4 = 0;
    D_801C1F9C = D_801C1FA4 = 32767.0f;
    D_801C1FA0 = D_801C1FA8 = -32768.0f;
    gMapHalfSize = 0; // int 0: a separate zero from the loops' 0.0f
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
        if (gMapHalfSize < a) {
            gMapHalfSize = a;
        }
        a = (z >= 0.0f) ? z : -z;
        if (gMapHalfSize < a) {
            gMapHalfSize = a;
        }
    }
    for (i = 0; i < D_801BC938; i++) {
        x = gCoursePoints[i].unk0;
        if (x < D_801C1F9C) {
            D_801C1F9C = x;
        }
        if (D_801C1FA0 < x) {
            D_801C1FA0 = x;
        }
        z = gCoursePoints[i].unk8;
        if (z < D_801C1FA4) {
            D_801C1FA4 = z;
        }
        if (D_801C1FA8 < z) {
            D_801C1FA8 = z;
        }
        a = (x >= 0.0f) ? x : -x;
        if (gMapHalfSize < a) {
            gMapHalfSize = a;
        }
        a = (z >= 0.0f) ? z : -z;
        if (gMapHalfSize < a) {
            gMapHalfSize = a;
        }
    }
    if (gMapHalfSize < 4096.0f) {
        gMapHalfSize = 4096.0f;
        D_801C1F9C = -4096.0f;
        D_801C1FA4 = -4096.0f;
        D_801C1FA0 = -D_801C1F9C;
        D_801C1FA8 = -D_801C1FA4;
    }
    D_801C1FAC = D_801C1FA0 - D_801C1F9C;
    D_801C1FB0 = D_801C1FA8 - D_801C1FA4;
    gMapScale = 160.0f / (2.0f * gMapHalfSize);
    D_801C1FB4 = (gMapHalfSize * 1.4142f) + 2048.0f;

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
        rider = &gRiderRaceState[i];
        rider->unk174 = 0;
        rider->lapCount = 0;
        rider->racePosition = 0;
        rider->unk324 = 0;
        rider->unk8 = 0;
        rider->unk320 = 0;
        rider->progress = 0; // int 0, as gMapHalfSize
        rider->unkC = rider->unk10 = rider->nearestRecord = D_801BB12C;
        rider->unk1C = -1;
        rider->unk20 = 0;
        rider->unk24 = 0;
        rider->unk28 = 0;
        if ((gCourseID == DOLPHIN_PARK) || (gGameModes == GMODE_STUNT)) {
            rider->power = 5;
        } else {
            rider->power = 0;
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
        rider->checkpointGap = 0;
        rider->gapTimer = 0;
        rider->gapRequest = 0;
        rider->unk2C8 = 0;
        rider->unk2E0 = 0;
        rider->unk2DC = 0;
        rider->unk2D8 = 0;
        rider->unk2D0 = 0;
        rider->unk328 = 0;
        rider->unk2E8 = 0;
        rider->unk2E4 = 0;
        rider->unk334 = 0;
        rider->finishState = 0;
        rider->unk2F0 = 0;
        rider->unk2F4 = 0;
        rider->unk304 = 0;
        for (j = 0; j < D_801BB120; j++) {
            rider->unk2C[j] = 0;
        }
        rider->lapTime = 0;
        rider->unk16C = 0;
        rider->raceTime = 0;
        rider->bestLapTime = 599999;
        rider->timeLeft = D_800D9280[gCourseID * 4] * 1000;
        for (j = 0; j < 9; j++) {
            rider->lapBuoyMisses[j] = 0;
            rider->lapTimes[j] = 0;
            for (k = 0; k < 8; k++) {
                rider->checkpointTimes[j][k] = 0;
            }
        }
        rider->unk330 = 0.0f;
        rider->unk308 = 0;
        rider->unk30C = 0;
        rider->inBox = 0;
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
            rider->unkC = rider->nearestRecord = k;
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
    D_801C1FD8 = D_801C1FD4 = 0;
    D_801C1FDC = 0;
    D_801C39C4 = D_800D8180[gCourseID];
    if (gDifficulty == DIFFICULTY_NORMAL) {
        D_801C39B8 = 0;
    } else if (gDifficulty == DIFFICULTY_HARD) {
        D_801C39B8 = 4;
    } else {
        D_801C39B8 = 5;
    }
    D_801C1FD0 = D_801C1FCC = D_801C1FC8 = 0;
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
        D_801C3A00 = 0;
        D_801C39FC = D_801C3A00;
        D_801C39C8 = 0;
        D_801C3A04 = 0;
        D_801C292C = 0;
    }
    D_801C39B0 = 100000.0f;
    D_801C39B4 = -100000.0f;
    D_801C2928 = D_801C2658 = D_801C2654 = D_801C2650 = 0;
    if (D_800DAB68 == 0) {
        D_801C1FE4 = gBestTimes[gCourseID][0].time;
        D_801C1FE8 = D_801C1FE0 = gBestLaps[gCourseID].time;
    } else {
        D_801C1FE4 = D_801C23B0[gCourseID].time;
        D_801C1FE8 = D_801C1FE0 = 0;
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
        if ((i < gRiders) && (i != gPlayer1Rider)) {
            D_801C26C0[i] = D_801C26C0[gPlayer1Rider];
            D_801C26C0[gPlayer1Rider] = D_800D8228 - 1;
        }
    }
    if (gCourseID != DOLPHIN_PARK) {
        for (i = 0; i < gRiders; i++) {
            gRiderRaceState[i].racePosition = D_801C26C0[i];
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

void Rider_SetFinishState(struct_800762D0* arg0) {
    if (D_801CE638 == 1) {
        if ((gGameModes == GMODE_STUNT) && (arg0->timeLeft <= 0)) {
            arg0->finishState = 2;
        } else if (arg0->raceTime >= 599999) {
            arg0->finishState = 2;
        } else {
            arg0->finishState = 1;
        }
        if ((gGameModes != GMODE_2P_VS) || (arg0->finishState != 2)) {
            arg0->progress = D_801C39B4;
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
// Score 1232 of 32100: same blocks and calls. The zone test as if / else if, the Drake Lake count and player as
// if / else give the original's branches; the Drake Lake loop counts with best and keeps its bound in wasIn (both
// reused; the permuter found them, and with them the int registers match, except wasIn's). Left: the frame is 0x90,
// not 0x88 (isHuman and rider spill to new slots below the declared ones, where the original spills them to slots of
// their own among them), d is not stored, and the float registers of the nearest-record and Drake Lake blocks differ.
void func_80076378(s32 arg0) {
    s32 prev;
    s32 next;
    f32 dx0;
    f32 dz0;
    f32 dxp;
    s32 cur;
    s32 best;
    s32 zoneA;
    s32 zoneB;
    s32 zoneC;
    s32 zoneD;
    f32 bestDist;
    f32 dzp;
    f32 dxn;
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

    rider = &gRiderRaceState[arg0];
    if (D_801CE638 == 2) {
        D_801C3780 = D_801C3720[arg0].unk0;
        D_801C3784 = 0.0f;
        D_801C3788 = D_801C3720[arg0].unk8;
    } else {
        D_801C3780 = D_80192690[arg0].unk44.x;
        D_801C3784 = D_80192690[arg0].unk44.y;
        D_801C3788 = D_80192690[arg0].unk44.z;
    }
    isHuman = (arg0 == gPlayer1Rider) || ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider));
    if (D_801CE638 == 1) {
        cur = rider->nearestRecord;
        best = cur;
        x = D_801C3780;
        z = D_801C3788;
        prev = D_801AEE20[cur].unkA8;
        next = D_801AEE20[cur].unkA0;
        dx0 = D_801AEE20[cur].unk0 - x;
        dzp = D_801AEE20[prev].unk8 - z;
        dxp = D_801AEE20[prev].unk0 - x;
        dz0 = D_801AEE20[cur].unk8 - z;
        dxn = D_801AEE20[next].unk0 - x;
        dzn = D_801AEE20[next].unk8 - z;
        bestDist = (dx0 * dx0) + (dz0 * dz0);
        d = (dxp * dxp) + (dzp * dzp);
        if (d < bestDist) {
            bestDist = d;
            if (cur && cur && cur) {} // FAKE: keeps x, z and d on the stack, as in the original
            best = prev;
        }
        if (((dxn * dxn) + (dzn * dzn)) < bestDist) {
            best = next;
        }
        func_80074368(x, z, &zoneA, &zoneB);
        if (cur != best) {
            func_80074368(D_801AEE20[best].unk0, D_801AEE20[best].unk8, &zoneC, &zoneD);
            if ((zoneA != -1) && ((zoneA == zoneC) || (zoneA == zoneD))) {
                rider->nearestRecord = best;
            } else if ((zoneB != -1) && ((zoneB == zoneC) || (zoneB == zoneD))) {
                rider->nearestRecord = best;
            }
        }
    }
    if (gCourseID == DRAKE_LAKE) {
        rider->unk318 = 0;
        if (gDifficulty < 2) {
            wasIn = 3;
        } else {
            wasIn = 6;
        }
        for (best = 0; best < wasIn; best++) {
            if (!(D_801C3784 > 40.0f)) {
                dx = D_801C3780 - D_800D81D4[best].x;
                dz = D_801C3788 - D_800D81D4[best].z;
                if (((dx * dx) + (dz * dz)) <= 22500.0f) {
                    rider->unk318 = 1;
                    break;
                }
            }
        }
    }
    if ((gCourseID == PORT_BLUE) || (gCourseID == TWILIGHT_CITY)) {
        wasIn = rider->inBox;
        if (gCourseID == PORT_BLUE) {
            rect = &D_800D8204;
        } else {
            rect = &D_800D8214;
        }
        if ((rect->minX <= D_801C3780) && (D_801C3780 <= rect->maxX) && (rect->minZ <= D_801C3788) &&
            (D_801C3788 <= rect->maxZ)) {
            rider->inBox = 1;
        } else {
            rider->inBox = 0;
        }
        if (isHuman && (wasIn != rider->inBox)) {
            if (arg0 == gPlayer1Rider) {
                player = 0;
            } else {
                player = 1;
            }
            if (rider->inBox != 0) {
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
extern s32 D_80228A98;
extern f32 D_801C39A0[];

void func_800C1B30(void);
void func_800C1EB8(s32);

#ifdef NON_MATCHING
// Score 43461 of 146400: same blocks and calls, 4 instructions shorter; register allocation and scheduling differ
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

    if (arg0 == gPlayer1Rider) {
        D_801C2658 = 0;
    }
    isHuman = (arg0 == gPlayer1Rider) || ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider));
    rider = &gRiderRaceState[arg0];
    rider->unk314 = 0;
    if (rider->gapTimer != 0) {
        rider->gapTimer--;
    }
    if ((gCourseID == DRAKE_LAKE) && (D_801C1FD0 == 0) && isHuman && (rider->raceTime >= 50001)) {
        D_801C1FD0 = 1;
    }
    if (gCourseID == GLACIER_COAST) {
        if (D_801C1FCC >= 2) {
            rider->unk350 = (struct UnkStruct_801C3C54*) D_801B7020;
        } else if (D_801C1FCC > 0) {
            rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
        }
    }
    if ((gCourseID == RIDER_SELECTION) && (arg0 == gPlayer2Rider)) {
        rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
    }
    if (((D_801CE628 == 1) && (arg0 == gPlayer1Rider)) ||
        ((gPlayers == TWO_PLAYERS) && (D_801CE628 == 2) && (arg0 == gPlayer2Rider))) {
        if (rider->finishState == 0) {
            Rider_SetFinishState((struct_800762D0*) rider);
        }
        return;
    }
    // The race clock; 9'59"99 retires (except in Dolphin Park).
    if ((D_801CE638 == 1) && (rider->unk2F4 == 0) && (rider->finishState == 0) && (D_800D817C == 0) && (D_801C1FD4 == 0)) {
        rider->lapTime += 50;
        if (rider->lapTime >= 599999) {
            rider->lapTime = 599999;
        }
        rider->raceTime += 50;
        if (rider->raceTime >= 599999) {
            rider->raceTime = 599999;
            if (gCourseID != DOLPHIN_PARK) {
                Rider_SetFinishState((struct_800762D0*) rider);
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
        if ((e->unk9C == 0) && (rider->unk2F4 == 0) && (rider->finishState == 0) && (type != 8) && (type != 9)) {
            if (((type == 0) && (rider->unk1C == 0)) || ((type == 1) && (rider->unk1C == 1))) {
                if (e->unkC8 != 0) {
                    if (rider->power < 5) {
                        rider->power++;
                        rider->unk314 = 1;
                    }
                    rider->unk28 = 1;
                    if (isHuman) {
                        if ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider)) {
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
                        Rider_SetFinishState((struct_800762D0*) rider);
                    }
                }
                rider->unk28 = 2;
                if (isHuman) {
                    sfx = gBuoyMisses - rider->unk134;
                    if (sfx < 0) {
                        sfx = 0;
                    }
                    if ((gPlayers == TWO_PLAYERS) && (arg0 == gPlayer2Rider)) {
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
            rider->nearestRecord = cur;
        }
        rider->unk1C = -1;
        rider->unk20 = 1;
        // Marine Fortress, above normal difficulty: once, near the type 2 object, a sound cue.
        if ((gCourseID == MARINE_FORTRESS) && (gDifficulty > 0) && (D_801C1FC8 == 0) && (rider->lapCount >= 2) &&
            (((D_800DAB68 == 0) && (e->unk98 == 6)) || (D_800DAB68 != 0))) {
            D_801C1FC8 = 1;
            dx = D_801BC940[D_801C39C0].unk0 - gCameraPerspective[D_80223930].eyeX;
            dz = D_801BC940[D_801C39C0].unk8 - gCameraPerspective[D_80223930].eyeZ;
            if (((dx * dx) + (dz * dz)) < 1.6e7f) {
                func_800C1B30();
            } else if (gPlayers == TWO_PLAYERS) {
                dx = D_801BC940[D_801C39C0].unk0 - gCameraPerspective[D_80223934].eyeX;
                dz = D_801BC940[D_801C39C0].unk8 - gCameraPerspective[D_80223934].eyeZ;
                if (((dx * dx) + (dz * dz)) < 1.6e7f) {
                    func_800C1B30();
                }
            }
        }
    }
    if (passed && (rider->unk13C == 0) && (rider->unk2F4 == 0) && (rider->finishState == 0) && (gCourseID != DOLPHIN_PARK)) {
        // A checkpoint gate: its time, and the gap shown against the time trial record
        // (gBestCheckpointTimes) or, in a race, asked of func_80079528 (gapRequest 10).
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
            time = rider->raceTime - frac;
            rider->checkpointTimes[rider->lapCount - 1][rider->unk164] = time;
            if ((D_801CE638 == 1) && (D_801C1FC4 == 0) && (D_801C1FD8 == 0) &&
                ((cur != D_801BB12C) || (rider->lapCount < D_801CE728[0]))) {
                if ((gGameModes == GMODE_TIME_TRIALS) && (D_800DAB68 == 0) && (cur == D_801BB12C) &&
                    (rider->lapCount < 3)) {
                    ref = gBestCheckpointTimes[gCourseID][rider->lapCount - 1];
                    if (ref > 0) {
                        if (ref < time) {
                            rider->gapRequest = 1;
                            rider->checkpointGap = time - ref;
                        } else {
                            rider->gapRequest = 2;
                            rider->checkpointGap = ref - time;
                        }
                        rider->gapTimer = 40;
                    }
                } else if ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS)) {
                    rider->gapRequest = 10;
                } else {
                    rider->gapRequest = 0;
                }
            }
        }
        // The line: the lap time and best lap, lap sounds, the last lap.
        if (cur == D_801BB12C) {
            if (rider->lapCount > 0) {
                rider->lapTime -= frac;
                if (D_801CE638 == 1) {
                    if (rider->lapCount < 10) {
                        rider->lapTimes[rider->lapCount - 1] = rider->lapTime;
                        rider->lapBuoyMisses[rider->lapCount - 1] = rider->unk130;
                    } else {
                        for (i = 0; i < 8; i++) {
                            rider->lapTimes[i] = rider->lapTimes[i + 1];
                            rider->lapBuoyMisses[i] = rider->lapBuoyMisses[i + 1];
                        }
                        rider->lapTimes[8] = rider->lapTime;
                        rider->lapBuoyMisses[8] = rider->unk130;
                    }
                    if (rider->lapTime < rider->bestLapTime) {
                        rider->bestLapTime = rider->lapTime;
                        rider->unk174 = rider->lapCount;
                    }
                    if ((gPlayers == ONE_PLAYER) && (arg0 == gPlayer1Rider)) {
                        if (rider->bestLapTime < D_801C1FE0) {
                            D_801C1FE0 = rider->bestLapTime;
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
                            if ((gGameModes == GMODE_TIME_TRIALS) && (rider->gapRequest == 2)) {
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
                rider->lapTime = frac;
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
                    rider->progress = D_801C39B0;
                    D_801C39B0 -= 10000.0f;
                    laps = D_801CE728[0];
                    if (laps >= 10) {
                        laps = 9;
                    }
                    rider->raceTime = 0;
                    for (i = 0; i < laps; i++) {
                        rider->raceTime += rider->lapTimes[i];
                    }
                    if (!isHuman) {
                        rider->power = 0;
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
    if (rider->power != rider->unk138) {
        if (rider->power - rider->unk138 == 0) {
            i = 0;
        } else if (rider->power - rider->unk138 > 0) {
            i = 1;
        } else {
            i = -1;
        }
        rider->unk138 += i;
    }
    if ((D_801CE638 != 1) || (gCourseID == DOLPHIN_PARK)) {
        rider->unk8 = 0;
        rider->progress = 0.0f;
        D_801C39A0[arg0] = 0.0f;
    }

    // Crossing the line backwards or forwards near it (within one record of it, four on
    // Sunset Bay) moves the lap counter unk320.
    r1 = D_801AEE20[rider->nearestRecord].unkA0;
    r2 = D_801AEE20[r1].unkA0;
    r3 = D_801AEE20[r2].unkA0;
    beyond = false;
    if (((D_801AEE20[D_801BB12C].unk74 * (D_801C3788 - D_801AEE20[D_801BB12C].unk8)) +
         ((D_801C3780 - D_801AEE20[D_801BB12C].unk0) * D_801AEE20[D_801BB12C].unk70)) > 0.0f) {
        beyond = true;
    }
    nearLine = (D_801BB12C == rider->nearestRecord) || (r1 == D_801BB12C);
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

    // Progress: the last record the rider is past (walking back from nearestRecord), and how far along
    // the segment to the next one; progress orders the riders.
    r = rider->nearestRecord;
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
    if ((rider->unk2F4 == 0) && (rider->finishState == 0)) {
        rider->progress = ((rider->unk320 * 1000) + (r * 10)) + len;
        D_801C39A0[arg0] = progress;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_8007687C.s")
#endif

extern s32 D_801C1FD4;

void Race_RankUnfinishedRiders(void) {
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
        for (i = 0, rider = gRiderRaceState; i < gRiders; i++, rider++) {
            if ((rider->unk2F4 == 0) && (rider->finishState == 0)) {
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
                rider->raceTime += (dist / (speed / 1.8f)) * 50.0f;
            }
        }
        for (i = 0; i < gRiders; i++) {
            if (gRiderRaceState[i].raceTime >= 600000) {
                gRiderRaceState[i].raceTime = 599999;
            }
            if ((gRiderRaceState[i].unk2F4 == 0) && (gRiderRaceState[i].finishState == 0)) {
                for (j = 0; j < gRiders; j++) {
                    if ((gRiderRaceState[j].unk2F4 == 0) && (gRiderRaceState[j].finishState == 0) && (j != i)) {
                        if ((gRiderRaceState[i].racePosition < gRiderRaceState[j].racePosition) &&
                            (gRiderRaceState[j].raceTime < gRiderRaceState[i].raceTime)) {
                            lap = gRiderRaceState[i].racePosition;
                            gRiderRaceState[i].racePosition = gRiderRaceState[j].racePosition;
                            gRiderRaceState[j].racePosition = lap;
                        }
                    }
                }
            }
        }
        if (gCourseID != DOLPHIN_PARK) {
            for (i = 0; i < gRiders; i++) {
                D_801C26C0[i] = gRiderRaceState[i].racePosition;
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
    temp_v1 = &gRiderRaceState[gPlayer1Rider];
    temp_a0 = &gRiderRaceState[gPlayer2Rider];
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
extern s32 D_801BB134;
extern s32 D_80228A94;

void func_801FB488(s32 arg0, s32 arg1, s32 arg2);

#ifdef NON_MATCHING
// Score 24854 of 111900: same blocks, switches and calls. Register allocation differs from the start (the
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

    if (arg0 != gPlayer1Rider) {} // an empty test, as in the original
    rider = &gRiderRaceState[arg0];
    rider->unk314 = 0;
    if ((gCourseID == RIDER_SELECTION) && (arg0 == gPlayer2Rider)) {
        rider->unk350 = (struct UnkStruct_801C3C54*) D_801B2F20;
    }
    if (((D_801CE628 == 1) && (arg0 == gPlayer1Rider)) ||
        ((gPlayers == TWO_PLAYERS) && (D_801CE628 == 2) && (arg0 == gPlayer2Rider))) {
        if (rider->finishState == 0) {
            Rider_SetFinishState((struct_800762D0*) rider);
        }
        return;
    }
    // The points of the last trick, shown when its timer runs out.
    if ((D_801C39D0 > 0) && (--D_801C39D0 <= 0)) {
        func_801FB488(2, D_801C39CC, 1);
        D_801C39CC = 0;
    }
    // The clock: race time up, time left (timeLeft) down; out of time and slow, or out of
    // time for 200 frames, retires.
    if ((rider->unk2F4 == 0) && (rider->finishState == 0) && (D_800D817C == 0) && (D_801C1FD4 == 0)) {
        rider->lapTime += 50;
        if (rider->lapTime >= 299999) {
            rider->lapTime = 299999;
        }
        rider->raceTime += 50;
        if (rider->raceTime >= 299999) {
            rider->raceTime = 299999;
        }
        rider->unk16C = D_800D4B00 & 0xFFFF;
        rider->timeLeft -= 50;
        if (rider->timeLeft <= 0) {
            rider->timeLeft = 0;
        }
        if (rider->timeLeft > 0) {
            rider->unk334 = 0;
        } else {
            rider->unk334++;
            if (((D_80192690[arg0].unkB90 * 1.8f) < 10.0f) || (rider->unk334 >= 201)) {
                Rider_SetFinishState((struct_800762D0*) rider);
            }
        }
    }
    // unk138 follows power one step a frame.
    if (rider->power != rider->unk138) {
        if (rider->power - rider->unk138 == 0) {
            i = 0;
        } else if (rider->power - rider->unk138 > 0) {
            i = 1;
        } else {
            i = -1;
        }
        rider->unk138 += i;
    }
    // Trick points (D_801C26E4) from the craft's trick state unk1604.
    if ((rider->unk2F4 == 0) && (rider->finishState == 0)) {
        points = 0;
        trick = D_80192690[arg0].unk1604;
        if (trick == 3) {
            D_801C26E0 = 1;
        } else if (trick == 4) {
            D_801C26E0 = 2;
        } else if (trick == 5) {
            D_801C26E0 = 3;
        } else if (trick == 6) {
            points = D_80192690[gPlayer1Rider].unk15EC * 14.3f;
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
            points = D_80192690[gPlayer1Rider].unk15EC * 7.15f;
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
    if (passed && (rider->unk2F4 == 0) && (rider->finishState == 0)) {
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
            rider->checkpointTimes[rider->lapCount - 1][rider->unk164] = rider->raceTime - frac;
            rider->unk334 = 0;
            bonus = ((rider->timeLeft + (frac / 2)) / 100) * D_800D92B8;
            if (bonus > 0) {
                func_801FB488(1, bonus, cur == D_801BB12C);
            }
            if (cur == D_801BB12C) {
                D_801C39D4 = bonus;
            }
            if (cur != D_801BB12C) {
                rider->timeLeft = D_800D9280[(gCourseID * 4) + rider->unk164] * 1000;
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
                rider->lapTime = frac;
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
                    rider->raceTime = 0;
                    for (i = 0; i < laps; i++) {
                        rider->raceTime += rider->lapTimes[i];
                    }
                    D_801C2928 = 0;
                    if (D_801CE600 == 0) {
                        for (i = 0; i < 3; i++) {
                            if (gStuntRecords[gCourseID][i].score < D_801C26D0 + D_801C39CC + D_801C39D4) {
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

// The checkpoint time of a rider for a lap and checkpoint. The original indexes checkpointTimes with
// the lap minus 2 (row 0 is the time at the start of lap 2).
#define RIDER_CP_TIME(rider, lap, cp) ((rider)->checkpointTimes[(lap) - 2][cp])

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
        if ((D_801C1FD8 == 0) && (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) && (D_801CE638 == 1) && (D_801CE600 == 0) &&
            (D_801C39CC == 0) && allClear) {
            D_801C1FD8 = 1;
            D_801C2928 = 0;
            for (i = 0; i < 3; i++) {
                if (gStuntRecords[gCourseID][i].score < D_801C26D0) {
                    D_801C2928 = i + 1;
                    for (j = 2; j > i; j--) {
                        gStuntRecords[gCourseID][j] = gStuntRecords[gCourseID][j - 1];
                    }
                    gStuntRecords[gCourseID][i].score = D_801C26D0;
                    gStuntRecords[gCourseID][i].rider = D_800DA9B0[0];
                    gStuntRecords[gCourseID][i].flag = D_801CB32C;
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < gRiders; i++) {
            func_80076378(i);
            func_8007687C(i);
        }
        // Riders who finished at once: the earlier raceTime gets the better progress, and a tie
        // goes to the rider ahead ("simultaneously goal").
        if ((D_801CE638 == 1) && (gGameModes == GMODE_CHAMPIONSHIP)) {
            for (i = 0; i < gRiders; i++) {
                if ((gRiderRaceState[i].unk2F4 != 0) && (gRiderRaceState[i].finishState == 0) && (gRiderRaceState[i].unk304 == 0)) {
                    gRiderRaceState[i].unk304 = 1;
                    for (j = 0; j < gRiders; j++) {
                        if ((gRiderRaceState[j].unk2F4 != 0) && (gRiderRaceState[j].finishState == 0) && (j != i)) {
                            if ((gRiderRaceState[i].progress < gRiderRaceState[j].progress) &&
                                (gRiderRaceState[i].raceTime < gRiderRaceState[j].raceTime)) {
                                tmp = gRiderRaceState[i].progress;
                                gRiderRaceState[i].progress = gRiderRaceState[j].progress;
                                gRiderRaceState[j].progress = tmp;
                            } else if ((gRiderRaceState[i].raceTime == gRiderRaceState[j].raceTime) &&
                                       (gRiderRaceState[i].racePosition < gRiderRaceState[j].racePosition) && (j != gPlayer1Rider)) {
                                gRiderRaceState[j].raceTime++;
                            }
                        }
                    }
                }
            }
        }
        // The human's finish with one player: best lap (gBestLaps), the top three
        // (gBestTimes, with the checkpoint times of a new best in gBestCheckpointTimes), or
        // D_801C23B0 when D_800DAB68 is set.
        if (D_801C1FD8 == 0) {
            if ((gRiderRaceState[gPlayer1Rider].unk2F4 != 0) && (D_801CE638 == 1) && (gPlayers == ONE_PLAYER) && (D_801CE600 == 0)) {
                D_801C1FD8 = 1;
                rider = &gRiderRaceState[gPlayer1Rider];
                if (D_800DAB68 == 0) {
                    if (rider->bestLapTime < gBestLaps[gCourseID].time) {
                        gBestLaps[gCourseID].time = rider->bestLapTime;
                        gBestLaps[gCourseID].rider = D_800DA9B0[0];
                        gBestLaps[gCourseID].flag = D_801CB32C;
                        gBestLaps[gCourseID].difficulty = gDifficulty;
                        D_801C2654 = 1;
                    }
                    for (i = 0; i < 3; i++) {
                        if (rider->raceTime < gBestTimes[gCourseID][i].time) {
                            D_801C2650 = i + 1;
                            for (j = 2; j > i; j--) {
                                gBestTimes[gCourseID][j] = gBestTimes[gCourseID][j - 1];
                            }
                            gBestTimes[gCourseID][i].time = rider->raceTime;
                            gBestTimes[gCourseID][i].rider = D_800DA9B0[0];
                            gBestTimes[gCourseID][i].flag = D_801CB32C;
                            gBestTimes[gCourseID][i].difficulty = gDifficulty;
                            if (i + 1 == 1) {
                                for (j = 0; j < 9; j++) {
                                    gBestCheckpointTimes[gCourseID][j] = rider->checkpointTimes[j][0];
                                }
                            }
                            break;
                        }
                    }
                } else if (rider->raceTime < D_801C23B0[gCourseID].time) {
                    D_801C23B0[gCourseID].time = rider->raceTime;
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
    place = gRiderRaceState[gPlayer1Rider].racePosition;
    // While racing, the places follow progress ("rank value adjust").
    if ((D_801CE638 == 1) && (D_801C1FD4 == 0) && (gGameModeState == GMODE_STATE_STARTED) &&
        ((gGameModes == GMODE_CHAMPIONSHIP) || (gGameModes == GMODE_2P_VS))) {
        for (i = 0; i < gRiders; i++) {
            D_801C3990[i] = i;
        }
        for (i = 0; i < gRiders - 1; i++) {
            for (j = i + 1; j < gRiders; j++) {
                if (gRiderRaceState[D_801C3990[i]].progress < gRiderRaceState[D_801C3990[j]].progress) {
                    tmp = D_801C3990[i];
                    D_801C3990[i] = D_801C3990[j];
                    D_801C3990[j] = tmp;
                }
            }
        }
        for (i = 0; i < gRiders; i++) {
            gRiderRaceState[D_801C3990[i]].racePosition = i;
        }
    }
    // A checkpoint gap (gapRequest 10 asks for one): to the rider one place ahead for the
    // human, or to the human for a rider behind; checkpointGap is the gap, gapTimer its timer.
    if (gGameModes == GMODE_CHAMPIONSHIP) {
        for (i = 0; i < gRiders; i++) {
            rider = &gRiderRaceState[i];
            if (rider->gapRequest == 10) {
                time = RIDER_CP_TIME(rider, rider->lapCount, rider->unk164);
                if ((i == gPlayer1Rider) && (rider->racePosition > 0)) {
                    for (j = 0; j < gRiders; j++) {
                        if (rider->racePosition - 1 == gRiderRaceState[j].racePosition) {
                            break;
                        }
                    }
                    other = RIDER_CP_TIME(&gRiderRaceState[j], rider->lapCount, rider->unk164);
                    if (other > 0) {
                        rider->gapRequest = 1;
                        rider->checkpointGap = time - other;
                        rider->gapTimer = 40;
                        rider->unk33C = j;
                        if (rider->racePosition == 1) {
                            func_800C3EF4(-((rider->checkpointGap + 500) / 1000));
                        }
                    } else {
                        rider->gapRequest = 0;
                    }
                } else if ((i != gPlayer1Rider) && (gRiderRaceState[gPlayer1Rider].racePosition < rider->racePosition)) {
                    other = RIDER_CP_TIME(&gRiderRaceState[gPlayer1Rider], rider->lapCount, rider->unk164);
                    if (other > 0) {
                        rider->gapRequest = 1;
                        rider->checkpointGap = time - other;
                        rider->gapTimer = 40;
                        if ((gRiderRaceState[gPlayer1Rider].racePosition == 0) && (rider->racePosition == 1)) {
                            func_800C3EF4((rider->checkpointGap + 500) / 1000);
                        }
                    } else {
                        rider->gapRequest = 0;
                    }
                } else {
                    rider->gapRequest = 0;
                }
            }
        }
    } else if (gGameModes == GMODE_2P_VS) {
        for (i = 0; i < gRiders; i++) {
            rider = &gRiderRaceState[i];
            if (rider->gapRequest == 10) {
                if (rider->racePosition == 1) {
                    time = RIDER_CP_TIME(rider, rider->lapCount, rider->unk164);
                    if (i == gPlayer1Rider) {
                        other = RIDER_CP_TIME(&gRiderRaceState[gPlayer2Rider], rider->lapCount, rider->unk164);
                        if (other == 0) {
                            other = time;
                        }
                        rider->gapRequest = 1;
                        rider->checkpointGap = time - other;
                        rider->gapTimer = 40;
                        gRiderRaceState[gPlayer2Rider].gapRequest = 2;
                        gRiderRaceState[gPlayer2Rider].checkpointGap = time - other;
                        gRiderRaceState[gPlayer2Rider].gapTimer = 40;
                        func_800C3EF4(-((rider->checkpointGap + 500) / 1000));
                    } else {
                        other = RIDER_CP_TIME(&gRiderRaceState[gPlayer1Rider], rider->lapCount, rider->unk164);
                        if (other == 0) {
                            other = time;
                        }
                        rider->gapRequest = 1;
                        rider->checkpointGap = time - other;
                        rider->gapTimer = 40;
                        gRiderRaceState[gPlayer1Rider].gapRequest = 2;
                        gRiderRaceState[gPlayer1Rider].checkpointGap = time - other;
                        gRiderRaceState[gPlayer1Rider].gapTimer = 40;
                        func_800C3EF4(-((rider->checkpointGap + 500) / 1000));
                    }
                } else {
                    rider->gapRequest = 0;
                }
            }
        }
    }
    if ((gGameModes == GMODE_2P_VS) && (D_801CE638 == 1)) {
        if (D_801C1FD4 == 0) {
            if (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) {
                if (gRiderRaceState[gPlayer2Rider].unk2F4 != 0) {
                    D_801C1FD4 = 1;
                    do {} while (0); // FAKE: register-allocation boundary found by the permuter
                    if (gRiderRaceState[gPlayer2Rider].raceTime >= gRiderRaceState[gPlayer1Rider].raceTime) {
                        gRiderRaceState[gPlayer1Rider].racePosition = 0;
                        gRiderRaceState[gPlayer2Rider].racePosition = 1;
                    } else {
                        gRiderRaceState[gPlayer1Rider].racePosition = 1;
                        gRiderRaceState[gPlayer2Rider].racePosition = 0;
                    }
                }
            }
        }
        if ((D_801C1FD8 == 0) &&
            ((gRiderRaceState[gPlayer1Rider].unk2F4 != 0) || (gRiderRaceState[gPlayer1Rider].finishState != 0) ||
             (gRiderRaceState[gPlayer2Rider].unk2F4 != 0) || (gRiderRaceState[gPlayer2Rider].finishState != 0))) {
            D_801C1FD8 = 1;
        }
    }
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (place != gRiderRaceState[gPlayer1Rider].racePosition)) {
        D_80228A9C = 1;
    }
    if ((D_801CE638 == 1) && (gGameModes == GMODE_2P_VS)) {
        func_80078264();
    }
    D_801C3A08 = osGetTime() - D_801C3A08;
    if ((gGameModes == GMODE_CHAMPIONSHIP) && (gRiderRaceState[gPlayer1Rider].unk2F4 != 0) && (D_801C1FDC < 0x7FFFFFFF)) {
        D_801C1FDC++;
    }
    func_801FC39C();
    func_801EF504();
    func_801F23A0();
    if ((gRiderRaceState[gPlayer1Rider].finishState == 0) &&
        ((gPlayers != TWO_PLAYERS) || (gRiderRaceState[gPlayer2Rider].finishState == 0)) && (D_801CE628 == 0)) {
        Hud_UpdateStartCountdown();
    }
    func_801F8DD0();
    func_801F9EA0();
    func_801F0E7C();
    Hud_UpdateOffCourseCountdown();
}
