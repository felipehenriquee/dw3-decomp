#include "CARDGAME.h"
#include "m2c.h"
#include "CARDGAME_auto.h"
#include "CARDGAME_data.h"

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80083E34);

void func_80083F48(u8 *o, s32 unused, s32 v, s32 add) {
    u8 *e = o + (((s8 *)o)[0x575] - 1) * 8;

    if (e[0x584] == v) {
        *(u16 *)(o + 0x4E0) += add;
    }
}

void func_80083F84(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *base0;
    base0 = (u8 *)arg0 + (arg1 * 0xC8);
    if (arg2 >= M2C_FIELD(base0, s16 *, 0x5A6)) {
        M2C_FIELD(arg0, u16 *, 0x4E0) = (u16) (M2C_FIELD(arg0, u16 *, 0x4E0) + arg3);
    }
}

void func_80083FC8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *base0;
    base0 = (u8 *)arg0 + (arg1 * 0xC8);
    if (arg2 < M2C_FIELD(base0, s16 *, 0x5A6)) {
        M2C_FIELD(arg0, u16 *, 0x4E0) = (u16) (M2C_FIELD(arg0, u16 *, 0x4E0) + arg3);
    }
}

void func_8008400C(void *arg0, s32 arg1, s32 arg2) {
    u8 *base0;
    base0 = (u8 *)arg0 + (arg1 * 0xC8);
    if (M2C_FIELD(base0, s16 *, 0x5A4) > 0) {
        M2C_FIELD(arg0, u16 *, 0x4E0) = (u16) (M2C_FIELD(arg0, u16 *, 0x4E0) + arg2);
    }
}

void func_8008404C(void *arg0, s32 arg1, s32 arg2) {
    u8 *base0;
    base0 = (u8 *)arg0 + (arg1 * 0x72);
    if ((u8) M2C_FIELD(base0, u8 *, 0x72C) < 6U) {
        M2C_FIELD(arg0, u16 *, 0x4E0) = (u16) (M2C_FIELD(arg0, u16 *, 0x4E0) + arg2);
    }
}

s32 func_80084090(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x424) - ((s32 (*)()) D_8004DF9C)();
    M2C_FIELD(arg0, s32 *, 0x424) = temp_v1;
    return temp_v1 < 1;
}

void func_800840D0(void *arg0, s32 arg1, s32 arg2) {
    if (arg2 == 0) {
        M2C_FIELD(arg0, s32 *, 0x440) = (s32) M2C_FIELD(arg0, s16 *, 0x5A0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x440) = (s32) M2C_FIELD(arg0, u8 *, 0x41C);
}

void func_800840F0(u8 *o) {
    s32 i;
    u8 *k = o + ((s8)o[0x575] - 1) * 8;
    CgCard14 *c;
    for (i = 0; i < 12; i++) {
        o[0x46F + i] = 0;
        if (i < 6) {
            if (i >= o[0x72C]) continue;
            c = &((CgCard14 *)(o + 0x72E))[i];
        } else {
            if (i - 6 >= o[0x79E]) continue;
            c = &((CgCard14 *)(o + 0x7A0))[i - 6];
        }
        if (c->id == k[0x586]) {
            o[0x46F + i] = 1;
        }
    }
}

void func_80084188(u8 *o) {
    s32 best = 0;
    s32 bi = 6;
    s32 i, v;
    for (i = 0; i < 12; i++) {
        (o + i)[0x46F] = 0;
        if (i >= 6) {
            v = (*(s32 (**)(u8 *, s32, s32))(o + 0x820))(o, 1, 1 << (i - 6));
            if (best < v) {
                best = v;
                (o + bi)[0x46F] = 0;
                bi = i;
                *(s32 *)(o + 0x440) = i;
                (o + i)[0x46F] = 1;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008423C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80084320);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80085DE8);

s32 func_80085F38(u8 *o, s32 n) {
    struct {
        u8 pad0[0x2C];
        void (*fn2C)(s32);
        u8 pad30[0x20];
        s32 (*fn50)(void);
        u8 pad54[4];
    } t;
    s32 r, res;

    func_8001EBF8(&t);
    t.fn2C(((CgArr50 *)o)->a[n] + 1);
    res = 0;
    r = t.fn50();
    if (r != 0) {
        if (o[0x2F8] == 7 || (o[0x2F8] == 5 && r == 2)) {
            res = 1;
        }
    }
    return res;
}

s32 func_80085FD0(u8 *o, u8 *b, s32 n) {
    struct {
        u8 *p0;
        u8 pad4[0x28];
        void (*fn2C)(s32);
        u8 pad30[0x28];
    } t;
    s32 r = 0;
    u8 *p;

    if (o[0x2F8] == 6) {
        func_8001EBF8(&t);
        t.fn2C(((CgArr50 *)o)->a[n] + 1);
        p = t.p0;
        if (p[3] == 0x10) {
            r = !(b[p[0] - 1] < p[5]);
        }
    } else {
        r = func_80085F38(o, n);
    }
    return r;
}

s16 func_80086090(s32 a, s32 b, s32 c) {
    return D_800A5844[D_8005CCB0[0]][a][b][c];
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800860D4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80086330);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008642C);

void func_80086A18(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0xE32) = 0;
    M2C_FIELD(arg1, s32 *, 0xE34) = 0;
    M2C_FIELD(arg1, s32 *, 0xE4C) = 0;
    M2C_FIELD(arg1, s32 *, 0xE64) = 0;
    M2C_FIELD(arg1, s32 *, 0xE7C) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80086A30);

void func_80086D28(s32 a, s32 b, s32 mode) {
    s32 n = 0;

    switch (mode) {
    case 1:
        n = 6;
        break;
    case 2:
        n = 12;
        break;
    }
    func_80086A30(a, b, n);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80086D78);

void func_80086EB0(void *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 var_v1;
    void *var_v0;

    if (arg2 > 0) {
        var_v1 = 0x27;
        var_v0 = arg0 + 0x27;
        do {
            M2C_FIELD(var_v0, s8 *, 0x49E) = 0;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
    } else {
        M2C_FIELD(arg0, s8 *, 0x49E) = 0;
    }
    func_80086A18((s32) arg0, arg1);
    M2C_FIELD(arg0, s8 *, 0x423) = 1;
    M2C_FIELD(arg0, s8 *, 0x499) = arg3;
    M2C_FIELD(arg0, s32 *, 0x43C) = 0;
    M2C_FIELD(arg0, s32 *, 0x440) = -1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80086F24);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800870A4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008722C);

/* nenhum dos itens marcados? (so com o modo < 6) */
s32 func_80087308(u8 *o, s32 unused, u8 *p) {
    s32 r = 1;
    s32 i;
    s32 n;

    if (o[0x444] < 6) {
        n = *(s16 *)(p + 0xA);
        for (i = 0; i < n; i++) {
            if (*(s8 *)(o + i + 0x446) != 0) {
                r = 0;
                break;
            }
        }
    }
    return r;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008735C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80087458);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800875AC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800878B4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80087B80);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80087DC8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80087EDC);

void func_80088F0C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK (**)(void *), 0xECC)(arg1);
    M2C_FIELD(arg0, s32 *, 0x440) = 0;
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
    M2C_FIELD(arg1, M2C_UNK (**)(void *), 0xEC8)(arg1);
    M2C_FIELD(arg0, s8 *, 0x49D) = 1;
    M2C_FIELD(arg0, s8 *, 0x49C) = 1;
    M2C_FIELD(arg0, s8 *, 0x499) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80088F78);

void func_800894E4(void *arg0, void *arg1, s32 arg2) {
    void *temp_s0;

    temp_s0 = (arg2 * 2) + D_800A58C4;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, u8, M2C_UNK, M2C_UNK, s32), 0xEE4)(arg1, M2C_FIELD(temp_s0, u8 *, 1), 0, 0, 1);
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, u8, s32, s32), 0xEAC)(arg1, 5, 5, M2C_FIELD(temp_s0, u8 *, 0), 0, 0x42);
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80089580);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800896F0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008985C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80089974);

