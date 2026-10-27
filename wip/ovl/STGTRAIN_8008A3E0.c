typedef struct { u8 pad[0x88]; s32 g[4][2][4]; } TrGrid88;
typedef struct { s32 a; s32 b; u8 pad[0x10]; } TrEnt18;
void func_8008A3E0(u8 *a, u8 **w, s32 on) {
    u8 *t;
    u8 *o;
    s32 v;
    s32 n;
    if (on != 0 && (n = ((TrGrid88 *)a)->g[*(s32 *)(a + 0x70)][*(s32 *)(a + 0x6C)][*(s32 *)(a + 0x68)]) > 0) {
        t = (u8 *)D_80044B38;
        v = (*(s32 (**)(s32))(t + 0x414))(D_8005CCA8[0] + 0x10B);
        o = w[2];
        (*(void (**)(u8 *, s32, s32))(o + 0x114))(o, v, ((TrEnt18 **)D_8008CFCC)[0xB7][n].a);
        v = (*(s32 (**)(s32))(t + 0x414))(D_8005CCA8[0] + 0x10B);
        o = w[3];
        (*(void (**)(u8 *, s32, s32))(o + 0x114))(o, v, ((TrEnt18 **)D_8008CFCC)[0xB7][n].b);
    } else {
        o = w[2];
        (*(void (**)(u8 *, s32))(o + 0x144))(o, 0);
        o = w[3];
        (*(void (**)(u8 *, s32))(o + 0x144))(o, 0);
    }
}

