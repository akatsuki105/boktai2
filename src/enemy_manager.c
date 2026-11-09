#include "enemy_manager.h"

#include "dust.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "entity.h"
#include "global.h"
#include "link_session.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "solar.h"
#include "vec3.h"
#include "vm.h"

extern const s16 s16_ARRAY_085ad3cc[4];

u32 RoomBlind_IsDim(void);
bool8 DefeatedEnemyLog_CanAdd(u16 param_1, u16 param_2);
void FUN_080ec900(u8 kind);
void EnemyManager_SetupSharedEntities(EnemyManager* p, Enemy* enemy);
void Enemy_Reset(Enemy* p);
void Enemy_ClearStateBegun(Enemy* p);
void FUN_080e5098(Enemy* p, s32 dx, s32 dz);
void Enemy_AddKillCount(Enemy* p);
void HUD_ShowEnemyGauge(u32 id, s32 hp, u32 maxHp, u32 param_4, u32 param_5);
void FUN_080ce544(u32 param_1, u32 param_2);
bool8 FUN_0817e83c(Enemy* p);
bool8 EnemyManager_StepPaletteFade(EnemyManager* p, Enemy* enemy);
void EnemyManager_StartPaletteFade(u32 plttDst, u32 plttSrc, u32 _, s32 kind, u32 immediate);
Entity* Entity080db520_Create(void);
Entity* SpiderVenom_Create(void);
Entity* EmoteManager_Create(void);
Entity* Entity081ea120_Create(u32 param_1, u32 param_2);
Entity* OctorokManager_Create(void);
void DefeatedEnemyLog_Add(u16 param_1, u16 param_2);

const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_h_08251f68[] = "eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_h_08251f74[] = "eneinline.h";

COMMON_DATA EnemyManager* gEnemyManager = NULL;    // 0x03002C5C
COMMON_DATA EnemyListNode* gEnemyListHead = NULL;  // 0x03002C60, 生存中のエネミーの単方向リスト, EnemyManager.list と同じ値

// 状態を切り替えて新しい状態を最初から始めさせる
static inline void Enemy_RequestState(Enemy* p, void* handler, u8 state) {
  p->stateBegun = TRUE;
  p->subStateDone = FALSE;
  p->state = state;
  p->handlerState = handler;
  p->stateTimer = 0;
}

// 下位状態を切り替えて最初から始めさせる
static inline void Enemy_RequestSubState(Enemy* p, u8 state0, u8 state1, u8 state2) {
  p->subState0 = state0;
  p->subState1 = state1;
  p->subState2 = state2;
  p->subStateTimer = 0;
  p->subStateBegun = TRUE;
}

static inline bool8 EnemyManager_TestFlag(EnemyManager* p, EnemyManagerFlags bit) {
  if (TEST_FLAGS(p->flags, bit)) return TRUE;
  return FALSE;
}

// tileIdx のタイルの高さを返す, 階段なら pos の端数ぶんだけ下げる
static inline s32 Enemy_TileHeight(u32 tileIdx, WorldPos* pos) {
  MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
  CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
  s32 stairs = tile->heightStairs >> 4;
  s32 height = (tile->heightStairs & 0xF) << 8;

  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= pos->z & 0xFF;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= pos->x & 0xFF;
      break;
    }
  }
  return height;
}

// 番兵ノードを1つ確保してリストを空の状態にする
void EnemyManager_InitList(EnemyManager* p) {
  EnemyListNode* node;

  p->list = Malloc(sizeof(EnemyListNode));
  ClearMemory(p->list, sizeof(EnemyListNode));
  node = p->list;
  node->next = NULL;
  node->enemy = NULL;
  gEnemyListHead = node;
  p->cursor = node;
}

// 敵を生存リストへ登録する
bool8 Enemy_Register(Enemy* p) {
  EnemyManager* mgr = GetEnemyManager();
  EnemyListNode* head;
  EnemyListNode* node;

  if (mgr == NULL) {
    return FALSE;
  }
  head = gEnemyListHead;
  if (TestMapFlag(MPF_UNK_2) && !DefeatedEnemyLog_CanAdd(gMapInitScriptID, p->mover.id)) {
    return FALSE;
  }
  if ((u16)mgr->enemyCount >= 20) {
    return FALSE;
  }
  if (FindEnemyById(p->mover.id) != NULL) {
    return FALSE;
  }

  node = Malloc(sizeof(EnemyListNode));
  ClearMemory(node, sizeof(EnemyListNode));
  node->enemy = p;
  node->next = head;
  gEnemyListHead = node;
  FUN_080ec900(p->kind);
  if (!TEST_FLAGS(p->flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a48(&p->mover);
  }
  EnemyManager_SetupSharedEntities(mgr, p);
  mgr->enemyCount++;
  return TRUE;
}

// リストから指定した敵のノードを外して解放する
NON_MATCH void Enemy_Unregister(Enemy* enemy) {
#ifdef NONMATCHING_C
  EnemyManager* mgr = GetEnemyManager();
  EnemyListNode* prev;
  EnemyListNode* node;

  if (mgr == NULL) {
    return;
  }
  node = gEnemyListHead;
  if (node == NULL) {
    return;
  }
  if (node->enemy == enemy) {
    EnemyListNode* next = node->next;

    gEnemyListHead = next;
    mgr->cursor = next;
    Free(node);
    mgr->enemyCount--;
    return;
  }
  for (prev = node; prev->next != NULL; prev = node) {
    node = prev->next;
    if (node->enemy == enemy) {
      EnemyListNode* next = node->next;

      Free(node);
      prev->next = next;
      mgr->cursor = next;
      mgr->enemyCount--;
      return;
    }
  }
#else
  INCFUNC("asm/func/Enemy_Unregister.inc");
#endif
}

// kind が ENEK_0 (全体宛て) のときだけ全ての敵へメッセージを配送する
void Enemy_BroadcastMsg(u8 kind, void* payload) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;

  if (node != NULL) {
    while (node->next != NULL) {
      p = node->enemy;
      if ((kind == ENEK_0) && (p->handlerMsg != NULL)) {
        p->handlerMsg(p, payload);
      }
      node = node->next;
    }
  }
}

// 指定した種族の敵へメッセージを配送する
void Enemy_SendMsgByKind(u8 enemyKind, void* payload) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;

  if (node != NULL) {
    while (node->next != NULL) {
      p = node->enemy;
      if ((p->kind == enemyKind) && (p->handlerMsg != NULL)) {
        p->handlerMsg(p, payload);
      }
      node = node->next;
    }
  }
}

// 指定した種族と variant の敵へメッセージを配送する
// 41/41 命令, p->handlerMsg のオフセットを p->variant の計算から流用してしまう
NON_MATCH void Enemy_SendMsgByKindVariant(u8 kind, u8 variant, void* payload) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;

  if (node != NULL) {
    while (node->next != NULL) {
      Enemy* p = node->enemy;

      if (p->kind == kind && p->variant == variant && p->handlerMsg != NULL) {
        p->handlerMsg(p, payload);
      }
      node = node->next;
    }
  }
#else
  INCFUNC("asm/func/Enemy_SendMsgByKindVariant.inc");
#endif
}

// 種族(ENEK_xxx) と mover.id で敵を1体だけ特定してメッセージを配送する
void Enemy_SendMsgById(u8 enemyKind, void* payload, u16 moverID) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;

  if (node != NULL) {
    while (node->next != NULL) {
      p = node->enemy;
      if ((p->kind == enemyKind) && (p->mover.id == moverID) && (p->handlerMsg != NULL)) {
        p->handlerMsg(p, payload);
        return;
      }
      node = node->next;
    }
  }
}

