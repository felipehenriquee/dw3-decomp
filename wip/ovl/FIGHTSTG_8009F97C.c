extern u8 D_80042B1C[];
void func_8009F97C(s32 side, s32 k) {
    u8 *t;
    u8 *q;
    u8 *p;
    Rec18 *r;
    s32 v;
    u8 *tb;
    if ((u8)side == 0) {
        t = D_800A4460;
        func_8009EC94(0, 1, *(s32 *)(t + 8));
        func_8009EC94(0x10, 0, *(s32 *)(t + 0xC));
    } else {
        t = D_800A4460;
        func_8009EC94(0, 0, *(s32 *)(t + 8));
        func_8009EC94(0x10, 1, *(s32 *)(t + 0xC));
    }
    q = D_800A4580;
    r = &D_80042BCA[k];
    p = q + 0x40;
    if ((u8)side == 0) {
        v = (u16)r->h[1];
        v = *(s16 *)(q + 2) * v;
    } else {
        tb = D_80042B1C;
        v = (u16)r->h[1] * *(s16 *)(tb + D_800A446C * 12 + 0x22) / 16 * *(s16 *)(q + 2);
    }
    func_8009F6DC((u8)side, k, v / *(s16 *)(p + 4));
}
