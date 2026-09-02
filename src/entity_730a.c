#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;            // ENTITY_UNK_3
  UnkStruct52 unk_18;  // 0x18
  u8 unk_4c[88 - 0x4C];
} Entity730A;
static_assert(sizeof(Entity730A) == 88);

INCASM("asm/entity_730a.inc");

s32 Entity730A_Destroy(Entity730A* p) {
  FUN_08022428(&p->unk_18);
  return 0;
}

s32 Entity730A_Init(Entity730A* p, u32 param) {
  FUN_080223f4(&p->unk_18, param, 7);
  return 0;
}

NAKED Entity730A* Entity730A_Create(u32 param) { INCFUNC("asm/func/Entity730A_Create.inc"); }
