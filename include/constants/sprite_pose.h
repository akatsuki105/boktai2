#ifndef __INCLUDE_CONSTANTS_SPRITE_POSE_H__
#define __INCLUDE_CONSTANTS_SPRITE_POSE_H__

// --------------------------------------------
// SPRITE_UI_START_MENU

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
#define SMENU_BRACE_L(pulseStep) (139 + (pulseStep))      // 括弧のアイコン "[", pulseStep は 0 から 3
#define SMENU_BRACE_R(pulseStep) (143 + (pulseStep))      // 括弧のアイコン "]", pulseStep は 0 から 3
#define SMENU_BACK 147                                    // "Bもどる"
#define SMENU_YESNO(pulseStep) (148 + (pulseStep))        // "はい/いいえ" の選択肢
#define SMENU_SELECT 156                                  // "SELECT"
#define SMENU_ITEM_BAG 157                                // アイテムインベントリの左上の "ITEM BAG"
#define SMENU_BADCOND_NAME(kind) (170 + (kind))           // 悪いステータス効果のアイコン+名前, kind は 0: ヒョウケツ, 1: インカ, 2: セキカ, 3: カーモス, 4: 毒, 5: 混乱, 6: 腹痛
#define SMENU_BADCOND_ICON(kind) (177 + (kind))           // 悪いステータス効果のアイコンのみ, kind は 0: ヒョウケツ, 1: インカ, 2: セキカ, 3: カーモス, 4: 毒, 5: 混乱, 6: 腹痛

// --------------------------------------------
// SPRITE_UI_LINK

#define LINK_NUMBER_S1(num) (0 + (num))   // 0..9 までの小さな数字 (パレットが違う2種類のうちの1つ)
#define LINK_COLON 10                     // ":" の文字
#define LINK_NUMBER_S2(num) (11 + (num))  // 0..9 までの小さな数字 (パレットが違う2種類のうちの1つ)
#define LINK_POSE21 21
#define LINK_SELL_BUY(cursor) (22 + (cursor))  // "売る 買う", (cursor 0: 売る, 1: 買う)
#define LINK_POSE24 24
#define LINK_POSE25 25
#define LINK_POSE26 26
#define LINK_POSE27 27
#define LINK_POSE28 28
#define LINK_POSE29 29
#define LINK_POSE30 30
#define LINK_POSE31 31
#define LINK_READY(phase) (32 + (phase))  // "READY" の大文字, phase は 0: "READY", 1: "READY.", 2: "READY..", 3: "READY..."
#define LINK_FIGHT 36                     // "FIGHT!" の大文字
#define LINK_FINISH 37                    // "FINISH!" の大文字
#define LINK_ROUND 38                     // "ROUND" の大文字
#define LINK_NUMBER_L(num) (39 + (num))   // 0..9 までの大きな数字
#define LINK_BLOCKING 49                  // "BLOCKING！！" の大文字
#define LINK_DOUBLE_BANG 50               // "!!" の大文字
#define LINK_POSE51 51
#define LINK_POSE52 52
#define LINK_POSE53 53
#define LINK_POSE54 54
#define LINK_POSE55 55
#define LINK_POSE56 56
#define LINK_POSE57 57
#define LINK_POSE58 58
#define LINK_POSE59 59
#define LINK_POSE60 60
#define LINK_POSE61 61
#define LINK_STRENGTH_RED 62              // LINK_STRENGTH_ICON(0) の色を赤くしたもの, error用?
#define LINK_STRENGTH_ICON(n) (63 + (n))  // 0..3 (0: 電波0, 1: 電波1, 2: 電波2, 3: 電波3)
#define LINK_PUSHSTART 67                 // "PUSH START" の文字
#define LINK_INTERVAL 68                  // "INTERVAL" の文字
#define LINK_WAIT 69                      // "WAIT..." の文字
#define LINK_BLOCK_ON 70                  // "BLOCK ON" の文字
#define LINK_BLOCK_OFF 71                 // "BLOCK OFF" の文字
#define LINK_RESULT_WIN 72                // "WIN!"
#define LINK_RESULT_LOSE 73               // "LOSE!"
#define LINK_RESULT_DRAW 74               // "DRAW"
#define LINK_MAX_MODE 75                  // "MAX MODE!" の文字

