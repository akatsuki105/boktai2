#include "enemy.h"
#include "global.h"
#include "random.h"

// 動作の種類ごとのアニメ番号を登録する
void Enemy_SetAnimEntry(Enemy* p, s32 idx, s32 anim, s32 val3) {
  p->animTable[idx].anim = anim;
  p->animTable[idx].unk_1 = val3;
}

// animTable[animIdx] のアニメを再生する, spriteKind で AuxSprite 系と MainSprite 系を呼び分ける
// 残差4命令, 原典は定数 4 (ANIM_PLAY_REVERSE と SPRFLAG_XFLIP が同値) を MainSprite_SetAnim の呼び出しをまたいで r8 に退避するが, こちらは呼び出し後に作り直すので r8 の退避/復帰が出ない
// Tier A-B 試済: EnemyAnimEntry* のローカル経由 / anim と f の計算順の入れ替え / MainSprite_SetFlags 経由のフラグ操作
NON_MATCH void Enemy_PlayAnim(Enemy* p, s32 animIdx) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 anim;
  s32 f;

  Enemy_SetAnimFacing(p, &variant, &flags);
  anim = p->animTable[animIdx].anim;
  f = flags | p->animTable[animIdx].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim + variant;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    MainSprite_SetAnim(s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
    if (f & ANIM_PLAY_XFLIP) {
      MainSprite_SetFlags(s, SPRFLAG_XFLIP);
    } else {
      MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnim.inc");
#endif
}

// 向きに合わせて animTable[idx] のアニメを再生する, 引数の再生フラグを足す
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimFlags(Enemy* p, s32 val1, u32 val2) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 anim;
  s32 f;

  Enemy_SetAnimFacing(p, &variant, &flags);
  anim = p->animTable[val1].anim;
  f = flags | val2 | p->animTable[val1].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim + variant;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimFlags.inc");
#endif
}

// 向きは左右反転だけに反映して animTable[idx] のアニメを再生する, 引数の再生フラグを足す
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimFlipOnlyFlags(Enemy* p, s32 val1, u32 val2) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 anim;
  s32 f;

  Enemy_SetAnimFacing(p, &variant, &flags);
  anim = p->animTable[val1].anim;
  f = flags | val2 | p->animTable[val1].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimFlipOnlyFlags.inc");
#endif
}

// 向きを反映せずに animTable[idx] のアニメを引数の再生フラグで再生する
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimNoFacingFlags(Enemy* p, s32 param_2, u32 param_3) {
#ifdef NONMATCHING_C
  s32 anim;
  s32 f;

  anim = p->animTable[param_2].anim;
  f = param_3 | p->animTable[param_2].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimNoFacingFlags.inc");
#endif
}

// 左右反転は向きから, 差分は variant で指定して animTable[idx] のアニメを再生する
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimWithVariant(Enemy* p, s32 param_2, s32 param_3) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 anim;
  s32 f;

  Enemy_SetAnimFacing(p, &variant, &flags);
  anim = p->animTable[param_2].anim;
  f = flags | p->animTable[param_2].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, param_3, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim + param_3;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimWithVariant.inc");
#endif
}

// 向きは左右反転だけに反映して animTable[idx] のアニメを再生する
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimFlipOnly(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  u8 variant;
  AuxAnimPlayFlags flags;
  s32 anim;
  s32 f;

  Enemy_SetAnimFacing(p, &variant, &flags);
  anim = p->animTable[param_2].anim;
  f = flags | p->animTable[param_2].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimFlipOnly.inc");
#endif
}

// 向きを反映せずに animTable[idx] のアニメを再生する
// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void Enemy_PlayAnimNoFacing(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  s32 anim;
  s32 f;

  anim = p->animTable[param_2].anim;
  f = p->animTable[param_2].unk_1;
  if (p->spriteKind == 0) {
    EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)p->sprite;

    p->playingAnim = anim;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, f);
  } else {
    MainSprite* s = &p->sprite->s;
    s32 a = anim;
    s32 mode;

    if (p->playingAnim == a && p->animForceRestart == 0) {
      if (f == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
        return;
      }
      if (f == 0 && !(s->flags & SPRFLAG_XFLIP)) {
        return;
      }
    }

    p->playingAnim = a;
    mode = MAIN_ANIM_FORCE_POSE;
    if (f & ANIM_PLAY_REVERSE) {
      mode = MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE;
    }
    MainSprite_SetAnim(&p->sprite->s, &p->sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, mode);
    if (f & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }

  p->animForceRestart = 0;
#else
  INCFUNC("asm/func/Enemy_PlayAnimNoFacing.inc");
#endif
}

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
      p->state = p->unk_54f;
      p->handlerState = p->unk_548;
      p->stateTimer = 0;
      p->subState0 = p->unk_54c;
      p->subState1 = p->unk_54d;
      p->subState2 = p->unk_54e;
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
    p->handlerState = p->unk_590;
    p->stateTimer = 0;
    if (*count == 1) {
      p->unk_1dc = ((p->unk_541 >> 5) + 3) & 7;
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
