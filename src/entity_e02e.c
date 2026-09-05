#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[0x78 - 0x18];
  SpriteState sprites[47];  // 0x0078, EntityE02E_Destroy
  u8 unk_1218[5276 - 0x1218];
} EntityE02E;
static_assert(sizeof(EntityE02E) == 5276);

INCASM("asm/entity_e02e.inc");
