#include "entity.h"
#include "global.h"

typedef struct Entity08013df0 {
  Entity e;      // 0x0, ENTITY_UNK_9
  void* unk_18;  // 0x18
} Entity08013df0;
static_assert(sizeof(Entity08013df0) == 28);

extern Entity08013df0* gEntity08013df0;  // 0x03002B40

INCASM("asm/entity_08013df0.inc");

NAKED s32 FUN_08013d70(Entity08013df0* p, void* q) { INCFUNC("asm/func/FUN_08013d70.inc"); }

s32 Entity08013df0_Update(Entity08013df0* _) { return 0; }

NAKED s32 Entity08013df0_Destroy(Entity08013df0* p) { INCFUNC("asm/func/Entity08013df0_Destroy.inc"); }

s32 Entity08013df0_Init(Entity08013df0* p) {
  gEntity08013df0 = p;
  p->unk_18 = NULL;
  return 0;
}

NAKED Entity08013df0* Entity08013df0_Create(void) { INCFUNC("asm/func/Entity08013df0_Create.inc"); }
