#include "WSTAG790.h"
#include "m2c.h"
#include "WSTAG790_auto.h"
#include "WSTAG790_data.h"

INCLUDE_ASM("asm/ovl/WSTAG790/nonmatchings/WSTAG790", func_800A5DF4);

void func_800A60D0(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x32C)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

u8 *func_800A6108(s32 unused) {
    return func_800143DC(func_800A5DF4, 112, 0, 809);
}

INCLUDE_ASM("asm/ovl/WSTAG790/nonmatchings/WSTAG790", func_800A6138);

void func_800A6224(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x32E)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

u8 *func_800A625C(s32 link) {
    return func_800143DC(func_800A6138, 0x5C, 0, link);
}

void func_800A628C(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[2] = func_800A6108(0x329);
        w[1] = func_800A625C(0x328);
        if (D_8004B370[0] == 1) {
            w[0] = func_800853F8(4);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A631C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A628C, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6980)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG790/nonmatchings/WSTAG790", func_800A6378);
