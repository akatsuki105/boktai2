#ifndef GUARD_GBA_EEPROM_H
#define GUARD_GBA_EEPROM_H

#include "gba/types.h"

typedef u16 eepromAdr;  // EEPROM address

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
 * @param eeprom_KbitSize 4: 4096bits(512Byte), 0x40: 65536bits(8KB)
 * @return 0 is normal end, non-zero is an argument error
 */
u16 IdentifyEeprom(u16 eeprom_KbitSize);
u16 EEPROMRead(eepromAdr address, u16* data);                   // Read 8 bytes
u16 EEPROMCompare(eepromAdr address, const u16* data);          // Verify 8 bytes
u16 EEPROMWrite0_8k_Check(eepromAdr address, const u16* data);  // Write 8 bytes

#endif  // GUARD_GBA_EEPROM_H