void func_80089EC8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x423) = 1;
}

/* largura: 8 por item do maior dos dois contadores (minimo 3) + 14 */
s32 func_80089ED4(u8 *o) {
    s32 n;

    if (o[0x72C] > o[0x79E]) {
        n = o[0x72C];
    } else {
        n = o[0x79E];
    }
    if (n < 3) {
        n = 3;
    }
    return n * 8 + 14;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80089F18);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008A068);

void func_8008AD48(u8 *o, s32 unused, s32 v) {
    *(s32 *)(o + 0x438) = v;
    *(s8 *)(o + 0x423) = 1;
}

s32 func_8008AD58(u8 *o) {
    return func_80089ED4(o);
}

s32 func_8008AD78(void) {
    return func_80089F18();
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008AD98);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008BAA4);

s32 func_8008BC6C(s32 arg0, s32 arg1, s32 arg2) {
    return func_8008BAA4(arg0, arg1, arg2, 0);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008BC8C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008BE04);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008C044);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008C5F0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008C6E0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008C8D8);

void func_8008C988(u8 *o) {
    struct {
        u8 *p0;
        u8 pad4[0x28];
        void (*fn2C)(s32);
        u8 pad30[0x28];
    } t;
    s32 bi = *(s16 *)(o + 0x5A0);
    s32 best;
    s32 i, v;

    func_8001EBF8(&t);
    best = 400;
    for (i = *(s16 *)(o + 0x5A0); i < 40; i++) {
        t.fn2C(((CgArr50 *)o)->a[*(s16 *)(o + i * 2 + 0x5B0)] + 1);
        v = *(s16 *)(t.p0 + 8);
        if (v < best) {
            best = v;
            bi = i;
        }
    }
    *(s32 *)(o + 0x440) = bi;
}

void func_8008CA4C(void *arg0, void *arg1, s32 arg2) {
    u8 *base0;
    s32 var_a0;
    void *var_v1;

    M2C_FIELD(arg1, M2C_UNK (**)(void *), 0xECC)(arg1);
    M2C_FIELD(arg1, M2C_UNK (**)(void *, s32), 0xEB8)(arg1, arg2);
    M2C_FIELD(arg0, s32 *, 0x440) = 0;
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
    M2C_FIELD(arg0, s32 *, 0x438) = arg2;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0xF14)(arg1, 0xF, 0xE500, 0x6100);
    base0 = (u8 *)arg0 + (M2C_FIELD(arg0, s8 *, 0x575) * 8);
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, s16), 0xF3C)(arg1, 0xF, M2C_FIELD(base0, s16 *, 0x580));
    M2C_FIELD(arg1, s16 *, 0x594) = 0;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0xF24)(arg1, 0xF, 8, 0x1000, 0x1000);
    M2C_FIELD(arg1, M2C_UNK (**)(void *), 0xEC8)(arg1);
    var_a0 = 0xE;
    var_v1 = arg0 + 0xE;
    M2C_FIELD(arg0, s8 *, 0x49D) = 2;
    M2C_FIELD(arg0, s8 *, 0x4AD) = 0;
    do {
        M2C_FIELD(var_v1, s8 *, 0x46F) = 0;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    M2C_FIELD(arg0, s8 *, 0x499) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008CB5C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008CE0C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008CFDC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008D274);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008D594);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008D854);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008D938);

void func_8008DA2C(u8 *o, u8 *x, s32 i, s32 j) {
    s32 jj = j * 7;
    u8 *e = o + (i * 57 + jj) * 2;
    s16 n;
    switch (e[0x738]) {
    case 0:
        ((CgArr614 *)o)->a[*(s16 *)(o + 0x5A2)] = *(s16 *)(e + 0x72E);
        n = *(s16 *)(o + 0x5A2) + 1;
        *(s16 *)(o + 0x5A2) = n;
        (*(void (**)(u8 *, s32, s32, s32))(x + 0xEA0))(x, 0, 7, n);
        break;
    case 1:
        ((CgArr6DC *)o)->a[*(s16 *)(o + 0x66A)] = *(s16 *)(e + 0x72E);
        n = *(s16 *)(o + 0x66A) + 1;
        *(s16 *)(o + 0x66A) = n;
        (*(void (**)(u8 *, s32, s32, s32))(x + 0xEA0))(x, 1, 7, n);
        break;
    }
}

s32 func_8008DAF4(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 var_a2;
    s32 var_s1;

    var_s1 = 0;
    var_a2 = arg3;
    if (arg2 != 0) {
        var_a2 = arg3 + 6;
    }
    if (func_8008D938(arg0, arg1, var_a2) != 0) {
        func_8008DA2C(arg0, arg1, arg2, arg3);
        var_s1 = 1;
    }
    return var_s1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008DB7C);

void func_8008DC70(u8 *o, u8 *x, s32 i, s32 j) {
    s32 jj = j * 7;
    u8 *e = o + (i * 57 + jj) * 2;
    s16 n;
    switch (e[0x738]) {
    case 0:
        ((CgArr600 *)o)->a[*(s16 *)(o + 0x5A6)] = *(s16 *)(e + 0x72E);
        n = *(s16 *)(o + 0x5A6) + 1;
        *(s16 *)(o + 0x5A6) = n;
        (*(void (**)(u8 *, s32, s32, s32))(x + 0xEA0))(x, 0, 6, n);
        break;
    case 1:
        ((CgArr6C8 *)o)->a[*(s16 *)(o + 0x66E)] = *(s16 *)(e + 0x72E);
        n = *(s16 *)(o + 0x66E) + 1;
        *(s16 *)(o + 0x66E) = n;
        (*(void (**)(u8 *, s32, s32, s32))(x + 0xEA0))(x, 1, 6, n);
        break;
    }
}

s32 func_8008DD38(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 var_a2;
    s32 var_s1;

    var_s1 = 0;
    var_a2 = arg3;
    if (arg2 != 0) {
        var_a2 = arg3 + 6;
    }
    if (func_8008DB7C(arg0, arg1, var_a2) != 0) {
        func_8008DC70(arg0, arg1, arg2, arg3);
        var_s1 = 1;
    }
    return var_s1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008DDC0);

s32 func_8008DEAC(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x424) + ((s32 (*)()) D_8004DF9C)();
    M2C_FIELD(arg0, s32 *, 0x424) = temp_v1;
    return arg2 < temp_v1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008DEF8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008E08C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008E398);

void func_8008E5B0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008E5BC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008EC44);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008EEC8);

void func_8008F0B4(CardGame *g, s32 unused, s32 k) {
    g->unk422 = 1;
    g->unk424 = 0;
    g->unk428 = g->slot[k].v2;
    g->unk42C = g->slot[k].v0;
    g->unk430 = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008F0F4);

void func_8008F2D8(u8 *o, s32 unused, s32 a, s32 b) {
    *(s32 *)(o + 0x430) = b;
    *(s32 *)(o + 0x434) = a;
    *(s8 *)(o + 0x423) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008F2EC);

void func_8008F530(s32 arg0, s32 arg1) {
    func_8008F2D8(arg0, arg1, -0x80, 0x10);
    M2C_FIELD(arg0, s32 *, 0x438) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008F560);

void func_8008F750(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x424) = 0;
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, s32), 0xEA8)(arg1, M2C_FIELD(arg0, s8 *, 0x575) - 2);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008F790);

s32 func_8008F948(u8 *o) {
    u8 *e = o + (((s8 *)o)[0x575] - 1) * 8;
    s32 v = *(s16 *)(e + 0x580);

    o[0x305]++;
    o[0x304] = v + 1;
    return 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008F978);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008FA9C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8008FF08);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80090058);

