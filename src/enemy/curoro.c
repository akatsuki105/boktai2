#include "enemy.h"
#include "global.h"

// クロロホルルン
typedef struct {
  Entity2UnkData unk_0;    // 0x000
  SpriteData* sprite;      // 0x044
  UnkStruct52 unk_48;      // 0x048, 0x0813e5ba
  u8 unk_7c[1712 - 0x7C];  // 0x07C
} Curoro;
static_assert(sizeof(Curoro) == 1712);

INCASM("asm/curoro.inc");
