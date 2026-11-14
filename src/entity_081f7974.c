#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// 出現アニメ → delay フレーム待機 → 消滅アニメの順に1回だけ再生されるエフェクト1個
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C, animIdx 1, 出現は variant 0, 消滅は variant 1
  AuxAnimFile* animFile;  // 0x3C, ANIM_121B
  s32 delay;              // 0x40, state 2 の残りフレーム数
  u16 unk_44;             // 0x44, 生成時に 0 が入るだけ
  u8 state;               // 0x46, sEntity081f7974ElemUpdates の添字 (0:待機 1:出現 2:待ち 3:消滅)
  s8 slotIdx;             // 0x47, usedMask 上の自分のビット番号, 空きは -1
} Entity081f7974Elem;
static_assert(sizeof(Entity081f7974Elem) == 72);

// エフェクトを16個まで同時に出すシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x018, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x034
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f7974Elem elems[16];  // 0x03C
} Entity081f7974;
static_assert(sizeof(Entity081f7974) == 1212);

static inline bool8 Entity081f7974_IsUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

static Entity081f7974* gEntity081f7974;  // 0x03000200

void Entity081f7974_UpdateIdle(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateAppear(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateWait(Entity081f7974*, Entity081f7974Elem*);
void Entity081f7974_UpdateVanish(Entity081f7974*, Entity081f7974Elem*);
Entity081f7974* Entity081f7974_Create(void);

void (*const sEntity081f7974ElemUpdates[4])(Entity081f7974*, Entity081f7974Elem*) = {
    Entity081f7974_UpdateIdle,
    Entity081f7974_UpdateAppear,
    Entity081f7974_UpdateWait,
    Entity081f7974_UpdateVanish,
};  // 0x085AE5A4

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081f7974Elem* Entity081f7974_AllocElem(Entity081f7974* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (!Entity081f7974_IsUsed(&p->usedMask, i)) {
      Entity081f7974Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

void Entity081f7974_UpdateIdle(Entity081f7974* p, Entity081f7974Elem* elem) {}

// 出現アニメを進め, 一巡したら待ちへ移る
void Entity081f7974_UpdateAppear(Entity081f7974* p, Entity081f7974Elem* elem) {
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    elem->state = 2;
  }
}

// 待ち時間が尽きたら消滅アニメを始める
void Entity081f7974_UpdateWait(Entity081f7974* p, Entity081f7974Elem* elem) {
  if (elem->delay > 0) {
    elem->delay--;
  } else {
    AuxAnim_SetAnim(&elem->anim, elem->animFile, 1, 1, 0);
    elem->state = 3;
  }
}

// 消滅アニメを進め, 一巡したら枠を空ける
void Entity081f7974_UpdateVanish(Entity081f7974* p, Entity081f7974Elem* elem) {
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    AuxSprite_Remove(&elem->sprite);
    p->usedMask &= ~(1 << elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
  }
}

// pos にエフェクトを1つ出す, 出現アニメの後 delay フレーム待って消える
void Entity081f7974_Spawn(Vec3* pos, s32 delay) {
  Entity081f7974* p = gEntity081f7974;
  Entity081f7974Elem* elem;
  AuxSprite* sprite;

  if (p == NULL) {
    p = Entity081f7974_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f7974_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->delay = delay;
  elem->unk_44 = 0;
  sprite = &elem->sprite;
  sprite->pos = *pos;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_121B);
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, 1, 0, 0);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  sprite->priority = 3;
}

// 使用中の枠について state ごとの更新関数を呼ぶ
s32 Entity081f7974_Update(Entity081f7974* p) {
  Entity081f7974Elem* elems = p->elems;

  if (p->usedMask != 0) {
    s32 i;

    for (i = 0; i < 16; i++) {
      if (Entity081f7974_IsUsed(&p->usedMask, i)) {
        sEntity081f7974ElemUpdates[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity081f7974_Destroy(Entity081f7974* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (Entity081f7974_IsUsed(&p->usedMask, i)) {
      Entity081f7974Elem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->sprite);
    }
  }
  gEntity081f7974 = NULL;
  return 0;
}

s32 Entity081f7974_Init(Entity081f7974* p) {
  p->usedMask = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  gEntity081f7974 = p;
  return 0;
}

Entity081f7974* Entity081f7974_Create(void) {
  Entity081f7974* p;

  if (gEntity081f7974 != NULL) {
    return gEntity081f7974;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f7974));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081f7974_Update, Entity081f7974_Destroy);
    if (Entity081f7974_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void Entity081f7974_ClearGlobal(void) { gEntity081f7974 = NULL; }
