extern u8 D_8004BB98[];

/* configura os atuadores (vibracao) do controle */
void func_80019148(s32 port) {
    s32 p = port & 0xFF;
    s32 n = PadInfoAct(p, -1, 0);
    s32 i;
    s32 r;

    for (i = 0; i < n; i++) {
        r = PadInfoAct(p, i, 2);
        if (r != 0) {
            D_8004B7D0[i + ((u32)p >> 4) * 6 + 0x3C8] = r & 1;
        }
    }
    PadSetActAlign(port & 0xFF, D_8004BB98 + ((u32)(port & 0xFF) >> 4) * 6);
}
