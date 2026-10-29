void func_80087704(s32 unused, u8 *o) {
    s32 a, b, t0, t1, step;
    switch (*(s32 *)(o + 0x10)) {
    case 1:
        a = *(s16 *)(o + 4);
        b = a + *(s16 *)(o + 8);
        step = *(s32 *)(o + 0x1C);
        t0 = *(s32 *)(o + 0x14);
        t1 = *(s32 *)(o + 0x18);
        if (a < t0) { a += step; if (t0 < a) a = t0; }
        else if (t0 < a) { a -= step; if (a < t0) a = t0; }
        if (b < t1) { b += step; if (t1 < b) b = t1; }
        else if (t1 < b) { b -= step; if (b < t1) b = t1; }
        *(s16 *)(o + 4) = a;
        *(s16 *)(o + 8) = b - a;
        break;
    case 2:
        a = *(s16 *)(o + 6);
        b = a + *(s16 *)(o + 0xA);
        step = *(s32 *)(o + 0x1C);
        t0 = *(s32 *)(o + 0x14);
        t1 = *(s32 *)(o + 0x18);
        if (a < t0) { a += step; if (t0 < a) a = t0; }
        else if (t0 < a) { a -= step; if (a < t0) a = t0; }
        if (b < t1) { b += step; if (t1 < b) b = t1; }
        else if (t1 < b) { b -= step; if (b < t1) b = t1; }
        *(s16 *)(o + 6) = a;
        *(s16 *)(o + 0xA) = b - a;
        break;
    default:
        return;
    }
    if (a == t0 && b == t1) *(s32 *)(o + 0x10) = 0;
}

