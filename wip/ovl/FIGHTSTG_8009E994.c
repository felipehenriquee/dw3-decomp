u8 *func_8009E994(s32 id) {
    FtCardCur *d = &D_800A4558;
    u8 *b;
    FtCard4 *e;
    u8 *ta;
    u8 *tb;
    s32 idx;
    if (id == D_800A4558.id) {
        if (d->isB != 0) {
            return d->p14;
        }
        return d->p10;
    }
    b = ((u8 *(*)(s32))D_80044F4C)(0x1CC);
    e = (FtCard4 *)(b + *(s32 *)(b + 4));
    ta = b + *(s32 *)(b + 8);
    tb = b + *(s32 *)(b + 0xC);
    for (; e->id != 0; e++) {
        if (e->id == id) {
            D_800A4558.id = id;
            idx = e->idx;
            d->idx = idx;
            d->kind = e->kind;
            d->isB = e->kind >= 0x3A;
            if (d->isB == 0) {
                return d->p14 = d->p10 = ta + idx * 0xC4;
            } else {
                return d->p14 = d->p10 = tb + idx * 72;
            }
        }
    }
    return 0;
}
