#include "entity.h"
#include "global.h"
#include "msgbus.h"

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[80 - sizeof(Entity)];
} EntityD3A9;
static_assert(sizeof(EntityD3A9) == 80);

NAKED void FUN_080c0ae4(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0ae4.inc"); }

NAKED void FUN_080c0b00(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b00.inc"); }

NAKED void FUN_080c0b1c(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b1c.inc"); }

NAKED void FUN_080c0b38(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b38.inc"); }

NAKED void FUN_080c0b54(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b54.inc"); }

NAKED void FUN_080c0b70(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b70.inc"); }

NAKED void FUN_080c0b8c(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0b8c.inc"); }

NAKED void FUN_080c0ba8(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0ba8.inc"); }

NAKED void FUN_080c0bc4(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0bc4.inc"); }

NAKED void FUN_080c0be0(EntityD3A9* p, EntityMsgBox* node, EntityMsg* data) { INCFUNC("asm/func/FUN_080c0be0.inc"); }

NAKED void* EntityD3A9_Update_Internal(EntityD3A9* p) { INCFUNC("asm/func/EntityD3A9_Update_Internal.inc"); }

s32 EntityD3A9_Update(EntityD3A9* p) {
  EntityD3A9_Update_Internal(p);
  return 0;
}

s32 EntityD3A9_Destroy(EntityD3A9* _) { return 0; }

NAKED s32 EntityD3A9_Init(EntityD3A9* p, u32 n) { INCFUNC("asm/func/EntityD3A9_Init.inc"); }

NAKED EntityD3A9* EntityD3A9_Create(u32 n) { INCFUNC("asm/func/EntityD3A9_Create.inc"); }
