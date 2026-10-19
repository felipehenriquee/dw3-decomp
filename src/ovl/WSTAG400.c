#include "WSTAG400.h"
#include "m2c.h"
#include "WSTAG400_auto.h"
#include "WSTAG400_data.h"

INCLUDE_ASM("asm/ovl/WSTAG400/nonmatchings/WSTAG400", func_800A5DE4);

void *func_800A5E8C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE4, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A82A8)();
    return temp_v0;
}

void func_800A5EE8(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C4B, 1);
}

void func_800A5F14(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C4C, 1);
}

void func_800A5F40(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C4D, 1);
}

void func_800A5F6C(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1C4E, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F98(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1A27, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1A26, 0);
}

extern struct opaque D_80048ABC;
void func_800A5FE4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1A26, 0);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C4B, 0);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C4C, 0);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C4D, 0);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C4E, 0);
}

INCLUDE_ASM("asm/ovl/WSTAG400/nonmatchings/WSTAG400", func_800A606C);
