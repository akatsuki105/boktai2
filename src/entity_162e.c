#include "entity.h"
#include "global.h"

// interval フレームごとに gStat->unk_2b8 を1つ減らし、0 になったらプレイヤーを action 0x1F にして自分を消す
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_8
  u16 timer;     // 0x18, _Update が毎フレーム +1 し interval に達したら 0 に戻す
  u16 interval;  // 0x1A, '.s' があればその値, なければ 30
} Entity162E;
static_assert(sizeof(Entity162E) == 28);

NAKED s32 Entity162E_Update(Entity162E* p) { INCFUNC("asm/func/Entity162E_Update.inc"); }

s32 Entity162E_Destroy(Entity162E* p) { return 0; }

NAKED s32 Entity162E_Init(Entity162E* p) { INCFUNC("asm/func/Entity162E_Init.inc"); }

NAKED Entity162E* Entity162E_Create(void) { INCFUNC("asm/func/Entity162E_Create.inc"); }
