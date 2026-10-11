#ifndef __INCLUDE_SAVE_H__
#define __INCLUDE_SAVE_H__

#include "gba/gba.h"
#include "types.h"

typedef struct {
  u32 frameCounter;       // 0x00, u32 の根拠: Entity0823acbc_Update が 0xFFFFFFFF と符号なし比較する
  s32 calibration;        // 0x04, 太陽センサーのキャリブレーション値
  u8 currentSlot;         // 0x08
  u8 unk_09;              // 0x09
  u8 unk_0a;              // 0x0A
  bool8 summerTime;       // 0x0B, サマータイム
  s32 crossoverPoint;     // 0x0C, クロスオーバーポイント, クロスオーバー通信をすることでもらえるポイント, ポイントを消費してアイテムなどと交換できる
  u32 crossoverUnlocked;  // 0x10, crossoverUnlocked == 0x369F の場合、クロスオーバーバトルが解放されている
  u16 crossoverCount;     // 0x14, クロスオーバーバトルでの対戦回数
  u16 crossoverWins;      // 0x16, クロスオーバーバトルでの勝利回数
  u16 eventFlags[4];      // 0x18, 0: BB3 (BlindBoxLv3), 1: BB4, 2: BB5 & バレンタイン, 3: なんか
  u32 prefecture;         // 0x20, 地域 (e.g. イバラキ: 1, トウキョウ: 6, キョウト: 20)
  u8 unk_24[4];           // 0x24
} SystemSaveData;
static_assert(sizeof(SystemSaveData) == 40);

extern SystemSaveData* gSystemSaveData;  // 0x030047A8

// --------------------------------------------

extern bool32 gSoftResetInhibit;
extern bool32 gSaveSucceeded;

// もう一方のスロットにセーブデータを書き込み、成功したらそちらを現在のスロットにする
u8 Save_WriteToNextSlot(void);

#endif  // __INCLUDE_SAVE_H__
