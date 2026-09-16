#include "eeprom.h"

#include "global.h"
#include "solar.h"
#include "sound.h"

// EEPROM アクセス中に退避しておく HBlank エフェクトの状態, EEPROM_BeginAccess が保存し EEPROM_EndAccess が戻す
typedef struct {
  u16* buffer;  // 0x00, gHBlankEffectBuffer
  vu16* reg;    // 0x04, gHBlankEffectReg
  u16 unk_8;    // 0x08, u16_03003510
  u16 unk_a;    // 0x0A, u16_03003514
  u8 unk_c[4];  // 0x0C
} SavedHBlankState;
static_assert(sizeof(SavedHBlankState) == 16);

COMMON_DATA SavedHBlankState gSavedHBlankState = {};  // 0x03004880

extern u16* gHBlankEffectBuffer;
extern vu16* gHBlankEffectReg;
extern u16 u16_03003510;
extern u16 u16_03003514;
extern u16 u16_0300351c;
extern u32 u32_0300481c;
extern u32 u32_0300170c;

s32 FUN_08243648(s32 n) {
  u32 val = n & (~7);
  if ((n & 7) != 0) val += 8;
  return val;
}

// EEPROM アクセス前に、HBlank エフェクト・サウンド・割り込みを止めて状態を退避する (EEPROM_EndAccess で戻す)
s32 EEPROM_BeginAccess(void) {
  gSavedHBlankState.buffer = gHBlankEffectBuffer;
  gSavedHBlankState.reg = gHBlankEffectReg;
  gSavedHBlankState.unk_8 = u16_03003510;
  gSavedHBlankState.unk_a = u16_03003514;
  gHBlankEffectBuffer = NULL;
  gHBlankEffectReg = NULL;
  u16_03003510 = 0;
  u16_03003514 = 0;
  FUN_082407e0();
  WaitForVBlank();
  u16_0300351c = 0;
  m4aSoundVSyncOff();
  WaitForVBlank();
  REG_IME = 0;
  u32_0300170c = u32_0300481c;
  u32_0300481c = 1;
  REG_IME = 1;
  FUN_08241704();
  return 0;
}

// EEPROM アクセス後に、EEPROM_BeginAccess で止めていた割り込み・サウンド・HBlank エフェクトを元に戻す
u32 EEPROM_EndAccess(void) {
  SavedHBlankState* s = &gSavedHBlankState;

  REG_IF = 1;
  u16_0300351c = 1;
  m4aSoundVSyncOn();
  WaitForVBlank();
  REG_IME = 0;
  gHBlankEffectBuffer = s->buffer;
  gHBlankEffectReg = s->reg;
  u16_03003510 = s->unk_8;
  u16_03003514 = s->unk_a;
  u32_0300481c = u32_0300170c;
  REG_IME = 1;
  FUN_0824172c();
}

NAKED s32 EEPROM_WriteOnce(eepromAdr addr, SaveData* data, s32 r2) { INCFUNC("asm/func/EEPROM_WriteOnce.inc"); }

// EEPROM から len バイトを data に読み込み、末尾のトレーラーの XOR/和チェックサムと長さで検証する
NON_MATCH s32 EEPROM_ReadOnce(eepromAdr addr, SaveData* data, s32 len) {
#ifdef NONMATCHING_C
  // 元はチェックサムのループで checksum[0]/[1] がレジスタに載り (初期値 movs #0、ループ後に strh で書き戻し)、こちらは毎回メモリを読み書きする
  u16 trailer[4];  // [0]: XOR チェックサム, [1]: 和チェックサム, [2]: データ長
  u16 checksum[2];
  u16* p;
  s32 total;
  s32 i;
  u16 err;

  total = len >> 3;
  p = data;
  for (i = 0; i < total; i++) {
    if (EEPROMRead(addr, p) != 0) {
      return -1;
    }
    p += 4;
    addr++;
  }
  err = EEPROMRead(addr, trailer);
  if (err == 0) {
    checksum[0] = 0;
    checksum[1] = 0;
    for (i = 0; i < len >> 1; i++) {
      checksum[0] ^= ((u16*)data)[i];
      checksum[1] += ((u16*)data)[i];
    }
  }
  checksum[0] ^= trailer[0];
  if ((err != 0) || (checksum[0] != 0) || (checksum[1] != trailer[1]) || (len != trailer[2])) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/EEPROM_ReadOnce.inc");
#endif
}

NON_MATCH s32 EEPROM_VerifyOnce(eepromAdr addr, s32 len) {
#ifdef NONMATCHING_C
  // 残りはレジスタ割当のみ: 元は total が r7、&buf (sp+0xC) が sb に入る (こちらは逆)
  u16 trailer[4];  // [0]: XOR チェックサム, [1]: 和チェックサム, [2]: データ長
  u16 checksum[2];
  u16 buf[4];
  s32 count;
  s32 total;
  u16* p;
  s32 i;
  s32 nextAddr;
  u16 err;

  total = len >> 3;
  checksum[0] = 0;
  checksum[1] = 0;
  count = 0;
  while (count < total) {
    if (EEPROMRead(addr, buf) != 0) {
      return -1;
    }
    nextAddr = addr + 1;
    count += 1;
    p = buf;
    i = 3;
    do {
      checksum[0] ^= *p;
      checksum[1] += *p;
      p += 1;
      i -= 1;
    } while (i >= 0);
    addr = nextAddr;
  }
  err = EEPROMRead(addr, trailer);
  checksum[0] ^= trailer[0];
  if ((err != 0) || (checksum[0] != 0) || (checksum[1] != trailer[1]) || (len != trailer[2])) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/EEPROM_VerifyOnce.inc");
#endif
}

// 引数を検査したうえで、EEPROM_WriteOnce による EEPROM への書き込みを成功するまで最大 8 回試す
s32 EEPROM_WriteRetry(eepromAdr addr, SaveData* data, s32 len) {
  s32 result;
  s32 i;

  if (((u32)data & 1) || (len != FUN_08243648(len)) || (len > 0x1FF8)) {
    return -1;
  }
  EEPROM_BeginAccess();
  result = -1;
  for (i = 0; i < 8; i++) {
    result = EEPROM_WriteOnce(addr, data, len);
    if (result >= 0) break;
  }
  EEPROM_EndAccess();
  return result;
}

// 引数を検査したうえで、EEPROM_ReadOnce による EEPROM からの読み込みを成功するまで最大 8 回試す
s32 EEPROM_ReadRetry(eepromAdr addr, SaveData* data, s32 len) {
  s32 result;
  s32 i;

  if (((u32)data & 1) || (len != FUN_08243648(len)) || (len > 0x1FF8)) {
    return -1;
  }
  EEPROM_BeginAccess();
  result = -1;
  for (i = 0; i < 8; i++) {
    result = EEPROM_ReadOnce(addr, data, len);
    if (result >= 0) break;
  }
  EEPROM_EndAccess();
  return result;
}

s32 EEPROM_Verify(eepromAdr addr, s32 len) {
  s32 result;

  if ((len != FUN_08243648(len)) || (len > 0x1FF8)) {
    return -1;
  }
  EEPROM_BeginAccess();
  result = EEPROM_VerifyOnce(addr, len);
  EEPROM_EndAccess();
  return result;
}
