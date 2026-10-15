#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[2908 - 0x18];
} Entity081f26bc;
static_assert(sizeof(Entity081f26bc) == 2908);

static Entity081f26bc* gEntity081f26bc;  // 0x030001EC

void FUN_081f1940(Entity081f26bc*, unknown*);
void FUN_081f1994(Entity081f26bc*, unknown*);
void FUN_081f1cc8(Entity081f26bc*, unknown*);
void FUN_081f1ffc(Entity081f26bc*, unknown*);

void (*const PTR_ARRAY_085ae538[4])(Entity081f26bc*, unknown*) = {
    FUN_081f1940,
    FUN_081f1994,
    FUN_081f1cc8,
    FUN_081f1ffc,
};  // 0x085AE538

INCASM("asm/entity_081f26bc.inc");
