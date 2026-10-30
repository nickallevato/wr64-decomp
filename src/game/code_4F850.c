#include "global.h"

typedef struct UnkStruct_800DACD0 {
    /* 0x00 */ s32 unk0;  /* inferred */
    /* 0x04 */ s32 unk4;  /* inferred */
    /* 0x08 */ s32 unk8;  /* inferred */
    /* 0x0C */ s32 unkC;  /* inferred */
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ s32 unk1C; /* inferred */
    /* 0x20 */ s32 unk20; /* inferred */
    /* 0x24 */ s32 unk24; /* inferred */
    /* 0x28 */ s32 unk28; /* inferred */
    /* 0x2C */ s32 unk2C; /* inferred */
    /* 0x30 */ s32 unk30; /* inferred */
    /* 0x34 */ s32 unk34; /* inferred */
    /* 0x38 */ s32 unk38; /* inferred */
    /* 0x3C */ s32 unk3C; /* inferred */
    /* 0x40 */ s32 unk40; /* inferred */
} UnkStruct_800DACD0;

typedef struct UnkStruct_800980D0_s {
    char pad[0xC0];
    u16 unkC0[20];
} UnkStruct_800980D0;

typedef struct UnkStruct_800DB4A8_s {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} UnkStruct_800DB4A8;

typedef struct UnkStruct_800DB760_s {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
} UnkStruct_800DB760; /* size = 0x8 */

typedef struct UnkStruct_801CE7E8_s {
    /* 0x00 */ u32 unk0[6];
    /* 0x18 */ u32 unk18[6];
} UnkStruct_801CE7E8; /* size = 0x30 */

typedef struct UnkStruct_800DCE98_s {
    /* 0x0 */ Gfx* unk0;
    /* 0x4 */ Gfx* unk4;
} UnkStruct_800DCE98; /* size = 0x8 */

typedef struct UnkStruct_801CE740_s {
    /* 0x0 */ s16 rider;
    /* 0x2 */ s16 unk2;
} UnkStruct_801CE740; /* size = 0x4 */

typedef struct UnkStruct_801CE7D8_s {
    s32 unk0;
    s32 unk4;
} UnkStruct_801CE7D8;

extern UnkStruct_800DB4A8 D_800DB4A8[];
extern UnkStruct_800DB4A8 D_800DB538[];
extern UnkStruct_800DB4A8 D_800DB558;
extern s32 D_800DCE18[];
extern s16 D_801CE768[];
extern UnkStruct_801CE7D8 D_801CE7D8[];
extern s32* D_800DB484[];
extern UnkStruct_801CE780 D_801CE780[];
extern UnkStruct_800DB760* D_800DB760[6];
extern s16 D_800DB778[][6];
extern UnkStruct_801CE7E8 D_801CE7E8[];
extern s32 D_800DAB90[];
extern s32 D_800DABA0[];
extern s32 D_800DABC0[];
extern UnkStruct_800DACD0 D_800DACD0[];
extern s32 D_801CE73C;
extern DmaEntry D_800DABD0[];
extern DmaEntry D_800DB330[];
extern UnkStruct_801CE740 D_801CE740[];

extern DmaEntry* D_800DC0E4[];
extern DmaEntry* D_800DC108[];
extern DmaEntry* D_800DC18C[];
extern DmaEntry* D_800DC4F0[];
extern DmaEntry* D_800DC514[];
extern DmaEntry* D_800DC698[];
extern DmaEntry* D_800DC6BC[];
extern DmaEntry* D_800DC700[];
extern DmaEntry* D_800DC728[];
extern DmaEntry D_800DC748[];
extern DmaEntry* D_800DC868[];
extern DmaEntry* D_800DC88C[];
extern DmaEntry* D_800DC8B0[];
extern DmaEntry* D_800DC8D4[];
extern DmaEntry* D_800DC93C[];
extern DmaEntry* D_800DC9FC[];
extern DmaEntry* D_800DCA38[];
extern DmaEntry* D_800DCA3C;
extern DmaEntry* D_800DCA68[];
extern DmaEntry* D_800DCA94[];
extern DmaEntry* D_800DCBE4[];
extern DmaEntry* D_800DCC08[];
extern DmaEntry* D_800DCC4C[];
extern DmaEntry* D_800DCC74[];
extern DmaEntry* D_800DCCA4[];
extern DmaEntry* D_800DCCD0[];
extern DmaEntry* D_800DCCF8[];
extern DmaEntry* D_800DCD20[];
extern DmaEntry* D_800DCD48[];
extern DmaEntry* D_800DCD84[];
extern DmaEntry* D_800DCD88;
extern DmaEntry* D_800DCDB4[];
extern DmaEntry* D_800DCE00[];
extern u8* D_800DCE84[];
extern UnkStruct_800DCE98 D_800DCE98[];
extern s32 D_801CB330;
extern u32 D_801CE6D0;
extern s32 D_801CE760[2];
extern u8* D_801CE998;
extern Gfx* D_801CE9A0[];
extern UnkStruct_80227A60 D_80227A60[];
extern Gfx* D_80227AD4;
extern Gfx* D_80227AD8;
extern Gfx* D_80227ADC;
extern Gfx* D_80227AE0;
extern Gfx* D_80227AE4;
extern u8 D_23930[];
extern Gfx D_8090510[];

extern void* D_80151954;
extern OSMesgQueue D_801540B8;
extern OSIoMesg D_801542A0;
extern s32 D_800D45EC;
extern s32 D_800DCE3C[];
extern s32 D_800DCE60[];
extern s16 D_801CE60C;
extern u32 D_801CE6E8;
extern s32 D_801CE730;
extern s32 D_801CE734;
extern s32 D_801CE738;
extern u16 D_800DCEC8[];
extern u8 D_8000D9C;
extern u8 D_8002C00;
extern u8 D_8002FA8;
extern u8 D_8003578;

