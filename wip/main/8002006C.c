extern s32 D_80055C38[];
s16 func_8002006C(s32 cmd) {
    u32 key = (u32)cmd >> 31;
    s32 excl = (cmd >> 30) & 1;
    s32 prog = (cmd >> 11) & 0x7F;
    s32 tone = (cmd >> 7) & 0xF;
    s32 note = cmd & 0x7F;
    s32 seq = (cmd >> 8) & 0xFF;
    s32 sep = cmd & 0xFF;
    s32 slot = func_80020030((cmd >> 18) & 0x7F);
    s16 voice = -1;
    s16 *sq;

    if (slot == -1) {
        return 0;
    }
    if (slot != 0) {
        D_80055C38[0] = slot;
    }
    if (excl) {
        u8 *t = D_800519EC;
        if (*(s32 *)(t + 0x4248) == cmd) {
            return 0;
        }
        if (*(s32 *)(t + 0x4248) != 0) {
            (*(void (**)(s32))(t + 0x427C))(*(s32 *)(t + 0x4248));
        }
        *(s32 *)(t + 0x4248) = cmd;
    }
    if (key) {
        voice = SsUtKeyOn(((Unk800519EC *)D_800519EC)->unk4204[slot].unk0, prog, tone, note, 0, 0x7F, 0x7F);
    } else {
        sq = &((Unk800519EC *)D_800519EC)->unk4204[slot].unk4[seq];
        SsSepStop(*sq, sep);
        SsSepSetVol(*sq, sep, 0x7F, 0x7F);
        SsSepPlay(*sq, sep, 1, 1);
    }
    return voice;
}
