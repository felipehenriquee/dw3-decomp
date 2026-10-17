#include "STCRDSHP.h"
#include "m2c.h"
#include "STCRDSHP_auto.h"
#include "STCRDSHP_data.h"

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008300C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800832C8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800835B8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80083780);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80083BA8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800843C0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800844B8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800852CC);

void func_8008536C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800852CC, 0x730, 0x78);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

void func_800853B4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (0xFF00 / arg2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF00;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) -(0xFF00 / arg2);
}

void func_8008543C(u8 *obj) {
    u8 *sys = D_8004DE10;
    u8 *o;
    u32 *ot;
    PolyF4 *p;
    DrMode *m;
    s32 c;

    o = (*(u8 *(**)(s32))(sys + 0x17C))(*(s32 *)(obj + 0x50));
    ot = (*(u32 *(**)(u8 *, s32))(o + 0x138))(o, *(s32 *)(obj + 0x54));
    p = (*(PolyF4 *(**)(void))(sys + 0x158))();
    ((u8 *)p)[3] = 5;
    p->code = 0x2A;
    m = (DrMode *)(p + 1);
    c = *(s32 *)(obj + 0x5C) >> 8;
    p->x0 = p->x2 = 0;
    p->y0 = p->y1 = 0;
    p->x1 = p->x3 = 320;
    p->y2 = p->y3 = 256;
    p->r0 = p->g0 = p->b0 = c;
    p->tag = (p->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)p & 0xFFFFFF);
    ((u8 *)m)[3] = 1;
    m->code[0] = 0xE1000245;
    m->tag = (m->tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)m & 0xFFFFFF);
    (*(void (**)(void *))(sys + 0x15C))((u8 *)m + 8);
}

void func_80085580(u8 *a) {
    s32 v;

    switch (*(s32 *)(a + 0xC)) {
    case 0:
    default:
        (*(void (**)(void *))(a + 0x38))(a);
        break;
    case 1:
        if (*(s32 *)(a + 0x10) == 0) {
            break;
        }
        v = *(s32 *)(a + 0x5C) + *(s32 *)(a + 0x60);
        *(s32 *)(a + 0x5C) = v;
        if (*(s32 *)(a + 0x58) == 0) {
            if (v > 0xFF00) {
                *(s32 *)(a + 0x5C) = 0xFF00;
                *(s32 *)(a + 0xC) = 2;
            }
        } else if (v < 0) {
            *(s32 *)(a + 0x5C) = 0;
            *(s32 *)(a + 0xC) = 2;
        }
    case 2:
        func_8008543C(a);
    case 3:
        break;
    }
}

void func_80085634(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085580, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_800853B4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085678);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085730);

void func_80085788(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800857B0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085BAC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085CD8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085DA0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085FDC);

void func_80086074(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x88, 0x80);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x115, 0x80);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x126, 0x80);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x115, 0xA6);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x12C, 0xA6);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x50, 0x97);
    M2C_FIELD(arg1, s32 *, 0x18) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xCE, 0x97);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xF0, 0x97);
    M2C_FIELD(arg1, s32 *, 0x20) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xCE, 0xA4);
    M2C_FIELD(arg1, s32 *, 0x24) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xF0, 0xA4);
    M2C_FIELD(arg1, s32 *, 0x2C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 3, 0x117, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x28) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 3, 0x11A, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x30) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x12, 0x67);
    temp_v0 = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x121, 0x67);
    M2C_FIELD(arg1, s32 *, 0x34) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, s32), 0x15C)(temp_v0, M2C_FIELD(arg0, s32 *, 0x58));
    M2C_FIELD(arg1, s32 *, 0x38) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x9A, 0x39);
    M2C_FIELD(arg1, s32 *, 0x3C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC5, 0x56);
    M2C_FIELD(arg1, s32 *, 0x40) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC5, 0x66);
    temp_v0_2 = func_8001B364(M2C_FIELD(arg0, s16 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) - 3, 0xB8, 0x56);
    M2C_FIELD(arg1, s32 *, 0x44) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0_2, 0);
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008627C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008674C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80086DC4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087A2C);

void func_80087B84(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087A2C, 0xDC, 0x4C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0xA0) = arg1;
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087BDC);

void func_80087CD4(void) {
    func_80014504(func_80087BDC, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087D00);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087E8C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087FAC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800880C4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008838C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088AFC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088B50);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088CA0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088E24);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088EF4);

void func_80088FB4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

s32 func_80089048(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800890B4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800890F4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80089160);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008923C);
