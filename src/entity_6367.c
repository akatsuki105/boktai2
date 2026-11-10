#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// SPRITE_EVENT_SUN_RAY をロードしている
typedef struct Entity6367 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx;                           // 0x018
  MainSprite sprites[3];                       // 0x038
  u32 unk_158;                                 // 0x158
  s32 scriptID_15c;                            // 0x15C
  s32 mode;                                    // 0x160, PTR_ARRAY_085affa0 の idx
  u32 timer_164;                               // 0x164, unk_158 の bit0 が立っていない間だけ毎フレーム +1
  s32 state;                                   // 0x168, Entity6367_UpdateRay の段階
  s32 timer_16c;                               // 0x16C, unk_158 の bit1 が立っていない間だけ毎フレーム +1
  u2_6 scaleX;                                 // 0x170, 3枚のスプライトへ写す拡大率
  u2_6 scaleY;                                 // 0x171, 同上
  u8 unk_172[2];                               // 0x172
  s32 dist;                                    // 0x174, 上位16bitが広がり量, 90 で止まる
  s32 speed;                                   // 0x178, 毎フレーム dist に足す
  s32 accel;                                   // 0x17C, 毎フレーム speed に足す
  s32 holdTime;                                // 0x180, '.t[0]', 真っ白のまま待つフレーム数
  s32 fadeTime;                                // 0x184, '.t[1]', 白から暗転するフレーム数
  s32 unk_188;                                 // 0x188
  s32 unk_18c;                                 // 0x18C, 15 を入れるだけ
  void (*updateCallback)(struct Entity6367*);  // 0x190
} Entity6367;
static_assert(sizeof(Entity6367) == 404);

static inline bool32 Entity6367_ConsumeFlag(u32* flags, u32 mask) {
  u32 set = *flags & mask;

  if (set) {
    set = TRUE;
  }
  *flags &= ~mask;
  return set;
}

static inline void Entity6367_SetState(Entity6367* p, u32* flags, s32 state) {
  p->state = state;
  p->timer_16c = 0;
  SET_FLAGS(*flags, 2);
}

// 拡大率を3枚のスプライトへ配る
void Entity6367_ApplyScale(Entity6367* p) {
  p->sprites[0].scaleX = p->scaleX;
  p->sprites[0].scaleY = p->scaleY;
  p->sprites[1].scaleX = p->scaleX;
  p->sprites[1].scaleY = p->scaleY;
  p->sprites[2].scaleX = p->scaleX;
  p->sprites[2].scaleY = p->scaleY;
}

// 残差は 1 命令, 先頭の定数とアドレスの順序と case 0 の SetState でアドレスを作り直す点だけ, flags が caller-save にならない条件は未解決
NON_MATCH void Entity6367_UpdateRay(Entity6367* p) {
#ifdef NONMATCHING_C
  u32* flags = &p->unk_158;

  Entity6367_ConsumeFlag(flags, 1);
  switch (p->state) {
    case 0: {
      s32 size;

      if (Entity6367_ConsumeFlag(flags, 2)) {
        p->dist = 0;
        p->speed = 0x7000;
        p->accel = 0;
        p->unk_18c = 15;
        p->sprites[2].pos.y = 128;
        gBgBrightness = 64;
        gObjBrightness = 64;
        gBgPlttBlendColor = 0x7FFF;
        gObjPlttBlendColor = 0x7FFF;
      }
      if (p->timer_16c > 40) {
        p->accel += 0x1400;
      } else if (p->timer_16c > 30) {
        p->accel += 0x100;
      } else {
        p->accel += 0x40;
      }
      p->speed += p->accel;
      p->dist += p->speed;
      if (p->dist > 0x5A0000) {
        p->dist = 0x5A0000;
      }
      size = p->dist >> 16;
      p->scaleX = Div(size * 63, 90) + 64;
      p->scaleY = Div(size * 5, 90) + 64;
      p->sprites[2].pos.y = Div(size * 2, 90) + 128;
      if (p->scaleX > 95 && Video_StepBrightnessFade(&p->unk_188, 1, 15, 0xFFFF)) {
        Entity6367_SetState(p, flags, 1);
      }
      if (p->sprites[0].flags & SPRFLAG_HIDDEN) {
        p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprites[0].flags |= SPRFLAG_HIDDEN;
        p->sprites[1].flags |= SPRFLAG_HIDDEN;
        p->sprites[2].flags |= SPRFLAG_HIDDEN;
      }
      Entity6367_ApplyScale(p);
      break;
    }
    case 1: {
      Entity6367_ConsumeFlag(flags, 2);
      if (p->timer_16c >= p->holdTime) {
        Entity6367_SetState(p, flags, 2);
      }
      break;
    }
    case 2: {
      s32 c;
      rgb555 color;

      Entity6367_ConsumeFlag(flags, 2);
      c = Div((p->fadeTime - p->timer_16c) * 31, p->fadeTime) & 31;
      color = (c << 10) | (c << 5) | c;
      gObjPlttBlendColor = color;
      gBgPlttBlendColor = color;
      if (p->timer_16c >= p->fadeTime) {
        Entity6367_SetState(p, flags, 3);
      }
      break;
    }
    case 3: {
      if (Entity6367_ConsumeFlag(flags, 2)) {
        VM_ExecByID(p->scriptID_15c, NULL);
      }
      KillEntity(&p->e);
      break;
    }
  }
#else
  INCFUNC("asm/func/Entity6367_UpdateRay.inc");
#endif
}

