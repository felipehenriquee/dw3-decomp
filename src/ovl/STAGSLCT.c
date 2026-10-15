#include "STAGSLCT.h"
#include "m2c.h"
#include "STAGSLCT_auto.h"
#include "STAGSLCT_data.h"

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_800849CC);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084A30);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084A5C);

void func_80084B2C(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x54) + arg1;
    M2C_FIELD(arg0, s32 *, 0x54) = temp_a1;
    if (temp_a1 < 0) {
        M2C_FIELD(arg0, s32 *, 0x54) = 0;
        return;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x5C) - M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_v1 < temp_a1) {
        M2C_FIELD(arg0, s32 *, 0x54) = temp_v1;
    }
}

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084B70);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084C94);

INCLUDE_RODATA("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", D_80082CB0);

INCLUDE_RODATA("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", D_800849A4);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80084D9C);

INCLUDE_ASM("asm/ovl/STAGSLCT/nonmatchings/STAGSLCT", func_80085EA4);
