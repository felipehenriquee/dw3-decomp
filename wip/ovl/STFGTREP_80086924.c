extern s32 D_8004B484[];
extern s32 D_8005CCA0[];
extern s32 D_8004B47C[];
s32 func_80086924(s32 a, s32 b, s32 v, s32 m) {
    s8 buf[0x18];
    s16 lv;
    s32 n;
    s32 r;
    u8 *p;
    lv = *(s16 *)(((u8 *(*)(void))D_8004B484[0])() + 0x1C);
    if (lv < 0x33) {
        n = v * 10 / lv;
    } else {
        n = v / 5;
    }
    switch (m) {
    case 0:
    case 1:
        r = n;
        break;
    case 2:
        r = n * 6 / 10;
        break;
    default:
        r = n / m;
        break;
    }
    p = ((u8 *(*)(s32))D_8005CCA0[0])(b);
    ((void (*)(s32, s32, s8 *))D_8004B47C[0])(a, b, buf);
    if (r <= 0) {
        r = 1;
    } else if (buf[2] < p[0x3C]) {
        if (r > 10) r = 10;
    } else {
        if (r > 50) r = 50;
    }
    return r;
}
