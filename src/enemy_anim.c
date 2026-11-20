#include "enemy.h"
#include "global.h"
#include "random.h"

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Enemy_PlayDirAnim(Enemy* p, u32 anim, u32 variant, u32 flags) {
  if (p->spriteKind == 0) {
    EnemyAuxSprite* s;

    p->playingAnim = anim;
    s = &p->s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &p->s->main.spr;
    s32 mode;

    anim += variant;
    if (p->playingAnim == anim && !p->animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    p->playingAnim = anim;
    mode = (flags & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&p->s->main.spr, &p->s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  p->animForceRestart = FALSE;
}

// 動作の種類ごとのアニメ番号を登録する
void Enemy_SetAnimEntry(Enemy* p, s32 idx, s32 anim, s32 val3) {
  p->animTable[idx].anim = anim;
  p->animTable[idx].unk_1 = val3;
}

// animTable[animIdx] のアニメを再生する, spriteKind で AuxSprite 系と MainSprite 系を呼び分ける
void Enemy_PlayAnim(Enemy* p, s32 animIdx) {
  u8 variant;
  AuxAnimPlayFlags flags;

  Enemy_SetAnimFacing(p, &variant, &flags);
  Enemy_PlayDirAnim(p, p->animTable[animIdx].anim, variant, flags | p->animTable[animIdx].unk_1);
}

// 向きに合わせて animTable[idx] のアニメを再生する, 引数の再生フラグを足す
void Enemy_PlayAnimFlags(Enemy* p, s32 val1, u32 val2) {
  u8 variant;
  AuxAnimPlayFlags flags;

  Enemy_SetAnimFacing(p, &variant, &flags);
  Enemy_PlayDirAnim(p, p->animTable[val1].anim, variant, flags | val2 | p->animTable[val1].unk_1);
}

// 向きは左右反転だけに反映して animTable[idx] のアニメを再生する, 引数の再生フラグを足す
void Enemy_PlayAnimFlipOnlyFlags(Enemy* p, s32 val1, u32 val2) {
  u8 variant;
  AuxAnimPlayFlags flags;

  Enemy_SetAnimFacing(p, &variant, &flags);
  Enemy_PlayDirAnim(p, p->animTable[val1].anim, 0, flags | val2 | p->animTable[val1].unk_1);
}

// 向きを反映せずに animTable[idx] のアニメを引数の再生フラグで再生する
void Enemy_PlayAnimNoFacingFlags(Enemy* p, s32 param_2, u32 param_3) { Enemy_PlayDirAnim(p, p->animTable[param_2].anim, 0, param_3 | p->animTable[param_2].unk_1); }

// 左右反転は向きから, 差分は variant で指定して animTable[idx] のアニメを再生する
void Enemy_PlayAnimWithVariant(Enemy* p, s32 param_2, s32 param_3) {
  u8 variant;
  AuxAnimPlayFlags flags;

  Enemy_SetAnimFacing(p, &variant, &flags);
  Enemy_PlayDirAnim(p, p->animTable[param_2].anim, param_3, flags | p->animTable[param_2].unk_1);
}

// 向きは左右反転だけに反映して animTable[idx] のアニメを再生する
void Enemy_PlayAnimFlipOnly(Enemy* p, s32 param_2) {
  u8 variant;
  AuxAnimPlayFlags flags;

  Enemy_SetAnimFacing(p, &variant, &flags);
  Enemy_PlayDirAnim(p, p->animTable[param_2].anim, 0, flags | p->animTable[param_2].unk_1);
}

// 向きを反映せずに animTable[idx] のアニメを再生する
void Enemy_PlayAnimNoFacing(Enemy* p, s32 param_2) { Enemy_PlayDirAnim(p, p->animTable[param_2].anim, 0, p->animTable[param_2].unk_1); }

// 201/198 命令, 下書き段階
NON_MATCH void Enemy_080eff14(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  u8* count;

  if (p->stateBegun) {
    p->stateBegun = FALSE;
    Enemy_PlayAnim(p, 0);
    p->flags3 |= 0x400;
    p->animSpeedDiv = 2;
  }

  count = &p->unk_542;
  if ((s8)*count <= 0) {
    *count = 0xFF;
    if (param_2 > 30) {
      p->stateBegun = TRUE;
      p->subStateDone = FALSE;
      p->state = p->savedState;
      p->handlerState = p->savedHandlerState;
      p->stateTimer = 0;
      p->subState0 = p->savedSubState0;
      p->subState1 = p->savedSubState1;
      p->subState2 = p->savedSubState2;
      p->subStateTimer = 0;
      p->subStateBegun = TRUE;
      p->flags3 &= ~0x400;
    }
  } else if (param_2 > 60) {
    p->subState0 = 3;
    p->subState1 = 1;
    p->subState2 = 0;
    p->subStateTimer = 0;
    p->subStateBegun = TRUE;
    p->stateBegun = TRUE;
    p->subStateDone = FALSE;
    p->state = 2;
    p->handlerState = p->handlerTurn;
    p->stateTimer = 0;
    if (*count == 1) {
      p->unk_1dc = ((p->lookBaseAngle >> 5) + 3) & 7;
    } else {
      s32 angle;
      s32 i;

      for (i = 0; i < 4; i++) {
        angle = (Random() & 3) * 64;
        if (angle != p->mover.angle) {
          break;
        }
        angle = p->mover.angle;
      }
      p->unk_1dc = ((angle >> 5) + 3) & 7;
    }
    (*count)--;
  }
#else
  INCFUNC("asm/func/Enemy_080eff14.inc");
#endif
}
