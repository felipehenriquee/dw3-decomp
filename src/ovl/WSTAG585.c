#include "WSTAG585.h"
#include "m2c.h"
#include "WSTAG585_auto.h"
#include "WSTAG585_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4033, 0) && (*(s32 (**)(s32, s32))(f + 0x10))(0x1C20, 1)) {
                w[0] = func_800853F8(0x1CC);
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E88(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6400)();
    return temp_v0;
}

void func_800A5EE4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4033, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG585/nonmatchings/WSTAG585", func_800A5F10);
