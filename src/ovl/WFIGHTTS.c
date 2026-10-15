#include "WFIGHTTS.h"
#include "m2c.h"
#include "WFIGHTTS_auto.h"
#include "WFIGHTTS_data.h"

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A67B8);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A6A28);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A6B90);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A7A60);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A7A90);

void func_800A7FCC(s32 arg0, s32 *arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A7A90, 0x58, 0x70);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 **, 0x54) = arg1;
    *arg1 = 0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8018);

void func_800A8438(s32 arg0, s32 *arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A8018, 0x58, 0x3C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 **, 0x54) = arg1;
    *arg1 = 0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8484);

void func_800A8760(s32 arg0) {
    M2C_FIELD(func_80014504(func_800A8484, 0x54, 0x38), s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8798);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8CE8);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A8D34);

INCLUDE_ASM("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", func_800A931C);

INCLUDE_RODATA("asm/ovl/WFIGHTTS/nonmatchings/WFIGHTTS", D_800A5DF8);
