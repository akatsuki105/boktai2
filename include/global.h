#ifndef __INCLUDE_GLOBAL_H__
#define __INCLUDE_GLOBAL_H__

#include "constants/constants.h"
#include "definition.h"
#include "gba/gba.h"
#include "struct.h"
#include "trig.h"
#include "types.h"
//
#include "game.h"

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

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

#define Q_4_12(n) ((s16)((n) * 4096))  // Converts a number to Q4.12 fixed-point format

// マップのユニットサイズ (Q8 マクロ作った方がいいかも？)
#define BLOCK 256

// 1.0 に相当する値は小数部のビット数だけで決まり、整数部の幅にも符号にも依存しない
#define FRACBITS_6 6                  // u2_6 / s2_6 / u10_6 / s10_6 の小数部
#define FRACUNIT_6 (1 << FRACBITS_6)  // 64

extern u32 gScriptDirectoryBuildTime;  // 0x03004594
extern u32 gFrameCounter;
extern s32 gMapBlockW;
extern s32 gMapBlockH;

// --------------------------------------------

void WaitForVBlank(void);
s32 SoftReset_0823a928(void);

void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void CopyMemory(u8* dst, u8* src, s32 bytesize);

s32 EmitSmoke(WorldPos* pos, u8 count, Vec3* size, s32 angle, s32 speed, s32 velYMax, s32 kind, u32 priority);

// 固定小数の値を整数に変換するための関数
static inline s32 FixToInt(s32 fracBits, s32 fixedPointValS32) { return fixedPointValS32 >= 0 ? (fixedPointValS32 >> fracBits) : -((-fixedPointValS32) >> fracBits); }

#endif  // __INCLUDE_GLOBAL_H__
