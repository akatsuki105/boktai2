#include "global.h"
#include "sprite.h"
#include "video.h"

// 表示レジスタの退避/復帰と直書き, src/video.c から分けただけで .text は連続している
// ウィンドウ矩形, WININ/WINOUT, DISPCNT, ブレンド, BGnHOFS/VOFS, パレット1色の直書き

extern u16 gWIN0H;
extern u16 gWIN0V;
extern u16 gWIN1H;
extern u16 gWIN1V;
extern u8 gOAMHeightTable[16];
extern u8 gOAMWidthTable[16];
extern u8 gOAMTileWidthTable[16];
extern u8 gOAMTileHeightTable[16];
extern u8 gOAMTileCounts[16];
extern u32 gOAMShapeSizeAttrTable[16];

IWRAM_DATA u16 u16_0300068a = 0;   // 0x0300068A, unused, padding?
IWRAM_DATA u16 gSavedDISPCNT = 0;  // 0x0300068C
IWRAM_DATA u16 gSavedWIN0H = 0;    // 0x0300068E
IWRAM_DATA u16 gSavedWIN1H = 0;    // 0x03000690
IWRAM_DATA u16 gSavedWIN0V = 0;    // 0x03000692
IWRAM_DATA u16 gSavedWIN1V = 0;    // 0x03000694
IWRAM_DATA u16 gSavedWININ = 0;    // 0x03000696, Video_SaveWININOUT が退避した WININ
IWRAM_DATA u16 gSavedWINOUT = 0;   // 0x03000698, Video_SaveWININOUT が退避した WINOUT

#define SPRITE_SIZE(widthPixel, heightPixel) ((heightPixel << 8) | widthPixel)

// clang-format off
// idx: SpriteShape
const u16 gSpriteSizeTable[16] = {
// OAM0.14-15:  Square(0)             Horizontal(1)         Vertical(2)           Prohibited(3)
                SPRITE_SIZE( 8,  8),  SPRITE_SIZE(16,  8),  SPRITE_SIZE( 8, 16),  0x0,
                SPRITE_SIZE(16, 16),  SPRITE_SIZE(32,  8),  SPRITE_SIZE( 8, 32),  0x0,
                SPRITE_SIZE(32, 32),  SPRITE_SIZE(32, 16),  SPRITE_SIZE(16, 32),  0x0,
                SPRITE_SIZE(64, 64),  SPRITE_SIZE(64, 32),  SPRITE_SIZE(32, 64),  0x0,
}; // 0x085b0130
// clang-format on

#undef SPRITE_SIZE

// ウィンドウ矩形の控えを退避する
void Video_SaveWindowRect(u32 win) {
  if (win == 0) {
    gSavedWIN0H = gWIN0H;
    gSavedWIN0V = gWIN0V;
  } else {
    gSavedWIN1H = gWIN1H;
    gSavedWIN1V = gWIN1V;
  }
}

// 退避しておいたウィンドウ矩形を控えに戻し、WINnH / WINnV にも書き戻す
// 命令数は一致, 残差はプール読みの順序 (元は 格納先 -> 読み出し元) と h/v のレジスタ番号
// gWIN0H = h = gSavedWIN0H; と連鎖代入にするとプールの順序は一致するが、レジスタ割当が合わないままなので自然な形に戻してある
NON_MATCH void Video_RestoreWindowRect(u32 win) {
#ifdef NONMATCHING_C
  vu16* p;
  u16 h, v;

  if (win == 0) {
    h = gSavedWIN0H;
    gWIN0H = h;
    v = gSavedWIN0V;
    gWIN0V = v;
    p = &REG_WIN0H;
  } else {
    h = gSavedWIN1H;
    gWIN1H = h;
    v = gSavedWIN1V;
    gWIN1V = v;
    p = &REG_WIN1H;
  }
  *p = h;
  p += 2;
  *p = v;
#else
  INCFUNC("asm/func/Video_RestoreWindowRect.inc");
#endif
}

