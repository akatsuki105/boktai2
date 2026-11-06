#include "camera.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "trig.h"
#include "vm.h"

// 画面の振動演出?
// 一定間隔で gCamera->shakeAmplitude を上げて NOISE_QUAKE_121 を鳴らすシングルトン, メッセージ (cmd 4/5) で外部からも起こせる
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_4
  u32 id;               // 0x18, mq の targetID と同じ値
  MsgQueue mq;          // 0x1C, targetClass 10
  bool32 disabled;      // 0x50, '.D=0', 0 以外なら自動発生もボタン操作も止まる
  s32 interval;         // 0x54, '.i=0', nextDelay の基準となるフレーム数
  s32 riseDur;          // 0x58, '.t[0]', 揺れが立ち上がるフレーム数
  s32 holdDur;          // 0x5C, '.t[1]', 最大の揺れを保つフレーム数
  s32 fallDur;          // 0x60, '.t[2]', 揺れが収まるフレーム数
  s32 amplitude;        // 0x64, '.l=0', 揺れの最大値
  s32 shakeAmplitude;   // 0x68, 今フレームの揺れ, gCamera->shakeAmplitude へ渡す
  s32 state;            // 0x6C, 0〜7
  s32 stateTimer;       // 0x70, state が変わると 0
  s32 nextDelay;        // 0x74, 次の発生までのフレーム数, interval + (乱数 & 0x7F)
  bool32 stateBegun;    // 0x78, state が変わった最初のフレームだけ 1
  bool32 soundPlaying;  // 0x7C, NOISE_QUAKE_121 を鳴らしている間 1
} Entity8EC8;
static_assert(sizeof(Entity8EC8) == 128);

