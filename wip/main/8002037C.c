extern s32 D_8005CCAC[];

/* som: id empacotado -> SsSepSetDecrescendo */
void func_8002037C(s32 id) {
    s32 neg = (u32)id >> 31;
    s32 sub = (id >> 8) & 0xFF;
    s32 seq = id & 0xFF;
    s32 ch = func_80020030((id >> 18) & 0x7F);
    u8 *t;
    s32 time;

    if (ch != -1 && neg == 0) {
        time = 0x32;
        t = D_800519EC;
        if (D_8005CCAC[0] != 0) {
            time = 0x3C;
        }
        SsSepSetDecrescendo(((Unk800519EC *)t)->unk4204[ch].unk4[sub], seq, 0x80, time);
        if (*(s32 *)(t + 0x4248) == id) {
            *(s32 *)(t + 0x4248) = 0;
        }
    }
}
