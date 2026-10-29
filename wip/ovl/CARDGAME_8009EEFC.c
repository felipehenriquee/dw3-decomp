void func_8009EEFC(u8 *o, s16 *arr, s32 range, s32 flags) {
    s32 lo = range & 0xFFFF;
    s32 hi = range >> 16;
    s32 i, j;
    s16 a, b;
    S8x2 t;
    u8 c;
    for (i = lo; i < hi - 1; i++) {
        for (j = i + 1; j < hi; j++) {
            a = arr[i];
            b = arr[j];
            if (((CgArr50 *)o)->a[arr[i]] > ((CgArr50 *)o)->a[arr[j]]) {
                arr[i] = b;
                arr[j] = a;
                if (flags & 1) {
                    t = ((CgCards30A *)o)->c[i];
                    ((CgCards30A *)o)->c[i] = ((CgCards30A *)o)->c[j];
                    ((CgCards30A *)o)->c[j] = t;
                }
                if (flags & 2) {
                    c = (o + (i - lo))[0x446];
                    (o + (i - lo))[0x446] = (o + (j - lo))[0x446];
                    (o + (j - lo))[0x446] = c;
                }
            }
        }
    }
}

