void func_80018928(s32 arg0, s32 arg1, s32 arg2) {
    u8 *base = D_8004B7D0;
    s32 o1 = (arg0 & 3) * 0x70;
    s32 o2 = ((u32)(arg0 & 0xFF) >> 4) * 0x1C0;
    u8 *p = &base[arg1 + o1 + o2];
    u8 *q = &base[arg2 + o1 + o2];
    u8 tmp = p[0xA4];

    p[0xA4] = q[0xA4];
    q[0xA4] = tmp;
}
