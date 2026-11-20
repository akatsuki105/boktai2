#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// Entity081f7de4 が出すエフェクト1個ぶん
typedef struct {
  AuxSprite spr;           // 0x000
  AuxAnimState anim;       // 0x02C
  u8 unk_3c[0x8C - 0x3C];  // 0x03C, まだ未解析
  AuxAnimFile* animFile;   // 0x08C, ANIM_8DC7
  u32 unk_90;              // 0x090, 生成時に120が入るだけ, 読み手は未発見
  u16 unk_94;              // 0x094, 生成時に0が入るだけ, 読み手は未発見
  u8 state;                // 0x096, sEntity081f7de4ElemUpdates の添字 (0: 何もしない, 1: 回転中, 2: 片付け)
  s8 idx;                  // 0x097, Entity081f7de4.activeMask のビット位置, 負なら未使用
  u16 timer;               // 0x098, state 1 の間 1フレームごとに +1
  bool8 resetTimer;        // 0x09A, 次の更新で timer を 0 に戻す
  u8 unk_9b;               // 0x09B
} Entity081f7de4Elem;
static_assert(sizeof(Entity081f7de4Elem) == 156);

// 指定座標にアフィン回転するエフェクトを最大2個まで出すエンティティ
// おそらく、シャイアンの回転斬り
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPR_EFF_SHAIAN_SPIN
  u8 unk_34[4];                 // 0x034
  u32 activeMask;               // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f7de4Elem elems[2];  // 0x03C
} Entity081f7de4;
static_assert(sizeof(Entity081f7de4) == 372);

static inline bool8 Entity081f7de4_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

static Entity081f7de4* gEntity081f7de4;  // 0x03000204

void Entity081f7de4_UpdateIdle(Entity081f7de4*, Entity081f7de4Elem*);
void Entity081f7de4_UpdateSpin(Entity081f7de4*, Entity081f7de4Elem*);
void Entity081f7de4_UpdateRemove(Entity081f7de4*, Entity081f7de4Elem*);
Entity081f7de4* Entity081f7de4_Create(void);

void (*const sEntity081f7de4ElemUpdates[3])(Entity081f7de4*, Entity081f7de4Elem*) = {
    Entity081f7de4_UpdateIdle,
    Entity081f7de4_UpdateSpin,
    Entity081f7de4_UpdateRemove,
};  // 0x085AE5B4

// 空いている枠を確保して返す, 空きが無ければ NULL
Entity081f7de4Elem* Entity081f7de4_AllocElem(Entity081f7de4* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (!Entity081f7de4_IsActive(&p->activeMask, i)) {
      Entity081f7de4Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

void Entity081f7de4_UpdateIdle(Entity081f7de4* p, Entity081f7de4Elem* elem) {}

// アニメを進めながら回転させる, ゲームオーバー中と死亡中は止める
void Entity081f7de4_UpdateSpin(Entity081f7de4* p, Entity081f7de4Elem* elem) {
  if (elem->resetTimer) {
    elem->timer = 0;
    elem->resetTimer = FALSE;
  }
  if (!TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    AuxSprite_AdvanceAnim(&elem->spr, &elem->anim);
    elem->spr.rotation += 8;
    elem->timer++;
  }
}

// スプライトを外して枠を空ける
void Entity081f7de4_UpdateRemove(Entity081f7de4* p, Entity081f7de4Elem* elem) {
  AuxSprite_Remove(&elem->spr);
  p->activeMask &= ~(1 << elem->idx);
  elem->idx = -1;
  elem->state = 0;
}

// pos に回転するエフェクトを1つ出す
void Entity081f7de4_Spawn(Vec3* pos, u32 rotation) {
  Entity081f7de4* p = gEntity081f7de4;
  Entity081f7de4Elem* elem;
  AuxSprite* sprite;

  if (p == NULL) {
    p = Entity081f7de4_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f7de4_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_90 = 120;
  elem->unk_94 = 0;
  elem->resetTimer = TRUE;
  sprite = &elem->spr;
  sprite->pos = *pos;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_8DC7);
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, 0, 0, 0);
  Video_SetAuxSpritePltt(sprite->gfx, 629);
  AuxSprite_AdvanceAnim(&elem->spr, &elem->anim);
  sprite->priority = 1;
  sprite->flags |= SPRFLAG_BLINK_ODD | SPRFLAG_AFFINE;
  sprite->rotation = rotation;
}

// 使用中の枠について state ごとの更新関数を呼ぶ
s32 Entity081f7de4_Update(Entity081f7de4* p) {
  Entity081f7de4Elem* elems = p->elems;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 2; i++) {
      if (Entity081f7de4_IsActive(&p->activeMask, i)) {
        sEntity081f7de4ElemUpdates[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity081f7de4_Destroy(Entity081f7de4* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (Entity081f7de4_IsActive(&p->activeMask, i)) {
      Entity081f7de4Elem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->spr);
    }
  }
  gEntity081f7de4 = NULL;
  return 0;
}

s32 Entity081f7de4_Init(Entity081f7de4* p) {
  p->activeMask = 0;
  Video_GetAuxSprite(&p->gfx, SPR_EFF_SHAIAN_SPIN);
  gEntity081f7de4 = p;
  return 0;
}

Entity081f7de4* Entity081f7de4_Create(void) {
  Entity081f7de4* p;

  if (gEntity081f7de4 != NULL) {
    return gEntity081f7de4;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f7de4));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081f7de4_Update, Entity081f7de4_Destroy);
    if (Entity081f7de4_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void Entity081f7de4_ClearGlobal(void) { gEntity081f7de4 = NULL; }

// 回転中のエフェクトをすべて片付けに回す
void Entity081f7de4_RemoveAll(void) {
  Entity081f7de4* p = gEntity081f7de4;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 2; i++) {
      if (p->elems[i].state == 1) {
        p->elems[i].state = 2;
      }
    }
  }
}
