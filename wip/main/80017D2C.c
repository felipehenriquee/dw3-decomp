/* malloc (primeiro bloco livre que cabe, a partir do inicio do heap) */
void *func_80017D2C(u32 size, s32 tag) {
    HeapBlock *b;
    HeapBlock *nb;
    u32 avail;

    size = (size + 3) >> 2 << 2;
    b = D_8004B5E0[0];
    if (b->tag != 1) {
        do {
            if (b->tag == 0) {
                avail = (u8 *)b->next - (u8 *)b - sizeof(HeapBlock);
                if (avail >= size) {
                    if (size + 20 < avail) {
                        nb = (HeapBlock *)((u8 *)b + size + sizeof(HeapBlock));
                        nb->unk0 = b;
                        nb->next = b->next;
                        nb->tag = 0;
                        b->next->unk0 = nb;
                        b->next = nb;
                    }
                    b->tag = tag;
                    return b + 1;
                }
            }
            b = b->next;
        } while (b->tag != 1);
    }
    return NULL;
}
