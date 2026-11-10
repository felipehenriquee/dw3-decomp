# Digimon World 3 — decompilação e port para PC

## Objetivo
Decompilar o Digimon World 3 (PS1, versão europeia `SLES_049.36` com patch de tradução BR da romsportugues) e criar um **port nativo para PC**.

Caminho escolhido:
1. Decomp *matching* (C que recompila byte a byte): **splat** + **binutils MIPS** + **GCC da PsyQ com maspsx** + **m2c** + decomp.me / objdiff.
2. Port: trocar as bibliotecas PsyQ (libgpu/libgte/libcd/libspu/libpad) pelo **PsyCross** (OpenGL/SDL), como fez o REDRIVER2.
3. Os assets **não** vão para o repositório: o port lê os dados do disco do próprio usuário.

## Estado atual (2026-10-15)
- [x] Disco extraído com `dumpsxiso` → `extraido/` + `layout.xml` (o mkpsxiso 2.30 para Windows está em `../mkpsxiso-2.30-win64/`).
- [x] Endereços do EXE e dos overlays mapeados e validados (ver abaixo).
- [x] Migrado para **Ubuntu 22.04 nativo** (não é WSL). O projeto fica no HD externo NTFS em `/media/felipe/Felipe Henrique/projetos/2026/digimon/Digimon World 3 (BR-EUR) (T1.01) (www.romsportugues.com) (1)/`.
- [x] Toolchain instalada: binutils-mips-linux-gnu 2.38, venv em `~/dw3-decomp/.venv` (splat64 0.50.1, spimdisasm 1.42.4 e o m2c do git — o pacote `m2c` do PyPI é outro projeto), maspsx em `~/dw3-decomp/tools/maspsx`.
- [x] Repositório `~/dw3-decomp` criado (git, no disco interno). O jogo fica em `disc/`, que está no `.gitignore`.
- [x] Primeiro split e rebuild **idêntico** do EXE: `make` → `build/sles_049.36: SUCESSO`. Config em `sles_049.36.yaml`, `make split` regera o asm.
- [x] Overlays no splat: um yaml por `.PRO` em `config/ovl/` (gerado por `tools/gen_ovl_yaml.py`). `make` → EXE + **318 overlays idênticos**.
- [x] Limites text/data reais do EXE e entry point nomeado (`__SN_ENTRY_POINT`, do `2MBYTE.OBJ`).
- [x] PsyQ identificada: **4.7**. 430 funções nomeadas em `symbol_addrs.txt`; cada objeto da lib virou um `.s` próprio em `asm/psyq/`.
- [x] Compilador identificado: **GCC 2.8.1 + maspsx**, `-O2`, `-G8` (ou 4) no EXE.
- [x] C no build: o código do jogo do EXE é `src/main.c` (C + `INCLUDE_ASM`); cada overlay é `src/ovl/<NOME>.c` (`-G0`). Tudo compilado pelo `make` e batendo.
- [ ] Decompilação (2026-11-09, 4ª): EXE **275 de 347** (79%); overlays **2283 de 3292** (69.3%). Total **2558 de 3639 (70.3%)**.

## Repositório `~/dw3-decomp`
- `sles_049.36.yaml`: config do splat do EXE. gp real = `0x8005CB50` (definido pelo código de entrada; o cabeçalho diz 0). Precisa de `ld_align_section_vram_end: False` e `ld_align_segment_vram_end: False`, senão o linker insere padding e o binário não bate.
- `config/ovl/<NOME>.yaml`: um por overlay. `tools/gen_ovl_yaml.py disc/PRO` cria os que faltam (não sobrescreve; apague o yaml para regerar). Overlays de tamanho ímpar usam `subalign: 1` e a cauda que não fecha uma palavra vira `bin`; senão o linker acrescenta 1 byte.
- `config/ovl.sha1`, `sles_049.36.sha1`: hashes conferidos pelo `make`.
- `src/main.c`: código do jogo do EXE. As funções não decompiladas são `INCLUDE_ASM("asm/nonmatchings/main", func_X);`; o `make split` só gera `.s` para elas e nunca sobrescreve o `.c`. Compilado com `-G8` (variável `G` no Makefile).
- `INCLUDE_ASM` usa o modo `maspsx_hack` (`include_asm_macro_style` no yaml do EXE): com `-G8` o gcc 2.8.1 joga as funções para depois dos dados e quebraria o `INCLUDE_ASM` comum. O C é compilado com `-DINCLUDE_ASM_USE_MACRO_INC=1` (o `macro.inc` deixa os `jlabel` globais, que a rodata das jump tables precisa). Os yaml dos overlays usam `generate_asm_macros_files: False`, senão sobrescrevem o `include/include_asm.h`.
- `include/common.h`: tipos básicos (`u8`, `s32`...). Os outros arquivos de `include/` são gerados pelo splat.
- `Makefile`: `make` (compila, assembla, linka, objcopy e confere todos os sha1), `make split` (regera `asm/`, `assets/` e `linker/` a partir do disco, ~12 s), `make clean`. Use `make -j$(nproc)`.
- Gerados e fora do git: `asm/`, `assets/` (dados do jogo), `linker/`, `build/`. Baixados e fora do git: `tools/psyq_sigs/` (assinaturas), `tools/old-gcc/` (compiladores).
- `disc/PRO/` tem os `.PRO`; `disc/SLES_049.36` é o EXE.

### Fluxo de decompilação
- `tools/gen_ctx.py <alvo>`: gera `include/<alvo>_auto.h` (protótipos `s32 f();` das funções em asm, protótipos das já decompiladas, dados do `$gp`). Dados fora do gp ficam em `include/main_data.h` / `include/ovl/<NOME>_data.h` (tipo fixado pela primeira função integrada; `NOT_GP` impede o `$gp` em escalares).
- `tools/autodecomp.py <alvo> [funcs]` / `--apply`: m2c → gcc → compara, com busca de tipos por símbolo; `--apply` integra e confere com o `make` (bissecção se quebrar).
- `tools/autodecomp_all.sh [overlays]`: o anterior em todos os overlays.
- `proj.apply_lock()`: trava usada por `autodecomp --apply` e `fn.py apply`; dá para integrar à mão enquanto o `autodecomp_all.sh` roda.
- `tools/arity.py`: aridade das funções pelo asm (vai para o contexto do m2c). `tools/audit_args.py`: revisão semântica de argumentos.
- `tools/perm_batch.sh [segundos] [threads]`: permuter em lote sobre `build/perm/`.
- `tools/fn.py <alvo> <func> show|test|apply <arq.c>`: decompilação manual. No `apply`, `typedef`s do arquivo vão para o header, `extern` de dados para o `_data.h`.
- `tools/propagate.py`, `tools/perm_setup.py`: ver acima.
- Dados: prefira array (`extern s32 X[];`) a escalar `NOT_GP` — com escalar o gcc grava via `$at`, e o original usa registrador (arrays/structs).
- Máquinas de estado: `switch (obj->state) { case 0: default: obj->fn38(obj); break; case 1: case 2: case 3: ...; }` — o `case 0:` explícito junto do `default` muda a árvore de comparações (`beqz` antes do `bltz`). A ordem dos `case` no fonte também muda o código.
- A ordem dos comandos no fonte importa mesmo quando o escalonador move os `sw` (ex.: conversões `s16` de parâmetros aparecem onde o fonte usa o parâmetro primeiro).
- Padrões aprendidos (GCC 2.8.1): retorno antecipado `if (x >= N) return -1;` costuma bater melhor; `return 1` compartilhado no fim em vez de `if/return 0/1` (senão vira `slt`/`xor`); campo de struct global acessado com offset na instrução pede ponteiro-base local (`u8 *p = D_X; *(s32 *)(p + off)`) ou struct; o tipo declarado de um símbolo muda o agendamento — valide com a declaração final.
- `make split` apaga `build/` (inclusive `build/autodecomp/`).

