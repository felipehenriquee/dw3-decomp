#include "WSTAG780.h"
#include "m2c.h"
#include "WSTAG780_auto.h"
#include "WSTAG780_data.h"

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A5EC0);

u8 *func_800A605C(s32 a, s32 b, s32 c, s32 d) {
    u8 *o = (u8 *)func_80014504(func_800A5EC0, 0x70, 0);
    Pair32 *e;
    u8 *t = (u8 *)D_800A83C8;
    *(s32 *)(o + 0x54) = b;
    *(s32 *)(o + 0x50) = a;
    *(s32 *)(o + 0x58) = c;
    *(s32 *)(o + 0x5C) = d;
    e = (Pair32 *)(t + (c * 8 + b * 16 + a * 32));
    *(s32 *)(o + 0x68) = e->x << 8;
    *(s32 *)(o + 0x6C) = e->y << 8;
    if (c != 0 && d != 0) {
        *(s32 *)(o + 0x68) += 0x3200;
        *(s32 *)(o + 0x6C) -= 0x1900;
    }
    return o;
}

void func_800A6130(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(0x1002, 7);
    g.fn74(0x140, 0x100);
    g.fn78(0, 0x1F0);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x1C50000), *(s32 *)(o + 0x50) >> 2, 0xDA, 0x47);
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A61C8);

u8 *func_800A635C(s32 arg0) {
    return func_800143DC(func_800A61C8, 84, 0, arg0);
}

s16 func_800A638C(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[1] -= dt;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A638C(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800A6480(u8 *o, s32 tex) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[8];
        void (*fn80)(s32, s32);
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;

    if (*(s32 *)(o + 0xC) == 1) {
        func_8001F648(&g);
        g.fn74(0x140, 0x100);
        g.fn80(tex, 4);
        g.fn88(0);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80099D8C), *(s32 *)(o + 0x50), *(s32 *)(o + 0x54), *(s32 *)(o + 0x58));
    }
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A652C);

Obj *func_800A6678(s32 arg0) {
    Obj *o = func_80014504(func_800A652C, 0x60, 0);
    M2C_FIELD(o, s32 *, 4) = arg0;
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A66B0);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A67A4);

Obj *func_800A6914(void) {
    return func_80014504(func_800A67A4, 0x60, 0);
}

void func_800A6940(u8 *o, Obj **w) {
    s32 i;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (i = 0; i < 6; i++) {
            w[i] = func_800A6678(i);
        }
        w[6] = func_800A6914();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_800A69D8(void) {
    return func_80014504(func_800A6940, 0x50, 0x1C);
}

void func_800A6A04(void *arg0, void *arg1) {
    s32 temp_a3;
    s32 temp_s1;

    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        temp_a3 = ((s32 (*)()) *D_8004DC0C)() & 1;
        if (M2C_FIELD(arg1, s32 *, 0) == 0) {
            M2C_FIELD(arg1, s32 *, 0) = func_800A605C(0, 0, 0, temp_a3);
        }
        if (M2C_FIELD(arg1, s32 *, 0xC) == 0) {
            M2C_FIELD(arg1, s32 *, 0xC) = func_800A605C(1, 1, 0, 0);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        temp_s1 = ((s32 (*)()) *D_8004DC0C)() & 1;
        if (M2C_FIELD(arg1, s32 *, 0) == 0) {
            M2C_FIELD(arg1, s32 *, 0) = func_800A605C(0, 0, 1, 0);
        }
        if (M2C_FIELD(arg1, s32 *, 0xC) == 0) {
            M2C_FIELD(arg1, s32 *, 0xC) = func_800A605C(0, 0, 1, 1);
        }
        if (M2C_FIELD(arg1, s32 *, 4) == 0) {
            M2C_FIELD(arg1, s32 *, 4) = func_800A605C(1, 0, 0, 0);
        }
        if (M2C_FIELD(arg1, s32 *, 8) == 0) {
            M2C_FIELD(arg1, s32 *, 8) = func_800A605C(0, 1, 0, temp_s1);
        }
    }
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6B4C);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6DC4);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6F40);

u8 *func_800A6F8C(s32 arg0) {
    return func_800143DC(func_800A6DC4, 96, 16, arg0);
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A6FBC);

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A72B0);

void func_800A7450(void *arg0, s32 arg1) {
    if (arg1 == 0x322) {
        M2C_FIELD(arg0, s32 *, 0x50) = 2;
        M2C_FIELD(arg0, s32 *, 0x64) = 5;
        ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0xA40006);
    }
}

u8 *func_800A749C(s32 arg0) {
    return func_800143DC(func_800A72B0, 120, 0, arg0);
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A74CC);

void *func_800A75B0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A74CC, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A9208)();
    return temp_v0;
}

void func_800A760C(void) {
    *D_8004B370 = 0;
}

void func_800A7618(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4066, 1);
}

void func_800A7644(void) {
    *D_8004B370 = 0x2D;
}

INCLUDE_ASM("asm/ovl/WSTAG780/nonmatchings/WSTAG780", func_800A7654);
