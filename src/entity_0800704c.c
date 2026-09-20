#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[92 - 0x18];
} Entity0800704c;
static_assert(sizeof(Entity0800704c) == 92);

IWRAM_DATA Entity0800704c* gEntity0800704c = NULL;  // 0x0300002C

INCASM("asm/entity_0800704c.inc");
