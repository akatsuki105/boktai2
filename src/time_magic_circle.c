#include "entity.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

#define TO_PAST 0
#define TO_PRESENT 1

// "時の家" のタイム魔方陣 ("時の家"はこの魔方陣を駆使して、現在と過去を行き来して攻略するダンジョン)
typedef struct TimeMC {
  Entity e;                                // 0x00, ENTITY_UNK_9
  u16 nearState;                           // 0x18, プレイヤーが近いかを 0/1 で覚え、変わったフレームだけ効果音を鳴らす
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

void FUN_080a6e88(bool32 stopSound);
void FUN_0807ba94(Player* p, Vec3* pos, u32 scriptID, DirS32 dir);
void TimeMC_UpdateActivated(TimeMC* p);
void TimeMC_UpdateDone(TimeMC* p);

// プレイヤーが魔方陣の中心から 0x60 以内にいるかどうか
bool32 TimeMC_IsPlayerNear(TimeMC* p) {
  s32 dx = gStat->playerX - p->pos.x;
  s32 dz;

  if (dx < 0) {
    dx = -dx;
  }
  dz = gStat->playerZ - p->pos.z;
  if (dz < 0) {
    dz = -dz;
  }
  if (dx <= 0x60 && dz <= 0x60 && dx * dx + dz * dz <= 0x60 * 0x60) {
    return TRUE;
  }
  return FALSE;
}

void TimeMC_SetUpdateCallback(TimeMC* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// プレイヤーが近いと浮き上がって光り, A ボタンでプレイヤーを pos へ飛ばす
void TimeMC_UpdateIdle(TimeMC* p) {
  if (!(gGameFlags & FLAG030047A4_UNK_9)) {
    if (p->readyTimer < 10) {
      p->readyTimer++;
    }
  }

  if (TimeMC_IsPlayerNear(p)) {
    if (p->nearState != 1) {
      PlaySound_082406e0(SE_CIRCLE_IN);
      p->nearState = 1;
    }
    if (p->highlight < 8) {
      p->highlight++;
    }
    if (p->rise < 23) {
      p->rise += 2;
    } else {
      p->rise = 24;
    }
    if (TEST_FLAGS(gPlayerStates[0], PMODE_ACTIVE) && (gInput[0].pressed & A_BUTTON) && gPlayerPtr[0]->formRequest == 0 && p->readyTimer > 9) {
      p->highlight = 8;
      FUN_080a6e88(TRUE);
      FUN_0807ba94(gPlayerPtr[0], &p->pos, 0, 4);
      TimeMC_SetUpdateCallback(p, TimeMC_UpdateActivated);
    }
  } else {
    if (p->nearState != 0) {
      PlaySound_082406e0(SE_CIRCLE_OUT);
      p->nearState = 0;
    }
    if (p->highlight != 0) {
      p->highlight--;
    }
    if (p->rise > 2) {
      p->rise -= 2;
    } else {
      p->rise = 0;
    }
  }

  if (p->rise == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->rise;
  }

  if (p->highlight > 7) {
    Video_SetAuxSpritePltt(&p->gfx, 286);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

// 沈みきってプレイヤーが落ち着いたら '.R' のスクリプトを '.A' の2引数で実行する
void TimeMC_UpdateActivated(TimeMC* p) {
  if (p->rise > 1) {
    p->rise -= 2;
  } else {
    p->rise = 0;
  }
  p->sprite.pos.y = p->pos.y + p->rise;
  if (p->rise == 0 && gPlayerPtr[0]->action == 0) {
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    TimeMC_SetUpdateCallback(p, TimeMC_UpdateDone);
    if (p->scriptID != 0) {
      u32 argv[2];
      ScriptArgs args;

      args.argc = 2;
      args.argv = argv;
      argv[0] = p->scriptArgs[0];
      argv[1] = p->scriptArgs[1];
      VM_ExecByID(p->scriptID, &args);
    }
  }
}

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

s32 TimeMC_Init(TimeMC* p, u32 _, u32 __) {
  s32 i;

  if (VM_SeekToNamedArg('t')) {
    p->kind = VM_GetValue();
  } else {
    p->kind = 0;
  }

  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
    p->pos.y = TileHeightAt(&p->pos);
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
  }

  if (VM_SeekToNamedArg('R')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }

  if (VM_SeekToNamedArg('A')) {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = VM_GetValue();
    }
  } else {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = 0;
    }
  }

  if (p->kind == TO_PAST) {
    p->plttID = 284;
  } else {
    p->plttID = 285;
  }

  Video_GetAuxSprite(&p->gfx, SPRITE_TIME_MCIRCLE);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->sprite.flags |= SPRFLAG_BLINK_ODD;
  p->sprite.priority = 3;
  p->sprite.pos = p->pos;

  Video_GetAuxSprite(&p->gfx2, SPRITE_TIME_MCIRCLE);
  AuxSprite_Add(&p->sprite2, &p->gfx2, 0);
  Video_SetAuxSpritePltt(&p->gfx2, p->plttID);
  p->sprite2.flags |= SPRFLAG_BLINK_EVEN;
  p->sprite2.priority = 3;
  p->sprite2.pos = p->pos;

  TimeMC_SetUpdateCallback(p, TimeMC_UpdateIdle);
  return 0;
}

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
