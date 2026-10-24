#include "common.h"

typedef struct UnkStruct_801BB138_s {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} UnkStruct_801BB138; /* size = 0x18 */

extern struct_801C1F84* D_801C1F80;
extern struct_801C1F84* D_801C1F84;
extern struct_801C1F84* D_801C1F88;
extern UnkStruct_801AEE20 D_801B2F20;
extern UnkStruct_801AEE20 D_801B7020;
extern s32 D_801BB120;
extern s32 D_801BB124;
extern s32 D_801BB128;
extern s32 D_801CE638;

extern UnkStruct_801BB138 D_801BB138[];
extern s32 D_801BC938;
extern f32 D_801C1CE8;
extern f32 D_801C1CEC;
extern f32 D_801C1CF0;
extern f32 D_801C1CF4;
extern f32 D_801C1CF8;
extern f32 D_801C1CFC;
extern u8 D_801C1D00[];
extern s32 D_801C1F00[4][4];
extern s32 D_801C1F40[4][4];

static const char devstr1[] = "Error: number of buoy2\n";
static const char devstr2[] = "Error: number of buoy3\n";

// The per-course setup lists, terminated by -1 in the field named in each type.
typedef struct CourseRecordSrc { /* table B records; ends at angle -1 */
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 z;
    /* 0x4 */ s16 type;
    /* 0x6 */ s16 angle;
} CourseRecordSrc; /* size = 0x8 */

typedef struct CourseBuoySrc { /* table A records; ends at type -1 */
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 z;
    /* 0x4 */ s16 type;
} CourseBuoySrc; /* size = 0x6 */

typedef struct CourseObjectSrc { /* type 1 objects; ends at heading -1 */
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 z;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 heading;
} CourseObjectSrc; /* size = 0xA */

typedef struct CourseRingSrc { /* type 8 objects (stunt mode); ends at heading -1 */
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 heading;
} CourseRingSrc; /* size = 0xC */

typedef struct CourseThingSrc { /* other objects; ends at heading -1 */
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 type;
    /* 0x8 */ s16 heading;
} CourseThingSrc; /* size = 0xA */

typedef struct CourseUnkBFA48Src { /* ends at unk4 -1, at most 8 */
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
} CourseUnkBFA48Src; /* size = 0xE */

typedef struct CourseUnkBFB70Src { /* ends at unk4 -1, at most 8; unk18 masks difficulties */
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
} CourseUnkBFB70Src; /* size = 0x1A */

typedef struct UnkStruct_801BFA48 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ char pad20[4];
} UnkStruct_801BFA48; /* size = 0x24 */

typedef struct UnkStruct_801BFB70 {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ char pad3E[2];
} UnkStruct_801BFB70; /* size = 0x40 */

// A 0x40-byte block of per-course parameters, copied to D_801924F0..D_8019252C.
typedef struct UnkStruct_800D699C {
    /* 0x00 */ s32 unk0[14];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
} UnkStruct_800D699C; /* size = 0x40 */

// The same for D_801C3B40..D_801C3B78.
typedef struct UnkStruct_800D6B1C {
    /* 0x00 */ s32 unk0[14];
    /* 0x38 */ s16 unk38;
} UnkStruct_800D6B1C;

