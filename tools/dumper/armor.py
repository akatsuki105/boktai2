#!/usr/bin/env -S uv run python3
"""ROMからgArmorDBのデータをCの構造体として標準出力する。

Usage: tools/dumper/armor.py <ROM_FILE> <ROM_ADDR>
e.g. tools/dumper/armor.py baserom.gba 0x08DAA7B0

ArmorData (include/armor.h, 8バイト):
  u8 id; u8 defence; u8 weight; u8 effectType; u8 value; u8 unk_5; s16 price;

エントリ数は ARMOR_NUM(include/constants/armor.h の ARMOR_TOAD_POWER + 1)。
数値フィールドはすべて10進数で出力する。
"""
import struct
import sys
from pathlib import Path

ARMOR_NAMES = [
    "ARMOR_CLOTH_ARMOR",
    "ARMOR_LEATHER_ARMOR",
    "ARMOR_CHAIN_MAIL",
    "ARMOR_SILVER_CHAIN",
    "ARMOR_SCALE_MAIL",
    "ARMOR_SAMURAI_ARMOR",
    "ARMOR_BLADE_MAIL",
    "ARMOR_BRIGANDINE",
    "ARMOR_MAIL_OF_SOL",
    "ARMOR_MAIL_OF_DARKNESS",
    "ARMOR_MAIL_OF_LUNA",
    "ARMOR_FIRE_DRAGON_FANG",
    "ARMOR_WATER_DRAGON_TAIL",
    "ARMOR_WIND_DRAGON_WING",
    "ARMOR_EARTH_DRAGON_CLAW",
    "ARMOR_DRAGON_SCALE",
    "ARMOR_FAIRY_ROBE",
    "ARMOR_EARTHLY_ROBE",
    "ARMOR_RAIN_COAT",
    "ARMOR_GARB_OF_LIGHT",
    "ARMOR_GARB_OF_DARKNESS",
    "ARMOR_MAGIC_ROBE",
    "ARMOR_BLOOD_CAPE",
    "ARMOR_SKULL_SUIT",
    "ARMOR_TRAINING_GEAR",
    "ARMOR_THIEF_CLOTHES",
    "ARMOR_HUNTER_CLOTHES",
    "ARMOR_POISON_GUARD",
    "ARMOR_WEAPON_GUARD",
    "ARMOR_PARADE_ARMOR",
    "ARMOR_NINJA_GI",
    "ARMOR_SPIKE_MAIL",
    "ARMOR_BLACK_ARMOR",
    "ARMOR_MEGA_POWER",
    "ARMOR_GUTS_POWER",
    "ARMOR_PROTO_POWER",
    "ARMOR_TOAD_POWER",
]

ARMOR_NUM = len(ARMOR_NAMES)
ENTRY_SIZE = 8
ROM_BASE = 0x08000000


def rom_addr_to_offset(addr: int) -> int:
    return addr - ROM_BASE


def main() -> None:
    if len(sys.argv) != 3:
        print(__doc__, file=sys.stderr)
        sys.exit(1)

    rom_path = Path(sys.argv[1])
    rom_addr = int(sys.argv[2], 0)
    offset = rom_addr_to_offset(rom_addr)

    data = rom_path.read_bytes()
    entries = data[offset : offset + ARMOR_NUM * ENTRY_SIZE]
    if len(entries) != ARMOR_NUM * ENTRY_SIZE:
        print(
            f"error: ROMから {ARMOR_NUM * ENTRY_SIZE} バイト読めませんでした"
            f" (offset=0x{offset:X}, got {len(entries)} bytes)",
            file=sys.stderr,
        )
        sys.exit(1)

    labels = ["id", "defence", "weight", "effectType", "value", "unk_5", "price"]
    rows: list[list[str]] = []
    for i in range(ARMOR_NUM):
        chunk = entries[i * ENTRY_SIZE : (i + 1) * ENTRY_SIZE]
        _id, defence, weight, effectType, value, unk_5, price = struct.unpack(
            "<BBBBBBh", chunk
        )
        rows.append(
            [ARMOR_NAMES[i], str(defence), str(weight), str(effectType), str(value), str(unk_5), str(price)]
        )

    num_cols = len(labels)
    widths = []
    for col in range(num_cols):
        cell_texts = [row[col] + ("," if col < num_cols - 1 else "") for row in rows]
        widths.append(max(len(labels[col]), max(len(t) for t in cell_texts)))

    # 各列(最終列のpriceを除く)はラベル/値の間を最低2スペース空ける。
    def pad(col: int) -> int:
        if col == num_cols - 1:
            return widths[col]
        return widths[col] + 2

    INDENT = "    "

    print("const ArmorData gArmorDB[ARMOR_NUM] = {")
    header = "".join(labels[c].ljust(pad(c)) for c in range(num_cols)).rstrip()
    print(f"//{' ' * (len(INDENT) - 1)}{header}")
    for row in rows:
        line = "".join(
            (row[c] + ("," if c < num_cols - 1 else "")).ljust(pad(c))
            for c in range(num_cols)
        ).rstrip()
        print(f"{INDENT}{{{line}}},")
    print("};")


if __name__ == "__main__":
    main()
