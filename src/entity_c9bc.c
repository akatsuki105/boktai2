#include "entity_c9bc.h"

#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "mover.h"
#include "sprite.h"
#include "vm.h"

COMMON_DATA EntityC9BC* gEntityC9BC = NULL;  // 0x03002B38

void EntityC9BCElem_UpdateState0(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState1(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState2(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState3(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState4(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState5(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState6(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);

void (*const sC9BCElemUpdates[7])(EntityC9BC*, EntityC9BCElem*, u32) = {
    EntityC9BCElem_UpdateState0,
    EntityC9BCElem_UpdateState1,
    EntityC9BCElem_UpdateState2,
    EntityC9BCElem_UpdateState3,
    EntityC9BCElem_UpdateState4,
    EntityC9BCElem_UpdateState5,
    EntityC9BCElem_UpdateState6,
};  // 0x085aa774

EntityC9BC* GetEntityC9BC(void) { return gEntityC9BC; }

NAKED void FUN_0800cb7c(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cb7c.inc"); }

NAKED void FUN_0800cbd0(unknown* param_1, unknown* param_2, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cbd0.inc"); }

void nop_0800cc04(void) {}

NAKED s32 FUN_0800cc08(EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cc08.inc"); }

NAKED s32 FUN_0800ccd0(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800ccd0.inc"); }

NAKED s32 FUN_0800cd70(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cd70.inc"); }

NAKED s32 FUN_0800cdb4(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cdb4.inc"); }

NAKED s32 FUN_0800ce24(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800ce24.inc"); }

NAKED s32 FUN_0800cf30(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/FUN_0800cf30.inc"); }

NAKED void EntityC9BCElem_UpdateState0(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState0.inc"); }

NAKED void EntityC9BCElem_UpdateState1(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState1.inc"); }

NAKED void EntityC9BCElem_UpdateState2(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState2.inc"); }

NAKED void EntityC9BCElem_UpdateState3(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState3.inc"); }

NAKED void EntityC9BCElem_UpdateState4(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState4.inc"); }

NAKED void EntityC9BCElem_UpdateState5(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState5.inc"); }

NAKED void EntityC9BCElem_UpdateState6(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState6.inc"); }

// 要素の state と unk_02 を退避して unk_2a を空にする
void EntityC9BCElem_SaveState(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  elem->unk_2a = 0;
  elem->unk_45 = elem->state;
  elem->unk_46 = elem->unk_02;
}

NAKED void FUN_0800d480(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/FUN_0800d480.inc"); }

NAKED s32 EntityC9BC_Update(EntityC9BC* p) { INCFUNC("asm/func/EntityC9BC_Update.inc"); }

s32 EntityC9BC_Destroy(EntityC9BC* p) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    FUN_0800cb7c(p, elem);
  }

  if (p->elems != NULL) {
    Free(p->elems);
    p->elems = NULL;
  }

  gEntityC9BC = NULL;
  return 0;
}

NAKED s32 EntityC9BC_Init(EntityC9BC* p, u32 _) { INCFUNC("asm/func/EntityC9BC_Init.inc"); }

EntityC9BC* EntityC9BC_Create(u32 val) {
  EntityC9BC* p = GetEntityC9BC();

  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(EntityC9BC));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC9BC_Update, EntityC9BC_Destroy);
    p->count = VM_GetNamedArgValue('m', 4);
    if (EntityC9BC_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
