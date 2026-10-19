#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sound.h"

// 魔法"ヒーリング"で生成されるエフェクト
typedef struct {
  Particle ptcl;  // 0x00, HealingParticles_Destroy が Particle_Remove に渡す
  u8 unk_28[8];   // 0x28
} HealingEffectParticle;
static_assert(sizeof(HealingEffectParticle) == 48);

struct HealingEffect;

typedef void HealingEffectFunc(struct HealingEffect* p);

typedef struct HealingEffect {
  Entity e;                           // 0x000, ENTITY_UNK_8
  Player* player;                     // 0x018, _Init の第2引数
  Vec3 pos;                           // 0x01C, _Init の第3引数を8バイトまるごと写す
  u8 unk_24[0x074 - 0x024];           // 0x024
  HealingEffectParticle ptcls[8];     // 0x074, _Destroy が Particle_Remove に渡す
  u8 unk_1f4[4];                      // 0x1F4
  u16 unk_1f8;                        // 0x1F8, unk_1fa を3で割った値
  u16 unk_1fa;                        // 0x1FA, _Init が 180 を入れる
  u16 unk_1fc;                        // 0x1FC, _Init が 900 を入れる
  u16 timer;                          // 0x1FE, HealingParticles_SetState が 0 に戻す
  HealingEffectFunc* updateCallback;  // 0x200
  u8 unk_204[516 - 0x204];            // 0x204
} HealingEffect;
static_assert(sizeof(HealingEffect) == 516);

void HealingParticles_SetState(HealingEffect* p, HealingEffectFunc* fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

NAKED void FUN_080a9058(HealingEffect* p) { INCFUNC("asm/func/FUN_080a9058.inc"); }

s32 HealingParticles_Update(HealingEffect* p) {
  p->updateCallback(p);
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

s32 HealingParticles_Init(HealingEffect* p, Player* player, Vec3* pos) {
  p->pos = *pos;
  p->player = player;
  HealingParticles_InitParticles(p);
  HealingParticles_InitHitbox(p);
  p->unk_1fa = 180;
  p->unk_1f8 = Div(180, 3);
  p->unk_1fc = 900;
  PlaySound_082406e0(919);
  HealingParticles_SetState(p, FUN_080a9058);
  return 0;
}

HealingEffect* HealingParticles_Create(Player* player, Vec3* pos) {
  HealingEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(HealingEffect));

  if (p != NULL) {
    SetEntityRoutine(p, HealingParticles_Update, HealingParticles_Destroy);
    if (HealingParticles_Init(p, player, pos) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
