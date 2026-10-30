#include "STPLNMET.h"
#include "m2c.h"
#include "STPLNMET_auto.h"
#include "STPLNMET_data.h"

void func_80082F58(s32 a, s32 b, u8 *o, s16 *p) {
    (*(void (**)(u8 *, s32, s32))(o + 0x118))(o, p[2] / 2, p[3] / 2);
    (*(void (**)(u8 *, s32))(o + 0x148))(o, 5);
}

void func_80082FCC(u8 *o, u8 **w) {
    SRect r;
    u8 *t;
    u8 *x;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = (u8 *)D_8004DE10;
        (*(void (**)(void))(t + 0x150))();
        (*(void (**)(s32))(t + 0x154))(0x19000);
        (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
        r.x = 0;
        r.y = 0;
        r.w = 0x140;
        r.h = 0xF0;
        x = (*(u8 *(**)(SRect *, s32, s32))(t + 0x16C))(&r, 1, 0x1000);
        (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 1, 1, 1);
        func_80082F58((s32)o, (s32)w, x, (s16 *)&r);
        (*(void (**)(SRect *, s32, s32))(t + 0x16C))(&r, 3, 0x1001);
        (*(void (**)(s32, s32, s32))(t + 0x180))(0x1001, 0x1000, 1);
        w[0] = (u8 *)func_800882A4();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80083118(void) {
    return func_80014504(func_80082FCC, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083144);

void func_80083310(u8 *o, s32 a, s32 b) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        s32 unk28;
        void (*fn2C)(s32);
        u8 pad30[0x38 - 0x30];
    } g;

    *(s32 *)(o + 0x50) = a;
    *(s32 *)(o + 0x54) = b;
    func_8001FFA8(&g);
    g.fn24(a, b);
    g.fn2C((*(s32 (**)(s32))&D_80044F5C)(0x8A70000));
    *(s32 *)(o + 0x58) = 1;
}

void func_80083398(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

Obj *func_800833A4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083144, 0x84, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x7C) = func_80083310;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x80) = func_80083398;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800833E8);

Obj *func_800835C4(void) {
    return func_80014504(func_800833E8, 0x68, 0);
}

void func_800835F0(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32);
        u8 pad90[4];
        void (*fn94)(s32, s32);
        u8 pad98[0xA0 - 0x98];
    } g;
    u8 *t;
    s32 v;
    Pair32 *tb;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        func_8001F648(&g);
        g.fn74(0x280, 0x100);
        g.fn7C(0x1001, 6);
        t = (u8 *)D_8004DE10;
        v = (*(s32 (**)(void))(t + 0x188))();
        tb = D_800885EC;
        if (tb[*(s32 *)(o + 0x60)].x < v - *(s32 *)(o + 0x64)) {
            *(s32 *)(o + 0x64) = (*(s32 (**)(void))(t + 0x188))();
            *(s32 *)(o + 0x60) += 1;
            if (tb[*(s32 *)(o + 0x60)].y == 0) {
                *(s32 *)(o + 0x60) = 0;
            }
        }
        g.fn84((*(s32 (**)(s32))&D_80044F5C)(0x28A0000), D_800885EC[*(s32 *)(o + 0x60)].y, 0, 0);
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80083748(void) {
    return func_80014504(func_800835F0, 0x68, 0);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083774);

void func_80083D38(s32 arg0) {
    M2C_FIELD(func_80014504(func_80083774, 0x5C, 8), s32 *, 0x50) = arg0;
}

void func_80083D70(void *arg0, s32 arg1) {
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

s32 func_80083E04(Fade *f) {
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

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083E70);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80084060);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_8008438C);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80084D10);

void func_80085A70(u8 *o, s32 b) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        u8 pad28[4];
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        func_8001FFA8(&g);
        g.fn24(*(s32 *)(o + 0x5C), *(s32 *)(o + 0x60));
        g.fn2C(((s32 (*)(s32))((s32 *)&D_80044F5C)[0])(0x7710000));
        if (D_8005CCA8[0] == 0) {
            D_80089BB0.n = 3;
            D_80089BB0.a = D_800895A0;
            D_80089BB0.b = D_800895C4;
        } else {
            D_80089BB0.n = 1;
            D_80089BB0.a = D_8008983C;
            D_80089BB0.b = D_80089848;
        }
        *(s32 *)(o + 0xBC) = 10;
        *(s32 *)(o + 0xDC) = 10;
        *(s32 *)(o + 0xCC) = 10;
        func_80083E70(o, b);
        break;
    case 1:
        func_80084D10(o, b);
        func_8008438C(o);
        break;
    case 2:
    case 3:
        break;
    }
}

void func_80085BB0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_80085BBC(u8 *o, s32 s) {
    void *t[4];
    s32 i;
    func_8001FCC0(t);
    ((void (*)(u8 *, s32, s32))t[2])(o + 0x78, s, 0);
    for (i = strlen(o + 0x78) >> 1; i < *(s32 *)(o + 0x94); i++) {
        *(s16 *)(o + 0x78 + i * 2) = 0x4081;
    }
}

