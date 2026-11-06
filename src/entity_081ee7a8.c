#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

typedef struct {
  AuxSprite sprite;   // 0x00
  AuxSpriteGfx gfx;   // 0x2C, 生成時の spriteID (Entity081ee7a8_SpawnDefault と Entity081ee7a8_SpawnDefaultNow は SPRITE_4384)
  AuxAnimState anim;  // 0x48, 一巡すると状態 2 で片付く
  u8 state;           // 0x58, PTR_ARRAY_085ae4d4 の添字
  u8 unk_59;          // 0x59
  u8 angle;           // 0x5A, 水平に動く向き
  u8 unk_5b;          // 0x5B
  s16 riseSpeed;      // 0x5C, delay が切れてから毎フレーム sprite.pos.y に足す
  s16 speed;          // 0x5E, angle の向きに毎フレーム動く量
  u8 unk_60[4];       // 0x60
  u16 delay;          // 0x64, 0 になるまで上昇しない
  s16 unk_66;         // 0x66, 生成時に 0
  u16 animSpeed;      // 0x68, AuxAnim_SetAnimSpeed の速さ
  u8 unk_6a[2];       // 0x6A
  s8 idx;             // 0x6C, elems の添字, 空きは -1
  u8 riseTime;        // 0x6D, 上昇するたびに 1 減り, 0 になると sprite.priority を 2 に下げる
  u16 hideTime;       // 0x6E, 0 になるまで隠れたまま何もしない
} Entity081ee7a8Elem;
static_assert(sizeof(Entity081ee7a8Elem) == 112);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxAnimFile* animFile;         // 0x018, 生成時の animFileID (Entity081ee7a8_SpawnDefault と Entity081ee7a8_SpawnDefaultNow は ANIM_F62B)
  Entity081ee7a8Elem elems[48];  // 0x01C
} Entity081ee7a8;
static_assert(sizeof(Entity081ee7a8) == 5404);

static Entity081ee7a8* gEntity081ee7a8;  // 0x030001D0

void Entity081ee7a8Elem_UpdateState0(Entity081ee7a8Elem*);
void Entity081ee7a8Elem_UpdateState1(Entity081ee7a8Elem*);
void Entity081ee7a8Elem_UpdateState2(Entity081ee7a8Elem*);
void Entity081ee7a8_Spawn(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 _, SpriteFlags flags, s32 hideTime, SpriteID32 spriteID, u32 animFileID, u32 animIdx, u32 variant, s32 plttID);
s32 Entity081ee7a8_Update(Entity081ee7a8* p);
s32 Entity081ee7a8_Destroy(Entity081ee7a8* p);
s32 Entity081ee7a8_Init(Entity081ee7a8* p);
Entity081ee7a8* Entity081ee7a8_Create(void);
Entity081ee7a8Elem* Entity081ee7a8_AllocElem(Entity081ee7a8* p);

void (*const PTR_ARRAY_085ae4d4[3])(Entity081ee7a8Elem*) = {
    Entity081ee7a8Elem_UpdateState0,
    Entity081ee7a8Elem_UpdateState1,
    Entity081ee7a8Elem_UpdateState2,
};  // 0x085AE4D4

void Entity081ee7a8Elem_UpdateState0(Entity081ee7a8Elem* elem) {}

