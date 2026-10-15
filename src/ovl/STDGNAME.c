#include "STDGNAME.h"
#include "m2c.h"
#include "STDGNAME_auto.h"
#include "STDGNAME_data.h"

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80082F8C);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083084);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800830B0);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083138);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008327C);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083330);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083378);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008340C);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083478);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083668);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083994);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80084318);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085078);

void func_800851B8(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800851C4);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085258);

void func_80085358(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xA;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085364);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085420);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008559C);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085B70);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80085DE4);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086144);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086184);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086368);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_8008645C);

void func_8008656C(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    temp_v0 = func_80083330();
    M2C_FIELD(temp_s0, void **, 8) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x64)(temp_v0, 0, 0x1E);
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800865B0);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800865F0);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800866AC);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80086730);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800867C4);
