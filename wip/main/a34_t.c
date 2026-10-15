extern u8 D_80044B3C[];

/* tabela em D_80044B3C: 64 entradas de 0x10 bytes */
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 id;
    s32 unk8;
    s32 unkC;
} Unk80044B3C;
Unk80044B3C *func_80013A34(void) {
    s32 i;
    Unk80044B3C *p = (Unk80044B3C *)D_80044B3C;

    for (i = 0; i < 64; i++, p++) {
        if (p->id == 0) {
            return p;
        }
    }
    return NULL;
}
