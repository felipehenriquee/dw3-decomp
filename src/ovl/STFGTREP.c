#include "STFGTREP.h"
#include "m2c.h"
#include "STFGTREP_auto.h"
#include "STFGTREP_data.h"

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80082E70);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80082F6C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80082F98);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083020);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083164);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083218);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083260);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083404);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083744);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083D9C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80083E74);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800848E4);

void func_80084A08(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
}

void func_80084A14(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xB;
}

void func_80084A20(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0x14;
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084A2C);

void func_80084AE0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084AEC);

void func_80084B98(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 3, 0x42, 0x17);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 3, 0x45, 0x17);
    temp_v0 = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x50), 1, 0x14, 0xC2);
    M2C_FIELD(arg1, s32 *, 8) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x160)(temp_v0, 2);
}

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084C20);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80084EC4);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800857F0);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085B24);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085B60);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085C08);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085C90);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085D24);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085D90);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085DD0);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80085E3C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086184);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_8008634C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_800865C0);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_8008670C);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086844);

INCLUDE_ASM("asm/ovl/STFGTREP/nonmatchings/STFGTREP", func_80086924);
