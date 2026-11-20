#ifndef __INCLUDE_ENEMY_BOKU_H__
#define __INCLUDE_ENEMY_BOKU_H__

#include "enemy.h"
#include "gba/gba.h"
#include "types.h"

// ENEK_BOKU (EV_GHOUL, EV_ZOMBIE, EV_GHOUL_P)
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u16 delayedScriptID;        // 0x658, '.x[0]', 0 でなければ delayedScriptTimer が delayedScriptWait に届いたときに実行する
  u8 delayedScriptWait;       // 0x65A, '.x[1]', delayedScriptID を実行するまでのフレーム数
  u8 delayedScriptTimer;      // 0x65B, 毎フレーム +1
  u16 unk_65c;                // 0x65C
  u16 unk_65e;                // 0x65E
  WorldPos unk_660;           // 0x660
  Vec3 unk_668;               // 0x668
  u16 timer_670;              // 0x670, FUN_080ffd28 が毎フレーム 1 減らす, 0 になるまで FUN_080ff270 が状態ハンドラを呼ばない
  u16 unk_672;                // 0x672, '.P[2]=120', FUN_080ff470 が timer_670 の初期値として写す
  u8 unk_674;                 // 0x674, '.P[0]=120'
  u8 unk_675[0x67C - 0x675];  // 0x675
  u16 unk_67c;                // 0x67C
  u16 unk_67e;                // 0x67E, '.P[1]=120'
  NavAgent navAgent;          // 0x680, Enemy.navAgent が指す
  Vec3 pathNodePos;           // 0x6A4, Enemy.pathNodePos が指す
} Boku;
static_assert(sizeof(Boku) == 1708);

#endif  // __INCLUDE_ENEMY_BOKU_H__
