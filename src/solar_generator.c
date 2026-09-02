#include "entity.h"
#include "global.h"

// パイルドライバーのジェネレータ(1つ分)
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[572 - 0x18];
} Entity080b3898;
static_assert(sizeof(Entity080b3898) == 572);

INCASM("asm/solar_generator.inc");
