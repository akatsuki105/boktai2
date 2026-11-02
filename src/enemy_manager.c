#include "enemy_manager.h"

#include "emote.h"
#include "enemy.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "solar.h"
#include "vec3.h"
#include "vm.h"

u32 EntityA628_IsActive(void);

extern const s16 s16_ARRAY_085ad3cc[4];
extern const char s_eneinline_h_08251f68[];  // "eneinline.h"
bool32 FUN_080ec5f0(u16 param_1, u16 param_2);
void FUN_080ec900(u8 kind);
void FUN_080eca74(EnemyManager* p, Enemy* enemy);
void FUN_080ee738(Enemy* p);
void Enemy_ClearStateBegun(Enemy* p);
void FUN_080e5098(Enemy* p, s32 dx, s32 dz);
void FUN_080e9178(Enemy* p);
void FUN_0809c344(u32 id, s32 hp, u32 maxHp, u32 param_4, u32 param_5);
void FUN_080ce544(u32 param_1, u32 param_2);
bool8 FUN_0817e83c(Enemy* p);
bool8 FUN_080eec74(EnemyManager* p, Enemy* enemy);
void FUN_080eeb14(u32 plttDst, u32 plttSrc, u32 _, s32 kind, u32 immediate);
void FUN_080e64e4(Enemy* p);
void FUN_080f54e4(Enemy* p);
Entity* Entity080db520_Create(void);
Entity* SpiderVenom_Create(void);
Entity* EmoteManager_Create(void);
void Entity080dbe54_Create(u32 param_1, u32 param_2);
Entity* Entity081ea120_Create(u32 param_1, u32 param_2);
Entity* Entity081ea820_Create(void);
void FUN_080e49c4(Enemy* p);
void FUN_080ec5b4(u16 param_1, u16 param_2);

static inline void Enemy_RequestState(Enemy* p, void* handler, u8 state) {
  p->stateBegun = TRUE;
  p->subStateDone = FALSE;
  p->state = state;
  p->handlerState = handler;
  p->stateTimer = 0;
}

static inline void Enemy_RequestSubState(Enemy* p, u8 state0, u8 state1, u8 state2) {
  p->subState0 = state0;
  p->subState1 = state1;
  p->subState2 = state2;
  p->subStateTimer = 0;
  p->subStateBegun = TRUE;
}

COMMON_DATA EnemyManager* gEnemyManager = NULL;    // 0x03002C5C
COMMON_DATA EnemyListNode* gEnemyListHead = NULL;  // 0x03002C60, 生存中のエネミーの単方向リスト, EnemyManager.list と同じ値

static inline bool8 Enemy_TestFlag5(Enemy* p, EnemyFlags5 bit) {
  if (TEST_FLAGS(p->flags5, bit)) return TRUE;
  return FALSE;
}

