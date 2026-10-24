#include "common.h"

typedef struct UnkStruct_801DB024 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkStruct_801DB024;

typedef struct UnkStruct_801DB0E4_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    f32 unk14[3];
    f32 unk24[3];
    f32 unk30;
} UnkStruct_801DB0E4_arg0;

typedef struct UnkStruct_801DB0E4_arg1 {
    f32 unk0[3];
    f32 unk4[3];
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} UnkStruct_801DB0E4_arg1;

typedef struct UnkStruct_801DBF68_s0 {
    s32 unk0;
    s32 unk4;
    struct UnkStruct_801DB0E4_arg1* unk8;
    s8 pad[0x1C];
} UnkStruct_801DBF68_s0;

typedef struct UnkStruct_801DBF68 {
    UnkStruct_801DBF68_s0 unk0[4];
} UnkStruct_801DBF68;

extern struct UnkStruct_801DBF68 D_80225CF4;

typedef struct UnkStruct_801DC0AC {
    UnkStruct_801DBF68_s0 unk0[3];
} UnkStruct_801DC0AC;

extern UnkStruct_801DC0AC D_80225D94;

typedef struct UnkStruct_801DD2D0_Pos {
    f32 unk0[2][6];
} UnkStruct_801DD2D0_Pos;

typedef struct UnkStruct_801DD2D0_Group {
    u32 start;
    u32 end;
    UnkStruct_801DB0E4_arg1 data;
} UnkStruct_801DD2D0_Group; // size = 0x3C

typedef struct UnkStruct_801DD2D0_Groups {
    UnkStruct_801DD2D0_Group unk0[2];
} UnkStruct_801DD2D0_Groups;

extern UnkStruct_801DD2D0_Pos D_80225E68;
extern UnkStruct_801DD2D0_Groups D_80225E98;
extern UnkStruct_801DBF68_s0 D_80225E0C;

void func_800AB92C(void);

#define ANG_NORMALIZE_1(x) (x < 0.0f ? 360.0f : 0.0f)
#define ANG_NORMALIZE_2(x) (x > 360.0f ? -360.0f : 0.0f)

#define SIGNF(x) (x >= 0 ? 1.0f : -1.0f)

extern s32 D_80228110[];
extern struct UnkStruct_801DB0E4_arg0 D_80228190[];
extern s32 D_802287A8;
extern s32 D_802287AC;

// A keyframed object (type 1, 2, 3 or 5) and the script runner that drives it.
// Layouts come from the copies and stores in func_801DEF84..func_801DFE80 and func_801E0F8C.
typedef struct UnkA95D0_Base {
    /* 0x00 */ f32 unk0[3];
    /* 0x0C */ f32 unkC[3];
    /* 0x18 */ f32 unk18[3];
    /* 0x24 */ f32 unk24[3];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40[2];
    /* 0x48 */ f32 unk48[2];
    /* 0x50 */ f32 unk50[2];
} UnkA95D0_Base; // size = 0x58

// A value eased toward a target: value += (target - value) * rate.
typedef struct UnkA95D0_Ease {
    /* 0x00 */ f32 value;
    /* 0x04 */ f32 target;
    /* 0x08 */ f32 rate;
} UnkA95D0_Ease; // size = 0xC

typedef struct UnkA95D0_Payload1 {
    /* 0x00 */ f32 unk0[3];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10[3];
    /* 0x1C */ f32 unk1C;
} UnkA95D0_Payload1; // size = 0x20

typedef struct UnkA95D0_Payload2 {
    /* 0x00 */ f32 unk0[3];
    /* 0x0C */ f32 unkC[2];
    /* 0x14 */ UnkA95D0_Ease unk14[3];
} UnkA95D0_Payload2; // size = 0x38

typedef struct UnkA95D0_Payload5 {
    /* 0x00 */ f32 unk0[3];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18[2];
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24[2];
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ UnkA95D0_Ease unk48[3];
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ f32 unk70;
    /* 0x74 */ s32 unk74[3];
    /* 0x80 */ s32 unk80;
} UnkA95D0_Payload5; // size = 0x84

typedef struct UnkA95D0_Key1 {
    /* 0x00 */ UnkA95D0_Base base;
    /* 0x58 */ UnkA95D0_Payload1 p;
} UnkA95D0_Key1;

typedef struct UnkA95D0_Key2 {
    /* 0x00 */ UnkA95D0_Base base;
    /* 0x58 */ UnkA95D0_Payload2 p;
} UnkA95D0_Key2;

typedef struct UnkA95D0_Key5 {
    /* 0x00 */ UnkA95D0_Base base;
    /* 0x58 */ UnkA95D0_Payload5 p;
} UnkA95D0_Key5;

typedef struct UnkA95D0_Obj {
    /* 0x00 */ s32 type;
    /* 0x04 */ UnkA95D0_Base base;
    /* 0x5C */ union {
        UnkA95D0_Payload1 p1;
        UnkA95D0_Payload2 p2;
        UnkA95D0_Payload5 p5;
    } u;
} UnkA95D0_Obj; // size = 0xE0

// A spline cursor: frame within the segment and segment index (-1 when done).
typedef struct UnkA95D0_Cursor {
    /* 0x00 */ s32 frame;
    /* 0x04 */ s32 seg;
} UnkA95D0_Cursor; // size = 0x8

typedef struct UnkA95D0_Spline3 {
    /* 0x00 */ s32 count;
    /* 0x04 */ f32* points[3];
    /* 0x10 */ s32* durations;
} UnkA95D0_Spline3; // size = 0x14

typedef struct UnkA95D0_Spline1 {
    /* 0x00 */ s32 count;
    /* 0x04 */ f32* points;
    /* 0x08 */ s32* durations;
} UnkA95D0_Spline1; // size = 0xC

struct UnkA95D0_Runner;

typedef struct UnkA95D0_Step {
    /* 0x00 */ s32 duration;
    /* 0x04 */ void (*func)(struct UnkA95D0_Runner*, s32);
    /* 0x08 */ s32 arg;
} UnkA95D0_Step; // size = 0xC

typedef struct UnkA95D0_Runner {
    /* 0x00 */ UnkA95D0_Obj* obj;
    /* 0x04 */ UnkA95D0_Step* step;
    /* 0x08 */ s32 frame;
    /* 0x0C */ UnkA95D0_Cursor* cursors;
    /* 0x10 */ f32* unk10[10];
} UnkA95D0_Runner; // size = 0x38

void func_801DEA94(UnkA95D0_Cursor* cursors, s32 count);
extern UnkA95D0_Runner D_80228058[];
extern UnkA95D0_Obj D_80227E98[];
void func_800AB95C(s32, s32);
extern UnkA95D0_Step D_80223F7C[];
extern UnkA95D0_Step D_80224D9C[];
extern UnkA95D0_Step D_80224F98[];
extern UnkA95D0_Step D_8022512C[];
extern UnkA95D0_Step D_802252B4[];
extern UnkA95D0_Step D_802254F4[];
extern UnkA95D0_Step D_80225804[];
void func_801DFC48(UnkA95D0_Obj* obj);
void func_801DFCB8(UnkA95D0_Runner* runner);
void func_801DD6B4(UnkA95D0_Runner* runner);
s32 func_8009CB68(void);
u8 func_8009CCE8(UnkStruct_func_8009CCE8* arg0);
extern UnkA95D0_Step D_80223A30[];
extern UnkA95D0_Step D_80223D38[];
extern UnkA95D0_Step D_80224060[];
extern UnkA95D0_Step D_802241E0[];
extern UnkA95D0_Step D_802242C0[];
extern UnkA95D0_Step D_80224430[];
extern UnkA95D0_Step D_802245B4[];
extern UnkA95D0_Step D_802246B4[];
extern UnkA95D0_Step D_80224944[];
extern UnkA95D0_Key1 D_80225A84;
extern UnkA95D0_Key5 D_80225AFC;
extern UnkA95D0_Key5 D_80225BD8;
void func_801DFD94(UnkA95D0_Runner* runner, UnkA95D0_Step* step);
void func_801E0F8C(camera_unk_1* cam, UnkA95D0_Obj* obj);
void func_801E0FF0(camera_unk_1* cam);
void func_801E11B4(GfxPool* pool, camera_unk_1* cam);
extern f32 D_80223940[];
extern f32 D_80223950[];
extern f32 D_80223960[];
extern f32 D_80223970[];
extern UnkA95D0_Cursor D_802280C8[][4];
extern f32 D_80228108;
void func_801DFD8C(UnkA95D0_Runner* runner, UnkA95D0_Obj* obj);
void func_801DFDA0(UnkA95D0_Runner* runner, UnkA95D0_Cursor* cursors);
void func_801DFDA8(UnkA95D0_Runner* runner, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6,
                   f32* arg7, f32* arg8, f32* arg9, f32* arg10);
