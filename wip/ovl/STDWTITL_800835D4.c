extern s32 D_80089264;
extern s32 D_80087C88;
extern s32 D_80087C8C;
u32 *func_800835D4(u8 *dec) {
    u32 *addr;
    u8 *sector;
    s32 cnt = 2000;
    s32 ww, hh;
    while (StGetNext(&addr, (u32 **)&sector) != 0) {
        if (--cnt == 0) {
            return 0;
        }
    }
    if (*(u32 *)(sector + 8) >= (u32)D_8008926C[0]) {
        D_80089264 = 1;
    }
    if (D_80087C88 != *(u16 *)(sector + 0x10) || D_80087C8C != *(u16 *)(sector + 0x12)) {
        func_80083438();
        ww = *(u16 *)(sector + 0x10);
        hh = *(u16 *)(sector + 0x12);
        D_80087C88 = ww;
        D_80087C8C = hh;
    }
    ww = D_80087C88 * 3 / 2;
    hh = D_80087C8C;
    *(s16 *)(dec + 0x1C) = *(s16 *)(dec + 0x24) = ww;
    *(s16 *)(dec + 0x1E) = *(s16 *)(dec + 0x26) = hh;
    *(s16 *)(dec + 0x32) = hh;
    return addr;
}
