#ifndef __INCLUDE_SAVE_H__
#define __INCLUDE_SAVE_H__

#include "gba/gba.h"
#include "types.h"

typedef struct {
  s32 frameCounter;   // 0x00
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

#endif  // __INCLUDE_SAVE_H__
