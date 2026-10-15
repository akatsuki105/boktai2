#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1696 - 0x18];
} Entity081ee2a0;
static_assert(sizeof(Entity081ee2a0) == 1696);

static Entity081ee2a0* gEntity081ee2a0;  // 0x030001CC

void FUN_081edd1c(Entity081ee2a0*, unknown*);
void FUN_081eddb0(Entity081ee2a0*, unknown*);
void FUN_081ee02c(Entity081ee2a0*, unknown*);

void (*const PTR_ARRAY_085ae4c8[3])(Entity081ee2a0*, unknown*) = {
    FUN_081edd1c,
    FUN_081eddb0,
    FUN_081ee02c,
};  // 0x085AE4C8

INCASM("asm/entity_081ee2a0.inc");
