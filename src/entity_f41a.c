#include "collision_map.h"
#include "cwolf_target.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "random.h"
#include "sprite.h"
#include "vm.h"

// 不使用 (おそらく、Cウルフのテスト用のダミー敵)
// SPRITE_BOKU_0 の姿でうろつく生き物, 叩かれると点滅してノックバックし、また歩き出す
typedef struct EntityF41A {
  Entity e;                            // 0x000, ENTITY_UNK_8
  u16 id;                              // 0x018, Init の第2引数, Mover_Init に渡して mover に入れる
  Mover mover;                         // 0x01C
  AuxSprite sprite;                    // 0x060
  AuxSpriteGfx gfx;                    // 0x08C, SPRITE_BOKU_0
  MoverTile tile;                      // 0x0A8, mover.tile がここを指す
  HitboxData hitbox;                   // 0x0B8
  AuxAnimState anim;                   // 0x108
  AuxAnimFile* animFile;               // 0x118, ANIM_BOKU
  CWolfTargetNode target;              // 0x11C, CWolfTargetManager_Register / CWolfTargetManager_Unregister
  u16 targetAngle;                     // 0x12C, 乱数で決める向き, mover.angle がここへ4ずつ近づく
  u16 turnTimer;                       // 0x12E, 0 になると targetAngle を引き直す (0x78..0xB7 フレーム)
  u16 animIdx;                         // 0x130, AuxAnim_SetAnim に渡すアニメ番号
  u16 pushSpeed;                       // 0x132, ノックバックの速さ, 毎フレーム 3/4 になる
  u16 state;                           // 0x134, 0 = うろつく, 1 = 被弾, 2 = ノックバック
  u16 stateTimer;                      // 0x136, state を変えると 0, 被弾中のパレット切り替えに使う
  void (*update)(struct EntityF41A*);  // 0x138, state に対応する更新関数
} EntityF41A;
static_assert(sizeof(EntityF41A) == 316);

void EntityF41A_UpdateWander(EntityF41A* p);
void EntityF41A_UpdateHit(EntityF41A* p);
void EntityF41A_UpdateKnockback(EntityF41A* p);

// state を切り替えて、対応する更新関数を差し込む
void EntityF41A_SetState(EntityF41A* p, s32 state) {
  void (*const handlers[3])(EntityF41A*) = {
      EntityF41A_UpdateWander,
      EntityF41A_UpdateHit,
      EntityF41A_UpdateKnockback,
  };  // 0x08251E08

  p->state = state;
  p->stateTimer = 0;
  p->update = handlers[p->state];
}

// CWolfTargetManager から届く通知, 0 = 攻撃が当たった, 1 = 吹き飛ばし開始
NON_MATCH bool32 EntityF41A_OnMessage(Mover* mover, s32 msg, s32 value) {
#ifdef NONMATCHING_C
  EntityF41A* p = mover->owner;

  if (msg == 0) {
    if (p->state != 2) {
      if (value > 0) {
        Vec3 v;
        v.x = 0, v.y = 0, v.z = 0;
        CreateDamageNumber(&p->hitbox, value, 0, &p->mover.pos, &v, 1);
      }
      EntityF41A_SetState(p, 1);
    }
  } else if (msg == 1) {
    p->pushSpeed = value;
    p->target.flags |= 1;
    EntityF41A_SetState(p, 2);
  }
  return TRUE;
#else
  INCFUNC("asm/func/EntityF41A_OnMessage.inc");
#endif
}

// targetAngle へ向きを4ずつ寄せながらうろつく, turnTimer が切れたら向きを引き直す
void EntityF41A_UpdateWander(EntityF41A* p) {
  if (p->mover.angle != p->targetAngle) {
    if (((p->targetAngle - p->mover.angle + 0x100) & 0xFF) < 0x80) {
      p->mover.angle = p->mover.angle + 4;
    } else {
      p->mover.angle = p->mover.angle + 0xFC;
    }
  }
  if (p->turnTimer == 0) {
    p->targetAngle = 64 * (RandomNext() & 3);
    p->turnTimer = 120 + (RandomNext() & 0x3F);
  } else {
    p->turnTimer--;
  }
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_Register(&p->hitbox);
  p->animIdx = 7;
}

