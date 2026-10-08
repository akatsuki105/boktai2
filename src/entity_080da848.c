#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite.h"

// 8枠ぶんの演出要素, activeMask のビットが立っている枠だけ生きている
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
  u8 unk_18[0x32 - 0x18];       // 0x018, まだ未解析
  u8 unk_32[3];                 // 0x032, 根拠: FUN_080d8644 が3要素を 0 で埋める
  u8 unk_35[3];                 // 0x035, 同上
  u8 unk_38[0x3E - 0x38];       // 0x038, まだ未解析
  u16 unk_3e[3];                // 0x03E, 同上
  u8 unk_44[0x4C - 0x44];       // 0x044, まだ未解析
  u32 unk_4c[3];                // 0x04C, 同上
  u8 unk_58[0x5C - 0x58];       // 0x058, まだ未解析
  Entity080da848Elem elems[8];  // 0x05C, 根拠: _Destroy の stride 0x134 × 8
  u32 activeMask;               // 0x9FC, 使用中の elems のビットマスク
} Entity080da848;
static_assert(sizeof(Entity080da848) == 2560);

extern Entity080da848* gEntity080da848;  // 0x0300015C

void FUN_080d8644(Entity080da848* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    p->unk_32[i] = 0;
    p->unk_35[i] = 0;
    p->unk_4c[i] = 0;
    p->unk_3e[i] = 0;
  }
}

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

void FUN_080d8ddc(Entity080da848Elem* _) {}

NAKED void FUN_080d8de0(Entity080da848* p, u32 param_2) { INCFUNC("asm/func/FUN_080d8de0.inc"); }

NAKED void FUN_080d8e98(Entity080da848* p) { INCFUNC("asm/func/FUN_080d8e98.inc"); }

NAKED void FUN_080d92ac(Entity080da848* p) { INCFUNC("asm/func/FUN_080d92ac.inc"); }

NAKED void FUN_080d94b4(Entity080da848* p) { INCFUNC("asm/func/FUN_080d94b4.inc"); }

NAKED void FUN_080d96b8(Entity080da848* p) { INCFUNC("asm/func/FUN_080d96b8.inc"); }

NAKED void FUN_080d9758(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9758.inc"); }

NAKED void FUN_080d9800(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9800.inc"); }

void (*const PTR_ARRAY_085ad2ec[6])(Entity080da848*) = {
    FUN_080d94b4,
    FUN_080d9758,
    FUN_080d92ac,
    FUN_080d8e98,
    FUN_080d9800,
    FUN_080d9800,
};  // 0x085AD2EC

NAKED void FUN_080d98d4(Entity080da848Elem* p) { INCFUNC("asm/func/FUN_080d98d4.inc"); }

NAKED s32 FUN_080d9974(Entity080da848* p) { INCFUNC("asm/func/FUN_080d9974.inc"); }

s32 FUN_080d99c4(Entity080da848* p) {
  s32 v = FUN_080d9974(p);

  if (v == 0) {
    return 0;
  }

  return v;
}

NAKED s32 FUN_080d99d4(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d99d4.inc"); }

NAKED s32 FUN_080d9a9c(Entity080da848* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080d9a9c.inc"); }

NAKED s32 FUN_080d9b3c(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d9b3c.inc"); }

NAKED s32 FUN_080d9cec(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d9cec.inc"); }

NAKED s32 FUN_080d9f5c(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080d9f5c.inc"); }

NAKED s32 FUN_080da110(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { INCFUNC("asm/func/FUN_080da110.inc"); }

NAKED s32 FUN_080da358(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080da358.inc"); }

NAKED s32 FUN_080da4f8(Entity080da848* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080da4f8.inc"); }

s32 FUN_080da698(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9) { return FUN_080da110(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 3, param_8, param_9); }

s32 FUN_080da6c4(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { return FUN_080da110(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }

void (*const PTR_ARRAY_085ad304[3])(Entity080da848Elem*) = {
    FUN_080d8ddc,
    FUN_080d98d4,
    NULL,
};  // 0x085AD304

NAKED s32 Entity080da848_Update(Entity080da848* p) { INCFUNC("asm/func/Entity080da848_Update.inc"); }

NAKED s32 Entity080da848_Destroy(Entity080da848* p) { INCFUNC("asm/func/Entity080da848_Destroy.inc"); }

NAKED void FUN_080da7cc(Entity080da848* p) { INCFUNC("asm/func/FUN_080da7cc.inc"); }

s32 Entity080da848_Init(Entity080da848* p) {
  p->activeMask = 0;
  FUN_080da7cc(p);
  gEntity080da848 = p;
  return 0;
}

Entity080da848* Entity080da848_Create(void) {
  if (gEntity080da848 == NULL) {
    Entity080da848* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity080da848));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080da848_Update, Entity080da848_Destroy);
      if (Entity080da848_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080da848;
}

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
