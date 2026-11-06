#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
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

extern const u8 u8_ARRAY_085ae468[4];

static inline bool8 Entity081ea820_IsElemUsed(Entity081ea820* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081ea820Elem_UpdateState0(Entity081ea820*, Entity081ea820Elem*);
void Entity081ea820Elem_UpdateState1(Entity081ea820*, Entity081ea820Elem*);
void Entity081ea820Elem_UpdateState2(Entity081ea820*, Entity081ea820Elem*);
s32 Entity081ea820_Spawn(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime);
s32 Entity081ea820_Update(Entity081ea820* p);
s32 Entity081ea820_Destroy(Entity081ea820* p);
s32 Entity081ea820_Init(Entity081ea820* p);
Entity081ea820* Entity081ea820_Create(void);
s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
Entity081ea820Elem* Entity081ea820_AllocElem(Entity081ea820* p);
void Entity081ea820_GetAnimVariant(Mover* src, u8* variant, u8* xflip);
void Entity081ea820Elem_InitHitbox(Entity081ea820Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime);

// Entity081ea820_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae46c[3])(Entity081ea820*, Entity081ea820Elem*) = {
    Entity081ea820Elem_UpdateState0,
    Entity081ea820Elem_UpdateState1,
    Entity081ea820Elem_UpdateState2,
};  // 0x085AE46C

void Entity081ea820Elem_UpdateState0(Entity081ea820* p, Entity081ea820Elem* elem) {}

void Entity081ea820Elem_OnHit(HitboxData* a, HitboxData* b, Entity081ea820Elem* elem) {}

void Entity081ea820Elem_InitHitbox(Entity081ea820Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) {
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 16, 16, 16);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockbackPower, 0, attrs, invincibleTime);
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, Entity081ea820Elem_OnHit, elem);
}

