# Trabalho em andamento: EXE (src/main.c)

Funções do EXE que ficaram perto de bater e precisam de mais trabalho.

- `hard.txt`: funções que ficaram perto mas não bateram (`função arquivo`).
  Candidatas para o decomp-permuter (`tools/perm_setup.py`) ou para
  ajuste manual. Anotações:
  - `800148C0`: o splat separou `func_80014908` e `func_8001491C`, que
    são `case`s do `switch` desta função (jump table `jtbl_80010114`).
    Corrigir em `symbol_addrs.txt` para virarem rótulos, refazer o split
    e decompilar o `switch` inteiro.
  - `8001D854`: precisa trocar o tipo canônico de `D_8004DE30` para
    `s32 []` (escalar `NOT_GP` gera `sw` com `$at`).
  - `80013914`: precisa dar nome aos campos `0x4–0x10` de `CdState`
    (`include/main.h`) e atualizar os usos de `pad[...]` em `src/main.c`.
- Os `.c` daqui são a melhor tentativa de cada uma (alguns `*_t.c`
  incluem typedefs locais só para o teste isolado).
