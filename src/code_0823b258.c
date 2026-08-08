#include "global.h"

Unk_0200865c* FindUnk0200865c(u16 id);

Unk_0200865c* FUN_0823b258(Unk_0200865c* p) {
  Unk_0200865c* q;
  if (PTR_030016f8 == NULL) {
    return NULL;
  } else {
    for (q = PTR_030016f8->unk_18; q != NULL; q = q->next) {
      if (q == p) {
        return q;
      }
    }
    return NULL;
  }
}

// リンクリストから指定ノードを削除する
bool32 FUN_0823b284(Unk_0200865c* p) {
  Entity2* head = PTR_030016f8;
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

void* FUN_0823b378(void) { return NULL; }

void* FUN_0823b37c(void) {
  PTR_030016f8 = NULL;
  return NULL;
}

s32 FUN_0823b388(Entity2* p) {
  PTR_030016f8 = p;
  p->unk_18 = NULL, p->unk_1c = NULL;
  return 0;
}

NAKED void* FUN_0823b39c(void) { INCFUNC("asm/func/FUN_0823b39c.inc"); }

INCASM("asm/code_0823b258.inc");

NAKED void* FUN_0823d85c(void* p) { INCFUNC("asm/func/FUN_0823d85c.inc"); }

void Delay(s32 n) {
  if (n > 0) {
    do {
      n -= 1;
    } while (n != 0);
  }
}

void FUN_0823d904(void) { RtcIoEnable(); }

void FUN_0823d910(void) { RtcIoDisable(); }
