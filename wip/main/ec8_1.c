extern s32 D_8004B370 NOT_GP;
s32 func_80015EC8(s32 arg0, s32 arg1) {
    s32 ret;
    if (arg1 != 0) {
        ret = 0;
        if (D_8004B370 == arg0) {
            ret = 1;
        }
    } else {
        ret = 1;
        if (D_8004B370 == arg0) {
            ret = 0;
        }
    }
    return ret;
}
