extern s32 D_80044F44[];
extern u8 D_800A44D0[];
extern u8 D_800A43F4[];
extern u8 D_800A4580[];
extern s32 D_8005CCA8[];
void func_8009D7A4(void) {
    u8 *a = D_800A44D0;
    u8 *s;
    Rec18 *r;
    u8 *f;
    if (*(s16 *)(a + *(s32 *)(a - 0x64) * 32 + 0x18) > 0) {
        f = D_800A4580;
        s = D_800A43F4;
        if ((*(s32 (**)(s32, s32))(f + 0xB8))(0, *(s32 *)(s + 0x24)) != 0) {
            r = &D_80042BCA[*(s32 *)(s + 0x24)];
            s[r->b[0xA] + 0x38] = 1;
            ((void (*)(s32))D_80044F44[0])(D_8005CCA8[0] + 0x6A);
        }
    }
}