void func_80085C50(DkArr78 *o, u8 *buf) {
    struct {
        u8 pad0[8];
        void (*fn8)(u8 *, u16 *, s32);
        u8 padC[4];
    } t;
    s32 i;
    for (i = 0; i < o->n * 2; i++) {
        buf[i] = 0;
    }
    for (i = o->n - 1; i >= 0; i--) {
        if (o->a[i] != 0x4081) {
            break;
        }
        o->a[i] = 0;
    }
    for (i = 0; i < o->n; i++) {
        if (o->a[i] != 0x4081) {
            break;
        }
    }
    func_8001FCC0(&t);
    t.fn8(buf, &o->a[i], 1);
}

void func_80085D50(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xA;
}

void func_80085D5C(u8 *o, s32 f) {
    s32 i;
    s32 x = *(s32 *)(o + 0x24);
    if (f != 0) {
        *(s32 *)(o + 0xC) = 2;
        func_80084060(o, x, 0);
        for (i = *(s32 *)(o + 0x94) - 1; i >= 0; i--) {
            if (*(u16 *)(o + i * 2 + 0x78) != 0x4081) {
                break;
            }
        }
        if (i == *(s32 *)(o + 0x94) - 1) {
            *(s32 *)(o + 0x90) = i;
        } else {
            *(s32 *)(o + 0x90) = i + 1;
        }
    } else {
        *(s32 *)(o + 0xC) = 1;
        *(s32 *)(o + 0x10) = 2;
        func_80084060(o, x, 1);
    }
}

u8 *func_80085E10(s32 s) {
    s32 k;
    u8 *o = (u8 *)func_80014504(func_80085A70, 0xF8, 0x34);
    *(void **)(o + 0xEC) = func_80085C50;
    *(void **)(o + 0xF0) = func_80085D5C;
    *(void **)(o + 0xF4) = func_80085D50;
    *(s32 *)(o + 0x54) = 0x1001;
    *(s32 *)(o + 0x58) = 6;
    k = D_8005CCA8[0];
    *(s32 *)(o + 0x50) = 0;
    *(s32 *)(o + 0x64) = -1;
    if (k == 0) {
        *(s32 *)(o + 0x94) = 5;
    } else {
        *(s32 *)(o + 0x94) = 8;
    }
    func_80085BBC(o, s);
    func_80085BB0(o, 0x140, 0x100);
    return o;
}

void func_80085ECC(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;

    temp_v0 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x20, 0x1A);
    M2C_FIELD(arg1, s32 *, 0) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0, 4);
    temp_v0_2 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x61, 0x42);
    M2C_FIELD(arg1, s32 *, 4) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_2, 1);
    temp_v0_3 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x40, 0x60);
    M2C_FIELD(arg1, s32 *, 8) = temp_v0_3;
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_3, 1);
    temp_v0_4 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x5A, 0xA9);
    M2C_FIELD(arg1, s32 *, 0xC) = temp_v0_4;
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_4, 1);
    temp_v0_5 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x6B, 0xB9);
    M2C_FIELD(arg1, s32 *, 0x14) = temp_v0_5;
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_5, 1);
    temp_v0_6 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x6B, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x18) = temp_v0_6;
    M2C_FIELD(temp_v0_6, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_6, 1);
    temp_v0_7 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) - 2, 0x5A, 0xB9);
    M2C_FIELD(arg1, s32 *, 0x1C) = temp_v0_7;
    M2C_FIELD(temp_v0_7, M2C_UNK (**)(s32, M2C_UNK), 0x88)(temp_v0_7, 1);
    temp_a0 = M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(temp_a0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_a0, 0);
    temp_v0_8 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xE3, 0xA9);
    M2C_FIELD(arg1, s32 *, 0x10) = temp_v0_8;
    M2C_FIELD(temp_v0_8, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_8, 1);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086074);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800862F0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800869C8);

void func_80086E40(u8 *o, s32 flag) {
    s32 x = *(s32 *)(o + 0x24);
    s32 i;

    if (flag) {
        *(s32 *)(o + 0xC) = 2;
        func_80086074(o, x, 0);
    } else {
        *(s32 *)(o + 0xC) = 1;
        *(s32 *)(o + 0x10) = 0;
        for (i = 2; i >= 0; i--) {
            *(s32 *)(o + i * 4 + 0x70) = 0;
        }
        *(s32 *)(o + 0x60) = 0;
        func_80086074(o, x, 1);
    }
}

void func_80086EAC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
}

