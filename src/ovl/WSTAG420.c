#include "WSTAG420.h"
#include "m2c.h"
#include "WSTAG420_auto.h"
#include "WSTAG420_data.h"

INCLUDE_ASM("asm/ovl/WSTAG420/nonmatchings/WSTAG420", func_800A5DE0);

void *func_800A5E74(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7E5C)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5ED0(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4012, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7401, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG420/nonmatchings/WSTAG420", func_800A5F1C);

INCLUDE_ASM("asm/ovl/WSTAG420/nonmatchings/WSTAG420", func_800A5F74);
