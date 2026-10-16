#include "WSTAG795.h"
#include "m2c.h"
#include "WSTAG795_auto.h"
#include "WSTAG795_data.h"

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A5F00);

void func_800A6180(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35B)) {
        M2C_FIELD(arg0, s32 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x5C) = 0;
        M2C_FIELD(arg0, s16 *, 0x5E) = (s16) *D_800A6A2A;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A61D0);

void func_800A6200(void) {
    M2C_FIELD(func_80014504(func_800A5F00, 0x68, 0), s32 *, 0x54) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6234);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A637C);

void func_800A654C(void) {
    func_80014504(func_800A637C, 0x54, 4);
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6578);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6654);

void func_800A66B0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4043, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A66DC);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6728);
