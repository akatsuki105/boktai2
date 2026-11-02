#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sprite_aux.h"
#include "vec3.h"

// 不使用?
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_8
  u32 timer;              // 0x18
  AuxSpriteGfx gfx;       // 0x1C, SPRITE_BAT
  AuxSprite sprite;       // 0x38
  AuxAnimState anim;      // 0x64
  AuxAnimFile* animFile;  // 0x74, ANIM_BAT
} EntityD438;
static_assert(sizeof(EntityD438) == 120);

static EntityD438* sEntityD438;  // 0x03000124

static inline void EntityD438_GetAnimDir(u8 dir, u8* variant, u8* flags) {
  if (dir == 1 || dir == 2) {
    *variant = 1;
  } else {
    *variant = 0;
  }
  if (dir > 1) {
    *flags = 1;
  } else {
    *flags = 0;
  }
}

// 0x1B77
void Cmd_1B77(void) {}

// 0xD562
void Cmd_D562(void) {}

void FUN_080558c0(void) { sEntityD438 = NULL; }

// コウモリをプレイヤーの周りで回し, 向きに合うアニメを当てて1コマ進める
s32 EntityD438_Update(EntityD438* p) {
  AuxSprite* sprite = &p->sprite;
  AuxAnimState* anim = &p->anim;
  Player* player = gPlayerPtr[0];
  Vec3 ofs;
  u8 variant;
  u8 flags;

  Vec3_SetPolar(&ofs, p->timer, 256);
  Vec3_Sum(&sprite->pos, &player->mover.pos, &ofs);
  EntityD438_GetAnimDir(Angle_ToDir4(p->timer & 0xFF), &variant, &flags);
  AuxAnim_SetAnim(anim, p->animFile, 0, variant, flags);
  AuxSprite_AdvanceAnim(sprite, anim);
  p->timer++;
}

s32 EntityD438_Destroy(EntityD438* p) {
  AuxSprite_Remove(&p->sprite);
  sEntityD438 = NULL;
}

s32 EntityD438_Init(EntityD438* p, u32 param_2) {
  AuxSpriteGfx* gfx;
  AuxSprite* spr;
  AuxAnimState* st;

  sEntityD438 = p;
  gfx = &p->gfx;
  spr = &p->sprite;
  st = &p->anim;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_BAT);
  Video_GetAuxSprite(gfx, SPRITE_BAT);
  AuxSprite_Add(spr, gfx, 0);
  AuxAnim_SetAnim(st, p->animFile, 0, 0, 0);
  p->timer = 0;
  return 0;
}

// 0xD438
EntityD438* EntityD438_Create(u32 id) {
  if (sEntityD438 == NULL) {
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
  return sEntityD438;
}

// 0x3D0C
void Cmd_3D0C(void) {}
