extern u8 D_8004DCF4[];
Obj *func_8001C85C(s32 arg0, s32 x, s32 y, s32 h, s32 arg4, s32 type) {
    s32 off = h;
    Obj *o = func_80014504(func_8001C7D8, 0xC0, 0);
    u8 *e;

    M2C_FIELD(o, s32 *, 0x64) = arg0;
    M2C_FIELD(o, s16 *, 0x54) = x;
    M2C_FIELD(o, s16 *, 0x56) = y;
    h += 0x20;
    M2C_FIELD(o, s16 *, 0x58) = h;
    M2C_FIELD(o, s16 *, 0x5A) = arg4;
    if ((u32)(type - 2) < 2) {
        off = 0;
    }
    e = D_8004DCF4 + type * 32;
    M2C_FIELD(o, s16 *, 0x6C) = *(u16 *)(e + 8) - off;
    M2C_FIELD(o, s16 *, 0x6E) = *(u16 *)(e + 0xA);
    M2C_FIELD(o, s16 *, 0x50) = x + M2C_FIELD(o, u16 *, 0x6C);
    M2C_FIELD(o, s16 *, 0x52) = y + M2C_FIELD(o, u16 *, 0x6E);
    return o;
}