extern RiderStruct D_801C2C70[];
void func_801DB8F0(UnkA95D0_Runner* runner);
void func_801DC0AC(UnkA95D0_Runner* runner);
void func_801DC274(UnkA95D0_Runner* runner);
void func_801DC60C(UnkA95D0_Runner* runner);
void func_801DCD34(UnkA95D0_Runner* runner);
void func_801DD2D0(UnkA95D0_Runner* runner);
void func_800AC098(UnkStruct_801DB0E4_arg0* arg0, s32 arg1);
extern UnkA95D0_Step D_80224B14[];
extern UnkStruct_801DB0E4_arg1 D_80225E34;
extern f32 D_80228120[][2];
void func_801DF744(UnkA95D0_Obj* obj);
void func_801DF38C(UnkA95D0_Obj* obj);
void func_801DF128(UnkA95D0_Obj* obj);
void func_801DF2F8(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4);
void func_801DDEDC(camera_unk_1* cam, UnkA95D0_Obj* obj, UnkA95D0_Runner* runner);
void func_801DEEC4(UnkA95D0_Obj* obj);
void func_801DF5F0(UnkA95D0_Obj* obj, UnkA95D0_Key5* key);
f32 func_801DE690(f32 t, s32 seg, f32* points, s32 count);
// Degrees to a gSinTable index (4096 steps per turn).
f32 func_801ED154(f32, f32);
#define DEG_TO_BINANG(x) ((s32) (((x) * 4096.0f) / 360.0f))
void func_801DF08C(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4);
void func_801DEE48(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines);
void func_801DEDE8(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines);
void func_801DED88(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines);
void func_801DEB08(f32* out, UnkA95D0_Cursor* cursor, UnkA95D0_Spline1* spline);
void func_801DEC00(f32* out, UnkA95D0_Cursor* cursor, UnkA95D0_Spline3* spline);
void func_801DF278(UnkA95D0_Obj* obj, s32 type, UnkA95D0_Key2* key);
void func_801DF008(UnkA95D0_Obj* obj, UnkA95D0_Key1* key);

// TODO: Improve these matches
void func_801DAFA0(void** arg0, s32 arg1) {
    *(f32*) (((u8*) (*arg0)) + 0x50) = 3.0f;
}

void func_801DAFB8(void* arg0) {
    u32 randVal;
    u32 result;
    void* savedArg0 = arg0;

    randVal = SysUtils_Rand();
    if ((randVal & 7) != 0) {
        result = SysUtils_Rand();
        *(u32*) ((u8*) savedArg0 + 8) = result % 15;
        return;
    }

    result = SysUtils_Rand();
    *(u32*) ((u8*) savedArg0 + 8) = (result % 19) + 0x19;
}

void func_801DB024(struct UnkStruct_801DB0E4_arg0* arg0) {
    if ((arg0->unk8 >= 0) && (((arg0->unk8 < 0x10)))) {
        arg0->unk8 += 2;
        if (arg0->unk8 >= 0x10) {
            if (SysUtils_Rand() & 7) {
                arg0->unk8 = 0;
            } else {
                arg0->unk8 = 0x10;
            }
        }
    } else {
        if ((arg0->unk8 >= 0x19) && (((arg0->unk8 < 0x2D)))) {
            arg0->unk8++;
            if (arg0->unk8 >= 0x2D) {
                if (SysUtils_Rand() & 0xF) {
                    arg0->unk8 = 0x2D;
                    return;
                }
                arg0->unk8 = 0x19;
            }
        } else {
            arg0->unk8++;
            if (arg0->unk8 >= 0x37) {
                arg0->unk8 = 0;
            }
        }
    }
}

void func_801DB0E4(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    f32 vec[3];
    f32 magnitud;
    s32 i;

    arg0->unk0 = 3;
    arg0->unk4 = 0;

    func_801DAFB8(arg0);

    for (i = 0; i < 3; i++) {
        arg0->unkC[i] = arg1->unk0[i];
        vec[i] = arg1->unk4[i] - arg1->unk0[i];
    }

    magnitud = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

    for (i = 0; i < 3; i++) {
        arg0->unk14[i] = vec[i] / magnitud;
    }

    arg0->unk24[0] = 0.0f;
    arg0->unk24[1] = 1.0f;
    arg0->unk24[2] = 0.0f;
    arg0->unk30 = 0.1f;

    *arg2 = arg1->unk1C;
}

void func_801DB1DC(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    s32 i;

    func_801DB024(arg0);

    if (*arg2 > 0) {
        for (i = 0; i < 3; i++) {
            arg0->unkC[i] += arg0->unk14[i] * arg1->unk18;
        }
        return;
    }

    arg0->unk0 = 0;
}

void func_801DB284(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    s32 var_s1;
    s32 var_s6;

    for (var_s6 = 0; var_s6 < arg3; var_s6++, arg0++) {
        arg0->unk0 = 3;
        arg0->unk4 = 0;

        func_801DAFB8(arg0);

        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            arg0->unkC[var_s1] = ((arg1->unk0[var_s1] + arg1->unk4[var_s1]) - (arg1->unk4[var_s1 + 3] * 0.5f)) +
                                 (((f32) (SysUtils_Rand() % 256) / 256) * arg1->unk4[var_s1 + 3]);
        }

        arg0->unk30 = 0.1f;
        arg2[var_s6][0] = SysUtils_Rand() % 360;
        arg2[var_s6][1] = SysUtils_Rand() % 360;
    }
}

