#include "STCRDSHP.h"
#include "m2c.h"
#include "STCRDSHP_auto.h"
#include "STCRDSHP_data.h"

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008300C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800832C8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800835B8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80083780);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80083BA8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800843C0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800844B8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800852CC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008536C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800853B4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008543C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085580);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085634);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085678);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085730);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085788);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800857B0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085BAC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085CD8);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085DA0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80085FDC);

void func_80086074(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    M2C_FIELD(arg1, s32 *, 0) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x88, 0x80);
    M2C_FIELD(arg1, s32 *, 4) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x115, 0x80);
    M2C_FIELD(arg1, s32 *, 8) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x126, 0x80);
    M2C_FIELD(arg1, s32 *, 0xC) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x115, 0xA6);
    M2C_FIELD(arg1, s32 *, 0x10) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x12C, 0xA6);
    M2C_FIELD(arg1, s32 *, 0x14) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x50, 0x97);
    M2C_FIELD(arg1, s32 *, 0x18) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xCE, 0x97);
    M2C_FIELD(arg1, s32 *, 0x1C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xF0, 0x97);
    M2C_FIELD(arg1, s32 *, 0x20) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xCE, 0xA4);
    M2C_FIELD(arg1, s32 *, 0x24) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xF0, 0xA4);
    M2C_FIELD(arg1, s32 *, 0x2C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 3, 0x117, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x28) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 3, 0x11A, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x30) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x12, 0x67);
    temp_v0 = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x121, 0x67);
    M2C_FIELD(arg1, s32 *, 0x34) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, s32), 0x15C)(temp_v0, M2C_FIELD(arg0, s32 *, 0x58));
    M2C_FIELD(arg1, s32 *, 0x38) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0x9A, 0x39);
    M2C_FIELD(arg1, s32 *, 0x3C) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC5, 0x56);
    M2C_FIELD(arg1, s32 *, 0x40) = func_8001AE38(M2C_FIELD(arg0, s16 *, 0x54), 1, 0xC5, 0x66);
    temp_v0_2 = func_8001B364(M2C_FIELD(arg0, s16 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) - 3, 0xB8, 0x56);
    M2C_FIELD(arg1, s32 *, 0x44) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_v0_2, 0);
}

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008627C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008674C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80086DC4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087A2C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087B84);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087BDC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087CD4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087D00);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087E8C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80087FAC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800880C4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008838C);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088AFC);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088B50);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088CA0);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088E24);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088EF4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80088FB4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80089048);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800890B4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_800890F4);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_80089160);

INCLUDE_ASM("asm/ovl/STCRDSHP/nonmatchings/STCRDSHP", func_8008923C);
