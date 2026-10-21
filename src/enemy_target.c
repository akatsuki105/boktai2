#include "enemy_target.h"

#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "player.h"

typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u32 unk_18;         // 0x18, EnemyTargetManager_Clear が 0 でクリアする
  s32 count;          // 0x1C, head のリストの登録数, 6件以上だと EnemyTargetManager_Add が登録を拒否する
  u32 unk_20;         // 0x20, EnemyTargetManager_Update が毎フレーム +1. EnemyTargetManager_Sweep は30フレームに1回だけ走る
  u16 unk_24;         // 0x24, EnemyTargetManager_Init が引数をそのまま書く
  u16 unk_26;         // 0x26, 読み手も書き手も未発見, padding?
  EnemyTarget* head;  // 0x28, 単方向リストの先頭
} EnemyTargetManager;
static_assert(sizeof(EnemyTargetManager) == 44);

IWRAM_DATA EnemyTargetManager* gEnemyTargetManager = NULL;  // 0x03000184

bool32 FUN_0808672c(void);

static void FUN_080f8cec(void);

// 敵との紐付けを解いて再登録待ちに戻す
static inline void EnemyTarget_Unlink(EnemyTarget* t) {
  t->flags &= ~ENEMYTARGET_LINKED;
  t->enemy = NULL;
  t->timer = 120;
}

// 登録リストを空にする
void EnemyTargetManager_Clear(void) {
  EnemyTargetManager* p = gEnemyTargetManager;
  if (p != NULL) {
    p->count = 0;
    p->unk_20 = 0;
    p->unk_18 = 0;
    p->head = NULL;
  }
}

bool32 FUN_080f8c2c(EnemyTarget* node) {
  if (node->flags & ENEMYTARGET_LINKED) return FALSE;
  if (node->timer != 0) return FALSE;
  if (node->kindMask == 1) {
    if (!FUN_0808672c()) {
      return FALSE;
    }
  }
  return TRUE;
}

// ノードをリストの先頭につなぐ, 6件以上か既に入っていれば拒否する
bool32 EnemyTargetManager_Add(EnemyTarget* node, Mover* owner, s32 kindMask) {
  EnemyTargetManager* p = gEnemyTargetManager;
  EnemyTarget* cur;

  if (p == NULL || p->count > 5) {
    return FALSE;
  }

  cur = p->head;
  while (cur != NULL) {
    if (cur == node) {
      return FALSE;
    }
    cur = cur->next;
  }

  node->owner = owner;
  node->kindMask = kindMask;
  node->flags = ENEMYTARGET_REGISTERED;
  node->timer = 0;
  node->enemy = NULL;
  node->next = p->head;
  p->head = node;
  p->count++;
  FUN_080f8cec();
  return TRUE;
}

// 登録リストからノードを外す
void EnemyTargetManager_Remove(EnemyTarget* node) {
  EnemyTargetManager* p = gEnemyTargetManager;

  if (p != NULL) {
    EnemyTarget* cur = p->head;
    EnemyTarget* prev = NULL;

    while (cur != NULL) {
      if (cur == node) {
        if (prev == NULL) {
          p->head = cur->next;
        } else {
          prev->next = cur->next;
        }
        p->count--;
        return;
      }
      prev = cur;
      cur = cur->next;
    }
  }
}

static void FUN_080f8cec(void) {}

EnemyTarget* EnemyTargetManager_FindByKind(u32 kindMask) {
  EnemyTargetManager* p = gEnemyTargetManager;
  EnemyTarget* node;

  if (p == NULL) return NULL;
  node = p->head;
  if (node != NULL) {
    do {
      if (node->kindMask == kindMask) {
        return node;
      }
      node = node->next;
    } while (node != NULL);
  }
  return NULL;
}

bool32 FUN_080f8d20(EnemyTarget* node) {
  EnemyTargetManager* p = gEnemyTargetManager;
  EnemyTarget* cur;

  if (p == NULL || node == NULL) return FALSE;
  cur = p->head;
  if (cur != NULL) {
    do {
      if ((cur->flags & ENEMYTARGET_REGISTERED) != 0) {
        if (cur == node) {
          return TRUE;
        }
      }
      cur = cur->next;
    } while (cur != NULL);
  }
  return FALSE;
}

Mover* EnemyTargetManager_FindOwnerByID(u16 id) {
  EnemyTargetManager* p = gEnemyTargetManager;
  EnemyTarget* cur;

  if (p == NULL || id == 0) return NULL;
  cur = p->head;
  if (cur != NULL) {
    do {
      if ((cur->flags & ENEMYTARGET_REGISTERED) != 0) {
        if (cur->owner->id == id) {
          return cur->owner;
        }
      }
      cur = cur->next;
    } while (cur != NULL);
  }
  return NULL;
}

