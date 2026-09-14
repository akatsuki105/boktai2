#include "entity.h"
#include "global.h"

typedef struct Entity081d0e20 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[108 - 0x18];
} Entity081d0e20;
static_assert(sizeof(Entity081d0e20) == 108);

extern Entity081d0e20* gEntity081d0e20;  // 0x03000188

INCASM("asm/entity_081d0e20.inc");
