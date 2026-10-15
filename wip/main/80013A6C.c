extern struct opaque D_8004DF98;
s32 func_80013A6C(s32 arg0) {
    s16 *p = (s16 *)func_800139FC(arg0);

    if (p != NULL) {
        M2C_FIELD(p, s32 *, 8) = (*(s32 (**)(void))&D_8004DF98)();
        if (p[0] == 3) {
            return 0;
        }
    } else {
        func_80013C30(arg0);
    }
    return 1;
}
