#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"

// 魔法"ヒーリング"で生成されるエフェクト
typedef struct {
  Particle ptcl;  // 0x00, HealingEffect_Destroy が Particle_Remove に渡す
  u8 angle;       // 0x28, 中心から見た向き, 毎フレーム angleSpeed ずつ回る
  u8 riseSpeed;   // 0x29, riseStart 以降に毎フレーム上がる量
  u8 riseStart;   // 0x2A, 上がり始めるフレーム
  u8 poseTimer;   // 0x2B, 0 と 4 でコマを切り替える
  u8 angleSpeed;  // 0x2C, 7 から 8 フレームごとに 2 まで落ちる
  u8 lifetime;    // 0x2D, この値まで timer が進んだら隠す
  u16 radius;     // 0x2E, 中心からの距離
} HealingEffectParticle;
static_assert(sizeof(HealingEffectParticle) == 48);

typedef struct HealingEffect {
  Entity e;                                       // 0x000, ENTITY_UNK_8
  Player* player;                                 // 0x018, _Init の第2引数
  Vec3 pos;                                       // 0x01C, _Init の第3引数を8バイトまるごと写す
  HitboxData hitbox;                              // 0x024, 攻撃も食らいもしない判定, timer が 12 未満の間だけ登録する
  HealingEffectParticle ptcls[8];                 // 0x074, _Destroy が Particle_Remove に渡す
  ParticleGroup* group;                           // 0x1F4, PTCL_GROUP_2
  u16 unk_1f8;                                    // 0x1F8, unk_1fa を3で割った値
  u16 unk_1fa;                                    // 0x1FA, _Init が 180 を入れる
  u16 unk_1fc;                                    // 0x1FC, _Init が 900 を入れる
  u16 timer;                                      // 0x1FE, HealingEffect_SetState が 0 に戻す
  void (*updateCallback)(struct HealingEffect*);  // 0x200
} HealingEffect;
static_assert(sizeof(HealingEffect) == 516);

void HealingEffect_SetState(HealingEffect* p, void* fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

// 粒子を回しながら上げ, 全部の寿命が尽きたら消える
// 残差: 172 対 161 命令, 原典は粒子のポインタを ptcl と &ptcl.pos の2本と i * 48 で持つが, こちらはフィールドごとに別のポインタを作る
NON_MATCH void FUN_080a9058(HealingEffect* p) {
#ifdef NONMATCHING_C
  bool32 alive = FALSE;
  s32 i;

  if (p->timer < 12) {
    Hitbox_Register(&p->hitbox);
  }
  for (i = 0; i < 8; i++) {
    HealingEffectParticle* e = &p->ptcls[i];

    if (p->timer >= e->lifetime) {
      e->ptcl.flags |= SPRFLAG_HIDDEN;
      continue;
    }
    alive = TRUE;
    e->angle += e->angleSpeed;
    e->ptcl.pos.x = p->pos.x + POLAR_X(e->radius, e->angle);
    e->ptcl.pos.z = p->pos.z + POLAR_Z(e->radius, e->angle);
    if (p->timer >= e->riseStart) {
      if ((p->timer & 7) == 0 && e->angleSpeed > 2) {
        e->angleSpeed--;
      }
      e->ptcl.pos.y += e->riseSpeed;
    }
    if (e->poseTimer == 0) {
      Particle_SetPose(&e->ptcl, p->group, 12);
    } else if (e->poseTimer == 4) {
      Particle_SetPose(&e->ptcl, p->group, 13);
    }
    if (++e->poseTimer > 7) {
      e->poseTimer = 0;
    }
  }
  p->timer++;
  if (!alive) {
    KillEntity((Entity*)p);
  }
#else
  INCFUNC("asm/func/FUN_080a9058.inc");
#endif
}

s32 HealingEffect_Update(HealingEffect* p) {
  p->updateCallback(p);
  return 0;
}

s32 HealingEffect_Destroy(HealingEffect* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  return 0;
}

// 中心の周りに 8 つの粒子を等間隔から少しずらして並べる
// 残差: 195 対 199 命令, 原典はループの中でも乱数表のアドレスを毎回読み直し, 最初の乱数の定数をループ外の値として使い回す
NON_MATCH void HealingEffect_InitParticles(HealingEffect* p) {
#ifdef NONMATCHING_C
  s32 baseAngle = Random() & 0xFF;
  s32 i;

  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    HealingEffectParticle* e = &p->ptcls[i];

    Particle_Add(&e->ptcl, p->group, 0);
    Particle_SetOffset(&e->ptcl, -4, -4);
    Particle_SetPltt(&e->ptcl, 1);
    e->angle = baseAngle + i * 32 + (Random() & 15);
    e->riseSpeed = (i & 3) * 2 + 3;
    e->radius = (Random() & 31) + 64;
    e->riseStart = (Random() & 15) + 12;
    e->angleSpeed = 7;
    e->ptcl.pos.x = p->pos.x + POLAR_X(e->radius, e->angle);
    e->ptcl.pos.y = p->pos.y;
    e->ptcl.pos.z = p->pos.z + POLAR_Z(e->radius, e->angle);
    e->ptcl.priority = 2;
    e->ptcl.offsetZ = -20;
    e->poseTimer = Random() & 7;
    if (e->poseTimer <= 3) {
      Particle_SetPose(&e->ptcl, p->group, 12);
    } else {
      Particle_SetPose(&e->ptcl, p->group, 13);
    }
    e->lifetime = (Random() & 15) + 56;
  }
#else
  INCFUNC("asm/func/HealingEffect_InitParticles.inc");
#endif
}

void HealingEffect_InitHitbox(HealingEffect* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size;
  Vec3 offset;

  VEC3_SET(size, 100, 50, 100);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX, 0, HIM_0, &size, &offset);
  Hitbox_SetAttack(hitbox, 0, 0, 0x8000, 0, 0);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->pos, 0);
}

s32 HealingEffect_Init(HealingEffect* p, Player* player, Vec3* pos) {
  p->pos = *pos;
  p->player = player;
  HealingEffect_InitParticles(p);
  HealingEffect_InitHitbox(p);
  p->unk_1fa = 180;
  p->unk_1f8 = Div(180, 3);
  p->unk_1fc = 900;
  PlaySound_082406e0(SE_M_HEALING);
  HealingEffect_SetState(p, FUN_080a9058);
  return 0;
}

HealingEffect* HealingEffect_Create(Player* player, Vec3* pos) {
  HealingEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(HealingEffect));

  if (p != NULL) {
    SetEntityRoutine(p, HealingEffect_Update, HealingEffect_Destroy);
    if (HealingEffect_Init(p, player, pos) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
