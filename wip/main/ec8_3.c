extern s32 D_8004B370 NOT_GP;
s32 func_80015EC8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        if (D_8004B370 == arg0) {
            return 1;
        }
        return 0;
    }
    if (D_8004B370 == arg0) {
        return 0;
    }
    return 1;
}
