#ifndef GUARD_ZOKTAI_DEFINITION_H
#define GUARD_ZOKTAI_DEFINITION_H

#include "gba/types.h"
#include "types.h"

typedef void* (*TaskFn)(u32, void*);
typedef void* (*TaskFnNoArg)(void);

extern s32 gCount_Unk_0203b000;
extern u32 gEntityDisableFlags;
extern u16 gEntityCount;
extern bool32 bool32_03004788;
extern u32 u32_03004798;
extern u16 gPlayerCount;
extern u16 u16_0300486c;
extern u16 u16_03004870;
extern u16 u16_ARRAY_03004874[6];
extern u32 u32_ARRAY_0203f400[256];

#define FLAG030047A4_UNK_0 (1 << 0)      // 0x1, セットされていると、(フィールドで)START/SELECTボタンを押しても何も起きない(その他のアクションはできる), メニュー画面では特に影響なし
#define FLAG030047A4_UNK_9 (1 << 9)      // 0x200, マップ切り替え時, 会話中にセット
#define FLAG030047A4_GAMEOVER (1 << 10)  // 0x400, GAMEOVER画面の間セット, 手動でセットするとGAMEOVER画面に遷移(ジャンゴは動ける)
#define FLAG030047A4_UNK_11 (1 << 11)    // 0x800, (手動で)セットすると、プレイヤーが動いてもカメラが追従しなくなる, 画面外に出てもNPCやマップ移動はあるっぽい?
#define FLAG030047A4_UNK_12 (1 << 12)    // 0x1000, プレイヤーのENEに関係, 手動でセットしたらENEが10固定になる
extern u32 gFlag030047a4;                // 0x030047A4

// --------------------------------------------

void FUN_0809c464(void);
void FUN_0822a4e0(void* p);
bool32 FUN_08234de8(unknown* p, u32 param_2, u32 param_3, u32 param_4);

#endif  // GUARD_ZOKTAI_DEFINITION_H
