#include "entity.h"
#include "global.h"
#include "player.h"

// 通信対戦の自キャラ (gPlayerPtr[1] に格納される)

INCASM("asm/player_link.inc");

NAKED void FUN_08084540(Player* p) { INCFUNC("asm/func/FUN_08084540.inc"); }

NAKED s32 LinkPlayer_Update(Player* p) { INCFUNC("asm/func/LinkPlayer_Update.inc"); }

NAKED s32 LinkPlayer_Destroy(Player* p) { INCFUNC("asm/func/LinkPlayer_Destroy.inc"); }

NAKED s32 LinkPlayer_Init(Player* p, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/LinkPlayer_Init.inc"); }

NAKED Player* LinkPlayer_Create(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/LinkPlayer_Create.inc"); }
