#include "STSTATUS.h"
#include "m2c.h"
#include "STSTATUS_auto.h"
#include "STSTATUS_data.h"

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80083558);

Obj *func_80083654(void) {
    return func_80014504(func_80083558, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80083680);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80083914);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80083B58);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80083C94);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80084238);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80084A98);

Obj *func_80084C48(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084A98, 0xD4, 0xA0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80084C90(void *arg0, s32 arg1, s32 arg2) {
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

void func_80084D18(u8 *obj) {
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

void func_80084E5C(u8 *a) {
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
        func_80084D18(a);
    case 3:
        break;
    }
}

Obj *func_80084F10(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084E5C, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80084C90;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80084F54);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008519C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800853E0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800855C8);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80085B6C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800862A0);

Obj *func_80086450(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800862A0, 0xD4, 0x9C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80086498);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80086680);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800867B8);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80086900);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80086C78);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80086DD4);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008744C);

void func_80088214(u8 *o, s32 b) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(s32 *)(o + 0x6C) = 0;
        func_80086498(o, b);
        *(s32 *)(o + 0x6CC) = *(s32 *)(o + 0x6EC) = *(s32 *)(o + 0x6DC) = *(s32 *)(o + 0x6FC) = 10;
        break;
    case 1:
        func_8008744C(o, b);
        func_80086DD4(o);
        break;
    case 2:
        break;
    case 3:
        *(s32 *)(*(u8 **)(o + 0x50) + 0x70) = 0;
        break;
    }
}

void *func_800882C8(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088214, 0x70C, 0xA4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 4;
    M2C_FIELD(temp_v0, void **, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = ((s32 (*)(s32)) *D_8004B44C)(M2C_FIELD(arg0, s32 *, 0x7C));
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008833C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008865C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008886C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80088A44);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800891A4);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008933C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800895C8);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80089BF0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008B3C8);

Obj *func_8008B4CC(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008B3C8, 0xFC, 0x90);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, void **, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008B520);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008B944);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008BB88);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008BD70);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008BE34);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008C02C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008C1C0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008C460);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008C954);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008D684);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008DDB0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008E744);

Obj *func_8008E8F8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008E744, 0x14C, 0x110);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x148) = func_8008C460;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008E94C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008ED04);

void func_8008EF48(u8 *o, u8 *b, s32 c) {
    if (c != 0) {
        (*(void (**)(u8 *, s32, s32))(*(u8 **)(b + 0xA0) + 0x114))(*(u8 **)(b + 0xA0), ((s32 (*)(s32))D_80044F4C[0])(D_8005CCA8[0] + 0xB0), 5);
        (*(void (**)(u8 *, s32, s32))(*(u8 **)(b + 0x9C) + 0x118))(*(u8 **)(b + 0x9C), 0, D_80048DA0[0]);
        (*(void (**)(u8 *, s32))(*(u8 **)(b + 0x9C) + 0x148))(*(u8 **)(b + 0x9C), 1);
    } else {
        (*(void (**)(u8 *, s32))(*(u8 **)(b + 0xA0) + 0x144))(*(u8 **)(b + 0xA0), 0);
        (*(void (**)(u8 *, s32))(*(u8 **)(b + 0x9C) + 0x144))(*(u8 **)(b + 0x9C), 0);
    }
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008F000);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008F0DC);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008F2B4);

void func_8008F4E8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        ((M2C_UNK (*)(s32, M2C_UNK)) *D_8009B5D8)(arg0 + 0x43C, 1);
        return;
    }
    ((M2C_UNK (*)(s32, M2C_UNK)) *D_8009B5D8)(arg0 + 0x43C, 0);
    func_8008F0DC(arg0, 0);
    func_8008F2B4(arg0, 0);
}

s32 func_8008F55C(s32 arg0) {
    return ((s32 (*)(s32)) *D_8009B5DC)(arg0 + 0x43C) != 0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008F584);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8008F8F0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80090264);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80091D18);

Obj *func_80091E4C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80091D18, 0x45C, 0xD4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80091E94);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80092094);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80092340);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80092524);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80092BC8);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80092FAC);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800934E0);

void *func_80093678(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800934E0, 0x70C, 0x6C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 3;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    if (arg2 != 0) {
        M2C_FIELD(temp_v0, s32 *, 0x60) = arg2;
    }
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
    return temp_v0;
}

void func_800936EC(u8 *o) {
    s32 k = *(s32 *)(o + 0x5C);
    s32 i;
    if (k == 0) {
        *(s32 *)(o + 0x68) = ((s32 (*)(s32, u8 *))D_80042BA4[0])(D_8009A890[0], o + 0x394);
        for (i = 0; i < *(s32 *)(o + 0x68); i++) {
            *(s16 *)(o + i * 2 + 0x6C) = *(s16 *)(o + i * 2 + 0x394);
        }
    } else {
        *(s32 *)(o + 0x68) = ((s32 (*)(s32, u8 *))D_80042BA4[0])(D_8009A890[k], o + 0x6C);
    }
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800937A4);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80093930);

s32 func_800939E8(s32 a, s32 k) {
    u8 buf[0x30];
    u8 c;

    ((void (*)(s32, u8 *))D_8004B468[0])(a, buf);
    {
        Rec18 *r = &D_80042BCA[k];
        c = r->b[0xC];
    }
    return (c << 6) + c * *(s16 *)(buf + 0x12) / 8;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80093A58);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80093E84);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80094144);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80094388);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80094558);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800946BC);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80094FBC);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80096380);

Obj *func_80096548(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80096380, 0x1F4, 0xB4);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80096590);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80096744);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80096988);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009744C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800980B0);

Obj *func_8009824C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800980B0, 0xF4, 0x8C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80098294);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80098450);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800986C0);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80098B84);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009913C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099324);

void func_80099430(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_8009943C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = 1;
}

void func_80099450(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_80099464(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009946C);

Obj *func_80099684(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8009946C, 0x9C, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x8C) = func_80099430;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x90) = func_8009943C;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x94) = func_80099450;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x98) = func_80099464;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800996EC);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_800997D4);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099894);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099A80);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099B6C);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099C64);

void func_80099D5C(void *arg0, s32 arg1) {
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

s32 func_80099DF0(Fade *f) {
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

void func_80099E5C(s32 *o, s32 a, s32 b, s32 n) {
    if (a != b) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        o[0] = n;
        o[3] = a << 8;
        o[2] = a;
        o[4] = b;
        o[6] = 1;
        o[5] = ((b - a) << 8) / o[0];
    }
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099EF0);

s32 func_80099F5C(s32 arg0, s32 arg1) {
    return D_8009AF40[(arg0 * 5) + arg1];
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099F84);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_80099FF8);

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009A1BC);

s32 func_8009A344(s32 bit, s32 m, s32 id) {
    u8 *p;
    if (id != -1) {
        p = *((u8 **(*)(s32))D_80042B98[0])(id);
        if (!((p[4] >> bit) & 1)) {
            return 0;
        }
        if (p[2] == 1) {
            if (m == 3) {
                return 0;
            }
        } else if (p[2] == 2) {
            if (m == 2) {
                return 0;
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009A3E8);

s32 func_8009A670(void) {
    if (D_80048D68[0] >= 0x2D7) {
        return -1;
    }
    return D_80048D68[0] >= 0x270;
}

s32 func_8009A698(void) {
    return D_8009B5FC[*(u8 *)D_80048D68] & 0x7F;
}

INCLUDE_ASM("asm/ovl/STSTATUS/nonmatchings/STSTATUS", func_8009A6B8);
