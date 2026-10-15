# Digimon World 3 — decompilação

Decompilação *matching* do **Digimon World 3** (PlayStation, versão europeia `SLES-04936`): código C que, compilado com o mesmo compilador do jogo, gera um executável idêntico byte a byte ao original. O objetivo final é um **port nativo para PC**, trocando as bibliotecas do PlayStation (PsyQ) pelo [PsyCross](https://github.com/OpenDriver2/PsyCross), como fez o [REDRIVER2](https://github.com/OpenDriver2/REDRIVER2).

> Este repositório **não contém nenhum dado do jogo**. Para compilar é preciso ter o seu próprio disco.

## Estado

| | |
|---|---|
| Executável `SLES_049.36` | reconstrói idêntico (ainda 100% assembly) |
| Overlays `AAA/PRO/*.PRO` | 318 de 318 reconstroem idênticos |
| Bibliotecas | PsyQ 4.7, 430 funções identificadas por assinatura |
| Compilador | GCC 2.8.1 (PsyQ) + [maspsx](https://github.com/mkst/maspsx) |
| Funções em C | 5 de prova em [`tools/compiler_probe.c`](tools/compiler_probe.c) (ainda fora do build) |

Hoje a versão alvo é a do disco com a tradução para português da romsportugues (`SLES_049.36` com sha1 `ae75434288284f85ecf01103705c38998ba30984`). Se houver um EXE europeu original disponível, ele passa a ser o alvo.

## Requisitos

Testado no Ubuntu 22.04.

```sh
sudo apt install binutils-mips-linux-gnu python3-venv make git
```

## Preparação

1. Clone com os submódulos:

   ```sh
   git clone --recursive git@github.com:felipehenriquee/dw3-decomp.git
   cd dw3-decomp
   ```

2. Ambiente Python:

   ```sh
   python3 -m venv .venv
   .venv/bin/pip install -r requirements.txt
   ```

3. Arquivos do disco. Extraia a imagem com o `dumpsxiso` (do [mkpsxiso](https://github.com/Lameguy64/mkpsxiso)) e copie para `disc/`:

   ```
   disc/SLES_049.36        executável principal
   disc/PRO/*.PRO          os 318 overlays (AAA/PRO no disco)
   ```

   Os hashes esperados estão em [`sles_049.36.sha1`](sles_049.36.sha1) e [`config/ovl.sha1`](config/ovl.sha1).

4. Compiladores antigos (só necessários para compilar C). Baixe os pacotes `-psx` da release 0.17 do [decompals/old-gcc](https://github.com/decompals/old-gcc/releases):

   ```sh
   mkdir -p tools/old-gcc/2.8.1
   curl -sL https://github.com/decompals/old-gcc/releases/download/0.17/gcc-2.8.1-psx.tar.gz \
       | tar xz -C tools/old-gcc/2.8.1
   ```

5. Assinaturas da PsyQ (só necessárias para refazer a identificação das bibliotecas):

   ```sh
   git clone --depth 1 https://github.com/lab313ru/psx_psyq_signatures tools/psyq_sigs
   ```

## Compilar

```sh
make split           # gera asm/, assets/ e linker/ a partir de disc/
make -j$(nproc)      # monta, linka e confere os sha1
```

Saída esperada:

```
build/sles_049.36: SUCESSO
overlays (318): SUCESSO
```

`make split` apaga e regera `asm/`, `assets/`, `linker/` e `build/`. Nenhum desses diretórios vai para o git.

## Organização

```
sles_049.36.yaml     config do splat para o executável
config/ovl/*.yaml    um config do splat por overlay
symbol_addrs.txt     nomes de funções (por enquanto, as da PsyQ)
include/             macros de assembly e include_asm.h
tools/               scripts do projeto (ver abaixo)
tools/maspsx/        submódulo
```

Depois do `make split`:

```
asm/main.s           código do jogo no executável
asm/psyq/<lib>/      um arquivo por objeto da PsyQ
asm/ovl/<NOME>/      código e dados de cada overlay
```

### Mapa do executável

| Endereço | Conteúdo |
|---|---|
| `0x80010000` | rodata |
| `0x80010E88` | `2MBYTE.OBJ` da PsyQ (`__main`, `__SN_ENTRY_POINT`) |
| `0x80010F4C–0x80020D8C` | código do jogo |
| `0x80020D8C–0x8003EDCC` | bibliotecas PsyQ |
| `0x8003EDCC` | data |
| `0x80082CB0` | overlays de nível 1 (`FIELDSTG`, `FIGHTSTG`, `CARDGAME`...) |
| `0x800A5DE0` | overlays de nível 2 (`WSTAG###`, `WFIGHTMN`, `WFIGHTTS`) |

### Ferramentas

| Script | Função |
|---|---|
| `tools/cc.sh <in.c> <out.o> [G]` | compila como o jogo (GCC 2.8.1 + maspsx); `G` = 8 para o EXE, 0 para overlays |
| `tools/cc_cmp.py <o> <exe> func_...` | compara funções compiladas com o original, ignorando relocações |
| `tools/psyq_match.py` | identifica objetos da PsyQ por assinatura |
| `tools/ovl_bounds.py` | estima os limites rodata/text/data de cada overlay |
| `tools/gen_ovl_yaml.py` | gera os configs do splat dos overlays |

Os scripts Python leem arquivos do disco; rode-os com `python3 -I`.

## Como testar uma função

```sh
tools/cc.sh minha_funcao.c build/teste.o 8
python3 -I tools/cc_cmp.py build/teste.o disc/SLES_049.36 func_80011DAC
```

Para gerar um primeiro rascunho em C a partir do assembly, use o [m2c](https://github.com/matt-kempster/m2c), que já vem no `requirements.txt`.

## Próximos passos

- Estrutura de C no build (`src/` com `INCLUDE_ASM` para as funções ainda em assembly).
- Separar a rodata/data das bibliotecas por objeto.
- Decompilar os overlays (confirmar `-G0`) e entender o formato dos `WSTAG`.
- Começar o port com o PsyCross.

## Créditos

- [splat](https://github.com/ethteck/splat), [spimdisasm](https://github.com/Decompollaborate/spimdisasm), [m2c](https://github.com/matt-kempster/m2c), [maspsx](https://github.com/mkst/maspsx), [old-gcc](https://github.com/decompals/old-gcc)
- Assinaturas da PsyQ: [lab313ru/psx_psyq_signatures](https://github.com/lab313ru/psx_psyq_signatures)
- Tradução para português: [romsportugues](https://www.romsportugues.com)

Digimon World 3 é marca da Bandai. Este projeto não tem afiliação com a Bandai nem com a Sony.
