#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite_aux.h"

// _Create が Entity080d84f8_Create と Entity080d84f8_CreateDelayed と Entity080d84f8_CreateWithAttrs の 3つある (_Init, _Update, _Destroy は共有)
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_10
  AuxSprite sprite;   // 0x18, poseIdx は timer >> 2
  AuxSpriteGfx gfx;   // 0x44
  HitboxData hitbox;  // 0x60, timer が 8 未満の間だけ毎フレーム登録し直す
  u16 delay;          // 0xB0, 0 になるまで何もしない
  u16 timer;          // 0xB2, 毎フレーム +1, 23 を越えると自分を消す
} Entity080d84f8;
static_assert(sizeof(Entity080d84f8) == 180);

// delay を待ってから爆発を見せ, アニメが終わったら自分を消す
s32 Entity080d84f8_Update(Entity080d84f8* p) {
  if (p->delay != 0) {
    p->delay--;
  } else {
    AuxSprite_SetPoseIdx(&p->sprite, p->timer >> 2);
    if (p->timer == 0) {
      AuxSprite_Show(&p->sprite);
      PlaySound_082406e0(SONG_405);
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

s32 Entity080d84f8_Destroy(Entity080d84f8* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// 爆発のスプライトを1枚用意する, 隠した状態で始める
void FUN_080d83a8(AuxSprite* sprite, AuxSpriteGfx* gfx, Vec3* pos, u32 plttOffset) {
  Video_GetAuxSprite(gfx, SPRITE_EXPLOSION);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->poseIdx = 0;
  Video_SetAuxSpritePltt(gfx, plttOffset + 275);
  sprite->pos = *pos;
  sprite->priority = 1;
  sprite->flags |= SPRFLAG_HIDDEN;
}

// 爆発の攻撃判定を 0x100 角で作る
void Entity080d84f8_InitHitbox(Entity080d84f8* p, HitboxData* hitbox, s32 ignoreMask, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44) {
  Vec3 halfSize;
  Vec3 offset;

  halfSize.x = 0x80, halfSize.y = 0x80, halfSize.z = 0x80;
  offset.x = 0, offset.y = 0, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, ignoreMask, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, unk_40, HBATTR_ALL, attrs, unk_44);
  Hitbox_SetHandler(hitbox, NULL, p);
}

s32 Entity080d84f8_Init(Entity080d84f8* p, Vec3* pos, s32 ignoreMask, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44, s32 plttOffset, s32 delay) {
  FUN_080d83a8(&p->sprite, &p->gfx, pos, plttOffset);
  Entity080d84f8_InitHitbox(p, &p->hitbox, ignoreMask, power, unk_40, attrs, unk_44);
  Hitbox_SetPos(&p->hitbox, pos, 0);
  p->delay = delay;
  p->timer = 0;
  return 0;
}

NAKED Entity080d84f8* Entity080d84f8_Create(Vec3* pos, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/Entity080d84f8_Create.inc"); }

Entity080d84f8* Entity080d84f8_CreateDelayed(Vec3* pos, s32 ignoreMask, s32 power, s32 unk_40, s32 plttOffset, s32 delay) {
  Entity080d84f8* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080d84f8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080d84f8_Update, Entity080d84f8_Destroy);
    if (Entity080d84f8_Init(p, pos, ignoreMask, power, unk_40, HBATTR_21 | HBATTR_18 | HBATTR_FLAME, 60, plttOffset, delay) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

Entity080d84f8* Entity080d84f8_CreateWithAttrs(Vec3* pos, s32 ignoreMask, s32 power, s32 unk_40, HitboxAttributes attrs, s32 unk_44, s32 plttOffset, s32 delay) {
  Entity080d84f8* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080d84f8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080d84f8_Update, Entity080d84f8_Destroy);
    if (Entity080d84f8_Init(p, pos, ignoreMask, power, unk_40, attrs, unk_44, plttOffset, delay) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
