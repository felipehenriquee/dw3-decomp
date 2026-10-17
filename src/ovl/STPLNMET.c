#include "STPLNMET.h"
#include "m2c.h"
#include "STPLNMET_auto.h"
#include "STPLNMET_data.h"

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80082F58);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80082FCC);

void func_80083118(void) {
    func_80014504(func_80082FCC, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083144);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083310);

void func_80083398(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

void func_800833A4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80083144, 0x84, 0);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x7C) = func_80083310;
    M2C_FIELD(temp_v0, s32 (**)(s32, s32, s32), 0x80) = func_80083398;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800833E8);

void func_800835C4(void) {
    func_80014504(func_800833E8, 0x68, 0);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800835F0);

void func_80083748(void) {
    func_80014504(func_800835F0, 0x68, 0);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083774);

void func_80083D38(s32 arg0) {
    M2C_FIELD(func_80014504(func_80083774, 0x5C, 8), s32 *, 0x50) = arg0;
}

void func_80083D70(void *arg0, s32 arg1) {
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

s32 func_80083E04(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80083E70);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80084060);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_8008438C);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80084D10);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80085A70);

void func_80085BB0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80085BBC);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80085C50);

void func_80085D50(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0xA;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80085D5C);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80085E10);

void func_80085ECC(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;

    temp_v0 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x20, 0x1A);
    M2C_FIELD(arg1, s32 *, 0) = temp_v0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0, 4);
    temp_v0_2 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x61, 0x42);
    M2C_FIELD(arg1, s32 *, 4) = temp_v0_2;
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_2, 1);
    temp_v0_3 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x40, 0x60);
    M2C_FIELD(arg1, s32 *, 8) = temp_v0_3;
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_3, 1);
    temp_v0_4 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x5A, 0xA9);
    M2C_FIELD(arg1, s32 *, 0xC) = temp_v0_4;
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_4, 1);
    temp_v0_5 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x6B, 0xB9);
    M2C_FIELD(arg1, s32 *, 0x14) = temp_v0_5;
    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_5, 1);
    temp_v0_6 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0x6B, 0xC7);
    M2C_FIELD(arg1, s32 *, 0x18) = temp_v0_6;
    M2C_FIELD(temp_v0_6, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_6, 1);
    temp_v0_7 = func_8001B364((s32) M2C_FIELD(arg0, s16 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) - 2, 0x5A, 0xB9);
    M2C_FIELD(arg1, s32 *, 0x1C) = temp_v0_7;
    M2C_FIELD(temp_v0_7, M2C_UNK (**)(s32, M2C_UNK), 0x88)(temp_v0_7, 1);
    temp_a0 = M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(temp_a0, M2C_UNK (**)(s32, M2C_UNK), 0x80)(temp_a0, 0);
    temp_v0_8 = func_8001AE38((s32) M2C_FIELD(arg0, s16 *, 0x54), 1, 0xE3, 0xA9);
    M2C_FIELD(arg1, s32 *, 0x10) = temp_v0_8;
    M2C_FIELD(temp_v0_8, M2C_UNK (**)(s32, M2C_UNK), 0x138)(temp_v0_8, 1);
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086074);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800862F0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800869C8);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086E40);

void func_80086EAC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = 0x32;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086EB8);

void func_80086F60(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80086EB8, 0xE4, 0x20);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0xDC) = func_80086E40;
    M2C_FIELD(temp_v0, s32 (**)(s32), 0xE0) = func_80086EAC;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80086FC0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087190);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087444);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087774);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800879E0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087A30);

void func_80087AC0(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80087A30, 0x8C, 0x30);
    M2C_FIELD(temp_v0, s32 (**)(s32, s32), 0x88) = func_800879E0;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x58) = 6;
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087B14);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087BF4);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80087C9C);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088070);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088138);

void func_800882A4(void) {
    void *temp_v0;

    temp_v0 = func_80014504(func_80088138, 0x6C, 0x28);
    M2C_FIELD(temp_v0, s32 *, 0x50) = 0x1001;
    M2C_FIELD(temp_v0, s32 *, 0x54) = 5;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_800882E0);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088398);

void func_80088438(void *arg0, s32 arg1) {
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

s32 func_800884CC(Fade *f) {
    if (f->active == 0) {
        return 1;
    }
    f->value += f->speed;
    if (f->speed > 0) {
        if (f->value > 0x1000) {
            f->value = 0x1000;
            f->active = 0;
            return 1;
        }
    } else if (f->value < 0) {
        f->value = 0;
        f->active = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088538);

INCLUDE_ASM("asm/ovl/STPLNMET/nonmatchings/STPLNMET", func_80088578);
