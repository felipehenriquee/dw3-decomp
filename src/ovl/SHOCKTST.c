#include "SHOCKTST.h"
#include "m2c.h"
#include "SHOCKTST_auto.h"
#include "SHOCKTST_data.h"

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80082DA0);

Obj *func_80082E98(void) {
    return func_80014504(func_80082DA0, 0x50, 4);
}

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80082EC4);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083064);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083274);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_8008332C);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800833C0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800835F4);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800836C0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083B2C);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083DB4);

INCLUDE_RODATA("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", D_80082CE0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80083EA4);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800842E0);

Obj *func_8008436C(s32 n) {
    u8 *heap;
    u8 *o = (u8 *)func_80014504(func_80083EA4, 0x88, 0x24);

    *(s32 *)(o + 0x78) = n;
    heap = (u8 *)&D_8004B5DC;
    *(u8 **)(o + 0x7C) = (*(u8 *(**)(s32, s32))(heap + 0x20))(n * 2, 2);
    *(u8 **)(o + 0x80) = (*(u8 *(**)(s32, s32))(heap + 0x20))(*(s32 *)(o + 0x78) * 2, 2);
    return (Obj *)o;
}

INCLUDE_RODATA("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", D_80082D24);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_800843F0);

INCLUDE_ASM("asm/ovl/SHOCKTST/nonmatchings/SHOCKTST", func_80084714);

Obj *func_8008499C(void) {
    return func_80014504(func_80084714, 0x5C, 0x10);
}
