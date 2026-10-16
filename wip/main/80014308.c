extern s32 D_8004B7B8[];

/* destroi um objeto: filhos (0x24, 0x20 deles), a lista e o proprio */
void func_80014308(s32 *obj) {
    s32 i;
    s32 *list;
    s32 *items;
    u8 *sys;

    if (obj[8] != 0) {
        list = (s32 *)obj[9];
        for (i = 0, sys = (u8 *)D_8004B610, items = list; i < obj[8]; i++, items++) {
            if (*items != 0) {
                (*(void (**)(s32))(sys + 0x1BC))(*items);
            }
        }
        (*(void (**)(s32))&D_8004B5EC)(obj[9]);
    }
    ((void (*)(void *))D_8004B7B8[0])(obj);
    (*(void (**)(void *))&D_8004B5EC)(obj);
}
