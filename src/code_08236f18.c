#include "animation.h"
#include "global.h"

// TODO: いろんな用途のデータが区別されてないのであとで分ける
IWRAM_DATA u8 u8_03000784[0x030016A0 - 0x03000784] = {};

NAKED bool32 FUN_08236fac(AnimState* p, AnimationFile* files, u16 animIdx, u8 param_4, AnimPlayFlags flags) { INCFUNC("asm/func/FUN_08236fac.inc"); }

NAKED bool32 FUN_08237040(AnimState* p, AnimationFile* files, u16 animIdx, u8 param_4, AnimPlayFlags flags) { INCFUNC("asm/func/FUN_08237040.inc"); }

NAKED bool32 FUN_08237064(AnimState* p, u16 val) { INCFUNC("asm/func/FUN_08237064.inc"); }

NAKED void FUN_08237098(AnimState* p, u16 speed) { INCFUNC("asm/func/FUN_08237098.inc"); }

NAKED void FUN_082370c0(AnimState* p) { INCFUNC("asm/func/FUN_082370c0.inc"); }
