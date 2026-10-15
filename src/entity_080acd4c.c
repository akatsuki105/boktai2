#include "entity.h"
#include "global.h"
#include "particle.h"

// 粒を8枠で使い回して順番に出すシングルトン
typedef struct {
  Particle ptcl;         // 0x00
  ParticleGroup* group;  // 0x28, PTCL_GROUP_0
  bool8 active;          // 0x2C, 0 の枠は飛ばす, timer が 0x10 に届くと 0 に戻す
  u8 unk_2d;             // 0x2D, 初期化で 0 を書くだけ
  u16 timer;             // 0x2E, 毎フレーム +1, >> 1 して 0xC を足したコマ番号を使う
} Entity080acd4cElem;
static_assert(sizeof(Entity080acd4cElem) == 48);

typedef struct Entity080acd4c {
  Entity e;                     // 0x000, ENTITY_UNK_10
  Entity080acd4cElem elems[8];  // 0x018
  u16 nextSlot;                 // 0x198, 次に使う枠の添字
  u8 unk_19a[2];                // 0x19A, 詰め物
} Entity080acd4c;
static_assert(sizeof(Entity080acd4c) == 412);

extern Entity080acd4c* gEntity080acd4c;  // 0x03002C54

NAKED void FUN_080acc14(void) { INCFUNC("asm/func/FUN_080acc14.inc"); }

NAKED void Entity080acd4cElem_Update(Entity080acd4cElem* elem) { INCFUNC("asm/func/Entity080acd4cElem_Update.inc"); }

NAKED s32 Entity080acd4c_Update(Entity080acd4c* p) { INCFUNC("asm/func/Entity080acd4c_Update.inc"); }

NAKED s32 Entity080acd4c_Destroy(Entity080acd4c* p) { INCFUNC("asm/func/Entity080acd4c_Destroy.inc"); }

NAKED void Entity080acd4c_InitElems(Entity080acd4c* p) { INCFUNC("asm/func/Entity080acd4c_InitElems.inc"); }

NAKED s32 Entity080acd4c_Init(Entity080acd4c* p) { INCFUNC("asm/func/Entity080acd4c_Init.inc"); }

NAKED Entity080acd4c* Entity080acd4c_Create(void) { INCFUNC("asm/func/Entity080acd4c_Create.inc"); }

NAKED void Entity080acd4c_Spawn(Vec3* pos) { INCFUNC("asm/func/Entity080acd4c_Spawn.inc"); }
