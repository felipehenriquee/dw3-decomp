extern u8 D_80042B1C[];

typedef struct {
    u8 pad0[0x58];
    s16 unk58[8];
} Unk80042B1C;

void func_80013534(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        ((Unk80042B1C *)D_80042B1C)->unk58[i] = 0;
    }
}
