extern s32 D_80048D34[];
extern s32 D_80042B70[];
extern s32 D_80048A7C[];
extern s32 D_8004B440[];
s32 func_80086834(u8 *o, u8 **w) {
    s32 r = 0;
    u8 *t;
    if ((*(s32 (**)(u8 *))(w[0] + 0x5C))(w[0]) != 0) {
        switch (*(s32 *)(o + 0x58)) {
        case 1:
            t = (u8 *)D_80048D34;
            r = 1;
            (*(void (**)(void))(t + 0x26FC))();
            (*(void (**)(void))(t + 0x2754))();
            ((void (*)(void))D_80042B70[0])();
            ((void (*)(void))D_80048A7C[0])();
            (*(void (**)(s32, s32))(t + 0x270C))(0x2D7, 0);
            return r;
        case 2:
            t = (u8 *)D_80048D34;
            r = 1;
            (*(void (**)(void))(t + 0x26FC))();
            ((void (*)(void))D_80042B70[0])();
            ((void (*)(void))D_80048A7C[0])();
            (*(void (**)(s32, s32))(t + 0x270C))(0xC00, 0);
            return r;
        case 3:
            if (D_8005CCA8[0] == 0) {
                t = (u8 *)D_80048D34;
                if ((*(s32 (**)(void))(t + 0x2714))() == 0xE01) {
                    (*(void (**)(s32, s32))(t + 0x270C))(0xE02, 0);
                } else {
                    (*(void (**)(s32, s32))(t + 0x270C))(0xE01, 0);
                }
            } else {
                ((void (*)(s32, s32))D_8004B440[0])(0xE02, 0);
            }
            r = 1;
            break;
        case 0:
        default:
            return r;
        }
    }
    return r;
}
