#include "WSTAG395.h"
#include "m2c.h"
#include "WSTAG395_auto.h"
#include "WSTAG395_data.h"

INCLUDE_ASM("asm/ovl/WSTAG395/nonmatchings/WSTAG395", func_800A5DE0);

void *func_800A5EB8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A731C)();
    return temp_v0;
}

void func_800A5F14(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4011, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F40(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8004, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1A28, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C08, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG395/nonmatchings/WSTAG395", func_800A5FA0);
