#include "entity.h"
#include "global.h"

// Entity08052ffc_Init で Video_GetAuxSprite(gfx, SPRITE_OJAMA_BAT); をしているので オジャマバット用のエンティティ (つまり通信対戦系のEntity)
typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[308 - 0x18];
} Entity08052ffc;
static_assert(sizeof(Entity08052ffc) == 308);

INCASM("asm/entity_08052ffc.inc");
