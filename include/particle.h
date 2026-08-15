#ifndef __INCLUDE_PARTICLE_H__
#define __INCLUDE_PARTICLE_H__

#include "gba/gba.h"

// ParticleFile の長さは .tileCount と .groupCount に依存するが、 boktai2 では ParticleFile が 1つしかないので、固定値で定義している

#define PARTICLE_TILE_SIZE 317  // = ParticleFile.tileCount
#define PARTICLE_GROUP_COUNT 3  // = ParticleFile.groupCount

typedef struct ParticleGroup {
  u16 id;      // 0x00
  u8 unk_02;   // 0x02
  u8 shape;    // 0x03
  u16 tile;    // 0x04, Start index of this particle group in the tiles array, number of tiles per particle is implied by the shape field.
  u16 unk_06;  // 0x06
} ParticleGroup;
static_assert(sizeof(ParticleGroup) == 8);

typedef struct {
  u32 unk_00;                                         // 0x00
  u16 tileCount;                                      // 0x04, Number of elements in the tiles array
  u16 groupCount;                                     // 0x06, Number of elements in the groups array
  u32 offsetToTiles;                                  // 0x08, Byte offset from start of the file to the tiles array
  struct ParticleGroup groups[PARTICLE_GROUP_COUNT];  // 0x0C, Array of particle groups
  u8 tiles[PARTICLE_TILE_SIZE * 32];                  // GBA tiles
} ParticleFile;

extern const ParticleFile gParticleFile0;  // 0x08A20138

void LoadParticleFile(ParticleFile* p);

#endif  // __INCLUDE_PARTICLE_H__
