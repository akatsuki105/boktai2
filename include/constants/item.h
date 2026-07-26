#ifndef GUARD_ZOKTAI_CONST_ITEM_H
#define GUARD_ZOKTAI_CONST_ITEM_H

#include "constants/coffin.h"

enum ItemID {
  ITEM_EARTHLY_NUT = 0,          // 大地の実
  ITEM_SOLAR_NUT = 1,            // 太陽の実
  ITEM_SPEED_NUT = 2,            // はやさの実
  ITEM_TIPTOE_NUT = 3,           // しのびの実
  ITEM_POWER_NUT = 4,            // ちからの実
  ITEM_CHOCOLATE_BANANA = 5,     // チョコバナナ
  ITEM_BEARNUT = 6,              // がまんの実
  ITEM_SEE_ALL_NUT = 7,          // 千里眼の実
  ITEM_ROTTEN_NUT = 8,           // くさった実
  ITEM_RED_MUSHROOM = 9,         // 赤いキノコ
  ITEM_BLUE_MUSHROOM = 10,       // 青いキノコ
  ITEM_BAD_MUSHROOM = 11,        // 悪いキノコ
  ITEM_DROP_OF_SUN = 12,         // 太陽のしずく
  ITEM_TOMATO_JUICE = 13,        // トマトジュース
  ITEM_ROTTEN_WATER = 14,        // くさった水
  ITEM_TASTY_MEAT = 15,          // おいしい肉
  ITEM_JERKY = 16,               // 干し肉
  ITEM_ROTTEN_MEAT = 17,         // くさった肉
  ITEM_CHOCOLATE = 18,           // チョコレート
  ITEM_MELTED_CHOCOLATE = 19,    // 溶けたチョコ
  ITEM_CHOCOLATE_COVERED = 20,   // チョコまみれ
  ITEM_DELUXE_CHOCOLATE = 21,    // デラックスチョコ
  ITEM_HEALER = 22,              // 回復薬
  ITEM_MAGICAL_POTION = 23,      // 魔法薬
  ITEM_ANTIDOTE = 24,            // 毒消し
  ITEM_ELIXIR = 25,              // 万能薬
  ITEM_SUNBLOCK = 26,            // 日焼け止め
  ITEM_MR_RAINNOT = 27,          // テルテルボーズ
  ITEM_TONNIAR_RM = 28,          // ズーボルテルテ
  ITEM_SUNNY_CLOG = 29,          // おてんきゲタ
  ITEM_WARP_LEAF = 30,           // 転移の葉
  ITEM_THE_FOOL = 31,            // 愚者のカード
  ITEM_THE_HIGH_PRIESTESS = 32,  // 女教皇のカード
  ITEM_THE_EMPRESS = 33,         // 女帝のカード
  ITEM_THE_EMPEROR = 34,         // 皇帝のカード
  ITEM_THE_LOVER = 35,           // 恋人のカード
  ITEM_THE_CHARIOT = 36,         // 戦車のカード
  ITEM_STRENGTH = 37,            // 力のカード
  ITEM_WOF = 38,                 // 運命の輪のカード
  ITEM_JUSTICE = 39,             // 正義のカード
  ITEM_THE_HANGED_MAN = 40,      // 吊るされた男のカード
  ITEM_DEATH = 41,               // 死神のカード
  ITEM_TEMPERANCE = 42,          // 節制のカード
  ITEM_THE_DEVIL = 43,           // 悪魔のカード
  ITEM_THE_TOWER = 44,           // 塔のカード
  ITEM_THE_STAR = 45,            // 星のカード
  ITEM_THE_MOON = 46,            // 月のカード
  ITEM_THE_SUN = 47,             // 太陽のカード
  ITEM_JUDGEMENT = 48,           // 審判のカード
  ITEM_DARK_CARD = 49,           // 暗黒カード
  ITEM_PET = 50,                 // PET
  ITEM_SPADE_EMBLEM = 51,        // スペードの紋章
  ITEM_HEART_EMBLEM = 52,        // ハートの紋章
  ITEM_DIAMOND_EMBLEM = 53,      // ダイアの紋章
  ITEM_CLUB_EMBLEM = 54,         // クラブの紋章
  ITEM_JOKER_EMBLEM = 55,        // ジョーカーの紋章
  ITEM_OAK_COFFIN = 56,          // オークコフィン, = COFFIN_ITEM_ID(COFFIN_OAK)
  // 57..63: COFFIN_ITEM_ID(1..7)
  ITEM_WAREHOUSE_KEY = 64,       // 倉庫のカギ
  ITEM_CIRCLE_KEY = 65,          // ○のカギ
  ITEM_TRIANGLE_KEY = 66,        //  △のカギ
  ITEM_SQUARE_KEY = 67,          // □のカギ
  ITEM_RED_CRYSTAL = 68,         // 赤の水晶
  ITEM_BLUE_CRYSTAL = 69,        // 青の水晶
  ITEM_GREEN_CRYSTAL = 70,       // 緑の水晶
  ITEM_YELLOW_CRYSTAL = 71,      // 黄の水晶
  ITEM_STONE_TABLET_PIECE = 72,  // 石版のかけら
  ITEM_TASTY_WATER = 73,         // おいしい水
  ITEM_THE_MAGICIAN = 74,        // 魔術師のカード
  ITEM_THE_HIEROPHANT = 75,      // 教皇のカード
  ITEM_THE_HERMIT = 76,          // 隠者のカード
  ITEM_THE_WORLD = 77,           // 世界のカード
  ITEM_NONE = -1,
};

#define ITEM_NUM (ITEM_THE_WORLD + 1)

// coffinid -> include/constants/coffin.h
#define COFFIN_ITEM_ID(coffinid) (coffinid + ITEM_OAK_COFFIN)

#endif  // GUARD_ZOKTAI_CONST_ITEM_H
