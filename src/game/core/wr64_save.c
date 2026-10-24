#include "common.h"

typedef struct UnkStruct_8007AEFC {
    u8 unk0;
    u8 unk1;
    s8 unk2;
    s8 unk3;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s8 unk8;
    s8 unk9;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    char pad[0x3];
    s8 unk13;
} UnkStruct_8007AEFC;

typedef struct UnkStruct_8007B2E4 {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
} UnkStruct_8007B2E4;

typedef struct UnkStruct_800D8578_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_800D8578;

typedef struct UnkStruct_8007D110_s {
    u8 pad[0x16];
    u8 bitpattern;
    u8 pad33[10];
} UnkStruct_8007D110;

typedef struct UnkStruct_8007B110_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[4];
    s8 unk10[2];
    u8 unk12;
    u8 unk13;
} UnkStruct_8007B110;

typedef struct UnkStruct_8007CB68_1_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    s8 unkF;
} UnkStruct_8007CB68_1;

extern UnkStruct_8007CB68_2 gSaveImage[];
extern UnkStruct_8007CB68_2 D_801AEB38;

extern s32 D_800D8264;
extern OSPfs D_801C3AD0;
extern s32 gSaveEepromPresent;
extern u8 D_801AEA68;
extern s32 D_801CB308[1][3];
extern s32 D_801CB32C;
extern u8 gSaveCheckCode[1];
extern s32 gSaveStuntOffsets[];
extern UnkStruct_800D8578 gDefaultStuntRecords[][3];
extern UnkStruct_800D8578 gStuntRecords[][3];
extern s32 D_800D826A;
extern u8 D_800D82D8;
extern u8 D_800D82E8;
extern OSPfs D_801C3AD0;
extern u8 D_801C23B0[];
extern u8 D_800D8290[];
extern u8 D_801AEBF0[];
extern UnkStruct_8007CB68_2 gSavePakImage;
extern UnkStruct_8007B110 D_801AEA8A[];
extern UnkStruct_8007B110 D_801AEC8A[];
extern UnkStruct_8007B110 D_801C202C[8][3];
extern UnkStruct_8007B110 D_801C22D4[8];
extern UnkStruct_8007B110 D_801C23C4[8];
extern UnkStruct_func_8007AF78_1 D_800D82F8[8][4];
extern s32 D_800DA940[4];
extern s32 D_800DA988[][3];
extern u8 D_800D8728[];
extern u8 D_801AEA28[];
extern u8 D_801C24C4[];

#define SAVE_SUCCESS 0

static const char devstr1[] = "EEPROM read error 1 (%d)\n";
static const char devstr2[] = "EEPROM check code error 1\n";
static const char devstr3[] = "EEPROM check sum error %d %d\n";
static const char devstr4[] = "EEPROM write error 1 (%d)\n";
static const char devstr5[] = "no EEPROM\n";
static const char devstr6[] = "EEPROM write error\n";
static const char devstr7[] = "EEPROM write error\n";
static const char devstr8[] = "EEPROM write error\n";
static const char devstr9[] = "EEPROM write error\n";
static const char devstr10[] = "EEPROM write error\n";
static const char devstr11[] = "EEPROM write error\n";
static const char devstr12[] = "EEPROM write error\n";
static const char devstr13[] = "EEPROM write error\n";
static const char devstr14[] = "EEPROM write error\n";
static const char devstr15[] = "EEPROM write error\n";
static const char devstr16[] = "EEPROM write error\n";
static const char devstr17[] = "EEPROM write error\n";
static const char devstr18[] = "EEPROM write error\n";
static const char devstr19[] = "EEPROM write error\n";
static const char devstr20[] = "EEPROM write error\n";
static const char devstr21[] = "EEPROM write error\n";
static const char devstr22[] = "EEPROM write error\n";
static const char devstr23[] = "EEPROM write error\n";
static const char devstr24[] = "EEPROM write error\n";

s32 Save_GenCheckSum(u8*);
void func_8007BBF0(void);
s32 Save_EepromReset(void);
s32 Save_PfsIsPlug(void);
void Save_BuildDefaultImage(UnkStruct_8007CB68_2* arg);
void func_8007B630(void);
void func_8007B930(void);
s32 Save_EepromWriteAll(void);

// Encode?
s32 Save_EncodeChar(s32 arg0) {
    if ((arg0 >= 'A') && (arg0 < '[')) {
        return arg0 - 0x40;
    }
    if (arg0 == ' ') {
        return 0x1B;
    }
    if (arg0 == '-') {
        return 0x1C;
    }
    if (arg0 == '.') {
        return 0x1D;
    }
    return 0;
}

// de-encode?
s32 Save_DecodeChar(s32 arg0) {
    if ((arg0 > 0) && (arg0 < 0x1B)) {
        return arg0 + '@';
    }
    if (arg0 == 0x1B) {
        return ' ';
    }
    if (arg0 == 0x1C) {
        return '-';
    }
    if (arg0 == 0x1D) {
        return '.';
    }
    return 0;
}

void Save_PackInitials(UnkStruct_func_8007AE8C* arg0, UnkStruct_func_8007AE8C* arg1) {
    s32 sp1C;
    s32 sp18;
    s32 temp_t5;

    sp1C = Save_EncodeChar(arg1->unk0);
    sp18 = Save_EncodeChar(arg1->unk1);
    temp_t5 = Save_EncodeChar(arg1->unk2);
    arg0->unk0 = (((sp1C * 1024) + (sp18 * 32) + temp_t5) >> 8);
    arg0->unk1 = ((sp1C * 1024) + (sp18 * 32) + temp_t5) & 0xFF;
}

void Save_UnpackInitials(UnkStruct_8007AEFC* arg0, UnkStruct_8007AEFC* arg1) {
    s32 sp1C = (arg1->unk1 & 0xFF) + ((arg1->unk0 & 0x7F) << 8);

    arg0->unk0 = Save_DecodeChar((sp1C >> 10) & 0x1F);
    arg0->unk1 = Save_DecodeChar((sp1C >> 5) & 0x1F);
    arg0->unk2 = Save_DecodeChar(sp1C & 0x1F);
}

