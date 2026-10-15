#include "boss.h"

#include "global.h"

// Boss の共通処理? (まだ調査不足)

// 各ボスのシングルトン, idx は BossID
IWRAM_DATA Boss* gBossList[8] = {};  // 0x030000A0

void FUN_08022a0c(Boss* p, BossID id) { gBossList[id] = p; }

void FUN_08022a1c(BossID id) { gBossList[id] = NULL; }

void* FUN_08022a2c(BossID id) { return gBossList[id]; }

INCASM("asm/boss.inc");
