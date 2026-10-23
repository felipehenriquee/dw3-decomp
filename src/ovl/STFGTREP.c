#include "STFGTREP.h"
#include "m2c.h"
#include "STFGTREP_auto.h"
#include "STFGTREP_data.h"

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80082E70);

Obj *func_80082F6C(void) {
    return func_80014504(func_80082E70, 0x50, 4);
}

void func_80082F98(void *arg0, s32 arg1, s32 arg2) {
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

void func_80083020(u8 *obj) {
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

void func_80083164(u8 *a) {
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
        func_80083020(a);
    case 3:
        break;
    }
}

Obj *func_80083218(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083164, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x64) = func_80082F98;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083260);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083404);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083744);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083D9C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083E74);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800848E4);

void func_80084A08(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}

void func_80084A14(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xB;
}

void func_80084A20(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0x14;
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084A2C);

void func_80084AE0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

Obj *func_80084AEC(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800848E4, 0x174, 0x30);
    M2C_FIELD(temp_v0, void (**)(void *), 0x160) = func_80084A08;
    M2C_FIELD(temp_v0, void (**)(void *), 0x164) = func_80084A14;
    M2C_FIELD(temp_v0, void (**)(void *), 0x168) = func_80084A20;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x16C) = func_80084A2C;
    M2C_FIELD(temp_v0, void (**)(void *), 0x170) = func_80084AE0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s16 *, 0x134) = -1;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg2;
    return temp_v0;
}

void func_80084B98(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 3, 0x42, 0x17);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 3, 0x45, 0x17);
    temp_v0 = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 1, 0x14, 0xC2);
    M2C_FIELD(arg1, s32 *, 8) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x160)(temp_v0, 2);
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084C20);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084EC4);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800857F0);

Obj *func_80085B24(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800857F0, 0xA0, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 7;
    return temp_v0;
}

void func_80085B60(void) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        u8 pad28[4];
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *f;

    func_8001FFA8(&g);
    g.fn24(0x280, 0);
    f = (u8 *)D_80044B38;
    g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x7A00000));
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x55);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x4E);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x6A);
}

/* algum dos 3 arquivos (0x55, 0x4E, 0x6A a partir de D_8005CCA8) existe? */
s32 func_80085C08(void) {
    u8 *f = (u8 *)D_80044B38;

    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x55) != 0) {
        return 1;
    }
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x4E) != 0) {
        return 1;
    }
    return (*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x6A) != 0;
}

void func_80085C90(void *arg0, s32 arg1) {
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

s32 func_80085D24(Fade *f) {
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

void func_80085D90(Lerp *l, s32 from, s32 to, s32 n) {
  if (from != to)
  {
    l->frames = n;
    l->acc = from << 8;
    l->step = ((to - from) << 8) / l->frames;
    l->cur = from;
    l->target = to;
    l->active = 1;
  }
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085DD0);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085E3C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086184);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_8008634C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800865C0);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_8008670C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086844);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086924);
