#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1776 - 0x18];
} Entity08202cd8;
static_assert(sizeof(Entity08202cd8) == 1776);

INCASM("asm/entity_08202cd8.inc");
