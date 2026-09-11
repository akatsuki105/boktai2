#include "entity.h"
#include "global.h"
#include "sprite.h"

// SPRITE_EVENT_SUN_RAY をロードしている
typedef struct Entity6367 {
  Entity e;                // 0x000, ENTITY_UNK_11
  SpriteSet spriteSet;     // 0x018
  SpriteState sprites[3];  // 0x038
  u32 unk_158;             // 0x158
  s32 scriptID_15c;        // 0x15C
  s32 mode;                // 0x160, PTR_ARRAY_085affa0 の idx
  u8 unk_164[0x190 - 0x164];
  void (*updateCallback)(struct Entity6367*);  // 0x190, このゲームでは FUN_0821a308 で固定
} Entity6367;
static_assert(sizeof(Entity6367) == 404);

NAKED void FUN_0821a2bc(Entity6367* p) { INCFUNC("asm/func/FUN_0821a2bc.inc"); }

NAKED void FUN_0821a308(Entity6367* p) { INCFUNC("asm/func/FUN_0821a308.inc"); }

void (*const PTR_ARRAY_085affa0[1])(Entity6367*) = {
    FUN_0821a308,
};

NAKED void FUN_0821a5d4(Entity6367* p) { INCFUNC("asm/func/FUN_0821a5d4.inc"); }

void Entity6367_Destroy_Internal(Entity6367* p) {
  FUN_0822f1c0(p->sprites);
  FUN_0822f1c0(p->sprites + 1);
  FUN_0822f1c0(p->sprites + 2);
}

NAKED void FUN_0821a714(Entity6367* p, s32 idx) { INCFUNC("asm/func/FUN_0821a714.inc"); }

NAKED s32 Entity6367_Update(Entity6367* p) { INCFUNC("asm/func/Entity6367_Update.inc"); }

s32 Entity6367_Destroy(Entity6367* p) {
  Entity6367_Destroy_Internal(p);
  return 0;
}

NAKED s32 Entity6367_Init(Entity6367* p) { INCFUNC("asm/func/Entity6367_Init.inc"); }

Entity6367* Entity6367_Create(void) {
  Entity6367* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity6367));
  if (p != NULL) {
    SetEntityRoutine(p, Entity6367_Update, Entity6367_Destroy);
    if (Entity6367_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
