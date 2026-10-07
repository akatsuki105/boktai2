#ifndef __INCLUDE_FONT_H__
#define __INCLUDE_FONT_H__

#include "gba/gba.h"

void FUN_0822ea60(u32 x8, u32 y8, u32 w8, u32 h8);
void FUN_0822eadc(u32 x8, u32 y8, u32 w8, u32 h8);
void FUN_0822e8b4(void);
void Font_DrawHankakuChar(u16 charcode, s32 x8, s32 y8, s32 style);
u32 Font_GetZenkakuCharCount(void);
void Font_DrawZenkakuChar(u16 charcode, s32 x8, s32 y8, s32 style);

#endif  // __INCLUDE_FONT_H__
