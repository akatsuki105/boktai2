#include "boss/duneyrr.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sound.h"
#include "vec3.h"

// ドゥネイルの攻撃"鱗粉玉"

#define SCALES_BALL 7  // ドゥネイルの"鱗粉玉"(見た目はエネルギーボール)

s32 SporeManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos);
void Entity08015584_SpawnHorizontal(WorldPos* pos, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

static inline void EmitParticles_08059a1c(WorldPos* pos, u8 angle) { Entity08015584_SpawnHorizontal(pos, angle, 0x20, 2, 5, 0x3000, Q6(0.5), 10, 10, 0xF8); }

// 状態を入れ替えて経過フレームを0に戻す
static inline void DuneyrrPowderBall_SetState(DuneyrrPowderBall* elem, u8 state) {
  elem->state = state;
  elem->timer = 0;
  elem->stateEntered = TRUE;
}

void FUN_080592fc(HitboxData* a, HitboxData* b, DuneyrrPowderBall* elem) {}

void DuneyrrPowderBall_InitHitbox(DuneyrrPowderBall* elem, s32 power, s32 knockback, s32 iframes) {
  HitboxData* hitbox = &elem->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.19), Q8(0.125), Q8(0.19));
  VEC3_SET(offset, 0, Q8(0.125), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetHandler(hitbox, FUN_080592fc, elem);
  Hitbox_SetAttack(hitbox, power, knockback, 0, 0, iframes);
}

void DuneyrrPowderBall_OnHurt(HitboxData* a, HitboxData* b, DuneyrrPowderBall* elem) {
  if (elem->state == 1 || elem->state == 2) {
    DuneyrrPowderBall_SetState(elem, 3);
    b->flags |= HBFLAG_HIDDEN;
    EmitParticles_08059a1c(&elem->sprite.pos, a->angle - 0x40);
    EmitParticles_08059a1c(&elem->sprite.pos, a->angle + 0x40);
  }
}

void DuneyrrPowderBall_InitHurtbox(DuneyrrPowderBall* elem) {
  HitboxData* hurtbox = &elem->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, DuneyrrPowderBall_OnHurt, elem);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_Register(hurtbox);
}

s32 DuneyrrPowderBallManager_InitBall(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
  Vec3* pos;
  AuxSpriteGfx* gfx = &elem->gfx;

  if (!Video_GetAuxSprite(gfx, SPRITE_DUNEYRR_AUX)) {
    return -1;
  }
  Video_SetAuxSpritePltt(gfx, 548);
  AuxSprite_Setup(&elem->sprite, gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->anim, SCALES_BALL, 0, 0);
  elem->sprite.priority = 2;
  pos = &elem->sprite.pos;
  Vec3_Clear(pos);
  DuneyrrPowderBall_InitHitbox(elem, p->power, p->knockback, p->iframes);
  DuneyrrPowderBall_InitHurtbox(elem);
  ParticleShadow_Init(&elem->shadow, pos, 0);
  ParticleShadow_Hide(&elem->shadow);
}

s32 DuneyrrPowderBallManager_RemoveBall(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
  u32 bit = 1 << idx;

  if (!(p->activeMask & bit)) {
    return -1;
  }
  AuxSprite_Remove(&elem->sprite);
  ParticleShadow_Hide(&elem->shadow);
  p->activeMask &= ~bit;
  return 0;
}

s32 DuneyrrPowderBallManager_DestroyBall(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
  DuneyrrPowderBallManager_RemoveBall(p, elem, idx);
  ParticleShadow_Remove(&elem->shadow);
  Hitbox_Unregister(&elem->hurtbox);
}

s32 FUN_080595a4(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) { return 0; }

// 残差は sprite->pos と pos を別のレジスタに持つ点と, z 側の 0x100 をレジスタに置いて muls する点
// dst / src を取る Vec3_Add と radius を引数で取る極座標の static inline を挟むと命令数まで揃う (9 ハンク, レジスタ1本の差) が一致しないので残していない, Tier A-C は試済
NON_MATCH s32 FUN_080595a8(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;
  u8 angle;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
  }
  elem->angle += 4;
  pos = &elem->sprite.pos;
  angle = elem->angle;
  pos->x = POLAR_X(0x100, angle);
  pos->y = 0;
  pos->z = POLAR_Z(0x100, angle);
  sprite->pos.x += p->center.x;
  sprite->pos.y += p->center.y;
  sprite->pos.z += p->center.z;
  Hitbox_SetPos(&elem->hurtbox, &sprite->pos, 0);
  if (elem->timer >= 64) {
    DuneyrrPowderBall_SetState(elem, 2);
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080595a8.inc");
#endif
}

