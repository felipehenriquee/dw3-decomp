extern s32 D_8009A784[];
void func_80083914(s32 a, u8 *w, s32 k, s32 on) {
    s16 buf[24];
    u8 *d;
    u8 *t;
    s32 *e;
    s32 *q;
    u8 *o;
    s32 off;
    s32 h;
    s32 v;
    s32 i;
    if (on) {
        d = (u8 *)D_80048D34;
        i = 0;
        h = (*(s32 (**)(s32))(d + 0x2718))(k);
        (*(void (**)(s32, s16 *))(d + 0x2734))(h, buf);
        v = (*(s32 (**)(s32))(d + 0x2750))(h);
        off = k * 44;
        o = *(u8 **)(w + off);
        (*(void (**)(u8 *, s32, s32))(o + 0x114))(o, v, -1);
        t = (u8 *)D_80044B38;
        e = (s32 *)(D_8009AF6C[0] + 0xC);
        for (; i < 5; i++) {
            v = (*(s32 (**)(s32))(t + 0x414))(D_8005CCA8[0] + 0xB0);
            o = *(u8 **)(w + off + 4);
            off += 4;
            (*(void (**)(u8 *, s32, s32))(o + 0x114))(o, v, *e);
            e += 3;
        }
        q = D_8009A784;
        off = k * 44;
        for (i = 0; i < 5; i++) {
            u8 *r = w + off;
            o = *(u8 **)(r + 0x18);
            off += 4;
            (*(void (**)(u8 *, s32, s32))(o + 0x118))(o, 0, buf[*q++]);
            o = *(u8 **)(r + 0x18);
            (*(void (**)(u8 *, s32))(o + 0x148))(o, 1);
        }
    } else {
        off = k * 44;
        o = *(u8 **)(w + off);
        (*(void (**)(u8 *, s32))(o + 0x144))(o, 0);
        for (i = 0; i < 5; i++) {
            o = *(u8 **)(w + off + 4);
            off += 4;
            (*(void (**)(u8 *, s32))(o + 0x144))(o, 0);
        }
        off = k * 44;
        for (i = 0; i < 5; i++) {
            o = *(u8 **)(w + off + 0x18);
            off += 4;
            (*(void (**)(u8 *, s32))(o + 0x144))(o, 0);
        }
    }
}