// スクリプトが登録したメッセージを宛先 (全体/種族/個体) ごとに敵へ配送する
void EnemyManager_DispatchScriptMsgs(EnemyManager* p) {
  s32 count = FUN_08230f94(p->msgRecordID, &p->msgRecords);
  ScriptRecord* record = p->msgRecords;

  while (count-- > 0) {
    u16* values = record->values;

    switch (values[0]) {
      case 1: {
        Enemy_BroadcastMsg(values[1], &values[2]);
        break;
      }
      case 2: {
        Enemy_SendMsgByKind(values[1], &values[2]);
        break;
      }
      case 3: {
        Enemy_SendMsgById(values[1], &values[3], values[2]);
        break;
      }
    }
    record++;
  }
}

// 視覚を持たず聴覚で索敵する種族 (マミー/サンドウォーム) が登録されたら MPF_UNK_0 を立てる
// 他の敵は視覚+聴覚で索敵するが, マミー/サンドウォームは聴覚のみで索敵する(その代わり聴覚の感度が高い)
void FUN_080ec900(u8 kind) {
  if ((kind == ENEK_MUMMY) || (kind == ENEK_SANDWORM)) {  // どちらも視覚ではなく聴覚で索敵する
    SET_FLAGS(gStat->mapFlags, MPF_UNK_0);
  }
}

// 1フレームおきに巡回カーソルを1体進め, その敵に的を探してよい印 (ENEFLAG_UNK_3) を立てる
void EnemyManager_AdvanceCursor(EnemyManager* p) {
  EnemyListNode* cursor;
  EnemyListNode* next;

  if ((p->frameCounter & 1) == 0) {
    cursor = p->cursor;
    if ((cursor != NULL) && (cursor->enemy != NULL)) {
      Enemy_SetFlag(cursor->enemy, ENEFLAG_UNK_3);
      next = cursor->next;
    } else {
      next = gEnemyListHead;
    }
    p->cursor = next;
  }
}

// 活動中の敵の数を数える
s32 Enemy_CountActive(void) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;
  s32 count = 0;

  while (p != NULL) {
    if (Enemy_IsDead(p) || TEST_FLAGS(p->flags, ENEFLAG_UNK_0 | ENEFLAG_UNK_1)) {
      node = node->next;
      p = node->enemy;
    } else {
      node = node->next;
      p = node->enemy;
      count++;
    }
  }
  return count;
}

// 87/87 命令, ループの外へ出す定数が 3 でなく 0x4000 になる
NON_MATCH void FUN_080ec9b0(EnemyManager* p) {
#ifdef NONMATCHING_C
  s32 count = Enemy_CountActive();

  if (count > 0) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* enemy = node->enemy;
    s32 n = 0;
    s32 limit;
    s32 wait;

    if (count < 5) {
      limit = 1;
      wait = count - 1;
    } else if (count < 10) {
      limit = 2;
      wait = Div(count + 1, 2) - 1;
    } else {
      limit = 4;
      wait = Div(count + 3, 4) - 1;
    }

    while (enemy != NULL) {
      if (Enemy_IsDead(enemy) || TEST_FLAGS(enemy->flags, ENEFLAG_UNK_0 | ENEFLAG_UNK_1)) {
        enemy->unk_48e = 0;
      } else if (enemy->unk_48e != 0) {
        enemy->unk_48e--;
      } else if (n < limit) {
        enemy->unk_48e = wait;
        Enemy_SetFlag4(enemy, ENEFLAG4_UNK_14);
        n++;
      }
      node = node->next;
      enemy = node->enemy;
    }
  }
#else
  INCFUNC("asm/func/FUN_080ec9b0.inc");
#endif
}

// 種族が使う共有エンティティを必要なら生成して敵に持たせる
void EnemyManager_SetupSharedEntities(EnemyManager* p, Enemy* enemy) {
  if (enemy->kind == ENEK_SPIDER) {
    if (!EnemyManager_TestFlag(p, EMFLAG_UNK_3)) {
      Entity* e = Entity080db520_Create();

      p->sharedEntity[0] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, EMFLAG_UNK_3);
      p->sharedEntityId[0] = e->id;
    }
    enemy->unk_260 = p->sharedEntity[0];
    if (enemy->variant == 1) {
      if (!EnemyManager_TestFlag(p, EMFLAG_UNK_4)) {
        Entity* e = SpiderVenom_Create();

        p->sharedEntity[1] = e;
        if (e == NULL) {
          return;
        }
        SET_FLAGS(p->flags, EMFLAG_UNK_4);
        p->sharedEntityId[1] = e->id;
      }
      enemy->unk_260 = p->sharedEntity[1];
    }
  } else if (!EnemyManager_TestFlag(p, EMFLAG_UNK_5)) {
    Entity* e = EmoteManager_Create();

    p->sharedEntity[2] = e;
    if (e == NULL) {
      return;
    }
    SET_FLAGS(p->flags, EMFLAG_UNK_5);
    p->sharedEntityId[2] = e->id;
  }
  if (enemy->kind == ENEK_GOLEM) {
    DustManager_Create(0, 0);
  }
  if (enemy->kind == ENEK_OCTOPUS) {
    if (!EnemyManager_TestFlag(p, EMFLAG_UNK_11)) {
      Entity* e = Entity081ea120_Create(0, 0);

      p->sharedEntity[6] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, EMFLAG_UNK_11);
      p->sharedEntityId[6] = e->id;
    }
    enemy->unk_264 = p->sharedEntity[6];
    if (!EnemyManager_TestFlag(p, EMFLAG_UNK_12)) {
      Entity* e = OctorokManager_Create();

      p->sharedEntity[7] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, EMFLAG_UNK_12);
      p->sharedEntityId[7] = e->id;
    }
    enemy->unk_260 = p->sharedEntity[7];
  }
}

void FUN_080ecbe4(void) {}

// 343/344 命令, flags のアドレスを別レジスタへ写す位置が違う
NON_MATCH void FUN_080ecbe8(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_2);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_14);
  switch (param_2) {
    case 0: {
      Vec3 pos;
      s32 route;

      SET_FLAGS(p->flags, ENEFLAG_UNK_4);
      pos.x = p->pathWalker.node->x;
      pos.z = p->pathWalker.node->y;
      pos.y = TileHeightAt(&pos);
      pos.y = p->mover.pos.y;
      if (!Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &pos)) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      } else {
        route = Map_TryFindNavRoute(p->navAgent, &p->mover.pos, &pos);
        if (route == 0) {
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
        } else if (route != 2) {
          ClearMemory(&p->mover.delta, sizeof(p->mover.delta));
        }
      }
      p->pathNodePos->val = 1;
      if (!Enemy_IsPosInRect(p, &pos, 32, 32)) {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
        Enemy_RequestSubState(p, 0, 0, 7);
        Enemy_RequestState(p, p->handlerMove, ES_UNK_1);
      } else {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
        Enemy_RequestSubState(p, 0, 0, 0);
        Enemy_RequestState(p, p->handlerWait, ES_UNK_0);
      }
      p->animSpeedDiv = 1;
      break;
    }
    case 1: {
      WorldPos* dst;
      s32 route;

      if (p->kind != ENEK_SPIDER) {
        SET_FLAGS(p->unk_222, ENEMY222_UNK_2);
      }
      SET_FLAGS(p->flags3, ENEFLAG3_UNK_7);
      p->chaseTimer = p->chaseTimeMax;
      Enemy_PlayAnim(p, 0);
      dst = &gPlayerPtr[0]->mover.pos;
      if (!Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, dst)) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      } else {
        route = Map_TryFindNavRoute(p->navAgent, &p->mover.pos, dst);
        if (route == 0) {
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
        } else if (route != 2) {
          ClearMemory(&p->mover.delta, sizeof(p->mover.delta));
        }
      }
      Enemy_RequestSubState(p, 0, 0, 12);
      Enemy_RequestState(p, p->handlerChase, ES_UNK_26);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080ecbe8.inc");
#endif
}

