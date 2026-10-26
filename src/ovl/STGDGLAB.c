#include "STGDGLAB.h"
#include "m2c.h"
#include "STGDGLAB_auto.h"
#include "STGDGLAB_data.h"

void func_80082F48(u8 *o, Obj **out) {
    s16 r[4];
    u8 *sys;
    u8 *bg;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        sys = D_8004DE10;
        (*(void (**)(void))(sys + 0x150))();
        (*(void (**)(s32))(sys + 0x154))(0xF000);
        (*(void (**)(s32, s32, s32, s32))(sys + 0x174))(0x140, 0xF0, 0, 0);
        r[0] = 0;
        r[1] = 0;
        r[2] = 0x140;
        r[3] = 0xF0;
        bg = (*(u8 *(**)(s16 *, s32, s32))(sys + 0x16C))(r, 3, 0x1000);
        (*(void (**)(u8 *, s32, s32, s32))(bg + 0x12C))(bg, 0, 0, 0);
        *out = func_8008EFD0();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80083040(void) {
    return func_80014504(func_80082F48, 0x50, 4);
}

void func_8008306C(void *arg0, s32 arg1, s32 arg2) {
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

void func_800830F4(u8 *obj) {
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

void func_80083238(u8 *a) {
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
        func_800830F4(a);
    case 3:
        break;
    }
}

Obj *func_800832EC(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083238, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x64) = func_8008306C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80083334);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80083484);

s32 func_80083550(s32 arg0, u32 arg1) {
    s32 var_s0;
    s32 var_s1;

    if (arg1 >= 4U) {
        return 0;
    }
    var_s0 = 0;
    var_s1 = 0;
    do {
        var_s1 += func_80083484(arg0, arg1, var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
    return var_s1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800835CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008365C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800841E4);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800842F4);

void *func_80085408(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800842F4, 0x29C, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, void **, 0x50) = arg0;
    M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x6C)(arg0);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085470);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085730);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085C50);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085DD0);

Obj *func_80087018(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085DD0, 0x100, 0xA0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087070);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087248);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087600);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008820C);

void func_800885EC(u8 *o, s32 b) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s32 *)(o + 0x54) = 8;
        *(s32 *)(o + 0x64) = 10;
        *(s32 *)(o + 0x74) = 10;
        *(s32 *)(o + 0x84) = 10;
        *(s32 *)(o + 0x94) = 10;
        *(s32 *)(o + 0xA4) = 8;
        func_80087070(o, b);
        break;
    case 1:
        func_80087600(o, b);
        func_8008820C(o, b);
        break;
    case 2:
    case 3:
        break;
    }
}

Obj *func_80088694(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800885EC, 0x130, 0x60);
    M2C_FIELD(temp_v0, s32 *, 0xB4) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0xB8) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_800886DC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    ((M2C_UNK (*)(void *, M2C_UNK)) D_8008FD98)(arg0 + 0x94, 1);
}

void func_80088718(u8 *o) {
    s32 i;
    u8 *t;
    *(s32 *)(o + 0xC) = 2;
    *(s32 *)(o + 0x18) = 1;
    t = *(u8 **)(o + 0x24);
    ((void (*)(u8 *, s32))D_8008FD98)(o + 0x94, 0);
    for (i = 0; i < 5; i++) {
        if (((u8 **)(t + 0x14))[i] != 0) {
            (*(void (**)(u8 *, s32))(((u8 **)(t + 0x14))[i] + 0x144))(((u8 **)(t + 0x14))[i], 0);
        }
        if (((u8 **)(t + 0x28))[i] != 0) {
            (*(void (**)(u8 *, s32))(((u8 **)(t + 0x28))[i] + 0x144))(((u8 **)(t + 0x28))[i], 0);
        }
    }
    if (*(u8 **)(t + 0x3C) != 0) {
        (*(void (**)(u8 *, s32))(*(u8 **)(t + 0x3C) + 0x144))(*(u8 **)(t + 0x3C), 0);
    }
    for (i = 4; i >= 0; i--) {
        *(s32 *)(o + i * 4 + 0xFC) = 0;
    }
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80088808);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80088B5C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80089AEC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A51C);

Obj *func_8008A610(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008A51C, 0x11C, 0x4C);
    M2C_FIELD(temp_v0, s32 (**)(), 0x114) = func_800886DC;
    M2C_FIELD(temp_v0, s32 (**)(), 0x118) = func_80088718;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_8008A670(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_8008A67C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = 1;
}

void func_8008A690(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_8008A6A4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A6AC);

Obj *func_8008A8C4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008A6AC, 0x9C, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x8C) = func_8008A670;
    M2C_FIELD(temp_v0, s32 (**)(), 0x90) = func_8008A67C;
    M2C_FIELD(temp_v0, s32 (**)(), 0x94) = func_8008A690;
    M2C_FIELD(temp_v0, s32 (**)(), 0x98) = func_8008A6A4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A92C);

