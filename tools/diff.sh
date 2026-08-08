#!/bin/bash
# Diff a single function (or all functions in a file) between the current build
# and the matching reference snapshot.
#
# Usage:
#   tools/diff.sh <symbol>          # diff one function
#   tools/diff.sh -f <c-file>       # diff every changed function in that file
#
# Setup it expects:
#   - expected/build/... contains .o files from a known-matching build
#     (refresh after each successful match with tools/refresh-expected.sh)
#   - build/$RONNAME/... contains your current attempt's .o files (built by `make`)
#   - build/$RONNAME/$RONNAME.map exists (always true after a build)

set -e

RONNAME="boktai2"

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
OBJDIFF="$HERE/objdiff-cli-macos-arm64"
MAPFILE="$REPO/build/$RONNAME/$RONNAME.map"
PY=$(command -v py.exe 2>/dev/null || command -v python3 2>/dev/null || command -v python)

if [ ! -x "$OBJDIFF" ]; then
  echo "error: $OBJDIFF not found. Download objdiff-cli-* v3.7.1+ from" >&2
  echo "       https://github.com/encounter/objdiff/releases and save it there." >&2
  exit 1
fi
if [ ! -f "$MAPFILE" ]; then
  echo "error: $MAPFILE not found. Run \`make\` first." >&2
  exit 1
fi

mode=symbol
if [ "$1" = "-f" ]; then
  mode=file
  shift
fi

arg="$1"
if [ -z "$arg" ]; then
  echo "usage: $0 [-f] <symbol|c-file>" >&2
  exit 1
fi

# Locate the .o for the requested symbol via the linker map.
# gnu map line we want:
#   .text  0x080ce4d0  0x39c  src/solid/locomoif_platform.o
#                 0x080ce538  FUN_080ce538
if [ "$mode" = symbol ]; then
  objrel=$("$PY" - "$MAPFILE" "$arg" <<'PYEOF'
import re, sys
mapf, fn = sys.argv[1], sys.argv[2]
cur = None
with open(mapf, encoding="utf-8", errors="replace") as f:
    for line in f:
        m = re.match(r"^ \.text\s+0x[0-9a-fA-F]+\s+0x[0-9a-fA-F]+\s+(\S+\.o)\s*$", line)
        if m:
            cur = m.group(1)
        elif cur and re.search(rf"\s{re.escape(fn)}\s*$", line):
            print(cur)
            sys.exit(0)
sys.exit(2)
PYEOF
)
  if [ -z "$objrel" ]; then
    echo "error: symbol '$arg' not found in $MAPFILE" >&2
    exit 1
  fi
else
  # File mode: take .c path, strip extension, find matching .o under build/$RONNAME/.
  base="${arg%.c}"
  base="${base#./}"
  objrel="${base#src/}"
  objrel="src/${objrel}.o"
fi

target="$REPO/expected/build/$RONNAME/$objrel"
base="$REPO/build/$RONNAME/$objrel"

if [ ! -f "$target" ]; then
  echo "error: target .o missing at $target" >&2
  echo "       Was the symbol added since the last expected/ snapshot?" >&2
  echo "       If so, refresh after the next successful match:" >&2
  echo "         tools/refresh-expected.sh $objrel" >&2
  exit 1
fi
if [ ! -f "$base" ]; then
  echo "error: current build .o missing at $base. Run \`make\` first." >&2
  exit 1
fi

tmpjson=$(gmktemp --suffix=.json)
trap 'rm -f "$tmpjson"' EXIT

if [ "$mode" = symbol ]; then
  "$OBJDIFF" diff -1 "$target" -2 "$base" "$arg" -o "$tmpjson" --format json-pretty >/dev/null
else
  "$OBJDIFF" diff -1 "$target" -2 "$base" -o "$tmpjson" --format json-pretty >/dev/null
fi

"$PY" - "$tmpjson" "$mode" "$arg" <<'PYEOF'
import json, sys

path, mode, arg = sys.argv[1], sys.argv[2], sys.argv[3]
data = json.load(open(path))

def render_symbol(sym):
    pct = sym.get("match_percent")
    name = sym.get("name", "?")
    print(f"\n=== {name}  ({pct:.4f}% match) ===" if pct is not None else f"\n=== {name} ===")
    left = sym
    # find right-side symbol with same name
    right = None
    for s in data.get("right", {}).get("symbols", []):
        if s.get("name") == name:
            right = s
            break
    lefti = left.get("instructions", [])
    righti = right.get("instructions", []) if right else []
    n = max(len(lefti), len(righti))
    for i in range(n):
        li = lefti[i] if i < len(lefti) else None
        ri = righti[i] if i < len(righti) else None
        ldk = li.get("diff_kind") if li else None
        rdk = ri.get("diff_kind") if ri else None
        mark = "    " if not (ldk or rdk) else "[!!]"
        lf = (li or {}).get("instruction", {}).get("formatted", "")
        rf = (ri or {}).get("instruction", {}).get("formatted", "")
        la = (li or {}).get("instruction", {}).get("address", "")
        ra = (ri or {}).get("instruction", {}).get("address", "")
        print(f"  {mark}  {la:>6} {lf:<40}  |  {ra:>6} {rf}")

if mode == "symbol":
    for s in data.get("left", {}).get("symbols", []):
        if s.get("name") == arg:
            render_symbol(s)
            break
    else:
        print(f"symbol {arg} not in diff output")
        sys.exit(1)
else:
    diffs = [s for s in data.get("left", {}).get("symbols", []) if (s.get("match_percent") or 100) < 100]
    if not diffs:
        print("All symbols match.")
    else:
        for s in diffs:
            render_symbol(s)
PYEOF
