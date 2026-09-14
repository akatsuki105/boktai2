#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[216 - 0x18];
} EntityEC96;
static_assert(sizeof(EntityEC96) == 216);

INCASM("asm/entity_ec96.inc");

NAKED s32 EntityEC96_Update(EntityEC96* p) { INCFUNC("asm/func/EntityEC96_Update.inc"); }

NAKED s32 EntityEC96_Destroy(EntityEC96* p) { INCFUNC("asm/func/EntityEC96_Destroy.inc"); }

NAKED s32 EntityEC96_Init(EntityEC96* p, u32 id) { INCFUNC("asm/func/EntityEC96_Init.inc"); }

NAKED EntityEC96* EntityEC96_Create(u32 id) { INCFUNC("asm/func/EntityEC96_Create.inc"); }
