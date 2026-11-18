#ifndef __INCLUDE_ENEMY_GOLEM_H__
#define __INCLUDE_ENEMY_GOLEM_H__

#include "enemy.h"
#include "gba/gba.h"
#include "types.h"

// Golem.flags (0x65C)
typedef u32 GolemFlags;
#define GOLEMFLAG_UNK_11 (1 << 11)        // 0x00000800, 立っていると次の転がり始めの溜めを省く
#define GOLEMFLAG_TARGET_FIXED (1 << 19)  // 0x00080000, Golem_SetTargetTile で目標を決めた印, 立っている間はプレイヤーの位置で上書きしない

// ENEK_GOLEM (EV_GOLEM_C, EV_GOLEM_S, EV_GOLEM_2, EV_GOLEM_P, EV_GOLEM_4, EV_GOLEM_5)
// 転がって攻撃するが, 壁やゴーレム同士で激突するとダメージを受け気絶する
typedef struct {
  Enemy e;
  u8 unk_654[4];      // 0x654
  u8 unk_658;         // 0x658
  u8 playRollSound;   // 0x659, 1 なら止まっている状態から転がり出すときに音を鳴らす
  u16 unk_65a;        // 0x65A
  GolemFlags flags;   // 0x65C, see GolemFlags
  u32 unk_660;        // 0x660
  u8 unk_664[4];      // 0x664
  u16 rollHitID;      // 0x668, 転がりで当てた相手の Hitbox.id, 突進の終わりに hitTargetID へ渡す
  u8 unk_66a[2];      // 0x66A
  NavAgent navAgent;  // 0x66C, Enemy.navAgent が指す
  Vec3 pathNodePos;   // 0x690, Enemy.pathNodePos が指す
  u8 unk_698[16];     // 0x698
  Vec3 unk_6a8;       // 0x6A8
  u32 unk_6b0;        // 0x6B0
  s16 rollTime;       // 0x6B4, 転がり続けられる残り, 1区間ごとに 30 減り尽きたら丸まりを解く
  s16 speed;          // 0x6B6, 転がる速さ, variant ごとの上限まで加速する (階段の上では上限も加速も下がる)
  u16 stopAnimSpeed;  // 0x6B8, 止まる間のアニメの速さ, animSpeedDiv はこの 1/128
  u16 rollFrames;     // 0x6BA, Golem_SubRoll で転がっているフレーム数
  u16 chargeGauge;    // 0x6BC, プレイヤーに近いほど貯まる (上限 400), クレイは 400, ほかは 200 で突進に移る
  u16 windUpTime;     // 0x6BE, 転がり始めの溜めの長さ, variant ごとに乱数で決まる
  u8 facing;          // 0x6C0, mover.angle の4方向
  u8 stopPhase;       // 0x6C1, Golem_StateStopAtTile の段階, 0: 減速 1: タイルの中心へ寄せる 2: 止まって待つ
  u8 moveAngle;       // 0x6C2, x か z の軸に揃えた進む向き
  u8 stopTimer;       // 0x6C3, 減速して止まってからのフレーム数
  u8 prevMoveAngle;   // 0x6C4, 前のフレームの moveAngle
  u8 rollAngle;       // 0x6C5, 転がる向き, 減速中もこの向きに滑る
  u8 unk_6c6;         // 0x6C6
  u8 unk_6c7;         // 0x6C7
  Vec3 targetPos;     // 0x6C8, 向かう先のタイルの中心
  Vec3 routeDest;     // 0x6D0, Golem_RouteTo で経路を引く先
  Vec3 unk_6d8;       // 0x6D8
  u16 shakePower;     // 0x6E0, Camera_Shake の強さ
  u16 shakeTimer;     // 0x6E2, 0 でない間毎フレーム画面を揺らして減る
} Golem;
static_assert(sizeof(Golem) == 1764);

#endif  // __INCLUDE_ENEMY_GOLEM_H__
