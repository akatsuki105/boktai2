#include "entity.h"
#include "global.h"
#include "msgbus.h"

typedef struct {
  Entity e;             // ENTITY_UNK_3
  EntityMsgBox msgbox;  // 0x18
  u8 unk_4c[88 - 0x4C];
} Entity730A;
static_assert(sizeof(Entity730A) == 88);

NAKED void FUN_08022668(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_08022668.inc"); }

NAKED void FUN_080226a8(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080226a8.inc"); }

NAKED void FUN_08022704(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_08022704.inc"); }

NAKED void FUN_08022770(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_08022770.inc"); }

NAKED void FUN_080227f4(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080227f4.inc"); }

NAKED void FUN_0802284c(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_0802284c.inc"); }

NAKED void FUN_0802285c(Entity730A* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_0802285c.inc"); }

NAKED s32 Entity730A_Update_Helper_08022864(Entity730A* p) { INCFUNC("asm/func/Entity730A_Update_Helper_08022864.inc"); }

NAKED s32 Entity730A_Update(Entity730A* p) { INCFUNC("asm/func/Entity730A_Update.inc"); }

s32 Entity730A_Destroy(Entity730A* p) {
  EntityMsgBus_Unregister(&p->msgbox);
  return 0;
}

s32 Entity730A_Init(Entity730A* p, u32 param) {
  EntityMsgBus_Register(&p->msgbox, param, 7);
  return 0;
}

NAKED Entity730A* Entity730A_Create(u32 param) { INCFUNC("asm/func/Entity730A_Create.inc"); }
