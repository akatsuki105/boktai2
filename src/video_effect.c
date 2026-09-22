#include "global.h"
#include "video.h"

extern u16 gMosaicDirty;
extern u16 gMosaicSize;
extern u8 gObjMosaicEnabled;
extern u8 gMosaicTargets;

extern u32 gHBlankEffectBG;
extern s32 gHBlankEffectKind;
extern void* gHBlankEffectTable;

extern u8 u8_ARRAY_02036c00[512];

// モザイクの設定を初期化する (I/O には反映しない)
void Video_ResetMosaic(void) {
  gMosaicDirty = 0;
  gMosaicSize = 0;
  gObjMosaicEnabled = 0;
  gMosaicTargets = 0;
}

void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets) {
  gMosaicDirty = 1;
  gMosaicSize = size;
  gObjMosaicEnabled = objEnabled;
  gMosaicTargets = targets;
}

// 次の Video_ApplyMosaic でモザイクを解除させる
void Video_ClearMosaic(void) {
  gMosaicDirty = 1;
  gMosaicSize = 0;
  gObjMosaicEnabled = 0;
  gMosaicTargets = 0;
}

// 要求されていればモザイクの設定を I/O レジスタに反映する
void Video_ApplyMosaic(void) {
  if (gMosaicDirty != 0) {
    if (gMosaicTargets & (1 << 0)) {
      REG_BG0CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG0CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 1)) {
      REG_BG1CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG1CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 2)) {
      REG_BG2CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG2CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 3)) {
      REG_BG3CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG3CNT &= ~BGCNT_MOSAIC;
    }
    if ((gMosaicTargets & (1 << 4)) == 0) {
      REG_MOSAIC = (u8)gMosaicSize;
    } else {
      REG_MOSAIC = gMosaicSize;
    }
    gMosaicDirty = 0;
  }
}

void Video_ResetHBlankEffect(void) {
  gHBlankEffectBG = 2;
  gHBlankEffectKind = 0;
  gHBlankEffectTable = NULL;
}

// スキャンライン毎に I/O レジスタへ転送する値のテーブルを設定する
void Video_SetHBlankEffect(s32 bg, s32 kind, void* table) {
  gHBlankEffectBG = bg;
  gHBlankEffectKind = kind;
  gHBlankEffectTable = table;
}

void* FUN_0822ee74(void) { return u8_ARRAY_02036c00; }

vu16* Video_GetBGnHOFS(s32 bg) {
  switch (bg) {
    case 0:
      return &REG_BG0HOFS;
    case 1:
      return &REG_BG1HOFS;
    case 2:
      return &REG_BG2HOFS;
    default:
      return &REG_BG3HOFS;
  }
}

vu16* Video_GetBGnVOFS(s32 bg) {
  switch (bg) {
    case 0:
      return &REG_BG0VOFS;
    case 1:
      return &REG_BG1VOFS;
    case 2:
      return &REG_BG2VOFS;
    default:
      return &REG_BG3VOFS;
  }
}

// 設定された HBlank エフェクトのテーブルから、ライン毎に I/O レジスタへ書く値のバッファを作る
void FUN_0822eef4(void) {
  if (gHBlankEffectTable != NULL) {
    s32 i;
    u32 base;

    u16* buf = FUN_0822ee74();
    vu16* reg = &REG_BG3HOFS;

    switch (gHBlankEffectKind) {
      case 0: {
        reg = Video_GetBGnHOFS(gHBlankEffectBG);
        base = gBgStates[gHBlankEffectBG].hofs & 0x1FF;
        for (i = 0; i < DISPLAY_HEIGHT; i++) {
          buf[i] = (((u16*)gHBlankEffectTable)[i] + base) & 0x1FF;
        }
        break;
      }
      case 1: {
        reg = Video_GetBGnVOFS(gHBlankEffectBG);
        base = gBgStates[gHBlankEffectBG].vofs & 0x1FF;
        for (i = 0; i < DISPLAY_HEIGHT; i++) {
          buf[i] = (((u16*)gHBlankEffectTable)[i] + base) & 0x1FF;
        }
        break;
      }
      case 2: {
        reg = &REG_MOSAIC;
        for (i = 0; i < DISPLAY_HEIGHT; i++) {
          buf[i] = ((u16*)gHBlankEffectTable)[i];
        }
        break;
      }
      case 3: {
        REG_BLDALPHA = BLDALPHA_BLEND(16, 8);
        REG_BLDCNT = 0x0EDE;
        reg = &REG_BLDY;
        for (i = 0; i < DISPLAY_HEIGHT; i++) {
          buf[i] = ((u16*)gHBlankEffectTable)[i] & 0x1F;
        }
        break;
      }
    }
    gHBlankEffectBuffer = buf, gHBlankEffectReg = reg;
    u16_03003510 = 1;
    u16_03003514 = 1;
    gHBlankEffectTable = NULL;
  }
}

// HBlank エフェクト用のバッファを空にし、エフェクト種類に応じた転送先レジスタを設定する
void FUN_0822f0d8(void) {
  u16* buf = FUN_0822ee74();
  vu16* reg;

  ClearMemory(buf, DISPLAY_HEIGHT * sizeof(u16));
  reg = &REG_BG3HOFS;
  switch (gHBlankEffectKind) {
    case 0: {
      reg = Video_GetBGnHOFS(gHBlankEffectBG);
      break;
    }
    case 1: {
      reg = Video_GetBGnVOFS(gHBlankEffectBG);
      break;
    }
    case 2: {
      Video_ClearMosaic();
      reg = &REG_MOSAIC;
      break;
    }
    case 3: {
      reg = &REG_BLDY;
      break;
    }
  }
  gHBlankEffectBuffer = buf, gHBlankEffectReg = reg;
  u16_03003510 = 1;
  u16_03003514 = 0;
  gHBlankEffectTable = NULL;
}

void FUN_0822f178(s32 idx, u32 evb, u32 eva) {
  static const u16 u16_ARRAY_085b0150[4] = {
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG0,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG1,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG2,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG3,
  };  // 0x085b0150
  REG_BLDCNT = u16_ARRAY_085b0150[idx] | BLDCNT_EFFECT_BLEND;
  REG_BLDALPHA = BLDALPHA_BLEND(eva, evb);
  REG_BLDY = 0;
}
