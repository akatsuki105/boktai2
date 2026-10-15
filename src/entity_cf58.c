#include "entity.h"
#include "global.h"
#include "sprite.h"

struct EntityCF58;

typedef void(EntityCF58Func)(struct EntityCF58* p);

// _Create が 2種類ある (_Init, _Update, _Destroy は共通)
typedef struct EntityCF58 {
  Entity e;                        // 0x00, ENTITY_UNK_4
  MainSpriteGfx gfx;               // 0x18
  MainSprite sprite;               // 0x38
  u8 unk_98;                       // 0x98, Init が 1 を書く, 0 のとき doneCallback を呼ぶ分岐がある
  u8 unk_99;                       // 0x99, '.f=0'
  u16 stateTimer;                  // 0x9A, updateCallback を差し替えるたびに 0 に戻る
  u32 killRequest;                 // 0x9C, 0 以外になると Update が自分を消す, 外から立てられる
  void* doneCallback;              // 0xA0, 終了時に owner を第1引数として呼ぶ
  void* owner;                     // 0xA4, doneCallback の第1引数
  s32 scriptID;                    // 0xA8, '.p=0', 0 でなければ実行する
  EntityCF58Func* updateCallback;  // 0xAC
} EntityCF58;
static_assert(sizeof(EntityCF58) == 176);

IWRAM_DATA EntityCF58* gEntityCF58 = NULL;  // 0x0300014C

NAKED void EntityCF58_RequestKill(void) { INCFUNC("asm/func/EntityCF58_RequestKill.inc"); }

NAKED void EntityCF58_SetUpdateCallback(EntityCF58* p, EntityCF58Func* fn) { INCFUNC("asm/func/EntityCF58_SetUpdateCallback.inc"); }

NAKED void EntityCF58_RunDoneCallback(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_RunDoneCallback.inc"); }

NAKED void EntityCF58_RunScript(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_RunScript.inc"); }

NAKED void FUN_080a5ea4(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5ea4.inc"); }

NAKED void FUN_080a5ec4(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5ec4.inc"); }

NAKED void FUN_080a5f40(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5f40.inc"); }

NAKED void FUN_080a5fd0(EntityCF58* p) { INCFUNC("asm/func/FUN_080a5fd0.inc"); }

NAKED s32 EntityCF58_Update(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_Update.inc"); }

NAKED s32 EntityCF58_Destroy(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_Destroy.inc"); }

NAKED void FUN_080a6048(EntityCF58* p) { INCFUNC("asm/func/FUN_080a6048.inc"); }

NAKED void FUN_080a6110(EntityCF58* p) { INCFUNC("asm/func/FUN_080a6110.inc"); }

NAKED s32 EntityCF58_InitWithCallback(EntityCF58* p, u32 param_2, u8 param_3, void* doneCallback, void* owner) { INCFUNC("asm/func/EntityCF58_InitWithCallback.inc"); }

NAKED EntityCF58* EntityCF58_CreateWithCallback(u32 param_1, u8 param_2, void* doneCallback, void* owner) { INCFUNC("asm/func/EntityCF58_CreateWithCallback.inc"); }

NAKED s32 EntityCF58_Init(EntityCF58* p) { INCFUNC("asm/func/EntityCF58_Init.inc"); }

NAKED EntityCF58* EntityCF58_Create(void) { INCFUNC("asm/func/EntityCF58_Create.inc"); }
