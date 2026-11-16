#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "particle.h"
#include "random.h"
#include "vec3.h"
#include "vm.h"

// 地点から上に湧き続ける粒, 8枠を使い回して消えたものから順に湧かし直す
typedef struct {
  bool8 active;   // 0x00, 1 の間だけ上昇する
  u8 angle;       // 0x01, 湧いた地点の中心から見た方角
  s16 height;     // 0x02, 毎フレーム riseSpeed だけ増え、maxHeight に届くと消える
  u16 radius;     // 0x04, '.d=256', 中心からの距離
  u16 timer;      // 0x06, 消えている間は湧くまでの残りフレーム, 上昇中はコマ送りの数え上げ
  Particle ptcl;  // 0x08
} SparkleEffectElem;
static_assert(sizeof(SparkleEffectElem) == 48);

// エレメントのパーティクルを下から上に沸かすエミッタ (HashName("輝きエフェクト"))
// 宝箱の出現, 鍛冶の完成, 朝露の浄化, 風の祝福, ソルデバの入手時などに使われる
// スクリプトが渡すインスタンスIDは HashName("キラキラ") = 0xE7C2, 朝露で重ねる4つは "キラキラ1"〜"キラキラ4" = 0xF88D〜0xF890
typedef struct {
  Entity e;                    // 0x000, ENTITY_UNK_11
  s32 timer;                   // 0x018, 毎フレーム +1, lifetime と比べて湧かすのを止める
  s32 lifetime;                // 0x01C, '.t=0x100', 負なら無期限
  u16 riseSpeed;               // 0x020, 0x14, 各枠の height に毎フレーム足す
  u16 maxHeight;               // 0x022, 400, height がここに届いた枠を消す
  u16 count;                   // 0x024, '.n=8', 使う枠数
  u16 poseIdx;                 // 0x026, '.T' で選ぶ Particle のpose番号 (0,2,4,...,14)
  ParticleGroup* group;        // 0x028, PTCL_GROUP_2, エレメントのパーティクル
  Vec3 pos;                    // 0x02C, '.p', y はタイルの attr から計算し直す
  SparkleEffectElem elems[8];  // 0x034
} SparkleEffect;
static_assert(sizeof(SparkleEffect) == 436);

bool32 SparkleEffect_HasActiveElem(SparkleEffect* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->elems[i].active == 1) {
      return TRUE;
    }
  }
  return FALSE;
}

void SparkleEffectElem_TryRespawn(SparkleEffect* p, SparkleEffectElem* elem) {
  if (elem->timer == 0) {
    if (p->lifetime < 0 || p->timer < p->lifetime) {
      elem->active = TRUE;
      elem->angle = Random();
      elem->height = 0;
      elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    }
  } else {
    elem->timer--;
  }
}

void SparkleEffectElem_Update(SparkleEffect* p, SparkleEffectElem* elem) {
  elem->height += p->riseSpeed;
  if ((elem->timer & 3) == 0) {
    Particle_SetPose(&elem->ptcl, p->group, p->poseIdx + ((elem->timer >> 2) & 1));
  }
  elem->timer++;

  if ((u16)elem->height >= p->maxHeight) {
    elem->active = FALSE;
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
    elem->timer = (8 - p->count) * 4 + 4;
  }
}

// 原典は第2引数 elem を分岐の前で1回だけ r1 に置き, i と elem のレジスタも入れ替わる, 試済: elem の局所変数化 / ポインタで回す / p->elems[i] 直書き
NON_MATCH s32 SparkleEffect_Update(SparkleEffect* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < p->count; i++) {
    SparkleEffectElem* elem = &p->elems[i];

    if (!elem->active) {
      SparkleEffectElem_TryRespawn(p, elem);
    } else {
      SparkleEffectElem_Update(p, elem);
    }
    Vec3_SetPolar(&elem->ptcl.pos, elem->angle, elem->radius);
    elem->ptcl.pos.y += elem->height;
    elem->ptcl.pos.x += p->pos.x;
    elem->ptcl.pos.y += p->pos.y;
    elem->ptcl.pos.z += p->pos.z;
  }
  for (i = p->count; i < 8; i++) {
    p->elems[i].ptcl.flags |= SPRFLAG_HIDDEN;
  }
  p->timer++;
  if (p->lifetime > 0 && p->timer >= p->lifetime && !SparkleEffect_HasActiveElem(p)) {
    KillEntity((Entity*)p);
  }
  return 0;
