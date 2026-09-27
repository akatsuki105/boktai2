#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"

// 魔法"ヒーリング"で生成されるエフェクト
typedef struct {
  Particle ptcl;  // 0x00, HealingParticles_Destroy が Particle_Remove に渡す
  u8 unk_28[8];   // 0x28
} HealingEffectParticle;
static_assert(sizeof(HealingEffectParticle) == 48);

struct HealingEffect;

typedef void HealingEffectFunc(struct HealingEffect* p);

typedef struct HealingEffect {
  Entity e;                        // 0x000, ENTITY_UNK_8
  u8 unk_18[0x074 - 0x018];        // 0x018
  HealingEffectParticle ptcls[8];  // 0x074, _Destroy が Particle_Remove に渡す
  u8 unk_1f4[0x1FE - 0x1F4];       // 0x1F4
  u16 timer;                       // 0x1FE, HealingParticles_SetState が 0 に戻す
  HealingEffectFunc* fn;           // 0x200, HealingParticles_SetState が入れ、_Update が毎フレーム呼ぶ
  u8 unk_204[516 - 0x204];         // 0x204
} HealingEffect;
static_assert(sizeof(HealingEffect) == 516);

void HealingParticles_SetState(HealingEffect* p, HealingEffectFunc* fn) {
  p->fn = fn;
  p->timer = 0;
}

NAKED void FUN_080a9058(HealingEffect* p) { INCFUNC("asm/func/FUN_080a9058.inc"); }

s32 HealingParticles_Update(HealingEffect* p) {
  p->fn(p);
  return 0;
}

s32 HealingParticles_Destroy(HealingEffect* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  return 0;
}

NAKED void HealingParticles_InitParticles(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_InitParticles.inc"); }

NAKED void HealingParticles_InitHitbox(HealingEffect* p) { INCFUNC("asm/func/HealingParticles_InitHitbox.inc"); }

NAKED s32 HealingParticles_Init(HealingEffect* p, Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Init.inc"); }

NAKED HealingEffect* HealingParticles_Create(Player* player, Vec3* pos) { INCFUNC("asm/func/HealingParticles_Create.inc"); }
