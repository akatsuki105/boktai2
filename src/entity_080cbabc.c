#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sprite.h"

// 角度と速度で飛ぶ攻撃判定つきのエフェクト, 地形より低くなるか 60 フレームで消える
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  AuxSprite sprite;   // 0x18, AuxSprite_Add(&sprite, &gfx, 0), Hitbox_SetPos は &sprite.pos を取る
  AuxSpriteGfx gfx;   // 0x44, SPRITE_EBALL_210E
  HitboxData hitbox;  // 0x60
  s16 velX;           // 0xB0, gSineTable[(angle + 0x40) & 0xFF] * speed >> 12 (0方向への丸め)
  u16 unk_b2;         // 0xB2, _Init が 0 を入れる, 読み手が見つかっていない
  s16 velZ;           // 0xB4, gSineTable[angle & 0xFF] * speed >> 12 (0方向への丸め)
  u8 unk_b6[2];       // 0xB6, 読み書きとも無し, padding?
  s32 state;          // 0xB8, 0 の間は飛行、それ以外は着弾処理
  Dir8U16 dir;        // 0xBC, ((angle + 0x10 & 0xFF) >> 5) + 3 & 7
  u16 timer;          // 0xBE, 飛行中は 60 で、着弾後は 6 で終わる
} Entity080cbabc;
static_assert(sizeof(Entity080cbabc) == 192);

// 向きに合わせて着弾の絵と反転を選ぶ
static inline void AuxSprite_SetImpactPose(AuxSprite* spr, s32 dir) {
  if (dir & 1) {
    spr->poseIdx = 7;
  } else if ((dir >> 1) & 1) {
    spr->poseIdx = 8;
  } else {
    spr->poseIdx = 6;
  }
  if (dir <= 2) {
    spr->flags &= ~(SPRFLAG_XFLIP | SPRFLAG_YFLIP);
  } else if (dir <= 4) {
    spr->flags = (spr->flags & ~SPRFLAG_XFLIP) | SPRFLAG_YFLIP;
  } else if (dir <= 5) {
    spr->flags |= SPRFLAG_XFLIP | SPRFLAG_YFLIP;
  } else {
    spr->flags = (spr->flags | SPRFLAG_XFLIP) & ~SPRFLAG_YFLIP;
  }
}

// 被弾コールバック, 着弾処理へ移る
void Entity080cbabc_OnHit(HitboxData* a, HitboxData* b, Entity080cbabc* p) {
  p->state = 1;
  p->timer = 0;
}

// 飛行中は進めて当たり判定を出し, 着弾後は向きに合わせた絵に変えて消える
s32 Entity080cbabc_Update(Entity080cbabc* p) {
  if (p->state != 0) {
    p->timer++;
    if (p->timer == 1) {
      p->sprite.poseIdx = 4;
    } else if (p->timer == 4) {
      AuxSprite_SetImpactPose(&p->sprite, p->dir);
    } else if (p->timer > 6) {
      KillEntity(&p->e);
    }
  } else {
    p->sprite.pos.x += p->velX;
    p->sprite.pos.z += p->velZ;
    Hitbox_SetPos(&p->hitbox, &p->sprite.pos, 0);
    Hitbox_Register(&p->hitbox);
    Player_SetFlag20(gPlayerPtr[0], PFLAG20_UNK_19 | PFLAG20_UNK_1);
    if (Map_GetTileHeightAt(&p->sprite.pos) > p->sprite.pos.y) {
      p->state = 1;
      p->timer = 0;
    } else if (++p->timer >= 60) {
      KillEntity(&p->e);
    }
  }
  return 0;
}

s32 Entity080cbabc_Destroy(Entity080cbabc* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// size: 0..3 (0 が 最小, 3: 最大)
void Entity080cbabc_InitSprite(Entity080cbabc* p, WorldPos* pos, s32 size, s32 plttOfs) {
  Video_GetAuxSprite(&p->gfx, SPRITE_EBALL_210E);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  AuxSprite_SetPoseIdx(&p->sprite, size);
  Video_SetAuxSpritePltt(&p->gfx, 44 + plttOfs);
  p->sprite.pos = *pos;
}

// 弾の当たり判定を作って登録する
void Entity080cbabc_InitHitbox(Entity080cbabc* p, s32 angle, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(0.12), Q8(0.12), Q8(0.12));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 1, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 1 << WK_GUN, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity080cbabc_OnHit, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  hitbox->angle = angle;
  Hitbox_Register(hitbox);
}

s32 Entity080cbabc_Init(Entity080cbabc* p, WorldPos* pos, s32 angle, s32 radius, s32 size, s32 plttOfs, s32 power, s32 knockback, HitboxAttributes attrs, u32 iframes) {
  Entity080cbabc_InitSprite(p, pos, size, plttOfs);
  Entity080cbabc_InitHitbox(p, angle, power, knockback, attrs, iframes);
  p->velX = POLAR_X(radius, angle);
  p->unk_b2 = 0;
  p->velZ = POLAR_Z(radius, angle);
  p->dir = Angle_ToDir8(angle);
  p->timer = 0;
  return 0;
}

/**
 * @brief SPRITE_EBALL_210E (弾) を作る
 * @param size 0..3 (0 が 最小, 3: 最大), SPRITE_EBALL_210E の poseIdx
 * @param plttOfs 44 + plttOfs が plttID
 */
Entity080cbabc* Entity080cbabc_Create(WorldPos* pos, s32 angle, s32 radius, s32 size, s32 plttOfs, s32 power, s32 knockback, HitboxAttributes attrs, u32 iframes) {
  Entity080cbabc* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080cbabc));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080cbabc_Update, Entity080cbabc_Destroy);
    if (Entity080cbabc_Init(p, pos, angle, radius, size, plttOfs, power, knockback, attrs, iframes) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
