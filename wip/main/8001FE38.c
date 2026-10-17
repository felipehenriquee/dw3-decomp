void func_8001FE38(s32 pack) {
    s32 i;
    u8 *buf;
    u8 *sys;
    u8 *src;
    u8 *dst;
    u8 c;
    s32 n, k;

    buf = (*(u8 *(**)(s32, s32))&D_8004B5F4)(*(s32 *)(D_8005CD20 + 0x18), 2);
    i = 0;
    sys = (u8 *)D_80044B38;
    while ((src = (*(u8 *(**)(s32, s32))(sys + 0x428))(i, pack)) != (u8 *)pack) {
        if (*(s32 *)src == 0x4E454C52) {
            src += 8;
            dst = buf;
            c = *src;
            while (c != 0) {
                if (c & 0x80) {
                    n = c & 0x7F;
                    src++;
                    for (k = 0; k < n; k++) {
                        *dst++ = *src;
                    }
                    src++;
                } else {
                    n = *src++;
                    for (k = 0; k < n; k++) {
                        *dst++ = *src++;
                    }
                }
                c = *src;
            }
            func_8001FD50(buf);
        } else {
            func_8001FD50(src);
        }
        i++;
        DrawSync(0);
        *(s32 *)(D_8005CD20 + 8) += 0x40;
    }
    (*(void (**)(u8 *))&D_8004B5EC)(buf);
}
