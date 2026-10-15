#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1452 - 0x18];
} Entity081f0b90;
static_assert(sizeof(Entity081f0b90) == 1452);

static Entity081f0b90* gEntity081f0b90;  // 0x030001E4

void FUN_081f03a0(Entity081f0b90*, unknown*);
void FUN_081f03a4(Entity081f0b90*, unknown*);
void FUN_081f0604(Entity081f0b90*, unknown*);
void FUN_081f0678(Entity081f0b90*, unknown*);

void (*const PTR_ARRAY_085ae518[4])(Entity081f0b90*, unknown*) = {
    FUN_081f03a0,
    FUN_081f0678,
    FUN_081f03a4,
    FUN_081f0604,
};  // 0x085AE518

INCASM("asm/entity_081f0b90.inc");
