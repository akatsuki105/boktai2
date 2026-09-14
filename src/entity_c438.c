#include "entity.h"
#include "global.h"
#include "sprite.h"

// SPRITE_MARKERS を読み込んでいる(EntityC438_Init)
typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_9
  u16 unk_18;          // 0x18
  u16 unk_1a;          // 0x1A
  SpriteState sprite;  // 0x1C
  Vec3 pos;            // 0x7C
} EntityC438;
static_assert(sizeof(EntityC438) == 132);

NAKED bool32 FUN_080aad30(EntityC438* p) { INCFUNC("asm/func/FUN_080aad30.inc"); }

NAKED s32 EntityC438_Update(EntityC438* p) { INCFUNC("asm/func/EntityC438_Update.inc"); }

NAKED s32 EntityC438_Destroy(EntityC438* p) { INCFUNC("asm/func/EntityC438_Destroy.inc"); }

NAKED s32 EntityC438_Init(EntityC438* p) { INCFUNC("asm/func/EntityC438_Init.inc"); }

EntityC438* EntityC438_Create(void) {
  EntityC438* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityC438));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC438_Update, EntityC438_Destroy);
    if (EntityC438_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
