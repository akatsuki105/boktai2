#include "animation.h"
#include "global.h"

// TODO: いろんな用途のデータが区別されてないのであとで分ける
IWRAM_DATA u8 u8_03000784[4] = {};

// 通信 (SIO マルチプレイ) の送受信リングバッファ
IWRAM_DATA s32 gSioRecvWriteIdx = 0;  // 0x03000788
IWRAM_DATA s32 gSioRecvReadIdx = 0;   // 0x0300078C
IWRAM_DATA s32 gSioRecvCount = 0;     // 0x03000790
IWRAM_DATA s32 gSioSendWriteIdx = 0;  // 0x03000794
IWRAM_DATA s32 gSioSendReadIdx = 0;   // 0x03000798
IWRAM_DATA s32 gSioSendCount = 0;     // 0x0300079C
IWRAM_DATA u8 gSioRecvBuf[64] = {};   // 0x030007A0
IWRAM_DATA u8 gSioSendBuf[64] = {};   // 0x030007E0

IWRAM_DATA u8 u8_03000820[0x030016A0 - 0x03000820] = {};

// アニメーションの再生を開始する。同じアニメを同じ向きで再生中なら flags だけ更新して FALSE を返す, リネーム案: Anim_Play
NON_MATCH bool32 FUN_08236fac(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags) {
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
  INCFUNC("asm/func/FUN_08236fac.inc");
#endif
}

// 同じアニメでも必ず先頭から再生し直す。cmdCount を 0 にして FUN_08236fac の「再生中なら再開しない」判定を外す, リネーム案: Anim_Restart
bool32 FUN_08237040(AuxAnimState* p, AuxAnimFile* files, u16 animIdx, u8 variant, AuxAnimPlayFlags flags) {
  p->cmdCount = 0;
  return FUN_08236fac(p, files, animIdx, variant, flags);
}

// 1コマの表示時間を変更する。経過 tick を新旧の比率で配分し直すので進行の割合は保たれる, リネーム案: Anim_SetWait
bool32 FUN_08237064(AuxAnimState* p, u16 val) {
  if (p->wait == 0) {
    p->wait = 1;
  }
  p->tick = DivArm(p->wait, val * p->tick);
  if ((p->wait = val) == 0) {
    p->wait = 1;
  }
  return TRUE;
}

// 再生速度を変更する (現在と同じ速度なら何もしない), リネーム案: Anim_SetSpeed
void FUN_08237098(AuxAnimState* p, u16 speed) {
  if (p->speed != speed) {
    if ((p->wait = (speed * p->duration) >> 6) == 0) {
      p->wait = 1;
    }
    p->speed = speed;
  }
}

// 再生速度を等速に戻す (wait は duration * 0x40 >> 6 = duration), リネーム案: Anim_ResetSpeed
void FUN_082370c0(AuxAnimState* p) {
  p->wait = p->duration;
  p->speed = 0x40;
}