// 生きている敵の数を数える
s32 Enemy_CountAlive(void) {
  EnemyListNode* node;
  Enemy* enemy;
  s32 count;

  GetEnemyManager();
  node = gEnemyListHead;
  enemy = node->enemy;
  count = 0;
  while (enemy != NULL) {
    if (enemy->hp > 0 && !Enemy_TestFlag2(enemy, ENEFLAG2_UNK_17)) {
      count++;
    }
    node = node->next;
    enemy = node->enemy;
  }
  return count;
}

// 指定した種族の生きている敵の数を数える
s32 Enemy_CountByKind(u32 kind) {
  EnemyListNode* node;
  Enemy* p;
  s32 count;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  count = 0;
  while (p != NULL) {
    if (p->hp > 0 && !Enemy_TestFlag2(p, ENEFLAG2_UNK_17) && p->kind == kind) {
      count++;
    }
    node = node->next;
    p = node->enemy;
  }

  return count;
}

// 指定した種族と variant の生きている敵の数を数える
// 46/46 命令, variant の読み出しで add r7, #0x63 にならない
NON_MATCH s32 Enemy_CountByKindVariant(u32 kind, u32 variant) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;
  s32 count;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  count = 0;
  while (p != NULL) {
    if (p->hp > 0 && !Enemy_TestFlag2(p, ENEFLAG2_UNK_17) && p->kind == kind && p->variant == variant) {
      count++;
    }
    node = node->next;
    p = node->enemy;
  }

  return count;
#else
  INCFUNC("asm/func/Enemy_CountByKindVariant.inc");
#endif
}

// 生きている敵を先頭から1体返す
Enemy* Enemy_GetFirstAlive(u32 _) {
  EnemyListNode* node;
  Enemy* enemy;

  GetEnemyManager();
  node = gEnemyListHead;
  enemy = node->enemy;
  while (enemy != NULL) {
    if (enemy->hp > 0 && !Enemy_TestFlag2(enemy, ENEFLAG2_UNK_17)) {
      return enemy;
    }
    node = node->next;
    enemy = node->enemy;
  }
  return NULL;
}

// 生きている敵をすべて倒す
void Enemy_KillAll(void) {
  EnemyListNode* node;
  Enemy* enemy;

  GetEnemyManager();
  node = gEnemyListHead;
  enemy = node->enemy;
  while (enemy != NULL) {
    if (!Enemy_IsDead(enemy)) {
      enemy->hp = 0;
      Enemy_SetFlag(enemy, ENEFLAG_UNK_12);
    }
    node = node->next;
    enemy = node->enemy;
  }
}

// 生きている敵すべてに damage を与え, 倒した敵の討伐数と経験値を加算する
// 480/508 命令, ループの出口の形と表示判定の分岐が未解決, 下書き段階
NON_MATCH void Enemy_DamageAll(s32 damage) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  while (p != NULL) {
    if (!Enemy_IsDead(p)) {
      s32 dx;
      s32 dz;

      CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
      p->unk_21e = 0;
      p->unk_220 = 0;
      p->unk_202 = 0;
      dx = (Random() & 63) - 16;
      dz = (Random() & 63) - 16;
      p->hurtbox.damage = damage;
      p->unk_48a = damage;
      p->hp -= p->hurtbox.damage;
      if (!(p->weaponExpMask & 0x4000)) {
        bool8 show;

        if (p->spriteKind == 0) {
          Video_SetAuxSpritePltt(&p->s->aux.gfx, p->unk_47c);
        } else {
          p->s->main.spr.pltt = &gObjPlttData[p->unk_47c * 16];
        }
        p->unk_492 = 8;
        SET_FLAGS(p->flags, ENEFLAG_UNK_15);
        show = TRUE;
        if ((gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
          switch (gLinkSession != NULL ? gLinkSession->playerIdx : -1) {
            case 0: {
              show = p->unk_4a0 == 1;
              break;
            }
            case 1: {
              show = p->unk_4a0 == 2;
              break;
            }
            case 2: {
              show = p->unk_4a0 == 4;
              break;
            }
            case 3: {
              show = p->unk_4a0 == 8;
              break;
            }
          }
        }
        if (show) {
          Vec3 v;

          HUD_ShowEnemyGauge(p->mover.id, p->hp, p->maxHp, p->unk_25a, 0);
          CpuFill32(0, &v, sizeof(v));
          if (p->unk_48a != 0 || !(p->weaponExpMask & 0x4000)) {
            CreateDamageNumber(&p->hurtbox, p->unk_48a, 0, &p->mover.pos, &v, 1);
          }
        }
      }
      FUN_080e5098(p, dx, dz);
      SET_FLAGS(p->flags3, ENEFLAG3_UNK_3);
      p->mover.angle = ArcTan2_8(dx, dz);
      p->hurtbox.iframes = 38;
      p->unk_4be = 0;
      if (p->hp <= 0) {
        Enemy_RequestState(p, p->handlerDying, ES_DYING);
        Enemy_RequestSubState(p, 3, 0, 0);
        p->unk_4a0 = 1;
        if (!(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14))) {
          if ((p->unk_4a0 & 1) && !TEST_FLAGS(p->flags5, ENEFLAG5_UNK_7)) {
            if ((p->kind != ENEK_OCTOPUS || p->variant != 1) && p->kind != ENEK_SKELETON && p->kind != ENEK_SKELETON_A && p->kind != ENEK_SKELETON_F) {
              gStat->unk_948[0] = gStat->unk_948[0] < 9999 ? gStat->unk_948[0] + 1 : 9999;
              gStat->totalEnemyKillCount = gStat->totalEnemyKillCount < 9999 ? gStat->totalEnemyKillCount + 1 : 9999;
              Enemy_AddKillCount(p);
            }
            AddPlayerExp(p->exp);
            Player_AddWeaponExp(p->weaponExpMask, p->weaponExp);
          }
          if (!TEST_FLAGS(p->flags5, ENEFLAG5_UNK_7) && !(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
            DefeatedEnemyLog_Add(gMapInitScriptID, p->mover.id);
          }
          SET_FLAGS(p->hurtbox.flags, HBFLAG_HIDDEN);
        } else {
          FUN_080ce544(p->unk_4a0, p->weaponExpMask);
        }
      } else {
        SET_FLAGS(p->flags3, ENEFLAG3_UNK_5);
        Enemy_RequestState(p, p->handlerDamaged, ES_DAMAGED);
        Enemy_RequestSubState(p, 3, 0, 0);
      }
      SET_FLAGS(p->flags, ENEFLAG_UNK_13);
    }
    node = node->next;
    p = node->enemy;
  }
#else
  INCFUNC("asm/func/Enemy_DamageAll.inc");
#endif
}

