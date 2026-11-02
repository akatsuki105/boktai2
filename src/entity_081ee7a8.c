#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  AuxSprite sprite;   // 0x00
  AuxSpriteGfx gfx;   // 0x2C, 生成時の spriteID (FUN_081ee4ec と FUN_081ee584 は SPRITE_4384)
  AuxAnimState anim;  // 0x48, 一巡すると状態 2 で片付く
  u8 state;           // 0x58, PTR_ARRAY_085ae4d4 の添字
  u8 unk_59;          // 0x59
  u8 angle;           // 0x5A, 水平に動く向き
  u8 unk_5b;          // 0x5B
  s16 riseSpeed;      // 0x5C, delay が切れてから毎フレーム sprite.pos.y に足す
  s16 speed;          // 0x5E, angle の向きに毎フレーム動く量
  u8 unk_60[4];       // 0x60
  s16 delay;          // 0x64, 0 になるまで上昇しない
  s16 unk_66;         // 0x66, 生成時に 0
  u16 animSpeed;      // 0x68, AuxAnim_SetAnimSpeed の速さ
  u8 unk_6a[2];       // 0x6A
  s8 idx;             // 0x6C, elems の添字, 空きは -1
  u8 riseTime;        // 0x6D, 上昇するたびに 1 減り, 0 になると状態 2 で片付く
  s16 hideTime;       // 0x6E, 0 になるまで隠れたまま何もしない
} Entity081ee7a8Elem;
static_assert(sizeof(Entity081ee7a8Elem) == 112);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxAnimFile* animFile;         // 0x018, 生成時の animFileID (FUN_081ee4ec と FUN_081ee584 は ANIM_F62B)
  Entity081ee7a8Elem elems[48];  // 0x01C
} Entity081ee7a8;
static_assert(sizeof(Entity081ee7a8) == 5404);

static Entity081ee7a8* gEntity081ee7a8;  // 0x030001D0

void Entity081ee7a8Elem_UpdateState0(Entity081ee7a8Elem*);
void Entity081ee7a8Elem_UpdateState1(Entity081ee7a8Elem*);
void Entity081ee7a8Elem_UpdateState2(Entity081ee7a8Elem*);

void (*const PTR_ARRAY_085ae4d4[3])(Entity081ee7a8Elem*) = {
    Entity081ee7a8Elem_UpdateState0,
    Entity081ee7a8Elem_UpdateState1,
    Entity081ee7a8Elem_UpdateState2,
};  // 0x085AE4D4

NAKED void Entity081ee7a8Elem_UpdateState0(Entity081ee7a8Elem* elem) { INCFUNC("asm/func/Entity081ee7a8Elem_UpdateState0.inc"); }

NAKED Entity081ee7a8Elem* Entity081ee7a8_AllocElem(Entity081ee7a8* p) { INCFUNC("asm/func/Entity081ee7a8_AllocElem.inc"); }

NAKED void Entity081ee7a8Elem_UpdateState1(Entity081ee7a8Elem* elem) { INCFUNC("asm/func/Entity081ee7a8Elem_UpdateState1.inc"); }

NAKED void Entity081ee7a8Elem_UpdateState2(Entity081ee7a8Elem* elem) { INCFUNC("asm/func/Entity081ee7a8Elem_UpdateState2.inc"); }

NAKED void FUN_081ee4ec(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 plttOffset, SpriteFlags flags, s32 hideTime) { INCFUNC("asm/func/FUN_081ee4ec.inc"); }

NAKED void FUN_081ee53c(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 _, SpriteFlags flags, s32 hideTime, SpriteID32 spriteID, u32 animFileID, u32 animIdx, u32 variant, s32 plttID) {
  INCFUNC("asm/func/FUN_081ee53c.inc");
}

NAKED void FUN_081ee584(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 plttOffset, SpriteFlags flags) { INCFUNC("asm/func/FUN_081ee584.inc"); }

NAKED void Entity081ee7a8_Spawn(
    Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 _, SpriteFlags flags, s32 hideTime, SpriteID32 spriteID, u32 animFileID, u32 animIdx, u32 variant, s32 plttID) {
  INCFUNC("asm/func/Entity081ee7a8_Spawn.inc");
}

NAKED s32 Entity081ee7a8_Update(Entity081ee7a8* p) { INCFUNC("asm/func/Entity081ee7a8_Update.inc"); }

NAKED s32 Entity081ee7a8_Destroy(Entity081ee7a8* p) { INCFUNC("asm/func/Entity081ee7a8_Destroy.inc"); }

NAKED s32 Entity081ee7a8_Init(Entity081ee7a8* p) { INCFUNC("asm/func/Entity081ee7a8_Init.inc"); }

NAKED Entity081ee7a8* Entity081ee7a8_Create(void) { INCFUNC("asm/func/Entity081ee7a8_Create.inc"); }

NAKED void Entity081ee7a8_ClearGlobal(void) { INCFUNC("asm/func/Entity081ee7a8_ClearGlobal.inc"); }
