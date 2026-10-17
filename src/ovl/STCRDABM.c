#include "STCRDABM.h"
#include "m2c.h"
#include "STCRDABM_auto.h"
#include "STCRDABM_data.h"

void func_80082D88(void *arg0, s32 arg1, s32 arg2) {
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

void func_80082E10(u8 *obj) {
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

void func_80082F54(u8 *a) {
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
        func_80082E10(a);
    case 3:
        break;
    }
}

void func_80083008(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80082F54, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80082D88;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_8008304C);

void func_80083114(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x5C);
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
}

void func_8008314C(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083174);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800835BC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083734);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083780);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083848);

void func_80083A78(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083848, 0x8C, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x84) = func_80083114;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x88) = func_8008314C;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

/* estado 0: limpa a tela, cria o objeto de fundo e o objeto principal */
void func_80083AD8(u8 *o, Obj **out) {
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
        *out = func_8008566C();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

Obj *func_80083BD0(void) {
    return func_80014504(func_80083AD8, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083BFC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083E14);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800840AC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084500);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084BC8);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084C38);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80085540);

Obj *func_8008566C(void) {
    Obj *o = func_80014504(func_80085540, 0xD8, 0x4C);

    o->unk50 = 0x1000;
    o->unk54 = 7;
    return o;
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800856A8);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800857A0);

void func_800858A0(void *arg0, s32 arg1) {
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

s32 func_80085934(Fade *f) {
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

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800859A0);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800859E0);
