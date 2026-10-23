#include "STDGNAME.h"
#include "m2c.h"
#include "STDGNAME_auto.h"
#include "STDGNAME_data.h"

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80082F8C);

Obj *func_80083084(void) {
    return func_80014504(func_80082F8C, 0x50, 4);
}

void func_800830B0(void *arg0, s32 arg1, s32 arg2) {
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

void func_80083138(u8 *obj) {
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

void func_8008327C(u8 *a) {
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
        func_80083138(a);
    case 3:
        break;
    }
}

Obj *func_80083330(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008327C, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x64) = func_800830B0;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    return temp_v0;
}

void func_80083378(void *arg0, s32 arg1) {
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

s32 func_8008340C(Fade *f) {
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

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083478);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083668);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083994);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80084318);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085078);

void func_800851B8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_800851C4(u8 *o, s32 s) {
    void *t[4];
    s32 i;
    func_8001FCC0(t);
    ((void (*)(u8 *, s32, s32))t[2])(o + 0x78, s, 0);
    for (i = strlen(o + 0x78) >> 1; i < *(s32 *)(o + 0x94); i++) {
        *(s16 *)(o + 0x78 + i * 2) = 0x4081;
    }
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085258);

void func_80085358(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xA;
}

u8 *func_80085364(s32 s, s32 b) {
    s32 k;
    u8 *o = (u8 *)func_80014504(func_80085078, 0xF8, 0x34);
    *(void **)(o + 0xF0) = func_80085258;
    *(void **)(o + 0xF4) = func_80085358;
    *(s32 *)(o + 0x54) = 0x1000;
    *(s32 *)(o + 0x58) = 3;
    k = D_8005CCA8[0];
    *(s32 *)(o + 0x50) = 1;
    *(s32 *)(o + 0x64) = b;
    if (k == 0) {
        *(s32 *)(o + 0x94) = 5;
    } else {
        *(s32 *)(o + 0x94) = 8;
    }
    func_800851C4(o, s);
    func_800851B8(o, 0x280, 0x100);
    return o;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085420);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008559C);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085B70);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085DE4);

Obj *func_80086144(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085DE4, 0xE0, 0x28);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086184);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086368);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008645C);

void func_8008656C(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_v0 = func_80083330();
    M2C_FIELD(temp_s0, void **, 8) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x64)(temp_v0, 0, 0x1E);
}

Obj *func_800865B0(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008645C, 0x6C, 0x10);
    M2C_FIELD(temp_v0, void (**)(void *), 0x68) = func_8008656C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800865F0);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800866AC);

void func_80086730(void *arg0, s32 arg1) {
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

s32 func_800867C4(Fade *f) {
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
