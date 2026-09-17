#include "entity.h"
#include "global.h"
#include "particle.h"

typedef struct ParticleShadowManager {
  Entity e;               // ENTITY_UNK_9
  ParticleGroup* group0;  // 0x18, PTCL_GROUP_0
  ParticleShadow* head;   // 0x1C, 影のリストの先頭, 対象座標から床の高さを求めて影パーティクルを配置し、床がなければ非表示にする
} ParticleShadowManager;
static_assert(sizeof(ParticleShadowManager) == 32);

extern ParticleShadowManager* gParticleShadowManager;  // 0x03000050

void FUN_08013634(void) { gParticleShadowManager = NULL; }

// リネーム案: ShadowList_Add
NAKED s32 FUN_08013640(ParticleShadowManager* p, ParticleShadow* shadow) { INCFUNC("asm/func/FUN_08013640.inc"); }

// リネーム案: ShadowList_Remove
NAKED s32 FUN_08013668(ParticleShadowManager* p, ParticleShadow* shadow) { INCFUNC("asm/func/FUN_08013668.inc"); }

// リネーム案: Shadow_Show
NAKED void FUN_08013698(ParticleShadow* shadow) { INCFUNC("asm/func/FUN_08013698.inc"); }

// リネーム案: Shadow_Hide
NAKED void FUN_080136b4(ParticleShadow* shadow) { INCFUNC("asm/func/FUN_080136b4.inc"); }

// リネーム案: Shadow_UpdateNone
NAKED void FUN_080136c8(ParticleShadow* shadow) { INCFUNC("asm/func/FUN_080136c8.inc"); }

// リネーム案: Shadow_FollowGround
NAKED void FUN_080136cc(ParticleShadow* shadow) { INCFUNC("asm/func/FUN_080136cc.inc"); }

NAKED s32 Entity0801381c_Update(ParticleShadowManager* p) { INCFUNC("asm/func/Entity0801381c_Update.inc"); }

NAKED s32 Entity0801381c_Destroy(ParticleShadowManager* p) { INCFUNC("asm/func/Entity0801381c_Destroy.inc"); }

NAKED s32 Entity0801381c_Init(ParticleShadowManager* p, void* data) { INCFUNC("asm/func/Entity0801381c_Init.inc"); }

NAKED ParticleShadowManager* Entity0801381c_Create(void* data, u32 _) { INCFUNC("asm/func/Entity0801381c_Create.inc"); }

// リネーム案: Shadow_Init
NAKED s32 FUN_0801385c(ParticleShadow* shadow, Vec3* ownerPos, u8 kind) { INCFUNC("asm/func/FUN_0801385c.inc"); }

// リネーム案: Shadow_Remove
NAKED s32 FUN_080138fc(ParticleShadow* shadow) { INCFUNC("asm/func/FUN_080138fc.inc"); }
