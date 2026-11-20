#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "puff.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// ドヴァリンの"墨玉"

// 墨玉の弾1発, 何かに当たるか life が尽きると砕けて InkBallPuddle (墨だまり) を残す
typedef struct InkBallShot {
  AuxSprite sprite;     // 0x00, SPRFLAG_HIDDEN が立っていて life が 0 なら空き
  AuxAnimState anim;    // 0x2C, ANIM_38E2 の 2 番
  Hitbox hurtbox;       // 0x3C, 攻撃を受けると InkBallShot_OnHurt で消える
  Hitbox hitbox;        // 0x8C, 当たると InkBallShot_OnHit で砕け始める
  Vec3 vel;             // 0xDC, homing のときは毎フレーム target へ向けて speed の長さに作り直す
  Vec3 target;          // 0xE4
  u16 life;             // 0xEC, 0 でなければ使用中, 飛んでいる間毎フレーム減らし 5 以下で砕ける
  u16 hurtboxDelay;     // 0xEE, 0 になるまで hurtbox に HBF_HIDDEN を立てておく
  u16 puddlePower;      // 0xF0, 砕けたときに残す InkBallPuddle の power
  u16 puddleKnockback;  // 0xF2, 同 knockback
  u16 puddleAttrs;      // 0xF4, 同 attrs
  u16 puddleIframes;    // 0xF6, 同 iframes
  u16 puddleTtl;        // 0xF8, 同 ttl
  u8 state;             // 0xFA, sInkBallShotStates の添字
  u8 stateTimer;        // 0xFB, state に入ってからのフレーム数, 0 のとき最初の更新
  u16 speed;            // 0xFC, homing のときの速さ
  bool8 homing;         // 0xFE, target へ向かって飛ぶなら 1
  u8 unk_ff[5];         // 0xFF, 読み手も書き手も未発見
} InkBallShot;
static_assert(sizeof(InkBallShot) == 260);

typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;       // 0x018, SPR_DVALIN_00
  AuxAnimFile* animFile;  // 0x034, ANIM_38E2
  u32 unk_38;             // 0x038, Init が 0 を書くだけで読み手は未発見
  u8 activeCount;         // 0x03C, 使用中の shots の数
  u8 unk_3d[3];           // 0x03D, padding?
  InkBallShot shots[8];   // 0x040
} InkBallShotManager;
static_assert(sizeof(InkBallShotManager) == 2144);

static InkBallShotManager* gInkBallShotManager;  // 0x03000218

s32 InkBallPuddle_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 ttl);
void InkBallShotManager_Remove(InkBallShot* shot);
void InkBallShot_StateFly(InkBallShotManager* p, InkBallShot* shot);
void InkBallShot_StateBurstStart(InkBallShotManager* p, InkBallShot* shot);
void InkBallShot_StateBurstEnd(InkBallShotManager* p, InkBallShot* shot);

void (*const sInkBallShotStates[3])(InkBallShotManager*, InkBallShot*) = {
    InkBallShot_StateFly,
    InkBallShot_StateBurstStart,
    InkBallShot_StateBurstEnd,
};  // 0x085AE818

void InkBallShot_SetState(InkBallShot* shot, u32 state) {
  shot->state = state;
  shot->stateTimer = 0;
}

// 飛んでいる最中に当たったら砕け始める
void InkBallShot_OnHit(Hitbox* a, Hitbox* b, InkBallShot* shot) {
  if (shot->state == 0) {
    InkBallShot_SetState(shot, 1);
  }
}

// 飛んでいる最中に攻撃を受けたら飛沫を出して消える
void InkBallShot_OnHurt(Hitbox* a, Hitbox* b, InkBallShot* shot) {
  if (shot->life != 0 && shot->state == 0) {
    PlaySound_082406e0(SONG_348);
    Puff_SpawnSpray(4, 2, 0x2000, Q6(1), &shot->sprite.pos);
    InkBallShotManager_Remove(shot);
  }
}

// ダーク属性でソルが弱点の食らい判定を作る
void InkBallShot_InitHurtbox(InkBallShot* shot) {
  Hitbox* hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 128, 128, 128);
  VEC3_SET(offset, 0, 128, 0);
  hurtbox = &shot->hurtbox;
  Hitbox_Init(hurtbox, 0, HBF_HURTBOX | HBF_DAMAGE, 0, 16, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &shot->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, InkBallShot_OnHurt, shot);
  Hitbox_SetPowerAndAttributes(hurtbox, 10, HBATTR_DARK, HBATTR_SOL);
  Hitbox_Register(hurtbox);
}

void InkBallShot_InitHitbox(InkBallShot* shot, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes) {
  Hitbox* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 128, 32);
  VEC3_SET(offset, 0, 128, 0);
  hitbox = &shot->hitbox;
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, InkBallShot_OnHit, shot);
  Hitbox_SetPos(hitbox, &shot->sprite.pos, 0);
}

