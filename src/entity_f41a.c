#include "animation.h"
#include "collision_map.h"
#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sprite_aux.h"
#include "struct.h"
#include "vm.h"

// SPRITE_BOKU_0 の姿でうろつく生き物。叩かれると点滅してノックバックし、また歩き出す
typedef struct EntityF41A {
  Entity e;                            // 0x000, ENTITY_UNK_8
  u16 id;                              // 0x018, Init の第2引数。FUN_0823b400 に渡して data に入れる
  u16 unk_1a;                          // 0x01A
  Entity2UnkData data;                 // 0x01C, 位置と向きはここが持つ。data.unk_5 が向き、data.delta が移動量
  AuxSprite sprite;                    // 0x060
  AuxSpriteGfx gfx;                    // 0x08C, Video_GetAuxSprite(SPRITE_BOKU_0)
  u8 tile[16];                         // 0x0A8, FUN_0823280c が足元のタイル情報を埋める。data.unk_18 がここを指す
  HitboxData hitbox;                   // 0x0B8
  AuxAnimState anim;                   // 0x108
  AuxAnimFile* animFile;               // 0x118, GetFile(DIR_ANIMATION, 0x1DF8)
  Entity5941Node detectNode;           // 0x11C, Entity5941_Register / FUN_0807f598
  u16 targetAngle;                     // 0x12C, 乱数で決める向き。data.unk_5 がここへ4ずつ近づく
  u16 turnTimer;                       // 0x12E, 0 になると targetAngle を引き直す (0x78..0xB7 フレーム)
  u16 animIdx;                         // 0x130, FUN_08236fac に渡すアニメ番号
  u16 pushSpeed;                       // 0x132, ノックバックの速さ。毎フレーム 3/4 になる
  u16 state;                           // 0x134, 0 = うろつく, 1 = 被弾, 2 = ノックバック
  u16 stateTimer;                      // 0x136, state を変えると 0。被弾中のパレット切り替えに使う
  void (*update)(struct EntityF41A*);  // 0x138, state に対応する更新関数
} EntityF41A;
static_assert(sizeof(EntityF41A) == 316);

s32 FUN_0823b400(Entity2UnkData* p, u16 id, Vec3* pos, u32 unk_5, u32 unk_4, void* owner);

void FUN_0823280c(unknown* p, Vec3* pos);
void FUN_0823b4b8(Entity2UnkData* p);
bool32 FUN_0823b46c(Entity2UnkData* p, AuxSprite* unk_28);
s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
s32 FUN_0823b284(Entity2UnkData* p);
bool32 FUN_0823b43c(Entity2UnkData* p, void* unk_18, u16 unk_1c, u16 unk_1e);
void FUN_0807f598(void* p);

void EntityF41A_UpdateWander(EntityF41A* p);
void EntityF41A_UpdateHit(EntityF41A* p);
void EntityF41A_UpdateKnockback(EntityF41A* p);

// state を切り替えて、対応する更新関数を差し込む
void EntityF41A_SetState(EntityF41A* p, s32 state) {
  void (*const handlers[3])(EntityF41A*) = {
      EntityF41A_UpdateWander,
      EntityF41A_UpdateHit,
      EntityF41A_UpdateKnockback,
  };

  p->state = state;
  p->stateTimer = 0;
  p->update = handlers[p->state];
}

