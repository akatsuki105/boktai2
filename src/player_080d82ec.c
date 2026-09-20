#include "global.h"
#include "player.h"

// 通信対戦で対戦相手のプレイヤー?

NAKED void FUN_080cc1a0(Player* p) { INCFUNC("asm/func/FUN_080cc1a0.inc"); }

INCASM("asm/player_080d82ec.inc");

NAKED void FUN_080d7bdc(void) { INCFUNC("asm/func/FUN_080d7bdc.inc"); }

NAKED void FUN_080d7f48(void) { INCFUNC("asm/func/FUN_080d7f48.inc"); }

NAKED void FUN_080d7fbc(Player* p) { INCFUNC("asm/func/FUN_080d7fbc.inc"); }

NAKED s32 Player080d82ec_Update(Player* p) { INCFUNC("asm/func/Player080d82ec_Update.inc"); }

NAKED s32 Player080d82ec_Destroy(Player* p) { INCFUNC("asm/func/Player080d82ec_Destroy.inc"); }

NAKED s32 Player080d82ec_Init(Player* p, u32 val1, u32 val2) { INCFUNC("asm/func/Player080d82ec_Init.inc"); }

NAKED Player* Player080d82ec_Create(u32 val1, u32 val2) { INCFUNC("asm/func/Player080d82ec_Create.inc"); }
