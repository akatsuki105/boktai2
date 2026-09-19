#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "vm.h"

// エネミー全体の管理者. シングルトンで、生存中のエネミーを gEnemyListHead のリストで持つ
typedef struct EnemyManager {
  Entity e;                     // 0x00, ENTITY_UNK_8
  Unk_0203f400* msgRecords;     // 0x18, FUN_080ec8a4 が FUN_08230f94(msgRecordID, &msgRecords) で先頭を受け取り、戻り値の件数だけ走査する
  EnemyListNode* list;          // 0x1C, EnemyManager_InitList が Malloc(8) した番兵ノード. gEnemyListHead と同じ値
  EnemyListNode* cursor;        // 0x20, FUN_080ec92c が1フレームおきに1つ進める巡回カーソル
  u32 msgRecordID;              // 0x24, EnemyManager_Init の第2引数. FUN_08230f94 の検索キー
  u16 unk_28;                   // 0x28, 読み手も書き手も未発見
  u16 frameCounter;             // 0x2A, EnemyManager_Update が毎フレーム +1
  u32 flags;                    // 0x2C, bit3/4/5/11/12=sharedEntity の生成済みフラグ, bit13=パレット遷移中, bit14/15/16=種族 0x0B/0x17/0x1B を今フレーム更新済み(Updateで毎回クリア), bit17=遷移でなく即時差し替え
  u8 unk_30;                    // 0x30, EnemyManager_Init が 3、FUN_080ef584 が VM_GetKeywordValue(0x6C, 3) を代入. FUN_080ec5b4 がレコードの3語目へコピーする
  u8 unk_31;                    // 0x31, 読み手も書き手も未発見
  s16 enemyCount;               // 0x32, Enemy_Init_080ec640 で +1 / FUN_080ec6fc で -1. 0x13 を超えると新規生成を拒否する
  Entity* sharedEntity[8];      // 0x34, FUN_080eca74 が種族に応じて生成する共有エンティティのキャッシュ. [0]=Entity080db520, [1]=FUN_081e8d0c, [2]=FUN_080da848, [6]=FUN_081ea120, [7]=FUN_081ea820
  u16 sharedEntityId[8];        // 0x54, FUN_080eca74 が sharedEntity[i]->e.id を控える
  EnemyPaletteFade palFade[3];  // 0x64, FUN_080eeb14 が種族 0x0B/0x17/0x1B の順に添字 0/1/2 を選ぶ
} EnemyManager;
static_assert(sizeof(EnemyManager) == 640);

extern EnemyManager* gEnemyManager;  // 0x03002C5C

// 実体は src/code_080917e4.s
u32 FUN_080a0808(void);
u8 FUN_080e8a60(Enemy* p);

EnemyManager* GetEnemyManager(void);

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

NAKED bool32 Enemy_Init_080ec640(Enemy* enemy) { INCFUNC("asm/func/Enemy_Init_080ec640.inc"); }

NAKED void FUN_080ec6fc(Enemy* enemy) { INCFUNC("asm/func/FUN_080ec6fc.inc"); }

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

NAKED void FUN_080ec79c(u8 kind, void* payload) { INCFUNC("asm/func/FUN_080ec79c.inc"); }

NAKED void FUN_080ec7e8(u8 kind, u8 unk_480, void* payload) { INCFUNC("asm/func/FUN_080ec7e8.inc"); }

NAKED void FUN_080ec848(u8 kind, void* payload, u16 id) { INCFUNC("asm/func/FUN_080ec848.inc"); }

NAKED void FUN_080ec8a4(EnemyManager* p) { INCFUNC("asm/func/FUN_080ec8a4.inc"); }

void FUN_080ec900(u8 kind) {
  if ((kind == 1) || (kind == 0x19)) {
    u16 flag = 1;
    gStat->unk_934 |= flag;
  }
}

// 巡回カーソルを1つ進め、通りかかった敵に flags の bit3 を立てる
void FUN_080ec92c(EnemyManager* p) {
  EnemyListNode* cursor;
  EnemyListNode* next;
  u32 flag;

  if ((p->frameCounter & 1) == 0) {
    cursor = p->cursor;
    if ((cursor != NULL) && (cursor->enemy != NULL)) {
      flag = 8;
      cursor->enemy->flags |= flag;
      next = cursor->next;
    } else {
      next = gEnemyListHead;
    }
    p->cursor = next;
  }
}

