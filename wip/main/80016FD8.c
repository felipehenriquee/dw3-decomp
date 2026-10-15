s32 func_80016FD8(u32 arg0) {
    Unk80048D34_3DC *p;
    s32 idx;

    if (arg0 >= 3) {
        return -1;
    }
    idx = ((Unk80048D34 *)D_80048D34)->unk70[arg0];
    p = &((Unk80048D34_3DC *)D_80048D34)[idx];
    return *(s32 *)(p->unk0 + 0x760) - 3;
}
