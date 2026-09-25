#include "entity.h"
#include "particle.h"
#include "sprite.h"
#include "global.h"

// 8枠ぶんの演出要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  u8 unk_0[0x2D];     // 0x000
  u8 unk_2d;          // 0x02D, FUN_080da8a0 が 0 かどうかを見る
  u8 unk_2e[10];      // 0x02E
  u8 ptclMask;        // 0x038, bit0..2 が立っている枠だけ _Destroy が Particle_Remove する
  u8 unk_39[11];      // 0x039
  u8 hasSprite;       // 0x044, 0 以外なら _Destroy が spr を AuxSprite_Remove する
  u8 unk_45[0x17];    // 0x045
  AuxSprite spr;      // 0x05C, _Destroy が AuxSprite_Remove に渡す
  Particle ptcls[3];  // 0x088, 根拠: _Destroy の stride 0x28 × 3
  u8 unk_100[0x34];   // 0x100
} Entity080da848Elem;
static_assert(sizeof(Entity080da848Elem) == 308);

typedef struct Entity080da848 {
  Entity e;                     // 0x000, ENTITY_UNK_9
  u8 unk_18[0x44];              // 0x018
  Entity080da848Elem elems[8];  // 0x05C, 根拠: _Destroy の stride 0x134 × 8
  u32 activeMask;               // 0x9FC, 使用中の elems のビットマスク
} Entity080da848;
static_assert(sizeof(Entity080da848) == 2560);

extern Entity080da848* gEntity080da848;  // 0x0300015C

NAKED void FUN_080d8644(Entity080da848* p) { INCFUNC("asm/func/FUN_080d8644.inc"); }

NAKED void FUN_080d866c(Entity080da848* p) { INCFUNC("asm/func/FUN_080d866c.inc"); }

NAKED s32 FUN_080d8788(Entity080da848* p, u32 param_2) { INCFUNC("asm/func/FUN_080d8788.inc"); }

NAKED void FUN_080d8864(Entity080da848* p, u32 param_2) { INCFUNC("asm/func/FUN_080d8864.inc"); }

NAKED void FUN_080d88ec(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d88ec.inc"); }

NAKED void FUN_080d8954(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d8954.inc"); }

NAKED void FUN_080d8990(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d8990.inc"); }

NAKED void FUN_080d89cc(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_080d89cc.inc"); }

NAKED void FUN_080d8a90(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d8a90.inc"); }

NAKED void FUN_080d8b58(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d8b58.inc"); }

NAKED void FUN_080d8c20(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d8c20.inc"); }

NAKED void FUN_080d8c70(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d8c70.inc"); }

NAKED void FUN_080d8cc0(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_080d8cc0.inc"); }

void FUN_080d8ddc(void) {}

NAKED void FUN_080d8de0(Entity080da848* p, u32 param_2) { INCFUNC("asm/func/FUN_080d8de0.inc"); }

NAKED void FUN_080d8e98(Entity080da848* p) { INCFUNC("asm/func/FUN_080d8e98.inc"); }

NAKED void FUN_080d92ac(Entity080da848* p) { INCFUNC("asm/func/FUN_080d92ac.inc"); }

NAKED void FUN_080d94b4(Entity080da848* p) { INCFUNC("asm/func/FUN_080d94b4.inc"); }

NAKED void FUN_080d96b8(Entity080da848* p) { INCFUNC("asm/func/FUN_080d96b8.inc"); }

NAKED void FUN_080d9758(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9758.inc"); }

NAKED void FUN_080d9800(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9800.inc"); }

NAKED void FUN_080d98d4(Entity080da848* p) { INCFUNC("asm/func/FUN_080d98d4.inc"); }

NAKED s32 FUN_080d9974(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9974.inc"); }

NAKED s32 FUN_080d99c4(void) { INCFUNC("asm/func/FUN_080d99c4.inc"); }

NAKED s32 FUN_080d99d4(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d99d4.inc"); }

NAKED s32 FUN_080d9a9c(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d9a9c.inc"); }

NAKED s32 FUN_080d9b3c(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d9b3c.inc"); }

NAKED s32 FUN_080d9cec(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d9cec.inc"); }

NAKED s32 FUN_080d9f5c(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d9f5c.inc"); }

NAKED s32 FUN_080da110(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080da110.inc"); }

NAKED s32 FUN_080da358(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080da358.inc"); }

NAKED s32 FUN_080da4f8(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080da4f8.inc"); }

NAKED void FUN_080da698(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9) { INCFUNC("asm/func/FUN_080da698.inc"); }

NAKED void FUN_080da6c4(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { INCFUNC("asm/func/FUN_080da6c4.inc"); }

NAKED s32 Entity080da848_Update(Entity080da848* p) { INCFUNC("asm/func/Entity080da848_Update.inc"); }

NAKED s32 Entity080da848_Destroy(Entity080da848* p) { INCFUNC("asm/func/Entity080da848_Destroy.inc"); }

NAKED void FUN_080da7cc(Entity080da848* p) { INCFUNC("asm/func/FUN_080da7cc.inc"); }

s32 Entity080da848_Init(Entity080da848* p) {
  p->activeMask = 0;
  FUN_080da7cc(p);
  gEntity080da848 = p;
  return 0;
}

NAKED Entity080da848* Entity080da848_Create(void) { INCFUNC("asm/func/Entity080da848_Create.inc"); }

void FUN_080da894(void) { gEntity080da848 = NULL; }

bool32 FUN_080da8a0(Entity080da848Elem* elem) {
  if (gEntity080da848 == NULL) {
    return TRUE;
  }
  if (elem == NULL) {
    return TRUE;
  }
  if (elem->unk_2d == 0) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_080da8cc(void) { INCFUNC("asm/func/FUN_080da8cc.inc"); }
