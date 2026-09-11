#include "boss.h"
#include "entity.h"
#include "global.h"

// 遺跡のリンゴ(他のイベントのリンゴやダーインの時も含むかはまだ不明)

typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[4188 - 0x18];
} EntityBA4B;
static_assert(sizeof(EntityBA4B) == 4188);

INCASM("asm/entity_ba4b.inc");

NAKED s32 EntityBA4B_Update(EntityBA4B* p) { INCFUNC("asm/func/EntityBA4B_Update.inc"); }

NAKED s32 EntityBA4B_Destroy(EntityBA4B* p) { INCFUNC("asm/func/EntityBA4B_Destroy.inc"); }

NAKED s32 EntityBA4B_Init(EntityBA4B* p, u32 id) { INCFUNC("asm/func/EntityBA4B_Init.inc"); }

NAKED EntityBA4B* EntityBA4B_Create(u32 id) { INCFUNC("asm/func/EntityBA4B_Create.inc"); }
