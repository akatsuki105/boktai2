#include "gba/gba.h"

// Copy from https://github.com/jiangzhengwenjz/csm3/blob/main/src/agb_eeprom.c

extern const eepromType gEEPROMConfig512;
extern const eepromType gEEPROMConfig8k;

IWRAM_DATA const eepromType* gEEPROMConfig = NULL;  // 0x0300581c

u16 EEPROMConfigure(u16 unk_1) {
  u16 ret;

  ret = 0;
  if (unk_1 == 4) {
    gEEPROMConfig = &gEEPROMConfig512;
  } else {
    if (unk_1 == 0x40) {
      gEEPROMConfig = &gEEPROMConfig8k;
    } else {
      gEEPROMConfig = &gEEPROMConfig512;
      ret = 1;
    }
  }
  return ret;
}

void DMA3Transfer(const void* src, void* dest, u16 count) {
  eepromType* config;
  u32 temp;

  u16 IME_save;

  IME_save = REG_IME;
  REG_IME = 0;  // disable all interrupts
  temp = REG_WAITCNT & 0xF8FF;
  config = (eepromType*)gEEPROMConfig;
  temp |= config->agbWait;  // configure wait state 2
  REG_WAITCNT = temp;
  REG_DMA3SAD = (u32)src;
  REG_DMA3DAD = (u32)dest;
  REG_DMA3CNT = count | 0x80000000;  // enable dma
  while ((REG_DMA3CNT_H & 0x8000) != 0) {
  }  // wait for dma to finish
  REG_IME = IME_save;
}

u16 EEPROMRead(u16 address, u16* data) {
  u16 buffer[0x44];

  u16* ptr;
  u8 t1, t2;
  u16 value;

  if (address >= gEEPROMConfig->adrCount) {
    return EEPROM_OUT_OF_RANGE;
  } else {
    ptr = buffer;
    // setup address
    (u8*)ptr += (gEEPROMConfig->adrBit << 1) + 1;
    ((u8*)ptr)++;
    for (t1 = 0; t1 < gEEPROMConfig->adrBit; t1++) {
      *(ptr--) = address;
      address >>= 1;
    }
    // read request
    *(ptr--) = 1;
    *ptr = 1;
    // send address to eeprom
    DMA3Transfer(buffer, (u16*)0xd000000, gEEPROMConfig->adrBit + 3);
    // recieve data
    DMA3Transfer((u16*)0xd000000, buffer, 0x44);
    // 4 bit junk
    ptr = buffer + 4;
    data += 3;
    // copy data into output buffer
    for (t1 = 0; t1 < 4; t1++) {
      value = 0;
      for (t2 = 0; t2 < 0x10; t2++) {
        value <<= 1;
        value |= (*ptr++) & 1;
      }
      *(data--) = value;
    }
    return 0;
  }
}

u16 EEPROMWrite(u16 address, const u16* data, u8 unk_3);

u16 EEPROMWrite1(u16 address, const u16* data) { return EEPROMWrite(address, data, 1); }

// reading from EEPROM like a status register
#define REG_EEPROM (*(vu16*)0xd000000)

u16 EEPROMWrite(u16 address, const u16* data, u8 unk_3) {
  u16 buffer[0x52];  // this is one too large?
  vu16 timeout_flag;
  vu16 prev_vcount;       // stack + a6
  vu16 current_vcount;    // stack + a8
  vu32 passed_scanlines;  // stack + ac
  u16 ret;
  vu16* temp2;

  u32 r2;

  u8 i, j;
  u16* ptr;

  if (address >= gEEPROMConfig->adrCount) return EEPROM_OUT_OF_RANGE;

  ptr = (u16*)(0x42 + (uintptr_t)&buffer + (uintptr_t)(gEEPROMConfig->adrBit * 2) + 0x42);
  *ptr-- = 0;
  // copy data into buffer
  for (i = 0; i < 4; i++) {
    r2 = *data++;
    for (j = 0; j < 16; j++) {
      *ptr = r2;
      ptr--;
      r2 = r2 >> 1;
    }
  }

  // copy address to buffer
  for (i = 0; i < gEEPROMConfig->adrBit; i++) {
    *ptr = address;
    ptr--;
    address = address >> 1;
  }
  *ptr-- = 0;
  *ptr-- = 1;
  DMA3Transfer(buffer, (u16*)0xd000000, gEEPROMConfig->adrBit + 0x43);
  ret = 0;
  timeout_flag = 0;
  prev_vcount = REG_VCOUNT;
  passed_scanlines = 0;

  while (1) {
    if (!timeout_flag) {
      if (REG_EEPROM & 1) {
        timeout_flag++;
        if (!unk_3) break;
      }
    }

    current_vcount = REG_VCOUNT;
    if (current_vcount != prev_vcount) {
      if (current_vcount > prev_vcount) {
        passed_scanlines += (current_vcount - prev_vcount);
      } else {
        passed_scanlines += (current_vcount - (prev_vcount - 0xE4));
      }

      if (passed_scanlines > 0x88) {
        if (timeout_flag) break;
        if ((REG_EEPROM & 1)) {
          break;
        }

        ret = 0xc001;
        break;
      }
      prev_vcount = current_vcount;
    }
  }

  return ret;
}

u16 EEPROMCompare(u16 address, const u16* data) {
  u16 ret;

  u16 buffer[4];
  u16* ptr;

  u8 i;

  ret = 0;
  if (address >= gEEPROMConfig->adrCount) {
    return EEPROM_OUT_OF_RANGE;
  }
  EEPROMRead(address, buffer);
  ptr = buffer;
  for (i = 0; i < ARRAY_COUNT(buffer); i++) {
    if (*data++ != *ptr++) {
      ret = EEPROM_COMPARE_FAILED;
      break;
    }
  }
  return ret;
}

u16 EEPROMWrite1_check(u16 address, const u16* data) {
  u8 i;
  u16 ret;

  for (i = 0; i < 3; i++) {
    ret = EEPROMWrite1(address, data);
    if (ret == 0) {
      ret = EEPROMCompare(address, data);
      if (ret == 0) break;
    }
  }
  return ret;
}
