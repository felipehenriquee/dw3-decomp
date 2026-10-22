#include "WSTAG741.h"
#include "m2c.h"
#include "WSTAG741_auto.h"
#include "WSTAG741_data.h"

INCLUDE_ASM("asm/ovl/WSTAG741/nonmatchings/WSTAG741", func_800A5DE4);

Obj *func_800A606C(void) {
    return func_80014504(func_800A5DE4, 0x54, 0xC);
}

void func_800A6098(u8 *o, s32 *w) {
    u8 *f;

    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4084, 1) != 0
            && (*(s32 (**)(s32, s32))(f + 0x10))(0x4085, 0) != 0) {
            w[1] = func_800853F8(0x510);
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6138(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6098, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7290)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG741/nonmatchings/WSTAG741", func_800A6194);

INCLUDE_ASM("asm/ovl/WSTAG741/nonmatchings/WSTAG741", func_800A626C);

INCLUDE_ASM("asm/ovl/WSTAG741/nonmatchings/WSTAG741", func_800A6324);

Obj *func_800A64BC(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6324, 0x6C, 0);
    M2C_FIELD(temp_v0, s32 *, 0x54) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x58) = arg1;
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A6504(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4084, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A6550(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4085, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x8233, 1);
}

void func_800A659C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BA, 1);
}

void func_800A65C8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BB, 1);
}

void func_800A65F4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BC, 1);
}

void func_800A6620(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BD, 1);
}

void func_800A664C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BE, 1);
}

void func_800A6678(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40BF, 1);
}

void func_800A66A4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C0, 1);
}

void func_800A66D0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C1, 1);
}

void func_800A66FC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C2, 1);
}

void func_800A6728(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C3, 1);
}

void func_800A6754(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C4, 1);
}

void func_800A6780(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C5, 1);
}

void func_800A67AC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C6, 1);
}

void func_800A67D8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C7, 1);
}

void func_800A6804(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C8, 1);
}

void func_800A6830(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x40C9, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG741/nonmatchings/WSTAG741", func_800A685C);
