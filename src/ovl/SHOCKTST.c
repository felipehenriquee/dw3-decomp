#include "SHOCKTST.h"
#include "m2c.h"
#include "SHOCKTST_auto.h"
#include "SHOCKTST_data.h"

void func_80082DA0(u8 *o, Obj **w) {
    s16 r[4];
    u8 *t;
    u8 *x;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = D_8004DE10;
        (*(void (**)(void))(t + 0x150))();
        (*(void (**)(s32))(t + 0x154))(0x5000);
        (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
        r[0] = 0;
        r[1] = 0;
        r[2] = 0x140;
        r[3] = 0xF0;
        x = (*(u8 *(**)(s16 *, s32, s32))(t + 0x16C))(r, 0x1, 0x1000);
        (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 0, 0, 0);
        w[0] = (Obj *)func_8008499C();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80082E98(void) {
    return func_80014504(func_80082DA0, 0x50, 4);
}

void func_80082EC4(s32 unused, u8 **w, u32 k) {
    s32 i;
    (*(void (**)(u8 *, s32))(w[0] + 0x138))(w[0], 0);
    for (i = 0; i < 2; i++) {
        (*(void (**)(u8 *, s32))(w[i + 4] + 0x138))(w[i + 4], 0);
        (*(void (**)(u8 *, s32))(w[i + 6] + 0x138))(w[i + 6], 0);
    }
    (*(void (**)(u8 *, s32))(w[8] + 0x138))(w[8], 0);
    switch (k) {
    case 1:
    default:
        (*(void (**)(u8 *, s32))(w[0] + 0x138))(w[0], 3);
        break;
    case 2:
        (*(void (**)(u8 *, s32))(w[4] + 0x138))(w[4], 3);
        break;
    case 3:
        (*(void (**)(u8 *, s32))(w[5] + 0x138))(w[5], 3);
        break;
    case 4:
        (*(void (**)(u8 *, s32))(w[6] + 0x138))(w[6], 3);
        break;
    case 5:
        (*(void (**)(u8 *, s32))(w[7] + 0x138))(w[7], 3);
        break;
    case 10:
        (*(void (**)(u8 *, s32))(w[8] + 0x138))(w[8], 3);
        break;
    case 0:
        (*(void (**)(u8 *, s32))(w[0] + 0x138))(w[0], 1);
        break;
    case 6:
        (*(void (**)(u8 *, s32))(w[4] + 0x138))(w[4], 1);
        break;
    case 7:
        (*(void (**)(u8 *, s32))(w[5] + 0x138))(w[5], 1);
        break;
    case 8:
        (*(void (**)(u8 *, s32))(w[6] + 0x138))(w[6], 1);
        break;
    case 9:
        (*(void (**)(u8 *, s32))(w[7] + 0x138))(w[7], 1);
        break;
    case 11:
        (*(void (**)(u8 *, s32))(w[8] + 0x138))(w[8], 1);
        break;
    }
}

s32 func_80083064(u8 *o, u8 **w) {
    u8 *t = (u8 *)D_8004B7D0;
    if ((((*(s32 (**)(s32))(t + 0x3F4))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 4)) & 1) || (((*(s32 (**)(s32))(t + 0x3FC))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 4)) & 1)) {
        *(s32 *)(o + 0x74) -= 1;
        if (*(s32 *)(o + 0x74) < 0) {
            *(s32 *)(o + 0x74) = 0;
        }
    } else if ((((*(s32 (**)(s32))(t + 0x3F4))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 6)) & 1) || (((*(s32 (**)(s32))(t + 0x3FC))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 6)) & 1)) {
        *(s32 *)(o + 0x74) += 1;
        if (*(s32 *)(o + 0x78) - 1 < *(s32 *)(o + 0x74)) {
            *(s32 *)(o + 0x74) = *(s32 *)(o + 0x78) - 1;
        }
    }
    (*(void (**)(u8 *, s32, s32))(*w + 0x118))(*w, 1, *(s32 *)(o + 0x74));
    func_80083274(o, (u8 *)w, *(s32 *)(o + 0x74));
    t = (u8 *)D_8004B7D0;
    if ((((*(s32 (**)(s32))(t + 0x3F4))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 0xD)) & 1)) {
        return 1;
    }
    if ((((*(s32 (**)(s32))(t + 0x3F4))(0) >> (*(s32 (**)(s32, s32))(t + 0x408))(0, 0xE)) & 1)) {
        return -1;
    }
    return 0;
}

void func_80083274(u8 *o, u8 *b, s32 n) {
    s32 i;
    u8 *p;
    p = *(u8 **)b;
    (*(void (**)(u8 *, s32, s32))(p + 0x118))(p, 1, n);
    for (i = 0; i < 2; i++) {
        p = ((u8 **)(b + 0x18))[i];
        (*(void (**)(u8 *, s32, s32))(p + 0x118))(p, 1, (((u8 **)(o + 0x7C))[i] + n * 2)[1]);
        p = ((u8 **)(b + 0x10))[i];
        (*(void (**)(u8 *, s32, s32))(p + 0x118))(p, 1, (((u8 **)(o + 0x7C))[i] + n * 2)[0]);
    }
}

void func_8008332C(u8 *o, u8 *b, s32 n) {
    s32 i;
    u8 *p;
    for (i = 0; i < 2; i++) {
        p = ((u8 **)(b + 0x18))[i];
        (*(void (**)(u8 *, s32, s32))(p + 0x118))(p, 1, (((u8 **)(o + 0x7C))[i] + n * 2)[1]);
        p = ((u8 **)(b + 0x10))[i];
        (*(void (**)(u8 *, s32, s32))(p + 0x118))(p, 1, ((s32 *)(o + 0x64))[i]);
    }
}

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800833C0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800835F4);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800836C0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083B2C);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083DB4);

INCLUDE_RODATA("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", D_80082CE0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083EA4);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800842E0);

Obj *func_8008436C(s32 n) {
    u8 *heap;
    u8 *o = (u8 *)func_80014504(func_80083EA4, 0x88, 0x24);

    *(s32 *)(o + 0x78) = n;
    heap = (u8 *)&D_8004B5DC;
    *(u8 **)(o + 0x7C) = (*(u8 *(**)(s32, s32))(heap + 0x20))(n * 2, 2);
    *(u8 **)(o + 0x80) = (*(u8 *(**)(s32, s32))(heap + 0x20))(*(s32 *)(o + 0x78) * 2, 2);
    return (Obj *)o;
}

INCLUDE_RODATA("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", D_80082D24);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800843F0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80084714);

Obj *func_8008499C(void) {
    return func_80014504(func_80084714, 0x5C, 0x10);
}