// 番兵ノードを1つ確保してリストを空の状態にする
void EnemyManager_InitList(EnemyManager* p) {
  EnemyListNode* node;

  p->list = Malloc(8);
  ClearMemory(p->list, 8);
  node = p->list;
  node->next = NULL;
  node->enemy = NULL;
  gEnemyListHead = node;
  p->cursor = node;
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

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// 敵を生存リストへ登録する
bool32 Enemy_Init_080ec640(Enemy* p) {
  EnemyManager* mgr = GetEnemyManager();
  EnemyListNode* head;
  EnemyListNode* node;

  if (mgr == NULL) {
    return FALSE;
  }
  head = gEnemyListHead;
  if (TestMapFlag(4) && !(u8)FUN_080ec5f0(gMapInitScriptID, p->mover.id)) {
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
  if (!TEST_FLAGS(p->flags2, 0x2000000)) {
    FUN_08002a48(&p->mover);
  }
  FUN_080eca74(mgr, p);
  mgr->enemyCount++;
  return TRUE;
}

// リストから指定した敵のノードを外して解放する
NON_MATCH void FUN_080ec6fc(Enemy* enemy) {
#ifdef NONMATCHING_C
  EnemyManager* mgr;
  EnemyListNode* node;
  EnemyListNode* prev;
  EnemyListNode* next;

  mgr = GetEnemyManager();
  if (mgr == NULL) {
    return;
  }
  node = gEnemyListHead;
  if (node == NULL) {
    return;
  }
  if (node->enemy == enemy) {
    next = node->next;
    gEnemyListHead = next;
    mgr->cursor = next;
    Free(node);
    mgr->enemyCount--;
    return;
  }
  do {
    prev = node;
    if (prev->next == NULL) {
      return;
    }
    node = prev->next;
  } while (node->enemy != enemy);
  next = node->next;
  Free(node);
  prev->next = next;
  mgr->cursor = next;
  mgr->enemyCount--;
#else
  INCFUNC("asm/func/FUN_080ec6fc.inc");
#endif
}

// 全ての敵へメッセージを配送する
void FUN_080ec758(u8 kind, void* payload) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;

  if (node != NULL) {
    while (node->next != NULL) {
      p = node->enemy;
      if ((kind == 0) && (p->handlerMsg != NULL)) {
        p->handlerMsg(p, payload);
      }
      node = node->next;
    }
  }
}

// 指定した種族の敵へメッセージを配送する
void FUN_080ec79c(u8 enemyKind, void* payload) {
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

// 41/41 命令, p->handlerMsg のオフセットを p->variant の計算から流用してしまう
NON_MATCH void FUN_080ec7e8(u8 kind, u8 variant, void* payload) {
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
  INCFUNC("asm/func/FUN_080ec7e8.inc");
#endif
}

// 種族(ENEK_xxx) と mover.id で敵を1体だけ特定してメッセージを配送する
void FUN_080ec848(u8 enemyKind, void* payload, u16 moverID) {
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

void FUN_080ec8a4(EnemyManager* p) {
  s32 count = FUN_08230f94(p->msgRecordID, &p->msgRecords);
  ScriptRecord* record = p->msgRecords;

  while (count-- > 0) {
    u16* values = record->values;

    switch (values[0]) {
      case 1: {
        FUN_080ec758(values[1], &values[2]);
        break;
      }
      case 2: {
        FUN_080ec79c(values[1], &values[2]);
        break;
      }
      case 3: {
        FUN_080ec848(values[1], &values[3], values[2]);
        break;
      }
    }
    record++;
  }
}

void FUN_080ec900(u8 kind) {
  if ((kind == ENEK_MUMMY) || (kind == ENEK_SANDWORM)) {  // どちらも視覚ではなく聴覚で索敵する
    SET_FLAGS(gStat->mapFlags, MPF_UNK_0);
  }
}

// 巡回カーソルを1つ進め、通りかかった敵に flags の bit3 を立てる
void FUN_080ec92c(EnemyManager* p) {
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
s32 FUN_080ec968(void) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;
  s32 count = 0;
  EnemyFlags mask;

  if (p != NULL) {
    mask = ENEFLAG_UNK_0 | ENEFLAG_UNK_1;
    do {
      if ((Enemy_IsDead(p) != 0) || ((p->flags & mask) != 0)) {
        node = node->next;
        p = node->enemy;
      } else {
        node = node->next;
        p = node->enemy;
        count++;
      }
    } while (p != NULL);
  }
  return count;
}

// 87/87 命令, ループの外へ出す定数が 3 でなく 0x4000 になる
NON_MATCH void FUN_080ec9b0(EnemyManager* p) {
#ifdef NONMATCHING_C
  s32 count = FUN_080ec968();

  if (count > 0) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* enemy = node->enemy;
    s32 n = 0;
    s32 limit;
    s32 wait;
    EnemyFlags mask;

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

    if (enemy != NULL) {
      mask = ENEFLAG_UNK_0 | ENEFLAG_UNK_1;
      do {
        if (Enemy_IsDead(enemy) != 0 || (enemy->flags & mask) != 0) {
          enemy->unk_48e = 0;
        } else {
          u8* timer = &enemy->unk_48e;

          if (*timer != 0) {
            *timer -= 1;
          } else if (n < limit) {
            *timer = wait;
            Enemy_SetFlag4(enemy, ENEFLAG4_UNK_14);
            n++;
          }
        }
        node = node->next;
        enemy = node->enemy;
      } while (enemy != NULL);
    }
  }
#else
  INCFUNC("asm/func/FUN_080ec9b0.inc");
#endif
}

void FUN_080eca74(EnemyManager* p, Enemy* enemy) {
  if (enemy->kind == 2) {
    if (!EnemyManager_TestFlag(p, 8)) {
      Entity* e = Entity080db520_Create();

      p->sharedEntity[0] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, 8);
      p->sharedEntityId[0] = e->id;
    }
    enemy->unk_260 = p->sharedEntity[0];
    if (enemy->variant == 1) {
      if (!EnemyManager_TestFlag(p, 16)) {
        Entity* e = SpiderVenom_Create();

        p->sharedEntity[1] = e;
        if (e == NULL) {
          return;
        }
        SET_FLAGS(p->flags, 16);
        p->sharedEntityId[1] = e->id;
      }
      enemy->unk_260 = p->sharedEntity[1];
    }
  } else if (!EnemyManager_TestFlag(p, 32)) {
    Entity* e = EmoteManager_Create();

    p->sharedEntity[2] = e;
    if (e == NULL) {
      return;
    }
    SET_FLAGS(p->flags, 32);
    p->sharedEntityId[2] = e->id;
  }
  if (enemy->kind == 3) {
    Entity080dbe54_Create(0, 0);
  }
  if (enemy->kind == 14) {
    if (!EnemyManager_TestFlag(p, 0x800)) {
      Entity* e = Entity081ea120_Create(0, 0);

      p->sharedEntity[6] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, 0x800);
      p->sharedEntityId[6] = e->id;
    }
    enemy->unk_264 = p->sharedEntity[6];
    if (!EnemyManager_TestFlag(p, 0x1000)) {
      Entity* e = Entity081ea820_Create();

      p->sharedEntity[7] = e;
      if (e == NULL) {
        return;
      }
      SET_FLAGS(p->flags, 0x1000);
      p->sharedEntityId[7] = e->id;
    }
    enemy->unk_260 = p->sharedEntity[7];
  }
}

void FUN_080ecbe4(void) {}

