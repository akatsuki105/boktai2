#ifndef __INCLUDE_EEPROM_H__
#define __INCLUDE_EEPROM_H__

#include "gba/gba.h"

typedef void SaveData;  // 解析が進んできたら普通にvoidにする予定, gSystemSaveData, gWorld, gStat, &gStat->unk_3b8

s32 FUN_08243648(s32 n);

s32 EEPROM_ReadRetry(eepromAdr addr, SaveData* data, s32 len);
s32 EEPROM_WriteRetry(eepromAdr addr, SaveData* data, s32 len);

#endif  // __INCLUDE_EEPROM_H__
