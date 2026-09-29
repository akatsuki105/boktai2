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

INCASM("asm/entity_4063.inc");
