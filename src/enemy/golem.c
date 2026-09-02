#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048, 0x08121992
  u8 unk_7c[1764 - 0x7C];  // 0x07C
} Golem;
static_assert(sizeof(Golem) == 1764);

INCASM("asm/golem.inc");
