#include "entity.h"
#include "global.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

struct EntityCF58;

typedef void(EntityCF58Func)(struct EntityCF58* p);
typedef void(EntityCF58DoneFunc)(void* owner);

// _Create が 2種類ある (_Init, _Update, _Destroy は共通)
typedef struct EntityCF58 {
  Entity e;                          // 0x00, ENTITY_UNK_4
  MainSpriteGfx gfx;                 // 0x18
  MainSprite sprite;                 // 0x38
  u8 unk_98;                         // 0x98, Init が 1 を書く, 0 のとき doneCallback を呼ぶ分岐がある
  u8 unk_99;                         // 0x99, '.f=0'
  u16 stateTimer;                    // 0x9A, updateCallback を差し替えるたびに 0 に戻る
  u32 killRequest;                   // 0x9C, 0 以外になると Update が自分を消す, 外から立てられる
  EntityCF58DoneFunc* doneCallback;  // 0xA0, 終了時に owner を第1引数として呼ぶ
  void* owner;                       // 0xA4, doneCallback の第1引数
  s32 scriptID;                      // 0xA8, '.p=0', 0 でなければ実行する
  EntityCF58Func* updateCallback;    // 0xAC
} EntityCF58;
static_assert(sizeof(EntityCF58) == 176);

IWRAM_DATA EntityCF58* gEntityCF58 = NULL;  // 0x0300014C

void EntityCF58_RequestKill(void) {
  EntityCF58* p = gEntityCF58;

  if (p != NULL) {
    p->killRequest = 1;
  }
}

void EntityCF58_SetUpdateCallback(EntityCF58* p, EntityCF58Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void EntityCF58_RunDoneCallback(EntityCF58* p) {
  if (p->doneCallback != NULL) {
    p->doneCallback(p->owner);
  }
}

void EntityCF58_RunScript(EntityCF58* p) {
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

void FUN_080a5ea4(EntityCF58* p) {
  if (p->unk_98 == 0) {
    EntityCF58_RunDoneCallback(p);
  } else {
    EntityCF58_RunScript(p);
  }
}

NAKED void FUN_080a5ec4(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5ec4.inc"); }

NAKED void FUN_080a5f40(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5f40.inc"); }

void FUN_080a5fd0(EntityCF58* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(0x294);
  }
  p->stateTimer++;
  if (p->stateTimer > 0x59) {
    FUN_080a5ea4(p);
    KillEntity((Entity*)p);
  }
}

s32 EntityCF58_Update(EntityCF58* p) {
  if (p->killRequest != 0) {
    KillEntity((Entity*)p);
  } else {
    p->updateCallback(p);
  }
  return 0;
}

s32 EntityCF58_Destroy(EntityCF58* p) {
  MainSprite_Remove(&p->sprite);
  gEntityCF58 = NULL;
  return 0;
}

NAKED void FUN_080a6048(EntityCF58* p, u32 param_2) { INCFUNC("asm/func/FUN_080a6048.inc"); }

NAKED void FUN_080a6110(EntityCF58* p, u32 param_2) { INCFUNC("asm/func/FUN_080a6110.inc"); }

// 原典は return を書き忘れている
s32 EntityCF58_InitWithCallback(EntityCF58* p, u32 param_2, u32 param_3, EntityCF58DoneFunc* doneCallback, void* owner) {
  p->unk_98 = 0;
  p->doneCallback = doneCallback;
  p->owner = owner;
  p->unk_99 = param_3;
  FUN_080a6048(p, param_2);
  FUN_080a6110(p, param_2);
  gEntityCF58 = p;
}

NAKED EntityCF58* EntityCF58_CreateWithCallback(u32 param_1, u8 param_2, void* doneCallback, void* owner) { INCFUNC("asm/func/EntityCF58_CreateWithCallback.inc"); }

NAKED s32 EntityCF58_Init(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_Init.inc"); }

EntityCF58* EntityCF58_Create(void) {
  if (gEntityCF58 == NULL) {
    EntityCF58* p = CreateEntity(ENTITY_UNK_4, sizeof(EntityCF58));

    if (p != NULL) {
      SetEntityRoutine(p, EntityCF58_Update, EntityCF58_Destroy);
      if (EntityCF58_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityCF58;
}
