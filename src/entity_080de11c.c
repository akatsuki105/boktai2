#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"

typedef struct {
  u8 unk_00[0x10];         // 0x00, まだ未解析
  Particle ptcl;           // 0x10
  u8 unk_38[0x40 - 0x38];  // 0x38, まだ未解析
  u8 unk_40;               // 0x40, _Init が 0 を入れる
  u8 unk_41[0x44 - 0x41];  // 0x41, まだ未解析
} Entity080de11cElem;
static_assert(sizeof(Entity080de11cElem) == 68);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_9
  Entity080de11cElem ptcls[48];  // 0x018
  AuxAnimFile* animFile;         // 0xCD8, ANIM_D1B8
  ParticleGroup* group;          // 0xCDC, PTCL_GROUP_0
  u8 unk_ce0[0xCE4 - 0xCE0];     // 0xCE0, まだ未解析
} Entity080de11c;
static_assert(sizeof(Entity080de11c) == 3300);

static Entity080de11c* gEntity080de11c;  // 0x03000174

NAKED s32 Entity080de11c_Update(Entity080de11c* p) { INCFUNC("asm/func/Entity080de11c_Update.inc"); }

// 全要素の粒子を描画リストから外す
s32 Entity080de11c_Destroy(Entity080de11c* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  gEntity080de11c = NULL;
  return 0;
}

NAKED s32 FUN_080ddcc8(WorldPos* pos, u8 param_2, Vec3* halfSize, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080ddcc8.inc"); }

NAKED void UNUSED FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

s32 Entity080de11c_Init(Entity080de11c* p) {
  s32 i;

  p->animFile = GetFile(DIR_ANIMATION, ANIM_D1B8);
  if (p->animFile == NULL) {
    return -1;
  }

  p->group = GetParticleGroup(PTCL_GROUP_0);
  if (p->group == NULL) {
    return -1;
  }

  for (i = 0; i < 48; i++) {
    Particle* ptcl = &p->ptcls[i].ptcl;

    p->ptcls[i].unk_40 = 0;
    Particle_Add(ptcl, p->group, 0);
    Particle_SetOffset(ptcl, -8, -10);
    ptcl->offsetZ = 2;
    ptcl->flags |= SPRFLAG_HIDDEN;
  }

  gEntity080de11c = p;
  return 0;
}

Entity080de11c* Entity080de11c_Create(void) {
  if (gEntity080de11c == NULL) {
    Entity080de11c* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080de11c));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080de11c_Update, Entity080de11c_Destroy);
      if (Entity080de11c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080de11c;
}

void FUN_080de168(void) { gEntity080de11c = NULL; }
