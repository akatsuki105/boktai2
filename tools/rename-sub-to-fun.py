#!/usr/bin/env python3
"""Rename sub_XXXXXXXX symbols to FUN_xxxxxxxx (project convention) across src/*.s.

sub_ is the default objdump/disassembler naming for unnamed functions; this
project's own convention is FUN_ with lowercase hex. This script performs a
pure text substitution (labels don't affect assembled bytes), scoped to
word-boundary matches of exactly 8 hex digits, across every src/*.s file so
cross-file bl references stay consistent with renamed definitions.

Usage:
  tools/rename-sub-to-fun.py            # dry run: report planned renames + collisions
  tools/rename-sub-to-fun.py --apply    # actually rewrite the files
"""
import glob
import re
import sys

SUB_RE = re.compile(r"\bsub_([0-9A-Fa-f]{8})\b")
FUN_RE = re.compile(r"\bFUN_([0-9A-Fa-f]{8})\b")


def find_files():
    return sorted(glob.glob("src/*.s"))


def collect_existing_fun_addrs(files):
    addrs = set()
    for path in files:
        with open(path) as f:
            text = f.read()
        for m in FUN_RE.finditer(text):
            addrs.add(m.group(1).lower())
    return addrs


def collect_sub_addrs(files):
    addrs = set()
    for path in files:
        with open(path) as f:
            text = f.read()
        for m in SUB_RE.finditer(text):
            addrs.add(m.group(1).lower())
    return addrs


def main():
    apply = "--apply" in sys.argv
    files = find_files()
    if not files:
        print("no src/*.s files found")
        return 1

    sub_addrs = collect_sub_addrs(files)
    if not sub_addrs:
        print("no sub_XXXXXXXX symbols found; nothing to do")
        return 0

    existing_fun_addrs = collect_existing_fun_addrs(files)
    collisions = sorted(sub_addrs & existing_fun_addrs)
    if collisions:
        print(f"REFUSING: {len(collisions)} address(es) already have a FUN_ symbol "
              f"defined/referenced elsewhere with a different case — resolve manually:")
        for addr in collisions:
            print(f"  {addr}")
        return 1

    print(f"{len(sub_addrs)} unique sub_ symbol(s) across {len(files)} file(s)")

    total_replacements = 0
    for path in files:
        with open(path) as f:
            text = f.read()
        new_text, n = SUB_RE.subn(lambda m: "FUN_" + m.group(1).lower(), text)
        if n == 0:
            continue
        total_replacements += n
        print(f"  {path}: {n} occurrence(s)")
        if apply:
            with open(path, "w") as f:
                f.write(new_text)

    print(f"total: {total_replacements} occurrence(s)"
          + (" renamed" if apply else " would be renamed (dry run, pass --apply)"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
