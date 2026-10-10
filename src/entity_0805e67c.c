#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[5392 - 0x18];
} Entity0805e67c;
static_assert(sizeof(Entity0805e67c) == 5392);

void FUN_0805e04c(Entity0805e67c*, unknown*, s32);
void FUN_0805e050(Entity0805e67c*, unknown*, s32);
void FUN_0805e110(Entity0805e67c*, unknown*, s32);
void FUN_0805e1fc(Entity0805e67c*, unknown*, s32);
void FUN_0805e2fc(Entity0805e67c*, unknown*, s32);

void (*const PTR_ARRAY_085aba5c[5])(Entity0805e67c*, unknown*, s32) = {
    FUN_0805e04c,
    FUN_0805e050,
    FUN_0805e110,
    FUN_0805e1fc,
    FUN_0805e2fc,
};  // 0x085ABA5C

INCASM("asm/entity_0805e67c.inc");
