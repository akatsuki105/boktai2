# Builds the ROM using a modern compiler, currently not supported (stub for future use)
MODERN ?= 0
ifeq (modern,$(MAKECMDGOALS))
	$(error Modern build is not supported yet.)
  MODERN := 1
endif

# "echo -e" requires bash
# -o pipefail は、パイプラインのいずれかのコマンドが失敗した場合に、シェルが失敗として終了するようにします。これにより、パイプライン内のエラーを検出しやすくなります。
# Make は、途中の処理でエラーが発生するとそこで実行をストップする仕組みになっています。しかし、パイプラインの途中でエラーが起きても、最後のコマンドが成功すると、Makefile は「すべて正常に完了した」と勘違いして次の処理へ進んでしまいます。これにより、不完全なファイルが生成されるなどのバグに繋がります。
SHELL := bash -o pipefail

# Default make rule
all: compare

# Tools --------------------------------------------

TOOLCHAIN := $(DEVKITARM)
# Don't use dkP's base_tools anymore because the redefinition of $(CC) conflicts with when we want to use $(CC) to preprocess files. Thus, manually create the variables for the bin files, or use arm-none-eabi binaries on the system if dkP is not installed on this system.
# Ja: $(CC) の再定義がファイルのプリプロセッシング時に競合するため、dkP の base_tools は使用しないでください。 したがって、バイナリファイル用の変数は手動で作成するか、このシステムに dkP がインストールされていない場合は、システム上の arm-none-eabi バイナリを使用してください。
ifneq (,$(TOOLCHAIN))
  ifneq ($(wildcard $(TOOLCHAIN)/bin),)
    export PATH := $(TOOLCHAIN)/bin:$(PATH)
  endif
endif

PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
AS := $(PREFIX)as
LD := $(PREFIX)ld

EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif

# macOS では arm-none-eabi-cpp を使用してください。macOS のデフォルトコンパイラ clang であり、clang のプリプロセッサは .s ファイルをプリプロセスする際に \u 文字を検出すると警告を表示します。これは Unicodeリテラルを期待しているためです。
# ただし、binutils-arm-none-eabi をインストールする環境では、このツールがデフォルトで付属していないため、無条件に arm-none-eabi-cpp を使用することはできません。
ifneq ($(MODERN),1)
# Vanilla
  ifeq ($(shell uname -s),Darwin)
    CPP := $(PREFIX)cpp
  else
    CPP := $(CC) -E
  endif
else
# Modern
  CPP := $(PREFIX)cpp
endif

include make_tools.mk
# Tool executables
BOKASM  := $(TOOLS_DIR)/bokasm/bokasm$(EXE)
GBAGFX  := $(TOOLS_DIR)/gbagfx/gbagfx$(EXE)
SCANINC := $(TOOLS_DIR)/scaninc/scaninc$(EXE)
PREPROC := $(TOOLS_DIR)/preproc/preproc$(EXE)

# ROM name --------------------------------------------

RONNAME := boktai2
BUILD_DIR := build/$(RONNAME)
ROM := $(RONNAME).gba
ELF := $(RONNAME).elf

# Flag --------------------------------------------

ASFLAGS := -mcpu=arm7tdmi --defsym MODERN=$(MODERN)

O_LEVEL ?= 2
ifeq ($(MODERN),0)
  # Vanilla
  # undef: 組み込みマクロ無効, std は 指定しなくても gnu89 っぽい？
  CPPFLAGS := -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc -undef -std=gnu89 -DMODERN=$(MODERN)
  CC1 := tools/agbcc/bin/agbcc$(EXE)
  override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O$(O_LEVEL) -fhex-asm
  LIBPATH := -L ../../tools/agbcc/lib
else
  # TODO: Modern
endif
LDFLAGS := $(LIBPATH) -lgcc -lc

# Collect sources --------------------------------------------

ASM_SRCS := $(shell find src -type f -name '*.s')
ASM_OBJS := $(addprefix $(BUILD_DIR)/, $(ASM_SRCS:.s=.o))
ASM_DEPS := $(ASM_OBJS:.o=.d)

C_SRCS := $(shell find src -type f -name '*.c')
C_OBJS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
C_DEPS := $(C_OBJS:.o=.d)

OBJS := $(ASM_OBJS) $(C_OBJS)
OBJS_REL := $(patsubst $(BUILD_DIR)/%,%,$(OBJS))

SUBDIRS := $(sort $(dir $(OBJS)))
$(shell mkdir -p $(SUBDIRS))

# Rules --------------------------------------------

ifeq ($(MODERN),0)
# Special configurations required for lib files

