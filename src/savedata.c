#include "eeprom.h"
#include "game.h"
#include "global.h"
#include "malloc.h"
#include "vm.h"

extern u32 u32_03004860;
extern u32 u32_030047b4;

// EEPROM_WriteOnce が各データの末尾に付ける 8 バイトのトレーラー (EEPROM_ReadOnce が検証する)
typedef struct {
  u16 xorChecksum;  // 0x0
  u16 sumChecksum;  // 0x2
  u16 length;       // 0x4, データ長
  u16 unk_6;        // 0x6
} EepromTrailer;

// EEPROM (64Kbit = 8192 バイト) 上のセーブデータの配置。ドキュメント用でビルドには使わない
// EEPROM のアドレスは 8 バイト単位のブロック番号で、各データは 8 の倍数に切り上げた長さ + トレーラーで書かれる
// Core / Extra はスロット 0/1 の 2 つずつあり、gSystemSaveData->currentSlot が今のスロットを指す
typedef struct {
  // ブロック 0: gSystemSaveData (Save_ReadSystemData / Save_WriteSystemData)
  u8 system[40];                // 0x0000, SystemSaveData
  EepromTrailer systemTrailer;  // 0x0028
  u8 unused_0030[88];           // 0x0030

  // ブロック 17 + slot * 129: Core の gWorld 部分 (Save_GetCoreAddr(slot, 0))
  struct {
    u8 world[1024];         // World 全体
    EepromTrailer trailer;  // +0x400
  } coreWorld[2];  // 0x0088

  // ブロック 275 + slot * 161: Core の gStat 部分 (Save_GetCoreAddr(slot, 1))
  struct {
    u8 stat[952];           // gStat の先頭〜0x3B8 (Save_GetExtraOffset), 先頭は magicNumber
    EepromTrailer trailer;  // +0x3B8
    u8 unused[328];         // +0x3C0, 確保されているが使われない
  } coreStat[2];  // 0x0898

  // ブロック 597 + slot * 193: Extra (Save_GetExtraAddr(slot))
  struct {
    u8 stat[1392];          // gStat の 0x3B8〜0x928 (Save_GetExtraSize)
    EepromTrailer trailer;  // +0x570
    u8 unused[144];         // +0x578, 確保されているが使われない
  } extra[2];  // 0x12A8

  u8 unused_1eb8[328];  // 0x1EB8, ブロック 983 以降は使われない
} Boktai2SaveData;
static_assert(sizeof(Boktai2SaveData) == 8192);

// FUN_0823201c が書き込む変数記述子
typedef struct {
  u8 desc[4];  // 0x0, Pointer/Indexed Pointer 記述子
  u16 count;   // 0x4, 記述子が指す値の個数
  u16 unk_6;   // 0x6
} q_VarDesc;

typedef struct {
  u32 count;             // 0x0000, values に退避した値の数
  q_VarDesc descs[512];  // 0x0004
  u32 values[512];       // 0x1004
} UnkData6148;
static_assert(sizeof(UnkData6148) == 6148);

void FUN_08231ca8(void);
void Save_BackupStatAndWorld(void);
void FUN_08231d5c(void* statFieldPtr, s32 bytesize);
void* FUN_08231d80(void* statFieldPtr);
void FUN_0823167c(u8* dst);
u32 FUN_082320e4(u8* pc, s32 offset);
void FUN_0823206c(u8* pc, s32 offset, u32 val);

u32 Save_GetCoreAddr(u32 val1, u32 val2) {
  if (val2 != 0) {
    return val1 * 161 + 0x113;
  }
  return val1 * 129 + 0x11;
}

u32 Save_GetExtraAddr(u32 val) { return val * 193 + 0x255; }

void* Save_GetExtraStart(void) { return gStat->unk_3b8; }

void* Save_GetExtraEnd(void) { return gStat->unk_928; }

