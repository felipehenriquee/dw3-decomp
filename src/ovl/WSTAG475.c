#include "WSTAG475.h"
#include "m2c.h"
#include "WSTAG475_auto.h"
#include "WSTAG475_data.h"

void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 8) {
            {
                u8 *f = (u8 *)&D_80048ABC;
                if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1A17, 0) && (*(s32 (**)(s32, s32))(f + 0x10))(0x1C43, 1)) { w[0] = func_800853F8(0xB4); goto end; }
            }
            if (D_8004B370[0] == 8 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x1C43, 0)) { w[0] = func_800853F8(0xB5); goto end; }
        }
        {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1A17, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x1A19, 0)) { w[0] = func_800853F8(0xBE); goto end; }
        }
        {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1A17, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x1A19, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x8015, 0)) { w[0] = func_800853F8(0xC8); goto end; }
        }
        if (D_8004B370[0] == 9 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x8015, 1)) {
            w[0] = func_800853F8(0xE6);
        }
    end:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A5F88(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5DE0, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6C10)();
    return temp_v0;
}

void func_800A5FE4(void) {
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x1A17, 1);
}

void func_800A6010(void) {
    *D_8004B370 = 0xA;
    ((M2C_UNK (*)(M2C_UNK, M2C_UNK)) *D_80048AC8)(0x800D, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG475/nonmatchings/WSTAG475", func_800A6048);
