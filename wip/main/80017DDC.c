/* malloc a partir do fim do heap (procura de tras para frente) */
void *func_80017DDC(u32 size, s32 tag) {
    s32 *info = (s32 *)&D_8004B5DC;
    HeapBlock *b;
    HeapBlock *prev;
    HeapBlock *nb;
    u32 avail;

    size = ((size + 3) >> 2 << 2) + sizeof(HeapBlock);
    b = (HeapBlock *)(info[2] - sizeof(HeapBlock));
    while ((HeapBlock *)info[1] != b) {
        prev = b->unk0;
        if (prev->tag == 0) {
            avail = (u8 *)b - (u8 *)prev;
            if (size == avail) {
                prev->tag = tag;
                return prev + 1;
            }
            if (size < avail) {
                nb = (HeapBlock *)((u8 *)b - size);
                nb->unk0 = prev;
                nb->next = b;
                nb->tag = tag;
                b->unk0->next = nb;
                b->unk0 = nb;
                return nb + 1;
            }
        }
        b = b->unk0;
    }
    return NULL;
}