Entity081ee7a8Elem* Entity081ee7a8_AllocElem(Entity081ee7a8* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Entity081ee7a8Elem* elem = &p->elems[i];

    if (elem->idx < 0) {
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

// angle の向きに流しつつ delay の後は昇らせ, アニメが一巡したら片付けの状態に移す
void Entity081ee7a8Elem_UpdateState1(Entity081ee7a8Elem* elem) {
  AuxSprite* spr = &elem->sprite;

  if (elem->hideTime != 0) {
    elem->sprite.flags |= SPRFLAG_HIDDEN;
    elem->hideTime--;
    return;
  }
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  AuxAnim_SetAnimSpeed(&elem->anim, elem->animSpeed);
  elem->sprite.pos.x += (elem->speed * COS(elem->angle)) >> 12;
  elem->sprite.pos.z += (elem->speed * SIN(elem->angle)) >> 12;
  if (elem->delay != 0) {
    elem->delay--;
  } else {
    elem->sprite.pos.y += elem->riseSpeed;
    if (elem->riseTime != 0) {
      elem->riseTime--;
    } else {
      elem->sprite.priority = 2;
    }
  }
  if (AuxSprite_AdvanceAnim(spr, &elem->anim)) {
    elem->state = 2;
  }
}

void Entity081ee7a8Elem_UpdateState2(Entity081ee7a8Elem* elem) {
  AuxSprite_Remove(&elem->sprite);
  elem->idx = -1;
  elem->state = 0;
}

// SPRITE_4384 / ANIM_F62B で粒を1つ出す
void Entity081ee7a8_SpawnDefault(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 plttOffset, SpriteFlags flags, s32 hideTime) {
  Entity081ee7a8_Spawn(pos, riseBase, riseRand, speedBase, speedRand, delay, angleBase, angleRand, animSpeed, priority, plttOffset, flags, hideTime, SPRITE_4384, ANIM_F62B, 0, 0, plttOffset + 125);
}

void Entity081ee7a8_SpawnEx(
    Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 _, SpriteFlags flags, s32 hideTime, SpriteID32 spriteID, u32 animFileID, u32 animIdx, u32 variant, s32 plttID) {
  Entity081ee7a8_Spawn(pos, riseBase, riseRand, speedBase, speedRand, delay, angleBase, angleRand, animSpeed, priority, _, flags, hideTime, spriteID, animFileID, animIdx, variant, plttID);
}

// Entity081ee7a8_SpawnDefault の hideTime 0 版
void Entity081ee7a8_SpawnDefaultNow(Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 plttOffset, SpriteFlags flags) {
  Entity081ee7a8_Spawn(pos, riseBase, riseRand, speedBase, speedRand, delay, angleBase, angleRand, animSpeed, priority, plttOffset, flags, 0, SPRITE_4384, ANIM_F62B, 0, 0, plttOffset + 125);
}

// 乱数で速さと向きを散らした粒を1つ出す
void Entity081ee7a8_Spawn(
    Vec3* pos, s32 riseBase, s32 riseRand, s32 speedBase, s32 speedRand, s32 delay, s32 angleBase, s32 angleRand, s32 animSpeed, u32 priority, s32 _, SpriteFlags flags, s32 hideTime, SpriteID32 spriteID, u32 animFileID, u32 animIdx, u32 variant, s32 plttID) {
  Entity081ee7a8* p = gEntity081ee7a8;
  Entity081ee7a8Elem* elem;
  u16* table;

  if (p == NULL) {
    p = Entity081ee7a8_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081ee7a8_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_66 = 0;
  elem->sprite.pos = *pos;
  Video_GetAuxSprite(&elem->gfx, spriteID);
  p->animFile = GetFile(DIR_ANIMATION, animFileID);
  AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->animFile, animIdx, variant, 0);
  Video_SetAuxSpritePltt(&elem->gfx, plttID);
  table = gRandomTable;
  elem->riseSpeed = Mod(_Random(table), riseRand) + riseBase;
  elem->speed = Mod(_Random(table), speedRand) - (speedRand >> 1) + speedBase;
  elem->angle = angleBase + Mod(_Random(table), angleRand);
  elem->delay = delay;
  elem->animSpeed = animSpeed;
  elem->riseTime = 12;
  elem->sprite.flags |= SPRFLAG_HIDDEN | flags;
  elem->sprite.priority = priority;
  elem->hideTime = hideTime;
}

s32 Entity081ee7a8_Update(Entity081ee7a8* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Entity081ee7a8Elem* elem = &p->elems[i];

    if (elem->idx >= 0) {
      PTR_ARRAY_085ae4d4[elem->state](elem);
    }
  }
  return 0;
}

s32 Entity081ee7a8_Destroy(Entity081ee7a8* p) {
  s32 i;

  for (i = 0; i < 48; i++) {
    Entity081ee7a8Elem* elem = &p->elems[i];

    if (elem->idx >= 0) {
      AuxSprite_Remove(&elem->sprite);
    }
  }
  gEntity081ee7a8 = NULL;
  return 0;
}

s32 Entity081ee7a8_Init(Entity081ee7a8* p) {
  s32 i;

  gEntity081ee7a8 = p;
  for (i = 0; i < 48; i++) {
    p->elems[i].idx |= -1;
  }
  return 0;
}

Entity081ee7a8* Entity081ee7a8_Create(void) {
  Entity081ee7a8* p;

  if (gEntity081ee7a8 != NULL) {
    return gEntity081ee7a8;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081ee7a8));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081ee7a8_Update, Entity081ee7a8_Destroy);
    if (Entity081ee7a8_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081ee7a8_ClearGlobal(void) { gEntity081ee7a8 = NULL; }
