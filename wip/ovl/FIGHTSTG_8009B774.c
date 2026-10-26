extern s32 D_800A368C[];
extern s32 D_80042B30[];
extern s32 D_80055C68[];
extern s32 D_80055C48[];
u8 *func_8009B774(s32 id, s32 b) {
    s32 snd;
    u8 *o;
    switch (id) {
    default:
        snd = D_800A368C[id];
        break;
    case 0x5A:
        snd = D_80042B30[0];
        break;
    case 0x5B:
        ((void (*)(s32))D_80055C68[0])(0x20040006);
        return 0;
    }
    o = 0;
    if (b != 0) {
        o = (u8 *)func_80014504(func_8009B6E4, 0x5C, 0);
        *(s32 *)(o + 0x50) = snd;
        *(s32 *)(o + 0x54) = (s16)((s32 (*)(s32))D_80055C48[0])(snd);
        *(s32 *)(o + 0x58) = b;
    } else {
        ((void (*)(s32))D_80055C48[0])(snd);
    }
    return o;
}
