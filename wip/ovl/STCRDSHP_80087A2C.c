extern s32 D_8008CB98[];
void func_80087A2C(u8 *o, u8 *x) {
    s32 i;
    s32 n;
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        (*(void (**)(u8 *))(o + 0x38))(o);
        *(u8 **)(o + 0xA8) = ((u8 *(*)(s32))D_8008CB98[0])(*(s32 *)(o + 0xA0));
        for (i = 0; i < 6; i++) {
            ((s32 *)(o + 0x74))[i] = (*(s16 **)(*(u8 **)(o + 0xA8) + 8))[i];
        }
        n = *(s32 *)(*(u8 **)(o + 0xA8) + 4);
        *(s32 *)(o + 0xA4) = n;
        *(s32 *)(o + 0x70) = n / 6 + (n % 6 != 0);
        *(Obj **)(x + 0x48) = func_80085FDC(*(s32 *)(o + 0x50), (s32 *)(o + 0x74));
        func_80086074(o, x);
        *(s32 *)(o + 0xAC) = 10;
        *(s32 *)(o + 0xBC) = 10;
        *(s32 *)(o + 0xCC) = 10;
        break;
    case 1:
        func_80086DC4(o, x);
        func_8008674C(o);
        break;
    case 2:
        if (*(Obj **)(x + 0x48) == 0) {
            *(s32 *)(o + 0xC) = 3;
        }
        break;
    case 3:
        break;
    }
}
