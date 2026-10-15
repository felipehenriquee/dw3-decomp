#include "STGDGLAB.h"
#include "m2c.h"
#include "STGDGLAB_auto.h"
#include "STGDGLAB_data.h"

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80082F48);

void func_80083040(void) {
    func_80014504(func_80082F48, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008306C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800830F4);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80083238);

void func_800832EC(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083238, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x64) = func_8008306C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80083334);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80083484);

s32 func_80083550(s32 arg0, u32 arg1) {
    s32 var_s0;
    s32 var_s1;

    if (arg1 >= 4U) {
        return 0;
    }
    var_s0 = 0;
    var_s1 = 0;
    do {
        var_s1 += func_80083484(arg0, arg1, var_s0);
        var_s0 += 1;
    } while (var_s0 < 4);
    return var_s1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800835CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008365C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800841E4);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800842F4);

void *func_80085408(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800842F4, 0x29C, 0x1C);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, void **, 0x50) = arg0;
    M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x6C)(arg0);
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085470);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085730);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085C50);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80085DD0);

void func_80087018(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085DD0, 0x100, 0xA0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087070);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087248);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80087600);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008820C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_800885EC);

void func_80088694(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800885EC, 0x130, 0x60);
    M2C_FIELD(temp_v0, s32 *, 0xB4) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0xB8) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

void func_800886DC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = 2;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    ((M2C_UNK (*)(void *, M2C_UNK)) D_8008FD98)(arg0 + 0x94, 1);
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80088718);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80088808);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80088B5C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_80089AEC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A51C);

void func_8008A610(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008A51C, 0x11C, 0x4C);
    M2C_FIELD(temp_v0, s32 (**)(), 0x114) = func_800886DC;
    M2C_FIELD(temp_v0, s32 (**)(), 0x118) = func_80088718;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

void func_8008A670(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_8008A67C(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x7C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x80) = arg2;
    M2C_FIELD(arg0, s32 *, 0x78) = 1;
}

void func_8008A690(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x70) = arg2;
    M2C_FIELD(arg0, s32 *, 0x68) = 1;
}

void func_8008A6A4(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x74) = arg1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A6AC);

void func_8008A8C4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008A6AC, 0x9C, 0);
    M2C_FIELD(temp_v0, s32 (**)(), 0x8C) = func_8008A670;
    M2C_FIELD(temp_v0, s32 (**)(), 0x90) = func_8008A67C;
    M2C_FIELD(temp_v0, s32 (**)(), 0x94) = func_8008A690;
    M2C_FIELD(temp_v0, s32 (**)(), 0x98) = func_8008A6A4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008A92C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008AD18);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008AD98);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008B798);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C060);

void func_8008C230(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008C060, 0x108, 0x38);
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C278);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C4EC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008C960);

void func_8008D774(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008C960, 0xAC, 0x5C);
    M2C_FIELD(temp_v0, s32 *, 0x70) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x74) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x78) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = arg1;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008D7CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008D9BC);

void func_8008DFA0(void *arg0) {
    void *temp_a0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x24);
    ((M2C_UNK (*)(s32, M2C_UNK)) D_8008FD98)(arg0 + 0x80, 0);
    func_8008D9BC(arg0, temp_s1, 0);
    temp_a0 = M2C_FIELD(temp_s1, void **, 0x68);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x80)(temp_a0, 0);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 1);
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E018);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E4CC);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008E8D0);

void func_8008EABC(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008E8D0, 0x174, 0x70);
    M2C_FIELD(temp_v0, s32 (**)(), 0x170) = func_8008DFA0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 2;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x16C) = arg2;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008EB30);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008EC50);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008ED0C);

s32 func_8008EEA0(void *arg0) {
    void *temp_a0;

    temp_a0 = *M2C_FIELD(arg0, void ***, 0x24);
    if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x114)(temp_a0);
        return 1;
    }
    return 0;
}

s32 func_8008EEFC(void *arg0) {
    void *temp_a0;

    temp_a0 = *M2C_FIELD(arg0, void ***, 0x24);
    if ((temp_a0 != NULL) && (M2C_FIELD(temp_a0, s32 *, 0xC) == 1)) {
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x118)(temp_a0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008EF58);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008EF8C);

void func_8008EFD0(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008ED0C, 0x7C, 0xC);
    M2C_FIELD(temp_v0, s32 (**)(), 0x68) = func_8008EEA0;
    M2C_FIELD(temp_v0, s32 (**)(), 0x6C) = func_8008EEFC;
    M2C_FIELD(temp_v0, s32 (**)(), 0x70) = func_8008EF58;
    M2C_FIELD(temp_v0, s32 (**)(), 0x74) = func_8008EC50;
    M2C_FIELD(temp_v0, s32 (**)(), 0x78) = func_8008EF8C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
}

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F040);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F16C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F22C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F2C0);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F32C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F36C);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F3D8);

INCLUDE_ASM("asm/ovl/STGDGLAB/nonmatchings/STGDGLAB", func_8008F424);