// '.k' の種族 (0 なら全種族) の敵をすべて倒す
// 195/196 命令, 一時レジスタに r3 まで使う割当が違う
NON_MATCH void Cmd_C12A(void) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;
  s32 removeFlag;
  u32 kind;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  removeFlag = VM_GetNamedArgValue('s', 0);
  kind = VM_GetNamedArgValue('k', 0);
  while (p != NULL) {
    if (Enemy_TestFlag(p, ENEFLAG_UNK_1) && p->hp > 0) {
      if (kind == 0 || kind == p->kind) {
        p->hp = 0;
        p->sleepTimer = 0;
        p->mover.pos.x = 0;
        p->mover.pos.y = 30000;
        p->mover.pos.z = 0;
        Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
        Enemy_RequestState(p, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_RequestSubState(p, 3, 0, 0);
        Enemy_Deactivate(p);
        if (!(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
          DefeatedEnemyLog_Add(gMapInitScriptID, p->mover.id);
        }
      }
    } else if (!Enemy_IsDead(p) && (kind == 0 || kind == p->kind)) {
      p->hp = 0;
      p->sleepTimer = 0;
      Enemy_SetFlag(p, ENEFLAG_UNK_12);
      if (removeFlag != 0) {
        SET_FLAGS(p->flags2, ENEFLAG2_UNK_22);
      }
    }
    node = node->next;
    p = node->enemy;
  }
#else
  INCFUNC("asm/func/Cmd_C12A.inc");
#endif
}

void Cmd_7659(void) {
  EnemyListNode* node;
  Enemy* p;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  while (p != NULL) {
    if (!Enemy_IsDead(p)) {
      u8 kind = p->kind;

      if (kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_GOLEM || kind == ENEK_COCKA) {
        Enemy_RequestState(p, p->unk_5c0, ES_UNK_5);
        Enemy_RequestSubState(p, 0, 0, 3);
        SET_FLAGS(p->flags2, ENEFLAG2_UNK_12);
      }
    }
    node = node->next;
    p = node->enemy;
  }
}

// 0xC1F2
void Enemy_Sleep(void) {
  s32 id = VM_GetNamedArgValue('n', 0);
  if (id != 0) {
    Enemy* p = FindEnemyById(id);
    if (p != NULL && p->handlerSleep != NULL) {
      p->sleepTimer = p->sleepTime;
      Enemy_SetFlag4(p, ENEFLAG4_UNK_1);
    }
  }
}

void Cmd_62AA(void) {
  u32 id = VM_GetNamedArgValue('n', 0);
  s32 mode = VM_GetNamedArgValue('m', 0);

  if (id != 0) {
    Enemy* p = FindEnemyById(id);

    if (p != NULL && Enemy_TestFlag5(p, ENEFLAG5_UNK_8)) {
      Enemy_RequestSubState(p, 2, 0, 0);
      if (mode == 0) {
        Enemy_RequestState(p, Enemy_ClearStateBegun, ES_INACTIVE);
      }
      SET_FLAGS(p->flags3, ENEFLAG3_UNK_14);
    }
  }
}

// 95/99 命令, gEnemyListHead を読む位置と定数の持ち方が違う (Cmd_62AA と同じ inline で近づく)
NON_MATCH void Cmd_4FD1(void) {
#ifdef NONMATCHING_C
  EnemyManager* manager = GetEnemyManager();
  EnemyListNode* node = gEnemyListHead;

  if (manager != NULL) {
    Enemy* p;
    s32 mode;

    p = node->enemy;
    mode = VM_GetNamedArgValue('m', 0);

    while (p != NULL) {
      if (!Enemy_IsDead(p) && Enemy_TestFlag5(p, ENEFLAG5_UNK_8)) {
        Enemy_RequestSubState(p, 2, 0, 0);
        if (mode == 0) {
          Enemy_RequestState(p, Enemy_ClearStateBegun, ES_INACTIVE);
        }
        SET_FLAGS(p->flags3, ENEFLAG3_UNK_14);
      }
      node = node->next;
      p = node->enemy;
    }
  }
#else
  INCFUNC("asm/func/Cmd_4FD1.inc");
#endif
}

void Cmd_60FB(void) {
  s32 id = VM_GetNamedArgValue('n', 0);
  s32 val = VM_GetNamedArgValue('d', 0);
  if (id != 0) {
    Enemy* p = FindEnemyById(id);
    if (p != NULL) {
      if (Enemy_TestFlag5(p, ENEFLAG5_UNK_8)) {
        FUN_080ecbe8(p, val);
      }
    }
  }
}

void Cmd_4E22(void) {
  if (GetEnemyManager() != NULL) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* p = node->enemy;
    s32 val = VM_GetNamedArgValue('d', 0);
    while (p != NULL) {
      if (!Enemy_IsDead(p) && TEST_FLAGS(p->flags3, ENEFLAG3_UNK_14)) {
        FUN_080ecbe8(p, val);
      }
      node = node->next;
      p = node->enemy;
    }
  }
}

void Cmd_286B(void) {
  EnemyListNode* node;
  Enemy* p;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  while (p != NULL) {
    if (!Enemy_IsDead(p)) {
      u8 kind = p->kind;

      if ((kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_GOLEM || kind == ENEK_COCKA) && !TEST_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
        Enemy_RequestState(p, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_RequestSubState(p, 0, 1, 0);
      }
    }
    node = node->next;
    p = node->enemy;
  }
}

// 経路ノード周辺にプレイヤーがいるかを返す
bool8 Enemy_IsPlayerNearSpawn(Enemy* p, Vec3* pos) {
  Vec3 node;
  Vec3 diff;
  Vec3 closest;
  s32 best = 0x7FFFFFFF;
  s32 found = -1;
  s32 i;

  if (p->kind == ENEK_MIMIC) {
    if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_26)) {
      return TRUE;
    }
    return FALSE;
  }

  Map_GetPathNodePos(&node, p->unk_250, p->unk_252);
  for (i = 0; i < 4; i++) {
    if (gPlayerPtr[i] != NULL) {
      s32 dist;

      Vec3_Diff(&diff, &gPlayerPtr[i]->mover.pos, &node);
      dist = diff.x * diff.x + diff.z * diff.z;
      if (best > dist) {
        best = dist;
        found = i;
        closest = diff;
      }
    }
  }
  if (found >= 0 && closest.x <= pos->x && closest.x >= -pos->x && closest.z <= pos->z && closest.z >= -pos->z) {
    return TRUE;
  }
  return FALSE;
}

// pos に一番近いマミー/ゴーレム/ボクを返す, 状態21の敵は除く
// 59/74 命令, sp を使う距離計算の形が違う
NON_MATCH Enemy* FUN_080edc40(Vec3* pos) {
#ifdef NONMATCHING_C
  s32 best = 10000000;
  Enemy* found = NULL;
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;

  while (p != NULL) {
    if (!Enemy_IsDead(p)) {
      u8 kind = p->kind;

      if ((kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_GOLEM) && p->state != ES_UNK_21) {
        s32 dx = (s16)(pos->x - p->mover.pos.x);
        s32 dz = (s16)(pos->z - p->mover.pos.z);
        s32 dist = dx * dx + dz * dz;

        if (dist < best) {
          best = dist;
          found = p;
        }
      }
    }
    node = node->next;
    p = node->enemy;
  }

  return found;
#else
  INCFUNC("asm/func/FUN_080edc40.inc");
#endif
}

// id の敵より後ろで活動停止していない最初の敵を返す, id が 0 なら先頭から
// 残差1命令, 定数 1 の movs がループ入口の前に出るか中に出るかだけ違う (命令列は 31 対 31)
NON_MATCH Enemy* Enemy_GetNextActive(u32 id) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;

  while (p != NULL) {
    if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_0) && id == 0) {
      return p;
    }
    if (p->mover.id == id) {
      id = 0;
    }
    node = node->next;
    p = node->enemy;
  }
  return NULL;
#else
  INCFUNC("asm/func/Enemy_GetNextActive.inc");
#endif
}

// id の敵より後ろで活動停止していないボク/マミー/ゴーレム/スケルトン系/コカトリス/犬の最初の敵を返す
Enemy* FUN_080edd2c(u32 id) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;

  while (p != NULL) {
    if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_0) && id == 0) {
      u8 kind = p->kind;

      if (kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_GOLEM || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_COCKA || kind == ENEK_DOG) {
        return p;
      }
    }
    if (p->mover.id == id) {
      id = 0;
    }
    node = node->next;
    p = node->enemy;
  }

  return NULL;
}

Enemy* GetFirstEnemy(void) { return gEnemyListHead->enemy; }

Enemy* FindEnemyById(u32 id) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;

  while (p != NULL) {
    if (p->mover.id == id) {
      return p;
    }
    node = node->next;
    p = node->enemy;
  }
  return NULL;
}

// スクリプトが指定した敵が生存している (hp > 0) かを返す
bool32 Cmd_E019(void) {
  u32 id = VM_GetValue();
  Enemy* p;
  bool32 alive;
  s32 hp;

  if (id == 0) {
    return FALSE;
  }
  p = FindEnemyById(id);
  if (p == NULL) {
    return FALSE;
  }
  hp = p->hp;
  alive = TRUE;
  if (hp <= 0) {
    alive = FALSE;
  }
  return alive;
}

