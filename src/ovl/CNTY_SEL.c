#include "CNTY_SEL.h"
#include "m2c.h"
#include "CNTY_SEL_auto.h"
#include "CNTY_SEL_data.h"

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082CE8);

/* limpa a tela, cria o objeto da selecao de pais e toca o som 0x21 */
Obj *func_80082E8C(void) {
    Obj *o;

    ClearImage2(D_800843C8, 0, 0, 0);
    o = func_80014504(func_80082CE8, 0x50, 4);
    ((void (*)(s32))D_80055C54[0])(0x21);
    return o;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082EF0);

/* n (0-29) para 0-254; 30 ou mais da 0xFF */
s32 func_80082FC4(s32 n) {
    if (n >= 30) {
        return 0xFF;
    }
    return n * 255 / 30;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083000);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083184);

Obj *func_800832D8(void) {
    return func_80014504(func_80083184, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083304);

void func_800833DC(u8 *o) {
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

    func_8001F648(&g);
    g.fn7C(0x100, 1);
    g.fn74(0x280, 0);
    g.fn88(*(s16 *)(o + 0x56));
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), *(s16 *)(o + 0x54) + 4, 0, 0);
}

void func_80083474(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_8008347C);

void func_80083594(void) {
    M2C_FIELD(func_80014504(func_8008347C, 0x60, 0), void (**)(void *, s16), 0x5C) = func_80083474;
}

s32 func_800835CC(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_800843EC[k].len) {
        return D_800843EC[k].to;
    }
    return D_800843EC[k].from + (D_800843EC[k].to - D_800843EC[k].from) * t / D_800843EC[k].len;
}

void func_80083630(u8 *o) {
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
    g.fn94(0x94, 0);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 2, 0x94, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_800836DC);

Obj *func_80083804(void) {
    return func_80014504(func_800836DC, 0x58, 0);
}

/* valor do trecho k no tempo o[0x52] (interpolacao linear) */
s32 func_80083830(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_800843FC[k].len) {
        return D_800843FC[k].to;
    }
    return D_800843FC[k].from + (D_800843FC[k].to - D_800843FC[k].from) * t / D_800843FC[k].len;
}

void func_80083894(u8 *o) {
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
    g.fn94(0x140, 0x14);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 1, 0x140, 0x14);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083940);

Obj *func_80083A68(void) {
    return func_80014504(func_80083940, 0x58, 0);
}

/* valor do trecho k no tempo o[0x52] (interpolacao linear) */
s32 func_80083A94(u8 *o, s32 k) {
    s32 t = *(s16 *)(o + 0x52);

    if (t >= D_8008440C[k].len) {
        return D_8008440C[k].to;
    }
    return D_8008440C[k].from + (D_8008440C[k].to - D_8008440C[k].from) * t / D_8008440C[k].len;
}

void func_80083B00(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
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
    g.fn78(0, 0x1F0);
    g.fn94(0, 0x9E);
    g.fn8C(*(s16 *)(o + 0x54), *(s16 *)(o + 0x56), 0x1000);
    g.fn84(((s32 (*)(s32))D_80044F5C[0])(0x8A30000), 3, 0, 0x9E);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083BC0);

Obj *func_80083CEC(void) {
    return func_80014504(func_80083BC0, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083D18);

Obj *func_80084394(void) {
    return func_80014504(func_80083D18, 0x54, 0x14);
}
