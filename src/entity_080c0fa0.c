#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "vm.h"

struct Entity080c0fa0;

typedef void(Entity080c0fa0Func)(struct Entity080c0fa0* p);

// _Create が Entity080c0fa0_Create と FUN_080c1108 の2つあるが、後者は使われていない
typedef struct Entity080c0fa0 {
  Entity e;                            // 0x00, ENTITY_UNK_10
  AuxSprite sprite;                    // 0x18, delay が 0 でない間は隠す
  AuxSpriteGfx gfx;                    // 0x44, SPRITE_EFF_210E, パレットは Init の第3引数
  Vec3 pos;                            // 0x60, Init の第2引数のコピー
  u8 unk_68[2];                        // 0x68, まだ未解析
  u16 poseIdx;                         // 0x6A, Init の第4引数
  u16 dir;                             // 0x6C, +1 して & 7 した値で gSineTable を引き速度を作る
  s16 vx;                              // 0x6E, -(速さ * sin(dir+0x40)) >> 12
  s16 vz;                              // 0x70, -(速さ * sin(dir)) >> 12
  u16 delay;                           // 0x72, 0 でなければ隠して待つ方から始める
  u16 lifetime;                        // 0x74, '.l=90', 経過フレームがここに達したらアニメを進める方へ移る
  u16 stateTimer;                      // 0x76, updateCallback を差し替えるたびに 0 に戻る
  Entity080c0fa0Func* updateCallback;  // 0x78
} Entity080c0fa0;
static_assert(sizeof(Entity080c0fa0) == 124);

void Entity080c0fa0_SetUpdateCallback(Entity080c0fa0* p, Entity080c0fa0Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// 向きから反転フラグと表示ポーズを決め, 6フレーム経ったら自分を消す
void Entity080c0fa0_AdvanceAnim(Entity080c0fa0* p) {
  if (p->stateTimer <= 2) {
    p->sprite.poseIdx = (p->poseIdx >> 1) + 4;
  } else {
    s32 idx;
    SpriteFlags flags;

    if (p->dir & 1) {
      idx = 1;
    } else {
      idx = ((p->dir >> 1) & 1) ? 2 : 0;
    }

    if (p->dir <= 2) {
      flags = 0;
    } else if (p->dir <= 4) {
      flags = SPRFLAG_YFLIP;
    } else if (p->dir <= 5) {
      flags = SPRFLAG_XFLIP | SPRFLAG_YFLIP;
    } else {
      flags = SPRFLAG_XFLIP;
    }

    p->sprite.flags |= flags;
    p->sprite.poseIdx = idx + 6;
  }

  p->stateTimer++;
  if (p->stateTimer > 5) {
    KillEntity(&p->e);
  }
}

// 速度ぶん進めてスプライトへ写し, lifetime フレーム経ったらアニメを進める方へ移る
void Entity080c0fa0_UpdateActive(Entity080c0fa0* p) {
  p->pos.x += p->vx;
  p->pos.z += p->vz;
  p->sprite.pos = p->pos;

  p->stateTimer++;
  if (p->stateTimer >= p->lifetime) {
    Entity080c0fa0_SetUpdateCallback(p, Entity080c0fa0_AdvanceAnim);
  }
}

// delay フレーム待ってからスプライトを見せて本体の更新へ移る
void Entity080c0fa0_UpdateDelay(Entity080c0fa0* p) {
  p->stateTimer++;
  if (p->stateTimer >= p->delay) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    Entity080c0fa0_SetUpdateCallback(p, Entity080c0fa0_UpdateActive);
  }
}

s32 Entity080c0fa0_Update(Entity080c0fa0* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity080c0fa0_Destroy(Entity080c0fa0* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

NAKED s32 Entity080c0fa0_Init(Entity080c0fa0* p, Vec3* pos, SpriteID32 pltt, s32 poseIdx, s32 dir, s32 speed, s32 delay, s32 lifetime) { INCFUNC("asm/func/Entity080c0fa0_Init.inc"); }

Entity080c0fa0* Entity080c0fa0_Create(Vec3* pos, SpriteID32 pltt, s32 poseIdx, s32 dir, s32 speed, s32 delay, s32 param_7) {
  Entity080c0fa0* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080c0fa0));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080c0fa0_Update, Entity080c0fa0_Destroy);
    if (Entity080c0fa0_Init(p, pos, pltt, poseIdx, dir, speed, delay, param_7) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// スクリプトの名前付き引数から Init の引数を組み立てる
s32 Entity080c0fa0_InitScripted(Entity080c0fa0* p, u32 param_2, u32 param_3) {
  Vec3 pos;
  s32 pltt;
  s32 poseIdx;
  s32 dir;
  s32 speed;
  s32 delay;
  s32 lifetime;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }

  pltt = VM_SeekToNamedArg('c') ? VM_GetValue() + 44 : 44;
  poseIdx = VM_SeekToNamedArg('E') ? VM_GetValue() : 0;
  dir = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;
  speed = VM_SeekToNamedArg('s') ? VM_GetValue() : 32;
  delay = VM_SeekToNamedArg('w') ? VM_GetValue() : 0;
  lifetime = VM_SeekToNamedArg('l') ? VM_GetValue() : 90;

  Entity080c0fa0_Init(p, &pos, pltt, poseIdx, dir, speed, delay, lifetime);
  return 0;
}

Entity080c0fa0* FUN_080c1108(u32 param_1, u32 param_2) {
  Entity080c0fa0* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080c0fa0));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080c0fa0_Update, Entity080c0fa0_Destroy);
    if (Entity080c0fa0_InitScripted(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
