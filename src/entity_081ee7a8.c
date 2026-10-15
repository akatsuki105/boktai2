#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[5404 - 0x18];
} Entity081ee7a8;
static_assert(sizeof(Entity081ee7a8) == 5404);

static Entity081ee7a8* gEntity081ee7a8;  // 0x030001D0

void FUN_081ee2f8(unknown*);
void FUN_081ee328(unknown*);
void FUN_081ee4d0(unknown*);

void (*const PTR_ARRAY_085ae4d4[3])(unknown*) = {
    FUN_081ee2f8,
    FUN_081ee328,
    FUN_081ee4d0,
};  // 0x085AE4D4

INCASM("asm/entity_081ee7a8.inc");
