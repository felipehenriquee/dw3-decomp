/* no de 0x14 bytes da lista em func_8001E324 */
typedef struct Unk8001E324 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    struct Unk8001E324 *next;
} Unk8001E324;

void func_8001E324(void *arg0, s32 arg1, s32 arg2) {
    Unk8001E324 *n;

    if (M2C_FIELD(arg0, s32 *, 0x7C) < M2C_FIELD(arg0, s32 *, 0x78)) {
        n = &M2C_FIELD(arg0, Unk8001E324 **, 0x80)[M2C_FIELD(arg0, s32 *, 0x7C)];
        n->unk8 = arg1;
        n->unkC = arg2;
        n->unk0 = 0;
        n->unk4 = 0;
        n->next = NULL;
        if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
            n[-1].next = n;
        }
        M2C_FIELD(arg0, s32 *, 0x7C)++;
    }
}
