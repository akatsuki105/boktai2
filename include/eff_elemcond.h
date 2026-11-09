#ifndef __INCLUDE_EFF_082473E0_H__
#define __INCLUDE_EFF_082473E0_H__

#include "gba/gba.h"
#include "particle.h"
#include "sprite_aux.h"
#include "types.h"

typedef enum {
  ELEMCOND_NONE = 0,
  ELEMCOND_INKA = 1,     // "インカ", 引火, 一定時間ごとに10ダメージを受ける, レバガチャで解除可能
  ELEMCOND_HYOKETU = 2,  // "ヒョウケツ", 氷結, 動きが鈍くなる, レバガチャで解除可能
  ELEMCOND_SEKIKA = 3,   // "セキカ", 石化, 動きが止まる, レバガチャで解除可能
} ElemCondKind;

struct ElementalCondEffect;

// ElementalCondEmitter が抱える粒子1個ぶんの枠, 4個を使い回す
typedef struct {
  u8 state;           // 0x00, 0: 空き, 1: 生存, 2: 消えかけ, sBurningParticleUpdates などの添字になり、各 kind の更新関数を選ぶ
  u8 blinkInterval;   // 0x01, 消えかけの点滅間隔, 10 から点滅のたびに減り, 0 で枠が空く
  u16 timer;          // 0x02, 埋まっている間毎フレーム増える, 出現時と点滅のたびに 0 に戻る
  s16 lifetime;       // 0x04, 生存中の残りフレーム数, 0 になると消えかけに移る (Player は 3600)
  u8 unk_6[2];        // 0x06, padding?
  Vec3 pos;           // 0x08, ElementalCondEmitter_AddParticle の第4引数が指す8バイトをそのまま写す
  Particle ptcl;      // 0x10, Particle_Add / Particle_SetOffset / Particle_Remove に渡る
  AuxAnimState anim;  // 0x38, AuxAnim_SetAnim に ElementalCondEffect.anim と一緒に渡る
} ElementalCondParticle;
static_assert(sizeof(ElementalCondParticle) == 72);

// 状態異常 (引火, 氷結, 石化) にかかった持ち主のワールド座標を追いかけて、画面座標系の粒子を最大4個出すエミッタ, ElementalCondEffect が毎フレーム駆動する, 持ち主は Player, Enemy, Generator
typedef struct ElementalCondEmitter {
  bool8 isRegistered;                                                         // 0x000, ElementalCondEmitter_Register が 1 にし、ElementalCondEmitter_Unregister が 0 に戻す, 既にその状態なら両者とも -1 を返す
  u8 kind;                                                                    // 0x001, see ElemCondKind
  u8 activeCount;                                                             // 0x002, 埋まっている枠の数, ElementalCondEmitter_AddParticle は 3 を超えると -1 を返す
  u8 aliveCount;                                                              // 0x003, 消えかけでない枠の数, 0 ならかかっていない
  u8 unk_4;                                                                   // 0x004, ElementalCondEmitter_Init の第4引数
  u8 unk_5;                                                                   // 0x005, ElementalCondEmitter_Init の第5引数
  u8 unk_6[2];                                                                // 0x006, padding?
  WorldPos* pos;                                                              // 0x008, 追いかけるワールド座標, ElementalCondEmitter_Init の第2引数 (Generator は &sprite.pos を渡す)
  ElementalCondParticle ptcls[4];                                             // 0x00C
  void (*update)(struct ElementalCondEffect*, struct ElementalCondEmitter*);  // 0x12C
  struct ElementalCondEmitter* prev;                                          // 0x130, ElementalCondEffect.emitters を先頭とする双方向リスト
  struct ElementalCondEmitter* next;                                          // 0x134
} ElementalCondEmitter;
static_assert(sizeof(ElementalCondEmitter) == 312);

missing ElementalCondEmitter_Reset(ElementalCondEmitter* e);
s32 ElementalCondEmitter_Init(ElementalCondEmitter* e, Vec3* pos, s32 kind, s32 unk_4, s32 unk_5);
s32 ElementalCondEmitter_FadeParticle(ElementalCondEmitter* e);
s32 ElementalCondEmitter_BurstParticle(ElementalCondEmitter* e, s32 count, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
s32 ElementalCondEmitter_Destroy(ElementalCondEmitter* e);
s32 ElementalCondEmitter_AddParticle(ElementalCondEmitter* e, u32 kind, u32 param_3, Vec3* spread);

#endif  // __INCLUDE_EFF_082473E0_H__
