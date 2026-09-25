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

#define Q_4_12(n) ((s16)((n) * 4096))  // Converts a number to Q4.12 fixed-point format

// 1.0 に相当する値は小数部のビット数だけで決まり、整数部の幅にも符号にも依存しない
#define FRACBITS_6 6                  // u2_6 / s2_6 / u10_6 / s10_6 の小数部
#define FRACUNIT_6 (1 << FRACBITS_6)  // 64

// NAKED void funcXXX(void) {
//  INCFUNC("asm/funcXXX.inc");
// }
#define INCFUNC(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

extern u32 gScriptDirectoryBuildTime;  // 0x03004594
extern Unk_0203b000 gUnk_0203b000[128];
extern u32 gFrameCounter;
extern s32 gMapBlockW;
extern s32 gMapBlockH;

// --------------------------------------------

void WaitForVBlank(void);
s32 SoftReset_0823a928(void);

void ClearMemory(void* dst, s32 bytesize);  // buffer から bytesize バイト分のメモリを0で埋める
void CopyMemory(u8* dst, u8* src, s32 bytesize);

extern const s16 gSineTable[320];
s32 ArcTan2_8(s32 x, s32 y);

void FUN_08241704(void);
void FUN_0824172c(void);

#endif  // GUARD_ZOKTAI_GLOBAL_H