extern s32 D_800D8250;
extern s32 D_801BB12C;
extern s32 D_801BB130;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern s32 D_801BB134;
extern UnkStruct_801BFA48 D_801BFA48[];
extern s32 D_801BFB68;
extern UnkStruct_801BFB70 D_801BFB70[];
extern s32 D_801BFD70;
extern s32 D_801C1F90;
extern f32 D_801C1FB8;
extern f32 D_801C1FBC;
extern void* D_801C1CD0;
extern void* D_801C1CD4;
extern void* D_801C1CD8;
extern void* D_801C1CDC;
extern void* D_801C1CE0;
extern void* D_801C1CE4;
extern s32 D_801924F0;
extern s32 D_801924F4;
extern s32 D_801924F8;
extern s32 D_801924FC;
extern s32 D_80192500;
extern s32 D_80192504;
extern s32 D_80192508;
extern s32 D_8019250C;
extern s32 D_80192510;
extern s32 D_80192514;
extern s32 D_80192518;
extern s32 D_8019251C;
extern s32 D_80192520;
extern s32 D_80192524;
extern s32 D_80192528;
extern f32 D_8019252C;
extern void* D_80192530;
extern void* D_80192534;
extern void* D_80192538;
extern s16 D_801C3B40;
extern s32 D_801C3B44;
extern s32 D_801C3B48;
extern s32 D_801C3B4C;
extern s32 D_801C3B50;
extern s32 D_801C3B54;
extern s32 D_801C3B58;
extern s32 D_801C3B5C;
extern s32 D_801C3B60;
extern s32 D_801C3B64;
extern s32 D_801C3B68;
extern s32 D_801C3B6C;
extern s32 D_801C3B70;
extern s32 D_801C3B74;
extern s32 D_801C3B78;
extern void* D_801C3B7C;
extern s32 D_801C3B80;
extern void* D_801C3B84;
extern f32 D_800D9630;
extern s32 D_800D8240;
extern s32 D_800D8248;
extern s32 D_800D824C;
extern s32 D_800D8254;
extern s32 D_800D8258;
extern u8 D_D019AC8[];
extern u8 D_D01AD10[];
// Per-course tables, indexed by gCourseID (one set for one player, one for two).
extern void* D_800D5470[];
extern void* D_800D54A0[];
extern void* D_800D54D0[];
extern void* D_800D5500[];
extern void* D_800D5530[];
extern void* D_800D5560[];
extern void* D_800D5590[];
extern void* D_800D55C0[];
extern void* D_800D55F0[];
extern void* D_800D5620[];
extern void* D_800D5650[];
extern void* D_800D5680[];
extern f32 D_800D5894[];
extern struct_801C1F84* D_800D5ED4[];
extern struct_801C1F84* D_800D61B4[];
extern struct_801C1F84* D_800D6274[];
extern s32* D_800D62A4[];
extern s32* D_800D62D4[];
extern s16* D_800D6304[];
extern CourseRecordSrc* D_800D6334[];
extern CourseRecordSrc* D_800D635C[];
extern CourseRecordSrc* D_800D6384[];
extern CourseRecordSrc* D_800D63AC[];
extern CourseRecordSrc* D_800D63D4[];
extern CourseRecordSrc* D_800D63FC[];
extern CourseRecordSrc* D_800D6424[];
extern CourseRecordSrc* D_800D644C[];
extern CourseRecordSrc* D_800D6474[];
extern CourseRecordSrc* D_800D649C[];
extern CourseRecordSrc* D_800D64C4[];
extern CourseRecordSrc* D_800D64EC[];
extern CourseRecordSrc* D_800D6514[];
extern CourseRecordSrc* D_800D653C[];
extern CourseRecordSrc* D_800D6564[];
extern CourseRecordSrc* D_800D658C[];
extern CourseRecordSrc* D_800D65B4[];
extern CourseRecordSrc* D_800D65DC[];
extern CourseRecordSrc* D_800D6604[];
extern CourseRecordSrc* D_800D662C[];
extern CourseRecordSrc D_800D5700[];
extern CourseObjectSrc* D_800D6654[];
extern CourseObjectSrc* D_800D667C[];
extern CourseObjectSrc* D_800D66A4[];
extern CourseObjectSrc* D_800D66CC[];
extern CourseBuoySrc* D_800D66F4[];
extern CourseBuoySrc* D_800D671C[];
extern CourseBuoySrc* D_800D6744[];
extern CourseBuoySrc* D_800D676C[];
extern s16* D_800D6794[];
extern s16* D_800D67BC[];
extern s16* D_800D67E4[];
extern s16* D_800D680C[];
extern CourseThingSrc* D_800D6834[];
extern CourseThingSrc* D_800D685C[];
extern CourseRingSrc* D_800D6884[];
extern CourseUnkBFA48Src* D_800D68AC[];
extern CourseUnkBFB70Src* D_800D68D4[];
extern CourseUnkBFA48Src* D_800D68FC[];
extern CourseUnkBFB70Src* D_800D6924[];
extern CourseUnkBFA48Src* D_800D694C[];
extern CourseUnkBFB70Src* D_800D6974[];
extern UnkStruct_800D699C* D_800D699C[];
extern void* D_800D69CC[];
extern void* D_800D69FC[];
extern void* D_800D6A2C[];
extern UnkStruct_800D699C* D_800D6A5C[];
extern void* D_800D6A8C[];
extern void* D_800D6ABC[];
extern void* D_800D6AEC[];
extern UnkStruct_800D6B1C* D_800D6B1C[];
extern void* D_800D6B4C[];
extern s32 D_800D6B7C[];
extern void* D_800D6BAC[];
extern UnkStruct_800D6B1C* D_800D6BDC[];
extern void* D_800D6C0C[];
extern s32 D_800D6C3C[];
extern void* D_800D6C6C[];

