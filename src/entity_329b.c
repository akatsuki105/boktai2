#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[776 - 0x18];
} Entity329B;
static_assert(sizeof(Entity329B) == 776);

IWRAM_DATA Entity329B* gEntity329B = NULL;  // 0x03000048

const u16 u16_ARRAY_085aa810[6] = {
    0x80, 0x2, 0x50, 0x60, 0x20, 0x40,
};  // 0x085aa810

INCASM("asm/entity_329b.inc");
