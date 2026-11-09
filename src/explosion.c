#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite_aux.h"

// 爆発の 効果処理 及び 演出 (おそらくゲーム内のほぼ全ての爆発がこれを使う)

// _Create が Explosion_Create と Explosion_CreateDelayed と Explosion_CreateWithAttrs の 3つある (_Init, _Update, _Destroy は共有)
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_10
  AuxSprite sprite;   // 0x18
  AuxSpriteGfx gfx;   // 0x44, SPRITE_EXPLOSION
  HitboxData hitbox;  // 0x60, timer が 8 未満の間だけ毎フレーム登録し直す
  u16 delay;          // 0xB0, 0 になるまで何もしない
  u16 timer;          // 0xB2, 毎フレーム +1, 23 を越えると自分を消す
} Explosion;
static_assert(sizeof(Explosion) == 180);

// delay を待ってから爆発を見せ, アニメが終わったら自分を消す
s32 Explosion_Update(Explosion* p) {
  if (p->delay != 0) {
    p->delay--;
  } else {
    AuxSprite_SetPoseIdx(&p->sprite, p->timer >> 2);
    if (p->timer == 0) {
      AuxSprite_Show(&p->sprite);
      PlaySound_082406e0(SE_EXPLOSION);
    }
    if (p->timer < 8) {
      Hitbox_Register(&p->hitbox);
    }
    p->timer++;
    if (p->timer > 23) {
      KillEntity(&p->e);
    }
  }
  return 0;
}

s32 Explosion_Destroy(Explosion* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// 爆発のスプライトを1枚用意する, 隠した状態で始める
void Explosion_InitSprite(AuxSprite* sprite, AuxSpriteGfx* gfx, Vec3* pos, u32 plttOffset) {
  Video_GetAuxSprite(gfx, SPRITE_EXPLOSION);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->poseIdx = 0;
  Video_SetAuxSpritePltt(gfx, 275 + plttOffset);
  sprite->pos = *pos;
  sprite->priority = 1;
  sprite->flags |= SPRFLAG_HIDDEN;
}

// 爆発の攻撃判定を 0x100 角で作る
void Explosion_InitHitbox(Explosion* p, HitboxData* hitbox, s32 ignoreMask, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, ignoreMask, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0x40, attrs, iframes);  // 0x40 は武器以外の攻撃
  Hitbox_SetHandler(hitbox, NULL, p);
}

s32 Explosion_Init(Explosion* p, Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 plttOffset, s32 delay) {
  Explosion_InitSprite(&p->sprite, &p->gfx, pos, plttOffset);
  Explosion_InitHitbox(p, &p->hitbox, ignoreMask, power, knockback, attrs, iframes);
  Hitbox_SetPos(&p->hitbox, pos, 0);
  p->delay = delay;
  p->timer = 0;
  return 0;
}

Explosion* Explosion_Create(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, s32 plttOffset) {
  Explosion* p = CreateEntity(ENTITY_UNK_10, sizeof(Explosion));

  if (p != NULL) {
    SetEntityRoutine(p, Explosion_Update, Explosion_Destroy);
    if (Explosion_Init(p, pos, ignoreMask, power, knockback, HBATTR_INKA | HBATTR_18 | HBATTR_FLAME, 60, plttOffset, 0) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

Explosion* Explosion_CreateDelayed(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, s32 plttOffset, s32 delay) {
  Explosion* p = CreateEntity(ENTITY_UNK_10, sizeof(Explosion));

  if (p != NULL) {
    SetEntityRoutine(p, Explosion_Update, Explosion_Destroy);
    if (Explosion_Init(p, pos, ignoreMask, power, knockback, HBATTR_INKA | HBATTR_18 | HBATTR_FLAME, 60, plttOffset, delay) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

Explosion* Explosion_CreateWithAttrs(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 plttOffset, s32 delay) {
  Explosion* p = CreateEntity(ENTITY_UNK_10, sizeof(Explosion));

  if (p != NULL) {
    SetEntityRoutine(p, Explosion_Update, Explosion_Destroy);
    if (Explosion_Init(p, pos, ignoreMask, power, knockback, attrs, iframes, plttOffset, delay) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
