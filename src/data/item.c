#include "item.h"

#include "armor.h"
#include "global.h"
#include "weapon.h"

const WeaponTemplate gWeaponDB[66] = {
    {WEAPON_NONE, WK_OTHERS, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {WEAPON_GRADIUS, WK_SWORD, 0, 1, 12805, 0, 100, 0, 0, 0, 0, 0, 0},
    {WEAPON_SHORT_SWORD, WK_SWORD, 0, 5, 14092, 0, 120, 0, 0, 0, 0, 0, 0},
    {WEAPON_BROAD_SWORD, WK_SWORD, 0, 9, 15376, 0, 150, 0, 0, 0, 0, 0, 0},
    {WEAPON_LONG_SWORD, WK_SWORD, 0, 13, 16661, 0, 190, 0, 0, 0, 0, 0, 0},
    {WEAPON_DULL_BLADE, WK_SWORD, 4, 1, 12801, 0, 50, 0, 0, 0, 2587, 0, 0},
    {WEAPON_ZWEIHANDER, WK_SWORD, 1, 17, 17945, 0, 240, 0, 0, 0, 2576, 0, 0},
    {WEAPON_FLAMEBERGE, WK_SWORD, 1, 21, 19230, 0, 300, 0, 0, 0, 2578, 0, 0},
    {WEAPON_CLAYMORE, WK_SWORD, 1, 25, 20514, 0, 370, 0, 0, 0, 2576, 0, 0},
    {WEAPON_MAGIC_SWORD, WK_SWORD, 1, 29, 21799, 0, 450, 0, 0, 0, 5150, 0, 0},
    {WEAPON_KATANA, WK_SWORD, 4, 17, 12834, 0, 500, 0, 0, 0, 2058, 0, 0},
    {WEAPON_BASTARD_SWORD, WK_SWORD, 2, 33, 23083, 0, 540, 0, 0, 0, 671761, 0, 0},
    {WEAPON_GREAT_SWORD, WK_SWORD, 2, 37, 25648, 0, 640, 0, 0, 0, 31, 0, 0},
    {WEAPON_BUSHIDO_SWORD, WK_SWORD, 2, 41, 28202, 0, 750, 0, 0, 0, 3, 0, 0},
    {WEAPON_BLOOD_SWORD, WK_SWORD, 2, 45, 30777, 0, 870, 0, 0, 0, 285, 0, 0},
    {WEAPON_MURAMASA, WK_SWORD, 4, 33, 23092, 0, 900, 0, 0, 0, 2058, 0, 0},
    {WEAPON_VORPAL_SWORD, WK_SWORD, 3, 49, 33341, 0, 1000, 0, 0, 0, 2573, 0, 0},
    {WEAPON_SOLAR_SWORD, WK_SWORD, 3, 53, 35906, 0, 1250, 0, 0, 0, 14, 0, 0},
    {WEAPON_DARK_SWORD, WK_SWORD, 4, 53, 35906, 0, 1500, 0, 0, 0, 2575, 0, 0},
    {WEAPON_GRAM, WK_SWORD, 4, 57, 38470, 0, 2000, 0, 0, 0, 0, 0, 0},
    {WEAPON_SHORT_SPEAR, WK_SPEAR, 0, 1, 12808, 0, 100, 0, 0, 0, 0, 0, 0},
    {WEAPON_GLAIVE, WK_SPEAR, 0, 5, 14095, 0, 120, 0, 0, 0, 0, 0, 0},
    {WEAPON_LONG_SPEAR, WK_SPEAR, 0, 9, 15380, 0, 150, 0, 0, 0, 0, 0, 0},
    {WEAPON_LANCE, WK_SPEAR, 0, 13, 16665, 0, 190, 0, 0, 0, 0, 0, 0},
    {WEAPON_STAFF, WK_SPEAR, 4, 1, 12804, 0, 50, 0, 0, 0, 2587, 0, 0},
    {WEAPON_CORSESCA, WK_SPEAR, 1, 17, 17950, 0, 240, 0, 0, 0, 28, 0, 0},
    {WEAPON_FIRE_PAW, WK_SPEAR, 1, 21, 19235, 0, 300, 0, 0, 0, 2578, 0, 0},
    {WEAPON_BARDICHE, WK_SPEAR, 1, 25, 20520, 0, 370, 0, 0, 0, 31, 0, 0},
    {WEAPON_ICE_GLAIVE, WK_SPEAR, 1, 29, 21805, 0, 450, 0, 0, 0, 2579, 0, 0},
    {WEAPON_RUNE_GLAIVE, WK_SPEAR, 4, 17, 12840, 0, 500, 0, 0, 0, 2057, 0, 0},
    {WEAPON_PARTIZAN, WK_SPEAR, 2, 33, 23090, 0, 540, 0, 0, 0, 28, 0, 0},
    {WEAPON_THUNDER_SPEAR, WK_SPEAR, 2, 37, 25655, 0, 640, 0, 0, 0, 2580, 0, 0},
    {WEAPON_BLOOD_SPEAR, WK_SPEAR, 2, 41, 28220, 0, 750, 0, 0, 0, 285, 0, 0},
    {WEAPON_GRAND_LANCE, WK_SPEAR, 2, 45, 30785, 0, 870, 0, 0, 0, 2581, 0, 0},
    {WEAPON_RUNE_SPEAR, WK_SPEAR, 4, 33, 23100, 0, 900, 0, 0, 0, 2057, 0, 0},
    {WEAPON_HALBERD, WK_SPEAR, 3, 49, 33350, 0, 1000, 0, 0, 0, 12, 0, 0},
    {WEAPON_WHITE_QUEEN, WK_SPEAR, 3, 53, 35915, 0, 1250, 0, 0, 0, 14, 0, 0},
    {WEAPON_BLACK_QUEEN, WK_SPEAR, 4, 53, 35915, 0, 1500, 0, 0, 0, 2575, 0, 0},
    {WEAPON_GUNGNIR, WK_SPEAR, 4, 57, 38480, 0, 2000, 0, 0, 0, 0, 0, 0},
    {WEAPON_CLUB, WK_HAMMER, 0, 1, 12811, 0, 100, 0, 0, 0, 0, 0, 0},
    {WEAPON_HAMMER, WK_HAMMER, 0, 5, 14098, 0, 120, 0, 0, 0, 0, 0, 0},
    {WEAPON_MACE, WK_HAMMER, 0, 9, 15384, 0, 150, 0, 0, 0, 0, 0, 0},
    {WEAPON_FLAIL, WK_HAMMER, 0, 13, 16669, 0, 190, 0, 0, 0, 0, 0, 0},
    {WEAPON_POUNDER, WK_HAMMER, 4, 1, 12807, 0, 50, 0, 0, 0, 2587, 0, 0},
    {WEAPON_AXE, WK_HAMMER, 1, 17, 17955, 0, 240, 0, 0, 0, 2582, 0, 0},
    {WEAPON_MAUL, WK_HAMMER, 1, 21, 19240, 0, 300, 0, 0, 0, 2583, 0, 0},
    {WEAPON_SILVER_MACE, WK_HAMMER, 1, 25, 20526, 0, 370, 0, 0, 0, 2584, 0, 0},
    {WEAPON_SILVER_FLAIL, WK_HAMMER, 1, 29, 21811, 0, 450, 0, 0, 0, 2585, 0, 0},
    {WEAPON_HEAVY_MACE, WK_HAMMER, 4, 17, 12846, 0, 500, 0, 0, 0, 2056, 0, 0},
    {WEAPON_BATTLE_AXE, WK_HAMMER, 2, 33, 23097, 0, 540, 0, 0, 0, 671761, 0, 0},
    {WEAPON_WAR_HAMMER, WK_HAMMER, 2, 37, 25662, 0, 640, 0, 0, 0, 31, 0, 0},
    {WEAPON_BLOODY_MACE, WK_HAMMER, 2, 41, 28228, 0, 750, 0, 0, 0, 285, 0, 0},
    {WEAPON_MORNING_STAR, WK_HAMMER, 2, 45, 30793, 0, 870, 0, 0, 0, WET_ANTI_IMMORTAL, 0, 0},
    {WEAPON_HEAVY_AXE, WK_HAMMER, 4, 33, 23108, 0, 900, 0, 0, 0, 2056, 0, 0},
    {WEAPON_EARTH_SHAKER, WK_HAMMER, 3, 49, 33359, 0, 1000, 0, 0, 0, 11, 0, 0},
    {WEAPON_DAYBREAK, WK_HAMMER, 3, 53, 35924, 0, 1250, 0, 0, 0, 14, 0, 0},
    {WEAPON_TWILIGHT, WK_HAMMER, 4, 53, 35924, 0, 1500, 0, 0, 0, 2575, 0, 0},
    {WEAPON_MJOLLNIR, WK_HAMMER, 4, 57, 38490, 0, 2000, 0, 0, 0, 0, 0, 0},
    {WEAPON_BROKEN_GUN, WK_GUN, 4, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {WEAPON_GUN_DEL_SOL, WK_GUN, 2, 1, 75, 0, 0, 0, 0, 0, 1, 0, 0},
    {WEAPON_GUN_DEL_HELL, WK_GUN, 2, 1, 80, 0, 0, 0, 0, 0, 2562, 0, 0},
    {WEAPON_MEGA_BUSTER, WK_GUN, 3, 1, 85, 0, 0, 0, 0, 0, 4, 0, 0},
    {WEAPON_STAR_PIECE, WK_OTHERS, 4, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {WEAPON_ASTRO_SWORD, WK_SWORD, 4, 1, 6, 0, 0, 0, 0, 0, 5, 0, 0},
    {WEAPON_ASTRO_SPEAR, WK_SPEAR, 4, 1, 6, 0, 0, 0, 0, 0, 6, 0, 0},
    {WEAPON_ASTRO_HAMMER, WK_HAMMER, 4, 1, 6, 0, 0, 0, 0, 0, 7, 0, 0},
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
