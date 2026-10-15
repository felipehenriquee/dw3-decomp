void func_8001A1B8(void *arg0, s32 arg1) {
    if (arg1 <= 0) {
        M2C_FIELD(arg0, s16 *, 0xA8) = 0;
        M2C_FIELD(arg0, s16 *, 0xAA) = 0;
        M2C_FIELD(arg0, u16 *, 0xA4) = M2C_FIELD(arg0, u16 *, 0x62);
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xA4) = 0;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0;
    M2C_FIELD(arg0, s16 *, 0xAA) = arg1;
    M2C_FIELD(arg0, s16 *, 0xA6) = 0;
}
