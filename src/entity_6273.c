#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[32 - 0x18];
} Entity6273;
static_assert(sizeof(Entity6273) == 32);

IWRAM_DATA Entity6273* gEntity6273 = NULL;  // 0x030000CC

INCASM("asm/entity_6273.inc");
