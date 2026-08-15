#include "entity_unk.h"
#include "global.h"

void FUN_0823b1ec(void) {
  gEntity2 = NULL;
  return;
}

void FUN_0823b1f8(Unk_0200865c* p) {
  if (gEntity2 != NULL) {
    if (gEntity2->unk_18 == NULL) {
      gEntity2->unk_18 = p;
      gEntity2->unk_1c = p;
      p->prev = NULL;
      p->next = NULL;
    } else {
      Unk_0200865c* tmp = gEntity2->unk_1c;
      tmp->next = p;
      p->prev = tmp;
      p->next = NULL;
      gEntity2->unk_1c = p;
    }
  }
}

Unk_0200865c* FindUnk0200865c(u16 id) {
  Unk_0200865c* p;
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

Unk_0200865c* FUN_0823b258(Unk_0200865c* p) {
  Unk_0200865c* q;
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
bool32 FUN_0823b284(Unk_0200865c* p) {
  Entity2* head = gEntity2;
  Unk_0200865c* prev;
  Unk_0200865c* next;
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

Unk_0200865c* FUN_0823b2d0(u16 id) {
  Unk_0200865c* p = FindUnk0200865c(id);
  return p;
}

Unk_0200865c* FUN_0823b2e0(Unk_0200865c* p) { return FUN_0823b258(p); }

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

INCASM("asm/code_0823b258.inc");
