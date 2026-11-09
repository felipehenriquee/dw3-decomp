extern struct opaque D_80048ABC;
extern s32 D_8004B370[];
void func_800A5DE0(u8 *o, s32 *w) {
    s32 a;
    u8 *f;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4005, 0)) {
            w[0] = func_800853F8(0x28);
        } else if (D_8004B370[0] == 0xB) {
            w[0] = func_800853F8(0x110);
        } else if (D_8004B370[0] == 0xD && (*(s32 (**)(s32, s32))(f + 0x10))(0x1C0C, 0)) {
            w[0] = func_800853F8(0x154);
        }
    end:
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

