extern struct opaque D_80055D28;
extern struct opaque D_80044F4C;
extern struct opaque D_80048744;
extern s32 D_800100C8 NOT_GP;
void func_80020D10(s32 arg0) {
    s32 *s = (s32 *)&D_80055D28;
    void *src;

    if (s[1] != arg0) {
        s[1] = arg0;
        src = (*(void *(**)(s32))&D_80044F4C)(arg0);
        memcpy(D_800100C8, src, (*(s32 (**)(s32))&D_80048744)(arg0) << 11);
    }
}
