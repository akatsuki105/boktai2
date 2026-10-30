#ifndef __INCLUDE_PARTICLE_H__
#define __INCLUDE_PARTICLE_H__

#include "gba/gba.h"
#include "sprite_animation.h"
#include "sprite_common.h"
#include "types.h"

// Particle Group ID
#define PTCL_GROUP_0 BOKHASH("eff_eff_00")  // 0x1C1A, ROMにこの文字列があるのでこれは確定
#define PTCL_GROUP_1 0x1C1C                 // BOKHASH("eff_eff_02") が 一致するが eff_eff_01 がないのは不自然
#define PTCL_GROUP_2 0x1C1E                 // 0x1C1E, エレメントのパーティクル

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
  bool8 active;           // 0x04
  u2_6 scaleX;            // 0x05
  u2_6 scaleY;            // 0x06
  u8 rotation;            // 0x07
  u16 tileNum;            // 0x08, GBAタイル番号 (Particle_SetPose で poseIdx と パーティクルのサイズを元に計算される)
  u8 spriteWidth;         // 0x0A
  u8 spriteHeight;        // 0x0B
  s8 offsetX;             // 0x0C
  s8 offsetY;             // 0x0D
  u8 plttSlot;            // 0x0E
  u8 priority;            // 0x0F
  s8 offsetZ;             // 0x10
  u8 listIdx;             // 0x11
  u8 _[2];                // 0x12, padding
  u32 oamAttr01;          // 0x14
  Vec3 pos;               // 0x18
  struct Particle* prev;  // 0x20
  struct Particle* next;  // 0x24
} Particle;
static_assert(sizeof(Particle) == 40);

// --------------------------------------------

extern Particle* gParticleLists[2];

void LoadParticleFile(ParticleFile* p);
ParticleGroup* GetParticleGroup(u16 ptclgroupID);
void Video_RemoveParticleFromDrawList(Particle* p, s32 idx);
void Particle_Add(Particle* p, ParticleGroup* g, u32 flags);
void Particle_Setup(Particle* p, ParticleGroup* g, u32 flags);
void Particle_Remove(Particle* p);
void Particle_SetPltt(Particle* p, s32 plttID);
void Particle_SetOffset(Particle* p, s32 offsetX, s32 offsetY);

// poseIdx は "include/constants/particle.h" の定数
void Particle_SetPose(Particle* p, ParticleGroup* g, u32 poseIdx);

static inline void Particle_Hide(Particle* p) { p->flags |= SPRFLAG_HIDDEN; }

static inline void Particle_SetTile(Particle* ptcl, ParticleGroup* group, u32 poseIdx) { ptcl->tileNum = poseIdx * ((ptcl->spriteWidth >> 3) * (ptcl->spriteHeight >> 3)) + group->tile; }

// 今のコマを粒子に当ててアニメを1コマ進める, 一巡したら TRUE を返す
static inline bool32 Particle_AdvanceAnim(Particle* ptcl, ParticleGroup* group, AuxAnimState* anim) {
  AuxAnimCmd* cmd = &anim->cmds[anim->cmdIdx];
  bool32 finished;

  Particle_SetTile(ptcl, group, *cmd >> 6);
  if ((anim->flags & ANIM_PLAY_XFLIP) != (AuxAnimCmd_GetFlip(cmd) & ANIM_PLAY_XFLIP)) {
    ptcl->flags |= SPRFLAG_XFLIP;
  } else {
    ptcl->flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (AuxAnimCmd_GetFlip(cmd) & ANIM_PLAY_YFLIP)) {
    ptcl->flags |= SPRFLAG_YFLIP;
  } else {
    ptcl->flags &= ~SPRFLAG_YFLIP;
  }

  if (++anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        finished = TRUE;
      } else {
        anim->cmdIdx--;
        finished = FALSE;
      }
    } else {
      if (++anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
        finished = TRUE;
      } else {
        finished = FALSE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->wait = ((*cmd & 0xF) * anim->speed) >> 6;
  } else {
    finished = FALSE;
  }
  return finished;
}

#endif  // __INCLUDE_PARTICLE_H__
