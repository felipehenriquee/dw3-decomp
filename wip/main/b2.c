extern u8 D_80048CB4[];
extern s32 D_8004B370[];
s32 func_80015B9C(s32 arg0, s32 arg1) {
    s32 v = D_8004B370[0];
    u8 *range = &D_80048CB4[arg1 * 2];
    s32 lo = range[0];
    s32 hi = range[1];
    s32 ret = 0;

    if (v >= lo) {
        ret = !(hi < v);
    }
    return ret;
}