void func_801DB430(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    f32 magnitude; // f20
    s32 i;
    f32 vec[3];
    s32 j;

    for (i = 0; i < arg3; i++, arg0++) {
        func_801DB024(arg0);
        vec[0] = COS((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[2] = SIN((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[1] =
            (SIN((s32) ((arg2[i][1] * 4096.0f) / 360.0f)) * arg1->unk30) * (1.0f - ((SysUtils_Rand() & 3) / 20.0f));

        if (vec[1] * ((arg1->unk0[1] - arg0->unkC[1])) > 0) {
            vec[1] *= 1.2f;
        }

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        for (j = 0; j < 3; j++) {
            arg0->unk14[j] = vec[j] / magnitude;
            arg0->unkC[j] += arg0->unk14[j] * (arg1->unk24 + (f32) (SysUtils_Rand() & 1));
        }

        vec[0] = arg1->unk0[0] - arg0->unkC[0];

        vec[2] = arg1->unk0[2] - arg0->unkC[2];

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[2]));

        if (magnitude > 0.0f) {
            magnitude = 1 / magnitude;
        }

        vec[0] *= magnitude * 3.0f;
        vec[2] *= magnitude * 3.0f;
        vec[1] = arg1->unk24 / arg1->unk28;

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        arg0->unk24[0] = vec[0] / magnitude;
        arg0->unk24[1] = vec[1] / magnitude;
        arg0->unk24[2] = vec[2] / magnitude;

        magnitude = (arg0->unk14[0] * vec[2]) - (arg0->unk14[2] * vec[0]);

        arg2[i][0] += (SIGNF(magnitude) * (arg1->unk28 + (SysUtils_Rand() % 31U * 0.125f)));
        arg2[i][0] += ANG_NORMALIZE_2(arg2[i][0]) + ANG_NORMALIZE_1(arg2[i][0]);
        arg2[i][1] += ((arg1->unk2C * (0.9f + ((f32) (SysUtils_Rand() & 3) / 20.0f))));
        arg2[i][1] += ANG_NORMALIZE_2(arg2[i][1]);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DB8F0.s")

void func_801DBF68(struct UnkStruct_801DB0E4_arg0* arg0) {
    s32 var_s2;
    UnkStruct_801DBF68 sp4C = D_80225CF4;
    s32 i;

    if (arg0->unk8 == 0) {
        func_800AB92C();
    }

    for (var_s2 = 0; var_s2 < D_802287AC; var_s2++) {
        if ((arg0->unk8 >= sp4C.unk0[var_s2].unk0) && (arg0->unk8 < sp4C.unk0[var_s2].unk4)) {
            D_802287A8 = 1;

            if (arg0->unk8 == sp4C.unk0[var_s2].unk0) {
                func_801DB0E4(&D_80228190[0], (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110[0]);
            }
            func_801DB1DC(&D_80228190[0], (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110[0]);
        }
    }
}

void func_801DC0AC(UnkA95D0_Runner* runner) {
    s32 i;
    UnkStruct_801DC0AC sp6C = D_80225D94;
    UnkStruct_801DBF68_s0 sp44 = D_80225E0C;

    if (runner->frame == 0) {
        func_800AB92C();
    }
    for (i = 0; i < 3; i++) {
        if ((runner->frame >= sp6C.unk0[i].unk0) && (runner->frame < sp6C.unk0[i].unk4)) {
            D_802287A8++;
            if (runner->frame == sp6C.unk0[i].unk0) {
                func_801DB0E4(&D_80228190[0], (UnkStruct_801DB0E4_arg1*) &sp6C.unk0[i].unk8, &D_80228110[0]);
            }
            func_801DB1DC(&D_80228190[0], (UnkStruct_801DB0E4_arg1*) &sp6C.unk0[i].unk8, &D_80228110[0]);
        }
    }
    if ((runner->frame >= sp44.unk0) && (runner->frame < sp44.unk4)) {
        D_802287A8++;
        if (runner->frame == sp44.unk0) {
            func_801DB0E4(&D_80228190[1], (UnkStruct_801DB0E4_arg1*) &sp44.unk8, &D_80228110[1]);
        }
        func_801DB1DC(&D_80228190[1], (UnkStruct_801DB0E4_arg1*) &sp44.unk8, &D_80228110[1]);
    }
}

#ifdef NON_MATCHING
extern s32 D_80228194;
extern s32 D_80228198;
extern f32 D_8022819C;
extern f32 D_802281A0;
extern f32 D_802281A4;
extern f32 D_802281B4;
extern f32 D_802281B8;
extern f32 D_802281BC;
extern f32 D_802281C0;

// The init stores and the D_80228198 increment get a shared base register here; the original keeps them apart.
void func_801DC274(UnkA95D0_Runner* runner) {
    f32 vec[3];
    UnkStruct_801DB0E4_arg0* e;
    f32 mag;
    s32 i;

    if (runner->step - D_80223A30 != 2) {
        return;
    }
    D_802287A8 = 1;
    if (runner->frame == 1) {
        func_800AB92C();
        D_80228190[0].unk0 = 6;
        D_80228194 = 2;
        D_80228198 = 0;
        D_802281C0 = 0.1f;
        D_8022819C = -300.0f;
        D_802281A0 = 0.0f;
        D_802281A4 = -540.0f;
        D_802281B4 = 0.0f;
        D_802281BC = 0.0f;
        D_802281B8 = 1.0f;
    }
    D_80228190[0].unk8++;
    vec[0] = -3.0f;
    vec[1] = 0.0f;
    vec[2] = -5.0f;
    mag = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));
    e = &D_80228190[0];
    for (i = 0; i < 3; i++) {
        e->unk14[i] = vec[i] / mag;
        e->unkC[i] += e->unk14[i] * 8.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC274.s")
#endif

void func_801DC404(UnkA95D0_Runner* runner) {
    f32 t;
    s32 index;
    UnkStruct_801DB0E4_arg1 sp54 = D_80225E34;
    UnkStruct_801DB0E4_arg1 sp20 = sp54;

    index = runner->step - D_80224B14;

    if (index != 2) {
        return;
    }
    D_802287A8 = 8;
    if (runner->frame == 1) {
        func_800AB92C();
        func_801DB284(&D_80228190[0], &sp20, D_80228120, 8);
    }
    t = runner->frame / runner->step->duration;
    sp20.unk0[0] += 300.0f * t;
    sp20.unk0[1] += -200.0f * t;
    sp20.unk0[2] += -200.0f * t;
    func_801DB430(&D_80228190[0], &sp20, D_80228120, 8);
}

void func_801DC5A8(UnkA95D0_Runner* runner) {
    s32 index = runner->step - D_80223F7C;

    if (index == 2 && runner->frame == 1) {
        func_800AB92C();
        func_800AB95C(1, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC60C.s")

#ifdef NON_MATCHING
// IDO keeps the D_80228190 and D_802287DC addresses in registers here; the original loads each with its own lui.
extern f32 D_802287B0[3];
extern f32 D_802287C0[3];
extern f32 D_802287D0[3];
extern f32 D_802287DC;
extern s32 D_80228198;
extern f32 D_8022819C;
extern f32 D_802281A0;
extern f32 D_802281A4;
extern f32 D_802281C0;

void func_801DCD34(UnkA95D0_Runner* runner) {
    s32 i;
    f32 d;
    f32 v;

    if (runner->step - D_802242C0 != 2) {
        return;
    }
    D_802287A8 = 1;
    D_802287C0[0] = -2050.0f;
    if (runner->frame < 150) {
        v = sqrtf(150 - runner->frame) * 12.0f;
    } else {
        v = 0.0f;
    }
    D_802287C0[1] = v + 650.0f;
    D_802287C0[2] = -5650.0f;
    if (runner->frame == 1) {
        func_800AB92C();
        D_80228190[0].unk0 = 12;
        D_80228190[0].unk4 = 0;
        D_80228198 = 0;
        D_802287B0[0] = D_802287C0[0] - 2600.0f;
        D_802287B0[1] = D_802287C0[1] + 450.0f;
        D_802287B0[2] = D_802287C0[2] - 950.0f;
        D_80228120[0][0] = 70.0f;
        D_802281C0 = 0.25f;
    }
    for (i = 0; i < 3; i++) {
        d = D_802287C0[i] - D_802287B0[i];
        D_802287DC = d;
        if (d >= 0.0f) {
            v = sqrtf(d);
        } else {
            v = -sqrtf(-d);
        }
        D_802287B0[i] += v * 0.3f;
    }
    D_8022819C = D_802287B0[0] - SIN(DEG_TO_BINANG((f32) (runner->frame - 150) * 8.0f)) * 20.0f;
    D_802281A0 = D_802287B0[1] - SIN(DEG_TO_BINANG((f32) (runner->frame - 150) * 4.5f)) * 12.0f;
    D_802281A4 = D_802287B0[2] - SIN(DEG_TO_BINANG((f32) (runner->frame - 150) * 7.5f)) * 25.0f;
    D_802287D0[0] = COS(DEG_TO_BINANG(D_80228120[0][0]));
    D_802287D0[2] = SIN(DEG_TO_BINANG(D_80228120[0][0]));
    D_802287D0[1] = (f32) (runner->frame / runner->step->duration) * 0.9f + -0.2f;
    D_802287DC = sqrtf(SQ(D_802287D0[0]) + SQ(D_802287D0[1]) + SQ(D_802287D0[2]));
    for (i = 0; i < 3; i++) {
        D_80228190[0].unk14[i] = D_802287D0[i] / D_802287DC;
    }
    D_80228120[0][0] += 160.0f / runner->step->duration;
    D_802287D0[0] = D_802287B0[0] - D_8022819C;
    D_802287D0[1] = (f32) (SysUtils_Rand() & 0x1F) + 600.0f;
    D_802287D0[2] = D_802287B0[2] - D_802281A4;
    D_802287DC = sqrtf(SQ(D_802287D0[0]) + SQ(D_802287D0[1]) + SQ(D_802287D0[2]));
    for (i = 0; i < 3; i++) {
        D_80228190[0].unk24[i] = D_802287D0[i] / D_802287DC;
    }
    D_80228198 = (D_80228198 + 1) % 2;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DCD34.s")
#endif

#ifdef NON_MATCHING
// Stack layout and loop strength reduction differ (the D_80228110 load moves above the unk8 store; s7/s8 swap).
void func_801DD2D0(UnkA95D0_Runner* runner) {
    UnkStruct_801DB0E4_arg0* e;
    f32 vec[3];
    f32 mag;
    s32 i;
    s32 j;
    UnkStruct_801DD2D0_Pos spDC = D_80225E68;
    UnkStruct_801DD2D0_Groups sp64 = D_80225E98;

    if (runner->step - D_802245B4 != 2) {
        return;
    }
    D_802287A8 = 16;
    if (runner->frame == 1) {
        func_800AB92C();
        for (i = 0; i < 2; i++) {
            e = &D_80228190[i];
            e->unk0 = 3;
            e->unk4 = 0;
            e->unk8 = 0;
            for (j = 0; j < 3; j++) {
                e->unkC[j] = spDC.unk0[i][j];
            }
            e->unk24[0] = 0.0f;
            e->unk24[1] = 1.0f;
            e->unk24[2] = 0.0f;
            e->unk30 = 0.1f;
            if (i == 0) {
                D_80228110[i] = 6;
            } else {
                D_80228110[i] = 0xFFFF;
            }
        }
        for (i = 0; i < 2; i++) {
            func_801DB284(&D_80228190[sp64.unk0[i].start], &sp64.unk0[i].data, D_80228120,
                          sp64.unk0[i].end - sp64.unk0[i].start);
        }
    }
    for (i = 0; i < 2; i++) {
        e = &D_80228190[i];
        e->unk8 += (e->unk8 < 0x10) ? 2 : 1;
        if (D_80228110[i] > 0) {
            if (e->unk8 >= 0x10) {
                e->unk8 = 0;
                D_80228110[i]--;
            }
        } else if (e->unk8 >= 0x2D) {
            e->unk8 = 0x19;
        }
        for (j = 0; j < 3; j++) {
            vec[j] = spDC.unk0[i][j + 3] + (f32) (SysUtils_Rand() & 3);
        }
        mag = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));
        for (j = 0; j < 3; j++) {
            e->unk14[j] = vec[j] / mag;
            e->unkC[j] += e->unk14[j] * 12.0f;
        }
    }
    for (i = 0; i < 2; i++) {
        func_801DB430(&D_80228190[sp64.unk0[i].start], &sp64.unk0[i].data, D_80228120,
                      sp64.unk0[i].end - sp64.unk0[i].start);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD2D0.s")
#endif


void func_801DD6B4(UnkA95D0_Runner* runner) {
    void (*func)(UnkA95D0_Runner*);

    D_802287A8 = 0;
    func = NULL;
    switch (D_801CE638) {
        case 8:
            switch (gCourseID) {
                case DOLPHIN_PARK:
                    func = func_801DC274;
                    break;
                case SUNNY_BEACH:
                    if (gDifficulty == DIFFICULTY_EXPERT) {
                        func = func_801DC404;
                    }
                    break;
                case SUNSET_BAY:
                    func = func_801DC5A8;
                    break;
                case DRAKE_LAKE:
                    func = func_801DC60C;
                    break;
                case PORT_BLUE:
                    func = func_801DCD34;
                    break;
                case GLACIER_COAST:
                    func = func_801DD2D0;
                    break;
            }
            break;
        case 21:
            switch (gDifficulty) {
                case DIFFICULTY_NORMAL:
                case DIFFICULTY_HARD:
                    D_802287AC = D_801C2C70[0].lapCount;
                    if (D_802287AC < 3) {
                        func = func_801DC0AC;
                    }
                    break;
                case DIFFICULTY_EXPERT:
                    switch (D_801C2C70[0].lapCount) {
                        case 0:
                            func = func_801DB8F0;
                            break;
                        case 1:
                            D_802287AC = 4;
                            func = (void (*)(UnkA95D0_Runner*)) func_801DBF68;
                            break;
                        case 2:
                            D_802287AC = 3;
                            func = (void (*)(UnkA95D0_Runner*)) func_801DBF68;
                            break;
                    }
                    break;
            }
            break;
    }
    if (func != NULL) {
        func(runner);
        func_800AC098(&D_80228190[0], D_802287A8);
    }
}

void func_801DD85C(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gCameraPerspective[i].unkE8 = i;
        gCameraPerspective[i].unkEC = 1;
        gCameraPerspective[i].unkF8 = 0;
        gCameraPerspective[i].camViewY = 0.0f;
        func_801DFD8C(&D_80228058[i], &D_80227E98[i]);
        func_801DFDA0(&D_80228058[i], D_802280C8[i]);
        func_801DFDA8(&D_80228058[i], &gCameraPerspective[i].unk4, (f32*) &gCameraPerspective[i].unk8,
                      &gCameraPerspective[i].unkC, &gCameraPerspective[i].unk1C, &gCameraPerspective[i].unk20,
                      &gCameraPerspective[i].unk24, &gCameraPerspective[i].unk10, &gCameraPerspective[i].unk14,
                      &gCameraPerspective[i].unk18, &D_80228108);
    }
}

void func_801DDA24(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDAB8(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

void func_801DDAB8(void* arg0, void* arg1, void* arg2) {
    UnkA95D0_Step* step;
    camera_unk_1* cam = arg0;
    UnkA95D0_Obj* obj = arg1;
    UnkA95D0_Runner* runner = arg2;

    cam->unk9C = 10.0f;
    cam->unkA0 = 16138.0f;
    D_80228108 = gWaterLevel;
    switch (cam->viewMode) {
        case 1:
            func_801DF008(obj, &D_80225A84);
            break;
        case 2:
            func_801DF5F0(obj, &D_80225AFC);
            obj->u.p5.unkC = D_80228108;
            obj->u.p5.unk18[0] = cam->unk4 - cam->unk1C * 100.0f;
            obj->u.p5.unk18[1] = cam->unkC - cam->unk24 * 100.0f;
            obj->u.p5.unk48[1].target = 90.0f;
            break;
        case 3:
        mode3:
            func_801DF5F0(obj, &D_80225BD8);
            obj->u.p5.unkC = D_80228108;
            obj->u.p5.unk18[0] = cam->unk4 - cam->unk1C * 100.0f;
            obj->u.p5.unk18[1] = cam->unkC - cam->unk24 * 100.0f;
            if ((gGameState == GAME_STATE_DEMO) || (gGameState == GAME_STATE_8)) {
                cam->camViewY = 0.0f;
            } else {
                obj->base.unk34 = D_80223940[cam->unkEC];
                obj->u.p5.unk48[0].value = D_80223950[cam->unkEC];
                obj->u.p5.unk48[2].value = D_80223960[cam->unkEC];
                cam->camViewY = D_80223970[cam->unkEC];
            }
            cam->viewMode = 4;
            break;
        case 5:
            switch (D_801CE638) {
                case 0:
                    cam->viewMode = 3;
                    goto mode3;
                case 8:
                default:
                    cam->viewMode = 6;
                    switch (gCourseID) {
                        case DOLPHIN_PARK:
                            step = D_80223A30;
                            break;
                        case SUNNY_BEACH:
                            switch (gDifficulty) {
                                case DIFFICULTY_NORMAL:
                                    step = D_80223D38;
                                    break;
                                case DIFFICULTY_HARD:
                                    step = D_80224944;
                                    break;
                                case DIFFICULTY_EXPERT:
                                    step = D_80224B14;
                                    break;
                            }
                            break;
                        case SUNSET_BAY:
                            step = D_80223F7C;
                            break;
                        case MARINE_FORTRESS:
                            step = D_80224060;
                            break;
                        case DRAKE_LAKE:
                            step = D_802241E0;
                            break;
                        case PORT_BLUE:
                            step = D_802242C0;
                            break;
                        case TWILIGHT_CITY:
                            step = D_80224430;
                            break;
                        case GLACIER_COAST:
                            step = D_802245B4;
                            break;
                        case SOUTHERN_ISLAND:
                            step = D_802246B4;
                            break;
                    }
                    func_801DFD94(runner, step);
                    break;
            }
            break;
        case 8:
            runner->frame = 0;
            cam->unk9C = 32.0f;
            cam->unk94 = 0.0f;
            cam->unk98 = 0.0f;
            cam->unkA0 = 4096.0f;
            break;
    }
    func_801E0F8C(cam, obj);
    func_801E0FF0(cam);
    func_801E11B4(&D_8011F8E8[0], cam);
    func_801E11B4(&D_8011F8E8[1], cam);
}

void func_801DDE48(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDEDC(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

void func_801DDEDC(camera_unk_1* cam, UnkA95D0_Obj* obj, UnkA95D0_Runner* runner) {
    UNUSED s32 pad[2];
    f32 prevX;
    f32 prevY;
    f32 prevZ;
    UnkA95D0_Step* step;

    D_80228108 = gWaterLevel;
    prevX = cam->unk4C;
    prevY = cam->unk50;
    prevZ = cam->unk54;
    switch (cam->viewMode) {
        case 1:
            break;
        case 2:
            obj->u.p5.unk0[0] = cam->unk4;
            obj->u.p5.unk0[1] = *(f32*) &cam->unk8 + 30.0f;
            obj->u.p5.unk0[2] = cam->unkC;
            obj->u.p5.unkC = D_80228108;
            obj->u.p5.unk24[0] = cam->unk1C;
            obj->u.p5.unk24[1] = cam->unk24;
            obj->u.p5.unk48[1].target += 1.0f;
            break;
        case 4:
            step = NULL;
            if ((gGameModes == GMODE_TIME_TRIALS) || (gGameModes == GMODE_CHAMPIONSHIP) ||
                (gGameModes == GMODE_STUNT)) {
                switch (D_80192690[cam->unkE8].unk16C8) {
                    case 1:
                        step = D_80224D9C;
                        break;
                    case 2:
                        step = D_80224F98;
                        break;
                    case 3:
                        step = D_8022512C;
                        break;
                    case 4:
                        step = D_802252B4;
                        break;
                    case 5:
                        step = D_802254F4;
                        break;
                    case 6:
                        step = D_80225804;
                        break;
                }
            }
            if (step != NULL) {
                obj->u.p5.unk80 = 0;
                obj->base.unk24[0] = 0.0f;
                obj->base.unk24[2] = 0.0f;
                obj->base.unk24[1] = 1.0f;
                func_801DFD94(runner, step);
                cam->viewMode = 7;
            } else {
                obj->u.p5.unk0[0] = cam->unk4;
                obj->u.p5.unk0[1] = *(f32*) &cam->unk8 + cam->camViewY;
                obj->u.p5.unk0[2] = cam->unkC;
                obj->u.p5.unkC = D_80228108;
                obj->u.p5.unk24[0] = cam->unk1C;
                obj->u.p5.unk24[1] = cam->unk24;
                obj->u.p5.unk34 = sqrtf(SQ(cam->unk10) + SQ(cam->unk18));
                break;
            }
        case 7:
            cam->camViewY += (0.0f - cam->camViewY) * 0.15f;
            if (runner->step->duration == -2) {
                if (runner->frame == 0) {
                    func_801DF5F0(obj, &D_80225BD8);
                    obj->u.p5.unk18[0] = cam->unk4 - cam->unk1C * 100.0f;
                    obj->u.p5.unk18[1] = cam->unkC - cam->unk24 * 100.0f;
                }
                runner->frame = 1;
                obj->u.p5.unk0[0] = cam->unk4;
                obj->u.p5.unk0[1] = *(f32*) &cam->unk8 + cam->camViewY;
                obj->u.p5.unk0[2] = cam->unkC;
                obj->u.p5.unkC = D_80228108;
                obj->u.p5.unk24[0] = cam->unk1C;
                obj->u.p5.unk24[1] = cam->unk24;
                obj->u.p5.unk34 = sqrtf(SQ(cam->unk10) + SQ(cam->unk18));
                obj->u.p5.unk48[1].target += 1.2f;
                if (obj->u.p5.unk48[1].target > 360.0f) {
                    obj->u.p5.unk48[1].target -= 360.0f;
                }
            } else {
                *(f32*) &cam->unk8 += cam->camViewY;
                func_801DFCB8(runner);
                *(f32*) &cam->unk8 -= cam->camViewY;
                if (runner->obj->type == 5) {
                    obj->base.unk3C += 0.1;
                    if (obj->base.unk3C > 1.0f) {
                        obj->base.unk3C = 1.0f;
                    }
                    obj->u.p5.unk48[0].rate += 0.1;
                    if (obj->u.p5.unk48[0].rate > 1.0f) {
                        obj->u.p5.unk48[0].rate = 1.0f;
                    }
                    obj->u.p5.unk48[2].rate += 0.1;
                    if (obj->u.p5.unk48[2].rate > 1.0f) {
                        obj->u.p5.unk48[2].rate = 1.0f;
                    }
                }
            }
            break;
        case 6:
            func_801DFCB8(runner);
            func_801DD6B4(runner);
            break;
        case 8:
            func_801DD6B4(runner);
            runner->frame++;
            goto skip;
    }
    func_801DFC48(obj);
skip:
    func_801E0F8C(cam, obj);
    func_8009CB68();
    func_8009CCE8((UnkStruct_func_8009CCE8*) cam);
    cam->unk58 = cam->unk4C - prevX;
    cam->unk5C = cam->unk50 - prevY;
    cam->unk60 = cam->unk54 - prevZ;
    func_801E0FF0(cam);
    func_801E11B4(gGfxPool, cam);
}

void func_801DE3CC(void) {
    s32 i;
    s32 mode;
    u16* buttons;
    f32 rate;
    f32 viewY;
    UnkA95D0_Payload5* p;

    for (i = 0; i < gPlayers; i++) {
        mode = gCameraPerspective[i].unkEC;
        p = &D_80227E98[i].u.p5;
        buttons = &gControllerOne[D_80154330[i]].unk_2;
        rate = 0.2f;
        if (*buttons & 3) {
            gCameraPerspective[i].unkF8 ^= 1;
            if (gCameraPerspective[i].unkF8) {
                AudioGeneral_PlaySound(0x11, i);
            } else {
                AudioGeneral_PlaySound(0x16, i);
            }
        }
        p->unk80 = gCameraPerspective[i].unkF8;
        if (*buttons & 8) {
            mode++;
        }
        if (*buttons & 4) {
            mode--;
        }
        if (mode < 0) {
            mode = 3;
            rate = 0.3f;
        } else if (mode >= 4) {
            mode = 0;
            rate = 0.3f;
        }
        if (gCameraPerspective[i].unkEC < mode) {
            AudioGeneral_PlaySound(0x1D, i);
        } else if (mode < gCameraPerspective[i].unkEC) {
            AudioGeneral_PlaySound(0x1E, i);
        }
        p->unk48[2].rate = rate;
        p->unk48[0].rate = rate;
        D_80227E98[i].base.unk3C = rate;
        D_80227E98[i].base.unk38 = D_80223940[mode];
        p->unk48[0].target = D_80223950[mode];
        p->unk48[2].target = D_80223960[mode];
        if (mode == gCameraPerspective[i].unkEC) {
            rate = 0.07f;
        }
        switch (D_80192690[i].unkC54) {
            case 23:
            case 24:
                rate = 0.15f;
            case 25:
                if (mode >= 2) {
                    viewY = 10.0f;
                } else {
                    viewY = 0.0f;
                }
                break;
            case 7:
                if (D_80192690[i].unkC58 < 0x38) {
                    viewY = 0.0f;
                } else {
                    viewY = D_80223970[mode];
                }
                break;
            default:
                viewY = D_80223970[mode];
                // FAKE: an empty statement here keeps IDO from merging this case with case 7's else.
                do {
                } while (0);
                break;
        }
        gCameraPerspective[i].unkEC = mode;
        gCameraPerspective[i].camViewY += (viewY - gCameraPerspective[i].camViewY) * rate;
    }
}

f32 func_801DE690(f32 t, s32 seg, f32* points, s32 count) {
    f32 u;
    f32 t2;
    f32 t3;
    f32 u2;
    f32 u3;
    f32 w[4];

    if (seg == 0) {
        u = 1.0f - t;
        t2 = t * t;
        w[0] = u * u * u;
        t3 = t2 * t;
        w[1] = ((t3 * 21.0f) / 12.0f) - (t2 * 9.0f * 0.5f) + (t * 3.0f);
        w[2] = ((-t3 * 11.0f) / 12.0f) + (t2 * 3.0f * 0.5f);
        w[3] = t3 / 6.0f;
    } else if (seg == 1) {
        u = 1.0f - t;
        t2 = t * t;
        w[0] = u * u * u * 0.25f;
        t3 = t2 * t;
        w[1] = ((t3 * 7.0f) / 12.0f) - (t2 * 5.0f * 0.25f) + (t * 0.25f) + 0.5833333f;
        w[2] = (-t3 * 0.5f) + (t2 * 0.5f) + (t * 0.5f) + 0.16666667f;
        w[3] = t3 / 6.0f;
    } else if ((count < 7) || (seg < (count - 5))) {
        u = 1.0f - t;
        t2 = t * t;
        t3 = t2 * t;
        w[0] = (u * u * u) / 6.0f;
        w[1] = ((t3 * 0.5f) - t2) + 0.6666667f;
        w[2] = (-t3 * 0.5f) + (t2 * 0.5f) + (t * 0.5f) + 0.16666667f;
        w[3] = t3 / 6.0f;
    } else if (count == (seg + 5U)) {
        u = 1.0f - t;
        u2 = u * u;
        u3 = u2 * u;
        w[0] = u3 / 6.0f;
        w[1] = (-u3 * 0.5f) + (u2 * 0.5f) + (u * 0.5f) + 0.16666667f;
        w[2] = ((u3 * 7.0f) / 12.0f) - (u2 * 5.0f * 0.25f) + (u * 0.25f) + 0.5833333f;
        w[3] = t * t * t * 0.25f;
    } else if (count == (seg + 4U)) {
        u = 1.0f - t;
        u2 = u * u;
        u3 = u2 * u;
        w[0] = u3 / 6.0f;
        w[1] = ((-u3 * 11.0f) / 12.0f) + (u2 * 3.0f * 0.5f);
        w[2] = ((u3 * 21.0f) / 12.0f) - (u2 * 9.0f * 0.5f) + (u * 3.0f);
        w[3] = t * t * t;
    }
    return w[0] * points[seg] + w[1] * points[seg + 1] + w[2] * points[seg + 2] + w[3] * points[seg + 3];
}

void func_801DEA94(UnkA95D0_Cursor* cursors, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        cursors[i].seg = 0;
        cursors[i].frame = 0;
    }
}

void func_801DEB08(f32* out, UnkA95D0_Cursor* cursor, UnkA95D0_Spline1* spline) {
    s32 duration;

    while ((duration = spline->durations[cursor->seg]) == 0) {
        cursor->seg++;
    }
    *out = func_801DE690((f32) cursor->frame / duration, cursor->seg, spline->points, spline->count);
    if (++cursor->frame >= spline->durations[cursor->seg]) {
        cursor->frame = 0;
        if (++cursor->seg >= spline->count - 3) {
            cursor->seg = -1;
        }
    }
}

void func_801DEC00(f32* out, UnkA95D0_Cursor* cursor, UnkA95D0_Spline3* spline) {
    s32 i;

    while (spline->durations[cursor->seg] == 0) {
        cursor->seg++;
    }
    for (i = 0; i < 3; i++) {
        out[i] = func_801DE690((f32) cursor->frame / spline->durations[cursor->seg], cursor->seg, spline->points[i],
                               spline->count);
    }
    if (++cursor->frame >= spline->durations[cursor->seg]) {
        cursor->frame = 0;
        if (++cursor->seg >= spline->count - 3) {
            cursor->seg = -1;
        }
    }
}

void func_801DED44(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines) {
    func_801DEC00(out, &cursors[0], &splines[0]);
    func_801DEC00(out + 3, &cursors[1], &splines[1]);
}

void func_801DED88(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines) {
    func_801DEC00(out, &cursors[0], &splines[0]);
    func_801DEC00(out + 3, &cursors[1], &splines[1]);
    func_801DEC00(out + 6, &cursors[2], &splines[2]);
}

void func_801DEDE8(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines) {
    func_801DEC00(out, &cursors[0], &splines[0]);
    func_801DEC00(out + 3, &cursors[1], &splines[1]);
    func_801DEB08(out + 6, &cursors[2], (UnkA95D0_Spline1*) &splines[2]);
}

void func_801DEE48(f32* out, UnkA95D0_Cursor* cursors, UnkA95D0_Spline3* splines) {
    func_801DEC00(out, &cursors[0], &splines[0]);
    func_801DEC00(out + 3, &cursors[1], &splines[1]);
    func_801DEC00(out + 6, &cursors[2], &splines[2]);
    func_801DEB08(out + 9, &cursors[3], (UnkA95D0_Spline1*) &splines[3]);
}

void func_801DEEC4(UnkA95D0_Obj* obj) {
    UnkA95D0_Base* b = &obj->base;
    s32 i;

    for (i = 0; i < 3; i++) {
        b->unk18[i] += (b->unk24[i] - b->unk18[i]) * b->unk30;
    }
    b->unk34 += (b->unk38 - b->unk34) * b->unk3C;
    for (i = 0; i < 2; i++) {
        b->unk40[i] += (b->unk48[i] - b->unk40[i]) * b->unk50[i];
    }
}

void func_801DEF84(UnkA95D0_Obj* obj, UnkA95D0_Base* base, UnkA95D0_Payload1* p) {
    obj->type = 1;
    obj->base = *base;
    obj->u.p1 = *p;
}

void func_801DF008(UnkA95D0_Obj* obj, UnkA95D0_Key1* key) {
    obj->type = 1;
    obj->base = key->base;
    obj->u.p1 = key->p;
}

void func_801DF08C(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4) {
    s32 i;

    if (arg1 != NULL) {
        UnkA95D0_Payload1* p = &obj->u.p1;
        for (i = 0; i < 3; i++) {
            p->unk0[i] = arg1[i];
        }
    }
    if (arg2 != NULL) {
        UnkA95D0_Payload1* p = &obj->u.p1;
        for (i = 0; i < 3; i++) {
            p->unk10[i] = arg2[i];
        }
    }
    if (arg3 != NULL) {
        UnkA95D0_Base* b = &obj->base;
        for (i = 0; i < 3; i++) {
            b->unk24[i] = arg3[i];
        }
    }
    if (arg4 != NULL) {
        obj->base.unk38 = *arg4;
    }
}

void func_801DF128(UnkA95D0_Obj* obj) {
    UnkA95D0_Payload1* p = &obj->u.p1;
    UnkA95D0_Base* b = &obj->base;
    s32 i;

    for (i = 0; i < 3; i++) {
        b->unk0[i] += (p->unk0[i] - b->unk0[i]) * p->unkC;
        b->unkC[i] += (p->unk10[i] - b->unkC[i]) * p->unk1C;
    }
    func_801DEEC4(obj);
}

void func_801DF1F8(UnkA95D0_Obj* obj, s32 type, UnkA95D0_Base* base, UnkA95D0_Payload2* p) {
    obj->type = type;
    obj->base = *base;
    obj->u.p2 = *p;
}

void func_801DF278(UnkA95D0_Obj* obj, s32 type, UnkA95D0_Key2* key) {
    obj->type = type;
    obj->base = key->base;
    obj->u.p2 = key->p;
}

void func_801DF2F8(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4) {
    UnkA95D0_Payload2* p = &obj->u.p2;
    UnkA95D0_Base* b = &obj->base;
    s32 i;

    if (arg1 != NULL) {
        for (i = 0; i < 3; i++) {
            p->unk0[i] = arg1[i];
        }
    }
    if (arg2 != NULL) {
        p->unk14[0].target = arg2[0];
        p->unk14[1].target = arg2[1];
        p->unk14[2].target = arg2[2];
    }
    if (arg3 != NULL) {
        for (i = 0; i < 3; i++) {
            b->unk24[i] = arg3[i];
        }
    }
    if (arg4 != NULL) {
        b->unk38 = *arg4;
    }
}

void func_801DF38C(UnkA95D0_Obj* obj) {
    UnkA95D0_Payload2* p = &obj->u.p2;
    UnkA95D0_Base* b = &obj->base;
    f32 yawDeg;
    f32 pitchDeg;
    f32 offset[3];
    s32 i;

    p->unk14[0].value += (p->unk14[0].target - p->unk14[0].value) * p->unk14[0].rate;
    p->unk14[1].value += (p->unk14[1].target - p->unk14[1].value) * p->unk14[1].rate;
    p->unk14[2].value += (p->unk14[2].target - p->unk14[2].value) * p->unk14[2].rate;
    yawDeg = p->unk14[1].value + p->unkC[0];
    pitchDeg = p->unk14[2].value + p->unkC[1];
    offset[0] = (p->unk14[0].value * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    offset[1] = p->unk14[0].value * SIN(DEG_TO_BINANG(pitchDeg));
    offset[2] = (p->unk14[0].value * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    switch (obj->type) {
        case 2:
            for (i = 0; i < 3; i++) {
                b->unk0[i] = p->unk0[i];
                b->unkC[i] = p->unk0[i] + offset[i];
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                b->unkC[i] = p->unk0[i];
                b->unk0[i] = p->unk0[i] + offset[i];
            }
            break;
    }
    func_801DEEC4(obj);
}

void func_801DF578(UnkA95D0_Obj* obj, UnkA95D0_Base* base, UnkA95D0_Payload5* p) {
    obj->type = 5;
    obj->base = *base;
    obj->u.p5 = *p;
}

void func_801DF5F0(UnkA95D0_Obj* obj, UnkA95D0_Key5* key) {
    obj->type = 5;
    obj->base = key->base;
    obj->u.p5 = key->p;
}

void func_801DF668(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6) {
    UnkA95D0_Payload5* p = &obj->u.p5;
    UnkA95D0_Base* b = &obj->base;
    s32 i;

    if (arg1 != NULL) {
        for (i = 0; i < 3; i++) {
            p->unk0[i] = arg1[i];
        }
    }
    if (arg2 != NULL) {
        p->unk24[0] = arg2[p->unk74[0]];
        p->unk24[1] = arg2[p->unk74[1]];
    }
    if (arg3 != NULL) {
        p->unk34 = *arg3;
    }
    if (arg4 != NULL) {
        p->unk48[0].target = arg4[0];
        p->unk48[1].target = arg4[1];
        p->unk48[2].target = arg4[2];
    }
    if (arg5 != NULL) {
        for (i = 0; i < 3; i++) {
            b->unk24[i] = arg5[i];
        }
    }
    if (arg6 != NULL) {
        b->unk38 = *arg6;
    }
}

#ifdef NON_MATCHING
// obj stays on the stack instead of in s0, so the frame is 8 bytes short and registers differ throughout.
void func_801DF744(UnkA95D0_Obj* obj) {
    f32 d[2];
    f32 v[2];
    f32 x;
    f32 y;
    UnkA95D0_Payload5* p;

    obj->u.p5.unk48[0].value += (obj->u.p5.unk48[0].target - obj->u.p5.unk48[0].value) * obj->u.p5.unk48[0].rate;
    obj->u.p5.unk48[2].value += (obj->u.p5.unk48[2].target - obj->u.p5.unk48[2].value) * obj->u.p5.unk48[2].rate;
    obj->u.p5.unk48[1].value += (obj->u.p5.unk48[1].target - obj->u.p5.unk48[1].value) * obj->u.p5.unk48[1].rate;
    d[0] = obj->u.p5.unk18[0] - obj->u.p5.unk0[obj->u.p5.unk74[0]];
    d[1] = obj->u.p5.unk18[1] - obj->u.p5.unk0[obj->u.p5.unk74[1]];
    p = &obj->u.p5;
    x = p->unk20 / sqrtf(SQ(d[1]) + SQ(d[0]));
    p->unk18[0] = d[0] * x + p->unk0[p->unk74[0]];
    p->unk18[1] = d[1] * x + p->unk0[p->unk74[1]];
    x = func_801ED154(d[1], d[0]) + p->unk48[1].value;
    obj->base.unkC[p->unk74[0]] =
        COS(DEG_TO_BINANG(x)) * (p->unk48[0].value * COS(DEG_TO_BINANG(p->unk48[2].value))) + p->unk0[p->unk74[0]];
    obj->base.unkC[p->unk74[1]] =
        SIN(DEG_TO_BINANG(x)) * (p->unk48[0].value * COS(DEG_TO_BINANG(p->unk48[2].value))) + p->unk0[p->unk74[1]];
    obj->base.unkC[p->unk74[2]] = SIN(DEG_TO_BINANG(p->unk48[2].value)) * p->unk48[0].value +
                           ((p->unk0[p->unk74[2]] - p->unkC) * p->unk6C + p->unkC);
    x = p->unk34 * p->unk38;
    if (x < p->unk3C) {
        x = x / p->unk3C;
    } else {
        x = 1.0f;
    }
    x = -2.0f * x * x * x + 3.0f * x * x;
    v[0] = p->unk24[0] * x;
    v[1] = p->unk24[1] * x;
    x = -(d[0] * v[0] + d[1] * v[1]) / (SQ(d[1]) + SQ(d[0]));
    d[0] = (d[0] * x + v[0]) * p->unk2C;
    d[1] = (d[1] * x + v[1]) * p->unk2C;
    x = sqrtf(SQ(d[1]) + SQ(d[0]));
    if (p->unk30 < x) {
        x = p->unk30 / x;
        d[0] *= x;
        d[1] *= x;
    }
    obj->base.unk0[p->unk74[0]] = d[0] + p->unk0[p->unk74[0]];
    obj->base.unk0[p->unk74[1]] = d[1] + p->unk0[p->unk74[1]];
    if (p->unk80 != 0) {
        obj->base.unk24[0] = d[0] * p->unk70;
        obj->base.unk24[1] = p->unk30;
        obj->base.unk24[2] = d[1] * p->unk70;
    } else {
        obj->base.unk24[0] = 0.0f;
        obj->base.unk24[2] = 0.0f;
        obj->base.unk24[1] = 1.0f;
    }
    y = p->unk0[p->unk74[2]];
    if (y <= p->unk10) {
        x = p->unk40;
    } else if (p->unk14 <= y) {
        x = p->unk44;
    } else {
        x = (y - p->unk10) / (p->unk14 - p->unk10);
        x = x * x * (p->unk44 - p->unk40) + p->unk40;
    }
    obj->base.unk0[p->unk74[2]] = (y - p->unkC) * x + p->unkC;
    func_801DEEC4(obj);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF744.s")
#endif

void func_801DFC48(UnkA95D0_Obj* obj) {
    switch (obj->type) {
        case 1:
            func_801DF128(obj);
            break;
        case 2:
        case 3:
            func_801DF38C(obj);
            break;
        case 5:
            func_801DF744(obj);
            break;
    }
}

void func_801DFCB8(UnkA95D0_Runner* runner) {
    UnkA95D0_Step* step;

    while (1) {
        step = runner->step;
        if (step == NULL) {
            return;
        }
        if (step->func != NULL) {
            step->func(runner, step->arg);
        }
        switch (step->duration) {
            case 0:
                runner->step++;
                continue;
            case -1:
                step = NULL;
                runner->frame = 0;
                break;
            case -2:
                runner->frame++;
                break;
            default:
                if (++runner->frame >= step->duration) {
                    step++;
                    runner->frame = 0;
                }
                break;
        }
        runner->step = step;
        return;
    }
}

void func_801DFD8C(UnkA95D0_Runner* runner, UnkA95D0_Obj* obj) {
    runner->obj = obj;
}

void func_801DFD94(UnkA95D0_Runner* runner, UnkA95D0_Step* step) {
    runner->step = step;
    runner->frame = 0;
}

void func_801DFDA0(UnkA95D0_Runner* runner, UnkA95D0_Cursor* cursors) {
    runner->cursors = cursors;
}

void func_801DFDA8(UnkA95D0_Runner* runner, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6,
                   f32* arg7, f32* arg8, f32* arg9, f32* arg10) {
    runner->unk10[0] = arg1;
    runner->unk10[1] = arg2;
    runner->unk10[2] = arg3;
    runner->unk10[3] = arg4;
    runner->unk10[4] = arg5;
    runner->unk10[5] = arg6;
    runner->unk10[6] = arg7;
    runner->unk10[7] = arg8;
    runner->unk10[8] = arg9;
    runner->unk10[9] = arg10;
}

void func_801DFDF0(UnkA95D0_Runner* runner, s32 count) {
    func_801DEA94(runner->cursors, count);
}

void func_801DFE10(UnkA95D0_Runner* runner, UnkA95D0_Key1* key) {
    func_801DF008(runner->obj, key);
}

void func_801DFE30(UnkA95D0_Runner* runner, UnkA95D0_Key2* key) {
    func_801DF278(runner->obj, 2, key);
}

void func_801DFE58(UnkA95D0_Runner* runner, UnkA95D0_Key2* key) {
    func_801DF278(runner->obj, 3, key);
}

void func_801DFE80(UnkA95D0_Runner* runner, UnkA95D0_Key5* key) {
    UnkA95D0_Payload5* p;
    s32 i;
    s32 axis;

    func_801DF5F0(runner->obj, key);
    p = &runner->obj->u.p5;
    for (i = 0; i < 3; i++) {
        p->unk0[i] = *runner->unk10[i];
    }
    for (i = 0; i < 2; i++) {
        axis = p->unk74[i];
        p->unk18[i] = *runner->unk10[axis] - *runner->unk10[axis + 3] * 100.0f;
    }
}

void func_801DFF5C(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[6];

    func_801DED44(out, runner->cursors, splines);
    func_801DF08C(runner->obj, &out[0], &out[3], NULL, NULL);
}

void func_801DFFA8(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[9];

    func_801DED88(out, runner->cursors, splines);
    func_801DF08C(runner->obj, &out[0], &out[3], &out[6], NULL);
}

void func_801DFFF4(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[7];

    func_801DEDE8(out, runner->cursors, splines);
    func_801DF08C(runner->obj, &out[0], &out[3], NULL, &out[6]);
}

void func_801E0044(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[10];

    func_801DEE48(out, runner->cursors, splines);
    func_801DF08C(runner->obj, &out[0], &out[3], &out[6], &out[9]);
}

void func_801E0094(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[6];

    func_801DED44(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[0], &out[3], NULL, NULL);
}

void func_801E00E0(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[9];

    func_801DED88(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[0], &out[3], &out[6], NULL);
}

void func_801E012C(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[7];

    func_801DEDE8(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[0], &out[3], NULL, &out[6]);
}

void func_801E017C(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[10];

    func_801DEE48(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[0], &out[3], &out[6], &out[9]);
}

void func_801E01CC(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[6];

    func_801DED44(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[3], &out[0], NULL, NULL);
}

void func_801E0218(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[9];

    func_801DED88(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[3], &out[0], &out[6], NULL);
}

void func_801E0264(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[7];

    func_801DEDE8(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[3], &out[0], NULL, &out[6]);
}

void func_801E02B4(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[10];

    func_801DEE48(out, runner->cursors, splines);
    func_801DF2F8(runner->obj, &out[3], &out[0], &out[6], &out[9]);
}

void func_801E0304(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[6];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload2* p;

    func_801DED44(out, runner->cursors, splines);
    p = &runner->obj->u.p2;
    p->unkC[0] = func_801ED154(*runner->unk10[5], *runner->unk10[3]);
    yawDeg = p->unkC[0] + out[1];
    p->unkC[1] = 0.0f;
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    func_801DF2F8(runner->obj, pos, &out[3], NULL, NULL);
}





void func_801E0454(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[9];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload2* p;

    func_801DED88(out, runner->cursors, splines);
    p = &runner->obj->u.p2;
    p->unkC[0] = func_801ED154(*runner->unk10[5], *runner->unk10[3]);
    yawDeg = p->unkC[0] + out[1];
    p->unkC[1] = 0.0f;
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    func_801DF2F8(runner->obj, pos, &out[3], &out[6], NULL);
}

void func_801E05A4(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[7];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload2* p;

    func_801DEDE8(out, runner->cursors, splines);
    p = &runner->obj->u.p2;
    p->unkC[0] = func_801ED154(*runner->unk10[5], *runner->unk10[3]);
    yawDeg = p->unkC[0] + out[1];
    p->unkC[1] = 0.0f;
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    func_801DF2F8(runner->obj, pos, &out[3], NULL, &out[6]);
}

void func_801E06F8(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[10];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload2* p;

    func_801DEE48(out, runner->cursors, splines);
    p = &runner->obj->u.p2;
    p->unkC[0] = func_801ED154(*runner->unk10[5], *runner->unk10[3]);
    yawDeg = p->unkC[0] + out[1];
    p->unkC[1] = 0.0f;
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    func_801DF2F8(runner->obj, pos, &out[3], &out[6], &out[9]);
}

void func_801E084C(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[6];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload5* p;

    func_801DED44(out, runner->cursors, splines);
    p = &runner->obj->u.p5;
    yawDeg = func_801ED154(*runner->unk10[5], *runner->unk10[3]) + out[1];
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    p->unkC = *runner->unk10[9];
    p->unk24[0] = *runner->unk10[p->unk74[0] + 3];
    p->unk24[1] = *runner->unk10[p->unk74[1] + 3];
    p->unk34 = sqrtf(SQ(*runner->unk10[p->unk74[0] + 6]) + SQ(*runner->unk10[p->unk74[1] + 6]));
    func_801DF668(runner->obj, pos, NULL, NULL, &out[3], NULL, NULL);
}

void func_801E0A18(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[9];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload5* p;

    func_801DED88(out, runner->cursors, splines);
    p = &runner->obj->u.p5;
    yawDeg = func_801ED154(*runner->unk10[5], *runner->unk10[3]) + out[1];
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    p->unkC = *runner->unk10[9];
    p->unk24[0] = *runner->unk10[p->unk74[0] + 3];
    p->unk24[1] = *runner->unk10[p->unk74[1] + 3];
    p->unk34 = sqrtf(SQ(*runner->unk10[p->unk74[0] + 6]) + SQ(*runner->unk10[p->unk74[1] + 6]));
    func_801DF668(runner->obj, pos, NULL, NULL, &out[3], &out[6], NULL);
}

void func_801E0BE8(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[7];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload5* p;

    func_801DEDE8(out, runner->cursors, splines);
    p = &runner->obj->u.p5;
    yawDeg = func_801ED154(*runner->unk10[5], *runner->unk10[3]) + out[1];
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    p->unkC = *runner->unk10[9];
    p->unk24[0] = *runner->unk10[p->unk74[0] + 3];
    p->unk24[1] = *runner->unk10[p->unk74[1] + 3];
    p->unk34 = sqrtf(SQ(*runner->unk10[p->unk74[0] + 6]) + SQ(*runner->unk10[p->unk74[1] + 6]));
    func_801DF668(runner->obj, pos, NULL, NULL, &out[3], NULL, &out[6]);
}

void func_801E0DB8(UnkA95D0_Runner* runner, UnkA95D0_Spline3* splines) {
    f32 out[10];
    f32 pos[3];
    f32 yawDeg;
    f32 pitchDeg;
    UnkA95D0_Payload5* p;

    func_801DEE48(out, runner->cursors, splines);
    p = &runner->obj->u.p5;
    yawDeg = func_801ED154(*runner->unk10[5], *runner->unk10[3]) + out[1];
    pitchDeg = out[2];
    pos[0] = *runner->unk10[0] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * COS(DEG_TO_BINANG(yawDeg));
    pos[1] = *runner->unk10[1] + out[0] * SIN(DEG_TO_BINANG(pitchDeg));
    pos[2] = *runner->unk10[2] + (out[0] * COS(DEG_TO_BINANG(pitchDeg))) * SIN(DEG_TO_BINANG(yawDeg));
    p->unkC = *runner->unk10[9];
    p->unk24[0] = *runner->unk10[p->unk74[0] + 3];
    p->unk24[1] = *runner->unk10[p->unk74[1] + 3];
    p->unk34 = sqrtf(SQ(*runner->unk10[p->unk74[0] + 6]) + SQ(*runner->unk10[p->unk74[1] + 6]));
    func_801DF668(runner->obj, pos, NULL, NULL, &out[3], &out[6], &out[9]);
}

void func_801E0F8C(camera_unk_1* cam, UnkA95D0_Obj* obj) {
    cam->unk4C = obj->base.unkC[0];
    cam->unk50 = obj->base.unkC[1];
    cam->unk54 = obj->base.unkC[2];
    cam->unk7C = obj->base.unk0[0];
    cam->unk80 = obj->base.unk0[1];
    cam->unk84 = obj->base.unk0[2];
    cam->unk70 = obj->base.unk18[0];
    cam->unk74 = obj->base.unk18[1];
    cam->unk78 = obj->base.unk18[2];
    cam->unk88 = obj->base.unk34;
    cam->unk94 = obj->base.unk40[0];
    cam->unk98 = obj->base.unk40[1];
}

void func_801E0FF0(camera_unk_1* cam) {
    f32 a;
    f32 b;
    f32 c;
    f32 mag;
    f32 t;

    a = cam->unk7C - cam->unk4C;
    b = cam->unk80 - cam->unk50;
    c = cam->unk84 - cam->unk54;
    cam->unk64 = a;
    cam->unk68 = b;
    cam->unk6C = c;
    mag = sqrtf(SQ(a) + SQ(b) + SQ(c));
    cam->unk64 /= mag;
    cam->unk68 /= mag;
    cam->unk6C /= mag;
    mag = sqrtf(SQ(cam->unk64) + SQ(cam->unk6C));
    cam->unkF0 = cam->unk64 / mag;
    cam->unkF4 = cam->unk6C / mag;
    t = SQ(cam->unk64) + SQ(cam->unk68) + SQ(cam->unk6C);
    t = -(cam->unk64 * cam->unk70 + cam->unk68 * cam->unk74 + cam->unk6C * cam->unk78) / t;
    cam->unk70 += cam->unk64 * t;
    cam->unk74 += cam->unk68 * t;
    cam->unk78 += cam->unk6C * t;
    mag = sqrtf(SQ(cam->unk70) + SQ(cam->unk74) + SQ(cam->unk78));
    cam->unk70 /= mag;
    cam->unk74 /= mag;
    cam->unk78 /= mag;
    b = cam->unk4C - cam->unk7C;
    c = cam->unk54 - cam->unk84;
    cam->unk8C = sqrtf(SQ(b) + SQ(c));
    cam->unk90 = cam->unk50 - cam->unk80;
}

void func_801E11B4(GfxPool* pool, camera_unk_1* cam) {
    func_800481E0(&pool->unkE008[cam->unkE8], &cam->unkE4, cam->unk88, 4.0f / 3.0f, cam->unk9C, cam->unkA0,
                  cam->unk94, cam->unk98);
    func_800484C8(&pool->unkE088[cam->unkE8], &cam->unkA4, cam->unk4C, cam->unk50, cam->unk54, cam->unk7C, cam->unk80,
                  cam->unk84, cam->unk70, cam->unk74, cam->unk78);
}
