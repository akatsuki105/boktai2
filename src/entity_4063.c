#include "entity.h"
#include "global.h"

// 画面にカウントダウンを出し、0 になったらスクリプトを実行して消えるタイマー
typedef struct Entity4063 {
  Entity e;          // 0x00, ENTITY_UNK_8
  u16 timer;         // 0x18, 残りフレーム数, _Init が '.t=1800' を入れ、_Update が毎フレーム -1. アドレスを FUN_0809c544 に渡して画面に出す
  bool16 cancelled;  // 0x1A, Entity4063_Cancel が立てる, _Update はこれを見るとスクリプトを実行せずに KillEntity する
  u32 scriptID;      // 0x1C, timer が 0 になったとき VM_ExecByID に渡す, _Init が '.p' から取る, 0 なら何も実行しない
} Entity4063;
static_assert(sizeof(Entity4063) == 32);

extern Entity4063* gEntity4063;  // 0x03002C50

NAKED s32 Entity4063_GetRemaining(void) { INCFUNC("asm/func/Entity4063_GetRemaining.inc"); }

// 次の更新でスクリプトを実行せずに消えるようにする
void Entity4063_Cancel(void) {
  if (gEntity4063 != NULL) {
    gEntity4063->cancelled = TRUE;
  }
}

NAKED s32 Entity4063_Update(Entity4063* p) { INCFUNC("asm/func/Entity4063_Update.inc"); }

s32 Entity4063_Destroy(Entity4063* p) {
  gEntity4063 = NULL;
  return 0;
}

NAKED s32 Entity4063_Init(Entity4063* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/Entity4063_Init.inc"); }

NAKED Entity4063* Entity4063_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/Entity4063_Create.inc"); }
