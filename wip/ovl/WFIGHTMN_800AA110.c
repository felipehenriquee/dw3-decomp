extern s32 D_8004B44C[];
extern s32 D_800A4668[];
void func_800AA110(u8 side, s32 x) {
    u8 *t = D_800A4460;
    s32 idx = *(s32 *)(t + 8);
    u8 *e;
    s32 k;
    u8 *a;
    s32 v;
    t += 0x10;
    e = idx * 32 + t;
    k = ((s32 (*)(void))D_8004B44C[0])();
    if (side != 0 && x != 0 && *(s16 *)(e + 8) != 0 && e[0x1A] == 0) {
        v = ((s32 (*)(s32))D_800A4668[0])(x);
        a = D_80042B1C + k * 2;
        *(s16 *)(a + 0x58) += v;
        if (*(s16 *)(a + 0x58) >= 1000) {
            *(s16 *)(a + 0x58) = 1000;
            func_8009CED0();
        }
    }
}
