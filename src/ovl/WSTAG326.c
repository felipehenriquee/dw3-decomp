#include "WSTAG326.h"
#include "m2c.h"
#include "WSTAG326_auto.h"
#include "WSTAG326_data.h"

INCLUDE_ASM("asm/ovl/WSTAG326/nonmatchings/WSTAG326", func_800A5DE0);

u8 *func_800A5F60(s32 arg0) {
    return func_800143DC(func_800A5DE0, 80, 0, arg0);
}

void func_800A5F90(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35A)) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

INCLUDE_ASM("asm/ovl/WSTAG326/nonmatchings/WSTAG326", func_800A5FC8);

void *func_800A6068(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FC8, 0x54, 8);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A68F4)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A60C4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4076, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x7400, 1);
}

extern struct opaque D_80048ABC;
void func_800A6110(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x4077, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x802A, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG326/nonmatchings/WSTAG326", func_800A615C);