void (*const PTR_ARRAY_085affa0[1])(Entity6367*) = {
    Entity6367_UpdateRay,
};  // 0x085AFFA0

void Entity6367_InitSprites(Entity6367* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_EVENT_SUN_RAY);
  MainSpriteGfx* gfx;
  MainSprite* spr;
  Vec3 pos;

  p->gfx = *f;
  gfx = &p->gfx;
  OpenMainSpriteFile(gfx, f);
  Vec3_Clear(&pos);
  spr = p->sprites;
  pos.x = 120, pos.y = 32;
  MainSprite_Add(spr, gfx, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE, 0, 0, 60, &pos);
  p->sprites[0].scaleX = p->scaleX;
  p->sprites[0].scaleY = p->scaleY;
  spr->rotation = 0;
  spr++;
  pos.x = 120, pos.y = 96;
  MainSprite_Add(spr, gfx, 1, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE, 0, 0, 60, &pos);
  p->sprites[1].scaleX = p->scaleX;
  p->sprites[1].scaleY = p->scaleY;
  spr->rotation = 0;
  spr++;
  pos.x = 120, pos.y = 128;
  MainSprite_Add(spr, gfx, 2, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE, 0, 0, 60, &pos);
  p->sprites[2].scaleX = p->scaleX;
  p->sprites[2].scaleY = p->scaleY;
  spr->rotation = 0;
}

void Entity6367_Destroy_Internal(Entity6367* p) {
  MainSprite_Remove(p->sprites);
  MainSprite_Remove(p->sprites + 1);
  MainSprite_Remove(p->sprites + 2);
}

void Entity6367_SetMode(Entity6367* p, s32 idx) {
  p->mode = idx;
  p->timer_164 = 0;
  p->updateCallback = PTR_ARRAY_085affa0[idx];
  SET_FLAGS(p->unk_158, 1);
  p->state = 0;
  p->timer_16c = 0;
  SET_FLAGS(p->unk_158, 2);
}

s32 Entity6367_Update(Entity6367* p) {
  if (!(p->unk_158 & 1)) {
    p->timer_164++;
  }
  if (!(p->unk_158 & 2)) {
    p->timer_16c++;
  }
  p->updateCallback(p);
  return 0;
}

s32 Entity6367_Destroy(Entity6367* p) {
  Entity6367_Destroy_Internal(p);
  return 0;
}

s32 Entity6367_Init(Entity6367* p) {
  if (VM_SeekToNamedArg('t')) {
    p->holdTime = VM_GetValue();
    p->fadeTime = VM_GetValue();
  }
  if (VM_SeekToNamedArg('e')) {
    p->scriptID_15c = VM_GetValue();
  }
  p->mode = 0;
  p->timer_164 = 0;
  p->state = 0;
  p->timer_16c = 0;
  p->scaleX = 64;
  p->scaleY = 64;
  Entity6367_InitSprites(p);
  Entity6367_SetMode(p, 0);
  return 0;
}

// 0x6367, HashName("エンディング"), SPRITE_EVENT_SUN_RAY は ラスボス撃破時に使うので、 エンディングで合ってる可能性は高い
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
