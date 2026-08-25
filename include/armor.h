#ifndef GUARD_ZOKTAI_ARMOR_H
#define GUARD_ZOKTAI_ARMOR_H

#include "constants/constants.h"
#include "gba/gba.h"
#include "types.h"

#define ARMORS(slot) (*(gStat->armors + slot))

// ArmorData.effectType (AET = Armor Effect Type)
#define AET_NONE 0
#define AET_SILVER_CHAIN 1    // 赤ジャンゴ: 全ステータス+<value>, 黒ジャンゴ: 全ステータス-<value>
#define AET_BLOOD_CAPE 2      // 赤ジャンゴ: 全ステータス-<value>, 黒ジャンゴ: 全ステータス+<value>
#define AET_STR 3             // チカラ+<value>(武者鎧)
#define AET_SOLAR_WIND 4      // 太陽風の影響を受けない(ブリガンダイン)
#define AET_RES_SOL 5         // ソル属性の耐性+太陽スタンドの蓄積速度が2倍(メイルオブソル)
#define AET_RES_DARK 6        // ダーク属性の耐性(メイルオブダーク)
#define AET_RES_FLAME 7       // フレイム属性の耐性(火竜の牙)
#define AET_RES_FROST 8       // フロスト属性の耐性(水竜の尾)
#define AET_RES_CLOUD 9       // クラウド属性の耐性(風竜の翼)
#define AET_RES_EARTH 10      // アース属性の耐性(地竜の爪)
#define AET_DRAGON_SCALE 11   // フレイム/フロスト/クラウド/アース属性の耐性(ドラゴンスケイル)
#define AET_RES_ALL 12        // 全属性の耐性(メイルオブルナ)
#define AET_FAIRY_ROBE 13     // 妖精虫の効果<value>%(妖精の衣)
#define AET_EARTHLY_ROBE 14   // 太陽の果実の効果<value>%(大地の衣)
#define AET_RAIN_COAT 15      // レインコート
#define AET_SUNLIGHT 16       // 太陽ゲージが<value>%(光のガーブ)
#define AET_ALLNIGHT 17       // 常に夜間の状態になる(闇のガーブ)
#define AET_MAGIC_COST 18     // 魔法のエナジー消費量が<value>%カット(マジックローブ)
#define AET_SKULL_SUIT 19     // 敵の視界が通常の半分の範囲になる(スカルスーツ)
#define AET_EXP_BOOST 20      // 獲得経験値が<value>%アップ(トレーニングギア)
#define AET_NORMAL_DROP 21    // 通常アイテムのドロップ率を<value>%にする(盗人の服)
#define AET_RARE_DROP 22      // レアアイテムのドロップ率を<value>%にする(狩人の服)
#define AET_IMMUNE_POISON 23  // 毒無効(ポイズンガード)
#define AET_WEAPON_GUARD 24   // 武器の耐久が減らない(ウエポンガード)
#define AET_PARADE 25         // クリムゾンの出現率を20%に(パレードアーマー)
#define AET_AGILITY 26        // ハヤサ+<value>(忍者着)
#define AET_SPIKE 27          // ダメージを受けると、敵に<value>のダメージを与える(スパイクメイル)
#define AET_BLACK_ARMOR 28    // 忘れた(黒の鎧)
#define AET_MEGA_POWER 29     // ロックバスターでチャージショットができるようになる(ロックパワー)
#define AET_GUTS_POWER 30     // 全てのダメージ半減(ガッツパワー)
#define AET_PROTO_POWER 31    // 赤ジャンゴのとき攻撃速度1.5倍(ブルースパワー)
#define AET_TOAD_POWER 32     // 雨を浴びるとエナジー回復(トードパワー)

typedef struct {
  u8 id;          // 0x00, see include/constants/armor.h
  u8 defence;     // 0x01, 耐久力
  u8 weight;      // 0x02, 重量
  u8 effectType;  // 0x03, see AET_xxx
  u8 value;       // 0x04, 特殊効果の効果値(Str+2なら2, Spe+10なら10みたいな)
  s16 price;      // 0x06
} ArmorData;
static_assert(sizeof(ArmorData) == 8);

extern const ArmorData gArmorDB[ARMOR_NUM];

// --------------------------------------------

armor32_t GetInventoryArmor(slot32_t n);
void SetArmorIntoInventory(slot32_t n, armor32_t a);
bool32 IsArmorAlreadyFound(armor32_t);
void SetArmorFoundFlag(armor32_t n);

#endif  // GUARD_ZOKTAI_ARMOR_H