// EEPROM に保存する領域の gStatBackup 側の先頭アドレスを返す
void* Save_GetBackupExtraStart(void) { return FUN_08231d80(Save_GetExtraStart()); }

// EEPROM に保存する領域の gStat 先頭からのオフセットを返す
s32 Save_GetExtraOffset(void) { return (u8*)Save_GetExtraStart() - (u8*)gStat; }

// セーブデータとして EEPROM に読み書きする gStat の領域のサイズを返す
s32 Save_GetExtraSize(void) {
  u8* start = Save_GetExtraStart();
  return (u8*)Save_GetExtraEnd() - start;
}

// EEPROM に保存する gStat の領域だけを gStatBackup にバックアップする
void Save_BackupExtra(void) {
  void* start = Save_GetExtraStart();
  FUN_08231d5c(start, Save_GetExtraSize());
}

// gSystemSaveData を EEPROM の先頭に書き込む
bool8 Save_WriteSystemData(void) {
  s32 len = FUN_08243648(sizeof(SystemSaveData));
  if (EEPROM_WriteRetry(0, gSystemSaveData, len) != len + 8) return FALSE;
  return TRUE;
}

// EEPROM の先頭から gSystemSaveData を読み込む。読めなければゼロクリアする
bool8 Save_ReadSystemData(void) {
  s32 len = FUN_08243648(sizeof(SystemSaveData));
  if (EEPROM_ReadRetry(0, gSystemSaveData, len) < 0) {
    ClearMemory(gSystemSaveData, sizeof(SystemSaveData));
    return FALSE;
  }
  return TRUE;
}

// gWorldBackup と gStatBackup の先頭部分を EEPROM の val 番に書き込む
bool8 Save_WriteCore(u32 val) {
  s32 len;
  s32 ret;

  *(u32*)gStat = gScriptDirectoryBuildTime;  // gStat->magicNumber
  FUN_08231d5c(gStat, sizeof(u32));
  len = FUN_08243648(sizeof(World));
  ret = EEPROM_WriteRetry(Save_GetCoreAddr(val, 0), FUN_08232260(), len);
  if (ret != len + 8) return FALSE;
  len = FUN_08243648(Save_GetExtraOffset());
  ret = EEPROM_WriteRetry(Save_GetCoreAddr(val, 1), FUN_08232254(), len);
  if (ret != len + 8) return FALSE;
  u32_030047b4 = TRUE;
  return TRUE;
}

// EEPROM の val 番から gWorld と gStat の先頭部分を読み込み、マジックナンバーが一致するか確認する
bool8 Save_ReadCore(u32 val) {
  s32 len = FUN_08243648(sizeof(World));
  if (EEPROM_ReadRetry(Save_GetCoreAddr(val, 0), gWorld, len) < 0) return FALSE;
  len = FUN_08243648(Save_GetExtraOffset());
  if (EEPROM_ReadRetry(Save_GetCoreAddr(val, 1), gStat, len) < 0) return FALSE;
  if (gStat->magicNumber != gScriptDirectoryBuildTime) return FALSE;
  u32_030047b4 = TRUE;
  return TRUE;
}

// val 番のデータとしてセーブデータを EEPROM に書き込む
bool8 Save_WriteExtra(u32 val) {
  s32 len = FUN_08243648(Save_GetExtraSize());
  if (EEPROM_WriteRetry(Save_GetExtraAddr(val), Save_GetBackupExtraStart(), len) != len + 8) return FALSE;
  return TRUE;
}

// val 番のデータを EEPROM から gStat->unk_3b8 に読み込む
bool8 Save_ReadExtra(u32 val) {
  s32 len = FUN_08243648(Save_GetExtraSize());
  if (EEPROM_ReadRetry(Save_GetExtraAddr(val), Save_GetExtraStart(), len) < 0) return FALSE;
  return TRUE;
}

