#include "entity.h"
#include "global.h"
#include "particle.h"

// 他に影を管理するEntityがないなら、ファイル名を shadow.c にして、 Entity0801381c は ShadowManager にする

typedef struct Entity0801381c {
  Entity e;               // ENTITY_UNK_9
  ParticleGroup* group0;  // 0x18, PTCL_GROUP_0
  q_Shadow* head;         // 0x1C, 影のリストの先頭, 対象座標から床の高さを求めて影パーティクルを配置し、床がなければ非表示にする
} Entity0801381c;
static_assert(sizeof(Entity0801381c) == 32);

extern Entity0801381c* gEntity0801381c;  // 0x03000050

void FUN_08013634(void) { gEntity0801381c = NULL; }

// リネーム案: ShadowList_Add
NAKED s32 FUN_08013640(Entity0801381c* p, q_Shadow* shadow) { INCFUNC("asm/func/FUN_08013640.inc"); }

// リネーム案: ShadowList_Remove
NAKED s32 FUN_08013668(Entity0801381c* p, q_Shadow* shadow) { INCFUNC("asm/func/FUN_08013668.inc"); }

// リネーム案: Shadow_Show
NAKED void FUN_08013698(q_Shadow* shadow) { INCFUNC("asm/func/FUN_08013698.inc"); }

// リネーム案: Shadow_Hide
NAKED void FUN_080136b4(q_Shadow* shadow) { INCFUNC("asm/func/FUN_080136b4.inc"); }

// リネーム案: Shadow_UpdateNone
NAKED void FUN_080136c8(q_Shadow* shadow) { INCFUNC("asm/func/FUN_080136c8.inc"); }

// リネーム案: Shadow_FollowGround
NAKED void FUN_080136cc(q_Shadow* shadow) { INCFUNC("asm/func/FUN_080136cc.inc"); }

NAKED s32 Entity0801381c_Update(Entity0801381c* p) { INCFUNC("asm/func/Entity0801381c_Update.inc"); }

NAKED s32 Entity0801381c_Destroy(Entity0801381c* p) { INCFUNC("asm/func/Entity0801381c_Destroy.inc"); }

NAKED s32 Entity0801381c_Init(Entity0801381c* p, void* data) { INCFUNC("asm/func/Entity0801381c_Init.inc"); }

NAKED Entity0801381c* Entity0801381c_Create(void* data, u32 _) { INCFUNC("asm/func/Entity0801381c_Create.inc"); }

// リネーム案: Shadow_Init
NAKED s32 FUN_0801385c(q_Shadow* shadow, Vec3* ownerPos, u8 kind) { INCFUNC("asm/func/FUN_0801385c.inc"); }

// リネーム案: Shadow_Remove
NAKED s32 FUN_080138fc(q_Shadow* shadow) { INCFUNC("asm/func/FUN_080138fc.inc"); }
