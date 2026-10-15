extern u8 D_8004DE10[];

/* tabela em D_8004DE10: 30 slots (em uso + id) */
typedef struct {
    u8 pad0[0x60];
    s32 used[30];
    s32 id[30];
} Unk8004DE10;

s32 func_8001DAD0(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg0 != 0) {
            if (((Unk8004DE10 *)D_8004DE10)->used[i] != 0 &&
                ((Unk8004DE10 *)D_8004DE10)->id[i] == arg0) {
                return i;
            }
        } else if (((Unk8004DE10 *)D_8004DE10)->used[i] == 0) {
            return i;
        }
    }
    return -1;
}
