#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

// ドゥラスロール(第1形態)の飛ばす棘

// 棘1発
typedef struct {
  u32 timer;          // 0x00, 出してからのフレーム数, 60 に達すると消える, 当たったときも 60 にして消す
  Vec3 vel;           // 0x04, 1フレームに sprite.pos へ足す量, y は常に 0
  AuxSprite sprite;   // 0x0C, pos が弾の座標, poseIdx は進む向きで 4..12, 残りの向きは左右反転で表す
  HitboxData hitbox;  // 0x38
} Entity0805d79cElem;
static_assert(sizeof(Entity0805d79cElem) == 136);

// ドゥラスロール(第1形態)の飛ばす棘を最大32発管理する
typedef struct Entity0805d79c {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u32 activeMask;                // 0x018, 1 << i で elems[i] が使用中
  AuxSpriteGfx gfx;              // 0x01C, SPRITE_DURATH_SPIKE
  Entity0805d79cElem elems[32];  // 0x038
} Entity0805d79c;
static_assert(sizeof(Entity0805d79c) == 4408);

// 当たったら寿命を尽きさせて消す
void Entity0805d79c_OnHit(HitboxData* a, HitboxData* b, Entity0805d79cElem* elem) { elem->timer = 60; }

NAKED void Entity0805d79c_InitElem(Entity0805d79c* p, Entity0805d79cElem* elem, s32 idx) { INCFUNC("asm/func/Entity0805d79c_InitElem.inc"); }

void Entity0805d79c_ReleaseElem(Entity0805d79c* p, Entity0805d79cElem* elem, s32 idx) {
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  AuxSprite_Remove(&elem->sprite);
  p->activeMask &= ~(1 << idx);
}

NAKED s32 Entity0805d79c_Update(Entity0805d79c* p) { INCFUNC("asm/func/Entity0805d79c_Update.inc"); }

s32 Entity0805d79c_Destroy(Entity0805d79c* p) {
  Entity0805d79cElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      Entity0805d79c_ReleaseElem(p, elem, i);
    }
  }
  return 0;
}

NAKED s32 Entity0805d79c_Init(Entity0805d79c* p) { INCFUNC("asm/func/Entity0805d79c_Init.inc"); }

Entity0805d79c* Entity0805d79c_Create(void) {
  Entity0805d79c* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0805d79c));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0805d79c_Update, Entity0805d79c_Destroy);
    if (Entity0805d79c_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED Entity0805d79cElem* Entity0805d79c_AllocElem(Entity0805d79c* p, s32* outIdx) { INCFUNC("asm/func/Entity0805d79c_AllocElem.inc"); }

NAKED s32 Entity0805d79c_Spawn(Entity0805d79c* p, s32 power, u32 angle, s32 speed, Vec3* pos) { INCFUNC("asm/func/Entity0805d79c_Spawn.inc"); }
