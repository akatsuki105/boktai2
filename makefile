ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

MODERN ?= 0

# Build target
NAME := zoktai
ROM := $(NAME).gba
ELF := $(NAME).elf

# Tools
TOOL = $(DEVKITARM)/bin
ifeq ($(MODERN),1)
  AGBCC := $(TOOL)/arm-none-eabi-gcc
else
  AGBCC := tools/agbcc/bin/agbcc$(EXE)
endif
AS = $(TOOL)/arm-none-eabi-as
LD = $(TOOL)/arm-none-eabi-ld
OBJCOPY = $(TOOL)/arm-none-eabi-objcopy
OBJDUMP := $(TOOL)/arm-none-eabi-objdump

# Flags
ARCH := -mcpu=arm7tdmi -march=armv4t -mthumb 
CFLAGS := -mthumb-interwork  -Wimplicit -Wparentheses -Werror -O2 -fshort-enums
ASFLAGS := $(ARCH) -mthumb-interwork
ifeq ($(MODERN),1)
	CPPFLAGS := -I $(DEVKITARM)/arm-none-eabi/include -iquote include -DMODERN=$(MODERN)
	CFLAGS += $(ARCH) $(CPPFLAGS) -Wno-pointer-to-int-cast -fno-toplevel-reorder -fno-aggressive-loop-optimizations
	LIBPATH := -L $(shell dirname $(shell $(AGBCC) --print-file-name=libgcc.a)) -L $(shell dirname $(shell $(AGBCC) --print-file-name=libc.a))
else
	CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -DMODERN=$(MODERN)
	CFLAGS += -fhex-asm
	LIBPATH := -L tools/agbcc/lib
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

ASFILE := $(shell find asm -type f -name '*.s') src/libs/m4a_1.s
ASOBJFILE := $(ASFILE:.s=.o)

CFILE := $(shell find src -type f -name '*.c')
COBJFILE := $(CFILE:.c=.o)

ifneq ($(MODERN),1)
# Special configurations required for lib files
src/libs/agb_eeprom.o: CFLAGS := -O -mthumb-interwork
endif

ifeq ($(MODERN),1)
	LDSCRIPT := ld_script_modern.ld
else
	LDSCRIPT := ld_script.ld
endif

.PHONY: all check compare clean clean-code

all: $(ROM) compare
check: $(ROM) compare
modern: ; @$(MAKE) $(ROM) -j8 MODERN=1

compare: $(ROM)
	@sha1sum -c $(NAME).sha1

clean: clean-src
	@rm -f $(ELF) $(ASOBJFILE) $(COBJFILE)

clean-code: clean-src
	@rm -f $(ELF) $(ASOBJFILE) $(COBJFILE) $(shell find asm -type f -name '*.o') $(shell find src -type f -name '*.o')

$(ROM): $(ELF)
	@$(OBJCOPY) -O binary $< $@

$(ELF): %.elf: $(ASOBJFILE) $(COBJFILE) ld_script.ld
	@$(LD) -T $(LDSCRIPT) -Map $*.map -o $@ $(ASOBJFILE) $(COBJFILE) $(LDFLAGS)

$(COBJFILE): %.o: %.c
ifeq ($(MODERN),1)
	@$(AGBCC) $(CFLAGS) $< -c -o $@
else
	@$(CPP) $(CPPFLAGS) $< | $(AGBCC) $(CFLAGS) -o $(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(subst .c,.s,$<)
	@$(AS) $(ASFLAGS) $(subst .c,.s,$<) -o $@ 
endif

$(ASOBJFILE): %.o: %.s
	@$(CPP) $(CPPFLAGS) $< | $(AS) $(ASFLAGS) -o $@ -

include src/src.mk
