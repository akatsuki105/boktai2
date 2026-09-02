#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048, 0x08149de6
  u8 unk_7c[1684 - 0x7C];  // 0x07C
} Mimic;
static_assert(sizeof(Mimic) == 1684);

INCASM("asm/mimic.inc");
