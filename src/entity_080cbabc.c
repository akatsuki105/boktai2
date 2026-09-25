#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sprite.h"

// 角度と速度で飛ぶ攻撃判定つきのエフェクト。地形より低くなるか 60 フレームで消える
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  AuxSprite sprite;   // 0x18, AuxSprite_Add(&sprite, &gfx, 0)。Hitbox_SetPos は &sprite.pos を取る
  AuxSpriteGfx gfx;   // 0x44, SPRITE_210E
  HitboxData hitbox;  // 0x60, FUN_080cb94c が Hitbox_Init / _SetAttack / _SetHandler / _SetPos / _Register する
  s16 velX;           // 0xB0, gSineTable[(angle + 0x40) & 0xFF] * speed >> 12 (0方向への丸め)
  u16 unk_b2;         // 0xB2, _Init が 0 を入れる。読み手が見つかっていない
  s16 velZ;           // 0xB4, gSineTable[angle & 0xFF] * speed >> 12 (0方向への丸め)
  u8 unk_b6[2];       // 0xB6, 読み書きとも無し, padding?
  s32 state;          // 0xB8, 0 の間は飛行、それ以外は着弾処理
  Facing16 dir;       // 0xBC, ((angle + 0x10 & 0xFF) >> 5) + 3 & 7
  u16 timer;          // 0xBE, 飛行中は 60 で、着弾後は 6 で終わる
} Entity080cbabc;
static_assert(sizeof(Entity080cbabc) == 192);

// 被弾コールバック。着弾処理へ移る
void FUN_080cb7b4(HitboxData* a, HitboxData* b, Entity080cbabc* p) {
  p->state = 1;
  p->timer = 0;
}

NAKED s32 Entity080cbabc_Update(Entity080cbabc* p) { INCFUNC("asm/func/Entity080cbabc_Update.inc"); }

s32 Entity080cbabc_Destroy(Entity080cbabc* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

void FUN_080cb8f8(Entity080cbabc* p, Vec3* pos, s32 metaspriteIdx, s32 plttID) {
  Video_GetAuxSprite(&p->gfx, SPRITE_210E);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  AuxSprite_SetPoseIdx(&p->sprite, metaspriteIdx);
  Video_SetAuxSpritePltt(&p->gfx, plttID + 44);
  p->sprite.pos = *pos;
}

// 弾の当たり判定を作って登録する
void FUN_080cb94c(Entity080cbabc* p, s32 angle, s32 power, s32 unk_40, s32 attributes, s32 unk_44) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  halfSize.x = 30, halfSize.y = 30, halfSize.z = 30;
  offset.x = 0, offset.y = 0, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_13 | HBFLAG_UNK_8 | HBFLAG_UNK_0, 0, 1, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, unk_40, 0x10, attributes, unk_44);
  Hitbox_SetHandler(hitbox, FUN_080cb7b4, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  hitbox->angle = angle;
  Hitbox_Register(hitbox);
}

NAKED s32 Entity080cbabc_Init(Entity080cbabc* p, Vec3* pos, s32 metaspriteIdx, s32 angle, s32 speed, s32 plttID, s32 param_7, s32 param_8, s32 param_9, u32 param_10) { INCFUNC("asm/func/Entity080cbabc_Init.inc"); }

Entity080cbabc* Entity080cbabc_Create(Vec3* pos, s32 metaspriteIdx, s32 angle, s32 speed, s32 plttID, s32 param_6, s32 param_7, s32 param_8, u32 param_9) {
  Entity080cbabc* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080cbabc));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080cbabc_Update, Entity080cbabc_Destroy);
    if (Entity080cbabc_Init(p, pos, metaspriteIdx, angle, speed, plttID, param_6, param_7, param_8, param_9) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
