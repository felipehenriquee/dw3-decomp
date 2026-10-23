#include "STITSHOP.h"
#include "m2c.h"
#include "STITSHOP_auto.h"
#include "STITSHOP_data.h"

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008321C);

Obj *func_80083318(void) {
    return func_80014504(func_8008321C, 0x50, 4);
}

void func_80083344(void *arg0, s32 arg1, s32 arg2) {
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

void func_800833CC(u8 *obj) {
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

void func_80083510(u8 *a) {
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
        func_800833CC(a);
    case 3:
        break;
    }
}

Obj *func_800835C4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083510, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80083344;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    return temp_v0;
}

void func_8008360C(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xB9, 0x3A);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x103, 0x54);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x11E, 0x54);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x9A, 0x2C);
    M2C_FIELD(arg1, s32 *, 0x18) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xC5, 0x49);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xC5, 0x59);
    temp_v0 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x58), M2C_FIELD(arg0, s32 *, 0x5C) - 1, 0xB8, 0x49);
    M2C_FIELD(arg1, s32 *, 0x20) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0, 0);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800836F8);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083810);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083970);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083EB0);

void func_80085890(u8 *o, s32 b) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        func_8008360C(o, b);
        *(s32 *)(o + 0xB8) = *(s32 *)(o + 0xA8) = *(s32 *)(o + 0x98) = *(s32 *)(o + 0x88) = 10;
        *(s32 *)(o + 0x64) = 1;
        break;
    case 1:
        func_80083EB0(o, b);
        func_80083970(o, b);
        break;
    case 2:
    case 3:
        break;
    }
}

void func_80085934(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 4);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x234)(temp_a0);
}

Obj *func_8008596C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085890, 0xC8, 0x24);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x50) = func_80085934;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800859C0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80085B18);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80085F48);

void func_800872F4(u8 *o, s32 b) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        func_800859C0(o, b);
        *(s32 *)(o + 0xBC) = *(s32 *)(o + 0xAC) = *(s32 *)(o + 0x9C) = *(s32 *)(o + 0x8C) = *(s32 *)(o + 0x7C) = 10;
        *(s32 *)(o + 0x68) = 1;
        break;
    case 1:
        func_80085F48(o, b);
        func_80085B18(o, b);
        break;
    case 2:
    case 3:
        break;
    }
}

void func_8008739C(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 4);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x234)(temp_a0);
}

Obj *func_800873D4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800872F4, 0xCC, 0x38);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x50) = func_8008739C;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087428);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800875E0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087920);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087CFC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087EC0);

void func_80088670(void *arg0, s32 arg1) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(temp_s0, void **, 0x4C);
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x88)(temp_a0, 7);
        temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x4C);
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x94)(temp_a0_2, 1);
        M2C_FIELD(arg0, s32 *, 0x6B8) = 0;
        return;
    }
    temp_a0_3 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_3, M2C_UNK (**)(void *, M2C_UNK), 0x88)(temp_a0_3, 0);
    temp_a0_4 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_4, M2C_UNK (**)(void *, M2C_UNK), 0x94)(temp_a0_4, 0);
    M2C_FIELD(arg0, s32 *, 0x6B8) = 1;
}

void func_80088714(void *arg0, s32 arg1) {
    s32 temp_a3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    M2C_FIELD(arg0, s32 *, 0x6B8) = arg1;
    temp_a0 = M2C_FIELD(temp_s0, void **, 0x4C);
    temp_a3 = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x6BC) % (s32) M2C_FIELD(arg0, s32 *, 0x6D4)) / 2;
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, s32, s32, s32), 0x84)(temp_a0, ((M2C_FIELD(arg0, s32 *, 0x6BC) % 2) * 0x83) + 0x1D, (temp_a3 * 0xE) + 0x24, temp_a3);
    temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, s32), 0x80)(temp_a0_2, arg1);
}

void func_800887C4(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
}

void func_800887EC(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
    func_80088714(arg0, 0);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088830);

void func_80088878(void *arg0) {
    u8 *base0;
    s32 temp_s1;
    void *temp_a0;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    func_800888E4((s32) arg0);
    func_800875E0((s32) arg0, temp_s1, 1);
    temp_a0 = M2C_FIELD(arg0, void **, 0x50);
    base0 = (u8 *)arg0 + (M2C_FIELD(arg0, s32 *, 0x6BC) * 2);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, s16, M2C_UNK), 0x50)(temp_a0, M2C_FIELD(base0, s16 *, 0x64), 1);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800888E4);

