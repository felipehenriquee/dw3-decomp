#include "WSTAG606.h"
#include "m2c.h"
#include "WSTAG606_auto.h"
#include "WSTAG606_data.h"

INCLUDE_ASM("asm/ovl/WSTAG606/nonmatchings/WSTAG606", func_800A5DE0);

void *func_800A5E80(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A681C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5EDC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407E, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F28(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x407F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8B0E, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG606/nonmatchings/WSTAG606", func_800A5F74);
