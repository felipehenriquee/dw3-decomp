#include "WSTAG580.h"
#include "m2c.h"
#include "WSTAG580_auto.h"
#include "WSTAG580_data.h"

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A5DE0);

void *func_800A5EA8(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7368)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A5F04(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x403C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C1F, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F50(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4021, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C20, 1);
}

extern struct opaque D_80048ABC;
void func_800A5F9C(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4034, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C22, 1);
}

extern struct opaque D_80048ABC;
void func_800A5FE8(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4035, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C23, 1);
}

extern struct opaque D_80048ABC;
void func_800A6034(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4036, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C24, 1);
}

extern struct opaque D_80048ABC;
void func_800A6080(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4037, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1C25, 1);
}

void func_800A60CC(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4038, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG580/nonmatchings/WSTAG580", func_800A60F8);
