extern s32 D_8005CCA0[];
void func_800A77B4(u8 *o, u8 **w) {
    u8 *t;
    u8 *e;
    u8 *q;
    s32 idx;
    switch (*(s32 *)(o + 0x14)) {
    case 0:
    default:
        idx = *(s32 *)(D_800A4460 + 8);
        e = idx * 32 + (D_800A4460 + 0x10);
        *(s16 *)e = *(u16 *)(w[1] + 0x64);
        func_800A69F0();
        func_800A7328();
        w[7] = (u8 *)func_8008A7F4(*(s16 *)e, 0);
        *(s32 *)(o + 0x14) += 1;
        break;
    case 1:
        if (w[7] == NULL) {
            t = D_800A4460;
            t += *(s32 *)(t + 8) * 32;
            q = ((u8 *(*)(s32))D_8005CCA0[0])(*(s16 *)(t + 0x10));
            w[7] = (u8 *)func_8009A298();
            *(s32 *)(o + 0x50) = 0;
            *(s32 *)(o + 0x54) = q[0x55];
            (*(void (**)(u8 *, s32, u8 *))(w[7] + 0xAC))(w[7], 0xC, o + 0x50);
            (*(void (**)(u8 *, s32))(o + 0x2C))(o, 2);
        }
        break;
    }
}


