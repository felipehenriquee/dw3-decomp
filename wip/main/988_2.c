/* lista de pares u16 terminada em 0xFFFF */
void func_80016988(u16 *p) {
    u16 a = *p;

    while (a != 0xFFFF) {
        p++;
        func_800165AC(a, *p++);
        a = *p;
    }
}