// 343/344 命令, flags のアドレスを別レジスタへ写す位置が違う
NON_MATCH void FUN_080ecbe8(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  EnemyFlags3* flags3;

  Enemy_ClearFlag2(p, 4);
  flags3 = &p->flags3;
  CLEAR_FLAGS(*flags3, 0x4000);
  switch (param_2) {
    case 0: {
      EnemyFlags* flags;
      Vec3 pos;
      NavAgent* agent;
      WorldPos* cur;
      s32 route;

      SET_FLAGS(p->flags, 16);
      pos.x = p->pathWalker.node->x;
      pos.z = p->pathWalker.node->y;
      pos.y = TileHeightAt(&pos);
      flags = &p->flags;
      pos.y = p->mover.pos.y;
      agent = p->navAgent;
      cur = &p->mover.pos;
      if (!Map_IsPosInAgentIsland(agent, cur, &pos) || (route = Map_TryFindNavRoute(agent, cur, &pos)) == 0) {
        CLEAR_FLAGS(*flags3, 0x200);
      } else if (route != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
      p->unk_4a8->val = 1;
      if (!Enemy_IsPosInRect(p, &pos, 32, 32)) {
        CLEAR_FLAGS(*flags, 0xC0);
        Enemy_RequestSubState(p, 0, 0, 7);
        Enemy_RequestState(p, p->unk_5a0, 1);
      } else {
        CLEAR_FLAGS(*flags, 0xD0);
        Enemy_RequestSubState(p, 0, 0, 0);
        Enemy_RequestState(p, p->unk_5a4, 0);
      }
      p->animSpeedDiv = 1;
      break;
    }
    case 1: {
      NavAgent* agent;
      WorldPos* cur;
      WorldPos* dst;
      s32 route;

      if (p->kind != 2) {
        SET_FLAGS(p->unk_222, 4);
      }
      SET_FLAGS(*flags3, 0x80);
      p->unk_24e = p->unk_24c;
      Enemy_PlayAnim(p, 0);
      agent = p->navAgent;
      cur = &p->mover.pos;
      dst = &gPlayerPtr[0]->mover.pos;
      if (!Map_IsPosInAgentIsland(agent, cur, dst) || (route = Map_TryFindNavRoute(agent, cur, dst)) == 0) {
        CLEAR_FLAGS(*flags3, 0x200);
      } else if (route != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
      Enemy_RequestSubState(p, 0, 0, 12);
      Enemy_RequestState(p, p->unk_5b8, 26);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080ecbe8.inc");
#endif
}

// 生きている敵の数を数える
s32 FUN_080ecf18(void) {
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
    if (p->hp > 0 && !Enemy_TestFlag2(p, 0x20000) && p->kind == kind) {
      count++;
    }
    node = node->next;
    p = node->enemy;
  }

  return count;
}

// 46/46 命令, variant の読み出しで add r7, #0x63 にならない
NON_MATCH s32 FUN_080ecfbc(u32 kind, u32 variant) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;
  s32 count;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  count = 0;
  while (p != NULL) {
    if (p->hp > 0 && !Enemy_TestFlag2(p, 0x20000) && p->kind == kind && p->variant == variant) {
      count++;
    }
    node = node->next;
    p = node->enemy;
  }

  return count;
#else
  INCFUNC("asm/func/FUN_080ecfbc.inc");
#endif
}

// 生きている敵を先頭から1体返す
Enemy* FUN_080ed020(u32 _) {
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

void FUN_080ed068(void) {
  EnemyListNode* node;
  Enemy* enemy;

  GetEnemyManager();
  node = gEnemyListHead;
  enemy = node->enemy;
  if (enemy != NULL) {
    do {
      if (!Enemy_IsDead(enemy)) {
        enemy->hp = 0;
        Enemy_SetFlag(enemy, ENEFLAG_UNK_12);
      }
      node = node->next;
      enemy = node->enemy;
    } while (enemy != NULL);
  }
}

// 480/508 命令, ループの出口の形と表示判定の分岐が未解決, 下書き段階
NON_MATCH void FUN_080ed0b0(s32 damage) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;

  GetEnemyManager();
  for (node = (EnemyListNode*)&gEnemyListHead; node = node->next, (p = node->enemy) != NULL;) {
    EnemyFlags* flags;
    EnemyFlags3* flags3;
    u32* expMask;
    u16* flags5;
    s32 dx;
    s32 dz;

    if (Enemy_IsDead(p) != 0) {
      continue;
    }

    flags = &p->flags;
    CLEAR_FLAGS(*flags, 0x141C0);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    {
      u16* table = gRandomTable;
      s32 idx = (gRandTableIdx + 1) & 0x3FF;

      dx = (table[idx] & 63) - 16;
      idx = (idx + 1) & 0x3FF;
      gRandTableIdx = idx;
      dz = (table[idx] & 63) - 16;
    }
    p->hitbox.damage = damage;
    p->unk_48a = damage;
    p->hp -= p->hitbox.damage;
    expMask = &p->weaponExpMask;
    if (!(*expMask & 0x4000)) {
      bool8 show;

      if (p->spriteKind == 0) {
        Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)p->sprite)->gfx, p->unk_47c);
      } else {
        p->sprite->s.pltt = &gObjPlttData[p->unk_47c * 16];
      }
      p->unk_492 = 8;
      SET_FLAGS(*flags, 0x8000);
      show = TRUE;
      if ((gGameFlags & 0x4800) && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
        switch (gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1) {
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

        FUN_0809c344(p->mover.id, p->hp, p->maxHp, p->unk_25a, 0);
        CpuFill32(0, &v, sizeof(v));
        if (p->unk_48a != 0 || !(*expMask & 0x4000)) {
          CreateDamageNumber(&p->hitbox, p->unk_48a, 0, &p->mover.pos, &v, 1);
        }
      }
    }
    FUN_080e5098(p, dx, dz);
    flags3 = &p->flags3;
    SET_FLAGS(*flags3, 8);
    p->mover.angle = ArcTan2_8(dx, dz);
    p->hitbox.invincibleTime = 38;
    p->unk_4be = 0;
    if (p->hp < 1) {
      Enemy_RequestState(p, p->unk_5d0, 17);
      Enemy_RequestSubState(p, 3, 0, 0);
      p->unk_4a0 = 1;
      if (!(gGameFlags & 0x4800)) {
        flags5 = &p->flags5;
        if ((p->unk_4a0 & 1) && !(*flags5 & 0x80)) {
          if ((p->kind != 14 || p->variant != 1) && p->kind != 5 && p->kind != 7 && p->kind != 6) {
            gStat->unk_948[0] = gStat->unk_948[0] < 9999 ? gStat->unk_948[0] + 1 : 9999;
            gStat->totalEnemyKillCount = gStat->totalEnemyKillCount < 9999 ? gStat->totalEnemyKillCount + 1 : 9999;
            FUN_080e9178(p);
          }
          AddPlayerExp(p->exp);
          Player_AddWeaponExp(*expMask, p->weaponExp);
        }
        if (!(*flags5 & 0x80) && !(gGameFlags & 0x4800) && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
          FUN_080ec5b4(gMapInitScriptID, p->mover.id);
        }
        SET_FLAGS(p->hitbox.flags, 4);
      } else {
        FUN_080ce544(p->unk_4a0, *expMask);
      }
    } else {
      SET_FLAGS(*flags3, 32);
      Enemy_RequestState(p, p->unk_5cc, 18);
      Enemy_RequestSubState(p, 3, 0, 0);
    }
    SET_FLAGS(*flags, 0x2000);
  }
#else
  INCFUNC("asm/func/FUN_080ed0b0.inc");
#endif
}

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
  if (p != NULL) {
    do {
      if (Enemy_TestFlag(p, 2) && p->hp > 0) {
        if (kind == 0 || kind == p->kind) {
          p->hp = 0;
          p->unk_192 = 0;
          p->mover.pos.x = 0;
          p->mover.pos.y = 30000;
          p->mover.pos.z = 0;
          Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
          Enemy_RequestState(p, Enemy_ClearStateBegun, 16);
          Enemy_RequestSubState(p, 3, 0, 0);
          FUN_080e49c4(p);
          if (!(gGameFlags & 0x4800) && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
            FUN_080ec5b4(gMapInitScriptID, p->mover.id);
          }
        }
      } else if (Enemy_IsDead(p) == 0 && (kind == 0 || kind == p->kind)) {
        p->hp = 0;
        p->unk_192 = 0;
        Enemy_SetFlag(p, ENEFLAG_UNK_12);
        if (removeFlag != 0) {
          p->flags2 |= ENEFLAG2_UNK_22;
        }
      }
      node = node->next;
      p = node->enemy;
    } while (p != NULL);
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

      if (kind == 4 || kind == 1 || kind == 3 || kind == 10) {
        Enemy_RequestState(p, p->unk_5c0, 5);
        Enemy_RequestSubState(p, 0, 0, 3);
        SET_FLAGS(p->flags2, 0x1000);
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
    if (p != NULL && p->unk_594 != NULL) {
      p->unk_192 = p->unk_190;
      Enemy_SetFlag4(p, ENEFLAG4_UNK_1);
    }
  }
}

