extern s32 D_80048ACC[];
extern s32 D_8004B370[];
void func_800A5DE0(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        if (D_8004B370[0] == 0x11 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x403C, 0)) {
            w[0] = func_800853F8(0x1B8);
        } else if (D_8004B370[0] == 0x12 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x4038, 0)) {
            w[0] = func_800853F8(0x208);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
