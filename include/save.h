#ifndef __INCLUDE_SAVE_H__
#define __INCLUDE_SAVE_H__

#include "gba/gba.h"
#include "types.h"

typedef struct {
  u32 frameCounter;   // 0x00, u32 の根拠: Entity0823acbc_Update が 0xFFFFFFFF と符号なし比較する
  s32 calibration;    // 0x04, 太陽センサーのキャリブレーション値
  u8 currentSlot;     // 0x08
  u8 unk_09;          // 0x09
  u8 unk_0a;          // 0x0A
  bool8 summerTime;   // 0x0B, サマータイム
  s32 unk_c;          // 0x0C, 根拠: FUN_0823d6bc
  u32 unk_10;         // 0x10, 根拠: FUN_0823d68c
  u16 unk_14;         // 0x14, 根拠: FUN_0823d700
  u16 unk_16;         // 0x16, 根拠: FUN_0823d700
  u16 eventFlags[4];  // 0x18, 0: BB3 (BlindBoxLv3), 1: BB4, 2: BB5 & バレンタイン, 3: なんか
  u32 timezone;       // 0x20, タイムゾーン, u32 の根拠: FUN_0823d680
  u8 unk_24[4];       // 0x24
} SystemSaveData;
static_assert(sizeof(SystemSaveData) == 40);

extern SystemSaveData* gSystemSaveData;
static inline void SystemSave_SetUnk09(u32 val) { gSystemSaveData->unk_09 = val; }

// --------------------------------------------

extern bool32 gSoftResetInhibit;

// もう一方のスロットにセーブデータを書き込み、成功したらそちらを現在のスロットにする
u8 Save_WriteToNextSlot(void);

#endif  // __INCLUDE_SAVE_H__
