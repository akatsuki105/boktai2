#include "global.h"

INCBIN(".rodata", "data/rodata.bin");   // ./tmp/bin.sh ./baserom.gba 0x085aa6b8 0x085abab4 ./data/rodata.bin
INCBIN(".rodata", "data/rodata2.bin");  // ./tmp/bin.sh ./baserom.gba 0x085abab4 0x085abfc8 ./data/rodata2.bin
INCBIN(".rodata", "data/rodata3.bin");  // ./tmp/bin.sh ./baserom.gba 0x085abfc8 0x085af0ec ./data/rodata3.bin
