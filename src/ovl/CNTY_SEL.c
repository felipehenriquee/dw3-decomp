#include "CNTY_SEL.h"
#include "m2c.h"
#include "CNTY_SEL_auto.h"
#include "CNTY_SEL_data.h"

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082CE8);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082E8C);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082EF0);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80082FC4);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083000);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083184);

void func_800832D8(void) {
    func_80014504(func_80083184, 0x54, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083304);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_800833DC);

void func_80083474(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_8008347C);

void func_80083594(void) {
    M2C_FIELD(func_80014504(func_8008347C, 0x60, 0), void (**)(void *, s16), 0x5C) = func_80083474;
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_800835CC);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083630);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_800836DC);

void func_80083804(void) {
    func_80014504(func_800836DC, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083830);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083894);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083940);

void func_80083A68(void) {
    func_80014504(func_80083940, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083A94);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083B00);

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083BC0);

void func_80083CEC(void) {
    func_80014504(func_80083BC0, 0x58, 0);
}

INCLUDE_ASM("asm/ovl/CNTY_SEL/nonmatchings/CNTY_SEL", func_80083D18);

void func_80084394(void) {
    func_80014504(func_80083D18, 0x54, 0x14);
}
