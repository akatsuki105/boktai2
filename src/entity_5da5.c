#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"
#include "vm.h"

// 4本の腕を持つシャンデリア, 炎で点き氷で消え、全部点くとスクリプトが走る
typedef struct {
  u8 index;            // 0x00, 0〜3, 親のビットマスクの位置とアニメ番号 index+2 を兼ねる
  u8 state;            // 0x01, 0 消灯, 1 点灯
  bool8 stateEntered;  // 0x02, state を変えた直後だけ立つ
  u8 unk_3;            // 0x03, 0 を書くだけ
  s32 timer;           // 0x04, state を変えるたびに 0 に戻る
  HitboxData hitbox;   // 0x08, flags 0x4001, ignoreMask 0x10, 半径は index 1,2 が {0x18, 0x100, 0x60} で他が {0x60, 0x100, 0x18}
  MainSprite sprite;   // 0x58
} Entity5DA5Elem;
static_assert(sizeof(Entity5DA5Elem) == 184);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u16 unk_18;               // 0x018, Entity5DA5_Create の引数が入る, 読み手が見つかっていない
  u16 scriptID;             // 0x01A, '.p=0', 全点灯か全消灯になったときに実行する
  u16 litMask;              // 0x01C, 点灯中の要素のビット, 下位4bit
  u8 unk_1e;                // 0x01E, 0 を書くだけ
  u8 unk_1f;                // 0x01F, 0 を書くだけ
  u32 unk_20;               // 0x020, 0 を書くだけ
  u32 scriptArgs[4];        // 0x024, '.a'
  u16 litBits;              // 0x034, 点いた要素のビット
  u16 unlitBits;            // 0x036, 消えた要素のビット
  u16 changedBits;          // 0x038, 点灯と消灯のどちらでも立つ変化したビット
  u8 unk_3a[2];             // 0x03A, 触られていない
  Vec3 pos;                 // 0x03C, '.P', 判定の基準位置
  Vec3 screenPos;           // 0x044, pos を等角投影してカメラ分を引いた画面座標
  MainSpriteGfx gfx;        // 0x04C, SPRITE_CHANDELIER
  MainSprite sprite;        // 0x06C, 土台, アニメ 6
  Entity5DA5Elem elems[4];  // 0x0CC
} Entity5DA5;
static_assert(sizeof(Entity5DA5) == 940);

IWRAM_DATA Entity5DA5* gEntity5DA5 = NULL;  // 0x03000038

const u16 u16_ARRAY_085aa690[8] = {0x0, 0x80, 0xFF80, 0x0, 0xFF80, 0x0, 0x0, 0x80};  // 0x085aa690

void Entity5DA5Elem_UpdateUnlit(Entity5DA5*, Entity5DA5Elem*);
void Entity5DA5Elem_UpdateLit(Entity5DA5*, Entity5DA5Elem*);

void (*const PTR_ARRAY_085aa6a0[2])(Entity5DA5*, Entity5DA5Elem*) = {
    Entity5DA5Elem_UpdateUnlit,
    Entity5DA5Elem_UpdateLit,
};  // 0x085aa6a0

const u8 u8_ARRAY_085aa6a8[4] = {11, 12, 11, 10};  // 0x085aa6a8

void Entity5DA5Elem_SetState(Entity5DA5Elem* p, u8 state) {
  p->state = state;
  p->timer = 0;
  p->stateEntered = TRUE;
}

bool32 Entity5DA5Elem_ConsumeStateEntered(Entity5DA5Elem* p) {
  if (p->stateEntered != 0) {
    p->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

NAKED void Entity5DA5Elem_OnHit(HitboxData* a, HitboxData* b, Entity5DA5Elem* owner) { INCFUNC("asm/func/Entity5DA5Elem_OnHit.inc"); }

NAKED s32 Entity5DA5Elem_Init(Entity5DA5* p, Entity5DA5Elem* elem, s32 index) { INCFUNC("asm/func/Entity5DA5Elem_Init.inc"); }

NAKED void Entity5DA5_RunScript(Entity5DA5* p, s32 param_2, u32 index) { INCFUNC("asm/func/Entity5DA5_RunScript.inc"); }

NAKED void Entity5DA5Elem_UpdateUnlit(Entity5DA5* p, Entity5DA5Elem* elem) { INCFUNC("asm/func/Entity5DA5Elem_UpdateUnlit.inc"); }

// state 1 (点灯) の更新, 入場時に見せて litMask に自分のビットを立てる
void Entity5DA5Elem_UpdateLit(Entity5DA5* p, Entity5DA5Elem* elem) {
  if (Entity5DA5Elem_ConsumeStateEntered(elem)) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->litMask |= 1 << elem->index;
  }
  elem->sprite.pos = p->screenPos;
  MainSprite_AdvanceAnim(&elem->sprite, &p->gfx);
}

NAKED s32 Entity5DA5_Update(Entity5DA5* p) { INCFUNC("asm/func/Entity5DA5_Update.inc"); }

// 原典は return を書き忘れている
s32 Entity5DA5_Destroy(Entity5DA5* p) {
  Entity5DA5Elem* elem;
  s32 i;

  MainSprite_Remove(&p->sprite);
  elem = &p->elems[0];
  for (i = 3; i >= 0; i--, elem++) {
    Hitbox_Unregister(&elem->hitbox);
    MainSprite_Remove(&elem->sprite);
  }
  gEntity5DA5 = NULL;
}

NAKED s32 Entity5DA5_Init(Entity5DA5* p, u32 param_2) { INCFUNC("asm/func/Entity5DA5_Init.inc"); }

Entity5DA5* Entity5DA5_Create(u32 param_1) {
  if (gEntity5DA5 == NULL) {
    Entity5DA5* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity5DA5));

    if (p != NULL) {
      SetEntityRoutine(p, Entity5DA5_Update, Entity5DA5_Destroy);
      if (Entity5DA5_Init(p, param_1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity5DA5;
}

NAKED s32 Entity5DA5_SetState(s32 index, s32 state, s32 param_3) { INCFUNC("asm/func/Entity5DA5_SetState.inc"); }

s32 Entity5DA5_SetStateScripted(void) {
  s32 index = VM_GetNamedArgValue('i', -1);
  s32 state = VM_GetNamedArgValue('m', 0);
  s32 param_3 = VM_GetNamedArgValue('d', 0);

  return Entity5DA5_SetState(index, state, param_3);
}

// 4つ全部点いていれば 1, 実体が無ければ -1
s32 Entity5DA5_AreAllLit(void) {
  Entity5DA5* p = gEntity5DA5;
  Entity5DA5Elem* elem;
  s32 lit;
  s32 result;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  lit = 0;
  elem = &p->elems[0];
  for (i = 3; i >= 0; i--, elem++) {
    if (elem->state == 1) {
      lit++;
    }
  }

  result = 0;
  if (lit == 4) {
    result = 1;
  }
  return result;
}

// 4つ全部消えていれば 1, 実体が無ければ -1
s32 Entity5DA5_AreAllUnlit(void) {
  Entity5DA5* p = gEntity5DA5;
  Entity5DA5Elem* elem;
  s32 lit;
  s32 result;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  lit = 0;
  elem = &p->elems[0];
  for (i = 3; i >= 0; i--, elem++) {
    if (elem->state == 1) {
      lit++;
    }
  }

  result = 0;
  if (lit == 0) {
    result = 1;
  }
  return result;
}
