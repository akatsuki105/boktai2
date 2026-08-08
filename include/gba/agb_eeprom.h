#ifndef GUARD_GBA_EEPROM_H
#define GUARD_GBA_EEPROM_H

#include "gba/types.h"

// error codes
#define EEPROM_OUT_OF_RANGE 0x80FF
#define EEPROM_COMPARE_FAILED 0x8000
#define EEPROM_UNSUPPORTED_TYPE 0x8080

typedef struct eepromTypeTag {
  u32 size;       // Byte size
  u16 adrCount;   // Total number of addresses
  u16 agbWait;    // Read/write wait value of AGB game pak bus (ROM2 area)
                  //   (Used inside the library)
  u8 adrBit;      // Number of address bits at DMA transfer time
  u8 padding[3];  // Padding for alignment
} eepromType;

extern const eepromType* gEEPROMConfig;

/**
 * selects EEPROM type
 * selects 512byte on invalid argument
 *
 * @param unk_1 4 for 512 byte, 0x40 for 8k
 * @return 1 on invalid argument, 0 otherwise
 */
u16 EEPROMConfigure(u16 unk_1);
u16 EEPROMRead(u16 address, u16* data);
u16 EEPROMCompare(u16 address, const u16* data);
u16 EEPROMWrite0_8k_Check(u16 address, const u16* data);

#endif  // GUARD_GBA_EEPROM_H
