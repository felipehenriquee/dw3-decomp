extern s32 D_80048ACC[];
extern s32 D_8004B370[];
void func_800A6228(u8 *o, s32 *w) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        w[1] = (s32)func_800A61FC();
        if (D_8004B370[0] == 0x25 && ((s32 (*)(s32, s32))D_80048ACC[0])(0x4060, 1)) {
            w[0] = func_800853F8(0x3A7);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
