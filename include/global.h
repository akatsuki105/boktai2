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
#include "player.h"

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
  u8 unk_08[3];       // 0x08
  bool8 summerTime;   // 0x0B, サマータイム
  u8 unk_0c[12];      // 0x0C
  u16 eventFlags[4];  // 0x18, 0: BB3, 1: BB4, 2: BB5 & バレンタイン, 3: なんか
  u8 timezone;        // 0x20, タイムゾーン
  u8 unk_21[7];       // 0x21
} SystemSaveData;
static_assert(sizeof(SystemSaveData) == 40);

extern Unk_0203b000 gUnk_0203b000[128];
extern SystemSaveData* gSystemSaveData;

// --------------------------------------------

void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void FUN_08230ab0(u8* dst, u8* src, s32 bytesize);

#endif  // GUARD_ZOKTAI_GLOBAL_H
