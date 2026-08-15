#include "entity_unk.h"
#include "global.h"

void FUN_0823b1ec(void) {
  gEntity2 = NULL;
  return;
}

void FUN_0823b1f8(Entity2UnkData* p) {
  if (gEntity2 != NULL) {
    if (gEntity2->unk_18 == NULL) {
      gEntity2->unk_18 = p;
      gEntity2->unk_1c = p;
      p->prev = NULL;
      p->next = NULL;
    } else {
      Entity2UnkData* tmp = gEntity2->unk_1c;
      tmp->next = p;
      p->prev = tmp;
      p->next = NULL;
      gEntity2->unk_1c = p;
    }
  }
}

Entity2UnkData* FindUnk0200865c(u16 id) {
  Entity2UnkData* p;
  if (gEntity2 == NULL) {
    return NULL;
  } else {
    for (p = gEntity2->unk_18; p != NULL; p = p->next) {
      if (p->id == id) {
        return p;
      }
    }
    return NULL;
  }
}

Entity2UnkData* FUN_0823b258(Entity2UnkData* p) {
  Entity2UnkData* q;
  if (gEntity2 == NULL) {
    return NULL;
  } else {
    for (q = gEntity2->unk_18; q != NULL; q = q->next) {
      if (q == p) {
        return q;
      }
    }
    return NULL;
  }
}

// リンクリストから指定ノードを削除する
bool32 FUN_0823b284(Entity2UnkData* p) {
  Entity2* head = gEntity2;
  Entity2UnkData* prev;
  Entity2UnkData* next;
  if ((head == NULL) || (p == NULL) || (FUN_0823b258(p) == NULL)) {
    return FALSE;
  }
  prev = p->prev;
  if (prev == NULL) {
    head->unk_18 = p->next;
  } else {
    prev->next = p->next;
  }
  next = p->next;
  if (next == NULL) {
    head->unk_1c = p->prev;
  } else {
    next->prev = p->prev;
  }
  return TRUE;
}

Entity2UnkData* FUN_0823b2d0(u16 id) {
  Entity2UnkData* p = FindUnk0200865c(id);
  return p;
}

Entity2UnkData* FUN_0823b2e0(Entity2UnkData* p) { return FUN_0823b258(p); }

NAKED s32 FUN_0823b2ec(void) { INCFUNC("asm/func/FUN_0823b2ec.inc"); }

s32 Entity2_Update(Entity2* _) { return 0; }

s32 Entity2_Destroy(Entity2* _) {
  gEntity2 = NULL;
  return 0;
}

s32 Entity2_Init(Entity2* p) {
  gEntity2 = p;
  p->unk_18 = NULL, p->unk_1c = NULL;
  return 0;
}

NAKED Entity2* Entity2_Create(void) { INCFUNC("asm/func/Entity2_Create.inc"); }

Entity2* FUN_0823b3ec(void) {
  if (gEntity2 == NULL) {
    return NULL;
  } else {
    return gEntity2;
  }
}

NAKED s32 FUN_0823b400(Entity2UnkData* p, u32 id, u32* unk_8, u32 unk_5, u32 unk_4, void* owner) { INCFUNC("asm/func/FUN_0823b400.inc"); }

NAKED bool32 FUN_0823b43c(Entity2UnkData* p, u32 unk_18, u16 unk_1c, u16 unk_1e) { INCFUNC("asm/func/FUN_0823b43c.inc"); }

bool32 FUN_0823b464(Entity2UnkData* p, u32 unk_20) {
  p->unk_20 = unk_20;
  return TRUE;
}

bool32 FUN_0823b46c(Entity2UnkData* p, u32 unk_28) {
  p->unk_28 = unk_28;
  return TRUE;
}

bool32 FUN_0823b474(Entity2UnkData* p, u32 unk_2c) {
  p->unk_2c = unk_2c;
  return TRUE;
}

NAKED bool32 FUN_0823b47c(Entity2UnkData* p, u32* unk_30_and_unk_34) { INCFUNC("asm/func/FUN_0823b47c.inc"); }

bool32 FUN_0823b490(Entity2UnkData* p, void* unk_24, u8 param_3, u8 param_4, u8 param_5) {
  p->unk_24 = unk_24;
  FUN_08234de8(unk_24, param_3, param_4, param_5);
  return TRUE;
}

NAKED void FUN_0823b4b8(Entity2UnkData* p) { INCFUNC("asm/func/FUN_0823b4b8.inc"); }
