#include "mover.h"

#include "camera.h"
#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Entity e;     // ENTITY_UNK_2
  Mover* head;  // 0x18, Mover の双方向リストの先頭, 根拠: Mover_Link (末尾に追加) / Mover_FindInList (先頭から走査)
  Mover* tail;  // 0x1C, 同リストの末尾
} MoverList;
static_assert(sizeof(MoverList) == 32);

IWRAM_DATA MoverList* gMoverList = NULL;  // 0x030016F8

void MoverList_ClearPtr(void) { gMoverList = NULL; }

void Mover_Link(Mover* p) {
  if (gMoverList != NULL) {
    if (gMoverList->head == NULL) {
      gMoverList->head = p;
      gMoverList->tail = p;
      p->prev = NULL;
      p->next = NULL;
    } else {
      gMoverList->tail->next = p;
      p->prev = gMoverList->tail;
      p->next = NULL;
      gMoverList->tail = p;
    }
  }
}

Mover* Mover_FindByID(u16 id) {
  Mover* p;
  if (gMoverList == NULL) return NULL;

  p = gMoverList->head;
  while (p != NULL) {
    if (p->id == id) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

Mover* Mover_FindInList(Mover* target) {
  Mover* p;
  if (gMoverList == NULL) return NULL;

  p = gMoverList->head;
  while (p != NULL) {
    if (p == target) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

// リンクリストから指定ノードを削除する
bool32 Mover_Unlink(Mover* p) {
  MoverList* mgr = gMoverList;
  Mover* prev;
  Mover* next;
  if ((mgr == NULL) || (p == NULL) || (Mover_FindInList(p) == NULL)) {
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

Mover* Mover_FindByID_Proxy(u16 id) {
  Mover* p = Mover_FindByID(id);
  return p;
}

Mover* Mover_FindInList_Proxy(Mover* p) { return Mover_FindInList(p); }

// スクリプトから ID を受け取り、そのノードの pos.x/y/z をスクリプト側へ返す
s32 Mover_GetPosScripted(void) {
  u8 buf[8];
  Mover* p = Mover_FindByID(VM_GetValue());

  if (p == NULL) {
    FUN_0823167c(buf);
    FUN_0823206c(buf, 0, 0);
    FUN_0823167c(buf);
    FUN_0823206c(buf, 0, 0);
    FUN_0823167c(buf);
    FUN_0823206c(buf, 0, 0);
    return -1;
  }
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, p->pos.x);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, p->pos.y);
  FUN_0823167c(buf);
  FUN_0823206c(buf, 0, p->pos.z);
  return 0;
}

s32 MoverList_Update(MoverList* _) { return 0; }

s32 MoverList_Destroy(MoverList* _) {
  gMoverList = NULL;
  return 0;
}

s32 MoverList_Init(MoverList* p, u32 id, u32 _) {
  gMoverList = p;
  p->head = NULL, p->tail = NULL;
  return 0;
}

MoverList* MoverList_Create(u32 id, u32 _) {
  if (gMoverList == NULL) {
    MoverList* p = CreateEntity(ENTITY_UNK_2, sizeof(MoverList));
    if (p != NULL) {
      SetEntityRoutine(p, MoverList_Update, MoverList_Destroy);
      if (MoverList_Init(p, id, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gMoverList;
}

MoverList* MoverList_Get(void) {
  if (gMoverList == NULL) {
    return NULL;
  } else {
    return gMoverList;
  }
}

// リストに繋ぐところまでやる初期化
s32 Mover_Init(Mover* p, u16 id, Vec3* pos, u32 angle, u32 unk_4, void* owner) {
  p->id = id;
  p->unk_2 = 0;
  p->unk_4 = unk_4;
  p->pos = *pos;
  p->angle = angle;
  p->delta.x = 0, p->delta.y = 0, p->delta.z = 0, p->delta.val = 0x10;
  p->tile = NULL;
  p->unk_20 = 0;
  p->auxSprite = 0;
  p->path = NULL;
  Mover_Link(p);
  p->owner = owner;
  return TRUE;
}

bool32 Mover_SetCollision(Mover* p, MoverTile* tile, u16 sizeX, u16 sizeZ) {
  p->tile = tile;
  FUN_0823280c(tile, &p->pos);
  p->sizeX = sizeX;
  p->sizeZ = sizeZ;
  return TRUE;
}

bool32 FUN_0823b464(Mover* p, u32 unk_20) {
  p->unk_20 = unk_20;
  return TRUE;
}

bool32 Mover_SetAuxSprite(Mover* p, AuxSprite* auxSprite) {
  p->auxSprite = auxSprite;
  return TRUE;
}

bool32 Mover_SetMainSprite(Mover* p, MainSprite* data) {
  p->mainSprite = data;
  return TRUE;
}

bool32 FUN_0823b47c(Mover* p, Vec3* unk_30) {
  u16 flag = 4;

  p->unk_2 |= flag;
  p->unk_30 = *unk_30;
  return TRUE;
}

bool32 Mover_SetPath(Mover* p, void* path, u8 param_3, u8 param_4, u8 param_5) {
  p->path = path;
  Map_InitPathWalker(path, param_3, param_4, param_5);
  return TRUE;
}

// delta の分だけ pos を進めて delta をクリアする
void Mover_ApplyMove(Mover* p) {
  if (p->tile != NULL) {
    switch (gCameraCoords.unk_12) {
      case 0: {
        FUN_0823349c(p->tile, &p->pos, &p->delta, p->sizeX, p->sizeZ, p->unk_4);
        break;
      }
      case 1: {
        p->pos.x += p->delta.x;
        p->pos.y += p->delta.z;
        p->pos.z = 0;
        break;
      }
    }
  } else {
    p->pos.x += p->delta.x;
    p->pos.y += p->delta.y;
    p->pos.z += p->delta.z;
  }
  if (p->auxSprite != NULL) {
    p->auxSprite->pos = p->pos;
  }
  p->delta.x = 0, p->delta.y = 0, p->delta.z = 0;
}
