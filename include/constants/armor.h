#ifndef GUARD_ZOKTAI_CONST_ARMOR_H
#define GUARD_ZOKTAI_CONST_ARMOR_H

enum ArmorID {
  ARMOR_CLOTH_ARMOR = 0,         // クロスアーマー
  ARMOR_LEATHER_ARMOR = 1,       // レザーアーマー
  ARMOR_CHAIN_MAIL = 2,          // チェインメイル
  ARMOR_SILVER_CHAIN = 3,        // シルバーチェイン
  ARMOR_SCALE_MAIL = 4,          // スケイルメイル
  ARMOR_SAMURAI_ARMOR = 5,       // 武者鎧
  ARMOR_BLADE_MAIL = 6,          // プレートメイル
  ARMOR_BRIGANDINE = 7,          // ブリガンダイン
  ARMOR_MAIL_OF_SOL = 8,         // メイルオブソル
  ARMOR_MAIL_OF_DARKNESS = 9,    // メイルオブダーク
  ARMOR_MAIL_OF_LUNA = 10,       // メイルオブルナ
  ARMOR_FIRE_DRAGON_FANG = 11,   // 火竜の牙
  ARMOR_WATER_DRAGON_TAIL = 12,  // 水竜の尾
  ARMOR_WIND_DRAGON_WING = 13,   // 風竜の翼
  ARMOR_EARTH_DRAGON_CLAW = 14,  // 地竜の爪
  ARMOR_DRAGON_SCALE = 15,       // ドラゴンスケイル
  ARMOR_FAIRY_ROBE = 16,         // 妖精の衣
  ARMOR_EARTHLY_ROBE = 17,       // 大地の衣
  ARMOR_RAIN_COAT = 18,          // レインコート
  ARMOR_GARB_OF_LIGHT = 19,      // 光のガーブ
  ARMOR_GARB_OF_DARKNESS = 20,   // 闇のガーブ
  ARMOR_MAGIC_ROBE = 21,         // マジックローブ
  ARMOR_BLOOD_CAPE = 22,         // 血濡れのマント
  ARMOR_SKULL_SUIT = 23,         // スカルスーツ
  ARMOR_TRAINING_GEAR = 24,      // トラックスーツ
  ARMOR_THIEF_CLOTHES = 25,      // 盗人の服
  ARMOR_HUNTER_CLOTHES = 26,     // 狩人の服
  ARMOR_POISON_GUARD = 27,       // ポイズンガード
  ARMOR_WEAPON_GUARD = 28,       // ウエポンガード
  ARMOR_PARADE_ARMOR = 29,       // パレードアーマー
  ARMOR_NINJA_GI = 30,           // 忍装束
  ARMOR_SPIKE_MAIL = 31,         // スパイクメイル
  ARMOR_BLACK_ARMOR = 32,        // 黒の鎧
  ARMOR_MEGA_POWER = 33,         // ロックパワー
  ARMOR_GUTS_POWER = 34,         // ガッツパワー
  ARMOR_PROTO_POWER = 35,        // ブルースパワー
  ARMOR_TOAD_POWER = 36,         // トードパワー
};

#define ARMOR_NONE (-1)

#define ARMOR_NUM (ARMOR_TOAD_POWER + 1)

#endif  // GUARD_ZOKTAI_CONST_ARMOR_H
