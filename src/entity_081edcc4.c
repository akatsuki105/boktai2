#include "entity.h"
#include "global.h"

// 不使用?
typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[468 - 0x18];
} Entity081edcc4;
static_assert(sizeof(Entity081edcc4) == 468);

IWRAM_DATA Entity081edcc4* gEntity081edcc4 = NULL;  // 0x030001C8

INCASM("asm/entity_081edcc4.inc");