### Ferramentas (`tools/`)
- `ovl_bounds.py`: estima os limites rodata/text/data de cada overlay.
- `gen_ovl_yaml.py`: gera os yaml dos overlays a partir do `ovl_bounds`.
- `psyq_match.py`: casa as assinaturas do `lab313ru/psx_psyq_signatures` com o EXE (`versoes`, lista, `--syms` para o `symbol_addrs.txt`, `--yaml` para os subsegmentos). Para baixar as assinaturas: `git clone --depth 1 https://github.com/lab313ru/psx_psyq_signatures tools/psyq_sigs`.
- `cc.sh <in.c> <out.o> [G]`: compila um `.c` isolado como o jogo (GCC 2.8.1 + maspsx), para testar funções fora do build. Os compiladores vêm de `decompals/old-gcc` (release 0.17, `gcc-2.8.1-psx.tar.gz`) extraídos em `tools/old-gcc/<versão>/`.
- `cc_cmp.py <o> <exe> func_XXXXXXXX...`: compara funções compiladas com o EXE, ignorando campos relocados.
- O `readelf` está em português neste sistema: scripts que leem a saída dele precisam de `LANG=C`.

## Arquivos do disco
| Caminho | Conteúdo |
|---|---|
| `extraido/SLES_049.36` | Executável principal (PS-X EXE) |
| `extraido/SYSTEM.CNF` | `BOOT = cdrom:\SLES_049.36;1`, `STACK = 801FFF00` |
| `extraido/AAA/PRO/*.PRO` | 318 overlays de código (binário cru, sem cabeçalho) |
| `extraido/AAA/DAT/` | Assets: `FIELD`, `FIGHT` (modelos e efeitos), `Z_STAGE` (cenários), `SOUND`, `COUNTRY/<idioma>` (textos), `SCREEN`, `CARD`... |
| `extraido/AAA/STR/` | Vídeos FMV (.STR) |
| `extraido/DUMMY` | Preenchimento (~35 MB) |

## Executável `SLES_049.36`
Layout (endereços de RAM; offset no arquivo = endereço − 0x80010000 + 0x800):

| Faixa | Conteúdo |
|---|---|
| `0x80010000–0x80010E88` | rodata (do jogo e, a partir de `0x800102D8`, das libs) |
| `0x80010E88–0x80010F4C` | `2MBYTE.OBJ` da PsyQ: `__main`, `__SN_ENTRY_POINT` |
| `0x80010F4C–0x80020D8C` | **código do jogo** (`src/main.c`, ~64 KB, 345 funções) |
| `0x80020D8C–0x8003EDCC` | PsyQ 4.7 (libpad, libgpu, libgs, libgte, libcd, libsnd, libspu, libmcrd, libcard, libapi, libc2) |
| `0x8003EDCC–0x8005CCE8` | data (inclui a área pequena acessada via `$gp`, ~`0x8005CCxx`) |
| `0x8005CCE8–0x800A5DE0` | zeros no arquivo: bss (zerada pelo entry até `0x80082CB0`) + área dos overlays |
| `0x800A5DE0–0x800F0DF4` | TIM de boot 320×480 16 bpp |


- Endereço de carga `0x80010000`, tamanho do texto `0xE1000` (vai até `0x800F1000`), entrada (pc0) `0x80010E90`, gp `0`.
- Região "SLES": `Sony Computer Entertainment Inc. for Europe area`.
- sha1 `ae75434288284f85ecf01103705c38998ba30984`. É o **EXE com patch**; pode ser diferente do retail. Se aparecer um EXE original, comparar e preferir o original como alvo do matching.
- Strings e rodata das bibliotecas aparecem logo no início (`0x800102d8`...).
- Região zerada em `0x8005CCDE–0x80082CB0` (provavelmente bss gravada no arquivo) e de novo até `0x800A5DE0` (área dos overlays de nível 1).
- Em `0x800A5DE0` o EXE guarda uma imagem **TIM** de 320×480 em 16 bpp, usada no boot e depois sobrescrita pelos overlays de nível 2.

## Overlays (`AAA/PRO`)
| Nível | Endereço de carga | Arquivos |
|---|---|---|
| 1 | `0x80082CB0` | 22 arquivos que não começam com W: `CARDGAME`, `CNTY_SEL`, `FIELDSTG`, `FIGHTSTG`, `SDIGIEDT`, `SFSTDATA`, `SHOCKTST`, `SMDLDATA`, `SOUNDTST`, `STAGSLCT`, `STCRDABM`, `STCRDDEK`, `STCRDSHP`, `STDGNAME`, `STDWTITL`, `STFGTREP`, `STGDGLAB`, `STGMCARD`, `STGTRAIN`, `STITSHOP`, `STPLNMET`, `STSTATUS`. O maior (CARDGAME, `0x23130`) termina exatamente em `0x800A5DE0`. |
| 2 | `0x800A5DE0` | 296 arquivos `W*`: `WSTAG###` (scripts de mapa) + `WFIGHTMN`, `WFIGHTTS` |

Como validei: os alvos de `jal` internos caem em prólogos de função (`addiu sp,sp,-N`) em cerca de 84% dos casos nos dois níveis. O restante são funções folha. Os scripts estão em `ferramentas/ovlbase.py` (estima a base) e `ferramentas/verify.py` (valida). Rode com `python3 -I script.py <caminho>`.

`SDIGIEDT`, `SFSTDATA` e `SMDLDATA` têm poucos ou nenhum `jal` e podem ser só dados (editores de debug?). Falta confirmar.

