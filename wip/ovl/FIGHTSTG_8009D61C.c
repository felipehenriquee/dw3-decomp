extern u8 D_800A4434[];
void func_8009D61C(void) {
    u8 *s = D_800A43F4;
    u8 *q = D_800A4580;
    u8 *t = D_800A4460;
    s32 k;
    u8 *e;
    Rec18 *r;
    u8 fl;
    s32 v;
    k = s[0x20] != 0;
    e = k * 3 * 32 + (*(s32 *)(t + k * 4 + 8) * 32 + (t + 0x10));
    if ((*(s32 (**)(s32, s32))(q + 0xBC))(s[0x20], *(s32 *)(s + 0x24)) != 0) {
        r = &D_80042BCA[*(s32 *)(s + 0x24)];
        if (r->b[0xA] == 8) {
            fl = e[0x1B];
            v = r->b[0xC];
        } else {
            fl = e[0x1B];
            v = q[0x36];
        }
        if (fl != 0) {
            v *= 2;
        }
        *(s32 *)(s + 0x2C) = *(s32 *)(s + 0x28) * v / 128;
        D_800A4434[0] = 1;
    }
}
