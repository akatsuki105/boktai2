#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_8
  u8 unk_18[3776 - 0x18];
} Entity08058ffc;
static_assert(sizeof(Entity08058ffc) == 3776);

IWRAM_DATA Entity08058ffc* gEntity08058ffc = NULL;  // 0x0300012C

void FUN_080573a0(Entity08058ffc*, unknown*, s32);
void FUN_08057478(Entity08058ffc*, unknown*, s32);
void FUN_0805758c(Entity08058ffc*, unknown*, s32);
void FUN_080579a4(Entity08058ffc*, unknown*, s32);
void FUN_08057db0(Entity08058ffc*, unknown*, s32);
void FUN_080581dc(Entity08058ffc*, unknown*, s32);
void FUN_08058460(Entity08058ffc*, unknown*, s32);
void FUN_080587cc(Entity08058ffc*, unknown*, s32);
void FUN_08058a98(Entity08058ffc*, unknown*, s32);
void FUN_08058ae4(Entity08058ffc*, unknown*, s32);

const u32 u32_ARRAY_085ab9a4[4] = {64, 16, 0, 0};  // 0x085AB9A4

void (*const PTR_ARRAY_085ab9b4[10])(Entity08058ffc*, unknown*, s32) = {
    FUN_080573a0,
    FUN_08057478,
    FUN_0805758c,
    FUN_080579a4,
    FUN_08057db0,
    FUN_080581dc,
    FUN_08058460,
    FUN_080587cc,
    FUN_08058a98,
    FUN_08058ae4,
};  // 0x085AB9B4

INCASM("asm/entity_08058ffc.inc");
