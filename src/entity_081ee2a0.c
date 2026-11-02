#include "entity.h"
#include "global.h"
#include "particle.h"
#include "vec3.h"

typedef struct {
  Particle ptcl;  // 0x00
  Vec3 vel;       // 0x28, vel.y は毎フレーム 1 ずつ減り, 床で跳ね返るたびに縮む
  u16 flags;      // 0x30, bit0 が立つと止まる (vel が全部 0 になったとき)
  u8 state;       // 0x32, PTR_ARRAY_085ae4c8 の添字, 1 で跳ね回り, lifetime が切れると 2 で片付く
  u8 idx;         // 0x33, elems の添字, 空きは 0xFF
  bool8 spawned;  // 0x34, 生成した次のフレームで ptcl を表示して 0 に戻る
  u8 unk_35;      // 0x35, 生成時に 30
  u8 animTimer;   // 0x36, 3 フレームごとに animFrame を切り替える
  u8 animFrame;   // 0x37, 0..1, basePose に足すポーズ番号
  s16 lifetime;   // 0x38
  u16 tileIdx;    // 0x3A, ptcl.pos のタイル番号
  u8 basePose;    // 0x3C, kind * 2
} Entity081ee2a0Elem;
static_assert(sizeof(Entity081ee2a0Elem) == 64);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_2
  Entity081ee2a0Elem elems[26];  // 0x01C
  u32 activeMask;                // 0x69C, elems の使用中ビット
} Entity081ee2a0;
static_assert(sizeof(Entity081ee2a0) == 1696);

static Entity081ee2a0* gEntity081ee2a0;  // 0x030001CC

void Entity081ee2a0Elem_UpdateState0(Entity081ee2a0*, Entity081ee2a0Elem*);
void Entity081ee2a0Elem_UpdateState1(Entity081ee2a0*, Entity081ee2a0Elem*);
void Entity081ee2a0Elem_UpdateState2(Entity081ee2a0*, Entity081ee2a0Elem*);

void (*const PTR_ARRAY_085ae4c8[3])(Entity081ee2a0*, Entity081ee2a0Elem*) = {
    Entity081ee2a0Elem_UpdateState0,
    Entity081ee2a0Elem_UpdateState1,
    Entity081ee2a0Elem_UpdateState2,
};  // 0x085AE4C8

NAKED void Entity081ee2a0Elem_UpdateState0(Entity081ee2a0* p, Entity081ee2a0Elem* elem) { INCFUNC("asm/func/Entity081ee2a0Elem_UpdateState0.inc"); }

NAKED Entity081ee2a0Elem* Entity081ee2a0_AllocElem(Entity081ee2a0* p) { INCFUNC("asm/func/Entity081ee2a0_AllocElem.inc"); }

NAKED void Entity081ee2a0Elem_UpdateAnim(Entity081ee2a0* p, Entity081ee2a0Elem* elem) { INCFUNC("asm/func/Entity081ee2a0Elem_UpdateAnim.inc"); }

NAKED void Entity081ee2a0Elem_UpdateState1(Entity081ee2a0* p, Entity081ee2a0Elem* elem) { INCFUNC("asm/func/Entity081ee2a0Elem_UpdateState1.inc"); }

NAKED void Entity081ee2a0Elem_UpdateState2(Entity081ee2a0* p, Entity081ee2a0Elem* elem) { INCFUNC("asm/func/Entity081ee2a0Elem_UpdateState2.inc"); }

NAKED Entity081ee2a0Elem* FUN_081ee07c(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind) { INCFUNC("asm/func/FUN_081ee07c.inc"); }

NAKED Entity081ee2a0Elem* FUN_081ee090(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) { INCFUNC("asm/func/FUN_081ee090.inc"); }

NAKED Entity081ee2a0Elem* Entity081ee2a0_Spawn(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority) { INCFUNC("asm/func/Entity081ee2a0_Spawn.inc"); }

NAKED s32 Entity081ee2a0_Update(Entity081ee2a0* p) { INCFUNC("asm/func/Entity081ee2a0_Update.inc"); }

NAKED s32 Entity081ee2a0_Destroy(Entity081ee2a0* p) { INCFUNC("asm/func/Entity081ee2a0_Destroy.inc"); }

NAKED s32 Entity081ee2a0_Init(Entity081ee2a0* p) { INCFUNC("asm/func/Entity081ee2a0_Init.inc"); }

NAKED Entity081ee2a0* Entity081ee2a0_Create(void) { INCFUNC("asm/func/Entity081ee2a0_Create.inc"); }

NAKED void Entity081ee2a0_ClearGlobal(void) { INCFUNC("asm/func/Entity081ee2a0_ClearGlobal.inc"); }