void Save_PackRecord(UnkStruct_func_8007AF78_1* arg0, UnkStruct_func_8007AF78_2* arg1) {
    s32 temp_t3;
    unsigned char new_var;
    temp_t3 = arg0->unk0;
    arg1->unk0 = (s8) (((temp_t3 >> 0x10) & 0xFFFF) + (arg0->unk7 << 5));
    new_var = temp_t3 >> 8;
    arg1->unk1 = (s8) new_var;
    new_var = temp_t3;
    arg1->unk2 = new_var ^ 0;
    Save_PackInitials((UnkStruct_func_8007AE8C*) &arg1->unk3, (UnkStruct_func_8007AE8C*) &arg0->unk10);
    arg1->unk3 = (arg1->unk3 ^ (arg0->unkB << 7));
    arg1->unk5 = arg0->unkC;
}

void Save_UnpackRecord(func_8007AFF4_arg0* arg0, func_8007AFF4_arg1* arg1) {
    s32 var_v1;
    u8 temp_t1;
    s32 a3;

    temp_t1 = arg0->unk0;
    a3 = arg0->unk1;
    var_v1 = (((temp_t1 & 0x1F) << 0x10) + (a3 << 8)) + arg0->unk2;

    if (var_v1 < 0) {
        if (temp_t1 && temp_t1) {}
        var_v1 = arg0->unk2 * 0;
    }

    if (var_v1 > 0x927BF) {
        var_v1 = 0x927BF;
    }

    arg1->unk0 = var_v1;
    temp_t1 >>= 5;
    arg1->unk4 = temp_t1 & 7;

    Save_UnpackInitials((UnkStruct_8007AEFC*) &arg1->unk10, (UnkStruct_8007AEFC*) &arg0->unk3);

    arg1->unk13 = 0;
    arg1->unk8 = (arg0->unk3 >> 7) & 1;
    arg1->unkC = arg0->unk5;
}

void Save_PackRecord5(UnkStruct_func_8007AF78_1* arg0, UnkStruct_func_8007AF78_2* arg1) {
    s32 temp_t3;
    temp_t3 = arg0->unk0;
    arg1->unk0 = ((((temp_t3) >> 16) & 0xFF) + (arg0->unk7 << 5));
    arg1->unk1 = (temp_t3 >> 8) & 0xFF;
    arg1->unk2 = temp_t3 & 0xFF;
    Save_PackInitials((UnkStruct_func_8007AE8C*) &arg1->unk3, (UnkStruct_func_8007AE8C*) &arg0->unk10);
    arg1->unk3 ^= (arg0->unkB << 7);
}

void Save_UnpackRecord5(Unkstruct_8007B1AC_arg1* arg0, UnkStruct_8007B110* arg1) {
    u8 temp_t0 = arg0->unk0;
    u8 temp_a2 = arg0->unk1;
    u8 temp_a3 = arg0->unk2;
    s32 var_v1;
    u32 temp_t1;

    var_v1 = ((temp_t0 & 0x1F) << 16) + (temp_a2 << 8) + temp_a3;

    if (var_v1 < 0) {
        var_v1 = 0;
    }

    temp_t1 = (u32) temp_t0 >> 5;

    if (var_v1 >= 0x927C0) {
        var_v1 = 0x927BF;
    }

    arg1->unk0 = var_v1;
    arg1->unk4 = temp_t1 & 7;

    Save_UnpackInitials((UnkStruct_8007AEFC*) ((u8*) arg1 + 0x10), (UnkStruct_8007AEFC*) &arg0->unk3);

    arg1->unk13 = 0;
    arg1->unk8 = (arg0->unk3 >> 7) & 1;
}

void Save_PackStuntRecord(Unkstruct_8007B1AC_arg0* arg0, Unkstruct_8007B1AC_arg1* arg1) {
    s32 new_var2;
    unsigned short new_var;
    s32 temp_t3;
    s8 new_var3;

    // looks fake
    new_var2 = arg0->unk0;
    temp_t3 = new_var2;
    new_var = temp_t3 >> 0x10;
    arg1->unk0 = new_var + (arg0->unk7 << 5);
    new_var3 = (s8) temp_t3;
    arg1->unk1 = (new_var2 = temp_t3 >> 8);
    arg1->unk2 = new_var3 & 0xFFFF;
    Save_PackInitials((UnkStruct_func_8007AE8C*) &arg1->unk3, (UnkStruct_func_8007AE8C*) &arg0->unkC);
    arg1->unk3 = (u8) (arg1->unk3 ^ (arg0->unkB << 7));
}

void Save_UnpackStuntRecord(UnkStruct_8007B2BC* arg0, UnkStruct_8007B2BC* arg1) {
    s32 temp_t0 = (u8) arg0->unk0;
    s32 temp_a2 = (u8) arg0->unk1;
    s32 temp_a3 = (u8) arg0->unk2;
    s32 var_v1;

    u8* dest_u8 = (u8*) arg1;
    s32* dest_s32 = (s32*) arg1;
    u8* src_u8 = (u8*) arg0;

    var_v1 = ((temp_t0 & 0x1F) << 16) + (temp_a2 << 8) + temp_a3;

    if (var_v1 < 0) {
        var_v1 = 0;
    }
    if (var_v1 >= 100000) {
        var_v1 = 99999;
    }

    dest_s32[0] = var_v1;
    dest_s32[1] = ((u32) temp_t0 >> 5) & 7;

    Save_UnpackInitials((UnkStruct_8007AEFC*) (dest_u8 + 0xC), (UnkStruct_8007AEFC*) (src_u8 + 3));

    dest_u8[0xF] = 0;
    dest_s32[2] = (src_u8[3] >> 7) & 1;
}

