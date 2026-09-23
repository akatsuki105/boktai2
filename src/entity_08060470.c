#include "entity.h"
#include "global.h"
#include "particle.h"

// Entity08060470 が持つ粒子1個。生成元 (Entity08060470_Spawn) が角度と速度から vel を作り、
// 以降は Entity08060470_UpdateElem が毎フレーム ptcl.pos に vel を足すだけ
typedef struct Entity08060470Elem {
  u8 state;       // 0x00, PTR_ARRAY_085abaac の添字 (0 = 何もしない, 1 = 飛行中), 根拠: Entity08060470_Update
  u8 unk_1;       // 0x01, 生成時に1、最初の更新で0にされる。読み手は未発見, 根拠: Entity08060470_UpdateElem
  u16 timer;      // 0x02, 毎フレーム +1, 根拠: Entity08060470_Update
  u16 lifetime;   // 0x04, timer がこれ以上になると消える。生成時は配置半径としても使われる, 根拠: Entity08060470_UpdateElem / Entity08060470_Spawn
  u8 unk_6[2];    // 0x06, 読み書きとも未発見
  Particle ptcl;  // 0x08, 根拠: FUN_0822da70 / Particle_Remove に渡される
  Vec3 vel;       // 0x30, 毎フレーム ptcl.pos に加算される, 根拠: Entity08060470_UpdateElem
} Entity08060470Elem;
static_assert(sizeof(Entity08060470Elem) == 56);

// 粒子を16個まで抱えるエンティティ。空きスロットは activeMask のビットで管理する
typedef struct Entity08060470 {
  Entity e;                      // 0x00, ENTITY_UNK_10
  u32 unk_18;                    // 0x18, 読み手も書き手も未発見
  u32 activeMask;                // 0x1C, 1 << i で elems[i] が使用中, 根拠: Entity08060470_Init が0クリア、Entity08060470_ReleaseElem がビットを落とす
  ParticleGroup* group;          // 0x20, GetParticleGroup(PTCL_GROUP_2), 根拠: Entity08060470_Init
  Entity08060470Elem elems[16];  // 0x24, 根拠: _Init / _Update / _Destroy が stride 0x38 で16回まわす
} Entity08060470;
static_assert(sizeof(Entity08060470) == 932);

NAKED void Entity08060470_InitElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) { INCFUNC("asm/func/Entity08060470_InitElem.inc"); }

NAKED void Entity08060470_ReleaseElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) { INCFUNC("asm/func/Entity08060470_ReleaseElem.inc"); }

NAKED void FUN_08060358(Entity08060470* p, Entity08060470Elem* elem, s32 idx) { INCFUNC("asm/func/FUN_08060358.inc"); }

NAKED void Entity08060470_UpdateElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) { INCFUNC("asm/func/Entity08060470_UpdateElem.inc"); }

void (*const PTR_ARRAY_085abaac[2])(Entity08060470*, Entity08060470Elem*, s32) = {
    FUN_08060358,
    Entity08060470_UpdateElem,
};  // 0x085ABAAC

NAKED s32 Entity08060470_Update(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Update.inc"); }

NAKED s32 Entity08060470_Destroy(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Destroy.inc"); }

NAKED s32 Entity08060470_Init(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Init.inc"); }

NAKED Entity08060470* Entity08060470_Create(void) { INCFUNC("asm/func/Entity08060470_Create.inc"); }

NAKED Entity08060470Elem* Entity08060470_FindFreeElem(Entity08060470* p, u32* outIdx) { INCFUNC("asm/func/Entity08060470_FindFreeElem.inc"); }

NAKED s32 Entity08060470_Spawn(u8 angle, s32 speed, u16 radius, Vec3* pos) { INCFUNC("asm/func/Entity08060470_Spawn.inc"); }
