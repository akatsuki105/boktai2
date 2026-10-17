#include "entity.h"
#include "global.h"
#include "vm.h"

// レコードの置き場, 0x03000740 の深さで 2面を切り替えて使う
typedef struct {
  s32 count;              // 0x00, recs の件数
  u32 valueCount;         // 0x04, values に積んだ u16 の個数
  ScriptRecord recs[32];  // 0x08
  u16 values[64];         // 0x108, recs[].values が指す先
} ScriptRecordBlock;
static_assert(sizeof(ScriptRecordBlock) == 392);

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

// Entity の更新が止まっていないときだけ, 使う面を切り替えてそちらを空にする
void FUN_08230eb4(void) {
  ScriptRecordBlock* blocks = ScriptRecord_GetBlocks();

  if (gEntityDisableFlags == 0) {
    ScriptRecordBlock* p;

    u32_03000740 ^= 1;
    p = &blocks[u32_03000740];
    p->count = 0;
    p->valueCount = 0;
  }
}

// 同じ id のレコードの直後に p を割り込ませ, 値を values 領域の末尾へ積む
void FUN_08230eec(ScriptRecord* p) {
  ScriptRecordBlock* b = &ScriptRecord_GetBlocks()[u32_03000740];
  ScriptRecord* rec = b->recs;
  s32 pos = b->count;
  u16* dst;
  u16* src;
  s32 i;

  for (i = 0; i < b->count; i++, rec++) {
    if (rec->id == p->id) {
      pos = i + 1;
    }
  }

  for (i = b->count; i > pos; i--) {
    b->recs[i] = b->recs[i - 1];
  }

  b->count++;
  rec = &b->recs[pos];
  rec->id = p->id;
  rec->unk_02 = 0;
  rec->count = p->count;
  src = p->values;
  dst = &b->values[b->valueCount];
  rec->values = dst;
  b->valueCount += p->count;

  for (i = 0; i < p->count; i++) {
    *dst++ = *src++;
  }
}

NAKED s32 FUN_08230f94(u32 id, ScriptRecord** out) { INCFUNC("asm/func/FUN_08230f94.inc"); }