#else
  INCFUNC("asm/func/SparkleEffect_Update.inc");
#endif
}

s32 SparkleEffect_Destroy(SparkleEffect* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->elems[i].ptcl);
  }
  return 0;
}

s32 SparkleEffect_Init(SparkleEffect* p, Vec3* pos, s32 radius, s32 lifetime, s32 count, s32 kind) {
  s32 height;
  s32 i;
  SparkleEffectElem* elem;

  switch (kind) {
    case 1: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 0;
      break;
    }
    case 3: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 4;
      break;
    }
    case 4: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 6;
      break;
    }
    case 5: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 8;
      break;
    }
    case 6: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 10;
      break;
    }
    case 7: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 12;
      break;
    }
    case 8: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 14;
      break;
    }
    case 0:
    case 2:
    default: {
      p->group = GetParticleGroup(PTCL_GROUP_2);
      p->poseIdx = 2;
      break;
    }
  }
  p->pos = *pos;
  height = TileHeightAt(&p->pos);
  if (p->pos.y < height) {
    p->pos.y = height;
  }
  p->timer = 0;
  p->lifetime = lifetime;
  p->riseSpeed = 20;
  p->maxHeight = 400;
  if (count > 7) {
    count = 8;
  }
  p->count = count;
  elem = p->elems;
  for (i = 0; i < 8; i++, elem++) {
    Particle* ptcl = &elem->ptcl;

    elem->active = FALSE;
    elem->angle = (RandomNext() & 0x7F) - 32;
    elem->height = 0;
    elem->radius = radius;
    elem->timer = i * 4;
    Particle_Add(ptcl, p->group, 1);
    Particle_SetOffset(ptcl, -4, -4);
    Particle_SetPose(ptcl, p->group, p->poseIdx);
    Particle_SetPltt(ptcl, 1);
    Vec3_SetPolar(&elem->ptcl.pos, elem->angle, elem->radius);
    elem->ptcl.pos.y += elem->height;
    elem->ptcl.pos.x += p->pos.x;
    elem->ptcl.pos.y += p->pos.y;
    elem->ptcl.pos.z += p->pos.z;
    elem->ptcl.priority = 1;
  }
  return 0;
}

SparkleEffect* SparkleEffect_CreateAt(Vec3* pos, s32 radius, s32 lifetime, s32 count, s32 kind) {
  SparkleEffect* p = CreateEntity(ENTITY_UNK_11, sizeof(SparkleEffect));

  if (p != NULL) {
    SetEntityRoutine(p, SparkleEffect_Update, SparkleEffect_Destroy);
    if (SparkleEffect_Init(p, pos, radius, lifetime, count, kind) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x99CA, HashName("輝きエフェクト")
SparkleEffect* SparkleEffect_Create(void) {
  SparkleEffect* p = CreateEntity(ENTITY_UNK_11, sizeof(SparkleEffect));

  if (p != NULL) {
    Vec3 pos;
    s32 radius, lifetime, count, kind;

    if (VM_SeekToNamedArg('p')) {
      VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    } else {
      VEC3_SET(pos, 0, 0, 0);
    }
    radius = VM_GetNamedArgValue('d', 256);
    lifetime = VM_GetNamedArgValue('t', 256);
    count = VM_GetNamedArgValue('n', 8);
    kind = VM_GetNamedArgValue('T', 0);
    SetEntityRoutine(p, SparkleEffect_Update, SparkleEffect_Destroy);
    if (SparkleEffect_Init(p, &pos, radius, lifetime, count, kind) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
