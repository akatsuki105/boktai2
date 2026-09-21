#ifndef __INCLUDE_FONT_H__
#define __INCLUDE_FONT_H__

#include "gba/gba.h"

typedef struct {
  u16 narrowCharCount;  // このゲームでは 128
  u16 wideCharCount;    // このゲームでは 1537
  u32 offsetToNarrowChars;
  u32 offsetToWideChars;
} FontHeader;

// FontHeader のオフセットをアドレスにしたもの
typedef struct {
  u16 narrowCharCount;  // 0x0, FontHeader.narrowCharCount, 半角文字 (8x16px)
  u16 wideCharCount;    // 0x2, FontHeader.wideCharCount, 全角文字 (16x16px)
  u8* narrowChars;      // tiles
  u8* wideChars;        // tiles
} FontInfo;
static_assert(sizeof(FontInfo) == 12);

#endif  // __INCLUDE_FONT_H__
