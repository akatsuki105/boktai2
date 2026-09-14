#include "entity.h"
#include "global.h"

typedef struct Entity08013b68 {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[32 - 0x18];
} Entity08013b68;
static_assert(sizeof(Entity08013b68) == 32);

extern Entity08013b68* gEntity08013b68;  // 0x03000054

void FUN_08013920(void) { gEntity08013b68 = NULL; }

INCASM("asm/entity_08013b68.inc");
