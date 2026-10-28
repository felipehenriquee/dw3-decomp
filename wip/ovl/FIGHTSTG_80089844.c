typedef struct { s32 id; s32 b; s32 c; } FtEnt12;
typedef struct { u8 b[8]; } U8x8;
Obj *func_80089844(s32 id, U8x8 *a, U8x8 *b) {
    u8 *o = (u8 *)func_80014504(func_8008970C, 0xC0, 4);
    FtEnt12 *e;
    *(s32 *)(o + 0x50) = 0;
    for (e = (FtEnt12 *)D_800A2550; e->id != 0; e++) {
        if (e->id == id) {
            *(s32 *)(o + 0x50) = id;
            *(s32 *)(o + 0x58) = e->c;
            *(s32 *)(o + 0x54) = e->b;
            *(s32 *)(o + 0x6C) = 0x280;
            *(s32 *)(o + 0x70) = 0x100;
            *(U8x8 *)(o + 0x5C) = *a;
            *(U8x8 *)(o + 0x64) = *b;
            break;
        }
    }
    if (*(s32 *)(o + 0x50) == 0) {
        (*(void (**)(u8 *, s32))(o + 0x28))(o, 3);
    }
    return (Obj *)o;
}

