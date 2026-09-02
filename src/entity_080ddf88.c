#include "entity.h"
#include "global.h"

typedef struct Entity080de11c {
  Entity e;  // 0x0, ENTITY_UNK_9
  u8 unk_18[3300 - 0x18];
} Entity080de11c;
static_assert(sizeof(Entity080de11c) == 3300);

extern Entity080de11c* gEntity080de11c;  // 0x03000174

NAKED void FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

NAKED s32 Entity080de11c_Init(Entity080de11c* p) { INCFUNC("asm/func/Entity080de11c_Init.inc"); }

s32 Entity080de11c_Update(Entity080de11c* p);
s32 Entity080de11c_Destroy(Entity080de11c* p);

Entity080de11c* Entity080de11c_Create(void) {
  Entity080de11c* p;
  if (gEntity080de11c == NULL) {
    p = CreateEntity(ENTITY_UNK_9, 3300);
    if (p != NULL) {
      SetEntityRoutine(p, Entity080de11c_Update, Entity080de11c_Destroy);
      if (Entity080de11c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080de11c;
}

void FUN_080de168(void) { gEntity080de11c = NULL; }

INCASM("asm/code_080ddf88.inc");
