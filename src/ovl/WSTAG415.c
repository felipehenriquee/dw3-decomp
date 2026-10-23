#include "WSTAG415.h"
#include "m2c.h"
#include "WSTAG415_auto.h"
#include "WSTAG415_data.h"

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A5DF4);

void func_800A5EE8(u8 *o, s32 tex) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        void (*fn78)(s32, s32);
        u8 pad7C[4];
        void (*fn80)(s32, s32);
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;

    if (*(s32 *)(o + 0xC) == 1) {
        func_8001F648(&g);
        g.fn74(0x140, 0x100);
        g.fn80(tex, 4);
        g.fn88(0);
        g.fn78(0, 0x1F0);
        g.fn84(((s32 (*)(s32))D_80044F5C[0])(D_80099D8C), *(s32 *)(o + 0x50), *(s32 *)(o + 0x54), *(s32 *)(o + 0x58));
    }
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A5FA8);

u8 *func_800A6230(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 0;
    return o;
}

u8 *func_800A6264(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 1;
    return o;
}

u8 *func_800A629C(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 2;
    return o;
}

u8 *func_800A62D4(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 3;
    return o;
}

u8 *func_800A630C(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 4;
    return o;
}

u8 *func_800A6344(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 5;
    return o;
}

u8 *func_800A637C(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 6;
    return o;
}

u8 *func_800A63B4(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 7;
    return o;
}

u8 *func_800A63EC(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 8;
    return o;
}

u8 *func_800A6424(s32 arg0) {
    u8 *o = func_800143DC(func_800A5FA8, 116, 0, arg0);

    *(s32 *)(o + 0x4) = 9;
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A645C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6558);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A698C);

u8 *func_800A6A98(s32 arg0) {
    u8 *o = func_800143DC(func_800A6558, 120, 0, arg0);

    *(s32 *)(o + 0x4) = 0;
    return o;
}

u8 *func_800A6ACC(s32 arg0) {
    u8 *o = func_800143DC(func_800A6558, 120, 0, arg0);

    *(s32 *)(o + 0x4) = 1;
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6B04);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6C8C);

void func_800A6E88(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x336)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

u8 *func_800A6EC0(s32 v) {
    u8 *o = func_800143DC(func_800A6C8C, 0x60, 0, 0x32C);

    *(s32 *)(o + 4) = v;
    return o;
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6EFC);

void *func_800A6FC0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6EFC, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A77D8)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A701C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4018, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A7068);
