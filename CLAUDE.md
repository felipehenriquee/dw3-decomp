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
- [ ] Decompilação (2026-10-17): EXE **266 de 347** (77%); overlays **1169 de 3292** (35,5%; `W*` 710 de 1646). Total **1435 de 3639 (39,4%)**.

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
1. Retomar o reteste dos `W*` (parou em ~550 de 718; os resultados ficam salvos e o `--run r3` pula o que já foi testado; no fim integra e propaga sozinho):
   `python3 -I tools/autodecomp_reps.py --retest --run r3 W > build/reps3.log 2>&1` (em segundo plano). O r2 (C/F/S) já terminou e foi integrado.
2. Permuter nas difíceis do EXE (rodar com a CPU livre, sem o reteste rodando): lista e arquivos em `wip/main/hard.txt`; `tools/perm_setup.py main func_X wip/main/X.c` cria o diretório em `build/perm/` (alguns já criados), depois `tools/perm_batch.sh 240 4`. Revisar o C antes de integrar.
3. `func_8001A2AC` (`wip/main/8001A2AC.c`) **bate** na comparação, mas o `make` falha: a jump table `jtbl_80010274` tem `INCLUDE_RODATA` próprio — ver se basta remover a linha ou se a ordem da rodata impede (aí usar `extern`, como a `D_80010234` da `func_8001AA10`).
4. Continuar o EXE à mão (~45 fora da lista difícil, de 90 a 870 instruções).
5. Corrigir a divisão do splat em `func_800148C0` (os `case`s `func_80014908`/`func_8001491C` viraram funções). Exige `make split`, que apaga `build/` — fazer quando nada estiver rodando.
6. **Revisão semântica para o port**: `tools/audit_args.py` (chamadas diretas; zerado no EXE). Chamadas indiretas ainda não são auditadas.
7. Jobs em segundo plano: parar com `tools/stop_jobs.sh` (pega a trava antes de matar) e commitar com `tools/commit_locked.sh "msg"`. Não use `pkill -f` com padrões que aparecem na própria linha de comando.

### Notas da decompilação manual (2026-10-17)
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
