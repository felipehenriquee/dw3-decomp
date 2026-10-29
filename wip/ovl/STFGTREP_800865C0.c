extern s32 D_8004B47C[];
extern s32 D_8004B480[];
extern s32 D_8005CCA0[];
typedef struct { s16 a; s8 lv; u8 pad3; s32 exp; u8 pad8[0x10]; } FrStat18;
s32 func_800865C0(u8 *a, s32 b, s32 add) {
    FrStat18 r;
    u8 *q;
    s32 up;
    s32 need;
    s32 m;
    s32 cont;
    q = ((u8 *(*)(s32))D_8005CCA0[0])(b);
    ((void (*)(u8 *, s32, FrStat18 *))D_8004B47C[0])(a, b, &r);
    r.exp += add;
    if (r.exp > 9999999) {
        r.exp = 9999999;
    }
    up = 0;
    if (r.lv >= 99) {
        return 0;
    }
    do {
        if (q[0x3C] >= r.lv + 1) {
            need = r.lv * 5 * 2;
        } else {
            m = q[0x3C] - 1;
            need = ((r.lv - m) * 25 + m * 5) * 2;
        }
        cont = 0;
        if (r.exp >= need) {
            r.lv++;
            up = 1;
            cont = r.lv < 99;
        }
    } while (cont);
    ((void (*)(u8 *, s32, FrStat18 *))D_8004B480[0])(a, b, &r);
    return up;
}
