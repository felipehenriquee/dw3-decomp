extern u8 D_80099D80[];
extern s32 D_8009B714[];
extern s32 D_8005CCA8[];
extern u8 D_800A77A0[];
extern u8 D_800A7714[];
extern u8 D_800A7798[];
extern u8 D_800A77DC[];
extern u8 D_800A76F8[];
void func_800A7068(void) {
    u8 *d = D_80099D80;
    *(s32 *)(d + 0xC) = 0x75E0000;
    *(u8 **)(d + 0x10) = D_800A77A0;
    *(s32 *)(d + 0x1C) = 0x75F;
    *(s32 *)(d + 0x44) = D_8005CCA8[0] + 0xEF;
    *(u8 **)(d + 0x28) = D_800A7714;
    *(s32 *)(d + 0x3C) = 13;
    *(s32 *)(d + 0x40) = 0x60340000;
    *(u8 **)(d + 0x4C) = D_800A7798;
    *(u8 **)(d + 0x24) = D_800A77DC;
    *(u8 **)(d + 0x20) = D_800A76F8;
    *(s32 *)(d + 0x2C) = 0x11500;
    *(s32 *)(d + 0x30) = 0x15500;
    *(s32 *)(d + 0x34) = 0;
    ((void (*)(s32))D_8009B714[0])(0);
}