void Cmd_62AA(void) {
  u32 id = VM_GetNamedArgValue('n', 0);
  s32 mode = VM_GetNamedArgValue('m', 0);

  if (id != 0) {
    Enemy* p = FindEnemyById(id);

    if (p != NULL && Enemy_TestFlag5(p, 0x100)) {
      Enemy_RequestSubState(p, 2, 0, 0);
      if (mode == 0) {
        Enemy_RequestState(p, Enemy_ClearStateBegun, 16);
      }
      SET_FLAGS(p->flags3, 0x4000);
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
      if (!Enemy_IsDead(p) && Enemy_TestFlag5(p, 0x100)) {
        Enemy_RequestSubState(p, 2, 0, 0);
        if (mode == 0) {
          Enemy_RequestState(p, Enemy_ClearStateBegun, 16);
        }
        SET_FLAGS(p->flags3, 0x4000);
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

      if ((kind == 4 || kind == 1 || kind == 3 || kind == 10) && !TEST_FLAGS(p->flags3, 0xA007)) {
        Enemy_RequestState(p, Enemy_ClearStateBegun, 16);
        Enemy_RequestSubState(p, 0, 1, 0);
      }
    }
    node = node->next;
    p = node->enemy;
  }
}

// 経路ノード周辺にプレイヤーがいるかを返す
bool32 FUN_080edb4c(Enemy* p, Vec3* pos) {
  Vec3 node;
  Vec3 diff;
  Vec3 closest;
  s32 best = 0x7FFFFFFF;
  s32 found = -1;
  s32 i;

  if (p->kind == 11) {
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

      if ((kind == 4 || kind == 1 || kind == 3) && p->state != 21) {
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

// id の敵を見つけた後ろから, ENEFLAG_UNK_0 が落ちている最初の敵を返す
// 残差1命令, 定数 1 の movs がループ入口の前に出るか中に出るかだけ違う (命令列は 31 対 31)
NON_MATCH Enemy* FUN_080edce8(u32 id) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;
  Enemy* p = node->enemy;

  while (p != NULL) {
    if ((p->flags & ENEFLAG_UNK_0) == 0 && id == 0) {
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
  INCFUNC("asm/func/FUN_080edce8.inc");
#endif
}

// 48/50 命令, id を r3 に残す形と kind の比較の並びが未解決
NON_MATCH Enemy* FUN_080edd2c(u32 id) {
#ifdef NONMATCHING_C
  EnemyListNode* node;
  Enemy* p;

  for (node = gEnemyListHead; (p = node->enemy) != NULL; node = node->next) {
    if (!(p->flags & ENEFLAG_UNK_0) && id == 0) {
      u8 kind = p->kind;

      if (kind == 4 || kind == 1 || kind == 3 || kind == 5 || kind == 7 || kind == 6 || kind == 10 || kind == 21) {
        return p;
      }
    }
    if (p->mover.id == id) {
      id = 0;
    }
  }

  return NULL;
#else
  INCFUNC("asm/func/FUN_080edd2c.inc");
#endif
}

Enemy* GetFirstEnemy(void) { return gEnemyListHead->enemy; }

Enemy* FindEnemyById(u32 id) {
  EnemyListNode* node;
  Enemy* p;

  for (node = gEnemyListHead; (p = node->enemy) != NULL; node = node->next) {
    if (p->mover.id == id) {
      return p;
    }
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

bool32 Cmd_6790(void) {
  u32 id = VM_GetValue();

  if ((id != 0) && (FindEnemyById(id) != NULL)) {
    return TRUE;
  }
  return FALSE;
}

// 指定した種族で flags に mask のビットが立っている敵が1体でもいるかを返す
NON_MATCH bool32 FUN_080ede14(u32 kind, u32 mask) {
#ifdef NONMATCHING_C
  Enemy* p;

  for (p = GetFirstEnemy(); p != NULL; p = FUN_080edce8(p->mover.id)) {
    if ((p->kind == kind) && (Enemy_IsDead(p) == 0) && ((p->flags & mask) != 0)) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080ede14.inc");
#endif
}

// 40/40 命令, return TRUE のブロックがループの前に出ない, FUN_080ede14 と同じ
NON_MATCH bool32 FUN_080ede60(u32 kind, u32 variant, u32 mask) {
#ifdef NONMATCHING_C
  Enemy* p = GetFirstEnemy();

  while (p != NULL) {
    if (p->kind == kind && p->variant == variant && Enemy_IsDead(p) == 0 && (p->flags & mask) != 0) {
      return TRUE;
    }
    p = FUN_080edce8(p->mover.id);
  }

  return FALSE;
#else
  INCFUNC("asm/func/FUN_080ede60.inc");
#endif
}

// 364/368 命令, レジスタ割当とループの出口の形が違う
NON_MATCH void FUN_080edebc(EnemyManager* p) {
#ifdef NONMATCHING_C
  EnemyListNode* node = gEnemyListHead;

  if (node != NULL) {
    Enemy* enemy = node->enemy;

    while (TRUE) {
      EnemyFlags3* flags3;
      bool8 test;

      if (enemy == NULL) {
        return;
      }
      if ((enemy->flags4 & 0x1000)) {
        void* arg;

        node = node->next;
        arg = enemy->unk_1cc;
        enemy->handlerDestroy(arg);
        Free(arg);
        enemy = node->enemy;
        continue;
      }

      enemy->handlerUpdate(enemy->unk_1cc);
      test = (gGameFlags & 0x4800) != 0;
      flags3 = &enemy->flags3;
      if (!test && !TEST_FLAGS(*flags3, 0x4000) && !TEST_FLAGS(enemy->flags2, 8) && enemy->unk_46f != 0) {
        EnemyFlags* flags;
        EnemyFlags active = Enemy_TestFlag(enemy, 2);

        flags = &enemy->flags;
        if (!active && (gStat->mapFlags & 2) && gStat->zoneID == enemy->zoneID && Enemy_IsDead(enemy) == 0 && gStat->sunGauge > 0 && gSunGaugeOverride != 1) {
          enemy->hitbox.invincibleTime = 0;
          enemy->unk_4be = 0;
          Enemy_ClearSpriteFlags(enemy, SPRFLAG_HIDDEN);
          enemy->hp = 0;
          FUN_080e64e4(enemy);
          *flags3 &= ~0x2000;
          *flags |= ENEFLAG_UNK_12;
        }
      }
      if (!TEST_FLAGS(enemy->flags3, 0x4000) && EnemyManager_TestFlag(p, 0x2000)) {
        u8 kindValue = enemy->kind;
        u8* kind = &enemy->kind;

        switch (kindValue) {
          case 11:
          case 23:
          case 27: {
            if (!TEST_FLAGS(enemy->flags, 0x2008000)) {
              if (enemy->spriteKind == 0) {
                enemy->sprite->s.unk_12 = enemy->unk_478;
              } else {
                enemy->sprite->s.plttID = enemy->unk_478;
              }
            }
            if (FUN_080eec74(p, enemy)) {
              if (p->flags & 0x20000) {
                u32 plttID;

                p->flags &= ~0x22000;
                enemy->flags2 &= ~0x200000;
                plttID = enemy->unk_47a + enemy->variant;
                if (enemy->spriteKind == 0) {
                  Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)enemy->sprite)->gfx, plttID);
                } else {
                  enemy->sprite->s.pltt = &gObjPlttData[plttID * 16];
                }
              } else {
                EnemyFlags2* flags2 = &enemy->flags2;

                if (*flags2 & 0x200000) {
                  FUN_080eeb14(enemy->unk_478, enemy->unk_47a + enemy->variant, 0, *kind, 0);
                  *flags2 &= ~0x200000;
                } else {
                  FUN_080eeb14(enemy->unk_47a + enemy->variant, enemy->unk_478, 0, *kind, 0);
                  *flags2 |= 0x200000;
                }
              }
            }
            break;
          }
        }
      }
      node = node->next;
      enemy = node->enemy;
    }
  }
#else
  INCFUNC("asm/func/FUN_080edebc.inc");
#endif
}

// 生存中の敵をすべて破棄する
void FUN_080ee218(void) {
  EnemyListNode* node = gEnemyListHead;
  Enemy* p;
  void* arg;

  if (node != NULL) {
    while ((p = node->enemy) != NULL) {
      node = node->next;
      arg = p->unk_1cc;
      p->handlerDestroy(arg);
      Free(arg);
    }
  }
}

// 43/50 命令, ENEFLAG_UNK_0 の判定も bool8 inline を通している
NON_MATCH void FUN_080ee254(void) {
#ifdef NONMATCHING_C
  if ((gGameFlags & 0x4800) && gEnemyListHead != NULL) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* p = node->enemy;

    while (p != NULL) {
      node = node->next;
      if (p->hp <= 0 && (p->flags & ENEFLAG_UNK_0) && !FUN_080edb4c(p, (Vec3*)s16_ARRAY_085ad3cc)) {
        FUN_080ee738(p);
      }
      p = node->enemy;
    }
  }
#else
  INCFUNC("asm/func/FUN_080ee254.inc");
#endif
}

// 敵を初期状態へ戻す
void FUN_080ee2c8(Enemy* p) {
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
  p->unk_256 = GetCollisionTileIdx(&p->mover.pos);
  p->mover.pos.y = Enemy_TileHeight(p->unk_256, &p->mover.pos);
  kind = p->spriteKind;
  spriteKind = &p->spriteKind;
  if (kind == 0) {
    ((AuxSprite*)p->sprite)->pos = p->mover.pos;
  } else {
    p->sprite->s.pos = p->mover.pos;
  }
  p->mover.angle = p->unk_564;
  p->heightAboveFloor = 0;
  ClearMemory(&p->jumpVel, 8);
  ClearMemory(&p->mover.delta, 8);
  active = TEST_FLAGS(p->flags, 0x200000);
  flags = &p->flags;
  flags2 = &p->flags2;
  if (active) {
    CLEAR_FLAGS(*flags2, 0x1000000);
    CLEAR_FLAGS(p->flags3, 0x200);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  plttID = p->unk_47a + p->variant;
  if (*spriteKind == 0) {
    Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)p->sprite)->gfx, plttID);
  } else {
    p->sprite->s.pltt = &gObjPlttData[plttID * 16];
  }
  CLEAR_FLAGS(*flags, 0x2008000);
  CLEAR_FLAGS(*flags2, 0x41C0);
  Hitbox_SetPos(&p->atkHitbox, &p->mover.pos, 0);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  p->hitbox.flags &= ~4;
  p->unk_494 = 0;
  p->unk_492 = 0;
  priority = 2;
  if (*spriteKind == 0) {
    ((AuxSprite*)p->sprite)->priority = priority;
  } else {
    p->sprite->s.priority = priority;
  }
  p->hitbox.invincibleTime = 0;
}

// 敵を初期状態へ戻す
void FUN_080ee538(Enemy* p) {
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
  p->unk_256 = GetCollisionTileIdx(&p->mover.pos);
  p->mover.pos.y = Enemy_TileHeight(p->unk_256, &p->mover.pos);
  kind = p->spriteKind;
  spriteKind = &p->spriteKind;
  if (kind == 0) {
    ((AuxSprite*)p->sprite)->pos = p->mover.pos;
  } else {
    p->sprite->s.pos = p->mover.pos;
  }
  p->heightAboveFloor = 0;
  ClearMemory(&p->jumpVel, 8);
  ClearMemory(&p->mover.delta, 8);
  active = TEST_FLAGS(p->flags, 0x200000);
  flags = &p->flags;
  flags2 = &p->flags2;
  if (active) {
    CLEAR_FLAGS(*flags2, 0x1000000);
    CLEAR_FLAGS(p->flags3, 0x200);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  plttID = p->unk_47a + p->variant;
  if (*spriteKind == 0) {
    Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)p->sprite)->gfx, plttID);
  } else {
    p->sprite->s.pltt = &gObjPlttData[plttID * 16];
  }
  CLEAR_FLAGS(*flags, 0x2008000);
  CLEAR_FLAGS(*flags2, 0x41C0);
  p->unk_494 = 0;
  p->unk_492 = 0;
  priority = 2;
  if (*spriteKind == 0) {
    ((AuxSprite*)p->sprite)->priority = priority;
  } else {
    p->sprite->s.priority = priority;
  }
}

