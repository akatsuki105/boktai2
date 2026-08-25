#include "global.h"

typedef void SaveData;  // 解析が進んできたら普通にvoidにする予定, gSystemSaveData, gWorld, gStat, &gStat->unk_3b8

NAKED s32 FUN_08243660(void) { INCFUNC("asm/func/FUN_08243660.inc"); }

NAKED u32 FUN_082436dc(void) { INCFUNC("asm/func/FUN_082436dc.inc"); }

NAKED s32 FUN_0824374c(eepromAdr addr, SaveData* data, s32 r2) { INCFUNC("asm/func/FUN_0824374c.inc"); }

NAKED s32 FUN_08243828(eepromAdr addr, SaveData* data, u32 r2) { INCFUNC("asm/func/FUN_08243828.inc"); }

typedef struct {
  u16 checksumXor;
  u16 checksumSum;
  u16 length;
  u16 sentinel;
} EepromTrailer;

NON_MATCH s32 FUN_082438e0(eepromAdr addr, s32 len) {
#ifdef NONMATCHING_C
  EepromTrailer trailer;
  u16 checksum[2];
  u16 buf[4];
  s32 count;
  s32 total;
  u16* p;
  s32 i;
  u16 nextAddr;

  total = len >> 3;
  checksum[0] = 0;
  checksum[1] = 0;
  count = 0;
  if (total > 0) {
    do {
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
    } while (count < total);
  }
  if ((EEPROMRead(addr, (u16*)&trailer) != 0) || ((checksum[0] ^= trailer.checksumXor) != 0) || (checksum[1] != trailer.checksumSum) || (len != trailer.length)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_082438e0.inc");
#endif
}

NAKED s32 FUN_08243988(eepromAdr addr, SaveData* data, s32 r2) { INCFUNC("asm/func/FUN_08243988.inc"); }

NAKED s32 FUN_082439f0(eepromAdr addr, SaveData* data, s32 r2) { INCFUNC("asm/func/FUN_082439f0.inc"); }

s32 FUN_08243648(s32 n);

s32 FUN_08243a58(eepromAdr addr, s32 len) {
  s32 result;

  if ((len != FUN_08243648(len)) || (len > 0x1FF8)) {
    return -1;
  }
  FUN_08243660();
  result = FUN_082438e0(addr, len);
  FUN_082436dc();
  return result;
}
