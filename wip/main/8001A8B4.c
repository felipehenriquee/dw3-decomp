s32 func_8001A8B4(u8 *w, ScriptCtx *ctx) {
    s32 *tbl;
    s32 c;
    u8 op;

    *(s16 *)(w + 0xA4) = (*(s16 *)(w + 0xAA) != 0) ? ctx->pc + 2 : ctx->end;
    tbl = D_8004DE00;
    while (ctx->pc < ctx->end) {
        c = (*(s32 (**)(u8 *, s32, s32))(tbl + 3))(ctx->base + ctx->pc, ctx->unkA, *(s32 *)(w + 0x50));
        switch ((u32)(c << 16) >> 24) {
        case 2:
            op = ctx->base[ctx->pc + 1];
            if (op == 5 || op == 8) {
                *(s16 *)(w + 0xA6) = ctx->pc;
                ctx->pc = ctx->end + 1;
                break;
            }
            ctx->pc += *(u16 *)(tbl[1] + op * 4);
            break;
        case 4:
            *(s16 *)(w + 0xA6) = ctx->pc - 1;
            return 3;
        default:
            *(s16 *)(w + 0xA6) = ctx->pc;
            ctx->pc = ctx->end + 1;
            break;
        }
    }
    return 0;
}
