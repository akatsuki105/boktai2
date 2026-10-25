#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

struct Mover;

// ノードの持ち主に用件を伝えるコールバック, 根拠: EntityF41A_OnMessage が Entity5941_Register の第3引数に渡る
typedef bool32 Entity5941Callback(struct Mover* owner, s32 msg, s32 value);

// gEntity5941 の単方向リストのノード, 敵は _Init で Entity5941_Register、_Destroy で Entity5941_Unregister を呼んで出入りする
typedef struct Entity5941Node {
  struct Mover* owner;          // 0x00, Entity5941_Register の第2引数 (敵の Mover)
  u32 flags;                    // 0x04, bit0 が落ちているノードだけ Entity5941_FindNearestInCone の対象になる
  Entity5941Callback* fn;       // 0x08, Entity5941_Register の第3引数
  struct Entity5941Node* next;  // 0x0C
} Entity5941Node;
static_assert(sizeof(Entity5941Node) == 16);

bool32 Entity5941_Register(Entity5941Node* node, void* owner, void* fn);
void Entity5941_Unregister(Entity5941Node* node);

// --------------------------------------------

// FUN_080155e4 に渡す粒子1種類ぶんの発生パラメータ
typedef struct {
  u16 kind;              // 0x00
  u16 flags;             // 0x02
  u16 unk_04;            // 0x04
  u16 animSpeed;         // 0x06
  u16 speedY;            // 0x08
  s16 speedYRand;        // 0x0A, speedY に加える乱数の幅
  u16 speedXZ;           // 0x0C
  s16 speedXZRand;       // 0x0E, speedXZ に加える乱数の幅
  u16 angleY;            // 0x10
  u16 angleYRand;        // 0x12
  u16 angleXZ;           // 0x14
  u16 angleXZRand;       // 0x16
  u16 decayStartY;       // 0x18
  u16 decayStartYRand;   // 0x1A
  u16 unk_1c;            // 0x1C
  u16 unk_1e;            // 0x1E
  u16 decayStartXZ;      // 0x20
  u16 decayStartXZRand;  // 0x22
  u16 unk_24;            // 0x24
  u16 unk_26;            // 0x26
} ParticleSpawnParam;
static_assert(sizeof(ParticleSpawnParam) == 40);

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
