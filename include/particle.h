#ifndef __INCLUDE_PARTICLE_H__
#define __INCLUDE_PARTICLE_H__

#include "gba/gba.h"
#include "sprite_common.h"
#include "types.h"

// Particle Group ID
#define PTCL_GROUP_0 0x1C1A
#define PTCL_GROUP_1 0x1C1C
#define PTCL_GROUP_2 0x1C1E

typedef u8 ParticleGroupFlags;  // ParticleGroup.flags
#define PGFLAG_BPP8 (1 << 4)    // 0x10, 8bpp

// AuxSprite でいう AuxSpriteGfx
typedef struct {
  u16 id;                    // 0x00
  ParticleGroupFlags flags;  // 0x02, see ParticleGroupFlags
  SpriteShape shape;         // 0x03, see SpriteShape
  u16 tile;                  // 0x04, Start index of this particle group in the tiles array, number of tiles per particle is implied by the shape field.
  u16 plttID;                // 0x06
} ParticleGroup;
static_assert(sizeof(ParticleGroup) == 8);

typedef struct {
  u32 unk_00;               // 0x00
  u16 tileCount;            // 0x04, Number of elements in the tiles array (このゲームでは ParticleFile は 1つで tileCount = 317)
  u16 groupCount;           // 0x06, Number of elements in the groups array
  u32 offsetToTiles;        // 0x08, Byte offset from start of the file to the tiles array
  ParticleGroup groups[3];  // 0x0C, Array of particle groups
  u8 tiles[317 * 32];       // GBA tiles
} ParticleFile;             // ParticleFile の長さは .tileCount と .groupCount に依存するが、 boktai2 では ParticleFile が 1つしかないので、固定値で定義している

// --------------------------------------------

typedef struct Particle {
  SpriteFlags flags;      // 0x00
  u8 active;              // 0x04
  s8 scaleX;              // 0x05
  s8 scaleY;              // 0x06
  u8 rotation;            // 0x07
  u16 tileNum;            // 0x08
  u8 spriteWidth;         // 0x0A
  u8 spriteHeight;        // 0x0B
  s8 offsetX;             // 0x0C
  s8 offsetY;             // 0x0D
  u8 plttSlot;            // 0x0E
  u8 priority;            // 0x0F
  u8 offsetZ;             // 0x10
  u8 listIdx;             // 0x11
  u8 unk_12[2];           // 0x12, padding?
  u32 oamAttr01;          // 0x14
  Vec3 pos;               // 0x18
  struct Particle* prev;  // 0x20
  struct Particle* next;  // 0x24
} Particle;
static_assert(sizeof(Particle) == 40);  // 　Video_RemoveParticleFromDrawList から 40バイト以上は確定 で 0x0805fdfe のループでは 40バイトずつアドレスが増えていくので、 40バイトで確定と思われる

// --------------------------------------------

extern Particle* gParticleLists[2];

void LoadParticleFile(ParticleFile* p);
ParticleGroup* GetParticleGroup(u16 ptclgroupID);
void Video_RemoveParticleFromDrawList(Particle* p, s32 idx);
void FUN_0822d9f0(Particle* p, ParticleGroup* g, u32 flags);
void FUN_0822da70(Particle* p, ParticleGroup* g, u32 flags);
void Particle_Remove(Particle* p);
void FUN_0822dadc(Particle* p, s32 plttID);
void Particle_SetOffset(Particle* p, s32 offsetX, s32 offsetY);
void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val);

#endif  // __INCLUDE_PARTICLE_H__
