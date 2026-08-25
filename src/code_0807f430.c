#include "global.h"

typedef struct Entity5941 {
  Entity e;  // 0x0, ENTITY_UNK_2
  u8 unk_18[32 - sizeof(Entity)];
} Entity5941;
static_assert(sizeof(Entity5941) == 32);

extern Entity5941* gEntity5941;  // 0x03002BF8

INCASM("asm/code_0807f430.inc");

NAKED void FUN_0807f598(UNK_PTR p) { INCFUNC("asm/func/FUN_0807f598.inc"); }

s32 Entity5941_Update(Entity5941* p) { return 0; }

s32 Entity5941_Destroy(Entity5941* p) {
  gEntity5941 = NULL;
  return 0;
}

NAKED s32 Entity5941_Init(Entity5941* p, UNK_PTR a, UNK_PTR b) { INCFUNC("asm/func/Entity5941_Init.inc"); }

NAKED Entity5941* Entity5941_Create(UNK_PTR a, UNK_PTR b) { INCFUNC("asm/func/Entity5941_Create.inc"); }
