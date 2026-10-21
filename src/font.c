#include "font.h"

#include "bg_pltt.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "video.h"

typedef struct {
  u16 hankakuCharCount;  // 0x0, 半角文字 (8x16px) の文字数 (タイル数は hankakuCharCount * 2)
  u16 zenkakuCharCount;  // 0x2, 全角文字 (16x16px) の文字数 (タイル数は zenkakuCharCount * 4)
  // これらのメンバは、 ROMでは &FontInfo からのオフセットでRAM読み込み時にポインタに変換される
  u8* hankaku;  // u8[hankakuCharCount * 2 * 32], 半角文字のタイルデータ
  u8* zenkaku;  // u8[zenkakuCharCount * 4 * 32], 全角文字のタイルデータ
} FontInfo;
static_assert(sizeof(FontInfo) == 12);

typedef FontInfo FontFile;  // ROM内の FontInfo であることを示すためのエイリアス

// gGlyphCache の1エントリ, Font_AcquireGlyph が確保し Font_ReleaseGlyph が解放する
// bit0-15: 文字, bit16-21: 属性3つ, bit22-29: 参照カウント
// u32[256] として宣言すると EWRAM の並びが変わって ROM が一致しなくなるので u8 の塊のまま持ち, 使う側で u32* に直す
EWRAM_DATA u8 gGlyphCache[0x800] = {};        // 0x02035400, 4バイト1エントリで256件, 添字 + 0x100 が BG タイル番号になる
EWRAM_DATA u8 gGlyphTileBuffer[0x1000] = {};  // 0x02035C00, VRAM へ流す前の字形の置き場, 32バイト1枚で最大128枚

IWRAM_DATA u8 gGlyphTileDst[128] = {};  // 0x030006A0, gGlyphTileBuffer の各枚の転送先タイル番号
IWRAM_DATA u32 gGlyphTileCount = 0;     // 0x03000720, 溜まっている枚数, Font_FlushGlyphTiles が流し終えて 0 に戻す

IWRAM_DATA FontInfo* gFontInfo = NULL;  // 0x03000724

// 多分、バッファのフォントのタイルデータをVRAMに転送する関数
void Font_FlushGlyphTiles(void) {
  u8* src = gGlyphTileBuffer;
  u32 i;

  for (i = 0; i < gGlyphTileCount; i++) {
    void* dst = (void*)(BG_VRAM + 0xA000 + (gGlyphTileDst[i] << 5));

    DmaCopy32(3, src, dst, 32);
    src += 0x20;
  }
  gGlyphTileCount = 0;
}

// タイル1枚ぶんの字形を gGlyphTileBuffer に積む
// 残差1命令, 原典は src を r1 のまま使い val を r3 に退避するが, こちらはカウンタに r1 を取るので src の退避が1本増える
NON_MATCH void Font_QueueGlyphTile(s32 val, u8* src) {
#ifdef NONMATCHING_C
  if (gGlyphTileCount <= 0x80) {
    gGlyphTileDst[gGlyphTileCount] = val;
    CopyMemory(&gGlyphTileBuffer[gGlyphTileCount * 32], src, 32);
    gGlyphTileCount++;
  }
#else
  INCFUNC("asm/func/Font_QueueGlyphTile.inc");
#endif
}

void Font_ClearInfo(void) { gFontInfo = NULL; }

FontInfo* Font_GetInfo(void) { return gFontInfo; }

// フォントファイルを読んで gFontInfo を作る
s32 Font_LoadInfo(void) {
  if (gFontInfo != NULL) {
    return 0;
  }

  gFontInfo = Malloc(sizeof(FontInfo));
  if (gFontInfo != NULL) {
    ClearMemory(gFontInfo, sizeof(FontInfo));

    {
      FontFile* f = GetFile(DIR_FONT, 0x3F51);
      if (f != NULL) {
        // 相対オフセットをROMアドレスに変換する
        *gFontInfo = *f;
        gFontInfo->hankaku = (u8*)((u32)gFontInfo->hankaku + (u32)f);
        gFontInfo->zenkaku = (u8*)((u32)gFontInfo->zenkaku + (u32)f);
        return 0;
      }
    }
  }
  return -1;
}

u32 Font_GetHankakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->hankakuCharCount;
}

u32 Font_GetZenkakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->zenkakuCharCount;
}

u8* Font_GetHankakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->hankaku;
}

u8* Font_GetZenkakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->zenkaku;
}

