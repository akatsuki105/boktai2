#ifndef __INCLUDE_GLOBAL_H__
#define __INCLUDE_GLOBAL_H__

#include "constants/constants.h"
#include "gba/gba.h"
#include "inline.h"
#include "macro.h"
#include "struct.h"
#include "trig.h"
#include "types.h"
//
#include "game.h"

// tools/preproc 用の定義
#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__INTELLISENSE__)
#define _(x) {x}   // _("string") is converted to charmap.txt by tools/preproc
#define __(x) {x}  //  __("string") is converted to charmap.txt by tools/preproc, but without a null terminator
#define INCBIN(...) {0}
#define INCBIN_U8 INCBIN
#define INCBIN_U16 INCBIN
#define INCBIN_U32 INCBIN
#define INCBIN_S8 INCBIN
#define INCBIN_S16 INCBIN
#define INCBIN_S32 INCBIN

// equal to HashName(x), preprocessed by TryConvertBokHash in tools/preproc
#define BOKHASH(x) 0
#endif

#define INCASM(file) \
  asm(".section .text\n\
  .include \"" file  \
      "\"\n\
          .align 2, 0\n    \
 .syntax divided\n");

// NAKED void funcXXX(void) { INCFUNC("asm/funcXXX.inc"); }
#define INCFUNC(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

#define Q8(n) ((s32)((n) * 256))  // マップのユニットサイズ
#define Q6(n) ((s32)((n) * 64))   // 26.6 fixed-point format

extern u32 gFrameCounter;
extern s32 gMapBlockW;
extern s32 gMapBlockH;
extern u32 gMapChangeFlags;
extern u32 u32_ARRAY_0203f400[256];

// --------------------------------------------

#define FLAG03002BC0_UNK_0 (1 << 0)  // 0x1, 用途不明
#define FLAG03002BC0_UNK_1 (1 << 1)  // 0x2, 用途不明, 用途はまだ不明 (マップ切り替え時, 会話中にセット)
#define FLAG03002BC0_UNK_2 (1 << 2)  // 0x4, 用途不明, GAMEOVER画面の間セット
#define FLAG03002BC0_UNK_3 (1 << 3)  // 0x8, 用途不明
extern u32 gPlayerStates[4];         // 0x03002BC0, プレイヤーごとのフラグ, 手動でセットしてもすぐに上書きされて何も起きない

// --------------------------------------------

#define FLAG030047A4_UNK_0 (1 << 0)      // 0x1, セットされていると、(フィールドで)START/SELECTボタンを押しても何も起きない(その他のアクションはできる), メニュー画面では特に影響なし
#define FLAG030047A4_UNK_8 (1 << 8)      // 0x100, FUN_0809eacc と Entity5CCC_AddEneCharge が見ている, セットされていると天窓の光が ENE を回復しない
#define FLAG030047A4_UNK_9 (1 << 9)      // 0x200, 用途はまだ不明 (マップ切り替え時, 会話中にセット)
#define FLAG030047A4_GAMEOVER (1 << 10)  // 0x400, GAMEOVER画面の間セット, 手動でセットするとGAMEOVER画面に遷移(ジャンゴは動ける)
#define FLAG030047A4_LINK (1 << 11)      // 0x800, 通信機能利用時にセットされる (通信対戦, 通信販売(アイテム交換) で確認)
#define FLAG030047A4_UNK_12 (1 << 12)    // 0x1000, プレイヤーのENEに関係, 手動でセットしたらENEが10固定になる
#define FLAG030047A4_UNK_14 (1 << 14)    // 0x4000, FUN_080f8bb8 が LINK と一緒に見る
extern u32 gDebugGameFlags;              // 0x030047A0, gGameFlags と OR されて使用される, デバッグ時に強制的にフラグをセットするためのものと予想
extern u32 gGameFlags;                   // 0x030047A4

// --------------------------------------------

void WaitForVBlank(void);
s32 SoftReset_0823a928(void);
void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void CopyMemory(u8* dst, u8* src, s32 bytesize);
u16 HashName(const char* s);
void BlendPltt(rgb555* dst, rgb555* src1, rgb555* src2, s32 t, s32 shift);
s32 EmitSmoke(WorldPos* pos, u8 count, Vec3* size, s32 angle, s32 speed, s32 velYMax, s32 kind, u32 priority);

#endif  // __INCLUDE_GLOBAL_H__