// ウィンドウの矩形を WINnH / WINnV に設定し、同じ値を控えにも残す
void Video_SetWindowRect(s32 win, s32 left, s32 top, s32 right, s32 bottom) {
  if (win == 0) {
    gWIN0H = (left << 8) | right;
    REG_WIN0H = gWIN0H;
    gWIN0V = (top << 8) | bottom;
    REG_WIN0V = gWIN0V;
  } else {
    gWIN1H = (left << 8) | right;
    REG_WIN1H = gWIN1H;
    gWIN1V = (top << 8) | bottom;
    REG_WIN1V = gWIN1V;
  }
}

// ウィンドウ内外の表示対象 (WININ/WINOUT) を設定する
void Video_SetWindowInOut(u32 win0In, u32 win1In, u32 winOut, u32 objWinIn) {
  REG_WININ = (win1In << 8) | win0In;
  REG_WINOUT = (objWinIn << 8) | winOut;
}

void Video_SaveWININOUT(void) {
  gSavedWININ = REG_WININ;
  gSavedWINOUT = REG_WINOUT;
}

void Video_RestoreWININOUT(void) {
  REG_WININ = gSavedWININ;
  REG_WINOUT = gSavedWINOUT;
}

void UNUSED Video_SaveDISPCNT(void) { gSavedDISPCNT = REG_DISPCNT; }

void UNUSED Video_RestoreDISPCNT(void) { REG_DISPCNT = gSavedDISPCNT; }

void Video_SetBLDCNTDirect(u32 effect, u32 target1, u32 target2) { REG_BLDCNT = target1 | (target2 << 8) | (effect << 6); }

void Video_SetBLDALPHADirect(u32 target1, u32 target2) { REG_BLDALPHA = BLDALPHA_BLEND(target1, target2); }

void Video_SetBLDYDirect(u32 bldy) { REG_BLDY = bldy; }

void UNUSED Video_SetBGnOFSDirect(s32 bg, u32 hofs, u32 vofs) {
  vu16* p;

  switch (bg) {
    case 0: {
      p = &REG_BG0HOFS;
      break;
    }
    case 1: {
      p = &REG_BG1HOFS;
      break;
    }
    case 2: {
      p = &REG_BG2HOFS;
      break;
    }
    case 3: {
      p = &REG_BG3HOFS;
      break;
    }
    default: {
      return;
    }
  }
  *p++ = hofs;
  *p = vofs;
}

void UNUSED Video_SetBG23OFSDirect(s32 bg, u32 hofs, u32 vofs) {
  vu16* p;

  switch (bg) {
    case 2: {
      p = &REG_BG2HOFS;
      break;
    }
    case 3: {
      p = &REG_BG3HOFS;
      break;
    }
    case 0:
    case 1:
    default: {
      return;
    }
  }
  *p++ = hofs;
  *p = vofs;
}

void UNUSED Video_SetBgPlttColorDirect(u32 plttIdx, u32 colorIdx, u32 color) { ((rgb555*)BG_PLTT)[plttIdx * 16 + colorIdx] = color; }

void UNUSED Video_SetObjPlttColorDirect(u32 plttIdx, u32 colorIdx, u32 color) { ((rgb555*)OBJ_PLTT)[plttIdx * 16 + colorIdx] = color; }

// gSpriteSizeTable から、OAM の形状・サイズ(0-15)ごとの幅/高さ/タイル数/OAM属性ビットの表を作る
void Video_CreateSpriteLUT(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 w = (u8)gSpriteSizeTable[i];
    s32 h = gSpriteSizeTable[i] >> 8;
    s32 tw = w >> 3;
    s32 th = h >> 3;
    gOAMWidthTable[i] = w;
    gOAMHeightTable[i] = h;
    gOAMTileWidthTable[i] = tw;
    gOAMTileHeightTable[i] = th;
    gOAMTileCounts[i] = tw * th;
    gOAMShapeSizeAttrTable[i] = ((i & 3) << 14) | ((i & 0xC) << 28);
  }
}
