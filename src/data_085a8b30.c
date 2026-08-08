#include "global.h"

const char EEPROM_V124[] = "EEPROM_V124";

const eepromType gEEPROMConfig512 = {
    0x00000200,                         // Total byte size
    0x0040,                             // Total number of addresses
    WAITCNT_WS2_N_8 | WAITCNT_WS2_S_8,  // 8/8 wait
    6,                                  // Number of address bits at DMA transfer time
};

const eepromType gEEPROMConfig8k = {
    0x00002000,                         // Total byte size
    0x0400,                             // Total number of addresses
    WAITCNT_WS2_N_8 | WAITCNT_WS2_S_8,  // 8/8 wait
    14,                                 // Number of address bits at DMA transfer time
};

const eepromType* const sEepromConfigArray[7] = {
    (const eepromType*)&gEEPROMConfig, &gEEPROMConfig512, &gEEPROMConfig8k, (const eepromType*)&gEEPROMConfig, (const eepromType*)&gEEPROMConfig, (const eepromType*)&gEEPROMConfig, (const eepromType*)&gEEPROMConfig,
};
