void func_80018310(s32 mtap, u8 rate) {
    u8 *pad = D_8004B7D0;
    u8 *heap = (u8 *)&D_8004B5DC;
    s32 i;
    s32 j;
    u8 *p;

    (*(void (**)(void *, s32))(heap + 0x24))(pad, 0x3E0);
    i = 0;
    (*(void (**)(void *, s32, s32))(heap + 0x28))(pad + 0x3C8, 0xFF, 0xC);
    for (; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            func_800188C0((i * 16 + j) & 0xFF);
        }
    }
    if (mtap) {
        p = D_8004B7D0 + 4;
        PadInitMtap(p, p + 0x22);
        *(s32 *)(p - 4) |= 0x80000000;
    } else {
        PadInitDirect(D_8004B7D0 + 4, D_8004B7D0 + 4 + 0x22);
    }
    rate &= 0x7F;
    p = D_8004B7D0;
    *(s16 *)(p + 0x3D4) = rate;
    *(s32 *)p |= 0x40000000;
    if (rate == 0) {
        *(s16 *)(p + 0x3D4) = 0x10;
    }
    func_80018460();
}
