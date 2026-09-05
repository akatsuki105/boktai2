#include "entity.h"
#include "global.h"

// 常駐して、ゲームオーバー条件を満たしたらゲームオーバー処理を行う(Init処理を失敗扱いにしてもHP0になって倒れてもそのままゲームオーバーにならない)
typedef struct GameOverManager {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[852 - 0x18];
} GameOverManager;
static_assert(sizeof(GameOverManager) == 852);

extern GameOverManager* gGameOverManager;  // 0x03000150

INCASM("asm/gameover.inc");

NAKED void FUN_080a7550(GameOverManager* p) { INCFUNC("asm/func/FUN_080a7550.inc"); }

NAKED void FUN_080a761c(void) { INCFUNC("asm/func/FUN_080a761c.inc"); }

NAKED void FUN_080a7678(GameOverManager* p) { INCFUNC("asm/func/FUN_080a7678.inc"); }

NAKED void FUN_080a76fc(GameOverManager* p) { INCFUNC("asm/func/FUN_080a76fc.inc"); }

NAKED void FUN_080a775c(GameOverManager* p) { INCFUNC("asm/func/FUN_080a775c.inc"); }

NAKED void FUN_080a7800(GameOverManager* p) { INCFUNC("asm/func/FUN_080a7800.inc"); }

NAKED void FUN_080a79ac(GameOverManager* p) { INCFUNC("asm/func/FUN_080a79ac.inc"); }

NAKED s32 GameOverManager_Update(GameOverManager* p) { INCFUNC("asm/func/GameOverManager_Update.inc"); }

NAKED s32 GameOverManager_Destroy(GameOverManager* p) { INCFUNC("asm/func/GameOverManager_Destroy.inc"); }

NAKED s32 GameOverManager_Init(GameOverManager* p) { INCFUNC("asm/func/GameOverManager_Init.inc"); }

GameOverManager* GameOverManager_Create(void) {
  GameOverManager* p;

  if (gGameOverManager != NULL) {
    return gGameOverManager;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(GameOverManager));
  if (p != NULL) {
    SetEntityRoutine(p, GameOverManager_Update, GameOverManager_Destroy);
    if (GameOverManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
