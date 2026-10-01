#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_12
  u8 unk_18[328 - 0x18];
} Entity4D4D;
static_assert(sizeof(Entity4D4D) == 328);

NAKED void FUN_0800f9b4(Entity4D4D* p, unknown* data) { INCFUNC("asm/func/FUN_0800f9b4.inc"); }

NAKED s32 Entity4D4D_Update(Entity4D4D* p) { INCFUNC("asm/func/Entity4D4D_Update.inc"); }

s32 Entity4D4D_Destroy(Entity4D4D* p) { return 0; }

NAKED s32 Entity4D4D_Init(Entity4D4D* p, u16 val) { INCFUNC("asm/func/Entity4D4D_Init.inc"); }

Entity4D4D* Entity4D4D_Create(u32 val) {
  Entity4D4D* p = CreateEntity(ENTITY_UNK_12, sizeof(Entity4D4D));

  if (p != NULL) {
    SetEntityRoutine(p, Entity4D4D_Update, Entity4D4D_Destroy);
    if (Entity4D4D_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
