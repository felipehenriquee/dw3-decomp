#include "WSTAG746.h"
#include "m2c.h"
#include "WSTAG746_auto.h"
#include "WSTAG746_data.h"

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A5DE0);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A5FF4);

s32 func_800A6024(void) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) *D_8004B7BC)(0x19, -1, -1);
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, s32 *, 0xC) != 1) {
            ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0x800410BD);
        }
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(temp_v0, 1);
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
    }
    return 0;
}

s32 func_800A60A4(void) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) *D_8004B7BC)(0x19, -1, -1);
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, s32 *, 0xC) != 2) {
            ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0x800410BD);
        }
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(temp_v0, 2);
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
    }
    return 0;
}

s32 func_800A6124(void) {
    void *temp_v0;

    temp_v0 = ((void *(*)(M2C_UNK, M2C_UNK, M2C_UNK)) *D_8004B7BC)(0x19, -1, -1);
    if (temp_v0 != NULL) {
        if (M2C_FIELD(temp_v0, s32 *, 0xC) != 1) {
            ((M2C_UNK (*)(M2C_UNK)) *D_80055C48)(0x800410BD);
        }
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x28)(temp_v0, 1);
        M2C_FIELD(temp_v0, s32 *, 4) = 1;
    }
    return 0;
}

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A61AC);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A62B8);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A6314);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A6434);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A651C);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A65E0);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A6870);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A68CC);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A6918);

INCLUDE_ASM("asm/ovl/WSTAG746/nonmatchings/WSTAG746", func_800A6964);
