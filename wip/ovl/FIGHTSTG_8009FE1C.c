s32 func_8009FE1C(u8 *a) {
    u8 *t = D_800A4460;
    u8 c = a[0];
    s32 idx = *(s32 *)(a + 4);
    s32 k = c != 0;
    s32 n = *(s32 *)(a + 8);
    u8 *s;
    s16 hp;
    s32 v;
    if (idx != *(s32 *)(t + k * 4 + 8)) {
        return 0;
    }
    func_8009EC94(c, 0, idx);
    s = D_800A45C0;
    hp = *(s16 *)(k * 3 * 32 + (idx * 32 + (t + 0x10)) + 6);
    v = (n / 2 - (*(s16 *)(s + 0x1A) + *(s16 *)(s + 0xE)) / 10) * hp / 100;
    if (v <= 0) {
        v = 1;
    }
    if (hp / 2 < v) {
        v = hp / 2;
    }
    return v;
}
