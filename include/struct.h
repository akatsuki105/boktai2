#ifndef __INCLUDE_STRUCT_H__
#define __INCLUDE_STRUCT_H__

#include "gba/gba.h"
#include "types.h"

// 用途不明の構造体　はここに置いておく

// --------------------------------------------

// Entity08015584_Spawn に渡す粒子1種類ぶんの発生パラメータ
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
  u16 decayY;            // 0x1C, Elem.decayY に当たる値だが Entity08015584_Spawn は読まない
  u16 decayYRand;        // 0x1E, decayY に加える乱数の幅, 同上
  u16 decayStartXZ;      // 0x20
  u16 decayStartXZRand;  // 0x22
  u16 decayXZ;           // 0x24, Elem.decayXZ に当たる値だが Entity08015584_Spawn は読まない
  u16 decayXZRand;       // 0x26, decayXZ に加える乱数の幅, 同上
} ParticleSpawnParam;
static_assert(sizeof(ParticleSpawnParam) == 40);

s32 Entity08015584_Spawn(s32 count, WorldPos* pos, ParticleSpawnParam* params);

// --------------------------------------------

#endif  // __INCLUDE_STRUCT_H__
