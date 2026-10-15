extern u8 D_8004DE10[];

/* tabela em D_8004DE10: 30 slots (em uso + id) */
typedef struct {
    u8 pad0[0x60];
    s32 used[30];
    s32 id[30];
} Unk8004DE10;
