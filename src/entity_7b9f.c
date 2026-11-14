#include "eff_scatter.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vm.h"

typedef struct Entity7B9FElem {
  AuxSprite sprite;                                // 0x00, Entity7B9F_Destroy が AuxSprite_Remove に渡す
  AuxAnimState anim;                               // 0x2C, ANIM_1E38
  HitboxData hitbox;                               // 0x3C
  ParticleShadow shadow;                           // 0x8C, unk_d2 が -1 でなければ _Destroy が ParticleShadow_Remove に渡す
  s16 id;                                          // 0xCC, '.n'
  u8 unk_ce[2];                                    // 0xCE
  s16 slotIdx;                                     // 0xD0, _AllocElem が確保したスロット番号
  s16 unk_d2;                                      // 0xD2, _AllocElem が -1 を入れる, -1 でなければ shadow が生きている
  u8 state;                                        // 0xD4
  u8 stateTimer;                                   // 0xD5
  u16 speedY;                                      // 0xD6
  void (*updateCallback)(struct Entity7B9FElem*);  // 0xD8
  u8 unk_dc[220 - 0xDC];                           // 0xDC, まだ未解析
} Entity7B9FElem;
static_assert(sizeof(Entity7B9FElem) == 220);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;         // 0x018, SPRITE_GOLEM
  AuxAnimFile* animFile;    // 0x034, ANIM_1E38
  Entity7B9FElem elems[4];  // 0x038, _AllocElem が usedMask の空きビットを探して確保する
  u32 usedMask;             // 0x3A8, elems[i] が使用中なら bit i が立つ
} Entity7B9F;
static_assert(sizeof(Entity7B9F) == 940);

IWRAM_DATA Entity7B9F* gEntity7B9F = NULL;  // 0x030001A0

static inline bool8 Entity7B9F_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081ee7a8_SpawnDefaultNow(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

void nop_081d8368(Entity7B9FElem* e);
void nop_081d88a4(void);
void FUN_081d836c(Entity7B9FElem* e);
void FUN_081d85a8(Entity7B9FElem* e);
Entity7B9F* Entity7B9F_Create(void);

Entity7B9FElem* Entity7B9F_AllocElem(Entity7B9F* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!Entity7B9F_IsActive(&p->usedMask, i)) {
      Entity7B9FElem* e = &p->elems[i];

      ClearMemory(e, sizeof(Entity7B9FElem));
      SET_BIT(p->usedMask, i);
      e->slotIdx = i;
      e->unk_d2 = -1;
      return e;
    }
  }
  return NULL;
}

void FUN_081d822c(Entity7B9FElem* e) {
  Entity7B9F* p = gEntity7B9F;

  if (p != NULL) {
    e->updateCallback = nop_081d8368;
    CLEAR_BIT(p->usedMask, e->slotIdx);
    e->slotIdx = -1;
    AuxSprite_Remove(&e->sprite);
    if (e->unk_d2 != -1) {
      ParticleShadow_Remove(&e->shadow);
      e->unk_d2 = -1;
    }
  }
}

// 氷の破片のパーティクルを 3〜6 個ばらまく
void Entity7B9FElem_ScatterIceShards(Entity7B9FElem* e) {
  Vec3 vel;
  Vec3 velRange;

  vel.x = -12;
  vel.y = RandomNext() & 7;
  vel.z = -12;
  velRange.x = 24;
  velRange.y = (RandomNext() & 7) + 3;
  velRange.z = 24;
  ScatterEffect_Spawn((RandomNext() & 3) + 3, SCATTER_ICE, &e->sprite.pos, &vel, &velRange, 60, 63);
}

void nop_081d8368(Entity7B9FElem* e) {}

// 命令数は一致, 残差は GetCollisionTileIdx 周りのレジスタ割当
NON_MATCH void FUN_081d836c(Entity7B9FElem* e) {
#ifdef NONMATCHING_C
  s32 tileIdx = GetCollisionTileIdx(&e->sprite.pos);
  u8* state = &e->state;
  u16* speedY = &e->speedY;
  s32 height;

  if (*state) {
    AuxSprite_Show(&e->sprite);
    ParticleShadow_Show(&e->shadow);
    *speedY = 0;
    *state = 0;
    e->stateTimer = 0;
    AuxAnim_SetAnimSpeed(&e->anim, Q6(0.5));
  }
  AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
  e->sprite.pos.y -= *speedY;
  Hitbox_SetPos(&e->hitbox, &e->sprite.pos, 0);
  Hitbox_Register(&e->hitbox);
  height = TileHeightAt(&e->sprite.pos);
  if (height < e->sprite.pos.y) {
    (*speedY)++;
  } else {
    e->updateCallback = FUN_081d85a8;
    e->sprite.pos.y = height;
    *state = 1;
  }
#else
  INCFUNC("asm/func/FUN_081d836c.inc");
#endif
}