// スクリプトが指定した敵が存在するかを返す
bool32 Cmd_6790(void) {
  u32 id = VM_GetValue();

  if ((id != 0) && (FindEnemyById(id) != NULL)) {
    return TRUE;
  }
  return FALSE;
}

// 指定した種族で flags に mask のビットが立っている敵が1体でもいるかを返す
NON_MATCH bool8 Enemy_HasKindWithFlags(u32 kind, u32 mask) {
#ifdef NONMATCHING_C
  Enemy* p;

  for (p = GetFirstEnemy(); p != NULL; p = Enemy_GetNextActive(p->mover.id)) {
    if ((p->kind == kind) && (!Enemy_IsDead(p)) && ((p->flags & mask) != 0)) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Enemy_HasKindWithFlags.inc");
#endif
}

// 指定した種族と variant で flags に mask のビットが立っている敵が1体でもいるかを返す
// 40/40 命令, return TRUE のブロックがループの前に出ない, Enemy_HasKindWithFlags と同じ
NON_MATCH bool8 Enemy_HasKindVariantWithFlags(u32 kind, u32 variant, u32 mask) {
#ifdef NONMATCHING_C
  Enemy* p = GetFirstEnemy();

  while (p != NULL) {
    if (p->kind == kind && p->variant == variant && !Enemy_IsDead(p) && (p->flags & mask) != 0) {
      return TRUE;
    }
    p = Enemy_GetNextActive(p->mover.id);
  }

  return FALSE;
#else
  INCFUNC("asm/func/Enemy_HasKindVariantWithFlags.inc");
#endif
}

// 敵を毎フレーム更新し, 破棄待ちの敵を破棄して, 屋外で日光が当たれば敵を倒し, 種族ごとのパレット遷移を進める
// 364/368 命令, レジスタ割当とループの出口の形が違う
NON_MATCH void EnemyManager_UpdateEnemies(EnemyManager* p) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;
  Enemy* enemy;

  if (node == NULL) {
    return;
  }
  enemy = node->enemy;
  while (enemy != NULL) {
    if (TEST_FLAGS(enemy->flags4, ENEFLAG4_UNK_12)) {
      void* arg = enemy->owner;

      node = node->next;
      enemy->handlerDestroy(arg);
      Free(arg);
      enemy = node->enemy;
      continue;
    }

    enemy->handlerUpdate(enemy->owner);
    if (!(gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) && !TEST_FLAGS(enemy->flags3, ENEFLAG3_UNK_14) && !TEST_FLAGS(enemy->flags2, ENEFLAG2_UNK_3) && enemy->unk_46f != 0) {
      if (!Enemy_TestFlag(enemy, ENEFLAG_UNK_1) && TEST_FLAGS(gStat->mapFlags, MPF_OUTDOOR) && gStat->zoneID == enemy->zoneID && !Enemy_IsDead(enemy) && gStat->sunGauge > 0 && gSunGaugeOverride != 1) {
        enemy->hurtbox.iframes = 0;
        enemy->unk_4be = 0;
        Enemy_ClearSpriteFlags(enemy, SPRFLAG_HIDDEN);
        enemy->hp = 0;
        FUN_080e64e4(enemy);
        CLEAR_FLAGS(enemy->flags3, ENEFLAG3_UNK_13);
        SET_FLAGS(enemy->flags, ENEFLAG_UNK_12);
      }
    }
    if (!TEST_FLAGS(enemy->flags3, ENEFLAG3_UNK_14) && EnemyManager_TestFlag(p, EMFLAG_UNK_13)) {
      switch (enemy->kind) {
        case ENEK_MIMIC:
        case ENEK_GHOST:
        case ENEK_SHAIAN: {
          if (!TEST_FLAGS(enemy->flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
            if (enemy->spriteKind == 0) {
              enemy->s->main.spr.unk_12 = enemy->unk_478;
            } else {
              enemy->s->main.spr.plttID = enemy->unk_478;
            }
          }
          if (EnemyManager_StepPaletteFade(p, enemy)) {
            if (TEST_FLAGS(p->flags, EMFLAG_UNK_17)) {
              u32 plttID = enemy->plttBase + enemy->variant;

              CLEAR_FLAGS(p->flags, EMFLAG_UNK_13 | EMFLAG_UNK_17);
              CLEAR_FLAGS(enemy->flags2, ENEFLAG2_UNK_21);
              if (enemy->spriteKind == 0) {
                Video_SetAuxSpritePltt(&enemy->s->aux.gfx, plttID);
              } else {
                enemy->s->main.spr.pltt = &gObjPlttData[plttID * 16];
              }
            } else if (TEST_FLAGS(enemy->flags2, ENEFLAG2_UNK_21)) {
              EnemyManager_StartPaletteFade(enemy->unk_478, enemy->plttBase + enemy->variant, 0, enemy->kind, 0);
              CLEAR_FLAGS(enemy->flags2, ENEFLAG2_UNK_21);
            } else {
              EnemyManager_StartPaletteFade(enemy->plttBase + enemy->variant, enemy->unk_478, 0, enemy->kind, 0);
              SET_FLAGS(enemy->flags2, ENEFLAG2_UNK_21);
            }
          }
          break;
        }
      }
    }
    node = node->next;
    enemy = node->enemy;
  }
#else
  INCFUNC("asm/func/EnemyManager_UpdateEnemies.inc");
#endif
}

// 生存中の敵をすべて破棄する
void Enemy_DestroyAll(void) {
  EnemyListNode* node = gEnemyListHead;

  if (node != NULL) {
    Enemy* p = node->enemy;

    while (p != NULL) {
      void* arg;

      node = node->next;
      arg = p->owner;
      p->handlerDestroy(arg);
      Free(arg);
      p = node->enemy;
    }
  }
}

// 通信プレイ中, 倒れた敵を近くにプレイヤーがいなければ初期状態へ戻して復活させる
// 43/50 命令, ENEFLAG_UNK_0 の判定も bool8 inline を通している
NON_MATCH void Enemy_RespawnDead(void) {
#ifdef NONMATCHING_C
  if ((gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) && gEnemyListHead != NULL) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* p = node->enemy;

    while (p != NULL) {
      node = node->next;
      if (p->hp <= 0 && TEST_FLAGS(p->flags, ENEFLAG_UNK_0) && !Enemy_IsPlayerNearSpawn(p, (Vec3*)s16_ARRAY_085ad3cc)) {
        Enemy_Reset(p);
      }
      p = node->enemy;
    }
  }
#else
  INCFUNC("asm/func/Enemy_RespawnDead.inc");
#endif
}

