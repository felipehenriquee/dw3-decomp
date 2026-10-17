#include "WSTAG740.h"
#include "m2c.h"
#include "WSTAG740_auto.h"
#include "WSTAG740_data.h"

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A5DE4);

Obj *func_800A606C(void) {
    return func_80014504(func_800A5DE4, 0x54, 0xC);
}

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A6098);

void *func_800A6138(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6098, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7234)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A6194);

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A626C);

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A6324);

void func_800A64BC(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6324, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
}

extern struct opaque D_80048ABC;
void func_800A6504(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403F, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A6550(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8488, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x4040, 1);
}

void func_800A659C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AA, 1);
}

void func_800A65C8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AB, 1);
}

void func_800A65F4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AC, 1);
}

void func_800A6620(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AD, 1);
}

void func_800A664C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AE, 1);
}

void func_800A6678(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40AF, 1);
}

void func_800A66A4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B0, 1);
}

void func_800A66D0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B1, 1);
}

void func_800A66FC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B2, 1);
}

void func_800A6728(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B3, 1);
}

void func_800A6754(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B4, 1);
}

void func_800A6780(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B5, 1);
}

void func_800A67AC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B6, 1);
}

void func_800A67D8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B7, 1);
}

void func_800A6804(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B8, 1);
}

void func_800A6830(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40B9, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG740/nonmatchings/WSTAG740", func_800A685C);
