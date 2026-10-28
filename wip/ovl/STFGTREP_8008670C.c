extern s32 D_8005CCA0[];
typedef struct { s16 a; s8 b; u8 pad3[5]; u16 h[6]; u8 pad14[4]; } FrRec18;
s32 func_8008670C(u8 *a, s32 b) {
    FrRec18 r;
    u8 *t = (u8 *)D_80048D34;
    u8 *q;
    s32 i;
    u16 v;
    (*(void (**)(u8 *, s32, FrRec18 *))(t + 0x2748))(a, b, &r);
    for (i = 0; i < 6; i++) {
        if ((s16)r.h[i] == 0) {
            q = ((u8 *(*)(s32))D_8005CCA0[0])(b);
            v = *(u16 *)(q + (i * 2 + 2) + 0x1C);
            if (v != 0 && r.b >= (q + i)[0x31]) {
                r.h[i] = v;
                if (i == 5) {
                    r.h[5] |= 0x8000;
                }
                (*(void (**)(u8 *, s32, FrRec18 *))(t + 0x274C))(a, b, &r);
                return *(u16 *)(q + (i * 2 + 2) + 0x1C);
            }
        }
    }
    return 0;
}