// EEPROM の指定領域を 0xABCD で埋めて消去する
bool32 EEPROM_Erase(eepromAdr addr, s32 size) {
  u16* buf;
  s32 i;

  if (size > 0x1FF8) size = 0x1FF8;
  size &= ~3;
  buf = Malloc(size);
  if (buf == NULL) return FALSE;
  for (i = 0; i < size >> 1; i++) {
    buf[i] = 0xABCD;
  }
  EEPROM_WriteRetry(addr, buf, size);
  Free(buf);
  return TRUE;
}

// 現在のスロットからセーブデータを読み込む
bool32 Save_ReadCurrentSlot(void) {
  u8 cur = gSystemSaveData->currentSlot;
  if (!Save_ReadCore(cur)) return FALSE;
  if (!Save_ReadExtra(cur)) return FALSE;
  return TRUE;
}

// もう一方のスロットからセーブデータを読み込み、読めたらそちらを現在のスロットにする
bool32 Save_ReadFromNextSlot(void) {
  s32 next = 1 - gSystemSaveData->currentSlot;
  if (!Save_ReadCore(next)) return FALSE;
  if (!Save_ReadExtra(next)) return FALSE;
  gSystemSaveData->currentSlot = next;
  return TRUE;
}

// もう一方のスロットにセーブデータを書き込み、書けたらそちらを現在のスロットにして gSystemSaveData も保存する
u8 Save_WriteToNextSlot(void) {
  s32 next = 1 - gSystemSaveData->currentSlot;
  if (!Save_WriteCore(next)) return FALSE;
  if (!Save_WriteExtra(next)) return FALSE;
  gSystemSaveData->currentSlot = next;
  return Save_WriteSystemData();
}

// 現在のスロットから gStat の EEPROM 保存領域だけを読み込む
u8 Save_ReadCurrentSlotExtra(void) { return Save_ReadExtra(gSystemSaveData->currentSlot); }

bool32 Save_WriteExtraToNextSlot(void) {
  u8 cur = gSystemSaveData->currentSlot;
  s32 next = 1 - cur;

  Save_BackupExtra();
  if (!Save_ReadCore(cur)) return FALSE;
  Save_BackupStatAndWorld();
  if (!Save_WriteCore(next)) return FALSE;
  if (!Save_WriteExtra(next)) return FALSE;
  return TRUE;
}

u8 Save_SwitchSlot(void) {
  gSystemSaveData->currentSlot = 1 - gSystemSaveData->currentSlot;
  return Save_WriteSystemData();
}

void UNUSED nop_08241420(void) {}

// スクリプトの引数で指定された変数の値を p に退避する
s32 VM_BackupVars(UnkData6148* p) {
  q_VarDesc* desc = p->descs;
  u32* dst = p->values;
  while (p->count <= 511 && VM_GetPC() != NULL) {
    s32 i;
    FUN_0823167c(desc->desc);
    for (i = 0; i < desc->count && p->count <= 511; i++) {
      *dst++ = FUN_082320e4(desc->desc, i);
      p->count++;
    }
    desc++;
  }
  return 0;
}

// VM_BackupVars で退避した値を元の変数に書き戻す
s32 VM_RestoreVars(UnkData6148* p) {
  q_VarDesc* desc = p->descs;
  u32* src = p->values;
  u32 n = 0;
  while (n < p->count) {
    s32 i;
    for (i = 0; i < desc->count && n < p->count; i++) {
      FUN_0823206c(desc->desc, i, *src++);
      n++;
    }
    desc++;
  }
  return 0;
}

s32 VM_ResetGameKeepingVars(void) {
  UnkData6148* buf = Malloc(6148);
  if (buf == NULL) return -1;
  ClearMemory(buf, 6148);
  if (VM_BackupVars(buf) < 0) return -1;
  FUN_08231ca8();
  if (VM_RestoreVars(buf) < 0) return -1;
  Free(buf);
}

void FUN_08241550(void) {
  gStat->unk_248 = Script_GetValue();
  u32_03004860 = 1;
}
