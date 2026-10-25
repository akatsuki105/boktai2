#ifndef GUARD_ZOKTAI_DEFINITION_H
#define GUARD_ZOKTAI_DEFINITION_H

#include "gba/types.h"
#include "types.h"

extern bool32 bool32_03004788;
extern u32 u32_03004798;
extern u32 u32_ARRAY_0203f400[256];

#define FLAG03002BC0_UNK_0 (1 << 0)  // 0x1, 用途不明
#define FLAG03002BC0_UNK_1 (1 << 1)  // 0x2, 用途不明, 用途はまだ不明 (マップ切り替え時, 会話中にセット)
#define FLAG03002BC0_UNK_2 (1 << 2)  // 0x4, 用途不明, GAMEOVER画面の間セット
#define FLAG03002BC0_UNK_3 (1 << 3)  // 0x8, 用途不明
extern u32 u32_03002bc0[4];          // 0x03002BC0, プレイヤーごとのフラグ, 手動でセットしてもすぐに上書きされて何も起きない

extern u32 u32_030047a0;  // 0x030047A0, gFlag030047a4 と OR されて使用される, デバッグ時に強制的にフラグをセットするためのものと予想

#define FLAG030047A4_UNK_0 (1 << 0)      // 0x1, セットされていると、(フィールドで)START/SELECTボタンを押しても何も起きない(その他のアクションはできる), メニュー画面では特に影響なし
#define FLAG030047A4_UNK_8 (1 << 8)      // 0x100, FUN_0809eacc と Entity5CCC_AddEneCharge が見ている, セットされていると天窓の光が ENE を回復しない
#define FLAG030047A4_UNK_9 (1 << 9)      // 0x200, 用途はまだ不明 (マップ切り替え時, 会話中にセット)
#define FLAG030047A4_GAMEOVER (1 << 10)  // 0x400, GAMEOVER画面の間セット, 手動でセットするとGAMEOVER画面に遷移(ジャンゴは動ける)
#define FLAG030047A4_LINK (1 << 11)      // 0x800, 通信機能利用時にセットされる (通信対戦, 通信販売(アイテム交換) で確認)
#define FLAG030047A4_UNK_12 (1 << 12)    // 0x1000, プレイヤーのENEに関係, 手動でセットしたらENEが10固定になる
#define FLAG030047A4_UNK_14 (1 << 14)    // 0x4000, FUN_080f8bb8 が LINK と一緒に見る
extern u32 gFlag030047a4;                // 0x030047A4

// --------------------------------------------

void FUN_0809c464(void);

#endif  // GUARD_ZOKTAI_DEFINITION_H
