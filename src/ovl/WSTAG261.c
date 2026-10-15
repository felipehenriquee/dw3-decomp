#include "WSTAG261.h"
#include "m2c.h"
#include "WSTAG261_auto.h"
#include "WSTAG261_data.h"

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A5DFC);

void func_800A6218(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        switch (arg1) {                             /* irregular */
        case 0x348:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 0;
            return;
        case 0x349:
            M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(arg0, 2);
            M2C_FIELD(arg0, s16 *, 0x58) = 1;
            break;
        }
    }
}

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A628C);

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A62F4);

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A634C);

INCLUDE_ASM("asm/ovl/WSTAG261/nonmatchings/WSTAG261", func_800A63A8);
