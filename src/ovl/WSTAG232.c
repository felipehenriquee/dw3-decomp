#include "WSTAG232.h"
#include "m2c.h"
#include "WSTAG232_auto.h"
#include "WSTAG232_data.h"

/* avanca a animacao st (quadro atual, tempo restante) pela tabela tbl de
   pares (quadro, duracao) terminada em 0xFF; retorna o quadro */
s16 func_800A5DE0(s16 *st, s16 *tbl, s32 depth) {
    s16 *e = tbl + st[0] * 2;
    s32 dt = (*(s32 (**)(void))&D_8004DF9C)();

    if (dt >= 5) {
        dt = 4;
    }
    if (depth == 0) {
        st[1] -= dt;
    }
    if (st[1] <= 0) {
        st[0]++;
        e += 2;
        st[1] += e[1];
        if (e[0] == 0xFF) {
            e = tbl;
            st[0] = 0;
            st[1] += e[1];
        }
        func_800A5DE0(st, tbl, depth + 1);
    }
    return e[0];
}

INCLUDE_ASM("asm/ovl/WSTAG232/nonmatchings/WSTAG232", func_800A5ED4);

Obj *func_800A5FCC(void) {
    return func_80014504(func_800A5ED4, 0x58, 0);
}

/* estado 0: cria o objeto e guarda em *out */
void func_800A5FF8(u8 *o, Obj **out) {
    switch (*(s32 *)(o + 0xC)) {
    case 0:
    default:
        *out = func_800A5FCC();
        (*(void (**)(u8 *))(o + 0x38))(o);
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void *func_800A605C(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_80014504(func_800A5FF8, 0x54, 4);
    M2C_FIELD(temp_v0, s32 *, 0x50) = arg0;
    ((M2C_UNK (*)()) *D_800A6650)();
    return temp_v0;
}

INCLUDE_ASM("asm/ovl/WSTAG232/nonmatchings/WSTAG232", func_800A60B8);
