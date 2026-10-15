#include "STITSHOP.h"
#include "m2c.h"
#include "STITSHOP_auto.h"
#include "STITSHOP_data.h"

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008321C);

void func_80083318(void) {
    func_80014504(func_8008321C, 0x50, 4);
}

void func_80083344(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x10) = 1;
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    if (arg1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (0xFF00 / arg2);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF00;
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) -(0xFF00 / arg2);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800833CC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083510);

void func_800835C4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083510, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80083344;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
}

void func_8008360C(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xB9, 0x3A);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x103, 0x54);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x11E, 0x54);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0x9A, 0x2C);
    M2C_FIELD(arg1, s32 *, 0x18) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xC5, 0x49);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x58), 1, 0xC5, 0x59);
    temp_v0 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x58), M2C_FIELD(arg0, s32 *, 0x5C) - 1, 0xB8, 0x49);
    M2C_FIELD(arg1, s32 *, 0x20) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0, 0);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800836F8);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083810);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083970);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80083EB0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80085890);

void func_80085934(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 4);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x234)(temp_a0);
}

void func_8008596C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085890, 0xC8, 0x24);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x50) = func_80085934;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800859C0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80085B18);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80085F48);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800872F4);

void func_8008739C(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 4);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0x234)(temp_a0);
}

void func_800873D4(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800872F4, 0xCC, 0x38);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x50) = func_8008739C;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087428);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800875E0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087920);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087CFC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80087EC0);

void func_80088670(void *arg0, s32 arg1) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    if (arg1 != 0) {
        temp_a0 = M2C_FIELD(temp_s0, void **, 0x4C);
        M2C_FIELD(temp_a0, M2C_UNK (**)(void *, M2C_UNK), 0x88)(temp_a0, 7);
        temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x4C);
        M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, M2C_UNK), 0x94)(temp_a0_2, 1);
        M2C_FIELD(arg0, s32 *, 0x6B8) = 0;
        return;
    }
    temp_a0_3 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_3, M2C_UNK (**)(void *, M2C_UNK), 0x88)(temp_a0_3, 0);
    temp_a0_4 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_4, M2C_UNK (**)(void *, M2C_UNK), 0x94)(temp_a0_4, 0);
    M2C_FIELD(arg0, s32 *, 0x6B8) = 1;
}

void func_80088714(void *arg0, s32 arg1) {
    s32 temp_a3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x24);
    M2C_FIELD(arg0, s32 *, 0x6B8) = arg1;
    temp_a0 = M2C_FIELD(temp_s0, void **, 0x4C);
    temp_a3 = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x6BC) % (s32) M2C_FIELD(arg0, s32 *, 0x6D4)) / 2;
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, s32, s32, s32), 0x84)(temp_a0, ((M2C_FIELD(arg0, s32 *, 0x6BC) % 2) * 0x83) + 0x1D, (temp_a3 * 0xE) + 0x24, temp_a3);
    temp_a0_2 = M2C_FIELD(temp_s0, void **, 0x4C);
    M2C_FIELD(temp_a0_2, M2C_UNK (**)(void *, s32), 0x80)(temp_a0_2, arg1);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800887C4);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800887EC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088830);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088878);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800888E4);

void func_800889A8(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087EC0, 0x704, 0x50);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6E8) = func_800887C4;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6EC) = func_800887EC;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6F0) = func_80088830;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x6F4) = func_80088714;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x6F8) = func_80088670;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x6FC) = func_80088878;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x700) = func_800888E4;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0x60) = arg1;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088A64);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088DB8);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088E8C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80088F4C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_800890B0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089274);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089A44);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_80089E2C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A0D0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A1FC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A450);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008A758);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008ADEC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008AF68);

void func_8008B29C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x1E4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1E8) = arg2;
    if (M2C_FIELD(arg0, s32 *, 0x1F0) != 0) {
        func_80089E2C((s32) arg0, temp_s1, 1);
        if (M2C_FIELD(arg0, s32 *, 0x5C) == 0) {
            func_8008A0D0((s32) arg0, temp_s1, 1);
            return;
        }
        func_8008A0D0((s32) arg0, temp_s1, 0);
        func_8008A1FC((s32) arg0, temp_s1, 1);
    }
}

void func_8008B324(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10) == 3) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
    }
}

void func_8008B340(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), void **, 0x20);
    M2C_FIELD(temp_a0, M2C_UNK (**)(void *, s32), 0x144)(temp_a0, arg1 & 0xFF);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008B378);

void func_8008B430(void *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    func_80089E2C((s32) arg0, temp_s1, 1);
    func_80089274((s32) arg0, temp_s1, arg1);
}

void func_8008B484(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008AF68, 0x248, 0xAC);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x234) = func_8008B29C;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x238) = func_8008B324;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x23C) = func_8008B340;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0x240) = func_8008B378;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x244) = func_8008B430;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x1E4) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x1E8) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x1F0) = 1;
}

void func_8008B524(void *arg0, void *arg1) {
    s32 temp_v0;

    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xD3, 0xCC);
    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0x1D, 0x14);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 3, 0x117, 0x17);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 3, 0x11A, 0x17);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xBE, 0x2F);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x50), 1, 0xBE, 0x3D);
    temp_v0 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x50), 0, 0xB0, 0x2F);
    M2C_FIELD(arg1, s32 *, 0x18) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0, 0);
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008B60C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008B908);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008BFB0);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C0C4);

void *func_8008C118(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008BFB0, 0xAC, 0x24);
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xA8) = func_8008C0C4;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x60) = ((s32 (*)()) D_8004B43C)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C17C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C238);

void func_8008C2DC(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = 1;
    if (arg1 != 0) {
        ((void (*)(s32))D_80055C48[0])(0x40019);
        M2C_FIELD(arg0, s32 *, 4) = 0x1000 / M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 8) = 0;
    } else {
        ((void (*)(s32))D_80055C48[0])(0x4001A);
        M2C_FIELD(arg0, s32 *, 8) = 0x1000;
        M2C_FIELD(arg0, s32 *, 4) = -((0x1000 / M2C_FIELD(arg0, s32 *, 0)) * 2);
    }
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C370);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C3DC);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C41C);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C488);

s32 func_8008C4CC(s32 arg0, M2C_UNK arg1) {
    return ((s32) M2C_FIELD(*((void **(*)(M2C_UNK)) D_80042B98)(arg1), u8 *, 4) >> arg0) & 1;
}

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C510);

INCLUDE_ASM("asm/ovl/STITSHOP/nonmatchings/STITSHOP", func_8008C800);