void func_8009076C(CardGame *g, s32 unused, s32 k) {
    g->unk424 = 0;
    g->unk434 = 0;
    g->unk428 = g->slot[k].v0;
    g->unk42C = g->slot[k].v1;
    g->unk422 = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800907AC);

void func_80090A6C(void *arg0, s32 arg1, s8 arg2) {
    s32 var_v1;
    void *var_v0;

    var_v1 = 0x27;
    var_v0 = arg0 + 0x27;
    do {
        M2C_FIELD(var_v0, s8 *, 0x46F) = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    M2C_FIELD(arg0, s8 *, 0x444) = arg2;
    M2C_FIELD(arg0, s8 *, 0x445) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80090A90);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80090BA0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80090CD8);

void func_800915C4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x428) = 0;
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800915D4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009170C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80091858);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800919FC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80091C6C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80091EB0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80092198);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80092438);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80092638);

void func_80092BA4(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s16 *, 0x5A6) = 0;
    M2C_FIELD(arg0, s16 *, 0x66E) = 0;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, s16), 0xEA0)(arg1, 0, 6, M2C_FIELD(arg0, s16 *, 0x5A6));
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, s16), 0xEA0)(arg1, 1, 6, M2C_FIELD(arg0, s16 *, 0x66E));
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, s16), 0xEA0)(arg1, 0, 5, M2C_FIELD(arg0, s16 *, 0x5A4));
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, s16), 0xEA0)(arg1, 1, 5, M2C_FIELD(arg0, s16 *, 0x66C));
    M2C_FIELD(arg0, s32 *, 0x440) = 0;
    M2C_FIELD(arg0, s8 *, 0x423) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80092C54);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80092E60);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80093624);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80093710);

void func_80093ADC(u8 *o, s32 unused, s32 k) {
    u8 *e = o + k * 0x72;
    s32 v;

    *(s32 *)(o + 0x424) = 0;
    v = e[0x72C];
    o[0x422] = 1;
    *(s32 *)(o + 0x428) = v - 1;
}

s32 func_80093B10(u8 *o, s32 b, s32 i) {
    s32 r = 0;
    switch (o[0x422]) {
    case 1:
        if (func_8008DAF4(o, b, i, *(s32 *)(o + 0x428)) == 0) {
            break;
        }
        *(s32 *)(o + 0x424) = 0;
        *(s32 *)(o + 0x428) -= 1;
        if (*(s32 *)(o + 0x428) < 0) {
            o[0x422] = 2;
            ((CgObj72C *)o)->e[i].b0 = 0;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80093BC4);

void func_80093C18(void *arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0xF14)(arg1, 0x11, 0x8300, 0x6100);
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, s32), 0xF3C)(arg1, 0x11, M2C_FIELD(arg0, u8 *, 0x304) - 1);
    M2C_FIELD(arg1, s16 *, 0x62C) = 0;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0xF24)(arg1, 0x11, 0xA, 0x1000, 0x1000);
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80093CAC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009403C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800942DC);

void func_80094828(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
    M2C_FIELD(arg0, s32 *, 0x424) = 0;
    M2C_FIELD(arg0, s32 *, 0x428) = 0;
    M2C_FIELD(arg0, s32 *, 0x42C) = 0;
    M2C_FIELD(arg0, s32 *, 0x430) = 0;
    M2C_FIELD(arg0, s32 *, 0x434) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80094848);

void func_80094B78(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
    M2C_FIELD(arg0, s32 *, 0x424) = 0;
    M2C_FIELD(arg0, s32 *, 0x428) = 0;
    M2C_FIELD(arg0, s32 *, 0x42C) = 0;
    M2C_FIELD(arg0, s32 *, 0x430) = 0;
    M2C_FIELD(arg0, s32 *, 0x434) = 0;
    M2C_FIELD(arg0, s32 *, 0x438) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80094B9C);

void func_80094FDC(void *arg0, void *arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0x424) = 0;
    M2C_FIELD(arg1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0xEE4)(arg1, arg2, 0, 0, 1);
    M2C_FIELD(arg0, s8 *, 0x422) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095030);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009518C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095208);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095274);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800952F4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009535C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800954F8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095BFC);

Obj *func_80095E2C(void) {
    return func_80014504(func_80095BFC, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095E58);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80095FB4);

void func_80096144(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
    M2C_FIELD(arg0, s16 *, 0x56) = arg2;
}

void func_80096150(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x63) = 1;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
}

void func_80096160(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 5;
    M2C_FIELD(arg0, s16 *, 0x64) = 5;
    M2C_FIELD(arg0, s8 *, 0x62) = 2;
    M2C_FIELD(arg0, s16 *, 0x5A) = 0x1000;
}

Obj *func_80096180(s16 arg0, s16 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80095FB4, 0x74, 0);
    M2C_FIELD(temp_v0, void (**)(void *, s16, s16), 0x68) = func_80096144;
    M2C_FIELD(temp_v0, void (**)(void *), 0x6C) = func_80096160;
    M2C_FIELD(temp_v0, void (**)(void *), 0x70) = func_80096150;
    M2C_FIELD(temp_v0, s16 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s16 *, 0x56) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x63) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800961F0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096418);

void func_800967F8(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x67) = 1;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
}

void func_80096808(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6A) = 6;
    M2C_FIELD(arg0, s16 *, 0x68) = 6;
    M2C_FIELD(arg0, s8 *, 0x66) = 2;
    M2C_FIELD(arg0, s16 *, 0x5C) = 0x1000;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096828);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096950);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096A94);

void func_80096C20(s32 a, s32 b, s32 i, s16 *p) {
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

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x340, 0);
    g.fn94(D_800A5978[i].x + 4, D_800A5978[i].y + 0x17);
    g.fn8C(0x1000, p[1], 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x25D0003), p[5] + 6, D_800A5978[i].x, D_800A5978[i].y);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096CF0);

void func_80096E24(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = 0xDC0;
    do {
        func_80096CF0(arg0, arg1, var_s0, arg0 + var_s1);
        var_s0 += 1;
        var_s1 += 0xC;
    } while (var_s0 < 3);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80096E8C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80097238);

void func_80097310(s32 arg0, void *arg1, void *arg2, M2C_UNK arg3, s32 arg4) {
    if (M2C_FIELD(arg1, s32 *, 0x10) != 0) {
        M2C_FIELD(arg2, M2C_UNK (**)(void *, s16, s16), 0x134)(arg2, (s16) (M2C_FIELD(arg1, u16 *, 0) + D_800A59A8[arg4]), (s16) (M2C_FIELD(arg1, u16 *, 2) + 4));
        M2C_FIELD(arg2, M2C_UNK (**)(void *, s32, s32), 0x114)(arg2, ((s32 (*)(M2C_UNK)) *D_80044F4C)(arg3), M2C_FIELD(arg1, s32 *, 0x10));
        return;
    }
    M2C_FIELD(arg2, M2C_UNK (**)(void *, M2C_UNK), 0x144)(arg2, 0);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800973E4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80097508);

void func_800978F0(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = 0xE0C;
    do {
        func_80097508(arg0, arg1, arg0 + var_s1, var_s0);
        var_s0 += 1;
        var_s1 += 0x18;
    } while (var_s0 < 6);
}

void func_80097958(s32 a, s32 b, s32 c, s32 x, s32 y) {
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

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn94(0, 0x78);
    g.fn8C((s16)c, 0x1000, 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x25D0002), 0x1A, x, y);
}

void func_80097A24(s32 a, s32 b, s32 x, s32 y) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[4];
        void (*fn8C)(s32, s32, s32);
        u8 pad90[0xA0 - 0x90];
    } g;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn8C(0x1000, 0x1000, 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x25D0002), 0x18, x, y);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80097ACC);

