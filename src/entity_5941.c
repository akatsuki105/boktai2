#include "entity.h"
#include "global.h"

typedef struct Entity5941 {
  Entity e;      // 0x0, ENTITY_UNK_2
  void* unk_18;  // 0x18, FUN_0807f598
  void* unk_1c;  // 0x1C
} Entity5941;
static_assert(sizeof(Entity5941) == 32);

extern Entity5941* gEntity5941;  // 0x03002BF8

NAKED unknown* FUN_0807f478(unknown* p) { INCFUNC("asm/func/FUN_0807f478.inc"); }

INCASM("asm/entity_5941.inc");

NAKED void FUN_0807f598(void* p) { INCFUNC("asm/func/FUN_0807f598.inc"); }

s32 Entity5941_Update(Entity5941* p) { return 0; }

s32 Entity5941_Destroy(Entity5941* p) {
  gEntity5941 = NULL;
  return 0;
}

s32 Entity5941_Init(Entity5941* p, void* unused1, void* unused2) {
  p->unk_18 = NULL;
  p->unk_1c = NULL;
  gEntity5941 = p;
  return 0;
}

NAKED Entity5941* Entity5941_Create(void* unused1, void* unused2) { INCFUNC("asm/func/Entity5941_Create.inc"); }
