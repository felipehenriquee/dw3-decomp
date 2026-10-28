void func_8008DEF8(u8 *o, u8 *x, s32 xy, s32 mode) {
    s32 i;
    s32 k = xy >> 16;
    s32 n = (s16)xy;
    *(s32 *)(o + 0x424) = 0;
    *(s32 *)(o + 0x428) = k;
    *(s32 *)(o + 0x42C) = n;
    *(s32 *)(o + 0x430) = k;
    if (k < 0) {
        *(s32 *)(o + 0x430) = -k;
    }
    *(s32 *)(o + 0x434) = n;
    if (n < 0) {
        *(s32 *)(o + 0x434) = -n;
    }
    for (i = 0; i < 12; i++) {
        if (*(s8 *)(o + i + 0x46F) == 0) {
            continue;
        }
        if (i < 6) {
            if (i >= o[0x72C]) {
                continue;
            }
            *(s16 *)(o + i * 14 + 0x730) += k;
            *(s16 *)(o + i * 14 + 0x732) += xy;
            if (mode == 2) {
                *(s16 *)(o + i * 14 + 0x730) = -*(s16 *)(o + i * 14 + 0x734);
            }
        } else {
            if (i - 6 >= o[0x79E]) {
                continue;
            }
            *(s16 *)(o + (i * 14 - 84) + 0x7A2) += k;
            *(s16 *)(o + (i * 14 - 84) + 0x7A4) += xy;
            if (mode == 2) {
                *(s16 *)(o + (i * 14 - 84) + 0x7A2) = -*(s16 *)(o + (i * 14 - 84) + 0x7A6);
            }
        }
        if (mode == 0) {
            (*(void (**)(u8 *, s32))(x + 0xF30))(x, i);
        } else {
            (*(void (**)(u8 *, s32))(x + 0xF34))(x, i);
        }
    }
}