void Save_Pack24(s32 arg0, UnkStruct_8007B2BC* arg1) {
    if (arg0 < 0) {
        arg0 = 0xFFFFFF;
    }

    arg1->unk0 = (s8) (arg0 >> 0x10);
    arg1->unk1 = (arg0 >> 8) & 0xFF;
    arg1->unk2 = arg0;
}

s32 Save_Unpack24(UnkStruct_8007B2E4* arg0) {
    u8 new_var1 = arg0->unk_0;
    u8 new_var2 = arg0->unk_1;
    u8 new_var3 = arg0->unk_2;
    u32 var_a2 = ((new_var1 << 0x10) + (new_var2 << 8)) + new_var3;
    if (var_a2 == 0xFFFFFF) {
        var_a2 = -1;
    }
    return var_a2;
}

extern s8 D_801AEA20;
extern s8 D_801AEA21;
extern s8 D_801AEA22;
extern s8 D_801AEA23;
extern s8 D_801AEA24;
extern s32 D_801CB288;
extern s32 D_801CB28C;
extern s32 D_801CB290;
extern s32 D_801CB294;

void Save_PackOptions(void) {
    D_801AEA24 = D_801CB280;
    D_801AEA20 = (s8) D_801CB288;
    D_801AEA21 = (s8) D_801CB28C;
    D_801AEA22 = (s8) D_801CB290;
    D_801AEA23 = (s8) D_801CB294;
}

void Save_BuildDefaultImage(UnkStruct_8007CB68_2* arg) {
    u8* var_u8;
    s32 j;
    s32 k;
    s32 i;
    u32* dst_u32;
    u32* src_u32;

    var_u8 = (u8*) arg;
    for (i = 0; i < 0x200; i++) {
        *var_u8 = 0xFF;
        var_u8++;
    }

    for (i = 0; i < 2; i++) {
        ((u8*) arg)[i] = gSaveCheckCode[i];
    }

    for (i = 0; i < 8; i++) {
        dst_u32 = (u32*) arg;
        for (j = 0; j < 4; j++) {
            Save_PackRecord(&D_800D82F8[i][j], &arg->unk60[i][j]);
        }

        for (j = 0; j < 2; j++) {
            Save_Pack24(D_800D82F8[i][3].unk0 * (j + 1), &((UnkStruct_8007CB68_2*) dst_u32)->unk1A8[i][j]);
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            Save_PackStuntRecord(&gDefaultStuntRecords[i][j], &arg->unk120[i][j]);
        }
    }

    for (i = 0; i < 8; i++) {
        Save_PackRecord5(D_800D8728, (&arg->unk1D8[i]));
    }

    for (i = 0; i < 4; i++) {
        Libc_strncpy(arg->unk10[i], &D_800DA950[i], 10);
        for (k = 0; k < 2; k++) {
            for (j = 0; j < 3; j++) {
                arg->unk38[k][i][j] = D_800DA950[i].unk_B[j];
            }
        }
    }

    arg->unkC = 0;
    for (src_u32 = D_800DA940, dst_u32 = arg; src_u32 < ((u32*) (0x10 + ((u8*) D_800DA940))); src_u32++) {
        ((u8*) dst_u32)[8] = *src_u32;
        dst_u32 = ((u8*) dst_u32) + 1;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            arg->unk50[i][j] = D_800DA988[i][j];
        }
    }
}

extern UnkStruct_func_8007AF78_1 gBestTimes[][3];
extern UnkStruct_func_8007AF78_1 gBestLaps[];
extern s32 gBestCheckpointTimes[][9];

