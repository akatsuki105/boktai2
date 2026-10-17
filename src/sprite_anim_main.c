#include "global.h"
#include "sprite.h"

#define PLAYMODE_PAUSE 0           // 停止
#define PLAYMODE_ONCE_AND_STOP 2   // 1回再生して停止
#define PLAYMODE_PLAY_ONCE_HIDE 3  // 1回再生して非表示

NAKED void MainSprite_SetAnim(MainSprite* p, MainSpriteGfx* gfx, u16 animIdx, u16 playMode, MainAnimPlayFlags16 flags) { INCFUNC("asm/func/MainSprite_SetAnim.inc"); }

// 指定したアニメの cmdIdx 番目のコマに切り替え、表示時間と「次で終わる」通知を設定し直す
NON_MATCH void MainSprite_SetAnimFrame(MainSprite* p, MainSpriteGfx* gfx, u16 animIdx, u16 cmdIdx) {
#ifdef NONMATCHING_C
  MainAnim* table = gfx->anims;
  MainAnim* anim;
  MainAnimCmd* cmds;
  MainAnimCmd* cmd;
  s32 n;

  anim = table + animIdx;  // 元は adds r6, r2, r0 (添字が先), この形だと adds r6, r0, r2 になる
  cmds = (MainAnimCmd*)((u8*)gfx->cmds + anim->cmdOffset);
  p->animCmdIdx = cmdIdx;
  if (cmdIdx >= anim->cmdCount) {
    p->animCmdIdx = anim->cmdCount - 1;
  }
  cmd = &cmds[p->animCmdIdx];
  MainSprite_SetPose(p, gfx, cmd->poseIdx, p->playMode);
  p->animCmdLength = anim->cmdCount;
  n = cmd->duration * p->animSpeed;
  if (n >= 0) {
    n >>= FRACBITS_6;
  } else {
    n = -((-n) >> FRACBITS_6);
  }
  if ((p->animCmdDuration = n) == 0) {
    p->animCmdDuration = 1;
  }
  p->animCmdTimer = 0;
  p->animEvents = 0;
  if (p->animCmdTimer + 1 >= p->animCmdDuration) {
    if (p->animFlags & MAIN_ANIM_REVERSE) {
      if (p->animCmdIdx == 0) {
        p->animEvents = MAIN_ANIM_EVENT_WILL_END;
      }
    } else if (p->animCmdIdx + 1 >= p->animCmdLength) {
      p->animEvents = MAIN_ANIM_EVENT_WILL_END;
    }
  }
#else
  INCFUNC("asm/func/MainSprite_SetAnimFrame.inc");
#endif
}

// 再生速度を変え、現在のコマの表示時間と「次で終わる」通知を計算し直す
s32 MainSprite_SetAnimSpeed(MainSprite* p, u32 speed) {
  MainAnimCmd* cmd = &p->animCmds[p->animCmdIdx];
  s32 n;

  p->animSpeed = speed;
  n = cmd->duration * p->animSpeed;
  if (n >= 0) {
    n >>= FRACBITS_6;
  } else {
    n = -((-n) >> FRACBITS_6);
  }
  if ((p->animCmdDuration = n) == 0) {
    p->animCmdDuration = 1;
  }
  p->animEvents &= ~MAIN_ANIM_EVENT_WILL_END;
  if (p->animCmdTimer + 1 >= p->animCmdDuration) {
    if (p->animFlags & MAIN_ANIM_REVERSE) {
      if (p->animCmdIdx == 0) {
        p->animEvents |= MAIN_ANIM_EVENT_WILL_END;
      }
    } else if (p->animCmdIdx + 1 >= p->animCmdLength) {
      p->animEvents |= MAIN_ANIM_EVENT_WILL_END;
    }
  }
  return 0;
}

