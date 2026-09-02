#include "item.h"

#include "armor.h"
#include "global.h"
#include "weapon.h"

const WeaponData gWeaponDB[WEAPON_NUM] = {
    {id : WEAPON_NONE, kind : WK_OTHERS, unk_02 : 0x00, lv : 1, unk_04 : 0x0000, price : 0, effects : {0, 0, 0}},
    {id : WEAPON_GRADIUS, kind : WK_SWORD, unk_02 : 0x00, lv : 1, unk_04 : 0x3205, price : 100, effects : {0, 0, 0}},
    {id : WEAPON_SHORT_SWORD, kind : WK_SWORD, unk_02 : 0x00, lv : 5, unk_04 : 0x370C, price : 120, effects : {0, 0, 0}},
    {id : WEAPON_BROAD_SWORD, kind : WK_SWORD, unk_02 : 0x00, lv : 9, unk_04 : 0x3C10, price : 150, effects : {0, 0, 0}},
    {id : WEAPON_LONG_SWORD, kind : WK_SWORD, unk_02 : 0x00, lv : 13, unk_04 : 0x4115, price : 190, effects : {0, 0, 0}},
    {id : WEAPON_DULL_BLADE, kind : WK_SWORD, unk_02 : 0x04, lv : 1, unk_04 : 0x3201, price : 50, effects : {2587, 0, 0}},
    {id : WEAPON_ZWEIHANDER, kind : WK_SWORD, unk_02 : 0x01, lv : 17, unk_04 : 0x4619, price : 240, effects : {2576, 0, 0}},
    {id : WEAPON_FLAMEBERGE, kind : WK_SWORD, unk_02 : 0x01, lv : 21, unk_04 : 0x4B1E, price : 300, effects : {2578, 0, 0}},
    {id : WEAPON_CLAYMORE, kind : WK_SWORD, unk_02 : 0x01, lv : 25, unk_04 : 0x5022, price : 370, effects : {2576, 0, 0}},
    {id : WEAPON_MAGIC_SWORD, kind : WK_SWORD, unk_02 : 0x01, lv : 29, unk_04 : 0x5527, price : 450, effects : {5150, 0, 0}},
    {id : WEAPON_KATANA, kind : WK_SWORD, unk_02 : 0x04, lv : 17, unk_04 : 0x3222, price : 500, effects : {2058, 0, 0}},
    {id : WEAPON_BASTARD_SWORD, kind : WK_SWORD, unk_02 : 0x02, lv : 33, unk_04 : 0x5A2B, price : 540, effects : {671761, 0, 0}},
    {id : WEAPON_GREAT_SWORD, kind : WK_SWORD, unk_02 : 0x02, lv : 37, unk_04 : 0x6430, price : 640, effects : {31, 0, 0}},
    {id : WEAPON_BUSHIDO_SWORD, kind : WK_SWORD, unk_02 : 0x02, lv : 41, unk_04 : 0x6E2A, price : 750, effects : {3, 0, 0}},
    {id : WEAPON_BLOOD_SWORD, kind : WK_SWORD, unk_02 : 0x02, lv : 45, unk_04 : 0x7839, price : 870, effects : {285, 0, 0}},
    {id : WEAPON_MURAMASA, kind : WK_SWORD, unk_02 : 0x04, lv : 33, unk_04 : 0x5A34, price : 900, effects : {2058, 0, 0}},
    {id : WEAPON_VORPAL_SWORD, kind : WK_SWORD, unk_02 : 0x03, lv : 49, unk_04 : 0x823D, price : 1000, effects : {2573, 0, 0}},
    {id : WEAPON_SOLAR_SWORD, kind : WK_SWORD, unk_02 : 0x03, lv : 53, unk_04 : 0x8C42, price : 1250, effects : {14, 0, 0}},
    {id : WEAPON_DARK_SWORD, kind : WK_SWORD, unk_02 : 0x04, lv : 53, unk_04 : 0x8C42, price : 1500, effects : {2575, 0, 0}},
    {id : WEAPON_GRAM, kind : WK_SWORD, unk_02 : 0x04, lv : 57, unk_04 : 0x9646, price : 2000, effects : {0, 0, 0}},
    {id : WEAPON_SHORT_SPEAR, kind : WK_SPEAR, unk_02 : 0x00, lv : 1, unk_04 : 0x3208, price : 100, effects : {0, 0, 0}},
    {id : WEAPON_GLAIVE, kind : WK_SPEAR, unk_02 : 0x00, lv : 5, unk_04 : 0x370F, price : 120, effects : {0, 0, 0}},
    {id : WEAPON_LONG_SPEAR, kind : WK_SPEAR, unk_02 : 0x00, lv : 9, unk_04 : 0x3C14, price : 150, effects : {0, 0, 0}},
    {id : WEAPON_LANCE, kind : WK_SPEAR, unk_02 : 0x00, lv : 13, unk_04 : 0x4119, price : 190, effects : {0, 0, 0}},
    {id : WEAPON_STAFF, kind : WK_SPEAR, unk_02 : 0x04, lv : 1, unk_04 : 0x3204, price : 50, effects : {2587, 0, 0}},
    {id : WEAPON_CORSESCA, kind : WK_SPEAR, unk_02 : 0x01, lv : 17, unk_04 : 0x461E, price : 240, effects : {28, 0, 0}},
    {id : WEAPON_FIRE_PAW, kind : WK_SPEAR, unk_02 : 0x01, lv : 21, unk_04 : 0x4B23, price : 300, effects : {2578, 0, 0}},
    {id : WEAPON_BARDICHE, kind : WK_SPEAR, unk_02 : 0x01, lv : 25, unk_04 : 0x5028, price : 370, effects : {31, 0, 0}},
    {id : WEAPON_ICE_GLAIVE, kind : WK_SPEAR, unk_02 : 0x01, lv : 29, unk_04 : 0x552D, price : 450, effects : {2579, 0, 0}},
    {id : WEAPON_RUNE_GLAIVE, kind : WK_SPEAR, unk_02 : 0x04, lv : 17, unk_04 : 0x3228, price : 500, effects : {2057, 0, 0}},
    {id : WEAPON_PARTIZAN, kind : WK_SPEAR, unk_02 : 0x02, lv : 33, unk_04 : 0x5A32, price : 540, effects : {28, 0, 0}},
    {id : WEAPON_THUNDER_SPEAR, kind : WK_SPEAR, unk_02 : 0x02, lv : 37, unk_04 : 0x6437, price : 640, effects : {2580, 0, 0}},
    {id : WEAPON_BLOOD_SPEAR, kind : WK_SPEAR, unk_02 : 0x02, lv : 41, unk_04 : 0x6E3C, price : 750, effects : {285, 0, 0}},
    {id : WEAPON_GRAND_LANCE, kind : WK_SPEAR, unk_02 : 0x02, lv : 45, unk_04 : 0x7841, price : 870, effects : {2581, 0, 0}},
    {id : WEAPON_RUNE_SPEAR, kind : WK_SPEAR, unk_02 : 0x04, lv : 33, unk_04 : 0x5A3C, price : 900, effects : {2057, 0, 0}},
    {id : WEAPON_HALBERD, kind : WK_SPEAR, unk_02 : 0x03, lv : 49, unk_04 : 0x8246, price : 1000, effects : {12, 0, 0}},
    {id : WEAPON_WHITE_QUEEN, kind : WK_SPEAR, unk_02 : 0x03, lv : 53, unk_04 : 0x8C4B, price : 1250, effects : {14, 0, 0}},
    {id : WEAPON_BLACK_QUEEN, kind : WK_SPEAR, unk_02 : 0x04, lv : 53, unk_04 : 0x8C4B, price : 1500, effects : {2575, 0, 0}},
    {id : WEAPON_GUNGNIR, kind : WK_SPEAR, unk_02 : 0x04, lv : 57, unk_04 : 0x9650, price : 2000, effects : {0, 0, 0}},
    {id : WEAPON_CLUB, kind : WK_HAMMER, unk_02 : 0x00, lv : 1, unk_04 : 0x320B, price : 100, effects : {0, 0, 0}},
    {id : WEAPON_HAMMER, kind : WK_HAMMER, unk_02 : 0x00, lv : 5, unk_04 : 0x3712, price : 120, effects : {0, 0, 0}},
    {id : WEAPON_MACE, kind : WK_HAMMER, unk_02 : 0x00, lv : 9, unk_04 : 0x3C18, price : 150, effects : {0, 0, 0}},
    {id : WEAPON_FLAIL, kind : WK_HAMMER, unk_02 : 0x00, lv : 13, unk_04 : 0x411D, price : 190, effects : {0, 0, 0}},
    {id : WEAPON_POUNDER, kind : WK_HAMMER, unk_02 : 0x04, lv : 1, unk_04 : 0x3207, price : 50, effects : {2587, 0, 0}},
    {id : WEAPON_AXE, kind : WK_HAMMER, unk_02 : 0x01, lv : 17, unk_04 : 0x4623, price : 240, effects : {2582, 0, 0}},
    {id : WEAPON_MAUL, kind : WK_HAMMER, unk_02 : 0x01, lv : 21, unk_04 : 0x4B28, price : 300, effects : {2583, 0, 0}},
    {id : WEAPON_SILVER_MACE, kind : WK_HAMMER, unk_02 : 0x01, lv : 25, unk_04 : 0x502E, price : 370, effects : {2584, 0, 0}},
    {id : WEAPON_SILVER_FLAIL, kind : WK_HAMMER, unk_02 : 0x01, lv : 29, unk_04 : 0x5533, price : 450, effects : {2585, 0, 0}},
    {id : WEAPON_HEAVY_MACE, kind : WK_HAMMER, unk_02 : 0x04, lv : 17, unk_04 : 0x322E, price : 500, effects : {2056, 0, 0}},
    {id : WEAPON_BATTLE_AXE, kind : WK_HAMMER, unk_02 : 0x02, lv : 33, unk_04 : 0x5A39, price : 540, effects : {671761, 0, 0}},
    {id : WEAPON_WAR_HAMMER, kind : WK_HAMMER, unk_02 : 0x02, lv : 37, unk_04 : 0x643E, price : 640, effects : {31, 0, 0}},
    {id : WEAPON_BLOODY_MACE, kind : WK_HAMMER, unk_02 : 0x02, lv : 41, unk_04 : 0x6E44, price : 750, effects : {285, 0, 0}},
    {id : WEAPON_MORNING_STAR, kind : WK_HAMMER, unk_02 : 0x02, lv : 45, unk_04 : 0x7849, price : 870, effects : {26, 0, 0}},
    {id : WEAPON_HEAVY_AXE, kind : WK_HAMMER, unk_02 : 0x04, lv : 33, unk_04 : 0x5A44, price : 900, effects : {2056, 0, 0}},
    {id : WEAPON_EARTH_SHAKER, kind : WK_HAMMER, unk_02 : 0x03, lv : 49, unk_04 : 0x824F, price : 1000, effects : {11, 0, 0}},
    {id : WEAPON_DAYBREAK, kind : WK_HAMMER, unk_02 : 0x03, lv : 53, unk_04 : 0x8C54, price : 1250, effects : {14, 0, 0}},
    {id : WEAPON_TWILIGHT, kind : WK_HAMMER, unk_02 : 0x04, lv : 53, unk_04 : 0x8C54, price : 1500, effects : {2575, 0, 0}},
    {id : WEAPON_MJOLLNIR, kind : WK_HAMMER, unk_02 : 0x04, lv : 57, unk_04 : 0x965A, price : 2000, effects : {0, 0, 0}},
    {id : WEAPON_BROKEN_GUN, kind : WK_GUN, unk_02 : 0x04, lv : 1, unk_04 : 0x0001, price : 0, effects : {0, 0, 0}},
    {id : WEAPON_GUN_DEL_SOL, kind : WK_GUN, unk_02 : 0x02, lv : 1, unk_04 : 0x004B, price : 0, effects : {1, 0, 0}},
    {id : WEAPON_GUN_DEL_HELL, kind : WK_GUN, unk_02 : 0x02, lv : 1, unk_04 : 0x0050, price : 0, effects : {2562, 0, 0}},
    {id : WEAPON_MEGA_BUSTER, kind : WK_GUN, unk_02 : 0x03, lv : 1, unk_04 : 0x0055, price : 0, effects : {4, 0, 0}},
    {id : WEAPON_STAR_PIECE, kind : WK_OTHERS, unk_02 : 0x04, lv : 1, unk_04 : 0x0001, price : 1, effects : {0, 0, 0}},
    {id : WEAPON_ASTRO_SWORD, kind : WK_SWORD, unk_02 : 0x04, lv : 1, unk_04 : 0x0006, price : 0, effects : {5, 0, 0}},
    {id : WEAPON_ASTRO_SPEAR, kind : WK_SPEAR, unk_02 : 0x04, lv : 1, unk_04 : 0x0006, price : 0, effects : {6, 0, 0}},
    {id : WEAPON_ASTRO_HAMMER, kind : WK_HAMMER, unk_02 : 0x04, lv : 1, unk_04 : 0x0006, price : 0, effects : {7, 0, 0}},
};

