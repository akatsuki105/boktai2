#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1752 - 0x18];
} Entity081ea820;
static_assert(sizeof(Entity081ea820) == 1752);

static Entity081ea820* gEntity081ea820;  // 0x030001BC

void FUN_081ea17c(Entity081ea820*, unknown*);
void FUN_081ea268(Entity081ea820*, unknown*);
void FUN_081ea44c(Entity081ea820*, unknown*);

// Entity081ea820_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae46c[3])(Entity081ea820*, unknown*) = {
    FUN_081ea17c,
    FUN_081ea268,
    FUN_081ea44c,
};  // 0x085AE46C

INCASM("asm/entity_081ea820.inc");
