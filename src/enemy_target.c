#include "enemy_target.h"

#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"

typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u32 unk_18;         // 0x18
  s32 count;          // 0x1C, head のリストの登録数 (6件まで登録できる)
  u32 frameCounter;   // 0x20
  u16 id;             // 0x24
  EnemyTarget* head;  // 0x28
} EnemyTargetManager;
static_assert(sizeof(EnemyTargetManager) == 44);

static EnemyTargetManager* sEnemyTargetManager;  // 0x03000184

bool32 FUN_0808672c(void);
void FUN_080f8bb8(Mover* owner);
bool8 FUN_080e4384(Enemy* p, Vec3* pos);
s32 FUN_080e3f50(Enemy* p, WorldPos* pos, WorldPos* dst);
s32 FUN_082340c8(Vec3* pos, Vec3* dir, s32 count, s32 limit);
bool32 FUN_080865dc(Vec3* out);
bool32 FUN_080f8e84(Mover* owner, s32 kind, u32 param);

static void nop_080f8cec(void);

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// 敵との紐付けを解いて再登録待ちに戻す
static inline void EnemyTarget_Unlink(EnemyTarget* t) {
  t->flags &= ~ENEMYTARGET_LINKED;
  t->enemy = NULL;
  t->cooldown = SECOND(2);
}

// 登録リストを空にする
void EnemyTargetManager_Clear(void) {
  EnemyTargetManager* p = sEnemyTargetManager;
  if (p != NULL) {
    p->count = 0;
    p->frameCounter = 0;
    p->unk_18 = 0;
    p->head = NULL;
  }
}

bool8 FUN_080f8c2c(EnemyTarget* node) {
  if (node->flags & ENEMYTARGET_LINKED) return FALSE;
  if (node->cooldown != 0) return FALSE;
  if (node->kindMask == 1) {
    if (!FUN_0808672c()) {
      return FALSE;
    }
  }
  return TRUE;
}

// ノードをリストの先頭につなぐ, 6件以上か既に入っていれば拒否する
bool32 EnemyTargetManager_Add(EnemyTarget* node, Mover* owner, s32 kindMask) {
  EnemyTargetManager* p = sEnemyTargetManager;
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
  node->cooldown = 0;
  node->enemy = NULL;
  node->next = p->head;
  p->head = node;
  p->count++;
  nop_080f8cec();
  return TRUE;
}

