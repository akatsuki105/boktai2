#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  AuxSprite sprite;       // 0x00, metaspriteIdx は 3
  Vec3 pos;               // 0x2C, 毎フレーム vel を足して sprite.pos に写す
  Vec3 vel;               // 0x34, vel.y は毎フレーム 1 ずつ減る
  HitboxData hitbox;      // 0x3C
  ParticleShadow shadow;  // 0x8C
  s32 timer;              // 0xCC, 状態 2 で 91 まで数えると消える
  s16 unk_d0;             // 0xD0
  u8 state;               // 0xD2, PTR_ARRAY_085ae46c の添字, 1 で飛んで着地すると砕け, 2 で点滅して消える
  s8 idx;                 // 0xD3, elems の添字, 空きは -1
} Entity081ea820Elem;
static_assert(sizeof(Entity081ea820Elem) == 212);

// 氷ブロックを投げ, 着地すると砕けて消える
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_CUBE_ICE
  u32 activeMask;               // 0x034, elems の使用中ビット
  Entity081ea820Elem elems[8];  // 0x038
} Entity081ea820;
static_assert(sizeof(Entity081ea820) == 1752);

static Entity081ea820* gEntity081ea820;  // 0x030001BC

void Entity081ea820Elem_UpdateState0(Entity081ea820*, Entity081ea820Elem*);
void Entity081ea820Elem_UpdateState1(Entity081ea820*, Entity081ea820Elem*);
void Entity081ea820Elem_UpdateState2(Entity081ea820*, Entity081ea820Elem*);

// Entity081ea820_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae46c[3])(Entity081ea820*, Entity081ea820Elem*) = {
    Entity081ea820Elem_UpdateState0,
    Entity081ea820Elem_UpdateState1,
    Entity081ea820Elem_UpdateState2,
};  // 0x085AE46C

NAKED void Entity081ea820Elem_UpdateState0(Entity081ea820* p, Entity081ea820Elem* elem) { INCFUNC("asm/func/Entity081ea820Elem_UpdateState0.inc"); }

NAKED void Entity081ea820Elem_OnHit(HitboxData* a, HitboxData* b, Entity081ea820Elem* elem) { INCFUNC("asm/func/Entity081ea820Elem_OnHit.inc"); }

NAKED void Entity081ea820Elem_InitHitbox(Entity081ea820Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081ea820Elem_InitHitbox.inc"); }

NAKED Entity081ea820Elem* Entity081ea820_AllocElem(Entity081ea820* p) { INCFUNC("asm/func/Entity081ea820_AllocElem.inc"); }

NAKED void Entity081ea820Elem_UpdateState1(Entity081ea820* p, Entity081ea820Elem* elem) { INCFUNC("asm/func/Entity081ea820Elem_UpdateState1.inc"); }

NAKED void Entity081ea820Elem_UpdateState2(Entity081ea820* p, Entity081ea820Elem* elem) { INCFUNC("asm/func/Entity081ea820Elem_UpdateState2.inc"); }

NAKED void Entity081ea820_GetAnimVariant(Mover* src, u8* variant, u8* xflip) { INCFUNC("asm/func/Entity081ea820_GetAnimVariant.inc"); }

NAKED s32 FUN_081ea524(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/FUN_081ea524.inc"); }

NAKED s32 Entity081ea820_ThrowAt(Mover* src, Mover* target, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081ea820_ThrowAt.inc"); }

NAKED s32 Entity081ea820_Spawn(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { INCFUNC("asm/func/Entity081ea820_Spawn.inc"); }

NAKED s32 Entity081ea820_Update(Entity081ea820* p) { INCFUNC("asm/func/Entity081ea820_Update.inc"); }

NAKED s32 Entity081ea820_Destroy(Entity081ea820* p) { INCFUNC("asm/func/Entity081ea820_Destroy.inc"); }

NAKED s32 Entity081ea820_Init(Entity081ea820* p) { INCFUNC("asm/func/Entity081ea820_Init.inc"); }

NAKED Entity081ea820* Entity081ea820_Create(void) { INCFUNC("asm/func/Entity081ea820_Create.inc"); }

NAKED void Entity081ea820_ClearGlobal(void) { INCFUNC("asm/func/Entity081ea820_ClearGlobal.inc"); }
