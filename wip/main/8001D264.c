s32 func_8001D264(u8 *s, u8 sjis, u8 *font) {
    u8 c = s[0];
    u16 code;
    u16 *e;

    if (c == 0) {
        return 0x400;
    }
    if (sjis) {
        if (c < 4) {
            return (s16)(s[0] << 8 | s[1]);
        }
        if (c == 10) {
            return 0x201;
        }
        code = s[0] << 8 | s[1];
        if ((u16)(code + 0x7DB1) < 0x146) {
            for (e = (u16 *)(*(u8 **)(font + 0xC) + 0x10); *e != 0xFFFF; e += 2) {
                if (code == *e) {
                    return ((u8 *)e)[2];
                }
            }
            return 0x300;
        }
        for (e = *(u16 **)(font + 0x10); *e != 0xFFFF; e += 2) {
            if (code == *e) {
                return ((u8 *)e)[2] | 0x100;
            }
        }
        return 0x300;
    }
    if (c == 1) {
        if (*(s16 *)(font + 0x16) < s[1]) {
            return (u8)(*(u16 *)(font + 0x16) + 1) | 0x100;
        }
        return (s16)(s[0] << 8 | s[1]);
    }
    if (c < 4) {
        return (s16)(s[0] << 8 | s[1]);
    }
    if (s[0] < *(s16 *)(font + 0x14)) {
        return s[0];
    }
    return 0x300;
}
