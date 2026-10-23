#include "STCRDDEK.h"
#include "m2c.h"
#include "STCRDDEK_auto.h"
#include "STCRDDEK_data.h"

void func_800831F0(u8 *o, Obj **out) {
    s16 r[4];
    u8 *sys;
    u8 *bg;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        sys = D_8004DE10;
        (*(void (**)(void))(sys + 0x150))();
        (*(void (**)(s32))(sys + 0x154))(0xF000);
        (*(void (**)(s32, s32, s32, s32))(sys + 0x174))(0x140, 0xF0, 0, 0);
        r[0] = 0;
        r[1] = 0;
        r[2] = 0x140;
        r[3] = 0xF0;
        bg = (*(u8 *(**)(s16 *, s32, s32))(sys + 0x16C))(r, 3, 0x1000);
        (*(void (**)(u8 *, s32, s32, s32))(bg + 0x12C))(bg, 0, 0, 0);
        *out = func_8008A0B8();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_800832E8(void) {
    return func_80014504(func_800831F0, 0x50, 4);
}

void func_80083314(void *arg0, s32 arg1, s32 arg2) {
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

void func_8008339C(u8 *obj) {
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

void func_800834E0(u8 *a) {
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
        func_8008339C(a);
    case 3:
        break;
    }
}

Obj *func_80083594(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800834E0, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80083314;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800835D8);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800837B4);

void func_800838C4(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s32 *)(o + 0x5C) = 0;
        break;
    case 1:
        func_800837B4(o);
    case 2:
        func_800835D8(o);
    case 3:
        break;
    }
}

Obj *func_80083934(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800838C4, 0x70, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 5;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008397C);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80083D28);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80084278);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80084440);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800847C0);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80084890);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80085210);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80086574);

Obj *func_8008660C(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086574, 0x494, 0xD4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    return temp_v0;
}

void func_80086664(void) {
}

void func_8008666C(u8 *o) {
    struct {
        u8 pad0[0x7C];
        void (*fn7C)(s32, s32);
        u8 pad80[0xA0 - 0x80];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x54), *(s32 *)(o + 0x58));
}

void func_800866A8(u8 *o) {
    u8 *p = D_8004B7D0;
    s32 bits = (*(s32 (**)(s32))(p + 0x3F4))(0);

    if ((bits >> (*(s32 (**)(s32, s32))(p + 0x408))(0, 0xE)) & 1) {
        *(s32 *)(o + 0xC) = 3;
    }
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008671C);

Obj *func_800867A0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008671C, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_800867E8(void *arg0, s32 arg1) {
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

s32 func_8008687C(Fade *f) {
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

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800868E8);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80086AD8);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80086E04);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80087788);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800884E8);

void func_80088628(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_80088634(u8 *o, s32 s) {
    void *t[4];
    s32 i;
    func_8001FCC0(t);
    ((void (*)(u8 *, s32, s32))t[2])(o + 0x78, s, 0);
    for (i = strlen(o + 0x78) >> 1; i < *(s32 *)(o + 0x94); i++) {
        *(s16 *)(o + 0x78 + i * 2) = 0x4081;
    }
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800886C8);

void func_800887C8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xA;
}

void *func_800887D4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800884E8, 0xF4, 0x34);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xEC) = func_800886C8;
    M2C_FIELD(temp_v0, void (**)(void *), 0xF0) = func_800887C8;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 3;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x94) = 0xA;
    M2C_FIELD(temp_v0, s32 *, 0x64) = -1;
    func_80088634((s32) temp_v0, arg0);
    func_80088628(temp_v0, 0x280, 0x100);
    return temp_v0;
}

void func_80088874(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_80088880(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = 1;
}

void func_80088894(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_800888A8(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_800888B0);

Obj *func_80088AC8(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800888B0, 0x9C, 0);
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x8C) = func_80088874;
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x90) = func_80088880;
    M2C_FIELD(temp_v0, void (**)(void *, s32, s32), 0x94) = func_80088894;
    M2C_FIELD(temp_v0, void (**)(void *, s32), 0x98) = func_800888A8;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 3;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80088B34);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80088D24);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80088E74);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008924C);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80089354);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_80089E98);

Obj *func_8008A0B8(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80089E98, 0x120, 0x6C);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x11C) = func_8008924C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 7;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008A100);

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008A21C);

void func_8008A2D8(void *arg0, s32 arg1) {
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

s32 func_8008A36C(Fade *f) {
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

void func_8008A3D8(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STCRDDEK/nonmatchings/STCRDDEK", func_8008A418);
