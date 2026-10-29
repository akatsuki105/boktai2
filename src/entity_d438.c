#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_aux.h"

typedef struct {
  Entity e;                // 0x00, ENTITY_UNK_8
  u32 timer;               // 0x18, Init が 0 を書き Update が読み書きする
  AuxSpriteGfx gfx;        // 0x1C, SPRITE_BAT
  AuxSprite sprite;        // 0x38
  AuxAnimState animState;  // 0x64
  AuxAnimFile* anim;       // 0x74, ANIM_BAT
} EntityD438;
static_assert(sizeof(EntityD438) == 120);

IWRAM_DATA EntityD438* gEntityD438 = NULL;  // 0x03000124

void Cmd_1B77(void) {}

void Cmd_D562(void) {}

void FUN_080558c0(void) { gEntityD438 = NULL; }

NAKED s32 EntityD438_Update(EntityD438* p) { INCFUNC("asm/func/EntityD438_Update.inc"); }

s32 EntityD438_Destroy(EntityD438* p) {
  AuxSprite_Remove(&p->sprite);
  gEntityD438 = NULL;
}

s32 EntityD438_Init(EntityD438* p, u32 param_2) {
  AuxSpriteGfx* gfx;
  AuxSprite* spr;
  AuxAnimState* st;

  gEntityD438 = p;
  gfx = &p->gfx;
  spr = &p->sprite;
  st = &p->animState;
  p->anim = GetFile(DIR_ANIMATION, ANIM_BAT);
  Video_GetAuxSprite(gfx, SPRITE_BAT);
  AuxSprite_Add(spr, gfx, 0);
  AuxAnim_SetAnim(st, p->anim, 0, 0, 0);
  p->timer = 0;
  return 0;
}

// 0xD438
EntityD438* EntityD438_Create(u32 id) {
  if (gEntityD438 == NULL) {
    EntityD438* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityD438));

    if (p != NULL) {
      SetEntityRoutine(p, EntityD438_Update, EntityD438_Destroy);
      if (EntityD438_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityD438;
}
