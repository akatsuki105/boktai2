#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[608 - 0x18];
} Entity081eeb28;
static_assert(sizeof(Entity081eeb28) == 608);

static Entity081eeb28* gEntity081eeb28;  // 0x030001D4

void FUN_081ee800(Entity081eeb28*, unknown*);
void FUN_081ee858(Entity081eeb28*, unknown*);
void FUN_081ee974(Entity081eeb28*, unknown*);

void (*const PTR_ARRAY_085ae4e0[3])(Entity081eeb28*, unknown*) = {
    FUN_081ee800,
    FUN_081ee858,
    FUN_081ee974,
};  // 0x085AE4E0

INCASM("asm/entity_081eeb28.inc");
