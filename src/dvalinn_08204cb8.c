#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct Entity08204cb8Elem {
  AuxSprite sprite;   // 0x00, SPRFLAG_HIDDEN が立っていて timer が 0 以下なら空き
  AuxAnimState anim;  // 0x2C, state 0 は ANIM_38E2 の 0 番, state 1 は 1 番
  s16 timer;          // 0x3C, state 0 で毎フレーム減らし, 0 になった後にアニメが一巡すると state 1 へ
  u8 state;           // 0x3E, sEntity08204cb8ElemStates の添字
  bool8 stateInited;  // 0x3F, state に入った最初の更新で立てる
  bool8 active;       // 0x40, Entity08204cb8_Update は 1 のものだけ更新する
  u8 unk_41[3];       // 0x41, padding?
} Entity08204cb8Elem;
static_assert(sizeof(Entity08204cb8Elem) == 68);

// ドヴァリンの出す水の波紋のアニメを最大 16 個まで管理する
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPR_DVALIN_00
  AuxAnimFile* animFile;         // 0x034, ANIM_38E2
  u32 unk_38;                    // 0x038, Init が 0 を書くだけで読み手は未発見
  u8 activeCount;                // 0x03C, 使用中の elems の数, 奇数番目と偶数番目で点滅させるフレームを分ける
  u8 unk_3d[3];                  // 0x03D, padding?
  Entity08204cb8Elem elems[16];  // 0x040
} Entity08204cb8;
static_assert(sizeof(Entity08204cb8) == 1152);

static Entity08204cb8* gEntity08204cb8;  // 0x03000220

void Entity08204cb8_ElemStateLoop(Entity08204cb8* p, Entity08204cb8Elem* elem);
void Entity08204cb8_ElemStateEnd(Entity08204cb8* p, Entity08204cb8Elem* elem);

void (*const sEntity08204cb8ElemStates[2])(Entity08204cb8*, Entity08204cb8Elem*) = {
    Entity08204cb8_ElemStateLoop,
    Entity08204cb8_ElemStateEnd,
};  // 0x085AE834

// 隠れていて timer が尽きた枠を先頭から探す, 16 個とも使用中なら NULL
Entity08204cb8Elem* Entity08204cb8_FindFreeElem(void) {
  Entity08204cb8* p = gEntity08204cb8;
  Entity08204cb8Elem* elem;
  s32 i;

  if (p->activeCount >= 16) {
    return NULL;
  }
  elem = p->elems;
  for (i = 0; i < 16; i++) {
    if (elem->timer <= 0 && (elem->sprite.flags & SPRFLAG_HIDDEN)) {
      return elem;
    }
    elem++;
  }
  return NULL;
}

void Entity08204cb8_SetElemState(Entity08204cb8Elem* elem, u32 state) {
  elem->state = state;
  elem->stateInited = FALSE;
}

// 空いている枠に波紋を1つ置く, 何個目かの偶奇で点滅させるフレームを分ける
void Entity08204cb8_AddElem(Vec3* pos, s32 timer) {
  Entity08204cb8* p = gEntity08204cb8;
  Entity08204cb8Elem* elem = Entity08204cb8_FindFreeElem();

  if (elem != NULL) {
    p->activeCount++;
    Entity08204cb8_SetElemState(elem, 0);
    elem->sprite.pos = *pos;
    elem->timer = timer;
    elem->active = TRUE;
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    if ((p->activeCount & 1) == 0) {
      elem->sprite.flags |= SPRFLAG_BLINK_ODD;
      elem->sprite.flags &= ~SPRFLAG_BLINK_EVEN;
    } else {
      elem->sprite.flags |= SPRFLAG_BLINK_EVEN;
      elem->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    }
  }
}

