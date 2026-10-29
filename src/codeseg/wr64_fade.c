#include "common.h"
#include "wr64fade.h"

void func_801E7280(FadeTransition* fade);
void func_801E73A0(FadeTransition* fade);
void func_801E73A0(FadeTransition* fade);
void func_801E76C0(FadeTransition* fade);
void func_801E74BC(FadeTransition* fade);

// This file's .bss, 0x80228A10..0x80228A3F (yaml split). The code names some fields of
// sCurrentFadeTransitionProps by address (D_80228A14..D_80228A32, resolve.txt).
FadeTransition sCurrentFadeTransitionProps;
u16 D_80228A34;
s16 D_80228A36;
extern s16 D_80228A30;
extern s16 D_80228A32;

void FadeTransition_SetProps(s32 type, u32 fadeTime, s32 duration) {
    s32 fade_color = 255;
    FadeTransition* transition = &sCurrentFadeTransitionProps;

    sCurrentFadeTransitionProps = sFadeTransitionDefaultProps;

    switch (type) {
        case 1:
            transition->state = 1;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 0;
            transition->r = 0;
            transition->g = 0;
            transition->b = 0;
            transition->alpha = 0;
            break;

        case 2:
            transition->state = 2;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 0;
            transition->r = 0;
            transition->g = 0;
            transition->b = 0;
            transition->alpha = 255;
            break;

        case 7:
            transition->state = 7;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 0;
            transition->b = transition->g = transition->r = fade_color;
            transition->alpha = 255;
            break;

        case 3:
            transition->state = 3;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 0;
            transition->b = transition->g = transition->r = fade_color;
            transition->alpha = 0;
            break;

        case 6:
            D_80228A30 = 0;

        case 4:
            transition->state = 4;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 1;
            transition->unk_18 = 0x46;
            transition->unk_1A = 0x41;
            D_80228A32 = 1;
            break;

        case 5:
            transition->state = 5;
            transition->unk_2 = 0;
            transition->waitDuration = duration;
            transition->fadeInTime = fadeTime;
            transition->holdTime = 1;
            transition->unk_18 = -0x109;
            transition->unk_1A = 0x41;
            D_80228A32 = 1;
            break;

        default:
            break;
    }
}

void FadeTransition_Update(void) {
    FadeTransition* fade = &sCurrentFadeTransitionProps;

    if (fade->completed == 1) {
        fade->completed = 0;
    }

    switch (fade->state) {
        case 1:
        case 3:
            fade->unk_4 = 1;
            fade->completed = 2;
            func_801E7280(fade);
            break;
        case 2:
        case 7:
            fade->unk_4 = 1;
            fade->completed = 2;
            func_801E73A0(fade);
            break;
        case 4:
        case 6:
            fade->unk_4 = 1;
            fade->completed = 2;
            func_801E74BC(fade);
            break;
        case 5:
            fade->unk_4 = 1;
            fade->completed = 2;
            func_801E76C0(fade);
            break;
    }
}

void func_801E7280(FadeTransition* fade) {
    switch (fade->unk_2) {
        case 0:
            if (fade->fadeTimer >= fade->waitDuration) {
                fade->unk_2 = 1;
                fade->fadeTimer = 0;
            } else {
                fade->alpha = 0;
                fade->fadeTimer++;
            }
            break;

        case 1:
            if (fade->fadeInTime >= fade->fadeTimer) {
                fade->alpha = ((fade->fadeTimer * 255.0f) / fade->fadeInTime);
                fade->fadeTimer++;
            } else {
                fade->unk_2 = 2;
                fade->fadeTimer = 0;
                fade->alpha = 255;
            }
            break;

        case 2:
            if (fade->fadeTimer >= fade->holdTime) {
                sCurrentFadeTransitionProps = sFadeTransitionDefaultProps;
                fade->completed = 1;
            } else {
                fade->fadeTimer++;
            }
            break;
    }
}

void func_801E73A0(FadeTransition* fade) {
    switch (fade->unk_2) {
        case 0:
            if (fade->fadeTimer >= fade->waitDuration) {
                fade->unk_2 = 1;
                fade->fadeTimer = 0;
                break;
            } else {
                fade->alpha = 0;
                fade->fadeTimer++;
            }
            break;

        case 1:
            if (fade->fadeInTime >= fade->fadeTimer) {
                fade->alpha = (((fade->fadeInTime - fade->fadeTimer) / (f32) fade->fadeInTime) * 255.0f);
                fade->fadeTimer++;
            } else {
                fade->unk_2 = 2;
                fade->fadeTimer = 0;
                fade->alpha = 0;
            }
            break;

        case 2:
            if (fade->fadeTimer >= fade->holdTime) {
                sCurrentFadeTransitionProps = sFadeTransitionDefaultProps;
                fade->completed = 1;
            } else {
                fade->fadeTimer++;
            }
            break;
    }
}

