void func_8008FF08(u8 *o, u8 *x, s32 side, s32 mode) {
    s32 k = side * 200;
    s32 i;
    s32 t;
    s32 v;
    u8 *r;
    *(s32 *)(o + 0x438) = *(s16 *)(o + k + 0x5A6);
    if (mode == 4) {
        v = *(s16 *)(o + (*(s32 *)(o + 0x440) * 2 + k) + 0x614);
        t = side * 2;
    } else {
        v = *(s16 *)(o + (*(s32 *)(o + 0x440) * 2 + k) + 0x5B0);
        t = side * 2;
    }
    t = ((t + side) * 8 + side) * 8;
    r = o + t;
    *(s16 *)(o + (*(s16 *)(r + 0x5A6) * 2 + t) + 0x600) = v;
    *(s16 *)(r + 0x5A6) += 1;
    if (*(s32 *)(o + 0x438) != 0) {
        if (side == 0) {
            o[0x499] = 5;
        } else {
            o[0x499] = 0xB;
            o[0x49C] = 1;
        }
    } else {
        if (side == 0) {
            o[0x499] = 0x11;
        } else {
            o[0x499] = 0x12;
            o[0x49C] = 1;
        }
    }
    (*(void (**)(u8 *, s32, s32))(x + 0xEC0))(x, side, v);
    for (i = 39; i >= 0; i--) {
        (o + i)[0x49E] = 0;
    }
    o[0x422] = 1;
}
