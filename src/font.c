#include "font.h"

#include "bg_pltt.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "video.h"

extern u8 u8_02035400[0x800];

IWRAM_DATA u8 u8_ARRAY_030006a0[128] = {};  // 0x030006A0
IWRAM_DATA u32 u32_03000720 = 0;            // 0x03000720, なんかのカウンタ
IWRAM_DATA FontInfo* gFontInfo = NULL;      // 0x03000724

// 多分、バッファのフォントのタイルデータをVRAMに転送する関数
NAKED void FUN_0822e73c(void) { INCFUNC("asm/func/FUN_0822e73c.inc"); }

NAKED void FUN_0822e794(s32 val, u8* src) { INCFUNC("asm/func/FUN_0822e794.inc"); }

void FUN_0822e7cc(void) { gFontInfo = NULL; }

FontInfo* FUN_0822e7d8(void) { return gFontInfo; }

// フォントファイルを読んで gFontInfo を作る。ヘッダのオフセットは実アドレスに直して持つ
s32 FUN_0822e7e4(void) {
  FontHeader* f;

  if (gFontInfo != NULL) {
    return 0;
  }
  gFontInfo = Malloc(sizeof(FontInfo));
  if (gFontInfo != NULL) {
    ClearMemory(gFontInfo, sizeof(FontInfo));
    f = GetFile(DIR_FONT, 0x3F51);
    if (f != NULL) {
      *gFontInfo = *(FontInfo*)f;
      gFontInfo->narrowChars += (u32)f;
      gFontInfo->wideChars += (u32)f;
      return 0;
    }
  }
  return -1;
}

u32 Video_GetHankakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->narrowCharCount;
}

u32 Video_GetZenkakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->wideCharCount;
}

u8* Video_GetHankakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->narrowChars;
}

u8* Video_GetZenkakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->wideChars;
}

void FUN_0822e8b4(void) { ClearMemory(u8_02035400, sizeof(u8_02035400)); }

void* FUN_0822e8c8(void) { return u8_02035400; }

// u8_02035400 の先頭256エントリ(u32)から、キーが一致する使用中のもの(上位8bitが非0)を探す
s32 FUN_0822e8d0(u32 val1, u32 val2, u32 val3, u32 val4) {
  s32 i;
  u32 key = (val1 | (val2 << 16) | (val3 << 18) | (val4 << 20)) & 0x3FFFFF;
  u32* p = FUN_0822e8c8();
  for (i = 0; i <= 0xFF; p++, i++) {
    if (((*p & 0x3FFFFF) == key) && (*p & (0xFF << 22))) {
      return i;
    }
  }
  return -1;
}

NON_MATCH s32 FUN_0822e920(void* tiledata, u32 val2, u32 val3, u32 val4, u32 val5) {
#ifdef NONMATCHING_C
  u32 buf[8];
  u32 hi, lo;
  s32 i;
  u32* p = FUN_0822e8c8();
  s32 idx = FUN_0822e8d0(val2, val3, val4, val5);

  if (idx >= 0) {
    u32 count = p[idx] & (0xFF << 22);
    p[idx] = (p[idx] & ~(0xFF << 22)) | (count + (1 << 22));
    return idx;
  }

  for (i = 0; i <= 0xFF; p++, i++) {
    if (!(*p & (0xFF << 22))) break;
  }
  if (i == 0x100) return -1;

  idx = i;
  *p = val2 | (val3 << 16) | (val4 << 18) | (val5 << 20) | (1 << 22);
  hi = (val4 * 0x01010101) << 6;
  lo = (val4 * 0x01010101) << 2;
  for (i = 0; i < 8; i++) {
    u32 w = ((u32*)tiledata)[i];
    buf[i] = (((w & 0xF0F0F0F0) | hi) & 0xF0F0F0F0) | (((w & 0x0F0F0F0F) | lo) & 0x0F0F0F0F);
  }
  FUN_0822e794(idx, (u8*)buf);
  return idx;
#else
  INCFUNC("asm/func/FUN_0822e920.inc");
#endif
}

// 参照カウント(上位8bit)を1減らし、0になったらエントリごと解放する
bool32 FUN_0822ea10(u32 tileidx) {
  u32* base = FUN_0822e8c8();

  tileidx -= 0x100;
  if (tileidx <= 0xFF) {
    u32 entry = base[tileidx];
    s32 count = (entry & (0xFF << 22)) >> 22;
    if (count > 0) {
      count--;
      if (count <= 0) {
        base[tileidx] = 0;
      } else {
        base[tileidx] = (entry & ~(0xFF << 22)) | (count << 22);
      }
      return TRUE;
    }
  }
  return FALSE;
}

// タイルマップ上の矩形 (x8, y8, w8, h8) を走査し、各タイルの下位10bit(タイル番号)を FUN_0822ea10 に渡して参照カウントを解放し、成功したら 0xF001 で塗り潰す
// 矩形内の各セルのタイルを1つ解放し、解放できたセルを空きタイルに差し替える
void FUN_0822ea60(u32 x8, u32 y8, u32 w8, u32 h8) {
  u16* map = GetTilemapBuffer(0);
  u32 left = x8;
  u32 right = x8 + w8;
  u32 bottom = y8 + h8;

  for (; y8 < bottom; y8++) {
    for (x8 = left; x8 < right; x8++) {
      if (FUN_0822ea10(map[(y8 << 5) + x8] & 0x3FF)) {
        map[(y8 << 5) + x8] = ((15 << 12) | 1);  // BGP15, タイル番号1
      }
    }
  }
}

// タイルマップの矩形を空きタイルで塗りつぶす (テキストボックスの背景用)
void FUN_0822eadc(u32 x8, u32 y8, u32 w8, u32 h8) {
  u16* map = GetTilemapBuffer(0);
  u32 left = x8;
  u32 right = x8 + w8;
  u32 bottom = y8 + h8;

  for (; y8 < bottom; y8++) {
    for (x8 = left; x8 < right; x8++) {
      map[(y8 << 5) + x8] = ((15 << 12) | 1);  // BGP15, タイル番号1
    }
  }
}

NAKED void Video_DrawCharNarrow(u16 charcode, s32 x8, s32 y8, unknown* param_4) { INCFUNC("asm/func/Video_DrawCharNarrow.inc"); }

NAKED void Video_DrawCharWide(u16 charcode, s32 x8, s32 y8, unknown* param_4) { INCFUNC("asm/func/Video_DrawCharWide.inc"); }

void nop_0822ec58(void) {}

// 多分、フォントのタイルデータをクリアする関数
void FUN_0822ec5c(void) { CpuFastFill(0x44444444, (void*)(VRAM + 0xA000), 0x2000); }

// フォント用パレット BGP14, BGP15 を、2 つのパレットファイルのどちらかから差し替える
void FUN_0822ec80(s32 val) {
  BgPlttFile* f;
  FileID fileID;

  switch (val) {
    case 0:
    default: {
      fileID = 0x529C;
      break;
    }
    case 1: {
      fileID = 0x539C;
      break;
    }
  }
  f = GetFile(DIR_BGPLTT, fileID);
  CpuCopy32(&f->body[224], &gBgPlttBuffer[224], 64);
}
