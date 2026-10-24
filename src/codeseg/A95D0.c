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
    f32 unk24;
    f32 unk28;
    f32 unk2C;
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

void func_800AB92C(void);

#define ANG_NORMALIZE_1(x) (x < 0.0f ? 360.0f : 0.0f)
#define ANG_NORMALIZE_2(x) (x > 360.0f ? -360.0f : 0.0f)

#define SIGNF(x) (x >= 0 ? 1.0f : -1.0f)

extern s32 D_80228110;
extern struct UnkStruct_801DB0E4_arg0 D_80228190;
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

typedef struct UnkA95D0_Payload1 {
    /* 0x00 */ f32 unk0[3];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10[3];
    /* 0x1C */ f32 unk1C;
} UnkA95D0_Payload1; // size = 0x20

typedef struct UnkA95D0_Payload2 {
    /* 0x00 */ f32 unk0[14];
} UnkA95D0_Payload2; // size = 0x38

typedef struct UnkA95D0_Payload5 {
    /* 0x00 */ f32 unk0[33];
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
    /* 0x10 */ s32 unk10[10];
} UnkA95D0_Runner; // size = 0x38

void func_801DEA94(UnkA95D0_Cursor* cursors, s32 count);
extern UnkA95D0_Runner D_80228058[];
extern UnkA95D0_Obj D_80227E98[];
void func_800AB95C(s32, s32);
extern UnkA95D0_Step D_80223F7C[];
void func_801DF744(UnkA95D0_Obj* obj);
void func_801DF38C(UnkA95D0_Obj* obj);
void func_801DF128(UnkA95D0_Obj* obj);
void func_801DF2F8(UnkA95D0_Obj* obj, f32* arg1, f32* arg2, f32* arg3, f32* arg4);
void func_801DDEDC(camera_unk_1* cam, UnkA95D0_Obj* obj, UnkA95D0_Runner* runner);
void func_801DEEC4(UnkA95D0_Obj* obj);
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

    arg0->unk24 = 0.0f;
    arg0->unk28 = 1.0f;
    arg0->unk2C = 0.0f;
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

        arg0->unk24 = vec[0] / magnitude;
        arg0->unk28 = vec[1] / magnitude;
        arg0->unk2C = vec[2] / magnitude;

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
                func_801DB0E4(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
            }
            func_801DB1DC(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC0AC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC274.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC404.s")

void func_801DC5A8(UnkA95D0_Runner* runner) {
    s32 index = runner->step - D_80223F7C;

    if (index == 2 && runner->frame == 1) {
        func_800AB92C();
        func_800AB95C(1, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC60C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DCD34.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD2D0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD6B4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD85C.s")

void func_801DDA24(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDAB8(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDAB8.s")

void func_801DDE48(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDEDC(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDEDC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE3CC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE690.s")

void func_801DEA94(UnkA95D0_Cursor* cursors, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        cursors[i].seg = 0;
        cursors[i].frame = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEB08.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEC00.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF2F8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF38C.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF668.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF744.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DFCB8.s")

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

void func_801DFDA8(UnkA95D0_Runner* runner, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7,
                   s32 arg8, s32 arg9, s32 arg10) {
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DFE80.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0304.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0454.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E05A4.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E06F8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E084C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0A18.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0BE8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0DB8.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E0FF0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801E11B4.s")
