#ifndef __INCLUDE_GLOBAL_H__
#define __INCLUDE_GLOBAL_H__

#include "constants/constants.h"
#include "gba/gba.h"
#include "inline.h"
#include "macro.h"
#include "trig.h"
#include "types.h"
//
#include "game.h"

#define STRING_DATA __attribute__((section(".rodata.string")))

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

// --------------------------------------------

#define GAMEFLAG_NO_PAUSE (1 << 0)    // 0x1, 暴走やジャッジメント等の演出中にセット, セットされていると、(フィールドで)START/SELECTボタンを押しても何も起きない(その他のアクションはできる), メニュー画面では特に影響なし
#define GAMEFLAG_UNK_8 (1 << 8)       // 0x100, FUN_0809eacc と Entity5CCC_AddEneCharge が見ている, セットされていると天窓の光が ENE を回復しない
#define GAMEFLAG_EVENT (1 << 9)       // 0x200, イベント中にセット (Script_0x007E/007F が立てて落とす), 会話中・マップ切り替え時も立つ
#define GAMEFLAG_GAMEOVER (1 << 10)   // 0x400, GAMEOVER画面の間セット, 手動でセットするとGAMEOVER画面に遷移(ジャンゴは動ける)
#define GAMEFLAG_LINK (1 << 11)       // 0x800, 通信機能利用時にセットされる (通信対戦, 通信販売(アイテム交換) で確認)
#define GAMEFLAG_CROSSOVER (1 << 12)  // 0x1000, クロスオーバーバトル中にセットされる? (mGBAがワイヤレスアダプタのエミュレーションをサポートしてないため検証が面倒で未確認)
#define GAMEFLAG_UNK_14 (1 << 14)     // 0x4000, Mover_ShowTrackingMarker が LINK と一緒に見る
extern u32 gDebugGameFlags;           // 0x030047A0, gGameFlags と OR されて使用される, デバッグ時に強制的にフラグをセットするためのものと予想
extern u32 gGameFlags;                // 0x030047A4

// --------------------------------------------

// gMapChangeFlags, 0 以外になると GameSystem_Update がマップ切り替えを始め, 終わったら 0 に戻す
enum {
  MAPCHANGE_LOAD = 1 << 0,     // 0x001, 別のマップへ移る
  MAPCHANGE_BACKUP = 1 << 4,   // 0x010, 切り替えの完了時にステータスとワールドを退避する
  MAPCHANGE_RESTART = 1 << 6,  // 0x040, 今のマップを読み直す
  MAPCHANGE_RESTORE = 1 << 8,  // 0x100, 切り替えの完了時に退避したゲーム状態に戻す
};
extern u32 gMapChangeFlags;  // 0x03004798

// --------------------------------------------

void WaitForVBlank(void);
s32 GameSystem_SoftReset(void);
void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void CopyMemory(u8* dst, u8* src, s32 bytesize);
u16 HashName(const char* s);
void BlendPltt(rgb555* dst, rgb555* src1, rgb555* src2, s32 t, s32 shift);
s32 EmitSmoke(WorldPos* pos, u8 count, Vec3* size, s32 angle, s32 speed, s32 velYMax, s32 kind, u32 priority);
void StartBgObjPlttFade(s32 kind, s32 durationShift, s32 r5, s32 g5, s32 b5, u32 bgRowMask, u32 objSkipMask);
void FUN_08240cf0(s16 x, s16 z, s16 param_3, s16 param_4, u8 flags, u16 moverID);
void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);

#endif  // __INCLUDE_GLOBAL_H__
