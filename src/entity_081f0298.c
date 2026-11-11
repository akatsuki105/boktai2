#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// 角度 angle の向きへ放物線を描いて飛び, 着地すると点滅して消える攻撃判定付きの物体1個
typedef struct {
  AuxSprite sprite;   // 0x00
  AuxAnimState anim;  // 0x2C, 飛行中は animIdx 18, 着地後は 19, variant は angle から決まる
  Vec3 vel;           // 0x3C, 毎フレーム sprite.pos に足す, y は毎フレーム 1 ずつ減る
  HitboxData hitbox;  // 0x44
  u16 unk_94;         // 0x94, 生成時に 0 が入るだけ
  u8 state;           // 0x96, sEntity081f0298States の添字 (0: 待機, 1: 飛行, 2: 着地)
  s8 slotIdx;         // 0x97, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;          // 0x98, 着地後は 19 フレームを超えると点滅を始め, 70 フレームを超えると消える
  bool8 stateBegun;   // 0x9A, 着地した次のフレームで着地アニメに切り替えて 0 に戻す
  u8 angle;           // 0x9B, 飛ぶ向き, gSineTable の添字
} Entity081f0298Elem;
static_assert(sizeof(Entity081f0298Elem) == 156);

// スケルトンが出す物体を最大12個まで管理するシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x018, SPRITE_SKELETON_MISC
  AuxAnimFile* animFile;         // 0x034, ANIM_1DC3
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f0298Elem elems[12];  // 0x03C
} Entity081f0298;
static_assert(sizeof(Entity081f0298) == 1932);

static Entity081f0298* gEntity081f0298;  // 0x030001E0

static inline bool8 Entity081f0298_IsUsed(Entity081f0298* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

// angle を4方向に丸め, 左右反転とアニメの variant に分ける
static inline void Entity081f0298_GetAnimVariant(u8 angle, u8* variant, u8* xflip) {
  u16 dir = Angle_ToDir4(angle);

  if (dir > DIR4_EAST) {
    *xflip = TRUE;
    *variant = 3 - dir;
  } else {
    *xflip = FALSE;
    *variant = dir;
  }
}

s32 Entity081f0298_Update(Entity081f0298* p);
s32 Entity081f0298_Destroy(Entity081f0298* p);
s32 Entity081f0298_Init(Entity081f0298* p);
Entity081f0298* Entity081f0298_Create(void);

const u8 sEntity081f0298BlinkIntervals[4] = {8, 4, 2, 1};  // 0x085AE508

void Entity081f0298_OnHit(HitboxData* a, HitboxData* b, Entity081f0298Elem* elem) {}

// 物体の攻撃判定を作る
void Entity081f0298_InitHitbox(Entity081f0298Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  VEC3_SET(size, Q8(0.125), Q8(0.25), Q8(0.125));
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f0298_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

void Entity081f0298_UpdateIdle(Entity081f0298* p, Entity081f0298Elem* elem) {}

// 着地から 20 フレームを過ぎたら次第に速く点滅させ, 70 フレームを超えたら消して空きに戻す
void Entity081f0298_BlinkOut(Entity081f0298* p, Entity081f0298Elem* elem) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->timer > 19) {
    s32 phase;

    if (elem->timer > 50) {
      phase = 2;
    } else if (elem->timer > 30) {
      phase = 1;
    } else {
      phase = 0;
    }

    if (Mod(elem->timer, sEntity081f0298BlinkIntervals[phase]) == 0) {
      if (sprite->flags & SPRFLAG_HIDDEN) {
        sprite->flags &= ~SPRFLAG_HIDDEN;
      } else {
        sprite->flags |= SPRFLAG_HIDDEN;
      }
    }
    if (elem->timer > 70) {
      AuxSprite_Hide(sprite);
      CLEAR_BIT(p->usedMask, elem->slotIdx);
      elem->state = 0;
      AuxSprite_Remove(sprite);
      elem->slotIdx = -1;
    }
  }
}

// state 2, 着地アニメに切り替えて流し, 点滅させて消す
void Entity081f0298_UpdateLanded(Entity081f0298* p, Entity081f0298Elem* elem) {
  u8 variant;
  u8 xflip;

  if (elem->stateBegun) {
    Entity081f0298_GetAnimVariant(elem->angle, &variant, &xflip);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 19, variant, xflip);
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  Entity081f0298_BlinkOut(p, elem);
  elem->timer++;
}

