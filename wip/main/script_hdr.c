/* contexto do interpretador: base do script e posicao atual */
typedef struct {
    u8 *base;
    s32 unk4;
    s16 pc;
} ScriptCtx;
