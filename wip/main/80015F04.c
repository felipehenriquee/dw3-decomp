s32 func_80015F04(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        if (((s8 *)&D_80048D34[arg0])[0x7C] != 0) {
            return 1;
        }
        if (((s8 *)&D_80048D34[arg0])[0x20F] != 0) {
            return 1;
        }
        return 0;
    }
    if (((s8 *)&D_80048D34[arg0])[0x7C] != 0) {
        return 0;
    }
    if (((s8 *)&D_80048D34[arg0])[0x20F] != 0) {
        return 1;
    }
    return 0;
}
