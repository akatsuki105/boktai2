#include "entity.h"
#include "global.h"
#include "player.h"

// 魔法"ヒーリング"で生成されるエフェクト
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[516 - 0x18];
} HealingEffect;
static_assert(sizeof(HealingEffect) == 516);

INCASM("asm/healing_effect.inc");

NAKED s32 HealingParticles_Init(HealingEffect* p, Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Init.inc"); }

NAKED HealingEffect* HealingParticles_Create(Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Create.inc"); }
