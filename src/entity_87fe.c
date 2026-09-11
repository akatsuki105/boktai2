#include "entity.h"
#include "global.h"
#include "player.h"

// プレイヤーの HP/ENE を約90フレームかけて最大値まで回復させる
typedef struct {
  Entity e;          // 0x0, ENTITY_UNK_9
  Player* player;    // 0x18, gPlayerPtr[0]
  u8 q_hpDone;       // 0x1C, hp が maxHP に達したら 1 ('l' キーワード無しなら最初から 1)
  u8 q_eneDone;      // 0x1D, ene が maxEne に達したら 1 ('e' キーワード無しなら最初から 1)
  u8 unk_1e[2];
  u16 q_hpStep;      // 0x20, 毎フレーム hp に加算、maxHP / 90 (最低 1)
  u16 q_eneStep;     // 0x22, 毎フレーム ene に加算、maxEne / 90 (最低 1)
  u32 scriptID;      // 0x24, 'p' キーワードの値、両方完了時に Script_ExecById で実行
} Entity87FE;
static_assert(sizeof(Entity87FE) == 40);

NAKED s32 Entity87FE_Update(Entity87FE* p) { INCFUNC("asm/func/Entity87FE_Update.inc"); }

s32 Entity87FE_Destroy(Entity87FE* p) { return 0; }

NAKED s32 Entity87FE_Init(Entity87FE* p) { INCFUNC("asm/func/Entity87FE_Init.inc"); }

Entity87FE* Entity87FE_Create(u32 unused1, u32 unused2) {
  Entity87FE* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity87FE));
  if (p != NULL) {
    SetEntityRoutine(p, Entity87FE_Update, Entity87FE_Destroy);
    if (Entity87FE_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
