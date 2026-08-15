#!/usr/bin/env -S uv run python3
"""ROMからgWeaponDBのデータをCの構造体として標準出力する。

Usage: tools/dumper/weapon.py <ROM_FILE> <ROM_ADDR>
e.g. tools/dumper/weapon.py baserom.gba 0x08DA9E68

WeaponData (include/weapon.h, 36バイト):
  u8 id; u8 kind; u8 unk_02; u8 lv; u32 unk_04;
  u16 unk_08; u16 unk_0a; u32 unk_0c[6];

エントリ数は 66 (include/constants/weapon.h の WEAPON_ASTRO_HAMMER + 1)。
数値フィールドはすべて10進数で出力する。
"""
import struct
import sys
from pathlib import Path

WEAPON_NAMES = {
    0: "WEAPON_NONE",
    1: "WEAPON_GRADIUS",
    2: "WEAPON_SHORT_SWORD",
    3: "WEAPON_BROAD_SWORD",
    4: "WEAPON_LONG_SWORD",
    5: "WEAPON_DULL_BLADE",
    6: "WEAPON_ZWEIHANDER",
    7: "WEAPON_FLAMEBERGE",
    8: "WEAPON_CLAYMORE",
    9: "WEAPON_MAGIC_SWORD",
    10: "WEAPON_KATANA",
    11: "WEAPON_BASTARD_SWORD",
    12: "WEAPON_GREAT_SWORD",
    13: "WEAPON_BUSHIDO_SWORD",
    14: "WEAPON_BLOOD_SWORD",
    15: "WEAPON_MURAMASA",
    16: "WEAPON_VORPAL_SWORD",
    17: "WEAPON_SOLAR_SWORD",
    18: "WEAPON_DARK_SWORD",
    19: "WEAPON_GRAM",
    20: "WEAPON_SHORT_SPEAR",
    21: "WEAPON_GLAIVE",
    22: "WEAPON_LONG_SPEAR",
    23: "WEAPON_LANCE",
    24: "WEAPON_STAFF",
    25: "WEAPON_CORSESCA",
    26: "WEAPON_FIRE_PAW",
    27: "WEAPON_BARDICHE",
    28: "WEAPON_ICE_GLAIVE",
    29: "WEAPON_RUNE_GLAIVE",
    30: "WEAPON_PARTIZAN",
    31: "WEAPON_THUNDER_SPEAR",
    32: "WEAPON_BLOOD_SPEAR",
    33: "WEAPON_GRAND_LANCE",
    34: "WEAPON_RUNE_SPEAR",
    35: "WEAPON_HALBERD",
    36: "WEAPON_WHITE_QUEEN",
    37: "WEAPON_BLACK_QUEEN",
    38: "WEAPON_GUNGNIR",
    39: "WEAPON_CLUB",
    40: "WEAPON_HAMMER",
    41: "WEAPON_MACE",
    42: "WEAPON_FLAIL",
    43: "WEAPON_POUNDER",
    44: "WEAPON_AXE",
    45: "WEAPON_MAUL",
    46: "WEAPON_SILVER_MACE",
    47: "WEAPON_SILVER_FLAIL",
    48: "WEAPON_HEAVY_MACE",
    49: "WEAPON_BATTLE_AXE",
    50: "WEAPON_WAR_HAMMER",
    51: "WEAPON_BLOODY_MACE",
    52: "WEAPON_MORNING_STAR",
    53: "WEAPON_HEAVY_AXE",
    54: "WEAPON_EARTH_SHAKER",
    55: "WEAPON_DAYBREAK",
    56: "WEAPON_TWILIGHT",
    57: "WEAPON_MJOLLNIR",
    58: "WEAPON_BROKEN_GUN",
    59: "WEAPON_GUN_DEL_SOL",
    60: "WEAPON_GUN_DEL_HELL",
    61: "WEAPON_MEGA_BUSTER",
    62: "WEAPON_STAR_PIECE",
    63: "WEAPON_ASTRO_SWORD",
    64: "WEAPON_ASTRO_SPEAR",
    65: "WEAPON_ASTRO_HAMMER",
}

WK_NAMES = {
    0: "WK_SWORD",
    1: "WK_SPEAR",
    2: "WK_HAMMER",
    3: "WK_OTHERS",
    4: "WK_GUN",
}

WEAPON_NUM = 66
ENTRY_SIZE = 36
ROM_BASE = 0x08000000


def rom_addr_to_offset(addr: int) -> int:
    return addr - ROM_BASE


def weapon_name(i: int) -> str:
    return WEAPON_NAMES.get(i, str(i))


def wk_name(kind: int) -> str:
    return WK_NAMES.get(kind, str(kind))


def main() -> None:
    if len(sys.argv) != 3:
        print(__doc__, file=sys.stderr)
        sys.exit(1)

    rom_path = Path(sys.argv[1])
    rom_addr = int(sys.argv[2], 0)
    offset = rom_addr_to_offset(rom_addr)

    data = rom_path.read_bytes()
    entries = data[offset : offset + WEAPON_NUM * ENTRY_SIZE]
    if len(entries) != WEAPON_NUM * ENTRY_SIZE:
        print(
            f"error: ROMから {WEAPON_NUM * ENTRY_SIZE} バイト読めませんでした"
            f" (offset=0x{offset:X}, got {len(entries)} bytes)",
            file=sys.stderr,
        )
        sys.exit(1)

    print("const WeaponData gWeaponDB[66] = {")
    for i in range(WEAPON_NUM):
        chunk = entries[i * ENTRY_SIZE : (i + 1) * ENTRY_SIZE]
        id_, kind, unk_02, lv, unk_04, unk_08, unk_0a, *unk_0c = struct.unpack(
            "<BBBBIHH6I", chunk
        )
        fields = [weapon_name(id_), wk_name(kind), unk_02, lv, unk_04, unk_08, unk_0a, *unk_0c]
        body = "{" + ", ".join(str(f) for f in fields) + "},"
        print(f"    {body}")
    print("};")


if __name__ == "__main__":
    main()
