#include "WSTAG220.h"
#include "m2c.h"
#include "WSTAG220_auto.h"
#include "WSTAG220_data.h"

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A5E74);

Obj *func_800A6430(void) {
    return func_80014504(func_800A5E74, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A645C);

Obj *func_800A6A18(void) {
    return func_80014504(func_800A645C, 0x64, 0x14);
}

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A6A44);

Obj *func_800A7000(void) {
    return func_80014504(func_800A6A44, 0x64, 0x14);
}

void func_800A702C(void *arg0) {
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

void *func_800A7074(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A702C, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A81B4)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG220/nonmatchings/WSTAG220", func_800A70D0);

void func_800A7230(void *arg0, s32 arg1) {
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

s32 func_800A72C4(Fade *f) {
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