void Font_ClearGlyphCache(void) { ClearMemory(gGlyphCache, sizeof(gGlyphCache)); }

void* Font_GetGlyphCache(void) { return gGlyphCache; }

// gGlyphCache の先頭256エントリ(u32)から、キーが一致する使用中のもの(上位8bitが非0)を探す
s32 Font_FindGlyph(u32 val1, u32 val2, u32 val3, u32 val4) {
  s32 i;
  u32 key = (val1 | (val2 << 16) | (val3 << 18) | (val4 << 20)) & 0x3FFFFF;
  u32* p = Font_GetGlyphCache();
  for (i = 0; i < 0x100; p++, i++) {
    if (((*p & 0x3FFFFF) == key) && (*p & (0xFF << 22))) {
      return i;
    }
  }
  return -1;
}

NON_MATCH s32 Font_AcquireGlyph(void* tiledata, u32 val2, u32 val3, u32 val4, u32 val5) {
#ifdef NONMATCHING_C
  u32 buf[8];
  u32 hi, lo;
  s32 i;
  u32* p = Font_GetGlyphCache();
  s32 idx = Font_FindGlyph(val2, val3, val4, val5);

  if (idx >= 0) {
    u32 count = p[idx] & (0xFF << 22);
    p[idx] = (p[idx] & ~(0xFF << 22)) | (count + (1 << 22));
    return idx;
  }

  for (i = 0; i < 0x100; p++, i++) {
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
  Font_QueueGlyphTile(idx, (u8*)buf);
  return idx;
#else
  INCFUNC("asm/func/Font_AcquireGlyph.inc");
#endif
}

// 参照カウント(上位8bit)を1減らし、0になったらエントリごと解放する
bool32 Font_ReleaseGlyph(u32 tileidx) {
  u32* base = Font_GetGlyphCache();

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

// タイルマップ上の矩形 (x8, y8, w8, h8) を走査し、各タイルの下位10bit(タイル番号)を Font_ReleaseGlyph に渡して参照カウントを解放し、成功したら 0xF001 で塗り潰す
// 矩形内の各セルのタイルを1つ解放し、解放できたセルを空きタイルに差し替える
void Font_ReleaseRect(u32 x8, u32 y8, u32 w8, u32 h8) {
  BgMapEntry* map = GetTilemapBuffer(0);
  u32 left = x8;
  u32 right = x8 + w8;
  u32 bottom = y8 + h8;

  for (; y8 < bottom; y8++) {
    for (x8 = left; x8 < right; x8++) {
      if (Font_ReleaseGlyph(map[(y8 << 5) + x8] & 0x3FF)) {
        map[(y8 << 5) + x8] = ((15 << 12) | 1);  // BGP15, タイル番号1
      }
    }
  }
}

// タイルマップの矩形を空きタイルで塗りつぶす (テキストボックスの背景用)
void Font_FillRect(u32 x8, u32 y8, u32 w8, u32 h8) {
  BgMapEntry* map = GetTilemapBuffer(0);
  u32 left = x8;
  u32 right = x8 + w8;
  u32 bottom = y8 + h8;

  for (; y8 < bottom; y8++) {
    for (x8 = left; x8 < right; x8++) {
      map[(y8 << 5) + x8] = ((15 << 12) | 1);  // BGP15, タイル番号1
    }
  }
}

NAKED void Font_DrawHankakuChar(u16 charcode, s32 x8, s32 y8, s32 style) { INCFUNC("asm/func/Font_DrawHankakuChar.inc"); }

NAKED void Font_DrawZenkakuChar(u16 charcode, s32 x8, s32 y8, s32 style) { INCFUNC("asm/func/Font_DrawZenkakuChar.inc"); }

void nop_0822ec58(void) {}

// 多分、フォントのタイルデータをクリアする関数
void Font_ClearGlyphVram(void) { CpuFastFill(0x44444444, (void*)(VRAM + 0xA000), 0x2000); }

// フォント用パレット BGP14, BGP15 を、2 つのパレットファイルのどちらかから差し替える
void Font_SetPltt(s32 val) {
  BgPlttFile* f;
  FileID fileID;

  switch (val) {
    case 0:
    default: {
      fileID = BGP_529C;
      break;
    }
    case 1: {
      fileID = BGP_539C;
      break;
    }
  }
  f = GetBgPlttFile(fileID);
  CpuCopy32(&f->body[224], &gBgPlttBuffer[224], 32 * sizeof(rgb555));
}
