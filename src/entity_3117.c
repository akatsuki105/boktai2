#include "entity.h"
#include "global.h"

typedef struct {
  u8 unk_0[184];  // まだ未解析
} Entity3117Entry;
static_assert(sizeof(Entity3117Entry) == 184);

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 count;  // 実際の entries の個数
  u8 unk_19;
  u8 unk_1a[2];
  Entity3117Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity3117;

extern Entity3117* gEntity3117;  // 0x03002C48

NAKED s32 FUN_080a4e94(void) { INCFUNC("asm/func/FUN_080a4e94.inc"); }

NAKED void FUN_080a4ee8(void) { INCFUNC("asm/func/FUN_080a4ee8.inc"); }

NAKED void FUN_080a4f54(void) { INCFUNC("asm/func/FUN_080a4f54.inc"); }

NAKED void FUN_080a4f78(void) { INCFUNC("asm/func/FUN_080a4f78.inc"); }

NAKED void FUN_080a4f90(void) { INCFUNC("asm/func/FUN_080a4f90.inc"); }

NAKED void FUN_080a4fac(void) { INCFUNC("asm/func/FUN_080a4fac.inc"); }

NAKED void FUN_080a4fd4(void) { INCFUNC("asm/func/FUN_080a4fd4.inc"); }

NAKED void FUN_080a504c(void) { INCFUNC("asm/func/FUN_080a504c.inc"); }

NAKED void FUN_080a50d8(void) { INCFUNC("asm/func/FUN_080a50d8.inc"); }

NAKED void FUN_080a51d4(unknown* param_1) { INCFUNC("asm/func/FUN_080a51d4.inc"); }

NAKED void FUN_080a5568(void) { INCFUNC("asm/func/FUN_080a5568.inc"); }

NAKED s32 Entity3117_Update(Entity3117* p) { INCFUNC("asm/func/Entity3117_Update.inc"); }

NAKED s32 Entity3117_Destroy(Entity3117* p) { INCFUNC("asm/func/Entity3117_Destroy.inc"); }

NAKED s32 Entity3117_Init(Entity3117* p, u32 param_2, u32 param_3, s32 count) { INCFUNC("asm/func/Entity3117_Init.inc"); }

NAKED Entity3117* Entity3117_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/Entity3117_Create.inc"); }
