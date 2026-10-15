#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1520 - 0x18];
} Entity081f4554;
static_assert(sizeof(Entity081f4554) == 1520);

static Entity081f4554* gEntity081f4554;  // 0x030001F4

void FUN_081f3394(Entity081f4554*, unknown*);
void FUN_081f3398(Entity081f4554*, unknown*);
void FUN_081f3508(Entity081f4554*, unknown*);
void FUN_081f3aa0(Entity081f4554*, unknown*);
void FUN_081f3e64(Entity081f4554*, unknown*);
void FUN_081f4010(Entity081f4554*, unknown*);

void (*const PTR_ARRAY_085ae560[6])(Entity081f4554*, unknown*) = {
    FUN_081f3394,
    FUN_081f3508,
    FUN_081f3aa0,
    FUN_081f3e64,
    FUN_081f4010,
    FUN_081f3398,
};  // 0x085AE560

INCASM("asm/entity_081f4554.inc");
