#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[0xa8 - 0x18];
  SpriteState sprites[36];  // 0xA8, Entity1B24_Destroy
  u8 unk_e28[3984 - 0xe28];
} Entity1B24;
static_assert(sizeof(Entity1B24) == 3984);

INCASM("asm/entity_1b24.inc");
