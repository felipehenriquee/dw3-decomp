extern s32 D_8005CCA0[];
typedef struct { s16 a; s8 b; u8 pad3[5]; s16 h[5]; u8 pad12[6]; } FrRec18;
s32 func_80086844(s32 a, s32 b) {
    FrRec18 r;
    u8 *t = (u8 *)D_80048D34;
    u8 *q;
    s32 i;
    u8 *p;
    u8 *t2;
    (*(void (**)(s32, s32, FrRec18 *))(t + 0x2748))(a, b, &r);
    q = ((u8 *(*)(s32))D_8005CCA0[0])(b);
    t2 = t;
    p = (u8 *)&r;
    for (i = 0; i < 5; i++, p += 2) {
        if (*(s16 *)(p + 8) > 0 && !(*(u16 *)(p + 8) & 0x2000)) {
            if (r.b >= q[i + 0x37]) {
                *(u16 *)(p + 8) |= 0x2000;
                (*(void (**)(s32, s32))(t2 + 0x274C))(a, b);
                return *(u16 *)(p + 8) & 0x1FFF;
            }
        }
    }
    return 0;
}
