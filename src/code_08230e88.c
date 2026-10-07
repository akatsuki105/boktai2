#include "global.h"
#include "vm.h"

IWRAM_DATA u32 u32_03000740 = 0;

EWRAM_DATA u32 u32_ARRAY_0203f400[256] = {};  // 0x0203F400

ScriptRecordBlock* ScriptRecord_GetBlocks(void) { return (ScriptRecordBlock*)u32_ARRAY_0203f400; }

// 2面のレコード置き場を両方空にして深さを 0 に戻す
void ScriptRecord_ResetAll(void) {
  ScriptRecordBlock* p = ScriptRecord_GetBlocks();

  u32_03000740 = 0;
  p[0].count = 0;
  p[0].valueCount = 0;
  p[1].count = 0;
  p[1].valueCount = 0;
}

NAKED void FUN_08230eb4(void) { INCFUNC("asm/func/FUN_08230eb4.inc"); }

NAKED void FUN_08230eec(unknown* p) { INCFUNC("asm/func/FUN_08230eec.inc"); }

NAKED s32 FUN_08230f94(u32 id, ScriptRecord** out) { INCFUNC("asm/func/FUN_08230f94.inc"); }