// Unpacks the EEPROM image into the records (courses 1-8 and the gStuntRecords table), the four names and the options.
#ifdef NON_MATCHING
// Same calls and loops; the original's frame is 0x78 (here 0x40), keeps a dead counter (1, 2, ...) in s5 in every
// loop and spills the gBestLaps pointer. Score 4527.
void func_8007B630(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            Save_UnpackRecord((func_8007AFF4_arg0*) gSaveImage->unk60[i][j], (func_8007AFF4_arg1*) &gBestTimes[i + 1][j]);
        }
        Save_UnpackRecord((func_8007AFF4_arg0*) gSaveImage->unk60[i][j], (func_8007AFF4_arg1*) &gBestLaps[i + 1]);
        for (j = 0; j < 2; j++) {
            gBestCheckpointTimes[i + 1][j] = Save_Unpack24((UnkStruct_8007B2E4*) gSaveImage->unk1A8[i][j]);
        }
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            Save_UnpackStuntRecord((UnkStruct_8007B2BC*) gSaveImage->unk120[i][j], (UnkStruct_8007B2BC*) &gStuntRecords[i][j]);
        }
    }
    for (i = 0; i < 8; i++) {
        Save_UnpackRecord5((Unkstruct_8007B1AC_arg1*) gSaveImage->unk1D8[i], (UnkStruct_8007B110*) &D_801C23B0[(i + 1) * 0x14]);
    }
    for (i = 0; i < 4; i++) {
        Libc_strncpy(&gPlayerNames[i], gSaveImage->unk10[i], 10);
        gPlayerNames[i].unk_0[10] = 0;
        for (k = 0; k < 2; k++) {
            for (j = 0; j < 3; j++) {
                gPlayerNames[(k * 4) + i].unk_B[j] = gSaveImage->unk38[k][i][j];
            }
        }
    }
    D_801CB280 = D_801AEA24;
    for (i = 0; i < 4; i++) {
        (&D_801CB288)[i] = (s8) gSaveImage->unk4[4 + i];
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            D_801CB308[i][j] = (s8) gSaveImage->unk50[i][j];
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/core/wr64_save/func_8007B630.s")
#endif

// Packs the records, the names and the options (Save_PackOptions) into the EEPROM image; the inverse of func_8007B630.
#ifdef NON_MATCHING
// Same calls and loops; the original's frame is 0x78 (here 0x40), keeps a dead counter (1, 2, ...) in s5 in every
// loop and spills the gBestLaps pointer. Score 4557.
void func_8007B930(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            Save_PackRecord(&gBestTimes[i + 1][j], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
        }
        Save_PackRecord(&gBestLaps[i + 1], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
        for (j = 0; j < 2; j++) {
            Save_Pack24(gBestCheckpointTimes[i + 1][j], (UnkStruct_8007B2BC*) gSaveImage->unk1A8[i][j]);
        }
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            Save_PackStuntRecord((Unkstruct_8007B1AC_arg0*) &gStuntRecords[i][j],
                          (Unkstruct_8007B1AC_arg1*) gSaveImage->unk120[i][j]);
        }
    }
    for (i = 0; i < 8; i++) {
        Save_PackRecord5((UnkStruct_func_8007AF78_1*) &D_801C23B0[(i + 1) * 0x14],
                      (UnkStruct_func_8007AF78_2*) gSaveImage->unk1D8[i]);
    }
    for (i = 0; i < 4; i++) {
        Libc_strncpy(gSaveImage->unk10[i], &gPlayerNames[i], 10);
        for (k = 0; k < 2; k++) {
            for (j = 0; j < 3; j++) {
                gSaveImage->unk38[k][i][j] = gPlayerNames[(k * 4) + i].unk_B[j];
            }
        }
    }
    Save_PackOptions();
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gSaveImage->unk50[i][j] = D_801CB308[i][j];
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/core/wr64_save/func_8007B930.s")
#endif

void func_8007BBE8() {
}

void func_8007BBF0() {
}

s32 Save_GenCheckSum(u8* data) {
    u16 chksum;
    s32 i;
    u8* temp;

    temp = &data[4];
    chksum = 0;

    for (i = 0; i < 508; i++) {
        chksum += *temp++;
    }

    return chksum;
}

s32 Save_EepromRead(void) {
    s32 temp_v0;
    s32 var_a1;
    s32 i;

    if (osEepromLongRead(&D_801540D0, 0x0, (u8*) gSaveImage, 0x200) != 0) {
        return 2;
    }

    for (i = 0, var_a1 = 0; i < 2; i++) {
        if (gSaveImage->unk4[i - 4] != gSaveCheckCode[i]) {
            var_a1 = 1;
            break;
        }
    }

    if (var_a1 == 0) {
        temp_v0 = Save_GenCheckSum((u8*) &gSaveImage);
        if (temp_v0 != gSaveImage->unk2) {
            var_a1 = 1;
            func_8007BBF0();
        }
    }
    if (var_a1 != 0) {
        temp_v0 = Save_EepromReset();
        if (temp_v0 != 0) {
            return temp_v0;
        }
    }
    return 0;
}

s32 Save_EepromWrite(void) {
    gSaveImage->unk2 = Save_GenCheckSum((u8*) &gSaveImage);
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) &gSaveImage, 0x200) != 0) {
        return 3;
    }
    return 0;
}

extern s32 gSaveEepromPresent;

s32 Save_EepromProbe(void) {
    if (osEepromProbe(&D_801540D0) == 0) {
        gSaveEepromPresent = 0;
        return 1;
    }
    gSaveEepromPresent = 1;
    return 0;
}

s32 Save_EepromReset(void) {
    if (gSaveEepromPresent == 0) {
        return 1;
    }
    Save_BuildDefaultImage(&gSaveImage);
    func_8007B630();
    return Save_EepromWrite();
}

s32 Save_EepromLoad(void) {
    s32 temp_v0;

    if (gSaveEepromPresent == 0) {
        Save_BuildDefaultImage(&gSaveImage);
        func_8007B630();
        return 1;
    }
    temp_v0 = Save_EepromRead();
    if (temp_v0 != 0) {
        return temp_v0;
    }
    func_8007B630();
    return 0;
}

s32 Save_EepromWriteAll(void) {
    if (gSaveEepromPresent == 0) {
        return 1;
    }
    func_8007B930();
    return Save_EepromWrite();
}

extern s32 D_800D82B0[];
extern u8 D_801AEBC0[];

// Copies course's records (the three gBestTimes entries, gBestLaps, and two gBestCheckpointTimes values) into the
// EEPROM image and writes the header, the course's unk60 row and its unk1A8 block.
s32 Save_EepromWriteCourse(s32 course) {
    s32 off;
    s32 j;
    s32 i;

    if (gSaveEepromPresent == 0) {
        return 1;
    }
    if ((course <= 0) || (course >= 9)) {
        return 0;
    }
    i = course - 1;
    for (j = 0; j < 3; j++) {
        Save_PackRecord(&gBestTimes[course][j], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
    }
    Save_PackRecord(&gBestLaps[course], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
    for (j = 0; j < 2; j++) {
        Save_Pack24(gBestCheckpointTimes[course][j], (UnkStruct_8007B2BC*) gSaveImage->unk1A8[i][j]);
    }
    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }
    if (osEepromLongWrite(&D_801540D0, ((u32) gSaveImage->unk60[i] - (u32) gSaveImage) >> 3,
                          (u8*) gSaveImage->unk60[i], 0x18) != 0) {
        return 3;
    }
    off = D_800D82B0[i];
    if (osEepromLongWrite(&D_801540D0, (((uintptr_t) D_801AEBC0 - (uintptr_t) &gSaveImage) + off) >> 3,
                          (u8*) gSaveImage->unk1A8 + off, 0x10) != 0) {
        return 3;
    }
    return 0;
}

s32 Save_EepromWriteStunt(s32 arg0) {
    s32 temp_v0;
    s32 var_v0;

    if (gSaveEepromPresent == 0) {
        return 1;
    }
    if (arg0 >= 9) {
        return 0;
    }

    for (var_v0 = 0; var_v0 < 3; var_v0++) {
        Save_PackStuntRecord((Unkstruct_8007B1AC_arg0*) &gStuntRecords[arg0][var_v0],
                      (Unkstruct_8007B1AC_arg1*) gSaveImage->unk120[arg0][var_v0]);
    }

    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }
    temp_v0 = gSaveStuntOffsets[arg0];
    if (osEepromLongWrite(&D_801540D0, ((((uintptr_t) &D_801AEB38 - (uintptr_t) &gSaveImage) + temp_v0)) >> 3,
                          (u8*) gSaveImage->unk120 + temp_v0, 0x18) != 0) {
        return 3;
    }
    return 0;
}

