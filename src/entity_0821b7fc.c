#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite_aux.h"

typedef struct {
  Particle ptcl;  // 0x00, Entity0821b7fc_Destroy が Particle_Remove に渡す
  u8 unk_28[8];   // 0x28
} Entity0821b7fcParticle;
static_assert(sizeof(Entity0821b7fcParticle) == 48);

typedef struct {
  Entity e;                         // 0x000, ENTITY_UNK_11
  AuxSprite sprite;                 // 0x018, _Destroy が AuxSprite_Remove に渡す
  u8 unk_44[0x06C - 0x044];         // 0x044
  u32 unk_6c;                       // 0x06C
  u8 unk_70[0x07C - 0x070];         // 0x070
  Entity0821b7fcParticle ptcls[8];  // 0x07C, 根拠: _Destroy の stride 0x30 で8回まわすループ
} Entity0821b7fc;
static_assert(sizeof(Entity0821b7fc) == 508);

NAKED void Entity0821b7fc_Update_Helper_0821b35c(Entity0821b7fc* p) { INCFUNC("asm/func/Entity0821b7fc_Update_Helper_0821b35c.inc"); }

NAKED void FUN_0821b470(Entity0821b7fc* p) { INCFUNC("asm/func/FUN_0821b470.inc"); }

NAKED s32 Entity0821b7fc_Update(Entity0821b7fc* p) { INCFUNC("asm/func/Entity0821b7fc_Update.inc"); }

s32 Entity0821b7fc_Destroy(Entity0821b7fc* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }

  return 0;
}

NAKED s32 Entity0821b7fc_Init(Entity0821b7fc* p, unknown* param_2) { INCFUNC("asm/func/Entity0821b7fc_Init.inc"); }

Entity0821b7fc* Entity0821b7fc_Create(unknown* arg) {
  Entity0821b7fc* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity0821b7fc));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0821b7fc_Update, Entity0821b7fc_Destroy);
    if (Entity0821b7fc_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void FUN_0821b840(Entity0821b7fc* p) { KillEntity((void*)p); }

bool32 FUN_0821b84c(Entity0821b7fc* p) { return p->unk_6c == 4; }
