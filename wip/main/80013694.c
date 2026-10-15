extern u8 D_8005CD28[];
s32 func_80013694(void) {
    s32 pos;
    u8 *s;

    CdGetSector(D_8005CD28, 3);
    pos = CdPosToInt(D_8005CD28);
    s = (u8 *)&D_80044B04;
    if (pos == *(s32 *)(s + 0x28)) {
        *(s32 *)(s + 0x28) = pos + 1;
        return 0;
    }
    return -1;
}