Entity081ea820Elem* Entity081ea820_AllocElem(Entity081ea820* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081ea820_IsElemUsed(p, i)) {
      Entity081ea820Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

// 211/212命令, 原典は乱数表のアドレスを vel.x の書き込みの後に読み, ip に置いて使い回す, 試済: table ローカルの位置, Random() マクロ直書き
NON_MATCH void Entity081ea820Elem_UpdateState1(Entity081ea820* p, Entity081ea820Elem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->sprite;
  s32 y;

  spr->pos = elem->pos;
  spr->flags &= ~SPRFLAG_HIDDEN;
  elem->pos.x += elem->vel.x;
  elem->pos.y += elem->vel.y;
  elem->pos.z += elem->vel.z;
  elem->vel.y--;
  y = spr->pos.y;
  if (y < (u32)TileHeightAt(&spr->pos) || spr->pos.y <= 0) {
    Vec3 vel;
    Vec3 velRange;
    u16* table;

    PlaySound_082406e0(SONG_470);
    CLEAR_BIT(p->activeMask, elem->idx);
    elem->state = 0;
    AuxSprite_Remove(spr);
    ParticleShadow_Remove(&elem->shadow);
    elem->idx = -1;
    elem->unk_d0 = 0;
    elem->timer = 0;
    table = gRandomTable;
    VEC3_SET(vel, -12, _Random(table) & 7, -12);
    VEC3_SET(velRange, 24, (_Random(table) & 7) + 3, 24);
    FUN_08014730(6, 3, &elem->pos, &vel, &velRange, 32, 31);
  } else {
    Hitbox_SetPos(&elem->hitbox, &elem->pos, 0);
    Hitbox_Register(&elem->hitbox);
  }
#else
  INCFUNC("asm/func/Entity081ea820Elem_UpdateState1.inc");
#endif
}

// 点滅させてから 91 フレームで消す
void Entity081ea820Elem_UpdateState2(Entity081ea820* p, Entity081ea820Elem* elem) {
  AuxSprite* spr = &elem->sprite;
  s32 phase;

  if (elem->timer > 60) {
    phase = 2;
  } else if (elem->timer > 40) {
    phase = 1;
  } else {
    phase = 0;
  }

  if (Mod(elem->timer, u8_ARRAY_085ae468[phase]) == 0) {
    if (spr->flags & SPRFLAG_HIDDEN) {
      spr->flags &= ~SPRFLAG_HIDDEN;
    } else {
      spr->flags |= SPRFLAG_HIDDEN;
    }
  }
  if (elem->timer > 90) {
    CLEAR_BIT(p->activeMask, elem->idx);
    elem->state = 0;
    AuxSprite_Remove(spr);
    ParticleShadow_Remove(&elem->shadow);
    elem->idx = -1;
    elem->unk_d0 = 0;
    elem->timer = 0;
  } else {
    elem->timer++;
  }
}

// src の向きを 4 方向に丸め, 左右反転とアニメの variant に分ける
void Entity081ea820_GetAnimVariant(Mover* src, u8* variant, u8* xflip) {
  u16 dir = Angle_ToDir4(src->angle);

  if (dir > 1) {
    *xflip = TRUE;
    *variant = 3 - dir;
  } else {
    *xflip = FALSE;
    *variant = dir;
  }
}

// vel を指定して氷ブロックを投げる
s32 Entity081ea820_Throw(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) { return Entity081ea820_Spawn(src, target, vel, power, knockbackPower, attrs, invincibleTime); }

// 148/147命令, 原典は Div(n, 2) を呼んでから乱数の添字を進めるが, こちらは添字を先に進める, 試済: 加算の左右, 一旦 vel.y に入れて足す, (u16) キャスト
NON_MATCH s32 Entity081ea820_ThrowAt(Mover* src, Mover* target, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 n;

  vel.x = target->pos.x - src->pos.x;
  vel.z = target->pos.z - src->pos.z;
  n = (Random() & 0x3F) + 30;
  vel.x = Div(vel.x, n);
  vel.z = Div(vel.z, n);
  vel.y = Div(n, 2) + (Random() & 7);
  if (vel.x > 48) {
    vel.x = 48;
  }
  if (vel.x < -48) {
    vel.x = -48;
  }
  if (vel.z > 48) {
    vel.z = 48;
  }
  if (vel.z < -48) {
    vel.z = -48;
  }
  return Entity081ea820_Spawn(src, target, &vel, power, knockbackPower, attrs, invincibleTime);
#else
  INCFUNC("asm/func/Entity081ea820_ThrowAt.inc");
#endif
}

// src の位置から vel で氷ブロックを1つ投げ, elems の添字を返す
s32 Entity081ea820_Spawn(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) {
  Entity081ea820* p = gEntity081ea820;
  Entity081ea820Elem* elem;
  u8 variant;
  u8 xflip;

  if (p == NULL) {
    p = Entity081ea820_Create();
    if (p == NULL) {
      return -1;
    }
  }
  elem = Entity081ea820_AllocElem(p);
  if (elem == NULL) {
    return -1;
  }
  elem->state = 1;
  Entity081ea820_GetAnimVariant(src, &variant, &xflip);
  elem->pos = src->pos;
  elem->unk_d0 = 0;
  elem->vel = *vel;
  ParticleShadow_Init(&elem->shadow, &elem->pos, 0);
  elem->sprite.pos = elem->pos;
  AuxSprite_Add(&elem->sprite, &p->gfx, 0);
  elem->sprite.poseIdx = 3;
  Video_SetAuxSpritePltt(elem->sprite.gfx, 0x243);
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  elem->sprite.priority = 2;
  Entity081ea820Elem_InitHitbox(elem, power, knockbackPower, attrs, invincibleTime);
  return elem->idx;
}

s32 Entity081ea820_Update(Entity081ea820* p) {
  Entity081ea820Elem* elems = p->elems;
  s32 i;

  if (p->activeMask != 0) {
    for (i = 0; i < 8; i++) {
      if (Entity081ea820_IsElemUsed(p, i)) {
        PTR_ARRAY_085ae46c[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity081ea820_Destroy(Entity081ea820* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081ea820_IsElemUsed(p, i)) {
      Entity081ea820Elem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->sprite);
      ParticleShadow_Remove(&elem->shadow);
    }
  }
  gEntity081ea820 = NULL;
  return 0;
}

s32 Entity081ea820_Init(Entity081ea820* p) {
  p->activeMask = 0;
  gEntity081ea820 = p;
  Video_GetAuxSprite(&p->gfx, SPRITE_CUBE_ICE);
  return 0;
}

Entity081ea820* Entity081ea820_Create(void) {
  Entity081ea820* p;

  if (gEntity081ea820 != NULL) {
    return gEntity081ea820;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081ea820));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081ea820_Update, Entity081ea820_Destroy);
    if (Entity081ea820_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081ea820_ClearGlobal(void) { gEntity081ea820 = NULL; }