## Bibliotecas e compilador
- **PsyQ 4.7**, pelas assinaturas: a 4.7 casa tudo o que a 4.6 casa e mais (inclusive o `PDRESRES.OBJ` inteiro, de 7,5 KB). LIBCD e LIBPAD só casam a partir da 4.6. As strings `$Id: sys.c ... 1998` só mostram que a libgpu não mudou desde 1998.
- 8 stubs curtos ficaram sem nome por serem ambíguos (setters/getters com assinatura igual), por exemplo `func_8002E25C`/`func_8002E27C` na libcd (provavelmente `CdSyncCallback`/`CdReadyCallback`). Eles estão em `asm/psyq/<lib>/<offset>.s`.
- **Compilador: GCC 2.8.1** (o 2.8.0 dá o mesmo resultado; 2.7.2 erra o epílogo, 2.91.66 e 2.95.2 erram o agendamento). Flags: `-O2 -funsigned-char -fpeephole -ffunction-cse -fpcc-struct-return -fcommon -msoft-float -mgas -fgnu-linker`. O EXE usa `-G4` ou `-G8` (há acesso via `$gp`); os overlays não usam `$gp` (provavelmente `-G0`). A versão do ASPSX (2.79/2.81/2.86) ainda não foi distinguida; o padrão é 2.86. O maspsx precisa de `--dont-force-G0`.
- A comparação com decomp.me não foi necessária: tudo foi feito localmente com `tools/cc.sh` + `tools/cc_cmp.py`.

## Próximos passos
0. Reteste r4 concluído em 2026-10-23 (só 1 nova). Seguir com as pequenas: `python3 -I tools/pending.py --skip build/w/skip.txt | grep -v " main "` (lista em ~50 instruções). As que quase bateram estão em `build/w/skip.txt` / `wip/ovl/` — boas candidatas para o permuter.
1. **Permuter em segundo plano** (`tools/perm_batch.sh 1200 6`, log em `build/perm/batch3.log`) pode estar rodando: só escreve em `build/perm/`, não mexe nos fontes. Ao terminar, veja `build/perm/zero.txt` e as pastas `output-0-*`; revise o C (tirar `new_var`, casts estranhos) e integre com `tools/fn.py`. Lista das difíceis do EXE: `wip/main/hard.txt`.
2. **Overlays, das menores para as maiores** (rendeu muito em 2026-10-17): liste as pendentes por tamanho (ver script em `build/w/` ou refaça: contar linhas `/* ` no `.s`), escreva o C com `tools/fn.py <alvo> <func> show/test/apply` e rode `tools/propagate.py` de tempos em tempos (leva o C para as cópias idênticas em outros overlays).
3. Geradores por forma: `tools/twocall.py` (duas chamadas `D_80048ABC.fn(K, n)`, 97 funções nos WSTAG); vale procurar outras formas repetidas com constantes diferentes (o `propagate.py` só junta formas idênticas). Ferramentas novas: `tools/mkobj.py` (funções que só criam objeto com `func_800143DC`/`func_80014504`), `tools/nearfix.py` (quase-certas do autodecomp: base local, parâmetros pulados), `tools/stmtperm.py` (testa a ordem das instruções simples).
4. `STDWTITL` a partir de ~0x87300 não preenche delay slots (outra versão de ASPSX/biblioteca?) — investigar antes de decompilar ali.
5. `func_8001A2AC` do EXE (`wip/main/8001A2AC.c`) bate, mas integrada desloca a rodata em 8 bytes (alinhamento da jtbl gerada pelo C).
6. Corrigir a divisão do splat em `func_800148C0` (`make split` apaga `build/` — fazer quando nada estiver rodando).
7. Revisão semântica para o port (`tools/audit_args.py`).
8. Jobs em segundo plano: parar com `tools/stop_jobs.sh` e commitar com `tools/commit_locked.sh "msg"`.

### Notas da decompilação manual (2026-11-09, 4ª sessão)
- **Abaixo de ~140 instruções só sobram a família "inicialização de mapa" (309 funções, `D_80099D80`) e o `skip.txt`.** Lista em `build/w/mapinit.txt` (regerar: pendentes cujo `.s` cita `D_80099D80`).
- Diagnóstico da inicialização de mapa (WSTAG366 `func_800A5ED0`, testes em `build/mi/`): o 3º argumento da 1ª chamada é o próprio descritor (`a2 = &D_80099D80`, `fn40(0, ID|1, m)`); com `struct` para o sistema (`D_8009B6C4.fn40`) some o `addiu s0,64`. O que falta é o agendamento: no dump `-dS` do GCC os `sw` do descritor têm prioridade 1 e saem na ordem do fonte, mas o `sw 0x44` (de `D_8005CCA8 + 0xE1`) tem prioridade 2 e vai para o fim; no original ele fica logo depois do `0x1C`. A ordem do fonte, `volatile`, endereço literal, ponteiro local, `inline` e `asm` de barreira não mudaram nada. `-fno-schedule-insns` chega mais perto, mas os outros C dos WSTAG precisam do sched1. O `tools/fn.py` agora aceita `CCSH=<script>` para testar outro compilador ou outras flags.
- **`addPrim` com campo de bits**: `typedef struct { u32 addr : 24; u32 len : 8; } PTag24;` e `((PTag24 *)p)->addr = ((PTag24 *)ot)->addr; ((PTag24 *)ot)->addr = (u32)p;` reproduzem a ordem das máscaras `0xFF000000`/`0xFFFFFF` (FIGHTSTG `func_80084BC0`). Nas quase do `wip/` (CARDGAME `func_800A32D8`, FIGHTSTG `func_80092E18`) piorou; lá o problema é outro.
- Índice de linha com deslocamento separado (`s4 = i*0x2C` além do ponteiro): agrupe `w + (i * 0x2C + j * 4) + 0x28` (STITSHOP `func_8008A1FC`).
- Tabela `T + idx*16 + i*4` com a soma antes da base: `*(s16 **)((i * 4 + idx * 16) - -(s32)tb)` (FIELDSTG `func_80085BD4`).
- Máquina de estados com `switch` 1..3 e `beq 1; slti 2; beq 2; beq 3`: ponha `case 0: default:` nos `switch` e teste a ordem dos `case` do `switch` interno (WSTAG785 `func_800A62B4`; o `stmtperm` não cobre isso, gerei as 24 permutações).
- Laço `for (i = 0; i < n - 2; i++, p++)` (o `p++` na expressão do `for`) manteve o `nop` do load (STGDGLAB `func_8008C278`).
- `if (a) {...} else {...}` mudando o ponteiro de janela: chamada com `t = (u8 *)D_8004B7D0;` repetido num bloco `{ }` próprio quando o original recarrega o `lui` (CARDGAME `func_80087B80`).
- Variável nova (bloco `{ u8 *r = ...; }`) quando o original deixa o endereço em `v0` em vez de `s`-reg (CARDGAME `func_800999A0`).
- Rodata da própria função (`dlabel` no `.s` da função) usada como argumento: `static const S16x4 r = { { 0, 0x78, 0x7FFF, 0 } };` dentro da função (FIGHTSTG `func_800880F0`); com `extern` o link falha.
- Leitura de controle (`fn3F4`/`fn3FC` + `fn408`): copie o modelo da SHOCKTST `func_80083064`; antes do grupo `0xD`/`0xE`, `t = (u8 *)D_8004B7D0;` de novo (STPLNMET `func_80087774`, STDGNAME `func_80085B70`).
- Quase (em `wip/ovl/`): STSTATUS `func_8008F2B4` (só registradores; permuter 80, artificial) e `func_80083914` (o `lui` de `D_8005CCA8` vai para `s6`; mais 5 cópias com outra tabela: `func_8008519C`, `func_8008B944`, `func_8008ED04`, `func_80094144`, `func_80096744`), WSTAG805 `func_800A6724` (33: ordem dos loads em `o->58 ± o->60`).

