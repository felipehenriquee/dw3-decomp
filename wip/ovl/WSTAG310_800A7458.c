extern s32 D_80099D8C[];
extern struct opaque D_80044F5C;
/* desenha o sprite which do objeto (which 1 fica 32 pixels acima) */
void func_800A7458(u8 *o, s32 tex, s32 which) {
    struct {
        u8 pad0[0x74];
        void (*fn74)(s32, s32);
        u8 pad78[8];
        void (*fn80)(s32, s32);
        void (*fn84)(s32, s32, s32, s32);
        void (*fn88)(s32);
        u8 pad8C[0xA0 - 0x8C];
    } g;
    s16 *a = (s16 *)(o + 0x64 + which * 4);
    s32 y = *(s32 *)(o + 0x58);
    s32 x = *(s32 *)(o + 0x54);
    s32 mode;

    if (which == 1) {
        y -= 0x20;
        mode = 4;
    } else {
        mode = 6;
    }
    func_8001F648(&g);
    g.fn74(0x140, 0x100);
    g.fn80(tex, mode);
    g.fn88(a[1]);
    g.fn84((*(s32 (**)(s32))&D_80044F5C)(D_80099D8C[0]), a[0], x, y);
}
