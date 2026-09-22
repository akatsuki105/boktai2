#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[260 - 0x18];
} Entity4B15;
static_assert(sizeof(Entity4B15) == 260);

IWRAM_DATA Entity4B15* gEntity4B15 = NULL;  // 0x03000090

// まだ　.text 部分の切り出しはしてない
