#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[480 - 0x18];
} Entity080a8ff8;
static_assert(sizeof(Entity080a8ff8) == 480);

INCASM("asm/entity_080a8ff8.inc");

NAKED s32 Entity080a8ff8_Update(Entity080a8ff8* p) { INCFUNC("asm/func/Entity080a8ff8_Update.inc"); }

NAKED s32 Entity080a8ff8_Destroy(Entity080a8ff8* p) { INCFUNC("asm/func/Entity080a8ff8_Destroy.inc"); }

NAKED void FUN_080a8d78(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8d78.inc"); }

NAKED void FUN_080a8dd8(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8dd8.inc"); }

NAKED s32 Entity080a8ff8_Init(Entity080a8ff8* p, void* owner, Vec3* pos, unknown* param_3) { INCFUNC("asm/func/Entity080a8ff8_Init.inc"); }

NAKED Entity080a8ff8* Entity080a8ff8_Create(void* owner, Vec3* pos, unknown* param_3) { INCFUNC("asm/func/Entity080a8ff8_Create.inc"); }
