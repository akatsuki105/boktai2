#!/bin/zsh
# Search the GBA decomp corpus for an instruction shape or source idiom.
#   corpus-grep.sh 'ands r0, r1'          # asm shape: who matched this?
#   corpus-grep.sh -c 'REGISTERED_WEAPON' # C idiom: how do siblings write it?
# Env: DECOMP_CORPUS (default ~/decomp/corpus)

set -eu

: "${DECOMP_CORPUS:?DECOMP_CORPUS is not set — export it before running}"

CORPUS_DIR="$DECOMP_CORPUS"

MODE=asm

if [ "${1:-}" = "-c" ]; then MODE=src; shift; fi
PAT="${1:?usage: corpus-grep.sh [-c] PATTERN}"
[ -d "$CORPUS_DIR" ] || { echo "corpus not found at $CORPUS_DIR — run setup.sh --corpus"; exit 1; }
for repo in "$CORPUS_DIR"/*/; do
  name="$(basename "$repo")"
  if [ "$MODE" = asm ]; then
    hits="$(grep -rn --include='*.s' --include='*.inc' -F "$PAT" "$repo" 2>/dev/null | head -5 || true)"
  else
    hits="$(grep -rn --include='*.c' --include='*.h' -F "$PAT" "$repo" 2>/dev/null | head -5 || true)"
  fi
  [ -n "$hits" ] && { echo "=== $name"; echo "$hits"; }
done
