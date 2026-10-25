#ifndef __INCLUDE_CONSTANTS_MISCS_H__
#define __INCLUDE_CONSTANTS_MISCS_H__

#define FRAME_PER_SECOND 60                        // 1秒のフレーム数
#define SECOND(n) ((int)((n) * FRAME_PER_SECOND))  // 1秒をフレーム数で表す

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

// SPRITE_UI_START_MENU の poseIdx
#define SMENU_NUM_BROWN(num) (0 + (num))  // 茶色の数字の poseIdx, 0 から始まる
#define SMENU_NUM_BLUE(num) (10 + (num))  // SMENU_NUM_BROWN の青色版
#define SMENU_NUM_RED(num) (20 + (num))   // SMENU_NUM_BROWN の赤色版
#define SMENU_NUM_BOLD(num) (30 + (num))  // SMENU_NUM_BROWN の縁取り付き版
#define SMENU_NUM_BOLD_DASH 40
#define SMENU_PAGE(pageIdx) (41 + (pageIdx))              // スタートメニューで左上に表示される 現在のページ名
#define SMENU_MAP_CHANGE 51                               // マップが複数階層あるときの階層切り替えUI
#define SMENU_MAP_SCROLL(dir) (52 + (dir))                // マップのスクロール方向を示すアイコン, dir は 0: 左, 1: 右, 2: 上, 3: 下
#define SMENU_CURSOR(pulseStep) (56 + (pulseStep))        // インベントリで現在位置のカーソル(赤)
#define SMENU_SELECTED 60                                 // インベントリで選択中を表すカーソル(青)
#define SMENU_EQUIP_CURSOR(pulseStep) (61 + (pulseStep))  // 装備中の武器に表示されるカーソル
#define SMENU_EQUIP_E 65                                  // 装備中のアイコンの右下につく"E"
#define SMENU_STATBAR(kind) (66 + (kind))                 // ステータスメニューの カラダ/ココロ/チカラ/ハヤサの各ステータスバー
#define SMENU_STAT_ASSIGN 77                              // "ふりわけ"
#define SMENU_STAT_ASSIGN_OK 78                           // "Aけってい"
#define SMENU_PAGE_LONG(idx) (100 + (idx))                // SMENU_PAGE の長いバージョン (どこで使ってたか忘れた)
#define SMENU_L_ICON 137                                  // Lボタンのアイコン, SMENU_PAGE と合わせて使う
#define SMENU_R_ICON 138                                  // Rボタンのアイコン, SMENU_PAGE と合わせて使う
#define SMENU_BACK 147                                    // "Bもどる"
#define SMENU_YESNO(pulseStep) (148 + (pulseStep))        // "はい/いいえ" の選択肢
#define SMENU_SELECT 156                                  // "SELECT"
#define SMENU_ITEM_BAG 157                                // アイテムインベントリの左上の "ITEM BAG"
#define SMENU_BADCOND_NAME(kind) (170 + (kind))           // 悪いステータス効果のアイコン+名前, kind は 0: ヒョウケツ, 1: インカ, 2: セキカ, 3: カーモス, 4: 毒, 5: 混乱, 6: 腹痛
#define SMENU_BADCOND_ICON(kind) (177 + (kind))           // 悪いステータス効果のアイコンのみ, kind は 0: ヒョウケツ, 1: インカ, 2: セキカ, 3: カーモス, 4: 毒, 5: 混乱, 6: 腹痛

#endif  // __INCLUDE_CONSTANTS_MISCS_H__