s32 Save_EepromWriteRecord5(s32 arg0) {
    s32 sp24[3];
    s32 temp_v0;

    if (gSaveEepromPresent == 0) {
        return 1;
    }

    if ((arg0 <= 0) || (arg0 >= 9)) {
        return 0;
    }

    sp24[0] = arg0 - 1;

    Save_PackRecord5(&D_801C23B0[arg0 * 0x14], ((u8*) gSaveImage + (arg0 * 5) + 0x1D3));
    Save_PackOptions();

    gSaveImage[0].unk2 = Save_GenCheckSum(gSaveImage);

    if (osEepromLongWrite(&D_801540D0, 0, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }

    temp_v0 = *(s32*) (&D_800D8290[sp24[0] * 4]);

    if (osEepromLongWrite(&D_801540D0, ((u32) (((u8*) D_801AEBF0 - (u8*) gSaveImage) + temp_v0) >> 3),
                          (u8*) &gSaveImage[0] + temp_v0 + 0x1D8, 0x10) != 0) {
        return 3;
    }

    return 0;
}

s32 Save_EepromWriteNames(void) {
    u8* var_s1;
    s32 var_s2;
    u32 k;
    s32 var_v0;

    if (gSaveEepromPresent == 0) {
        return 1;
    }

    var_s1 = &D_801CB308[0];

    for (var_s2 = 0; var_s2 < 4; var_s2++) {
        Libc_strncpy(&D_801AEA28[var_s2 * 10], (&gPlayerNames[var_s2]), 10);
        for (k = 0; k < 2; k++) {
            for (var_v0 = 0; var_v0 < 3; var_v0++) {
                gSaveImage->unk38[k][var_s2][var_v0] = gPlayerNames[(k * 4) + var_s2].unk_B[var_v0];
            }
        }
    }

    Save_PackOptions();

    gSaveImage->unk2 = Save_GenCheckSum(gSaveImage);

    if (osEepromLongWrite(&D_801540D0, 0, gSaveImage, 0x10) != 0) {
        k = 0;
        return 3;
    }

    if (osEepromLongWrite(&D_801540D0, ((u32) (D_801AEA28 - ((u8*) gSaveImage))) >> 3, D_801AEA28, 0x40) != 0) {
        return 3;
    }

    return 0;
}

s32 Save_EepromWriteHeader(void) {
    if (gSaveEepromPresent == 0) {
        return 1;
    }
    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }
    return 0;
}

int func_8007C50C(void) {
    int i;
    int j;

    if (gSaveEepromPresent == 0) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gSaveImage->unk50[i][j] = D_801CB308[i][j];
        }
    }

    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) &gSaveImage);
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) &gSaveImage, 16) != 0) {
        return 3;
    }

    if (osEepromLongWrite(&D_801540D0, ((u32) ((u32) &D_801AEA68 - (u32) &gSaveImage->unk0) >> 3), &D_801AEA68, 16) !=
        0) {
        return 3;
    }
    return SAVE_SUCCESS;
}

// Resets course's records to the defaults (D_800D82F8, D_800D8728) and writes them to the EEPROM.
s32 Save_EepromResetCourse(s32 course) {
    s32 off1;
    s32 off2;
    s32 off3;
    s32 i;
    s32 j;
    UnkStruct_func_8007AF78_1* lap;

    i = course - 1;
    for (j = 0; j < 3; j++) {
        gBestTimes[course][j] = D_800D82F8[i][j];
    }
    gBestLaps[course] = D_800D82F8[i][j];
    for (j = 0; j < 2; j++) {
        gBestCheckpointTimes[course][j] = D_800D82F8[i][3].unk0 * (j + 1);
    }
    lap = (UnkStruct_func_8007AF78_1*) &D_801C23B0[course * 0x14];
    *lap = *(UnkStruct_func_8007AF78_1*) D_800D8728;
    for (j = 0; j < 3; j++) {
        Save_PackRecord(&gBestTimes[course][j], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
    }
    Save_PackRecord(&gBestLaps[course], (UnkStruct_func_8007AF78_2*) gSaveImage->unk60[i][j]);
    for (j = 0; j < 2; j++) {
        Save_Pack24(gBestCheckpointTimes[course][j], (UnkStruct_8007B2BC*) gSaveImage->unk1A8[i][j]);
    }
    Save_PackRecord5(lap, (UnkStruct_func_8007AF78_2*) gSaveImage->unk1D8[i]);
    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
    if (gSaveEepromPresent == 0) {
        return 1;
    }
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }
    if (osEepromLongWrite(&D_801540D0, ((u32) gSaveImage->unk60[i] - (u32) gSaveImage) >> 3,
                          (u8*) gSaveImage->unk60[i], 0x18) != 0) {
        return 3;
    }
    off1 = gSaveStuntOffsets[course];
    if (osEepromLongWrite(&D_801540D0, (((uintptr_t) &D_801AEB38 - (uintptr_t) &gSaveImage) + off1) >> 3,
                          (u8*) gSaveImage->unk120 + off1, 0x18) != 0) {
        return 3;
    }
    off2 = D_800D82B0[i];
    if (osEepromLongWrite(&D_801540D0, (((uintptr_t) D_801AEBC0 - (uintptr_t) &gSaveImage) + off2) >> 3,
                          (u8*) gSaveImage->unk1A8 + off2, 0x10) != 0) {
        return 3;
    }
    off3 = *(s32*) &D_800D8290[i * 4];
    if (osEepromLongWrite(&D_801540D0, (((uintptr_t) D_801AEBF0 - (uintptr_t) &gSaveImage) + off3) >> 3,
                          (u8*) gSaveImage->unk1D8 + off3, 0x10) != 0) {
        return 3;
    }
    return 0;
}

