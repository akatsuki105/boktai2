#ifndef GUARD_ZOKTAI_CONST_ARMOR_H
#define GUARD_ZOKTAI_CONST_ARMOR_H

// Armor ID
#define ARMOR_CLOTH_ARMOR 0         // クロスアーマー
#define ARMOR_LEATHER_ARMOR 1       // レザーアーマー
#define ARMOR_CHAIN_MAIL 2          // チェインメイル
#define ARMOR_SILVER_CHAIN 3        // シルバーチェイン
#define ARMOR_SCALE_MAIL 4          // スケイルメイル
#define ARMOR_SAMURAI_ARMOR 5       // 武者鎧
#define ARMOR_BLADE_MAIL 6          // プレートメイル
#define ARMOR_BRIGANDINE 7          // ブリガンダイン
#define ARMOR_MAIL_OF_SOL 8         // メイルオブソル
#define ARMOR_MAIL_OF_DARKNESS 9    // メイルオブダーク
#define ARMOR_MAIL_OF_LUNA 10       // メイルオブルナ
#define ARMOR_FIRE_DRAGON_FANG 11   // 火竜の牙
#define ARMOR_WATER_DRAGON_TAIL 12  // 水竜の尾
#define ARMOR_WIND_DRAGON_WING 13   // 風竜の翼
#define ARMOR_EARTH_DRAGON_CLAW 14  // 地竜の爪
#define ARMOR_DRAGON_SCALE 15       // ドラゴンスケイル
#define ARMOR_FAIRY_ROBE 16         // 妖精の衣
#define ARMOR_EARTHLY_ROBE 17       // 大地の衣
#define ARMOR_RAIN_COAT 18          // レインコート
#define ARMOR_GARB_OF_LIGHT 19      // 光のガーブ
#define ARMOR_GARB_OF_DARKNESS 20   // 闇のガーブ
#define ARMOR_MAGIC_ROBE 21         // マジックローブ
#define ARMOR_BLOOD_CAPE 22         // 血濡れのマント
#define ARMOR_SKULL_SUIT 23         // スカルスーツ
#define ARMOR_TRAINING_GEAR 24      // トラックスーツ
#define ARMOR_THIEF_CLOTHES 25      // 盗人の服
#define ARMOR_HUNTER_CLOTHES 26     // 狩人の服
#define ARMOR_POISON_GUARD 27       // ポイズンガード
#define ARMOR_WEAPON_GUARD 28       // ウエポンガード
#define ARMOR_PARADE_ARMOR 29       // パレードアーマー
#define ARMOR_NINJA_GI 30           // 忍装束
#define ARMOR_SPIKE_MAIL 31         // スパイクメイル
#define ARMOR_BLACK_ARMOR 32        // 黒の鎧
#define ARMOR_MEGA_POWER 33         // ロックパワー
#define ARMOR_GUTS_POWER 34         // ガッツパワー
#define ARMOR_PROTO_POWER 35        // ブルースパワー
#define ARMOR_TOAD_POWER 36         // トードパワー
#define ARMOR_NUM 37
#define ARMOR_NONE (-1)

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

#endif  // GUARD_ZOKTAI_CONST_ARMOR_H
