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
