#include "entity.h"
#include "global.h"

void FUN_0805fb20(unknown*, unknown*, s32);
void FUN_0805fc38(unknown*, unknown*, s32);

void (*const PTR_ARRAY_085aba9c[2])(unknown*, unknown*, s32) = {
    FUN_0805fb20,
    FUN_0805fc38,
};  // 0x085ABA9C

INCASM("asm/entity_0805fe30.inc");
