#include "STCRDABM.h"
#include "m2c.h"
#include "STCRDABM_auto.h"
#include "STCRDABM_data.h"

void func_80082D88(void *arg0, s32 arg1, s32 arg2) {
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

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80082E10);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80082F54);

void func_80083008(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80082F54, 0x68, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x64) = func_80082D88;
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1000;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0;
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_8008304C);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083114);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_8008314C);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083174);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800835BC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083734);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083780);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083848);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083A78);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083AD8);

void func_80083BD0(void) {
    func_80014504(func_80083AD8, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083BFC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80083E14);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800840AC);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084500);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084BC8);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80084C38);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80085540);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_8008566C);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800856A8);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800857A0);

void func_800858A0(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_80085934);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800859A0);

INCLUDE_ASM("asm/ovl/STCRDABM/nonmatchings/STCRDABM", func_800859E0);
