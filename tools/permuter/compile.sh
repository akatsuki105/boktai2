#!/bin/bash

# see permuter_settings.toml.compiler_command
# decomp-permuter から "{infile} {outfile}" の形式で呼ばれる

set -e

SRC="$1"
# $2 = "-o"（permuter の呼び出し規約: compile.sh input.c -o output.o）
OUT="$3"

REPO="$(cd "$(dirname "$0")/../.." && pwd)"
AGBCC="$REPO/tools/agbcc/bin/agbcc"
AS="${DEVKITARM}/bin/arm-none-eabi-as"
CPP="cc -E"

CPPFLAGS="-I $REPO/tools/agbcc -I $REPO/tools/agbcc/include -iquote $REPO/include -nostdinc -undef -std=gnu89 -DMODERN=0"
CFLAGS="-mthumb-interwork -Wimplicit -Wparentheses -O2 -fshort-enums -fhex-asm"
ASFLAGS="-mcpu=arm7tdmi -march=armv4t -mthumb -mthumb-interwork"

tmp_s=$(gmktemp /tmp/perm_XXXX.s)
trap "rm -f $tmp_s" EXIT

$CPP $CPPFLAGS "$SRC" | $AGBCC $CFLAGS -o "$tmp_s"
printf ".text\n\t.align\t2, 0\n" >> "$tmp_s"
$AS $ASFLAGS "$tmp_s" -o "$OUT"
