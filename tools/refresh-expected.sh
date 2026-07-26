#!/bin/bash
# Copy current build artifacts into expected/ so that future objdiff comparisons
# treat the current state as the matching baseline.
#
# Usage:
#   tools/refresh-expected.sh                # refresh everything (slow, ~26MB)
#   tools/refresh-expected.sh src/foo/bar.o  # refresh one .o (after a match)
#   tools/refresh-expected.sh src/foo/bar.c  # convenience: same .o, .c form
#
# Run after each commit that ends with a confirmed sha1 match. Without this,
# tools/diff.sh will report spurious diffs for any function you've decompiled
# since the last refresh.

set -e
ROMNAME="boktai2"
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
SRC="$REPO/build/$ROMNAME"
DST="$REPO/expected/build/$ROMNAME"

# Sanity: make sure we're refreshing from a matching build.
if [ -f "$REPO/$ROMNAME.sha1" ] && [ -f "$REPO/$ROMNAME.gba" ]; then
  if ! (cd "$REPO" && sha1sum -c "$ROMNAME.sha1") >/dev/null 2>&1; then
    echo "refusing to refresh: $ROMNAME.gba does not match $ROMNAME.sha1." >&2
    echo "Build a matching ROM first (\`make\`) before refreshing." >&2
    exit 1
  fi
fi

if [ -z "$1" ]; then
  echo "refreshing entire expected/build/$ROMNAME/ from build/$ROMNAME/ ..."
  mkdir -p "$DST"
  rsync -a "$SRC"/ "$DST"/
  echo "done."
  exit 0
fi

# Single-file refresh. Accept either .o or .c form.
arg="$1"
case "$arg" in
  *.c) rel="${arg%.c}.o" ;;
  *.o) rel="$arg" ;;
  *)   echo "error: argument must end in .c or .o (got: $arg)" >&2; exit 1 ;;
esac
rel="${rel#./}"

srcf="$SRC/$rel"
dstf="$DST/$rel"

if [ ! -f "$srcf" ]; then
  echo "error: $srcf not found." >&2
  exit 1
fi
mkdir -p "$(dirname "$dstf")"
cp "$srcf" "$dstf"
echo "refreshed: $rel"