void func_8009848C(s32 a, s32 b, s32 c, s32 x, s32 y) {
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

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x340, 0);
    g.fn94(0, 0x86);
    g.fn8C((s16)c, 0x1000, 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x25D0003), 1, x, y);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80098558);

s32 func_80098864(s32 arg0, s32 arg1) {
    s32 var_a0;

    if (arg0 < 7) {
        var_a0 = 0x2900;
    } else {
        var_a0 = 0xF600 / arg0;
    }
    return var_a0 * arg1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80098898);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80099440);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800999A0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80099BE4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80099D18);

void func_80099DE8(s16 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    s32 k;

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x340, 0);
    o[6]++;
    switch (o[6] >> 2) {
    default:
        o[6] = 0;
    case 0:
        k = 0;
        break;
    case 1:
        k = 3;
        break;
    case 2:
        k = 1;
        break;
    }
    g.fn88(k);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x25D0003), 8, o[0], o[1]);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80099ED4);

void func_80099F60(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_s2;

    func_80099BE4(arg0, arg1, 0, arg0 + 0xA8);
    func_80099BE4(arg0, arg1, 1, arg0 + 0xFC);
    temp_s2 = arg0 + 0x60;
    func_80099440(temp_s2, arg1, 0);
    temp_s0 = arg0 + 0xB4;
    func_80099440(temp_s0, arg1, 1);
    func_80098898(temp_s2, arg1, 0);
    func_80098898(temp_s0, arg1, 1);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_80099FFC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A1A0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A454);

s32 func_8009A540(u8 *o, u8 *e) {
    s32 r;

    r = 0;
    *(s32 *)(e + 0x28) += ((s32 (*)(void))D_8004DF9C)();
    if (*(s32 *)(e + 0x28) >= 10) {
        r = 1;
        e[0x42] = 0xB;
        *(s32 *)(e + 0x2C) = 0;
        *(s32 *)(e + 0x28) = 0;
        *(s16 *)(e + 0x26) = 0;
        e[0x47] = 0;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A5B0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A62C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A75C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A82C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009A998);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009ACAC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009AF28);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009B028);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009B168);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009B678);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009B76C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009B890);

void func_8009BA3C(s32 arg0, void *arg1) {
    if ((M2C_FIELD(arg1, s16 *, 0x18) != 0) && (M2C_FIELD(arg1, s16 *, 0x1A) != 0)) {
        func_8009ACAC();
        func_8009B028(arg0, arg1);
        func_8009AF28(arg0, arg1);
        func_8009A998(arg0, arg1);
        func_8009B678(arg0, arg1);
        func_8009B168(arg0, arg1);
    }
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009BAC8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009BBA8);

void func_8009BE40(s32 arg0, s32 arg1, s16 arg2) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0xC);
    M2C_FIELD(temp_a0, s16 *, 0xDC0) = 0x1000;
    M2C_FIELD(temp_a0, s16 *, 0xDC8) = 1;
    M2C_FIELD(temp_a0, s16 *, 0xDC2) = 0;
    M2C_FIELD(temp_a0, s16 *, 0xDCA) = arg2;
    M2C_FIELD(temp_a0, s16 *, 0xDC6) = 0xA;
    M2C_FIELD(temp_a0, s16 *, 0xDC4) = 0xA;
}

void func_8009BE78(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0xC);
    M2C_FIELD(temp_a0, s16 *, 0xDC0) = 0x1000;
    M2C_FIELD(temp_a0, s16 *, 0xDC2) = 0x1000;
    M2C_FIELD(temp_a0, s16 *, 0xDC8) = 3;
    M2C_FIELD(temp_a0, s16 *, 0xDC6) = 5;
    M2C_FIELD(temp_a0, s16 *, 0xDC4) = 5;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009BEAC);

void func_8009BF5C(s32 arg0, s32 arg1) {
    void *temp_s0;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x4001A);
    temp_s0 = arg0 + (arg1 * 0x18);
    M2C_FIELD(temp_s0, s16 *, 0xE10) = 0x1000;
    M2C_FIELD(temp_s0, s16 *, 0xE12) = 0x1000;
    M2C_FIELD(temp_s0, s8 *, 0xE23) = 3;
    M2C_FIELD(temp_s0, s16 *, 0xE16) = 6;
    M2C_FIELD(temp_s0, s16 *, 0xE14) = 6;
}

s32 func_8009BFCC(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x12);
    M2C_FIELD(temp_a0, s8 *, 0xCF8) = 1;
    M2C_FIELD(temp_a0, s16 *, 0xCE8) = arg2;
    M2C_FIELD(temp_a0, s16 *, 0xCEA) = arg3;
    M2C_FIELD(temp_a0, s16 *, 0xCF2) = 0;
    M2C_FIELD(temp_a0, s16 *, 0xCF0) = 0;
    M2C_FIELD(temp_a0, s16 *, 0xCEE) = 0;
    M2C_FIELD(temp_a0, s16 *, 0xCEC) = 0;
    M2C_FIELD(temp_a0, s8 *, 0xCF7) = 0;
    M2C_FIELD(temp_a0, s8 *, 0xCF6) = 0;
    M2C_FIELD(temp_a0, s16 *, 0xCF4) = 0;
    return 0;
}

s32 func_8009C010(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s32 arg4) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x12);
    M2C_FIELD(temp_a0, s8 *, 0xCF8) = 2;
    M2C_FIELD(temp_a0, s16 *, 0xCF0) = arg3;
    M2C_FIELD(temp_a0, s8 *, 0xCF7) = arg2;
    M2C_FIELD(temp_a0, s8 *, 0xCF6) = arg2;
    M2C_FIELD(temp_a0, s16 *, 0xCF2) = (s16) arg4;
    M2C_FIELD(temp_a0, u16 *, 0xCEC) = (u16) M2C_FIELD(temp_a0, u16 *, 0xCE8);
    M2C_FIELD(temp_a0, u16 *, 0xCEE) = (u16) M2C_FIELD(temp_a0, u16 *, 0xCEA);
    return 0;
}

void func_8009C054(void *arg0, s32 arg1, s8 arg2, s16 arg3, s32 arg4) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x40019);
    M2C_FIELD(arg0, s16 *, 0xDF2) = 0xC;
    M2C_FIELD(arg0, s16 *, 0xDF0) = 0xC;
    M2C_FIELD(arg0, s16 *, 0xDF4) = arg3;
    M2C_FIELD(arg0, s32 *, 0xDE8) = arg1;
    M2C_FIELD(arg0, s8 *, 0xDFB) = arg2;
    M2C_FIELD(arg0, s32 *, 0xDE4) = arg4;
    M2C_FIELD(arg0, s8 *, 0xDFA) = 1;
}

void func_8009C0DC(void *arg0) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x4001A);
    M2C_FIELD(arg0, s16 *, 0xDF2) = 6;
    M2C_FIELD(arg0, s16 *, 0xDF0) = 6;
    M2C_FIELD(arg0, s8 *, 0xDFA) = 5;
}

void func_8009C124(void *arg0) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x8004503C);
    M2C_FIELD(arg0, s16 *, 0xDF2) = 0xA;
    M2C_FIELD(arg0, s16 *, 0xDF0) = 0xA;
    M2C_FIELD(arg0, s8 *, 0xDFA) = 4;
}

void func_8009C16C(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xDF4) = arg1;
}

void func_8009C174(void *arg0, s16 arg1) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x40019);
    M2C_FIELD(arg0, s16 *, 0xE02) = 0xC;
    M2C_FIELD(arg0, s16 *, 0xE00) = 0xC;
    M2C_FIELD(arg0, s16 *, 0xE04) = arg1;
    M2C_FIELD(arg0, s16 *, 0xE0A) = 1;
}

