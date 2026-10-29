#include "enemy_manager.h"

#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "vm.h"

u32 EntityA628_IsActive(void);

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

NAKED bool32 Enemy_Init_080ec640(Enemy* p) { INCFUNC("asm/func/Enemy_Init_080ec640.inc"); }

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

NAKED void FUN_080ec7e8(u8 kind, u8 variant, void* payload) { INCFUNC("asm/func/FUN_080ec7e8.inc"); }

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

NAKED void FUN_080ec8a4(EnemyManager* p) { INCFUNC("asm/func/FUN_080ec8a4.inc"); }

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

NAKED void FUN_080ec9b0(EnemyManager* p) { INCFUNC("asm/func/FUN_080ec9b0.inc"); }

NAKED void FUN_080eca74(EnemyManager* p, Enemy* enemy) { INCFUNC("asm/func/FUN_080eca74.inc"); }

void FUN_080ecbe4(void) {}

NAKED void FUN_080ecbe8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080ecbe8.inc"); }

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
NAKED s32 Enemy_CountByKind(u32 kind) { INCFUNC("asm/func/Enemy_CountByKind.inc"); }

NAKED s32 FUN_080ecfbc(u32 kind, u32 variant) { INCFUNC("asm/func/FUN_080ecfbc.inc"); }

// 生きている敵を先頭から1体返す
Enemy* FUN_080ed020(void) {
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

NAKED void FUN_080ed0b0(s32 param_1) { INCFUNC("asm/func/FUN_080ed0b0.inc"); }

NAKED void Cmd_C12A(void) { INCFUNC("asm/func/Cmd_C12A.inc"); }

NAKED void Cmd_7659(void) { INCFUNC("asm/func/Cmd_7659.inc"); }

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

NAKED void Cmd_62AA(void) { INCFUNC("asm/func/Cmd_62AA.inc"); }

NAKED void Cmd_4FD1(void) { INCFUNC("asm/func/Cmd_4FD1.inc"); }

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

NAKED void Cmd_286B(void) { INCFUNC("asm/func/Cmd_286B.inc"); }

NAKED bool32 FUN_080edb4c(Enemy* p, Vec3* pos) { INCFUNC("asm/func/FUN_080edb4c.inc"); }

NAKED Enemy* FUN_080edc40(Vec3* pos) { INCFUNC("asm/func/FUN_080edc40.inc"); }

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

NAKED Enemy* FUN_080edd2c(u32 id) { INCFUNC("asm/func/FUN_080edd2c.inc"); }

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

NAKED bool32 FUN_080ede60(u32 kind, u32 variant, u32 mask) { INCFUNC("asm/func/FUN_080ede60.inc"); }

NAKED void FUN_080edebc(EnemyManager* p) { INCFUNC("asm/func/FUN_080edebc.inc"); }

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

NAKED void FUN_080ee254(void) { INCFUNC("asm/func/FUN_080ee254.inc"); }

NAKED void FUN_080ee2c8(Enemy* p) { INCFUNC("asm/func/FUN_080ee2c8.inc"); }

NAKED void FUN_080ee538(Enemy* p) { INCFUNC("asm/func/FUN_080ee538.inc"); }

NAKED void FUN_080ee738(Enemy* p) { INCFUNC("asm/func/FUN_080ee738.inc"); }

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

NAKED void FUN_080eeb14(u32 plttDst, u32 plttSrc, u32 _, u8 kind, u32 immediate) { INCFUNC("asm/func/FUN_080eeb14.inc"); }

NAKED bool32 FUN_080eec74(EnemyManager* p, Enemy* enemy) { INCFUNC("asm/func/FUN_080eec74.inc"); }

NAKED bool32 FUN_080eee70(void) { INCFUNC("asm/func/FUN_080eee70.inc"); }

NAKED void FUN_080eeee0(Enemy* p) { INCFUNC("asm/func/FUN_080eeee0.inc"); }

NAKED void FUN_080eef6c(Enemy* p) { INCFUNC("asm/func/FUN_080eef6c.inc"); }

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

NAKED void Cmd_C7DC(void) { INCFUNC("asm/func/Cmd_C7DC.inc"); }

NAKED void Cmd_F200(void) { INCFUNC("asm/func/Cmd_F200.inc"); }

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

NAKED void Cmd_1E97(void) { INCFUNC("asm/func/Cmd_1E97.inc"); }

EnemyManager* GetEnemyManager(void) { return gEnemyManager; }