### Notas da decompilação manual (2026-11-09, 3ª sessão)
- **Família `D_80048ABC.fn10` + `func_800853F8` (eventos de mapa nos WSTAG)**: declare `u8 *f = (u8 *)&D_80048ABC;` **dentro de um bloco `{ }` próprio para cada `if`** (o original recarrega `lui/addiu` em cada bloco, com o `li a0` antes do `lui`). Rendeu ~15 funções (WSTAG400/405/406/490/300/295/735/421/475/750...).
- Nessa família, **cada sucesso grava `w[k] = func_800853F8(K); goto end;`** (uma gravação por ramo, o GCC funde depois): com `a = K; goto call;` e uma gravação só, `o`/`w` trocam de `s`-reg (WSTAG620, WSTAG212). O ponteiro `d = D_80048D34` (campo `0x263C`) também vai num bloco `{ u8 *d = ...; }` por grupo.
- Ainda não fecham: `o`/`w` trocados com 1–2 gravações (WSTAG206/395/285/226 `func_800A6228`/580/210 `func_800A73DC`) e `v`/`f` trocados quando há um laço antes (WSTAG310/311/820). Na WSTAG310 o permuter zerou com `if (D_800A8504 || f) { bloco 0x2A9 } else { igual }` (artificial). WSTAG305 `func_800A60B4`: 43 dif., só o delay slot do último `bne`. Rascunhos em `wip/ovl/`.
- Leitura de animação com `switch (v) { case 0x12C: ...; case 0xFF: ...; default: ... }` nessa ordem, e **variável separada** (`q`) para o ponteiro do `case 1` (senão ele vai para `s0`) (WSTAG526 `func_800A693C`/`func_800A6178`). Na `func_800A6178` o `p[9]` recebe o retorno da chamada.
- `if (k == 0x320) f(o,1); else if (k == 0x324) f(o,0);` com o `jalr` fundido: `switch` com `case 0x324` antes do `case 0x320` (WSTAG780 `func_800A6F40`).
- `if (x <= 0 && y >= 0) q = 0; else if ... else q = 0;` (com o `else` final) na atan2 da WSTAG526 `func_800A6CC8`.
- Retorno antecipado ao contrário: quando o original faz `bne`/`beqz` para o caso útil e `j fim; v0 = 0` no outro, escreva `if (ok) { ...; return p; } return 0;` (FIELDSTG `func_80089F24`, FIGHTSTG `func_80087EE4`).
- O truque `(x - -(y))` resolveu várias pequenas do `skip.txt` (FIELDSTG `func_800927A0`, FIGHTSTG `func_800A15A8`, STITSHOP `func_80088830`, CARDGAME `func_800A4924`); parâmetro `s32` (não `u8`) quando o original grava com `sb` mas carrega com `lw` da pilha (CARDGAME `func_800A3558`).

### Notas da decompilação manual (2026-11-09)
- `build/w/skip.txt` agora lista também as que só foram olhadas e parecem longas (não só as tentadas); a lista de `pending.py --skip` fica menor.
- **Mais chamadas sem argumento** (o `a0` sobra de uma comparação anterior com 1): `D_8009B5D0()`/`D_8009B5D4()` (STSTATUS `func_80099894`), `fn2714()` do `D_80048D34` (STCRDDEK `func_80089E98`), `fn150()` do `D_8004DE10` (CARDGAME `func_80095BFC`).
- O jogo tem erros reais que precisam ser reproduzidos: na WSTAG480/481 `func_800A5F84` a 5ª entrada (`o+0x74`) lê `D_800A685C[3]`, não `[4]`.
- Laço decrescente com ponteiro (`for (i = 14; i >= 0; i--) { p[0x151] = 0; p -= 0x4C; }`): quando o original usa outros registradores, declare `j`/`q` num bloco `{ }` próprio (CARDGAME `func_80092438`).
- Laços aninhados com `w[i*2 + j + 1]`: `b = f(...); q = (u8 *)w + (i * 8 + j * 4); *(u8 **)(q + 4) = b;` (STSTATUS `func_80091E94`).
- Dois quocientes iguais (`v / n` duas vezes): o original guarda o segundo e multiplica o primeiro; `*(o+0x64) = v / n * m; *(o+0x88) = v / n;` chega perto (STSTATUS `func_8009946C`, em `wip/`; a chamada final é fundida com a do outro ramo).
- Quase (em `wip/ovl/`): STGTRAIN `func_80084064` (4; permuter 100), STSTATUS `func_800853E0` (registradores das bases; permuter 245), `func_8008865C`, `func_8009946C`, WSTAG460 `func_800A6118` (fim fundido), CARDGAME `func_80095BFC` (retorno `s8` e cross-jump).
- (2ª sessão) Leitura de controle com duas máscaras: escreva tudo numa expressão só, `if ((fn3FC(0) & (1 << fn408(0, 7))) | (fn3F4(0) & (1 << fn408(0, 7))))`; com temporários (`a = ...; b = ...`) os registradores mudam (CARDGAME `func_8008BE04`).
- (2ª sessão) Chamada final com argumento condicional: `if (o->10 < 3) f(o, 1); else f(o, 0);` gera os dois `li a1` do original; `f(o, c < 3 ? 1 : 0)` vira `slti` (STCRDABM `func_80083848`, STCRDSHP `func_80085DA0`).
- (2ª sessão) FIGHTSTG `func_80098A84` bate no C, mas o `make` falha (jump table `jtbl_80083124` na rodata); C em `wip/ovl/`. SHOCKTST `func_800833C0` (rascunho) também em `wip/ovl/`.

