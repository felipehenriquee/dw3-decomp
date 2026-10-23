void func_8008DDC0(u8 *o, u8 *x, s32 m) {
    s32 any = 0;
    s32 i, c;
    for (i = 0; i < 12; i++) {
        if (*(s8 *)(o + i + 0x46F) == 0) {
            continue;
        }
        c = (i < 6) ? (i < o[0x72C]) : (i - 6 < o[0x79E]);
        if (c) {
            (*(void (**)(u8 *, s32, s32))(x + 0xF38))(x, i, m);
            any = 1;
        }
    }
    if (any != 0) {
        switch (m) {
        case 0:
        default:
            ((void (*)(s32))D_80055C48)(0x9C0001);
            break;
        case 1:
            ((void (*)(s32))D_80055C48)(0x9C0000);
            break;
        }
    }
    *(s32 *)(o + 0x424) = 0;
}
