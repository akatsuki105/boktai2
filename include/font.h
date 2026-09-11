#ifndef __INCLUDE_FONT_H__
#define __INCLUDE_FONT_H__

#include "gba/gba.h"

typedef struct {
  u16 narrowCharCount;  // このゲームでは 128
  u16 wideCharCount;    // このゲームでは 1537
  u32 offsetToNarrowChars;
  u32 offsetToWideChars;
} FontHeader;

extern FontHeader gFontFile0;  // 0x089ee090

// FontHeader のオフセットをアドレスにしたもの
typedef struct {
  u16 narrowCharCount;  // 0x0, FontHeader.narrowCharCount
  u16 wideCharCount;    // 0x2, FontHeader.wideCharCount
  u8* narrowChars;
  u8* wideChars;
} FontInfo;
static_assert(sizeof(FontInfo) == 12);

extern FontInfo* gFontInfo;  // 0x03000724

#endif  // __INCLUDE_FONT_H__