// 登録リストからノードを外す
void EnemyTargetManager_Remove(EnemyTarget* node) {
  EnemyTargetManager* p = sEnemyTargetManager;

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

static void nop_080f8cec(void) {}

EnemyTarget* EnemyTargetManager_FindByKind(u32 kindMask) {
  EnemyTargetManager* p = sEnemyTargetManager;
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

bool8 FUN_080f8d20(EnemyTarget* node) {
  EnemyTargetManager* p = sEnemyTargetManager;
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
  EnemyTargetManager* p = sEnemyTargetManager;
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
  EnemyTargetManager* mgr = sEnemyTargetManager;
  EnemyTarget* t;

  if (mgr == NULL) {
    return;
  }
  if (Mod(mgr->frameCounter, 30) != 0) {
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
  EnemyTargetManager* p = sEnemyTargetManager;

  if ((p != NULL) && (node != NULL)) {
    EnemyTarget* cur = p->head;

    while (cur != NULL) {
      if ((cur == node) && (cur->flags & ENEMYTARGET_REGISTERED)) {
        cur->flags &= ~ENEMYTARGET_LINKED;
        cur->enemy = NULL;
        cur->cooldown = SECOND(4);
        nop_080f8cec();
        return;
      }
      cur = cur->next;
    }
  }
}

// owner->unk_4 のプレイヤーについて, kind 0 なら goodCondID が param と一致するか, kind 1 なら frameCounter のビットが立っているかを返す
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

// 敵から的 (node->owner) が見えるかを調べて Bind する, kindMask 1/4 は Mover を写して2回まで位置をずらして試す, 2 は 1P の状態も確かめる
// 下書きの段階で 862/1274 命令, 見えるかの判定 (EnemyTarget_CanSee) は原典で2か所に展開されている, FUN_080e4444 と同じ判定
NON_MATCH bool8 EnemyTargetManager_Bind(EnemyTarget* node, Enemy* enemy, s32* best) {
#ifdef NONMATCHING_C
  switch (node->kindMask) {
    case 1:
    case 4: {
      Mover m = *node->owner;
      s32 i;

      for (i = 0; i < 2; i++) {
        {
          Vec3 d;
          s32 distSq;
          bool32 ok = FALSE;
          bool32 dimKnown = TRUE;

          d.x = m.pos.x - enemy->mover.pos.x;
          d.y = m.pos.y - enemy->mover.pos.y;
          d.z = m.pos.z - enemy->mover.pos.z;
          distSq = d.x * d.x + d.z * d.z;
          if (FUN_080e4384(enemy, &m.pos)) {
            *best = distSq;
            enemy->unk_1f8 = (node->kindMask & 6) ? 1 : 0;
            ok = TRUE;
          } else {
            s32 diff = ArcTan2_8(d.x, d.z) - enemy->mover.angle;

            if (diff > 0x80) {
              diff -= 0x100;
            } else if (diff < -0x80) {
              diff += 0x100;
            }
            if (diff < 0) {
              diff = -diff;
            }
            if (diff <= enemy->unk_1fd) {
              s32 limit;
              u32 near;
              bool32 dim;

              if (node->kindMask == 2) {
                if (gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) {
                  dim = (u8)FUN_080f8e84(&m, 1, 0x10000);
                } else {
                  dim = (u8)FUN_080f8e84(&m, 1, 0x10000) || !(gStat->mapFlags & MPF_BRIGHT);
                }
              } else if (!(gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14))) {
                dim = !(gStat->mapFlags & MPF_BRIGHT);
              } else {
                dimKnown = FALSE;
              }
              if (!dimKnown) {
              } else if (dim) {
                limit = (s32)enemy->range0Sq / 2;
                near = limit;
                if (!(enemy->flags5 & ENEFLAG5_UNK_3)) {
                  near = Div(limit * 7, 10);
                }
              } else {
                limit = enemy->range0Sq;
                near = enemy->unk_1e8;
              }

              if (dimKnown && distSq <= limit) {
                s32 step = FUN_080e3f50(enemy, &enemy->mover.pos, &m.pos);

                if (step >= 0) {
                  s32 tile = GetCollisionTileIdx(&m.pos);
                  s32 cur = enemy->unk_256;
                  s32 height = (s8)(enemy->mover.pos.y >> 8);
                  bool32 adjacent = FALSE;

                  if (tile - 1 == cur || tile == cur + gCollisionMap->tiledata->width || tile + 1 == cur || tile == cur - gCollisionMap->tiledata->width) {
                    if (((Map_FindTileOverride(tile, 1) != NULL ? &Map_FindTileOverride(tile, 1)->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) == height &&
                        !((Map_FindTileOverride(tile, 1) != NULL ? &Map_FindTileOverride(tile, 1)->tile : &gCollisionMap->tiledata->tiles[tile])->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_UNK_6))) {
                      adjacent = TRUE;
                    }
                  }

                  if (adjacent) {
                    if ((enemy->flags5 & ENEFLAG5_UNK_3) || Map_IsPosInAgentIsland(enemy->navAgent, &enemy->mover.pos, &m.pos)) {
                      *best = distSq;
                      enemy->unk_1f8 = (node->kindMask & 6) ? 1 : 0;
                      ok = TRUE;
                    }
                  } else if ((step == 2 || FUN_082340c8(&enemy->mover.pos, &m.pos, 10, 0x100)) && distSq < *best) {
                    *best = distSq;
                    if ((node->kindMask & 6) && ((near == 0 && step == 0) || (enemy->flags5 & ENEFLAG5_UNK_3) || (step != 2 && distSq <= near))) {
                      enemy->unk_1f8 = 1;
                    } else {
                      enemy->unk_1f8 = 0;
                    }
                    ok = TRUE;
                  }
                }
              }
            }
          }

          if (ok && Map_IsPosInAgentIsland(enemy->navAgent, &enemy->mover.pos, &m.pos)) {
            return TRUE;
          }
        }
        FUN_080865dc(&m.pos);
      }
      return FALSE;
    }
    case 2: {
      Mover* owner;

      if (!(enemy->flags & ENEFLAG_UNK_3)) {
        return FALSE;
      }
      owner = node->owner;
      if (gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) {
        s32 idx;

        if (owner == NULL) {
          return FALSE;
        }
        idx = owner->unk_4 < 4 ? owner->unk_4 : -1;
        if (idx < 0) {
          return FALSE;
        }
        if (gPlayerStates[idx] & 8) {
          return FALSE;
        }
      }
      if ((u8)FUN_080f8e84(owner, 1, 0x21000)) {
        return FALSE;
      }
      {
        Vec3 d;
        s32 distSq;
        bool32 ok = FALSE;
        bool32 dimKnown = TRUE;

        d.x = node->owner->pos.x - enemy->mover.pos.x;
        d.y = node->owner->pos.y - enemy->mover.pos.y;
        d.z = node->owner->pos.z - enemy->mover.pos.z;
        distSq = d.x * d.x + d.z * d.z;
        if (FUN_080e4384(enemy, &node->owner->pos)) {
          *best = distSq;
          enemy->unk_1f8 = (node->kindMask & 6) ? 1 : 0;
          ok = TRUE;
        } else {
          s32 diff = ArcTan2_8(d.x, d.z) - enemy->mover.angle;

          if (diff > 0x80) {
            diff -= 0x100;
          } else if (diff < -0x80) {
            diff += 0x100;
          }
          if (diff < 0) {
            diff = -diff;
          }
          if (diff <= enemy->unk_1fd) {
            s32 limit;
            u32 near;
            bool32 dim;

            if (node->kindMask == 2) {
              if (gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) {
                dim = (u8)FUN_080f8e84(node->owner, 1, 0x10000);
              } else {
                dim = (u8)FUN_080f8e84(node->owner, 1, 0x10000) || !(gStat->mapFlags & MPF_BRIGHT);
              }
            } else if (!(gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14))) {
              dim = !(gStat->mapFlags & MPF_BRIGHT);
            } else {
              dimKnown = FALSE;
            }
            if (!dimKnown) {
            } else if (dim) {
              limit = (s32)enemy->range0Sq / 2;
              near = limit;
              if (!(enemy->flags5 & ENEFLAG5_UNK_3)) {
                near = Div(limit * 7, 10);
              }
            } else {
              limit = enemy->range0Sq;
              near = enemy->unk_1e8;
            }

            if (dimKnown && distSq <= limit) {
              s32 step = FUN_080e3f50(enemy, &enemy->mover.pos, &node->owner->pos);

              if (step >= 0) {
                s32 tile = GetCollisionTileIdx(&node->owner->pos);
                s32 cur = enemy->unk_256;
                s32 height = (s8)(enemy->mover.pos.y >> 8);
                bool32 adjacent = FALSE;

                if (tile - 1 == cur || tile == cur + gCollisionMap->tiledata->width || tile + 1 == cur || tile == cur - gCollisionMap->tiledata->width) {
                  if (((Map_FindTileOverride(tile, 1) != NULL ? &Map_FindTileOverride(tile, 1)->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) == height &&
                      !((Map_FindTileOverride(tile, 1) != NULL ? &Map_FindTileOverride(tile, 1)->tile : &gCollisionMap->tiledata->tiles[tile])->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_UNK_6))) {
                    adjacent = TRUE;
                  }
                }

                if (adjacent) {
                  if ((enemy->flags5 & ENEFLAG5_UNK_3) || Map_IsPosInAgentIsland(enemy->navAgent, &enemy->mover.pos, &node->owner->pos)) {
                    *best = distSq;
                    enemy->unk_1f8 = (node->kindMask & 6) ? 1 : 0;
                    ok = TRUE;
                  }
                } else if ((step == 2 || FUN_082340c8(&enemy->mover.pos, &node->owner->pos, 10, 0x100)) && distSq < *best) {
                  *best = distSq;
                  if ((node->kindMask & 6) && ((near == 0 && step == 0) || (enemy->flags5 & ENEFLAG5_UNK_3) || (step != 2 && distSq <= near))) {
                    enemy->unk_1f8 = 1;
                  } else {
                    enemy->unk_1f8 = 0;
                  }
                  ok = TRUE;
                }
              }
            }
          }
        }

        if (ok && Map_IsPosInAgentIsland(enemy->navAgent, &enemy->mover.pos, &node->owner->pos)) {
          return TRUE;
        }
      }
      return FALSE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/EnemyTargetManager_Bind.inc");
#endif
}

// kindMask に合う登録済みの的のうち Bind できた最後のものを敵に割り当てる
EnemyTarget* EnemyTargetManager_Claim(Enemy* p, s32 kindMask) {
  EnemyTargetManager* m = sEnemyTargetManager;
  EnemyTarget* found;
  EnemyTarget* node;
  s32 best;
  s32 hit;

  if (TestMapFlag(MPF_UNK_6) || m == NULL) {
    return NULL;
  }

  found = NULL;
  best = 0x7FFFFFFF;
  hit = -1;
  for (node = m->head; node != NULL; node = node->next) {
    if ((node->flags & ENEMYTARGET_REGISTERED) && node->owner != NULL && (node->kindMask & kindMask) && FUN_080f8c2c(node) && EnemyTargetManager_Bind(node, p, &best)) {
      found = node;
      hit = (s32)found;
    }
  }

  if (hit >= 0) {
    switch (found->kindMask) {
      case 1: {
        found->flags |= ENEMYTARGET_LINKED;
        found->enemy = p;
        break;
      }
      case 2:
      case 4: {
        Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
        FUN_080f8bb8(found->owner);
        break;
      }
    }
  }
  Enemy_ClearFlag(p, ENEFLAG_UNK_3);
  return found;
}

void EnemyTargetManager_TickTimers(void) {
  EnemyTargetManager* p = sEnemyTargetManager;

  if (p != NULL) {
    EnemyTarget* node = p->head;

    while (node != NULL) {
      if (node->cooldown != 0) {
        node->cooldown--;
      }
      node = node->next;
    }
  }
}

s32 EnemyTargetManager_Update(EnemyTargetManager* p) {
  EnemyTargetManager_Sweep();
  EnemyTargetManager_TickTimers();
  p->frameCounter++;
}

s32 EnemyTargetManager_Destroy(EnemyTargetManager* p) { sEnemyTargetManager = NULL; }

s32 EnemyTargetManager_Init(EnemyTargetManager* p, u16 id) {
  sEnemyTargetManager = p;
  EnemyTargetManager_Clear();
  p->id = id;
}

// 0xD854
EnemyTargetManager* EnemyTargetManager_Create(u16 id) {
  if (sEnemyTargetManager == NULL) {
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
  return sEnemyTargetManager;
}

void EnemyTargetManager_ClearGlobal(void) { sEnemyTargetManager = NULL; }
