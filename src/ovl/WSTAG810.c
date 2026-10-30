#include "WSTAG810.h"
#include "m2c.h"
#include "WSTAG810_auto.h"
#include "WSTAG810_data.h"

s16 func_800A5DE0(u8 *o, AnimEnt4 *tbl, s32 once, s32 depth) {
    AnimEnt4 *e = tbl + *(s16 *)(o + 0x4);
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0x6) -= dt;
    }
    if (*(s16 *)(o + 0x6) <= 0) {
        *(s16 *)(o + 0x4) += 1;
        e++;
        *(s16 *)(o + 0x6) += e->dur;
        if (once != 0) {
            if (e->id == 0xFF) {
                return 0xFF;
            }
        } else if (e->id == 0xFF) {
            e = tbl;
            *(s16 *)(o + 0x4) = 0;
            *(s16 *)(o + 0x6) += e->dur;
        }
        func_800A5DE0(o, tbl, once, depth + 1);
    }
    return e->id;
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A5F00);

void func_800A6178(void *arg0, s32 arg1) {
    if (arg1 == 0x35B) {
        M2C_FIELD(arg0, s8 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, s16 *, 0x5A) = (s16) *D_800A719E;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A61C4(s32 arg0) {
    u8 *o = func_800143DC(func_800A5F00, 104, 0, arg0);

    *(s16 *)(o + 0x52) = 1;
    *(s8 *)(o + 0x51) = 0;
    return o;
}

u8 *func_800A6200(s32 arg0) {
    u8 *o = func_800143DC(func_800A5F00, 104, 0, arg0);

    *(s16 *)(o + 0x52) = 3;
    *(s8 *)(o + 0x51) = 0;
    return o;
}

u8 *func_800A623C(s32 arg0) {
    u8 *o = func_800143DC(func_800A5F00, 104, 0, arg0);

    *(s16 *)(o + 0x52) = 5;
    *(s8 *)(o + 0x51) = 0;
    return o;
}

Obj *func_800A6278(s16 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5F00, 0x68, 0);
    M2C_FIELD(temp_v0, s16 *, 0x52) = arg0;
    M2C_FIELD(temp_v0, s8 *, 0x51) = 1;
    return temp_v0;
}

void func_800A62B8(u8 *o, u8 **w) {
    s32 i;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(void))(o + 0x38))();
        for (i = 0; i < 0x3E; i++) {
            if (D_800A71F4[i].off == 0) {
                w[i] = func_800A69D0(D_800A71F4[i].x, D_800A71F4[i].y, D_800A71F4[i].p);
            }
        }
        if (((s32 (*)(s32, s32))D_80048ACC[0])(0x406E, 0) != 0) {
            w[0x3E] = func_800A61C4(0x34C);
        } else {
            w[0x3E] = (u8 *)func_800A6278(1);
        }
        if (((s32 (*)(s32, s32))D_80048ACC[0])(0x406F, 0) != 0) {
            w[0x3F] = func_800A6200(0x34B);
        } else {
            w[0x3F] = (u8 *)func_800A6278(3);
        }
        if (((s32 (*)(s32, s32))D_80048ACC[0])(0x406D, 0) != 0) {
            w[0x40] = func_800A623C(0x34A);
        } else {
            w[0x40] = (u8 *)func_800A6278(5);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6418(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A62B8, 0x54, 0x104);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7FD4)();
    return temp_v0;
}

s16 func_800A6474(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6474(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A6594(u8 *o, s32 tex, s32 i) {
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

s32 func_800A667C(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6740);

u8 *func_800A69D0(s32 x, s32 y, s32 p) {
    u8 *o = func_800143DC(func_800A6740, 0x6C, 0, 0x17);

    *(s32 *)(o + 0x54) = x;
    *(s32 *)(o + 0x58) = y;
    *(s32 *)(o + 0x50) = p;
    return o;
}

s32 func_800A6A2C(void) {
    u8 *d = D_80048D34;

    if (*(s32 *)(d + 0x26E4) != 0) {
        ((void (*)(s32, s32))D_8009B704[0])(7, 0x6ED0003);
        D_80099D94[0] = (s32)D_800A7AAC;
        *(s32 *)(d + 0x26E4) = 0;
    }
    return 0;
}

s32 func_800A6A90(void) {
    u8 *d = D_80048D34;

    if (*(s32 *)(d + 0x26E4) == 0) {
        ((void (*)(s32, s32))D_8009B704[0])(7, 0x6ED0004);
        D_80099D94[0] = (s32)D_800A7DAC;
        *(s32 *)(d + 0x26E4) = 0x20;
    }
    return 0;
}

extern struct opaque D_80048ABC;
void func_800A6AF8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x406D, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C3A, 1);
}

extern struct opaque D_80048ABC;
void func_800A6B44(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x406E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C3B, 1);
}

extern struct opaque D_80048ABC;
void func_800A6B90(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x406F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C3C, 1);
}

void func_800A6BDC(void) {
    *D_8004B370 = 0x29;
}

INCLUDE_ASM("asm/ovl/WSTAG810/nonmatchings/WSTAG810", func_800A6BEC);
