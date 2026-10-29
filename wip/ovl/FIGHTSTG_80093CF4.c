void func_80093CF4(u8 *arg0) {
    u8 **w = *(u8 ***)(arg0 + 0x24);
    s32 i = 0;
    s32 t;
    u8 *e;
    s32 idx;
    if (w[1] == 0) {
        t = ((s32 (*)(s32))D_80044F4C)(D_8005CCA8[0] + 0x7F);
        do {
            u8 *o = (u8 *)func_8001AE38(0x1005, 1, 0x24, (s16)(i * 19 + 0x6D));
            s32 n = i + 1;
            w[i + 1] = o;
            (*(void (**)(u8 *, s32, s32))(o + 0x114))(o, t, n);
            i = n;
        } while (i < 6);
        e = D_800A4460;
        idx = *(s32 *)(e + 8);
        e += 0x10;
        e = e + idx * 32;
        if (e[0x1C] & 8) {
            for (i = 0; i < 3; i++) {
                (*(void (**)(u8 *, s32))(w[1] + 0x138))(w[i + 1], 7);
            }
        }
        if (e[0x1C] & 0x20) {
            (*(void (**)(u8 *, s32))(w[1] + 0x138))(w[3], 7);
        }
    }
}

