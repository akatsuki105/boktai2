#include "entity.h"
#include "global.h"

// BLDCNT と BLDALPHA / BLDY を指定フレーム数かけて動かし、終わると自分を消すブレンド演出
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_11
  u8 mode;       // 0x18, '.m=1', 1 なら BLDALPHA, それ以外は BLDY を動かす
  s8 from[2];    // 0x19, '.i', 補間の初期値 (BLDY は [0] だけ使う)
  s8 delta[2];   // 0x1B, '.a' から from を引いた差分, timer/duration を掛けて from に足す
  u8 unk_1d[3];  // 0x1D, 触られていない
  u16 target1;   // 0x20, '.s=0', BLDCNT の第1対象
  u16 target2;   // 0x22, '.d=0', BLDCNT の第2対象
  s32 timer;     // 0x24, 毎フレーム +1, duration 以上になると自分を消す
  s32 duration;  // 0x28, '.t=60', 0 を渡されたときも 60 になる
} Entity82B7;
static_assert(sizeof(Entity82B7) == 44);

NAKED s32 Entity82B7_Update(Entity82B7* p) { INCFUNC("asm/func/Entity82B7_Update.inc"); }

NAKED s32 Entity82B7_Destroy(Entity82B7* p) { INCFUNC("asm/func/Entity82B7_Destroy.inc"); }

NAKED s32 Entity82B7_Init(Entity82B7* p) { INCFUNC("asm/func/Entity82B7_Init.inc"); }

NAKED Entity82B7* Entity82B7_Create(void) { INCFUNC("asm/func/Entity82B7_Create.inc"); }
