#include "WSTAG605.h"
#include "m2c.h"
#include "WSTAG605_auto.h"
#include "WSTAG605_data.h"

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5DE0);

void *func_800A5E68(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6850)();
    return temp_v0;
}

void func_800A5EC4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x8680, 1);
    *D_8004B370 = 0x12;
}

extern struct opaque D_80048ABC;
void func_800A5EF8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x40A6, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG605/nonmatchings/WSTAG605", func_800A5F44);
