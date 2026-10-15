#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2988 - 0x18];
} Entity081f3324;
static_assert(sizeof(Entity081f3324) == 2988);

static Entity081f3324* gEntity081f3324;  // 0x030001F0

const u8 u8_ARRAY_085ae548[4] = {8, 4, 2, 1};  // 0x085AE548

void FUN_081f27d0(Entity081f3324*, unknown*);
void FUN_081f28c0(Entity081f3324*, unknown*);
void FUN_081f29b4(Entity081f3324*, unknown*);
void FUN_081f2af8(Entity081f3324*, unknown*);
void FUN_081f2e68(Entity081f3324*, unknown*);

void (*const PTR_ARRAY_085ae54c[5])(Entity081f3324*, unknown*) = {
    FUN_081f27d0,
    FUN_081f2af8,
    FUN_081f2e68,
    FUN_081f29b4,
    FUN_081f28c0,
};  // 0x085AE54C

INCASM("asm/entity_081f3324.inc");