### Notas da decompilação manual (2026-11-04)
- **Finais iguais fundidos pelo GCC** (`j` para o `jalr` do outro ramo, função 16 bytes menor): declare um dos ponteiros com outro retorno (`void` num, `s32` no outro); o RTL muda e o cross-jump não acontece (CNTY_SEL `func_80082CE8`).
- **`move` depois da divisão**: `c = i / 9; r = c; c = i - r * 9;` em vez de `i / 9` + `i % 9` (STCRDDEK `func_800835D8`). Com soma ao fim: `c = n / 6; r = c; c = n - r * 6; c = c != 0; c = r - -c;` (STCRDSHP `func_80087A2C`).
- **Mesma variável com dois tipos**: quando o registrador do ponteiro segue vivo depois do primitivo, use um `p` só e `p++` em vez de `m = (DrMode *)(p + 1)` (FIGHTSTG `func_8009E77C`).
- Elemento de animação/janela com `addu a0,s,s2` e `s2` começando em `0x50`/`0x5C`: `o + (i * 8 + 0x50)` no argumento e `*(T *)(o + i * 8 + 0x50)` no load criam as duas variáveis de indução (WSTAG780 `func_800A67A4`, WSTAG740 `func_800A6324`, WSTAG800 `func_800A6344`). Sem chamada no meio: `b = f(); q = (u8 *)w + (i * 4 + 0x18); *(u8 **)(q + 4) = b;` (STGDGLAB `func_80087070`); com a carga antes da chamada: `q = ...; z = *(u8 **)(q + 0x34);` (STSTATUS `func_800891A4`).
- Endereço içado para `s`-reg antes do laço: `i = 0; f = func_X; for (; i < n; i++)` (WSTAG740). `lui` só depois do teste do laço: atribua a base **dentro** do laço (`d = (u8 *)D_X;`), o GCC iça depois do teste (STCRDABM `func_800835BC`, STSTATUS `func_80084A98`, STCRDDEK `func_800835D8`).
- Registro por byte `lb a2,0x7C(s0)` sem dobrar o offset: base local logo antes do uso, `d = (s8 *)D_80048D34; (id + d)[0x7C]` (STCRDSHP `func_800835B8`, STSTATUS `func_8008F0DC`).
- `base + K` num `s`-reg antes de somar o índice: `k = f(); d += 0x75C; e = k * 0x3DC + d;` (STSTATUS `func_8008886C`). Em `t + idx*32`, com o índice no registrador do resultado: `e = *(u8 **)(t + 8); t += 0x10; e = (u8 *)((s32)e << 5); e = e + (s32)t;` (FIGHTSTG `func_80090C8C`).
- Parâmetro `u8` muda o chamador (ele mascara antes): se o `make` quebrar com a função batendo, volte para `s32` (CNTY_SEL `func_80083000`). `CgPt16` por valor: `sw a1,0x24(sp)` na entrada (CARDGAME `func_800A32D8`).
- `switch` com `default` antes de valores especiais (`default: guarda; case 0xFF: ...; case 0x12C: ...`) gera `beq; beq; guarda` (WSTAG740). `case 1: default:` quando o `sltiu` da jump table cai no caso 1 (SHOCKTST `func_80082EC4`).
- Quase: CARDGAME `func_800A32D8` (só `a2`/`a3` das máscaras), FIELDSTG `func_8008ED2C` (4: `a0`/`v1`), STCRDSHP `func_80088CA0` (`a1`/`v1`; permuter 30) e `func_80087D00` (zero constante num `s`-reg), WFIGHTMN `func_800A66B0` (variável de indução `+10`), STGTRAIN `func_800863D4`, STSTATUS `func_800980B0` (um `s`-reg a mais). FIGHTSTG `func_8009DF78` bate, mas o `make` falha (jump table). C em `wip/ovl/`.

### Notas da decompilação manual (2026-10-30)
- `pending.py` lista muitas da família "inicialização de mapa" (`D_80099D80`) no topo; filtre com `grep -q D_80099D80` no `.s` para achar as outras.
- **Leitura de script** `o->8C` (FIGHTSTG): `x = *(*(s16 **)(o + 0x8C))++;` repetido (o GCC usa offsets do mesmo ponteiro); um `p` local com `o->8C = p` não bate. `switch (*(*(s16 **)(o + 0x8C))++)` com `case 1..4: break;` explícitos gera a árvore `slti 5 / bgtz / beqz`.
- Atribuição usada como base: `*(s32 *)((*(u8 **)(x + 0x3C) = f()) + 0x50) = ...` (FIGHTSTG `func_8008B69C`).
- **Chamadas sem argumento**: quando o original não carrega `a0` antes do `jalr` (o valor sobrou de antes), a função não recebe parâmetro (`D_80089B98()`, `D_8004DC0C()` = rand). Base local `t = (u8 *)D_800519EC; (t + 0x4274)` para campos grandes.
- `k*0x60 + idx*32 + D`: `t = k + 0x60; p = t + D_800A4470;` (WFIGHTMN `func_800A8770`). Não resolveu a FIGHTSTG `func_8009C8B0`.
- Ponteiros de janela usados direto na chamada (`(*(fn)(w[5] + 0x114))(w[5], ...)`) quando o original relê `w[i]` em `a0` a cada chamada (STITSHOP `func_80083810`, STSTATUS `func_80094558`).
- Retorno lido antes do `sb` final (`r = e->type; base[0xAF1] = k; return r;`) e `goto` para pôr o `return 0` no meio (FIGHTSTG `func_8009BA4C`).
- Expressão repetida nos dois ramos (`v = a[0x2F] + a->8 / 8` em cada um) mantém o `lh` duplicado (FIGHTSTG `func_800A0B98` e irmãs `func_800A0D00`/`func_800A0FAC`/`func_800A0E68`).
- `fuzzyprop.py` sempre tenta o WSTAG800 `func_800A5DE0` e quebra (conhecido, ignorar).
- Quase: FIELDSTG `func_80087704` (6), FIGHTSTG `func_80093E44` (registradores; permuter 20), `func_8009A734` (4; permuter 20), `func_800A0A18` (11: posição do `lui` do rand), STCRDSHP `func_80087A2C` (`move` na divisão por 6), STFGTREP `func_80086924` (registradores dos parâmetros), WSTAG805 `func_800A69E8` (9: `li a0` antes do `lui` de `D_80048ABC`), CARDGAME `func_8009A82C` (agendamento; permuter 505), FIGHTSTG `func_8009ADD4` (rascunho). C em `wip/ovl/`.

