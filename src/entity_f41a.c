#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "random.h"
#include "sprite.h"
#include "vm.h"

// 不使用?
// SPRITE_BOKU の姿でうろつく生き物, 叩かれると点滅してノックバックし、また歩き出す
typedef struct EntityF41A {
  Entity e;                            // 0x000, ENTITY_UNK_8
  u16 id;                              // 0x018, Init の第2引数, Mover_Init に渡して data に入れる
  u16 unk_1a;                          // 0x01A
  Mover data;                          // 0x01C, 位置と向きはここが持つ, data.unk_5 が向き、data.delta が移動量
  AuxSprite sprite;                    // 0x060
  AuxSpriteGfx gfx;                    // 0x08C, SPRITE_BOKU
  MoverTile tile;                      // 0x0A8, data.tile がここを指す
  HitboxData hitbox;                   // 0x0B8
  AuxAnimState anim;                   // 0x108
  AuxAnimFile* animFile;               // 0x118, ANIM_BOKU
  Entity5941Node detectNode;           // 0x11C, Entity5941_Register / Entity5941_Unregister
  u16 targetAngle;                     // 0x12C, 乱数で決める向き, data.unk_5 がここへ4ずつ近づく
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

// Entity5941 から届く通知, 0 = 攻撃が当たった, 1 = 吹き飛ばし開始
NON_MATCH bool32 EntityF41A_OnMessage(Mover* data, s32 msg, s32 value) {
#ifdef NONMATCHING_C
  EntityF41A* p = data->owner;

  if (msg == 0) {
    if (p->state != 2) {
      if (value > 0) {
        Vec3 v;

        v.x = 0, v.y = 0, v.z = 0;
        CreateDamageNumber(&p->hitbox, value, 0, &p->data.pos, &v, 1);
      }
      EntityF41A_SetState(p, 1);
    }
  } else if (msg == 1) {
    p->pushSpeed = value;
    p->detectNode.flags |= 1;
    EntityF41A_SetState(p, 2);
  }
  return TRUE;
#else
  INCFUNC("asm/func/EntityF41A_OnMessage.inc");
#endif
}

// targetAngle へ向きを4ずつ寄せながらうろつく, turnTimer が切れたら向きを引き直す
void EntityF41A_UpdateWander(EntityF41A* p) {
  if (p->data.angle != p->targetAngle) {
    if (((p->targetAngle - p->data.angle + 0x100) & 0xFF) < 0x80) {
      p->data.angle = p->data.angle + 4;
    } else {
      p->data.angle = p->data.angle + 0xFC;
    }
  }
  if (p->turnTimer == 0) {
    u16* table = gRandomTable;
    p->targetAngle = 64 * (_Random(table) & 3);
    p->turnTimer = 120 + (_Random(table) & 0x3F);
  } else {
    p->turnTimer--;
  }
  Hitbox_SetPos(&p->hitbox, &p->data.pos, 0);
  Hitbox_Register(&p->hitbox);
  p->animIdx = 7;
}

// 被弾中, 6フレームだけ明るいパレットにして点滅させる
void EntityF41A_UpdateHit(EntityF41A* p) {
  if (p->stateTimer <= 5) {
    Video_SetAuxSpritePltt(&p->gfx, 306);
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
    p->data.delta.x += POLAR_X(p->pushSpeed, p->data.angle);
    p->data.delta.z += POLAR_Z(p->pushSpeed, p->data.angle);
    p->pushSpeed = (p->pushSpeed * 3) >> 2;
  } else {
    p->data.angle += 0x80;
    p->targetAngle = p->data.angle;
    CLEAR_FLAGS((&p->detectNode)->flags, 1);
    EntityF41A_SetState(p, 0);
  }
}

// 向きを4方向に丸めてアニメの variant と左右反転を決め, アニメを1コマ進める
void EntityF41A_UpdateAnim(EntityF41A* p) {
  s32 dir = ((((p->data.angle + 0x20) & 0xFF) >> 6) + 1) & 3;
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
  Mover_ApplyMove(&p->data);
  return 0;
}

s32 EntityF41A_Destroy(EntityF41A* p) {
  AuxSprite_Remove(&p->sprite);
  Mover_Unlink(&p->data);
  Entity5941_Unregister(&p->detectNode);
  return 0;
}

// '.p' で位置をもらい、その足元の高さに吸着させてから data を登録する
void EntityF41A_InitData(EntityF41A* p) {
  Vec3 pos;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  pos.y = TileHeightAt(&pos);
  Mover_Init(&p->data, p->id, &pos, 0, 7, p);
}

// 足元のタイル情報を取って data に結びつける
void EntityF41A_InitTile(EntityF41A* p) {
  Map_InitMoverTile(&p->tile, &p->data.pos);
  Mover_SetCollision(&p->data, &p->tile, 30, 30);
}

// AuxSprite を用意して data に結びつけ、アニメファイルを読む
void EntityF41A_InitSprite(EntityF41A* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOKU);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  Mover_SetAuxSprite(&p->data, &p->sprite);
  Video_SetAuxSpritePltt(&p->gfx, 307);
  p->sprite.pos = p->data.pos;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_BOKU);
  p->animIdx = 7;
  EntityF41A_UpdateAnim(p);
}

void EntityF41A_InitHitbox(EntityF41A* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size, offset;

  VEC3_SET(size, Q8(0.25), Q8(0.391), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.391), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetAttack(hitbox, 10, 0x1E, 0, 0, 0x10);
  Hitbox_SetHandler(hitbox, NULL, p);
}

s32 EntityF41A_Init(EntityF41A* p, u32 id, u32 param_3) {
  p->id = id;
  EntityF41A_InitData(p);
  EntityF41A_InitTile(p);
  EntityF41A_InitSprite(p);
  EntityF41A_InitHitbox(p);
  Entity5941_Register(&p->detectNode, &p->data, EntityF41A_OnMessage);
  EntityF41A_SetState(p, 0);
  return 0;
}

// 0xF41A
EntityF41A* EntityF41A_Create(u32 param_1, u32 param_2) {
  EntityF41A* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityF41A));

  if (p != NULL) {
    SetEntityRoutine(p, EntityF41A_Update, EntityF41A_Destroy);
    if (EntityF41A_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
