#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[3020 - 0x18];
} Entity081f1770;
static_assert(sizeof(Entity081f1770) == 3020);

static Entity081f1770* gEntity081f1770;  // 0x030001E8

void FUN_081f0be8(Entity081f1770*, unknown*);
void FUN_081f0c3c(Entity081f1770*, unknown*);
void FUN_081f12cc(Entity081f1770*, unknown*);
void FUN_081f1428(Entity081f1770*, unknown*);

void (*const PTR_ARRAY_085ae528[4])(Entity081f1770*, unknown*) = {
    FUN_081f0be8,
    FUN_081f0c3c,
    FUN_081f12cc,
    FUN_081f1428,
};  // 0x085AE528

INCASM("asm/entity_081f1770.inc");
