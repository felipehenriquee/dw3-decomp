extern s32 D_8004DE10[];
extern s32 D_80048D34[];
extern s32 D_8004B43C[];
extern SRect D_800A5938[];
void func_80095BFC(u8 *o, u8 **w) {
    struct {
        u8 pad0[0x24];
        void (*fn24)(s32, s32);
        void (*fn28)(s32, s32);
        void (*fn2C)(s32);
        u8 pad30[8];
    } g;
    u8 *t;
    u8 *f;
    u8 *x;
    u8 *d;
    s32 k;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        t = (u8 *)D_8004DE10;
        f = (u8 *)D_80044B38;
        (*(void (**)(void))(t + 0x150))();
        (*(void (**)(s32))(t + 0x154))(0xA000);
        (*(void (**)(s32, s32, s32, s32))(t + 0x174))(0x140, 0xF0, 0, 0);
        func_8001FFA8(&g);
        g.fn24(0x280, 0);
        g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x25D0000));
        g.fn24(0x340, 0);
        g.fn2C((*(s32 (**)(s32))(f + 0x424))(0x25D0001));
        x = (*(u8 *(**)(SRect *, s32, s32))(t + 0x16C))(D_800A5938, 3, 0x100);
        (*(void (**)(u8 *, s32, s32, s32))(x + 0x12C))(x, 0x1F, 0x1F, 0x1F);
        *w = (u8 *)func_800A3240(((s8 (*)(void))D_8004B43C[0])());
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
        if ((*w)[0x303] == 2) {
            (*(void (**)(u8 *, s32))(o + 0x28))(o, 2);
            (*(void (**)(u8 *, s32))(*w + 0x28))(*w, 3);
        }
        break;
    case 2:
        switch (*(s32 *)(o + 0x10)) {
        case 0:
        default:
            d = (u8 *)D_80048D34;
            k = 0x1500;
            if (!((*(s32 (**)(s32))(d + 0x2704))(1) & 0xF)) {
                k = *(s32 *)(d + 0x34);
            }
            (*(void (**)(s32, s32))(d + 0x270C))(k, 0);
            (*(void (**)(u8 *))(o + 0x3C))(o);
            break;
        case 1:
            break;
        }
        break;
    case 3:
        break;
    }
}
