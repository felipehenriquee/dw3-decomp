extern u8 D_80099D80[];
extern u8 D_8009B6C4[];
extern s32 D_8005CCA8[];
extern u8 D_800A62EC[];
extern u8 D_800A6390[];
extern u8 D_800A61C0[];
extern u8 D_800A62E4[];
extern u8 D_800A61A4[];
/* inicializa o mapa: descritor em D_80099D80 e recursos */
void func_800A5E84(void) {
    u8 *m = D_80099D80;
    u8 *sys = D_8009B6C4;

    *(s32 *)(m + 0x8) = 0x6BD;
    *(s32 *)(m + 0xC) = 0x6BE0000;
    *(u8 **)(m + 0x10) = D_800A62EC;
    *(u8 **)(m + 0x14) = D_800A6390;
    *(s32 *)(m + 0x1C) = 0x6BC;
    *(s32 *)(m + 0x44) = D_8005CCA8[0] + 0xE1;
    *(u8 **)(m + 0x28) = D_800A61C0;
    *(s32 *)(m + 0x3C) = 0x32;
    *(s32 *)(m + 0x40) = 0x60C80000;
    *(u8 **)(m + 0x4C) = D_800A62E4;
    *(s32 *)(m + 0x2C) = 0x10600;
    *(s32 *)(m + 0x30) = 0x2BC00;
    *(s32 *)(m + 0x34) = 0;
    *(u8 **)(m + 0x20) = D_800A61A4;
    (*(void (**)(s32, s32, u8 *))(sys + 0x40))(0, 0x6BE0001, m);
    (*(void (**)(s32, s32))(sys + 0x40))(7, 0x6BE0002);
    (*(void (**)(s32, s32))(sys + 0x40))(4, 0x6BE0003);
    (*(void (**)(s32))(sys + 0x50))(0);
}
