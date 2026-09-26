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
extern u16 gBgPlttBlendColor;
extern u16 gStagedDISPCNT;

extern u16* gHBlankEffectBuffer;
extern vu16* gHBlankEffectReg;
extern u16 u16_03003510;
extern u16 u16_03003514;

rgb555* FUN_0822d00c(void);

void Video_SetDrawPasses(s32 val, Procedure ptclFn, Procedure auxsprFn, Procedure mainsprFn);
void MainSprite_DrawList(void);
void MainSprite_DrawListScreen(void);
void FUN_0822aaac(void);
void FUN_0822ac90(void);
void FUN_0822db5c(void);
void FUN_0822de64(void);

void SetBGPrioDirect(s32 bg, u32 prio);
void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs);
void Video_SetupBGLayout(s32 layout, u32 param_2, unknown* f, u32 param_4, u32 param_5, s32 count, s32* indices);

u16* GetTilemapBuffer(s32 bg);

void FUN_0822f0d8(void);
void Video_SetHBlankEffect(s32 bg, s32 kind, void* table);
void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets);
void Video_ClearMosaic(void);

void Video_SetWindowRect(s32 win, s32 left, s32 top, s32 right, s32 bottom);

#endif  // __INCLUDE_VIDEO_H__