void func_80095CE8(u8* arg0, s32 arg1);
void func_800967EC(u32* arg0, s32 arg1);
u32* func_800961B8(s32 arg0, s32 arg1);
u32* func_800962F0(s32 arg0);
u32* func_800963CC(s32 arg0, s32 arg1);
u32* func_800964CC(s32 arg0);
u32* func_800965B8(s32 arg0);
Gfx* func_80093DBC(Gfx* gfxPtr, u16 red, u16 green, u16 blue);

extern void game_dma_copy(uintptr_t devAddr, void* vAddr, u32 nbytes);

#ifdef NON_MATCHING
// Score 270 of 63000: one instruction. In the unrolled ceremony loop the original stores D_801CE9A0[3] through
// the at it already holds and moves the second src step (+0x88) up two stores; here another lui at is emitted.
// The two stack pads give the original's frame (0x68).
void unk_game_load(void) {
    s32 pad[5]; // stack pad
    s32 fromState67;
    s32 pad2; // stack pad
    DmaEntry** list;
    Gfx* saved30;
    Gfx* saved34;
    Gfx* saved38;
    Gfx* saved3C;
    Gfx* saved40;
    s32 course;
    s32 load;
    s32 buffer;
    s32 i;
    UnkStruct_800DCE98* e;
    UnkStruct_80227A60* src;
    DmaEntry** p;
    DmaEntry* entry;

    load = 0;
    buffer = 0;
    fromState67 = 0;
    switch (gGameState) {
        case 1: // no GAME_STATE_* name; the jump table starts at 1
            break;
        case GAME_STATE_BOOT_UP:
            load = 1;
            buffer = 3;
            list = D_800DC700;
            break;
        case GAME_STATE_TITLE_SCREEN:
            course = gCourseID;
            load = 1;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            D_800DC728[2] = D_800DC4F0[course];
            D_800DC728[3] = D_800DC698[course];
            D_800DC728[4] = D_800DC0E4[course];
            D_800DC728[5] = D_800DC18C[course];
            D_801CE998 = (u8*) ((u32) D_23930 + 0x80316800);
            list = D_800DC728;
            break;
        case GAME_STATE_DEMO:
        case GAME_STATE_TIME_TRIAL:
            course = gCourseID;
            load = 1;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            if (D_801CE608.player == 1) {
                switch (D_801CE608.gameMode) {
                    case 0:
                        list = D_800DC88C;
                        break;
                    case 0xB:
                        list = D_800DC8B0;
                        break;
                    default:
                        list = D_800DC868;
                        break;
                }
                list[2] = D_800DC4F0[course];
                list[3] = D_800DC698[course];
                if ((gCourseID == DOLPHIN_PARK) && (D_801CE608.gameMode == 4)) {
                    list[7] = D_800DC748;
                } else {
                    list[7] = NULL;
                }
                list[4] = D_800DC0E4[course];
            } else {
                list = D_800DC8D4;
                D_800DC8D4[2] = D_800DC514[course];
                D_800DC8D4[3] = D_800DC6BC[course];
                D_800DC8D4[4] = D_800DC108[course];
            }
            list[5] = D_800DC18C[course];
            break;
        case GAME_STATE_2A:
            list = D_800DC868;
            break;
        case GAME_STATE_29:
            list = D_800DC868;
            break;
        case GAME_STATE_RIDER_SELECT:
            load = 1;
            buffer = 2;
            list = D_800DC93C;
            D_800DC93C[1] = D_800DC0E4[0];
            break;
        case GAME_STATE_COURSE_SELECT:
            course = gCourseID;
            load = 1;
            buffer = 1;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            list = D_800DC9FC;
            D_800DC9FC[0] = D_800DC0E4[course];
            break;
        case GAME_STATE_RACE_RESULTS:
            course = gCourseID;
            load = 1;
            buffer = 1;
            list = D_800DCA38;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            D_800DCA3C = D_800DC0E4[course];
            break;
        case GAME_STATE_TIME_TRIALS_RESULTS:
            if (gPrevGameState != GAME_STATE_64) {
                course = gCourseID;
                load = 1;
                buffer = 1;
                if (course < 0) {
                    course = DOLPHIN_PARK;
                }
                if (course >= 9) {
                    course = SOUTHERN_ISLAND;
                }
                list = D_800DCA94;
                D_800DCA94[1] = D_800DC0E4[course];
            }
            break;
        case GAME_SATE_COURSE_OVERVIEW:
            course = D_801CB330;
            load = 1;
            if (course < 0) {
                course = 0;
            }
            if (course >= 9) {
                course = 8;
            }
            D_800DCC08[2] = D_800DC4F0[course];
            D_800DCC08[3] = D_800DC698[course];
            D_800DCC08[4] = D_800DC0E4[course];
            D_800DCC08[6] = D_800DCBE4[course];
            list = D_800DCC08;
            D_800DCC08[5] = D_800DC18C[course];
            break;
        case GAME_STATE_OPTIONS_MENU:
            load = 1;
            buffer = 1;
            list = D_800DCC4C;
            break;
        case GAME_STATE_OPTIONS_CHANGE_NAMES:
            load = 1;
            buffer = 1;
            list = D_800DCC74;
            D_800DCC74[1] = D_800DC0E4[0];
            break;
        case GAME_STATE_OPTIONS_CHANGE_CONDITIONS:
            load = 1;
            buffer = 1;
            list = D_800DCCD0;
            break;
        case GAME_STATE_OPTIONS_AUDIO:
            load = 1;
            buffer = 1;
            list = D_800DCCF8;
            break;
        case GAME_STATE_OPTIONS_SAVE_AND_LOAD:
            load = 1;
            buffer = 1;
            list = D_800DCD48;
            break;
        case GAME_STATE_OPTIONS_VIEW_RECORDS:
            load = 1;
            buffer = 1;
            list = D_800DCCA4;
            break;
        case GAME_STATE_OPTIONS_ERASE_COURSE_RECORDS:
            load = 1;
            buffer = 1;
            list = D_800DCD20;
            break;
        case GAME_STATE_64:
            course = gCourseID;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            if (D_801CE608.gameMode == 4) {
                if (gPrevGameState == GAME_STATE_67) {
                    load = 1;
                    fromState67 = 1;
                }
                list = D_800DCA68;
                D_800DCA68[0] = D_800DC0E4[course];
            } else if (D_801CE608.gameMode == 0) {
                load = 1;
                list = D_800DCA94;
                D_800DCA94[1] = D_800DC0E4[course];
            }
            buffer = 1;
            break;
        case GAME_STATE_STUNT_MODE_RESULTS:
            course = gCourseID;
            load = 1;
            buffer = 1;
            list = D_800DCD84;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            D_800DCD88 = D_800DC0E4[course];
            break;
        case GAME_STATE_36:
            course = gCourseID;
            load = 1;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            list = D_800DCDB4;
            D_800DCDB4[0] = D_800DC0E4[course];
            break;
        case GAME_STATE_CEREMONY:
            course = gCourseID;
            load = 1;
            buffer = 4;
            if (course < 0) {
                course = DOLPHIN_PARK;
            }
            if (course >= 9) {
                course = SOUTHERN_ISLAND;
            }
            list = D_800DCE00;
            D_800DCE00[3] = D_800DC0E4[course];
            break;
    }
    if (load != 0) {
        D_800D45F0 = D_800DCE84[buffer];
        D_801CE6D0 = osVirtualToPhysical(D_800D45F0);
        D_801CE730 = 0;
        if (1) { // FAKE: a permuter find; changes the register allocation of the block
            D_801CE734 = 0;
            D_801CE738 = 0;
            p = list;
            while (*p != NULL) {
                entry = *p;
                func_80095A28(entry);
                p++;
            }
            if (D_801CE730 > 0) {
                if (D_801CE760[0] != -1) {
                    saved30 = D_80227A60[0].unk30[0];
                    saved34 = D_80227A60[0].unk30[1];
                    saved38 = D_80227A60[0].unk30[2];
                    saved3C = D_80227A60[0].unk30[3];
                    saved40 = D_80227A60[0].unk30[4];
                    src = &D_80227A60[D_801CE760[0]];
                    D_80227A60[0].unk30[0] = src->unk30[0];
                    D_80227A60[0].unk30[1] = src->unk30[1];
                    D_80227A60[0].unk30[2] = src->unk30[2];
                    D_80227A60[0].unk30[3] = src->unk30[3];
                    D_80227A60[0].unk30[4] = src->unk30[4];
                }
                if (D_801CE760[1] != -1) {
                    if ((D_801CE760[1] == 0) && (D_801CE760[0] != -1)) {
                        D_80227AD4 = saved30;
                        D_80227AD8 = saved34;
                        D_80227ADC = saved38;
                        D_80227AE0 = saved3C;
                        D_80227AE4 = saved40;
                    } else {
                        src = &D_80227A60[D_801CE760[1]];
                        D_80227AD4 = src->unk30[0];
                        D_80227AD8 = src->unk30[1];
                        D_80227ADC = src->unk30[2];
                        D_80227AE0 = src->unk30[3];
                        D_80227AE4 = src->unk30[4];
                    }
                }
                if (D_801CE73C == 4) {
                    D_80227A60[4].unk0[3] = D_80227A60[2].unk0[3];
                    D_80227A60[5].unk0[3] = D_80227A60[3].unk0[3];
                    D_80227A60[2].unk0[1] = D_80227A60[0].unk0[1];
                    D_80227A60[2].unk0[3] = D_80227A60[0].unk0[3];
                    D_80227A60[3].unk0[1] = D_80227A60[1].unk0[1];
                    D_80227A60[3].unk0[3] = D_80227A60[1].unk0[3];
                }
                if (gGameState == GAME_STATE_CEREMONY) {
                    for (i = 0, src = D_80227A60; i < 4; i++, src++) {
                        e = &D_800DCE98[D_800DA9B0[i]];
                        D_801CE9A0[i] = src->unk0[2];
                        src->unk0[2] = D_8090510;
                        src->unk0[3] = e->unk0;
                        src->unk0[8] = e->unk4;
                    }
                }
            }
        }
        if (gGameState != GAME_STATE_BOOT_UP) {
            gDisplayListHead = (Gfx*) gGfxPool;
            if (fromState67 == 0) {
                gDisplayListHead = func_80093F78(gDisplayListHead);
            } else {
                gDisplayListHead = func_80093DBC(gDisplayListHead, 0xFF, 0xFF, 0xFF);
            }
            gDPFullSync(gDisplayListHead++);
            gSPEndDisplayList(gDisplayListHead++);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_4F850/unk_game_load.s")
#endif

void func_80095A28(DmaEntry* entry) {
    u32 size;
    u32 i;
    u32 var_fp;
    u32 var_s0;
    u32 flag;
    u8* data;
    u8* src;
    u8* dest;
    u32 var_v0_2;

    for (flag = entry->flag; flag != 0; entry++, flag = entry->flag) {
        size = ALIGN_2(entry->segRomEnd - entry->segRomStart);
        if (flag == 6) {
            func_80097F74(entry->segRomStart, D_800D45EC, size);
        } else {
            if (gGameState == 1) {
                func_80097F74(entry->segRomStart, 0x80360000, size);
            } else {
                func_80097F74(entry->segRomStart, 0x802A0000, size);
            }
            if (entry->flag == 5) {
                data = D_800D45E4;
                if (D_801CE608.player == 1) {
                    var_fp = D_800DCE3C[gCourseID];
                } else {
                    var_fp = D_800DCE60[gCourseID];
                }
            } else if (entry->flag == 8) {
                D_800D45E8 = D_800D45E4 + var_fp;
                D_801CE6E8 = osVirtualToPhysical(D_800D45E8);
                data = D_800D45E8;
            } else if (entry->flag == 9) {
                data = (u8*) 0x8029A200;
            } else {
                data = D_800D45F0;
            }

            data += entry->offset;

            if (gGameState == 1) {
                Mio0_Decompress((u8*) 0x80360000, data);
            } else {
                Mio0_Decompress((u8*) 0x802A0000, data);
            }

            if (entry->flag == 3) {
                src = data;
                dest = data + 0x2000;
                for (i = 0; i < 0x1000; i++) {
                    *dest++ = *src++;
                }
            } else if (entry->flag == 4) {
                osWritebackDCacheAll();
                func_80095CE8(data, D_801CE730);
                D_801CE730++;
            } else if (entry->flag == 7) {
                osWritebackDCacheAll();
                func_80096048(data, D_801CE734);
                D_801CE734++;
            } else if (entry->flag == 0xA) {
                osWritebackDCacheAll();
                func_80096694(data, entry->offset, D_801CE738);
                D_801CE738++;
            }
        }
    }
}

void func_80095CE8(u8* arg0, s32 arg1) {

    s32 var_a1;
    s32 sp68;

    s32 var_v0;
    s32 sp60;
    s32 pad; // stack pad
    s32 var_s1;
    s16* var_a2;
    u32 var_s5;
    s32 temp_s0;

    var_a2 = (s16*) &D_801CE740[arg1];
    if (var_a2[1] != 0) {
        sp60 = 2;
    } else {
        sp60 = 1;
    }

    for (sp68 = 0; sp68 < sp60; sp68++) {
        temp_s0 = (var_a2[0] * 3) + var_a2[1] + sp68;

        for (var_s5 = 0; var_s5 != 0x11; var_s5++) {

            var_v0 = 0;

            switch (var_s5) {

                case 0:

                    var_s1 = D_800DACD0[temp_s0].unk0 & 0xFFFFFF;

                    break;

                case 1:

                    var_s1 = D_800DACD0[temp_s0].unk4 & 0xFFFFFF;

                    break;

                case 2:

                    var_s1 = D_800DACD0[temp_s0].unk8 & 0xFFFFFF;

                    break;

                case 3:

                    var_s1 = D_800DACD0[temp_s0].unkC & 0xFFFFFF;

                    break;

                case 4:

                    var_s1 = D_800DACD0[temp_s0].unk10 & 0xFFFFFF;

                    break;

                case 5:

                    var_s1 = D_800DACD0[temp_s0].unk14 & 0xFFFFFF;

                    break;

                case 6:

                    var_s1 = D_800DACD0[temp_s0].unk18 & 0xFFFFFF;

                    break;

                case 7:

                    var_s1 = D_800DACD0[temp_s0].unk1C & 0xFFFFFF;

                    break;

                case 8:

                    var_s1 = D_800DACD0[temp_s0].unk20 & 0xFFFFFF;

                    break;

                case 9:

                    var_s1 = D_800DACD0[temp_s0].unk24 & 0xFFFFFF;

                    break;

                case 10:

                    var_s1 = D_800DACD0[temp_s0].unk28 & 0xFFFFFF;

                    break;

                case 11:

                    var_s1 = D_800DACD0[temp_s0].unk2C & 0xFFFFFF;

                    break;

                case 12:
                    var_v0 = 2;
                    var_s1 = D_800DACD0[temp_s0].unk30 & 0xFFFFFF;
                    break;

                case 13:
                    var_v0 = 2;
                    var_s1 = D_800DACD0[temp_s0].unk34 & 0xFFFFFF;
                    break;

                case 14:
                    var_v0 = 2;
                    var_s1 = D_800DACD0[temp_s0].unk38 & 0xFFFFFF;
                    break;

                case 15:
                    var_v0 = 2;
                    var_s1 = D_800DACD0[temp_s0].unk3C & 0xFFFFFF;
                    break;

                case 16:
                    var_v0 = 2;
                    var_s1 = D_800DACD0[temp_s0].unk40 & 0xFFFFFF;
                    break;
            }

            // @note This condition is never true
            if (var_v0 == 1) {
                if (sp68 == 1) {
                    continue;
                }
            } else if (var_v0 == 2 && *var_a2 != 2 && *var_a2 != 6) {
                continue;
            }

            if ((D_801CE73C == 3) || (D_801CE73C == 2)) {
                var_a1 = D_800DABA0[arg1];
            } else if (D_801CE73C == 4) {
                var_a1 = D_800DABC0[arg1];
            } else {
                var_a1 = D_800DAB90[arg1];
            }

            func_800967EC((u32*) (arg0 + var_s1), var_a1);
        }
    }
}

void func_80096048(void* arg0, s32 arg1) {
    s32 count;
    s32 type;
    UnkStruct_801CE780* entry;
    s32 base;
    s32 list;
    s32* table;

    type = D_801CE7D8[arg1].unk0;
    table = D_800DB484[type];
    count = 0;
    entry = &D_801CE780[arg1];
    base = D_801CE7D8[arg1].unk4 & 0xFFFFFF;
    while (1) {
        list = table[count];
        if (list == 0) {
            break;
        }
        func_800967EC((u32*) ((list & 0xFFFFFF) + (u8*) arg0), base);
        ((u32*) &entry->unk8)[count] = list + base;
        count++;
    }
    entry->unk0 = count;
    switch (type) {
        case 3:
        case 6:
            entry->unk4 = (UnkStruct_801CE780_unk4**) func_800961B8(type, base);
            break;
        case 1:
            entry->unk4 = (UnkStruct_801CE780_unk4**) func_800962F0(base);
            break;
        case 2:
        case 4:
            entry->unk4 = (UnkStruct_801CE780_unk4**) func_800963CC(type, base);
            break;
        case 0:
            entry->unk4 = (UnkStruct_801CE780_unk4**) func_800965B8(base);
            break;
        case 8:
            entry->unk4 = (UnkStruct_801CE780_unk4**) func_800964CC(base);
            break;
    }
}

u32* func_800961B8(s32 arg0, s32 arg1) {
    s32 pad; // stack pad
    s32 count;
    s32 pad2; // stack pad
    u32* sp38;
    u8* sp34;
    s32 i;
    u32* temp_s0;

    switch (arg0) {
        case 3:
            sp34 = &D_8002FA8;
            count = 1;
            break;
        case 6:
            sp34 = &D_8002C00;
            count = 1;
            break;
    }
    // For any other arg0, sp34 and count are used uninitialized, as in the original.
    sp38 = (u32*) (SegmentedToVirtual((u32) sp34) + arg1);
    for (i = 0; i < count; i++) {
        temp_s0 = (u32*) (SegmentedToVirtual(sp38[i]) + arg1);
        sp38[i] = (u32) temp_s0;
        temp_s0[1] = SegmentedToVirtual(temp_s0[1]) + arg1;
        temp_s0[2] = SegmentedToVirtual(temp_s0[2]) + arg1;
        temp_s0[3] = SegmentedToVirtual(temp_s0[3]) + arg1;
        temp_s0[4] = SegmentedToVirtual(temp_s0[4]) + arg1;
        temp_s0[5] = SegmentedToVirtual(temp_s0[5]) + arg1;
        temp_s0[6] = SegmentedToVirtual(temp_s0[6]) + arg1;
        temp_s0[7] = SegmentedToVirtual(temp_s0[7]) + arg1;
        temp_s0[8] = SegmentedToVirtual(temp_s0[8]) + arg1;
    }
    return sp38;
}

u32* func_800962F0(s32 arg0) {
    s32 pad[2]; // stack pad
    u32* sp34;
    u32* var_s2;
    u32* temp_ptr;
    s32 i;

    sp34 = var_s2 = SegmentedToVirtual((u32) &D_80030EC) + arg0;

    for (i = 0; i != 0xC; i += 4, var_s2++) {
        *var_s2 = SegmentedToVirtual(*var_s2) + arg0;
        temp_ptr = (u32*) *var_s2;
        temp_ptr[1] = SegmentedToVirtual(temp_ptr[1]) + arg0;
        temp_ptr[2] = SegmentedToVirtual(temp_ptr[2]) + arg0;
        temp_ptr[3] = SegmentedToVirtual(temp_ptr[3]) + arg0;
        temp_ptr[4] = SegmentedToVirtual(temp_ptr[4]) + arg0;
        temp_ptr[5] = SegmentedToVirtual(temp_ptr[5]) + arg0;
        temp_ptr[6] = SegmentedToVirtual(temp_ptr[6]) + arg0;
    }

    return sp34;
}

u32* func_800963CC(s32 arg0, s32 arg1) {
    s32 pad; // stack pad
    s32 count;
    s32 pad2; // stack pad
    u32* sp38;
    u8* sp34;
    s32 i;
    u32* temp_s0;

    switch (arg0) {
        case 2:
            sp34 = &D_8003578;
            count = 2;
            break;
        case 4:
            sp34 = &D_8000D9C;
            count = 1;
            break;
    }
    // For any other arg0, sp34 and count are used uninitialized, as in the original.
    sp38 = (u32*) (SegmentedToVirtual((u32) sp34) + arg1);
    for (i = 0; i < count; i++) {
        temp_s0 = (u32*) (SegmentedToVirtual(sp38[i]) + arg1);
        sp38[i] = (u32) temp_s0;
        temp_s0[1] = SegmentedToVirtual(temp_s0[1]) + arg1;
        temp_s0[2] = SegmentedToVirtual(temp_s0[2]) + arg1;
        temp_s0[3] = SegmentedToVirtual(temp_s0[3]) + arg1;
        temp_s0[4] = SegmentedToVirtual(temp_s0[4]) + arg1;
    }
    return sp38;
}

void func_800964C4(void) {
}

u32* func_800964CC(s32 arg0) {
    s32 pad[2]; // stack pad
    u32* sp34;
    u32* var_s2;
    u32 temp_s0;
    u32* temp_ptr;
    s32 i;

    var_s2 = SegmentedToVirtual((u32) &D_8001C58) + arg0;
    sp34 = var_s2;

    for (i = 0; i != 8; i += 4, var_s2++) {
        temp_s0 = SegmentedToVirtual(*var_s2) + arg0;
        *var_s2 = temp_s0;
        temp_ptr = (u32*) temp_s0;

        temp_ptr[1] = SegmentedToVirtual(temp_ptr[1]) + arg0;
        temp_ptr[2] = SegmentedToVirtual(temp_ptr[2]) + arg0;
        temp_ptr[3] = SegmentedToVirtual(temp_ptr[3]) + arg0;
        temp_ptr[4] = SegmentedToVirtual(temp_ptr[4]) + arg0;
        temp_ptr[5] = SegmentedToVirtual(temp_ptr[5]) + arg0;
        temp_ptr[6] = SegmentedToVirtual(temp_ptr[6]) + arg0;
        temp_ptr[7] = SegmentedToVirtual(temp_ptr[7]) + arg0;
    }

    return sp34;
}

u32* func_800965B8(s32 arg0) {
    s32 pad[2]; // stack pad
    u32* sp34;
    s32 var_s3;
    u32* temp_s0;
    u32* var_s2;

    var_s2 = SegmentedToVirtual((u32) &D_800C1FC) + arg0;
    sp34 = var_s2;
    for (var_s3 = 0; var_s3 < 0x20; var_s3 += 4, var_s2 += 1) {
        temp_s0 = SegmentedToVirtual(*var_s2) + arg0;
        *var_s2 = temp_s0;
        temp_s0[1] = (u32) (SegmentedToVirtual(temp_s0[1]) + arg0);
        temp_s0[2] = (u32) (SegmentedToVirtual(temp_s0[2]) + arg0);
        temp_s0[3] = (u32) (SegmentedToVirtual(temp_s0[3]) + arg0);
        temp_s0[4] = (u32) (SegmentedToVirtual(temp_s0[4]) + arg0);
        temp_s0[5] = (u32) (SegmentedToVirtual(temp_s0[5]) + arg0);
        temp_s0[6] = (u32) (SegmentedToVirtual(temp_s0[6]) + arg0);
    }
    return sp34;
}

void func_80096694(void* arg0, s32 arg1, s32 arg2) {
    s32 pad; // stack pad
    s32 course;
    s32 i;
    UnkStruct_800DB760* entry;

    if (gGameState == GAME_SATE_COURSE_OVERVIEW) {
        course = gCourseID;
    } else {
        course = arg2;
    }
    for (i = 0; i < 6; i++) {
        entry = D_800DB760[i];
        entry += course;
        if (D_800DB778[course][i] != 0) {
            D_801CE7E8[course].unk0[i] = (entry->unk0 & 0xFFFFFF) + 0x08000000;
            D_801CE7E8[course].unk18[i] = (entry->unk4 & 0xFFFFFF) + 0x08000000;
            func_800967EC((u32*) ((entry->unk0 & 0xFFFFFF) + (u8*) arg0), arg1);
            func_800967EC((u32*) ((entry->unk4 & 0xFFFFFF) + (u8*) arg0), arg1);
        } else {
            D_801CE7E8[course].unk0[i] = 0;
            D_801CE7E8[course].unk18[i] = 0;
        }
    }
}

void func_800967EC(u32* arg0, s32 arg1) {
    s32 var_a0;
    u32* temp_v1;
    u32 temp_t6;
    u32* var_v0;

    var_v0 = arg0;
loop_1: // m2c label: the loop is written as a goto; a do-while was not tried
    temp_t6 = (u32) *var_v0 >> 0x18;
    if (temp_t6 != 0xB8) {
        var_a0 = 0;
        if (temp_t6 == 4) {
            var_a0 = 1;
        } else if (temp_t6 == 0xFD) {
            var_a0 = 2;
        }
        temp_v1 = var_v0 + 1;
        if (var_a0 != 0) {
            *temp_v1 += arg1;
        }
        var_v0 += 2;
        goto loop_1; // m2c goto (loop back to loop_1)
    }
}

void func_8009684C(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 var_v1;
    s32 t6;
    s32 i;

    var_v0 = arg0;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            var_v1 = arg1;
            if (arg1 != -1) {
                D_801CE768[arg1] = 0;
            }
        } else {
            var_v1 = arg2;
            if (arg2 != -1) {
                D_801CE768[arg2] = 1;
            }
        }
        D_801CE7D8[i].unk0 = var_v1;
        D_801CE7D8[i].unk4 = var_v0;
        if (var_v1 == -1) {
            D_800DB538[i].unk8 = 0;
            D_800DB538[i].unkC = 0;
        } else {
            D_800DB538[i] = D_800DB4A8[var_v1];
            D_800DB538[i].unkC = var_v0 & 0xFFFFFF;
            var_v0 += D_800DCE18[var_v1];
            var_v0 = (var_v0 + 0x3F) & ~0x3F;
        }
    }
}

#ifdef NON_MATCHING
// Score 1493 of 134600: the original's case 2 shares one lui at between each pair of D_801CE740[].unk2 stores (here
// one lui per store, two instructions longer), and the first loop places the D_801CE740 pointer step at the end of
// the struct-copy block with the `4` for dst->flag loaded early (in the unk2 test's delay slot) and the D_800DABA0
// address in the beq delay slot (here a nop, one more instruction). Case 2 clears unk2 in a loop of four like case 3
// (IDO unrolls it into lui at stores; four separate stores use one base register). The chained D_801CE760 store
// shares one -1 as in the original. Reading alts[i] through the pointer ap gives the display-list loop's reload after
// each store, and alts declared after dl puts it at 0x40 as in the original. The order of each chained alts store
// (alts[1] = alts[2], alts[3] = alts[4], alts[5] = alts[6] in case 0; alts[3] = alts[5] in case 4) gives the
// original's store order and the registers for the 1.
// D_800DACD0's entries have UnkStruct_80227A60's layout (17 display lists).
#define MODEL(i) (*(UnkStruct_80227A60*) &D_800DACD0[i])

void func_80096960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 count;
    s32 models;
    s32 rider;
    DmaEntry* src;
    s32 offset;
    DmaEntry* dst;
    s32* dl;
    s16 alts[8];
    s16* ap;

    for (i = 0; i < 8; i++) {
        D_801CE740[i].unk2 = 1;
    }
    D_801CE760[0] = D_801CE760[1] = -1;
    D_801CE73C = arg0;
    switch (D_801CE73C) {
        case 0:
            count = 4;
            models = 7;
            D_801CE740[0].unk2 = 0;
            break;
        case 1:
            D_801CE740[1].unk2 = 0;
            count = 2;
            models = 2;
            D_801CE740[0].unk2 = D_801CE740[1].unk2;
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                D_801CE740[i].unk2 = 0;
            }
            count = 4;
            models = 4;
            break;
        case 3:
            for (i = 0; i < 8; i++) {
                D_801CE740[i].unk2 = 0;
            }
            count = 8;
            models = 8;
            break;
        case 4:
            D_801CE740[1].unk2 = 0;
            count = 4;
            models = 6;
            D_801CE740[0].unk2 = D_801CE740[1].unk2;
            break;
    }
    for (i = 0; i < count; i++) {
        dst = &D_800DB330[i];
        switch (i % 4) {
            case 0:
                rider = arg1;
                break;
            case 1:
                rider = arg2;
                break;
            case 2:
                rider = arg3;
                break;
            case 3:
                rider = arg4;
                break;
        }
        if (rider < 0) {
            rider = 0;
        }
        src = &D_800DABD0[rider];
        if (i >= 4) {
            rider += 4;
            src += 4;
        }
        D_801CE740[i].rider = rider;
        if (D_801CE740[i].unk2 != 0) {
            rider += 8;
            src += 8;
        }
        *dst = *src;
        dst->flag = 4;
        if ((D_801CE73C == 3) || (D_801CE73C == 2)) {
            dst->offset = D_800DABA0[i];
        } else if (D_801CE73C == 4) {
            dst->offset = D_800DABC0[i];
        } else {
            dst->offset = D_800DAB90[i];
        }
    }
    dst++;
    dst->segRomStart = 0;
    dst->segRomEnd = 0;
    dst->flag = 0;
    dst->offset = 0;
    for (i = 0; i < 8; i++) {
        alts[i] = 0;
    }
    switch (arg0) {
        case 0:
            D_80227A60[0] = MODEL(D_801CE740[0].rider * 3);
            D_80227A60[1] = MODEL(D_801CE740[1].rider * 3 + 1);
            D_80227A60[2] = MODEL(D_801CE740[1].rider * 3 + 2);
            D_80227A60[3] = MODEL(D_801CE740[2].rider * 3 + 1);
            D_80227A60[4] = MODEL(D_801CE740[2].rider * 3 + 2);
            D_80227A60[5] = MODEL(D_801CE740[3].rider * 3 + 1);
            D_80227A60[6] = MODEL(D_801CE740[3].rider * 3 + 2);
            if (D_801CE740[0].rider == 2) {
                alts[0] = 1;
            } else if (D_801CE740[0].rider == 6) {
                alts[0] = 2;
            }
            if (D_801CE740[1].rider == 2) {
                alts[1] = alts[2] = 1;
            } else if (D_801CE740[1].rider == 6) {
                alts[1] = alts[2] = 2;
            }
            if (D_801CE740[2].rider == 2) {
                alts[3] = alts[4] = 1;
            } else if (D_801CE740[2].rider == 6) {
                alts[3] = alts[4] = 2;
            }
            if (D_801CE740[3].rider == 2) {
                alts[5] = alts[6] = 1;
            } else if (D_801CE740[3].rider == 6) {
                alts[5] = alts[6] = 2;
            }
            for (i = 0; i < count; i++) {
                if (D_801CE740[i].rider == 2) {
                    if (i == 0) {
                        D_801CE760[0] = i;
                    } else {
                        D_801CE760[0] = (i + i) - 1;
                    }
                } else if (D_801CE740[i].rider == 6) {
                    if (i == 0) {
                        D_801CE760[1] = i;
                    } else {
                        D_801CE760[1] = (i + i) - 1;
                    }
                }
            }
            break;
        case 1:
            D_80227A60[0] = MODEL(D_801CE740[0].rider * 3);
            D_80227A60[1] = MODEL(D_801CE740[1].rider * 3);
            if (D_801CE740[0].rider == 2) {
                alts[0] = 1;
            } else if (D_801CE740[0].rider == 6) {
                alts[0] = 2;
            }
            if (D_801CE740[1].rider == 2) {
                alts[1] = 1;
            } else if (D_801CE740[1].rider == 6) {
                alts[1] = 2;
            }
            for (i = 0; i < count; i++) {
                if (D_801CE740[i].rider == 2) {
                    D_801CE760[0] = i;
                } else if (D_801CE740[i].rider == 6) {
                    D_801CE760[1] = i;
                }
            }
            break;
        case 2:
            D_80227A60[0] = MODEL(D_801CE740[0].rider * 3);
            D_80227A60[1] = MODEL(D_801CE740[1].rider * 3);
            D_80227A60[2] = MODEL(D_801CE740[2].rider * 3);
            D_80227A60[3] = MODEL(D_801CE740[3].rider * 3);
            if (D_801CE740[0].rider == 2) {
                alts[0] = 1;
            } else if (D_801CE740[0].rider == 6) {
                alts[0] = 2;
            }
            if (D_801CE740[1].rider == 2) {
                alts[1] = 1;
            } else if (D_801CE740[1].rider == 6) {
                alts[1] = 2;
            }
            if (D_801CE740[2].rider == 2) {
                alts[2] = 1;
            } else if (D_801CE740[2].rider == 6) {
                alts[2] = 2;
            }
            if (D_801CE740[3].rider == 2) {
                alts[3] = 1;
            } else if (D_801CE740[3].rider == 6) {
                alts[3] = 2;
            }
            for (i = 0; i < count; i++) {
                if (D_801CE740[i].rider == 2) {
                    D_801CE760[0] = i;
                } else if (D_801CE740[i].rider == 6) {
                    D_801CE760[1] = i;
                }
            }
            break;
        case 4:
            D_80227A60[0] = MODEL(D_801CE740[0].rider * 3);
            D_80227A60[1] = MODEL(D_801CE740[1].rider * 3);
            D_80227A60[2] = MODEL(D_801CE740[2].rider * 3 + 1);
            D_80227A60[3] = MODEL(D_801CE740[3].rider * 3 + 1);
            D_80227A60[4] = MODEL(D_801CE740[2].rider * 3 + 2);
            D_80227A60[5] = MODEL(D_801CE740[3].rider * 3 + 2);
            if (D_801CE740[0].rider == 2) {
                alts[0] = 1;
            } else if (D_801CE740[0].rider == 6) {
                alts[0] = 2;
            }
            if (D_801CE740[1].rider == 2) {
                alts[1] = 1;
            } else if (D_801CE740[1].rider == 6) {
                alts[1] = 2;
            }
            if (D_801CE740[2].rider == 2) {
                alts[2] = alts[4] = 1;
            } else if (D_801CE740[2].rider == 6) {
                alts[2] = alts[4] = 2;
            }
            if (D_801CE740[3].rider == 2) {
                alts[3] = alts[5] = 1;
            } else if (D_801CE740[3].rider == 6) {
                alts[3] = alts[5] = 2;
            }
            for (i = 0; i < 2; i++) {
                if (D_801CE740[i].rider == 2) {
                    D_801CE760[0] = i;
                } else if (D_801CE740[i].rider == 6) {
                    D_801CE760[1] = i;
                }
            }
            break;
        case 3:
            for (i = 0; i < models; i++) {
                D_80227A60[i] = MODEL(D_801CE740[i].rider * 3);
                if (D_801CE740[i].rider == 2) {
                    alts[i] = 1;
                } else if (D_801CE740[i].rider == 6) {
                    alts[i] = 2;
                }
            }
            for (i = 0; i < count; i++) {
                if (D_801CE740[i].rider == 2) {
                    D_801CE760[0] = i;
                } else if (D_801CE740[i].rider == 6) {
                    D_801CE760[1] = i;
                }
            }
            break;
    }
    for (i = 0; i < models; i++) {
        ap = &alts[i];
        switch (arg0) {
            case 0:
                if (i == 0) {
                    offset = D_800DAB90[0];
                } else {
                    offset = D_800DAB90[(i - 1) / 2 + 1];
                }
                break;
            case 1:
                offset = D_800DAB90[i];
                break;
            case 4:
                if (i < 4) {
                    offset = D_800DABC0[i];
                } else if (i == 4) {
                    offset = D_800DABC0[2];
                } else {
                    offset = D_800DABC0[3];
                }
                break;
            case 2:
            case 3:
                offset = D_800DABA0[i];
                break;
        }
        dl = (s32*) &D_80227A60[i]; // the 17 display lists as offsets
        dl[0] += offset;
        dl[1] += offset;
        dl[2] += offset;
        dl[3] += offset;
        dl[4] += offset;
        dl[5] += offset;
        dl[6] += offset;
        dl[7] += offset;
        dl[8] += offset;
        dl[9] += offset;
        dl[10] += offset;
        dl[11] += offset;
        if (*ap != 0) {
            dl[12] += offset;
        }
        if (*ap != 0) {
            dl[13] += offset;
        }
        if (*ap != 0) {
            dl[14] += offset;
        }
        if (*ap != 0) {
            dl[15] += offset;
        }
        if (*ap != 0) {
            dl[16] += offset;
        }
    }
}
#undef MODEL
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_4F850/func_80096960.s")
#endif

