#include "entity.h"
#include "global.h"

// 画面全体のフェード (ブレンド係数 s32_0300445c と フェード色 u16_03004464) を動かすシングルトン
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_11
  u16 unk_18;         // 0x18, _Create の引数, 書き込むだけで読み手が見つかっていない
  u16 unk_1a;         // 0x1A, _Init が VM キーワード 'f' を入れる, 読み手が見つかっていない
  u16 unk_1c;         // 0x1C, _Init が 0 を入れるだけ
  u16 state;          // 0x1E, 0:停止, 1/3:係数を 0x40 へ上げる (_StepUp), 2/4:0 へ下げる (_StepDown)
  u16 timer;          // 0x20, state に入ってからのステップ数, (timer << 6) >> durationShift が係数
  u16 durationShift;  // 0x22, params[0] の写し, 1 << durationShift ステップで終わる
  u16 request;        // 0x24, 1..4 の要求, _Update が state に移して毎フレーム 0 に戻す
  u16 params[7];      // 0x26, [0]=durationShift, [1..3]=フェード色の R/G/B (u16_03004464 へ rgb555 で合成), [4]=u16_03004490
} Entity6978;
static_assert(sizeof(Entity6978) == 52);

COMMON_DATA Entity6978* gEntity6978 = NULL;  // 0x03002B30

INCASM("asm/entity_6978.inc");

NAKED s32 Entity6978_Update(Entity6978* p) { INCFUNC("asm/func/Entity6978_Update.inc"); }

s32 Entity6978_Destroy(Entity6978* p) { gEntity6978 = NULL; }

NAKED s32 Entity6978_Init(Entity6978* p, u16 id) { INCFUNC("asm/func/Entity6978_Init.inc"); }

Entity6978* Entity6978_Create(u32 id) {
  Entity6978* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity6978));
  if (p != NULL) {
    SetEntityRoutine(p, Entity6978_Update, Entity6978_Destroy);
    if (Entity6978_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
