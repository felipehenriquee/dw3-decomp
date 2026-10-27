extern s32 D_800A457C[];
typedef struct { u8 b[10]; } Rec10;
typedef struct { s32 used; s32 pad4; Rec10 d; u8 pad12[2]; } FtSlot14;
typedef struct { u8 pad[0x60]; FtSlot14 s[16]; } FtSlots60;
Obj *func_8008B508(u8 *par, s32 id) {
    u8 *o;
    u8 *src;
    s32 i;
    if (id == 0) {
        return 0;
    }
    o = (u8 *)func_80014504(func_8008B200, 0x1A8, 0);
    *(u8 **)(o + 0x50) = par;
    *(Pair32 *)(o + 0x54) = *(Pair32 *)(par + 0x68);
    src = ((u8 *(*)(s32))D_800A457C[0])(id);
    for (i = 15; i >= 0; i--) {
        ((FtSlots60 *)o)->s[i].used = 0;
    }
    for (i = 0; i < 16; i++, src += 10) {
        if (src[0] == 0xFF) {
            break;
        }
        if (src[2] != 0) {
            ((FtSlots60 *)o)->s[i].d = *(Rec10 *)src;
            ((FtSlots60 *)o)->s[i].used = 1;
            *(s32 *)(o + 0x5C) += 1;
        }
    }
    return (Obj *)o;
}
