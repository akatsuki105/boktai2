#!/usr/bin/env python3
"""Canonicalized instruction-stream diff: your object vs. the original asm.

Usage: streamdiff.py BUILT_OBJECT SYMBOL ORIGINAL_INC
    e.g.  streamdiff.py build/boktai2/src/foo.o FUN_08012345 /tmp/foo_orig.inc

Keep a copy of the original .inc (git show HEAD:asm/... > /tmp/foo_orig.inc)
before you truncate it, so you can diff against it after edits.

Canonicalization masks what legitimately differs (branch targets, pool
offsets, immediate radix, negs/rsbs and add/adds spellings) so that every
remaining hunk is a REAL codegen difference. Remember: a diff that looks
label-only can still hide inverted branch polarity — only the ROM gate is
truth.  Set OBJDUMP to override the objdump binary.
"""

import difflib
import os
import re
import subprocess
import sys


def canon(x):
    """命令文字列を正規化して表記揺れなどの本質的でない差異を吸収する"""
    x = re.sub(r"@.*", "", x)
    x = re.sub(r"\s+", " ", x).strip()
    x = re.sub(r"^adds (r\d+), #", r"add \1, #", x)
    x = re.sub(r"\bnegs (r\d+), (r\d+)\b", r"rsbs \1, \2, #0x0", x)
    x = re.sub(r"\bip\b", "r12", x)
    x = re.sub(r"\bsb\b", "r9", x)
    x = re.sub(r"\bsl\b", "r10", x)
    x = re.sub(r"^muls (r\d+), (r\d+), \1$", r"muls \1, \2", x)
    m = re.match(
        r"^(b(?:l|x|eq|ne|cs|cc|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?(?:\.n|\.w)?) (.*)$",
        x,
    )
    if m and not x.startswith("bic"):
        op = m.group(1).replace(".n", "").replace(".w", "")
        tgt = m.group(2)
        s = re.search(r"<([^>+]+)", tgt)
        if op == "bl":
            x = f"bl {s.group(1)}" if s else f"bl {tgt}"
        else:
            x = f"{op} X"
    x = re.sub(r"\[pc, #\d+\].*", "=POOL", x)
    x = re.sub(r"=\S+.*", "=POOL", x)
    # .inc のプールラベル参照 (ldr rN, _08XXXXXX) を =POOL に正規化する
    x = re.sub(r"^(ldr r\d+), [A-Za-z_][A-Za-z0-9_]*$", r"\1, =POOL", x)
    x = re.sub(r", \[(r\d+|sp), #0(?:x0)?\]", r", [\1]", x)
    x = re.sub(r"#0x([0-9a-f]+)", lambda m: "#" + str(int(m.group(1), 16)), x)
    x = re.sub(r"#(\d+)", lambda m: "#" + hex(int(m.group(1))), x)
    return x.rstrip(", ")


def main():
    if len(sys.argv) != 4:
        print(__doc__, file=sys.stderr)
        return 2
    obj, sym, inc = sys.argv[1:4]
    objdump = os.environ.get("OBJDUMP", "arm-none-eabi-objdump")

    # ビルド済みオブジェクトから対象シンボルの命令列を抽出する
    d = subprocess.run([objdump, "-d", obj], capture_output=True, text=True).stdout
    i = d.find(f"<{sym}>:")
    if i < 0:
        print(f"{sym} not found in {obj}", file=sys.stderr)
        return 1
    nxt = re.search(r"<[A-Za-z_0-9]+>:", d[i + len(sym) + 3 :])
    body = d[i : i + len(sym) + 3 + nxt.start()] if nxt else d[i:]
    mine = []
    for line in body.splitlines()[1:]:
        m = re.match(r"\s*[0-9a-f]+:\s+[0-9a-f ]+\t(.*)", line)
        if m:
            t = m.group(1).split(";")[0].strip()
            if t:
                mine.append(t)

    # 元の .inc ファイルから対象シンボルの命令列を抽出する
    g = open(inc, encoding="utf-8", errors="replace").read()
    j = g.find(f"thumb_func_start {sym}")
    if j < 0:
        # per-function .inc ファイルには thumb_func_start がない: ファイル全体を使う
        seg = g
    else:
        seg = g[j:]
        end = re.search(r"thumb_func_start (?!" + re.escape(sym) + r")", seg)
        if end:
            seg = seg[: end.start()]
    theirs = []
    for ls in seg.splitlines():
        ls = ls.strip()
        # ディレクティブ・コメント・ラベル行はスキップ
        # ラベル付き .4byte 行 (_08XXXX: .4byte ...) も除外する
        if not ls or ls[0] in ".@" or ls.startswith("thumb_func") or ls.endswith(":"):
            continue
        if re.search(r"\.(4byte|2byte|short|byte)\b", ls):
            continue
        theirs.append(ls.split("@")[0].strip())

    # 両者を正規化して命令ストリームを比較する
    A = [canon(x) for x in mine if not x.startswith((".word", ".short"))]
    B = [canon(x) for x in theirs if not x.startswith(".4byte")]
    print(f"{len(A)} insns (yours) vs {len(B)} (original)")
    sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
    hunks = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        hunks += 1
        print(f"--- {tag} yours[{i1}:{i2}] original[{j1}:{j2}]")
        for x in A[i1:i2]:
            print("  M", x)
        for x in B[j1:j2]:
            print("  T", x)
    if hunks == 0:
        print("stream identical — run the ROM gate for the final word")
    return 0


if __name__ == "__main__":
    sys.exit(main())
