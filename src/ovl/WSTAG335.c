#include "WSTAG335.h"
#include "m2c.h"
#include "WSTAG335_auto.h"
#include "WSTAG335_data.h"

/* estado 0: espera curta (laco vazio) e passa ao estado 1 */
void func_800A5DE4(u8 *o) {
    s32 i;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (i = 13; i >= 0; i--) {
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5E3C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 0x38);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6F1C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG335/nonmatchings/WSTAG335", func_800A5E98);
