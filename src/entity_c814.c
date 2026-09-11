#include "entity.h"
#include "global.h"

// 不使用?
typedef struct {
  Entity e;               // 0x0, ENTITY_UNK_8
  u16 unk_18;             // 0x18
  Entity2UnkData unk_1c;  // 0x1C
  u8 unk_60[220 - 0x60];
} EntityC814;
static_assert(sizeof(EntityC814) == 220);

INCASM("asm/entity_c814.inc");
