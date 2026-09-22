#ifndef __INCLUDE_VIDEO_H__
#define __INCLUDE_VIDEO_H__

#include "gba/gba.h"
#include "types.h"

// BG1枚分の状態 (gBgStates[4] @ 0x03003ED0), 要素の区切りの根拠: entity_cbb0, enemy_dex が &gBgStates[3] (0x03003F60) を起点に +0x10..+0x28 を触る
typedef struct {
  u8 unk_00[24];
  s16 unk_18;  // 0x18, ×2 したものが tilemap の 1 行のエントリ数, 根拠: FUN_0822bcf4
  u8 unk_1a[6];
  u16 hofs;  // 0x20, BGnHOFS の基準値 (HBlank エフェクトで各ラインの値に足される), 根拠: FUN_0822eef4, StageBGRegs
  u16 vofs;  // 0x22, BGnVOFS の基準値, 根拠: FUN_0822eef4, StageBGRegs
  u8 unk_24[8];
  u16* tilemap;  // 0x2C, タイルマップのバッファ, 根拠: FUN_0822bcf4 がタイル番号|反転<<10|パレット<<12 を書く
} BgState;
static_assert(sizeof(BgState) == 48);

extern BgState gBgStates[4];
extern rgb555 gBgPlttBuffer[256];

extern u16* gHBlankEffectBuffer;
extern vu16* gHBlankEffectReg;
extern u16 u16_03003510;
extern u16 u16_03003514;

void Video_SetDrawPasses(s32 val, Procedure ptclFn, Procedure auxsprFn, Procedure mainsprFn);
u16* GetTilemapBuffer(s32 bg);

void Video_SetHBlankEffect(s32 bg, s32 kind, void* table);
void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets);
void Video_ClearMosaic(void);

#endif  // __INCLUDE_VIDEO_H__
