#include "WSTAG740.h"
#include "m2c.h"
#include "WSTAG740_auto.h"
#include "WSTAG740_data.h"

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A5DE4);

Obj *func_800A606C(void) {
    return func_80014504(func_800A5DE4, 0x54, 0xC);
}

extern struct opaque D_80048ABC;
/* estado 0: se as flags 0x403F (ligada) e 0x4040 (desligada) batem, cria o evento */
void func_800A6098(u8 *o, s32 *w) {
    u8 *f;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x403F, 1) != 0
            && (*(s32 (**)(s32, s32))(f + 0x10))(0x4040, 0) != 0) {
            w[0] = func_800853F8(0x321);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6138(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6098, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7234)();
    return temp_v0;
}

s32 func_800A6194(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 d = ((s32 (*)(void))D_8004DF9C[0])();
    if (d >= 5) {
        d = 4;
    }
    if (depth == 0) {
        st[1] -= d;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (e[0] == 0xFF) {
            return 0xFF;
        }
        func_800A6194(st, tbl, depth + 1);
    }
    return e[0];
}

void func_800A626C(u8 *o, s32 tex, s32 i) {
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

    func_8001F648(&g);
    g.fn74(0x140, 0x100);
    g.fn80(tex, 4);
    g.fn88(p[1]);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80099D8C), p[0], *(s32 *)(o + 0x54), *(s32 *)(o + 0x58));
}

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A6324);

Obj *func_800A64BC(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6324, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A6504(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A6550(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8488, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x4040, 1);
}

void func_800A659C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AA, 1);
}

void func_800A65C8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AB, 1);
}

void func_800A65F4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AC, 1);
}

void func_800A6620(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AD, 1);
}

void func_800A664C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AE, 1);
}

void func_800A6678(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AF, 1);
}

void func_800A66A4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B0, 1);
}

void func_800A66D0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B1, 1);
}

void func_800A66FC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B2, 1);
}

void func_800A6728(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B3, 1);
}

void func_800A6754(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B4, 1);
}

void func_800A6780(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B5, 1);
}

void func_800A67AC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B6, 1);
}

void func_800A67D8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B7, 1);
}

void func_800A6804(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B8, 1);
}

void func_800A6830(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B9, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A685C);
