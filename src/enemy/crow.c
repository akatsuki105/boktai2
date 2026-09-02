#include "enemy.h"
#include "global.h"

typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048, 0x081466ba
  u8 unk_7c[1728 - 0x7C];  // 0x07C
} Crow;
static_assert(sizeof(Crow) == 1728);

INCASM("asm/crow.inc");
