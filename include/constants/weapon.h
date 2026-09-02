#ifndef GUARD_ZOKTAI_CONST_WEAPON_H
#define GUARD_ZOKTAI_CONST_WEAPON_H

// WeaponKind
#define WK_SWORD 0   // 剣(ソード)
#define WK_SPEAR 1   // 槍(スピア)
#define WK_HAMMER 2  // 槌(ハンマー)
#define WK_OTHERS 3  // その他(拳, 星のかけら)
#define WK_GUN 4     // 銃

// Weapon ID
#define WEAPON_NONE 0            // 装備なし (拳)
#define WEAPON_GRADIUS 1         // グラディウス
#define WEAPON_SHORT_SWORD 2     // ショートソード
#define WEAPON_BROAD_SWORD 3     // ブロードソード
#define WEAPON_LONG_SWORD 4      // ロングソード
#define WEAPON_DULL_BLADE 5      // なまくら
#define WEAPON_ZWEIHANDER 6      // ツヴァイハンダー
#define WEAPON_FLAMEBERGE 7      // フランベルジュ
#define WEAPON_CLAYMORE 8        // クレイモア
#define WEAPON_MAGIC_SWORD 9     // マジックソード
#define WEAPON_KATANA 10         // 刀
#define WEAPON_BASTARD_SWORD 11  // バスタードソード
#define WEAPON_GREAT_SWORD 12    // グレートソード
#define WEAPON_BUSHIDO_SWORD 13  // 武士道ブレード
#define WEAPON_BLOOD_SWORD 14    // ブラッドソード
#define WEAPON_MURAMASA 15       // 村正
#define WEAPON_VORPAL_SWORD 16   // ウォーバルソード
#define WEAPON_SOLAR_SWORD 17    // 太陽の剣
#define WEAPON_DARK_SWORD 18     // 暗黒の剣
#define WEAPON_GRAM 19           // グラム
#define WEAPON_SHORT_SPEAR 20    // ショートスピア
#define WEAPON_GLAIVE 21         // グレイブ
#define WEAPON_LONG_SPEAR 22     // ロングスピア
#define WEAPON_LANCE 23          // ランス
#define WEAPON_STAFF 24          // 六尺棒
#define WEAPON_CORSESCA 25       // コルセスカ
#define WEAPON_FIRE_PAW 26       // ファイヤーポー
#define WEAPON_BARDICHE 27       // バルディッシュ
#define WEAPON_ICE_GLAIVE 28     // アイスグレイブ
#define WEAPON_RUNE_GLAIVE 29    // ルーングレイブ
#define WEAPON_PARTIZAN 30       // パルチザン
#define WEAPON_THUNDER_SPEAR 31  // サンダースピア
#define WEAPON_BLOOD_SPEAR 32    // ブラッドスピア
#define WEAPON_GRAND_LANCE 33    // グランドランス
#define WEAPON_RUNE_SPEAR 34     // ルーンスピア
#define WEAPON_HALBERD 35        // ハルバード
#define WEAPON_WHITE_QUEEN 36    // ホワイトクイーン
#define WEAPON_BLACK_QUEEN 37    // ブラッククイーン
#define WEAPON_GUNGNIR 38        // グングニル
#define WEAPON_CLUB 39           // クラブ
#define WEAPON_HAMMER 40         // ハンマー
#define WEAPON_MACE 41           // メイス
#define WEAPON_FLAIL 42          // フレイル
#define WEAPON_POUNDER 43        // とんかち
#define WEAPON_AXE 44            // アックス
#define WEAPON_MAUL 45           // モール
#define WEAPON_SILVER_MACE 46    // シルバーメイス
#define WEAPON_SILVER_FLAIL 47   // シルバーフレイル
#define WEAPON_HEAVY_MACE 48     // ヘヴィメイス
#define WEAPON_BATTLE_AXE 49     // バトルアックス
#define WEAPON_WAR_HAMMER 50     // ウォーハンマー
#define WEAPON_BLOODY_MACE 51    // ブラッディメイス
#define WEAPON_MORNING_STAR 52   // モーニングスター
#define WEAPON_HEAVY_AXE 53      // ヘヴィアックス
#define WEAPON_EARTH_SHAKER 54   // アースシェイカー
#define WEAPON_DAYBREAK 55       // あかつき
#define WEAPON_TWILIGHT 56       // たそがれ
#define WEAPON_MJOLLNIR 57       // ミョルニル
#define WEAPON_BROKEN_GUN 58     // 壊れた太陽銃
#define WEAPON_GUN_DEL_SOL 59    // ガン・デル・ソル
#define WEAPON_GUN_DEL_HELL 60   // ガン・デル・ヘル
#define WEAPON_MEGA_BUSTER 61    // ロックバスター
#define WEAPON_STAR_PIECE 62     // 星のかけら
#define WEAPON_ASTRO_SWORD 63    // アストロソード
#define WEAPON_ASTRO_SPEAR 64    // アストロスピア
#define WEAPON_ASTRO_HAMMER 65   // アストロハンマー
#define WEAPON_NUM 66

