#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_main.h"
#include "video.h"
#include "vm.h"

typedef struct {
  Entity e;           // 0x000, ENTITY_UNK_8
  u32 timer;          // 0x018, 毎フレーム +1
  MainSpriteGfx gfx;  // 0x01C, SPRITE_RINGO
  MainSprite sprite;  // 0x03C
  s32 scriptID;       // 0x09C, '.e', timer が 180 になったら VM_ExecByID に渡す
  rgb555 pltt[256];   // 0x0A0, sprite.pltt が指す OBJ パレット, EntityFBE5_Init が全色を RGB(4, 4, 4) で埋める
} EntityFBE5;
static_assert(sizeof(EntityFBE5) == 672);

// 101/101 命令, timer を r1 に置く形にならない
NON_MATCH s32 EntityFBE5_Update(EntityFBE5* p) {
#ifdef NONMATCHING_C
  u32 t;

  if (p->timer < 8) {
    if ((p->timer & 3) == 0) {
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprite.flags |= SPRFLAG_HIDDEN;
    }
  } else if (p->timer < 16) {
    if ((p->timer & 3) <= 1) {
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprite.flags |= SPRFLAG_HIDDEN;
    }
  } else if (p->timer == 16) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }

  if (p->timer == 30) {
    MainSprite_SetAnim(&p->sprite, &p->gfx, 25, PLAYMODE_LOOP, 0);
  }

  t = p->timer;
  if (t >= 90) {
    if (t < 106) {
      if ((t & 3) <= 1) {
        p->sprite.flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprite.flags |= SPRFLAG_HIDDEN;
      }
    } else if (t < 127) {
      if ((t & 3) == 0) {
        p->sprite.flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprite.flags |= SPRFLAG_HIDDEN;
      }
    } else if (t == 127) {
      p->sprite.flags |= SPRFLAG_HIDDEN;
    }
  }

  if (t == 180) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
    }
  } else {
    MainSprite_AdvanceAnim(&p->sprite, &p->gfx);
    p->timer++;
  }
#else
  INCFUNC("asm/func/EntityFBE5_Update.inc");
#endif
}

void Entity6978_SetRequest(u32 request, s32 count, u32* args);

s32 EntityFBE5_Destroy(EntityFBE5* p) {
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  MainSprite_Remove(&p->sprite);
  return 0;
}

// 141/145 命令, p->gfx の複写で使うレジスタと &p->gfx の持ち方が違う
NON_MATCH s32 EntityFBE5_Init(EntityFBE5* p, u32 param_2) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_RINGO);
  MainSpriteGfx* gfx;
  Vec3 pos;
  u32 args[5];
  s32 i;
  s32 j;

  if (f == NULL) {
    return -1;
  }

  p->gfx = *f;
  gfx = &p->gfx;
  OpenMainSpriteFile(gfx, f);
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
  } else {
    pos.x = 120;
    pos.y = 80;
  }
  pos.z = 0;
  p->scriptID = VM_GetNamedArgValue('e', 0);
  p->timer = 0;
  MainSprite_Add(&p->sprite, gfx, 0, SPRFLAG_UNK_13 | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprite, gfx, 24, PLAYMODE_LOOP, 0);
  Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
  args[0] = 2;
  args[1] = 1;
  args[2] = 31;
  args[3] = 31;
  args[4] = 31;
  Entity6978_SetRequest(3, 5, args);
  for (i = 0; i < 16; i++) {
    for (j = 15; j >= 0; j--) {
      p->pltt[i * 16 + j] = 0x1084;
    }
  }
  p->sprite.plttID = 0x6541;
  p->sprite.pltt = p->pltt;
  return 0;
#else
  INCFUNC("asm/func/EntityFBE5_Init.inc");
#endif
}

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
