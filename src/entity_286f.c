#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1084 - 0x18];
} Entity286F;
static_assert(sizeof(Entity286F) == 1084);

COMMON_DATA Entity286F* gEntity286F = NULL;  // 0x03002B50

INCASM("asm/entity_286f.inc");
