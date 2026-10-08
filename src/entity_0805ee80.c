#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[696 - 0x18];
} Entity0805ee80;
static_assert(sizeof(Entity0805ee80) == 696);

void FUN_0805eb58(Entity0805ee80*, unknown*, s32);
void FUN_0805eb5c(Entity0805ee80*, unknown*, s32);
void FUN_0805ebf4(Entity0805ee80*, unknown*, s32);
void FUN_0805ec20(Entity0805ee80*, unknown*, s32);
void FUN_0805ecb4(Entity0805ee80*, unknown*, s32);
void FUN_0805ed84(Entity0805ee80*, unknown*, s32);

void (*const PTR_ARRAY_085aba70[6])(Entity0805ee80*, unknown*, s32) = {
    FUN_0805eb58,
    FUN_0805eb5c,
    FUN_0805ebf4,
    FUN_0805ec20,
    FUN_0805ecb4,
    FUN_0805ed84,
};  // 0x085ABA70

INCASM("asm/entity_0805ee80.inc");