// Entity5941 から届く通知。0 = 攻撃が当たった, 1 = 吹き飛ばし開始
NON_MATCH bool32 EntityF41A_OnMessage(Entity2UnkData* data, s32 msg, s32 value) {
#ifdef NONMATCHING_C
  EntityF41A* p = data->p_38;

  if (msg == 0) {
    if (p->state != 2) {
      if (value > 0) {
        Vec3 v;

        v.x = 0, v.y = 0, v.z = 0;
        FUN_0805fe7c(&p->hitbox, value, 0, &p->data.pos, &v, 1);
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

// targetAngle へ向きを4ずつ寄せながらうろつく。turnTimer が切れたら向きを引き直す
NON_MATCH void EntityF41A_UpdateWander(EntityF41A* p) {
#ifdef NONMATCHING_C
  if (p->data.unk_5 != p->targetAngle) {
    if (((p->targetAngle - p->data.unk_5 + 0x100) & 0xFF) < 0x80) {
      p->data.unk_5 = p->data.unk_5 + 4;
    } else {
      p->data.unk_5 = p->data.unk_5 + 0xFC;
    }
  }
  if (p->turnTimer == 0) {
    u16* tbl = gRandomTable;
    u32 idx = (gRandTableIdx + 1) & 0x3FF;

    p->targetAngle = (tbl[idx] & 3) << 6;
    gRandTableIdx = (idx + 1) & 0x3FF;
    p->turnTimer = (tbl[gRandTableIdx] & 0x3F) + 0x78;
  } else {
    p->turnTimer--;
  }
  FUN_082364c4(&p->hitbox, &p->data.pos, 0);
  FUN_08236400(&p->hitbox);
  p->animIdx = 7;
#else
  INCFUNC("asm/func/EntityF41A_UpdateWander.inc");
#endif
}

// 被弾中。6フレームだけ明るいパレットにして点滅させる
void EntityF41A_UpdateHit(EntityF41A* p) {
  if (p->stateTimer <= 5) {
    Video_SetAuxSpritePltt(&p->gfx, 0x132);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, 0x133);
  }
  p->animIdx = 2;
  p->stateTimer++;
}

// 吹き飛ばされている間。speed を 3/4 ずつ減らし、0 になったら向きを反転してうろつきに戻る
NON_MATCH void EntityF41A_UpdateKnockback(EntityF41A* p) {
#ifdef NONMATCHING_C
  p->animIdx = 2;
  if (p->pushSpeed != 0) {
    p->data.delta.x += p->pushSpeed * gSineTable[(p->data.unk_5 + 0x40) & 0xFF] / 4096;
    p->data.delta.z += p->pushSpeed * gSineTable[p->data.unk_5] / 4096;
    p->pushSpeed = (p->pushSpeed * 3) >> 2;
  } else {
    p->data.unk_5 += 0x80;
    p->targetAngle = p->data.unk_5;
    p->detectNode.flags &= ~1;
    EntityF41A_SetState(p, 0);
  }
#else
  INCFUNC("asm/func/EntityF41A_UpdateKnockback.inc");
#endif
}

NAKED void EntityF41A_UpdateAnim(EntityF41A* p) { INCFUNC("asm/func/EntityF41A_UpdateAnim.inc"); }

s32 EntityF41A_Update(EntityF41A* p) {
  p->update(p);
  EntityF41A_UpdateAnim(p);
  FUN_0823b4b8(&p->data);
  return 0;
}

s32 EntityF41A_Destroy(EntityF41A* p) {
  AuxSprite_Remove(&p->sprite);
  FUN_0823b284(&p->data);
  FUN_0807f598(&p->detectNode);
  return 0;
}

// スクリプトの 'p' で位置をもらい、その足元の高さに吸着させてから data を登録する
void EntityF41A_InitData(EntityF41A* p) {
  Vec3 pos;
  Vec3* q;
  s32 bx, bz;
  u32 idx;
  u8* tile;
  s32 ground;
  s32 stairs;

  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue();
    pos.z = Script_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  q = &pos;
  bx = q->x >> 8, bz = q->z >> 8;
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  tile = (u8*)FUN_08234224(idx, 1);
  if (tile != NULL) {
    tile += 4;
  } else {
    tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
  }
  stairs = *tile >> 4;
  ground = (*tile & 0xF) << 8;
  switch (stairs) {
    case 1: {
      ground -= (u8)q->z;
      break;
    }
    case 2: {
      ground -= (u8)q->x;
      break;
    }
  }
  pos.y = ground;
  FUN_0823b400(&p->data, p->id, &pos, 0, 7, p);
}

// 足元のタイル情報を取って data に結びつける
void EntityF41A_InitTile(EntityF41A* p) {
  FUN_0823280c(p->tile, &p->data.pos);
  FUN_0823b43c(&p->data, p->tile, 30, 30);
}

// AuxSprite を用意して data に結びつけ、アニメファイルを読む
void EntityF41A_InitSprite(EntityF41A* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOKU_0);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  FUN_0823b46c(&p->data, &p->sprite);
  Video_SetAuxSpritePltt(&p->gfx, 0x133);
  p->sprite.pos = p->data.pos;
  p->animFile = GetFile(DIR_ANIMATION, 0x1DF8);
  p->animIdx = 7;
  EntityF41A_UpdateAnim(p);
}

void EntityF41A_InitHitbox(EntityF41A* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size, offset;

  size.x = 0x40, size.y = 100, size.z = 0x40;
  offset.x = 0, offset.y = 100, offset.z = 0;
  FUN_0823646c(hitbox, 0, HBFLAG_UNK_13 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  FUN_082364f8(hitbox, 10, 0x1E, 0, 0, 0x10);
  FUN_0823651c(hitbox, NULL, p);
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
