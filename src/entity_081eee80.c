#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[8248 - 0x18];
} Entity081eee80;
static_assert(sizeof(Entity081eee80) == 8248);

static Entity081eee80* gEntity081eee80;  // 0x030001D8

void FUN_081eeb80(Entity081eee80*, unknown*);
void FUN_081eeb84(Entity081eee80*, unknown*);
void FUN_081eec1c(Entity081eee80*, unknown*);

void (*const PTR_ARRAY_085ae4ec[3])(Entity081eee80*, unknown*) = {
    FUN_081eeb80,
    FUN_081eeb84,
    FUN_081eec1c,
};  // 0x085AE4EC

INCASM("asm/entity_081eee80.inc");
