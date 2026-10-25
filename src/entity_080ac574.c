#include "entity.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "registry.h"
#include "vm.h"

// 4個を使い回す粒子の枠
typedef struct {
  Particle ptcl;         // 0x00
  Vec3 origin;           // 0x28, ばらつきを加える前の発生位置
  ParticleGroup* group;  // 0x30, PTCL_GROUP_2
  u16 unk_34;            // 0x34, FUN_080ac5b4 が探すときの照合キー
  u16 active;            // 0x36, _Update が 0 の枠を飛ばす
  u16 timer;             // 0x38, 毎フレーム +1, 3以下と7以下でコマを変え, lifetime に届くと作り直す
  u16 lifetime;          // 0x3A
  u16 lifetimeBase;      // 0x3C, 寿命の下限
  u16 lifetimeRand;      // 0x3E, 0 以外なら寿命にこの範囲の乱数を足す
} Entity080ac574Particle;
static_assert(sizeof(Entity080ac574Particle) == 64);

typedef struct {
  Entity e;                         // 0x00, ENTITY_UNK_11
  Entity080ac574Particle ptcls[4];  // 0x18
} Entity080ac574;
static_assert(sizeof(Entity080ac574) == 280);

// 残差2命令 (68/66). 原典は pos.x/pos.z を ldrh で読んでおり (s16 なのに符号拡張しない), さらに &gRandTableIdx を ip 経由で持ち直している
// (u16) キャストを付けると ldrh になり 63/66 まで縮むが, 座標を u16 で読む C は原典として不自然なので採らない. 演算順 5通り, table ローカル有無, Random()/_Random() は試済
NON_MATCH void FUN_080ac3d4(Entity080ac574Particle* ptcl) {
#ifdef NONMATCHING_C
  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetFrame(&ptcl->ptcl, ptcl->group, 3);
  ptcl->ptcl.pos = ptcl->origin;
  ptcl->ptcl.pos.x += (Random() & 0x3F) - 31;
  ptcl->ptcl.pos.z += (Random() & 0x3F) - 31;
  ptcl->timer = 0;
  if (ptcl->lifetimeRand != 0) {
    ptcl->lifetime = ptcl->lifetimeBase + Mod(Random(), ptcl->lifetimeRand);
  } else {
    ptcl->lifetime = ptcl->lifetimeBase;
  }
#else
  INCFUNC("asm/func/FUN_080ac3d4.inc");
#endif
}

void FUN_080ac46c(Entity080ac574Particle* ptcl) {
  ptcl->timer++;
  if (ptcl->timer <= 3) {
    Particle_SetFrame(&ptcl->ptcl, ptcl->group, 3);
  } else if (ptcl->timer <= 7) {
    Particle_SetFrame(&ptcl->ptcl, ptcl->group, 2);
  } else if (ptcl->timer < ptcl->lifetime) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
  } else {
    FUN_080ac3d4(ptcl);
  }
}

s32 Entity080ac574_Update(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active != 0) {
      FUN_080ac46c(&p->ptcls[i]);
    }
  }
  return 0;
}

s32 Entity080ac574_Destroy(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

// 粒子4枠を隠した状態で用意し, レジストリに自分を登録する
s32 Entity080ac574_Init(Entity080ac574* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Entity080ac574Particle* ptcl = &p->ptcls[i];
    ParticleGroup* g = GetParticleGroup(PTCL_GROUP_2);

    ptcl->group = g;
    Particle_Add(&ptcl->ptcl, g, 0);
    Particle_SetPltt(&ptcl->ptcl, 1);
    Particle_SetOffset(&ptcl->ptcl, -4, -4);
    ptcl->ptcl.priority = 2;
    ptcl->ptcl.offsetZ = 0xEC;
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->unk_34 = 0;
    ptcl->active = 0;
  }
  Registry_Add(0xA854, p, 0);
  return 0;
}

Entity080ac574* Entity080ac574_Create(void) {
  Entity080ac574* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080ac574));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080ac574_Update, Entity080ac574_Destroy);
    if (Entity080ac574_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// unk_34 が id の粒子を隠して枠を空ける
void FUN_080ac5b4(u32 id) {
  Entity080ac574* p = Registry_Find(0xA854);
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active != 0 && p->ptcls[i].unk_34 == id) {
      p->ptcls[i].ptcl.flags |= SPRFLAG_HIDDEN;
      p->ptcls[i].active = 0;
    }
  }
}

void FUN_080ac5f4(void) {
  if (VM_SeekToNamedArg('n')) {
    FUN_080ac5b4(VM_GetValue());
  }
}

// 空いている枠を1つ探して発生位置と寿命を仕込む
void Entity080ac574_Spawn(s32 id, Vec3* origin, s32 lifetimeBase, s32 lifetimeRand) {
  Entity080ac574* p = Registry_Find(0xA854);
  s32 i;

  if (p == NULL) {
    p = Entity080ac574_Create();
  }

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active == 0) {
      break;
    }
  }
  if (i >= 4) {
    return;
  }

  p->ptcls[i].unk_34 = id;
  p->ptcls[i].origin = *origin;
  p->ptcls[i].lifetimeBase = lifetimeBase;
  p->ptcls[i].lifetimeRand = lifetimeRand;
  p->ptcls[i].active = 1;
  p->ptcls[i].ptcl.flags &= ~SPRFLAG_HIDDEN;
  FUN_080ac3d4(&p->ptcls[i]);
}

// スクリプトから 'n'(ID) 'p'(発生位置) 's'(寿命) を受け取って1発生させる
void Entity080ac574_SpawnScripted(void) {
  Vec3 origin;
  s32 id = VM_SeekToNamedArg('n') ? VM_GetValue() : 0;
  s32 lifetimeBase;
  s32 lifetimeRand;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(origin, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(origin, 0, 0, 0);
  }

  if (VM_SeekToNamedArg('s')) {
    lifetimeBase = VM_GetValue();
    lifetimeRand = VM_GetValue();
  } else {
    lifetimeBase = 16;
    lifetimeRand = 0;
  }

  Entity080ac574_Spawn(id, &origin, lifetimeBase, lifetimeRand);
}