### Notas da decompilação manual (2026-10-29)
- Elemento de 76 bytes com operandos do `addu` trocados: `(x - -((b + o->43C) * 76))` (CARDGAME `func_80089F18`).
- Ponteiro local `s16 *arr = (s16 *)(o + 0x678)` separa as variáveis de indução (CARDGAME `func_80085DE8`).
- Ponteiro de função por índice: `((s32 (*)(s32))D_80044B38[0x109])(...)`; `i = 0` depois da 1ª chamada muda o registrador (WSTAG795 `func_800A6234`).
- **Struct passada por valor como argumento** (`a1/a2` + `a3`/pilha carregados fora de ordem): `((s32 (*)(u8 *, Pair32, Pair32))f)(o, D[k], d)` (FIELDSTG `func_8008DFEC`).
- `rand()` via `D_8004DC0C` sem argumentos; `v = r->b[6]; k = v + v * (...) / 128;` e base local `s32 *tb = (s32 *)D_800A4460;` em cada ramo (FIGHTSTG `func_800A08C8`).
- Ao mudar a assinatura (retorno `u8 *`/parâmetros), corrija os chamadores (`func_800A61F0` WSTAG800, `func_8008AD78` CARDGAME).
- Quase: FIELDSTG `func_80087704` (6 instr.: ordem do `lh` de `w`; ordem dos loads step/t0/t1 acerta os registradores), FIGHTSTG `func_80093CF4` (16: s2/s3 trocados), CARDGAME `func_8009EEFC` (permuter sem zero), STGDGLAB `func_80083334` (rascunho). C em `wip/ovl/`.

### Notas da decompilação manual (2026-10-28)
- Família CARDGAME com `o + j*0x72` (mão do jogador, `0x72C` = nº de cartas): use `(o - -(j * 0x72))[0x72C]` no laço e `(o + (i * 14 - -(j * 0x72)) + off)` no elemento. Resolveu `func_800A3E9C`/`func_800A3F48`/`func_800A4078`/`func_800A41F8`.
- STDWTITL tem o exemplo de vídeo da PsyQ (movie.c): `strNext` (`func_800835D4`), `strNextVlc` (`func_800836D8`), `strCallback` (`func_80083760`) com a struct `DecEnv` (types.h) e `StHeader` (`frameCount` +8, `width`/`height` +0x10). Usar as structs (não `u8 *`) fez bater. `strInitDecEnv` (`func_80083478`) ainda não (agendamento).
- Família STDWTITL/STDGNAME/STPLNMET/STCRDDEK "estado com contador" (`func_80084CD4` e cópias com constantes `0x58`/`0x5C` diferentes): adaptar o C trocando constantes; `fuzzyprop` pega parte.
- Constante guardada num `s`-reg que o original carrega antes do contador do laço (`li v1,10` antes de `li s0,1`): ponha o valor numa variável (`v = 10; ... = v;`).
- Acesso por campo de struct global (`tb[slot].b[6]`) em vez de ponteiro `e = &tb[slot]` muda a ordem do `addu` (FIGHTSTG `func_8008F5D4`).
- `if (st[4] == 0) return; switch (...)` separa o teste de zero da árvore do `switch`.
- Permuter rápido para funções pequenas: `tools/perm_setup.py <ovl> <func> arq.c` e depois `timeout 150 .venv/bin/python tools/decomp-permuter/permuter.py -j6 --stop-on-zero build/perm/<func>` (achou o `tb = D_X; t = tb[0];` da `func_800836D8`).

