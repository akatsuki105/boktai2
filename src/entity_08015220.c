#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct Entity08015220 {
  Entity e;  // ENTITY_UNK_10
  u8 unk_18[1536 - 0x18];
} Entity08015220;
static_assert(sizeof(Entity08015220) == 1536);

extern Entity08015220* gEntity08015220;  // 0x0300005C

const u16 u16_ARRAY_085aa8f0[9] = {
    0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};  // 0x085AA8F0

const ActorSpriteID16 u16_ARRAY_085aa902[9] = {
    0x84EE, 0xA874, 0xA894, 0xC42D, 0xDF0E, 0xA875, 0xA895, 0x0334, 0x1E15,
};  // 0x085AA902

void FUN_08014d94(void) { gEntity08015220 = NULL; }

NAKED s32 FUN_08014da0(s32 param_1, unknown* param_2, unknown* param_3, unknown* param_4, unknown* param_5, unknown* param_6, unknown* param_7, unknown* param_8, unknown* param_9, unknown* param_10, unknown* param_11, unknown* param_12) { INCFUNC("asm/func/FUN_08014da0.inc"); }

NAKED void FUN_08015074(Entity08015220* p, unknown* data) { INCFUNC("asm/func/FUN_08015074.inc"); }

NAKED s32 Entity08015220_Update(Entity08015220* p) { INCFUNC("asm/func/Entity08015220_Update.inc"); }

NAKED s32 Entity08015220_Destroy(Entity08015220* p) { INCFUNC("asm/func/Entity08015220_Destroy.inc"); }

NAKED s32 Entity08015220_Init(Entity08015220* p, u32 _) { INCFUNC("asm/func/Entity08015220_Init.inc"); }

Entity08015220* Entity08015220_Create(u32 val, u32 _) {
  Entity08015220* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity08015220));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08015220_Update, Entity08015220_Destroy);
    if (Entity08015220_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
