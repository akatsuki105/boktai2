#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"
#include "video.h"

// 1発ぶんのエフェクト
typedef struct {
  AuxSprite sprite;        // 0x00
  u8 unk_2c[0xF3 - 0x2C];  // 0x2C, まだ未解析
  u8 unk_f3;               // 0xF3, FUN_080df478 が 1 を入れる
  u16 flags;               // 0xF4, FUN_080de344 が bit2 を立てる
  u8 state;                // 0xF6, _Update が 0x085AD354 の関数表の添字として引く
  u8 index;                // 0xF7, FUN_080de174 が確保したスロット番号を入れる
  s16 timer;               // 0xF8, FUN_080de344 が毎フレーム減らし, 0 になると 3 に戻す
  u8 unk_fa[2];            // 0xFA, まだ未解析, padding?
} Entity080df420Elem;
static_assert(sizeof(Entity080df420Elem) == 252);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x18, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x34, まだ未解析
  u32 usedMask;                  // 0x38, elems のどのスロットが使用中か, FUN_080de174 が立てる
  s16 frame;                     // 0x3C, _Update が毎フレーム 1 足す
  s16 count;                     // 0x3E, FUN_080de174 が確保のたびに 1 足す
  Entity080df420Elem elems[24];  // 0x40
} Entity080df420;
static_assert(sizeof(Entity080df420) == 6112);

IWRAM_DATA Entity080df420* gEntity080df420 = NULL;  // 0x03000178

void nop_080de81c(Entity080df420*, Entity080df420Elem*);
void FUN_080de820(Entity080df420*, Entity080df420Elem*);

void (*const sEntity080df420Updates[2])(Entity080df420*, Entity080df420Elem*) = {
    nop_080de81c,
    FUN_080de820,
};  // 0x085AD354

void FUN_080debbc(unknown*, unknown*);
void FUN_080defd0(unknown*, unknown*);

void (*const PTR_ARRAY_085ad35c[2])(unknown*, unknown*) = {
    FUN_080debbc,
    FUN_080defd0,
};  // 0x085AD35C

NAKED s32 FUN_080de174(unknown* param_1) { INCFUNC("asm/func/FUN_080de174.inc"); }

NAKED void FUN_080de1cc(Entity080df420Elem* elem, s32 angle) { INCFUNC("asm/func/FUN_080de1cc.inc"); }

NAKED void FUN_080de344(unknown* param_1) { INCFUNC("asm/func/FUN_080de344.inc"); }

NAKED void FUN_080de3b4(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) { INCFUNC("asm/func/FUN_080de3b4.inc"); }

NAKED void FUN_080de52c(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) { INCFUNC("asm/func/FUN_080de52c.inc"); }

NAKED void FUN_080de6b0(Entity080df420Elem* elem, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8) { INCFUNC("asm/func/FUN_080de6b0.inc"); }

NAKED void FUN_080de7a0(Entity080df420Elem* elem) { INCFUNC("asm/func/FUN_080de7a0.inc"); }

void nop_080de81c(Entity080df420* p, Entity080df420Elem* elem) {}

NAKED void FUN_080de820(Entity080df420* p, Entity080df420Elem* param_2) { INCFUNC("asm/func/FUN_080de820.inc"); }

NAKED void FUN_080debbc(unknown* p, unknown* param_2) { INCFUNC("asm/func/FUN_080debbc.inc"); }

NAKED void FUN_080defd0(unknown* p, unknown* param_2) { INCFUNC("asm/func/FUN_080defd0.inc"); }

NAKED void FUN_080df148(WorldPos* pos, Vec3* vel, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9) { INCFUNC("asm/func/FUN_080df148.inc"); }

NAKED s32 Entity080df420_Update(Entity080df420* p) { INCFUNC("asm/func/Entity080df420_Update.inc"); }

// 残差5命令 (24/29): 原典は usedMask の判定を 0/1 に起こしてから改めて test する, bool32 を返す static inline でも畳まれてしまう
NON_MATCH s32 Entity080df420_Destroy(Entity080df420* p) {
#ifdef NONMATCHING_C
  s32 i;
  Entity080df420Elem* e;

  for (i = 0, e = p->elems; i < 24; i++, e++) {
    if (p->usedMask & 1 << i) {
      AuxSprite_Remove(&e->sprite);
    }
  }
  gEntity080df420 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity080df420_Destroy.inc");
#endif
}

s32 Entity080df420_Init(Entity080df420* p) {
  p->usedMask = 0;
  p->frame = 0;
  p->count = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  gEntity080df420 = p;
  return 0;
}

Entity080df420* Entity080df420_Create(void) {
  Entity080df420* p;

  if (gEntity080df420 != NULL) {
    return gEntity080df420;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080df420));
  if (p != NULL) {
    SetEntityRoutine(p, Entity080df420_Update, Entity080df420_Destroy);
    if (Entity080df420_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void FUN_080df46c(void) { gEntity080df420 = NULL; }

// 使用中の枠を全部 state 3 へ移す
// 残差2命令 (35 対 33), 原典は使用中判定の結果を 1/0 として一度作ってから改めて 0 と比べる (いわゆる 0/1 の作り置き)
// static inline bool32 の判定関数にすると 37 対 33 で遠ざかる
NON_MATCH void FUN_080df478(void) {
#ifdef NONMATCHING_C
  Entity080df420* p = gEntity080df420;
  s32 i;

  if (p == NULL) {
    return;
  }
  if (p->usedMask == 0) {
    return;
  }

  for (i = 0; i < 24; i++) {
    if (p->usedMask & (1 << i)) {
      p->elems[i].state = 3;
      p->elems[i].unk_f3 = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_080df478.inc");
#endif
}
