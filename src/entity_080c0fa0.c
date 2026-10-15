#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

struct Entity080c0fa0;

typedef void(Entity080c0fa0Func)(struct Entity080c0fa0* p);

// _Create が Entity080c0fa0_Create と FUN_080c1108 の2つあるが、後者は使われていない
typedef struct Entity080c0fa0 {
  Entity e;                            // 0x00, ENTITY_UNK_10
  AuxSprite sprite;                    // 0x18, delay が 0 でない間は隠す
  AuxSpriteGfx gfx;                    // 0x44, SPRITE_EFF_210E, パレットは Init の第3引数
  Vec3 pos;                            // 0x60, Init の第2引数のコピー
  u8 unk_68[2];                        // 0x68, まだ未解析
  u16 metaspriteIdx;                   // 0x6A, Init の第4引数
  u16 dir;                             // 0x6C, +1 して & 7 した値で gSineTable を引き速度を作る
  s16 vx;                              // 0x6E, -(速さ * sin(dir+0x40)) >> 12
  s16 vz;                              // 0x70, -(速さ * sin(dir)) >> 12
  s16 delay;                           // 0x72, 0 でなければ隠して待つ方から始める
  u16 unk_74;                          // 0x74, Init の第8引数
  u16 stateTimer;                      // 0x76, updateCallback を差し替えるたびに 0 に戻る
  Entity080c0fa0Func* updateCallback;  // 0x78
} Entity080c0fa0;
static_assert(sizeof(Entity080c0fa0) == 124);

NAKED void Entity080c0fa0_SetUpdateCallback(Entity080c0fa0* p, Entity080c0fa0Func* fn) { INCFUNC("asm/func/Entity080c0fa0_SetUpdateCallback.inc"); }

NAKED void Entity080c0fa0_AdvanceAnim(Entity080c0fa0* p) { INCFUNC("asm/func/Entity080c0fa0_AdvanceAnim.inc"); }

NAKED void Entity080c0fa0_UpdateActive(Entity080c0fa0* p) { INCFUNC("asm/func/Entity080c0fa0_UpdateActive.inc"); }

NAKED void Entity080c0fa0_UpdateDelay(Entity080c0fa0* p) { INCFUNC("asm/func/Entity080c0fa0_UpdateDelay.inc"); }

NAKED s32 Entity080c0fa0_Update(Entity080c0fa0* p) { INCFUNC("asm/func/Entity080c0fa0_Update.inc"); }

NAKED s32 Entity080c0fa0_Destroy(Entity080c0fa0* p) { INCFUNC("asm/func/Entity080c0fa0_Destroy.inc"); }

NAKED s32 Entity080c0fa0_Init(Entity080c0fa0* p, Vec3* pos, SpriteID32 pltt, u16 metaspriteIdx, u16 dir, s32 speed, s16 delay, u16 param_8) { INCFUNC("asm/func/Entity080c0fa0_Init.inc"); }

NAKED Entity080c0fa0* Entity080c0fa0_Create(Vec3* pos, SpriteID32 pltt, u16 metaspriteIdx, u16 dir, s32 speed, s16 delay, u16 param_7) { INCFUNC("asm/func/Entity080c0fa0_Create.inc"); }

NAKED s32 FUN_080c1008(Entity080c0fa0* p) { INCFUNC("asm/func/FUN_080c1008.inc"); }

NAKED Entity080c0fa0* FUN_080c1108(u32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_080c1108.inc"); }
