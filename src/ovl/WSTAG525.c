#include "WSTAG525.h"
#include "m2c.h"
#include "WSTAG525_auto.h"
#include "WSTAG525_data.h"

INCLUDE_ASM("asm/ovl/WSTAG525/nonmatchings/WSTAG525", func_800A5DE0);

void *func_800A5E80(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6DEC)();
    return temp_v0;
}

void func_800A5EDC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4003, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F08(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x402B, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F54(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x402C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8013, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG525/nonmatchings/WSTAG525", func_800A5FA0);
