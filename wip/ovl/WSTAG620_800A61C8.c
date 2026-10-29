extern s32 D_80048D34[];
extern struct opaque D_80048ABC;
extern s32 D_80048ACC NOT_GP;
extern s32 D_8004B370[];
void func_800A61C8(u8 *o, u8 **w) {
    u8 *t;
    u8 *f;
    s32 m;
    s32 k;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = (u8 *)D_80048D34;
        m = *(s32 *)(t + 0x263C);
        if (m == 0x13) {
            f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x403B, 0) != 0) {
                k = 0x214;
                goto make;
            }
            if (*(s32 *)(t + 0x263C) == m && (*(s32 (**)(s32, s32))(f + 0x10))(0x403B, 1) != 0) {
                k = 0x216;
                goto make;
            }
        }
        f = (u8 *)&D_80048ABC;
        if ((*(s32 (**)(s32, s32))(f + 0x10))(0x403A, 0) != 0 && (*(s32 (**)(s32, s32))(f + 0x10))(0x1C1B, 1) != 0) {
            k = 0x21C;
            goto make;
        }
        if (D_8004B370[0] == 0x14 && ((s32 (*)(s32, s32))D_80048ACC)(0x4003, 1) != 0) {
            k = 0x227;
        make:
            w[0] = (u8 *)func_800853F8(k);
        }
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}
