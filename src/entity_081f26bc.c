#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "particle.h"
#include "sprite.h"
#include "sprite_animation.h"

// flags の bit4 で obj が指す粒子
typedef struct {
  Particle ptcl;         // 0x00
  ParticleGroup* group;  // 0x28
} Entity081f26bcPtcl;
static_assert(sizeof(Entity081f26bcPtcl) == 44);

// 動く破片 1 つ, Entity081f26bc_Spawn で出す
typedef struct {
  void* obj;           // 0x00, flags の bit3 なら AuxSprite + AuxSpriteGfx (0x48), bit4 なら Particle + ParticleGroup* (0x2C) を Malloc したもの
  AuxAnimState anim;   // 0x04
  Vec3 vel;            // 0x14
  HitboxData hitbox;   // 0x1C, flags の bit2 と bit8 が立っているときだけ登録する
  u16 flags;           // 0x6C, bit2: hitbox あり, bit3: AuxSprite, bit4: Particle, bit7: vel が 0 でない, bit8: hitbox が有効
  u8 state;            // 0x6E, PTR_ARRAY_085ae538 の添字, 0: 空き, 3: 点滅して消える
  s8 idx;              // 0x6F, elems の添字, 空きなら -1
  u16 life;            // 0x70
  u16 unk_72;          // 0x72
  u16 vanishTimer;     // 0x74, 点滅して消える状態の経過フレーム
  bool8 stateEntered;  // 0x76
  u8 unk_77;           // 0x77, 0 になると消える状態へ移る
} Entity081f26bcElem;
static_assert(sizeof(Entity081f26bcElem) == 120);

// 破片を 24 個まで動かす
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  u32 usedMask;                  // 0x018, bit i が立っていれば elems[i] が使用中
  Entity081f26bcElem elems[24];  // 0x01C
} Entity081f26bc;
static_assert(sizeof(Entity081f26bc) == 2908);

static Entity081f26bc* gEntity081f26bc;  // 0x030001EC

void FUN_081f1940(Entity081f26bc* p, Entity081f26bcElem* e);
void FUN_081f1994(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_StateBounce(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_StateVanish(Entity081f26bc* p, Entity081f26bcElem* e);

void (*const PTR_ARRAY_085ae538[4])(Entity081f26bc*, Entity081f26bcElem*) = {
    FUN_081f1940,
    FUN_081f1994,
    Entity081f26bc_StateBounce,
    Entity081f26bc_StateVanish,
};  // 0x085AE538

NAKED void FUN_081f17c8(Entity081f26bc* p) { INCFUNC("asm/func/FUN_081f17c8.inc"); }

NAKED void Entity081f26bc_UpdateHitbox(Entity081f26bcElem* e, Vec3* pos) { INCFUNC("asm/func/Entity081f26bc_UpdateHitbox.inc"); }

void FUN_081f1888(void) {}

NAKED void Entity081f26bc_InitHitbox(Entity081f26bcElem* e, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081f26bc_InitHitbox.inc"); }

void FUN_081f1940(Entity081f26bc* p, Entity081f26bcElem* e) {}

NAKED Entity081f26bcElem* Entity081f26bc_AllocElem(Entity081f26bc* p) { INCFUNC("asm/func/Entity081f26bc_AllocElem.inc"); }

NAKED void FUN_081f1994(Entity081f26bc* p, Entity081f26bcElem* e) { INCFUNC("asm/func/FUN_081f1994.inc"); }

NAKED void Entity081f26bc_StateBounce(Entity081f26bc* p, Entity081f26bcElem* e) { INCFUNC("asm/func/Entity081f26bc_StateBounce.inc"); }

// 点滅して消える状態, アニメを進めながら点滅させ, 消えきったら obj を解放して枠を空ける
// 残差はレジスタ割当 (292/321), 原典は anim を ip に追い出して使うたび低位レジスタへ移すが, こちらは r4 に収まり &e->flags が r8 に回る
// 手動送りは AuxSprite_AdvanceAnim / Particle_AdvanceAnim で原典と同形, anim のローカル化 (関数頭 / 分岐内), 送り全体の inline 化は試済
NON_MATCH void Entity081f26bc_StateVanish(Entity081f26bc* p, Entity081f26bcElem* e) {
#ifdef NONMATCHING_C
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->vanishTimer = 0;
  }
  if (e->flags & 8) {
    AuxSprite_AdvanceAnim(e->obj, &e->anim);
  } else {
    Entity081f26bcPtcl* ptcl = e->obj;

    Particle_AdvanceAnim(&ptcl->ptcl, ptcl->group, &e->anim);
  }
  if (Sprite_UpdateVanishBlink(e->flags & 8 ? &((AuxSprite*)e->obj)->flags : &((Particle*)e->obj)->flags, e->vanishTimer, 60, 40)) {
    CLEAR_BIT(gEntity081f26bc->usedMask, e->idx);
    e->state = 0;
    if (e->flags & 8) {
      AuxSprite* spr = e->obj;

      if (spr->active) {
        AuxSprite_Remove(spr);
        Free(e->obj);
      }
    } else {
      Particle* ptcl = e->obj;

      if (ptcl->active) {
        Particle_Remove(ptcl);
        Free(e->obj);
      }
    }
    e->idx = -1;
    e->flags = 0;
  } else {
    e->vanishTimer++;
  }
#else
  INCFUNC("asm/func/Entity081f26bc_StateVanish.inc");
#endif
}

NAKED AuxAnimFile* Entity081f26bc_LoadAuxSprite(Entity081f26bcElem* e, SpriteID32 spriteID, u32 animFileID) { INCFUNC("asm/func/Entity081f26bc_LoadAuxSprite.inc"); }

NAKED Entity081f26bcElem* Entity081f26bc_Spawn(
    Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY) {
  INCFUNC("asm/func/Entity081f26bc_Spawn.inc");
}

NAKED s32 Entity081f26bc_Update(Entity081f26bc* p) { INCFUNC("asm/func/Entity081f26bc_Update.inc"); }

NAKED s32 Entity081f26bc_Destroy(Entity081f26bc* p) { INCFUNC("asm/func/Entity081f26bc_Destroy.inc"); }

s32 Entity081f26bc_Init(Entity081f26bc* p) {
  p->usedMask = 0;
  gEntity081f26bc = p;
  return 0;
}

NAKED Entity081f26bc* Entity081f26bc_Create(void) { INCFUNC("asm/func/Entity081f26bc_Create.inc"); }

void FUN_081f2708(void) { gEntity081f26bc = NULL; }