void func_8009C1CC(void *arg0) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x4001A);
    M2C_FIELD(arg0, s16 *, 0xE02) = 6;
    M2C_FIELD(arg0, s16 *, 0xE00) = 6;
    M2C_FIELD(arg0, s16 *, 0xE0A) = 5;
}

void func_8009C214(void *arg0) {
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x8004503C);
    M2C_FIELD(arg0, s16 *, 0xE02) = 0xA;
    M2C_FIELD(arg0, s16 *, 0xE00) = 0xA;
    M2C_FIELD(arg0, s16 *, 0xE0A) = 4;
}

void func_8009C25C(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xE04) = arg1;
}

void func_8009C264(u8 *o) {
    *(s16 *)(o + 0x60) = *(s16 *)(o + 0x62) = *(s16 *)(o + 0x64) = 0;
    *(s16 *)(o + 0x6C) = 0;
    *(s16 *)(o + 0x6E) = 0xF1;
    *(s16 *)(o + 0x80) = 0x147;
    *(s16 *)(o + 0x82) = 0x8F;
    *(s16 *)(o + 0x9C) = 0x140;
    *(s16 *)(o + 0x9E) = 0xBD;
    *(s16 *)(o + 0xB4) = *(s16 *)(o + 0xB6) = *(s16 *)(o + 0xB8) = 0;
    *(s16 *)(o + 0xC0) = 0;
    *(s16 *)(o + 0xC2) = -0x64;
    *(s16 *)(o + 0xD4) = 0x147;
    *(s16 *)(o + 0xD6) = 0x50;
    *(s16 *)(o + 0xF0) = 0x140;
    *(s16 *)(o + 0xF2) = 0x26;
}

void func_8009C2D0(u8 *o) {
    *(s16 *)(o + 0x64) = 1;
    *(s16 *)(o + 0x66) = 2;
    *(s16 *)(o + 0x60) = *(s16 *)(o + 0x62) = 0x14;
    *(s16 *)(o + 0x6C) = 0;
    *(s16 *)(o + 0x6E) = 0xF1;
    *(s16 *)(o + 0x80) = 0x147;
    *(s16 *)(o + 0x82) = 0x8F;
    *(s16 *)(o + 0x9C) = 0x140;
    *(s16 *)(o + 0x9E) = 0xBD;
    *(s16 *)(o + 0xB8) = 1;
    *(s16 *)(o + 0xB4) = *(s16 *)(o + 0xB6) = 0x14;
    *(s16 *)(o + 0xC0) = 0;
    *(s16 *)(o + 0xC2) = -0x64;
    *(s16 *)(o + 0xD4) = 0xF9;
    *(s16 *)(o + 0xD6) = 0x50;
    *(s16 *)(o + 0xF0) = 0x140;
    *(s16 *)(o + 0xF2) = 0x26;
}

void func_8009C350(u8 *o) {
    *(s16 *)(o + 0x64) = 3;
    *(s16 *)(o + 0x60) = *(s16 *)(o + 0x62) = 10;
    *(s16 *)(o + 0x6C) = 0;
    *(s16 *)(o + 0x6E) = 0x8D;
    *(s16 *)(o + 0x80) = 0x120;
    *(s16 *)(o + 0x82) = 0x8F;
    *(s16 *)(o + 0x9C) = 0x113;
    *(s16 *)(o + 0x9E) = 0xBD;
    *(s16 *)(o + 0xB8) = 3;
    *(s16 *)(o + 0xB4) = *(s16 *)(o + 0xB6) = 10;
    *(s16 *)(o + 0xC0) = 0;
    *(s16 *)(o + 0xC2) = 0;
    *(s16 *)(o + 0xD4) = 0x120;
    *(s16 *)(o + 0xD6) = 0x50;
    *(s16 *)(o + 0xF0) = 0x113;
    *(s16 *)(o + 0xF2) = 0x26;
}

void func_8009C3C0(void *arg0, s32 arg1) {
    u8 *base0;
    void *temp_a2;

    temp_a2 = arg0 + (arg1 * 0x54);
    M2C_FIELD(temp_a2, s16 *, 0x64) = 4;
    base0 = (u8 *)arg0 + ((arg1 ^ 1) * 0x54);
    M2C_FIELD(base0, s16 *, 0x64) = 0;
    M2C_FIELD(temp_a2, s16 *, 0x66) = 2;
    M2C_FIELD(temp_a2, s16 *, 0x62) = 0xA;
    M2C_FIELD(temp_a2, s16 *, 0x60) = 0xA;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x6C) = 0;
        M2C_FIELD(arg0, s16 *, 0x6E) = 0xF1;
        return;
    }
    M2C_FIELD(temp_a2, s16 *, 0x6C) = 0;
    M2C_FIELD(temp_a2, s16 *, 0x6E) = -0x64;
}

void func_8009C438(void *arg0, s32 arg1) {
    u8 *base0;
    void *temp_a2;

    temp_a2 = arg0 + (arg1 * 0x54);
    M2C_FIELD(temp_a2, s16 *, 0x64) = 5;
    base0 = (u8 *)arg0 + ((arg1 ^ 1) * 0x54);
    M2C_FIELD(base0, s16 *, 0x64) = 0;
    M2C_FIELD(temp_a2, s16 *, 0x62) = 5;
    M2C_FIELD(temp_a2, s16 *, 0x60) = 5;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x6C) = 0;
        M2C_FIELD(arg0, s16 *, 0x6E) = 0x8D;
        return;
    }
    M2C_FIELD(temp_a2, s16 *, 0x6C) = 0;
    M2C_FIELD(temp_a2, s16 *, 0x6E) = 0;
}

void func_8009C4A4(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x54);
    M2C_FIELD(temp_a0, s8 *, 0xB0) = 1;
    M2C_FIELD(temp_a0, s16 *, 0xAE) = 0xC;
    M2C_FIELD(temp_a0, s16 *, 0xAC) = 0xC;
    M2C_FIELD(temp_a0, s16 *, 0xA8) = 0;
}

void func_8009C4D8(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x54);
    M2C_FIELD(temp_a0, s8 *, 0xB0) = 3;
    M2C_FIELD(temp_a0, s16 *, 0xAE) = 6;
    M2C_FIELD(temp_a0, s16 *, 0xAC) = 6;
    M2C_FIELD(temp_a0, s16 *, 0xA8) = 0x1000;
}

s32 func_8009C510(u8 *o, s32 i, s32 a, s32 b) {
    ((void (*)(u8 *, s32))D_8004B600[0])(o + (i * 76 + 0x108), 0x4C);
    o += i * 76;
    o[0x14A] = o[0x14D] = 1;
    *(s32 *)(o + 0x108) = a;
    *(s32 *)(o + 0x10C) = b;
    *(s16 *)(o + 0x122) = *(s16 *)(o + 0x126) = *(s16 *)(o + 0x120) = *(s16 *)(o + 0x124) = 0x1000;
    *(s16 *)(o + 0x140) = *(s16 *)(o + 0x142) = 0;
    *(s16 *)(o + 0x12C) = i;
    o[0x14B] = 0;
    o[0x14C] = 0;
    o[0x14F] = 0;
    o[0x151] = 0;
    *(s16 *)(o + 0x12E) = 0;
    return 0;
}

s32 func_8009C5D8(s32 arg0, s32 arg1) {
    void *temp_s0;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x8004613E);
    temp_s0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_s0, s8 *, 0x14A) = 4;
    M2C_FIELD(temp_s0, s32 *, 0x130) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x134) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x120) = 0x1000;
    M2C_FIELD(temp_s0, s16 *, 0x122) = 0x1000;
    M2C_FIELD(temp_s0, s16 *, 0x12E) = 0;
    return 0;
}

