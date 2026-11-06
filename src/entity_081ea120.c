#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  Vec3 pos;      // 0x00, sprites[idx] の位置
  u8 unk_08[2];  // 0x08
  u8 state;      // 0x0A, PTR_ARRAY_085ae45c の添字, 1 でアニメを流し, 一巡すると 2 で片付ける
  s8 idx;        // 0x0B, sprites と anims の添字, 空きは -1
} Entity081ea120Item;
static_assert(sizeof(Entity081ea120Item) == 12);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* animFile;        // 0x018, ANIM_931E
  AuxSprite sprites[8];         // 0x01C
  AuxSpriteGfx gfx;             // 0x17C, SPRITE_863A
  AuxAnimState anims[8];        // 0x198
  u32 activeMask;               // 0x218, items の使用中ビット
  Entity081ea120Item items[8];  // 0x21C
} Entity081ea120;
static_assert(sizeof(Entity081ea120) == 636);

static Entity081ea120* gEntity081ea120;  // 0x030001B8

static inline bool8 Entity081ea120_IsItemUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081ea120Item_UpdateState0(Entity081ea120*, Entity081ea120Item*);
void Entity081ea120Item_UpdateState1(Entity081ea120*, Entity081ea120Item*);
void Entity081ea120Item_UpdateState2(Entity081ea120*, Entity081ea120Item*);
Entity081ea120Item* Entity081ea120_AllocItem(Entity081ea120* p);
s32 Entity081ea120_Update(Entity081ea120* p);
s32 Entity081ea120_Destroy(Entity081ea120* p);
void Entity081ea120_LoadAuxSprite(Entity081ea120* p);
s32 Entity081ea120_Init(Entity081ea120* p, u32 _);

// Entity081ea120_Update が (p, item) で呼ぶ
void (*const PTR_ARRAY_085ae45c[3])(Entity081ea120*, Entity081ea120Item*) = {
    Entity081ea120Item_UpdateState0,
    Entity081ea120Item_UpdateState1,
    Entity081ea120Item_UpdateState2,
};  // 0x085AE45C

const u8 u8_ARRAY_085ae468[4] = {8, 4, 2, 1};  // 0x085AE468, Entity081ea820Elem_UpdateState2 が Mod の除数として引く

void Entity081ea120Item_UpdateState0(Entity081ea120* p, Entity081ea120Item* item) {}

// アニメを進め, 一巡したら片付けの状態に移す
void Entity081ea120Item_UpdateState1(Entity081ea120* p, Entity081ea120Item* item) {
  AuxSprite* spr = &p->sprites[item->idx];

  spr->pos = item->pos;
  spr->flags &= ~SPRFLAG_HIDDEN;
  if (AuxSprite_AdvanceAnim(spr, &p->anims[item->idx])) {
    item->state = 2;
  }
}

// スプライトを外して枠を返す
void Entity081ea120Item_UpdateState2(Entity081ea120* p, Entity081ea120Item* item) {
  AuxSprite_Remove(&p->sprites[item->idx]);
  item->state = 0;
  CLEAR_BIT(p->activeMask, item->idx);
  ClearMemory(item, sizeof(Entity081ea120Item));
  item->idx = -1;
}

Entity081ea120Item* Entity081ea120_AllocItem(Entity081ea120* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081ea120_IsItemUsed(&p->activeMask, i)) {
      Entity081ea120Item* item = &p->items[i];

      item->idx = i;
      p->activeMask |= 1 << i;
      return item;
    }
  }
  return NULL;
}

// pos にアニメを count 個出す
s32 Entity081ea120_Spawn(Vec3* pos, s32 count, u32 priority, u32 animIdx, s32 plttID) {
  Entity081ea120* p;
  s32 i;

  if (pos == NULL) {
    return -1;
  }
  p = gEntity081ea120;
  if (p == NULL) {
    return -1;
  }
  for (i = 0; i < count; i++) {
    Entity081ea120Item* item = Entity081ea120_AllocItem(p);
    AuxSprite* spr;

    if (item == NULL) {
      return -1;
    }
    spr = &p->sprites[item->idx];
    item->pos = *pos;
    AuxSprite_Add(spr, &p->gfx, 0);
    AuxAnim_SetAnim(&p->anims[item->idx], p->animFile, animIdx, 0, 0);
    Video_SetAuxSpritePltt(spr->gfx, plttID);
    spr->flags |= SPRFLAG_HIDDEN;
    spr->priority = priority;
    item->state = 1;
  }
  return 0;
}

s32 Entity081ea120_Update(Entity081ea120* p) {
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 8; i++) {
    if (Entity081ea120_IsItemUsed(&p->activeMask, i)) {
      Entity081ea120Item* item = &p->items[i];

      PTR_ARRAY_085ae45c[item->state](p, item);
    }
  }
  return 0;
}

s32 Entity081ea120_Destroy(Entity081ea120* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081ea120_IsItemUsed(&p->activeMask, i)) {
      Entity081ea120Item* item = &p->items[i];

      AuxSprite_Remove(&p->sprites[item->idx]);
    }
  }
  gEntity081ea120 = NULL;
  return 0;
}

void Entity081ea120_LoadAuxSprite(Entity081ea120* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_863A);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_931E);
}

s32 Entity081ea120_Init(Entity081ea120* p, u32 _) {
  Entity081ea120_LoadAuxSprite(p);
  return 0;
}

Entity081ea120* Entity081ea120_Create(u32 id, u32 param_2) {
  Entity081ea120* p;

  if (gEntity081ea120 != NULL) {
    return gEntity081ea120;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081ea120));
  gEntity081ea120 = p;
  if (p != NULL) {
    SetEntityRoutine(p, Entity081ea120_Update, Entity081ea120_Destroy);
    if (Entity081ea120_Init(p, 0) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081ea120_ClearGlobal(void) { gEntity081ea120 = NULL; }