void func_80097E68(void) {
    DmaTransfer* transfer = D_800DAB38;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (transfer->flag != 0) {
            transfer->flag = 0;
            func_80095A28(transfer->entry);
        }
        transfer++;
    }
}

void game_dma_copy(uintptr_t devAddr, void* vAddr, u32 nbytes) {
    if (D_801540B8.validCount >= D_801540B8.msgCount) {
        osRecvMesg(&D_801540B8, &D_80151954, OS_MESG_BLOCK);
    }
    osInvalDCache(vAddr, nbytes);
    osPiStartDma(&D_801542A0, 0, 0, devAddr, osPhysicalToVirtual((uintptr_t) vAddr), nbytes, &D_801540B8);
    osRecvMesg(&D_801540B8, &D_80151954, OS_MESG_BLOCK);
}

void func_80097F74(uintptr_t devAddr, s32 vAddr, u32 arg2) {
    s32 pad[0x2]; // stack pad
    u32 sp2C;
    s32 temp_v0;
    u8* var_s0;
    s32 var_s1;
    s32 var_s2;
    u32 temp_hi;
    s32 temp_lo;

    temp_lo = arg2 / 10240U;
    temp_hi = arg2 % 10240U;

    sp2C = temp_hi;
    if ((temp_hi != 0) && (temp_hi < 0x10)) {
        sp2C = 0x10;
    }

    var_s2 = 0;
    if (temp_lo > 0) {
        var_s0 = devAddr;
        if (temp_lo > 0) {
            var_s1 = vAddr;
            do {
                game_dma_copy(var_s0, var_s1, 0x2800U);
                var_s2++;
                var_s0 += 0x2800;
                var_s1 += 0x2800;
            } while (var_s2 != temp_lo);
        }
    }

    temp_v0 = var_s2 * 0x2800;
    if (sp2C != 0) {
        game_dma_copy((u32) devAddr + temp_v0, vAddr + temp_v0, sp2C);
    }
}

void func_80098048(s32 arg0, s32 arg1) {
    s32 v1;
    u32 size;
    u32 new_var;
    u32 romAddr;
    if (arg0 == 0) {
        v1 = 0x10;
    } else {
        v1 = 0xF;
    }
    size = v1 * 0xC;
    new_var = D_800DA920[arg0];
    romAddr = (new_var & 0xFFFFFF) + (size * arg1);
    game_dma_copy((uintptr_t) (&D_165C00[romAddr]), D_801CE9B8, size);
}

void func_800980C8(void) {
}

void func_800980D0(UnkStruct_800980D0* arg0) {
    s32 i;
    s32 j;
    u16* v1;

    for (i = 0; i < 3; i++) {
        s32* var = gFrameBuffers[i];
        /* clang-format off */
        for (j = 0; j < 0x9600; j++) { *var++ = 0; }
        /* clang-format on */
    }

    v1 = D_800DCEC8;
    for (i = 56; i < 184; i++) {
        u16* v0 = (i * SCREEN_WIDTH) + arg0->unkC0;
        for (j = 0; j < 128; j++) {
            *v0++ = *v1++;
        }
    }
}
