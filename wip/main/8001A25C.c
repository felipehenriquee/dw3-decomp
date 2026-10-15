void func_8001A25C(void *arg0, u8 arg1) {
    struct {
        s32 unk0;
        s16 (*fn)(void *, s32, s32);
        s32 unk8;
        s32 unkC;
    } sp10;

    if (arg1 != 0) {
        func_8001FCC0(&sp10, arg1);
        M2C_FIELD(arg0, s16 *, 0xBC) = sp10.fn((u8 *)arg0 + 0x5C, M2C_FIELD(arg0, s32 *, 0x50), M2C_FIELD(arg0, s16 *, 0xB4));
    } else {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    }
}
