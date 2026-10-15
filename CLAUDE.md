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
- [ ] Decompilação: EXE **188 de 347** funções em C (54%); overlays **275 de 3292** (8,4%; os `WSTAG` ainda não começaram). Total **463 de 3639 (12,7%)**.

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
1. Retomar o autodecomp nos overlays a partir do `WFIGHTTS` (parou ali; inclui os 293 `WSTAG`):
   `ls src/ovl | sed 's/\.c$//' | awk '$0 >= "WFIGHTTS"' > build/ovl_todo.txt; tools/autodecomp_all.sh $(cat build/ovl_todo.txt)`
   (~1 h; rode em segundo plano). Depois, rodar de novo nos overlays já processados (CARDGAME..WFIGHTMN): desde então o autodecomp ganhou aridade, argumentos repassados e constantes sem sinal.
2. `tools/propagate.py`: antes, ligar `disassemble_all: True` nos yaml e refazer o `make split` (gera o asm das funções já decompiladas em `.../matchings/`). Atenção: `make split` apaga `build/` (resultados do autodecomp, diretórios do permuter).
3. Permuter: `tools/perm_setup.py main --near 8` e `tools/perm_batch.sh 300 4` (as difíceis do EXE estão em `wip/main/`). Revisar o C antes de integrar.
4. Corrigir a divisão do splat em `func_800148C0` (os `case`s `func_80014908`/`func_8001491C` viraram funções).
5. **Revisão semântica para o port**: `tools/audit_args.py` (chamadas diretas com argumentos faltando; zerado no EXE). Chamadas indiretas (ponteiro de função/método) ainda não são auditadas.
6. Para parar com segurança jobs em segundo plano: pegue a trava (`proj.apply_lock`) antes de matar os processos, e não use `pkill -f` com padrões que aparecem na sua própria linha de comando.

## Convenções
- Conversar com o usuário em **português**.
- Nunca commitar assets ou binários do jogo no repositório.
