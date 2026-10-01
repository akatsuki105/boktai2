#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "video.h"

typedef struct {
  Entity e;           // 0x000, ENTITY_UNK_8
  u32 timer;          // 0x018, 毎フレーム +1
  MainSpriteGfx gfx;  // 0x01C, SPRITE_RINGO
  MainSprite sprite;  // 0x03C
  s32 scriptID;       // 0x09C, '.e', timer が 180 になったら VM_ExecByID に渡す
  rgb555 pltt[256];   // 0x0A0, sprite.pltt が指す OBJ パレット, EntityFBE5_Init が全色を RGB(4, 4, 4) で埋める
} EntityFBE5;
static_assert(sizeof(EntityFBE5) == 672);

NAKED s32 EntityFBE5_Update(EntityFBE5* p) { INCFUNC("asm/func/EntityFBE5_Update.inc"); }

s32 EntityFBE5_Destroy(EntityFBE5* p) {
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  MainSprite_Remove(&p->sprite);
  return 0;
}

NAKED s32 EntityFBE5_Init(EntityFBE5* p, u32 param_2) { INCFUNC("asm/func/EntityFBE5_Init.inc"); }

EntityFBE5* EntityFBE5_Create(u32 param_1) {
  EntityFBE5* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityFBE5));

  if (p != NULL) {
    SetEntityRoutine(p, EntityFBE5_Update, EntityFBE5_Destroy);
    if (EntityFBE5_Init(p, param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
