typedef struct { s16 x, y; } S16x2;
void func_80084464(u8 *o, s32 v, S16x2 *p) {
    u8 **l = *(u8 ***)(o + 0x24);
    s32 j, i;
    for (j = 0; j < 2; j++) {
        if (*(s32 *)((j * 12 + *(u8 **)(o + 0x64)) + 0x34) != 0) {
            for (i = 0; i < *(s32 *)(o + 0x50); i++) {
                if (i != 0) {
                    *(s32 *)(l[i + 1] + 0x54) = v;
                    if (p != 0) {
                        *(S16x2 *)(l[i + 1] + 0x58) = *p;
                    }
                }
            }
        }
    }
}