// スプライトの位置から3方向ぶんのエフェクトを出す
void FUN_081d8560(Entity7B9FElem* e) {
  s32 i;

  for (i = 0; i < 3; i++) {
    Entity081ee7a8_SpawnDefaultNow(&e->sprite.pos, 8, 0x10, 4, 0xC, 0x12, i * 32, 8, Q6(1), 1, 0, 0x200);
  }
}

void FUN_081d85a8(Entity7B9FElem* e) {
  Entity7B9F* p = gEntity7B9F;

  if (p != NULL) {
    AuxAnimState* anim;

    if (e->state) {
      e->state = 0;
      e->stateTimer = 0;
      anim = &e->anim;
      AuxAnim_SetAnim(anim, p->animFile, 6, 1, ANIM_PLAY_XFLIP);
      AuxAnim_SetAnimSpeed(anim, Q6(0.5));
    }
    e->speedY = Div(e->speedY << 3, 10);
    e->sprite.pos.y += e->speedY;
    Hitbox_SetPos(&e->hitbox, &e->sprite.pos, 0);
    Hitbox_Register(&e->hitbox);
    AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
    if (e->anim.cmdIdx == 3) {
      Entity7B9FElem_ScatterIceShards(e);
      FUN_081d8560(e);
      FUN_081d822c(e);
      PlaySound_082406e0(SONG_481);
    }
  }
}

void FUN_081d8714(Entity7B9FElem* e, s32 param_2) {
  Entity7B9F* p = gEntity7B9F;

  if (p != NULL) {
    AuxSpriteGfx* gfx = &p->gfx;

    Video_GetAuxSprite(gfx, SPRITE_GOLEM);
    AuxSprite_Add(&e->sprite, gfx, 0);
    p->animFile = GetFile(DIR_ANIMATION, 0x1E38);
    AuxAnim_SetAnim(&e->anim, p->animFile, 8, 1, ANIM_PLAY_XFLIP);
    Video_SetAuxSpritePltt(gfx, param_2 + 513);
  }
}

s32 Entity7B9F_Update(Entity7B9F* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (Entity7B9F_IsActive(&p->usedMask, i)) {
      p->elems[i].updateCallback(&p->elems[i]);
    }
  }
  return 0;
}

s32 Entity7B9F_Destroy(Entity7B9F* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (Entity7B9F_IsActive(&p->usedMask, i)) {
      Entity7B9FElem* e = &p->elems[i];

      CLEAR_BIT(p->usedMask, i);
      AuxSprite_Remove(&e->sprite);
      if (e->unk_d2 != -1) {
        ParticleShadow_Remove(&e->shadow);
        e->unk_d2 = -1;
      }
    }
  }
  gEntity7B9F = NULL;
  return 0;
}

s32 Entity7B9F_Init(Entity7B9F* p) {
  gEntity7B9F = p;
  return 0;
}

Entity7B9F* Entity7B9F_Create(void) {
  if (gEntity7B9F == NULL) {
    Entity7B9F* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity7B9F));

    if (p != NULL) {
      SetEntityRoutine(p, Entity7B9F_Update, Entity7B9F_Destroy);
      if (Entity7B9F_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity7B9F;
}

void nop_081d88a4(void) {}

void FUN_081d88a8(Entity7B9FElem* e, s32 param_2, s32 param_3) {
  HitboxData* hitbox = &e->hitbox;
  Vec3 offset;
  Vec3 size;

  VEC3_SET(offset, 0, 50, 0);
  VEC3_SET(size, 84, 64, 84);
  hitbox->id = e->id;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x20, &size, &offset);
  Hitbox_SetAttack(hitbox, param_2, param_3, 0x2000, 0x440008, 60);
  Hitbox_SetPos(hitbox, &e->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, nop_081d88a4, e);
}

void Cmd_7B9F(void) {
  Entity7B9F* p = gEntity7B9F;
  Entity7B9FElem* e;
  u32 power;
  u32 knockback;

  if (p == NULL) {
    p = Entity7B9F_Create();
    if (p == NULL) {
      return;
    }
  }
  e = Entity7B9F_AllocElem(p);
  if (e == NULL) {
    return;
  }
  FUN_081d8714(e, 2);
  if (VM_SeekToNamedArg('p')) {
    e->sprite.pos.x = VM_GetValue();
    e->sprite.pos.y = VM_GetValue();
    e->sprite.pos.z = VM_GetValue();
  }
  e->id = VM_GetNamedArgValue('n', 0);
  if (VM_SeekToNamedArg('a')) {
    power = VM_GetValue();
    knockback = VM_GetValue();
  } else {
    power = 100;
    knockback = 100;
  }
  e->state = 1;
  e->stateTimer = 0;
  e->updateCallback = FUN_081d836c;
  e->unk_d2 = ParticleShadow_Init(&e->shadow, &e->sprite.pos, 0);
  ParticleShadow_Hide(&e->shadow);
  FUN_081d88a8(e, power, knockback);
}

void ClearEntity7B9F(void) { gEntity7B9F = NULL; }
