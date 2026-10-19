#include "boss.h"
#include "entity.h"
#include "global.h"
#include "shadow.h"
#include "sprite_main.h"
#include "struct.h"

// カワイイ
typedef struct Durathror {
  Entity e;                   // 0x000, ENTITY_UNK_8
  u8 unk_18[0x280 - 0x18];    // 0x018, まだ未解析
  MainSprite sprite_280;      // 0x280
  u8 unk_2e0[0x4E8 - 0x2E0];  // 0x2E0, まだ未解析
  MainSprite sprite_4e8;      // 0x4E8
  u8 unk_548[0xD70 - 0x548];  // 0x548, まだ未解析
  AuxShadow shadow;           // 0xD70
  u8 unk_ddc[0xE14 - 0xDDC];  // 0xDDC, まだ未解析
  Entity5941Node node;        // 0xE14
} Durathror;
static_assert(sizeof(Durathror) == 3620);

void FUN_08036848(Durathror*);
void FUN_08038a60(Durathror*);
void FUN_0803787c(Durathror*);
void FUN_08037888(Durathror*);
void FUN_080378b4(Durathror*);
void FUN_080379a8(Durathror*);
void FUN_08037a48(Durathror*);
void FUN_08037e10(Durathror*);
void FUN_08037ee0(Durathror*);
void FUN_08038080(Durathror*);
void FUN_08038200(Durathror*);
void FUN_080382f0(Durathror*);
void bee_08038358(Durathror*);
void bee_08038514(Durathror*);
void FUN_080385f8(Durathror*);

void (*const PTR_ARRAY_085aae30[13])(Durathror*) = {
    FUN_0803787c,
    FUN_08037888,
    FUN_080378b4,
    FUN_080379a8,
    FUN_08037a48,
    FUN_08037e10,
    FUN_08037ee0,
    FUN_08038080,
    FUN_08038200,
    FUN_080382f0,
    bee_08038358,
    bee_08038514,
    FUN_080385f8,
};  // 0x085AAE30

void FUN_080395fc(Durathror*);
void FUN_08039680(Durathror*);
void FUN_08039704(Durathror*);
void FUN_08039754(Durathror*);
void FUN_080397a4(Durathror*);
void FUN_0803981c(Durathror*);
void FUN_08039878(Durathror*);
void FUN_08039918(Durathror*);
void FUN_08039ac4(Durathror*);

void (*const PTR_ARRAY_085aae64[9])(Durathror*) = {
    FUN_080395fc,
    FUN_08039680,
    FUN_08039704,
    FUN_08039754,
    FUN_080397a4,
    FUN_0803981c,
    FUN_08039878,
    FUN_08039918,
    FUN_08039ac4,
};  // 0x085AAE64

void FUN_08039cd8(Durathror*);
void FUN_08039d38(Durathror*);
void FUN_08039d70(Durathror*);
void FUN_08039dd0(Durathror*);

void (*const PTR_ARRAY_085aae88[4])(Durathror*) = {
    FUN_08039cd8,
    FUN_08039d38,
    FUN_08039d70,
    FUN_08039dd0,
};  // 0x085AAE88

void FUN_08039df4(Durathror*);
void FUN_08039e2c(Durathror*);
void FUN_08039e70(Durathror*);
void FUN_08039eb4(Durathror*);
void FUN_08039f14(Durathror*);
void FUN_08039f74(Durathror*);
void FUN_08039fd8(Durathror*);

void (*const PTR_ARRAY_085aae98[7])(Durathror*) = {
    FUN_08039df4,
    FUN_08039e2c,
    FUN_08039e70,
    FUN_08039eb4,
    FUN_08039f14,
    FUN_08039f74,
    FUN_08039fd8,
};  // 0x085AAE98

void FUN_0803a03c(Durathror*);
void FUN_0803a058(Durathror*);
void FUN_0803a074(Durathror*);
void FUN_0803a090(Durathror*);
void FUN_0803a0cc(Durathror*);
void FUN_0803a0e8(Durathror*);

void (*const PTR_ARRAY_085aaeb4[6])(Durathror*) = {
    FUN_0803a03c,
    FUN_0803a058,
    FUN_0803a074,
    FUN_0803a090,
    FUN_0803a0cc,
    FUN_0803a0e8,
};  // 0x085AAEB4

void FUN_0803a128(Durathror*, s32);
void FUN_0803a180(Durathror*, s32);
void FUN_0803a1d8(Durathror*, s32);
void FUN_0803a3d0(Durathror*, s32);
void FUN_0803a438(Durathror*, s32);
void FUN_0803a500(Durathror*, s32);
void FUN_0803a668(Durathror*, s32);
void FUN_0803a6ec(Durathror*, s32);
void FUN_0803a8c0(Durathror*, s32);
void durathror_0803aae8(Durathror*, s32);
void durathror_0803acbc(Durathror*, s32);
void FUN_0803ad74(Durathror*, s32);
void FUN_0803adf0(Durathror*, s32);
void bee_0803aee4(Durathror*, s32);
void FUN_0803af44(Durathror*, s32);
void durathror_0803b024(Durathror*, s32);
void FUN_0803b1a4(Durathror*, s32);
void FUN_0803b1e0(Durathror*, s32);
void FUN_0803b278(Durathror*, s32);
void FUN_0803b310(Durathror*, s32);
void FUN_0803b42c(Durathror*, s32);
void FUN_0803b52c(Durathror*, s32);
void FUN_0803b628(Durathror*, s32);

// clang-format off
void (*const durathror_085aaecc[24])(Durathror*, s32) = {
    NULL,
    FUN_0803a128,
    FUN_0803a180,
    FUN_0803a1d8,
    FUN_0803a3d0,
    FUN_0803a438,
    FUN_0803a500,
    FUN_0803a668,
    FUN_0803a6ec,
    FUN_0803a8c0,
    durathror_0803aae8,
    durathror_0803acbc,
    FUN_0803ad74,
    FUN_0803adf0,
    bee_0803aee4,
    FUN_0803af44,
    durathror_0803b024,
    FUN_0803b1a4,
    FUN_0803b1e0,
    FUN_0803b278,
    FUN_0803b310,
    FUN_0803b42c,
    FUN_0803b52c,
    FUN_0803b628,
};  // 0x085AAECC
// clang-format on

INCASM("asm/durathror.inc");

void FUN_080390f8(Durathror*);
void FUN_0803a104(Durathror*);
void FUN_0803b7c4(Durathror*);
void FUN_08039280(Durathror*);

s32 Durathror_Update(Durathror* p) {
  FUN_080390f8(p);
  FUN_0803a104(p);
  FUN_0803b7c4(p);
  FUN_08039280(p);
  return 0;
}

s32 Durathror_Destroy(Durathror* p) {
  AuxShadow_Remove(&p->shadow);
  FUN_08038a60(p);
  FUN_08036848(p);
  MainSprite_Remove(&p->sprite_280);
  MainSprite_Remove(&p->sprite_4e8);
  Entity5941_Unregister(&p->node);
  FUN_08022b04((Boss*)p);
  return 0;
}

NAKED s32 Durathror_Init(Durathror* p, u32 id) { INCFUNC("asm/func/Durathror_Init.inc"); }

Durathror* Durathror_Create(u32 id) {
  Durathror* p = FUN_08022a2c(BOSS_DURATHROR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Durathror));
  if (p != NULL) {
    SetEntityRoutine(p, Durathror_Update, Durathror_Destroy);
    if (Durathror_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
