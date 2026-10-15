extern s32 D_8004B438 NOT_GP;
extern struct opaque D_80055D28;
extern s32 D_80055CCC NOT_GP;
extern struct opaque D_80044F4C;
extern struct opaque D_80048744;
void func_80020C64(void) {
    s32 id = ((s32 (*)(void))D_8004B438)() >> 8;
    s32 *p;
    void *src;

    if (((s32 *)&D_80055D28)[0] != id) {
        ((s32 *)&D_80055D28)[0] = id;
        ((s32 *)&D_80055D28)[1] = -1;
        p = &(&D_80055CCC)[id];
        src = (*(void *(**)(s32))&D_80044F4C)(*p);
        /* tamanho em setores de 2048 bytes */
        memcpy(D_800100C4, src, (*(s32 (**)(s32))&D_80048744)(*p) << 11);
    }
}