// clang-format off
const ArmorData gArmorDB[ARMOR_NUM] = {
//   id                        defence  weight  effectType  value  price
    {ARMOR_CLOTH_ARMOR,        10,      5,      0,          0,     50},
    {ARMOR_LEATHER_ARMOR,      15,      10,     0,          0,     100},
    {ARMOR_CHAIN_MAIL,         20,      15,     0,          0,     200},
    {ARMOR_SILVER_CHAIN,       25,      20,     1,          1,     400},
    {ARMOR_SCALE_MAIL,         30,      25,     0,          0,     800},
    {ARMOR_SAMURAI_ARMOR,      35,      30,     3,          2,     1200},
    {ARMOR_BLADE_MAIL,         40,      35,     0,          0,     1600},
    {ARMOR_BRIGANDINE,         45,      40,     4,          0,     2000},
    {ARMOR_MAIL_OF_SOL,        25,      22,     5,          0,     1750},
    {ARMOR_MAIL_OF_DARKNESS,   30,      22,     6,          0,     1750},
    {ARMOR_MAIL_OF_LUNA,       25,      22,     12,         0,     1750},
    {ARMOR_FIRE_DRAGON_FANG,   30,      33,     7,          0,     750},
    {ARMOR_WATER_DRAGON_TAIL,  30,      33,     8,          0,     750},
    {ARMOR_WIND_DRAGON_WING,   30,      33,     9,          0,     750},
    {ARMOR_EARTH_DRAGON_CLAW,  30,      33,     10,         0,     750},
    {ARMOR_DRAGON_SCALE,       28,      24,     11,         0,     1000},
    {ARMOR_FAIRY_ROBE,         16,      4,      13,         200,   500},
    {ARMOR_EARTHLY_ROBE,       28,      8,      14,         200,   750},
    {ARMOR_RAIN_COAT,          12,      6,      15,         0,     250},
    {ARMOR_GARB_OF_LIGHT,      30,      12,     16,         200,   1250},
    {ARMOR_GARB_OF_DARKNESS,   30,      12,     17,         0,     1250},
    {ARMOR_MAGIC_ROBE,         26,      16,     18,         20,    750},
    {ARMOR_BLOOD_CAPE,         22,      12,     2,          2,     750},
    {ARMOR_SKULL_SUIT,         20,      16,     19,         50,    750},
    {ARMOR_TRAINING_GEAR,      25,      16,     20,         150,   1000},
    {ARMOR_THIEF_CLOTHES,      18,      24,     21,         0,     1000},
    {ARMOR_HUNTER_CLOTHES,     24,      24,     22,         0,     100},
    {ARMOR_POISON_GUARD,       18,      28,     23,         0,     250},
    {ARMOR_WEAPON_GUARD,       24,      28,     24,         0,     500},
    {ARMOR_PARADE_ARMOR,       32,      28,     25,         0,     750},
    {ARMOR_NINJA_GI,           18,      28,     26,         10,    750},
    {ARMOR_SPIKE_MAIL,         40,      40,     27,         20,    1500},
    {ARMOR_BLACK_ARMOR,        50,      50,     28,         20,    1750},
    {ARMOR_MEGA_POWER,         25,      30,     29,         0,     1500},
    {ARMOR_GUTS_POWER,         30,      40,     30,         0,     1500},
    {ARMOR_PROTO_POWER,        25,      20,     31,         0,     1500},
    {ARMOR_TOAD_POWER,         20,      20,     32,         0,     1500},
};
// clang-format on

