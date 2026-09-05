#include "entity.h"
#include "global.h"

typedef struct {
  u16 unk_0;  // 0x00
  u8 unk_2[2];
  u16 unk_4;  // 0x04
  u8 unk_6[16 - 0x06];
} Entity794CData;
static_assert(sizeof(Entity794CData) == 16);

typedef struct Entity794C {
  Entity e;  // ENTITY_UNK_5
  u8 unk_18[0x20 - 0x18];
  Entity794CData data[8];  // 0x20, FUN_08240b44
  u8 unk_a0[216 - 0xa0];
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

extern Entity794C* gEntity794C;  // 0x03001700

INCASM("asm/entity_794c.inc");
