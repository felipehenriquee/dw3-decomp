#include "WSTAG311.h"
#include "m2c.h"
#include "WSTAG311_auto.h"
#include "WSTAG311_data.h"

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A5E40);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A5F34);

void func_800A6084(void) {
    func_80014504(func_800A5F34, 0x60, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A60B0);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A61D0);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6594);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6604);

void func_800A6634(void) {
    func_80014504(func_800A61D0, 0x84, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6660);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6780);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6B44);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6BB4);

void func_800A6BE4(void) {
    func_80014504(func_800A6780, 0x84, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6C10);

void *func_800A6DD0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6C10, 0x54, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A8B18)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6E2C);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A6F4C);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A7034);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A70F8);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A7388);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A73E4);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A7460);

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A74C0);

void func_800A750C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x405F, 1);
}

void func_800A7538(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4060, 1);
}

void func_800A7564(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x406C, 1);
}

void func_800A7590(void) {
    *D_8004B370 = 0x28;
}

INCLUDE_ASM("asm/ovl/WSTAG311/nonmatchings/WSTAG311", func_800A75A0);
