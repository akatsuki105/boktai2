#include "entity.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "vm.h"

// プレイヤーの HP/ENE を約90フレームかけて最大値まで回復させる
typedef struct {
  Entity e;        // 0x00, ENTITY_UNK_9
  Player* player;  // 0x18, gPlayerPtr[0]
  bool8 hpDone;    // 0x1C, '.l', hp が maxHP に達したら 1
  bool8 eneDone;   // 0x1D, '.e', ene が maxEne に達したら 1
  u8 unk_1e[2];    // 0x1E, ??
  u16 hpStep;      // 0x20, 毎フレーム hp に加算、maxHP / 90 (最低 1)
  u16 eneStep;     // 0x22, 毎フレーム ene に加算、maxEne / 90 (最低 1)
  u32 scriptID;    // 0x24, '.p', 両方完了時に Script_ExecById で実行
} Entity87FE;
static_assert(sizeof(Entity87FE) == 40);

// hp/ene を毎フレーム加算し、最大値に達した側から打ち止める。両方揃ったら SE とスクリプトを実行して自身を消す
s32 Entity87FE_Update(Entity87FE* p) {
  if (!p->hpDone) {
    if ((p->player->hp += p->hpStep) >= p->player->maxHP) {
      p->player->hp = p->player->maxHP;
      p->hpDone = TRUE;
    }
  }
  if (!p->eneDone) {
    if ((p->player->ene += p->eneStep) >= p->player->maxEne) {
      p->player->ene = p->player->maxEne;
      p->eneDone = TRUE;
    }
  }
  if (p->hpDone && p->eneDone) {
    sound_08240740(0x259);
    if (p->scriptID != 0) Script_ExecById(p->scriptID, NULL);
    KillEntity((Entity*)p);
  }
  return 0;
}

s32 Entity87FE_Destroy(Entity87FE* p) { return 0; }

// '.l', '.e' で hp/ene それぞれの回復可否を決め、90 フレームで最大値に届く毎フレームの加算量を求める
s32 Entity87FE_Init(Entity87FE* p) {
  s32 hpArg, eneArg;

  p->player = gPlayerPtr[0];
  if (p->player == NULL) {
    return -1;
  }

  hpArg = VM_SeekToKeyword('l') ? Script_GetValue() : 0;
  eneArg = VM_SeekToKeyword('e') ? Script_GetValue() : 0;

  if (hpArg != 0 && p->player->hp < p->player->maxHP) {
    if ((p->hpStep = Div(p->player->maxHP, 90)) == 0) {
      p->hpStep = 1;
    }
    p->hpDone = FALSE;
  } else {
    p->hpDone = TRUE;
  }

  if (eneArg != 0 && p->player->ene < p->player->maxEne) {
    if ((p->eneStep = Div(p->player->maxEne, 90)) == 0) {
      p->eneStep = 1;
    }
    p->eneDone = FALSE;
  } else {
    p->eneDone = TRUE;
  }
  if (!p->hpDone || !p->eneDone) PlaySound_082406e0(0x259);

  if (VM_SeekToKeyword('p')) {
    p->scriptID = Script_GetValue();
  } else {
    p->scriptID = 0;
  }
  return 0;
}

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
