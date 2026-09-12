#ifndef GUARD_ZOKTAI_GLOBAL_H
#define GUARD_ZOKTAI_GLOBAL_H

#include "constants/constants.h"
#include "definition.h"
#include "gba/gba.h"
#include "incbin.h"
#include "struct.h"
#include "types.h"
//
#include "game.h"

#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__INTELLISENSE__)
#define _(x) {x}   // _("string") is converted to charmap.txt by tools/preproc
#define __(x) {x}  //  __("string") is converted to charmap.txt by tools/preproc, but without a null terminator
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

// NAKED void funcXXX(void) {
//  INCFUNC("asm/funcXXX.inc");
// }
#define INCFUNC(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

typedef struct {
  s32 frameCounter;   // 0x00
  s32 calibration;    // 0x04, 太陽センサーのキャリブレーション値
  u8 currentSlot;     // 0x08
  u8 unk_09[2];       // 0x09
  bool8 summerTime;   // 0x0B, サマータイム
  s32 unk_c;          // 0x0C, 根拠: FUN_0823d6bc
  u32 unk_10;         // 0x10, 根拠: FUN_0823d68c
  u16 unk_14;         // 0x14, 根拠: FUN_0823d700
  u16 unk_16;         // 0x16, 根拠: FUN_0823d700
  u16 eventFlags[4];  // 0x18, 0: BB3 (BlindBoxLv3), 1: BB4, 2: BB5 & バレンタイン, 3: なんか
  u32 timezone;       // 0x20, タイムゾーン, u32 の根拠: FUN_0823d680
  u8 unk_24[4];       // 0x24
} SystemSaveData;
static_assert(sizeof(SystemSaveData) == 40);

// BG1枚分の状態 (gBgStates[4] @ 0x03003ED0), 要素の区切りの根拠: entity_cbb0, enemy_dex が &gBgStates[3] (0x03003F60) を起点に +0x10..+0x28 を触る
typedef struct {
  u8 unk_00[24];
  s16 unk_18;  // 0x18, ×2 したものが q_tilemap の 1 行のエントリ数, 根拠: FUN_0822bcf4
  u8 unk_1a[6];
  u16 hofs;  // 0x20, BGnHOFS の基準値 (HBlank エフェクトで各ラインの値に足される), 根拠: FUN_0822eef4, StageBGRegs
  u16 vofs;  // 0x22, BGnVOFS の基準値, 根拠: FUN_0822eef4, StageBGRegs
  u8 unk_24[8];
  u16* q_tilemap;  // 0x2C, タイルマップのバッファ, 根拠: FUN_0822bcf4 がタイル番号|反転<<10|パレット<<12 を書く
} BgState;
static_assert(sizeof(BgState) == 48);

extern u32 gScriptDirectoryBuildTime;  // 0x03004594
extern Unk_0203b000 gUnk_0203b000[128];
extern SystemSaveData* gSystemSaveData;

// --------------------------------------------

void WaitForVBlank(void);

void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void CopyMemory(u8* dst, u8* src, s32 bytesize);

#endif  // GUARD_ZOKTAI_GLOBAL_H
