#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1696 - 0x18];
} Entity081fa164;
static_assert(sizeof(Entity081fa164) == 1696);

static Entity081fa164* gEntity081fa164;  // 0x03000214

void FUN_081f9dfc(Entity081fa164*, unknown*);
void FUN_081f9e94(Entity081fa164*, unknown*);
void FUN_081f9ee8(Entity081fa164*, unknown*);

void (*const PTR_ARRAY_085ae5f0[3])(Entity081fa164*, unknown*) = {
    FUN_081f9dfc,
    FUN_081f9e94,
    FUN_081f9ee8,
};  // 0x085AE5F0

INCASM("asm/entity_081fa164.inc");
