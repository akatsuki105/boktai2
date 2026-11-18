#ifndef __INCLUDE_ENEMY_DOG_H__
#define __INCLUDE_ENEMY_DOG_H__

#include "enemy.h"
#include "gba/gba.h"
#include "types.h"

// ENEK_DOG(EV_BANDIT, EV_GRAVEKEEPER, EV_HELLHOUND, EV_BANDIT_P)
typedef struct {
  Enemy e;
  u8 unk_654[4];      // 0x654
  Hitbox unk_658;     // 0x658, 2つ目の攻撃判定, atkPower[1] などの攻撃値を載せる
  u32 unk_6a8;        // 0x6A8, bit0 は待ちが明けたときに立てる
  u32 unk_6ac;        // 0x6AC, playerDistSq がこれ未満なら副状態 (0,2,0) へ
  u32 unk_6b0;        // 0x6B0, playerDistSq がこれ未満でほぼ正面なら副状態 (0,2,1) へ
  u32 unk_6b4;        // 0x6B4, プレイヤーとの距離の2乗がこれ未満なら飛びかかりに入る
  u32 unk_6b8;        // 0x6B8, playerDistSq と比べる距離の閾値, unk_6bc と対
  u32 unk_6bc;        // 0x6BC, playerDistSq がこれを超えると副状態 19 へ移る
  u16 unk_6c0;        // 0x6C0, 0 になるまで数え下ろし, 0 になると unk_6c2 か unk_6c4 から入れ直す
  u16 unk_6c2;        // 0x6C2
  u16 unk_6c4;        // 0x6C4, ENEFLAG3_UNK_7 のときの unk_6c2
  u16 unk_6c6;        // 0x6C6, 0 になるまで毎フレーム減る
  u16 unk_6c8;        // 0x6C8, 0 になるまで毎フレーム減る
  u16 unk_6ca;        // 0x6CA, 0 になるまで毎フレーム減る
  u16 unk_6cc;        // 0x6CC, unk_6c8 に入れ直す値
  u16 unk_6ce;        // 0x6CE, unk_6ca に入れ直す値
  s16 unk_6d0;        // 0x6D0, 負なら unk_6d2/unk_6d4 は無効
  s16 unk_6d2;        // 0x6D2
  s16 unk_6d4;        // 0x6D4
  u8 unk_6d6;         // 0x6D6
  u8 unk_6d7;         // 0x6D7
  u8 unk_6d8;         // 0x6D8, 0 になるまで毎フレーム減る
  u8 unk_6d9;         // 0x6D9, 盗んだ食べ物で回復する割合 (maxHp の %)
  u8 unk_6da[2];      // 0x6DA
  NavAgent navAgent;  // 0x6DC, Enemy.navAgent が指す
  Vec3 pathNodePos;   // 0x700, Enemy.pathNodePos が指す
  Vec3 unk_708;       // 0x708, 飛びかかる直前のプレイヤーの位置
} Dog;
static_assert(sizeof(Dog) == 1808);

#endif  // __INCLUDE_ENEMY_DOG_H__
