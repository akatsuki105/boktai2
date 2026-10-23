#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

#define TO_PAST 0
#define TO_PRESENT 1

// "時の家" のタイム魔方陣 ("時の家"はこの魔方陣を駆使して、現在と過去を行き来して攻略するダンジョン)
typedef struct TimeMC {
  Entity e;                                // 0x00, ENTITY_UNK_9
  s16 nearState;                           // 0x18, プレイヤーが近いかを 0/1 で覚え、変わったフレームだけ効果音を鳴らす
  u8 kind;                                 // 0x1A, '.t', 0: 現在から過去(TO_PAST), 1: 過去から現在(TO_PRESENT)
  AuxSprite sprite;                        // 0x1C, flags に SPRFLAG_BLINK_ODD が立つ, rise が 0 の間は隠す
  AuxSpriteGfx gfx;                        // 0x48, SPRITE_TIME_MCIRCLE
  WorldPos pos;                            // 0x64, '.p', y はタイルの attr から計算し直す, 起動するとプレイヤーをここへ移す
  AuxSprite sprite2;                       // 0x6C, flags に 0x400 が立つ, 起動が終わると隠す
  AuxSpriteGfx gfx2;                       // 0x98, SPRITE_TIME_MCIRCLE
  u16 plttID;                              // 0xB4, kind が TO_PAST: 284 (青), TO_PRESENT: 285 (黄)
  u16 highlight;                           // 0xB6, 近いと 8 まで増え離れると減る, 8 でパレットが 286 になる
  u16 rise;                                // 0xB8, 近いと 2 ずつ 0x18 まで増え離れると減る, pos.y に足した値が sprite の y になる
  u16 readyTimer;                          // 0xBA, 10 を越えていないと A ボタンで起動できない
  u16 scriptArgs[2];                       // 0xBC, '.A'
  s32 scriptID;                            // 0xC0, '.R', 起動が終わったときに実行する, 0 なら実行しない
  u16 stateTimer;                          // 0xC4, updateCallback を差し替えるたびに 0 に戻る
  void (*updateCallback)(struct TimeMC*);  // 0xC8
} TimeMC;
static_assert(sizeof(TimeMC) == 204);

NAKED bool32 TimeMC_IsPlayerNear(TimeMC* p) { INCFUNC("asm/func/TimeMC_IsPlayerNear.inc"); }

void TimeMC_SetUpdateCallback(TimeMC* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

NAKED void TimeMC_UpdateIdle(TimeMC* p) { INCFUNC("asm/func/TimeMC_UpdateIdle.inc"); }

NAKED void TimeMC_UpdateActivated(TimeMC* p) { INCFUNC("asm/func/TimeMC_UpdateActivated.inc"); }

void TimeMC_UpdateDone(TimeMC* p) {}

s32 TimeMC_Update(TimeMC* p) {
  p->updateCallback(p);
  return 0;
}

s32 TimeMC_Destroy(TimeMC* p) {
  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  return 0;
}

NAKED s32 TimeMC_Init(TimeMC* p, u32 _, u32 __) { INCFUNC("asm/func/TimeMC_Init.inc"); }

// 0x4759
TimeMC* TimeMC_Create(u32 id, u32 _) {
  TimeMC* p = CreateEntity(ENTITY_UNK_9, sizeof(TimeMC));

  if (p != NULL) {
    SetEntityRoutine(p, TimeMC_Update, TimeMC_Destroy);
    if (TimeMC_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
