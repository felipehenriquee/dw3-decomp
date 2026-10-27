extern u8 D_8004935C[];
void func_80088D24(DkCnt74 *o, u8 **w, s32 d, s32 on) {
    u8 *x;
    s32 i;
    if (on != 0) {
        x = w[d * 7 + 2];
        (*(void (**)(u8 *, u8 *, s32))(x + 0x114))(x, D_8004935C + d * 0x66, -1);
        for (i = 0; i < 6; i++) {
            x = w[d * 7 + 3 + i];
            (*(void (**)(u8 *, s32, s32))(x + 0x118))(x, 0, o->a[d][i]);
            (*(void (**)(u8 *, s32))(x + 0x148))(x, 1);
        }
    } else {
        x = w[d * 7 + 2];
        (*(void (**)(u8 *, s32))(x + 0x144))(x, 0);
        for (i = 0; i < 6; i++) {
            x = w[d * 7 + 3 + i];
            (*(void (**)(u8 *, s32))(x + 0x144))(x, 0);
        }
    }
}