### Notas da decompilação manual (2026-10-26)
- `tools/gen_scrinit.py`: gerador para a família "inicialização de tela" (`D_8004DE10` fn150/fn154/fn174/fn16C/fn12C + construtor); usa `build/w/n22.c` como modelo. Rodar de novo quando houver mais pendentes com essa forma.
- Família "inicialização de mapa" (`func_800A5E84`/`func_800A6080`..., dezenas de WSTAG): com uma `static inline` recebendo os argumentos da 1ª chamada (`map_call(0, ID|1, ...)`) o começo da função bate (`a0`/`a1` carregados antes dos stores). Falta a posição do load de `D_8005CCA8` + o `D_8009B6C4` em `s0` (o GCC os agenda no fim). Tentativa em `wip/ovl/WSTAG730_800A6080_inline.c`.
- Parâmetro `u8` (não `s32` + cast) quando o original faz `andi` só no uso (ex.: FIGHTSTG `func_8009BC94`).
- Constante 1 içada para um `s`-reg dentro de laço com chamada (`1 << i`, `s[i] = 1`): não resolvido (FIGHTSTG `func_8009DDD8`, `func_8009DB94`).
- Família "leitor de animação" dos WSTAG (`func_800A5DE0` e variantes recursivas com `D_8004DF9C`): todas as pendentes integradas. Formas: tabela `s16` (id, dur), `AnimEnt4` (`s16 id; u8 dur; u8 next`), `AnimEnt8` (com `s32 d` somado em `o[0]`), parâmetro `once` (para no `0xFF`, devolve `0xFF` ou volta um quadro) e `AnimSt` (`seq/frame/t`, tabela `u8 (**)[4]`). Os chamadores (`func_800A5ED4`/`func_800A5EB8`/`func_800A5F00` com `D_80099D90`) seguem o modelo `switch (o->C) { case 0: default: ... case 1: for (r = D_80099D90; r->b[2]; r++) ... }`.
- Retorno `s16` guardado sem `sll/sra` (`sw v0` direto ou comparado com `0xFF` sem `andi`): chame com cast `((s32 (*)(...))func_800A5DE0)(...)`.
- Ponteiro que anda 8 bytes por iteração junto com o índice e é iniciado **depois** das constantes do laço: escreva `*(T *)(o + i * 8 + off)` (o GCC cria a variável de indução); um `p = o` explícito sai antes delas.
- `base + idx*32 + 0x70`: `idx = *(s32 *)(t + 0xC); t += 0x10; e = t + idx * 32; ... (e + 0x60)` (mesmo truque do `+0x10` das notas anteriores).
- Busca em tabela com `do { if (p[0] == k) { ...; goto end; } p += 3; } while (p[0] != 0); end:` (FIELDSTG `func_80092110`); `for` com `break` gera outro leiaute.
- Estruturas de campo para fixar `base+idx`: `CgE0C` (`e->a[k-1]` mantém o `-1` fora do offset), `FsW10`, `DkArr78`.
- Struct local passada por endereço que fica na pilha depois da struct gráfica (`sw` em `0xB0(sp)`): declare `Pair32 p;` depois de `g` (dois `s32` soltos vão para registradores).
- `propagate.py` tenta pôr o leitor de animação (`s16 func_800A5DE0`) no WSTAG800 e quebra os chamadores (que usam o protótipo `s32 f()`); ignorar ou ajustar os chamadores com cast.
- **`lui` da tabela saindo cedo/tarde demais** (`&T[idx]`, `base + idx*8`): use uma variável-base atribuída logo antes do uso (`tb = D_X; e = &tb[idx];`). Resolveu STGTRAIN `func_800861BC`/`func_800862D0` e FIELDSTG `func_80092CA0`; ainda não as FIGHTSTG `func_8009C8B0`/`func_8009CB10`.
- Jump table do CARDGAME `func_8008423C` (`switch` de 30..40) caiu no lugar certo: o problema das notas antigas é só da jtbl no início exato da rodata.
- Busca em tabela com sentinela que relê o campo (`lh` a cada passo): `for (i = 0; T[i].id != 0; i++)` indexado, não ponteiro.
- Variável "achou" (`found = 1`) que precisa ficar num `s`-reg através de uma chamada: atribua **antes** da chamada; depois dela o GCC prova que não está viva e usa `a0`.
- Família "liga/desliga" de janelas (`w[i]->fn114(w[i], D_80044B38.fn414(D_8005CCA8 + K), n)` / `fn144(w[i], 0)`): STITSHOP `func_800836F8`, STCRDSHP `func_80087E8C`/`func_80087FAC`, STGTRAIN `func_80084270`. Lista das restantes: `grep -l '0x144(\$a0)'` nos pendentes.
- **Operandos do `addu` trocados** (o original faz `base + x`, o GCC gera `x + base`): `(o - -(x))[off]` (achado pelo permuter, CARDGAME `func_800A3D90`) ou `t = t - -(idx * 32)` (FIGHTSTG `func_800A1C18`). No `mult`: `m = h * *&m;` (FIGHTSTG `func_800A01AC`).
- Inverso do truque do `lui`: `p = &T[k]; p->campo` faz o `sll` do índice sair **antes** do `lui` (FIGHTSTG `func_80096EC8`).
- Jump table no início da rodata funcionou em STDWTITL `func_8008453C` e CARDGAME `func_80083E34`; as CARDGAME `func_800A4440`/`func_800A4494` continuam falhando (o C bate, o `make` não).
- Coordenada `s16` calculada no laço (`(s16)(i * 19 + 0x92)`): o GCC guarda o valor deslocado (`<< 16`) como variável de indução; um `s16 y += 19` não bate.
- Padrão **sem solução ainda**: elemento `k*0x60 + idx*32 + (D_800A4460 + 0x10)` com o `lui` no meio (FIGHTSTG `func_8009C8B0`/`func_8009CB10`/`func_8009FE1C`/`func_8009D61C`, WFIGHTMN `func_800AABF0`/`func_800AA9F0`/`func_800A88CC`). Bom alvo para o permuter (`tools/perm_setup.py` + `build/perm/run_r5.sh` como modelo).
- `wip/ovl/` ganhou várias quase-certas desta sessão (STSTATUS `func_80083B58`, STGTRAIN `func_8008A3E0`, STCRDDEK `func_80088D24`, STDWTITL `func_800835D4`/`func_80086834`, FIGHTSTG `func_80092E18`/`func_8008B508`, CARDGAME `func_80096828`, WFIGHTMN `func_800A77B4`/`func_800A69F0`, STAGSLCT `func_80084B70`, STCRDSHP `func_80085BAC`).
- Padrão `k*96 + idx*32 + base`: com `j = k_expr; i = idx_expr; q = j * 3 * 32 + (i * 32 + D);` o `lui` sai no lugar certo; sobram só nomes de registradores (WFIGHTMN `func_800A8AC8` a 4 instruções, `func_800A88CC` a 6; C em `wip/ovl/`).
- Índice `j + s*200` dentro de laço aninhado: guarde `k = s * 200;` no laço externo e use `(o + (j + k))[off]` (CARDGAME `func_8009EDCC`). Cuidado: `j - -(s*200)` inverte a variável de indução (`subu`).
- Chamador com parâmetro repassado que o m2c perdeu (`func_800A0548` → `func_8009EDCC(arg0, arg1)`): acrescentar o parâmetro no chamador antes do `apply`.
- Quase (2026-10-26, 5ª): FIGHTSTG `func_800A01AC` (ordem dos operandos do `mult`), `func_8009D61C` (s0/s1 trocados), STSTATUS `func_80099324` (ordem das constantes), STGTRAIN `func_80085DD8` (árvore do `switch`; talvez falte um `case`), STITSHOP `func_8008A0D0` (posição do `lw` do ponteiro), WFIGHTMN `func_800AABF0`. C em `wip/ovl/`.
- Quase (2026-10-26, 3ª): FIGHTSTG `func_8009C8B0`/`func_8009CB10` (só a posição do `lui` no cálculo final `k*0x60 + idx*32 + base+0x10`), CARDGAME `func_800A3D90` (1 `addu` com operandos trocados em `o + j*0x72`), STAGSLCT `func_80084C94` (leiaute do `if` que escolhe `±0x111`).
- Quase: STGTRAIN `func_800862D0` (só a ordem do `lui` da tabela `D_8008C364`), CARDGAME `func_800A3E9C` (o original reaproveita `j*8`), STFGTREP `func_80086844`, WSTAG625 `func_800A5F00` (ordem das comparações do retorno). Tentativas em `wip/ovl/`.

### Notas da decompilação manual (2026-10-23)
- Ponteiro local para o símbolo atribuído **logo antes do uso** (`r = &D_80042BCA[k]; ... r->b[0xB]`) faz o `lui` sair depois do cálculo do índice e impede o GCC de dobrar o deslocamento no `%lo` (`D+0xC`). Resolveu várias do FIGHTSTG.
- `base + 0x10 + idx*32` com `t+16` calculado antes: `idx = *(s32 *)(t + 8); t += 0x10; e = t + idx * 32;`.
- Ordem dos operandos do `addu`: `o[0x46F + i]` gera `i+o`; `(o + i)[0x46F]` ou campo de struct (`((T *)o)->a[i]`) gera `o+i`. O mesmo vale para índices `j * 7 + i * 57` (a ordem no fonte decide).
- `switch` com só `case 1`/`case 2` e árvore `beq 1; slti 2; beq 2`: falta um `case 0: default: break;`.
- `case 0: default:` seguido de `case 1` sozinho gera `slti 2` (não `blez`).
- Variável de resultado (`r = 0` ... `return r`) que precisa ficar viva num `s`-reg: evite `return r` antecipado; use `if (cond) r = ...`.
- Valor comparado como booleano (`(p[3] >= 0x3A) == m`): guarde em variável (`t = p[3] >= 0x3A; if (t == m)`) para manter `sltiu/xori`.
- Retorno `s16` de uma função atribuído a byte: declare a variável `u8` para não gerar `sll/sra`.
- Construtor/gráfico `func_8001F648(&g)`: struct local de 0xA0 com os ponteiros de função; o deslocamento na pilha − 0x10 é o campo.
- Funções que só trocam s0/s1 (o vs w) entre overlays idênticos (WSTAG226, WSTAG210) não fecharam; ver `skip.txt`.
- `Rec18` virou union (`b[18]`, `h[9]`).
- Tabela 2D de bytes (`D_800975C0[][9]`): declare como array 2D, não `u8 *` com `row * 9`.
- Chamada repetida nos dois ramos de um `if` (ex.: `g.fn88(...)`) mantém o `lw` duplicado do original; uma chamada só após o `if` não bate.
- Cópia de registrador antes de um `sb` (`move v0,s1; sb v0`): atribuição encadeada `r = e[0x42] = 1;`.
- **Registradores de parâmetros trocados** (ex.: `tex` em s4 em vez de s2): copie o parâmetro numa variável local no início (`s32 t = tex;`, `u8 *p = o;`). Resolveu a família gráfica WSTAG735/736/745/746/750/815/820 e a WSTAG785 `func_800A6540`; não resolveu WSTAG226/210, FIELDSTG `func_8008F128` e CARDGAME `func_8009BEAC`.
- Load repetido de um campo (o original relê `e->28`): escreva a expressão onde ela é usada em vez de guardar num temporário.
- Booleano `c == 0`/`c != 0` usado como índice: declare `u8 c` e guarde em variável (`k = c == 0`) para sair `sltiu` em vez de desvio.
- Laço com contador reaproveitado: o original pode reutilizar a variável de um laço anterior como contador do seguinte (troca de registradores).
- Comparação contra o valor do `switch` (`k == *(s32 *)(o + 0xC)` dentro do `case 1`) mantém o `bne` com registrador.
- Funções gráficas do CARDGAME (`0x25D000x`) seguem um modelo: struct `g` de `func_8001F648`, `fn7C(0x100,1)`, `fn74(0x280|0x340,0)`, `fn94`, `fn8C`, `fn84`.
- CARDGAME `func_800A4440/4494`: jump table no começo da rodata do overlay; o C não consegue colocá-la lá.

