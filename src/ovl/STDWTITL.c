#include "STDWTITL.h"
#include "m2c.h"
#include "STDWTITL_auto.h"
#include "STDWTITL_data.h"

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80082D70);

void func_80082E9C(void) {
    func_80014504(func_80082D70, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80082EC8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083028);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083054);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800831E8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800833AC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800833E4);

void func_80083438(void) {
    ResetGraph(1);
    ClearImage2(&D_80087C90, 0, 0, 0);
    DrawSync(0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083478);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083500);

void func_80083568(s32 arg0, M2C_UNK arg1) {
    func_8008714C(0);
    func_800873E8(arg1);
    StSetRing(D_8008924C, 0x20);
    StSetStream(1, 1, -1, 0, 0);
    func_80083500(arg0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800835D4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800836D8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083760);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800838B0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083944);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083C70);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083CC0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083F48);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80083F80);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800840A8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800841E0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084218);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008426C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800843A4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800844E8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008453C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084628);

void func_8008483C(void) {
    func_80014504(func_80084628, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084868);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800848EC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008497C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800849D8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084A70);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084BB0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084BE8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084C3C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084CD4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084DF0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084E44);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80084EDC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008503C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085074);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800850C8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085160);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008529C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800852F0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085594);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085BE4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085C1C);

s16 func_80085C5C(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x52);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085C68);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085CD4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085D64);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085F0C);

s32 func_80085F38(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x50);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80085F44);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086018);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008605C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086108);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086228);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086544);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800867A8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800867E0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086834);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800869D0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086C70);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086DB0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80086DF8);

void func_80086FA0(void *arg0, s32 arg1) {
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

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087034);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800870A0);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800870E0);

void func_8008714C(s32 arg0) {
    if (arg0 == 0) {
        ResetCallback();
    }
    func_8008740C(arg0);
}

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087180);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008720C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800872A4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087320);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087340);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008737C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873C4);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800873E8);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008740C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800874FC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008758C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087618);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800876AC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087740);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087758);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_800877DC);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_8008780C);

INCLUDE_ASM("asm/ovl/STDWTITL/nonmatchings/STDWTITL", func_80087B5C);
