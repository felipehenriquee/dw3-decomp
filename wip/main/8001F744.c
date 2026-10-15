/* tabela de offsets relativos: [0] = quantidade, [1..] = offsets */
s32 func_8001F744(s32 *tbl, s32 i) {
    s32 n = tbl[0];

    if (i < 0 || n < i) {
        return 0;
    }
    return (s32)tbl + tbl[i + 1];
}
