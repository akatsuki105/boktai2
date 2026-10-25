#include "entity.h"
#include "global.h"

typedef struct Entity0805b790 {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2304 - 0x18];
} Entity0805b790;
static_assert(sizeof(Entity0805b790) == 2304);

void FUN_0805b36c(Entity0805b790*, unknown*, s32);
void FUN_0805b4d0(Entity0805b790*, unknown*, s32);
void FUN_0805b640(Entity0805b790*, unknown*, s32);

// Entity0805b790_Update が引く
void (*const PTR_ARRAY_085aba20[3])(Entity0805b790*, unknown*, s32) = {
    FUN_0805b36c,
    FUN_0805b4d0,
    FUN_0805b640,
};  // 0x085ABA20

INCASM("asm/entity_0805b790.inc");
