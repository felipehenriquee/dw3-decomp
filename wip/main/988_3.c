/* lista de pares u16 terminada em 0xFFFF */
void func_80016988(u16 *p) {
    u16 a;

    for (a = *p; a != 0xFFFF; a = *p) {
        p++;
        func_800165AC(a, *p);
        p++;
    }
}