// --------------------------------------------
// SPRITE_UI_MISC

#define UI_MISC_POSE_0 0
#define UI_MISC_POSE_1 1
#define UI_MISC_POSE_2 2
#define UI_MISC_POSE_3 3
#define UI_MISC_POSE_4 4
#define UI_MISC_POSE_5 5
#define UI_MISC_POSE_6 6
#define UI_MISC_POSE_7 7
#define UI_MISC_POSE_8 8
#define UI_MISC_POSE_9 9
#define UI_MISC_POSE_10 10
#define UI_MISC_POSE_11 11
#define UI_MISC_POSE_12 12
#define UI_MISC_POSE_13 13
#define UI_MISC_POSE_14 14
#define UI_MISC_POSE_15 15
#define UI_MISC_POSE_16 16
#define UI_MISC_POSE_17 17
#define UI_MISC_POSE_18 18
#define UI_MISC_POSE_19 19
#define UI_FORGE_GREAT 20
#define UI_FORGE_GOOD 21
#define UI_FORGE_BAD 22
#define UI_MISC_POSE_23 23
#define UI_MISC_POSE_24 24
#define UI_MISC_POSE_25 25
#define UI_MISC_POSE_26 26
#define UI_MISC_POSE_27 27
#define UI_MISC_POSE_28 28
#define UI_MISC_POSE_29 29
#define UI_MISC_POSE_30 30
#define UI_MISC_POSE_31 31
#define UI_MISC_POSE_32 32
#define UI_MISC_POSE_33 33
#define UI_MISC_POSE_34 34
#define UI_MISC_POSE_35 35
#define UI_MISC_POSE_36 36
#define UI_MISC_POSE_37 37
#define UI_MISC_POSE_38 38
#define UI_MISC_POSE_39 39
#define UI_MISC_POSE_40 40
#define UI_MISC_POSE_41 41

// --------------------------------------------
// SPRITE_PORTRAITS 0..29
#define PORTRAIT_RDJANGO 0  // 赤ジャンゴ
#define PORTRAIT_BDJANGO 1  // 黒ジャンゴ
#define PORTRAIT_OTNK 2
#define PORTRAIT_SABATA 3
#define PORTRAIT_SMITH 4
#define PORTRAIT_RITA 5
#define PORTRAIT_ZAJI 6
#define PORTRAIT_SUMIRE 7
#define PORTRAIT_KURO 8
#define PORTRAIT_KID 9
#define PORTRAIT_SHAIAN 10
#define PORTRAIT_LADY 11
#define PORTRAIT_COFFIN_SELLER 12
#define PORTRAIT_ENNIO 13
#define PORTRAIT_MARCELLO 14
#define PORTRAIT_HATENA 15  // キャラクター"???" の顔 (PORTRAIT_QUESTION とは関係ない)
#define PORTRAIT_LUIS 16
#define PORTRAIT_DAINN 17
#define PORTRAIT_DUNEYRR 18
#define PORTRAIT_DVALINN 19
#define PORTRAIT_DURATHROR 20
#define PORTRAIT_RINGO_HAT 21
#define PORTRAIT_RINGO 22
#define PORTRAIT_RINGO_DAINN 23
#define PORTRAIT_ROCKMAN 24
#define PORTRAIT_SHADEMAN 25
#define PORTRAIT_QUESTION 26         // "?" の文字
#define PORTRAIT_RDJANGO_ROCKMAN 27  // 赤ジャンゴ+ロックマン
#define PORTRAIT_BDJANGO_ROCKMAN 28  // 黒ジャンゴ+ロックマン
#define PORTRAIT_KURO_KEGA 29

// --------------------------------------------

#endif  // __INCLUDE_CONSTANTS_SPRITE_POSE_H__