s32 Save_EepromResetStunt(s32 arg0) {
    s32 temp_v0;
    s32 var_v0;

    for (var_v0 = 0; var_v0 < 3; var_v0++) {
        gStuntRecords[arg0][var_v0] = gDefaultStuntRecords[arg0][var_v0];
    }

    for (var_v0 = 0; var_v0 < 3; var_v0++) {
        Save_PackStuntRecord((Unkstruct_8007B1AC_arg0*) &gStuntRecords[arg0][var_v0],
                      (Unkstruct_8007B1AC_arg1*) gSaveImage->unk120[arg0][var_v0]);
    }

    Save_PackOptions();
    gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
    if (gSaveEepromPresent == 0) {
        return 1;
    }
    if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
        return 3;
    }
    temp_v0 = gSaveStuntOffsets[arg0];
    if (osEepromLongWrite(&D_801540D0, ((((uintptr_t) &D_801AEB38 - (uintptr_t) &gSaveImage) + temp_v0)) >> 3,
                          (u8*) gSaveImage->unk120 + temp_v0, 0x18) != 0) {
        return 3;
    }
    return 0;
}

void Save_MergePakImage(void) {
    s32 i;
    s32 j;
    UnkStruct_8007CB68_1* new_var;
    u32 k;
    s32 changed;
    UnkStruct_8007B110* new_var2;
    UnkStruct_8007CB68_2* eep;
    UnkStruct_8007B110 rec_a[3];
    UnkStruct_8007B110 rec_b[3];
    UnkStruct_8007B110 rec_tmp;
    UnkStruct_8007CB68_1 buf_a[3];
    UnkStruct_8007CB68_1 buf_b[3];
    UnkStruct_8007CB68_1 buf_tmp;

    eep = (UnkStruct_8007CB68_2*) gSaveImage;
    new_var = buf_b;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            Save_UnpackRecord(((UnkStruct_8007CB68_2*) gSaveImage)->unk60[i][j], &rec_a[j]);
            Save_UnpackRecord(((UnkStruct_8007CB68_2*) (&gSavePakImage))->unk60[i][j], &rec_b[j]);
        }

        changed = 0;
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if ((((rec_a[j].unk0 == rec_b[k].unk0) && (rec_a[j].unk4 == rec_b[k].unk4)) &&
                     (rec_a[j].unk8 == rec_b[k].unk8)) &&
                    (Libc_strncmp(rec_a[j].unk10, rec_b[k].unk10, 3) == 0)) {
                    rec_b[k].unk0 = 0x927BF;
                }
            }
        }

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (rec_b[k].unk0 < rec_a[j].unk0) {
                    rec_tmp = rec_a[j];
                    rec_a[j] = rec_b[k];
                    rec_b[k] = rec_tmp;
                    if (j == 0) {
                        changed = 1;
                    }
                }
            }
        }

        for (j = 0; j < 3; j++) {
            Save_PackRecord(&rec_a[j], ((UnkStruct_8007CB68_2*) gSaveImage)->unk60[i][j]);
        }

        if (changed) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 3; k++) {
                    ((UnkStruct_8007CB68_2*) gSaveImage)->unk1A8[i][j][k] =
                        ((UnkStruct_8007CB68_2*) (&gSavePakImage))->unk1A8[i][j][k];
                }
            }
        }
    }

    for (i = 0; i < 8; i++) {
        Save_UnpackRecord(((UnkStruct_8007CB68_2*) gSaveImage)->unk60[i][3], &rec_a[0]);
        Save_UnpackRecord(((UnkStruct_8007CB68_2*) (&gSavePakImage))->unk60[i][3], &rec_b[0]);
        if (rec_b[0].unk0 < rec_a[0].unk0) {
            new_var2 = rec_b;
            rec_a[0] = new_var2[0];
        }
        Save_PackRecord(&rec_a[0], ((UnkStruct_8007CB68_2*) gSaveImage)->unk60[i][3]);
    }

    for (i = 0; i < 8; i++) {
        Save_UnpackRecord5(((UnkStruct_8007CB68_2*) gSaveImage)->unk1D8[i], &rec_a[0]);
        Save_UnpackRecord5(((UnkStruct_8007CB68_2*) (&gSavePakImage))->unk1D8[i], &rec_b[0]);
        if (rec_b[0].unk0 < rec_a[0].unk0) {
            new_var2 = rec_b;
            rec_a[0] = new_var2[0];
        }
        Save_PackRecord5(&rec_a[0], ((UnkStruct_8007CB68_2*) gSaveImage)->unk1D8[i]);
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            Save_UnpackStuntRecord(((UnkStruct_8007CB68_2*) gSaveImage)->unk120[i][j], &buf_a[j]);
            Save_UnpackStuntRecord(((UnkStruct_8007CB68_2*) (&gSavePakImage))->unk120[i][j], &buf_b[j]);
        }

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if ((((buf_a[j].unk0 == new_var[k].unk0) && (buf_a[j].unk4 == new_var[k].unk4)) &&
                     (buf_a[j].unk8 == buf_b[k].unk8)) &&
                    (Libc_strncmp(&buf_a[j].unkC, &buf_b[k].unkC, 3) == 0)) {
                    buf_b[k].unk0 = 0;
                }
            }
        }

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (buf_a[j].unk0 < new_var[k].unk0) {
                    buf_tmp = buf_a[j];
                    buf_a[j] = new_var[k];
                    buf_b[k] = buf_tmp;
                }
            }
        }

        for (j = 0; j < 3; j++) {
            Save_PackStuntRecord(&buf_a[j], ((UnkStruct_8007CB68_2*) gSaveImage)->unk120[i][j]);
        }
    }
}

