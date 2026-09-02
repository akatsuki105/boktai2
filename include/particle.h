#ifndef __INCLUDE_PARTICLE_H__
#define __INCLUDE_PARTICLE_H__

#include "gba/gba.h"

// ParticleFile の長さは .tileCount と .groupCount に依存するが、 boktai2 では ParticleFile が 1つしかないので、固定値で定義している

#define PARTICLE_TILE_SIZE 317  // = ParticleFile.tileCount

#define PTCL_GROUP_COUNT 3  // = ParticleFile.groupCount

// Particle Group ID
#define PTCL_GROUP_0 0x1C1A
#define PTCL_GROUP_1 0x1C1C
#define PTCL_GROUP_2 0x1C1E

typedef struct ParticleGroup {
  u16 id;      // 0x00
  u8 unk_02;   // 0x02
  u8 shape;    // 0x03
  u16 tile;    // 0x04, Start index of this particle group in the tiles array, number of tiles per particle is implied by the shape field.
  u16 plttID;  // 0x06
} ParticleGroup;
static_assert(sizeof(ParticleGroup) == 8);

typedef struct {
  u32 unk_00;                                     // 0x00
  u16 tileCount;                                  // 0x04, Number of elements in the tiles array
  u16 groupCount;                                 // 0x06, Number of elements in the groups array
  u32 offsetToTiles;                              // 0x08, Byte offset from start of the file to the tiles array
  struct ParticleGroup groups[PTCL_GROUP_COUNT];  // 0x0C, Array of particle groups
  u8 tiles[PARTICLE_TILE_SIZE * 32];              // GBA tiles
} ParticleFile;

extern const ParticleFile gParticleFile0;  // 0x08A20138

void LoadParticleFile(ParticleFile* p);
ParticleGroup* GetParticleGroup(u16 ptclID);

// --------------------------------------------

typedef struct Particle {
  u32 unk_0;  // 0x00
  u8 unk_4;   // 0x04
  u8 unk_5[8 - 5];
  u16 unk_8;        // 0x08
  u8 spriteWidth;   // 0x0A
  u8 spriteHeight;  // 0x0B
  s8 unk_c;         // 0x0C
  s8 unk_d;         // 0x0D
  u8 unk_e;         // 0x0E
  u8 unk_f;         // 0x0F
  u8 unk_10;        // 0x10
  u8 unk_11;        // 0x11
  u8 unk_12[2];
  u32 unk_14;               // 0x14
  Vec3 pos;                 // 0x18
  struct Particle* unk_20;  // 0x20
  struct Particle* unk_24;  // 0x24
} Particle;
static_assert(sizeof(Particle) == 40);  // 　FUN_0822a3c4 から 40バイト以上は確定 で 0x0805fdfe のループでは 40バイトずつアドレスが増えていくので、 40バイトで確定と思われる

void FUN_0822a3c4(Particle* p, s32 idx);

// --------------------------------------------

#endif  // __INCLUDE_PARTICLE_H__
