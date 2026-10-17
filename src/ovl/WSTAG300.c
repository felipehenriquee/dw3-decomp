#include "WSTAG300.h"
#include "m2c.h"
#include "WSTAG300_auto.h"
#include "WSTAG300_data.h"

INCLUDE_ASM("asm/ovl/WSTAG300/nonmatchings/WSTAG300", func_800A5DE0);

void *func_800A5ED8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7108)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG300/nonmatchings/WSTAG300", func_800A5F34);

extern struct opaque D_80048ABC;
void func_800A5F94(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x404B, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7402, 1);
}

void func_800A5FE0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x404C, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG300/nonmatchings/WSTAG300", func_800A600C);
