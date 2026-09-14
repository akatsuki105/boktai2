#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[52 - 0x18];
} Entity6978;
static_assert(sizeof(Entity6978) == 52);

COMMON_DATA Entity6978* gEntity6978 = NULL;  // 0x03002B30

INCASM("asm/entity_6978.inc");

NAKED s32 Entity6978_Update(Entity6978* p) { INCFUNC("asm/func/Entity6978_Update.inc"); }

NAKED s32 Entity6978_Destroy(Entity6978* p) { INCFUNC("asm/func/Entity6978_Destroy.inc"); }

NAKED s32 Entity6978_Init(Entity6978* p, u16 id) { INCFUNC("asm/func/Entity6978_Init.inc"); }

Entity6978* Entity6978_Create(u32 id) {
  Entity6978* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity6978));
  if (p != NULL) {
    SetEntityRoutine(p, Entity6978_Update, Entity6978_Destroy);
    if (Entity6978_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
