#include "global.h"
#include "player.h"

// 通信対戦で対戦相手のプレイヤー?

const u8 u8_ARRAY_085ad148[4] = {3, 4, 6, 0};  // 0x085AD148 (u8_ARRAY_085abab4 と同じもの)

void FUN_080d2008(Player* p);
void FUN_080d2968(Player* p);
void FUN_080d318c(Player* p);
void FUN_080d34b4(Player* p);
void FUN_080d36ac(Player* p);

const PlayerFunc PTR_ARRAY_085ad14c[5] = {
    [WK_SWORD] = FUN_080d2008,
    [WK_SPEAR] = FUN_080d2968,
    [WK_HAMMER] = FUN_080d318c,
    [WK_OTHERS] = FUN_080d34b4,
    [WK_GUN] = FUN_080d36ac,
};  // 0x085AD14C

const u16 gMagicCosts_085ad160[MAGIC_NUM] = {
    [MAGIC_SOL] = 5,
    [MAGIC_DARK] = 5,
    [MAGIC_FLAME] = 10,
    [MAGIC_FROST] = 10,
    [MAGIC_CLOUD] = 10,
    [MAGIC_EARTH] = 10,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 100,
    [MAGIC_UNK_8] = 10,
    [MAGIC_UNK_9] = 100,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 0,
    [MAGIC_HEALING] = 0,
    [MAGIC_DYNAMITE] = 0,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 10,
    [MAGIC_RAT] = 10,
    [MAGIC_WOLF] = 10,
};  // 0x085AD160

void FUN_080d0738(Player* p);
void FUN_080d0a04(Player* p);
void FUN_080d0aa0(Player* p);
void FUN_080d4494(Player* p);
void FUN_080d0c6c(Player* p);
void FUN_080d13b8(Player* p);
void FUN_080d5510(Player* p);
void FUN_080d55d8(Player* p);
void FUN_080d44c4(Player* p);
void FUN_080d482c(Player* p);
void FUN_080d4a34(Player* p);
void FUN_080d4d34(Player* p);
void FUN_080d4fa4(Player* p);
void FUN_080d53e4(Player* p);
void FUN_080d3f1c(Player* p);
void FUN_080d16d4(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085ad184[32] = {
    FUN_080d0738,
    FUN_080d0a04,
    FUN_080d0aa0,
    FUN_080d4494,
    FUN_080d0c6c,
    NULL,
    NULL,
    FUN_080d13b8,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d55d8,
    NULL,
    NULL,
    NULL,
    FUN_080d44c4,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d482c,
    FUN_080d4a34,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
    NULL,
};  // 0x085AD184
// clang-format on

// clang-format off
const PlayerFunc PTR_ARRAY_085ad204[31] = {
    FUN_080d0738,
    FUN_080d0a04,
    FUN_080d5510,
    FUN_080d3f1c,
    FUN_080d0c6c,
    NULL,
    NULL,
    FUN_080d16d4,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d482c,
    FUN_080d4a34,
    FUN_080d4d34,
    FUN_080d4fa4,
    FUN_080d53e4,
    NULL,
    NULL,
};  // 0x085AD204
// clang-format on

void FUN_080d57e4(Player* p);
void FUN_080d5948(Player* p);
void FUN_080d5ae0(Player* p);
void FUN_080d6408(Player* p);
void FUN_080d613c(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085ad280[27] = {
    FUN_080d57e4,
    FUN_080d5948,
    NULL,
    NULL,
    FUN_080d5ae0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d6408,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_080d613c,
    NULL,
    NULL,
};  // 0x085AD280
// clang-format on

// facing から animIDOffset と xflip を決める
void Player080d82ec_SetAnimFacing(Player* p) {
  u8 v = p->facing;

  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = 1;
  } else {
    p->animIDOffset = v;
    p->xflip = 0;
  }
}

INCASM("asm/player_080d82ec.inc");

NAKED void FUN_080d7bdc(void) { INCFUNC("asm/func/FUN_080d7bdc.inc"); }

NAKED void FUN_080d7f48(void) { INCFUNC("asm/func/FUN_080d7f48.inc"); }

NAKED void FUN_080d7fbc(Player* p) { INCFUNC("asm/func/FUN_080d7fbc.inc"); }

NAKED s32 Player080d82ec_Update(Player* p) { INCFUNC("asm/func/Player080d82ec_Update.inc"); }

NAKED s32 Player080d82ec_Destroy(Player* p) { INCFUNC("asm/func/Player080d82ec_Destroy.inc"); }

NAKED s32 Player080d82ec_Init(Player* p, u32 val1, u32 val2) { INCFUNC("asm/func/Player080d82ec_Init.inc"); }

Player* Player080d82ec_Create(u32 val1, u32 val2) {
  Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));

  if (p != NULL) {
    SetEntityRoutine(p, Player080d82ec_Update, Player080d82ec_Destroy);
    if (Player080d82ec_Init(p, val1, val2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
