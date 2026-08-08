#!/bin/zsh
# Second-opinion oracle: an independent cross-check alongside tools/diff.sh (objdiff).
#
# Where diff.sh uses objdiff's own Rust disassembler, this uses devkitARM's
# arm-none-eabi-objdump with --disassemble=<func> symbol isolation, then folds
# out addresses and link-time relocations. Two independent disassemblers agreeing
# is a much stronger signal than either alone; disagreement flags a tooling bug.
#
# It compares the CURRENT build object against the known-matching snapshot in
# expected/ (refresh with tools/refresh-expected.sh after a confirmed match).
#
# Usage:
#   tools/diff2.sh <FunctionName>            # auto-finds the .o from the map
#   tools/diff2.sh <FunctionName> <obj.o>    # explicit object (path under build/$RONNAME)
#
# Exit 0 = byte-identical (ignoring link relocs); 1 = differs; 2 = setup error.
set -e

RONNAME="boktai2"

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
FN="$1"; OBJ="$2"
OBJDUMP="${OBJDUMP:-arm-none-eabi-objdump}"
command -v "$OBJDUMP" >/dev/null 2>&1 || OBJDUMP="$DEVKITARM/bin/arm-none-eabi-objdump"

if [ -z "$FN" ]; then echo "usage: tools/diff2.sh <FunctionName> [obj.o]" >&2; exit 2; fi
MAP="$REPO/build/$RONNAME/$RONNAME.map"

# Find the object file containing FN by tracking the most recent ".text ... X.o"
# section header that precedes the "<addr>  FN" symbol line in the map.
if [ -z "$OBJ" ]; then
  if [ ! -f "$MAP" ]; then echo "error: $MAP not found (run make first), or pass the .o explicitly" >&2; exit 2; fi
  OBJ=$(awk -v fn="$FN" '
    /^ \.text +0x[0-9a-f]+ +0x[0-9a-f]+ / { cur=$4 }
    $0 ~ ("^ +0x[0-9a-f]+ +" fn "$") { print cur; exit }
  ' "$MAP")
fi
if [ -z "$OBJ" ]; then echo "error: could not locate object for $FN in map; pass it explicitly" >&2; exit 2; fi

CUR="$REPO/build/$RONNAME/$OBJ"
REF="$REPO/expected/build/$RONNAME/$OBJ"
[ -f "$CUR" ] || { echo "error: current object $CUR not found (run make)" >&2; exit 2; }
[ -f "$REF" ] || { echo "error: reference $REF not found (run tools/refresh-expected.sh)" >&2; exit 2; }

dis() {
  "$OBJDUMP" -d --disassemble="$FN" "$1" 2>/dev/null \
    | grep -E "^[[:space:]]+[0-9a-f]+:" \
    | sed -E 's/^[[:space:]]+[0-9a-f]+:[[:space:]]+[0-9a-f ]+\t//; s/[0-9a-f]+ <[^>]*>/<L>/g' \
    | grep -vE '^\.short[[:space:]]+0x0000$'   # objdump renders 2-byte align padding inconsistently; never a real diff
}
TA=$(gmktemp); TB=$(gmktemp); trap 'rm -f "$TA" "$TB"' EXIT
dis "$REF" > "$TA"
dis "$CUR" > "$TB"

NREF=$(wc -l < "$TA"); NCUR=$(wc -l < "$TB")
echo "[$FN]  $OBJ   ref=$NREF instr  cur=$NCUR instr"

if diff -q "$TA" "$TB" >/dev/null; then
  echo "  MATCH (identical instruction stream)"; exit 0
fi
# Differences that are only .word literal-vs-.rodata are link-time relocs -> still a match.
REAL=$(diff "$TA" "$TB" | grep -E "^[<>]" | grep -vE "^[<>][[:space:]]*\.word" || true)
if [ -z "$REAL" ]; then
  echo "  MATCH modulo link relocations (only .word <abs> vs .word .rodata differ)"; exit 0
fi
echo "  DIFFERS:"; diff "$TA" "$TB" | sed 's/^/    /'
exit 1