### Notas da decompilação manual (2026-10-22)
- `tools/pending.py [--skip arq] [--show N]`: pendentes por tamanho (ignora `jlabel` e a biblioteca do STDWTITL). `build/w/skip.txt` tem as já tentadas que não fecharam.
- `tools/ctor_return.py`: converte construtores `void` (só criam o objeto e preenchem campos) para devolver `Obj *`; conferir com o `make`.
- Atribuição encadeada (`a = b = c = 0`) grava na ordem inversa (c, b, a); a ordem dos `sh` denuncia.
- Permuter na `func_800859E0` (passo de interpolação, 11 cópias) não passou de 330; a inicialização de mapa (`func_800A5E84`) também segue em aberto.

### Notas da decompilação manual (2026-10-19)
- `tools/fuzzyprop.py`: propagação que ignora constantes (troca símbolos e números; valores ambíguos testam combinações). `tools/twocall.py` agora cobre N chamadas `D_80048ABC.fn(K, n)`.
- Overlays linkam com `build/ovl_syms.txt` (união de todos os `undefined_syms_auto.txt`), então o C pode citar um símbolo do EXE que o asm do overlay não usa (ex.: `&D_80048ABC + 0x10` no lugar de `D_80048ACC`).
- `propagate.candidate` leva junto as declarações de dados que o C usa e o asm não cita.
- Parâmetros gravados na pilha logo na entrada (`sw a0,0x18(sp)` ...) = struct passada por valor (ex.: `Pair32`, `Pair32x2` em `types.h`).
- Família "inicialização de mapa" (`func_800A5E84` e variantes, dezenas de WSTAG): ainda não bate; as constantes carregadas no início (t0/a3) sugerem parâmetros de função `inline`. Tentativas em `wip/ovl/WSTAG371_800A5E84*.c`.
- Funções de 2–3 instruções `jlabel` (ex.: `FIGHTSTG func_8008B66C..`) são `case` de `switch` separados pelo splat, não funções.

### Notas da decompilação manual (2026-10-17)
- Typedefs ficam em `include/types.h` (incluído pelo `common.h`): o `fn.py apply` grava lá, e assim o `propagate.py` consegue usar o mesmo C em outros overlays.
- Antes de declarar `extern` no arquivo do `fn.py`, confira a declaração que já existe em `include/ovl/<NOME>_data.h`: o apply substitui a linha e pode quebrar outras funções (ex.: `D_8004DC0C`, `D_80044F4C` são `s32 NOT_GP` nos overlays; use `((tipo (*)(...))D_X)(...)`).
- Funções que só criam objeto ou só chamam outra devolvem o valor (retorno em `v0` passa adiante): declare `Obj *`/`u8 *`/`s32` e use `return`, senão os chamadores que usam o valor não compilam. Chamadores com argumento repassado que o m2c perdeu: acrescente o parâmetro.
- Laço cuja cabeça é o início da função aparece como `j func_X` (não é recursão).
- Ordem das instruções no fonte muda o agendamento de loads/stores: `tools/stmtperm.py` testa as permutações.
- `tools/fn.py apply` mostra as linhas de erro do make quando falha.
- `fn.py apply` agora tira o `INCLUDE_RODATA` da rodata usada só pela função quando o C não cita o símbolo (string literal). Se a rodata ficar fora de ordem, o `make` falha e reverte: use `extern char D_X[];` e deixe o `INCLUDE_RODATA`.
- Rodata dentro do próprio `.s` da função (`dlabel` antes do `glabel`): o literal no C fica na posição certa.
- Heurística de alias do GCC 2.8: acesso escalar (`*(s16 *)(p + off)`) e acesso a campo de struct agendam diferente; se um `sw`/`sh` muda de lugar, troque um pelo outro.
- Parâmetro `u8` não gera `andi` na entrada (o chamador já mascara); `(u8)port` e cópia local do parâmetro mudam a alocação de registradores.
- Tipos novos em `include/main.h`: `MsgWork`, `DrawEnv`, `PolyF4`, `DrMode`, `SortList`/`SndBank`/`SndReq`/`McSave` etc.; `ScriptCtx` ganhou `end` (0x6) e `unkA`.

### Regras automáticas do autodecomp (resumo)
- Aridade das funções no contexto do m2c (`tools/arity.py`); assinatura completada com `arg0..argN` quando o corpo usa `argN` (`fix_params`).
- Variantes testadas quando não bate: `arg0`/objeto como primeiro argumento de chamadas indiretas (`add_self_args`), `M2C_FIELD((base + i*N), ...)` achatado (`flatten_fields`), constantes ≥ 0x80 em campo `s8` viram `u8`.
- Símbolos com tipo já fixado são testados com a declaração fixada e cast (igual ao que vai para o build).
- `tools/autodecomp_reps.py`: um representante por forma de função, um `Pool` só, resultados salvos aos poucos (`--run NOME` retoma), integra e propaga no fim.

## Convenções
- Conversar com o usuário em **português**.
- Nunca commitar assets ou binários do jogo no repositório.
