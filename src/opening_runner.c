#include "entity.h"
#include "file.h"
#include "global.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// (太陽銃を奪われた後の)サンミゲルに向かって、ジャンゴとおてんこが走っていく演出 (手前から奥へ走っていくので、スプライトが徐々に小さくなる)
// このエンティティ1つは ジャンゴ または おてんこ のどちらかのみを表す (なので、 2つ必要)
// スクリプト (Scr_0x0332) が渡すインスタンスIDは HashName("ジャンゴ") = 0xBF31 ('.k=0') と HashName("おてんこ") = 0xBB34 ('.k=1')
typedef struct OpRunner {
  Entity e;                                  // 0x0, ENTITY_UNK_8
  MainSpriteGfx djangoGfx;                   // 0x18, SPR_DJANGO_SABATA
  MainSprite django;                         // 0x38, kind=0
  AuxSprite otenko;                          // 0x98, kind=1
  AuxSpriteGfx otenkoGfx;                    // 0xC4, SPR_OTENKO_00
  AuxAnimState otenkoAnim;                   // 0xE0 ->otenkoAnimFile
  AuxAnimFile* otenkoAnimFile;               // 0xF0, ANIM_OTENKO
  s32 kind;                                  // 0xF4, '.k', 0: ジャンゴ, 1: おてんこ
  u32 pauseFlags;                            // 0xF8, bit0/bit1 が立っている間 stateTimer / moveTimer を止める
  u32 state;                                 // 0xFC, updateCallback の表の添字 (0 だけ)
  u32 stateTimer;                            // 0x100
  u32 moveState;                             // 0x104, 0: 止まっている, 1: 目的地へ移動中
  u32 moveTimer;                             // 0x108
  s32 posX;                                  // 0x10C, s16_16, '.p[0]'
  s32 posY;                                  // 0x110, s16_16, '.p[1]'
  s32 targetX;                               // 0x114, 移動先, Cmd_641D の '.p[0]'
  s32 targetY;                               // 0x118, Cmd_641D の '.p[1]'
  s32 dirX;                                  // 0x11C, 目的地への単位ベクトル (s16_16)
  s32 dirY;                                  // 0x120
  s16 speed;                                 // 0x124, '.s'
  u8 unk_126[2];                             // 0x126, まだ未解析
  s16 speedScaleFrom;                        // 0x128, 64 = 等倍, speedScaleTo へ補間する
  s16 speedScaleTo;                          // 0x12A, Cmd_88B7 の '.s'
  s16 speedScaleFrames;                      // 0x12C, Cmd_88B7 の '.t', 補間にかけるフレーム数
  s16 speedScaleTimer;                       // 0x12E, 補間の残りフレーム数
  s16 scaleFrom;                             // 0x130, '.S=64', スプライトの拡大率を scaleTo へ補間する
  s16 scaleTo;                               // 0x132, '.S=64', Cmd_1ED1 の '.s'
  s16 scaleFrames;                           // 0x134, Cmd_1ED1 の '.t'
  s16 scaleTimer;                            // 0x136, 補間の残りフレーム数
  u32 arrivalScript;                         // 0x138, Cmd_641D の '.P', 目的地に着いたら実行するスクリプトの ID
  AuxSprite shadow;                          // 0x13C, pose 5, 毎フレーム点滅させる
  AuxSpriteGfx shadowGfx;                    // 0x168, SPR_EFF_1C1B
  void (*updateCallback)(struct OpRunner*);  // 0x184
  u8 unk_188[392 - 0x188];                   // 0x188, まだ未解析
} OpRunner;
static_assert(sizeof(OpRunner) == 392);

COMMON_DATA OpRunner* gOpRunners[2] = {};  // 0x03002C98, [0: ジャンゴ, 1: おてんこ]

static inline bool32 OpRunner_ConsumePauseFlag(OpRunner* p, u32 mask) {
  u32 set = p->pauseFlags & mask;

  if (set) {
    set = TRUE;
  }
  p->pauseFlags &= ~mask;
  return set;
}

static inline void OpRunner_SetMoveState(OpRunner* p, u32 state) {
  p->moveState = state;
  p->moveTimer = 0;
  SET_FLAGS(p->pauseFlags, 2);
}

// '.p' の座標へ向けて移動を始めさせる, 着いたら '.P' のスクリプトを実行する ('.k' で対象を選ぶ)
void Cmd_641D(void) {
  s32 kind = VM_GetNamedArgValue('k', -1);
  OpRunner* p = gOpRunners[kind];
  s32 dx;
  s32 dy;
  u16 dist;

  if (VM_SeekToNamedArg('p')) {
    p->targetX = VM_GetValue();
    p->targetY = VM_GetValue();
  }
  if (VM_SeekToNamedArg('P')) {
    p->arrivalScript = VM_GetValue();
  } else {
    p->arrivalScript = 0;
  }
  dx = p->targetX - FixToInt(16, p->posX);
  dy = p->targetY - FixToInt(16, p->posY);
  dist = Sqrt(dx * dx + dy * dy);
  p->dirX = Div(dx << 16, dist);
  p->dirY = Div(dy << 16, dist);
  OpRunner_SetMoveState(p, 1);
}

