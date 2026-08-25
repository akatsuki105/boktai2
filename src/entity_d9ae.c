#include "global.h"

typedef struct EntityD9AE {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[116 - 0x18];
} EntityD9AE;
static_assert(sizeof(EntityD9AE) == 116);

extern EntityD9AE* gEntityD9AE;  // 0x03000020

void FUN_08003008(void) { gEntityD9AE = NULL; }

INCASM("asm/entity_d9ae.inc");

INCBIN(".rodata", "data/entity_d9ae.bin");  // ./tmp/bin.sh ./baserom.gba 0x085aa650 0x085aa66c ./data/entity_d9ae.bin
