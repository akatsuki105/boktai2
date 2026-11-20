#include "collision_map.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "mover.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

// 不使用?, ナビメッシュに沿って歩き, B ボタンを押すとプレイヤーの位置への経路を引き直す
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u16 id;             // 0x18, mover.id
  Mover mover;        // 0x1C
  AuxSprite sprite;   // 0x60
  AuxSpriteGfx gfx;   // 0x8C, SPR_NODATA_9DA7
  MoverTile tile;     // 0xA8, mover.tile がここを指す
  NavAgent navAgent;  // 0xB8, waypoint へ速さ 10 で向かう
} EntityC814;
static_assert(sizeof(EntityC814) == 220);

void Map_StepNavPath(NavAgent* agent, Vec3* pos);

// 次の通過点へ向かって進み, B ボタンでセーブされたプレイヤーの位置への経路を引き直す
s32 EntityC814_Update(EntityC814* p) {
  s32 dx = p->mover.pos.x - p->navAgent.waypoint.x;
  s32 dz = p->mover.pos.z - p->navAgent.waypoint.z;

  if (dx != 0 || dz != 0) {
    s32 angle = ArcTan2_8(dx, dz);

    p->mover.delta.x = -POLAR_X(10, angle);
    p->mover.delta.z = -POLAR_Z(10, angle);
  }
  Mover_ApplyMove(&p->mover);
  Map_StepNavPath(&p->navAgent, &p->mover.pos);
  if (gInput[0].pressed & B_BUTTON) {
    Vec3 dst;

    dst.x = PLAYER_X, dst.y = 0, dst.z = PLAYER_Z;
    Map_TryFindNavRoute(&p->navAgent, &p->mover.pos, &dst);
  }
  return 0;
}

s32 EntityC814_Destroy(EntityC814* p) {
  AuxSprite_Remove(&p->sprite);
  Mover_Unlink(&p->mover);
  return 0;
}

// '.p' で位置をもらい, その足元の高さに置いて mover を登録する
void EntityC814_InitMover(EntityC814* p) {
  Vec3 pos;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  pos.y = TileHeightAt(&pos);
  Mover_Init(&p->mover, p->id, &pos, 0, MOVER_OBJECT, p);
}

// AuxSprite を用意して mover に結びつける
void EntityC814_InitSprite(EntityC814* p) {
  Video_GetAuxSprite(&p->gfx, SPR_NODATA_9DA7);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  Mover_SetAuxSprite(&p->mover, &p->sprite);
  p->sprite.pos = p->mover.pos;
}

// 足元のタイル情報を取って mover に結びつける
void EntityC814_InitTile(EntityC814* p) {
  Map_InitMoverTile(&p->tile, &p->mover.pos);
  Mover_SetCollision(&p->mover, &p->tile, 30, 30);
}

void EntityC814_InitNavAgent(EntityC814* p) { Map_InitNavAgent(&p->navAgent, &p->mover.pos); }

s32 EntityC814_Init(EntityC814* p, u32 id, u32 _) {
  p->id = id;
  EntityC814_InitMover(p);
  EntityC814_InitSprite(p);
  EntityC814_InitTile(p);
  EntityC814_InitNavAgent(p);
  return 0;
}

// 0xC814
EntityC814* EntityC814_Create(u32 id, u32 _) {
  EntityC814* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityC814));

  if (p != NULL) {
    SetEntityRoutine(p, EntityC814_Update, EntityC814_Destroy);
    if (EntityC814_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
