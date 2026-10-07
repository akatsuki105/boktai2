#include "global.h"
#include "sprite_aux.h"

// アニメーションの再生を開始する, 同じアニメを同じ向きで再生中なら flags だけ更新して FALSE を返す
NON_MATCH bool32 AuxAnim_SetAnim(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags) {
#ifdef NONMATCHING_C
  AuxAnim* a;
  AuxAnimCmd cmd;
  s32 idx;

  a = &((AuxAnim*)files->body)[animIdx];
  p->cmds = (AuxAnimCmd*)((u8*)files + a->cmdOffset) + variant * a->cmdCount;
  p->speed = 0x40;
  if (p->animIdx == animIdx && p->cmdCount != 0) {
    if (flags & ANIM_PLAY_REVERSE) {
      if (p->flags & ANIM_PLAY_REVERSE) {
        goto playing;
      }
    } else if (!(p->flags & ANIM_PLAY_REVERSE)) {
      goto playing;
    }
  }
  p->cmdCount = a->cmdCount;
  idx = (u8)(flags & ANIM_PLAY_REVERSE);
  if (idx != 0) {
    idx = p->cmdCount - 1;
  }
  p->cmdIdx = idx;
  cmd = p->cmds[p->cmdIdx];
  p->wait = p->duration = cmd & 0xF;
  p->tick = 0;
  p->animIdx = animIdx;
  p->flags = flags;
  return TRUE;

playing:
  p->flags = flags;
  return FALSE;
#else
  INCFUNC("asm/func/AuxAnim_SetAnim.inc");
#endif
}

// 同じアニメでも必ず先頭から再生し直す, cmdCount を 0 にして AuxAnim_SetAnim の「再生中なら再開しない」判定を外す
bool32 AuxAnim_RestartAnim(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags) {
  p->cmdCount = 0;
  return AuxAnim_SetAnim(p, files, animIdx, variant, flags);
}

// 1コマの表示時間を変更する, 経過 tick を新旧の比率で配分し直すので進行の割合は保たれる
bool32 AuxAnim_SetFrameDuration(AuxAnimState* p, u16 val) {
  if (p->wait == 0) {
    p->wait = 1;
  }
  p->tick = DivArm(p->wait, val * p->tick);
  if ((p->wait = val) == 0) {
    p->wait = 1;
  }
  return TRUE;
}

// 再生速度を変更する (現在と同じ速度なら何もしない)
void AuxAnim_SetAnimSpeed(AuxAnimState* p, u16 speed) {
  if (p->speed != speed) {
    if ((p->wait = (speed * p->duration) >> 6) == 0) {
      p->wait = 1;
    }
    p->speed = speed;
  }
}

// 再生速度を等速に戻す (wait は duration * 0x40 >> 6 = duration)
void AuxAnim_ResetAnimSpeed(AuxAnimState* p) {
  p->wait = p->duration;
  p->speed = 0x40;
}