const ItemData gItemDB[ITEM_NUM] = {
    {290, 1, 120, 40, 0, 0, 50, 0},   // ITEM_EARTHLY_NUT
    {306, 2, 120, 40, 0, 0, 100, 0},  // ITEM_SOLAR_NUT
    {786, 5, 120, 1, 30, 0, 100, 0},  // ITEM_SPEED_NUT
    {786, 5, 120, 0, 30, 0, 100, 0},  // ITEM_TIPTOE_NUT
    {786, 5, 120, 2, 30, 0, 100, 0},  // ITEM_POWER_NUT
    {786, 5, 0, 2, 60, 0, 300, 0},    // ITEM_CHOCOLATE_BANANA
    {786, 5, 120, 3, 15, 0, 400, 0},  // ITEM_BEARNUT
    {786, 5, 120, 4, 30, 0, 50, 0},   // ITEM_SEE_ALL_NUT
    {290, 1, 0, 5, 30, 0, 5, 0},      // ITEM_ROTTEN_NUT
    {786, 5, 240, 5, 15, 0, 50, 0},   // ITEM_RED_MUSHROOM
    {786, 5, 240, 6, 30, 0, 200, 0},  // ITEM_BLUE_MUSHROOM
    {306, 2, 0, 5, 30, 0, 5, 0},      // ITEM_BAD_MUSHROOM
    {322, 3, 120, 8, 0, 0, 50, 0},    // ITEM_DROP_OF_SUN
    {290, 1, 240, 40, 0, 0, 50, 0},   // ITEM_TOMATO_JUICE
    {306, 2, 0, 10, 30, 0, 5, 0},     // ITEM_ROTTEN_WATER
    {290, 1, 120, 60, 0, 0, 150, 0},  // ITEM_TASTY_MEAT
    {290, 1, 0, 40, 0, 0, 150, 0},    // ITEM_JERKY
    {290, 1, 0, 5, 30, 0, 5, 0},      // ITEM_ROTTEN_MEAT
    {290, 1, 120, 20, 0, 0, 100, 0},  // ITEM_CHOCOLATE
    {290, 1, 0, 20, 0, 0, 50, 0},     // ITEM_MELTED_CHOCOLATE
    {274, 1, 0, 20, 0, 0, 0, 0},      // ITEM_CHOCOLATE_COVERED
    {290, 1, 0, 40, 0, 0, 300, 0},    // ITEM_DELUXE_CHOCOLATE
    {290, 1, 0, 20, 0, 0, 50, 0},     // ITEM_HEALER
    {306, 2, 0, 20, 0, 0, 100, 0},    // ITEM_MAGICAL_POTION
    {322, 3, 0, 2, 0, 0, 50, 0},      // ITEM_ANTIDOTE
    {322, 3, 0, 7, 0, 0, 200, 0},     // ITEM_ELIXIR
    {786, 5, 0, 7, 60, 0, 50, 0},     // ITEM_SUNBLOCK
    {274, 8, 0, 0, 0, 0, 400, 0},     // ITEM_MR_RAINNOT
    {274, 8, 0, 1, 0, 0, 200, 0},     // ITEM_TONNIAR_RM
    {274, 8, 0, 2, 0, 0, 300, 0},     // ITEM_SUNNY_CLOG
    {786, 7, 0, 0, 0, 0, 50, 0},      // ITEM_WARP_LEAF
    {786, 7, 0, 1, 0, 0, 200, 0},     // ITEM_THE_FOOL
    {274, 4, 0, 1, 1, 0, 600, 0},     // ITEM_THE_HIGH_PRIESTESS
    {274, 4, 0, 0, 1, 0, 600, 0},     // ITEM_THE_EMPRESS
    {786, 5, 0, 8, 30, 0, 200, 0},    // ITEM_THE_EMPEROR
    {274, 11, 0, 0, 0, 0, 200, 0},    // ITEM_THE_LOVER
    {274, 4, 0, 3, 1, 0, 600, 0},     // ITEM_THE_CHARIOT
    {274, 4, 0, 2, 1, 0, 600, 0},     // ITEM_STRENGTH
    {274, 4, 0, 4, 2, 0, 800, 0},     // ITEM_WOF
    {274, 12, 0, 0, 0, 0, 200, 0},    // ITEM_JUSTICE
    {274, 10, 0, 0, 0, 0, 200, 0},    // ITEM_THE_HANGED_MAN
    {274, 10, 0, 1, 0, 0, 200, 0},    // ITEM_DEATH
    {338, 14, 0, 0, 0, 0, 400, 0},    // ITEM_TEMPERANCE
    {786, 6, 0, 2, 10, 0, 200, 0},    // ITEM_THE_DEVIL
    {274, 12, 0, 1, 0, 0, 200, 0},    // ITEM_THE_TOWER
    {274, 13, 0, 0, 0, 0, 400, 0},    // ITEM_THE_STAR
    {786, 6, 0, 1, 10, 0, 200, 0},    // ITEM_THE_MOON
    {786, 6, 0, 0, 10, 0, 200, 0},    // ITEM_THE_SUN
    {258, 0, 0, 0, 0, 0, 400, 0},     // ITEM_JUDGEMENT
    {530, 9, 0, 0, 0, 0, 0, 0},       // ITEM_DARK_CARD
    {514, 0, 0, 0, 0, 0, 0, 0},       // ITEM_PET
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_SPADE_EMBLEM
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_HEART_EMBLEM
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_DIAMOND_EMBLEM
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_CLUB_EMBLEM
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_JOKER_EMBLEM
    {2, 0, 0, 0, 0, 0, 60, 0},        // ITEM_OAK_COFFIN
    {2, 0, 0, 0, 0, 0, 80, 0},        // COFFIN_ITEM_ID(1)
    {2, 0, 0, 0, 0, 0, 100, 0},       // COFFIN_ITEM_ID(2)
    {2, 0, 0, 0, 0, 0, 120, 0},       // COFFIN_ITEM_ID(3)
    {2, 0, 0, 0, 0, 0, 140, 0},       // COFFIN_ITEM_ID(4)
    {2, 0, 0, 0, 0, 0, 160, 0},       // COFFIN_ITEM_ID(5)
    {2, 0, 0, 0, 0, 0, 180, 0},       // COFFIN_ITEM_ID(6)
    {2, 0, 0, 0, 0, 0, 200, 0},       // COFFIN_ITEM_ID(7)
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_WAREHOUSE_KEY
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_CIRCLE_KEY
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_TRIANGLE_KEY
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_SQUARE_KEY
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_RED_CRYSTAL
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_BLUE_CRYSTAL
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_GREEN_CRYSTAL
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_YELLOW_CRYSTAL
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_STONE_TABLET_PIECE
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_TASTY_WATER
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_THE_MAGICIAN
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_THE_HIEROPHANT
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_THE_HERMIT
    {2, 0, 0, 0, 0, 0, 0, 0},         // ITEM_THE_WORLD
};