// 空いている枠を探す, life が 0 で非表示のものが空き
InkBallShot* InkBallShotManager_FindFree(void) {
  InkBallShotManager* p = gInkBallShotManager;
  InkBallShot* shot;
  s32 i;

  if (p->activeCount >= 8) {
    return NULL;
  }
  shot = p->shots;
  for (i = 0; i < 8; i++) {
    if (shot->life == 0 && (shot->sprite.flags & SPRFLAG_HIDDEN)) {
      return shot;
    }
    shot++;
  }
  return NULL;
}

// 空き枠を1つ取って墨玉を出す, target があればそこへ vel.x の速さで追いかける
void InkBallShotManager_Add(Vec3* pos, Vec3* vel, Vec3* target, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  InkBallShotManager* p = gInkBallShotManager;
  InkBallShot* shot = InkBallShotManager_FindFree();

  if (shot != NULL) {
    p->activeCount++;
    InkBallShot_SetState(shot, 0);
    shot->sprite.pos = *pos;
    if (vel == NULL) {
      Vec3_Clear(&shot->vel);
    } else {
      shot->vel = *vel;
    }
    if (target == NULL) {
      Vec3_Clear(&shot->target);
      shot->homing = FALSE;
      shot->speed = 0;
    } else {
      shot->target = *target;
      shot->speed = vel->x;
      shot->homing = TRUE;
    }
    shot->life = life;
    shot->hurtboxDelay = hurtboxDelay;
    shot->sprite.flags &= ~SPRFLAG_HIDDEN;
    InkBallShot_InitHitbox(shot, power, knockback, attrs, iframes);
    shot->puddlePower = puddlePower;
    shot->puddleKnockback = puddleKnockback;
    shot->puddleAttrs = puddleAttrs;
    shot->puddleIframes = puddleIframes;
    shot->puddleTtl = puddleTtl;
  }
}

// 枠を解放する, life を 0 にしてスプライトと hurtbox を隠し, 使用中の数を1つ減らす
void InkBallShotManager_Remove(InkBallShot* shot) {
  InkBallShotManager* p = gInkBallShotManager;

  if (shot != NULL) {
    p->activeCount--;
    shot->life = 0;
    shot->sprite.flags |= SPRFLAG_HIDDEN;
    Hitbox_Hide(&shot->hurtbox);
  }
}

// homing なら target へ向けて speed で進み, 着いたら砕け始める, そうでなければ vel のまま進む, life が尽きても砕ける
// 298/299命令, 原典は target のアドレスを Sqrt の後でスタックへ移し distSq をスタックに置く (こちらは target をすぐスタックへ置く), 割当の差
// Tier A-C 試済 (vel/target/pos のポインタ化, 長さを返す inline, Vec3_Add/Sum の順, 宣言順, dvalinn.c の同形の書き方), 未: speed の読み方の別形
NON_MATCH void InkBallShot_StateFly(InkBallShotManager* p, InkBallShot* shot) {
#ifdef NONMATCHING_C
  Vec3* pos;
  bool32 burst = FALSE;

  if (shot->homing) {
    Vec3* vel = &shot->vel;
    Vec3* target = &shot->target;
    s32 distSq;
    u32 dist;
    u32 speed = shot->speed;

    pos = &shot->sprite.pos;
    vel->x = target->x - pos->x;
    vel->y = target->y - pos->y;
    vel->z = target->z - pos->z;
    distSq = vel->x * vel->x + vel->y * vel->y + vel->z * vel->z;
    dist = (u16)Sqrt(distSq);
    if (dist == 0) {
      distSq = -1;
    } else {
      vel->x = Div(vel->x * speed, dist);
      vel->y = Div(vel->y * speed, dist);
      vel->z = Div(vel->z * speed, dist);
    }
    if (distSq <= shot->speed * shot->speed) {
      shot->sprite.pos = *target;
      burst = TRUE;
    } else {
      Vec3_Add(pos, vel);
    }
  } else {
    pos = &shot->sprite.pos;
    Vec3_Add(pos, &shot->vel);
  }
  AuxSprite_AdvanceAnim(&shot->sprite, &shot->anim);
  Hitbox_SetPos(&shot->hitbox, pos, 0);
  Hitbox_Register(&shot->hitbox);
  Hitbox_SetPos(&shot->hurtbox, pos, 0);
  if (shot->hurtboxDelay != 0) {
    shot->hurtboxDelay--;
    Hitbox_Hide(&shot->hurtbox);
  } else {
    Hitbox_ClearFlags(&shot->hurtbox, HBF_HIDDEN);
  }
  shot->stateTimer++;
  if (--shot->life <= 5) {
    burst = TRUE;
  }
  if (burst) {
    InkBallShot_SetState(shot, 1);
  }
#else
  INCFUNC("asm/func/InkBallShot_StateFly.inc");
#endif
}

// 砕け始めの絵にして hurtbox を出し, 5 フレームで次へ進む
void InkBallShot_StateBurstStart(InkBallShotManager* p, InkBallShot* shot) {
  if (shot->stateTimer == 0) {
    shot->sprite.poseIdx = 30;
    Hitbox_ClearFlags(&shot->hurtbox, HBF_HIDDEN);
  }
  if (++shot->stateTimer > 4) {
    InkBallShot_SetState(shot, 2);
  }
}

