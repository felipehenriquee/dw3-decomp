extern s32 D_8004B448[];
extern u8 D_80048ABC[];
extern s32 D_80048AC0[];
extern s32 D_8004B40C[];
void func_800169E0(void) {
    s32 i;

    if (D_8004B40C[0] != 0) {
        for (i = 2; i >= 0; i--) {
            D_80048ABC[i] = 0;
        }
        func_800165AC(0x12, 0);
    }
    if (((s32 (*)(void))D_8004B448[0])() == 0x700) {
        func_800165AC(0x11, 1);
        func_800165AC(0x12, 1);
        func_800165AC(0x10, D_80048AC0[0] != 0 ? 1 : 0);
        D_80048AC0[0] = 0;
    }
}
