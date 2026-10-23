s32 func_8008D854(u8 *o, u8 *x, s32 i, s32 n) {
    struct {
        u8 *p0;
        u8 pad4[0x28];
        void (*fn2C)(s32);
        u8 pad30[0x28];
    } t;
    u8 *p = o + (i * 200 + 0x59C);
    s32 r, k;
    u8 *q;

    func_8001EBF8(&t);
    t.fn2C(((CgArr50 *)o)->a[n] + 1);
    k = t.p0[0] - 1;
    r = 0;
    if (k < 5) {
        q = p + k;
        if (q[0xC] < 99) {
            q[0xC]++;
        }
        r = 1;
        (*(void (**)(u8 *, s32, s32, s32))(x + 0xEA0))(x, i, k, q[0xC]);
    }
    return r;
}
