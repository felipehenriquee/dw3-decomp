# Trabalho em andamento: EXE (src/main.c)

Funções decompiladas à mão que **já batem** no teste isolado
(`tools/fn.py ... test`), mas ainda não foram integradas.

- `queue.txt`: ordem de integração (algumas dependem de typedefs que
  outras levam para `include/main.h`, então respeite a ordem). Para
  integrar todas:

  ```sh
  for f in $(cat wip/main/queue.txt); do
      python3 -I tools/fn.py main func_$f apply wip/main/$f.c | tail -1
  done
  ```

  O `apply` testa, integra e roda o `make`; se não bater, desfaz.
  Depois de integrar, apague os arquivos usados.
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
- Arquivos `*_t.c` e `NNN_k.c`: variantes de teste; podem ser apagados.
