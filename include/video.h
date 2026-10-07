#ifndef __INCLUDE_VIDEO_H__
#define __INCLUDE_VIDEO_H__

#include "gba/gba.h"
#include "tilemap.h"
#include "types.h"

// BG1枚分の状態 (gBgStates[4] @ 0x03003ED0), 要素の区切りの根拠: entity_cbb0, enemy_dex が &gBgStates[3] (0x03003F60) を起点に +0x10..+0x28 を触る
typedef struct {
  u8 unk_00[16];         // 0x00
  u16 unk_10;            // 0x10, Video_SetBGLayer が 0x1000 を入れる
  u16 unk_12;            // 0x12, 同上
  u8 unk_14[4];          // 0x14
  s16 width16;           // 0x18, TilemapLayer.width (= 16px単位)
  u16 height16;          // 0x1A, TilemapLayer.height (= 16px単位)
  u16 unk_1c;            // 0x1C, width16 と同じ値
  u16 unk_1e;            // 0x1E, height16 と同じ値
  u16 hofs;              // 0x20, BGnHOFS の基準値 (HBlank エフェクトで各ラインの値に足される)
  u16 vofs;              // 0x22, BGnVOFS の基準値
  u8 unk_24[4];          // 0x24
  MetatileIdx16* mtmap;  // 0x28, TilemapLayer.mtmap
  BgMapEntry* tilemap;   // 0x2C, GBAタイルマップのバッファ
} BgState;
static_assert(sizeof(BgState) == 48);

extern BgState gBgStates[4];
extern rgb555 gBgPlttBuffer[256];
extern rgb555 gBgPlttBlendColor;
extern rgb555 gObjPlttBlendColor;
extern u16 gBgPlttFadeRowMask;  // 0x03004454, bit i が立っているパレット行だけ ApplyBgPlttBlend が明るさ・ブレンドを掛ける
extern u16 gStagedDISPCNT;

extern s32 gBgBrightness;
extern s32 gBgBrightness2;
extern s32 gObjBrightness;

extern u16* gHBlankEffectBuffer;
extern vu16* gHBlankEffectReg;
extern u16 u16_03003510;
extern u16 u16_03003514;

extern u32 gOamDirty;
extern u32 gVBlankCount;

rgb555* GetBgPlttBlendBuffer(void);

void Video_SetBLDCNTDirect(u32 effect, u32 target1, u32 target2);
void Video_SetBLDALPHADirect(u32 target1, u32 target2);
void Video_SetDrawPasses(s32 val, Procedure ptclFn, Procedure auxsprFn, Procedure mainsprFn);
void Particle_DrawList(void);
void AuxSprite_DrawList(void);
void MainSprite_DrawList(void);
void AuxSprite_DrawListScreen(void);
void Particle_DrawListScreen(void);
void MainSprite_DrawListScreen(void);
void AuxSprite_DrawListGameover(void);
void Particle_DrawListGameover(void);
void MainSprite_DrawListGameover(void);

void SetBGPrioDirect(s32 bg, u32 prio);
void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs);
void Video_SetupBGLayout(s32 layout, u32 param_2, TilemapFile* tilemap, u32 param_4, u32 param_5, s32 count, s32* indices);
void Video_SetupBG(s32 bg, u32 param_2, unknown* f, u32 unused, s16 param_5, s16 param_6, u32 prio, BgMapEntry* tilemap);
void Video_SetBGLayer(s32 bg, TilemapFile* tilemap, s32 layerIdx);
void ClearBGTilemapBuffer(s32 bg);
void Video_ResetBG(void);

BgMapEntry* GetTilemapBuffer(s32 bg);

void FUN_0822f0d8(void);
void FUN_0822f178(s32 idx, u32 evb, u32 eva);  // REG_BLDCNT / REG_BLDALPHA を設定する
void Video_SetHBlankEffect(s32 bg, s32 kind, void* table);
void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets);
void Video_ClearMosaic(void);

void Video_SetWindowRect(s32 win, s32 left, s32 top, s32 right, s32 bottom);

#endif  // __INCLUDE_VIDEO_H__
