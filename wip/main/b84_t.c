extern u8 D_8004DE10[];

/* tabela em D_8004DE10: 30 slots (em uso + id) */
typedef struct {
    u8 pad0[0x60];
    s32 used[30];
    s32 id[30];
} Unk8004DE10;
void func_8001DB84(s32 slot, s32 used, s32 id) {
    s32 i;

    for (i = 29; i != slot; i--) {
        ((Unk8004DE10 *)D_8004DE10)->used[i] = ((Unk8004DE10 *)D_8004DE10)->used[i - 1];
        ((Unk8004DE10 *)D_8004DE10)->id[i] = ((Unk8004DE10 *)D_8004DE10)->id[i - 1];
    }
    ((Unk8004DE10 *)D_8004DE10)->used[slot] = used;
    ((Unk8004DE10 *)D_8004DE10)->id[slot] = id;
}