// 移動速度の倍率を '.t' フレームかけて '.s' へ変える ('.k' で対象を選ぶ)
void Cmd_88B7(void) {
  s32 kind = VM_GetNamedArgValue('k', -1);
  OpRunner* p = gOpRunners[kind];

  if (VM_SeekToNamedArg('s')) {
    p->speedScaleFrom = p->speedScaleTo;
    p->speedScaleTo = VM_GetValue();
  }
  if (VM_SeekToNamedArg('t')) {
    p->speedScaleFrames = VM_GetValue();
  }
  p->speedScaleTimer = p->speedScaleFrames;
}

// 拡大率を '.t' フレームかけて '.s' へ変える ('.k' で対象を選ぶ)
void Cmd_1ED1(void) {
  s32 kind = VM_GetNamedArgValue('k', -1);
  OpRunner* p = gOpRunners[kind];

  if (VM_SeekToNamedArg('s')) {
    p->scaleFrom = p->scaleTo;
    p->scaleTo = VM_GetValue();
  }
  if (VM_SeekToNamedArg('t')) {
    p->scaleFrames = VM_GetValue();
  }
  p->scaleTimer = p->scaleFrames;
}

// 本体のスプライトを posX/posY に合わせる, おてんこは 15 ドット上にずらす
void OpRunner_SyncSpritePos(OpRunner* p) {
  if (p->kind == 0) {
    p->django.pos.x = FixToInt(16, p->posX);
    p->django.pos.y = FixToInt(16, p->posY);
  } else {
    p->otenko.pos.x = FixToInt(16, p->posX);
    p->otenko.pos.y = FixToInt(16, p->posY);
    p->otenko.pos.y -= 15;
  }
}

// 目的地へ1フレーム分進める, 通り過ぎたら目的地に合わせて TRUE を返す
bool32 OpRunner_MoveToTarget(OpRunner* p) {
  bool32 arrived = FALSE;
  s32 speedScale;
  s32 speed;
  s32 vx;
  s32 vy;
  s32 dx;
  s32 dy;

  if (p->speedScaleTimer > 0) {
    speedScale = Div(p->speedScaleFrom * p->speedScaleTimer + p->speedScaleTo * (p->speedScaleFrames - p->speedScaleTimer), p->speedScaleFrames);
    p->speedScaleTimer--;
  } else {
    speedScale = p->speedScaleTo;
  }
  speed = FixToInt(6, (speedScale * p->speed) << 8);
  vx = FixToInt(8, p->dirX * speed);
  vy = FixToInt(8, p->dirY * speed);
  p->posX += vx;
  p->posY += vy;
  dx = p->targetX - FixToInt(16, p->posX);
  dy = p->targetY - FixToInt(16, p->posY);
  if (p->dirX * dx + p->dirY * dy <= 0) {
    p->posX = p->targetX << 16;
    p->posY = p->targetY << 16;
    arrived = TRUE;
  }
  OpRunner_SyncSpritePos(p);
  return arrived;
}

// 目的地へ進めて走るアニメと拡大率を更新し, 影を点滅させる
void OpRunner_UpdateRun(OpRunner* p) {
  s32 scale;
  AuxSprite* shadow;
  s32 shadowScale;

  if (OpRunner_ConsumePauseFlag(p, 1) && p->kind == 0) {
    PlaySound_082406e0(SE_RUNNING_FOOTSTEPS);
  }

  switch (p->moveState) {
    case 0: {
      OpRunner_ConsumePauseFlag(p, 2);
      OpRunner_SyncSpritePos(p);
      break;
    }
    case 1: {
      OpRunner_ConsumePauseFlag(p, 2);
      if (OpRunner_MoveToTarget(p)) {
        OpRunner_SetMoveState(p, 0);
        if (p->arrivalScript != 0) {
          VM_ExecByID(p->arrivalScript, NULL);
        }
      }
      break;
    }
  }

  if (p->scaleTimer > 0) {
    scale = Div(p->scaleFrom * p->scaleTimer + p->scaleTo * (p->scaleFrames - p->scaleTimer), p->scaleFrames);
    p->scaleTimer--;
  } else {
    scale = p->scaleTo;
  }

  if (p->kind == 0) {
    MainSprite_AdvanceAnim(&p->django, &p->djangoGfx);
    p->django.scaleX = scale;
    p->django.scaleY = scale;
  } else {
    AuxSprite_AdvanceAnim(&p->otenko, &p->otenkoAnim);
    p->otenko.scaleX = scale;
    p->otenko.scaleY = scale;
  }

  shadow = &p->shadow;
  shadow->pos.x = FixToInt(16, p->posX);
  shadow->pos.y = FixToInt(16, p->posY);
  shadowScale = Div(scale * 3, 4);
  shadow->scaleX = shadowScale;
  shadow->scaleY = shadowScale;
  if (shadow->flags & SPRFLAG_HIDDEN) {
    AuxSprite_Show(shadow);
  } else {
    AuxSprite_Hide(shadow);
  }
}