s32 FUN_0805965c(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 ofs;
  s32 radius;

  if (elem->stateEntered) {
    Vec3* start;
    Vec3* target;
    s32 dx;
    s32 dz;

    elem->stateEntered = FALSE;
    elem->startPos = sprite->pos;
    elem->targetPos = p->player->mover.pos;
    start = &elem->startPos;
    target = &elem->targetPos;
    elem->angle = ArcTan2_8(target->x - start->x, target->z - start->z);
    dx = target->x - start->x;
    dz = target->z - start->z;
    elem->dist = Sqrt(dx * dx + dz * dz);
    Hitbox_ClearFlags(&elem->hurtbox, HBFLAG_HIDDEN);
  }
  Vec3_SetPolar(&ofs, elem->angle, (elem->dist * elem->timer) >> 6);
  Vec3_Sum(&sprite->pos, &elem->startPos, &ofs);
  sprite->pos.y = elem->startPos.y + FixToInt(12, SIN(elem->timer * 2) * 0x200);
  if (elem->timer > 0x1F && sprite->pos.y <= 0x1FF) {
    Hitbox_SetPos(&elem->hitbox, &sprite->pos, 0);
    Hitbox_Register(&elem->hitbox);
  }
  if (elem->timer >= 64) {
    PlaySound_082406e0(SONG_963);
    DuneyrrPowderBall_SetState(elem, 3);
    {
      HitboxData* hurtbox = &elem->hurtbox;
      hurtbox->flags |= HBFLAG_HIDDEN;
    }
    SporeManager_Emit(3, 0, 0x100, 2, 2, 30, p->sporePower, 0, &sprite->pos);
  }
  return 0;
}

s32 FUN_08059804(DuneyrrPowderBallManager* p, DuneyrrPowderBall* elem, s32 idx) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    DuneyrrPowderBallManager_RemoveBall(p, elem, idx);
  }
  return 0;
}

// 使用中の要素ごとに state の処理を呼んでアニメを1コマ進め, 当たり判定の位置を合わせ, state 1 の数を数える
s32 DuneyrrPowderBallManager_Update(DuneyrrPowderBallManager* p) {
  static s32 (*const PTR_ARRAY_085ab9dc[4])(DuneyrrPowderBallManager*, DuneyrrPowderBall*, s32) = {
      FUN_080595a4,
      FUN_080595a8,
      FUN_0805965c,
      FUN_08059804,
  };  // 0x085AB9DC

  s32 count = 0;
  DuneyrrPowderBall* elem = p->balls;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      PTR_ARRAY_085ab9dc[elem->state](p, elem, i);
      AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
      if (elem->state == 1) {
        count++;
      }
      elem->timer++;
    }
  }
  p->circlingCount = count;
  p->frameCount++;
  return 0;
}

s32 DuneyrrPowderBallManager_Destroy(DuneyrrPowderBallManager* p) {
  DuneyrrPowderBall* elem = p->balls;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    DuneyrrPowderBallManager_DestroyBall(p, elem, i);
  }
  return 0;
}

s32 DuneyrrPowderBallManager_Init(DuneyrrPowderBallManager* p, s32 power, s32 knockback, s32 param_4, s32 param_5) {
  DuneyrrPowderBall* elem;
  s32 i;

  p->anim = GetFile(DIR_ANIMATION, ANIM_31F4);
  p->power = power;
  p->knockback = knockback;
  p->iframes = param_4;
  p->sporePower = param_5;
  elem = p->balls;
  for (i = 0; i < 8; i++, elem++) {
    DuneyrrPowderBallManager_InitBall(p, elem, i);
  }
  p->center.x = 0x680;
  p->center.y = 0x100;
  p->center.z = 0x780;
  p->player = GetPlayer(0);
}

DuneyrrPowderBallManager* DuneyrrPowderBallManager_Create(s32 power, s32 knockback, s32 param_3, s32 param_4) {
  DuneyrrPowderBallManager* p = CreateEntity(ENTITY_UNK_8, sizeof(DuneyrrPowderBallManager));

  if (p != NULL) {
    SetEntityRoutine(p, DuneyrrPowderBallManager_Update, DuneyrrPowderBallManager_Destroy);
    if (DuneyrrPowderBallManager_Init(p, power, knockback, param_3, param_4) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 残差はループの中で読む activeMask がこちらではループの外へ出される点と, pos / center のポインタの持ち方, FUN_080595a8 と同じ inline を挟むと 15 ハンクまで縮むが一致しないので残していない, Tier A-C は試済
NON_MATCH s32 DuneyrrPowderBallManager_AddBall(DuneyrrPowderBallManager* p, u32 angle, u32 param_3) {
#ifdef NONMATCHING_C
  DuneyrrPowderBall* elem;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  elem = p->balls;
  for (i = 0; i < 8; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      AuxSprite* sprite = &elem->sprite;

      DuneyrrPowderBall_SetState(elem, 1);
      elem->angle = angle;
      elem->unk_3 = param_3;
      elem->hitbox.power = p->power;
      sprite->pos.x = POLAR_X(0x100, elem->angle);
      sprite->pos.y = 0;
      sprite->pos.z = POLAR_Z(0x100, elem->angle);
      sprite->pos.x += p->center.x;
      sprite->pos.y += p->center.y;
      sprite->pos.z += p->center.z;
      ParticleShadow_Show(&elem->shadow);
      sprite->poseIdx = 41;
      Video_AddAuxSpriteIntoDrawList(sprite, 0);
      p->activeMask |= 1 << i;
      break;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/DuneyrrPowderBallManager_AddBall.inc");
#endif
}
