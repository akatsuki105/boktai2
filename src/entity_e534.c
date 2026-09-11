#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[0xCD4 - 24];
  UnkStruct52 unk_cd4;  // 0xCD4, 根拠: 0x08012bfc
} EntityE534;
static_assert(sizeof(EntityE534) == 3336);

void FUN_080120d4(EntityE534*, void*, void*);
void FUN_0801230c(EntityE534*, void*, void*);
void FUN_08012194(EntityE534*, void*, void*);
void FUN_080124e0(EntityE534*, void*, void*);
void FUN_08012698(EntityE534*, void*, void*);
void FUN_0801280c(EntityE534*, void*, void*);
void FUN_080128cc(EntityE534*, void*, void*);

void (*const PTR_ARRAY_085aa81c[7])(EntityE534*, void*, void*) = {
    FUN_080120d4, FUN_0801230c, FUN_08012194, FUN_080124e0, FUN_08012698, FUN_0801280c, FUN_080128cc,
};  // 0x085aa81c

INCASM("asm/entity_e534.inc");

NAKED s32 EntityE534_Update(EntityE534* p) { INCFUNC("asm/func/EntityE534_Update.inc"); }

NAKED s32 EntityE534_Destroy(EntityE534* p) { INCFUNC("asm/func/EntityE534_Destroy.inc"); }

NAKED s32 EntityE534_Init(EntityE534* p, u32 id) { INCFUNC("asm/func/EntityE534_Init.inc"); }

NAKED EntityE534* EntityE534_Create(u32 id) { INCFUNC("asm/func/EntityE534_Create.inc"); }