s32 Save_PfsIsPlug(void) {
    UnkStruct_8007D110 wtf;

    PRINTF("PfsisPlug: %02x %d\n", 0, 0);
    osPfsIsPlug(&D_801540D0, &wtf.bitpattern);
    if (!((1 << D_80154330[0]) & (wtf.bitpattern))) {
        D_800D8264 = 0;
        return 1;
    }
    D_800D8264 = 1;
    switch (osPfsInit(&D_801540D0, &D_801C3AD0, D_80154330[0])) {
        case 0:
            return 0;
        case 1:
        case 11:
            return 1;
        default:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            return 2;
    }
}

static const char devstr26[] = "no PFS in controller 1\n";
static const char devstr27[] = "PFS corrupted\n";
static const char devstr28[] = "no PFS in controller 1 !\n";
static const char devstr29[] = "bad PFS %d\n";
static const char devstr30[] = "PFS find file\n";

extern u8 D_800D82D8;
extern u8 D_800D82E8;
extern OSPfs D_801C3AD0;

s32 Save_PfsFindFile(void) {
    s32 ret;
    s32 fileNo;

    ret = Save_PfsIsPlug();
    if (ret != 0) {
        return ret;
    }
    ret = osPfsFindFile(&D_801C3AD0, 1U, 0x4E57524AU, &D_800D82E8, &D_800D82D8, &fileNo);
    switch (ret) {
        case 0:
            return SAVE_SUCCESS;
        case PFS_ERR_INVALID:
            PRINTF("PFS file not exists\n");
            return 4;

        default:
        case PFS_ERR_NOPACK:
        case PFS_ERR_NEW_PACK:
        case PFS_ERR_INCONSISTENT:
        case PFS_ERR_CONTRFAIL:
            PRINTF("PFS find file error %d\n", ret);
            return 2;
    }
}

s32 Save_PfsCheckFree(void) {
    s32 ret;
    s32 bytesFree;

    ret = Save_PfsIsPlug();
    if (ret != 0) {
        return ret;
    }
    ret = osPfsFreeBlocks(&D_801C3AD0, &bytesFree);
    switch (ret) {
        case 0:
            PRINTF("PFS free size %d\n", bytesFree);
            if (bytesFree >= 0x200) {
                return SAVE_SUCCESS;
            }
            return 3;
        case PFS_ERR_INVALID:
            PRINTF("PFS file not exists\n");
            return 4;
        default:
        case PFS_ERR_NOPACK:
        case PFS_ERR_NEW_PACK:
        case PFS_ERR_INCONSISTENT:
        case PFS_ERR_CONTRFAIL:
            PRINTF("PFS check free error %d\n", ret);
            return 2;
    }
}

static const char devstr36[] = "file_no: %d\n";
static const char devstr37[] = "PFS check code error\n";
static const char devstr38[] = "PFS check sum error %d %d\n";
static const char devstr39[] = "EEPROM write error\n";
static const char devstr40[] = "EEPROM write error\n";
static const char devstr41[] = "PFS read error\n";
static const char devstr42[] = "PFS no data\n";
static const char devstr43[] = "PFS file not exists ... making\n";
static const char devstr44[] = "PFS data full\n";
static const char devstr45[] = "PFS allocate file error %d\n";
static const char devstr46[] = "PFS write file error %d\n";
static const char devstr47[] = "PFS read error (write)\n";
static const char devstr48[] = "PFS check code error\n";
static const char devstr49[] = "PFS check sum error %d %d\n";
static const char devstr50[] = "file_no: %d\n";
static const char devstr51[] = "PFS write error\n";
static const char devstr52[] = "PFS no delete file\n";
static const char devstr53[] = "PFS delete error %d\n";

// The whole 0x200-byte save image, copied as words.
typedef struct SaveBlock {
    u32 w[0x80];
} SaveBlock;

// Reads the save file from the Controller Pak into gSavePakImage, checks its code and checksum, and takes part of it:
// mode 0 the whole image, 1-4 name mode - 1 (with 0x80 added, only its three bytes, into the second set), 5 the
// merged records (Save_MergePakImage). The result is written to the EEPROM.
#ifdef NON_MATCHING
// The frame is 8 bytes smaller (each slot 8 lower), and the read result is copied to v1 (v0/v1 swap). Score 931.
extern u8 D_801AEA78[];

