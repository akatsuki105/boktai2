# Decodes custom font strings and sets them as comments in Ghidra's listing view.
# @author   akatsuki105 (2026-08-12)
# @category GBA
# @runtime PyGhidra

import os
import re
import typing

if typing.TYPE_CHECKING:
    from ghidra.ghidra_builtins import *

from ghidra.program.model.listing import CodeUnit

TERMINATOR = 0x00
CHARMAP_PATH = "./charmap.txt"

# 'char' = XX [YY ...] 形式の行にマッチする。char部分は非貪欲マッチ(絵文字などのcombining文字を想定)
_CHARMAP_LINE_RE = re.compile(r"^'(.+?)'\s*=\s*(.+)$")


def load_charmap(path=CHARMAP_PATH):
    """charmap.txt を読み込み、バイト列(tuple) -> 文字 の辞書を構築する"""
    charmap = {}

    # charmap.txt のコメント通り、0x20-0x7F はファイル内で明示された例外を除き ASCII と同じ
    for b in range(0x20, 0x80):
        charmap[(b,)] = chr(b)

    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("@"):
                continue
            m = _CHARMAP_LINE_RE.match(line)
            if not m:
                continue
            char, hex_part = m.group(1), m.group(2)
            key = tuple(int(tok, 16) for tok in hex_part.split())
            charmap[key] = char

    return charmap


# charmap.txt の内容をここに反映させる(スクリプト実行のたびに読み込むので、 charmap.txt を編集して再実行すれば変更が反映される)
CHARMAP = load_charmap()
MAX_KEY_LEN = max((len(k) for k in CHARMAP), default=1)


def decode_custom_string(prog, addr, max_length=128):
    """指定アドレスから始まる独自フォント文字列をデコードする"""
    mem = prog.getMemory()
    decoded_chars = []
    cur = addr
    consumed = 0

    while consumed < max_length:
        remaining = max_length - consumed
        matched = False

        # 最長一致でバイト列をデコードする(charmap.txt は1バイトと2バイトの符号が混在するため)
        for length in range(min(MAX_KEY_LEN, remaining), 0, -1):
            try:
                key = tuple(mem.getByte(cur.add(i)) & 0xFF for i in range(length))
            except Exception:
                key = None

            if key is not None and key in CHARMAP:
                decoded_chars.append(CHARMAP[key])
                cur = cur.add(length)
                consumed += length
                matched = True
                break

        if matched:
            continue

        # どの長さでも一致しなかった場合、1バイトだけ読んで終端判定 or エスケープ表記
        try:
            b = mem.getByte(cur) & 0xFF
        except Exception:
            break

        if b == TERMINATOR:
            break

        # charmap.txt 未対応のバイトは \xXX 表記で残す(charmap.txt 更新が必要な箇所の目印)
        decoded_chars.append("\\x{:02X}".format(b))
        cur = cur.add(1)
        consumed += 1

    return "".join(decoded_chars)


# Ghidraのリスティングビューのコメントとして設定
def set_listing_comment(prog, addr, comment):
    prog.getListing().setComment(addr, CodeUnit.PRE_COMMENT, comment)


def main():
    # 選択している範囲、または現在のカーソル位置の文字列を処理
    if currentSelection is not None and not currentSelection.isEmpty():
        start_addr = currentSelection.getMinAddress()
    else:
        start_addr = currentAddress

    if start_addr is None:
        println("[custom_string] アドレスを取得できませんでした")
        return

    decoded = decode_custom_string(currentProgram, start_addr)
    if not decoded:
        println(
            "[custom_string] {} から文字列をデコードできませんでした".format(start_addr)
        )
        return

    set_listing_comment(currentProgram, start_addr, decoded)
    println("[custom_string] {} : {}".format(start_addr, decoded))


if __name__ == "__main__":
    main()
