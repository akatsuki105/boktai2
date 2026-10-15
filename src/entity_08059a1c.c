#include "entity.h"
#include "global.h"

// Duneyrr関係
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[2752 - 0x18];
} Entity08059a1c;
static_assert(sizeof(Entity08059a1c) == 2752);

void FUN_080595a4(Entity08059a1c*, unknown*, s32);
void FUN_080595a8(Entity08059a1c*, unknown*, s32);
void FUN_0805965c(Entity08059a1c*, unknown*, s32);
void FUN_08059804(Entity08059a1c*, unknown*, s32);

// Entity08059a1c_Update が引く
void (*const PTR_ARRAY_085ab9dc[4])(Entity08059a1c*, unknown*, s32) = {
    FUN_080595a4,
    FUN_080595a8,
    FUN_0805965c,
    FUN_08059804,
};  // 0x085AB9DC

INCASM("asm/entity_08059a1c.inc");
