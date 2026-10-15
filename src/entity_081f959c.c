#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1564 - 0x18];
} Entity081f959c;
static_assert(sizeof(Entity081f959c) == 1564);

static Entity081f959c* gEntity081f959c;  // 0x0300020C

void FUN_081f8d0c(Entity081f959c*, unknown*);
void FUN_081f8d10(Entity081f959c*, unknown*);
void FUN_081f8eb0(Entity081f959c*, unknown*);
void FUN_081f90e0(Entity081f959c*, unknown*);

void (*const PTR_ARRAY_085ae5d0[4])(Entity081f959c*, unknown*) = {
    FUN_081f8d0c,
    FUN_081f8d10,
    FUN_081f8eb0,
    FUN_081f90e0,
};  // 0x085AE5D0

INCASM("asm/entity_081f959c.inc");
