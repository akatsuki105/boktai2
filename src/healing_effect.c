#include "entity.h"
#include "global.h"
#include "player.h"

// 魔法"ヒーリング"で生成されるエフェクト
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[516 - 0x18];
} HealingEffect;
static_assert(sizeof(HealingEffect) == 516);

NAKED void HealingParticles_SetState(HealingEffect* p, void* fn) { INCFUNC("asm/func/HealingParticles_SetState.inc"); }

NAKED void FUN_080a9058(HealingEffect* p) { INCFUNC("asm/func/FUN_080a9058.inc"); }

NAKED s32 HealingParticles_Update(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_Update.inc"); }

NAKED s32 HealingParticles_Destroy(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_Destroy.inc"); }

NAKED void HealingParticles_InitParticles(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_InitParticles.inc"); }

NAKED void HealingParticles_InitHitbox(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_InitHitbox.inc"); }

NAKED s32 HealingParticles_Init(HealingEffect* p, Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Init.inc"); }

NAKED HealingEffect* HealingParticles_Create(Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Create.inc"); }
