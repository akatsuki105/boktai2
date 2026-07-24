#include "entity.h"

#include "global.h"

void FUN_0823092c(struct Entity* p);

// 0x08230b44
void ResetEntityManager(void) {
  DmaCopy32(3, gDefaultEntityManager, gEntityManager, sizeof gEntityManager);
  return;
}

// 0x08230b68
void AddEntity(struct Entity* p) {
  const u32 n = p->kind;
  struct EntityHeader* h = &gEntityManager[n];
  struct Entity* cur = h->entity;
  if (cur != NULL) {
    cur->prev = p;
  }
  p->next = cur;
  h->entity = p;
}

void RemoveEntity(struct Entity* p) {
  const u32 n = p->kind;
  struct EntityHeader* h = &gEntityManager[n];

  struct Entity* prev = p->prev;
  struct Entity* next = p->next;
  if (prev != NULL) {
    prev->next = next;
  } else {
    h->entity = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

struct Entity* CreateEntity(u32 kind, u32 r1) {
  struct Entity* p = AllocateEntity(r1);
  if (p == NULL) {
    return NULL;
  }
  FUN_082309cc(p, r1);
  p->kind = kind;
  if (gEntityCount == 0) {
    gEntityCount++;
  }
  p->id = gEntityCount;
  gEntityCount++;
  AddEntity(p);
  return p;
}

void SetEntityRoutine(struct Entity* p, EntityFunc fn1, EntityFunc fn2) {
  p->unk_08 = fn1;
  p->unk_0c = fn2;
}

void entity_08230c00(void) {
  s32 i;
  struct EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    if ((u32_030044bc & h->unk_04) == 0) {
      struct Entity* p;
      struct Entity* list = h->entity;
      while (p = list, p != NULL) {
        list = p->next;
        if (!(p->unk_12 & 1)) {
          if (p->unk_08 != NULL) {
            p->unk_08(p);
          }
        } else {
          if (p->unk_0c != NULL) {
            p->unk_0c(p);
          }
          RemoveEntity(p);
          FUN_0823092c(p);
        }
      }
    }
  }
}

u32 KillEntity(struct Entity* p) {
  p->unk_12 |= 1;
  return 0;
}

struct Entity* entity_08230c78(struct Entity* p) {
  struct Entity* e;
  if (p->unk_0c != NULL) {
    e = (p->unk_0c(p));
  } else {
    e = NULL;
  }
  if ((s32)(e) >= 0) {
    p->unk_0c = NULL;
    p->unk_12 |= 1;
  }
  return e;
}

void entity_08230ca4(s32 r0) {
  s32 i;
  struct EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    struct Entity* p;
    struct Entity** cur = &h->entity;
    for (p = *cur; p != NULL; p = p->next) {
      if (p->unk_16 < r0) {
        KillEntity(p);
      }
    }
  }
}

struct Entity* FindEntity(u16 entityID) {
  s32 i;
  struct EntityHeader* h = gEntityManager;
  for (i = 0; i < ENTITY_KINDS; i++, h++) {
    struct Entity* p;
    for (p = h->entity; p != NULL; p = p->next) {
      if (p->id == entityID) {
        return p;
      }
    }
  }
  return NULL;
}

s32 KillEntityIfExists(u16 entityID) {
  struct Entity* p = FindEntity(entityID);
  if (p == NULL) {
    return -1;
  }
  return KillEntity(p);
}
