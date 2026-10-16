#include "WSTAG306.h"
#include "m2c.h"
#include "WSTAG306_auto.h"
#include "WSTAG306_data.h"

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A5EB8);

void func_800A6018(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x335)) {
        M2C_FIELD(arg0, s16 *, 0x50) = ((s16 (*)(M2C_UNK)) *D_80055C48)(0xA0042FCB);
        M2C_FIELD(arg0, s16 *, 0x58) = 0;
        M2C_FIELD(arg0, u16 *, 0x5A) = (u16) *D_800A673A;
        M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x2C)(arg0, 1);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A6084);

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A60B4);

void *func_800A6160(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A60B4, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C18)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG306/nonmatchings/WSTAG306", func_800A61BC);
