BASENAME := sles_049.36
BUILD    := build
CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
PYTHON   := .venv/bin/python
SPLAT    := $(PYTHON) -m splat split
JOBS     ?= $(shell nproc)

# compilador do jogo: GCC 2.8.1 da PsyQ + maspsx (ver tools/cc.sh)
GCC_DIR  := tools/old-gcc/2.8.1
CPP      := $(GCC_DIR)/cpp
CC1      := $(GCC_DIR)/cc1
MASPSX   := $(PYTHON) tools/maspsx/maspsx.py --aspsx-version=2.86 \
            --run-assembler --dont-force-G0 --gnu-as-path=$(AS)
CPPFLAGS := -P -Iinclude -DINCLUDE_ASM_USE_MACRO_INC=1
CFLAGS   := -quiet -O2 -funsigned-char -fpeephole -ffunction-cse \
            -fpcc-struct-return -fcommon -msoft-float -mgas -fgnu-linker -w
# -G do EXE (usa $$gp); os overlays nao usam $$gp
G        := 8

ASFLAGS  := -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -EL -G0 -32 -mno-shared
LDFLAGS  := -EL --no-check-sections -nostdlib

OVLS     := $(basename $(notdir $(wildcard config/ovl/*.yaml)))
EXE      := $(BUILD)/$(BASENAME)
OVL_BINS := $(OVLS:%=$(BUILD)/ovl/%.PRO)

all: check

# os .d do splat listam os objetos de cada elf
-include linker/$(BASENAME).d $(OVLS:%=linker/ovl/%.d)

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# o .c inclui os .s das funcoes ainda nao decompiladas
.SECONDEXPANSION:
$(BUILD)/src/%.o: src/%.c $$(wildcard asm/nonmatchings/$$*/*.s) $$(wildcard include/*.h) Makefile
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) -G$(G) > $(@:.o=.s)
	$(MASPSX) -EL -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G$(G) \
		-Iinclude -o $@ < $(@:.o=.s)

# overlays: nao usam $$gp
$(BUILD)/src/ovl/%.o: G := 0
$(BUILD)/src/ovl/%.o: src/ovl/%.c $$(wildcard asm/ovl/$$*/nonmatchings/$$*/*.s) $$(wildcard include/*.h include/ovl/*.h) Makefile
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -Iinclude/ovl $< | $(CC1) $(CFLAGS) -G$(G) > $(@:.o=.s)
	$(MASPSX) -EL -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G$(G) \
		-Iinclude -o $@ < $(@:.o=.s)

$(BUILD)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips $< $@

$(BUILD)/$(BASENAME).elf: linker/$(BASENAME).ld
	$(LD) $(LDFLAGS) -T $< -T linker/$(BASENAME).undefined_syms_auto.txt \
		-T linker/$(BASENAME).undefined_funcs_auto.txt -Map $(@:.elf=.map) -o $@

# simbolos de dados usados por qualquer overlay (o C de um overlay pode citar
# um simbolo que o asm dele nao usa, ex.: &D_80048ABC + 0x10)
$(BUILD)/ovl_syms.txt: $(wildcard linker/ovl/*.undefined_syms_auto.txt)
	@mkdir -p $(dir $@)
	cat linker/ovl/*.undefined_syms_auto.txt | sort -u > $@

$(BUILD)/ovl/%.elf: linker/ovl/%.ld $(BUILD)/ovl_syms.txt
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -T $< -T $(BUILD)/ovl_syms.txt -T linker/ovl/$*.undefined_syms_auto.txt \
		-T linker/ovl/$*.undefined_funcs_auto.txt -Map $(@:.elf=.map) -o $@

$(EXE): $(BUILD)/$(BASENAME).elf
	$(OBJCOPY) -O binary $< $@

$(BUILD)/ovl/%.PRO: $(BUILD)/ovl/%.elf
	$(OBJCOPY) -O binary $< $@

check: $(EXE) $(OVL_BINS)
	@sha1sum --quiet -c $(BASENAME).sha1 && echo "$(EXE): SUCESSO"
	@sha1sum --quiet -c config/ovl.sha1 && echo "overlays ($(words $(OVLS))): SUCESSO"

# regera asm/, assets/ e linker/ a partir do disco
split:
	rm -rf asm assets linker $(BUILD)
	$(SPLAT) $(BASENAME).yaml
	ls config/ovl/*.yaml | xargs -P $(JOBS) -n 1 $(SPLAT) > /dev/null

clean:
	rm -rf $(BUILD)

.PHONY: all check split clean