s32 func_8009C654(s32 arg0, s32 arg1) {
    void *temp_s0;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x9C0003);
    temp_s0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_s0, s8 *, 0x14A) = 6;
    M2C_FIELD(temp_s0, s16 *, 0x120) = 0x1000;
    M2C_FIELD(temp_s0, s16 *, 0x122) = 0x1000;
    M2C_FIELD(temp_s0, s32 *, 0x130) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x134) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x14F) = 1;
    M2C_FIELD(temp_s0, s16 *, 0x12E) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x118) = (s32) M2C_FIELD(temp_s0, s32 *, 0x108);
    M2C_FIELD(temp_s0, s32 *, 0x11C) = (s32) M2C_FIELD(temp_s0, s32 *, 0x10C);
    return 0;
}

s32 func_8009C6E8(s32 arg0, s32 arg1) {
    void *temp_s0;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x9C0003);
    temp_s0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_s0, s8 *, 0x14A) = 7;
    M2C_FIELD(temp_s0, s32 *, 0x130) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x134) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x14F) = 1;
    M2C_FIELD(temp_s0, s16 *, 0x12E) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x118) = (s32) M2C_FIELD(temp_s0, s32 *, 0x108);
    M2C_FIELD(temp_s0, s32 *, 0x11C) = (s32) M2C_FIELD(temp_s0, s32 *, 0x10C);
    return 0;
}

s32 func_8009C770(s32 arg0, s32 arg1) {
    void *temp_s0;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x40014);
    temp_s0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_s0, s8 *, 0x14A) = 8;
    M2C_FIELD(temp_s0, s32 *, 0x130) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x134) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x14F) = 2;
    M2C_FIELD(temp_s0, s16 *, 0x12E) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x118) = (s32) M2C_FIELD(temp_s0, s32 *, 0x108);
    M2C_FIELD(temp_s0, s32 *, 0x11C) = (s32) M2C_FIELD(temp_s0, s32 *, 0x10C);
    return 0;
}

s32 func_8009C7F8(CgObjE *o, s32 i, s32 m) {
    switch (m) {
    case 0:
    default:
        o->e[i].b14A = 9;
        o->e[i].b14F = 3;
        break;
    case 1:
        o->e[i].b14F = 4;
        o->e[i].b14A = 10;
        break;
    }
    o->e[i].a118 = o->e[i].a108;
    o->e[i].b11C = o->e[i].b10C;
    o->e[i].w130 = 0;
    o->e[i].w134 = 0;
    o->e[i].h12E = 0;
    return 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009C898);

s32 func_8009C904(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_8009C898(arg0, arg1, 0, arg2, /* extra? */ arg3, /* extra? */ 1);
}

s32 func_8009C938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_8009C898(arg0, arg1, arg2, arg3, /* extra? */ arg4, /* extra? */ 0);
}

void func_8009C960(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_a0, s32 *, 0x110) = arg3;
    M2C_FIELD(temp_a0, s32 *, 0x134) = arg2;
    M2C_FIELD(temp_a0, s32 *, 0x130) = arg2;
    M2C_FIELD(temp_a0, s32 *, 0x114) = arg4;
    M2C_FIELD(temp_a0, s32 *, 0x118) = (s32) M2C_FIELD(temp_a0, s32 *, 0x108);
    M2C_FIELD(temp_a0, s32 *, 0x11C) = (s32) M2C_FIELD(temp_a0, s32 *, 0x10C);
}

void func_8009C9A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base0;
    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x8004603C);
    base0 = (u8 *)arg0 + (arg1 * 0x4C);
    M2C_FIELD(base0, s8 *, 0x14A) = 2;
    func_8009C960(arg0, arg1, arg2, arg3, arg4);
}

void func_8009CA3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base0;
    base0 = (u8 *)arg0 + (arg1 * 0x4C);
    M2C_FIELD(base0, s8 *, 0x14A) = 3;
    func_8009C960(arg0, arg1, arg2, arg3, arg4);
}

s32 func_8009CA80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_a0, s8 *, 0x14A) = 5;
    M2C_FIELD(temp_a0, s32 *, 0x138) = 0x10;
    M2C_FIELD(temp_a0, s16 *, 0x120) = 0x1000;
    M2C_FIELD(temp_a0, s16 *, 0x122) = 0x1000;
    M2C_FIELD(temp_a0, s32 *, 0x110) = arg3;
    M2C_FIELD(temp_a0, s32 *, 0x134) = arg2;
    M2C_FIELD(temp_a0, s32 *, 0x130) = arg2;
    M2C_FIELD(temp_a0, s32 *, 0x114) = arg4;
    M2C_FIELD(temp_a0, s32 *, 0x118) = (s32) M2C_FIELD(temp_a0, s32 *, 0x108);
    M2C_FIELD(temp_a0, s32 *, 0x11C) = (s32) M2C_FIELD(temp_a0, s32 *, 0x10C);
    return 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009CAE0);

void func_8009CC4C(void *arg0, s32 arg1) {
    if (arg1 & 1) {
        M2C_FIELD(arg0, s8 *, 0x90) = 1;
    }
    if (arg1 & 4) {
        M2C_FIELD(arg0, s8 *, 0x91) = 1;
    }
    if (arg1 & 0x10) {
        M2C_FIELD(arg0, s8 *, 0x92) = 1;
    }
    if (arg1 & 0x40) {
        M2C_FIELD(arg0, s8 *, 0x93) = 1;
    }
    if (arg1 & 0x100) {
        M2C_FIELD(arg0, s8 *, 0x94) = 1;
    }
    if (arg1 & 0x400) {
        M2C_FIELD(arg0, s8 *, 0x95) = 1;
    }
    if (arg1 & 0x1000) {
        M2C_FIELD(arg0, s8 *, 0x96) = 1;
    }
    if (arg1 & 0x4000) {
        M2C_FIELD(arg0, s8 *, 0x97) = 1;
    }
    if (arg1 & 0x10000) {
        M2C_FIELD(arg0, s8 *, 0x98) = 1;
    }
    if (arg1 & 0x40000) {
        M2C_FIELD(arg0, s8 *, 0x99) = 1;
    }
    if (arg1 & 2) {
        M2C_FIELD(arg0, s8 *, 0xE4) = 1;
    }
    if (arg1 & 8) {
        M2C_FIELD(arg0, s8 *, 0xE5) = 1;
    }
    if (arg1 & 0x20) {
        M2C_FIELD(arg0, s8 *, 0xE6) = 1;
    }
    if (arg1 & 0x80) {
        M2C_FIELD(arg0, s8 *, 0xE7) = 1;
    }
    if (arg1 & 0x200) {
        M2C_FIELD(arg0, s8 *, 0xE8) = 1;
    }
    if (arg1 & 0x800) {
        M2C_FIELD(arg0, s8 *, 0xE9) = 1;
    }
    if (arg1 & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0xEA) = 1;
    }
    if (arg1 & 0x8000) {
        M2C_FIELD(arg0, s8 *, 0xEB) = 1;
    }
    if (arg1 & 0x20000) {
        M2C_FIELD(arg0, s8 *, 0xEC) = 1;
    }
    if (arg1 & 0x80000) {
        M2C_FIELD(arg0, s8 *, 0xED) = 1;
    }
}

void func_8009CDA4(u8 *o) {
    u8 *heap = (u8 *)&D_8004B5DC;

    (*(void (**)(u8 *, s32))(heap + 0x24))(o + 0x90, 10);
    (*(void (**)(u8 *, s32))(heap + 0x24))(o + 0xE4, 10);
}

s32 func_8009CDFC(s32 arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_a0, s8 *, 0x14A) = 0;
    M2C_FIELD(temp_a0, s8 *, 0x14D) = 0;
    M2C_FIELD(temp_a0, s16 *, 0x142) = 0;
    return 0;
}

