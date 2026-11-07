#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "video.h"

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

void Entity0805d79c_InitElem(Entity0805d79c* p, Entity0805d79cElem* elem, s32 idx) {
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  elem->timer = 0;
  Vec3_Clear(&elem->vel);
  AuxSprite_Setup(&elem->sprite, &p->gfx, 1);
  hitbox = &elem->hitbox;
  VEC3_SET(halfSize, 8, 32, 8);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetHandler(hitbox, Entity0805d79c_OnHit, elem);
  Hitbox_SetAttack(hitbox, 10, 20, 0, 0, 20);
}

void Entity0805d79c_ReleaseElem(Entity0805d79c* p, Entity0805d79cElem* elem, s32 idx) {
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  AuxSprite_Remove(&elem->sprite);
  p->activeMask &= ~(1 << idx);
}

// 使用中の棘を進めて攻撃判定を出し, 60 フレーム経ったら消す
s32 Entity0805d79c_Update(Entity0805d79c* p) {
  Entity0805d79cElem* elem = p->elems;
  Entity0805d79cElem* e = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, elem++, e++) {
    if (p->activeMask & (1 << i)) {
      HitboxData* hitbox = &e->hitbox;
      Vec3* pos = &e->sprite.pos;

      Vec3_Sum(&elem->sprite.pos, &elem->sprite.pos, &elem->vel);
      Hitbox_SetPos(hitbox, pos, 0);
      Hitbox_Register(hitbox);
      if (elem->timer >= 60) {
        Entity0805d79c_ReleaseElem(p, e, i);
      } else {
        elem->timer++;
      }
    }
  }
  return 0;
}

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

s32 Entity0805d79c_Init(Entity0805d79c* p) {
  Entity0805d79cElem* elem;
  AuxSpriteGfx* gfx;
  s32 i;

  p->activeMask = 0;
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_DURATH_SPIKE);
  Video_SetAuxSpritePltt(gfx, 0xDB);
  elem = p->elems;
  for (i = 0; i < 32; i++, elem++) {
    Entity0805d79c_InitElem(p, elem, i);
  }
  return 0;
}

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

// 空いている棘を探して返し, その添字を outIdx に入れる, 空きが無ければ NULL を返して outIdx は 0
Entity0805d79cElem* Entity0805d79c_AllocElem(Entity0805d79c* p, s32* outIdx) {
  Entity0805d79cElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      *outIdx = i;
      return elem;
    }
  }
  *outIdx = 0;
  return NULL;
}

// pos から angle の向きへ speed で棘を1発飛ばす, 空きが無ければ -1
// 127/128命令, 原典は p を r6 / speed を r7 に置き (こちらは逆), 反転の印を r4, &sprite を r1 に作ってから r2 へ写す, 試済: 反転と表示を AuxSprite の inline に, ポーズを AuxSprite_SetPoseIdx に, flip を u32 に
NON_MATCH s32 Entity0805d79c_Spawn(Entity0805d79c* p, s32 power, u32 angle, s32 speed, Vec3* pos) {
#ifdef NONMATCHING_C
  Entity0805d79cElem* elem;
  HitboxData* hitbox;
  AuxSprite* spr;
  s32 idx;
  u8 dir;
  bool8 flip;

  elem = Entity0805d79c_AllocElem(p, &idx);
  if (elem == NULL) {
    return -1;
  }
  hitbox = &elem->hitbox;
  elem->timer = 0;
  Vec3_SetPolar(&elem->vel, angle, speed);
  elem->sprite.pos = *pos;
  dir = ((angle + 0x60) & 0xFF) >> 4;
  if (dir > 8) {
    dir = 16 - dir;
    flip = TRUE;
  } else {
    flip = FALSE;
  }
  spr = &elem->sprite;
  spr->poseIdx = dir + 4;
  if (flip) {
    elem->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    elem->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  Video_AddAuxSpriteIntoDrawList(spr, 0);
  Hitbox_SetAttack(hitbox, power, 20, 0, 0, 20);
  Hitbox_SetPos(hitbox, pos, 0);
  p->activeMask |= 1 << idx;
  return 0;
#else
  INCFUNC("asm/func/Entity0805d79c_Spawn.inc");
#endif
}
