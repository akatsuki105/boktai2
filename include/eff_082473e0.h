#ifndef __INCLUDE_EFF_082473E0_H__
#define __INCLUDE_EFF_082473E0_H__

#include "gba/gba.h"
#include "particle.h"
#include "sprite_aux.h"
#include "types.h"

struct Eff082473e0;

// SSEEmitter が抱える粒子1個ぶんの枠。4個を使い回す
typedef struct {
  u8 state;           // 0x00, 0: 空き, 1: 生存, 2: 消えかけ。PTR_ARRAY_08dbd818 などの添字になり、各 kind の更新関数を選ぶ
  u8 unk_1;           // 0x01, SSEEmitter_Reset が枠を全部リセットするとき 10 を書く
  u16 unk_2;          // 0x02, 出現時に 0 に戻るタイマ
  s16 unk_4;          // 0x04, FUN_082467d0 の第3引数
  u8 unk_6[2];        // 0x06, padding?
  Vec3 pos;           // 0x08, FUN_082467d0 の第4引数が指す8バイトをそのまま写す
  Particle ptcl;      // 0x10, FUN_0822d9f0 / Particle_SetOffset / Particle_Remove に渡る
  AuxAnimState anim;  // 0x38, FUN_08236fac に Eff082473e0.anim と一緒に渡る
} SSEEmitterParticle;
static_assert(sizeof(SSEEmitterParticle) == 72);

// ワールド座標を1つ追いかけて、画面座標系の粒子を最大4個出すエミッタ。SolarSensorEntity が毎フレーム駆動する, 持ち主は (今のところ) Player (0x4C4) と Generator (0x100) の2つ
typedef struct SSEEmitter {
  bool8 isRegistered;                                       // 0x000, SSEEmitter_Register が 1 にし、SSEEmitter_Unregister が 0 に戻す。既にその状態なら両者とも -1 を返す
  u8 kind;                                                  // 0x001, 0..3。FUN_082467d0 がこれで fn_12c と アニメ番号 を選ぶ
  u8 activeCount;                                           // 0x002, 埋まっている枠の数。FUN_082467d0 は 3 を超えると -1 を返す
  u8 unk_3;                                                 // 0x003, activeCount と一緒に増える別のカウンタ
  u8 unk_4;                                                 // 0x004, SSEEmitter_Init の第4引数
  u8 unk_5;                                                 // 0x005, SSEEmitter_Init の第5引数
  u8 unk_6[2];                                              // 0x006, padding?
  Vec3* pos;                                                // 0x008, 追いかけるワールド座標。SSEEmitter_Init の第2引数 (Generator は &sprite.pos を渡す)
  SSEEmitterParticle ptcls[4];                              // 0x00C
  void (*fn_12c)(struct Eff082473e0*, struct SSEEmitter*);  // 0x12C, SSE_Update(0x0824736c) で実行
  struct SSEEmitter* prev;                                  // 0x130, Eff082473e0.emitters を先頭とする双方向リスト
  struct SSEEmitter* next;                                  // 0x134
} SSEEmitter;
static_assert(sizeof(SSEEmitter) == 312);

#endif  // __INCLUDE_EFF_082473E0_H__
