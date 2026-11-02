#include "entity.h"
#include "global.h"
#include "particle.h"
#include "vec3.h"

typedef struct {
  Particle ptcl;   // 0x00, PTCL_GROUP_0 のポーズ 52
  u16 flags;       // 0x28, bit0 は ptcl を表示中
  u8 state;        // 0x2A, PTR_ARRAY_085ae4e0 の添字
  u8 idx;          // 0x2B, elems の添字, 空きは 0xFF
  s16 spawned;     // 0x2C, 生成時に 1, 次のフレームで 0 に戻る
  u16 blinkTimer;  // 0x2E, 0 になるたびに ptcl の表示を切り替えて 38 に戻す
} Entity081eeb28Elem;
static_assert(sizeof(Entity081eeb28Elem) == 48);

// 雷が光っている間, バットに変身している間, GOOD_SEE の間だけ点滅して見える目印
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_0
  Entity081eeb28Elem elems[12];  // 0x01C
  u32 activeMask;                // 0x25C, elems の使用中ビット
} Entity081eeb28;
static_assert(sizeof(Entity081eeb28) == 608);

static Entity081eeb28* gEntity081eeb28;  // 0x030001D4

void Entity081eeb28Elem_UpdateState0(Entity081eeb28*, Entity081eeb28Elem*);
void Entity081eeb28Elem_UpdateState1(Entity081eeb28*, Entity081eeb28Elem*);
void Entity081eeb28Elem_UpdateState2(Entity081eeb28*, Entity081eeb28Elem*);

void (*const PTR_ARRAY_085ae4e0[3])(Entity081eeb28*, Entity081eeb28Elem*) = {
    Entity081eeb28Elem_UpdateState0,
    Entity081eeb28Elem_UpdateState1,
    Entity081eeb28Elem_UpdateState2,
};  // 0x085AE4E0

NAKED void Entity081eeb28Elem_UpdateState0(Entity081eeb28* p, Entity081eeb28Elem* elem) { INCFUNC("asm/func/Entity081eeb28Elem_UpdateState0.inc"); }

NAKED Entity081eeb28Elem* Entity081eeb28_AllocElem(Entity081eeb28* p) { INCFUNC("asm/func/Entity081eeb28_AllocElem.inc"); }

NAKED void Entity081eeb28Elem_UpdateState1(Entity081eeb28* p, Entity081eeb28Elem* elem) { INCFUNC("asm/func/Entity081eeb28Elem_UpdateState1.inc"); }

NAKED void Entity081eeb28Elem_UpdateState2(Entity081eeb28* p, Entity081eeb28Elem* elem) { INCFUNC("asm/func/Entity081eeb28Elem_UpdateState2.inc"); }

NAKED Entity081eeb28Elem* Entity081eeb28_Spawn(Vec3* pos) { INCFUNC("asm/func/Entity081eeb28_Spawn.inc"); }

NAKED s32 Entity081eeb28_Update(Entity081eeb28* p) { INCFUNC("asm/func/Entity081eeb28_Update.inc"); }

NAKED s32 Entity081eeb28_Destroy(Entity081eeb28* p) { INCFUNC("asm/func/Entity081eeb28_Destroy.inc"); }

NAKED s32 Entity081eeb28_Init(Entity081eeb28* p) { INCFUNC("asm/func/Entity081eeb28_Init.inc"); }

NAKED Entity081eeb28* Entity081eeb28_Create(void) { INCFUNC("asm/func/Entity081eeb28_Create.inc"); }

NAKED void Entity081eeb28_ClearGlobal(void) { INCFUNC("asm/func/Entity081eeb28_ClearGlobal.inc"); }
