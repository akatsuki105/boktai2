#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[1832 - 0x18];
} Entity081f73ec;
static_assert(sizeof(Entity081f73ec) == 1832);

static Entity081f73ec* gEntity081f73ec;  // 0x030001FC

void FUN_081f6314(Entity081f73ec*, unknown*);
void FUN_081f6318(Entity081f73ec*, unknown*);
void FUN_081f6368(Entity081f73ec*, unknown*);
void FUN_081f6afc(Entity081f73ec*, unknown*);
void FUN_081f6c78(Entity081f73ec*, unknown*);
void FUN_081f6d14(Entity081f73ec*, unknown*);
void FUN_081f710c(Entity081f73ec*, unknown*);

void (*const PTR_ARRAY_085ae588[7])(Entity081f73ec*, unknown*) = {
    FUN_081f6314,
    FUN_081f6d14,
    FUN_081f710c,
    FUN_081f6afc,
    FUN_081f6c78,
    FUN_081f6368,
    FUN_081f6318,
};  // 0x085AE588

INCASM("asm/entity_081f73ec.inc");