NAKED s32 FUN_080ec968(void) { INCFUNC("asm/func/FUN_080ec968.inc"); }

NAKED void FUN_080ec9b0(EnemyManager* p) { INCFUNC("asm/func/FUN_080ec9b0.inc"); }

NAKED void FUN_080eca74(EnemyManager* p, Enemy* enemy) { INCFUNC("asm/func/FUN_080eca74.inc"); }

void FUN_080ecbe4(void) {}

NAKED void FUN_080ecbe8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080ecbe8.inc"); }

NAKED s32 FUN_080ecf18(void) { INCFUNC("asm/func/FUN_080ecf18.inc"); }

NAKED s32 FUN_080ecf60(u32 kind) { INCFUNC("asm/func/FUN_080ecf60.inc"); }

NAKED s32 FUN_080ecfbc(u32 kind, u32 unk_480) { INCFUNC("asm/func/FUN_080ecfbc.inc"); }

NAKED Enemy* FUN_080ed020(void) { INCFUNC("asm/func/FUN_080ed020.inc"); }

void FUN_080ed068(void) {
  EnemyListNode* node;
  Enemy* p;
  u32 flag;

  GetEnemyManager();
  node = gEnemyListHead;
  p = node->enemy;
  if (p != NULL) {
    flag = 0x1000;
    do {
      if (FUN_080e8a60(p) == 0) {
        p->unk_184 = 0;
        p->flags |= flag;
      }
      node = node->next;
      p = node->enemy;
    } while (p != NULL);
  }
}

NAKED void FUN_080ed0b0(s32 param_1) { INCFUNC("asm/func/FUN_080ed0b0.inc"); }

NAKED void FUN_080ed564(void) { INCFUNC("asm/func/FUN_080ed564.inc"); }

NAKED void FUN_080ed724(void) { INCFUNC("asm/func/FUN_080ed724.inc"); }

NAKED void Enemy_Sleep(void) { INCFUNC("asm/func/Enemy_Sleep.inc"); }

NAKED void FUN_080ed834(void) { INCFUNC("asm/func/FUN_080ed834.inc"); }

NAKED void FUN_080ed8f0(void) { INCFUNC("asm/func/FUN_080ed8f0.inc"); }

NAKED void FUN_080ed9d0(void) { INCFUNC("asm/func/FUN_080ed9d0.inc"); }

NAKED void FUN_080eda24(void) { INCFUNC("asm/func/FUN_080eda24.inc"); }

NAKED void FUN_080eda7c(void) { INCFUNC("asm/func/FUN_080eda7c.inc"); }

NAKED bool32 FUN_080edb4c(Enemy* p, Vec3* pos) { INCFUNC("asm/func/FUN_080edb4c.inc"); }

NAKED Enemy* FUN_080edc40(Vec3* pos) { INCFUNC("asm/func/FUN_080edc40.inc"); }

NAKED Enemy* FUN_080edce8(u32 id) { INCFUNC("asm/func/FUN_080edce8.inc"); }

NAKED Enemy* FUN_080edd2c(u32 id) { INCFUNC("asm/func/FUN_080edd2c.inc"); }

Enemy* GetFirstEnemy(void) { return gEnemyListHead->enemy; }

Enemy* FindEnemyById(u32 id) {
  EnemyListNode* node;
  Enemy* p;

  for (node = gEnemyListHead; (p = node->enemy) != NULL; node = node->next) {
    if (p->unk_0.id == id) {
      return p;
    }
  }
  return NULL;
}

// スクリプトが指定した敵が生存している (unk_184 > 0) かを返す
bool32 FUN_080eddc8(void) {
  u32 id = Script_GetValue();
  Enemy* p;
  bool32 alive;
  s32 hp;

  if ((id == 0) || ((p = FindEnemyById(id)) == NULL)) {
    return FALSE;
  }
  hp = p->unk_184;
  alive = TRUE;
  if (hp <= 0) {
    alive = FALSE;
  }
  return alive;
}

