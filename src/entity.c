#include "entity.h"

#include "global.h"
#include "malloc.h"

void Free(void* p);

// 0x08230b44
void ResetEntityManager(void) {
  DmaCopy32(3, gDefaultEntityManager, gEntityManager, sizeof gEntityManager);
  return;
}

// 0x08230b68
void AddEntity(Entity* p) {
  const u32 n = p->kind;
  EntityHeader* h = &gEntityManager[n];
  Entity* cur = h->entity;
  if (cur != NULL) {
    cur->prev = p;
  }
  p->next = cur;
  h->entity = p;
}

void RemoveEntity(Entity* p) {
  const u32 n = p->kind;
  EntityHeader* h = &gEntityManager[n];

  Entity* prev = p->prev;
  Entity* next = p->next;
  if (prev != NULL) {
    prev->next = next;
  } else {
    h->entity = next;
  }
  if (next != NULL) next->prev = prev;
}

Entity* CreateEntity(u32 kind, s32 bytesize) {
  Entity* p = Malloc(bytesize);
  if (p == NULL) {
    return NULL;
  }
  ClearMemory(p, bytesize);
  p->kind = kind;
  if (gEntityCount == 0) gEntityCount++;
  p->id = gEntityCount;
  gEntityCount++;
  AddEntity(p);
  return p;
}

void SetEntityRoutine(void* entity, void* entity_func_onupdate, void* entity_func_ondestroy) {
  ((Entity*)entity)->onUpdate = (EntityFunc)entity_func_onupdate;
  ((Entity*)entity)->onDestroy = (EntityFunc)entity_func_ondestroy;
}

// Entityをすべて更新する, ゲームの要素はすべて Entity で表されてるっぽいので 実質的な gameloop
void UpdateAllEntities(void) {
  s32 i;
  EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    if ((u32_030044bc & h->unk_04) == 0) {
      Entity* p;
      Entity* list = h->entity;
      while (p = list, p != NULL) {
        list = p->next;
        if (!(p->unk_12 & E_FLAG_DELETE)) {
          if (p->onUpdate != NULL) p->onUpdate(p);
        } else {
          if (p->onDestroy != NULL) p->onDestroy(p);
          RemoveEntity(p);
          Free(p);
        }
      }
    }
  }
}

u32 KillEntity(Entity* p) {
  p->unk_12 |= E_FLAG_DELETE;
  return 0;
}

s32 entity_08230c78(Entity* p) {
  s32 result;
  if (p->onDestroy != NULL) {
    result = p->onDestroy(p);
  } else {
    result = 0;
  }
  if (result >= 0) {
    p->onDestroy = NULL;
    p->unk_12 |= E_FLAG_DELETE;
  }
  return result;
}

void entity_08230ca4(s32 r0) {
  s32 i;
  EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    Entity* p;
    Entity** cur = &h->entity;
    for (p = *cur; p != NULL; p = p->next) {
      if (p->unk_16 < r0) {
        KillEntity(p);
      }
    }
  }
}

Entity* FindEntity(u16 entityID) {
  s32 i;
  EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    Entity* p;
    for (p = h->entity; p != NULL; p = p->next) {
      if (p->id == entityID) {
        return p;
      }
    }
  }
  return NULL;
}

s32 KillEntityIfExists(u16 entityID) {
  Entity* p = FindEntity(entityID);
  if (p == NULL) {
    return -1;
  }
  return KillEntity(p);
}
