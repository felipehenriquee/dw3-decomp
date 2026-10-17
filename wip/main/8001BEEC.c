
extern u8 D_8004DD10[];
void func_8001BEEC(u8 *obj) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        s32 unk78;
        void (*fn7C)(s32, s32);
        s32 unk80;
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA8 - 0x8C];
    } g;
    u8 *par;
    s32 k;
    s16 *pos;
    s32 x;
    u8 *sys;

    par = *(u8 **)(obj + 0x50);
    k = *(s32 *)(par + 0x58);
    pos = (s16 *)(D_8004DD10 + k * 32);
    if ((u32)(k - 2) < 2) {
        x = *(s16 *)(par + 0x64) - 14;
    } else {
        x = *pos;
    }
    if (obj[0x5C] == 0) {
        return;
    }
    func_8001F648(&g);
    g.fn7C(*(s32 *)(*(u8 **)(obj + 0x50) + 0x54), 0);
    g.fn74(0x140, 0);
    sys = D_8004DE10;
    if ((*(s32 (**)(void))(sys + 0x188))() - *(s32 *)(obj + 0x58) >= 6) {
        *(s32 *)(obj + 0x58) = (*(s32 (**)(void))(sys + 0x188))();
        if (++*(s32 *)(obj + 0x54) >= 4) {
            *(s32 *)(obj + 0x54) = 0;
        }
    }
    g.fn88(*(s32 *)(obj + 0x54));
    g.fn84((*(s32 (**)(s32))((u8 *)&D_80044F4C + 0x10))(0x2860000), 7,
           *(s16 *)(*(u8 **)(obj + 0x50) + 0x60) + x,
           *(s16 *)(*(u8 **)(obj + 0x50) + 0x62) + pos[1]);
}

