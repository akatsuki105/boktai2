#include "entity.h"
#include "global.h"

typedef struct {
  u8 unk_0[188];  // まだ未解析
} Entity8AF6Entry;
static_assert(sizeof(Entity8AF6Entry) == 188);

typedef struct {
  Entity e;  // 0x00, ENTITY_UNK_9
  u8 count;  // 実際の entries の個数
  u8 unk_19;
  u8 unk_1a[2];
  Entity8AF6Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity8AF6;                  // Entity8AF6 はサイズが可変

extern Entity8AF6* gEntity8AF6;  // 0x03002C4C

INCASM("asm/entity_8af6.inc");
