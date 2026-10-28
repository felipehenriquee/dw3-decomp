void func_80090BA0(u8 *o, u8 *x, s32 side) {
    u8 *r = o + side * 200;
    s32 i;
    *(s32 *)(o + 0x42C) = 0;
    *(s32 *)(o + 0x438) = *(s16 *)(r + 0x5A6);
    for (i = *(s16 *)(r + 0x5A0); i < 40; i++) {
        if (*(s8 *)(o + i + 0x46F) != 0) {
            *(s16 *)(o + (*(s16 *)(r + 0x5A6) * 2 + side * 200) + 0x600) = *(s16 *)(o + (i * 2 + side * 200) + 0x5B0);
            *(s16 *)(r + 0x5A6) += 1;
            *(s32 *)(o + 0x42C) = 1;
        }
    }
    for (i = 39; i >= 0; i--) {
        (o + i)[0x49E] = 0;
    }
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
    (*(void (**)(u8 *, s32))(x + 0xEC0))(x, side);
    o[0x422] = 1;
}
