#include "global.h"

// TODO: いろんな用途のデータが区別されてないのであとで分ける
IWRAM_DATA u8 u8_03000784[0x030016A0 - 0x03000784] = {};

INCASM("asm/code_08236f18.inc");
