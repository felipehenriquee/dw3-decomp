void func_80085BAC(u8 *o) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[4];
        void (*fn7C)(s32, s32);
        u8 pad80[4];
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    u8 *t;
    s32 i;
    s32 row;
    s32 col;
    func_8001F648(&g);
    g.fn7C(*(s32 *)(o + 0x54), *(s32 *)(o + 0x58) - 1);
    g.fn74(0x280, 0);
    t = (u8 *)D_80044B38;
    for (i = 0; i < *(s32 *)(o + 0x68); i++) {
        row = i / 6;
        col = i - row * 6;
        g.fn88(*(s32 *)(o + 0x70));
        g.fn84((*(s32 (**)(s32))(t + 0x424))(0x63E0000), 6, col * 42 + 0x23, row * 54 + 0x44);
    }
}
