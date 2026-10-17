#include "STDGNAME.h"
#include "m2c.h"
#include "STDGNAME_auto.h"
#include "STDGNAME_data.h"

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80082F8C);

void func_80083084(void) {
    func_80014504(func_80082F8C, 0x50, 4);
}

void func_800830B0(void *arg0, s32 arg1, s32 arg2) {
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

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083138);

void func_8008327C(u8 *a) {
    s32 v;

    switch (*(s32 *)(a + 0xC)) {
    case 0:
    default:
        (*(void (**)(void *))(a + 0x38))(a);
        break;
    case 1:
        if (*(s32 *)(a + 0x10) == 0) {
            break;
        }
        v = *(s32 *)(a + 0x5C) + *(s32 *)(a + 0x60);
        *(s32 *)(a + 0x5C) = v;
        if (*(s32 *)(a + 0x58) == 0) {
            if (v > 0xFF00) {
                *(s32 *)(a + 0x5C) = 0xFF00;
                *(s32 *)(a + 0xC) = 2;
            }
        } else if (v < 0) {
            *(s32 *)(a + 0x5C) = 0;
            *(s32 *)(a + 0xC) = 2;
        }
    case 2:
        func_80083138(a);
    case 3:
        break;
    }
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_80083330);

void func_80083378(void *arg0, s32 arg1) {
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

void func_80086144(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80085DE4, 0xE0, 0x28);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1000;
}

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

void func_800865B0(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_8008645C, 0x6C, 0x10);
    M2C_FIELD(temp_v0, void (**)(void *), 0x68) = func_8008656C;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
}

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800865F0);

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800866AC);

void func_80086730(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/STDGNAME/nonmatchings/STDGNAME", func_800867C4);
