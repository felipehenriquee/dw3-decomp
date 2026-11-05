extern s32 D_8009AF68[];
void func_800980B0(u8 *o, u8 *x) {
    s32 i;
    u8 *d;
    u8 *f;
    s32 v;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        d = (u8 *)D_80048D34;
        for (i = 0; i < 3; i++) {
            if ((*(s32 (**)(s32))(d + 0x2718))(i) >= 0) {
                *(s32 *)(o + 0x5C) += 1;
            }
        }
        for (i = 0; i < *(s32 *)(o + 0x5C); i++) {
            *(s32 *)(o + i * 16 + 0x94) = 10;
        }
        v = 10;
        f = (u8 *)D_8009AF68;
        (*(void (**)(u8 *, s32))(f + 0x670))(o + 0x94, 1);
        for (i = 0; i < 2; i++) {
            *(s32 *)(o + i * 16 + 0xC4) = v;
            (*(void (**)(u8 *, s32))(f + 0x670))(o + (i * 16 + 0xC4), 1);
            *(s32 *)(o + 0xE4) = 8;
            (*(void (**)(u8 *, s32))(f + 0x670))(o + 0xE4, 0);
        }
        func_80096590(o, x);
        break;
    case 1:
        func_8009744C(o, x);
        func_80096988(o);
        break;
    case 2:
    case 3:
        break;
    }
}
