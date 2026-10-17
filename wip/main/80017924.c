extern s32 D_8005CCA0[];

/* item do inventario (0x14 bytes, 44 por personagem a partir de 0x7B8) */
typedef struct {
    u8 pad0[0x7B8];
    s16 id;
    u8 count;
} Unk80048D34_Item;

/* poe o item no primeiro espaco livre do inventario (se ainda nao tem) */
s32 func_80017924(s32 who, s32 id) {
    s32 i;
    s32 slot;
    Unk80048D34_Item *it;

    if (func_8001764C(who, id) == -1) {
        for (i = 0, slot = -1; i < 44; i++) {
            if (((Unk80048D34_7B8 *)(D_80048D34 + who * 0x3DC + i * 0x14))->unk7B8 == 0) {
                slot = i;
                break;
            }
        }
        if (slot != -1) {
            ((void (*)(s32))D_8005CCA0[0])(id);
            it = (Unk80048D34_Item *)(D_80048D34 + (who * 247 + slot * 5) * 4);
            it->id = id;
            it->count = 1;
            return 1;
        }
    }
    return 0;
}
