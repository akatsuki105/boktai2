#include "entity.h"
#include "global.h"

typedef struct {
  u8 unk_0[184];  // まだ未解析
} Entity3117Entry;
static_assert(sizeof(Entity3117Entry) == 184);

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 count;  // 実際の entries の個数
  u8 unk_19;
  u8 unk_1a[2];
  Entity3117Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity3117;

extern Entity3117* gEntity3117;  // 0x03002C48

INCASM("asm/entity_3117.inc");
