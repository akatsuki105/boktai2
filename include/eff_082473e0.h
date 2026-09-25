#ifndef __INCLUDE_EFF_082473E0_H__
#define __INCLUDE_EFF_082473E0_H__

#include "gba/gba.h"
#include "particle.h"
#include "sprite_aux.h"
#include "types.h"

struct Eff082473e0;

// Eff082473e0Emitter が抱える粒子1個ぶんの枠。4個を使い回す
typedef struct {
  u8 state;           // 0x00, 0: 空き, 1: 生存, 2: 消えかけ。PTR_ARRAY_08dbd818 などの添字になり、各 kind の更新関数を選ぶ
  u8 unk_1;           // 0x01, Eff082473e0Emitter_Reset が枠を全部リセットするとき 10 を書く
  u16 unk_2;          // 0x02, 出現時に 0 に戻るタイマ
  s16 unk_4;          // 0x04, FUN_082467d0 の第3引数
  u8 unk_6[2];        // 0x06, padding?
  Vec3 pos;           // 0x08, FUN_082467d0 の第4引数が指す8バイトをそのまま写す
  Particle ptcl;      // 0x10, FUN_0822d9f0 / Particle_SetOffset / Particle_Remove に渡る
  AuxAnimState anim;  // 0x38, FUN_08236fac に Eff082473e0.anim と一緒に渡る
} Eff082473e0Particle;
static_assert(sizeof(Eff082473e0Particle) == 72);

// ワールド座標を1つ追いかけて、画面座標系の粒子を最大4個出すエミッタ。SolarSensorEntity が毎フレーム駆動する, 持ち主は (今のところ) Player (0x4C4) と Generator (0x100) の2つ
typedef struct Eff082473e0Emitter {
  bool8 isRegistered;                                               // 0x000, Eff082473e0Emitter_Register が 1 にし、Eff082473e0Emitter_Unregister が 0 に戻す。既にその状態なら両者とも -1 を返す
  u8 kind;                                                          // 0x001, 0..3。FUN_082467d0 がこれで fn_12c と アニメ番号 を選ぶ
  u8 activeCount;                                                   // 0x002, 埋まっている枠の数。FUN_082467d0 は 3 を超えると -1 を返す
  u8 unk_3;                                                         // 0x003, activeCount と一緒に増える別のカウンタ
  u8 unk_4;                                                         // 0x004, Eff082473e0Emitter_Init の第4引数
  u8 unk_5;                                                         // 0x005, Eff082473e0Emitter_Init の第5引数
  u8 unk_6[2];                                                      // 0x006, padding?
  Vec3* pos;                                                        // 0x008, 追いかけるワールド座標。Eff082473e0Emitter_Init の第2引数 (Generator は &sprite.pos を渡す)
  Eff082473e0Particle ptcls[4];                                     // 0x00C
  void (*fn_12c)(struct Eff082473e0*, struct Eff082473e0Emitter*);  // 0x12C, Eff082473e0_Update(0x0824736c) で実行
  struct Eff082473e0Emitter* prev;                                  // 0x130, Eff082473e0.emitters を先頭とする双方向リスト
  struct Eff082473e0Emitter* next;                                  // 0x134
} Eff082473e0Emitter;
static_assert(sizeof(Eff082473e0Emitter) == 312);

#endif  // __INCLUDE_EFF_082473E0_H__
