#include "enemy.h"
#include "global.h"

// Enemy の共通部分?

NAKED void FUN_080ef84c(Enemy* p, s32 val1, s32 val2, s32 val3) { INCFUNC("asm/func/FUN_080ef84c.inc"); }

NAKED void FUN_080ef86c(Enemy* p, s32 val1) { INCFUNC("asm/func/FUN_080ef86c.inc"); }

NAKED void FUN_080ef968(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080ef968.inc"); }

NAKED void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080efa6c.inc"); }

INCASM("asm/enemy_080ef84c.inc");