# pret/pokeXXX では old_agbcc を使うが、このゲームでは使わないと思われる
# 根拠: ビルドが合わない & pretのm4aと異なるソースコード(e.g. SampleFreqSet)を使っている
# $(BUILD_DIR)/src/lib/m4a.o: CC1 := tools/agbcc/bin/old_agbcc$(EXE)

$(BUILD_DIR)/src/lib/librfu_intr.o: CC1 := tools/agbcc/bin/agbcc_arm$(EXE)
$(BUILD_DIR)/src/lib/librfu_intr.o: CFLAGS := -O2 -mthumb-interwork -quiet
$(BUILD_DIR)/src/lib/agb_eeprom.o: CFLAGS := -O -mthumb-interwork
endif

ifeq ($(MODERN),1)
	LDSCRIPT := ld_script_modern.ld
else
	LDSCRIPT := ld_script.ld
endif

# RULES_NO_SCAN: ビルドを伴わないルールの一覧
RULES_NO_SCAN += clean clean-code clean-scripts
.PHONY: all modern compare $(RULES_NO_SCAN)

NODEP ?= 0
DO_BUILD ?= 1
ifneq (,$(MAKECMDGOALS))
	ifeq (,$(filter-out $(RULES_NO_SCAN),$(MAKECMDGOALS)))
		NODEP := 1
		DO_BUILD := 0
	endif
endif

# SHELLSTATUS: 直前に実行したコマンドの終了ステータスを格納する特殊変数 (GNU Make 4.3 以降のみらしいので、未定義なら互換性のために 0 を設定しておく)
.SHELLSTATUS ?= 0

# ビルドを伴うルールの場合は tool をビルドする
ifeq ($(DO_BUILD),1)
# やっていることは単なる make -f make_tools.mk
# あとの仰々しい部分は make -f make_tools.mk のコマンドをターミナルに出すのと、 エラーが起きたときに終了するためのもの
  $(foreach line, $(shell $(MAKE) -f make_tools.mk | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))
  ifneq ($(.SHELLSTATUS),0)
    $(error Errors occurred while building tools. See error messages above for more details)
  endif
endif

modern: $(ROM)

compare: $(ROM)
	@sha1sum -c $(RONNAME).sha1

clean: clean-code clean-scripts clean-graphics

clean-code:
	rm -rf ./$(BUILD_DIR)
	rm -f $(ELF)

clean-scripts:
	rm -f data/scripts/*.inc

$(ROM): $(ELF)
	$(OBJCOPY) -O binary --pad-to 0x9000000 $< $@

$(ELF): $(LDSCRIPT) $(OBJS)
	@cd $(BUILD_DIR) && $(LD) -T ../../$< -Map $(RONNAME).map -o ../../$@ $(OBJS_REL) $(LDFLAGS)

$(C_OBJS): $(BUILD_DIR)/%.o: %.c
ifeq ($(MODERN),1)
# TODO: MODERN
else
	@$(CPP) $(CPPFLAGS) $< -o $(BUILD_DIR)/$(subst .c,.i,$<)
	$(PREPROC) $(BUILD_DIR)/$(subst .c,.i,$<) charmap.txt | $(CC1) $(CFLAGS) -o $(BUILD_DIR)/$(subst .c,.s,$<)
# 	@$(CPP) $(CPPFLAGS) $< | $(PREPROC) -i $< charmap.txt | $(CC1) $(CFLAGS) -o $(BUILD_DIR)/$(subst .c,.s,$<) -
	@echo -e ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$(subst .c,.s,$<)
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/$(subst .c,.s,$<) -o $@ 
endif

$(C_DEPS): $(BUILD_DIR)/%.d: %.c
	$(SCANINC) -M $@ -I include $<

# NODEP が 1 のときは依存関係ファイルを読み込まない、これをしないと make clean とかのときに不要な .dファイルを作ろうとしてしまう
ifneq ($(NODEP),1)
-include $(C_DEPS)
endif

$(BUILD_DIR)/%.o: %.s
	@$(AS) $(ASFLAGS) $< -o $@

$(ASM_OBJS:.o=.d): $(BUILD_DIR)/%.d: %.s
	$(SCANINC) -M $@ -I include $<

ifneq ($(NODEP),1)
-include $(ASM_DEPS)
endif

# Scripts  --------------------------------------------

BOKSCRIPTS := $(shell find data/scripts -type f -name '*.bokasm')
BOKSCRIPTS_INC := $(BOKSCRIPTS:.bokasm=.inc)

$(BOKSCRIPTS_INC): %.inc: %.bokasm
	$(BOKASM) $< $@

$(BUILD_DIR)/src/data/scripts.o: src/data/scripts.s $(BOKSCRIPTS_INC) charmap.txt
	$(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@ -

# Assets --------------------------------------------

include graphics_file_rules.mk