// 268/277 命令, 状態フィールドのアドレスを保持して使い回す形が inline では作れない
NON_MATCH void FUN_080ee738(Enemy* p) {
#ifdef NONMATCHING_C
  FUN_080ee2c8(p);
  Enemy_RequestSubState(p, 3, 0, 0);
  Enemy_RequestState(p, Enemy_ClearStateBegun, 16);
  p->flags = p->unk_55c;
  p->flags2 = p->unk_560;
  p->mover.angle = p->unk_564;
  p->subState0 = p->unk_565;
  p->subState1 = p->unk_566;
  p->subState2 = p->unk_567;
  p->handlerState = p->unk_568;
  p->state = p->unk_56c;
  p->flags5 = p->unk_572;
  p->heightAboveFloor = p->unk_570;
  p->hp = p->maxHp;
  p->flags4 = 0;
  p->unk_222 = 0;
  p->flags3 = 0;
  p->subStateDone = FALSE;
  p->subStateBegun = TRUE;
  p->stateBegun = TRUE;
  p->animForceRestart = FALSE;
  p->unk_24e = 0;
  p->unk_192 = 0;
  p->unk_544 = 0;
  p->nodeWait = 0;
  p->unk_1d4 = 0;
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
  ClearMemory(p->unk_458, 8);
  p->unk_464 = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, s_eneinline_h_08251f68, 2434);
  p->unk_540 = 0;
  p->unk_541 = 0;
  p->unk_542 = 0xFF;
  p->unk_548 = NULL;
  p->unk_54c = 0;
  p->unk_54d = 0;
  p->unk_54e = 0;
  p->unk_54f = 0;
  FUN_080eeee0(p);
  p->flags |= 2;
  p->hitbox.flags |= 4;
  if (p->unk_5f8 != NULL) {
    p->unk_5f8(p);
  }
  FUN_080eeee0(p);
  p->emote = Emote_Remove(p->emote, 1, p->mover.id);
  p->emote = Emote_RemovePtcl(p->emote, 3, p->mover.id);
  FUN_080ecbe4();
