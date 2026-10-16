#include "WSTAG641.h"
#include "m2c.h"
#include "WSTAG641_auto.h"
#include "WSTAG641_data.h"

INCLUDE_ASM("asm/ovl/WSTAG641/nonmatchings/WSTAG641", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG641/nonmatchings/WSTAG641", func_800A5EE0);

void *func_800A5F54(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5EE0, 0x54, 0);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6758)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG641/nonmatchings/WSTAG641", func_800A5FB0);
