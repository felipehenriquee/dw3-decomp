#include "WSTAG295.h"
#include "m2c.h"
#include "WSTAG295_auto.h"
#include "WSTAG295_data.h"

INCLUDE_ASM("asm/ovl/WSTAG295/nonmatchings/WSTAG295", func_800A5DE0);

void *func_800A5EE0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6D44)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F3C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C1A, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x404D, 1);
}

void func_800A5F88(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4058, 1);
}

void func_800A5FB4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4059, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG295/nonmatchings/WSTAG295", func_800A5FE0);
