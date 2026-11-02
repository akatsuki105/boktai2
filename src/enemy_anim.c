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

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080ef968(Enemy* p, s32 val1, u32 val2) {
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
  INCFUNC("asm/func/FUN_080ef968.inc");
#endif
}

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) {
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
  INCFUNC("asm/func/FUN_080efa6c.inc");
#endif
}

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080efb60(Enemy* p, s32 param_2, u32 param_3) {
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
  INCFUNC("asm/func/FUN_080efb60.inc");
#endif
}

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080efc44(Enemy* p, s32 param_2, s32 param_3) {
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
  INCFUNC("asm/func/FUN_080efc44.inc");
#endif
}

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080efd44(Enemy* p, s32 param_2) {
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
  INCFUNC("asm/func/FUN_080efd44.inc");
#endif
}

// Enemy_PlayAnim と同じ下書き, animTable の読み順と r8 の持ち方が残差
NON_MATCH void FUN_080efe38(Enemy* p, s32 param_2) {
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
  INCFUNC("asm/func/FUN_080efe38.inc");
#endif
}

// 201/198 命令, 下書き段階
NON_MATCH void Enemy_080eff14(Enemy* enemy, s32 param_2) {
#ifdef NONMATCHING_C
  u8* count;

  if (enemy->stateBegun) {
    enemy->stateBegun = FALSE;
    Enemy_PlayAnim(enemy, 0);
    enemy->flags3 |= 0x400;
    enemy->animSpeedDiv = 2;
  }

  count = &enemy->unk_542;
  if ((s8)*count <= 0) {
    *count = 0xFF;
    if (param_2 > 30) {
      enemy->stateBegun = TRUE;
      enemy->subStateDone = FALSE;
      enemy->state = enemy->unk_54f;
      enemy->handlerState = enemy->unk_548;
      enemy->stateTimer = 0;
      enemy->subState0 = enemy->unk_54c;
      enemy->subState1 = enemy->unk_54d;
      enemy->subState2 = enemy->unk_54e;
      enemy->subStateTimer = 0;
      enemy->subStateBegun = TRUE;
      enemy->flags3 &= ~0x400;
    }
  } else if (param_2 > 60) {
    enemy->subState0 = 3;
    enemy->subState1 = 1;
    enemy->subState2 = 0;
    enemy->subStateTimer = 0;
    enemy->subStateBegun = TRUE;
    enemy->stateBegun = TRUE;
    enemy->subStateDone = FALSE;
    enemy->state = 2;
    enemy->handlerState = enemy->unk_590;
    enemy->stateTimer = 0;
    if (*count == 1) {
      enemy->unk_1dc = ((enemy->unk_541 >> 5) + 3) & 7;
    } else {
      s32 angle;
      s32 i;

      for (i = 0; i < 4; i++) {
        angle = (Random() & 3) * 64;
        if (angle != enemy->mover.angle) {
          break;
        }
        angle = enemy->mover.angle;
      }
      enemy->unk_1dc = ((angle >> 5) + 3) & 7;
    }
    (*count)--;
  }
#else
  INCFUNC("asm/func/Enemy_080eff14.inc");
#endif
}
