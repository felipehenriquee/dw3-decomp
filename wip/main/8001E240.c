typedef struct SortNode {
    s32 key;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    struct SortNode *next;
} SortNode;

typedef struct {
    u8 pad0[0x78];
    s32 max;
    s32 count;
    SortNode *nodes;
} SortList;

void func_8001E240(SortList *s, s32 a, s32 b, s32 key, s32 d) {
    SortNode *n, *cur, *prev;
    s32 i;

    if (s->count < s->max) {
        n = &s->nodes[s->count];
        cur = s->nodes;
        n->unk8 = a;
        n->unkC = b;
        n->key = key;
        n->unk4 = d;
        if (s->count != 0) {
            prev = NULL;
            for (i = 0; i < s->max; i++) {
                if (cur->key < key) {
                    cur = prev;
                    break;
                }
                prev = cur;
                if (cur->next == NULL) {
                    break;
                }
                cur = cur->next;
            }
            if (cur->next == NULL) {
                cur->next = n;
                n->next = NULL;
            } else {
                n->next = cur->next;
                cur->next = n;
            }
        } else {
            n->next = NULL;
        }
        s->count++;
    }
}