// 72/74命令, Camera_PollMessages と同じ残差, 原典は p を r0 から退避してから gMsgBus のプール定数を r0 に載せる, 試済: bus ローカル
NON_MATCH void Entity8EC8_HandleMessages(Entity8EC8* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 4: {
        p->riseDur = msg->args[0];
        p->amplitude = msg->args[1];
        p->state = 5;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 5: {
        p->fallDur = msg->args[0];
        p->state = 7;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Entity8EC8_HandleMessages.inc");
#endif
}

// 残差1命令, 原典は gPlayerPtr[0] のレジスタから写しを作る (Cmd_TestEquipBuff 系と同じ)
NON_MATCH bool8 Entity8EC8_IsStartHeld(void) {
#ifdef NONMATCHING_C
  Player* p = gPlayerPtr[0];

  if ((gInput[0].down & START_BUTTON) && p != NULL && p->mode == PMODE_ACTIVE && !(p->flag20 & PFLAG20_BUSY)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Entity8EC8_IsStartHeld.inc");
#endif
}

// 残差1命令, 原典は gPlayerPtr[0] のレジスタから写しを作る (Cmd_TestEquipBuff 系と同じ)
NON_MATCH bool8 Entity8EC8_IsSelectHeld(void) {
#ifdef NONMATCHING_C
  Player* p = gPlayerPtr[0];

  if ((gInput[0].down & SELECT_BUTTON) && p != NULL && p->mode == PMODE_ACTIVE && !(p->flag20 & PFLAG20_BUSY)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Entity8EC8_IsSelectHeld.inc");
#endif
}

// 309/309命令, state/stateTimer/stateBegun を値引数の SetState inline 経由にすると flags 分岐の 0 の使い回しが揃い, 残差は SIN/COS の添字を持つレジスタ (原典 r2, こちら r3) だけになる, 試済: 添字ローカルの型 s32/u32/u16/s16/u8/s8, 宣言位置, ブロック局所, POLAR_X/Z, 添字や波形の inline
NON_MATCH s32 Entity8EC8_Update(Entity8EC8* p) {
#ifdef NONMATCHING_C
  s32 amp = 0;
  s32 angle;
  bool32 begun;

  Entity8EC8_HandleMessages(p);
  p->stateTimer++;
  if (!p->disabled) {
    if (gGameFlags & (GAMEFLAG_EVENT | GAMEFLAG_GAMEOVER)) {
      if (p->state != 0) {
        p->state = 0;
      } else {
        p->state = 4;
      }
      p->stateTimer = 0;
      p->stateBegun = TRUE;
      if (p->soundPlaying) {
        FUN_082405c0(1);
        p->soundPlaying = FALSE;
      }
    } else if (Entity8EC8_IsStartHeld()) {
      p->state = 0;
      p->stateTimer = 0;
      p->stateBegun = TRUE;
      p->shakeAmplitude = 0;
      Camera_Translate();
      PlaySound_082406e0(NOISE_QUAKE_121);
      sound_08240740(NOISE_QUAKE_121);
      p->soundPlaying = FALSE;
    } else if (Entity8EC8_IsSelectHeld()) {
      p->state = 0;
      p->stateTimer = 0;
      p->stateBegun = TRUE;
      p->shakeAmplitude = 0;
      Camera_Translate();
      if (p->soundPlaying) {
        FUN_082405c0(1);
        p->soundPlaying = FALSE;
      }
    }
    if (p->soundPlaying && !sound_08240960(NOISE_QUAKE_121)) {
      p->soundPlaying = FALSE;
    }
  }

  switch (p->state) {
    case 0: {
      begun = p->stateBegun;
      p->stateBegun = FALSE;
      if (begun) {
        p->nextDelay = p->interval + (Random() & 0x7F);
      }
      if ((s32)gEntityDisableFlags > 0) {
        p->stateTimer = 0;
      } else if (!p->disabled && p->stateTimer >= p->nextDelay) {
        p->state = 1;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 1: {
      begun = p->stateBegun;
      p->stateBegun = FALSE;
      if (begun) {
        FUN_082404b0(NOISE_QUAKE_121);
        FUN_082404fc(FixToInt(4, p->riseDur));
        p->soundPlaying = TRUE;
      }
      angle = Div(p->stateTimer << 6, p->riseDur);
      amp = FixToInt(12, SIN(angle) * p->amplitude);
      p->shakeAmplitude = amp;
      if (p->stateTimer >= p->riseDur) {
        p->state = 2;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 2: {
      amp = p->amplitude;
      p->shakeAmplitude = amp;
      if (p->stateTimer >= p->holdDur) {
        p->state = 3;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 3: {
      begun = p->stateBegun;
      p->stateBegun = FALSE;
      if (begun) {
        FUN_082405c0(FixToInt(4, p->fallDur));
      }
      angle = Div(p->stateTimer << 6, p->fallDur);
      amp = FixToInt(12, COS(angle) * p->amplitude);
      p->shakeAmplitude = amp;
      if (p->stateTimer >= p->fallDur) {
        p->state = 0;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 4: {
      p->shakeAmplitude = FixToInt(2, p->shakeAmplitude * 3);
      amp = p->shakeAmplitude;
      if (amp == 0) {
        p->state = 0;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 5: {
      angle = Div(p->stateTimer << 6, p->riseDur);
      amp = FixToInt(12, SIN(angle) * p->amplitude);
      if (p->stateTimer >= p->riseDur) {
        p->state = 6;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
    case 6: {
      amp = p->amplitude;
      break;
    }
    case 7: {
      angle = Div(p->stateTimer << 6, p->fallDur);
      amp = FixToInt(12, COS(angle) * p->amplitude);
      if (p->stateTimer >= p->fallDur) {
        p->state = 0;
        p->stateTimer = 0;
        p->stateBegun = TRUE;
      }
      break;
    }
  }
  Camera_Shake(amp);
  return 0;
#else
  INCFUNC("asm/func/Entity8EC8_Update.inc");
#endif
}

s32 Entity8EC8_Destroy(Entity8EC8* p) {
  MsgQueue_Unregister(&p->mq);
  sound_08240740(NOISE_QUAKE);
  return 0;
}

s32 Entity8EC8_Init(Entity8EC8* p, u32 id) {
  p->id = id;
  p->disabled = VM_GetNamedArgValue('D', 0);
  p->interval = VM_GetNamedArgValue('i', 0);
  if (VM_SeekToNamedArg('t')) {
    p->riseDur = VM_GetValue();
    p->holdDur = VM_GetValue();
    p->fallDur = VM_GetValue();
  }
  p->amplitude = VM_GetNamedArgValue('l', 0);
  p->shakeAmplitude = 0;
  p->soundPlaying = FALSE;
  p->state = 0;
  p->stateTimer = 0;
  p->stateBegun = TRUE;
  MsgQueue_Register(&p->mq, id, 10);
  return 0;
}

// 0x8EC8
Entity8EC8* Entity8EC8_Create(u32 id) {
  Entity8EC8* p = CreateEntity(ENTITY_UNK_4, sizeof(Entity8EC8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity8EC8_Update, Entity8EC8_Destroy);
    if (Entity8EC8_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
