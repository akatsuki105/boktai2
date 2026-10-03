#include "entity.h"
#include "global.h"

// SPRITE_OJAMA_BAT を使うのでオジャマバット用のエンティティ (つまりクロスオーバーのEntity)
typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[308 - 0x18];
} Entity08052ffc;
static_assert(sizeof(Entity08052ffc) == 308);

const u8 u8_ARRAY_085ab73c[4] = {26, 29, 18, 33};  // 0x085AB73C

const u16 u16_ARRAY_085ab740[4] = {0x760, 0x800, 0x8A0, 0x800};  // 0x085AB740

INCASM("asm/entity_08052ffc.inc");