// val 番の処理へ切り替えて移動も止める (このゲームでは val は 0 固定)
void OpRunner_SetState(OpRunner* p, s32 val) {
  static void (*const sOpRunnerUpdates[1])(OpRunner*) = {
      OpRunner_UpdateRun,
  };  // 0x085AFFA4

  p->state = val;
  p->stateTimer = 0;
  p->updateCallback = sOpRunnerUpdates[val];
  SET_FLAGS(p->pauseFlags, 1);
  OpRunner_SetMoveState(p, 0);
}

// 本体 (ジャンゴかおてんこ) と影のスプライトを posX/posY に追加する
void OpRunner_AddSprites(OpRunner* p) {
  s32 x = FixToInt(16, p->posX);
  s32 y = FixToInt(16, p->posY);
  s32 scale = p->scaleFrom;
  s32 idx = p->kind;
  s32 subScale;

  if (idx == 0) {
    MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPR_DJANGO_SABATA);
    MainSprite* sprite;
    Vec3 pos;

    p->djangoGfx = *f;
    OpenMainSpriteFile(&p->djangoGfx, f);
    Vec3_Clear(&pos);
    sprite = &p->django;
    pos.x = x;
    pos.y = y;
    MainSprite_Add(sprite, &p->djangoGfx, 7, SPRFLAG_UNK_15 | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE, 1, PLAYMODE_PAUSE, 60, &pos);
    MainSprite_SetAnim(sprite, &p->djangoGfx, 5, PLAYMODE_LOOP, 0);
    sprite->scaleX = scale;
    sprite->scaleY = scale;
  } else {
    AuxAnimFile* files;

    Video_GetAuxSprite(&p->otenkoGfx, SPR_OTENKO_00);
    AuxSprite_Add(&p->otenko, &p->otenkoGfx, SPRFLAG_UNK_15 | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE);
    p->otenko.pos.x = x;
    p->otenko.pos.y = y;
    p->otenko.scaleX = scale;
    p->otenko.scaleY = scale;
    p->otenko.priority = 0;
    files = GetFile(DIR_ANIMATION, ANIM_OTENKO);
    p->otenkoAnimFile = files;
    AuxAnim_SetAnim(&p->otenkoAnim, files, 0, 0, 0);
  }

  Video_GetAuxSprite(&p->shadowGfx, SPR_EFF_1C1B);
  AuxSprite_Add(&p->shadow, &p->shadowGfx, SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE);
  AuxSprite_SetPoseIdx(&p->shadow, 5);
  p->shadow.pos.x = x;
  p->shadow.pos.y = y;
  subScale = Div(scale * 3, 4);
  p->shadow.scaleX = subScale;
  p->shadow.scaleY = subScale;
  p->shadow.priority = 2;
}

// スプライトを描画リストから外す
void OpRunner_RemoveSprites(OpRunner* p) {
  if (p->kind == 0) {
    MainSprite_Remove(&p->django);
  } else {
    AuxSprite_Remove(&p->otenko);
  }

  AuxSprite_Remove(&p->shadow);
}

s32 OpRunner_Update(OpRunner* p) {
  if (!(p->pauseFlags & 1)) {
    p->stateTimer++;
  }
  if (!(p->pauseFlags & 2)) {
    p->moveTimer++;
  }
  p->updateCallback(p);
  return 0;
}

// 描画を畳んで gOpRunners の登録枠を空ける
s32 OpRunner_Destroy(OpRunner* p) {
  OpRunner_RemoveSprites(p);
  gOpRunners[p->kind] = NULL;
  return 0;
}

s32 OpRunner_Init(OpRunner* p) {
  s32 scale;

  p->pauseFlags = 0;
  p->kind = VM_GetNamedArgValue('k', -1);
  if (VM_SeekToNamedArg('p')) {
    p->posX = VM_GetValue() << 16;
    p->posY = VM_GetValue() << 16;
  }
  if (VM_SeekToNamedArg('s')) {
    p->speed = VM_GetValue();
  }
  scale = VM_GetNamedArgValue('S', 64);
  p->state = 0;
  p->stateTimer = 0;
  p->moveState = 0;
  p->moveTimer = 0;
  p->speedScaleFrom = 64;
  p->speedScaleTo = 64;
  p->speedScaleFrames = 0;
  p->speedScaleTimer = 0;
  p->scaleFrom = scale;
  p->scaleTo = scale;
  p->scaleFrames = 0;
  p->scaleTimer = 0;
  OpRunner_AddSprites(p);
  OpRunner_SetState(p, 0);
  gOpRunners[p->kind] = p;
  return 0;
}

// 0x0FC5
OpRunner* OpRunner_Create(void) {
  OpRunner* p = CreateEntity(ENTITY_UNK_8, sizeof(OpRunner));

  if (p != NULL) {
    SetEntityRoutine(p, OpRunner_Update, OpRunner_Destroy);
    if (OpRunner_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
