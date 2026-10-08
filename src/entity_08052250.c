#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[448 - 0x18];
} Entity08052250;
static_assert(sizeof(Entity08052250) == 448);

void FUN_08051dfc(Entity08052250*);
void FUN_08051e30(Entity08052250*);
void FUN_08051e7c(Entity08052250*);
void FUN_08051efc(Entity08052250*);
void FUN_08052084(Entity08052250*);
void FUN_0805212c(Entity08052250*);

void (*const PTR_ARRAY_085ab70c[6])(Entity08052250*) = {
    FUN_08051dfc,
    FUN_08051e30,
    FUN_08051e7c,
    FUN_08051efc,
    FUN_08052084,
    FUN_0805212c,
};  // 0x085AB70C

INCASM("asm/entity_08052250.inc");
