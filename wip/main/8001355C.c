typedef struct {
    u8 unk0[0xC];
} Unk80041838;

extern Unk80041838 D_80041838[];
Unk80041838 *func_8001355C(s32 arg0) {
    if (arg0 <= 0) {
        return NULL;
    }
    return &D_80041838[arg0];
}
