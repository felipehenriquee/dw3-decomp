/* lista de pares u16 terminada em 0xFFFF */
void func_80016988(u16 *p) {
    u16 a;
    u16 b;

    while ((a = *p++) != 0xFFFF) {
        b = *p++;
        func_800165AC(a, b);
    }
}
