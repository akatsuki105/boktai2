#!/usr/bin/env python3
"""Canonicalized instruction-stream diff: your object vs. the original asm.

Usage: streamdiff.py BUILT_OBJECT SYMBOL ORIGINAL_INC
    e.g.  streamdiff.py build/boktai2/src/foo.o FUN_08012345 /tmp/foo_orig.inc

Keep a copy of the original .inc (git show HEAD:asm/... > /tmp/foo_orig.inc)
before you truncate it, so you can diff against it after edits.

Canonicalization masks what legitimately differs (label/symbol spelling,
pool offsets, immediate radix, negs/rsbs, bhs/bcs, blo/bcc and add/adds
spellings) so that every remaining hunk is a REAL codegen difference.
Branch targets are NOT masked: an intra-function target is resolved to a
signed instruction-index delta (`beq ~+7`), so a branch that lands on the
wrong block shows up as a hunk instead of hiding behind a masked label.
A target outside the function keeps its symbol name.  Only the ROM gate is
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
        r"^(b(?:l|x|eq|ne|cs|cc|hs|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?(?:\.n|\.w)?) (.*)$",
        x,
    )
    if m and not x.startswith("bic"):
        op = m.group(1).replace(".n", "").replace(".w", "")
        # 同じ命令の別表記に揃える (objdump は bcs/bcc、agbcc の .inc は bhs/blo を出す)
        op = {"bhs": "bcs", "blo": "bcc", "bal": "b"}.get(op, op)
        tgt = m.group(2)
        s = re.search(r"<([^>+]+)", tgt)
        if op == "bl":
            x = f"bl {s.group(1)}" if s else f"bl {tgt}"
        elif tgt.startswith("~") or tgt.startswith("&"):
            x = f"{op} {tgt}"  # resolve_targets() が解決済み
        else:
            x = f"{op} X"  # 解決できなかった (関数外への分岐など)
    x = re.sub(r"\[pc, #\d+\].*", "=POOL", x)
    x = re.sub(r"=\S+.*", "=POOL", x)
    # .inc のプールラベル参照 (ldr rN, _08XXXXXX) を =POOL に正規化する
    x = re.sub(r"^(ldr r\d+), [A-Za-z_][A-Za-z0-9_]*$", r"\1, =POOL", x)
    x = re.sub(r", \[(r\d+|sp), #0(?:x0)?\]", r", [\1]", x)
    x = re.sub(r"#0x([0-9a-f]+)", lambda m: "#" + str(int(m.group(1), 16)), x)
    x = re.sub(r"#(\d+)", lambda m: "#" + hex(int(m.group(1))), x)
    return x.rstrip(", ")


# 分岐先を解決する対象の命令 (bx はレジスタ、bl はシンボル名で比較するので除く)
BRANCH_OPS = {"b", "beq", "bne", "bcs", "bcc", "bhs", "blo", "bmi", "bpl",
              "bvs", "bvc", "bhi", "bls", "bge", "blt", "bgt", "ble", "bal"}


def split_branch(text):
    """分岐命令なら (op, target) を返す。そうでなければ None。"""
    m = re.match(r"^(b[a-z]*)(?:\.n|\.w)?\s+(\S.*)$", text.strip())
    if not m or m.group(1) not in BRANCH_OPS:
        return None
    return m.group(1), m.group(2).strip()


def resolve_targets(insns, pos_of):
    """分岐先を「現在位置からの命令数の差」に書き換える。

    ラベル名やアドレスの綴りは両者で必ず違うので、そのまま比較できない。
    かといって従来のように X で潰すと、飛び先が違う本物のバグ (do-while(0) の
    break がループ先頭に戻ってしまう類) が「一致」に見えてしまう。
    関数内に着地する分岐は index の差 (~+7 / ~-3) に、関数外へ出る分岐は
    シンボル名 (&Foo) に正規化する。
    """
    out = []
    for i, text in enumerate(insns):
        b = split_branch(text)
        if b:
            op, tgt = b
            key = tgt.split()[0].strip("<>")
            if key in pos_of:
                text = f"{op} ~{pos_of[key] - i:+d}"
            else:
                sym = re.search(r"<([^>+]+)", tgt)
                text = f"{op} &{sym.group(1) if sym else tgt}"
        out.append(text)
    return out


def symbol_range(objdump, obj, sym):
    """シンボルテーブルから対象関数の (開始アドレス, 終了アドレス) を返す。

    .inc から組み立てた関数は、中のジャンプ先ラベル (_08XXXXXX) までシンボルに
    なるため、objdump -d の見出し行だけを頼りに範囲を決めると関数の途中で
    打ち切られる。シンボルのサイズが取れるならそれを使う。
    """
    t = subprocess.run([objdump, "-t", obj], capture_output=True, text=True).stdout
    for line in t.splitlines():
        # 例: 000000e8 g     F .text\t0000005c VM_Ctrl_Switch
        m = re.match(r"^([0-9a-f]+)\s.*\sF\s\S+\s+([0-9a-f]+)\s+(\S+)$", line)
        if m and m.group(3) == sym:
            start, size = int(m.group(1), 16), int(m.group(2), 16)
            if size > 0:
                return start, start + size
    return None


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
    rng = symbol_range(objdump, obj, sym)
    if rng is None:
        # サイズが取れない場合のみ、次の見出し行までで代用する
        nxt = re.search(r"<[A-Za-z_0-9]+>:", d[i + len(sym) + 3 :])
        body = d[i : i + len(sym) + 3 + nxt.start()] if nxt else d[i:]
    else:
        body = d[i:]
    mine = []
    mine_addrs = []
    for line in body.splitlines()[1:]:
        m = re.match(r"\s*([0-9a-f]+):\s+[0-9a-f ]+\t(.*)", line)
        if m:
            if rng is not None and not (rng[0] <= int(m.group(1), 16) < rng[1]):
                continue
            t = m.group(2).split(";")[0].strip()
            # プールの定数は命令ではないので index から除く (.inc 側の .4byte と対称)
            if t and not t.startswith((".word", ".short")):
                mine.append(t)
                mine_addrs.append(m.group(1).lstrip("0"))
    mine = resolve_targets(mine, {a: i for i, a in enumerate(mine_addrs)})

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
    label_pos = {}  # ラベル名 -> そのラベルが指す命令の index
    for ls in seg.splitlines():
        ls = ls.strip()
        # ディレクティブ・コメント行はスキップ
        # ラベル付き .4byte 行 (_08XXXX: .4byte ...) も除外する
        if not ls or ls[0] in ".@" or ls.startswith("thumb_func"):
            continue
        if ls.endswith(":"):
            label_pos[ls[:-1].strip()] = len(theirs)  # 分岐先の解決に使う
            continue
        if re.search(r"\.(4byte|2byte|short|byte)\b", ls):
            continue
        theirs.append(ls.split("@")[0].strip())
    theirs = resolve_targets(theirs, label_pos)

    # 両者を正規化して命令ストリームを比較する
    A = [canon(x) for x in mine]
    B = [canon(x) for x in theirs]
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
