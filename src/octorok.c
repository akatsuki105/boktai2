#include "eff_scatter.h"
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

// ドヴァリン、オクトパスの投げる岩

typedef struct {
  AuxSprite sprite;       // 0x00, metaspriteIdx は 3
  Vec3 pos;               // 0x2C, 毎フレーム vel を足して sprite.pos に写す
  Vec3 vel;               // 0x34, vel.y は毎フレーム 1 ずつ減る
  HitboxData hitbox;      // 0x3C
  ParticleShadow shadow;  // 0x8C
  s32 timer;              // 0xCC, 状態 2 で 91 まで数えると消える
  s16 unk_d0;             // 0xD0
  u8 state;               // 0xD2, sOctorokStates の添字, 1 で飛んで着地すると砕け, 2 で点滅して消える
  s8 idx;                 // 0xD3, octoroks の添字, 空きは -1
} Octorok;
static_assert(sizeof(Octorok) == 212);

// 岩を投げ, 着地すると砕けて消える
typedef struct {
  Entity e;             // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;     // 0x018, SPRITE_CUBE_ICE, この1番小さいやつを岩として使う
  u32 activeMask;       // 0x034, octoroks の使用中ビット
  Octorok octoroks[8];  // 0x038
} OctorokManager;
static_assert(sizeof(OctorokManager) == 1752);

static OctorokManager* gOctorokManager;  // 0x030001BC

s32 Octorok_Spawn(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);
OctorokManager* OctorokManager_Create(void);

static inline bool8 OctorokManager_IsUsed(OctorokManager* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

void Octorok_UpdateState0(OctorokManager* p, Octorok* octorok) {}

void Octorok_OnHit(HitboxData* a, HitboxData* b, Octorok* octorok) {}

void Octorok_InitHitbox(Octorok* octorok, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 16, 16, 16);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &octorok->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetPos(hitbox, &octorok->pos, 0);
  Hitbox_SetHandler(hitbox, Octorok_OnHit, octorok);
}

Octorok* OctorokManager_Alloc(OctorokManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!OctorokManager_IsUsed(p, i)) {
      Octorok* octorok = &p->octoroks[i];

      p->activeMask |= 1 << i;
      octorok->idx = i;
      return octorok;
    }
  }
  return NULL;
}

void Octorok_UpdateState1(OctorokManager* p, Octorok* octorok) {
  AuxSprite* spr = &octorok->sprite;
  s32 y;

  spr->pos = octorok->pos;
  spr->flags &= ~SPRFLAG_HIDDEN;
  octorok->pos.x += octorok->vel.x;
  octorok->pos.y += octorok->vel.y;
  octorok->pos.z += octorok->vel.z;
  octorok->vel.y--;
  y = spr->pos.y;
  if (y < (u32)TileHeightAt(&spr->pos) || spr->pos.y <= 0) {
    Vec3 vel;
    Vec3 velRange;

    PlaySound_082406e0(SONG_470);
    CLEAR_BIT(p->activeMask, octorok->idx);
    octorok->state = 0;
    AuxSprite_Remove(spr);
    ParticleShadow_Remove(&octorok->shadow);
    octorok->idx = -1;
    octorok->unk_d0 = 0;
    octorok->timer = 0;
    VEC3_SET(vel, -12, RandomNext() & 7, -12);
    VEC3_SET(velRange, 24, (RandomNext() & 7) + 3, 24);
    ScatterEffect_Spawn(6, SCATTER_STONE, &octorok->pos, &vel, &velRange, 32, 31);
  } else {
    Hitbox_SetPos(&octorok->hitbox, &octorok->pos, 0);
    Hitbox_Register(&octorok->hitbox);
  }
}

// 点滅させてから 91 フレームで消す
void Octorok_UpdateState2(OctorokManager* p, Octorok* octorok) {
  static const u8 u8_ARRAY_085ae468[4] = {8, 4, 2, 1};  // 0x085AE468

  AuxSprite* spr = &octorok->sprite;
  s32 phase;

  if (octorok->timer > 60) {
    phase = 2;
  } else if (octorok->timer > 40) {
    phase = 1;
  } else {
    phase = 0;
  }

  if (Mod(octorok->timer, u8_ARRAY_085ae468[phase]) == 0) {
    if (spr->flags & SPRFLAG_HIDDEN) {
      spr->flags &= ~SPRFLAG_HIDDEN;
    } else {
      spr->flags |= SPRFLAG_HIDDEN;
    }
  }
  if (octorok->timer > 90) {
    CLEAR_BIT(p->activeMask, octorok->idx);
    octorok->state = 0;
    AuxSprite_Remove(spr);
    ParticleShadow_Remove(&octorok->shadow);
    octorok->idx = -1;
    octorok->unk_d0 = 0;
    octorok->timer = 0;
  } else {
    octorok->timer++;
  }
}