void func_8008AD18(u8 *o) {
    s32 i;
    u8 **c = *(u8 ***)(o + 0x24);

    for (i = 0; i < *(s32 *)(o + 0x20) - 1; i++, c++) {
        if (*c != NULL) {
            (*(void (**)(u8 *, s32))(*c + 0x144))(*c, 0);
        }
    }
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008AD98);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008B798);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C060);

Obj *func_8008C230(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008C060, 0x108, 0x38);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C278);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C4EC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C960);

Obj *func_8008D774(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008C960, 0xAC, 0x5C);
    M2C_FIELD(temp_v0, s32 *, 0x70) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x74) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x78) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008D7CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008D9BC);

void func_8008DFA0(void *arg0) {
    void *temp_a0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x24);
    ((M2C_UNK (*)(s32, M2C_UNK)) D_8008FD98)(arg0 + 0x80, 0);
    func_8008D9BC(arg0, temp_s1, 0);
    temp_a0 = M2C_FIELD(temp_s1, void **, 0x68);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x80)(temp_a0, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 1);
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E018);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E4CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E8D0);

Obj *func_8008EABC(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008E8D0, 0x174, 0x70);
    M2C_FIELD(temp_v0, s32 (**)(), 0x170) = func_8008DFA0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x16C) = arg2;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008EB30);

void func_8008EC50(u8 *o) {
    s32 i, j;
    u8 *t;
    t = (u8 *)D_80048D34;
    *(s32 *)(o + 0x60) = 0;
    for (i = 0; i < 3; i++) {
        if (((s32 *)(t + 0x70))[i] >= 0) {
            *(s32 *)(o + 0x60) += 1;
        }
    }
    t = (u8 *)D_80048D34;
    for (i = 0; i < 3; i++) {
        if (((s32 *)(t + 0x70))[i] < 0) {
            for (j = i; j < 3; j++) {
                if (((s32 *)(t + 0x70))[j] >= 0) {
                    ((s32 *)(t + 0x70))[i] = ((s32 *)(t + 0x70))[j];
                    ((s32 *)(t + 0x70))[j] = -1;
                    break;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008ED0C);

s32 func_8008EEA0(void *arg0) {
    void *temp_a0;

    temp_a0 = *M2C_FIELD(arg0, void ***, 0x24);
    if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x114)(temp_a0);
        return 1;
    }
    return 0;
}

s32 func_8008EEFC(void *arg0) {
    void *temp_a0;

    temp_a0 = *M2C_FIELD(arg0, void ***, 0x24);
    if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x118)(temp_a0);
        return 1;
    }
    return 0;
}

/* o primeiro filho existe e esta no estado 1? */
s32 func_8008EF58(u8 *o) {
    u8 *c = **(u8 ***)(o + 0x24);

    if (c != NULL && *(s32 *)(c + 0xC) == 1) {
        return 1;
    }
    return 0;
}

void func_8008EF8C(u8 *o) {
    u8 *w = *(u8 **)(o + 0x24);
    u8 *c = (u8 *)func_800832EC();

    *(u8 **)(w + 8) = c;
    (*(void (**)(u8 *, s32, s32))(c + 0x64))(c, 0, 0x1E);
}

Obj *func_8008EFD0(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008ED0C, 0x7C, 0xC);
    M2C_FIELD(temp_v0, s32 (**)(), 0x68) = func_8008EEA0;
    M2C_FIELD(temp_v0, s32 (**)(), 0x6C) = func_8008EEFC;
    M2C_FIELD(temp_v0, s32 (**)(), 0x70) = func_8008EF58;
    M2C_FIELD(temp_v0, s32 (**)(), 0x74) = func_8008EC50;
    M2C_FIELD(temp_v0, s32 (**)(), 0x78) = func_8008EF8C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F040);

s32 func_8008F16C(void) {
    u8 *p = (u8 *)D_80044B38;
    if ((*(s32 (**)(s32))(p + 0x404))(D_8005CCA8[0] + 0x39) != 0) return 1;
    if ((*(s32 (**)(s32))(p + 0x404))(D_8005CCA8[0] + 0x4E) != 0) return 1;
    if ((*(s32 (**)(s32))(p + 0x404))(D_8005CCA8[0] + 0x47) != 0) return 1;
    if ((*(s32 (**)(s32))(p + 0x404))(D_8005CCA8[0] + 0xA2) != 0) return 1;
    return (*(s32 (**)(s32))(p + 0x404))(D_8005CCA8[0] + 0x9B) != 0;
}

void func_8008F22C(void *arg0, s32 arg1) {
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

s32 func_8008F2C0(Fade *f) {
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

void func_8008F32C(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F36C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F3D8);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F424);
