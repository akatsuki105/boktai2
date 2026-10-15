#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1932 - 0x18];
} Entity081f0298;
static_assert(sizeof(Entity081f0298) == 1932);

static Entity081f0298* gEntity081f0298;  // 0x030001E0

const u8 u8_ARRAY_085ae508[4] = {8, 4, 2, 1};  // 0x085AE508

void FUN_081efb94(Entity081f0298*, unknown*);
void FUN_081efc20(Entity081f0298*, unknown*);
void FUN_081efd78(Entity081f0298*, unknown*);

void (*const PTR_ARRAY_085ae50c[3])(Entity081f0298*, unknown*) = {
    FUN_081efb94,
    FUN_081efd78,
    FUN_081efc20,
};  // 0x085AE50C

INCASM("asm/entity_081f0298.inc");
