#!/bin/sh
# Fast codegen probe: preprocess + compile ONE file without a full build.
# Usage (from the repo root):  scripts/microtest.sh src/foo.c [out.s]
# Prints compiler warnings/errors in seconds; inspect out.s for shapes.
# NOTE: check the makefile for per-file flag overrides before trusting
# the base flags below.
set -eu
FILE="${1:?usage: microtest.sh src/path/file.c [out.s]}"
OUT="${2:-/tmp/microtest.s}"
cpp -I tools/agbcc -I tools/agbcc/include -iquote include -nostdinc \
    -std=gnu89 -DMODERN=0 "$FILE" \
  | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit -Wparentheses \
      -O2 -fshort-enums -fhex-asm -o "$OUT"
echo "wrote $OUT"
