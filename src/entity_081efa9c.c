#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2108 - 0x18];
} Entity081efa9c;
static_assert(sizeof(Entity081efa9c) == 2108);

static Entity081efa9c* gEntity081efa9c;  // 0x030001DC

void FUN_081eeed8(Entity081efa9c*, unknown*);
void FUN_081eef2c(Entity081efa9c*, unknown*);
void FUN_081ef3fc(Entity081efa9c*, unknown*);
void FUN_081ef5ec(Entity081efa9c*, unknown*);

void (*const PTR_ARRAY_085ae4f8[4])(Entity081efa9c*, unknown*) = {
    FUN_081eeed8,
    FUN_081eef2c,
    FUN_081ef3fc,
    FUN_081ef5ec,
};  // 0x085AE4F8

INCASM("asm/entity_081efa9c.inc");