// 残差は next += vel の読み順と TileHeightAt の pos の写し先, Vec3_Add / Vec3_Sum / 成分ごとの += と anim のローカル化は試済
NON_MATCH void Entity081f0298_UpdateFly(Entity081f0298* p, Entity081f0298Elem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim;
  WorldPos next;
  s32 curY;
  s32 nextY;

  AuxSprite_Show(&elem->sprite);
  anim = &elem->anim;
  anim->tick = 0;
  if (elem->timer == 3) {
    anim->cmdIdx = 0;
  } else if (elem->timer == 6) {
    anim->cmdIdx = 1;
  } else {
    anim->cmdIdx = 2;
  }
  AuxSprite_AdvanceAnim(sprite, anim);
  next = sprite->pos;
  Vec3_Add(&next, &elem->vel);
  elem->vel.y--;
  curY = TileHeightAt(&sprite->pos);
  nextY = TileHeightAt(&next);
  sprite->pos = next;
  if (sprite->pos.y < curY || sprite->pos.y < nextY) {
    sprite->pos.x -= elem->vel.x;
    sprite->pos.x -= elem->vel.y;
    sprite->pos.z -= elem->vel.z;
    elem->vel.x = 0;
    elem->vel.y = 0;
    elem->vel.z = 0;
    elem->timer = 0;
    elem->state = 2;
    elem->stateBegun = TRUE;
  } else {
    Hitbox_SetPos(&elem->hitbox, &sprite->pos, 0);
    Hitbox_Register(&elem->hitbox);
    elem->timer++;
  }
#else
  INCFUNC("asm/func/Entity081f0298_UpdateFly.inc");
#endif
}

// 空いているスロットを1つ確保して 0 で埋める
Entity081f0298Elem* Entity081f0298_AllocElem(Entity081f0298* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity081f0298_IsUsed(p, i)) {
      Entity081f0298Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      ClearMemory(elem, sizeof(Entity081f0298Elem));
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

Entity081f0298Elem* FUN_081f0088(Entity081f0298* p) {
  Entity081f0298Elem* elem = Entity081f0298_AllocElem(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

// pos から angle の向きへ speed で物体を投げる
void Entity081f0298_Spawn(Vec3* pos, u32 angle, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 speed) {
  Entity081f0298* p = gEntity081f0298;
  Entity081f0298Elem* elem;
  AuxSprite* sprite;
  u8 variant;
  u8 xflip;

  if (p == NULL) {
    p = Entity081f0298_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = FUN_081f0088(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_94 = 0;
  elem->angle = angle;
  elem->timer = 0;
  Entity081f0298_InitHitbox(elem, power, knockback, attrs, iframes);
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, &p->gfx, 0);
  Entity081f0298_GetAnimVariant(elem->angle, &variant, &xflip);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 18, variant, xflip);
  sprite->pos = *pos;
  elem->vel.x = POLAR_X(speed, elem->angle);
  elem->vel.z = POLAR_Z(speed, elem->angle);
  elem->vel.y = 10;
  AuxSprite_Hide(sprite);
  sprite->priority = 1;
}

void (*const sEntity081f0298States[3])(Entity081f0298*, Entity081f0298Elem*) = {
    Entity081f0298_UpdateIdle,
    Entity081f0298_UpdateFly,
    Entity081f0298_UpdateLanded,
};  // 0x085AE50C

// 使用中の物体を state ごとに動かす
s32 Entity081f0298_Update(Entity081f0298* p) {
  Entity081f0298Elem* elems = p->elems;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081f0298_IsUsed(p, i)) {
      sEntity081f0298States[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081f0298_Destroy(Entity081f0298* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081f0298_IsUsed(p, i)) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081f0298 = NULL;
  return 0;
}

s32 Entity081f0298_Init(Entity081f0298* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_SKELETON_MISC);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_1DC3);
  p->usedMask = 0;
  gEntity081f0298 = p;
  return 0;
}

Entity081f0298* Entity081f0298_Create(void) {
  if (gEntity081f0298 == NULL) {
    Entity081f0298* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f0298));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f0298_Update, Entity081f0298_Destroy);
      if (Entity081f0298_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f0298;
}

void Entity081f0298_ClearGlobal(void) { gEntity081f0298 = NULL; }
