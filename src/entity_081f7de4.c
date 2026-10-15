#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[372 - 0x18];
} Entity081f7de4;
static_assert(sizeof(Entity081f7de4) == 372);

static Entity081f7de4* gEntity081f7de4;  // 0x03000204

void FUN_081f7a14(Entity081f7de4*, unknown*);
void FUN_081f7a18(Entity081f7de4*, unknown*);
void FUN_081f7b5c(Entity081f7de4*, unknown*);

void (*const PTR_ARRAY_085ae5b4[3])(Entity081f7de4*, unknown*) = {
    FUN_081f7a14,
    FUN_081f7a18,
    FUN_081f7b5c,
};  // 0x085AE5B4

INCASM("asm/entity_081f7de4.inc");
