#include "WSTAG795.h"
#include "m2c.h"
#include "WSTAG795_auto.h"
#include "WSTAG795_data.h"

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A5F00);

void func_800A6180(void *arg0, s32 arg1) {
    if ((arg0 != NULL) && (arg1 == 0x35B)) {
        M2C_FIELD(arg0, s32 *, 0x50) = 1;
        M2C_FIELD(arg0, s16 *, 0x5C) = 0;
        M2C_FIELD(arg0, s16 *, 0x5E) = (s16) *D_800A6A2A;
        M2C_FIELD(arg0, M2C_UNK (**)(), 0x28)(arg0, 2);
    }
}

u8 *func_800A61D0(s32 arg0) {
    return func_800143DC(func_800A5F00, 104, 0, arg0);
}

void func_800A6200(void) {
    M2C_FIELD(func_80014504(func_800A5F00, 0x68, 0), s32 *, 0x54) = 1;
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6234);

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A637C);

Obj *func_800A654C(void) {
    return func_80014504(func_800A637C, 0x54, 4);
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6578);

void *func_800A6654(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6578, 0x54, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A7328)();
    return temp_v0;
}

void func_800A66B0(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x4043, 1);
}

extern struct opaque D_80048ABC;
void func_800A66DC(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x1C05, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x4063, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG795/nonmatchings/WSTAG795", func_800A6728);