void func_801E74BC(FadeTransition* fade) {
    switch (fade->unk_2) {
        case 0:
            if (fade->fadeTimer >= fade->waitDuration) {
                fade->unk_2 = 1;
                fade->fadeTimer = 0;
            } else {
                fade->fadeTimer++;
            }
            break;

        case 1:
            fade->fadeTimer++;
            if (fade->fadeInTime == 0) {
                fade->unk_18 += 20;
            } else {
                fade->unk_18 += 20;
            }
            if (fade->unk_18 >= 250) {
                fade->unk_2 = 2;
                fade->unk_18 = 250;
                fade->fadeTimer = 0;
            }
            break;

        case 2:
            if (fade->fadeTimer >= fade->holdTime) {
                sCurrentFadeTransitionProps = sFadeTransitionDefaultProps;
                fade->completed = 1;
            } else {
                fade->fadeTimer++;
            }
            break;
    }

    func_800481E0((Mtx*) D_801CE5F8->unk1300, &D_80228A34, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88((Mtx*) D_801CE5F8->unk1340, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, (f32) fade->unk_18,
                  (f32) fade->unk_1A, -250.0f, 0.05f);

    fade->unk_1E++;
    if (fade->unk_1E >= 2) {
        fade->unk_1E = 0;
        fade->unk_1C ^= 1;
    }
}

void func_801E76C0(FadeTransition* fade) {
    switch (fade->unk_2) {
        case 0:
            if (fade->fadeTimer >= fade->waitDuration) {
                fade->unk_2 = 1;
                fade->fadeTimer = 0;
                if (D_801CE638 != 8) {
                    if (fade->fadeInTime == 2) {
                        AudioGeneral_PlaySound(0x38, 0);
                    } else {
                        AudioGeneral_PlaySound(0x2A, 0);
                    }
                }
            } else {
                fade->fadeTimer++;
            }
            break;
        case 1:
            fade->fadeTimer++;
            if (fade->fadeInTime == 0) {
                fade->unk_18 += 20;
            } else {
                fade->unk_18 += 20;
            }

            if (fade->unk_18 >= -0x55) {
                fade->unk_2 = 2;
                fade->unk_18 = -0x55;
                fade->fadeTimer = 0;
            }
            break;

        case 2:
            if (fade->fadeTimer >= fade->holdTime) {
                sCurrentFadeTransitionProps = sFadeTransitionDefaultProps;
                fade->completed = 1;
            } else {
                fade->fadeTimer++;
            }
            break;
    }

    func_800481E0((Mtx*) D_801CE5F8->unk1300, &D_80228A34, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88((Mtx*) D_801CE5F8->unk1340, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, (f32) fade->unk_18,
                  (f32) fade->unk_1A, -250.0f, 0.05f);

    fade->unk_1E += 1;
    if (fade->unk_1E >= 2) {
        fade->unk_1E = 0;
        fade->unk_1C ^= 1;
    }
}

// Fields of sCurrentFadeTransitionProps, which the asm addresses by their own symbols.
extern s16 D_80228A14; // unk_4
extern s16 D_80228A18; // fadeTimer
extern s16 D_80228A1C; // fadeInTime
extern s16 D_80228A20; // r
extern s16 D_80228A22; // g
extern s16 D_80228A24; // b
extern s16 D_80228A26; // alpha
extern Gfx* D_80226CE4[2][2];
extern Gfx* D_80226CF4[2][2];
extern Mtx D_7001300[];
extern Mtx D_7001340[];
extern Gfx D_106F5B0[];

Gfx* FadeTransition_Draw(Gfx* gdl) {
    FadeTransition* fade = &sCurrentFadeTransitionProps;
    Gfx** dl;
    Gfx* dl0;
    Gfx* dl1;

    if ((sCurrentFadeTransitionProps.state == 0) || (D_80228A14 == 0)) {
        return gdl;
    }
    if (D_80228A30 != D_80228A36) {
        return gdl;
    }
    switch (fade->state) {
        case 1:
        case 2:
            if (gPlayers == ONE_PLAYER) {
                gdl = func_801E7C58(gdl, 8, 20, 310, 218, D_80228A20, D_80228A22,
                                    D_80228A24, D_80228A26);
            } else {
                gdl = func_801E7C58(gdl, 8, 12, 310, 228, D_80228A20, D_80228A22,
                                    D_80228A24, D_80228A26);
            }
            break;
        case 3:
        case 7:
            if (gPlayers == ONE_PLAYER) {
                gdl = func_801E7C58(gdl, 8, 20, 310, 218, D_80228A20, D_80228A22,
                                    D_80228A24, D_80228A26);
            } else {
                gdl = func_801E7C58(gdl, 8, 12, 310, 228, D_80228A20, D_80228A22,
                                    D_80228A24, D_80228A26);
            }
            break;
        case 4:
        case 5:
        case 6:
            gSPPerspNormalize(gdl++, D_80228A34);
            gSPMatrix(gdl++, D_7001300, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPMatrix(gdl++, D_7001340, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gdl++, D_106F5B0);
            if (D_80228A1C == 0) {
                dl = D_80226CE4[D_80228A18 & 1];
            } else {
                dl = D_80226CF4[D_80228A18 & 1];
            }
            dl0 = dl[0];
            dl1 = dl[1];
            gDPPipeSync(gdl++);
            gSPDisplayList(gdl++, dl0);
            gDPPipeSync(gdl++);
            gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_XLU_SURF2);
            gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 319, 239);
            gSPDisplayList(gdl++, dl1);
            break;
    }
    return gdl;
}

Gfx* func_801E7C58(Gfx* dList, u32 ulx, u32 uly, u32 lrx, u32 lry, u32 r, u32 g, u32 b, u32 a) {
    if (r > 255) {
        r = 255;
    }
    if (g > 255) {
        g = 255;
    }
    if (b > 255) {
        b = 255;
    }
    if (a > 255) {
        a = 255;
    }

    if ((ulx > (320 - 1)) && (lrx > (320 - 1))) {
        return dList;
    }
    if ((uly > 240 - 1) && (lry > 240 - 1)) {
        return dList;
    }
    if (ulx > (320 - 1)) {
        ulx = 0;
    }
    if (lrx > (320 - 1)) {
        lrx = 320 - 1;
    }
    if (uly > (240 - 1)) {
        uly = 0;
    }
    if (lry > (240 - 1)) {
        lry = 240;
    }

    gSPViewport(dList++, &D_106F008);
    gSPClearGeometryMode(dList++, -1);
    gSPSetGeometryMode(dList++, G_SHADE);
    gSPTexture(dList++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(dList++);
    gDPSetCycleType(dList++, G_CYC_1CYCLE);
    gDPSetPrimColor(dList++, 0, 0, r, g, b, a);
    gDPSetCombineMode(dList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(dList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPFillRectangle(dList++, ulx, uly, lrx + 1, lry + 1);
    gDPSetAlphaCompare(dList++, G_AC_NONE);

    return dList++;
}

extern Vp* D_106F008;

void* func_801E7E74(Gfx* dList, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gSPViewport(dList++, &D_106F008);
    gSPClearGeometryMode(dList++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | -1);
    gSPSetGeometryMode(dList++, G_SHADE);
    gSPTexture(dList++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(dList++);
    gDPSetCycleType(dList++, G_CYC_1CYCLE);
    gDPSetCombineMode(dList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

    if (arg4 == 0xFF) {
        gDPSetRenderMode(dList++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    } else {
        gDPSetRenderMode(dList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    }

    gDPSetScissor(dList++, G_SC_NON_INTERLACE, 0, 0, 320 - 1, 240 - 1);

    gDPSetAlphaCompare(dList++, G_AC_NONE);
    gDPSetPrimColor(dList++, 0, 0, arg1, arg2, arg3, arg4);

    return dList;
}

Gfx* func_801E7FD8(Gfx* dList, s32 ulx, s32 uly, s32 lrx, s32 lry) {
    s32 flag = 1;

    if (ulx > 320 - 1) {
        flag = 0;
    } else if (lrx < 0) {
        flag = 0;
    } else {
        if (uly > 240 - 1) {
            flag = 0;
        } else if (lry < 0) {
            flag = 0;
        }
    }

    if (flag == 0) {
        return dList;
    }

    if (ulx < 0) {
        ulx = 0;
    }
    if (lrx > 320 - 1) {
        lrx = 320 - 1;
    }
    if (uly < 0) {
        uly = 0;
    }
    if (lry > 240 - 1) {
        lry = 240 - 1;
    }

    gDPFillRectangle(dList++, ulx, uly, lrx + 1, lry + 1);

    return dList;
}