// 被弾中, 6フレームだけ明るいパレットにして点滅させる
void EntityF41A_UpdateHit(EntityF41A* p) {
  if (p->stateTimer <= 5) {
    Video_SetAuxSpritePltt(&p->gfx, OBP_WHITE_306);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, 307);
  }
  p->animIdx = 2;
  p->stateTimer++;
}

// 吹き飛ばされている間, speed を 3/4 ずつ減らし、0 になったら向きを反転してうろつきに戻る
void EntityF41A_UpdateKnockback(EntityF41A* p) {
  p->animIdx = 2;
  if (p->pushSpeed != 0) {
    p->mover.delta.x += POLAR_X(p->pushSpeed, p->mover.angle);
    p->mover.delta.z += POLAR_Z(p->pushSpeed, p->mover.angle);
    p->pushSpeed = (p->pushSpeed * 3) >> 2;
  } else {
    p->mover.angle += 0x80;
    p->targetAngle = p->mover.angle;
    CLEAR_FLAGS((&p->target)->flags, 1);
    EntityF41A_SetState(p, 0);
  }
}

// 向きを4方向に丸めてアニメの variant と左右反転を決め, アニメを1コマ進める
void EntityF41A_UpdateAnim(EntityF41A* p) {
  s32 dir = ((((p->mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3;
  s32 variant;
  s32 xflip;

  if (dir > 1) {
    variant = 3 - dir;
    xflip = TRUE;
  } else {
    variant = dir;
    xflip = FALSE;
  }
  AuxAnim_SetAnim(&p->anim, p->animFile, p->animIdx, variant, xflip);
  AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
}

s32 EntityF41A_Update(EntityF41A* p) {
  p->update(p);
  EntityF41A_UpdateAnim(p);
  Mover_ApplyMove(&p->mover);
  return 0;
}

s32 EntityF41A_Destroy(EntityF41A* p) {
  AuxSprite_Remove(&p->sprite);
  Mover_Unlink(&p->mover);
  CWolfTargetManager_Unregister(&p->target);
  return 0;
}

// '.p' で位置をもらい、その足元の高さに吸着させてから mover を登録する
void EntityF41A_InitMover(EntityF41A* p) {
  Vec3 pos;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  pos.y = TileHeightAt(&pos);
  Mover_Init(&p->mover, p->id, &pos, 0, 7, p);
}

// 足元のタイル情報を取って mover に結びつける
void EntityF41A_InitTile(EntityF41A* p) {
  Map_InitMoverTile(&p->tile, &p->mover.pos);
  Mover_SetCollision(&p->mover, &p->tile, 30, 30);
}

// AuxSprite を用意して mover に結びつけ、アニメファイルを読む
void EntityF41A_InitSprite(EntityF41A* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOKU_0);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  Mover_SetAuxSprite(&p->mover, &p->sprite);
  Video_SetAuxSpritePltt(&p->gfx, 307);
  p->sprite.pos = p->mover.pos;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_BOKU);
  p->animIdx = 7;
  EntityF41A_UpdateAnim(p);
}

void EntityF41A_InitHitbox(EntityF41A* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size, offset;

  VEC3_SET(size, Q8(0.25), Q8(0.391), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.391), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, 10, 30, 0, 0, 16);
  Hitbox_SetHandler(hitbox, NULL, p);
}

s32 EntityF41A_Init(EntityF41A* p, u32 id, u32 _) {
  p->id = id;
  EntityF41A_InitMover(p);
  EntityF41A_InitTile(p);
  EntityF41A_InitSprite(p);
  EntityF41A_InitHitbox(p);
  CWolfTargetManager_Register(&p->target, &p->mover, EntityF41A_OnMessage);
  EntityF41A_SetState(p, 0);
  return 0;
}

// 0xF41A
EntityF41A* EntityF41A_Create(u32 id, u32 _) {
  EntityF41A* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityF41A));

  if (p != NULL) {
    SetEntityRoutine(p, EntityF41A_Update, EntityF41A_Destroy);
    if (EntityF41A_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
