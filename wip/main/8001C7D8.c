void func_8001C7D8(u8 *arg0) {
    switch (*(s32 *)(arg0 + 0xC)) {
    default:
        *(s32 *)(arg0 + 0x68) = 0;
        if (*(s32 *)(arg0 + 0xB8) == 0) {
            *(s32 *)(arg0 + 0x60) = 0;
        } else {
            *(s32 *)(arg0 + 0x60) = 0x1000;
        }
        *(s32 *)(arg0 + 0x90) = 0;
        *(s32 *)(arg0 + 0x88) = *(s16 *)(arg0 + 0x54);
        *(s32 *)(arg0 + 0x8C) = *(s16 *)(arg0 + 0x56);
        (*(void (**)(void *))(arg0 + 0x38))(arg0);
        break;
    case 1:
        func_8001C4EC(arg0);
        break;
    case 2:
    case 3:
        break;
    }
}
