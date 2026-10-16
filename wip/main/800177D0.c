/* copia o campo 0 dos registros com os 3 ids pedidos (-1 se nao achar) */
void func_800177D0(s32 who, s16 *ids) {
    s32 i;
    s32 idx;
    u8 *base;
    s32 o;
    s32 off;

    i = 0;
    base = D_80048D34;
    o = who * 0x3DC;
    off = o;
    for (; i < 3; i++) {
        idx = func_8001764C(who, *ids);
        if (idx >= 0) {
            *(s16 *)(o + base + 0x7B0) = *(u16 *)(idx * 0x14 + off + base + 0x7B8);
        } else {
            *(s16 *)(o + base + 0x7B0) = -1;
        }
        o += 2;
        ids++;
    }
}