s32 func_8009CE28(s32 arg0, s32 arg1) {
    void *temp_s1;

    ((M2C_UNK (*)(M2C_UNK)) D_80055C48)(0x4001C);
    temp_s1 = arg0 + (arg1 * 0x4C);
    M2C_FIELD(temp_s1, s8 *, 0x14A) = 0xB;
    M2C_FIELD(temp_s1, s32 *, 0x134) = 0;
    M2C_FIELD(temp_s1, s32 *, 0x130) = 0;
    return 0;
}

void func_8009CE94(s32 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 temp_a3;
    s32 var_s0;

    var_s0 = 0;
    if (arg2 > 0) {
        do {
            temp_a3 = arg3 + func_80098864(arg2, var_s0);
            if (arg1 == 0) {
                func_8009C510(arg0, var_s0, temp_a3, arg4);
                var_s0 += 1;
            } else {
                func_8009C9A0(arg0, var_s0, arg1, temp_a3, arg4);
                var_s0 += 1;
            }
        } while (var_s0 < arg2);
    }
}

u8 func_8009CF60(u8 *o, s32 i) {
    struct {
        u8 *p0;
        u8 pad4[0x2C - 4];
        void (*fn2C)(s32);
        u8 pad30[0x58 - 0x30];
    } g;

    func_8001EBF8(&g);
    g.fn2C((*(s16 **)(o + 0x50))[i] + 1);
    return *g.p0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009CFBC);

void func_8009D0B0(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_a1;
    s32 var_a1;

    var_a1 = arg2;
    if (arg2 < 0) {
        var_a1 = arg2 + 7;
    }
    temp_a1 = var_a1 >> 3;
    M2C_FIELD(arg0, M2C_UNK (**)(s32, s32), 0x24)((temp_a1 * 0x10) + 0x140, ((arg2 - (temp_a1 * 8)) << 5) + 0x100);
    M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, s32), 0x28)(0x300, arg2 + 0x100);
    M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK), 0x20)(arg1);
}

s16 func_8009D140(s32 arg0) {
    return (s16) D_800A5B14[arg0];
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009D15C);

Obj *func_8009D310(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8009BBA8, 0xF48, 0x38);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xEA0) = func_8009CAE0;
    M2C_FIELD(temp_v0, void (**)(s32, s32, s16), 0xEA4) = func_8009BE40;
    M2C_FIELD(temp_v0, void (**)(s32, s32), 0xEA8) = func_8009BE78;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xEAC) = func_8009BEAC;
    M2C_FIELD(temp_v0, void (**)(s32, s32), 0xEB0) = func_8009BF5C;
    M2C_FIELD(temp_v0, void (**)(void *, s32), 0xEB8) = func_8009CC4C;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xEB4) = func_8009CDA4;
    M2C_FIELD(temp_v0, void (**)(void *, s32, s8, s16, s32), 0xEE4) = func_8009C054;
    M2C_FIELD(temp_v0, void (**)(void *), 0xEE8) = func_8009C0DC;
    M2C_FIELD(temp_v0, void (**)(void *, s16), 0xEF0) = func_8009C16C;
    M2C_FIELD(temp_v0, void (**)(void *), 0xEEC) = func_8009C124;
    M2C_FIELD(temp_v0, void (**)(void *, s16), 0xEF4) = func_8009C174;
    M2C_FIELD(temp_v0, void (**)(void *), 0xEF8) = func_8009C1CC;
    M2C_FIELD(temp_v0, void (**)(void *), 0xEFC) = func_8009C214;
    M2C_FIELD(temp_v0, void (**)(void *, s16), 0xF00) = func_8009C25C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xED8) = func_80098864;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s16, s16), 0xEDC) = func_8009BFCC;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s8, s16, s32), 0xEE0) = func_8009C010;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xF08) = func_8009C9A0;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF0C) = func_8009CA3C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32, s32), 0xF10) = func_8009CA80;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF2C) = func_8009C654;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF30) = func_8009C6E8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF34) = func_8009C770;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xF38) = func_8009C7F8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF28) = func_8009C5D8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xF14) = func_8009C510;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF18) = func_8009CDFC;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF1C) = func_8009CE28;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0xF20) = func_8009C904;
    M2C_FIELD(temp_v0, s32 (**)(), 0xF24) = func_8009C938;
    M2C_FIELD(temp_v0, void (**)(s32, s16, s16, s32, s32), 0xF04) = func_8009CE94;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xEC4) = func_8009C350;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xEC8) = func_8009C2D0;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xEBC) = func_8009C438;
    M2C_FIELD(temp_v0, void (**)(s32, s32), 0xED0) = func_8009C4A4;
    M2C_FIELD(temp_v0, void (**)(s32, s32), 0xED4) = func_8009C4D8;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xEC0) = func_8009C3C0;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xECC) = func_8009C264;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xF3C) = func_8009CFBC;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xF40) = func_8009CF60;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0xF44) = func_8009D15C;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009D540);

Obj *func_8009D6B4(void) {
    return func_80014504(func_8009D540, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009D6E0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009D8FC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009D9E4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009DA68);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009DBE8);

s32 func_8009DEC4(u8 *o, u8 *b) {
    s32 r = 0;
    if (*(s32 *)(o + 0x4E8) == 0) {
        o[0x499] = 2;
        (*(void (**)(u8 *))(*(u8 **)(b + 0x18) + 0xEC4))(*(u8 **)(b + 0x18));
        *(s32 *)(o + 0x4E8) += 1;
    }
    if (*(s16 *)(*(u8 **)(b + 0x18) + 0x64) == 0 && o[0x498] == 0) {
        r = 1;
    }
    return r;
}

s32 func_8009DF68(u8 *o, s32 unused, s32 i, s32 m) {
    u8 *p = o + 0x498;
    switch (m) {
    case 0:
        *(s32 *)(p + 0x3C) = ((CgObjSlot *)o)->s[i].v2;
        break;
    case 1:
        *(s32 *)(p + 0x3C) = ((CgObjSlot *)o)->s[i].v0;
        break;
    case 2:
        *(s32 *)(p + 0x3C) = ((CgObjSlot *)o)->s[i].v1;
        break;
    }
    *(s32 *)(p + 0x38) = *(s32 *)(p + 0x34) = *(s32 *)(p + 0x30) = 0;
    return *(s32 *)(p + 0x40) = *(s32 *)(p + 0x3C) * 4 + 10;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009E024);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009E560);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009E62C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009E668);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009EDCC);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009EEFC);

void func_8009F04C(u8 *o, s32 base, s32 n) {
    u8 *p = o + 0x59C;
    u8 *f;
    s32 i, a, b;
    s32 t;
    if (n < 2) {
        return;
    }
    for (i = 0, f = D_8004DC04; i < 40; i++) {
        a = (*(s32 (**)(void))(f + 8))() % n + base;
        b = (*(s32 (**)(void))(f + 8))() % n + base;
        t = ((CgArr14 *)p)->a[a];
        ((CgArr14 *)p)->a[a] = ((CgArr14 *)p)->a[b];
        ((CgArr14 *)p)->a[b] = t;
    }
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009F110);

s32 func_8009F8C0(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, u8 *, 0x2F9) == 0) {
        M2C_FIELD(arg0, u8 *, 0x421) = 0xA7;
        M2C_FIELD(arg0, s8 *, 0x2F4) = 1;
        M2C_FIELD(arg0, u8 *, 0x2F9) = 1U;
    } else {
        if (M2C_FIELD(arg0, s32 *, 0x440) == 0) {
            M2C_FIELD(arg0, s8 *, 0x2F5) = 0;
        } else {
            M2C_FIELD(arg0, s8 *, 0x2F5) = 1;
        }
        var_v1 = 1;
    }
    return var_v1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009F910);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009F998);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009FB18);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_8009FDD8);

void func_800A0548(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x574) = 0;
    func_8009EDCC();
    M2C_FIELD(arg0, M2C_UNK (**)(void *, void *, s32, M2C_UNK), 0x814)(arg0, arg0 + 0x600, M2C_FIELD(arg0, s16 *, 0x5A6) << 0x10, 0);
}

