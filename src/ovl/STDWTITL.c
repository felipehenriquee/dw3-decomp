#include "STDWTITL.h"
#include "m2c.h"
#include "STDWTITL_auto.h"
#include "STDWTITL_data.h"

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80082D70);

Obj *func_80082E9C(void) {
    return func_80014504(func_80082D70, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80082EC8);

Obj *func_80083028(void) {
    return func_80014504(func_80082EC8, 0x50, 0xC);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083054);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800831E8);

void func_800833AC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_800833E4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800831E8, 0x7C, 0);
    M2C_FIELD(temp_v0, void (**)(void *), 0x78) = func_800833AC;
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x6C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80083438(void) {
    ResetGraph(1);
    ClearImage2(&D_80087C90, 0, 0, 0);
    DrawSync(0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083478);

/* posiciona o CD em pos e le em velocidade dupla ate conseguir */
void func_80083500(s32 pos) {
    u8 mode = 0x80;

    do {
        while (CdControl(2, pos, 0) == 0) {
        }
        while (CdControl(0xE, &mode, 0) == 0) {
        }
    } while (CdRead2(0x1E0) == 0);
}

void func_80083568(s32 arg0, M2C_UNK arg1) {
    func_8008714C(0);
    func_800873E8(arg1);
    StSetRing(D_8008924C, 0x20);
    StSetStream(1, 1, -1, 0, 0);
    func_80083500(arg0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800835D4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800836D8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083760);

void func_800838B0(TitlBlink *o) {
    volatile s32 c = 0x800000;
    while (o->done == 0) {
        c--;
        if (c == 0) {
            o->done = 1;
            o->sel = o->sel == 0;
            o->x = o->pt[o->sel].x;
            o->y = o->pt[o->sel].y;
        }
    }
    o->done = 0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083944);

Obj *func_80083C70(s32 a, s32 b) {
    Obj *o = func_80014504(func_80083944, 0x54, 0);

    D_80089268[0] = a;
    D_8008926C[0] = b;
    return o;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083CC0);

void func_80083F48(s32 arg0) {
    M2C_FIELD(func_80014504(func_80083CC0, 0x58, 4), s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083F80);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800840A8);

void func_800841E0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80084218(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800840A8, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_800841E0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008426C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800843A4);

Obj *func_800844E8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800843A4, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_800841E0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008453C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084628);

Obj *func_8008483C(void) {
    return func_80014504(func_80084628, 0x54, 0);
}

void func_80084868(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0x10)) {
    case 0:
    default:
        w[0] = (s32)func_80086DB0((s32)o);
        (*(s32 *)(o + 0x10))++;
        break;
    case 1:
        if (w[0] == 0) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
        }
        break;
    }
}

void func_800848EC(u8 *o, s32 a) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (((s32 (*)(void))D_80055C60[0])() == 0) {
            (*(void (**)(u8 *))(o + 0x38))(o);
            ((void (*)(void))D_80088238[0])();
        }
        break;
    case 1:
        func_80084868(o, a);
        break;
    case 2:
    case 3:
        break;
    }
}

void *func_8008497C(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800848EC, 0x58, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 2;
    ((M2C_UNK (*)(M2C_UNK)) *D_80055C54)(0x47);
    return temp_v0;
}

void func_800849D8(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 1, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084A70);

void func_80084BB0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80084BE8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084A70, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_80084BB0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80084C3C(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 1, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084CD4);

Obj *func_80084DF0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084CD4, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_80084BB0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_80084E44(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 0, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084EDC);

void func_8008503C(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

Obj *func_80085074(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80084EDC, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_8008503C;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

void func_800850C8(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        u8 pad88[0xA0 - 0x88];
    } g;

    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x60), 0);
    g.fn78(0, 0x1F0);
    g.fn74(0x280, 0x100);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80088234), 0, *(s32 *)(o + 0x58), *(s32 *)(o + 0x5C));
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085160);

Obj *func_8008529C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085160, 0x74, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x70) = func_8008503C;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800852F0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085594);

void func_80085BE4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

void func_80085C1C(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v1 == 1) {
        M2C_FIELD(arg0, s16 *, 0x5A) = 2;
        M2C_FIELD(arg0, s8 *, 0x58) = (s8) temp_v1;
        M2C_FIELD(arg0, s16 *, 0x54) = 0;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 2);
    }
}

s16 func_80085C5C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x52);
}

Obj *func_80085C68(s16 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085594, 0xA8, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x9C) = func_80085BE4;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xA0) = func_80085C1C;
    M2C_FIELD(temp_v0, s16 (**)(void *), 0xA4) = func_80085C5C;
    M2C_FIELD(temp_v0, s32 *, 0x8C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x90) = 2;
    M2C_FIELD(temp_v0, s16 *, 0x50) = arg0;
    return temp_v0;
}

s32 func_80085CD4(s32 arg0) {
    if (arg0 >= 0x1E) {
        return 0xFF;
    }
    return (((s32) (rsin((arg0 << 0xA) / 30) * 0x1E) / 4096) * 0xFF) / 30;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085D64);

void func_80085F0C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
}

s32 func_80085F38(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x50);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085F44);

Obj *func_80086018(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085F44, 0x60, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x58) = func_80085F0C;
    M2C_FIELD(temp_v0, s32 (**)(void *), 0x5C) = func_80085F38;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008605C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086108);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086228);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086544);

void func_800867A8(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 1) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

Obj *func_800867E0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086544, 0x98, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x94) = func_800867A8;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x80) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086834);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800869D0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086C70);

Obj *func_80086DB0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086C70, 0x13C, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086DF8);

void func_80086FA0(void *arg0, s32 arg1) {
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

s32 func_80087034(Fade *f) {
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

void func_800870A0(Lerp *l, s32 from, s32 to, s32 n) {
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

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800870E0);

void func_8008714C(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    func_8008740C(arg0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087180);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008720C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800872A4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087320);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087340);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008737C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873C4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873E8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008740C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800874FC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008758C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087618);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800876AC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087740);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087758);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800877DC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008780C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087B5C);
