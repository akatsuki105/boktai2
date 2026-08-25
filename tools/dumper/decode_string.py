#!/usr/bin/env -S uv run python3
"""ROM上の文字列を charmap.txt でデコードして .string 形式で標準出力する。

Usage: tools/dumper/decode_string.py <ROM_FILE> <ROM_ADDR>
e.g. tools/dumper/decode_string.py baserom.gba 0x08CD167C
  -> .string "<PROC=0>\\n<END>$"

指定アドレスから終端文字('$' = charmap.txt上で 0x00 にマップされた文字)まで
読み進め、charmap.txt でデコードできた文字列を .string "..." として出力する。
charmap.txt の裸の識別子(シングルクオートで囲まれていない、例: CTRL85FF = 85 FF)
に一致したバイト列は {CTRL85FF} のようにブレース付きの名前として出力する。
デコード中に charmap.txt に存在しない未定義バイトに遭遇した場合は、文字列の
先頭からその時点で判明している終端文字まで生バイト列として
.byte 0xXX, ... (16バイト/行) にフォールバックする。
"""
import sys
from pathlib import Path

ROM_BASE = 0x08000000
CHARMAP_PATH = Path(__file__).resolve().parents[2] / "charmap.txt"
READ_WINDOW = 0x2000
BYTES_PER_LINE = 16


def parse_charmap(path: Path) -> tuple[dict[bytes, str], dict[bytes, str], dict[bytes, str]]:
    """charmap.txt を (char_map, escape_map, constant_map) に変換する。

    char_map: バイト列 -> 表示文字 (例: b'\\x80\\x01' -> 'あ')
    escape_map: バイト列 -> エスケープ名 (例: b'\\x0a' -> 'n', 出力時は \\n になる)
    constant_map: バイト列 -> 定数名 (シングルクオートなしの裸の識別子。
      例: b'\\x85\\xff' -> 'CTRL85FF', 出力時は {CTRL85FF} になる)
    """
    char_map: dict[bytes, str] = {}
    escape_map: dict[bytes, str] = {}
    constant_map: dict[bytes, str] = {}

    for line in path.read_text(encoding="utf-8").split("\n"):
        line = line.split(" @", 1)[0].strip()
        if not line or line.startswith("@") or "=" not in line:
            continue

        if not line.startswith("'"):
            # シングルクオートで囲まれていない裸の識別子(定数)。
            name, rhs = line.split("=", 1)
            name = name.strip()
            seq = bytes(int(b, 16) for b in rhs.split())
            constant_map[seq] = name
            continue

        # LHS が 'X' や '\X' の場合、X 自体が '=' のこともあるため、
        # 単純に最初の '=' で区切らずクォートの終端を見て区切る。
        closing_idx = 3 if line[1] == "\\" else 2
        if closing_idx >= len(line) or line[closing_idx] != "'":
            continue

        lhs = line[: closing_idx + 1]
        rhs = line[closing_idx + 1 :].split("=", 1)[1].strip()

        inner = lhs[1:-1]
        seq = bytes(int(b, 16) for b in rhs.split())

        if inner.startswith("\\") and inner != "\\'":
            escape_map[seq] = inner[1:]
        else:
            ch = "'" if inner == "\\'" else inner
            char_map[seq] = ch

    return char_map, escape_map, constant_map


def find_terminator_seq(char_map: dict[bytes, str]) -> bytes:
    for seq, ch in char_map.items():
        if ch == "$":
            return seq
    raise SystemExit("error: charmap.txt に '$' (終端文字) の定義がありません")


def format_byte_dump(data: bytes) -> str:
    lines = []
    for i in range(0, len(data), BYTES_PER_LINE):
        chunk = data[i : i + BYTES_PER_LINE]
        lines.append("  .byte " + ", ".join(f"0x{b:02X}" for b in chunk))
    return "\n".join(lines)


def decode(
    data: bytes,
    char_map: dict[bytes, str],
    escape_map: dict[bytes, str],
    constant_map: dict[bytes, str],
) -> str | None:
    """終端文字まで正常にデコードできれば .string 用の中身を返す。未定義バイトに
    遭遇したら None を返す(呼び出し側で生バイトダンプにフォールバックする)。"""
    lengths = sorted(
        {len(k) for k in char_map} | {len(k) for k in escape_map} | {len(k) for k in constant_map},
        reverse=True,
    )

    out = []
    pos = 0
    while True:
        matched = None
        for length in lengths:
            seq = data[pos : pos + length]
            if seq in char_map:
                matched = (seq, char_map[seq], "char")
                break
            if seq in escape_map:
                matched = (seq, escape_map[seq], "escape")
                break
            if seq in constant_map:
                matched = (seq, constant_map[seq], "constant")
                break

        if matched is None:
            return None

        seq, value, kind = matched
        pos += len(seq)

        if kind == "escape":
            out.append("\\" + value)
            continue

        if kind == "constant":
            out.append("{" + value + "}")
            continue

        if value == "$":
            out.append("$")
            break

        if value in ("\\", '"'):
            out.append("\\" + value)
        else:
            out.append(value)

    return "".join(out)


def main() -> None:
    if len(sys.argv) != 3:
        print(__doc__, file=sys.stderr)
        sys.exit(1)

    rom_path = Path(sys.argv[1])
    rom_addr = int(sys.argv[2], 0)
    offset = rom_addr - ROM_BASE if rom_addr >= ROM_BASE else rom_addr

    char_map, escape_map, constant_map = parse_charmap(CHARMAP_PATH)
    term_seq = find_terminator_seq(char_map)

    rom_data = rom_path.read_bytes()
    window = rom_data[offset : offset + READ_WINDOW]

    string_body = decode(window, char_map, escape_map, constant_map)
    if string_body is not None:
        print(f'.string "{string_body}"')
        return

    end = window.find(term_seq)
    if end == -1:
        print(
            f"error: 0x{READ_WINDOW:X} バイト以内に終端文字が見つかりませんでした"
            f" (addr=0x{rom_addr:X})",
            file=sys.stderr,
        )
        sys.exit(1)

    raw = window[: end + len(term_seq)]
    print(format_byte_dump(raw))


if __name__ == "__main__":
    main()
