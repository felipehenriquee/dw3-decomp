#include "WSTAG815.h"
#include "m2c.h"
#include "WSTAG815_auto.h"
#include "WSTAG815_data.h"

INCLUDE_ASM("asm/ovl/WSTAG815/nonmatchings/WSTAG815", func_800A5DE0);

void func_800A5F44(u8 *o) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        void (*fn28)(s32, s32);
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *t;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        func_8001FFA8(&g);
        g.fn24(0x280, 0);
        g.fn28(0, 0xF0);
        t = (u8 *)D_80044B38;
        g.fn2C((*(s32 (**)(s32))(t + 0x414))(0x775));
        g.fn24(0x280, 0x100);
        g.fn28(0, 0x1F0);
        g.fn2C((*(s32 (**)(s32))(t + 0x414))(0x898));
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        func_800A5DE0(o);
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_800A604C(void) {
    return func_80014504(func_800A5F44, 0x60, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG815/nonmatchings/WSTAG815", func_800A6078);

u8 *func_800A6184(s32 a) {
    u8 *o = func_800143DC(func_800A6078, 0x54, 0x1C, 0x17);

    *(s32 *)(o + 0x50) = a;
    ((void (*)(void))D_800A725C[0])();
    return o;
}

s16 func_800A61E4(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        if (once) {
            if (e[0] == 0xFF) {
                return 0xFF;
            }
        } else if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A61E4(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A6304(u8 *o, s32 tex, s32 i) {
    s32 t = tex;
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[8];
        void (*fn80)(s32, s32);
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    s16 *p = (s16 *)(o + (i * 4 + 0x64));
    s32 y = *(s32 *)(o + 0x58);
    s32 x = *(s32 *)(o + 0x54);
    s32 m;

    if (i == 1) {
        y -= 0x20;
        m = 4;
    } else {
        m = 6;
    }

    func_8001F648(&g);
    g.fn74(0x140, 0x100);
    g.fn80(t, m);
    g.fn88(p[1]);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80099D8C), p[0], x, y);
}

s32 func_800A63EC(s32 x, s32 y, s32 w, s32 h) {
    s16 r[4];
    u8 *o = (*(u8 *(**)(s32))&D_8004DF8C)(0x1002);

    (*(void (**)(u8 *, s16 *))(o + 0x128))(o, r);
    if (x + w < r[0]) {
        return 0;
    }
    if (r[0] + r[2] < x) {
        return 0;
    }
    if (y + h < r[1]) {
        return 0;
    }
    return r[1] + r[3] >= y;
}

INCLUDE_ASM("asm/ovl/WSTAG815/nonmatchings/WSTAG815", func_800A64B0);

u8 *func_800A6740(s32 x, s32 y, s32 p) {
    u8 *o = func_800143DC(func_800A64B0, 0x6C, 0, 0x17);

    *(s32 *)(o + 0x54) = x;
    *(s32 *)(o + 0x58) = y;
    *(s32 *)(o + 0x50) = p;
    return o;
}

extern struct opaque D_80048ABC;
void func_800A679C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4070, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A67E8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4071, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A6834(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4072, 1);
}

void func_800A6860(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40A9, 1);
}

extern struct opaque D_80048ABC;
void func_800A688C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4073, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG815/nonmatchings/WSTAG815", func_800A68D8);
