#ifndef __INCLUDE_CONSTANTS_MISCS_H__
#define __INCLUDE_CONSTANTS_MISCS_H__

#define FRAME_PER_SECOND 60                        // 1秒のフレーム数
#define SECOND(n) ((int)((n) * FRAME_PER_SECOND))  // 1秒をフレーム数で表す

#define STAT_VITALITY 0  // カラダ (HP最大値に影響)
#define STAT_SPIRIT 1    // ココロ (ENE最大値に影響)
#define STAT_STRENGTH 2  // チカラ (攻撃力に影響)
#define STAT_AGILITY 3   // ハヤサ (プレイヤーの移動速度や防御力に影響)
#define STAT_KINDS 4

// 向き, 対応する angle (256 で一周) も併記する, angle は 0 が東 (+x) で, 増えるほど南 (+z) へ回る
#define DIR8_UP 0          // 画面上, 北西 (-x, -z), angle 160
#define DIR8_UP_RIGHT 1    // 画面右上, 北 (-z), angle 192
#define DIR8_RIGHT 2       // 画面右, 北東 (+x, -z), angle 224
#define DIR8_DOWN_RIGHT 3  // 画面右下, 東 (+x), angle 0
#define DIR8_DOWN 4        // 画面下, 南東 (+x, +z), angle 32
#define DIR8_DOWN_LEFT 5   // 画面左下, 南 (+z), angle 64
#define DIR8_LEFT 6        // 画面左, 南西 (-x, +z), angle 96
#define DIR8_UP_LEFT 7     // 画面左上, 西 (-x), angle 128

// 4方向の向き (Angle_ToDir4 の戻り値), 対応する angle (256 で一周) も併記する
#define DIR4_NORTH 0  // -z, 画面右上, angle 192
#define DIR4_EAST 1   // +x, 画面右下, angle 0
#define DIR4_SOUTH 2  // +z, 画面左下, angle 64
#define DIR4_WEST 3   // -x, 画面左上, angle 128

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

#endif  // __INCLUDE_CONSTANTS_MISCS_H__
