#include "entity.h"
#include "global.h"
#include "particle.h"

typedef struct {
  u32 unk_00;              // 0x00, まだ未解析
  Particle ptcl;           // 0x04
  u8 unk_2c[0x44 - 0x2C];  // 0x2C, まだ未解析
} Entity080de11cElem;
static_assert(sizeof(Entity080de11cElem) == 68);

typedef struct {
  Entity e;                      // 0x0, ENTITY_UNK_9
  u8 unk_18[0x24 - 0x18];        // 0x18, まだ未解析
  Entity080de11cElem ptcls[48];  // 0x24
} Entity080de11c;
static_assert(sizeof(Entity080de11c) == 3300);

IWRAM_DATA Entity080de11c* gEntity080de11c = NULL;  // 0x03000174

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

NAKED s32 FUN_080ddcc8(unknown* p, u8 param_2, unknown* param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080ddcc8.inc"); }

NAKED void FUN_080ddf88(void) { INCFUNC("asm/func/FUN_080ddf88.inc"); }

NAKED s32 Entity080de11c_Init(Entity080de11c* p) { INCFUNC("asm/func/Entity080de11c_Init.inc"); }

s32 Entity080de11c_Update(Entity080de11c* p);
s32 Entity080de11c_Destroy(Entity080de11c* p);

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
