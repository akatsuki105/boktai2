#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  Entity e;  // ENTITY_UNK_2
  Entity2UnkData* head;  // 0x18, Entity2UnkData の双方向リストの先頭, 根拠: FUN_0823b1f8 (末尾に追加) / FUN_0823b258 (先頭から走査)
  Entity2UnkData* tail;  // 0x1C, 同リストの末尾
} EntityB8B9;
static_assert(sizeof(EntityB8B9) == 32);

IWRAM_DATA EntityB8B9* gEntityB8B9 = NULL;  // 0x030016F8

void FUN_0823b1ec(void) { gEntityB8B9 = NULL; }

void FUN_0823b1f8(Entity2UnkData* p) {
  if (gEntityB8B9 != NULL) {
    if (gEntityB8B9->head == NULL) {
      gEntityB8B9->head = p;
      gEntityB8B9->tail = p;
      p->prev = NULL;
      p->next = NULL;
    } else {
      Entity2UnkData* tmp = gEntityB8B9->tail;
      tmp->next = p;
      p->prev = tmp;
      p->next = NULL;
      gEntityB8B9->tail = p;
    }
  }
}

Entity2UnkData* FindUnk0200865c(u16 id) {
  Entity2UnkData* p;
  if (gEntityB8B9 == NULL) {
    return NULL;
  } else {
    for (p = gEntityB8B9->head; p != NULL; p = p->next) {
      if (p->id == id) {
        return p;
      }
    }
    return NULL;
  }
}

Entity2UnkData* FUN_0823b258(Entity2UnkData* p) {
  Entity2UnkData* q;
  if (gEntityB8B9 == NULL) {
    return NULL;
  } else {
    for (q = gEntityB8B9->head; q != NULL; q = q->next) {
      if (q == p) {
        return q;
      }
    }
    return NULL;
  }
}

// リンクリストから指定ノードを削除する
bool32 FUN_0823b284(Entity2UnkData* p) {
  EntityB8B9* mgr = gEntityB8B9;
  Entity2UnkData* prev;
  Entity2UnkData* next;
  if ((mgr == NULL) || (p == NULL) || (FUN_0823b258(p) == NULL)) {
    return FALSE;
  }
  prev = p->prev;
  if (prev == NULL) {
    mgr->head = p->next;
  } else {
    prev->next = p->next;
  }
  next = p->next;
  if (next == NULL) {
    mgr->tail = p->prev;
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

s32 EntityB8B9_Update(EntityB8B9* _) { return 0; }

s32 EntityB8B9_Destroy(EntityB8B9* _) {
  gEntityB8B9 = NULL;
  return 0;
}

s32 EntityB8B9_Init(EntityB8B9* p) {
  gEntityB8B9 = p;
  p->head = NULL, p->tail = NULL;
  return 0;
}

NAKED EntityB8B9* EntityB8B9_Create(void) { INCFUNC("asm/func/EntityB8B9_Create.inc"); }

EntityB8B9* FUN_0823b3ec(void) {
  if (gEntityB8B9 == NULL) {
    return NULL;
  } else {
    return gEntityB8B9;
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

bool32 FUN_0823b474(Entity2UnkData* p, MainSprite* data) {
  p->unk_2c = data;
  return TRUE;
}

bool32 FUN_0823b47c(Entity2UnkData* p, Vec3* unk_30) {
  u16 flag = 4;

  p->unk_2 |= flag;
  p->unk_30 = *unk_30;
  return TRUE;
}

bool32 FUN_0823b490(Entity2UnkData* p, void* unk_24, u8 param_3, u8 param_4, u8 param_5) {
  p->unk_24 = unk_24;
  FUN_08234de8(unk_24, param_3, param_4, param_5);
  return TRUE;
}

NAKED void FUN_0823b4b8(Entity2UnkData* p) { INCFUNC("asm/func/FUN_0823b4b8.inc"); }
