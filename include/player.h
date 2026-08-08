#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "entity.h"
#include "gba/gba.h"
#include "types.h"
#include "weapon.h"

// Player.kind
enum PlayerKind {
  PLAYER_SOLAR_DJANGO,
  PLAYER_DARK_DJANGO,
  PLAYER_UNK_02,
  PLAYER_UNK_03,
  PLAYER_UNK_04,
  PLAYER_SABATA,
};

typedef struct {
  u16 unk_264;
  u16 unk_266;
  u16 unk_268;
  u16 unk_26a;
  u16 unk_26c;
  u16 unk_26e;
  u16 unk_270;
  u16 unk_272;
  s16 unk_274;
  s16 unk_276;
} Player_264;

typedef struct Player {
  Entity e;
  void* unk_18;
  u32 unk_1c;
  u16 unk_20;
  u16 unk_22;
  u16 unk_24;
  u16 unk_26;
  u8 unk_28;
  u8 unk_29;
  u16 unk_2a;
  EntityFunc unk_2c;
  u16 unk_30;
  u8 unk_32;
  u8 unk_33;
  u8 unk_34;
  bool8 unk_35;
  u16 unk_36;
  u16 unk_38;
  u8 unk_3a[554];
  Player_264 unk_264;
  u16 unk_278;
  s16 unk_27a;
  u32 unk_27c;
  u8 unk_280[216];
  u8 kind;  // 0x358: see PlayerKind
  u8 unk_359;
  u16 unk_35a;
  u16 unk_35c;
  u16 unk_35e;
  u16 unk_360;
  u16 unk_362;
  u16 hp;      // 0x364
  u16 maxHP;   // 0x366
  u16 ene;     // 0x368
  u16 maxEne;  // 0x36A
  u8 unk_36c[10];
  u16 unk_376;
  u32 unk_378;
  u8 unk_37c;
  u8 unk_37d;
  u16 unk_37e;
  u8 unk_380[16];
  u16 unk_390;
  u16 unk_392;
  u8 unk_394[56];
  u16 unk_3cc;
  u16 unk_3ce;
  u8 unk_3d0;
  u8 unk_3d1;
  u8 unk_3d2[106];
  u16 unk_43c[3];
  u8 unk_442[1402];
  u16 unk_9bc;
  u16 pad_9be;
  s32 unk_9c0;
  u32 unk_9c4;
  u8 unk_9c8[168];
  Weapon* weapon_a70;
  weapon8_t weaponID_a74;
  u8 weaponKind_a75;
  u8 unk_a76[78];
} Player;
static_assert(sizeof(Player) == 2756);

// ------------------------------------------------------------------------------------------------------------------------------------

extern Player* gPlayerPtr[4];

#endif  // GUARD_ZOKTAI_PLAYER_H
