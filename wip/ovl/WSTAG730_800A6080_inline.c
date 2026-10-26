extern s32 D_80099D80[];
extern u8 D_8009B6C4[];
extern s32 D_8005CCA8[];
extern u8 D_800A67F0[];
extern u8 D_800A6948[];
extern u8 D_800A6200[];
extern u8 D_800A67BC[];
extern u8 D_800A697C[];
static inline void map_call(s32 a, s32 b, s32 *d, u8 *f) {
    d[2] = 0x679;
    d[3] = 0x67A0000;
    d[4] = (s32)D_800A67F0;
    d[5] = (s32)D_800A6948;
    d[7] = 0x678;
    d[17] = D_8005CCA8[0] + 0xD3;
    d[11] = 0xC600;
    d[12] = 0xDE00;
    d[10] = (s32)D_800A6200;
    d[15] = 8;
    d[16] = 0x60200000;
    d[19] = (s32)D_800A67BC;
    d[13] = 0;
    d[9] = (s32)D_800A697C;
    (*(void (**)(s32, s32))(f + 0x40))(a, b);
}
void func_800A6080(void) {
    map_call(0, 0x67A0001, D_80099D80, D_8009B6C4);
    (*(void (**)(s32, s32))(D_8009B6C4 + 0x40))(7, 0x67A0002);
    (*(void (**)(s32))(D_8009B6C4 + 0x50))(0);
}
