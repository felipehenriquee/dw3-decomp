void func_8008C8D8(u8 *o) {
    s32 n, found, i, s;
    i = *(s16 *)(o + 0x668);
    n = o[0x41B];
    found = 0;
    for (s = i; i < n; i++) {
        if (*(s8 *)(o + (i - s) + 0x446) != 0) {
            *(s32 *)(o + 0x440) = i;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        for (i = 39; *(s16 *)(o + 0x668) < i; i--) {
            if (*(s8 *)(o + (i - *(s16 *)(o + 0x668)) + 0x446) != 0) {
                break;
            }
        }
        *(s32 *)(o + 0x440) = i;
    }
    (o + *(s32 *)(o + 0x440))[0x46F] = 1;
}
