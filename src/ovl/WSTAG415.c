#include "WSTAG415.h"
#include "m2c.h"
#include "WSTAG415_auto.h"
#include "WSTAG415_data.h"

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A5DF4);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A5EE8);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A5FA8);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6230);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6264);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A629C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A62D4);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A630C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6344);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A637C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A63B4);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A63EC);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6424);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A645C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6558);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A698C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6A98);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6ACC);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6B04);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6C8C);

void func_800A6E88(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x336)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x2C)(arg0, 1);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6EC0);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A6EFC);

void *func_800A6FC0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6EFC, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A77D8)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A701C);

INCLUDE_ASM("asm/ovl/WSTAG415/nonmatchings/WSTAG415", func_800A7068);