#ifdef NON_MATCHING
// 47402: same lists, switches and stores; register allocation and scheduling differ throughout,
// and this C is shorter (the frame is 0x90, not 0xA0).
void func_80071E70(void) {
    s32 i;
    s32 n;
    s32 t;
    s32 type;
    s32 kind;
    s32 angle;
    s32 difficulty;
    UnkStruct_800D699C* params;
    UnkStruct_800D6B1C* params2;
    CourseUnkBFA48Src* src1;
    CourseUnkBFB70Src* src2;
    CourseRecordSrc* list0;
    CourseRecordSrc* list1;
    CourseRecordSrc* list2;
    CourseRecordSrc* rec;
    CourseBuoySrc* buoys;
    CourseObjectSrc* objects;
    CourseRingSrc* rings;
    CourseThingSrc* things;
    CourseBuoySrc* b;
    s16* edge;
    s16* pts;
    UnkStruct_801AEE20* table;
    UnkStruct_801AEE20* e;
    UnkStruct_801BC940* o;
    UnkStruct_801BB138* a;

    if (D_801CE638 == 21) {
        D_801C1CD0 = D_D01AD10;
        D_801C1CD4 = D_D019AC8;
        D_801C1CD8 = NULL;
        D_801C1CDC = NULL;
        D_801C1CE0 = NULL;
        D_801C1CE4 = NULL;
    } else if (gPlayers == ONE_PLAYER) {
        D_801C1CD0 = D_800D5470[gCourseID];
        D_801C1CD4 = D_800D54A0[gCourseID];
        D_801C1CD8 = D_800D5530[gCourseID];
        D_801C1CDC = D_800D5560[gCourseID];
        D_801C1CE0 = D_800D55F0[gCourseID];
        D_801C1CE4 = D_800D5620[gCourseID];
    } else {
        D_801C1CD0 = D_800D54D0[gCourseID];
        D_801C1CD4 = D_800D5500[gCourseID];
        D_801C1CD8 = D_800D5590[gCourseID];
        D_801C1CDC = D_800D55C0[gCourseID];
        D_801C1CE0 = D_800D5650[gCourseID];
        D_801C1CE4 = D_800D5680[gCourseID];
    }
    if (gPlayers == ONE_PLAYER) {
        D_80192538 = D_800D69CC[gCourseID];
        D_80192534 = D_800D69FC[gCourseID];
        params = D_800D699C[gCourseID];
        D_80192530 = D_800D6A2C[gCourseID];
    } else {
        D_80192538 = D_800D6A8C[gCourseID];
        D_80192534 = D_800D6ABC[gCourseID];
        params = D_800D6A5C[gCourseID];
        D_80192530 = D_800D6AEC[gCourseID];
    }
    D_801924F4 = params->unk0[0];
    D_801924F8 = params->unk0[1];
    D_801924FC = params->unk0[2];
    D_80192500 = params->unk0[3];
    D_80192504 = params->unk0[4];
    D_80192508 = params->unk0[5];
    D_8019250C = params->unk0[6];
    D_80192510 = params->unk0[7];
    D_80192514 = params->unk0[8];
    D_80192518 = params->unk0[9];
    D_8019251C = params->unk0[10];
    D_80192520 = params->unk0[11];
    D_80192524 = params->unk0[12];
    D_80192528 = params->unk0[13];
    D_8019252C = params->unk38;
    D_801924F0 = params->unk3C;
    if (gPlayers == ONE_PLAYER) {
        D_801C3B84 = D_800D6B4C[gCourseID];
        D_801C3B7C = D_800D6BAC[gCourseID];
        D_801C3B80 = D_800D6B7C[gCourseID] - 2;
        params2 = D_800D6B1C[gCourseID];
    } else {
        D_801C3B84 = D_800D6C0C[gCourseID];
        D_801C3B7C = D_800D6C6C[gCourseID];
        D_801C3B80 = D_800D6C3C[gCourseID] - 2;
        params2 = D_800D6BDC[gCourseID];
    }
    D_800D9630 = D_800D5894[gCourseID];
    D_801C3B44 = params2->unk0[0];
    D_801C3B48 = params2->unk0[2];
    D_801C3B4C = params2->unk0[4];
    D_801C3B50 = params2->unk0[1];
    D_801C3B54 = params2->unk0[3];
    D_801C3B58 = params2->unk0[5];
    D_801C3B5C = params2->unk0[6];
    D_801C3B60 = params2->unk0[8];
    D_801C3B64 = params2->unk0[7];
    D_801C3B68 = params2->unk0[9];
    D_801C3B6C = params2->unk0[10];
    D_801C3B70 = params2->unk0[12];
    D_801C3B74 = params2->unk0[11];
    D_801C3B78 = params2->unk0[13];
    D_801C3B40 = params2->unk38;

    // D_801BFA48 and D_801BFB70, at most 8 each.
    D_801BFB68 = 0;
    D_801BFD70 = 0;
    if (D_801CE638 == 8) {
        src1 = D_800D68FC[gCourseID];
        src2 = D_800D6924[gCourseID];
    } else if (gGameModes == GMODE_STUNT) {
        src1 = D_800D694C[gCourseID];
        src2 = D_800D6974[gCourseID];
    } else {
        src1 = D_800D68AC[gCourseID];
        src2 = D_800D68D4[gCourseID];
    }
    for (; src1->unk4 != -1; src1++) {
        D_801BFA48[D_801BFB68].unk0 = src1->unk0;
        D_801BFA48[D_801BFB68].unk4 = src1->unk2;
        angle = (src1->unk4 / 360.0f) * 4096.0f;
        D_801BFA48[D_801BFB68].unk8 = gSinTable[angle & 0xFFF] * 64.0f;
        D_801BFA48[D_801BFB68].unkC = gSinTable[(angle + 0x400) & 0xFFF] * 64.0f;
        D_801BFA48[D_801BFB68].unk1C = src1->unk6 / 64;
        D_801BFA48[D_801BFB68].unk10 = src1->unk8;
        D_801BFA48[D_801BFB68].unk14 = src1->unkA;
        D_801BFA48[D_801BFB68].unk18 = src1->unkC;
        if (++D_801BFB68 >= 8) {
            break;
        }
    }
    for (; src2->unk4 != -1; src2++) {
        // Entries flagged for this difficulty (or bit 3 with D_800DAB68/D_800D8250) are left out.
        if ((src2->unk18 & (1 << gDifficulty)) || (((D_800DAB68 != 0) || (D_800D8250 != 0)) && (src2->unk18 & 8))) {
            continue;
        }
        D_801BFB70[D_801BFD70].unk0 = src2->unk0;
        D_801BFB70[D_801BFD70].unk4 = src2->unk2;
        angle = (src2->unk4 / 360.0f) * 4096.0f;
        D_801BFB70[D_801BFD70].unk10 = gSinTable[angle & 0xFFF] * 64.0f;
        D_801BFB70[D_801BFD70].unk14 = gSinTable[(angle + 0x400) & 0xFFF] * 64.0f;
        angle = (src2->unk6 / 360.0f) * 4096.0f;
        D_801BFB70[D_801BFD70].unk8 = gSinTable[angle & 0xFFF] * 64.0f;
        D_801BFB70[D_801BFD70].unkC = gSinTable[(angle + 0x400) & 0xFFF] * 64.0f;
        D_801BFB70[D_801BFD70].unk18 = src2->unk8;
        D_801BFB70[D_801BFD70].unk1C = src2->unkA;
        D_801BFB70[D_801BFD70].unk20 = src2->unkC;
        D_801BFB70[D_801BFD70].unk24 = src2->unkE;
        D_801BFB70[D_801BFD70].unk2C = src2->unk10;
        D_801BFB70[D_801BFD70].unk30 = src2->unk12;
        D_801BFB70[D_801BFD70].unk34 = src2->unk14;
        D_801BFB70[D_801BFD70].unk28 = 0;
        D_801BFB70[D_801BFD70].unk38 = src2->unk16;
        D_801BFB70[D_801BFD70].unk3C = src2->unk18;
        if (++D_801BFD70 >= 8) {
            break;
        }
    }
    D_801C1F80 = D_800D5ED4[gCourseID];
    D_801C1F84 = D_800D61B4[gCourseID];
    D_801C1F88 = D_800D6274[gCourseID];
    if (D_800D8240 != 0) {
        return;
    }

    D_801BFA40 = 0;
    D_801BC938 = 0;
    D_801BB128 = 0;
    D_801BB124 = 0;
    D_801BB120 = 0;
    D_801BB12C = 0;
    D_801BB130 = 0;
    D_801BB134 = 0;
    if (D_801CE638 == 21) {
        return;
    }
    if (gGameModes == GMODE_2P_VS) {
        D_801C1FBC = 0.0f;
        D_801C1F90 = *D_800D62D4[gCourseID];
        D_801C1FB8 = D_801C1FBC;
    } else {
        D_801C1F90 = *D_800D62A4[gCourseID];
        D_801C1FB8 = D_800D6304[gCourseID][0];
        D_801C1FBC = D_800D6304[gCourseID][1];
    }
    if ((D_801CE638 != 8) && ((D_800DAB68 != 0) || (D_800D8250 != 0))) {
        D_801C1F90 ^= 1;
    }
    // The lists for this course and mode: three record tables, the buoys and the objects.
    if ((D_801CE638 == 8) || (D_800D8248 != 0)) {
        list0 = list1 = list2 = D_800D6514[gCourseID];
        buoys = D_800D6744[gCourseID];
        objects = D_800D66A4[gCourseID];
    } else if ((gGameModes == GMODE_STUNT) || (D_800D824C != 0)) {
        list1 = NULL;
        list2 = NULL;
        list0 = D_800D653C[gCourseID];
        buoys = D_800D676C[gCourseID];
        objects = D_800D66CC[gCourseID];
        rings = D_800D6884[gCourseID];
    } else if ((D_800DAB68 != 0) || (D_800D8250 != 0)) {
        if (gPlayers == ONE_PLAYER) {
            list0 = D_800D6564[gCourseID];
            list1 = D_800D658C[gCourseID];
            list2 = D_800D65B4[gCourseID];
            buoys = D_800D66F4[gCourseID];
            objects = D_800D6654[gCourseID];
        } else {
            list0 = D_800D65DC[gCourseID];
            list1 = D_800D6604[gCourseID];
            list2 = D_800D662C[gCourseID];
            buoys = D_800D671C[gCourseID];
            objects = D_800D667C[gCourseID];
        }
    } else if (gPlayers == TWO_PLAYERS) {
        if (gDifficulty == DIFFICULTY_NORMAL) {
            list0 = D_800D649C[gCourseID];
        } else if (gDifficulty == DIFFICULTY_HARD) {
            list0 = D_800D64C4[gCourseID];
        } else {
            list0 = D_800D64EC[gCourseID];
        }
        buoys = D_800D671C[gCourseID];
        objects = D_800D667C[gCourseID];
        if (gCourseID == RIDER_SELECTION) {
            list1 = D_800D5700;
        } else {
            list1 = NULL;
        }
        list2 = NULL;
    } else {
        if (D_800D8254 == 0) {
            difficulty = gDifficulty;
        } else {
            difficulty = D_800D8258;
        }
        if ((difficulty == DIFFICULTY_NORMAL) || (gCourseID == DOLPHIN_PARK)) {
            list0 = D_800D6334[gCourseID];
            list1 = D_800D635C[gCourseID];
            list2 = D_800D6384[gCourseID];
        } else if (difficulty == DIFFICULTY_HARD) {
            list0 = D_800D63AC[gCourseID];
            list1 = D_800D63D4[gCourseID];
            list2 = D_800D63FC[gCourseID];
        } else {
            list0 = D_800D6424[gCourseID];
            list1 = D_800D644C[gCourseID];
            list2 = D_800D6474[gCourseID];
        }
        buoys = D_800D66F4[gCourseID];
        objects = D_800D6654[gCourseID];
    }
    if (gPlayers == TWO_PLAYERS) {
        edge = D_800D67BC[gCourseID];
        things = D_800D685C[gCourseID];
        pts = D_800D680C[gCourseID];
    } else {
        edge = D_800D6794[gCourseID];
        things = D_800D6834[gCourseID];
        pts = D_800D67E4[gCourseID];
    }

    // Table B (and its two alternatives): the records, chained in list order.
    for (t = 0; t < 3; t++) {
        switch (t) {
            case 0:
                table = D_801AEE20;
                rec = list0;
                break;
            case 1:
                table = &D_801B2F20;
                rec = list1;
                break;
            case 2:
                table = &D_801B7020;
                rec = list2;
                break;
        }
        if (rec == NULL) {
            continue;
        }
        for (n = 0, e = table; rec->angle != -1; rec++, e++) {
            e->unk24 = rec->x;
            e->unk28 = rec->z;
            type = rec->type;
            switch (type) {
                case 1:
                case 5:
                case 7:
                case 10:
                case 13:
                case 16:
                case 19:
                case 22:
                    kind = 1;
                    break;
                case 2:
                    kind = 2;
                    break;
                case 3:
                    kind = 3;
                    break;
                case 8:
                case 11:
                case 14:
                case 17:
                case 20:
                case 23:
                    kind = 4;
                    break;
                case 24:
                    kind = 6;
                    break;
                case 25:
                    kind = 7;
                    break;
                case 26:
                    kind = 8;
                    break;
                case 27:
                    kind = 9;
                    break;
                case 28:
                    kind = 10;
                    break;
                case 29:
                    kind = 11;
                    break;
                case 30:
                    kind = 12;
                    break;
                case 31:
                    kind = 13;
                    break;
                case 32:
                    kind = 14;
                    break;
                default:
                    kind = 0;
                    break;
            }
            e->unk98 = kind;
            e->unkB4 = n + 1;
            e->unkA4 = -1;
            if ((type == 4) || (type == 5)) {
                e->unkBC = 1;
            } else {
                e->unkBC = 0;
            }
            switch (type) {
                case 6:
                case 7:
                case 8:
                case 24:
                case 25:
                case 29:
                case 30:
                case 31:
                case 32:
                    kind = 1;
                    break;
                case 9:
                case 10:
                case 11:
                    kind = 2;
                    break;
                case 12:
                case 13:
                case 14:
                    kind = 3;
                    break;
                case 15:
                case 16:
                case 17:
                    kind = 4;
                    break;
                case 18:
                case 19:
                case 20:
                    kind = 5;
                    break;
                case 21:
                case 22:
                case 23:
                    kind = 6;
                    break;
                default:
                    kind = 0;
                    break;
            }
            e->unkC0 = kind;
            if ((gCourseID == DOLPHIN_PARK) && (type == 27)) {
                e->unkC0 = 1;
            }
            if ((gCourseID != DOLPHIN_PARK) && ((type == 26) || (type == 27))) {
                e->unkC0 = 2;
            }
            e->unk6C = rec->angle;
            angle = (e->unk6C / 360.0f) * 4096.0f;
            e->unk70 = gSinTable[angle & 0xFFF];
            e->unk74 = gSinTable[(angle + 0x400) & 0xFFF];
            if (t == 0) {
                if (e->unk98 == 3) {
                    D_801BB12C = n;
                }
                if (e->unk98 == 5) {
                    D_801BB130 = n;
                }
            }
            if (++n >= 64) {
                break;
            }
        }
        if (n > 0) {
            table[n - 1].unkB4 = 0;
        }
        if (t == 0) {
            D_801BB120 = n;
        } else if (t == 1) {
            D_801BB124 = n;
            if ((D_801BB120 != n) && (gCourseID != DOLPHIN_PARK)) {
                D_801BB124 = 0;
            }
        } else {
            D_801BB128 = n;
            if ((D_801BB120 != n) && (gCourseID != DOLPHIN_PARK)) {
                D_801BB128 = 0;
            }
        }
    }

    // The objects (D_801BC940, at most 64): type 1 from the course list, type 8 in stunt mode,
    // and the others by their list type.
    for (; objects->heading != -1; objects++) {
        o = &D_801BC940[D_801BFA40];
        o->unk4C = 1;
        o->unk28 = 0.0f;
        o->unk24 = objects->x;
        o->unk2C = objects->z;
        o->unk50 = objects->unk4;
        o->unk58 = objects->unk6;
        o->unk48 = objects->heading;
        if (((objects->unk4 == 2) && (gDifficulty == DIFFICULTY_HARD) && (D_800D8254 == 0)) ||
            ((objects->unk4 == 3) && (gDifficulty == DIFFICULTY_EXPERT) && (D_800D8254 == 0))) {
            continue;
        }
        if (++D_801BFA40 >= 64) {
            break;
        }
    }
    if ((gGameModes == GMODE_STUNT) || (D_800D824C != 0)) {
        for (; rings->heading != -1; rings++) {
            o = &D_801BC940[D_801BFA40];
            o->unk4C = 8;
            o->unk24 = rings->x;
            o->unk28 = rings->y;
            o->unk2C = rings->z;
            o->unk50 = rings->unk6;
            o->unkC0 = rings->unk8;
            o->unk48 = rings->heading;
            D_801BB134++;
            if (++D_801BFA40 >= 64) {
                break;
            }
        }
    }
    for (; things->heading != -1; things++) {
        o = &D_801BC940[D_801BFA40];
        switch (things->type) {
            case 1:
                o->unk4C = 2;
                break;
            case 2:
                o->unk4C = 3;
                break;
            case 3:
                if (gDifficulty < 2) {
                    continue;
                }
                o->unk4C = 4;
                break;
            case 4:
                o->unk4C = 5;
                break;
            case 5:
                if (gDifficulty <= 0) {
                    continue;
                }
                o->unk4C = 6;
                break;
            case 6:
                if (gDifficulty < 2) {
                    continue;
                }
                o->unk4C = 7;
                break;
            case 7:
                o->unk4C = 8;
                break;
            case 8:
                o->unk4C = 9;
                break;
            case 9:
                o->unk4C = 10;
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                if (gPlayers == TWO_PLAYERS) {
                    continue;
                }
                o->unk4C = 11;
                o->unk50 = things->type - 10;
                break;
            default:
                continue;
        }
        o->unk24 = things->x;
        o->unk28 = things->y;
        o->unk2C = things->z;
        o->unk48 = things->heading;
        if (++D_801BFA40 >= 64) {
            break;
        }
    }

    // Table A (D_801BB138, at most 256): the small buoys by type and difficulty, the course-edge
    // points (type 1), and the points with a height (type 5).
    for (b = buoys; b->type != -1; b++) {
        switch (b->type) {
            case 1:
                kind = 1;
                break;
            case 2:
                kind = 2;
                if ((gDifficulty <= 0) && (D_800D8254 == 0)) {
                    continue;
                }
                break;
            case 3:
                if ((gDifficulty < 2) && (D_800D8254 == 0)) {
                    continue;
                }
                kind = 3;
                if ((gCourseID == TWILIGHT_CITY) && ((D_800DAB68 != 0) || (D_800D8250 != 0))) {
                    continue;
                }
                break;
            case 4:
                kind = 4;
                break;
            default:
                kind = 0;
                break;
        }
        a = &D_801BB138[D_801BC938];
        a->unk10 = kind;
        a->unk0 = b->x;
        a->unk8 = b->z;
        if (++D_801BC938 >= 256) {
            break;
        }
    }
    if ((edge[0] != -1) || (edge[1] != -1)) {
        i = 0;
        do {
            a = &D_801BB138[D_801BC938];
            a->unk10 = 1;
            a->unk0 = edge[i * 2];
            a->unk8 = edge[i * 2 + 1];
            if (++D_801BC938 >= 256) {
                break;
            }
            i++;
        } while ((edge[i * 2] != -1) || (edge[i * 2 + 1] != -1));
    }
    if ((pts[0] != -1) || (pts[2] != -1)) {
        i = 0;
        do {
            if (D_801BC938 >= 256) {
                break;
            }
            a = &D_801BB138[D_801BC938];
            a->unk10 = 5;
            a->unk0 = pts[i * 3];
            a->unk4 = pts[i * 3 + 1];
            a->unk8 = pts[i * 3 + 2];
            D_801BC938++;
            i++;
        } while ((pts[i * 3] != -1) || (pts[i * 3 + 2] != -1));
    }
    if (D_801CE638 == 21) {
        D_801BC938 = 0;
        D_801BFA40 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_80071E70.s")
#endif

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

#ifdef NON_MATCHING
// 2265: same loops. In the first loop the original stores the new bounds with lui at and keeps
// the record's coordinate in fs3; here the stores use the hoisted addresses and the registers differ.
void func_80073E6C(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 count;
    f32 cellW;
    f32 cellH;
    f32 x0;
    f32 x1;
    f32 z0;
    f32 z1;
    UnkStruct_801BB138* p;
    s32 type;

    D_801C1CEC = 524287.0f;
    D_801C1CF4 = -524288.0f;
    D_801C1CE8 = D_801C1CEC;
    D_801C1CF0 = D_801C1CF4;
    for (i = 0, p = D_801BB138; i < D_801BC938; i++, p++) {
        type = p->unk10;
        if (type != 5) {
            p->unk4 = 0.0f;
        }
        if (p->unk0 < D_801C1CE8) {
            D_801C1CE8 = p->unk0;
        }
        if (D_801C1CF0 < p->unk0) {
            D_801C1CF0 = p->unk0;
        }
        if (p->unk8 < D_801C1CEC) {
            D_801C1CEC = p->unk8;
        }
        if (D_801C1CF4 < p->unk8) {
            D_801C1CF4 = p->unk8;
        }
        p->unkC = 25.0f;
        if ((type != 2) && (type != 3) && (type != 4)) {
            p->unk14 = 0;
        } else {
            p->unk14 = 1;
        }
    }
    D_801C1CE8 -= 25.0f;
    D_801C1CF0 += 25.0f;
    D_801C1CEC -= 25.0f;
    D_801C1CF4 += 25.0f;
    D_801C1CF8 = D_801C1CF0 - D_801C1CE8;
    D_801C1CFC = D_801C1CF4 - D_801C1CEC;
    n = 0;
    cellW = D_801C1CF8 / 4;
    cellH = D_801C1CFC / 4;
    for (i = 0; i < 4; i++) {
        x0 = (i * cellW) + D_801C1CE8;
        x1 = x0 + cellW;
        x0 -= 25.0f;
        x1 += 25.0f;
        for (j = 0; j < 4; j++) {
            D_801C1F00[i][j] = n;
            count = 0;
            z0 = (j * cellH) + D_801C1CEC;
            z1 = z0 + cellH;
            z0 -= 25.0f;
            z1 += 25.0f;
            for (k = 0; k < D_801BC938; k++) {
                if (n < 0x1FF) {
                    if ((x0 <= D_801BB138[k].unk0) && (D_801BB138[k].unk0 <= x1)) {
                        if ((z0 <= D_801BB138[k].unk8) && (D_801BB138[k].unk8 <= z1)) {
                            D_801C1D00[n] = k;
                            n++;
                            count++;
                        }
                    }
                }
            }
            D_801C1F40[i][j] = count;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_80073E6C.s")
#endif

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

extern UnkStruct_801BC940_unk60 D_801BFD78[];
extern s32 D_801C0578;
extern Mtx D_801C0CD0[];
extern f32 gSinTable[0x1000];
// Collision boxes of the objects (model space), per course and object type.
extern UnkStruct_801BC940_unk60 D_800D6CF0[];
extern UnkStruct_801BC940_unk60 D_800D6E70[];
extern UnkStruct_801BC940_unk60 D_800D6FF0[];
extern UnkStruct_801BC940_unk60 D_800D7130[];
extern UnkStruct_801BC940_unk60 D_800D7270[];
extern UnkStruct_801BC940_unk60 D_800D73B0[];
extern UnkStruct_801BC940_unk60 D_800D74F0[];
extern UnkStruct_801BC940_unk60 D_800D7530[];
extern UnkStruct_801BC940_unk60 D_800D7570[];
extern UnkStruct_801BC940_unk60 D_800D7630[];
extern UnkStruct_801BC940_unk60 D_800D7670[];
extern UnkStruct_801BC940_unk60 D_800D76B0[];
// Fixed boxes (world space), copied as they are.
extern UnkStruct_801BC940_unk60 D_800D76F0[];
extern UnkStruct_801BC940_unk60 D_800D7770[];
extern UnkStruct_801BC940_unk60 D_800D77F0[];
extern UnkStruct_801BC940_unk60 D_800D7870[];
extern UnkStruct_801BC940_unk60 D_800D7970[];
extern UnkStruct_801BC940_unk60 D_800D79B0[];
extern Gfx* D_800D6C9C[];
extern Gfx* D_800D6CCC[];
extern Gfx D_101CB08[];
extern Gfx D_101CB18[];
extern Gfx D_101EA48[];
extern Gfx D_D00E858[];
extern Gfx D_D02BDE8[];
extern Gfx D_D02BDF8[];
extern Gfx D_E009808[];
extern Gfx D_E0098B0[];
extern Gfx D_E00D5D8[];
extern Gfx D_E00D678[];
extern Gfx D_E00D720[];
extern Gfx D_E00D7C8[];
extern Gfx D_E00D8A8[];
extern Gfx D_E00F2C0[];
extern Gfx D_E00F348[];
extern Gfx D_E00F3D8[];
extern Gfx D_E00F460[];
extern Gfx D_E0109C0[];
extern Gfx D_E010AE0[];
extern Gfx D_E010C00[];
extern Gfx D_E010D20[];
extern Gfx D_E01B660[];
extern Gfx D_E01B7D0[];

void func_801EE6F4(MtxF* mf, f32 rx, f32 ry, f32 rz, f32 x, f32 y, f32 z);
void func_801EDC60(MtxF* mf, f32 x, f32 y, f32 z, f32* outX, f32* outY, f32* outZ);
void func_801EDD04(MtxF* mf, f32 x, f32 y, f32 z, f32* outX, f32* outY, f32* outZ);

#ifdef NON_MATCHING
// 7030: same blocks, calls and stores. The original loads both sine pairs before the zero
// stores, reloads unk4C in each case of the second switch, and numbers registers differently.
void func_800744EC(void) {
    s32 i;
    s32 k;
    s32 angle;
    f32 rot;
    UnkStruct_801BC940* e;
    UnkStruct_801BC940_unk60* box;
    UnkStruct_801BC940_unk60* src;
    Mtx* mtx;
    MtxF* mf;

    D_801C0578 = 0;
    for (i = 0; i < D_801BFA40; i++) {
        e = &D_801BC940[i];
        rot = e->unk48;
        e->unk0 = e->unk24;
        e->unk4 = e->unk28;
        e->unk10 = rot + 180.0f;
        e->unk8 = e->unk2C;
        e->unk20 = e->unk1C = e->unk18 = 0.0f;
        e->unkC = 0.0f;
        e->unk14 = 0.0f;
        angle = (rot / 360.0f) * 4096.0f;
        e->unk30 = gSinTable[angle & 0xFFF];
        e->unk34 = gSinTable[(angle + 0x400) & 0xFFF];
        angle = ((rot + 90.0f) / 360.0f) * 4096.0f;
        e->unk40 = 0.0f;
        e->unk44 = 0.0f;
        e->unkBC = 0;
        e->unk6C = 0;
        e->unk70 = 0;
        e->unkB4 = NULL;
        e->unkB8 = NULL;
        e->unk64 = 0;
        e->unk68 = 0;
        e->unk60 = NULL;
        e->unk38 = gSinTable[angle & 0xFFF];
        e->unk3C = gSinTable[(angle + 0x400) & 0xFFF];
        switch (e->unk4C) {
            case 3:
            case 4:
            case 11:
                e->unk54 = 2;
                break;
            case 8:
                e->unk54 = 3;
                break;
            default:
                e->unk54 = 1;
                break;
        }
        switch (e->unk4C) {
            case 2:
                e->unk58 = 3;
                break;
            case 8:
                e->unk58 = 5;
                break;
            case 5:
            case 6:
            case 7:
            case 9:
                e->unk58 = 4;
                break;
            default:
                e->unk58 = 0;
                break;
        }
        switch (e->unk4C) {
            case 1:
            case 2:
            case 6:
            case 7:
                e->unk5C = 1;
                break;
            case 5:
            case 9:
                e->unk5C = 2;
                break;
            default:
                e->unk5C = 0;
                break;
        }
        if (e->unk4C == 1) {
            e->unk6C = 20;
            e->unk70 = 0;
            e->unk18 = 1.0f;
            e->unk1C = -4.0f;
            e->unk64 = D_801C0578;
            if (gCourseID == DOLPHIN_PARK) {
                e->unk68 = 6;
                e->unk60 = D_800D6E70;
                e->unkB4 = D_D02BDE8;
                e->unkB8 = D_D02BDF8;
            } else if ((gCourseID == DRAKE_LAKE) && (gGameModes == GMODE_STUNT)) {
                e->unk68 = 5;
                e->unk60 = D_800D6FF0;
                e->unkB4 = D_D00E858;
                e->unkB8 = NULL;
            } else if (gCourseID == PORT_BLUE) {
                if ((gDifficulty == DIFFICULTY_NORMAL) || (D_800DAB68 != 0) || (D_800D8250 != 0)) {
                    e->unk68 = 5;
                    e->unk60 = D_800D73B0;
                    e->unkB4 = D_E010D20;
                } else if (gDifficulty == DIFFICULTY_HARD) {
                    e->unk68 = 5;
                    e->unk60 = D_800D7270;
                    e->unkB4 = D_E010C00;
                } else {
                    e->unk68 = 5;
                    e->unk60 = D_800D7130;
                    e->unkB4 = D_E010AE0;
                }
                e->unkB8 = NULL;
            } else if (gCourseID == TWILIGHT_CITY) {
                if ((e->unk50 == 0) || ((e->unk50 == 1) && (gDifficulty == DIFFICULTY_EXPERT))) {
                    e->unk68 = 1;
                    e->unk60 = D_800D74F0;
                    e->unkB4 = D_E00F348;
                    e->unkB8 = D_E00F2C0;
                } else {
                    e->unk68 = 1;
                    e->unk60 = D_800D7530;
                    e->unkB4 = D_E00F460;
                    e->unkB8 = D_E00F3D8;
                }
            } else if (gCourseID == GLACIER_COAST) {
                e->unk68 = 3;
                e->unk60 = D_800D7570;
                e->unkB4 = D_E01B7D0;
                e->unkB8 = D_E01B660;
            } else {
                e->unk68 = 6;
                e->unk60 = D_800D6CF0;
                e->unkB4 = D_101CB08;
                e->unkB8 = D_101CB18;
                e->unk4 = -24.0f;
            }
        } else if (e->unk4C == 2) {
            e->unk68 = 1;
            e->unk60 = D_800D7630;
            e->unkB4 = D_E00D678;
            e->unkB8 = D_E00D5D8;
            e->unk64 = D_801C0578;
        } else if (e->unk4C == 5) {
            e->unkB4 = D_E00D720;
            e->unkB8 = NULL;
            e->unk40 = 50.0f;
        } else if (e->unk4C == 6) {
            e->unk68 = 1;
            e->unk60 = D_800D7670;
            e->unkB4 = D_E00D7C8;
            e->unkB8 = NULL;
            e->unk64 = D_801C0578;
        } else if (e->unk4C == 7) {
            e->unk68 = 1;
            e->unk60 = D_800D76B0;
            e->unkB4 = D_E00D8A8;
            e->unkB8 = NULL;
            e->unk64 = D_801C0578;
        } else if (e->unk4C == 9) {
            e->unkB4 = D_E0109C0;
            e->unkB8 = NULL;
            e->unk40 = 25.0f;
        } else if (e->unk4C == 10) {
            e->unkB4 = D_E009808;
            e->unkB8 = NULL;
            e->unk40 = 50.0f;
        } else if ((e->unk4C == 3) || (e->unk4C == 4)) {
            e->unkB4 = NULL;
            e->unkB8 = D_E0098B0;
        } else if (e->unk4C == 8) {
            e->unkB4 = D_101EA48;
            e->unkB8 = NULL;
        } else if (e->unk4C == 11) {
            e->unkB4 = NULL;
            if (gCourseID == DOLPHIN_PARK) {
                e->unkB8 = D_800D6C9C[e->unk50];
            } else {
                e->unkB8 = D_800D6CCC[e->unk50];
            }
        } else {
            continue;
        }
        mtx = &D_801C0CD0[i];
        mf = &e->unk74;
        func_801EE6F4(mf, e->unkC, e->unk10, e->unk14, e->unk0, e->unk4, e->unk8);
        _MtxF_to_Mtx(mf, mtx);
        for (k = 0; k < e->unk68; k++) {
            box = &D_801BFD78[D_801C0578];
            if ((e->unk68 + D_801C0578) >= 33) {
                break;
            }
            src = &e->unk60[k];
            func_801EDC60(mf, src->unk0, src->unk4, src->unk8, &box->unk0, &box->unk4, &box->unk8);
            func_801EDD04(mf, src->unkC, src->unk10, src->unk14, &box->unkC, &box->unk10, &box->unk14);
            func_801EDD04(mf, src->unk18, src->unk1C, src->unk20, &box->unk18, &box->unk1C, &box->unk20);
            func_801EDD04(mf, src->unk24, src->unk28, src->unk2C, &box->unk24, &box->unk28, &box->unk2C);
            box->unk30 = src->unk30;
            box->unk34 = src->unk34;
            box->unk38 = src->unk38;
            box->unk3C = src->unk3C;
            D_801C0578++;
        }
    }
    if ((gCourseID == SUNSET_BAY) && (gPlayers == ONE_PLAYER)) {
        for (k = 0; k < 2; k++) {
            D_801BFD78[D_801C0578++] = D_800D77F0[k];
        }
    } else if (gCourseID == PORT_BLUE) {
        if ((gGameModes == GMODE_STUNT) || (gDifficulty == DIFFICULTY_NORMAL)) {
            for (k = 0; k < 2; k++) {
                D_801BFD78[D_801C0578++] = D_800D7770[k];
            }
        } else if (gDifficulty == DIFFICULTY_EXPERT) {
            for (k = 0; k < 2; k++) {
                D_801BFD78[D_801C0578++] = D_800D76F0[k];
            }
        }
    } else if (gCourseID == TWILIGHT_CITY) {
        for (k = 0; k < 4; k++) {
            D_801BFD78[D_801C0578++] = D_800D7870[k];
        }
    } else if (gCourseID == GLACIER_COAST) {
        D_801BFD78[D_801C0578++] = D_800D7970[0];
        for (k = 0; k < 16; k++) {
            D_801BFD78[D_801C0578++] = D_800D79B0[k];
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2C670/func_800744EC.s")
#endif

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
