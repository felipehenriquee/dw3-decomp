#include "WSTAG270.h"
#include "m2c.h"
#include "WSTAG270_auto.h"
#include "WSTAG270_data.h"

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A5E40);

Obj *func_800A63FC(void) {
    return func_80014504(func_800A5E40, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6428);

Obj *func_800A69E4(void) {
    return func_80014504(func_800A6428, 0x64, 0x14);
}

void func_800A6A10(void *arg0) {
    switch (M2C_FIELD(arg0, s32 *, 0xC)) {
    case 0:
    default:
        M2C_FIELD(arg0, void (**)(void *), 0x38)(arg0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A6A58(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A6A10, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A87A4)();
    return temp_v0;
}

extern struct opaque D_80048ABC;
void func_800A6AB4(void) {
    u8 *f = (u8 *)&D_80048ABC;

    (*(void (**)(s32, s32))(f + 0xC))(0x8192, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x1A1C, 1);
    (*(void (**)(s32, s32))(f + 0xC))(0x40A1, 1);
}

INCLUDE_ASM("asm/ovl/WSTAG270/nonmatchings/WSTAG270", func_800A6B14);

void func_800A6C08(void *arg0, s32 arg1) {
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

s32 func_800A6C9C(Fade *f) {
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
