#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
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

void FUN_080a5f40(EntityCF58* p);
void EntityCF58_InitSprite(EntityCF58* p, u32 mode);
void EntityCF58_InitState(EntityCF58* p, u32 param_2);
s32 EntityCF58_InitWithCallback(EntityCF58* p, u32 param_2, u32 param_3, EntityCF58DoneFunc* doneCallback, void* owner);

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

void EntityCF58_Finish(EntityCF58* p) {
  if (p->unk_98 == 0) {
    EntityCF58_RunDoneCallback(p);
  } else {
    EntityCF58_RunScript(p);
  }
}

void FUN_080a5ec4(EntityCF58* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(VO_READY);
  }
  if (p->sprite.animCmdIdx >= 1 && p->sprite.animCmdIdx <= 3 && p->sprite.animCmdTimer == 0) {
    PlaySound_082406e0(SE_COUNTDOWN);
  }
  p->stateTimer++;
  if (MainSprite_AdvanceAnim(&p->sprite, &p->gfx)) {
    MainSprite_SetPose(&p->sprite, &p->gfx, 36, 1);
    EntityCF58_SetUpdateCallback(p, FUN_080a5f40);
    EntityCF58_Finish(p);
  }
}

void FUN_080a5f40(EntityCF58* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(VO_FIGHT);
  }
  if (p->stateTimer < 8) {
    u16* table = gRandomTable;

    p->sprite.pos.x = (_Random(table) & 3) - 2;
    p->sprite.pos.y = (_Random(table) & 3) - 2;
  } else if (p->stateTimer == 8) {
    p->sprite.pos.x = 0;
    p->sprite.pos.y = 0;
  }
  if (++p->stateTimer >= 30) {
    KillEntity(&p->e);
  }
}

void FUN_080a5fd0(EntityCF58* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_ANS_WRONG);
  }
  p->stateTimer++;
  if (p->stateTimer >= SECOND(1.5)) {
    EntityCF58_Finish(p);
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

void EntityCF58_InitSprite(EntityCF58* p, u32 mode) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);

  if (f != NULL) {
    Vec3 pos;

    p->gfx = *f;
    OpenMainSpriteFile(&p->gfx, f);
    VEC3_SET(pos, 0, 0, 0);
    if (mode == 0) {
      MainSprite_Add(&p->sprite, &p->gfx, 0x20, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
      MainSprite_SetAnim(&p->sprite, &p->gfx, 0, 2, 0);
    } else if (mode == 1) {
      MainSprite_Add(&p->sprite, &p->gfx, 0x25, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
    } else {
      MainSprite_Add(&p->sprite, &p->gfx, 0x20, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
      MainSprite_SetAnim(&p->sprite, &p->gfx, 0, 2, 0);
    }
  }
}

void EntityCF58_InitState(EntityCF58* p, u32 param_2) {
  if (param_2 == 0) {
    EntityCF58_SetUpdateCallback(p, FUN_080a5ec4);
  } else if (param_2 == 1) {
    EntityCF58_SetUpdateCallback(p, FUN_080a5fd0);
  } else {
    EntityCF58_SetUpdateCallback(p, FUN_080a5ec4);
  }
}

// 原典は return を書き忘れている
s32 EntityCF58_InitWithCallback(EntityCF58* p, u32 param_2, u32 param_3, EntityCF58DoneFunc* doneCallback, void* owner) {
  p->unk_98 = 0;
  p->doneCallback = doneCallback;
  p->owner = owner;
  p->unk_99 = param_3;
  EntityCF58_InitSprite(p, param_2);
  EntityCF58_InitState(p, param_2);
  gEntityCF58 = p;
}

EntityCF58* EntityCF58_CreateWithCallback(u32 param_1, u32 param_2, void* doneCallback, void* owner) {
  if (gEntityCF58 == NULL) {
    EntityCF58* p = CreateEntity(ENTITY_UNK_4, sizeof(EntityCF58));

    if (p != NULL) {
      SetEntityRoutine(p, EntityCF58_Update, EntityCF58_Destroy);
      if (EntityCF58_InitWithCallback(p, param_1, param_2, doneCallback, owner) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityCF58;
}

// 47/45命令, 原典は '.f' が無いとき VM_SeekToNamedArg の戻り値 (0) をそのまま unk_99 に書く, 三項演算子とローカル変数は試済
NON_MATCH s32 EntityCF58_Init(EntityCF58* p) {
#ifdef NONMATCHING_C
  u32 mode;

  p->unk_98 = 1;
  mode = VM_SeekToNamedArg('m') ? VM_GetValue() : 0;
  p->unk_99 = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
  if (VM_SeekToNamedArg('p')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  EntityCF58_InitSprite(p, mode);
  EntityCF58_InitState(p, mode);
  gEntityCF58 = p;
#else
  INCFUNC("asm/func/EntityCF58_Init.inc");
#endif
}

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
