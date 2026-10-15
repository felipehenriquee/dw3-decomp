extern struct opaque D_8004B5F4;
void func_8001B4CC(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x5C) > M2C_FIELD(arg0, s32 *, 0x60)) {
        if (M2C_FIELD(arg0, s32 *, 0x64) != 0) {
            (*(void (**)(s32))&D_8004B5EC)(M2C_FIELD(arg0, s32 *, 0x64));
        }
        M2C_FIELD(arg0, s32 *, 0x64) = (*(s32 (**)(s32, s32))&D_8004B5F4)(M2C_FIELD(arg0, s32 *, 0x5C), 2);
        M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(arg0, s32 *, 0x5C);
    }
    M2C_FIELD(arg0, s32 *, 0x6C) = M2C_FIELD(arg0, s32 *, 0x64);
}
