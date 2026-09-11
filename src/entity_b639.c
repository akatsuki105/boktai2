#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;        // 0x0, ENTITY_UNK_4
  u32 unk_18[16];  // 0x18, 根拠: FUN_08241574
} EntityB639;
static_assert(sizeof(EntityB639) == 88);

IWRAM_DATA EntityB639* gEntityB639 = NULL;  // 0x03001704
COMMON_DATA u32 u32_03004860 = 0;           // 0x03004860

NAKED s32 FUN_08241574(Vec3* pos) { INCFUNC("asm/func/FUN_08241574.inc"); }

s32 EntityB639_Update(EntityB639* p) { return 0; }

s32 EntityB639_Destroy(EntityB639* p) {
  gEntityB639 = NULL;
  u32_03004860 = 0;
  return 0;
}

NAKED s32 EntityB639_Init(EntityB639* p, u32 unused1, void* unused2) { INCFUNC("asm/func/EntityB639_Init.inc"); }

NAKED EntityB639* EntityB639_Create(u32 unused1, void* unused2) { INCFUNC("asm/func/EntityB639_Create.inc"); }
