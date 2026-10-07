#include "entity.h"
#include "global.h"

// ヨルムンガンドに関係 (ヨルムンガンドのサブエンティティ?)
typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[5764 - 0x18];
} Entity082464b8;
static_assert(sizeof(Entity082464b8) == 5764);

const u32 u32_ARRAY_ARRAY_08dbd7d0[6][2] = {
    {0x1,      0x2 },
    {0x2,      0x1 },
    {0x200004, 0x8 },
    {0x400008, 0x4 },
    {0x4010,   0x20},
    {0x8020,   0x10},
};  // 0x08DBD7D0

void FUN_08246090(Entity082464b8*, unknown*, s32);
void FUN_0824617c(Entity082464b8*, unknown*, s32);
void FUN_082462f4(Entity082464b8*, unknown*, s32);
void FUN_082463cc(Entity082464b8*, unknown*, s32);

void (*const sEntity082464b8Updates[4])(Entity082464b8*, unknown*, s32) = {
    FUN_08246090,
    FUN_0824617c,
    FUN_082462f4,
    FUN_082463cc,
};  // 0x08DBD800

INCASM("asm/entity_082464b8.inc");

NAKED s32 Entity082464b8_Update(Entity082464b8* p) { INCFUNC("asm/func/Entity082464b8_Update.inc"); }

NAKED s32 Entity082464b8_Destroy(Entity082464b8* p) { INCFUNC("asm/func/Entity082464b8_Destroy.inc"); }

NAKED s32 Entity082464b8_Init(Entity082464b8* p, s32 val) { INCFUNC("asm/func/Entity082464b8_Init.inc"); }

NAKED Entity082464b8* Entity082464b8_Create(s32 val, s32 _) { INCFUNC("asm/func/Entity082464b8_Create.inc"); }

NAKED s32 FUN_082464fc(unknown* p, unknown* param_2, unknown* param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_082464fc.inc"); }

NAKED void* FUN_08246624(unknown* p) { INCFUNC("asm/func/FUN_08246624.inc"); }
