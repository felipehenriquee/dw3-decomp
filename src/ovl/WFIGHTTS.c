#include "WFIGHTTS.h"
#include "m2c.h"
#include "WFIGHTTS_auto.h"
#include "WFIGHTTS_data.h"

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A67B8);

void func_800A6A28(void) {
    struct {
        u8 pad0[0x20];
        void (*fn20)(s32);
        void (*fn24)(s32, s32);
        u8 pad28[4];
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *f;

    func_8001FFA8(&g);
    g.fn24(0x200, 0);
    f = (u8 *)D_80044B38;
    g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x4560001));
    g.fn24(0, 0xF4);
    g.fn20((*(s32 (**)(s32))(f + 0x424))(0x4560000));
    g.fn24(0x140, 0x100);
    g.fn2C((*(s32 (**)(s32))(f + 0x414))(0x79E));
    g.fn24(0x1C0, 0x100);
    g.fn2C((*(s32 (**)(s32))(f + 0x414))(0x7AE));
    g.fn24(0x200, 0x100);
    g.fn2C((*(s32 (**)(s32))(f + 0x414))(0x7E1));
    g.fn24(0x240, 0x100);
    g.fn2C((*(s32 (**)(s32))(f + 0x414))(0x7E3));
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A6B90);

u8 *func_800A7A60(void) {
    return func_800143DC(func_800A6B90, 0, 0, 0);
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A7A90);

void func_800A7FCC(s32 arg0, s32 *arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A7A90, 0x58, 0x70);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 **, 0x54) = arg1;
    *arg1 = 0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8018);

void func_800A8438(s32 arg0, s32 *arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A8018, 0x58, 0x3C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 **, 0x54) = arg1;
    *arg1 = 0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8484);

void func_800A8760(s32 arg0) {
    M2C_FIELD(func_80014504(func_800A8484, 0x54, 0x38), s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8798);

u8 *func_800A8CE8(s32 arg0, s32 arg1) {
    u8 *o = func_800143DC(func_800A8798, 600, 112, 65535);

    *(s32 *)(o + 0x250) = arg0;
    *(s32 *)(o + 0x254) = arg1;
    return o;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8D34);

u8 *func_800A931C(s32 arg0, s32 arg1) {
    u8 *o = func_800143DC(func_800A8D34, 256, 112, 65535);

    *(s32 *)(o + 0xF8) = arg0;
    *(s32 *)(o + 0xFC) = arg1;
    return o;
}

INCLUDE_RODATA("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", D_800A5DF8);
