#include "WSTAG800.h"
#include "m2c.h"
#include "WSTAG800_auto.h"
#include "WSTAG800_data.h"

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A5DE0);

void func_800A5F00(u8 *o) {
    Rec18 *r;
    Rec18 *q;
    s32 i;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (q = D_80099D90; q->b[2] != 0; q++) {
            if (q->b[1] == 1) {
                *(s16 *)(o + 0x58) = 0;
                *(s16 *)(o + 0x5A) = D_800A7604[2];
                *(Rec18 **)(o + 0x54) = q;
            }
            if (q->b[1] == 2) {
                *(s16 *)(o + 0x60) = 0;
                *(s16 *)(o + 0x62) = D_800A763C[2];
                *(Rec18 **)(o + 0x5C) = q;
            }
        }
        *(s16 *)(o + 0x50) = 0;
        if (*(s16 *)(o + 0x52) == 0) {
            (*(void (**)(u8 *))(o + 0x38))(o);
        } else {
            *(s16 *)(o + 0x58) = 0;
            *(s16 *)(o + 0x5A) = D_800A7612[0];
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
        }
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            r = *(Rec18 **)(o + i * 8 + 0x54);
            switch (i) {
            case 0:
                r->b[0] = 1;
                r->b[4] = 0x46;
                r->b[9] = func_800A5DE0(o + 0x54, D_800A7604, 0, 0);
                break;
            case 1:
                r->b[0] = 0;
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            r = *(Rec18 **)(o + i * 8 + 0x54);
            switch (i) {
            case 0:
                r->b[0] = 1;
                if (*(s16 *)(o + 0x50) != 0) {
                    v = func_800A5DE0(o + 0x54, D_800A7610, 1, 0);
                    if (v == 0xFF) {
                        r->b[4] = 0x50;
                        *(s16 *)(o + 0x50) = 0;
                    } else {
                        r->b[4] = v;
                    }
                } else {
                    r->b[4] = 0x50;
                }
                r->b[9] = 0;
                break;
            case 1:
                r->b[0] = 1;
                r->b[4] = 0x51;
                r->b[9] = func_800A5DE0(o + 0x5C, D_800A763C, 0, 0);
                break;
            }
        }
        break;
    case 3:
        break;
    }
}

void func_800A6174(void *arg0, s32 arg1) {
    if (arg1 == 0x35B) {
        M2C_FIELD(arg0, s16 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, s16 *, 0x5A) = (s16) *D_800A7612;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A61C0(s32 arg0) {
    return func_800143DC(func_800A5F00, 100, 0, arg0);
}

void func_800A61F0(void) {
    M2C_FIELD(func_80014504(func_800A5F00, 0x64, 0), s16 *, 0x52) = 1;
}

s16 func_800A6224(u8 *o, AnimEnt4 *tbl, s32 once, s32 depth) {
    AnimEnt4 *e = tbl + *(s16 *)(o + 0x8);
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        *(s16 *)(o + 0xA) -= dt;
    }
    if (*(s16 *)(o + 0xA) <= 0) {
        *(s16 *)(o + 0x8) += 1;
        e++;
        *(s16 *)(o + 0xA) += e->dur;
        if (once != 0) {
            if (e->id == 0xFF) {
                return 0xFF;
            }
        } else if (e->id == 0xFF) {
            e = tbl;
            *(s16 *)(o + 0x8) = 0;
            *(s16 *)(o + 0xA) += e->dur;
        }
        func_800A6224(o, tbl, once, depth + 1);
    }
    return e->id;
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6344);

u8 *func_800A6510(s32 arg0) {
    return func_800143DC(func_800A6344, 108, 0, arg0);
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6540);

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6688);

Obj *func_800A6858(void) {
    return func_80014504(func_800A6688, 0x54, 4);
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6884);

void *func_800A69CC(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6884, 0x54, 0x20);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7E88)();
    return temp_v0;
}

s16 func_800A6A28(s16 *st, s16 *tbl, s32 once, s32 depth) {
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
        func_800A6A28(st, tbl, once, depth + 1);
    }
    return e[0];
}

void func_800A6B48(u8 *o, s32 tex, s32 i) {
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

s32 func_800A6C30(s32 x, s32 y, s32 w, s32 h) {
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

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A6CF4);

u8 *func_800A6F84(s32 x, s32 y, s32 p) {
    u8 *o = func_800143DC(func_800A6CF4, 0x6C, 0, 0x17);

    *(s32 *)(o + 0x54) = x;
    *(s32 *)(o + 0x58) = y;
    *(s32 *)(o + 0x50) = p;
    return o;
}

extern struct opaque D_80048ABC;
void func_800A6FE0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C0A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x4061, 1);
}

extern struct opaque D_80048ABC;
void func_800A702C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4044, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A7078(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4045, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x84CB, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG800/nonmatchings/WSTAG800", func_800A70C4);
