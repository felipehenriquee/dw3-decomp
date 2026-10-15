BASENAME := sles_049.36
BUILD    := build
CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
PYTHON   := .venv/bin/python
SPLAT    := $(PYTHON) -m splat split
JOBS     ?= $(shell nproc)

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

$(BUILD)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(OBJCOPY) -I binary -O elf32-tradlittlemips -B mips $< $@

$(BUILD)/$(BASENAME).elf: linker/$(BASENAME).ld
	$(LD) $(LDFLAGS) -T $< -T linker/$(BASENAME).undefined_syms_auto.txt \
		-T linker/$(BASENAME).undefined_funcs_auto.txt -Map $(@:.elf=.map) -o $@

$(BUILD)/ovl/%.elf: linker/ovl/%.ld
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -T $< -T linker/ovl/$*.undefined_syms_auto.txt \
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
