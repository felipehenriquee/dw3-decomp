#include "WSTAG820.h"
#include "m2c.h"
#include "WSTAG820_auto.h"
#include "WSTAG820_data.h"

s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[2] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[3] -= dt;
    }
    if (st[3] <= 0) {
        st[2]++;
        e += 2;
        st[3] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A5EB8);

u8 *func_800A5FB4(s32 link) {
    u8 *o = func_800143DC(func_800A5EB8, 0x58, 0, link);

    ((void (*)(s32))D_80055C48[0])(0x4001D);
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6008);

void *func_800A6160(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6008, 0x54, 0x14);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A76E8)();
    return temp_v0;
}

s16 func_800A61BC(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A61BC(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A62DC(u8 *o, s32 tex, s32 i) {
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

s32 func_800A63C4(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A6488);

u8 *func_800A6718(s32 x, s32 y, s32 p) {
    u8 *o = func_800143DC(func_800A6488, 0x6C, 0, 0x17);

    *(s32 *)(o + 0x54) = x;
    *(s32 *)(o + 0x58) = y;
    *(s32 *)(o + 0x50) = p;
    return o;
}

u8 *func_800A6774(s32 arg0) {
    u8 *o = func_800143DC(func_800A6488, 108, 0, arg0);

    *(s32 *)(o + 0x54) = 460;
    *(s32 *)(o + 0x58) = 436;
    *(s32 *)(o + 0x50) = 60;
    return o;
}

void func_800A67BC(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

extern struct opaque D_80048ABC;
void func_800A67F4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4074, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

void func_800A6840(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4075, 1);
}

void func_800A686C(void) {
    *D_8004B370 = 0x2B;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x7401, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG820/nonmatchings/WSTAG820", func_800A68A4);