#else
  INCFUNC("asm/func/FUN_080ee738.inc");
#endif
}

void FUN_080ee9d4(EnemyManager* p) {
  if (Mod(p->frameCounter, 15) == 0) {
    if (EntityA628_IsActive() == 0) {
      SET_FLAGS(gStat->mapFlags, MPF_BRIGHT);
    } else {
      CLEAR_FLAGS(gStat->mapFlags, MPF_BRIGHT);
    }
  }
}

s32 EnemyManager_Update(EnemyManager* p) {
  FUN_080ee254();
  FUN_080ec8a4(p);
  FUN_080ec92c(p);
  FUN_080ec9b0(p);
  FUN_080edebc(p);
  FUN_080ee9d4(p);
  CLEAR_FLAGS(p->flags, EMFLAG_UNK_14 | EMFLAG_UNK_15 | EMFLAG_UNK_16);
  p->frameCounter++;
  return 0;
}

s32 EnemyManager_Destroy(EnemyManager* p) {
  FUN_080ee218();
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

void FUN_080eeb08(void) { gEnemyManager = NULL; }

// レジスタ割当とループ外へ出すアドレスの組が違う, 下書き段階
NON_MATCH void FUN_080eeb14(u32 plttDst, u32 plttSrc, u32 _, s32 kind, u32 immediate) {
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
    case 23: {
      fade = &manager->palFade[1];
      break;
    }
    case 11: {
      fade = &manager->palFade[0];
      break;
    }
    case 27: {
      fade = &manager->palFade[2];
      break;
    }
    default: {
      return;
    }
  }

  FUN_080ed020(kind);
  pltt = gObjPlttData;
  fade->plttID = plttDst;
  dst = &pltt[plttDst * 16];
  src = &pltt[plttSrc * 16];
  for (i = 0; i < 16; i++) {
    u16 color;
    u32 r;
    u32 g;
    u32 b;

    if (EnemyManager_TestFlag(manager, 0x2000) && fade->timer != 32) {
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
  manager->flags |= 0x2000;
  fade->timer = 32;
  if (immediate == 0) {
    manager->flags &= ~0x20000;
  } else {
    manager->flags |= 0x20000;
  }
#else
  INCFUNC("asm/func/FUN_080eeb14.inc");
#endif
}

// ループ内のアドレスの持ち方とレジスタ割当が違う
NON_MATCH bool8 FUN_080eec74(EnemyManager* p, Enemy* enemy) {
#ifdef NONMATCHING_C
  EnemyPaletteFade* fade;
  bool8 skip;

  if (Enemy_IsDead(enemy) != 0 || !EnemyManager_TestFlag(p, 0x2000)) {
    return FALSE;
  }

  skip = FALSE;
  switch (enemy->kind) {
    case 23: {
      fade = &p->palFade[1];
      if (EnemyManager_TestFlag(p, 0x8000)) {
        skip = TRUE;
      }
      break;
    }
    case 11: {
      fade = &p->palFade[0];
      if (EnemyManager_TestFlag(p, 0x4000)) {
        skip = TRUE;
      }
      break;
    }
    case 27: {
      fade = &p->palFade[2];
      if (EnemyManager_TestFlag(p, 0x10000)) {
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
    if (!TEST_FLAGS(enemy->flags, 0x2008000)) {
      if (enemy->spriteKind == 0) {
        *(EnemyPaletteFade**)&enemy->sprite->s.animFlags = fade;
      } else {
        enemy->sprite->s.pltt = fade->pltt;
      }
    }
  } else {
    EnemyFlags* flags = &enemy->flags;

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
        case 23: {
          SET_FLAGS(p->flags, 0x8000);
          break;
        }
        case 11: {
          SET_FLAGS(p->flags, 0x4000);
          break;
        }
        case 27: {
          SET_FLAGS(p->flags, 0x10000);
          break;
        }
      }
    }
    if (!TEST_FLAGS(*flags, 0x2008000)) {
      if (enemy->spriteKind == 0) {
        *(EnemyPaletteFade**)&enemy->sprite->s.animFlags = fade;
      } else {
        enemy->sprite->s.pltt = fade->pltt;
      }
    }
    if (fade->timer != 0) {
      return FALSE;
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080eec74.inc");
#endif
}

// 37/47 命令, 判定を bool 変数に受ける形が未解決
NON_MATCH bool32 FUN_080eee70(void) {
#ifdef NONMATCHING_C
  if (gEnemyManager != NULL && (gEnemyManager->flags & 0x2000)) {
    if (gGameFlags & 0x4800) {
      if (Enemy_CountByKind(11) != 0) {
        return 0;
      }
    } else {
      if (Enemy_CountByKind(11) != 0 || Enemy_CountByKind(23) != 0 || Enemy_CountByKind(27) != 0) {
        return 0;
      }
    }
  }

  return 1;
#else
  INCFUNC("asm/func/FUN_080eee70.inc");
#endif
}

// 45/58 命令, FUN_080ede14 の結果の受け方と判定の並びが未解決
NON_MATCH void FUN_080eeee0(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyManager* manager = gEnemyManager;

  if (manager != NULL && (manager->flags & 0x2000)) {
    s32 count;

    if (gGameFlags & 0x4800) {
      count = Enemy_CountByKind(11);
    } else {
      if (FUN_080ede14(11, 0x20000)) {
        return;
      }
      if (FUN_080ede14(23, 0x20000)) {
        return;
      }
      count = FUN_080ede14(27, 0x20000);
    }
    if (count == 0) {
      manager->flags &= ~0x22000;
    }
  }
#else
  INCFUNC("asm/func/FUN_080eeee0.inc");
#endif
}

// 57/58 命令, spriteKind が 0 以外の枝で p->sprite の持ち方が違う
NON_MATCH void FUN_080eef6c(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyPaletteFade* fade;

  if (gEnemyManager == NULL) {
    return;
  }

  switch (p->kind) {
    case 23: {
      fade = &gEnemyManager->palFade[1];
      break;
    }
    case 11: {
      fade = &gEnemyManager->palFade[0];
      break;
    }
    case 27: {
      fade = &gEnemyManager->palFade[2];
      break;
    }
    default: {
      return;
    }
  }

  if (fade->timer != 0) {
    if (p->spriteKind == 0) {
      p->sprite->s.unk_12 = p->unk_478;
      *(EnemyPaletteFade**)&p->sprite->s.animFlags = fade;
    } else {
      MainSprite* sprite = &p->sprite->s;

      sprite->plttID = p->unk_478;
      sprite->pltt = fade->pltt;
    }
  }
#else
  INCFUNC("asm/func/FUN_080eef6c.inc");
#endif
}

// '.n' の敵に '.r' の2値を入れる
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
  p->unk_256 = GetCollisionTileIdx(&p->mover.pos);
  height = Enemy_TileHeight(p->unk_256, &p->mover.pos);
  p->floorY = height;
  p->heightAboveFloor = p->mover.pos.y - height;
  p->mover.pos.y = p->floorY;
}

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
        p->atkUnk40[i] = value;
      }
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkAttrs[i] = value;
      }
      value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
      if (value >= 0) {
        p->atkInvincibleTime[i] = value;
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
      p->unk_190 = value;
    }
    value = VM_GetPC() != NULL ? (s32)VM_GetValue() : -1;
    if (value >= 0) {
      p->unk_24c = value;
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
    p->unk_19a = VM_GetNamedArgValue('D', 0);
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

void Cmd_9311(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->flags |= (u16)VM_GetNamedArgValue('s', 0);
  }
}

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
  Vec3 target;
  Vec3 diff;

  if (gEnemyListHead != NULL) {
    EnemyListNode* node = gEnemyListHead;
    Enemy* p = node->enemy;

    if (p != NULL) {
      do {
        if (p->unk_46f != 1 || p->kind == ENEK_CURORO || p->kind == ENEK_BAT || p->kind == ENEK_CROW || p->kind == ENEK_BEE || p->kind == ENEK_SERPENT) {
          node = node->next;
          p = node->enemy;
          continue;
        }

        {
          MapTileOverride* ov = Map_FindTileOverride(p->unk_256, 1);
          CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[p->unk_256];

          if ((tile->attr & 0x40) && p->floorY >= p->mover.pos.y + p->heightAboveFloor) {
            if (Enemy_IsDead(p) == 0) {
              void* handler = p->unk_5d8;

              if (handler == NULL) {
                handler = FUN_080f54e4;
              }
              Enemy_RequestState(p, handler, 22);
              Enemy_RequestSubState(p, 3, 0, 0);
              p->flags2 |= 0x20000;
            }
          } else if ((tile->attr & 0x80) && TEST_FLAGS(gStat->mapFlags, MPF_HOT) && p->hitbox.invincibleTime == 0) {
            s32 col = Mod(p->unk_256, gCollisionMap->tiledata->width);
            s32 row = Div(p->unk_256, gCollisionMap->tiledata->width);

            target.x = col * 256 + 128;
            ov = Map_FindTileOverride(p->unk_256, 1);
            tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[p->unk_256];
            target.y = (tile->heightStairs & 15) << 8;
            target.z = row * 256 + 128;
            Vec3_Diff(&diff, &target, &p->mover.pos);
            p->angle = ArcTan2_8(diff.x, diff.z) >> 5;
            p->unk_4a0 = 32;
            p->hitbox.damage = p->hp;
            p->unk_48a = p->hp;
            p->hitbox.knockbackPower = 40;
            p->weaponExpMask = 64;
            p->unk_48c = 1;
            p->flags |= 0x2000;
          }
        }
        node = node->next;
        p = node->enemy;
      } while (p != NULL);
    }
  }
#else
  INCFUNC("asm/func/Cmd_1E97.inc");
#endif
}

EnemyManager* GetEnemyManager(void) { return gEnemyManager; }