// 1コマの表示フレーム数を変更する, 経過タイマーを新旧の比率で配分し直すので進行の割合は保たれる
bool32 MainSprite_SetFrameDuration(MainSprite* p, u16 val) {
  p->animCmdTimer = DivArm(p->animCmdDuration, val * p->animCmdTimer);
  p->animCmdDuration = val;
  return TRUE;
}

// MainSprite のアニメーションを1フレーム分進める関数
NON_MATCH bool32 MainSprite_AdvanceAnim(MainSprite* p, MainSpriteGfx* gfx) {
#ifdef NONMATCHING_C
  MainAnimCmd* frame;
  bool32 finished;
  u16 idx;
  s32 n;

  if (p->playMode == PLAYMODE_PAUSE) {
    return FALSE;
  }
  finished = FALSE;
  p->animEvents = 0;
  if (p->animCmdTimer == 0) {
    frame = &p->animCmds[p->animCmdIdx];
    MainSprite_SetPose(p, gfx, frame->poseIdx, p->playMode);
  }
  p->animCmdTimer++;
  if (p->animCmdTimer >= p->animCmdDuration) {
    if (p->animFlags & MAIN_ANIM_REVERSE) {
      if (p->animCmdIdx == 0) {
        finished = TRUE;
      } else {
        p->animCmdIdx--;
      }
    } else {
      p->animCmdIdx++;
      if (p->animCmdIdx >= p->animCmdLength) {
        finished = TRUE;
        p->animCmdIdx = p->animCmdLength - 1;
      }
    }
    if (finished) {
      p->animEvents |= MAIN_ANIM_EVENT_ENDED;
      if (p->playMode == PLAYMODE_ONCE_AND_STOP) {
        p->playMode = PLAYMODE_PAUSE;
      } else if (p->playMode == PLAYMODE_PLAY_ONCE_HIDE) {
        p->playMode = PLAYMODE_PAUSE;
        p->flags |= SPRFLAG_HIDDEN;
      } else {
        idx = p->animFlags & MAIN_ANIM_REVERSE;
        if (idx != 0) {
          idx = p->animCmdLength - 1;
        }
        p->animCmdIdx = idx;
        p->animEvents |= MAIN_ANIM_EVENT_ADVANCED;
      }
    } else {
      p->animEvents |= MAIN_ANIM_EVENT_ADVANCED;
    }
    frame = &p->animCmds[p->animCmdIdx];
    p->animCmdTimer = 0;
    n = frame->duration * p->animSpeed;
    if (n >= 0) {
      n >>= FRACBITS_6;
    } else {
      n = -((-n) >> FRACBITS_6);
    }
    if ((p->animCmdDuration = n) == 0) {
      p->animCmdDuration = 1;
    }
  } else if (p->animCmdTimer + 1 >= p->animCmdDuration) {
    if (p->animFlags & MAIN_ANIM_REVERSE) {
      if (p->animCmdIdx == 0) {
        p->animEvents |= MAIN_ANIM_EVENT_WILL_END;
      }
    } else if (p->animCmdIdx + 1 >= p->animCmdLength) {
      p->animEvents |= MAIN_ANIM_EVENT_WILL_END;
    }
  }
  return finished;
#else
  INCFUNC("asm/func/MainSprite_AdvanceAnim.inc");
#endif
}

// アニメ animIdx の全コマの表示フレーム数の合計
// 残差1命令, 原典は anim を animIdx のレジスタ上で作って r4 を使わずに収める
NON_MATCH s32 UNUSED MainSprite_GetAnimDuration(MainSprite* _, MainSpriteGfx* gfx, u32 animIdx) {
#ifdef NONMATCHING_C
  MainAnim* anim = &gfx->anims[animIdx];
  MainAnimCmd* cmd = (MainAnimCmd*)((u8*)gfx->cmds + anim->cmdOffset);
  s32 total = 0;
  s32 i;

  for (i = 0; i < anim->cmdCount; i++) {
    total += cmd->duration;
    cmd++;
  }
  return total;
#else
  INCFUNC("asm/func/MainSprite_GetAnimDuration.inc");
#endif
}
