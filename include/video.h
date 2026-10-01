#ifndef __INCLUDE_VIDEO_H__
#define __INCLUDE_VIDEO_H__

#include "gba/gba.h"
#include "tilemap.h"
#include "types.h"

// BG1枚分の状態 (gBgStates[4] @ 0x03003ED0), 要素の区切りの根拠: entity_cbb0, enemy_dex が &gBgStates[3] (0x03003F60) を起点に +0x10..+0x28 を触る
typedef struct {
  u8 unk_00[16];
  u16 unk_10;  // 0x10, Video_SetBGLayer が 0x1000 を入れる
  u16 unk_12;  // 0x12, 同上
  u8 unk_14[4];
  s16 unk_18;  // 0x18, ×2 したものが tilemap の 1 行のエントリ数, 根拠: FUN_0822bcf4. Video_SetBGLayer が TilemapLayer.width を入れる
  u16 unk_1a;  // 0x1A, Video_SetBGLayer が TilemapLayer.height を入れる
  u16 unk_1c;  // 0x1C, unk_18 と同じ値
  u16 unk_1e;  // 0x1E, unk_1a と同じ値
  u16 hofs;    // 0x20, BGnHOFS の基準値 (HBlank エフェクトで各ラインの値に足される), 根拠: FUN_0822eef4, StageBGRegs
  u16 vofs;    // 0x22, BGnVOFS の基準値, 根拠: FUN_0822eef4, StageBGRegs
  u8 unk_24[4];
  MetatileIdx16* mtmap;  // 0x28, Video_SetBGLayer が TilemapLayer.offsetToTilemap を絶対アドレスにして入れる
  u16* tilemap;          // 0x2C, タイルマップのバッファ, 根拠: FUN_0822bcf4 がタイル番号|反転<<10|パレット<<12 を書く
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

extern u32 gOamDirty;
extern u32 gVBlankCount;

rgb555* FUN_0822d00c(void);

void Video_SetBLDCNTDirect(u32 effect, u32 target1, u32 target2);
void Video_SetBLDALPHADirect(u32 target1, u32 target2);
void Video_SetDrawPasses(s32 val, Procedure ptclFn, Procedure auxsprFn, Procedure mainsprFn);
void Particle_DrawList(void);
void AuxSprite_DrawList(void);
void MainSprite_DrawList(void);
void FUN_0822ac90(void);
void FUN_0822de64(void);
void MainSprite_DrawListScreen(void);
void AuxSprite_DrawListGameover(void);
void Particle_DrawListGameover(void);
void MainSprite_DrawListGameover(void);

void SetBGPrioDirect(s32 bg, u32 prio);
void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs);
void Video_SetupBGLayout(s32 layout, u32 param_2, TilemapFile* tilemap, u32 param_4, u32 param_5, s32 count, s32* indices);
void Video_SetupBG(s32 bg, u32 param_2, unknown* f, u32 unused, s16 param_5, s16 param_6, u32 prio, u16* tilemap);
void Video_SetBGLayer(s32 bg, TilemapFile* tilemap, s32 layerIdx);
void ClearBGTilemapBuffer(s32 bg);
void vram_0822b778(void);

u16* GetTilemapBuffer(s32 bg);

void FUN_0822f0d8(void);
void FUN_0822f178(s32 idx, u32 evb, u32 eva);  // REG_BLDCNT / REG_BLDALPHA を設定する
void Video_SetHBlankEffect(s32 bg, s32 kind, void* table);
void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets);
void Video_ClearMosaic(void);

void Video_SetWindowRect(s32 win, s32 left, s32 top, s32 right, s32 bottom);

#endif  // __INCLUDE_VIDEO_H__
