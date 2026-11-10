#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite.h"
#include "vec3.h"

// 爆発の煙の粒1つ, 角度の方向へ広がりながら昇り, 点滅しつつアニメを進めて消える
typedef struct {
  AuxSprite sprite;   // 0x00, poseIdx は timer >> animShift
  Vec3 vel;           // 0x2C, x / z は毎フレーム半分になり, y はそのまま
  u8 angle;           // 0x34, 広がる向き
  s8 delay;           // 0x35, 動き出すまでのフレーム数, 0 になると -1 にして動き出す
  u16 blinkInterval;  // 0x36, timer がこれで割り切れるフレームだけ描画する, 1〜8
  u16 timer;          // 0x38
  u8 unk_3a[2];       // 0x3A
  u8 state;           // 0x3C, sEntity081eee80ElemStates の添字, 0: 空き, 1: 飛ぶ, 2: 消える
  u8 animShift;       // 0x3D, timer >> animShift が 6 になると消える
  u8 idx;             // 0x3E, elems の添字
  bool8 active;       // 0x3F
} Entity081eee80Elem;
static_assert(sizeof(Entity081eee80Elem) == 64);

// 爆発の煙の粒を最大 128 個まで管理する
typedef struct {
  Entity e;                       // 0x0000, ENTITY_UNK_10
  AuxSpriteGfx gfx;               // 0x0018, SPRITE_EXPLOSION
  u8 unk_34[4];                   // 0x0034
  Entity081eee80Elem elems[128];  // 0x0038
} Entity081eee80;
static_assert(sizeof(Entity081eee80) == 8248);

static Entity081eee80* gEntity081eee80;  // 0x030001D8

void Entity081eee80_ElemStateNone(Entity081eee80* p, Entity081eee80Elem* elem);
void Entity081eee80_ElemStateFly(Entity081eee80* p, Entity081eee80Elem* elem);
void Entity081eee80_ElemStateEnd(Entity081eee80* p, Entity081eee80Elem* elem);
Entity081eee80* Entity081eee80_Create(void);

void (*const sEntity081eee80ElemStates[3])(Entity081eee80*, Entity081eee80Elem*) = {
    Entity081eee80_ElemStateNone,
    Entity081eee80_ElemStateFly,
    Entity081eee80_ElemStateEnd,
};  // 0x085AE4EC

void Entity081eee80_ElemStateNone(Entity081eee80* p, Entity081eee80Elem* elem) {}

// 待ち時間を過ぎたら広がりながら昇り, 点滅しつつアニメを進め, 最後のポーズで消える状態へ移る
void Entity081eee80_ElemStateFly(Entity081eee80* p, Entity081eee80Elem* elem) {
  AuxSprite* sprite = &elem->sprite;
  s32 pose;

  if (elem->delay > 0) {
    elem->delay--;
    return;
  }
  if (elem->delay == 0) {
    elem->delay = -1;
  }

  elem->timer++;
  pose = elem->timer >> elem->animShift;
  if (pose == 6) {
    elem->state = 2;
    return;
  }

  if (Mod(elem->timer, elem->blinkInterval) != 0) {
    if (sprite->active) {
      Video_RemoveAuxSpriteFromDrawList(sprite, 0);
    }
    return;
  }

  if (!sprite->active) {
    Video_AddAuxSpriteIntoDrawList(sprite, 0);
  }
  sprite->pos.x += elem->vel.x;
  sprite->pos.y += elem->vel.y;
  sprite->pos.z += elem->vel.z;
  elem->vel.x >>= 1;
  elem->vel.z >>= 1;
  sprite->poseIdx = pose;
}

// 粒のスプライトを外して空きに戻す
void Entity081eee80_ElemStateEnd(Entity081eee80* p, Entity081eee80Elem* elem) {
  if (elem->sprite.active) {
    AuxSprite_Remove(&elem->sprite);
  }
  elem->state = 0;
  ClearMemory(elem, sizeof(Entity081eee80Elem));
}

// 空いている粒を探して確保する
Entity081eee80Elem* Entity081eee80_FindFreeElem(Entity081eee80* p) {
  s32 i;

  for (i = 0; i < 128; i++) {
    Entity081eee80Elem* elem = &p->elems[i];
    if (elem->active != TRUE) {
      elem->idx = i;
      elem->active = TRUE;
      return elem;
    }
  }
  return NULL;
}

// 残差はレジスタ割当のみ, 原典は plttOffset をスタックから2回読み直し, 3回目の乱数で表の番地を r3 に置く
NON_MATCH s32 Entity081eee80_Spawn(Vec3* pos, s32 priority, s32 delay, s32 angle, s32 speed, s32 animShift, s32 plttOffset) {
#ifdef NONMATCHING_C
  Entity081eee80* p;
  Entity081eee80Elem* elem;
  AuxSprite* sprite;

  if (pos == NULL) {
    return 0;
  }
  p = gEntity081eee80;
  if (p == NULL) {
    p = Entity081eee80_Create();
    if (p == NULL) {
      return 0;
    }
  }
  elem = Entity081eee80_FindFreeElem(p);
  if (elem == NULL) {
    return 0;
  }

  sprite = &elem->sprite;
  AuxSprite_Setup(sprite, &p->gfx, 0);
  sprite->poseIdx = 0;
  AuxSprite_Show(sprite);
  sprite->priority = priority;
  sprite->pos = *pos;
  elem->state = 1;
  elem->timer = 0;
  elem->angle = angle;
  elem->delay = (RandomNext() & 7) + delay;
  elem->blinkInterval = (RandomNext() & 7) + 1;
  Vec3_SetPolar(&elem->vel, angle, speed);
  elem->vel.y = Random() & 31;
  elem->animShift = animShift;
  if (plttOffset > 0) {
    Video_SetAuxSpritePltt(sprite->gfx, plttOffset + 0x113);
  }
  return 0;
#else
  INCFUNC("asm/func/Entity081eee80_Spawn.inc");
#endif
}

// 使用中の粒を状態ごとに動かす
s32 Entity081eee80_Update(Entity081eee80* p) {
  s32 i;

  for (i = 0; i < 128; i++) {
    if (p->elems[i].active == TRUE) {
      sEntity081eee80ElemStates[p->elems[i].state](p, &p->elems[i]);
    }
  }
  return 0;
}

// 使用中の粒のスプライトを外す
s32 Entity081eee80_Destroy(Entity081eee80* p) {
  s32 i;

  for (i = 0; i < 128; i++) {
    if (p->elems[i].active == TRUE && p->elems[i].sprite.active) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081eee80 = NULL;
  return 0;
}

s32 Entity081eee80_Init(Entity081eee80* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_EXPLOSION);
  gEntity081eee80 = p;
  return 0;
}

Entity081eee80* Entity081eee80_Create(void) {
  Entity081eee80* p;

  if (gEntity081eee80 != NULL) {
    return gEntity081eee80;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081eee80));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081eee80_Update, Entity081eee80_Destroy);
    if (Entity081eee80_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081eee80_ClearGlobal(void) { gEntity081eee80 = NULL; }
