s32 func_800140D8(u32 arg0) {
    s32 idx = arg0 & 0xFFFF;
    s32 *base = (s32 *)func_80013E5C(arg0 >> 16);

    return base[idx] + (s32)base;
}
