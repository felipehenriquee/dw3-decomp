extern struct opaque D_80048ABC;
extern s32 D_80048ACC[];
extern s32 D_8004B370[];
void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 5 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x4011, 0)) {
            w[0] = func_800853F8(0x50);
        } else {
            u8 *f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x1A27, 1) && (*(s32 (**)(s32, s32))(f + 0x10))(0x1A28, 0)) {
                w[0] = func_800853F8(0x519);
            }
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
