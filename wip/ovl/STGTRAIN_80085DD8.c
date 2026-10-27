extern s32 D_8004B448[];
Obj *func_80085DD8(void) {
    u8 *o = (u8 *)func_80014504(func_80085BB0, 0x114, 0x80);
    *(void **)(o + 0x110) = func_80084370;
    *(s32 *)(o + 0x50) = 0x1000;
    *(s32 *)(o + 0x54) = 6;
    switch (((s32 (*)(void))D_8004B448[0])()) {
    default:
        *(s32 *)(o + 0x58) = 0x2D;
        break;
    case 0x23D:
        *(s32 *)(o + 0x58) = 0x2E;
        break;
    case 0x24B:
        *(s32 *)(o + 0x58) = 0x2F;
        break;
    case 0x267:
        *(s32 *)(o + 0x58) = 0x30;
        break;
    case 0x28C:
        *(s32 *)(o + 0x58) = 0x31;
        break;
    case 0x2AA:
        *(s32 *)(o + 0x58) = 0x32;
        break;
    case 0x2B5:
        *(s32 *)(o + 0x58) = 0x33;
        break;
    case 0x2CF:
        *(s32 *)(o + 0x58) = 0x34;
        break;
    }
    return (Obj *)o;
}
