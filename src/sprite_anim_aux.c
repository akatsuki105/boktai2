#include "global.h"
#include "sprite_aux.h"

// アニメーションの再生を開始する, 同じアニメを同じ向きで再生中なら flags だけ更新して FALSE を返す
// 残差3箇所 (74/74 命令): p->cmds の加算で原典は結果を積の側 (r0) に置く, cmds[cmdIdx] は原典が添字を先に作って ldrh で読み (直接 & 0xF だと ldrb), tick の 0 を duration の格納より先に作る
// Tier A は試済 (ポインタ経由の読み, 値を返す inline, sizeof を掛けたバイト加算), 分岐形は向きの違いを && / || で並べた条件で一致 (三項演算子や != 比較だと分岐の向きが変わる)
NON_MATCH bool32 AuxAnim_SetAnim(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags) {
#ifdef NONMATCHING_C
  AuxAnim* a;
  AuxAnimCmd cmd;
  s32 idx;

  a = &((AuxAnim*)files->body)[animIdx];
  p->cmds = (AuxAnimCmd*)((u8*)files + a->cmdOffset) + variant * a->cmdCount;
  p->speed = 0x40;
  if (p->animIdx != animIdx || p->cmdCount == 0 || ((flags & ANIM_PLAY_REVERSE) && !(p->flags & ANIM_PLAY_REVERSE)) || (!(flags & ANIM_PLAY_REVERSE) && (p->flags & ANIM_PLAY_REVERSE))) {
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
  }
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
  p->wait = val;
  if (p->wait == 0) {
    p->wait = 1;
  }
  return TRUE;
}

// 再生速度を変更する (現在と同じ速度なら何もしない)
void AuxAnim_SetAnimSpeed(AuxAnimState* p, u16 speed) {
  if (p->speed != speed) {
    p->wait = (speed * p->duration) >> 6;
    if (p->wait == 0) p->wait = 1;
    p->speed = speed;
  }
}

// 再生速度を等速に戻す
void AuxAnim_ResetAnimSpeed(AuxAnimState* p) {
  p->wait = p->duration;
  p->speed = Q6(1);
}