// 砕け終わりの絵にして 11 フレーム後に墨だまりを残して消える
void InkBallShot_StateBurstEnd(InkBallShotManager* p, InkBallShot* shot) {
  if (shot->stateTimer == 0) {
    shot->sprite.poseIdx = 31;
    Hitbox_ClearFlags(&shot->hurtbox, HBF_HIDDEN);
  }
  if (++shot->stateTimer > 10) {
    InkBallPuddle_Spawn(&shot->sprite.pos, shot->puddlePower, shot->puddleKnockback, shot->puddleAttrs, shot->puddleIframes, shot->puddleTtl);
    PlaySound_082406e0(SONG_242);
    InkBallShotManager_Remove(shot);
  }
}

// 使用中の弾を state ごとに動かす, 表に無い state に当たるとそこで打ち切る
void InkBallShotManager_Update(InkBallShotManager* p) {
  InkBallShot* shot = p->shots;
  s32 i;

  for (i = 0; i < 8; shot++, i++) {
    if (shot->life != 0) {
      if (shot->state > 2) {
        return;
      }
      sInkBallShotStates[shot->state](p, shot);
    }
  }
}

s32 InkBallShotManager_Destroy(InkBallShotManager* p) {
  InkBallShot* shot = p->shots;
  s32 i;

  for (i = 0; i < 8; shot++, i++) {
    if (shot->sprite.active) {
      AuxSprite_Remove(&shot->sprite);
    }
    Hitbox_Unregister(&shot->hurtbox);
  }
  gInkBallShotManager = NULL;
  return 0;
}

// 8つの枠を全部作り直す, スプライトとアニメを割り当てて判定を初期化し, 全部空きにする
s32 InkBallShotManager_InitShots(InkBallShotManager* p) {
  AuxAnimFile* files;
  InkBallShot* shot;
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPR_DVALIN_00);
  Video_SetAuxSpritePltt(&p->gfx, 566);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_38E2);
  files = p->animFile;

  shot = p->shots;
  for (i = 0; i < 8; shot++, i++) {
    AuxSprite_Add(&shot->sprite, &p->gfx, 0);
    AuxAnim_SetAnim(&shot->anim, files, 2, 0, 0);
    shot->sprite.flags |= SPRFLAG_HIDDEN;
    InkBallShot_InitHurtbox(shot);
    InkBallShot_InitHitbox(shot, 0, 0, 0, 0);
    Vec3_Clear(&shot->vel);
    shot->life = 0;
    shot->hurtboxDelay = 0;
  }
  return 0;
}

s32 InkBallShotManager_Init(InkBallShotManager* p) {
  p->activeCount = 0;
  p->unk_38 = 0;
  Video_GetAuxSprite(&p->gfx, SPR_DVALIN_00);
  if (InkBallShotManager_InitShots(p) < 0) {
    return -1;
  } else {
    return 0;
  }
}

InkBallShotManager* InkBallShotManager_Create(void) {
  InkBallShotManager* p;

  if (gInkBallShotManager != NULL) {
    return gInkBallShotManager;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(InkBallShotManager));
  if (p != NULL) {
    SetEntityRoutine(p, InkBallShotManager_Update, InkBallShotManager_Destroy);
    if (InkBallShotManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// angle の向きに speed で飛ぶ墨玉を出す入口, エンティティがまだなければ先に作る
s32 InkBallShot_SpawnAngled(Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  Vec3 vel;

  if (gInkBallShotManager == NULL) {
    gInkBallShotManager = InkBallShotManager_Create();
  }
  Vec3_SetPolar(&vel, angle, speed);
  InkBallShotManager_Add(pos, &vel, NULL, power, knockback, attrs, iframes, life, hurtboxDelay, puddlePower, puddleKnockback, puddleAttrs, puddleIframes, puddleTtl);
}

// target なしで vel のまま飛ぶ墨玉を出す入口, エンティティがまだなければ先に作る
s32 InkBallShot_Spawn(Vec3* pos, Vec3* vel, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  if (gInkBallShotManager == NULL) {
    gInkBallShotManager = InkBallShotManager_Create();
  }
  InkBallShotManager_Add(pos, vel, NULL, power, knockback, attrs, iframes, life, hurtboxDelay, puddlePower, puddleKnockback, puddleAttrs, puddleIframes, puddleTtl);
}

// target を追いかけて speed で飛ぶ墨玉を出す入口, エンティティがまだなければ先に作る
s32 InkBallShot_SpawnHoming(Vec3* pos, Vec3* target, u32 speed, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  Vec3 vel;

  if (gInkBallShotManager == NULL) {
    gInkBallShotManager = InkBallShotManager_Create();
  }
  Vec3_Set(&vel, speed, 0, 0);
  InkBallShotManager_Add(pos, &vel, target, power, knockback, attrs, iframes, life, hurtboxDelay, puddlePower, puddleKnockback, puddleAttrs, puddleIframes, puddleTtl);
}