// 敵を初期位置の経路ノードへ戻して見た目と当たり判定を初期化する, 経路を使わない種族は位置を動かさない
void Enemy_ResetToSpawn(Enemy* p) {
  u32 plttID;
  u8* spriteKind;
  u8 kind;
  u8 priority;
  EnemyFlags active;
  EnemyFlags* flags;
  EnemyFlags2* flags2;

  p->prevPathNode = p->unk_252;
  if (p->kind != ENEK_BAT && p->kind != ENEK_CROW && p->kind != ENEK_CENTIPEDE && p->kind != ENEK_SLIME) {
    Map_GetPathNodePos(&p->mover.pos, p->unk_250, p->unk_252);
    Map_InitPathWalker(&p->pathWalker, p->unk_250, p->unk_251, p->unk_252);
    Map_InitNavAgent(p->navAgent, &p->mover.pos);
    p->mover.path = &p->pathWalker;
  }
  p->tileIdx = GetCollisionTileIdx(&p->mover.pos);
  p->mover.pos.y = Enemy_TileHeight(p->tileIdx, &p->mover.pos);
  kind = p->spriteKind;
  spriteKind = &p->spriteKind;
  if (kind == 0) {
    p->s->aux.spr.pos = p->mover.pos;
  } else {
    p->s->main.spr.pos = p->mover.pos;
  }
  p->mover.angle = p->initAngle;
  p->heightAboveFloor = 0;
  ClearMemory(&p->jumpVel, sizeof(p->jumpVel));
  ClearMemory(&p->mover.delta, sizeof(p->mover.delta));
  active = TEST_FLAGS(p->flags, ENEFLAG_UNK_21);
  flags = &p->flags;
  flags2 = &p->flags2;
  if (active) {
    CLEAR_FLAGS(*flags2, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  plttID = p->plttBase + p->variant;
  if (*spriteKind == 0) {
    Video_SetAuxSpritePltt(&p->s->aux.gfx, plttID);
  } else {
    p->s->main.spr.pltt = &gObjPlttData[plttID * 16];
  }
  CLEAR_FLAGS(*flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25);
  CLEAR_FLAGS(*flags2, ENEFLAG2_UNK_6 | ENEFLAG2_UNK_7 | ENEFLAG2_UNK_8 | ENEFLAG2_UNK_14);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  p->hurtbox.flags &= ~HBFLAG_HIDDEN;
  p->unk_494 = 0;
  p->unk_492 = 0;
  priority = 2;
  if (*spriteKind == 0) {
    p->s->aux.spr.priority = priority;
  } else {
    p->s->main.spr.priority = priority;
  }
  p->hurtbox.iframes = 0;
}

// 位置は動かさずに経路と見た目を初期化する
void Enemy_ResetInPlace(Enemy* p) {
  u32 plttID;
  u8* spriteKind;
  u8 kind;
  u8 priority;
  EnemyFlags active;
  EnemyFlags* flags;
  EnemyFlags2* flags2;

  p->prevPathNode = p->unk_252;
  Map_InitPathWalker(&p->pathWalker, p->unk_250, p->unk_251, p->unk_252);
  Map_InitNavAgent(p->navAgent, &p->mover.pos);
  p->mover.path = &p->pathWalker;
  p->tileIdx = GetCollisionTileIdx(&p->mover.pos);
  p->mover.pos.y = Enemy_TileHeight(p->tileIdx, &p->mover.pos);
  kind = p->spriteKind;
  spriteKind = &p->spriteKind;
  if (kind == 0) {
    p->s->aux.spr.pos = p->mover.pos;
  } else {
    p->s->main.spr.pos = p->mover.pos;
  }
  p->heightAboveFloor = 0;
  ClearMemory(&p->jumpVel, sizeof(p->jumpVel));
  ClearMemory(&p->mover.delta, sizeof(p->mover.delta));
  active = TEST_FLAGS(p->flags, ENEFLAG_UNK_21);
  flags = &p->flags;
  flags2 = &p->flags2;
  if (active) {
    CLEAR_FLAGS(*flags2, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  plttID = p->plttBase + p->variant;
  if (*spriteKind == 0) {
    Video_SetAuxSpritePltt(&p->s->aux.gfx, plttID);
  } else {
    p->s->main.spr.pltt = &gObjPlttData[plttID * 16];
  }
  CLEAR_FLAGS(*flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25);
  CLEAR_FLAGS(*flags2, ENEFLAG2_UNK_6 | ENEFLAG2_UNK_7 | ENEFLAG2_UNK_8 | ENEFLAG2_UNK_14);
  p->unk_494 = 0;
  p->unk_492 = 0;
  priority = 2;
  if (*spriteKind == 0) {
    p->s->aux.spr.priority = priority;
  } else {
    p->s->main.spr.priority = priority;
  }
}

// 敵を出現時の状態へ戻し, 種族ごとの onReset を呼ぶ
// 268/277 命令, 状態フィールドのアドレスを保持して使い回す形が inline では作れない
NON_MATCH void Enemy_Reset(Enemy* p) {
#ifdef NONMATCHING_C
  Enemy_ResetToSpawn(p);
  Enemy_RequestSubState(p, 3, 0, 0);
  Enemy_RequestState(p, Enemy_ClearStateBegun, ES_INACTIVE);
  p->flags = p->initFlags;
  p->flags2 = p->initFlags2;
  p->mover.angle = p->initAngle;
  p->subState0 = p->initSubState0;
  p->subState1 = p->initSubState1;
  p->subState2 = p->initSubState2;
  p->handlerState = p->initHandlerState;
  p->state = p->initState;
  p->flags5 = p->initFlags5;
  p->heightAboveFloor = p->initHeightAboveFloor;
  p->hp = p->maxHp;
  p->flags4 = 0;
  p->unk_222 = 0;
  p->flags3 = 0;
  p->subStateDone = FALSE;
  p->subStateBegun = TRUE;
  p->stateBegun = TRUE;
  p->animForceRestart = FALSE;
  p->chaseTimer = 0;
  p->sleepTimer = 0;
  p->unk_544 = 0;
  p->nodeWait = 0;
  p->hitTargetID = 0;
  p->playerMover = NULL;
  p->angle = 0;
  p->unk_21c = 0;
  p->animSpeedDiv = 1;
  p->weaponExpMask = 0;
  p->flags6 = 0;
  p->unk_4a0 = 0;
  p->unk_48c = 0;
  p->unk_4be = 0;
  p->unk_48d = 0;
  p->unk_48e = 0;
  ClearMemory(p->unk_458, sizeof(p->unk_458));
  p->unk_464 = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, s_eneinline_h_08251f68, 2434);
  p->lookAngle = 0;
  p->lookBaseAngle = 0;
  p->unk_542 = 0xFF;
  p->savedHandlerState = NULL;
  p->savedSubState0 = 0;
  p->savedSubState1 = 0;
  p->savedSubState2 = 0;
  p->savedState = 0;
  EnemyManager_TryEndPaletteFade(p);
  SET_FLAGS(p->flags, ENEFLAG_UNK_1);
  SET_FLAGS(p->hurtbox.flags, HBFLAG_HIDDEN);
  if (p->onReset != NULL) {
    p->onReset(p);
  }
  EnemyManager_TryEndPaletteFade(p);
  p->emote = Emote_Remove(p->emote, 1, p->mover.id);
  p->emote = Emote_RemovePtcl(p->emote, 3, p->mover.id);
  FUN_080ecbe4();
#else
  INCFUNC("asm/func/Enemy_Reset.inc");
#endif
}

// 15フレームごとに, 回る背景が無効なら部屋を明るい扱いにする
void EnemyManager_UpdateBrightFlag(EnemyManager* p) {
  if (Mod(p->frameCounter, 15) == 0) {
    if (RoomBlind_IsDim() == 0) {
      SET_FLAGS(gStat->mapFlags, MPF_BRIGHT);
    } else {
      CLEAR_FLAGS(gStat->mapFlags, MPF_BRIGHT);
    }
  }
}

s32 EnemyManager_Update(EnemyManager* p) {
  Enemy_RespawnDead();
  EnemyManager_DispatchScriptMsgs(p);
  EnemyManager_AdvanceCursor(p);
  FUN_080ec9b0(p);
  EnemyManager_UpdateEnemies(p);
  EnemyManager_UpdateBrightFlag(p);
  CLEAR_FLAGS(p->flags, EMFLAG_UNK_14 | EMFLAG_UNK_15 | EMFLAG_UNK_16);
  p->frameCounter++;
  return 0;
}

s32 EnemyManager_Destroy(EnemyManager* p) {
  Enemy_DestroyAll();
  Free(gEnemyListHead);
  gEnemyManager = NULL;
  return 0;
}

// 戻り値を設定しないまま返る, 呼び出し元の EnemyManager_Create は戻り値が負かどうかを見ている
s32 EnemyManager_Init(EnemyManager* p, u16 msgRecordID, u32 _) {
  p->msgRecordID = msgRecordID;
  p->frameCounter = 0;
  p->enemyCount = 0;
  p->unk_30 = 3;
  EnemyManager_InitList(p);
  gEnemyManager = p;
}

EnemyManager* EnemyManager_Create(u16 msgRecordID, u16 _) {
  if (gEnemyManager == NULL) {
    EnemyManager* p = CreateEntity(ENTITY_UNK_8, sizeof(EnemyManager));
    if (p != NULL) {
      SetEntityRoutine(p, EnemyManager_Update, EnemyManager_Destroy);
      if (EnemyManager_Init(p, msgRecordID, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEnemyManager;
}

void EnemyManager_ClearGlobal(void) { gEnemyManager = NULL; }

// ミミック/ゴースト/シャイアンのパレット遷移を plttSrc から plttDst へ向けて始める
// レジスタ割当とループ外へ出すアドレスの組が違う, 下書き段階
NON_MATCH void EnemyManager_StartPaletteFade(u32 plttDst, u32 plttSrc, u32 _, s32 kind, u32 immediate) {
#ifdef NONMATCHING_C
  EnemyManager* manager = gEnemyManager;
  EnemyPaletteFade* fade;
  rgb555* pltt;
  rgb555* dst;
  rgb555* src;
  s32 i;

  if (manager == NULL) {
    return;
  }

  switch (kind) {
    case ENEK_GHOST: {
      fade = &manager->palFade[1];
      break;
    }
    case ENEK_MIMIC: {
      fade = &manager->palFade[0];
      break;
    }
    case ENEK_SHAIAN: {
      fade = &manager->palFade[2];
      break;
    }
    default: {
      return;
    }
  }

  Enemy_GetFirstAlive(kind);
  pltt = gObjPlttData;
  fade->plttID = plttDst;
  dst = &pltt[plttDst * 16];
  src = &pltt[plttSrc * 16];
  for (i = 0; i < 16; i++) {
    u16 color;
    u32 r;
    u32 g;
    u32 b;

    if (EnemyManager_TestFlag(manager, EMFLAG_UNK_13) && fade->timer != 32) {
      color = fade->pltt[i];
    } else {
      color = *src;
    }
    r = color & 31;
    fade->stepR[i] = (*dst & 31) - r;
    g = (color >> 5) & 31;
    fade->stepG[i] = ((*dst >> 5) & 31) - g;
    b = (color >> 10) & 31;
    fade->stepB[i] = ((*dst >> 10) & 31) - b;
    fade->r[i] = r << 5;
    fade->g[i] = g << 5;
    fade->b[i] = b << 5;
    dst++;
    src++;
  }
  SET_FLAGS(manager->flags, EMFLAG_UNK_13);
  fade->timer = 32;
  if (immediate == 0) {
    CLEAR_FLAGS(manager->flags, EMFLAG_UNK_17);
  } else {
    SET_FLAGS(manager->flags, EMFLAG_UNK_17);
  }
#else
  INCFUNC("asm/func/EnemyManager_StartPaletteFade.inc");
#endif
}

// パレット遷移を1段進めて敵のスプライトへ繋ぐ, 遷移が終わったら TRUE を返す
// ループ内のアドレスの持ち方とレジスタ割当が違う
NON_MATCH bool8 EnemyManager_StepPaletteFade(EnemyManager* p, Enemy* enemy) {
#ifdef NONMATCHING_C
  EnemyPaletteFade* fade;
  bool8 skip;

  if (Enemy_IsDead(enemy) || !EnemyManager_TestFlag(p, EMFLAG_UNK_13)) {
    return FALSE;
  }

  skip = FALSE;
  switch (enemy->kind) {
    case ENEK_GHOST: {
      fade = &p->palFade[1];
      if (EnemyManager_TestFlag(p, EMFLAG_UNK_15)) {
        skip = TRUE;
      }
      break;
    }
    case ENEK_MIMIC: {
      fade = &p->palFade[0];
      if (EnemyManager_TestFlag(p, EMFLAG_UNK_14)) {
        skip = TRUE;
      }
      break;
    }
    case ENEK_SHAIAN: {
      fade = &p->palFade[2];
      if (EnemyManager_TestFlag(p, EMFLAG_UNK_16)) {
        skip = TRUE;
      }
      if (!FUN_0817e83c(enemy)) {
        return FALSE;
      }
      break;
    }
    default: {
      return TRUE;
    }
  }

  if (fade->timer == 0) {
    if (!TEST_FLAGS(enemy->flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
      if (enemy->spriteKind == 0) {
        *(EnemyPaletteFade**)&enemy->s->main.spr.animFlags = fade;
      } else {
        enemy->s->main.spr.pltt = fade->pltt;
      }
    }
  } else {
    if (!skip) {
      s32 i;

      for (i = 0; i < 16; i++) {
        s32 r;
        s32 g;
        s32 b;

        fade->r[i] += fade->stepR[i];
        r = fade->r[i];
        fade->g[i] += fade->stepG[i];
        g = fade->g[i];
        fade->b[i] += fade->stepB[i];
        b = fade->b[i];
        fade->pltt[i] = (r >> 5) | ((g >> 5) << 5) | ((b >> 5) << 10);
      }
      fade->timer--;
      switch (enemy->kind) {
        case ENEK_GHOST: {
          SET_FLAGS(p->flags, EMFLAG_UNK_15);
          break;
        }
        case ENEK_MIMIC: {
          SET_FLAGS(p->flags, EMFLAG_UNK_14);
          break;
        }
        case ENEK_SHAIAN: {
          SET_FLAGS(p->flags, EMFLAG_UNK_16);
          break;
        }
      }
    }
    if (!TEST_FLAGS(enemy->flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
      if (enemy->spriteKind == 0) {
        *(EnemyPaletteFade**)&enemy->s->main.spr.animFlags = fade;
      } else {
        enemy->s->main.spr.pltt = fade->pltt;
      }
    }
    if (fade->timer != 0) {
      return FALSE;
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/EnemyManager_StepPaletteFade.inc");
#endif
}

// 37/47 命令, 判定を bool 変数に受ける形が未解決
NON_MATCH bool8 FUN_080eee70(void) {
#ifdef NONMATCHING_C
  if (gEnemyManager != NULL && (gEnemyManager->flags & EMFLAG_UNK_13)) {
    if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) {
      if (Enemy_CountByKind(ENEK_MIMIC) != 0) {
        return FALSE;
      }
    } else {
      if (Enemy_CountByKind(ENEK_MIMIC) != 0 || Enemy_CountByKind(ENEK_GHOST) != 0 || Enemy_CountByKind(ENEK_SHAIAN) != 0) {
        return FALSE;
      }
    }
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_080eee70.inc");
#endif
}

// パレット遷移を使う敵が残っていなければパレット遷移を終える
// 45/58 命令, Enemy_HasKindWithFlags の結果の受け方と判定の並びが未解決
NON_MATCH void EnemyManager_TryEndPaletteFade(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyManager* manager = gEnemyManager;

  if (manager != NULL && (manager->flags & EMFLAG_UNK_13)) {
    s32 count;

    if (gGameFlags & (GAMEFLAG_LINK | GAMEFLAG_UNK_14)) {
      count = Enemy_CountByKind(ENEK_MIMIC);
    } else {
      if (Enemy_HasKindWithFlags(ENEK_MIMIC, ENEFLAG_UNK_17)) {
        return;
      }
      if (Enemy_HasKindWithFlags(ENEK_GHOST, ENEFLAG_UNK_17)) {
        return;
      }
      count = Enemy_HasKindWithFlags(ENEK_SHAIAN, ENEFLAG_UNK_17);
    }
    if (count == 0) {
      CLEAR_FLAGS(manager->flags, EMFLAG_UNK_13 | EMFLAG_UNK_17);
    }
  }
#else
  INCFUNC("asm/func/EnemyManager_TryEndPaletteFade.inc");
#endif
}

// パレット遷移中なら敵のスプライトを遷移中のパレットへ繋ぐ
// 57/58 命令, spriteKind が 0 以外の枝で p->sprite の持ち方が違う
NON_MATCH void Enemy_ApplyPaletteFade(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyPaletteFade* fade;

  if (gEnemyManager == NULL) {
    return;
  }

  switch (p->kind) {
    case ENEK_GHOST: {
      fade = &gEnemyManager->palFade[1];
      break;
    }
    case ENEK_MIMIC: {
      fade = &gEnemyManager->palFade[0];
      break;
    }
    case ENEK_SHAIAN: {
      fade = &gEnemyManager->palFade[2];
      break;
    }
    default: {
      return;
    }
  }

  if (fade->timer != 0) {
    if (p->spriteKind == 0) {
      p->s->main.spr.unk_12 = p->unk_478;
      *(EnemyPaletteFade**)&p->s->main.spr.animFlags = fade;
    } else {
      MainSprite* sprite = &p->s->main.spr;

      sprite->plttID = p->unk_478;
      sprite->pltt = fade->pltt;
    }
  }
#else
  INCFUNC("asm/func/Enemy_ApplyPaletteFade.inc");
#endif
}

// '.n' の敵の初期位置の経路と経路ノードを '.r' で差し替える
void Cmd_B3D7(void) {
  u32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Enemy* e = FindEnemyById(id);

    if (e != NULL && VM_SeekToNamedArg('r')) {
      s32 a = VM_GetPC() != NULL ? VM_GetValue() : 0;
      s32 b = VM_GetPC() != NULL ? VM_GetValue() : 0;

      e->unk_250 = a;
      e->unk_252 = b;
    }
  }
}

// 敵を指定座標へ置いて足元の床へ合わせる
void Cmd_C7DC(void) {
  s32 id = VM_GetNamedArgValue('n', 0);
  Enemy* p;
  s32 height;

  if (id == 0) {
    return;
  }
  p = FindEnemyById(id);
  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('p')) {
    return;
  }

  p->mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
  p->mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
  p->mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  p->tileIdx = GetCollisionTileIdx(&p->mover.pos);
  height = Enemy_TileHeight(p->tileIdx, &p->mover.pos);
  p->floorY = height;
  p->heightAboveFloor = p->mover.pos.y - height;
  p->mover.pos.y = p->floorY;
}

// '.N' の敵の索敵範囲/攻撃/HP などの能力値をスクリプトの値で上書きする, 負の値の項目は変えない
// 392/393 命令, p とループ変数のレジスタ割当が違う
NON_MATCH void Cmd_F200(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('N', 0);
  Enemy* p;
  s32 value;

  if (id == 0) {
    return;
  }
  p = FindEnemyById(id);
  if (p == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('e')) {
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->range0 = value;
      p->range1 = value;
      p->range0Sq = p->range0 * p->range0;
      p->range1Sq = p->range0Sq;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_1fd = value;
    }
  }
  if (VM_SeekToNamedArg('a')) {
    s32 i;

    for (i = 0; i < 4; i++) {
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkPower[i] = value;
      }
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkKnockback[i] = value;
      }
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkAttrs[i] = value;
      }
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkIframes[i] = value;
      }
    }
  }
  if (VM_SeekToNamedArg('A')) {
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->maxHp = value;
      p->unk_546 = (value & 0xFFFF) >> 2;
      p->hp = p->maxHp;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->power = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_187 = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_188 = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->attrs = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->weakness = value;
    }
  }
  if (VM_SeekToNamedArg('l')) {
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_18e = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->sleepTime = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->chaseTimeMax = value;
    }
  }
  if (VM_SeekToNamedArg('n')) {
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->range2 = value;
      p->range2Sq = p->range2 * p->range2;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_1fe = value;
    }
  }
  if (VM_SeekToNamedArg('R')) {
    p->unk_194 = VM_GetNamedArgValue('R', 0);
  }
  if (VM_SeekToNamedArg('F')) {
    p->scriptID = VM_GetNamedArgValue('F', 0);
  }
  if (VM_SeekToNamedArg('I')) {
    p->unk_198 = VM_GetNamedArgValue('I', 0);
  }
  if (VM_SeekToNamedArg('D')) {
    p->defeatScriptID = VM_GetNamedArgValue('D', 0);
  }
  if (VM_SeekToNamedArg('G')) {
    s32 i;

    for (i = 0; i < 5; i++) {
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        (&p->unk_19c)[i] = value;
      }
    }
  }
  if (VM_SeekToNamedArg('K')) {
    p->unk_25a = VM_GetNamedArgValue('K', 2);
  }
#else
  INCFUNC("asm/func/Cmd_F200.inc");
#endif
}

