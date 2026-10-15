s32 func_8001B63C(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x70) = 0x10000000;
    func_8001B48C(arg0, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x58) != 0) {
        func_8001B4CC(arg0);
        func_8001B554(arg0);
        return M2C_FIELD(arg0, s32 *, 0x64);
    }
    return arg1;
}
