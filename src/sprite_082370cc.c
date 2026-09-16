#include "global.h"
#include "sprite.h"

NAKED void FUN_082370cc(SpriteState* p, SpriteSet* data, u16 param_3, u16 param_4, u16 param_5) { INCFUNC("asm/func/FUN_082370cc.inc"); }

NAKED void FUN_082371ac(SpriteState* p, SpriteSet* data, u16 param_3, u16 param_4) { INCFUNC("asm/func/FUN_082371ac.inc"); }

NAKED s32 FUN_0823723c(SpriteState* p, u32 val) { INCFUNC("asm/func/FUN_0823723c.inc"); }

// 1コマの表示フレーム数を変更する。経過タイマーを新旧の比率で配分し直すので進行の割合は保たれる, リネーム案: Sprite_SetFrameDuration
bool32 FUN_082372ac(SpriteState* p, u16 val) {
  p->q_frameTimer = DivArm(p->q_frameDuration, val * p->q_frameTimer);
  p->q_frameDuration = val;
  return TRUE;
}

// スプライトのアニメーションを1フレーム分進める関数, リネーム案: Sprite_AdvanceAnim
NON_MATCH bool32 FUN_082372cc(SpriteState* p, SpriteSet* data) {
#ifdef NONMATCHING_C
  q_AnimFrame* frame;
  bool32 finished;
  u16 idx;
  s32 n;

  if (p->q_playMode == 0) {
    return FALSE;
  }
  finished = FALSE;
  p->q_animEvents = 0;
  if (p->q_frameTimer == 0) {
    frame = &p->q_frames[p->q_frameIdx];
    Sprite_SetSprite(p, data, frame->spriteIdx, p->q_playMode);
  }
  p->q_frameTimer++;
  if (p->q_frameTimer >= p->q_frameDuration) {
    if (p->q_animFlags & 2) {
      if (p->q_frameIdx == 0) {
        finished = TRUE;
      } else {
        p->q_frameIdx--;
      }
    } else {
      p->q_frameIdx++;
      if (p->q_frameIdx >= p->q_frameCount) {
        finished = TRUE;
        p->q_frameIdx = p->q_frameCount - 1;
      }
    }
    if (finished) {
      p->q_animEvents = 2 | p->q_animEvents;
      if (p->q_playMode == 2) {
        p->q_playMode = 0;
      } else if (p->q_playMode == 3) {
        p->q_playMode = 0;
        p->flags |= SPRFLAG_HIDDEN;
      } else {
        idx = p->q_animFlags & 2;
        if (idx != 0) {
          idx = p->q_frameCount - 1;
        }
        p->q_frameIdx = idx;
        p->q_animEvents = 4 | p->q_animEvents;
      }
    } else {
      p->q_animEvents = 4 | p->q_animEvents;
    }
    frame = &p->q_frames[p->q_frameIdx];
    p->q_frameTimer = 0;
    n = frame->duration * p->q_animSpeed;
    if (n >= 0) {
      n >>= 6;
    } else {
      n = -((-n) >> 6);
    }
    if ((p->q_frameDuration = n) == 0) {
      p->q_frameDuration = 1;
    }
  } else if (p->q_frameTimer + 1 >= p->q_frameDuration) {
    if (p->q_animFlags & 2) {
      if (p->q_frameIdx == 0) {
        p->q_animEvents |= 1;
      }
    } else if (p->q_frameIdx + 1 >= p->q_frameCount) {
      p->q_animEvents |= 1;
    }
  }
  return finished;
#else
  INCFUNC("asm/func/FUN_082372cc.inc");
#endif
}

NAKED unknown* FUN_082373e4(unknown* p, unknown* data, u32 val) { INCFUNC("asm/func/FUN_082373e4.inc"); }
