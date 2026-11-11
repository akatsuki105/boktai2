#include "entity.h"
#include "global.h"
#include "vm.h"

// メッセージの置き場1面, 2面を sScriptMesgBlockIdx で切り替え, 今フレームの面に書き込み前フレームの面から読む
typedef struct {
  s32 count;             // 0x00, mesgs の件数
  u32 valueCount;        // 0x04, values に積んだ u16 の個数
  ScriptMesg mesgs[32];  // 0x08
  u16 values[64];        // 0x108, mesgs[].values が指す先
} ScriptMesgBlock;
static_assert(sizeof(ScriptMesgBlock) == 392);

static u32 sScriptMesgBlockIdx;  // 0x03000740, 今フレームに書き込む面の番号 (0 / 1)

EWRAM_DATA u32 sScriptMesgBlocks[256] = {};  // 0x0203F400, ScriptMesgBlock 2面ぶんの置き場

ScriptMesgBlock* ScriptMesg_GetBlocks(void) { return (ScriptMesgBlock*)sScriptMesgBlocks; }

// 2面のメッセージ置き場を両方空にして面の番号を 0 に戻す
void ScriptMesg_ResetAll(void) {
  ScriptMesgBlock* p = ScriptMesg_GetBlocks();

  sScriptMesgBlockIdx = 0;
  p[0].count = 0;
  p[0].valueCount = 0;
  p[1].count = 0;
  p[1].valueCount = 0;
}

// Entity の更新が止まっていないときだけ, 使う面を切り替えてそちらを空にする
void ScriptMesg_SwapBlock(void) {
  ScriptMesgBlock* blocks = ScriptMesg_GetBlocks();

  if (gSuspendFlags == 0) {
    ScriptMesgBlock* p;

    sScriptMesgBlockIdx ^= 1;
    p = &blocks[sScriptMesgBlockIdx];
    p->count = 0;
    p->valueCount = 0;
  }
}

// 同じ id のメッセージの直後に p を割り込ませ, 値を values 領域の末尾へ積む
void ScriptMesg_Post(ScriptMesg* p) {
  ScriptMesgBlock* b = &ScriptMesg_GetBlocks()[sScriptMesgBlockIdx];
  ScriptMesg* rec = b->mesgs;
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
    b->mesgs[i] = b->mesgs[i - 1];
  }

  b->count++;
  rec = &b->mesgs[pos];
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

// 前のフレームに積まれた面から id のメッセージを探し, 先頭を *out に入れて同じ id が続く件数を返す, 無ければ 0
s32 ScriptMesg_Find(u32 id, ScriptMesg** out) {
  ScriptMesgBlock* b = &ScriptMesg_GetBlocks()[1 - sScriptMesgBlockIdx];
  ScriptMesg* rec = b->mesgs;
  s32 i;

  for (i = 0; i < b->count; i++, rec++) {
    if (rec->id == id) {
      s32 n;

      *out = rec;
      for (rec++, i++, n = 1; i < b->count && rec->id == id; i++, n++, rec++) {
      }
      return n;
    }
  }
  return 0;
}