void Cmd_E1C6(void) {
  s32 id = VM_GetNamedArgValue('n', 0);
  if (id != 0) {
    Enemy* p = FindEnemyById(id);
    if (p != NULL) {
      if (VM_GetNamedArgValue('f', 0) == 0) {
        Enemy_ClearFlag2(p, ENEFLAG2_UNK_26);
      } else {
        Enemy_SetFlag2(p, ENEFLAG2_UNK_26);
      }
    }
  }
}

// EnemyManager.flags に '.s' のビットを立てる
void Cmd_9311(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->flags |= (u16)VM_GetNamedArgValue('s', 0);
  }
}

// EnemyManager.flags から '.s' のビットを落とす
void Cmd_0740(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->flags &= ~(u16)VM_GetNamedArgValue('s', 0);
  }
}

void Cmd_2571(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->unk_30 = VM_GetNamedArgValue('l', 3);
  }
}

// 0x1E97, レジスタ割当とタイル判定の分岐の並びが未解決, 下書き段階
NON_MATCH void Cmd_1E97(void) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;

  if (node == NULL) {
    return;
  }
  p = node->enemy;
  while (p != NULL) {
    if (p->unk_46f == 1 && p->kind != ENEK_CURORO && p->kind != ENEK_BAT && p->kind != ENEK_CROW && p->kind != ENEK_BEE && p->kind != ENEK_SERPENT) {
      MapTileOverride* ov = Map_FindTileOverride(p->tileIdx, 1);
      CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[p->tileIdx];

      if (TEST_FLAGS(tile->attr, TATTR_FALLDEATH) && p->floorY >= p->mover.pos.y + p->heightAboveFloor) {
        if (!Enemy_IsDead(p)) {
          void* handler = p->unk_5d8;

          if (handler == NULL) {
            handler = Enemy_StateFallDeath;
          }
          Enemy_RequestState(p, handler, ES_UNK_22);
          Enemy_RequestSubState(p, 3, 0, 0);
          SET_FLAGS(p->flags2, ENEFLAG2_UNK_17);
        }
      } else if (TEST_FLAGS(tile->attr, TATTR_SPECIAL) && TEST_FLAGS(gStat->mapFlags, MPF_HOT) && p->hurtbox.iframes == 0) {
        Vec3 target;
        Vec3 diff;
        s32 col = Mod(p->tileIdx, gCollisionMap->tiledata->width);
        s32 row = Div(p->tileIdx, gCollisionMap->tiledata->width);

        target.x = col * 256 + 128;
        ov = Map_FindTileOverride(p->tileIdx, 1);
        tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[p->tileIdx];
        target.y = (tile->heightStairs & 0xF) << 8;
        target.z = row * 256 + 128;
        Vec3_Diff(&diff, &target, &p->mover.pos);
        p->angle = ArcTan2_8(diff.x, diff.z) >> 5;
        p->unk_4a0 = 32;
        p->hurtbox.damage = p->hp;
        p->unk_48a = p->hp;
        p->hurtbox.knockback = 40;
        p->weaponExpMask = 64;
        p->unk_48c = 1;
        SET_FLAGS(p->flags, ENEFLAG_UNK_13);
      }
    }
    node = node->next;
    p = node->enemy;
  }
#else
  INCFUNC("asm/func/Cmd_1E97.inc");
#endif
}

EnemyManager* GetEnemyManager(void) { return gEnemyManager; }
