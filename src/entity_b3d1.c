#include "entity.h"
#include "global.h"

typedef struct EntityB3D1 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1468 - 0x18];
} EntityB3D1;
static_assert(sizeof(EntityB3D1) == 1468);

extern EntityB3D1* gEntityB3D1;  // 0x03000158

INCASM("asm/entity_b3d1.inc");
