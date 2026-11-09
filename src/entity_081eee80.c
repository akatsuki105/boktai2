#include "entity.h"
#include "global.h"
#include "sprite.h"

// 爆発の煙の粒1つ, 角度の方向へ広がりながら昇り, 点滅しつつアニメを進めて消える
typedef struct {
  AuxSprite sprite;   // 0x00, poseIdx は timer >> animShift
  Vec3 vel;           // 0x2C, x / z は毎フレーム半分になり, y はそのまま
  u8 angle;           // 0x34, 広がる向き
  s8 delay;           // 0x35, 動き出すまでのフレーム数, 0 になると -1 にして動き出す
  u16 blinkInterval;  // 0x36, timer がこれで割り切れるフレームだけ描画する, 1〜8
  u16 timer;          // 0x38
  u8 state;           // 0x3C, sEntity081eee80ElemStates の添字, 0: 空き, 1: 飛ぶ, 2: 消える
  u8 animShift;       // 0x3D, timer >> animShift が 6 になると消える
  u8 idx;             // 0x3E, elems の添字
  bool8 active;       // 0x3F
} Entity081eee80Elem;
static_assert(sizeof(Entity081eee80Elem) == 64);

// 爆発の煙の粒を最大 128 個まで管理する
typedef struct {
  Entity e;                       // 0x0000, ENTITY_UNK_10
  AuxSpriteGfx gfx;               // 0x0018, SPRITE_EXPLOSION
  u8 unk_34[4];                   // 0x0034
  Entity081eee80Elem elems[128];  // 0x0038
} Entity081eee80;
static_assert(sizeof(Entity081eee80) == 8248);

static Entity081eee80* gEntity081eee80;  // 0x030001D8

void Entity081eee80_ElemStateNone(Entity081eee80* p, Entity081eee80Elem* elem);
void Entity081eee80_ElemStateFly(Entity081eee80* p, Entity081eee80Elem* elem);
void Entity081eee80_ElemStateEnd(Entity081eee80* p, Entity081eee80Elem* elem);

void (*const sEntity081eee80ElemStates[3])(Entity081eee80*, Entity081eee80Elem*) = {
    Entity081eee80_ElemStateNone,
    Entity081eee80_ElemStateFly,
    Entity081eee80_ElemStateEnd,
};  // 0x085AE4EC

NAKED void Entity081eee80_ElemStateNone(Entity081eee80* p, Entity081eee80Elem* elem) { INCFUNC("asm/func/Entity081eee80_ElemStateNone.inc"); }

NAKED void Entity081eee80_ElemStateFly(Entity081eee80* p, Entity081eee80Elem* elem) { INCFUNC("asm/func/Entity081eee80_ElemStateFly.inc"); }

NAKED void Entity081eee80_ElemStateEnd(Entity081eee80* p, Entity081eee80Elem* elem) { INCFUNC("asm/func/Entity081eee80_ElemStateEnd.inc"); }

NAKED Entity081eee80Elem* Entity081eee80_FindFreeElem(Entity081eee80* p) { INCFUNC("asm/func/Entity081eee80_FindFreeElem.inc"); }

NAKED s32 Entity081eee80_Spawn(Vec3* pos, s32 priority, s32 delay, s32 angle, s32 speed, s32 animShift, s32 plttOffset) { INCFUNC("asm/func/Entity081eee80_Spawn.inc"); }

NAKED s32 Entity081eee80_Update(Entity081eee80* p) { INCFUNC("asm/func/Entity081eee80_Update.inc"); }

NAKED s32 Entity081eee80_Destroy(Entity081eee80* p) { INCFUNC("asm/func/Entity081eee80_Destroy.inc"); }

NAKED s32 Entity081eee80_Init(Entity081eee80* p) { INCFUNC("asm/func/Entity081eee80_Init.inc"); }

NAKED Entity081eee80* Entity081eee80_Create(void) { INCFUNC("asm/func/Entity081eee80_Create.inc"); }

NAKED void Entity081eee80_ClearGlobal(void) { INCFUNC("asm/func/Entity081eee80_ClearGlobal.inc"); }
