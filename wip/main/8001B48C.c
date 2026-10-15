void func_8001B48C(void *arg0, s32 *arg1) {
    M2C_FIELD(arg0, s32 **, 0x50) = arg1;
    if (arg1[0] == 0x4E454C52) {
        M2C_FIELD(arg0, s32 *, 0x58) = 1;
        M2C_FIELD(arg0, s32 *, 0x5C) = arg1[1];
    } else {
        M2C_FIELD(arg0, s32 *, 0x58) = 0;
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    }
    arg1 += 2;
    M2C_FIELD(arg0, s32 **, 0x54) = arg1;
    M2C_FIELD(arg0, s32 **, 0x68) = arg1;
}
