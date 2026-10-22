#ifndef __INCLUDE_CONSTANTS_MISCS_H__
#define __INCLUDE_CONSTANTS_MISCS_H__

#define STAT_VITALITY 0  // カラダ
#define STAT_SPIRIT 1    // ココロ
#define STAT_STRENGTH 2  // チカラ
#define STAT_AGILITY 3   // ハヤサ
#define STAT_KINDS 4

// 向き
#define FACE_UP 0          // 上
#define FACE_UP_RIGHT 1    // 右上
#define FACE_RIGHT 2       // 右
#define FACE_DOWN_RIGHT 3  // 右下
#define FACE_DOWN 4        // 下
#define FACE_DOWN_LEFT 5   // 左下
#define FACE_LEFT 6        // 左
#define FACE_UP_LEFT 7     // 左上

// 良いステータス効果
#define GOOD_NINJA 0      // しのびの実
#define GOOD_SPEED 1      // 移動速度1.5倍(はやさの実)
#define GOOD_POWER 2      // 運搬速度アップ(ちからの実)
#define GOOD_GAMAN 3      // ダメージ無効(がまんの実)
#define GOOD_SEE 4        // 見えないアイテムや罠が見える(千里眼の実)
#define GOOD_MINI 5       // 小人(赤いキノコ)
#define GOOD_INVISIBLE 6  // 透明状態(青いキノコ)
#define GOOD_UVCUT 7      // 日焼け止め
#define GOOD_EMPEROR 8    // 全属性に耐性(皇帝のカード)

// 悪いステータス効果
#define BAD_HARAITA 0  // 腹痛 (移動すると画面にモザイクがかかる)
#define BAD_POISON 1   // 毒
#define BAD_CONFUSE 2  // 混乱

// EnemyKind, GameInfo.enemyKillCount[24] の idx?
#define ENEKD_BOKU 0               // ボク系
#define ENEKD_MUMMY 1              // マミー系(マミー, ガスト)
#define ENEKD_SPIDER 2             // スパイダー系(スパイダー, ポイズンスパイダー)
#define ENEKD_GOLEM 3              // ゴーレム系
#define ENEKD_SKELETON 4           // スケルトン系
#define ENEKD_LICH 5               // リッチ系
#define ENEKD_CENTIPEDE 6          // センチピード
#define ENEKD_COCKATRICE 7         // コカトリス系
#define ENEKD_MIMIC 8              // ミミック
#define ENEKD_SWORD 9              // ソード系
#define ENEKD_AX 10                // アックス系
#define ENEKD_OCTOPUS 11           // オクトパス系
#define EKEKD_12 12                // ???
#define ENEKD_CURORO 13            // クロロホルルン系
#define ENEKD_BAT 14               // バット系
#define ENEKD_CROW 15              // クロウ系
#define ENEKD_DOG 16               // 犬系
#define ENEKD_SLIME 17             // スライム系
#define ENEKD_BEE 18               // ビー系
#define ENEKD_GHOST 19             // ゴースト系
#define ENEKD_SAND_WORM 20         // サンドウォーム
#define ENEKD_SERPENT 21           // サーペント
#define ENEKD_SHAIAN 22            // シャイアン
#define ENEKD_ROOT_OF_DARKNESS 23  // 暗黒の根

#endif  // __INCLUDE_CONSTANTS_MISCS_H__
