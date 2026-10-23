#include "WFIGHTMN.h"
#include "m2c.h"
#include "WFIGHTMN_auto.h"
#include "WFIGHTMN_data.h"

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A5ECC);

Obj *func_800A6414(void) {
    return func_80014504(func_800A5ECC, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A6440);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A66B0);

s32 func_800A684C(void) {
    u8 *a = D_80042B1C;
    u8 *t;
    s32 k, lim, r, d;
    if (a[0x3C] == 0) {
        return 0;
    }
    t = D_80048D34;
    k = (*(s32 (**)(s32))(t + 0x2718))(0);
    d = 0x20 - *(s16 *)(t + k * 0x3DC + 0x784);
    lim = a[0x3C] * (d - *(s16 *)(a + 0x1C)) / 32;
    r = ((s32 (*)(void))D_8004DC0C)() % 128;
    if (r == 0) {
        return 1;
    }
    return r < lim;
}

void func_800A6920(s32 a) {
    u8 *t = D_80048D34;
    s32 r = (*(s32 (**)(s32))(t + 0x2718))(a);
    s16 *q;
    s32 i;
    if (r >= 0) {
        q = (s16 *)((*(u8 *(**)(s32))(t + 0x2750))(r) + 0x3C8);
        for (i = 0; i < 2; i++) {
            if (q[i] == 0x140) {
                func_8009C6A4(0, a, 0);
                return;
            }
        }
    }
}

void func_800A69B8(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_800A6920(var_s0);
        var_s0 += 1;
    } while (var_s0 < 3);
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A69F0);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A6B18);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A6C44);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A7328);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A7418);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A77B4);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A78D8);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A7B08);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A7C00);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A7FE4);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8118);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8260);

void func_800A8458(u8 *o, u8 *w) {
    *(s32 *)(w + 0x1C) = func_8009A298();
    *(s32 *)(o + 0x50) = 0x6A;
    (*(void (**)(u8 *, s32, u8 *))(*(u8 **)(w + 0x1C) + 0xAC))(*(u8 **)(w + 0x1C), 1, o + 0x50);
    {
        u8 *d = D_800A4460;
        *(s16 *)(d + 0xD0) = 0;
        *(s16 *)(d + 0xD2) = 0;
    }
    (*(void (**)(u8 *, s32))(o + 0x2C))(o, 2);
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A84D0);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8770);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A88CC);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A89F0);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8AC8);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8BF4);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8E90);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A8F88);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A9584);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A9640);

void func_800A97BC(u8 *o, u8 *w) {
    u8 *x;
    switch (*(s32 *)(o + 0x14)) {
    case 0:
    default:
        if (*(u8 **)(w + 0x1C) == 0) {
            goto done;
        }
        if (((s32 (*)(void))D_8004DF98[0])() - *(s32 *)(o + 0x54) > *(s32 *)(o + 0x58)) {
            x = *(u8 **)(w + 0x1C);
            (*(void (**)(u8 *))(x + 0xB0))(x);
            *(s32 *)(o + 0x14) += 1;
        }
        break;
    case 1:
        if (*(u8 **)(w + 0x1C) != 0) {
            *(s32 *)(*(u8 **)(w + 0x1C) + 0xC) = 3;
        }
    done:
        (*(void (**)(u8 *, s32))(o + 0x2C))(o, 0);
        break;
    }
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A988C);

void func_800A9C10(u8 *o) {
    u8 *d = D_800A3868;
    s32 m[8];
    u8 *f;
    s32 i = (*(s32 (**)(s32))(d + 0xB04))(3);
    if (i >= 0) {
        *(s16 *)(d + i * 28) = 0;
    }
    m[0] = 3;
    m[1] = 1;
    m[2] = -1;
    (*(void (**)(s32 *))(d + 0xAFC))(m);
    f = D_800A4460;
    *(s16 *)(f + 0x86) = 0;
    *(s16 *)(f + 0x82) = 0;
    (*(void (**)(u8 *, s32))(o + 0x2C))(o, 2);
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800A9CB4);

u8 *func_800A9FF0(void) {
    u8 *heap;
    u8 *o = func_800143DC(func_800A6C44, 0x74, 0x20, 0xC);

    heap = (u8 *)&D_8004B5DC;

    (*(void (**)(void *, s32))(heap + 0x24))(&D_800A4468, 0xD4);
    (*(void (**)(void *, s32))(heap + 0x24))(D_80042B84, 0x12);
    return o;
}

void func_800AA06C(u8 side, s32 k) {
    Rec18 *r = &D_80042BCA[k];
    s32 ok;
    u8 t;
    if (side == 0 && D_800A4536 == 4) {
        ok = 0;
        if (r->b[0x10] != 5 && r->b[0x10] != 12) {
            t = r->b[0xA];
            if (t >= 2 && (u8)(t - 9) >= 2) {
                ok = t != 12;
            }
            if (r->b[7] >= 2) {
                ok = 1;
            }
            if (ok) {
                D_800A4538 = k;
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800AA110);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800AA1F0);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800AA9F0);

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800AAB10);

void func_800AABA0(s32 x) {
    u8 *d = D_800A4460;

    if (*(s16 *)(d + 0xD6) == 6 && (u8)x == 0 && d[0xDB] != 0) {
        func_8009D0EC();
    }
}

INCLUDE_ASM("asm/ovl/WFIGHTMN/nonmatchings/WFIGHTMN", func_800AABF0);
