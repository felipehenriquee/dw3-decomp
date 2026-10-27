extern u8 D_80048D34[];
Obj *func_80096828(s32 d, s32 x, s32 y) {
    struct {
        u8 *p0;
        u8 pad4[0x28];
        void (*fn2C)(s32);
        u8 pad30[0x28];
    } t;
    u8 *o;
    s32 i;
    func_8001EBF8(&t);
    o = (u8 *)func_80014504(func_80096418, 0x74, 0x1C);
    for (i = 5; i >= 0; i--) {
        (o + i)[0x60] = 0;
    }
    for (i = 0; i < 40; i++) {
        t.fn2C(((DkDeck63E *)D_80048D34)->a[d][i]);
        (o + (t.p0[0] - 1))[0x60]++;
    }
    *(void **)(o + 0x6C) = func_800967F8;
    *(s32 *)(o + 0x50) = d;
    *(s16 *)(o + 0x58) = x;
    *(s16 *)(o + 0x5A) = y;
    o[0x67] = 0;
    *(void **)(o + 0x70) = func_80096808;
    return (Obj *)o;
}