// src の向きを 4 方向に丸め, 左右反転とアニメの variant に分ける
void Octorok_GetAnimVariant(Mover* src, u8* variant, u8* xflip) {
  u16 dir = Angle_ToDir4(src->angle);

  if (dir > 1) {
    *xflip = TRUE;
    *variant = 3 - dir;
  } else {
    *xflip = FALSE;
    *variant = dir;
  }
}

// vel を指定して岩を投げる
s32 Octorok_Throw(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) { return Octorok_Spawn(src, target, vel, power, knockback, attrs, iframes); }

s32 Octorok_ThrowAt(Mover* src, Mover* target, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Vec3 vel;
  s32 n;

  vel.x = target->pos.x - src->pos.x;
  vel.z = target->pos.z - src->pos.z;
  n = (RandomNext() & 0x3F) + 30;
  vel.x = Div(vel.x, n);
  vel.z = Div(vel.z, n);
  vel.y = Div(n, 2) + (RandomNext() & 7);
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
  return Octorok_Spawn(src, target, &vel, power, knockback, attrs, iframes);
}

// src の位置から vel で岩を1つ投げ, octoroks の添字を返す
s32 Octorok_Spawn(Mover* src, Mover* target, Vec3* vel, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  OctorokManager* p = gOctorokManager;
  Octorok* octorok;
  u8 variant;
  u8 xflip;

  if (p == NULL) {
    p = OctorokManager_Create();
    if (p == NULL) {
      return -1;
    }
  }
  octorok = OctorokManager_Alloc(p);
  if (octorok == NULL) {
    return -1;
  }
  octorok->state = 1;
  Octorok_GetAnimVariant(src, &variant, &xflip);
  octorok->pos = src->pos;
  octorok->unk_d0 = 0;
  octorok->vel = *vel;
  ParticleShadow_Init(&octorok->shadow, &octorok->pos, 0);
  octorok->sprite.pos = octorok->pos;
  AuxSprite_Add(&octorok->sprite, &p->gfx, 0);
  octorok->sprite.poseIdx = 3;
  Video_SetAuxSpritePltt(octorok->sprite.gfx, OBP_OCTOROK);
  octorok->sprite.flags |= SPRFLAG_HIDDEN;
  octorok->sprite.priority = 2;
  Octorok_InitHitbox(octorok, power, knockback, attrs, iframes);
  return octorok->idx;
}

s32 OctorokManager_Update(OctorokManager* p) {
  static void (*const sOctorokStates[3])(OctorokManager*, Octorok*) = {
      Octorok_UpdateState0,
      Octorok_UpdateState1,
      Octorok_UpdateState2,
  };  // 0x085AE46C

  Octorok* octoroks = p->octoroks;
  s32 i;

  if (p->activeMask != 0) {
    for (i = 0; i < 8; i++) {
      if (OctorokManager_IsUsed(p, i)) {
        sOctorokStates[octoroks[i].state](p, &octoroks[i]);
      }
    }
  }
  return 0;
}

s32 OctorokManager_Destroy(OctorokManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (OctorokManager_IsUsed(p, i)) {
      Octorok* octorok = &p->octoroks[i];

      AuxSprite_Remove(&octorok->sprite);
      ParticleShadow_Remove(&octorok->shadow);
    }
  }
  gOctorokManager = NULL;
  return 0;
}

s32 OctorokManager_Init(OctorokManager* p) {
  p->activeMask = 0;
  gOctorokManager = p;
  Video_GetAuxSprite(&p->gfx, SPRITE_CUBE_ICE);
  return 0;
}

OctorokManager* OctorokManager_Create(void) {
  OctorokManager* p;

  if (gOctorokManager != NULL) {
    return gOctorokManager;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(OctorokManager));
  if (p != NULL) {
    SetEntityRoutine(p, OctorokManager_Update, OctorokManager_Destroy);
    if (OctorokManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void OctorokManager_ClearGlobal(void) { gOctorokManager = NULL; }
