extern s32 D_80048D34[];
extern struct opaque D_80048ABC;
extern W745Ent D_800A71AC[];
void func_800A6008(u8 *o, u8 **w) {
    s32 i;
    u8 *f;
    u8 *t;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        for (i = 0; i < 4; i++) {
            if (D_800A71AC[i].skip == 0) {
                w[i + 1] = (u8 *)func_800A6718(D_800A71AC[i].a, D_800A71AC[i].b, D_800A71AC[i].id);
            } else if (D_800A71AC[i].skip == 2) {
                w[i + 1] = (u8 *)func_800A6774(0x34D);
            }
        }
        t = (u8 *)D_80048D34;
        if (*(s32 *)(t + 0x263C) == 0x29) {
            f = (u8 *)&D_80048ABC;
            if ((*(s32 (**)(s32, s32))(f + 0x10))(0x4074, 0) != 0) {
                w[0] = (u8 *)func_800853F8(0x424);
            } else if (*(s32 *)(t + 0x263C) == 0x29 && (*(s32 (**)(s32, s32))(f + 0x10))(0x4074, 1) != 0 &&
                       (*(s32 (**)(s32, s32))(f + 0x10))(0x4075, 0) != 0) {
                w[0] = (u8 *)func_800853F8(0x42E);
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
