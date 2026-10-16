#include "WSTAG310.h"
#include "m2c.h"
#include "WSTAG310_auto.h"
#include "WSTAG310_data.h"

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A5E40);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A5F34);

void func_800A6084(void) {
    func_80014504(func_800A5F34, 0x60, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A60B0);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A61D0);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6598);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A65D4);

void func_800A660C(void) {
    func_80014504(func_800A61D0, 0x84, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6638);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6758);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6B1C);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6B58);

void func_800A6B90(void) {
    func_80014504(func_800A6758, 0x9C, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6BBC);

void *func_800A6D7C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6BBC, 0x54, 0x18);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A8CE4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6DD8);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6EF8);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A6FE8);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A70AC);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A72CC);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7338);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7458);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7540);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A7604);

void func_800A7894(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A7604, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg2;
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A78EC);

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A794C);

void func_800A7998(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4050, 1);
}

void func_800A79C4(void) {
    *D_8004B370 = 0x27;
}

INCLUDE_ASM("asm/ovl/WSTAG310/nonmatchings/WSTAG310", func_800A79D4);
