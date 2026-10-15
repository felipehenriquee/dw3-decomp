extern s32 D_8004B438 NOT_GP;
extern struct opaque D_80055D28;
extern s32 D_80055CCC NOT_GP;
extern struct opaque D_80044F4C;
extern struct opaque D_80048744;
void func_80020C64(void) {
    s32 id = ((s32 (*)(void))D_8004B438)() >> 8;

    void *src;

    if (((s32 *)&D_80055D28)[0] != id) {
        ((s32 *)&D_80055D28)[0] = id;
        ((s32 *)&D_80055D28)[1] = -1;

        src = (*(void *(**)(s32))&D_80044F4C)((&D_80055CCC)[id]);
        /* tamanho em setores de 2048 bytes */
        memcpy(D_800100C4, src, (*(s32 (**)(s32))&D_80048744)((&D_80055CCC)[id]) << 11);
    }
}