Obj *func_800889A8(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087EC0, 0x704, 0x50);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6E8) = func_800887C4;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6EC) = func_800887EC;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6F0) = func_80088830;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x6F4) = func_80088714;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x6F8) = func_80088670;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6FC) = func_80088878;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x700) = func_800888E4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088A64);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088DB8);

void func_80088E8C(u8 *o, u8 *x, s32 *q) {
    s16 v;
    o += q[0] * 128 + 0x64;
    if (q[2] == 0) {
        v = ((s16 *)o)[D_8008CAE8[q[1]]];
    } else {
        v = ((s16 *)(o + 0x2C))[D_8008CAE8[q[1]]];
    }
    (*(void (**)(u8 *, s32, s32))(x + 0x118))(x, 0, v);
    (*(void (**)(u8 *, s32))(x + 0x148))(x, 1);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088F4C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800890B0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089274);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089A44);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089E2C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A0D0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A1FC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A450);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A758);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008ADEC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008AF68);

void func_8008B29C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x1E4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1E8) = arg2;
    if (M2C_FIELD(arg0, s32 *, 0x1F0) != 0) {
        func_80089E2C((s32) arg0, temp_s1, 1);
        if (M2C_FIELD(arg0, s32 *, 0x5C) == 0) {
            func_8008A0D0((s32) arg0, temp_s1, 1);
            return;
        }
        func_8008A0D0((s32) arg0, temp_s1, 0);
        func_8008A1FC((s32) arg0, temp_s1, 1);
    }
}

void func_8008B324(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == 3) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
    }
}

void func_8008B340(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 0x20);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, s32), 0x144)(temp_a0, arg1 & 0xFF);
}

void func_8008B378(u8 *o) {
    u8 *f = (u8 *)&D_80042B98;
    if ((*(s32 (**)(s32, s32))(f + 8))(*(s32 *)(o + 0x1E4), 3) != 0 ||
        (*(s32 (**)(s32, s32))(f + 8))(*(s32 *)(o + 0x1E4), 4) != 0 ||
        (*(s32 (**)(s32, s32))(f + 8))(*(s32 *)(o + 0x1E4), 5) != 0) {
        ((void (*)(s32))D_80055C48[0])(0x4001B);
        *(s32 *)(o + 0x10) = 10;
        *(s32 *)(o + 0x1F0) = 0;
        *(s32 *)(o + 0x5C) = 1 - *(s32 *)(o + 0x5C);
    }
}

void func_8008B430(void *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    func_80089E2C((s32) arg0, temp_s1, 1);
    func_80089274((s32) arg0, temp_s1, arg1);
}

Obj *func_8008B484(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008AF68, 0x248, 0xAC);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x234) = func_8008B29C;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x238) = func_8008B324;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x23C) = func_8008B340;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x240) = func_8008B378;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x244) = func_8008B430;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x1E4) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x1E8) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x1F0) = 1;
    return temp_v0;
}

void func_8008B524(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xD3, 0xCC);
    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0x1D, 0x14);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 3, 0x117, 0x17);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 3, 0x11A, 0x17);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xBE, 0x2F);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xBE, 0x3D);
    temp_v0 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x50), 0, 0xB0, 0x2F);
    M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0, 0);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008B60C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008B908);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008BFB0);

void func_8008C0C4(u8 *o) {
    u8 *w = *(u8 **)(o + 0x24);
    u8 *c = *(u8 **)(w + 0x8);

    (*(void (**)(u8 *, s32, s32))(c + 0x118))(c, 0, D_80048DA0[0]);
    c = *(u8 **)(w + 0x8);
    (*(void (**)(u8 *, s32))(c + 0x148))(c, 1);
}

void *func_8008C118(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008BFB0, 0xAC, 0x24);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xA8) = func_8008C0C4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x60) = ((s32 (*)()) D_8004B43C)();
    return temp_v0;
}

void func_8008C17C(void) {
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
    g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x4030000));
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x71);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x6A);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x63);
    (*(void (**)(s32))(f + 0x40C))(D_8005CCA8[0] + 0x94);
}

s32 func_8008C238(void) {
    u8 *f = (u8 *)D_80044B38;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x71) != 0) return 1;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x6A) != 0) return 1;
    if ((*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x63) != 0) return 1;
    return (*(s32 (**)(s32))(f + 0x404))(D_8005CCA8[0] + 0x94) != 0;
}

void func_8008C2DC(void *arg0, s32 arg1) {
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

s32 func_8008C370(Fade *f) {
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

void func_8008C3DC(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C41C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C488);

s32 func_8008C4CC(s32 arg0, M2C_UNK arg1) {
    return ((s32) M2C_FIELD(*((void **(*)(M2C_UNK)) D_80042B98)(arg1), u8 *, 4) >> arg0) & 1;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C510);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C800);
