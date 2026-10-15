void func_80013EFC(s32 arg0) {
    s16 *p = (s16 *)func_800139FC(arg0);

    if (p != NULL && p[0] == 3) {
        (*(void (**)(s32))&D_8004B5EC)(M2C_FIELD(p, s32 *, 0xC));
        M2C_FIELD(p, s32 *, 4) = 0;
        M2C_FIELD(p, s32 *, 0xC) = 0;
        M2C_FIELD(p, s32 *, 8) = 0;
        p[1] = 0;
        p[0] = 0;
    }
}
