#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "mover.h"
#include "sprite_aux.h"

// 不使用?, ナビメッシュに沿って歩き, B ボタンを押すとプレイヤーの位置への経路を引き直す
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u16 id;             // 0x18, mover.id
  Mover mover;        // 0x1C
  AuxSprite sprite;   // 0x60
  AuxSpriteGfx gfx;   // 0x8C, SPRITE_NODATA_9DA7
  MoverTile tile;     // 0xA8, mover.tile がここを指す
  NavAgent navAgent;  // 0xB8, waypoint へ速さ 10 で向かう
} EntityC814;
static_assert(sizeof(EntityC814) == 220);

NAKED s32 EntityC814_Update(EntityC814* p) { INCFUNC("asm/func/EntityC814_Update.inc"); }

NAKED s32 EntityC814_Destroy(EntityC814* p) { INCFUNC("asm/func/EntityC814_Destroy.inc"); }

NAKED void EntityC814_InitMover(EntityC814* p) { INCFUNC("asm/func/EntityC814_InitMover.inc"); }

NAKED void EntityC814_InitSprite(EntityC814* p) { INCFUNC("asm/func/EntityC814_InitSprite.inc"); }

NAKED void EntityC814_InitTile(EntityC814* p) { INCFUNC("asm/func/EntityC814_InitTile.inc"); }

NAKED void EntityC814_InitNavAgent(EntityC814* p) { INCFUNC("asm/func/EntityC814_InitNavAgent.inc"); }

NAKED s32 EntityC814_Init(EntityC814* p, u32 id, u32 param_3) { INCFUNC("asm/func/EntityC814_Init.inc"); }

NAKED EntityC814* EntityC814_Create(u32 id, u32 param_2) { INCFUNC("asm/func/EntityC814_Create.inc"); }
