#include "WSTAG481.h"
#include "m2c.h"
#include "WSTAG481_auto.h"
#include "WSTAG481_data.h"

INCLUDE_ASM("asm/ovl/WSTAG481/nonmatchings/WSTAG481", func_800A5DF8);

INCLUDE_ASM("asm/ovl/WSTAG481/nonmatchings/WSTAG481", func_800A5F84);

Obj *func_800A6164(void) {
    return func_80014504(func_800A5F84, 0x78, 0);
}

void func_800A6190(u8 *o, Obj **out) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *out = func_800A6164();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A61F4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6190, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6FB0)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG481/nonmatchings/WSTAG481", func_800A6250);
