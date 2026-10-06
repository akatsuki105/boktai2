#ifndef GUARD_ZOKTAI_DEFINITION_H
#define GUARD_ZOKTAI_DEFINITION_H

#include "gba/types.h"
#include "types.h"

extern u16 gEntityCount;
extern bool32 bool32_03004788;
extern u32 u32_03004798;
extern u16 gPlayerCount;
extern u32 u32_ARRAY_0203f400[256];

extern u32 u32_030047a0;  // 0x030047A0, gFlag030047a4 と OR されて使用される, デバッグ時に強制的にフラグをセットするためのものと予想

#define FLAG030047A4_UNK_0 (1 << 0)      // 0x1, セットされていると、(フィールドで)START/SELECTボタンを押しても何も起きない(その他のアクションはできる), メニュー画面では特に影響なし
#define FLAG030047A4_UNK_8 (1 << 8)      // 0x100, FUN_0809eacc と FUN_0809e630 が見ている, セットされていると天窓の光が ENE を回復しない
#define FLAG030047A4_UNK_9 (1 << 9)      // 0x200, マップ切り替え時, 会話中にセット
#define FLAG030047A4_GAMEOVER (1 << 10)  // 0x400, GAMEOVER画面の間セット, 手動でセットするとGAMEOVER画面に遷移(ジャンゴは動ける)
#define FLAG030047A4_LINK (1 << 11)      // 0x800, 通信機能利用時にセットされる (通信対戦, 通信販売(アイテム交換) で確認)
#define FLAG030047A4_UNK_12 (1 << 12)    // 0x1000, プレイヤーのENEに関係, 手動でセットしたらENEが10固定になる
extern u32 gFlag030047a4;                // 0x030047A4

// --------------------------------------------

void FUN_0809c464(void);

#endif  // GUARD_ZOKTAI_DEFINITION_H
