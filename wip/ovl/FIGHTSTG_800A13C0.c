extern u8 D_8003EF5C[];
s32 func_800A13C0(s32 unused, s32 k) {
    s32 i;
    u8 *d = D_800A4460;
    s16 v = *(s16 *)(d + *(s32 *)(d + 8) * 32 + 0x10);
    s32 lim;
    for (i = 0; i < 8; i++) {
        if (*(u16 *)(D_8003EF5C + i * 0x58) == v) {
            return 0;
        }
    }
    lim = D_80042BCA[k].b[0xB];
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}
====
extern u8 D_8003EF5C[];
s32 func_800A13C0(s32 unused, s32 k) {
    s32 i;
    u8 *d = D_800A4460;
    s16 v = *(s16 *)(d + *(s32 *)(d + 8) * 32 + 0x10);
    s32 lim;
    for (i = 0; i < 8; i++) {
        if (*(u16 *)(D_8003EF5C + i * 0x58) == v) {
            return 0;
        }
    }
    lim = ((u8 *)&D_80042BCA[k])[0xB];
    return (((s32 (*)(void))D_8004DC0C)() & 0x7F) < lim;
}