s32 func_8007D2D4(s32 mode) {
    s32 n;
    s32 ret;
    s32 i;
    s32 second;
    s32 fileNo;

    second = 0;
    ret = Save_PfsIsPlug();
    if (ret != 0) {
        return ret;
    }
    if (mode >= 0x80) {
        mode -= 0x80;
        second = 1;
    }
    if (osPfsFindFile(&D_801C3AD0, 1U, 0x4E57524AU, &D_800D82E8, &D_800D82D8, &fileNo) == 0) {
        ret = osPfsReadWriteFile(&D_801C3AD0, fileNo, PFS_READ, 0, 0x200, (u8*) &gSavePakImage);
        switch (ret) {
            case 0:
                for (i = 0; i < 2; i++) {
                    if (gSavePakImage.unk4[i - 4] != gSaveCheckCode[i]) {
                        return 6;
                    }
                }
                if (Save_GenCheckSum((u8*) &gSavePakImage) != gSavePakImage.unk2) {
                    return 6;
                }
                func_8007B930();
                switch (mode) {
                    case 0:
                        // FAKE: UnkStruct_8007CB68_2 is only 2-byte aligned, so a plain struct copy uses lwl/lwr
                        *(SaveBlock*) gSaveImage = *(SaveBlock*) &gSavePakImage;
                        func_8007B630();
                        if (Save_EepromWrite() != 0) {
                            return 5;
                        }
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                        n = mode - 1;
                        if (second == 0) {
                            Libc_strncpy(gSaveImage->unk10[n], gSavePakImage.unk10[n], 10);
                        }
                        for (i = 0; i < 3; i++) {
                            gSaveImage->unk38[second][n][i] = gSavePakImage.unk38[0][n][i];
                        }
                        func_8007B630();
                        if (Save_EepromWriteNames() != 0) {
                            return 5;
                        }
                        break;
                    case 5:
                        Save_MergePakImage();
                        func_8007B630();
                        Save_PackOptions();
                        gSaveImage->unk2 = Save_GenCheckSum((u8*) gSaveImage);
                        if (gSaveEepromPresent != 0) {
                            if (osEepromLongWrite(&D_801540D0, 0U, (u8*) gSaveImage, 0x10) != 0) {
                                return 3;
                            }
                            if (osEepromLongWrite(&D_801540D0, ((u32) D_801AEA78 - (u32) gSaveImage) >> 3, D_801AEA78,
                                                  0x1A0) != 0) {
                                return 5;
                            }
                            break;
                        }
                        return 5;
                }
                return 0;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                return 2;
            default:
                return ret;
        }
    } else {
        return 4;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/core/wr64_save/func_8007D2D4.s")
#endif

// Writes the save image to the Controller Pak file (making it when there is none): mode 0 the whole image, 1-4 name
// mode - 1 (0x80 added is ignored), 5 the records. When the file is new or its data is bad, the rest of the image
// starts from the defaults (Save_BuildDefaultImage).
#ifdef NON_MATCHING
// Same calls and jump tables; the original places the code that follows the file switch right after its case 0
// (the new-file case jumps back into it), so blocks are ordered differently and registers differ. Score 4441.
s32 func_8007D614(s32 mode) {
    s32 n;
    s32 ret;
    s32 fresh;
    s32 i;
    s32 j;
    s32 k;
    s32 fileNo;

    ret = Save_PfsIsPlug();
    if (ret != 0) {
        return ret;
    }
    if (mode >= 0x80) {
        mode -= 0x80;
    }
    switch (osPfsFindFile(&D_801C3AD0, 1U, 0x4E57524AU, &D_800D82E8, &D_800D82D8, &fileNo)) {
        case 0:
            fresh = 0;
            break;
        default:
        case PFS_ERR_NOPACK:
        case PFS_ERR_NEW_PACK:
        case PFS_ERR_INCONSISTENT:
        case PFS_ERR_CONTRFAIL:
            return 2;
        case PFS_ERR_INVALID:
            fresh = 1;
            switch (osPfsAllocateFile(&D_801C3AD0, 1U, 0x4E57524AU, &D_800D82E8, &D_800D82D8, 0x200, &fileNo)) {
                case 0:
                    break;
                case PFS_DIR_FULL:
                    return 3;
                default:
                case PFS_ERR_NOPACK:
                case PFS_ERR_NEW_PACK:
                case PFS_ERR_INCONSISTENT:
                case PFS_ERR_CONTRFAIL:
                case PFS_ERR_INVALID:
                case PFS_ERR_BAD_DATA:
                case PFS_DATA_FULL:
                    return 2;
            }
            break;
    }
    func_8007B930();
    if ((mode != 0) && (fresh == 0)) {
        switch (osPfsReadWriteFile(&D_801C3AD0, fileNo, PFS_READ, 0, 0x200, (u8*) &gSavePakImage)) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                return 2;
            default:
                for (i = 0; i < 2; i++) {
                    if (gSavePakImage.unk4[i - 4] != gSaveCheckCode[i]) {
                        fresh = 1;
                    }
                }
                if (Save_GenCheckSum((u8*) &gSavePakImage) != gSavePakImage.unk2) {
                    fresh = 1;
                }
                break;
        }
    }
    if (fresh != 0) {
        Save_BuildDefaultImage(&gSavePakImage);
    }
    switch (mode) {
        case 0:
            // FAKE: UnkStruct_8007CB68_2 is only 2-byte aligned, so a plain struct copy uses lwl/lwr
            *(SaveBlock*) &gSavePakImage = *(SaveBlock*) gSaveImage;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            n = mode - 1;
            Libc_strncpy(gSavePakImage.unk10[n], gSaveImage->unk10[n], 10);
            for (i = 0; i < 3; i++) {
                gSavePakImage.unk38[0][n][i] = gSaveImage->unk38[0][n][i];
            }
            break;
        case 5:
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 4; j++) {
                    for (k = 0; k < 6; k++) {
                        gSavePakImage.unk60[i][j][k] = gSaveImage->unk60[i][j][k];
                    }
                }
                for (j = 0; j < 2; j++) {
                    for (k = 0; k < 3; k++) {
                        gSavePakImage.unk1A8[i][j][k] = gSaveImage->unk1A8[i][j][k];
                    }
                }
                for (k = 0; k < 5; k++) {
                    gSavePakImage.unk1D8[i][k] = gSaveImage->unk1D8[i][k];
                }
            }
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 3; j++) {
                    for (k = 0; k < 5; k++) {
                        gSavePakImage.unk120[i][j][k] = gSaveImage->unk120[i][j][k];
                    }
                }
            }
            break;
    }
    gSavePakImage.unk2 = Save_GenCheckSum((u8*) &gSavePakImage);
    switch (osPfsReadWriteFile(&D_801C3AD0, fileNo, PFS_WRITE, 0, 0x200, (u8*) &gSavePakImage)) {
        case 0:
            return 0;
        default:
        case PFS_ERR_NOPACK:
        case PFS_ERR_NEW_PACK:
        case PFS_ERR_INCONSISTENT:
        case PFS_ERR_CONTRFAIL:
        case PFS_ERR_INVALID:
        case PFS_ERR_BAD_DATA:
            return 2;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/core/wr64_save/func_8007D614.s")
#endif

s32 Save_PfsDeleteFile(void) {
    s32 ret;

    ret = Save_PfsIsPlug();
    if (ret != 0) {
        return ret;
    }
    ret = osPfsDeleteFile(&D_801C3AD0, 1U, 0x4E57524AU, &D_800D82E8, &D_800D82D8);
    switch (ret) { /* irregular */
        case 0:
            return SAVE_SUCCESS;
        case PFS_ERR_INVALID:
            return 4;
        default:
            return 2;
    }
}