void func_800A0590(u8 *o, CgList *l) {
    s32 i, j;
    for (i = l->n - 1; i >= 0; i--) {
        if (*(s8 *)(o + i + 0x46F) != 0) {
            for (j = i; j < l->n - 1; j++) {
                l->a[j] = l->a[j + 1];
            }
            l->n--;
        }
    }
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0628);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0708);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0754);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0844);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A09FC);

void func_800A0ACC(u8 *o, s32 i) {
    s32 j;
    ((CgObj59C *)o)->s[i].x = 0;
    ((CgObj59C *)o)->s[i].y = 0;
    for (j = 0; j < ((CgObj72Cb *)o)->e[i].n; j++) {
        ((CgObj59C *)o)->s[i].x += ((CgObj72Cb *)o)->e[i].s[j].x;
        ((CgObj59C *)o)->s[i].y += ((CgObj72Cb *)o)->e[i].s[j].y;
    }
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0B80);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0CD4);

void func_800A0F4C(void *arg0, void *arg1) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg1, void **, 0x18);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0xEC8)(temp_a0);
    M2C_FIELD(arg0, s8 *, 0x49D) = 1;
    M2C_FIELD(arg0, s8 *, 0x499) = 1;
    M2C_FIELD(arg0, s8 *, 0x2F9) = 0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A0F94);

void func_800A19F8(void *arg0) {
    s16 temp_v0;
    u16 temp_v1;

    if (M2C_FIELD(arg0, s16 *, 0xA) > 0) {
        do {
            temp_v1 = M2C_FIELD(arg0, u16 *, 4) - 1;
            temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0xA) - 1;
            M2C_FIELD(arg0, u16 *, 4) = temp_v1;
            M2C_FIELD(arg0, s16 *, 0xA) = temp_v0;
            M2C_FIELD((arg0 + ((s32) (temp_v1 << 0x10) >> 0xF)), u16 *, 0x14) = (u16) M2C_FIELD((arg0 + ((s32) (temp_v0 << 0x10) >> 0xF)), u16 *, 0x64);
            M2C_FIELD(arg0, u16 *, 8) = (u16) (M2C_FIELD(arg0, u16 *, 8) + 1);
        } while (M2C_FIELD(arg0, s16 *, 0xA) > 0);
    }
}

void func_800A1A5C(void *arg0, M2C_UNK arg1) {
    void *temp_s1;

    temp_s1 = arg0 + 0x59C;
    func_800A19F8(temp_s1);
    func_8009DA68(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, s16, s16), 0x810)(arg0, M2C_FIELD(temp_s1, s16 *, 4), M2C_FIELD(temp_s1, s16 *, 8));
    M2C_FIELD(arg0, s8 *, 0x304) = 0;
    M2C_FIELD(arg0, s8 *, 0x305) = 0;
    M2C_FIELD(arg0, s16 *, 0x59C) = 0;
    M2C_FIELD(arg0, s16 *, 0x59E) = 0;
    M2C_FIELD(arg0, s16 *, 0x664) = 0;
    M2C_FIELD(arg0, s16 *, 0x666) = 0;
    func_8009EDCC(arg0, arg1);
    M2C_FIELD(arg0, u8 *, 0x300) = (u8) (M2C_FIELD(arg0, u8 *, 0x300) + 1);
    func_8009D9E4(arg0, arg1);
}

void func_800A1AF8(u8 *o) {
    u8 *t = D_800A5D5C;
    u8 *e;

    o[0x2F4] = 1;
    e = t + o[0x2F6] * 4;
    o[0x421] = e[0];
    o[0x2F7] = e[2];
}

void func_800A1B2C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x5AD) = 0;
    M2C_FIELD(arg0, s8 *, 0x675) = 1;
    M2C_FIELD(arg0, s8 *, 0x303) = 0;
    M2C_FIELD(arg0, s8 *, 0x302) = 1;
    M2C_FIELD(arg0, s8 *, 0x2F8) = 1;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A1B48);

s32 func_800A1DB8(u8 *o, u8 *b) {
    s32 r = 0;
    if (*(s32 *)(o + 0x4E8) == 0) {
        o[0x499] = o[0x49D] = 1;
        (*(void (**)(u8 *))(*(u8 **)(b + 0x18) + 0xEC8))(*(u8 **)(b + 0x18));
        *(s32 *)(o + 0x4E8) += 1;
    }
    if (*(s16 *)(*(u8 **)(b + 0x18) + 0x64) == 2 && o[0x498] == 0) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A1E60);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A2180);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A2608);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A2DF8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A2F00);

void *func_800A3240(s8 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A2F00, 0x824, 0x1C);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x810) = func_8009F04C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0x814) = func_8009EEFC;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x818) = func_800A0754;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x81C) = func_800A0708;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x820) = func_800A3934;
    M2C_FIELD(temp_v0, s8 *, 0x2E8) = arg0;
    ((M2C_UNK (*)(M2C_UNK)) *D_80055C54)(0x27);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A32D8);

void func_800A3488(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    u8 temp_a0;
    void *temp_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x54) - ((s32 (*)()) D_8004DF9C)();
    M2C_FIELD(arg0, s32 *, 0x54) = temp_v1;
    if (temp_v1 > 0) {
        var_a2 = 0;
        do {
            temp_a1 = arg0 + var_a2;
            temp_a0 = M2C_FIELD(temp_a1, u8 *, 0x5E);
            temp_v0 = (s32) ((temp_a0 - M2C_FIELD(temp_a1, u8 *, 0x61)) * M2C_FIELD(arg0, s32 *, 0x54)) / (s32) M2C_FIELD(arg0, s32 *, 0x58);
            var_a2 += 1;
            M2C_FIELD(temp_a1, s8 *, 0x64) = (s8) (temp_a0 - temp_v0);
        } while (var_a2 < 3);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x5D) != 0) {
        M2C_FIELD(arg0, s32 *, 0x50) = 2;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, u8 *, 0x64) = (u8) M2C_FIELD(arg0, u8 *, 0x5E);
    M2C_FIELD(arg0, u8 *, 0x65) = (u8) M2C_FIELD(arg0, u8 *, 0x5F);
    M2C_FIELD(arg0, u8 *, 0x66) = (u8) M2C_FIELD(arg0, u8 *, 0x60);
}

void func_800A3548(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    M2C_FIELD(arg0, s8 *, 0x64) = arg1;
    M2C_FIELD(arg0, s8 *, 0x65) = arg2;
    M2C_FIELD(arg0, s8 *, 0x66) = arg3;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A3558);

s32 func_800A35A4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x50) == 0;
}

void func_800A35B0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = 2;
}

void func_800A35BC(u8 *o) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        if (*(s32 *)(o + 0x50) == 1) {
            func_800A3488(o);
        }
        ((void (*)(u8 *, CgPt16, CgPt16))func_800A32D8)(o, D_800A5D94[0], D_800A5D94[1]);
        if (*(s32 *)(o + 0x50) == 2) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_800A367C(s8 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A35BC, 0x78, 4);
    M2C_FIELD(temp_v0, void (**)(void *, s8, s8, s8), 0x68) = func_800A3548;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32, s32), 0x6C) = func_800A3558;
    M2C_FIELD(temp_v0, s32 (**)(void *), 0x70) = func_800A35A4;
    M2C_FIELD(temp_v0, s8 *, 0x5C) = arg0;
    M2C_FIELD(temp_v0, void (**)(void *), 0x74) = func_800A35B0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A36E4);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A3934);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A3D90);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A3E9C);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A3F48);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4078);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A41A8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A41F8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4328);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4440);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4494);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A44F0);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A45F8);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4924);

INCLUDE_ASM("asm/ovl/CARDGAME/nonmatchings/CARDGAME", func_800A4978);
