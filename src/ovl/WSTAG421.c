#include "WSTAG421.h"
#include "m2c.h"
#include "WSTAG421_auto.h"
#include "WSTAG421_data.h"

INCLUDE_ASM("asm/ovl/WSTAG421/nonmatchings/WSTAG421", func_800A5DE0);

void *func_800A5F1C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F6C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F78(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x40A3, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5FC4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8016, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40A7, 1);
}

void func_800A6010(void) {
    *D_8004B370 = 0x1C;
}

INCLUDE_ASM("asm/ovl/WSTAG421/nonmatchings/WSTAG421", func_800A6020);
