#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[2396 - 0x18];
} Entity081f8a28;
static_assert(sizeof(Entity081f8a28) == 2396);

static Entity081f8a28* gEntity081f8a28;  // 0x03000208

void FUN_081f8120(Entity081f8a28*, unknown*);
void FUN_081f8124(Entity081f8a28*, unknown*);
void FUN_081f82cc(Entity081f8a28*, unknown*);
void FUN_081f8620(Entity081f8a28*, unknown*);

void (*const PTR_ARRAY_085ae5c0[4])(Entity081f8a28*, unknown*) = {
    FUN_081f8120,
    FUN_081f8124,
    FUN_081f82cc,
    FUN_081f8620,
};  // 0x085AE5C0

INCASM("asm/entity_081f8a28.inc");
