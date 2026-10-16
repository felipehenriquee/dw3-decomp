extern s32 D_80048CF8[];

/* soma um atributo dos 3 personagens e compara com o limiar idx */
s32 func_80015FBC(s32 idx, s32 flag) {
    u8 info[0x30];
    s32 sum = 0;
    s32 i;
    s32 id;
    u8 *sys = D_80048D34;

    for (i = 0; i < 3; i++) {
        id = (*(s32 (**)(s32))(sys + 0x2718))(i);
        if (id >= 0) {
            (*(void (**)(s32, void *))(sys + 0x2734))(id, info);
            sum += *(s16 *)(info + 0x16);
        }
    }
    if (flag != 0) {
        if (sum < D_80048CF8[idx]) {
            return 0;
        }
        return 1;
    }
    if (sum < D_80048CF8[idx]) {
        return 1;
    }
    return 0;
}