// 波紋を隠して枠を空ける
void Entity08204cb8_RemoveElem(Entity08204cb8Elem* elem) {
  Entity08204cb8* p = gEntity08204cb8;

  if (elem != NULL) {
    p->activeCount--;
    elem->timer = 0;
    elem->active = FALSE;
    elem->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// state 0, 波紋のアニメ (0 番) を繰り返し, timer が尽きてアニメが一巡したら state 1 へ移る
void Entity08204cb8_ElemStateLoop(Entity08204cb8* p, Entity08204cb8Elem* elem) {
  bool32 animDone;

  if (!elem->stateInited) {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 0, 0, 0);
    elem->stateInited = TRUE;
  }
  animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  if (elem->timer > 0) {
    elem->timer--;
  }
  if (elem->timer == 0 && animDone) {
    Entity08204cb8_SetElemState(elem, 1);
  }
}

// state 1, 消えるアニメ (1 番) を一巡させてから枠を空ける
void Entity08204cb8_ElemStateEnd(Entity08204cb8* p, Entity08204cb8Elem* elem) {
  if (!elem->stateInited) {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 1, 0, 0);
    elem->stateInited = TRUE;
  }
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    Entity08204cb8_RemoveElem(elem);
  }
}

// 使用中の波紋を state ごとに動かす, 表に無い state に当たるとそこで打ち切る
void Entity08204cb8_Update(Entity08204cb8* p) {
  Entity08204cb8Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (elem->active == TRUE) {
      if (elem->state > 1) {
        return;
      }
      sEntity08204cb8ElemStates[elem->state](p, elem);
    }
    elem++;
  }
}

s32 Entity08204cb8_Destroy(Entity08204cb8* p) {
  Entity08204cb8Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (elem->sprite.active) {
      AuxSprite_Remove(&elem->sprite);
    }
    elem++;
  }
  gEntity08204cb8 = NULL;
  return 0;
}

// 絵とアニメを読み込み, 16 個の波紋を隠した状態で用意する
// 58/54命令, 原典はループの 0 を r6, animFile を r8 に置くが, こちらは逆で 0 を書くたびに mov が増える
// 試済: animFile をローカルにする (p->animFile を毎周読むと 49 命令), 連鎖代入, 宣言順, AuxSprite_Hide
NON_MATCH s32 Entity08204cb8_InitElems(Entity08204cb8* p) {
#ifdef NONMATCHING_C
  AuxAnimFile* animFile;
  Entity08204cb8Elem* elem;
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPR_DVALIN_00);
  Video_SetAuxSpritePltt(&p->gfx, 565);
  animFile = GetFile(DIR_ANIMATION, ANIM_38E2);
  p->animFile = animFile;
  elem = p->elems;
  for (i = 0; i < 16; i++) {
    AuxSprite_Add(&elem->sprite, &p->gfx, 0);
    elem->sprite.priority = 3;
    AuxAnim_SetAnim(&elem->anim, animFile, 0, 0, 0);
    elem->sprite.flags |= SPRFLAG_HIDDEN;
    elem->timer = 0;
    elem->active = FALSE;
    elem++;
  }
  return 0;
#else
  INCFUNC("asm/func/Entity08204cb8_InitElems.inc");
#endif
}

s32 Entity08204cb8_Init(Entity08204cb8* p) {
  p->activeCount = 0;
  p->unk_38 = 0;
  Video_GetAuxSprite(&p->gfx, SPR_DVALIN_00);
  if (Entity08204cb8_InitElems(p) < 0) {
    return -1;
  }
  return 0;
}

Entity08204cb8* Entity08204cb8_Create(void) {
  if (gEntity08204cb8 == NULL) {
    Entity08204cb8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08204cb8));

    if (p != NULL) {
      SetEntityRoutine(p, Entity08204cb8_Update, Entity08204cb8_Destroy);
      if (Entity08204cb8_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity08204cb8;
}

// 管理エンティティが無ければ作ってから, pos に波紋を1つ出す, 原典は return を書き忘れている
s32 Entity08204cb8_Spawn(Vec3* pos, s32 timer) {
  if (gEntity08204cb8 == NULL) {
    gEntity08204cb8 = Entity08204cb8_Create();
  }
  Entity08204cb8_AddElem(pos, timer);
}