bool32 FUN_080eddf8(void) {
  u32 id = Script_GetValue();

  if ((id != 0) && (FindEnemyById(id) != NULL)) {
    return TRUE;
  }
  return FALSE;
}

NAKED bool32 FUN_080ede14(u32 kind, u32 mask) { INCFUNC("asm/func/FUN_080ede14.inc"); }

NAKED bool32 FUN_080ede60(u32 kind, u32 unk_480, u32 mask) { INCFUNC("asm/func/FUN_080ede60.inc"); }

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
  u16 flag;

  if (Mod(p->frameCounter, 15) == 0) {
    if (FUN_080a0808() == 0) {
      flag = 0x20;
      gStat->unk_934 |= flag;
    } else {
      flag = 0x20;
      gStat->unk_934 &= ~flag;
    }
  }
}

s32 EnemyManager_Update(EnemyManager* p) {
  u32 mask;

  FUN_080ee254();
  FUN_080ec8a4(p);
  FUN_080ec92c(p);
  FUN_080ec9b0(p);
  FUN_080edebc(p);
  FUN_080ee9d4(p);
  mask = ~0x1C000;
  p->flags &= mask;
  p->frameCounter++;
  return 0;
}

s32 EnemyManager_Destroy(EnemyManager* p) {
  FUN_080ee218();
  Free(gEnemyListHead);
  gEnemyManager = NULL;
  return 0;
}

// 戻り値を設定しないまま返る。呼び出し元の EnemyManager_Create は戻り値が負かどうかを見ている
s32 EnemyManager_Init(EnemyManager* p, u16 msgRecordID, u32 _) {
  p->msgRecordID = msgRecordID;
  p->frameCounter = 0;
  p->enemyCount = 0;
  p->unk_30 = 3;
  EnemyManager_InitList(p);
  gEnemyManager = p;
}

EnemyManager* EnemyManager_Create(u16 msgRecordID, u16 _) {
  EnemyManager* p;

  if (gEnemyManager != NULL) {
    return gEnemyManager;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(EnemyManager));
  if (p != NULL) {
    SetEntityRoutine(p, EnemyManager_Update, EnemyManager_Destroy);
    if (EnemyManager_Init(p, msgRecordID, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_080eeb08(void) { gEnemyManager = NULL; }

NAKED void FUN_080eeb14(u32 plttDst, u32 plttSrc, u32 _, u8 kind, u32 immediate) { INCFUNC("asm/func/FUN_080eeb14.inc"); }

NAKED bool32 FUN_080eec74(EnemyManager* p, Enemy* enemy) { INCFUNC("asm/func/FUN_080eec74.inc"); }

NAKED bool32 FUN_080eee70(void) { INCFUNC("asm/func/FUN_080eee70.inc"); }

NAKED void FUN_080eeee0(void) { INCFUNC("asm/func/FUN_080eeee0.inc"); }

NAKED void FUN_080eef6c(Enemy* p) { INCFUNC("asm/func/FUN_080eef6c.inc"); }

NAKED void FUN_080eefec(void) { INCFUNC("asm/func/FUN_080eefec.inc"); }

NAKED void FUN_080ef048(void) { INCFUNC("asm/func/FUN_080ef048.inc"); }

NAKED void FUN_080ef154(void) { INCFUNC("asm/func/FUN_080ef154.inc"); }

NAKED void FUN_080ef4e4(void) { INCFUNC("asm/func/FUN_080ef4e4.inc"); }

void FUN_080ef534(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->flags |= (u16)VM_GetKeywordValue(0x73, 0);
  }
}

void FUN_080ef55c(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->flags &= ~(u16)VM_GetKeywordValue(0x73, 0);
  }
}

void FUN_080ef584(void) {
  EnemyManager* p = gEnemyManager;

  if (p != NULL) {
    p->unk_30 = VM_GetKeywordValue(0x6C, 3);
  }
}

NAKED void FUN_080ef5a8(void) { INCFUNC("asm/func/FUN_080ef5a8.inc"); }

EnemyManager* GetEnemyManager(void) { return gEnemyManager; }
