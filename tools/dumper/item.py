#!/usr/bin/env -S uv run python3
"""ROMからgItemDBのデータをCの構造体として標準出力する。

Usage: tools/dumper/item.py <ROM_FILE> <ROM_ADDR>
e.g. tools/dumper/item.py baserom.gba 0x08DAA8D8

ItemData (include/item.h, 16バイト):
  u16 unk_00; u16 effectType; u16 unk_04; u16 value;
  u16 unk_08; u16 unk_0a; u16 price; u16 unk_0e;

エントリ数は ITEM_NUM = 78 (include/constants/item.h の ITEM_THE_WORLD + 1)。
フィールド名がまだ判明していないため、id フィールドは持たず、
各エントリはコメントでのみ ITEM_ID (57..63 はコフィン用の予約領域) を示す。
数値フィールドはすべて10進数で出力する。
"""
import struct
import sys
from pathlib import Path

ITEM_NAMES = {
    0: "ITEM_EARTHLY_NUT",
    1: "ITEM_SOLAR_NUT",
    2: "ITEM_SPEED_NUT",
    3: "ITEM_TIPTOE_NUT",
    4: "ITEM_POWER_NUT",
    5: "ITEM_CHOCOLATE_BANANA",
    6: "ITEM_BEARNUT",
    7: "ITEM_SEE_ALL_NUT",
    8: "ITEM_ROTTEN_NUT",
    9: "ITEM_RED_MUSHROOM",
    10: "ITEM_BLUE_MUSHROOM",
    11: "ITEM_BAD_MUSHROOM",
    12: "ITEM_DROP_OF_SUN",
    13: "ITEM_TOMATO_JUICE",
    14: "ITEM_ROTTEN_WATER",
    15: "ITEM_TASTY_MEAT",
    16: "ITEM_JERKY",
    17: "ITEM_ROTTEN_MEAT",
    18: "ITEM_CHOCOLATE",
    19: "ITEM_MELTED_CHOCOLATE",
    20: "ITEM_CHOCOLATE_COVERED",
    21: "ITEM_DELUXE_CHOCOLATE",
    22: "ITEM_HEALER",
    23: "ITEM_MAGICAL_POTION",
    24: "ITEM_ANTIDOTE",
    25: "ITEM_ELIXIR",
    26: "ITEM_SUNBLOCK",
    27: "ITEM_MR_RAINNOT",
    28: "ITEM_TONNIAR_RM",
    29: "ITEM_SUNNY_CLOG",
    30: "ITEM_WARP_LEAF",
    31: "ITEM_THE_FOOL",
    32: "ITEM_THE_HIGH_PRIESTESS",
    33: "ITEM_THE_EMPRESS",
    34: "ITEM_THE_EMPEROR",
    35: "ITEM_THE_LOVER",
    36: "ITEM_THE_CHARIOT",
    37: "ITEM_STRENGTH",
    38: "ITEM_WOF",
    39: "ITEM_JUSTICE",
    40: "ITEM_THE_HANGED_MAN",
    41: "ITEM_DEATH",
    42: "ITEM_TEMPERANCE",
    43: "ITEM_THE_DEVIL",
    44: "ITEM_THE_TOWER",
    45: "ITEM_THE_STAR",
    46: "ITEM_THE_MOON",
    47: "ITEM_THE_SUN",
    48: "ITEM_JUDGEMENT",
    49: "ITEM_DARK_CARD",
    50: "ITEM_PET",
    51: "ITEM_SPADE_EMBLEM",
    52: "ITEM_HEART_EMBLEM",
    53: "ITEM_DIAMOND_EMBLEM",
    54: "ITEM_CLUB_EMBLEM",
    55: "ITEM_JOKER_EMBLEM",
    56: "ITEM_OAK_COFFIN",
    # 57..63: COFFIN_ITEM_ID(1..7)、include/constants/item.h 参照
    64: "ITEM_WAREHOUSE_KEY",
    65: "ITEM_CIRCLE_KEY",
    66: "ITEM_TRIANGLE_KEY",
    67: "ITEM_SQUARE_KEY",
    68: "ITEM_RED_CRYSTAL",
    69: "ITEM_BLUE_CRYSTAL",
    70: "ITEM_GREEN_CRYSTAL",
    71: "ITEM_YELLOW_CRYSTAL",
    72: "ITEM_STONE_TABLET_PIECE",
    73: "ITEM_TASTY_WATER",
    74: "ITEM_THE_MAGICIAN",
    75: "ITEM_THE_HIEROPHANT",
    76: "ITEM_THE_HERMIT",
    77: "ITEM_THE_WORLD",
}

ITEM_NUM = 78
ENTRY_SIZE = 16
ROM_BASE = 0x08000000


def rom_addr_to_offset(addr: int) -> int:
    return addr - ROM_BASE


def item_comment(i: int) -> str:
    if i in ITEM_NAMES:
        return ITEM_NAMES[i]
    if 57 <= i <= 63:
        return f"COFFIN_ITEM_ID({i - 56})"
    return f"ITEM_ID={i}"


def main() -> None:
    if len(sys.argv) != 3:
        print(__doc__, file=sys.stderr)
        sys.exit(1)

    rom_path = Path(sys.argv[1])
    rom_addr = int(sys.argv[2], 0)
    offset = rom_addr_to_offset(rom_addr)

    data = rom_path.read_bytes()
    entries = data[offset : offset + ITEM_NUM * ENTRY_SIZE]
    if len(entries) != ITEM_NUM * ENTRY_SIZE:
        print(
            f"error: ROMから {ITEM_NUM * ENTRY_SIZE} バイト読めませんでした"
            f" (offset=0x{offset:X}, got {len(entries)} bytes)",
            file=sys.stderr,
        )
        sys.exit(1)

    lines = []
    for i in range(ITEM_NUM):
        chunk = entries[i * ENTRY_SIZE : (i + 1) * ENTRY_SIZE]
        fields = struct.unpack("<HHHHHHHH", chunk)
        body = "{" + ", ".join(str(f) for f in fields) + "},"
        lines.append((body, item_comment(i)))

    width = max(len(body) for body, _ in lines)

    print("const ItemData gItemDB[ITEM_NUM] = {")
    for body, comment in lines:
        print(f"    {body.ljust(width)}  // {comment}")
    print("};")


if __name__ == "__main__":
    main()