void func_80086EB8(u8 *o, s32 b) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        func_80085ECC(o, b);
        *(s32 *)(o + 0xBC) = 10;
        *(s32 *)(o + 0xC4) = 0x1000;
        *(s32 *)(o + 0xCC) = 10;
        *(s32 *)(o + 0xD4) = 0x1000;
        func_80086E40(o, 1);
        break;
    case 1:
        func_800869C8(o, b);
        func_800862F0(o);
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80086F60(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086EB8, 0xE4, 0x20);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xDC) = func_80086E40;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xE0) = func_80086EAC;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086FC0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087190);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087444);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087774);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800879E0);

void func_80087A30(u8 *o, s32 a) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        func_80086FC0(o, a);
        func_800879E0(o, 1);
        break;
    case 1:
        func_80087774(o, a);
        func_80087444(o);
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80087AC0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087A30, 0x8C, 0x30);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x88) = func_800879E0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80087B14(u8 *o, u8 *b) {
    s32 i = 0;
    u8 *f = (u8 *)D_80044B38;
    for (; i < 3; i++) {
        ((u8 **)(b + 0x1C))[i] = (u8 *)func_8001AE38(*(s16 *)(o + 0x50), 3, D_80089A80[i * 2], 0x12);
        (*(void (**)(u8 *, s32, s32))(((u8 **)(b + 0x1C))[i] + 0x114))(((u8 **)(b + 0x1C))[i], (*(s32 (**)(s32))(f + 0x414))(D_8005CCA8[0] + 0x8D), i + 3);
        (*(void (**)(u8 *, s32))(((u8 **)(b + 0x1C))[i] + 0x138))(((u8 **)(b + 0x1C))[i], 1);
        (*(void (**)(u8 *, s32))(((u8 **)(b + 0x1C))[i] + 0x144))(((u8 **)(b + 0x1C))[i], 0);
    }
}

void func_80087BF4(u8 *o, u8 *b, s32 c) {
    s32 i;
    for (i = 0; i < 3; i++) {
        (*(void (**)(u8 *, s32))(((u8 **)(b + 0x1C))[i] + 0x144))(((u8 **)(b + 0x1C))[i], (u8)c);
        if (*(s32 *)(o + 0x58) == i) {
            (*(void (**)(u8 *, s32))(((u8 **)(b + 0x1C))[i] + 0x138))(((u8 **)(b + 0x1C))[i], 0);
        } else {
            (*(void (**)(u8 *, s32))(((u8 **)(b + 0x1C))[i] + 0x138))(((u8 **)(b + 0x1C))[i], 1);
        }
    }
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087C9C);

void func_80088070(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32, s32);
        u8 pad90[4];
        void (*fn94)(s32, s32);
        u8 pad98[0xA0 - 0x98];
    } g;
    s32 s;

    func_8001F648(&g);
    g.fn74(0x280, 0x100);
    g.fn7C(*(s32 *)(o + 0x50), *(s32 *)(o + 0x54));
    s = *(s32 *)(o + 0x64);
    if (s == 0) {
        return;
    }
    if (s != 0x1000) {
        g.fn8C(s, 0x1000, 0x1000);
        g.fn94(0x18, 0x20);
    }
    g.fn84((*(s32 (**)(s32))&D_80044F5C)(0x28A0000), *(s32 *)(o + 0x58) + 0xC, 0x18, 0x15);
}

void func_80088138(u8 *o, u8 *b) {
    u8 *t;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
        default:
            ((void (*)(void))D_80089B98[0])();
            ((void (*)(s32))D_80055C54[0])(0x20);
            *(s32 *)(o + 0x10) += 1;
            break;
        case 1:
            if (((s32 (*)(void))D_80089B9C[0])() == 0) {
                func_80087B14(o, b);
                *(s32 *)(o + 0x5C) = 10;
                (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            }
            break;
        }
        break;
    case 1:
        func_80087C9C(o, b);
        func_80088070(o);
        break;
    case 2:
        t = (u8 *)D_800519EC;
        if ((*(s32 (**)(void))(t + 0x4274))() == 0) {
            (*(void (**)(s32))(t + 0x425C))(0x60800000);
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 1);
        }
        break;
    case 3:
        ((void (*)(s32))D_80055C68[0])(0x60800000);
        ((void (*)(s32, s32))D_8004B440[0])(0x2D8, 0);
        break;
    }
}

Obj *func_800882A4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088138, 0x6C, 0x28);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 5;
    return temp_v0;
}

void func_800882E0(void) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        u8 pad28[4];
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *f;

    func_8001FFA8(&g);
    g.fn24(0x280, 0x100);
    f = (u8 *)D_80044B38;
    g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x28B0000));
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x8D);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x4E);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x86);
    (*(void (**)(s32))(f + 0x40C))(0x771);
}

s32 func_80088398(void) {
    u8 *f = (u8 *)D_80044B38;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x8D) != 0) return 1;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x4E) != 0) return 1;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x86) != 0) return 1;
    return (*(s32 (**)(s32))(f + 0x404))(0x771) != 0;
}

void func_80088438(void *arg0, s32 arg1) {
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

s32 func_800884CC(Fade *f) {
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

void func_80088538(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088578);