// 30フレームに1回, 敵が死んだか活動停止したノードの紐付けを解いて再登録待ちにする
void EnemyTargetManager_Sweep(void) {
  EnemyTargetManager* mgr = gEnemyTargetManager;
  EnemyTarget* t;

  if (mgr == NULL) {
    return;
  }
  if (Mod(mgr->unk_20, 30) != 0) {
    return;
  }

  t = mgr->head;
  while (t != NULL) {
    if ((t->flags & ENEMYTARGET_REGISTERED) && (t->flags & ENEMYTARGET_LINKED)) {
      Enemy* e = t->enemy;

      if (e == NULL || Enemy_IsDead(e) || Enemy_TestFlag(e, ENEFLAG_UNK_0 | ENEFLAG_UNK_1)) {
        EnemyTarget_Unlink(t);
        continue;
      }
      if (Enemy_GetFlag3(e, ENEFLAG3_UNK_12) == 0) {
        EnemyTarget_Unlink(t);
      }
    }
    t = t->next;
  }
}

// ノードと敵の紐付けを解除し、再登録までの待ち時間を置く
void EnemyTargetManager_Release(EnemyTarget* node) {
  EnemyTargetManager* p = gEnemyTargetManager;

  if ((p != NULL) && (node != NULL)) {
    EnemyTarget* cur = p->head;

    while (cur != NULL) {
      if ((cur == node) && (cur->flags & ENEMYTARGET_REGISTERED)) {
        cur->flags &= ~ENEMYTARGET_LINKED;
        cur->enemy = NULL;
        cur->timer = 240;
        FUN_080f8cec();
        return;
      }
      cur = cur->next;
    }
  }
}

// owner->unk_4 のプレイヤーについて, kind 0 なら goodCondID が param と一致するか, kind 1 なら unk_20 のビットが立っているかを返す
bool32 FUN_080f8e84(Mover* owner, s32 kind, u32 param) {
  s32 n = 0;
  Player* player;

  switch (owner->unk_4) {
    case 0: {
      break;
    }
    case 1: {
      n = 1;
      break;
    }
    case 2: {
      n = 2;
      break;
    }
    case 3: {
      n = 3;
      break;
    }
    default: {
      return FALSE;
    }
  }

  player = gPlayerPtr[n];
  if (player == NULL) {
    return FALSE;
  }

  if (kind == 0) {
    u16 bound = player->goodCondTimer;
    bool32 ok = FALSE;

    if (bound != 0) {
      if (player->goodCondID == param) {
        ok = TRUE;
      }
    }
    if (ok) {
      return TRUE;
    }
  } else if (kind == 1) {
    if (player->flag20 & param) {
      return TRUE;
    }
  }

  return FALSE;
}

NAKED bool32 EnemyTargetManager_Bind(EnemyTarget* node, Enemy* enemy, unknown* param_3) { INCFUNC("asm/func/EnemyTargetManager_Bind.inc"); }

NAKED EnemyTarget* EnemyTargetManager_Claim(Enemy* p, u8 kindMask) { INCFUNC("asm/func/EnemyTargetManager_Claim.inc"); }

void EnemyTargetManager_TickTimers(void) {
  EnemyTargetManager* p = gEnemyTargetManager;

  if (p != NULL) {
    EnemyTarget* node = p->head;

    while (node != NULL) {
      if (node->timer != 0) {
        node->timer--;
      }
      node = node->next;
    }
  }
}

s32 EnemyTargetManager_Update(EnemyTargetManager* p) {
  EnemyTargetManager_Sweep();
  EnemyTargetManager_TickTimers();
  p->unk_20++;
}

s32 EnemyTargetManager_Destroy(EnemyTargetManager* p) { gEnemyTargetManager = NULL; }

s32 EnemyTargetManager_Init(EnemyTargetManager* p, u16 id) {
  gEnemyTargetManager = p;
  EnemyTargetManager_Clear();
  p->unk_24 = id;
}

// 0xD854
EnemyTargetManager* EnemyTargetManager_Create(u16 id) {
  if (gEnemyTargetManager == NULL) {
    EnemyTargetManager* p = CreateEntity(ENTITY_UNK_8, sizeof(EnemyTargetManager));
    if (p != NULL) {
      SetEntityRoutine(p, EnemyTargetManager_Update, EnemyTargetManager_Destroy);
      if (EnemyTargetManager_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEnemyTargetManager;
}

void EnemyTargetManager_ClearGlobal(void) { gEnemyTargetManager = NULL; }
