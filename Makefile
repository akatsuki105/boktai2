ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

# Currently not supported (stub for future use)
MODERN ?= 0

# Build target
RONNAME := zoktai
BUILD_DIR := build/$(RONNAME)
ROM := $(RONNAME).gba
ELF := $(RONNAME).elf

all: $(ROM) compare

# Tools
TOOL = $(DEVKITARM)/bin
ifeq ($(MODERN),1)
  AGBCC := $(TOOL)/arm-none-eabi-gcc
else
  AGBCC := tools/agbcc/bin/agbcc$(EXE)
endif

AS := $(TOOL)/arm-none-eabi-as
LD := $(TOOL)/arm-none-eabi-ld
OBJCOPY := $(TOOL)/arm-none-eabi-objcopy

# Flags
ARCH := -mcpu=arm7tdmi -march=armv4t -mthumb 
ASFLAGS := $(ARCH) -mthumb-interwork -g

CFLAGS := -mthumb-interwork  -Wimplicit -Wparentheses -Werror -O2 -fshort-enums
ifeq ($(MODERN),0)
# Vanilla
# undef: 組み込みマクロ無効, std は 指定しなくても gnu89 っぽい？
	CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -undef -std=gnu89 -DMODERN=$(MODERN)
	CFLAGS += -fhex-asm
	LIBPATH := -L ../../tools/agbcc/lib
else
# Modern
	CPPFLAGS := -I $(DEVKITARM)/arm-none-eabi/include -iquote include -DMODERN=$(MODERN)
	CFLAGS += $(ARCH) $(CPPFLAGS) -Wno-pointer-to-int-cast -fno-toplevel-reorder -fno-aggressive-loop-optimizations -Wno-address-of-packed-member
	LIBPATH := -L $(shell dirname $(shell $(AGBCC) --print-file-name=libgcc.a)) -L $(shell dirname $(shell $(AGBCC) --print-file-name=libc.a))
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

ASM_SRCS := $(shell find asm -type f -name '*.s') src/libs/m4a_1.s
ASM_OBJS := $(addprefix $(BUILD_DIR)/, $(ASM_SRCS:.s=.o))

C_SRCS := $(shell find src -type f -name '*.c')
C_OBJS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))

OBJS := $(ASM_OBJS) $(C_OBJS)
OBJS_REL := $(patsubst $(BUILD_DIR)/%,%,$(OBJS))

SUBDIRS := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(SUBDIRS))

ifneq ($(MODERN),1)
# Special configurations required for lib files
$(BUILD_DIR)/src/libs/agb_eeprom.o: CFLAGS := -O -mthumb-interwork
endif

ifeq ($(MODERN),1)
	LDSCRIPT := ld_script_modern.ld
else
	LDSCRIPT := ld_script.ld
endif

# RULES_NO_SCAN: ビルドを伴わないルールの一覧
RULES_NO_SCAN += clean clean-code
.PHONY: all modern compare $(RULES_NO_SCAN)

modern: $(ROM)

compare: $(ROM)
	@sha1sum -c $(RONNAME).sha1

clean: clean-code

clean-code:
	rm -rf ./$(BUILD_DIR)
	rm -f $(ELF)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(ELF): $(LDSCRIPT) $(OBJS)
	@cd $(BUILD_DIR) && $(LD) -T ../../$< -Map $(RONNAME).map -o ../../$@ $(OBJS_REL) $(LDFLAGS)

$(C_OBJS): $(BUILD_DIR)/%.o: %.c
ifeq ($(MODERN),1)
	@$(AGBCC) $(CFLAGS) $< -c -o $@
else
	$(CPP) $(CPPFLAGS) $< | $(AGBCC) $(CFLAGS) -o $(BUILD_DIR)/$(subst .c,.s,$<)
	@echo ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$(subst .c,.s,$<)
	$(AS) $(ASFLAGS) $(BUILD_DIR)/$(subst .c,.s,$<) -o $@ 
endif

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

