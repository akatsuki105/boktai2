#include "enemy.h"
#include "global.h"

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
    MainSprite_SetAnim(s, &p->sprite->gfx, a, 2, (f & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
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

NAKED void FUN_080ef968(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080ef968.inc"); }

NAKED void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080efa6c.inc"); }

NAKED void FUN_080efb60(Enemy* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080efb60.inc"); }

NAKED void FUN_080efc44(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080efc44.inc"); }

NAKED void FUN_080efd44(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efd44.inc"); }

NAKED void FUN_080efe38(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efe38.inc"); }

NAKED void Enemy_080eff14(Enemy* enemy, s32 param_2) { INCFUNC("asm/func/Enemy_080eff14.inc"); }
