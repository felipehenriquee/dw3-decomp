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
- [ ] Decompilação (2026-10-26, 3ª sessão): EXE **275 de 347** (79%); overlays **2027 de 3292** (61.6%). Total **2302 de 3639 (63.3%)**.

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
