extern struct opaque D_8004B5DC;
extern s32 *D_8005CB50[];

/* inicializa o heap: de D_8005CB50[0] ate 0x801FF000 (abaixo da pilha) */
void func_80017C5C(void) {
    s32 *info = (s32 *)&D_8004B5DC;
    s32 *start;
    s32 *end;

    info[2] = 0x801FF000;
    end = (s32 *)0x801FEFF4;
    start = D_8005CB50[0];
    info[1] = (s32)start;
    info[0] = 0x801FF000 - (s32)start;
    start[0] = (s32)start;
    start[1] = (s32)end;
    start[2] = 0;
    end[0] = (s32)start;
    end[2] = 1;
    end[1] = info[2];
}
