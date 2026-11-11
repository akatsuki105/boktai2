#ifndef __INCLUDE_PUFF_H__
#define __INCLUDE_PUFF_H__

#include "gba/gba.h"
#include "types.h"

// Puff_Spawn に渡す発生パラメータ, 玉の種類・速さ・向き・減速をそれぞれ基準値と乱数の幅で持つ
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
  u16 decayY;            // 0x1C, Puff.decayY に当たる値だが Puff_Spawn は読まない
  u16 decayYRand;        // 0x1E, decayY に加える乱数の幅, 同上
  u16 decayStartXZ;      // 0x20
  u16 decayStartXZRand;  // 0x22
  u16 decayXZ;           // 0x24, Puff.decayXZ に当たる値だが Puff_Spawn は読まない
  u16 decayXZRand;       // 0x26, decayXZ に加える乱数の幅, 同上
} PuffParam;
static_assert(sizeof(PuffParam) == 40);

s32 Puff_Spawn(s32 count, WorldPos* pos, PuffParam* params);
void Puff_SpawnSpray(s32 count, u32 kind, u32 flags, u32 animSpeed, WorldPos* pos);
void Puff_SpawnSprayEx(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos);
void Puff_SpawnSprayOne(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);
void Puff_SpawnRadial(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);
void Puff_SpawnHorizontal(WorldPos* pos, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);

#endif  // __INCLUDE_PUFF_H__