// Weapon Effect Type ID (武器の特殊効果ID)
#define WET_NONE 0
#define WET_GUN_DEL_SOL 1     // 太陽ゲージが高いほど威力アップ!(ガン・デル・ソル)
#define WET_GUN_DEL_HELL 2    // 夜の間は威力アップ!(ガン・デル・ヘル)
#define WET_KAJIBA 3          // ライフが減ると威力アップ
#define WET_GYAKU_KAJIBA 4    // ライフが減ると威力ダウン
#define WET_ASTRO_SWORD 5     // アストロソードの特殊効果
#define WET_ASTRO_SPEAR 6     // アストロスピアの特殊効果
#define WET_ASTRO_HAMMER 7    // アストロハンマーの特殊効果
#define WET_VITALITY 8        // カラダに応じて威力アップ
#define WET_SPIRIT 9          // ココロに応じて威力アップ
#define WET_AGILITY 10        // ハヤサに応じて威力アップ
#define WET_HP 11             // ライフに応じて威力アップ
#define WET_ENE 12            // エナジーに応じて威力アップ
#define WET_STATCOND 13       // 状態異常時に威力アップ
#define WET_SOL 14            // 太陽ゲージが高いほど威力アップ!(太陽の剣, あかつき)
#define WET_NIGHT 15          // 夜の間は威力アップ(暗黒の剣, たそがれ)
#define WET_RANDOM 16         // たまに追加ダメージ(ツヴァイハンダー,クレイモア)
#define WET_KILLCOUNT 17      // 同じタイプの敵の討伐数に応じて威力アップ(バスタードソード, バトルアックス)
#define WET_FLAME 18          // フレイム属性で攻撃した時に威力アップ(フランベルジュ)
#define WET_FROST 19          // フロスト〃
#define WET_CLOUD 20          // クラウド〃
#define WET_EARTH 21          // アース〃(グランドランス)
#define WET_ANTI_BEAST 22     // ビーストタイプへの攻撃時に追加ダメージ(アックス)
#define WET_ANTI_THING 23     // シング〃(モール)
#define WET_ANTI_PHANTOM 24   // ファントム〃(シルバーメイス)
#define WET_ANTI_UNDEAD 25    // アンデッド〃(シルバーフレイル)
#define WET_ANTI_IMMORTAL 26  // イモータル〃(モーニングスター)
#define WET_NAMAKURA 27       // 10%の確率で敵の防御を無視して攻撃(なまくら系)
#define WET_PARALYZE 28       // 10%の確率でマヒ
#define WET_BLOOD_SWORD 29    // 敵を倒すとライフが変化, 赤ジャンゴ: -1, 黒ジャンゴ: +1
#define WET_ENE_COST 30       // エンチャント攻撃のMP消費を下げる(マジックソード)
#define WET_DURABILITY 31     // 武器の耐久消費を減らす

#endif  // GUARD_ZOKTAI_CONST_WEAPON_H
